#include "FightManager.h"
#include <windows.h>
#include "scene.hpp"
#include "sceneHandler.hpp"

FightManager::FightManager(std::string identifier, Enemy* enemy, Player* player, Highscores* hs) :
	GameObject(identifier)
{
	this->enemy = enemy;
	this->player = player;
	this->hs = hs;

	playerTurn = true;
}

FightManager::~FightManager() {};

void FightManager::update() 
{
	if (player->GetHP() <= 0)
	{
		ResetArena();
		
		scene->GetHandler()->stackScene("Death_Scene");
	}

	ManageTurn();
};

void FightManager::render(sf::RenderWindow& window) 
{
	sf::Font font;
	font.loadFromFile("ARIBL0.ttf");

	sf::Text playerText(playerFeedback, font, 20);
	playerText.setFillColor(sf::Color::White);
	playerText.setPosition(0, 500);
	window.draw(playerText);

	sf::Text enemyText(enemyFeedback, font, 20);
	enemyText.setFillColor(sf::Color::White);
	enemyText.setPosition(1280 - enemyText.getGlobalBounds().width - 10, 500);
	window.draw(enemyText);
};

void FightManager::ManageTurn()
{
	
	//printf("manager enemy HP: %d\n", enemy->GetHP());
	if (!player->canUseMove)
	{
		playerFeedback = player->moveText;
		Sleep(1000);
		if (enemy->GetHP() > 0) 
		{
			DecideEnemyMove();
			enemyFeedback = enemy->moveText;
		}
		else 
		{
			enemyFeedback = "Enemy died and a new one spawned!";
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

sf::Text FightManager::TextFeedback(std::string feedbackMsg)
{
	sf::Font font;
	font.loadFromFile("ARIBL0.ttf");

	sf::Text text("", font, 20);
	text.setPosition(500, 500);
	text.setFillColor(sf::Color::White);
	text.setString(feedbackMsg);

	return text;
}

void FightManager::ResetArena()
{
	//hs->AddHS(player->highScore);
	hs->WriteHS(player->highScore);
	player->Reset();
	enemy->SetHP();
}