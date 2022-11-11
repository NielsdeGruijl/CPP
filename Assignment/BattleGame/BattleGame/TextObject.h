#pragma once

#include "gameObject.hpp"
#include <SFML/Graphics.hpp>
#include "Player.h"

class TextObject : public GameObject
{
	private:
		sf::Text text;
		sf::Font font;
		Player* player;
		int highscore;
	public:
		TextObject(std::string identifier, std::string str, std::string fontFile, int characterSize, Player* player);
		~TextObject();

		void update() override;
		void render(sf::RenderWindow& window) override;
		
		void SetText(std::string str);
		sf::Text GetText() const;

		void SetColor(sf::Color color);
		void SetPos(sf::Vector2f pos);
};
