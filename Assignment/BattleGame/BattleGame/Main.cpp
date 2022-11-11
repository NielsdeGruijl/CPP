#include <SFML/Graphics.hpp>

#include "scene.hpp"
#include "spriteObject.hpp"
#include "Button.h"
#include "sceneHandler.hpp"
#include "enemy.h"
#include "player.h"
#include "FightManager.h"
#include "Highscores.h"
#include "TextObject.h"
#include "Ranking.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "ShitShowdown");
    Scene scene1("Main_Menu");
    Scene scene2("Fight_Scene");
    Scene scene3("Death_Scene");

    SceneHandler handler;
    handler.addScene(scene1);
    handler.addScene(scene2);
    handler.addScene(scene3);

    Highscores hs("highscores");

    SpriteObject playerHP("playerHP", "HealthBar.png");
    playerHP.setScale(sf::Vector2f(1, 0.8f));
    playerHP.setPosition(sf::Vector2f(20, 10));
    
    SpriteObject playerHPBackground(playerHP);
    playerHPBackground.SetColor(sf::Color::Blue);
    playerHPBackground.setScale(sf::Vector2f(1, 0.8f));
    playerHPBackground.setPosition(sf::Vector2f(20, 10));

    srand(time(0));
    int playerSkin = rand() % 3;
    std::string playerSprite;

    switch (playerSkin) 
    {
        case 0:
            playerSprite = "Player1.png";
            break;
        case 1:
            playerSprite = "Player2.png";
            break;
        case 2:
            playerSprite = "Player3.png";
            break;
        default:
            playerSprite = "Player1.png";
            break;
    }

    Player player("player", playerSprite, &playerHP);
    player.setScale(sf::Vector2f(2, 2));
    player.setPosition(sf::Vector2f(200, 180));

    SpriteObject enemyHP("enemyHP", "HealthBar.png");
    enemyHP.setScale(sf::Vector2f(1, 0.8f));
    enemyHP.setPosition(sf::Vector2f(window.getSize().x - enemyHP.getSprite().getGlobalBounds().width - 20, 10));

    SpriteObject enemyHPBackground(playerHP);
    enemyHPBackground.SetColor(sf::Color::Blue);
    enemyHPBackground.setScale(sf::Vector2f(1, 0.8f));
    enemyHPBackground.setPosition(sf::Vector2f(window.getSize().x - enemyHP.getSprite().getGlobalBounds().width - 20, 10));

    srand(time(0));
    int enemySkin = rand() % 3;
    std::string enemySprite;

    switch (enemySkin)
    {
        case 0:
            enemySprite = "Enemy1.png";
            break;
        case 1:
            enemySprite = "Enemy2.png";
            break;
        case 2:
            enemySprite = "Enemy3.png";
            break;
        default:
            enemySprite = "Enemy1.png";
            break;
    }

    Enemy enemy("enemy", enemySprite , &enemyHP);
    enemy.setScale(sf::Vector2f(2, 2));
    enemy.setPosition(sf::Vector2f(1280 - (enemy.getSprite().getGlobalBounds().width + 200), 180));

    Button playButton("button", "Play.png", &window);
    playButton.setScale(sf::Vector2f(3, 2));
    playButton.setPosition(sf::Vector2f(50, 150));
    playButton.action = [&handler] {
        handler.stackScene("Fight_Scene");
    };

    Button quitButton("quit", "Quit.png", &window);
    quitButton.setScale(sf::Vector2f(1.8f, 1.8f));
    quitButton.setPosition(sf::Vector2f(50, 300));
    quitButton.action = [] {
        exit(0);
    };

    Button clearDataButton("clearData", "Eraser.png", &window);
    clearDataButton.setScale(sf::Vector2f(1.8f, 1.8f));
    clearDataButton.setPosition(sf::Vector2f(50, 440));
    clearDataButton.action = [&hs] {
        hs.ClearHS();
    };

    Ranking ranking("ranking", &hs);

    Button attackButton("attack", "Attack.png", &window);
    attackButton.setScale(sf::Vector2f(2, 2));
    attackButton.setPosition(sf::Vector2f(250, 570));
    attackButton.action = [&enemy, &player] {
        if (player.canUseMove) {
            player.Attack(&enemy);
        }
    };

    Button healButton("heal", "Heal.png", &window);
    healButton.setScale(sf::Vector2f(2, 2));
    healButton.setPosition(sf::Vector2f(1280 - (healButton.getSprite().getGlobalBounds().width + 250), 570));
    healButton.action = [&player] {
        if (player.canUseMove) {
            player.Heal();
        }
    };

    Button returnButton("return", "menu.png", &window);
    returnButton.setPosition(sf::Vector2f(window.getSize().x / 2 - (returnButton.getSprite().getGlobalBounds().width / 2), window.getSize().y / 2 - returnButton.getSprite().getGlobalBounds().height / 2));
    returnButton.setScale(sf::Vector2f(2, 2));
    returnButton.action = [&handler] {
        //printf("returning to main menu...\n");
        handler.stackScene("Main_Menu");
    };

    TextObject endScreenHS("endHS", "", "ARIBL0.ttf", 50, &player);
    endScreenHS.SetPos(sf::Vector2f(window.getSize().x / 2 - endScreenHS.GetText().getGlobalBounds().width / 2, 200));
    endScreenHS.SetColor(sf::Color::White);

    SpriteObject HUD("HUD", "HUD-export.png");
    HUD.setPosition(sf::Vector2f(0, 0));

    FightManager manager("manager", &enemy, &player, &hs);


    Button quitFight("quitFight", "menu.png", &window);
    quitFight.setScale(sf::Vector2f(0.8f, 0.8f));
    quitFight.setPosition(sf::Vector2f(window.getSize().x - quitFight.getSprite().getGlobalBounds().width, window.getSize().y - quitFight.getSprite().getGlobalBounds().height));
    quitFight.action = [&handler, &manager] {
        //printf("returning to main menu...\n");
        handler.stackScene("Main_Menu");
        manager.ResetArena();
    };

    scene1.addGameObject(playButton);
    scene1.addGameObject(quitButton);
    scene1.addGameObject(clearDataButton);
    scene1.addGameObject(ranking);

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
    scene2.addGameObject(quitFight);

    scene3.addGameObject(returnButton);
    scene3.addGameObject(endScreenHS);


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





