#include "player.h"

Player::Player(std::string identifier, std::string spriteFile, SpriteObject* healthBar) :
	SpriteObject(identifier, spriteFile), healthBar(healthBar)
{
	maxHP = 30;
	this->HP = maxHP;
	canUseMove = true;
	printf("Player HP: %d\n", this->HP);
	healthBarWidth = healthBar->getSprite().getScale().x;
	newHealthBarWidth = healthBarWidth;
}

Player::Player(const Player& other) :
	SpriteObject(other.getIdentifier(), other.getSpriteFile()), healthBar(other.healthBar)
{
	maxHP = 30;
	this->HP = maxHP;
	canUseMove = true;
	printf("Player HP: %d\n", this->HP);
	healthBarWidth = healthBar->getSprite().getScale().x;
	newHealthBarWidth = healthBarWidth;
}

Player::~Player() {}

void Player::update() {}

void Player::render(sf::RenderWindow& window) {
	window.draw(this->sprite);

	sf::Font font;
	font.loadFromFile("ARIBL0.ttf");

	sf::Text text("", font, 30);
	text.setFillColor(sf::Color::White);
	text.setPosition(280, 15);
	hpCounter = std::to_string(HP) + "/" + std::to_string(maxHP);
	text.setString(hpCounter);

	window.draw(text);
}

int Player::GetHP() const
{
	return HP;
}

void Player::TakeDamage(const int dmgTaken)
{
	HP -= dmgTaken;

	if (HP <= 0) {
		HP = 0;
	}

	UpdateHealthBar();

	printf("Player HP: %d\n", HP);
}

void Player::Attack(Enemy* target) 
{
	int dmg = 5;
	target->TakeDamage(dmg);
	printf("Player used gun and dealt %d damage\n", dmg);
	canUseMove = false;
}

void Player::Heal() 
{
	int heal = rand() % 5 + 5;

	if (HP < maxHP) {
		HP += heal;

		if (HP >= maxHP) {
			HP = maxHP;

			healthBar->setScale(sf::Vector2f(1, 0.8f));
		}

		UpdateHealthBar();
	}


	printf("New Healthbar Width: %f\n Old healthbar width: %f\n", newHealthBarWidth, healthBarWidth);
	printf("Player used heal and healed for %d HP\n", heal);
	printf("Player HP: %d\n", HP);
	canUseMove = false;
}

void Player::UpdateHealthBar()
{
	newHealthBarWidth = ((float)HP / (float)maxHP) * healthBarWidth;

	healthBar->setScale(sf::Vector2f(newHealthBarWidth, 0.8f));

	hpCounter = std::to_string(HP) + "/" + std::to_string(maxHP);
	text.setString(hpCounter);

	if (newHealthBarWidth <= 0) {
		newHealthBarWidth = 0;
	}

	if (newHealthBarWidth >= healthBarWidth) {
		newHealthBarWidth = healthBarWidth;
	}
}