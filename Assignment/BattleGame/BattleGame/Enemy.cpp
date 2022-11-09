#include "enemy.h"

Enemy::Enemy(std::string identifier, std::string spriteFile, SpriteObject* healthBar) :
	SpriteObject(identifier, spriteFile), healthBar(healthBar)
{
	this->HP = SetHP();
	printf("Enemy HP: %d\n", HP);
	canUseMove = false;
	healthBarWidth = healthBar->getSprite().getScale().x;
	newHealthBarWidth = healthBarWidth;
}

Enemy::Enemy(const Enemy& other) :
	SpriteObject(other.getIdentifier(), other.getSpriteFile())
{
	this->HP = SetHP();
	printf("Enemy HP: %d\n", HP);
	canUseMove = false;
	healthBarWidth = healthBar->getSprite().getScale().x;
}

Enemy::~Enemy() {}

void Enemy::update()
{
	if (HP <= 0) 
	{
		OnDeath();
	}
};

int Enemy::GetHP() const 
{
	return this->HP;
}

int Enemy::SetHP() 
{
	maxHP = rand() % 10 + 25;
	return maxHP;
}

void Enemy::TakeDamage(const int dmgTaken)
{
	HP -= dmgTaken;
	if (HP <= 0) {
		HP = 0;
	}

	UpdateHealthBar();

	printf("Enemy HP: %d\n", HP);
	//healthBar->setScale(sf::Vector2f(newHealthBarWidth, 0.8f));
}

void Enemy::OnDeath()
{
	HP = SetHP();

	UpdateHealthBar();
}

int Enemy::Attack()
{
	int dmg = rand() % 10 + 3;
	printf("Enemy attacked and dealt %d damage!\n", dmg);
	return dmg;
}

void Enemy::Heal()
{
	int randHP = rand() % 10 + 3;

	if (HP < maxHP) 
	{
		HP += randHP;

		if (HP > maxHP) {
			HP = maxHP;
		}

		UpdateHealthBar();
	}
	
	//newHealthBarWidth += oneHP * randHP;
	//healthBar->setScale(sf::Vector2f(newHealthBarWidth, 0.8f));

	printf("Enemy healed for %d HP!\n", randHP);
}

void Enemy::DoNothing()
{
	printf("Enemy has braindamage, it did nothing!\n");
}

void Enemy::UpdateHealthBar()
{
	newHealthBarWidth = ((float)HP / (float)maxHP) * healthBarWidth;

	healthBar->setScale(sf::Vector2f(newHealthBarWidth, 0.8f));

	if (newHealthBarWidth <= 0) {
		newHealthBarWidth = 0;
	}

	if (newHealthBarWidth >= healthBarWidth) {
		newHealthBarWidth = healthBarWidth;
	}
}