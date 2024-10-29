#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
	_brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound() const {
	std::cout << "wuff wuff" << std::endl;
}

Dog::Dog(const Dog &rhs) : Animal("Dog") {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = rhs;
	this->_brain = new Brain(*rhs._brain);
}

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		*this = rhs;
	}
	std::cout << "Dog assignation operator called" << std::endl;
	return *this;
}