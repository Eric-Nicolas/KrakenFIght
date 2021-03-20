#pragma once
#include <string>

class Weapon
{
public:
	Weapon(const std::string& name = "")
		: _name(name), _attack(0)
	{
		if (name != "")
			_name[0] = (char)toupper(_name[0]);

		if (name == "Bow")
			_attack = 15;
		else if (name == "Sharp Blade")
			_attack = 30;
		else
			_attack = 23;
	}

	Weapon(const Weapon& other)
		: _name(other._name), _attack(other._attack)
	{
	}

	unsigned int getAttack() const { return _attack; }

	void setAttack(unsigned int attack)
	{
		_attack = attack;
	}

	const std::string& getName() const
	{
		return _name;
	}

private:
	std::string _name;
	unsigned int _attack;
};
