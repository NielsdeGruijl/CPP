#pragma once
#include <cstdio>
#include <SFML/Graphics.hpp>

using namespace sf;

class SpriteClass
{
public:
    SpriteClass();
    SpriteClass(std::string, Vector2f, Vector2f);
	~SpriteClass();

    Texture texture;
	Sprite sprite;

    Vector2f startPos;
    Vector2f endPos;

	void MoveSprite(float speed);
    void StoreMovement(Vector2f lastMove);
    void UndoMovements();
private:
    Vector2f movementMemory[5];
    int movementIndex = 0;
};

SpriteClass::SpriteClass() 
{
}

SpriteClass::SpriteClass(std::string filename, Vector2f scale, Vector2f spawnPos)
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
    if(startPos != sprite.getPosition()) startPos = sprite.getPosition();

    if (Keyboard::isKeyPressed(Keyboard::W)) {
        sprite.move(0, -speed);
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        sprite.move(-speed, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        sprite.move(0, speed);
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        sprite.move(speed, 0);
    }
    
    if (endPos != sprite.getPosition()) endPos = sprite.getPosition();
}

void SpriteClass::StoreMovement(Vector2f lastMove)
{
    if (movementIndex >= 4)
    {
        for (int i = 0; i <= movementIndex; i++)
        {
            if (i < 4)
            {
                movementMemory[i] = movementMemory[i + 1];
            }
        }
    }

    movementMemory[movementIndex] = lastMove;

    if (movementIndex < 5) movementIndex++;
}

void SpriteClass::UndoMovements()
{

}