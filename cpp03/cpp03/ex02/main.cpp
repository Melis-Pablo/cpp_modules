#include "FlagTrap.hpp"

int main(void) {
	FlagTrap FlagTrap("Flaggy");

	FlagTrap.attack("target");
	FlagTrap.takeDamage(5);
	FlagTrap.beRepaired(5);
	FlagTrap.highFivesGuys();

	return 0;
}