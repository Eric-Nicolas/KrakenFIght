#include <ctime>
#include "Functions.hpp"

int main()
{
	srand(time(nullptr));

	std::cout << "Welcome to you, young fighter!" << std::endl;
	std::cout << "Enter your name : ";

	Player player(inputName(), 100, 10);

	std::cout << "\nVery good " << player.getName() << '!' << std::endl;
	
	std::string weaponSelected(chooseWeaponName());
	std::cout << "You chose: " << weaponSelected << std::endl;

	player.addWeapon(Weapon(weaponSelected));
	player.showInfo();

	std::cout << "\n-----------------------------------\n" << std::endl;
	
	Entity kraken(400, 10);
	LaunchFight(player, kraken);

	return 0;
}
