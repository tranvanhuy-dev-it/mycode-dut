#include "BossFightUI.h"
#include "Audio.h"
#include <iostream>
#include <sstream>

BossFightUI::BossFightUI()
    : showDialog(false), 
      isBossFightActive(false),
      showNotification(false)
{
    if (!font.loadFromFile("assets/font/font1.ttf"))
        std::cout << "Font load failed!\n";
    
    // Nút khiêu chiến Boss (hình tròn)
    bossButton = CircleButton(40.f);
    bossButton.setPosition(50.f, 680.f);
    bossButton.setColor(sf::Color(200, 50, 50)); // Màu đỏ
    bossButton.setOutline(sf::Color::Black, 5.f);
    bossButton.setIconScale(0.125f, 0.125f);
    bossButton.setTexture("assets/icon/boss.png"); // Cần tạo icon này
    
    // Dialog background
    dialogBackground.setSize(sf::Vector2f(600.f, 400.f));
    dialogBackground.setFillColor(sf::Color(50, 50, 50, 230));
    dialogBackground.setOutlineColor(sf::Color::Red);
    dialogBackground.setOutlineThickness(5.f);
    
    // Confirm text
    confirmText.setFont(font);
    confirmText.setCharacterSize(50);
    confirmText.setFillColor(sf::Color::White);
    confirmText.setOutlineColor(sf::Color::Black);
    confirmText.setOutlineThickness(3.f);
    confirmText.setStyle(sf::Text::Bold);
    confirmText.setString("KHIEU CHIEN BOSS?\n\nBan co chac chan muon\ndoi dau voi Boss?\n\nCac monster se bien mat!");
    
    // Buttons
    const String yes = "CHIEN DAU";
    const String no = "HUY BO";
    
    confirmButton = RectangleButton(
        0.f, 0.f, 250.f, 60.f, &font, yes,
        sf::Color(150, 50, 50), 
        sf::Color(200, 80, 80), 
        sf::Color(180, 60, 60), 
        40
    );
    confirmButton.setTextColor(sf::Color::White);
    confirmButton.setOutline(sf::Color::Black, 3.f);
    
    cancelButton = RectangleButton(
        0.f, 0.f, 250.f, 60.f, &font, no,
        sf::Color(100, 100, 100), 
        sf::Color(150, 150, 150), 
        sf::Color(130, 130, 130), 
        40
    );
    cancelButton.setTextColor(sf::Color::White);
    cancelButton.setOutline(sf::Color::Black, 3.f);
    
    // Boss HP bar (top screen)
    bossHpBack.setSize(sf::Vector2f(800.f, 30.f));
    bossHpBack.setFillColor(sf::Color(80, 80, 80));
    bossHpBack.setOutlineColor(sf::Color::Red);
    bossHpBack.setOutlineThickness(3.f);
    
    bossHpBar.setFillColor(sf::Color::Red);
    
    bossNameText.setFont(font);
    bossNameText.setCharacterSize(30);
    bossNameText.setFillColor(sf::Color::Red);
    bossNameText.setOutlineColor(sf::Color::Black);
    bossNameText.setOutlineThickness(2.f);
    bossNameText.setStyle(sf::Text::Bold);
    bossNameText.setString("BOSS - CHUA TE BAO LUC");
    
    // Notification
    notificationText.setFont(font);
    notificationText.setCharacterSize(60);
}

void BossFightUI::handleEvent(sf::Event& event, sf::RenderWindow& window, Character* player)
{
    // Nút khiêu chiến
    if (bossButton.isClicked(window, event) || 
        (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X))
    {
        if (!isBossFightActive)
        {
            showDialog = true;
            static Audio clickSound("assets/audio/select.ogg");
            clickSound.playSound();
        }
        else
        {
            showNotificationText("Dang trong tran chien voi Boss!", sf::Color::Yellow);
        }
    }
    
    // Xử lý dialog
    if (showDialog)
    {
        if (confirmButton.isClicked(window, event) ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            // Kiểm tra level tối thiểu (ví dụ: >= 3)
            if (player->get_level() >= 3)
            {
                isBossFightActive = true;
                showDialog = false;
                showNotificationText("CHUAN BI CHIEN DAU VOI BOSS!", sf::Color::Red);
                
                static Audio bossSound("assets/audio/boss_start.ogg");
                bossSound.playSound();
            }
            else
            {
                showDialog = false;
                showNotificationText("Can it nhat Level 3 de doi dau Boss!", sf::Color::Yellow);
                
                static Audio errorSound("assets/audio/error.ogg");
                errorSound.playSound();
            }
        }
        
        if (cancelButton.isClicked(window, event) ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace))
        {
            showDialog = false;
        }
    }
}

