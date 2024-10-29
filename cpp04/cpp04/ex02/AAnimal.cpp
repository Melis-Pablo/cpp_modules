#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("Animal") {
	std::cout << "Animal Default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << "Animal Default constructor called by type: " << _type << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "Animal Destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &rhs) {
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = rhs;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs) {
	std::cout << "Animal Assignation operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

void AAnimal::makeSound() const {
	std::cout << "Animal Sound" << std::endl;
}

std::string AAnimal::getType() const {
	return this->_type;
}

void AAnimal::setType(std::string type) {
	this->_type = type;
}