#include <SFML/Graphics.hpp>
#include <iostream>
#include "WeaponCraftUI.h"
#include "EntityManager.h"
#include "CharacterUI.h"
#include "UpgradeCastleUI.h"
#include "WeaponSelectUI.h"
#include "Quest.h"
#include "CameraController.h"
#include "Menu.h"
#include "Map.h"
#include "Audio.h"
#include "Intro.h"
#include "TileMap.h"
#include "CollisionManager.h"
#include "BossFightUI.h"
#include "Boss.h"

enum class GameState
{
    Menu,
    Intro,
    Playing,
    GameOver,
    Win
};

// --- Reset functions ---
void resetGame(EntityManager &manager, Character *&player, Castle *&castle, bool &bossDefeated)
{
    manager.clear();
    // bossDefeated = false;

    player = new Character(4000.f, 4200.f, 200, 50, 3);
    castle = new Castle(4000.f, 4200.f, 500, 50);
    manager.set_player(player);
    manager.add(player);
    manager.set_castle(castle);
    manager.add(castle);
    manager.create_monster(150, 50, 10, 80);
    manager.create_resource(480);
    bossDefeated = false;
}

void resetResourcesAndMonsters(EntityManager &manager, double CELL_SIZE, int hp, int damage, int damageRange)
{
    Vector<Entity *> entities = manager.getEntities();
    for (int i = 0; i < entities.get_size(); i++)
    {
        Entity *e = entities[i];
        if (dynamic_cast<Monster *>(e) || dynamic_cast<Resource *>(e))
            manager.remove(e);
    }
    manager.create_monster(150, hp, damage, damageRange);
    manager.create_resource(480);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "FORTRESS OF SURVIVAL");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("assets/font/font1.ttf"))
    {
        std::cerr << "[ERROR] Khong the load font!" << std::endl;
        return EXIT_FAILURE;
    }

    Audio gameloopaudio("assets/audio/loop.ogg"),
        menuaudio("assets/audio/menu.ogg"),
        gameoveraudio("assets/audio/over.ogg"),
        winaudio("assets/audio/win.ogg");

    // --- Intro ---
    Intro intro;

    // --- UI ---
    Menu menu(1920, 1080, "FORTRESS OF SURVIVAL", "PLAY GAME", "EXIT"),
        over(1920, 1080, "GAME OVER", "PLAY AGAIN", "EXIT"),
        win(1920, 1080, "YOU WIN", "PLAY AGAIN", "EXIT");

    CharacterUI ui;
    WeaponCraftUI craftUI(window);
    UpgradeCastleUI upgradeUI;
    Quest task;

    BossFightUI bossUI;

    // Thêm biến tracking Boss fight
    bool bossDefeated = false;
    // ================ MAP & TILEMAP SETUP ===========
    double CELL_SIZE = 32.0;
    sf::Clock clock;

    std::cout << "[INFO] Bat dau load map..." << std::endl;

    // Load Map data
    Map gameMap;
    if (!gameMap.load_File("assets/map/mapdata.txt"))
    {
        std::cerr << "[ERROR] Khong the load file map: assets/map/mapdata.txt" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "[SUCCESS] Load map thanh cong" << std::endl;

    int mapWidth = gameMap.get_width();
    int mapHeight = gameMap.get_height();
    std::cout << "[INFO] Map size: " << mapWidth << " x " << mapHeight << std::endl;

    // Kiểm tra map có hợp lệ không
    if (mapWidth <= 0 || mapHeight <= 0)
    {
        std::cerr << "[ERROR] Map size khong hop le: " << mapWidth << "x" << mapHeight << std::endl;
        return EXIT_FAILURE;
    }

    // Setup world bounds based on map size
    sf::FloatRect worldBounds(0, 0, mapWidth * CELL_SIZE, mapHeight * CELL_SIZE);
    std::cout << "[INFO] World bounds: " << worldBounds.width << "x" << worldBounds.height << std::endl;

    // Load TileMap
    TileMap tileMap;
    if (!tileMap.LoadTileset("assets/map/Tileset.png", sf::Vector2u((unsigned int)CELL_SIZE, (unsigned int)CELL_SIZE)))
    {
        std::cerr << "[ERROR] Khong the load tileset: assets/map/Tileset.png" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "[SUCCESS] Load tileset thanh cong" << std::endl;

    // Build TileMap từ gameMap
    tileMap.buildMap(gameMap);
    std::cout << "[SUCCESS] TileMap da duoc xay dung" << std::endl;

    // Kiểm tra texture đã load
    if (!tileMap.is_TextureLoaded())
    {
        std::cerr << "[ERROR] Texture chua duoc load" << std::endl;
        return EXIT_FAILURE;
    }

    // Setup Camera
    CameraController camera(sf::Vector2f(1920, 1080), worldBounds);

    // Setup EntityManager with QuadTree
    Rect worldRect(0, 0, worldBounds.width, worldBounds.height);
    EntityManager manager(worldRect, 10);
    manager.rebuildQuadtree(worldRect);

    // ================= A* GRID SETUP ==================
    std::vector<std::vector<ASNode>> astarGrid;
    astarGrid.resize(mapHeight);

    for (int i = 0; i < mapHeight; ++i)
    {
        astarGrid[i].resize(mapWidth);
        for (int j = 0; j < mapWidth; ++j)
        {
            astarGrid[i][j].set_position(i, j);
            bool isWalkable = gameMap.isWalkable(i, j);
            astarGrid[i][j].set_walkable(isWalkable);
        }
    }
    std::cout << "[SUCCESS] A* Grid da duoc khoi tao (" << mapHeight << "x" << mapWidth << ")" << std::endl;

    // ================= GAME ENTITIES ==================
    Character *player = new Character(4000.f, 4200.f, 200, 50, 3);
    Castle *castle = new Castle(4000.f, 4000.f, 500, 50);
    WeaponSelectUI weaponselect(window, player);

    manager.set_player(player);
    manager.add(player);
    manager.set_castle(castle);
    manager.add(castle);

    manager.create_monster(150, 50, 10, 80);
    manager.create_resource(480);

    std::cout << "[SUCCESS] Khoi tao game entities thanh cong" << std::endl;

    // --- Game state ---
    GameState state = GameState::Menu;
    menuaudio.setLoop(true);
    menuaudio.playSound();
    gameloopaudio.setLoop(true);

    auto playMusicForState = [&](GameState s)
    {
        gameloopaudio.stopSound();
        menuaudio.stopSound();
        gameoveraudio.stopSound();
        winaudio.stopSound();
        switch (s)
        {
        case GameState::Menu:
            menuaudio.playSound();
            break;
        case GameState::Playing:
            gameloopaudio.playSound();
            break;
        case GameState::GameOver:
            gameoveraudio.playSound();
            break;
        case GameState::Win:
            winaudio.playSound();
            break;
        default:
            break;
        }
    };

    // --- Message for level reset ---
    sf::Text levelMessage;
    levelMessage.setFont(font);
    levelMessage.setCharacterSize(80);
    levelMessage.setFillColor(sf::Color::Green);
    levelMessage.setStyle(sf::Text::Bold);
    levelMessage.setPosition(683 - 300, 100); // Centered for 1920 width

    sf::Clock messageClock;
    bool showMessage = false;

    int resetDone = 0;

    CollisionManager collisionManager;
    std::cout << "[SUCCESS] Collision Manager da duoc khoi tao" << std::endl;

    std::cout << "[SUCCESS] Bat dau game loop" << std::endl;

    // --- Main loop ---
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            switch (state)
            {
            case GameState::Menu:
            {
                int action = menu.handleEvent(event, window);
                if (action == 1)
                {
                    state = GameState::Intro;
                    playMusicForState(state);
                }
                else if (action == 2)
                    window.close();
                break;
            }

            case GameState::Intro:
            {
                menuaudio.stopSound();
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                {
                    intro.next();
                    if (intro.isFinished())
                    {
                        state = GameState::Playing;
                        playMusicForState(state);
                    }
                }
                break;
            }

            case GameState::Playing:
            {
                if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space))
                    player->attack(manager.getQuadtree(), task);

                craftUI.handleEvent(event, player, window);
                upgradeUI.handleEvent(event, player, castle, window);
                weaponselect.handleEvent(event, window);
                task.handleEvent(event, window);
                camera.handleEvent(event);
                break;
            }

            case GameState::GameOver:
            {
                int action = over.handleEvent(event, window);
                if (action == 1)
                {
                    resetGame(manager, player, castle, bossDefeated);
                    resetDone = 0;
                    state = GameState::Playing;
                    playMusicForState(state);
                }
                else if (action == 2)
                    window.close();
                break;
            }

            case GameState::Win:
            {
                int action = win.handleEvent(event, window);
                if (action == 1)
                {
                    resetGame(manager, player, castle, bossDefeated);
                    resetDone = 0;
                    state = GameState::Playing;
                    playMusicForState(state);
                }
                else if (action == 2)
                    window.close();
                break;
            }
            }
        }

        // --- Update ---
        float dt = clock.restart().asSeconds();
        window.clear(sf::Color(40, 40, 40));

        switch (state)
        {
        case GameState::Menu:
            menu.render(window);
            break;

        case GameState::Intro:
            intro.update(dt);
            intro.draw(window);
            break;

        case GameState::Playing:
        {
            std::cout << "Player HP: " << player->get_hp()
                      << "/" << player->get_hp_max()
                      << " | Status: " << player->get_status() << std::endl;
            std::cout << "Castle HP: " << castle->get_hp()
                      << "/" << castle->get_hp_max()
                      << " | Status: " << castle->get_status() << std::endl;

            player->handleInput(dt, &collisionManager, &manager.getQuadtree());

            // ========== XỬ LÝ BOSS FIGHT ==========
            bossUI.handleEvent(event, window, player);

            // Khi người chơi xác nhận đánh Boss
            if (bossUI.isBossFight() && !manager.getBoss())
            {
                // Xóa tất cả Monster thường
                manager.clearMonsters();

                // Tính damage Boss dựa trên level player
                // Level max (10): HP = 200 + 50*9 = 650
                // Damage = 650 / 5 = 130
                int playerMaxHp = 200 + 50 * 9; // Level 10
                int bossDamage = playerMaxHp / 5;

                // HP Boss tùy theo level player
                int bossHp = 2000 + player->get_level() * 50;

                // Spawn Boss
                manager.spawnBoss(
                    bossHp,     // HP
                    bossDamage, // Damage
                    150,        // Damage range
                    0.8         // Attack speed (chậm nhưng mạnh)
                );

                std::cout << "Boss Fight Started!\n";
                std::cout << "Player Level: " << player->get_level() << "\n";
                std::cout << "Boss HP: " << bossHp << ", Damage: " << bossDamage << "\n";
            }

            // Update Boss UI
            bossUI.update(manager.getBoss());

            // Kiểm tra Boss đã chết
            if (bossUI.isBossFight() && manager.getBoss() && !manager.getBoss()->get_status())
            {
                bossDefeated = true;
                bossUI.setBossFight(false);

                // Thưởng khi giết Boss
                player->incr_gold(500);
                player->incr_exp(500);

                std::cout << "Boss Defeated! Rewards: +500 Gold, +500 EXP\n";

                // Spawn lại Monster thường sau khi Boss chết
                manager.create_monster(60, 50, 10, 80);
                manager.create_resource(150);
            }

            // ========================================

            manager.update(dt, gameMap, manager);

            // --- Level reset logic ---
            if (resetDone == 0 && player->get_level() >= 3)
            {
                levelMessage.setString("Level moi! Tai nguyen & Quai vat da reset!");
                messageClock.restart();
                showMessage = true;
                resetResourcesAndMonsters(manager, CELL_SIZE, 70, 15, 100);
                resetDone++;
            }
            else if (resetDone == 1 && player->get_level() >= 5)
            {
                levelMessage.setString("Level moi! Tai nguyen & Quai vat da reset!");
                messageClock.restart();
                showMessage = true;
                resetResourcesAndMonsters(manager, CELL_SIZE, 70, 20, 150);
                resetDone++;
            }
            else if (resetDone == 2 && player->get_level() >= 7)
            {
                levelMessage.setString("Level moi! Tai nguyen & Quai vat da reset!");
                messageClock.restart();
                showMessage = true;
                resetResourcesAndMonsters(manager, CELL_SIZE, 80, 25, 250);
                resetDone++;
            }
            else if (resetDone == 3 && player->get_level() >= 9)
            {
                levelMessage.setString("Level moi! Tai nguyen & Quai vat da reset!");
                messageClock.restart();
                showMessage = true;
                resetResourcesAndMonsters(manager, CELL_SIZE, 80, 30, 350);
                resetDone++;
            }

            // --- Check game over ---
            if (!player->get_status() || !castle->get_status())
            {
                state = GameState::GameOver;
                playMusicForState(state);
                break;
            }

            // === CHECK WIN CONDITION (cập nhật) ===
            bool hasAllWeapons = (player->get_weapons().get_size() == 6);
            bool maxLevel = (player->get_level() >= 10);
            bool maxCastle = (castle->get_level() >= 5);
            bool defeatedBoss = bossDefeated; // ← THÊM điều kiện

            if (hasAllWeapons && maxLevel && maxCastle && defeatedBoss)
            {
                state = GameState::Win;
                playMusicForState(state);
                break;
            }

            // === BẮT BUỘC ĐẦU BOSS Ở LEVEL MAX ===
            if (maxLevel && maxCastle && !bossDefeated && !bossUI.isBossFight())
            {
                // Tự động kích hoạt Boss fight
                if (!manager.getBoss())
                {
                    bossUI.setBossFight(true);
                    bossUI.showNotificationText("PHAI TIEU DIET BOSS DE THANG GAME!", sf::Color::Red);
                }
            }

            // --- Camera follow player ---
            camera.follow(player->get_position() + player->getSize() / 2.f);
            camera.handleInput(window, dt);

            // --- Render with camera view ---
            window.setView(camera.getView());

            // QUAN TRỌNG: Dùng drawVisible thay vì draw
            sf::RenderStates states = sf::RenderStates::Default;
            tileMap.drawVisible(window, states, camera.getView());

            // Render entities
            manager.render(window);

            // Draw current weapon
            auto &weapons = player->get_weapons();
            if (weapons.get_size() > 0)
            {
                weapons[player->get_indexWeapon()]->draw(window);
            }

            // Reset to default view for UI
            window.setView(window.getDefaultView());

            // --- Render UI ---
            ui.update(player, window);
            ui.render(window, player);
            upgradeUI.render(window, castle);
            weaponselect.update(window);
            weaponselect.render(window);
            craftUI.render(window, player);
            task.render(window);
            bossUI.render(window, manager.getBoss());

            // --- Show level message ---
            if (showMessage)
            {
                window.draw(levelMessage);
                if (messageClock.getElapsedTime().asSeconds() > 5.f)
                    showMessage = false;
            }

            break;
        }

        case GameState::GameOver:
            over.render(window);
            break;

        case GameState::Win:
            win.render(window);
            break;
        }

        window.display();
    }

    manager.clear();
    return 0;
}