#pragma once

#include "spriteObject.hpp"
#include <SFML/Graphics.hpp>
#include <functional>

class Button : public SpriteObject
{
	private:
		sf::RenderWindow* window;
		sf::FloatRect spriteRect;
	public:
		std::function<void()> action;
	public:	
		Button(std::string identifier, std::string spriteFile, sf::RenderWindow* window);
		Button(const Button& other);
		~Button();

		void update() override;
		void onClick();
};