void BossFightUI::render(sf::RenderWindow& window, Boss* boss)
{
    // Nút khiêu chiến (luôn hiển thị)
    bossButton.render(window);
    
    // Dialog xác nhận
    if (showDialog)
    {
        sf::Vector2u winSize = window.getSize();
        float centerX = winSize.x / 2.f;
        float centerY = winSize.y / 2.f;
        
        // Background
        dialogBackground.setPosition(
            centerX - dialogBackground.getSize().x / 2.f,
            centerY - dialogBackground.getSize().y / 2.f
        );
        window.draw(dialogBackground);
        
        // Text
        sf::FloatRect textBounds = confirmText.getLocalBounds();
        confirmText.setOrigin(
            textBounds.left + textBounds.width / 2.f,
            textBounds.top + textBounds.height / 2.f
        );
        confirmText.setPosition(centerX, centerY - 80.f);
        window.draw(confirmText);
        
        // Buttons
        confirmButton.setPosition(centerX - 270.f, centerY + 120.f);
        cancelButton.setPosition(centerX + 20.f, centerY + 120.f);
        
        confirmButton.update(window);
        cancelButton.update(window);
        
        confirmButton.render(window);
        cancelButton.render(window);
    }
    
    // Boss HP bar (khi đang đánh boss)
    if (isBossFightActive && boss && boss->get_status())
    {
        sf::Vector2u winSize = window.getSize();
        float centerX = winSize.x / 2.f;
        
        bossHpBack.setPosition(centerX - bossHpBack.getSize().x / 2.f, 50.f);
        
        float hpPercent = (float)boss->get_hp() / boss->get_hp_max();
        bossHpBar.setSize(sf::Vector2f(bossHpBack.getSize().x * hpPercent, bossHpBack.getSize().y));
        bossHpBar.setPosition(bossHpBack.getPosition());
        
        window.draw(bossHpBack);
        window.draw(bossHpBar);
        
        // Boss name + HP text
        std::stringstream ss;
        ss << "BOSS - CHUA TE BAO LUC  [HP: " << boss->get_hp() << "/" << boss->get_hp_max() << "]";
        bossNameText.setString(ss.str());
        
        sf::FloatRect nameBounds = bossNameText.getLocalBounds();
        bossNameText.setOrigin(
            nameBounds.left + nameBounds.width / 2.f,
            nameBounds.top + nameBounds.height / 2.f
        );
        bossNameText.setPosition(centerX, 25.f);
        window.draw(bossNameText);
    }
    
    // Notification
    if (showNotification)
    {
        if (notificationClock.getElapsedTime().asSeconds() < 3.f)
        {
            sf::Vector2u winSize = window.getSize();
            sf::FloatRect bounds = notificationText.getLocalBounds();
            notificationText.setOrigin(
                bounds.left + bounds.width / 2.f,
                bounds.top + bounds.height / 2.f
            );
            notificationText.setPosition(winSize.x / 2.f, winSize.y / 2.f - 200.f);
            window.draw(notificationText);
        }
        else
        {
            showNotification = false;
        }
    }
}

void BossFightUI::update(Boss* boss)
{
    // Kiểm tra boss đã chết chưa
    if (isBossFightActive && boss && !boss->get_status())
    {
        isBossFightActive = false;
        showNotificationText("BAN DA TIEU DIET BOSS!", sf::Color::Green);
    }
}

void BossFightUI::showNotificationText(const std::string& text, sf::Color color)
{
    notificationText.setString(text);
    notificationText.setFillColor(color);
    notificationText.setOutlineColor(sf::Color::Black);
    notificationText.setOutlineThickness(3.f);
    notificationText.setStyle(sf::Text::Bold);
    showNotification = true;
    notificationClock.restart();
}

bool BossFightUI::getConfirmClicked() const
{
    return isBossFightActive;
}

void BossFightUI::resetConfirm()
{
    isBossFightActive = false;
}