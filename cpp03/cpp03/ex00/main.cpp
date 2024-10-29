#include "ClapTrap.hpp"

int main(void) {
    ClapTrap claptrap1("ClapTrap1");
    ClapTrap claptrap2("ClapTrap2");

    // Test attack
    claptrap1.attack("Target1");
    // Expected output: ClapTrap ClapTrap1 attacks Target1, causing 0 points of damage!

    // Test takeDamage
    claptrap1.takeDamage(5);
    // Expected output: ClapTrap ClapTrap1 takes 5 points of damage!

    // Test beRepaired
    claptrap1.beRepaired(3);
    // Expected output: ClapTrap ClapTrap1 is repaired for 3 points!

    // Test energy depletion
    for (int i = 0; i < 9; ++i) {
        claptrap1.attack("Target2");
    }
    // Expected output: ClapTrap ClapTrap1 attacks Target2, causing 0 points of damage! (repeated 8 times)
    // Expected output: ClapTrap ClapTrap1 is out of energy!

    // Test cloning
    ClapTrap claptrap3(claptrap1);
    // Expected output: ClapTrap ClapTrap1 is cloned!
	// Expected output: ClapTrap ClapTrap1 is assigned!

    // Test assignment
    claptrap2 = claptrap1;
    // Expected output: ClapTrap ClapTrap2 is assigned!

    return 0;
}