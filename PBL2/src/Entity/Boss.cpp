#include "Boss.h"
#include "Audio.h"
#include <cmath>
#include <iostream>

Boss::Boss() {}

Boss::Boss(int x, int y, int hp_max, int damage, double damage_range, double attack_speed)
    : LivingEntity(x, y, hp_max),
      damage(damage),
      damage_range(damage_range),
      attack_speed(attack_speed),
      phase(1),
      currentState(BossState::Idle),
      previousState(BossState::Idle),
      currentFrame(0),
      frameTime(0.1f),
      frameTimer(0.f),
      chargeTime(1.5f),
      chargeTimer(0.f),
      isFlashing(false),
      flashTimer(0.f),
      deathTimer(0.f),
      deathAnimationFinished(false)
{
    attackcooldown = 0.f;
    type = "Boss";

    // Load animations
    loadAnimations();

    // Setup sprite
    sprite.setTexture(idleTexture);
    sprite.setPosition(x, y);
    sprite.setScale(2.5f, 2.5f); // Boss lớn hơn
    normalColor = sf::Color::White;

    // HP Bar
    hpBarSize = sf::Vector2f(250.f, 20.f);
    hpBack.setSize(hpBarSize);
    hpBack.setFillColor(sf::Color(100, 100, 100));
    hpBack.setOutlineColor(sf::Color::Red);
    hpBack.setOutlineThickness(3.f);
    hpBar.setFillColor(sf::Color::Red);

    // Movement
    speed = 100.f;
    moveDir = {0.f, 0.f};
    moveTimer = 0.f;
    moveDuration = 2.f;

    // Attack circle
    attackCircle.setRadius(damage_range);
    attackCircle.setOrigin(damage_range, damage_range);
    attackCircle.setFillColor(sf::Color(255, 0, 0, 80));
    attackCircleTimer = 0.f;

    // Map bounds
    minX = 100.f;
    maxX = 7900.f;
    minY = 100.f;
    maxY = 7900.f;

    // Initial state
    setState(BossState::Moving);
}

Boss::~Boss() {}

void Boss::loadAnimations()
{
    // Dựa vào sprite sheet của bạn:
    // Row 1: Idle/Move (4 frames)
    // Row 2: Move/Charge/Attack (4 frames)
    // Row 3: Hurt/Death (4 frames)

    // Load main sprite sheet
    sf::Texture mainSheet;
    if (!mainSheet.loadFromFile("assets/boss/boss_spritesheet.png"))
    {
        std::cout << "Error loading boss spritesheet, using fallback\n";
        // Fallback
        idleTexture.loadFromFile("assets/monster/Monster.png");
        moveTexture = idleTexture;
        chargeTexture = idleTexture;
        attackTexture = idleTexture;
        hurtTexture = idleTexture;
        deathTexture = idleTexture;
        return;
    }

    // Giả sử mỗi frame 128x128 pixels
    int frameWidth = 128;
    int frameHeight = 128;

    sf::Image img = mainSheet.copyToImage();

    // Move (row 0)
    moveTexture.loadFromImage(img, sf::IntRect(0, 0, frameWidth * 4, frameHeight));

    // Attack (row 1)
    attackTexture.loadFromImage(img, sf::IntRect(0, frameHeight, frameWidth * 4, frameHeight));

    // Hurt (row 2)
    hurtTexture.loadFromImage(img, sf::IntRect(0, frameHeight * 2, frameWidth * 4, frameHeight));
}

