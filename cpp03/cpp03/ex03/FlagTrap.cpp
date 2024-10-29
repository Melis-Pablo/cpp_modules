#include "FlagTrap.hpp"

FlagTrap::FlagTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FlagTrap " << this->_name << " is born!" << std::endl;
}

FlagTrap::~FlagTrap() {
	std::cout << "FlagTrap " << this->_name << " is dead!" << std::endl;
}

void FlagTrap::highFivesGuys() {
	if (_energyPoints < 1)
		std::cout << "FlagTrap " << this->_name << " is out of energy!" << std::endl;
	else {
		std::cout << "FlagTrap " << this->_name << " requests a high five!" << std::endl;
		_energyPoints--;
	}
}