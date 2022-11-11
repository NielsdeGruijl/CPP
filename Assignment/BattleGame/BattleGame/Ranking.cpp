#include "Ranking.h"
#include <SFML/Graphics.hpp>

Ranking::Ranking(std::string identifier, Highscores* hs) :
	GameObject(identifier) 
{
	this->hs = hs;
}

Ranking::~Ranking() {}

void Ranking::update() {}

void Ranking::render(sf::RenderWindow& window)
{
	sf::Font font;
	font.loadFromFile("ARIBL0.ttf");

	hs->ReadHS();

	for (int i = 0; i < hs->topFive.size() && i < 5; i++)
	{
		std::string str;
		str = std::to_string(i + 1) + ". " + std::to_string(hs->topFive[i]);
		sf::Text text(str, font, 30);
		text.setPosition(1000, 200 + (i * 50));
		text.setFillColor(sf::Color::White);

		window.draw(text);
	}
}