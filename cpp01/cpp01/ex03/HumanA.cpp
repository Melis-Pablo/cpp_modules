#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon) : _name(name), _weapon(Weapon) {
}

HumanA::~HumanA() {
}

void HumanA::attack() const {
	if (this->_weapon.get_type() != "")
		std::cout << this->_name << "attacks with his " << this->_weapon.get_type() << std::endl;
	else
		std::cout << this->_name << "Does not have a weapon to attack [They bit their opponent]" << std::endl;
}