#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs) {
	std::cout << "ClapTrap " << rhs._name << " is cloned!" << std::endl;
	*this = rhs;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	std::cout << "ClapTrap " << rhs._name << " is assigned!" << std::endl;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (_energyPoints < 1)
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
	else {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints < amount)
		std::cout << "ClapTrap " << _name << " died from the attack!" << std::endl;
	else {
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints < 1)
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
	else {
		std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
}