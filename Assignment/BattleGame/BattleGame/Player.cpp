#include "player.h"
#include "TextObject.h"

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

void Player::render(sf::RenderWindow& window) 
{
	window.draw(this->sprite);

	sf::Font font;
	font.loadFromFile("ARIBL0.ttf");
	
	hpCounter = std::to_string(HP) + "/" + std::to_string(maxHP);
	sf::Text text(hpCounter, font, 30);
	text.setFillColor(sf::Color::White);
	text.setPosition(280, 15);

	hsString = "Score: " + std::to_string(highScore);
	sf::Text hsText(hsString, font, 30);
	hsText.setFillColor(sf::Color::White);
	hsText.setPosition(window.getSize().x / 2 - hsText.getGlobalBounds().width / 2, 20);

	window.draw(hsText);
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
	int dmg = rand() % 5 + 5;
	target->TakeDamage(dmg);

	highScore += dmg;

	moveText = "You attacked and dealt " + std::to_string(dmg) + " damage!";

	printf("HighScore: %d\n", highScore);
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
	
	moveText = "You healed for " + std::to_string(heal) + " HP";

	printf("Player healed for %d HP\n", heal);
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

void Player::Reset()
{
	HP = maxHP;
	UpdateHealthBar();
	highScore = 0;
}
