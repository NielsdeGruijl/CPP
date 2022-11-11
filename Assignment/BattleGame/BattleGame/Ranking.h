#pragma once

#include "gameObject.hpp"
#include "Highscores.h"

class Ranking : public GameObject
{
	private:
		std::vector<int> ranking;
		Highscores* hs;
	public:
		Ranking(std::string identifier, Highscores* hs);
		~Ranking();

		void update() override;
		void render(sf::RenderWindow& window) override;

		void UpdateRankings();

};