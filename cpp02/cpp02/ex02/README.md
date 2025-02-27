# Exercise 02: Now we're talking

## Overview
This exercise extends the Fixed-point number class with comprehensive operator overloading and utility functions. You'll implement comparison operators, arithmetic operators, increment/decrement operators, and static min/max functions.

## Core Concepts
- Operator Overloading
- Comparison Operators
- Arithmetic Operators
- Increment/Decrement Operators
- Static Member Functions
- Const Correctness

## Concepts Explained

### Comparison Operators
Operators that determine the relationship between objects.

**Key Points:**
- Implement all six: >, <, >=, <=, ==, !=
- Return boolean value indicating comparison result
- Often implemented using existing conversion methods
- Should be consistent (if a > b then b < a)
- Usually const functions that don't modify objects

**Example:**
```cpp
bool Fixed::operator>(const Fixed& other) const {
    return this->toFloat() > other.toFloat();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->getRawBits() == other.getRawBits();
}
```

### Arithmetic Operators
Operators that perform mathematical operations on objects.

**Key Points:**
- Implement addition, subtraction, multiplication, division (+, -, *, /)
- Return a new object with the operation result
- Ensure proper fixed-point arithmetic
- Watch for potential overflow and division by zero
- Typically don't modify the original objects

**Example:**
```cpp
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    // For fixed-point multiplication, need to account for fractional bits
    return Fixed(this->toFloat() * other.toFloat());
}
```

### Increment/Decrement Operators
Operators that change an object's value by the smallest possible increment.

**Key Points:**
- Implement pre- and post-increment (++x, x++)
- Implement pre- and post-decrement (--x, x--)
- Pre-increment returns reference to modified object
- Post-increment returns copy of original value
- Increment by the smallest representable value (epsilon)

**Example:**
```cpp
// Pre-increment
Fixed& Fixed::operator++() {
    this->value++;
    return *this;
}

// Post-increment
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}
```

### Static Member Functions
Functions that belong to the class rather than any specific instance.

**Key Points:**
- Called on the class itself, not on objects
- Can be overloaded (different parameter types)
- Don't have access to instance variables unless passed an object
- Useful for utility functions related to the class
- Can return references to objects for efficiency

**Example:**
```cpp
// For non-const objects
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

// For const objects
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}
```

### Const Correctness
Using const to indicate which operations modify objects and which don't.

**Key Points:**
- Parameter const: Function won't modify the parameter
- Return const: Returned value can't be modified
- Function const: Function won't modify the calling object
- Helps compiler optimize and catch errors
- Enables function overloading based on constness

**Example:**
```cpp
// Non-modifying function
bool operator<(const Fixed& other) const;

// Two versions of min function with different const qualifiers
static Fixed& min(Fixed& a, Fixed& b);
static const Fixed& min(const Fixed& a, const Fixed& b);
```

## Implementation Notes
- Implement all six comparison operators (>, <, >=, <=, ==, !=)
- Implement all four arithmetic operators (+, -, *, /)
- Implement all increment/decrement operators (pre/post ++/--)
- Implement static min/max functions for both const and non-const references
- Ensure epsilon is the smallest representable value
- Test thoroughly with various combinations of operations
- Handle edge cases like division by zero appropriately
- Be careful with fixed-point arithmetic in multiplication and division
- Maintain proper operator semantics (e.g., post-increment returns original value)

## Related Topics
- Operator precedence
- Function overloading
- Reference returns
- Copy elision and return value optimization
- Fixed-point arithmetic algorithms
- Epsilon values in numeric computation