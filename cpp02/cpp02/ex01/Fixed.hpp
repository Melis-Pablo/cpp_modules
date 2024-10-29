#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // Allowed Functions: roundf

class Fixed {
	private:
		int					_value;
		static const int	_fractionalBits = 8;

	public:
		Fixed(); // Default constructor
		~Fixed(); // Destructor

		Fixed( const Fixed &src ); // Copy constructor
		Fixed &operator=( const Fixed &src ); // Assignation operator overload

		Fixed(const int val); // Int constructor
		Fixed(const float val); // Float constructor

		int getRawBits( void ) const; // Returns the raw value of the fixed point value
		void setRawBits( int const raw ); // Sets the raw value of the fixed point value

		float toFloat( void ) const; // Returns the floating point value
		int toInt( void ) const; // Returns the integer value
};

std::ostream &operator<<( std::ostream &o, Fixed const &i ); // Output operator overload

#endif