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

    Button button("button", "pepeDrool.jpg", &window);
    button.action = []() 
    {
        
    };

    scene1.addGameObject(player);
    scene1.addGameObject(enemy);
    scene1.addGameObject(button);

    SceneHandler handler;
    handler.addScene(scene1);
    handler.addScene(scene2);

    int counter = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        handler.update();
        handler.render(window);
        window.display();
    }

    return 0;
}





