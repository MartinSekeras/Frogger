#pragma once
#include "SFML/Graphics.hpp"

class Car
{

private:

	/* Creates private textures, sprites, rect for collision & variable for speed */
	sf::Texture carTexture;
	sf::Sprite carSprite;
	sf::RectangleShape rect;
	float speed;
	

public:

	/* Creates public functions */
	Car(sf::Vector2f position, sf::Vector2f scale, sf::Vector2f dim, sf::Vector2f rectPos, float speedin, bool islog);
	void drawCar(sf::RenderWindow &window);
	void move();
	sf::FloatRect getBB();
	bool islog;
	~Car();
};