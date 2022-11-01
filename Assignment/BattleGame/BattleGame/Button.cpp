#include "Button.h"

Button::Button(std::string identifier, std::string spriteFile, sf::RenderWindow* window)
	: SpriteObject(identifier, spriteFile)
{
	this->window = window;
}

Button::Button(const Button& other) 
	: SpriteObject(other.getIdentifier(), other.getSpriteFile()), window(other.window)
{
}

Button::~Button() {};


void Button::update()
{
	onClick();
}

void Button::onClick()
{
	sf::FloatRect spriteRect = sprite.getGlobalBounds();

	sf::Event event;

	while (window->pollEvent(event)) 
	{
		if (event.type == sf::Event::MouseButtonPressed) 
		{
			if (spriteRect.contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
			{
				action();
			}
		}
	}
}