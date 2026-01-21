#pragma once
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "String.h"

using namespace std;

class Entity // class dai dien cho mot vat the
{
protected:
    int x, y;          // toa do
    bool walkable;     // di qua duoc hay khong
    string type;
    sf::Sprite sprite; // Hinh anh duoc hien thi tren game
    bool status = true;

    bool isCollidable = true;      // Có kiểm tra va chạm không
    bool isSolid = false;          // Có chặn vật khác không (tường, cây,...)
    float collisionRadius = 0.f;   // Bán kính va chạm (cho tối ưu)


public:
    Entity();
    Entity(int, int);
    int get_x() const;
    int get_y() const;
    string get_type() const;

    void set_position(int, int);
    bool is_walkable() const;
    sf::Sprite get_sprite() const;
    virtual void draw(sf::RenderWindow &); // ve hinh anh ra cua so game
    virtual bool get_status() const { return status; }

    bool getIsCollidable() const;
    void setIsCollidable(bool value);
    
    bool getIsSolid() const;
    void setIsSolid(bool value);
    
    float getCollisionRadius() const;
    void setCollisionRadius(float r);
    
    // HÀM PHỤ TRỢ LẤY VỊ TRÍ TRUNG TÂM
    sf::Vector2f getCenter() const;
};
