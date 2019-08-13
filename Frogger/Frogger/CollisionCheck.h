#pragma once
#include "SFML/Graphics.hpp"

#ifndef CollisionCheck

class CollisionCheck
{

private:

	/* Creates private rect for collision with homes. */
	sf::RectangleShape rect;

public:

	/* Creates public functions */
	CollisionCheck(sf::Vector2f position, sf::Vector2f scale, sf::Vector2f size);
	sf::FloatRect getBB();
	void drawRect(sf::RenderWindow &window);

	~CollisionCheck();
};

#endif

