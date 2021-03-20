#pragma once
#include <algorithm>
#include "Dice.hpp"
#include "Player.hpp"

void capitalize(std::string& str)
{
	str[0] = (char)toupper(str[0]);
}

std::string inputName()
{
	std::string name;

	// Extracts characters to store it in a str
	std::getline(std::cin, name);

	capitalize(name);

	return name;
}

std::string chooseWeaponName()
{
	const std::string WEAPONS_NAME[] = {
		"Bow",
		"Sharp blade",
		"Mace"
	};

	std::cout << "Choose among these weapons : " << std::endl;

	// Iterates through the array
	for (const std::string& weaponName : WEAPONS_NAME)
		std::cout << "> " << weaponName << std::endl;

	std::string name = "";

	while (name == "")
	{
		std::getline(std::cin, name);

		capitalize(name);

		// If the user input text is not in the array
		if (std::find(std::begin(WEAPONS_NAME), std::end(WEAPONS_NAME), name) == std::end(WEAPONS_NAME))
		{
			std::cout << "Please enter a correct name!\n" << std::endl;
			name = "";
		}
	}

	return name;
}

void LaunchFight(Player& player, Entity& kraken)
{
	while (kraken.isAlive())
	{
		unsigned int result = Dice::roll();

		std::cout << "Dice result: " << result << std::endl;

		if (result % 2 != 0)
		{
			player.attack(kraken);
			std::cout << "You attacked the Kraken! ";

			if (kraken.isAlive())
				std::cout << "It has now " << kraken.getHealth() << " hp!" << std::endl;
			else
				std::cout << "It has no more hp!" << std::endl;
		}
		else if (result == 6)
		{
			kraken.attack(player);
			std::cout << "The Kraken attacked you ! ";

			if (player.isAlive())
				std::cout << "You have now " << player.getHealth() << " hp!" << std::endl;
			else
				std::cout << "You have no more hp!" << std::endl;
		}
		else
		{
			std::cout << "You couldn't attack!" << std::endl;
		}

		std::cout << '-' << std::endl;

		if (!player.isAlive())
		{
			std::cout << "\nThe darkness prevails... You are dead!" << std::endl;
			break;
		}
	}

	if (!kraken.isAlive())
		std::cout << "\nThe enemy has been defeated!" << std::endl;
}
