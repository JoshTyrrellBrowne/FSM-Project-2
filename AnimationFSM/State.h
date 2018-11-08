#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <typeinfo>

#include <Input.h>
#include <Animation.h>
#include <Debug.h>

class State
{
public:
	virtual void handleInput() {}

	virtual void update() {}

	virtual void idle(Animation* a)
	{
		DEBUG_MSG("State::Idling");
		std::cout << "State::Idling" << std::endl;
	}
	virtual void jumping(Animation* a)
	{
		DEBUG_MSG("State::Jumping");
		std::cout << "State::Jumping" << std::endl;
	}
	virtual void climbing(Animation* a)
	{
		DEBUG_MSG("State::Climbing");
		std::cout << "State::Climbing" << std::endl;
	}
};

#endif // ! ANIMATION_H

