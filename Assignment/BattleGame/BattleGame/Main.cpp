#include <SFML/Graphics.hpp>

#include "PlayButton.h"
#include "scene.hpp"
#include "spriteObject.hpp"
#include "Button.h"
#include "sceneHandler.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "ShitShowdown");
    Scene scene1("Main_Menu");
    Scene scene2("Fight_Scene");

    SpriteObject player("player", "player.jpg");
    player.setPosition(sf::Vector2f(200, 200));
    player.setScale(sf::Vector2f(0.5f, 0.5f));
    SpriteObject enemy("enemy", "enemy.jpg");
    enemy.setPosition(sf::Vector2f(800, 200));
    enemy.setScale(sf::Vector2f(0.5f, 0.5f));

    SpriteObject bob("bob", "head.png");

    SceneHandler handler;
    handler.addScene(scene1);
    handler.addScene(scene2);

    Button button("button", "pepeDrool.jpg", &window);
    button.setScale(sf::Vector2f(0.5f, 0.1f));
    button.action = [&handler] {
        handler.stackScene("Fight_Scene");
    };

    scene1.addGameObject(player);
    scene1.addGameObject(enemy);
    scene1.addGameObject(button);
    scene2.addGameObject(bob);

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





