#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	// Tests for min and max functions
    Fixed c(3);
    Fixed d(4);

    std::cout << "Testing min and max functions:" << std::endl;
    std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
    std::cout << "min(const c, const d): " << Fixed::min(static_cast<const Fixed&>(c), static_cast<const Fixed&>(d)) << std::endl;
    std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;
    std::cout << "max(const c, const d): " << Fixed::max(static_cast<const Fixed&>(c), static_cast<const Fixed&>(d)) << std::endl;

	return 0;
}

/*
Expected output:
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
Testing min and max functions:
min(c, d): 3
min(const c, const d): 3
max(c, d): 4
max(const c, const d): 4
$>
*/