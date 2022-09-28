#include "Sprite.h"

int main()
{
    const int spritesLength = 2;
    SpriteClass sprites[spritesLength];

    SpriteClass sprite("pepeDrool.jpg", Vector2f(0.1f, 0.1f), Vector2f(0, 0));
    SpriteClass sprite1("chimken.png", Vector2f(0.1f, 0.1f), Vector2f(200, 200));

    sprites[0] = sprite;
    sprites[1] = sprite1;

	RenderWindow window(VideoMode(800, 600), "SFML Window");

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
        // Draw the sprites
        if (!Keyboard::isKeyPressed(Keyboard::Space)) {

            for (int i = 0; i < spritesLength; i++)
            {
                window.draw(sprites[i].sprite);
            }
        }

        //Move the Sprites

        if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::A) ||
            Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::D))
        {
            for (int i = 0; i < spritesLength; i++)
            {
                sprites[i].MoveSprite(0.5f);
            }
        }


        // Update the window
        window.display();
    }


	return 0;
};