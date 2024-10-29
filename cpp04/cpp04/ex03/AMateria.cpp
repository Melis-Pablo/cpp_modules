#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {
	std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << "AMateria Default constructor called by type: " << _type << std::endl;
}

AMateria::AMateria(AMateria const & src) {
	std::cout << "AMateria Copy constructor called" << std::endl;
	*this = src;
}

AMateria & AMateria::operator=(AMateria const & rhs) {
	std::cout << "AMateria Assignation operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

AMateria::~AMateria() {
	std::cout << "AMateria Destructor called by type: " << _type << std::endl;
}

std::string const & AMateria::getType() const {
	return this->_type;
}

AMateria* AMateria::clone() const {
	return (AMateria*)this;
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria " << _type << " used on " << target.getName() << std::endl;
}