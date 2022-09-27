#include "Sprite.h"

using namespace sf;

int main()
{
    const int spritesLength = 2;
    SpriteClass sprites[spritesLength];

    SpriteClass sprite("pepeDrool.jpg", Vector2f(0.1f, 0.1f), Vector2f(0, 0));
    SpriteClass sprite1("chimken.png", Vector2f(0.1f, 0.1f), Vector2f(200, 200));

    sprites[0] = sprite;
    sprites[1] = sprite1;

	RenderWindow window(VideoMode(800, 600), "SFML Window");
    
	//if (!texture.loadFromFile("pepeDrool.jpg"))
	//	return EXIT_FAILURE;

    while (window.isOpen())
    {
        // Process events
        Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        if (!Keyboard::isKeyPressed(Keyboard::Space)) {

            for (int i = 0; i < spritesLength; i++)
            {
                window.draw(sprites[i].sprite);
            }
        }

        sprites[0].MoveSprite(1.0f);
        sprite.MoveSprite(1.0f);
        sprite1.MoveSprite(0.5f);

        // Update the window
        window.display();
    }


	return 0;
};