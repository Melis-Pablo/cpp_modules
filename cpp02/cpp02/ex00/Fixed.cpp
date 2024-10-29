#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
	// *this = src;
}

Fixed& Fixed::operator=(const Fixed &src) {
	std::cout << "Copy Assignation operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits( int const raw ) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}