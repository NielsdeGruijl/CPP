#include "PlayButton.h"

PlayButton::PlayButton(std::string identifier, std::string spriteFile, sf::RenderWindow* window)
	: Button(identifier, spriteFile, window), window(window)
{
}

PlayButton::PlayButton(const PlayButton& other)
	: Button(other.getIdentifier(), other.getSpriteFile(), other.window), window(other.window)
{
}

PlayButton::~PlayButton() {}


