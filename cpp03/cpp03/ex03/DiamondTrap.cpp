#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FlagTrap(name), _name(name) {
    _hitPoints = FlagTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FlagTrap::_attackDamage;
    std::cout << "DiamondTrap " << _name << " created." << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destroyed." << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}