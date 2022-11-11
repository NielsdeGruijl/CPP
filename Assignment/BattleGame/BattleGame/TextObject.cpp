#include "TextObject.h"

TextObject::TextObject(std::string identifier, std::string str, std::string fontFile, int characterSize, Player* player) :
	GameObject(identifier), player(player)
{
	this->font.loadFromFile(fontFile);
	this->text.setFont(font);
	this->text.setString(str);
	this->text.setCharacterSize(characterSize);
}

TextObject::~TextObject() {}

void TextObject::update() {}

void TextObject::render(sf::RenderWindow& window) 
{
	this->SetText("Score: " + std::to_string(player->highScore));

	window.draw(this->text);
}

sf::Text TextObject::GetText() const
{
	return this->text;
}

void TextObject::SetColor(sf::Color color)
{
	this->text.setFillColor(color);
}

void TextObject::SetPos(sf::Vector2f pos)
{
	this->text.setPosition(pos);
}

void TextObject::SetText(std::string str)
{
	text.setString(str);
}