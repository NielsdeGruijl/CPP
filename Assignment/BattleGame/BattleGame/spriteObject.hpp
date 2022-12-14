#pragma once

#include "gameObject.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class SpriteObject : public GameObject {
    private:
        std::string spriteFile;
        sf::Texture texture;
    protected:
        sf::Sprite sprite;
    public:
        SpriteObject(std::string identifier, std::string spriteFile);
        SpriteObject(const SpriteObject& other);
        ~SpriteObject();
        
    public:
        void update() override;
        void render(sf::RenderWindow& window) override;
        
        void setPosition(sf::Vector2f position);
        void setScale(sf::Vector2f scale);
        sf::Sprite getSprite() const;
        std::string getSpriteFile() const;
        void SetColor(sf::Color color);
        void SetTexture(const std::string spriteFile);

        
};



