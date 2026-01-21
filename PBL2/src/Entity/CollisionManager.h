#pragma once
#include "Entity.h"
#include "Character.h"
#include "Monster.h"
#include "Castle.h"
#include "Resource.h"
#include "Quadtree.h"
#include "Vector.h"
#include <SFML/Graphics.hpp>

struct CollisionInfo
{
    Entity* entityA;
    Entity* entityB;
    float penetrationDepth;
    sf::Vector2f normal; // hướng đẩy ra
};

class CollisionManager
{
private:
    // Kiểm tra va chạm AABB (Axis-Aligned Bounding Box)
    bool checkAABB(const sf::FloatRect& a, const sf::FloatRect& b);
    
    // Kiểm tra va chạm giữa 2 sprite
    bool checkSpriteCollision(const sf::Sprite& a, const sf::Sprite& b);
    
    // Tính toán thông tin va chạm chi tiết
    CollisionInfo calculateCollisionInfo(Entity* a, Entity* b);
    
    // Xử lý phản hồi va chạm (đẩy ra)
    void resolveCollision(Entity* a, Entity* b, const CollisionInfo& info);

public:
    CollisionManager();
    
    // Kiểm tra và xử lý va chạm của Character với các entity khác
    bool handleCharacterCollisions(Character* player, Quadtree& qt);
    
    // Kiểm tra và xử lý va chạm của Monster với các entity khác
    void handleMonsterCollisions(Monster* monster, Quadtree& qt, Character* player, Castle* castle);
    
    // Kiểm tra va chạm giữa 2 entity bất kỳ
    bool checkCollision(Entity* a, Entity* b);
    
    // Ngăn entity đi qua các vật thể không thể đi qua
    void preventOverlap(Entity* moving, Entity* static_obj);
    
    // Kiểm tra xem entity có thể di chuyển đến vị trí mới không
    bool canMoveTo(Entity* entity, float newX, float newY, Quadtree& qt);
};