#include "TextureLoader.h"

/* Main Function in class to create load texture and sprite for object & create pointers for position, scale, size, collision position & speed */
TextureLoader::TextureLoader(sf::Vector2f homePosition, sf::Vector2f homeScale, sf::Vector2f frogHomeOnePosition, sf::Vector2f frogHomeOneScale)
{
	homeSprite.setPosition(homePosition);
	homeSprite.setScale(homeScale);

	frogHomeOneSprite.setPosition(frogHomeOnePosition);
	frogHomeOneSprite.setScale(frogHomeOneScale);

	/* Loads texture */
	if (!homeTexture.loadFromFile("../Assets/Textures/Top_Home_Area.png")) {
		std::cout << "Error loading texture Heart" << std::endl;
	}

	/* Loads texture */
	if (!frogHomeOneTexture.loadFromFile("../Assets/Textures/Frog_16x16.png")) {
		std::cout << "Error loading texture Heart" << std::endl;
	}

	/* Binds textures to sprite */
	homeSprite.setTexture(homeTexture);
	frogHomeOneSprite.setTexture(frogHomeOneTexture);

}

/* Draw function to draw the sprite */
void TextureLoader::drawHome(sf::RenderWindow & window)
{
	window.draw(homeSprite);
}

/* Draw function to draw the sprite */
void TextureLoader::drawHomeOne(sf::RenderWindow & window)
{
	window.draw(frogHomeOneSprite);
}

TextureLoader::~TextureLoader()
{
}
