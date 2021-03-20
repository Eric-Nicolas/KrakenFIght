#pragma once
#include <cstdlib>

class Dice
{
public:
	static unsigned int roll()
	{
		return (rand() % 6) + 1;
	}
};
