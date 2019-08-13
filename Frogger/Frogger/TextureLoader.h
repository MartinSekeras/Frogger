#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class TextureLoader
{
private:

	/* Creates private textures and sprites */
	sf::Texture homeTexture;
	sf::Texture frogHomeOneTexture;
	sf::Sprite homeSprite;
	sf::Sprite frogHomeOneSprite;

public:

	/* Creates public functions */
	TextureLoader(sf::Vector2f homePosition, sf::Vector2f homeScale, sf::Vector2f frogHomeOnePosition, sf::Vector2f frogHomeOneScale);
	void drawHome(sf::RenderWindow &window);
	void drawHomeOne(sf::RenderWindow &window);

	~TextureLoader();
};

