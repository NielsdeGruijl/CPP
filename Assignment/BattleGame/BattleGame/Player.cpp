#include "player.h"

Player::Player(std::string identifier, std::string spriteFile) :
	SpriteObject(identifier, spriteFile)
{
	maxHP = 30;
	this->HP = maxHP;
	canUseMove = true;
}

Player::Player(const Player& other) :
	SpriteObject(other.getIdentifier(), other.getSpriteFile())
{
	maxHP = 30;
	this->HP = maxHP;
	canUseMove = true;
}

Player::~Player() {}

void Player::update() {};

int Player::GetHP() const
{
	return HP;
}

void Player::TakeDamage(const int dmgTaken)
{
	HP -= dmgTaken;
	printf("Player HP: %d\n", HP);
}

void Player::Attack(Enemy* target) 
{
	int dmg = 5;
	target->TakeDamage(dmg);
	printf("Player used gun and dealt %d damage\n", dmg);
	canUseMove = false;
	
}