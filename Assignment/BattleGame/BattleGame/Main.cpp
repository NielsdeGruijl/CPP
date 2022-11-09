#include <SFML/Graphics.hpp>

#include "scene.hpp"
#include "spriteObject.hpp"
#include "Button.h"
#include "sceneHandler.hpp"
#include "enemy.h"
#include "player.h"
#include "FightManager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "ShitShowdown");
    Scene scene1("Main_Menu");
    Scene scene2("Fight_Scene");

    SceneHandler handler;
    handler.addScene(scene1);
    handler.addScene(scene2);

    SpriteObject playerHP("playerHP", "HealthBar.png");
    playerHP.setScale(sf::Vector2f(1, 0.8f));
    playerHP.setPosition(sf::Vector2f(20, 10));
    
    SpriteObject playerHPBackground(playerHP);
    playerHPBackground.SetColor(sf::Color::Blue);
    playerHPBackground.setScale(sf::Vector2f(1, 0.8f));
    playerHPBackground.setPosition(sf::Vector2f(20, 10));

    Player player("player", "player.jpg", &playerHP);
    player.setScale(sf::Vector2f(0.5f, 0.5f));
    player.setPosition(sf::Vector2f(200, 200));

    SpriteObject enemyHP("enemyHP", "HealthBar.png");
    enemyHP.setScale(sf::Vector2f(1, 0.8f));
    enemyHP.setPosition(sf::Vector2f(window.getSize().x - enemyHP.getSprite().getGlobalBounds().width - 20, 10));

    SpriteObject enemyHPBackground(playerHP);
    enemyHPBackground.SetColor(sf::Color::Blue);
    enemyHPBackground.setScale(sf::Vector2f(1, 0.8f));
    enemyHPBackground.setPosition(sf::Vector2f(window.getSize().x - enemyHP.getSprite().getGlobalBounds().width - 20, 10));

    Enemy enemy("enemy", "enemy.jpg", &enemyHP);
    enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    enemy.setPosition(sf::Vector2f(780, 200));

    Button playButton("button", "Play.png", &window);
    playButton.setScale(sf::Vector2f(3, 2));
    playButton.setPosition(sf::Vector2f(window.getSize().x / 2 - playButton.getSprite().getGlobalBounds().width / 2, 150));
    playButton.action = [&handler] {
        handler.stackScene("Fight_Scene");
    };

    Button quitButton("quit", "Quit.png", &window);
    quitButton.setScale(sf::Vector2f(1.8f, 1.8f));
    quitButton.setPosition(sf::Vector2f(window.getSize().x / 2 - quitButton.getSprite().getGlobalBounds().width / 2, 300));
    quitButton.action = [] {
        exit(0);
    };

    Button attackButton("attack", "Attack.png", &window);
    attackButton.setScale(sf::Vector2f(2, 2));
    attackButton.setPosition(sf::Vector2f(125, 570));
    attackButton.action = [&enemy, &player] {
        player.Attack(&enemy);
    };

    Button healButton("heal", "Heal.png", &window);
    healButton.setScale(sf::Vector2f(2, 2));
    healButton.setPosition(sf::Vector2f(1280 - (healButton.getSprite().getGlobalBounds().width + 125), 570));
    healButton.action = [&player] {
        player.Heal();
    };

    SpriteObject HUD("HUD", "HUD.png");
    HUD.setPosition(sf::Vector2f(0, 0));

    FightManager manager("manager", &enemy, &player);

    scene1.addGameObject(playButton);
    scene1.addGameObject(quitButton);
    scene2.addGameObject(HUD);
    scene2.addGameObject(player);
    scene2.addGameObject(playerHPBackground);
    scene2.addGameObject(playerHP);
    scene2.addGameObject(enemy);
    scene2.addGameObject(enemyHPBackground);
    scene2.addGameObject(enemyHP);
    scene2.addGameObject(attackButton);
    scene2.addGameObject(healButton);
    scene2.addGameObject(manager);


    int counter = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) 
            {
                if (event.mouseButton.button == sf::Mouse::Button(0)) 
                {
                    handler.leftMouseButtonPressed = true;
                }
            }
        }
        window.clear();
        handler.update();
        handler.leftMouseButtonPressed = false;
        handler.render(window);
        window.display();
    }

    return 0;
}





