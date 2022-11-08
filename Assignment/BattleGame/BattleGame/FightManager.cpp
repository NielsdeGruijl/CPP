#include "FightManager.h"

FightManager::FightManager(std::string identifier, Enemy* enemy, Player* player) :
	GameObject(identifier)
{
	this->enemy = enemy;
	this->player = player;
	this->enemyMove = &enemy->canUseMove;
	this->playerMove = &player->canUseMove;

	playerTurn = true;
}

FightManager::~FightManager() {};

void FightManager::update() 
{
	ManageTurn();
};

void FightManager::render(sf::RenderWindow& window) {};

void FightManager::ManageTurn()
{
	if (!player->canUseMove)
	{
		enemy->canUseMove = true;
		player->canUseMove = true;
	}
}