#include "Van.h"
#include <iostream>

/* Main Function in class to create load texture and sprite for object & create pointers for position, scale, size, collision position & speed */
Van::Van(sf::Vector2f position, sf::Vector2f scale, sf::Vector2f dim, sf::Vector2f rectPos, float speedin, bool islog)
{
	vanSprite.setPosition(position);
	vanSprite.setScale(scale);
	rect.setSize(dim);
	rect.setScale(scale);
	rect.setPosition(rectPos);
	speed = speedin;
	islog = islog;

	/* Loads texture */
	if (!vanTexture.loadFromFile("../Assets/Textures/Van.png")) {
		std::cout << "Error loading texture for Player" << std::endl;
	}

	/* Binds textures to sprite */
	vanSprite.setTexture(vanTexture);
}

/* Draw function to draw the sprite */
void Van::drawCar(sf::RenderWindow & window)
{
	//window.draw(rect);		//Used for debugging of collision.
	window.draw(vanSprite);
}

/* Move function for sprite. Moves the sprite and resets its position when it goes off screen. */
void Van::move()
{
	vanSprite.move(-speed, 0);
	rect.move(-speed, 0);
	if (vanSprite.getPosition().x <= -108 && rect.getPosition().x <= -108) {
		vanSprite.setPosition(600, vanSprite.getPosition().y);
		rect.setPosition(600, rect.getPosition().y);
	}
}

/* Gets global bounds for collision. */
sf::FloatRect Van::getBB()
{
	return rect.getGlobalBounds();
}

Van::~Van()
{
}
