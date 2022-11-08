#pragma once

#include "spriteObject.hpp"
#include "enemy.h"

class Player : public SpriteObject
{
	private:
		int HP;
		int maxHP;
	public:	
		bool canUseMove;
	public:
		Player(std::string identifier, std::string spriteFile);
		Player(const Player& other);
		~Player();

		void update() override;
		
		int GetHP() const;
		void TakeDamage(const int dmgTaken);

		void Attack(Enemy* target);
		void Heal();

};