void Boss::setState(BossState newState)
{
    if (currentState == newState)
        return;

    previousState = currentState;
    currentState = newState;
    currentFrame = 0;
    frameTimer = 0.f;

    // Set texture và frame count theo state
    switch (currentState)
    {
    case BossState::Idle:
        sprite.setTexture(idleTexture);
        totalFrames = 4;
        frameTime = 0.15f;
        break;

    case BossState::Moving:
        sprite.setTexture(moveTexture);
        totalFrames = 4;
        frameTime = 0.12f;
        moveTimer = moveDuration;
        break;

    case BossState::Charging:
        sprite.setTexture(chargeTexture);
        totalFrames = 2;
        frameTime = 0.3f;
        chargeTimer = chargeTime;
        break;

    case BossState::Attacking:
        sprite.setTexture(attackTexture);
        totalFrames = 2;
        frameTime = 0.2f;
        break;

    case BossState::Hurt:
        sprite.setTexture(hurtTexture);
        totalFrames = 4;
        frameTime = 0.1f;
        isFlashing = true;
        flashTimer = 0.4f;
        break;

    case BossState::Dying:
        sprite.setTexture(deathTexture);
        totalFrames = 1;
        frameTime = 0.2f;
        deathTimer = 2.f; // Animation chết kéo dài 2s
        break;

    case BossState::Dead:
        deathAnimationFinished = true;
        break;
    }

    // Setup frame rect
    int frameWidth = sprite.getTexture()->getSize().x / totalFrames;
    int frameHeight = sprite.getTexture()->getSize().y;
    frameRect = sf::IntRect(0, 0, frameWidth, frameHeight);
    sprite.setTextureRect(frameRect);
}

void Boss::updateAnimation(float deltaTime)
{
    frameTimer += deltaTime;

    if (frameTimer >= frameTime)
    {
        frameTimer = 0.f;
        currentFrame++;

        // Loop animation (trừ death)
        if (currentState != BossState::Dying && currentState != BossState::Dead)
        {
            if (currentFrame >= totalFrames)
                currentFrame = 0;
        }
        else if (currentFrame >= totalFrames)
        {
            currentFrame = totalFrames - 1; // Giữ frame cuối
        }

        // Update texture rect
        int frameWidth = sprite.getTexture()->getSize().x / totalFrames;
        frameRect.left = currentFrame * frameWidth;
        sprite.setTextureRect(frameRect);
    }

    // Flash effect khi bị thương
    if (isFlashing)
    {
        flashTimer -= deltaTime;
        if (flashTimer <= 0.f)
        {
            isFlashing = false;
            sprite.setColor(normalColor);
        }
        else
        {
            // Nhấp nháy đỏ-trắng
            int flashCount = (int)(flashTimer * 10) % 2;
            sprite.setColor(flashCount == 0 ? sf::Color::Red : normalColor);
        }
    }
}

void Boss::updateMovement(float deltaTime, sf::Vector2f targetPos)
{
    if (currentState == BossState::Charging ||
        currentState == BossState::Attacking ||
        currentState == BossState::Hurt ||
        currentState == BossState::Dying ||
        currentState == BossState::Dead)
        return;

    moveTimer -= deltaTime;

    if (moveTimer > 0.f)
    {
        // Di chuyển về phía target
        sf::Vector2f bpos = sprite.getPosition();
        moveDir.x = targetPos.x - bpos.x;
        moveDir.y = targetPos.y - bpos.y;

        float len = std::sqrt(moveDir.x * moveDir.x + moveDir.y * moveDir.y);
        if (len > 0.f)
        {
            moveDir.x /= len;
            moveDir.y /= len;
        }

        x += moveDir.x * speed * deltaTime;
        y += moveDir.y * speed * deltaTime;

        // Clamp
        if (x < minX)
            x = minX;
        if (x > maxX)
            x = maxX;
        if (y < minY)
            y = minY;
        if (y > maxY)
            y = maxY;

        sprite.setPosition(x, y);

        if (currentState != BossState::Moving)
            setState(BossState::Moving);
    }
    else
    {
        // Dừng lại, chuẩn bị tích chiêu
        setState(BossState::Charging);
    }
}

void Boss::performAttack(LivingEntity *target)
{
    if (!target || !target->get_status())
        return;

    target->take_damage(damage);

    // Hiệu ứng
    attackCircleTimer = 0.3f;

    // Sound effect
    static Audio attackSound("assets/audio/boss_attack.ogg");
    attackSound.setVolume(50.f);
    attackSound.playSound();

    std::cout << "Boss attacked! Damage: " << damage << std::endl;
}

