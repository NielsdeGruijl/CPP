#include "enemy.h"

Enemy::Enemy(std::string identifier, std::string spriteFile, SpriteObject* healthBar) :
	SpriteObject(identifier, spriteFile), healthBar(healthBar)
{
	canUseMove = false;
	healthBarWidth = healthBar->getSprite().getScale().x;
	newHealthBarWidth = healthBarWidth;
	SetHP();
	printf("Enemy HP: %d\n", HP);
	hpCounter = std::to_string(HP) + "/" + std::to_string(maxHP);
}

Enemy::Enemy(const Enemy& other) :
	SpriteObject(other.getIdentifier(), other.getSpriteFile())
{
	SetHP();
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

void Enemy::render(sf::RenderWindow& window)
{
	window.draw(this->sprite);

	sf::Font font;
	font.loadFromFile("ARIBL0.ttf");

	sf::Text text("", font, 30);
	text.setFillColor(sf::Color::White);
	text.setPosition(1280 - 370, 15);
	hpCounter = std::to_string(HP) + "/" + std::to_string(maxHP);
	text.setString(hpCounter);

	window.draw(text);

}

int Enemy::GetHP() const 
{
	return this->HP;
}

void Enemy::SetHP() 
{
	maxHP = rand() % 10 + 25;
	HP = maxHP;
	UpdateHealthBar();
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
	int enemySkin = rand() % 3;
	std::string enemySprite;

	switch (enemySkin)
	{
	case 0:
		enemySprite = "Enemy1.png";
		break;
	case 1:
		enemySprite = "Enemy2.png";
		break;
	case 2:
		enemySprite = "Enemy3.png";
		break;
	default:
		enemySprite = "Enemy1.png";
		break;
	}
	
	this->SetTexture(enemySprite);
	SetHP();
}

int Enemy::Attack()
{
	int dmg = rand() % 10 + 3;

	moveText = "Enemy attacked and dealt " + std::to_string(dmg) + " damage!";

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

	moveText = "Enemy healed for " + std::to_string(randHP) + " HP!";

	printf("Enemy healed for %d HP!\n", randHP);
}

void Enemy::DoNothing()
{
	moveText = "The enemy did nothing!";

	printf("The enemy did nothing!\n");
}

void Enemy::UpdateHealthBar()
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