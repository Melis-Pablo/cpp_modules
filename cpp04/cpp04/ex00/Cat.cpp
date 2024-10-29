#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow meow" << std::endl;
}

Cat::Cat(const Cat &rhs) : Animal("Cat") {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = rhs;
}

Cat &Cat::operator=(const Cat &rhs) {
	if (this != &rhs) {
		*this = rhs;
	}
	std::cout << "Cat assignation operator called" << std::endl;
	return *this;
}