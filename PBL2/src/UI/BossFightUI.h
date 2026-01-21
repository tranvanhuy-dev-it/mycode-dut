#pragma once
#include <SFML/Graphics.hpp>
#include "CircleButton.h"
#include "RectangleButton.h"
#include "Character.h"
#include "Boss.h"

class BossFightUI
{
private:
    sf::Font font;
    
    // Nút khiêu chiến Boss
    CircleButton bossButton;
    
    // Dialog xác nhận
    RectangleButton confirmButton;
    RectangleButton cancelButton;
    sf::Text confirmText;
    sf::RectangleShape dialogBackground;
    
    // Thông báo
    sf::Text notificationText;
    sf::Clock notificationClock;
    bool showNotification;
    
    // Boss HP bar (hiển thị ở top screen khi đang đánh boss)
    sf::RectangleShape bossHpBack;
    sf::RectangleShape bossHpBar;
    sf::Text bossNameText;
    
    bool showDialog;
    bool isBossFightActive;
    
public:
    BossFightUI();
    
    void handleEvent(sf::Event& event, sf::RenderWindow& window, Character* player);
    void render(sf::RenderWindow& window, Boss* boss = nullptr);
    void update(Boss* boss);
    
    // Getter/Setter
    bool isDialogShown() const { return showDialog; }
    bool isBossFight() const { return isBossFightActive; }
    void setBossFight(bool value) { isBossFightActive = value; }
    
    void showNotificationText(const std::string& text, sf::Color color);
    
    // Callback khi xác nhận đánh boss
    bool getConfirmClicked() const;
    void resetConfirm();
};