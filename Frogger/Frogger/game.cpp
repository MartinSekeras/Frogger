#include "game.h"


game::game()
{
		/* Establishes the window */
		sf::RenderWindow window(sf::VideoMode(600, 860), "Frogger v1.0");

		/* Sets the maximum framerate of the window to 60 */
		window.setFramerateLimit(60);

		/* Loads player */
		Player player(sf::Vector2f(270, 734), sf::Vector2f(4, 4), sf::Vector2f(50, 55), sf::Vector2f(277, 736), false);

		/* Loads textures from class which will be drawn if certain conditions apply */
		TextureLoader home(sf::Vector2f(0, 0), sf::Vector2f(1, 1), sf::Vector2f(14, 15), sf::Vector2f(4, 4));		//Includes render for first frog on Home 1, & Background! Background is always drawn!
		TextureLoader HomeOne(sf::Vector2f(0, 0), sf::Vector2f(1, 1), sf::Vector2f(142, 15), sf::Vector2f(4, 4));
		TextureLoader HomeTwo(sf::Vector2f(0, 0), sf::Vector2f(1, 1), sf::Vector2f(270, 15), sf::Vector2f(4, 4));
		TextureLoader HomeThree(sf::Vector2f(0, 0), sf::Vector2f(1, 1), sf::Vector2f(398, 15), sf::Vector2f(4, 4));
		TextureLoader HomeFour(sf::Vector2f(0, 0), sf::Vector2f(1, 1), sf::Vector2f(526, 15), sf::Vector2f(4, 4));

		/* Loads all the cars */
		Car car(sf::Vector2f(400, 673), sf::Vector2f(4.0, 4.0), sf::Vector2f(15, 10), sf::Vector2f(400, 685), 6.0, false);
		Van vanOne(sf::Vector2f(400, 620), sf::Vector2f(4.0, 4.0), sf::Vector2f(29, 10), sf::Vector2f(400, 624), 6.0, false);
		Car carThree(sf::Vector2f(400, 553), sf::Vector2f(4.0, 4.0), sf::Vector2f(15, 10), sf::Vector2f(400, 565), 4.0, false);
		Van vanTwo(sf::Vector2f(400, 500), sf::Vector2f(4.0, 4.0), sf::Vector2f(29, 10), sf::Vector2f(400, 504), 7.0, false);

		Car carFive(sf::Vector2f(400, 373), sf::Vector2f(4.0, 4.0), sf::Vector2f(15, 10), sf::Vector2f(400, 385), 5.0, false);
		Van vanThree(sf::Vector2f(400, 320), sf::Vector2f(4.0, 4.0), sf::Vector2f(29, 10), sf::Vector2f(400, 324), 5.0, false);
		Car carSeven(sf::Vector2f(400, 253), sf::Vector2f(4.0, 4.0), sf::Vector2f(15, 10), sf::Vector2f(400, 265), 7.0, false);

		Van vanFour(sf::Vector2f(400, 143), sf::Vector2f(4.0, 4.0), sf::Vector2f(29, 10), sf::Vector2f(400, 147), 8.0, false);
		Car carNine(sf::Vector2f(400, 75), sf::Vector2f(4.0, 4.0), sf::Vector2f(15, 10), sf::Vector2f(400, 87), 9.0, false);

		/* Loads collision with homes on the top of the screen */
		CollisionCheck homeOne(sf::Vector2f(18, 15), sf::Vector2f(4.0, 4.0), sf::Vector2f(14, 14));
		CollisionCheck homeTwo(sf::Vector2f(146, 15), sf::Vector2f(4.0, 4.0), sf::Vector2f(14, 14));
		CollisionCheck homeThree(sf::Vector2f(274, 15), sf::Vector2f(4.0, 4.0), sf::Vector2f(14, 14));
		CollisionCheck homeFour(sf::Vector2f(401, 15), sf::Vector2f(4.0, 4.0), sf::Vector2f(14, 14));
		CollisionCheck homeFive(sf::Vector2f(529, 15), sf::Vector2f(4.0, 4.0), sf::Vector2f(14, 14));

		/* Sets a bool for each home so we can use it later for end game and more stuff for game over */
		bool homeOneColl = false;
		bool homeTwoColl = false;
		bool homeThreeColl = false;
		bool homeFourColl = false;
		bool homeFiveColl = false;
		bool gameOver = false;
		bool gameWon = false;
		bool gameRunning = true;

		int score = 0;
		int moveReward = 10;
		int homeReward = 200;

		/* Loads the textures and binds them to sprite so we can use it */
		sf::Texture timerBarT;
		sf::Sprite timerBarS;
		//Loads texture.
		if (!timerBarT.loadFromFile("../Assets/Textures/timer_bar.png")) {
			std::cout << "Error loading texture Heart" << std::endl;
		}
		//Binds textures to sprite
		timerBarS.setPosition(0, 850);
		timerBarS.setScale(1, 10);
		timerBarS.setTexture(timerBarT);

		/* Loads the textures and binds them to sprite so we can use it */
		sf::Texture hTexture;
		sf::Sprite health;
		//Loads texture.
		if (!hTexture.loadFromFile("../Assets/Textures/Heart_Full.png")) {
			std::cout << "Error loading texture Heart" << std::endl;
		}
		//Binds textures to sprite
		health.setPosition(450, 800);
		health.setScale(3, 3);
		health.setTexture(hTexture);

		/* Loads font and creates text from the font so we can use it in string */
		sf::Font Controls;
		//Loads texture.
		if (!Controls.loadFromFile("../Assets/Fonts/arial.ttf"))
		{
			std::cout << "Error loading font Arial" << std::endl;
		}
		//Binds Font to Text.
		sf::Text ControlText;
		ControlText.setFont(Controls);
		ControlText.setString("ESC <-- EXIT \nARROW KEYS <-- MOVEMENT \nR <--RELOAD");
		ControlText.setCharacterSize(13);
		ControlText.setPosition(5, 800);

		/* Loads font and creates text from the font so we can use it in string */
		sf::Font youLost;
		//Loads font.
		if (!youLost.loadFromFile("../Assets/Fonts/arial.ttf"))
		{
			std::cout << "Error loading font Arial" << std::endl;
		}
		//Binds Font to Text.
		sf::Text youLostText;
		youLostText.setFont(youLost);
		youLostText.setString("You Lost");
		youLostText.setCharacterSize(52);
		youLostText.setPosition(200, 430);

		/*******************************************************************************************************************************************
		*    Title: "Easiest way to convert int to string in C++"
		*    Poster: Nemo
		*    Date: April 8 2011
		*    Code version: Unknown
		*	 What was used?: The below available conversion from intiger to string using stringstream was borrowed and modified to suit my purpose.
		*    Availability: https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c.
		*******************************************************************************************************************************************/

		/* Converts a int value to string */
		std::stringstream ss;
		ss << score;
		std::string scoreString = ss.str();

		/* Loads font and creates text from the font so we can use it in string */
		sf::Font scoreFont;
		//Loads font.
		if (!scoreFont.loadFromFile("../Assets/Fonts/arial.ttf"))
		{
			std::cout << "Error loading font Arial" << std::endl;
		}
		//Binds Font to Text.
		sf::Text scoreText;
		scoreText.setFont(scoreFont);
		scoreText.setString(scoreString);
		scoreText.setCharacterSize(24);
		scoreText.setPosition(290, 815);

		/* Loads font and creates text from the font so we can use it in string */
		sf::Font youWon;
		//Loads font.
		if (!youWon.loadFromFile("../Assets/Fonts/arial.ttf"))
		{
			std::cout << "Error loading font Arial" << std::endl;
		}
		//Binds Font to Text.
		sf::Text youWonText;
		youWonText.setFont(youWon);
		youWonText.setString("You Won");
		youWonText.setCharacterSize(52);
		youWonText.setPosition(200, 430);

		/* Main while loop */
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type) {
				case sf::Event::Closed:
					window.close();
					/* Controls */
				case sf::Event::KeyReleased:
					if (sf::Keyboard::Key::Up == event.key.code && gameOver == false) {
						player.moveUp();
						score += moveReward;
					}
					else if (sf::Keyboard::Key::Down == event.key.code && gameOver == false) {
						player.moveDown();
						//Score not increase
					}
					else if (sf::Keyboard::Key::Left == event.key.code && gameOver == false) {
						player.moveleft();
						//score not increase
					}
					else if (sf::Keyboard::Key::Right == event.key.code && gameOver == false) {
						player.moveRight();
						//score not increase
					}
					else if (sf::Keyboard::Key::Escape == event.key.code) {
						window.close();
					}
					else if (sf::Keyboard::Key::R == event.key.code) {
						gameOver = false;
						health.setPosition(450, 800);
						homeOneColl = false;
						homeTwoColl = false;
						homeThreeColl = false;
						homeFourColl = false;
						homeFiveColl = false;
						gameRunning = true;
						gameWon = false;
						window.clear();
						timerBarS.setPosition(0, 850);
						score = 0;
						player.resetPos();
					}
				}
			}

			/* Converts a int value to string */
			std::stringstream ss;
			ss << score;
			std::string scoreString = ss.str();

			/* Displays the int value converted to string */
			scoreText.setString(scoreString);

			/* makes the timer move if game is not over */
			if (gameRunning == true) {
				timerBarS.move(-0.2, 0);
			}
			
			/* Makes the objects move on screen. */
			car.move();
			vanOne.move();
			carThree.move();
			vanTwo.move();
			carFive.move();
			vanThree.move();
			carSeven.move();
			vanFour.move();
			carNine.move();

			/*Checks for collision with any moving objects on screen. */
			if (player.getBB().intersects(car.getBB())) {
				std::cout << "Collided 1" << std::endl;
				player.resetPos();
				health.move(48, 0);
			}
			else if (player.getBB().intersects(vanOne.getBB())) {
				std::cout << "Collided 2" << std::endl;
				player.resetPos();
				health.move(48, 0);
			}
			else if (player.getBB().intersects(carThree.getBB())) {
				std::cout << "Collided 3" << std::endl;
				player.resetPos();
				health.move(48, 0);
			}
			else if (player.getBB().intersects(vanTwo.getBB())) {
				std::cout << "Collided 4" << std::endl;
				player.resetPos();
				health.move(48, 0);
			}
			else if (player.getBB().intersects(carFive.getBB())) {
				std::cout << "Collided 5" << std::endl;
				player.resetPos();
				health.move(48, 0);
			}
			else if (player.getBB().intersects(vanThree.getBB())) {
				std::cout << "Collided 6" << std::endl;
				player.resetPos();
				health.move(48, 0);
			}
			else if (player.getBB().intersects(carSeven.getBB())) {
				std::cout << "Collided 7" << std::endl;
				player.resetPos();
				health.move(48, 0);
			}
			else if (player.getBB().intersects(vanFour.getBB())) {
				std::cout << "Collided 8" << std::endl;
				player.resetPos();
				health.move(48, 0);
			}
			else if (player.getBB().intersects(carNine.getBB())) {
				std::cout << "Collided 9" << std::endl;
				player.resetPos();
				health.move(48, 0);
			}

			/* Check for collision with homes */
			if (player.getBB().intersects(homeOne.getBB())) {

				if (homeOneColl == false) {
					score += homeReward;
				}

				std::cout << "Collided w/ Home 1" << std::endl;
				homeOneColl = true;
				player.resetPos();
				
			}
			else if (player.getBB().intersects(homeTwo.getBB())) {

				if (homeTwoColl == false) {
					score += homeReward;
				}

				std::cout << "Collided w/ Home 2" << std::endl;
				homeTwoColl = true;
				player.resetPos();
				
			}
			else if (player.getBB().intersects(homeThree.getBB())) {

				if (homeThreeColl == false) {
					score += homeReward;
				}

				std::cout << "Collided w/ Home 3" << std::endl;
				homeThreeColl = true;
				player.resetPos();
				
			}
			else if (player.getBB().intersects(homeFour.getBB())) {

				if (homeFourColl == false) {
					score += homeReward;
				}

				std::cout << "Collided w/ Home 4" << std::endl;
				homeFourColl = true;
				player.resetPos();
				
			}
			else if (player.getBB().intersects(homeFive.getBB())) {

				if (homeFiveColl == false) {
					score += homeReward;
				}

				std::cout << "Collided w/ Home 5" << std::endl;
				homeFiveColl = true;
				player.resetPos();
				
			}

			/*Draws all objects on screen.*/
			window.clear();
			home.drawHome(window);
			player.drawPl(window);
			car.drawCar(window);
			vanOne.drawCar(window);
			carThree.drawCar(window);
			vanTwo.drawCar(window);
			carFive.drawCar(window);
			vanThree.drawCar(window);
			carSeven.drawCar(window);
			vanFour.drawCar(window);
			carNine.drawCar(window);
			window.draw(health);
			window.draw(ControlText);
			window.draw(timerBarS);
			window.draw(scoreText);

			/* If you collide with home a boolean is set true and if that is set true a frog is drawn onto that spot. */
			if (homeOneColl == true) {
				home.drawHomeOne(window);
			}
			if (homeTwoColl == true) {
				HomeOne.drawHomeOne(window);
			}
			if (homeThreeColl == true) {
				HomeTwo.drawHomeOne(window);
			}
			if (homeFourColl == true) {
				HomeThree.drawHomeOne(window);
			}
			if (homeFiveColl == true) {
				HomeFour.drawHomeOne(window);
			}

			/* Checks if all homes havebeen triggered */
			if (homeOneColl == true && homeTwoColl == true && homeThreeColl == true && homeFourColl == true && homeFiveColl == true) {
				/* If all homes have been triggered then game ends */
				window.draw(youWonText);
				gameOver = true;
				gameWon = true;
				gameRunning = false;
			}

			/* Game over if health reaches 0 or better yet when position of health goes above 590 to save time and memory. */
			if (health.getPosition().x > 590) {
				/* DIsplays messages and enables gameOver bool to block input */
				window.draw(youLostText);
				gameOver = true;
				gameRunning = false;
			}

			/* Checks if the position of timer is -600 or in better terms it chesks if the timer has moved from the screen */
			if (timerBarS.getPosition().x < -600 && gameWon == false) {
				/* DIsplays messages and enables gameOver bool to block input */
				window.draw(youLostText);
				gameOver = true;
				gameRunning = false;
			}

			window.display();
		}
	}


game::~game()
{
}
