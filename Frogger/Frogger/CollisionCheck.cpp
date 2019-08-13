#include "CollisionCheck.h"
#include "Player.h"
#include "Car.h"

/* Main Function in class to create object & create pointers for position, scale & size. */
CollisionCheck::CollisionCheck(sf::Vector2f position, sf::Vector2f scale, sf::Vector2f size)
{
	rect.setPosition(position);
	rect.setScale(scale);
	rect.setSize(size);
}

/* Gets global bounds for collision. */
sf::FloatRect CollisionCheck::getBB()
{
	return rect.getGlobalBounds();
}

/* Used draw function to align collision boxes properly. */
void CollisionCheck::drawRect(sf::RenderWindow & window)
{
		window.draw(rect);
}

CollisionCheck::~CollisionCheck()
{

}
