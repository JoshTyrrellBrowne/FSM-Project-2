#ifndef PLAYER_H
#define PLAYER_H

#include <Input.h>
#include <Animation.h>
#include <AnimatedSprite.h>
#include <SFML/Graphics.hpp>

class Player
{
private:
	Animation m_animation;
	AnimatedSprite m_animated_sprite;
	Player();

public:
	Player(const AnimatedSprite&);
	~Player();
	AnimatedSprite& getAnimatedSprite();
	void handleInput(sf::RenderWindow&);
	void update();

	void setStateSprites(const AnimatedSprite&);
};

#endif // !PLAYER_H
