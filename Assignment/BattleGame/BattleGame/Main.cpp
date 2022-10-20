#include <SFML/Graphics.hpp>

#include "scene.hpp"
#include "spriteObject.hpp"
#include "sceneHandler.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "ShitShowdown");
    Scene scene1("Main_Menu");
    Scene scene2("Fight_Scene");

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





