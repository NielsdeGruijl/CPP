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

    Player player("player", "player.jpg");
    player.setPosition(sf::Vector2f(200, 200));
    player.setScale(sf::Vector2f(0.5f, 0.5f));
    Enemy enemy("enemy", "enemy.jpg");
    enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    enemy.setPosition(sf::Vector2f(780, 200));

    Button playButton("button", "pepeDrool.jpg", &window);
    playButton.setScale(sf::Vector2f(0.5f, 0.1f));
    playButton.action = [&handler] {
        handler.stackScene("Fight_Scene");
    };

    Button attackButton("attack", "no.png", &window);
    attackButton.setScale(sf::Vector2f(0.5f, 0.1f));
    attackButton.setPosition(sf::Vector2f(50, 500));
    attackButton.action = [&enemy, &player] {
        player.Attack(&enemy);
    };

    FightManager manager("manager", &enemy, &player);

    scene1.addGameObject(playButton);
    scene2.addGameObject(player);
    scene2.addGameObject(enemy);
    scene2.addGameObject(attackButton);
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





