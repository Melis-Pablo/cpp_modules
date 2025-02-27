# Exercise 01: My Awesome PhoneBook

## Overview
This exercise introduces object-oriented programming in C++ through the creation of a simple phonebook application. You'll implement classes with attributes and methods, manage an array of objects, and handle user input/output operations.

## Core Concepts
- Classes and Objects
- Access Modifiers
- Member Functions
- Data Encapsulation
- Fixed-size Arrays
- User Input Handling
- Text Formatting

## Concepts Explained

### Classes and Objects
The fundamental building blocks of object-oriented programming in C++.

**Key Points:**
- Classes define a blueprint for objects
- Objects are instances of classes
- Separate interface (declaration) from implementation
- Class definitions typically go in header (.hpp) files
- Implementation goes in source (.cpp) files

**Example:**
```cpp
// In Contact.hpp
class Contact {
private:
    std::string name;

public:
    Contact();
    void setName(std::string new_name);
    std::string getName() const;
};

// In Contact.cpp
Contact::Contact() {
    // Constructor implementation
}
```

[Documentation Link](http://www.cplusplus.com/doc/tutorial/classes/)

### Access Modifiers
Control the visibility and accessibility of class members.

**Key Points:**
- `private`: Accessible only within the class
- `public`: Accessible from anywhere
- `protected`: Accessible within class and derived classes
- Keep data members private (encapsulation)
- Expose functionality through public methods

**Example:**
```cpp
class PhoneBook {
private:
    // Internal data not accessible outside
    Contact contacts[8];
    int count;

public:
    // Interface exposed to users of the class
    void addContact(const Contact& contact);
    void searchContact() const;
};
```

### Member Functions
Functions that are part of a class and operate on its data.

**Key Points:**
- Can access private members of their class
- Can be defined inside or outside the class
- When defined outside, use the scope resolution operator `::`
- Can be declared `const` if they don't modify the object

**Example:**
```cpp
// Declaration in header
class Contact {
public:
    void display() const;
};

// Definition in implementation file
void Contact::display() const {
    std::cout << "Name: " << name << std::endl;
}
```

### Data Encapsulation
Hiding the internal state of objects and controlling access through methods.

**Key Points:**
- Keep data members `private`
- Provide public getter/setter methods as needed
- Allows validation of inputs
- Enables changing internal implementation without affecting users

**Example:**
```cpp
class Contact {
private:
    std::string phoneNumber;

public:
    void setPhoneNumber(std::string num) {
        // Validate phone number format
        phoneNumber = num;
    }

    std::string getPhoneNumber() const {
        return phoneNumber;
    }
};
```

### Fixed-size Arrays
Using arrays to store multiple objects of the same type.

**Key Points:**
- Arrays have a fixed size determined at compile time
- Elements are accessed via index: `array[index]`
- No bounds checking is performed automatically
- Can store primitive types or objects

**Example:**
```cpp
class PhoneBook {
private:
    Contact contacts[8]; // Array of 8 Contact objects
    int contactCount;
};
```

### String Input/Output
Reading from and writing to the console in C++.

**Key Points:**
- Use `std::cin` for input, `std::cout` for output
- Extract input with `>>` operator
- For line input, use `std::getline()`
- Check for input failures

**Example:**
```cpp
std::string name;
std::cout << "Enter name: ";
std::getline(std::cin, name);
```

[Documentation Link](http://www.cplusplus.com/reference/string/string/getline/)

### Text Formatting
Controlling the appearance of output text.

**Key Points:**
- Use `<iomanip>` header for formatting options
- `std::setw(n)` sets the width of the next output field
- `std::setfill(c)` sets the fill character
- `std::right` / `std::left` for alignment

**Example:**
```cpp
#include <iomanip>
#include <iostream>

std::cout << std::setw(10) << std::right << "Name";
```

[Documentation Link](http://www.cplusplus.com/reference/iomanip/)

## Implementation Notes
- Design your classes before implementation
- Make Contact class store individual contact data
- Make PhoneBook class contain the array of contacts
- Handle the 8-contact limit by replacing oldest
- Truncate long strings with a dot for display
- Validate user input to prevent empty fields
- Ensure proper text alignment in columns

## Related Topics
- Constructors and destructors
- String manipulation methods
- Input validation techniques
- Command parsing