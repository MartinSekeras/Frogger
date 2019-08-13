#include "Car.h"
#include <iostream>

/* Main Function in class to create load texture and sprite for object & create pointers for position, scale, size, collision position & speed */
Car::Car(sf::Vector2f position, sf::Vector2f scale, sf::Vector2f dim, sf::Vector2f rectPos, float speedin, bool islog)
{
	/* Definitions */
	carSprite.setPosition(position);
	carSprite.setScale(scale);
	rect.setSize(dim);
	rect.setScale(scale);
	rect.setPosition(rectPos);
	speed = speedin;
	islog = islog;

	/* Loads texture */
	if (!carTexture.loadFromFile("../Assets/Textures/Car_Reversed_16x16.png")) {
		std::cout << "Error loading texture for Player" << std::endl;
	}

	/* Binds textures to sprite */
	carSprite.setTexture(carTexture);
}

/* Draw function to draw the sprite */
void Car::drawCar(sf::RenderWindow & window)
{
	//window.draw(rect);		//Used for debugging of collision.
	window.draw(carSprite);
}

/* Move function for sprite. Moves the sprite and resets its position when it goes off screen. */
void Car::move()
{
	carSprite.move(speed, 0);
	rect.move(speed, 0);
	if (carSprite.getPosition().x >= 632 && rect.getPosition().x >= 632) {
		carSprite.setPosition(-32, carSprite.getPosition().y);
		rect.setPosition(-32, rect.getPosition().y);
	}
}

/* Gets global bounds for collision. */
sf::FloatRect Car::getBB()
{
	return rect.getGlobalBounds();
}

Car::~Car()
{
}
