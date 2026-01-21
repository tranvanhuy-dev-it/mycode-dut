#include "CollisionManager.h"
#include <cmath>

CollisionManager::CollisionManager() {}

bool CollisionManager::checkAABB(const sf::FloatRect& a, const sf::FloatRect& b)
{
    return a.intersects(b);
}

bool CollisionManager::checkSpriteCollision(const sf::Sprite& a, const sf::Sprite& b)
{
    return a.getGlobalBounds().intersects(b.getGlobalBounds());
}

bool CollisionManager::checkCollision(Entity* a, Entity* b)
{
    if (!a || !b || !a->get_status() || !b->get_status())
        return false;
    
    return checkSpriteCollision(a->get_sprite(), b->get_sprite());
}

CollisionInfo CollisionManager::calculateCollisionInfo(Entity* a, Entity* b)
{
    CollisionInfo info;
    info.entityA = a;
    info.entityB = b;
    
    sf::FloatRect boundsA = a->get_sprite().getGlobalBounds();
    sf::FloatRect boundsB = b->get_sprite().getGlobalBounds();
    
    // Tính toán độ sâu xuyên thủng theo mỗi trục
    float overlapX = std::min(boundsA.left + boundsA.width, boundsB.left + boundsB.width)
                   - std::max(boundsA.left, boundsB.left);
    float overlapY = std::min(boundsA.top + boundsA.height, boundsB.top + boundsB.height)
                   - std::max(boundsA.top, boundsB.top);
    
    // Chọn trục có độ xuyên thủng nhỏ nhất để đẩy ra
    if (overlapX < overlapY)
    {
        info.penetrationDepth = overlapX;
        info.normal = (boundsA.left < boundsB.left) ? sf::Vector2f(-1.f, 0.f) : sf::Vector2f(1.f, 0.f);
    }
    else
    {
        info.penetrationDepth = overlapY;
        info.normal = (boundsA.top < boundsB.top) ? sf::Vector2f(0.f, -1.f) : sf::Vector2f(0.f, 1.f);
    }
    
    return info;
}

void CollisionManager::resolveCollision(Entity* a, Entity* b, const CollisionInfo& info)
{
    // Chỉ đẩy entity có thể di chuyển (walkable = false nghĩa là static)
    bool aCanMove = a->is_walkable();
    bool bCanMove = b->is_walkable();
    
    if (!aCanMove && !bCanMove)
        return; // Cả 2 đều static, không xử lý
    
    sf::Vector2f separation = info.normal * info.penetrationDepth;
    
    if (aCanMove && !bCanMove)
    {
        // Chỉ đẩy A
        a->set_position(a->get_x() + separation.x, a->get_y() + separation.y);
    }
    else if (!aCanMove && bCanMove)
    {
        // Chỉ đẩy B
        b->set_position(b->get_x() - separation.x, b->get_y() - separation.y);
    }
    else
    {
        // Cả 2 đều có thể di chuyển, chia đôi lực đẩy
        a->set_position(a->get_x() + separation.x * 0.5f, a->get_y() + separation.y * 0.5f);
        b->set_position(b->get_x() - separation.x * 0.5f, b->get_y() - separation.y * 0.5f);
    }
}

bool CollisionManager::handleCharacterCollisions(Character* player, Quadtree& qt)
{
    if (!player || !player->get_status())
        return false;
    
    sf::FloatRect bounds = player->get_sprite().getGlobalBounds();
    Rect searchArea(
        bounds.left + bounds.width / 2.f,
        bounds.top + bounds.height / 2.f,
        bounds.width + 50.f,
        bounds.height + 50.f
    );
    
    Vector<Entity*> nearbyEntities;
    qt.query(searchArea, nearbyEntities);
    
    for (int i = 0; i < nearbyEntities.get_size(); ++i)
    {
        Entity* other = nearbyEntities[i];
        
        if (other == player || !other->get_status())
            continue;
        
        // Bỏ qua Resource (đã xử lý bằng attack)
        if (dynamic_cast<Resource*>(other))
            continue;
        
        if (checkCollision(player, other))
        {
            // Nếu va chạm với vật không thể đi qua
            if (!other->is_walkable())
            {
                CollisionInfo info = calculateCollisionInfo(player, other);
                resolveCollision(player, other, info);
            }
            
            // Xử lý va chạm đặc biệt với Monster
            if (Monster* monster = dynamic_cast<Monster*>(other))
            {
                // Đẩy nhân vật ra (monster đã tự động tấn công qua update)
                CollisionInfo info = calculateCollisionInfo(player, other);
                resolveCollision(player, monster, info);
            }
        }
    }
    return true;
}