void Boss::take_damage(int value)
{
    if (currentState == BossState::Dying || currentState == BossState::Dead)
        return;

    hp -= value;

    if (hp <= 0)
    {
        hp = 0;
        status = false;
        setState(BossState::Dying);

        static Audio deathSound("assets/audio/boss_death.ogg");
        deathSound.setVolume(60.f);
        deathSound.playSound();
    }
    else
    {
        setState(BossState::Hurt);

        static Audio hurtSound("assets/audio/boss_hurt.ogg");
        hurtSound.setVolume(40.f);
        hurtSound.playSound();
    }
}

void Boss::update(float deltaTime, Castle *castle, Character *player, Quadtree *qt)
{
    if (currentState == BossState::Dead)
        return;

    // Update animation
    updateAnimation(deltaTime);

    // Death animation
    if (currentState == BossState::Dying)
    {
        deathTimer -= deltaTime;
        if (deathTimer <= 0.f)
        {
            setState(BossState::Dead);
        }
        return;
    }

    // Hurt state duration
    if (currentState == BossState::Hurt)
    {
        if (frameTimer >= frameTime * totalFrames * 0.8f) // Sau 80% animation
        {
            setState(BossState::Moving);
        }
        return;
    }

    // Target selection
    sf::Vector2f bpos = sprite.getPosition();
    sf::Vector2f ppos = player->get_sprite().getPosition();
    sf::Vector2f cpos = castle->get_sprite().getPosition();

    float d_player = std::hypot(bpos.x - ppos.x, bpos.y - ppos.y);
    float d_castle = std::hypot(bpos.x - cpos.x, bpos.y - cpos.y);

    sf::Vector2f targetPos = (d_player < d_castle ? ppos : cpos);
    LivingEntity *target = (d_player < d_castle ? static_cast<LivingEntity *>(player) : static_cast<LivingEntity *>(castle));
    float dist = std::min(d_player, d_castle);

    // Charging state
    if (currentState == BossState::Charging)
    {
        chargeTimer -= deltaTime;
        if (chargeTimer <= 0.f)
        {
            // Check nếu trong tầm đánh
            if (dist <= damage_range)
            {
                setState(BossState::Attacking);
            }
            else
            {
                setState(BossState::Moving);
            }
        }
        return;
    }

    // Attacking state
    if (currentState == BossState::Attacking)
    {
        if (attackcooldown <= 0.f)
        {
            performAttack(target);
            attackcooldown = 1.f / attack_speed;
        }

        // Sau khi tấn công xong, quay lại di chuyển
        if (frameTimer >= frameTime * totalFrames * 0.9f)
        {
            setState(BossState::Moving);
        }
        return;
    }

    // Cooldown
    if (attackcooldown > 0.f)
        attackcooldown -= deltaTime;

    // Movement
    updateMovement(deltaTime, targetPos);

    // Phase transition
    float hpPercent = (float)hp / hp_max;
    if (hpPercent < 0.5f && phase == 1)
    {
        phase = 2;
        speed *= 1.4f;
        attack_speed *= 1.3f;
        moveDuration *= 0.7f;
        std::cout << "Boss entered Phase 2! (Speed/AttackSpeed increased)\n";
    }

    // Update HP bar
    hpBar.setSize(sf::Vector2f(hpBarSize.x * hpPercent, hpBarSize.y));

    sf::FloatRect bounds = sprite.getGlobalBounds();
    hpBack.setPosition(
        bounds.left + bounds.width / 2.f - hpBarSize.x / 2.f,
        bounds.top - hpBarSize.y - 10.f);
    hpBar.setPosition(hpBack.getPosition());

    // Update attack circle
    if (attackCircleTimer > 0.f)
    {
        attackCircleTimer -= deltaTime;
        attackCircle.setPosition(
            bounds.left + bounds.width / 2.f,
            bounds.top + bounds.height / 2.f);
    }
}

void Boss::draw(sf::RenderWindow &window)
{
    if (currentState == BossState::Dead && deathAnimationFinished)
        return;

    // Vẽ attack circle
    if (attackCircleTimer > 0.f)
        window.draw(attackCircle);

    // Vẽ boss sprite
    window.draw(sprite);

    // Vẽ HP bar
    if (currentState != BossState::Dead)
    {
        window.draw(hpBack);
        window.draw(hpBar);
    }
}
