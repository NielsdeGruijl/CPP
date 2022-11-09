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
	//printf("manager enemy HP: %d\n", enemy->GetHP());

	if (!player->canUseMove)
	{
		if (enemy->GetHP() > 0) 
		{
			DecideEnemyMove();
		}
		player->canUseMove = true;
	}
}

void FightManager::DecideEnemyMove() 
{
	int move = rand() % 3;

	switch (move)
	{
	case 0:
		player->TakeDamage(enemy->Attack());
		break;
	case 1:
		enemy->Heal();
		break;
	case 2:
		enemy->DoNothing();
		break;
	default:
		printf("ur code sucks retard lmao : %d\n", move);
		break;
	}
}