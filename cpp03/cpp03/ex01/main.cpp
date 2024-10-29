#include "ScavTrap.hpp"

int main(void) {
	ScavTrap scavTrap("Scabby");

	scavTrap.attack("target");
	scavTrap.takeDamage(10);
	scavTrap.beRepaired(5);
	scavTrap.guardGate();

	return 0;
}