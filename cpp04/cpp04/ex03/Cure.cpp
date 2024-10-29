#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure(const Cure &rhs) : AMateria("cure") {
	std::cout << "Cure Copy constructor called" << std::endl;
	*this = rhs;
}

Cure &Cure::operator=(const Cure &rhs) {
	std::cout << "Cure Assignation operator called" << std::endl;
	if (this != &rhs)
		AMateria::operator=(rhs);
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure Destructor called" << std::endl;
}

AMateria *Cure::clone() const {
	std::cout << "Cure Clone called" << std::endl;
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}