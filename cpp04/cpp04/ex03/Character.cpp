#include "Character.hpp"

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	std::cout << "Character " << this->_name << " created" << std::endl;
}

Character::Character(const Character &copy) {
	*this = copy;
	std::cout << "Character " << this->_name << " copied/created" << std::endl;
}

Character &Character::operator=(const Character &rhs) {
	if (this == &rhs)
		return *this;
	this->_name = rhs._name;
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
		this->_materia[i] = rhs._materia[i]->clone();
	}
	std::cout << "Character " << this->_name << " assigned" << std::endl;
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
	}
	std::cout << "Character " << this->_name << " destroyed" << std::endl;
}

std::string const &Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] == NULL) {
			this->_materia[i] = m;
			std::cout << "Materia " << m->getType() << " equipped" << std::endl;
			return;
		}
	}
	std::cout << "Materia " << m->getType() << " not equipped" << std::endl;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && this->_materia[idx] != NULL) {
		this->_materia[idx] = NULL;
		std::cout << "Materia " << idx << " unequipped" << std::endl;
	}
	else
		std::cout << "Materia " << idx << " not unequipped" << std::endl;
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < 4 && this->_materia[idx] != NULL) {
		this->_materia[idx]->use(target);
		std::cout << "Materia " << idx << " used" << std::endl;
	}
	else
		std::cout << "Materia " << idx << " not used" << std::endl;
}
