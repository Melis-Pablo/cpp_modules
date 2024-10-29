#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}

Dog::Dog(const Dog &rhs) : Animal("Dog") {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = rhs;
}

Dog &Dog::operator=(const Dog &rhs) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &rhs)
		*this = rhs;
	return *this;
}