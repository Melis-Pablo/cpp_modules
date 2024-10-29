#include "Animal.hpp"

Animal::Animal(void) : _type("Animal") {
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal Default constructor called by type: " << _type << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal &rhs) {
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = rhs;
}

Animal &Animal::operator=(const Animal &rhs) {
	std::cout << "Animal Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::setType(std::string type) {
	this->_type = type;
}
