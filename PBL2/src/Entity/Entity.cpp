#include "Entity.h"

Entity::Entity() {}
Entity::Entity(int _x, int _y)
    : x(_x), y(_y) {};

int Entity::get_x() const { return x; }
int Entity::get_y() const { return y; }
string Entity::get_type() const { return type; }
void Entity::set_position(int newx, int newy)
{
       x = newx;
       y = newy;
}

sf::Sprite Entity::get_sprite() const { return this->sprite; }

bool Entity::is_walkable() const { return walkable; }

void Entity::draw(sf::RenderWindow &window) // tham chieu toi cua so game dang thuc thi
{
       window.draw(sprite);
}

bool Entity::getIsCollidable() const { return isCollidable; }
void Entity::setIsCollidable(bool value) { isCollidable = value; }

bool Entity::getIsSolid() const { return isSolid; }
void Entity::setIsSolid(bool value) { isSolid = value; }

float Entity::getCollisionRadius() const { return collisionRadius; }
void Entity::setCollisionRadius(float r) { collisionRadius = r; }

//  HÀM PHỤ TRỢ LẤY VỊ TRÍ TRUNG TÂM
sf::Vector2f Entity::getCenter() const
{
       sf::FloatRect bounds = sprite.getGlobalBounds();
       return sf::Vector2f(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
}
