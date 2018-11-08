#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>

using namespace std;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets\\grid.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

	// Setup Players Default Animated Sprite
	AnimatedSprite animated_spriteIdle(texture);
	AnimatedSprite animated_spriteJumping(texture);
	//IDLE
	animated_spriteIdle.addFrame(sf::IntRect(3, 3, 84, 84));
	animated_spriteIdle.addFrame(sf::IntRect(88, 3, 84, 84));
	animated_spriteIdle.addFrame(sf::IntRect(173, 3, 84, 84));
	animated_spriteIdle.addFrame(sf::IntRect(258, 3, 84, 84));
	animated_spriteIdle.addFrame(sf::IntRect(343, 3, 84, 84));
	animated_spriteIdle.addFrame(sf::IntRect(428, 3, 84, 84));
	//JUMPING
	animated_spriteJumping.addFrame(sf::IntRect(3, 88, 84, 84));
	animated_spriteJumping.addFrame(sf::IntRect(88, 88, 84, 84));
	animated_spriteJumping.addFrame(sf::IntRect(173, 88, 84, 84));
	animated_spriteJumping.addFrame(sf::IntRect(258, 88, 84, 84));
	animated_spriteJumping.addFrame(sf::IntRect(343, 88, 84, 84));
	animated_spriteJumping.addFrame(sf::IntRect(428, 88, 84, 84));


	// Setup the Player
	Player player(animated_spriteIdle);
	Input input;
	
	// Start the game loop
	while (window.isOpen())
	{
		//// Process events
		//sf::Event event;
		//while (window.pollEvent(event))
		//{
		//	switch (event.type)
		//	{
		//	case sf::Event::Closed:
		//		// Close window : exit
		//		window.close();
		//		break;
		//	case sf::Event::KeyPressed:
		//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		//		{
		//			//player.
		//			input.setCurrent(Input::Action::LEFT);
		//		}
		//		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		//		{
		//			input.setCurrent(Input::Action::RIGHT);
		//		}
		//		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		//		{
		//			input.setCurrent(Input::Action::UP);
		//		}
		//		break;
		//	default:
		//		input.setCurrent(Input::Action::IDLE);
		//		break;
		//	}
		//}

		// Handle input to Player
		player.handleInput(window);

		// Update the Player
		player.update();

		// Clear screen
		window.clear();

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};