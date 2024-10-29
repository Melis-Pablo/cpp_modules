#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->setType(type);
}

Weapon::~Weapon(void) {
}

const std::string &Weapon::get_type() {
	return (this->_type);
}

void Weapon::setType(std::string type) {
	this->_type = type;
}