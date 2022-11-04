#include "Button.h"
#include "scene.hpp"
#include "sceneHandler.hpp"

Button::Button(std::string identifier, std::string spriteFile, sf::RenderWindow* window)
	: SpriteObject(identifier, spriteFile), action(action)
{
	this->window = window;
}

Button::Button(const Button& other) 
	: SpriteObject(other.getIdentifier(), other.getSpriteFile()), window(other.window), action(other.action)
{
}

Button::~Button() {};


void Button::update()
{
	onClick();
}

void Button::onClick()
{
	spriteRect = sprite.getGlobalBounds();

	if (scene->GetHandler()->leftMouseButtonPressed) 
	{
		if (spriteRect.contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		{
			printf("button clicked");
			action();
		}
	}


}