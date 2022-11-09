#pragma once

#include "spriteObject.hpp"
#include "enemy.h"
#include <SFML/Graphics.hpp>

class Player : public SpriteObject
{
	private:
		int HP;
		int maxHP;
		float healthBarWidth;
		float newHealthBarWidth;
		SpriteObject* healthBar;
		sf::Text text;
	public:	
		bool canUseMove;
	public:
		Player(std::string identifier, std::string spriteFile, SpriteObject* healthBar);
		Player(const Player& other);
		~Player();

		void update() override;
		void render(sf::RenderWindow& window) override;
		
		int GetHP() const;
		void TakeDamage(const int dmgTaken);

		void Attack(Enemy* target);
		void Heal();

		void UpdateHealthBar();

};