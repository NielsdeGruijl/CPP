#pragma once
#include <cstdio>
#include <iostream>
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

    Vector2f lastPos;
    //Vector2f endPos;

    bool lastPosSet = false;
    //bool endPosSet = false;

	void MoveSprite(float speed);
    void StoreOldPos(Vector2f lastMove);
    void UndoMovements();
private:
    Vector2f oldPositions[5];
    Vector2f* arr = oldPositions;
    int positionIndex = 0;
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
    //if (lastPos != sprite.getPosition() && !lastPosSet)
    //{
    //    lastPos = sprite.getPosition();
    //    lastPosSet = true;
    //}

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
    
    //if (endPos != sprite.getPosition() && !endPosSet)
    //{
    //    endPos = sprite.getPosition();
    //    endPosSet = true;
    //}

}

void SpriteClass::StoreOldPos(Vector2f lastPos)
{
    if (positionIndex > 4)
    {
        //delete &oldPositions[0];

        for (int i = 0; i <= positionIndex; i++)
        {
            if (i < 4)
            {
                oldPositions[i] = oldPositions[i + 1];
            }
        }

        //printf("Oldest position has been removed!");
    }

    printf("Current pos in the array: %d\n", positionIndex);
    oldPositions[positionIndex] = lastPos;
    //arr[positionIndex] = lastPos;

    

    for (int i = 0; i <= positionIndex; i++)
    {
        printf("LastPos: (%f, %f)", lastPos.x, lastPos.y);
        printf("Stored positions %d : (%f, %f)\n", i, oldPositions[positionIndex].x, oldPositions[positionIndex].y);
    }

    

    if (positionIndex < 4) positionIndex++;

    lastPosSet = false;
    //endPosSet = false;
}

void SpriteClass::UndoMovements()
{

}