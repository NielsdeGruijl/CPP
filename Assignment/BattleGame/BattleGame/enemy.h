#pragma once
#include "spriteObject.hpp"

class Enemy : public SpriteObject
{
	private:
		int HP;
		int maxHP;
		float healthBarWidth;
		float newHealthBarWidth;
		SpriteObject* healthBar;
	public:
		bool canUseMove;
	public:
		Enemy(std::string identifier, std::string spriteFile, SpriteObject* healthBar);
		Enemy(const Enemy& other);
		~Enemy();

		void update() override;
		int GetHP() const;
		int SetHP();
		void TakeDamage(const int dmgTaken);
		void OnDeath();
		int Attack();
		void Heal();
		void DoNothing();
		void UpdateHealthBar();
};