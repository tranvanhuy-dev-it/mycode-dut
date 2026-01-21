#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include "Vector.h"
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Character.h"
#include "Quadtree.h"
#include "Boss.h"

class Map;
class EntityManager
{
private:
    Vector<Entity *> entities; // tat ca cac vat the
    Quadtree qt;               // cay quadtree

    Character *player = nullptr;
    Castle *castle = nullptr;
    Boss* boss = nullptr;

public:
    EntityManager(const Rect &, double);
    ~EntityManager();

    void add(Entity *);
    void remove(Entity *);

    Character *getPlayer();
    Castle *getCastle();
    Vector<Entity *> &getEntities();
    Quadtree &getQuadtree();

    void set_player(Character *);
    void set_castle(Castle *);

    void update(float, /*Vector<Vector<ASNode>>&, double,*/ Map &, EntityManager &);
    void render(sf::RenderWindow &);

    Vector<Entity *> queryRange(const Rect &);

    void rebuildQuadtree(const Rect &newArea);
    void create_monster(int, int, int, int);
    void create_resource(int);

    void clear();

    void updateQuadtree();

     // Getter/Setter cho Boss
    Boss* getBoss() { return boss; }
    void set_boss(Boss* value) { boss = value; }
    
    // Spawn Boss
    void spawnBoss(int hp, int damage, int damageRange, double attackSpeed);
    
    // Xóa tất cả Monster thường (khi Boss xuất hiện)
    void clearMonsters();
};

#endif
