#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal default constructor called by type: " << type << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = rhs;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->_type;
}

void WrongAnimal::setType(std::string type) {
	this->_type = type;
}