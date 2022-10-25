#pragma once

#include "spriteObject.hpp"
#include <SFML/Graphics.hpp>

class Button : public SpriteObject
{
	private:
		
	public:	
		Button(std::string identifier, std::string spriteFile);
		Button(const Button& other);
		~Button();

		void update() override;
};