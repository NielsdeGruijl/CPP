#include "Button.h"

Button::Button(std::string identifier, std::string spriteFile)
	: SpriteObject(identifier, spriteFile)
{
}

Button::Button(const Button& other) :
	SpriteObject(other.getIdentifier(), other.getSpriteFile())
{
}

Button::~Button() {};


void Button::update()
{

}