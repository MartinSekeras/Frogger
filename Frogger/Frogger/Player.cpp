#include "Player.h"
#include <iostream>

/* Main Function in class to create load texture and sprite for object & create pointers for position, scale, size & collision position */
Player::Player(sf::Vector2f position, sf::Vector2f scale, sf::Vector2f dim, sf::Vector2f rectPosition, bool isOnLog)
{

	/* Definitions */
	playerSprite.setPosition(position);
	playerSprite.setScale(scale);
	rect.setSize(dim);
	rect.setPosition(rectPosition);
	isOnLog = isOnLog;
	
	/* Loads texture */
	if (!playerTexture.loadFromFile("../Assets/Textures/Frog_16x16.png")) {
		std::cout << "Error loading texture for Player" << std::endl;
	}

	/* Binds textures to sprite */
	playerSprite.setTexture(playerTexture);
	
}

/* Draw function to draw the sprite */
void Player::drawPl(sf::RenderWindow & window)
{
	//window.draw(rect);
	window.draw(playerSprite);
}

/* Move function for sprite. Moves the sprite while it's on screen; if the sprite is about to move offscreen with next move it ignores the input. */
void Player::moveUp()
{
	if (playerSprite.getPosition().y > 20) {
		if (playerSprite.getPosition().y == 74 && playerSprite.getPosition().x == 78) {
			//Do nothing!!!
		}
		else if(playerSprite.getPosition().y == 74 && playerSprite.getPosition().x == 206) {
			//Do nothing!!!
		}
		else if (playerSprite.getPosition().y == 74 && playerSprite.getPosition().x == 334) {
			//Do nothing!!!
		}
		else if (playerSprite.getPosition().y == 74 && playerSprite.getPosition().x == 462) {
			//Do nothing!!!
		}
		else {
			playerSprite.move(0, -60);
			rect.move(0, -60);
		}
	
	}
}

/* Move function for sprite. Moves the sprite while it's on screen; if the sprite is about to move offscreen with next move it ignores the input. */
void Player::moveDown()
{
	if (playerSprite.getPosition().y < 734) {
		playerSprite.move(0, 60);
		rect.move(0, 60);
	}
}

/* Move function for sprite. Moves the sprite while it's on screen; if the sprite is about to move offscreen with next move it ignores the input. */
void Player::moveleft()
{
	if(playerSprite.getPosition().x > 20) {
	playerSprite.move(-64, 0);
	rect.move(-64, 0);
	}
}

/* Move function for sprite. Moves the sprite while it's on screen; if the sprite is about to move offscreen with next move it ignores the input. */
void Player::moveRight()
{
	if (playerSprite.getPosition().x < 520) {
	playerSprite.move(64, 0);
	rect.move(64, 0);
	}
}

/* Gets the position of plater sprite and returns it to whatever calls this function. */
float Player::getPosition()
{
	return playerSprite.getPosition().y;
}

/* Gets the rect used for collision and returns it. */
sf::RectangleShape Player::getRect()
{
	return rect;
}

/* Gets the player sprite and returns it. */
sf::Sprite Player::getSprite()
{
	return playerSprite;
}

/* Gets global bounds for collision. */
sf::FloatRect Player::getBB()
{
	return rect.getGlobalBounds();
}

/* Function to reset position of player when called. */
void Player::resetPos()
{
	playerSprite.setPosition(270, 734);
	rect.setPosition(277, 737);
}

Player::~Player()
{
}
