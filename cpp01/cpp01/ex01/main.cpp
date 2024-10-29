#include "Zombie.hpp"

int	main() {
	int N = 43;

	Zombie *zombies = zombieHorde(N, "PEDRO");
	for (int i = 0; i < N; i++) {
		std::cout << "Zombie " << i << ": ";
		zombies[i].announce();
	}
	delete [] zombies;
	return (0);
}