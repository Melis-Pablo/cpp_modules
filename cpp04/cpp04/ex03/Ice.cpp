#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice Default constructor called" << std::endl;
}

Ice::Ice(const Ice &rhs) : AMateria("ice") {
	std::cout << "Ice Copy constructor called" << std::endl;
	*this = rhs;
}

Ice &Ice::operator=(const Ice &rhs) {
	std::cout << "Ice Assignation operator called" << std::endl;
	if (this != &rhs)
		AMateria::operator=(rhs);
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice Destructor called" << std::endl;
}

AMateria *Ice::clone() const {
	std::cout << "Ice Clone called" << std::endl;
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}