void CollisionManager::handleMonsterCollisions(Monster* monster, Quadtree& qt, Character* player, Castle* castle)
{
    if (!monster || !monster->get_status())
        return;
    
    sf::FloatRect bounds = monster->get_sprite().getGlobalBounds();
    Rect searchArea(
        bounds.left + bounds.width / 2.f,
        bounds.top + bounds.height / 2.f,
        bounds.width + 100.f,
        bounds.height + 100.f
    );
    
    Vector<Entity*> nearbyEntities;
    qt.query(searchArea, nearbyEntities);
    
    for (int i = 0; i < nearbyEntities.get_size(); ++i)
    {
        Entity* other = nearbyEntities[i];
        
        if (other == monster || !other->get_status())
            continue;
        
        // Bỏ qua Character và Castle (đã xử lý trong Monster::update)
        if (other == player || other == castle)
            continue;
        
        // Bỏ qua Resource
        if (dynamic_cast<Resource*>(other))
            continue;
        
        if (checkCollision(monster, other))
        {
            // Va chạm với Monster khác - đẩy ra
            if (Monster* otherMonster = dynamic_cast<Monster*>(other))
            {
                CollisionInfo info = calculateCollisionInfo(monster, otherMonster);
                resolveCollision(monster, otherMonster, info);
            }
            // Va chạm với vật thể static
            else if (!other->is_walkable())
            {
                CollisionInfo info = calculateCollisionInfo(monster, other);
                resolveCollision(monster, other, info);
            }
        }
    }
}

void CollisionManager::preventOverlap(Entity* moving, Entity* static_obj)
{
    if (!moving || !static_obj)
        return;
    
    if (!checkCollision(moving, static_obj))
        return;
    
    CollisionInfo info = calculateCollisionInfo(moving, static_obj);
    
    // Đẩy entity di chuyển ra khỏi vật thể static
    sf::Vector2f separation = info.normal * (info.penetrationDepth + 1.f);
    moving->set_position(moving->get_x() + separation.x, moving->get_y() + separation.y);
}

bool CollisionManager::canMoveTo(Entity* entity, float newX, float newY, Quadtree& qt)
{
    if (!entity)
        return false;
    
    // Lưu vị trí cũ
    int oldX = entity->get_x();
    int oldY = entity->get_y();
    
    // Di chuyển tạm thời
    entity->set_position(newX, newY);
    
    // Kiểm tra va chạm
    sf::FloatRect bounds = entity->get_sprite().getGlobalBounds();
    Rect searchArea(
        bounds.left + bounds.width / 2.f,
        bounds.top + bounds.height / 2.f,
        bounds.width + 20.f,
        bounds.height + 20.f
    );
    
    Vector<Entity*> nearbyEntities;
    qt.query(searchArea, nearbyEntities);
    
    bool canMove = true;
    for (int i = 0; i < nearbyEntities.get_size(); ++i)
    {
        Entity* other = nearbyEntities[i];
        
        if (other == entity || !other->get_status())
            continue;
        
        if (!other->is_walkable() && checkCollision(entity, other))
        {
            canMove = false;
            break;
        }
    }
    
    // Khôi phục vị trí cũ
    entity->set_position(oldX, oldY);
    
    return canMove;
}