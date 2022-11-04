#include "scene.hpp"

Scene::Scene(std::string identifier) : identifier(identifier) { }

Scene::~Scene() { }

void Scene::addGameObject(GameObject& object) {
    this->listOfGameObjects.push_back(&object);
    object.SetScene(this);
}

void Scene::update() { 
    for(unsigned int i = 0; i < this->listOfGameObjects.size(); i++) {
        this->listOfGameObjects[i]->update();
    }
}

void Scene::render(sf::RenderWindow& window) { 
    for(unsigned int i = 0; i < this->listOfGameObjects.size(); i++) {
       this->listOfGameObjects[i]->render(window);
    }
}

std::string Scene::getIdentifier() const {
    return this->identifier;
}

void Scene::SetHandler(SceneHandler* handler) 
{
    this->handler = handler;
}

SceneHandler* Scene::GetHandler()
{
    return this->handler;
}
