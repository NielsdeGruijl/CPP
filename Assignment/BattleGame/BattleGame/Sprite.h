#pragma once

#include "gameObject.hpp"
#include <SFML/Graphics/Texture.hpp>

class Sprite : public GameObject
{
public:
	Sprite(std::string identifier, std::string fileName);
	~Sprite();

private:

};
