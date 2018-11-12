#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>


Player::Player()
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::Player(const AnimatedSprite& s) : m_animated_sprite(s)
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::~Player() {}

AnimatedSprite& Player::getAnimatedSprite()
{
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::handleInput(sf::RenderWindow& t_window)
{
	DEBUG_MSG("Handle Input");

	//switch (in.getCurrent())
	//{
	//case Input::Action::IDLE:
	//	//std::cout << "Player Idling" << std::endl;
	//	m_animation.idle();
	//	break;
	//case Input::Action::UP:
	//	//std::cout << "Player Up" << std::endl;
	//	m_animation.climbing();
	//	break;
	//case Input::Action::LEFT:
	//	//std::cout << "Player Left" << std::endl;
	//	m_animation.jumping();
	//	break;
	//case Input::Action::RIGHT:
	//	//std::cout << "Player Idling" << std::endl;
	//	m_animation.jumping();
	//	break;
	//default:
	//	break;
	//}

	// Process events
	sf::Event event;
	while (t_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			// Close window : exit
			t_window.close();
			break;
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
			{
				m_animation.idle();
				//input.setCurrent(Input::Action::LEFT);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
			{
				m_animation.climbing();
				//input.setCurrent(Input::Action::RIGHT);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
			{
				m_animation.jumping();
				//input.setCurrent(Input::Action::UP);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				m_animation.shoveling();
				//input.setCurrent(Input::Action::UP);
			}
			break;
		default:
			//input.setCurrent(Input::Action::IDLE);
			break;
		}
	}
}

void Player::update()
{
	//std::cout << "Handle Update" << std::endl;
	//int stateIndex = m_animation.getCurrent();
	m_animated_sprite.update();
}

void Player::setStateSprites(const AnimatedSprite& t_animatedSprite)
{
	//m_animation.setCurrent(new Idle());
	//m_animation.setPrevious(new Idle());
	m_animated_sprite = t_animatedSprite;
}
