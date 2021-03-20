#pragma once
#include <iostream>
#include <string>
#include "Entity.hpp"
#include "Weapon.hpp"

class Player : public Entity
{
public:
	Player(const std::string& name, int health, unsigned int attack) 
		: Entity(health, attack)
	{
		_name = name;
	}

	const std::string& getName() const { return _name; }

	void addWeapon(const Weapon& weapon)
	{
		_weapon = Weapon(weapon);
		_attack += weapon.getAttack();
	}

	void showInfo() const
	{
		std::cout << "\nName: " << _name << std::endl;
		std::cout << "Weapon: " << _weapon.getName() << std::endl;
		std::cout << "Hp: " << _health << std::endl;
		std::cout << "Damage: " << _attack << std::endl;
	}

private:
	std::string _name;
	Weapon _weapon;
};
