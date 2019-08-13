#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
private:

	/* Creates private textures, sprites & rect for collision */
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::RectangleShape rect;

public:

	/* Creates public functions */
	Player(sf::Vector2f position, sf::Vector2f scale, sf::Vector2f dim, sf::Vector2f rectPosition, bool isOnLog);
	void drawPl(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	void moveleft();
	void moveRight();
	float getPosition();
	sf::RectangleShape getRect();
	sf::Sprite getSprite();
	sf::FloatRect getBB();
	void resetPos();
	bool isOnLog;
	

	~Player();
};