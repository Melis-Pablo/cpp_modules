#include "Zombie.hpp"

int main(void) {
	std::string name;

	std::cout << "Choose name for zombie on the stack" << std::endl;
	std::cout << "Name: " << std::flush;
	std::cin >> name;

	Zombie zombie_s(name);

	std::cout << "Choose name for zombie on the heap" << std::endl;
	std::cout << "Name: " << std::flush;
	std::cin >> name;

	zombie_s.announce();

	Zombie *zombie_h = newZombie(name);
	zombie_h->announce();
	delete zombie_h;

	std::cout << "randomChump(): " << std::endl;
	randomChump("chumper");
	return (0);
}