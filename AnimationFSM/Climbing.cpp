#include <Climbing.h>
#include <Jumping.h>
#include <Idle.h>
#include <Shoveling.h>

#include <string>

void Climbing::idle(Animation* a)
{
	std::cout << "Climbing -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
void Climbing::jumping(Animation* a)
{
	std::cout << "Climbing -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Climbing::shoveling(Animation * a)
{
	std::cout << "Climbing -> Shoveling" << std::endl;
	a->setCurrent(new Shoveling());
	delete this;
}
