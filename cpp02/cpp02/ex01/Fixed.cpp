#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) : _value(val << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val) : _value(::roundf(val * (1 << _fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	// this->setRawBits(src.getRawBits());
	*this = src;
}

Fixed& Fixed::operator=(const Fixed &src) {
	std::cout << "Copy Assignation operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits( int const raw ) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat( void ) const {
	return static_cast<float>(this->getRawBits()) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const {
	return this->_value >> _fractionalBits;
}

std::ostream &operator<<( std::ostream &o, Fixed const &i ) {
	o << i.toFloat();
	return o;
}