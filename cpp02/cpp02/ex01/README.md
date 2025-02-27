# Exercise 01: Towards a more useful fixed-point number class

## Overview
This exercise expands the Fixed-point number class by adding constructors and conversion functions that allow working with integers and floating-point values. You'll also implement operator overloading for stream insertion.

## Core Concepts
- Type Conversion in Classes
- Operator Overloading
- Fixed-Point Number Conversion
- Bit Manipulation
- Stream Operators

## Concepts Explained

### Type Conversion in Classes
Creating constructors and methods that convert between different data types.

**Key Points:**
- Constructors can initialize objects from different types
- Conversion methods transform internal representation to other types
- Explicit type conversion prevents ambiguity
- Implement symmetric conversions (to and from each type)
- Maintain precision through careful bit manipulation

**Example:**
```cpp
class Fixed {
public:
    // Convert from int to fixed-point
    Fixed(const int value);

    // Convert from float to fixed-point
    Fixed(const float value);

    // Convert from fixed-point to int
    int toInt(void) const;

    // Convert from fixed-point to float
    float toFloat(void) const;
};
```

### Integer to Fixed-Point Conversion
Converting integer values to fixed-point representation.

**Key Points:**
- Shift the integer value left by the number of fractional bits
- Simple bit-shifting operation (value << fractionalBits)
- No precision loss since integers have no fractional part
- Integer range is reduced by the number of fractional bits
- Creates fixed-point representation with all fractional bits set to 0

**Example:**
```cpp
Fixed::Fixed(const int value) {
    // For 8 fractional bits, shift left by 8
    this->value = value << fractionalBits;
}
```

### Float to Fixed-Point Conversion
Converting floating-point values to fixed-point representation.

**Key Points:**
- Multiply floating-point value by 2^(fractional bits)
- Can use bit shifting or direct multiplication
- Precision loss can occur due to rounding
- May need to handle edge cases like overflows
- Creates fixed-point representation with accurate fractional bits

**Example:**
```cpp
Fixed::Fixed(const float value) {
    // For 8 fractional bits, multiply by 256 (2^8)
    this->value = roundf(value * (1 << fractionalBits));
}
```

### Fixed-Point to Integer/Float Conversion
Converting fixed-point representation back to standard types.

**Key Points:**
- For integer: Shift right by the number of fractional bits
- For float: Divide by 2^(fractional bits)
- Integer conversion discards fractional part (truncation)
- Float conversion preserves fractional precision
- Symmetric with the corresponding constructor conversions

**Example:**
```cpp
int Fixed::toInt(void) const {
    // Shift right to remove fractional bits
    return this->value >> fractionalBits;
}

float Fixed::toFloat(void) const {
    // Divide by 2^8 to get the floating-point value
    return (float)this->value / (1 << fractionalBits);
}
```

### Stream Insertion Operator Overloading
Defining how objects are output to streams like std::cout.

**Key Points:**
- Overloaded as a non-member function
- Takes stream and object as parameters
- Returns reference to stream for chaining
- Determines how the object appears when output
- Commonly uses an object's conversion methods

**Example:**
```cpp
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    // Output the floating-point representation
    os << fixed.toFloat();
    return os;
}
```

## Implementation Notes
- Add constructors for int and float conversion
- Implement toInt() and toFloat() conversion methods
- Overload the insertion (<<) operator for output streaming
- Use bit operations for efficient conversion
- Pay attention to precision and potential overflow
- Use the provided main function to test your implementation
- Ensure all constructor and operator calls print appropriate messages
- Make sure your conversions work correctly for edge cases

## Related Topics
- Floating-point representation in computers
- Binary arithmetic and bit manipulation
- Rounding methods for numeric conversion
- Precision loss in numeric representations
- Friend functions in C++