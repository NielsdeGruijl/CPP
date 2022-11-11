#pragma once
#include "gameObject.hpp"
#include "enemy.h"
#include "Player.h"
#include "Highscores.h"

class FightManager : public GameObject
{
	private:
		Enemy* enemy;
		Player* player;
		Highscores* hs;
		std::string playerFeedback;
		std::string enemyFeedback;
	public:
		sf::Text* feedbackText;
		bool playerTurn;
	public:	
		FightManager(std::string identifier, Enemy* enemy, Player* player, Highscores* hs);
		~FightManager();

		void update() override;
		void render(sf::RenderWindow& window) override;

		void ManageTurn();
		void DecideEnemyMove();
		sf::Text TextFeedback(std::string feedbackMsg);
		void ResetArena();
};
