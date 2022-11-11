#pragma once
#include "spriteObject.hpp"
#include <SFML/Graphics.hpp>

class Enemy : public SpriteObject
{
	private:
		int HP;
		int maxHP;
		float healthBarWidth;
		float newHealthBarWidth;
		SpriteObject* healthBar;
		sf::Text text;
		std::string hpCounter;
	public:
		bool canUseMove;
		std::string moveText;
	public:
		Enemy(std::string identifier, std::string spriteFile, SpriteObject* healthBar);
		Enemy(const Enemy& other);
		~Enemy();

		void update() override;
		void render(sf::RenderWindow& window) override;

		int GetHP() const;
		void SetHP();
		void TakeDamage(const int dmgTaken);
		void OnDeath();
		int Attack();
		void Heal();
		void DoNothing();
		void UpdateHealthBar();
};