#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					_value;
		static const int	_fractionalBits = 8;

	public:
		Fixed(); // Default constructor
		~Fixed(); // Destructor

		Fixed( const Fixed &src ); // Copy constructor
		Fixed &operator=( const Fixed &src ); // copy assignment operator overload

		int getRawBits( void ) const; // Returns the raw value of the fixed point value
		void setRawBits( int const raw ); // Sets the raw value of the fixed point value
};

#endif