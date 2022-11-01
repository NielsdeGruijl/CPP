#pragma once

#include "Button.h"
#include <SFML/Graphics.hpp>
#include <functional>

class PlayButton : Button
{
	private:
		sf::RenderWindow* window;
public:
	std::function<void()> action;
	public:
		PlayButton(std::string identifier, std::string spriteFile, sf::RenderWindow* window);
		PlayButton(const PlayButton& other);
		~PlayButton();
};
