#pragma once
#include "spriteObject.hpp"

class Enemy : public SpriteObject
{
	private:
		int HP;
	public:
		bool canUseMove;
	public:
		Enemy(std::string identifier, std::string spriteFile);
		Enemy(const Enemy& other);
		~Enemy();

		void update() override;
		int GetHP() const;
		int SetHP();
		void TakeDamage(const int dmgTaken);
		void OnDeath();
		void SelectMove();
		void Attack();
		void Heal();
		void DoNothing();
};