#pragma once
#include <cstdio>
#include <SFML/Graphics.hpp>

class SpriteClass
{
public:
    SpriteClass();
    SpriteClass(std::string, sf::Vector2f, sf::Vector2f);
	~SpriteClass();

    sf::Texture texture;
	sf::Sprite sprite;

	void MoveSprite(float speed);
private:
	
};

SpriteClass::SpriteClass() 
{
}

SpriteClass::SpriteClass(std::string filename, sf::Vector2f scale, sf::Vector2f spawnPos)
{
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setScale(scale);
    sprite.setPosition(spawnPos);
}

SpriteClass::~SpriteClass()
{
}

void SpriteClass::MoveSprite(float speed)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        sprite.move(0, -speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sprite.move(-speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sprite.move(0, speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sprite.move(speed, 0);
    }
}