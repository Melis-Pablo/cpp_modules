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
		Fixed(const int val); // Int constructor
		Fixed(const float val); // Float constructor
		Fixed( const Fixed &src ); // Copy constructor
		Fixed &operator=( const Fixed &src ); // Assignation operator overload
		~Fixed(); // Destructor

		int getRawBits( void ) const; // Returns the raw value of the fixed point value
		void setRawBits( int const raw ); // Sets the raw value of the fixed point value

		float toFloat( void ) const; // Returns the floating point value
		int toInt( void ) const; // Returns the integer value

		// Comparison operators
		bool operator>(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;
		// arithmetic operators
		Fixed operator+(const Fixed &rhs) const;
		Fixed operator-(const Fixed &rhs) const;
		Fixed operator*(const Fixed &rhs) const;
		Fixed operator/(const Fixed &rhs) const;
		// increment and decrement operators
		Fixed &operator++(); // pre-increment
		Fixed operator++(int); // post-increment
		Fixed &operator--(); // pre-decrement
		Fixed operator--(int); // post-decrement
		// min and max functions
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<( std::ostream &o, Fixed const &i ); // Output operator overload


#endif