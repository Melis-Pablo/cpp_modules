#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " is born!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " is dead!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_energyPoints < 1)
		std::cout << "ScavTrap " << _name << " is out of energy!" << std::endl;
	else {
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode!" << std::endl;
}