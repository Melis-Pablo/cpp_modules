#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = rhs;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &rhs) {
		*this = rhs;
	}
	return *this;
}