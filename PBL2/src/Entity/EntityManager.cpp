#include "EntityManager.h"
#include "Monster.h"
#include "Castle.h"
#include "Character.h"
#include <iostream>
#include <CollisionManager.h>
#include "Map.h"

using namespace std;

struct ResourceInfo
{
    ResourceType type;
    float xs; // ti te ra
    std::string filename;
    int gold;
    int exp;
    float scale;
};

ResourceInfo resourceInfos[] = {
    {ResourceType::Wood, 0.2f, "assets/resource/wood.png", 5, 2, 0.23},
    {ResourceType::Stone, 0.15f, "assets/resource/stone.png", 5, 2, 0.5},
    {ResourceType::Sand, 0.13f, "assets/resource/sand.png", 4, 2, 0.3},
    {ResourceType::Coal, 0.13f, "assets/resource/coal.png", 7, 10, 0.3},
    {ResourceType::Iron, 0.12f, "assets/resource/iron.png", 8, 15, 0.2},
    {ResourceType::Gold, 0.09f, "assets/resource/gold.png", 8, 20, 0.3},
    {ResourceType::Diamond, 0.09f, "assets/resource/diamond.png", 20, 30, 0.5},
    {ResourceType::Emerald, 0.09f, "assets/resource/emerald.png", 25, 35, 0.3}};


EntityManager::EntityManager(const Rect &area, double cap)
    : qt(area, cap)
{
}

EntityManager::~EntityManager()
{
    for (auto *e : entities)
    {
        if (e != player && e != castle) // không xóa player và castle
            delete e;
            e = nullptr;
    }
    entities.clear();
}

void EntityManager::add(Entity *e)
{
    entities.push_back(e);
    qt.insert(e);
}

void EntityManager::remove(Entity *e)
{
    qt.remove(e);
    entities.remove(e);
    delete e;
    e = nullptr;
}

Character *EntityManager::getPlayer() { return player; }

Castle *EntityManager::getCastle() { return castle; }

Vector<Entity *> &EntityManager::getEntities()
{
    return entities;
}

Quadtree &EntityManager::getQuadtree()
{
    return qt;
}


void EntityManager::set_player(Character *value) { player = value; }
void EntityManager::set_castle(Castle *value) { castle = value; }

void EntityManager::update(float dt, /*Vector<Vector<ASNode>> &grid, double cellSize,*/ Map &map, EntityManager &manager)
{
    Castle *castle = getCastle();
    Character *player = getPlayer();

    // map.updateGrid(manager.getEntities(), grid, cellSize);

    // TẠO COLLISION MANAGER (hoặc truyền từ ngoài vào)
    static CollisionManager collisionMgr;

    for (auto *e : entities) // duyet tat ca vat the
    {
        if (Monster *m = dynamic_cast<Monster *>(e))
        {
            // quai tim duong tan cong bang A*
            m->update(dt, castle, player, &qt /*grid, cellSize*/, &collisionMgr);
        }
    }
    castle->update(dt);
    player->update(dt);
    updateQuadtree();
}

void EntityManager::render(sf::RenderWindow &window)
{
    for (auto *e : entities)
        e->draw(window);
    castle->render(window);
    player->draw(window);
}

void EntityManager::rebuildQuadtree(const Rect& newArea) {
    qt.clear();
    qt = Quadtree(newArea, qt.get_capacity()); // Giả sử có hàm get_capacity
    for (auto* e : entities) {
        qt.insert(e);
    }
}

bool isOverlapping(const sf::Sprite &s1, const sf::Sprite &s2)
{
    return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
}

void EntityManager::create_monster(int n, int hp, int damage, int damagerange)
{
    sf::Sprite tempSprite; // sprite tam

    for (int i = 0; i < n; i++)
    {
        bool check = false; // false la khong duoc tao, true la duoc tao
        while (!check)
        {
            // random mot vi tri cho linh
            float x = rand() % 8000 - 50 + 25;
            float y = rand() % 8000 - 50 + 25;
            tempSprite.setPosition(x, y);
            check = true;

            // kiem tra vi tri moi co chong len nhung vat the hien co trong game khong
            for (auto *e : entities)
            {
                if (isOverlapping(tempSprite, e->get_sprite()))
                {
                    check = false; // neu nhu chong len thi khog duoc
                    break;
                }
            }
        }
        Monster *m = new Monster(tempSprite.getPosition().x, tempSprite.getPosition().y, hp, damage, damagerange, 0.5, 10, 20);
        add(m);
    }
}

ResourceInfo choose() // ap dung thay Tu day lien:))))
{
    float r = static_cast<float>(rand()) / RAND_MAX; // 0~1
    float sum = 0.f;
    for (auto &info : resourceInfos)
    {
        sum += info.xs;
        if (r <= sum)
            return info;
    }
    return resourceInfos[0];
}

void EntityManager::create_resource(int n)
{
    sf::Sprite tempSprite;
    sf::Texture tempTexture;

    for (int i = 0; i < n; i++)
    {
        bool check = false;
        ResourceInfo info = choose();


        while (!check)
        {
            float x = rand() % 8000 - 50 + 25;
            float y = rand() % 7900 - 50 + 25;
            tempSprite.setPosition(x, y);
            check = true;

            for (auto *e : entities)
            {
                if (isOverlapping(tempSprite, e->get_sprite()))
                {
                    check = false;
                    break;
                }
            }
        }

        Resource *r = new Resource(tempSprite.getPosition().x, tempSprite.getPosition().y, info.type, info.filename, info.gold, info.exp, info.scale);
        add(r);
    }
}

void EntityManager::clear()
{
    // Xóa tất cả entities
    for (int i = 0; i < entities.get_size(); i++)
        delete entities[i];
    entities.clear();

    // Reset con trỏ
    player = nullptr;
    castle = nullptr;
    boss = nullptr;

    // Reset quadtree
    qt.clear();
}

void EntityManager::updateQuadtree()
{
    qt.clear(); // xóa hết
    for (auto *e : entities)
    {
        if (!e->get_status())
            continue; // bỏ qua nếu entity không còn hoạt động
        qt.insert(e); // insert lại theo vị trí mới
    }
}

void EntityManager::spawnBoss(int hp, int damage, int damageRange, double attackSpeed)
{
    // Tính damage dựa trên yêu cầu: 1 đòn = 1/5 HP player max level
    // Player level max (10) có HP max = 200 + 50*10 = 700
    // => damage = 700 / 5 = 140
    
    // Vị trí spawn boss (ví dụ: giữa map)
    int bossX = 3250;
    int bossY = 3050;
    
    boss = new Boss(bossX, bossY, hp, damage, damageRange, attackSpeed);
    add(boss);
    
    std::cout << "Boss spawned at (" << bossX << ", " << bossY << ")\n";
    std::cout << "Boss HP: " << hp << ", Damage: " << damage << "\n";
}

void EntityManager::clearMonsters()
{
    // Xóa tất cả Monster (không phải Boss, Player, Castle, Resource)
    for (int i = entities.get_size() - 1; i >= 0; i--)
    {
        Entity* e = entities[i];
        
        // Kiểm tra nếu là Monster thường (không phải Boss)
        if (Monster* m = dynamic_cast<Monster*>(e))
        {
            if (dynamic_cast<Boss*>(m) == nullptr)  // Không phải Boss
            {
                remove(e);
            }
        }
    }
    
    std::cout << "All normal monsters cleared!\n";
}



