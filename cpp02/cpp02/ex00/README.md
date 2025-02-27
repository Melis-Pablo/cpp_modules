# Exercise 00: My First Class in Orthodox Canonical Form

## Overview
This exercise introduces the Orthodox Canonical Form for C++ classes and fixed-point numbers. You'll implement a basic fixed-point number class with the four essential orthodox canonical methods and simple value management.

## Core Concepts
- Orthodox Canonical Form
- Fixed-Point Numbers
- Class Declaration and Implementation
- Access Modifiers
- Static Class Members
- Header and Implementation Files

## Concepts Explained

### Orthodox Canonical Form
A C++ class design pattern that provides consistent object creation, copying, assignment, and destruction.

**Key Points:**
- Includes four essential member functions: default constructor, copy constructor, copy assignment operator, and destructor
- Ensures proper resource management and class invariants
- Prevents memory leaks and undefined behavior
- Standard practice for well-designed C++ classes

**Example:**
```cpp
class CanonicalClass {
public:
    // Default constructor
    CanonicalClass();

    // Copy constructor
    CanonicalClass(const CanonicalClass& other);

    // Copy assignment operator
    CanonicalClass& operator=(const CanonicalClass& other);

    // Destructor
    ~CanonicalClass();
};
```

### Fixed-Point Numbers
Numeric representation that uses a fixed number of bits for the integer part and a fixed number of bits for the fractional part.

**Key Points:**
- Balance between performance and precision
- Fixed number of fractional bits (8 bits in this exercise)
- Internal representation typically uses an integer type
- Used in graphics, audio processing, and embedded systems
- Alternative to floating-point when exact representation is needed

**Example:**
```cpp
// For a fixed-point number with 8 fractional bits:
// The value 1.5 would be stored as 1.5 * 2^8 = 1.5 * 256 = 384
// The binary representation would be 0000000110000000
```

### Static Class Members
Variables or functions that belong to the class rather than any specific instance.

**Key Points:**
- Declared with the `static` keyword inside the class
- Only one copy exists regardless of how many objects are created
- Static constants don't change for any instance of the class
- Typically used for shared class properties or configuration
- Often defined outside the class declaration

**Example:**
```cpp
class Fixed {
private:
    static const int fractionalBits = 8;
    // ...
};
```

### Class Implementation Separation
Splitting class code into declaration (header) and implementation (source) files.

**Key Points:**
- Header (.hpp) contains class declaration, constants, and inline functions
- Implementation (.cpp) contains method definitions
- Improves compilation speed and code organization
- Requires proper include guards to prevent double inclusion
- Allows clients to use class without seeing implementation details

**Example:**
```cpp
// Fixed.hpp
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
    // Class declaration
};

#endif

// Fixed.cpp
#include "Fixed.hpp"

// Method implementations
```

## Implementation Notes
- Implement all four canonical methods with appropriate messaging
- Use appropriate access modifiers (private/public) for members
- Store the fixed-point value as an integer
- Use a static constant integer to store the number of fractional bits (8)
- Implement getRawBits() and setRawBits() for value access
- Make sure your copy operations properly copy the fixed-point value
- Add appropriate output messages to track when functions are called
- Use proper include guards in your header file

## Related Topics
- Rule of Three (C++98) / Rule of Five (C++11)
- Binary representation of numbers
- Bitwise operations
- Memory management in C++
- Const correctness