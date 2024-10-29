#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	// std::cout << "Float constructor called" << std::endl;
}

Point::Point(const Point &src) : _x(src.getX()), _y(src.getY()) {
	// std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &src) {
	// std::cout << "Copy Assignation operator called" << std::endl;
	if (this != &src) {
		(Fixed)this->_x = src.getX();
		(Fixed)this->_y = src.getY();
	}
	return *this;
}

Point::~Point() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed const &Point::getX() const {
	return this->_x;
}

Fixed const &Point::getY() const {
	return this->_y;
}