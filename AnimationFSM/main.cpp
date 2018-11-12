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
	AnimatedSprite animated_spriteClimbing(texture);
	AnimatedSprite animated_spriteShoveling(texture);
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
	//CLIMBING
	animated_spriteClimbing.addFrame(sf::IntRect(3, 173, 84, 84));
	animated_spriteClimbing.addFrame(sf::IntRect(88, 173, 84, 84));
	animated_spriteClimbing.addFrame(sf::IntRect(173, 173, 84, 84));
	animated_spriteClimbing.addFrame(sf::IntRect(258, 173, 84, 84));
	animated_spriteClimbing.addFrame(sf::IntRect(343, 173, 84, 84));
	animated_spriteClimbing.addFrame(sf::IntRect(428, 173, 84, 84));
	//SHOVELING
	animated_spriteShoveling.addFrame(sf::IntRect(3, 258, 84, 84));
	animated_spriteShoveling.addFrame(sf::IntRect(88, 258, 84, 84));
	animated_spriteShoveling.addFrame(sf::IntRect(173, 258, 84, 84));
	animated_spriteShoveling.addFrame(sf::IntRect(258, 258, 84, 84));
	animated_spriteShoveling.addFrame(sf::IntRect(343, 258, 84, 84));
	animated_spriteShoveling.addFrame(sf::IntRect(428, 258, 84, 84));

	// Setup the Player
	Player player(animated_spriteIdle);
	Input input;
	
	// Start the game loop
	while (window.isOpen())
	{
		// ANIMATION CHANGE ==================================================================
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		{
			if (player.getAnimatedSprite().getTextureRect().top != 258)	//if current animation != shoveling
			{
				player.setStateSprites(animated_spriteJumping);		//set to jumping animation
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		{
			player.setStateSprites(animated_spriteIdle);		//set to idle animation
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			if (player.getAnimatedSprite().getTextureRect().top != 258)	//if current animation != shoveling
			{
				player.setStateSprites(animated_spriteClimbing);	//set to climbing animation
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player.setStateSprites(animated_spriteShoveling);	//set to shoveling animation
		}

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