#include "Shoveling.h"

#include "Idle.h"
#include "Jumping.h"
#include "Climbing.h"

void Shoveling::idle(Animation * a)
{
	std::cout << "Shoveling -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Shoveling::climbing(Animation * a)
{
	std::cout << "Cannot go from shoveling to climbing." << std::endl;
	
}

void Shoveling::jumping(Animation * a)
{
	std::cout << "Cannot go from shoveling to jumping." << std::endl;
}
