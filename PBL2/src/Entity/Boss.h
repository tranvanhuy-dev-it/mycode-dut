#pragma once
#include "LivingEntity.h"
#include "Character.h"
#include "Castle.h"
#include "Quadtree.h"
#include <SFML/Graphics.hpp>

// Trạng thái Boss
enum class BossState
{
    Idle,           // Đứng yên
    Moving,         // Di chuyển
    Charging,       // Tích chiêu
    Attacking,      // Tấn công
    Hurt,           // Bị thương
    Dying,          // Đang chết
    Dead            // Đã chết
};

class Boss : public LivingEntity
{
private:
    // Combat stats
    int damage;
    double damage_range;
    double attack_speed;
    float attackcooldown;
    float chargeTime;        // Thời gian tích chiêu
    float chargeTimer;       // Đếm thời gian tích chiêu
    
    // Animation
    sf::Texture idleTexture;
    sf::Texture moveTexture;
    sf::Texture chargeTexture;
    sf::Texture attackTexture;
    sf::Texture hurtTexture;
    sf::Texture deathTexture;
    
    BossState currentState;
    BossState previousState;
    
    // Animation frame
    int currentFrame;
    float frameTime;
    float frameTimer;
    int totalFrames;
    sf::IntRect frameRect;
    
    // HP Bar
    sf::RectangleShape hpBack;
    sf::RectangleShape hpBar;
    sf::Vector2f hpBarSize;
    
    // Movement
    float speed;
    sf::Vector2f moveDir;
    float moveTimer;
    float moveDuration;      // Thời gian di chuyển trước khi dừng
    
    // Attack effects
    sf::CircleShape attackCircle;
    float attackCircleTimer;
    
    // Map bounds
    float minX, maxX, minY, maxY;
    
    // Phase system
    int phase;
    
    // Hurt flash effect
    bool isFlashing;
    float flashTimer;
    sf::Color normalColor;
    
    // Death animation
    float deathTimer;
    bool deathAnimationFinished;
    
public:
    Boss();
    Boss(int x, int y, int hp_max, int damage, double damage_range, double attack_speed);
    ~Boss();
    
    void draw(sf::RenderWindow& window) override;
    void update(float deltaTime, Castle* castle, Character* player, Quadtree* qt);
    
    // State management
    void setState(BossState newState);
    BossState getState() const { return currentState; }
    
    // Animation
    void updateAnimation(float deltaTime);
    void loadAnimations();
    
    // Combat
    void performAttack(LivingEntity* target);
    void take_damage(int value) override;
    
    // Movement
    void updateMovement(float deltaTime, sf::Vector2f targetPos);
    void randomWander(float deltaTime);
    
    // Getters
    int get_damage() const { return damage; }
    int get_phase() const { return phase; }
    bool isDeadAnimationFinished() const { return deathAnimationFinished; }
    void attack(Character* player, Castle* castle);
};