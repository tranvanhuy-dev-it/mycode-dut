#pragma once
#include "LivingEntity.h"
#include "Monster.h"
#include "Quadtree.h"
#include "Weapons.h"
#include "Bag.h"
#include "Castle.h"
#include "String.h"
#include "Quest.h"
#include <sstream>
// dung trong ham craft_weapon()

class CollisionManager;
struct Recipe // cong thuc che che tao vu khi
{
    int wood;
    int stone;
    int sand;
    int coal;
    int iron;
    int gold;
    int diamond;
    int emerald;
};

extern Recipe recipes[];

class Castle;

class Character : public LivingEntity
{
private:
    int level;
    int gold;
    int exp;
    int exp_max;
    Bag bag;
    int lives;
    Vector<Weapons *> weapons;
    int indexWeapon; // chi so cua vu khi trong vecto

    sf::Texture up;
    sf::Texture right_cung, right_kiemgo, right_kiemsat, right_riu, right_sung, right_hand;
    sf::Texture down_cung, down_kiemgo, down_kiemsat, down_riu, down_sung, down_hand;
    sf::Texture left_cung, left_kiemgo, left_kiemsat, left_riu, left_sung, left_hand;

    sf::Vector2f velocity;           // Vận tốc hiện tại
    sf::Vector2f lastValidPosition;  // Vị trí hợp lệ cuối cùng
    bool isColliding;                // Đang va chạm hay không
    float pushbackForce;             // Lực đẩy lùi khi va chạm

public:
    Character();
    Character(int, int, int, int, int);
    ~Character();

    int get_gold() const; // lay so vang hien co
    int get_exp() const;  // lay kinh nghiem hien co
    int get_exp_max() const;
    Bag get_bag() const;
    Bag &get_bag();
    int get_indexWeapon() const;
    int get_level() const; // lay ra level
    Vector<Weapons *> &get_weapons();
    int get_resource_amount(ResourceType type) const;
    sf::Vector2f get_position() const;
    sf::Vector2f getSize() const;
    bool get_status() const;
    int get_lives() const;

    // THÊM GETTERS/SETTERS CHO COLLISION
    sf::Vector2f getVelocity() const { return velocity; }
    void setVelocity(const sf::Vector2f& v) { velocity = v; }
    
    sf::Vector2f getLastValidPosition() const { return lastValidPosition; }
    void setLastValidPosition(const sf::Vector2f& pos) { lastValidPosition = pos; }
    
    bool getIsColliding() const { return isColliding; }
    void setIsColliding(bool value) { isColliding = value; }
    

    void set_indexWeapon(int);
    void setScale(float, float); // doi kich co cua anh

    void incr_gold(int); // tang vang len
    void incr_exp(int);  // tang kinh nghiem len
    void decr_gold(int); // giam vang xuong khi xay nha
    void decr_exp(int);  // giam kinh nghiem

    void levelUp(); // tang level
    void level_up_castle(Castle *);

    void handleInput(double, CollisionManager* collisionMgr, Quadtree* qt); // di chuyen bang tay

    void update(float); // di chuyen

    void attack(Quadtree &, Quest &task); // tan cong.....tham so dau vao la mot vecto cac Monster

    void add_weapon(Weapons *);
    void switch_weapon(int index);
    bool craft_weapon(WeaponType);
    void take_damage(int value) override;

     // THÊM HÀM XỬ LÝ VA CHẠM
    void onCollision(Entity* other);  // Callback khi va chạm
    void savePosition();              // Lưu vị trí trước khi di chuyển
    void restorePosition();           // Khôi phục vị trí nếu va chạm không hợp lệ

};