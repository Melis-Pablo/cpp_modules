#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
}

HumanB::~HumanB() {
}

void HumanB::attack() const {
	if (this->_weapon != NULL && this->_weapon->get_type() != "")
		std::cout << _name << "attacks with his " << this->_weapon->get_type() << std::endl;
	else
		std::cout << _name << "Does not have a weapon to attack [They bit their opponent]" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}