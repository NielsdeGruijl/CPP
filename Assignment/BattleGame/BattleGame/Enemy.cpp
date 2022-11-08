#include "enemy.h"

Enemy::Enemy(std::string identifier, std::string spriteFile) :
	SpriteObject(identifier, spriteFile)
{
	this->HP = SetHP();
	printf("%d\n", HP);
	canUseMove = false;
}

Enemy::Enemy(const Enemy& other) :
	SpriteObject(other.getIdentifier(), other.getSpriteFile())
{
	this->HP = SetHP();
	canUseMove = false;
}

Enemy::~Enemy() {}

void Enemy::update()
{
	if (HP <= 0) 
	{
		OnDeath();
	}

	if (canUseMove)
	{
		SelectMove();
	}
};

int Enemy::GetHP() const 
{
	return this->HP;
}

int Enemy::SetHP() 
{
	return rand() % 10 + 25;
}

void Enemy::TakeDamage(const int dmgTaken)
{
	HP -= dmgTaken;
	printf("Enemy HP: %d\n", HP);
}

void Enemy::OnDeath()
{
	HP = SetHP();
}

void Enemy::SelectMove()
{
	int move = rand() % 3;

	switch (move)
	{
	case 0:
		Attack();
		break;
	case 1:
		Heal();
		break;
	case 2:
		DoNothing();
		break;
	default:
		printf("ur code sucks retard lmao : %d\n", move);
		break;
	}
}

void Enemy::Attack()
{
	printf("Enemy attacked!\n");
	canUseMove = false;
}

void Enemy::Heal()
{
	int randHP = rand() % (10 - 3 + 1) + 3;
	HP += randHP;

	printf("Enemy healed for %d HP!\n", randHP);
	canUseMove = false;
}

void Enemy::DoNothing()
{
	printf("Enemy has braindamage, it did nothing!\n");
	canUseMove = false;
}