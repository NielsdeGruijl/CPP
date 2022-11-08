#pragma once
#include "gameObject.hpp"
#include "enemy.h"
#include "Player.h"

class FightManager : public GameObject
{
	private:
		Enemy* enemy;
		Player* player;
		bool* enemyMove;
		bool* playerMove;
	public:
		bool playerTurn;
	public:	
		FightManager(std::string identifier, Enemy* enemy, Player* player);
		~FightManager();

		void update() override;
		void render(sf::RenderWindow& window) override;

		void ManageTurn();
};
