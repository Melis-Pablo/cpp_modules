#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap diamondTrap("Diamond");

    diamondTrap.attack("target");
    diamondTrap.takeDamage(10);
    diamondTrap.beRepaired(5);
    diamondTrap.whoAmI();
	return 0;
}