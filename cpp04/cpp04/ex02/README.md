# Exercise 02: Abstract class

## Overview
This exercise introduces abstract classes in C++. You'll modify the Animal class to prevent instantiation, turning it into an abstract base class that can only be used as a template for derived classes, while maintaining the existing polymorphic behavior.

## Core Concepts
- Abstract Classes
- Pure Virtual Functions
- Interface Design
- Class Hierarchies
- Contract Enforcement

## Concepts Explained

### Abstract Classes
Classes that cannot be instantiated directly and serve as templates for derived classes.

**Key Points:**
- Cannot create objects of an abstract class
- Must be inherited to be useful
- Acts as a blueprint for derived classes
- Enforces a common interface for all derived types
- May contain a mix of implemented and pure virtual functions

**Example:**
```cpp
// Abstract class example
class AbstractAnimal {
public:
    virtual ~AbstractAnimal() {}
    virtual void makeSound() const = 0; // Pure virtual function
    virtual void eat() const { // Regular virtual function with implementation
        std::cout << "The animal eats" << std::endl;
    }
};

// Cannot create an instance directly
// AbstractAnimal a; // Error!

// Must use it through derived classes
class Dog : public AbstractAnimal {
public:
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};
```

[Documentation Link](http://www.cplusplus.com/doc/tutorial/polymorphism/)

### Pure Virtual Functions
Virtual functions that have no implementation in the base class and must be overridden in derived classes.

**Key Points:**
- Declared with `= 0` at the end of the function declaration
- Makes the class abstract if at least one such function exists
- Derived classes must implement all pure virtual functions to be instantiable
- Defines the interface that derived classes must conform to
- Can still have a separate implementation in the base class (rarely used)

**Example:**
```cpp
class Animal {
public:
    // Pure virtual function
    virtual void makeSound() const = 0;

    // Regular virtual function
    virtual void move() const {
        std::cout << "The animal moves" << std::endl;
    }
};
```

### Abstract vs. Concrete Classes
Understanding the distinction between classes that can and cannot be instantiated.

**Key Points:**
- Abstract classes have at least one pure virtual function
- Concrete classes implement all pure virtual functions from their base classes
- Abstract classes define interfaces or partial implementations
- Concrete classes provide complete implementations
- Class hierarchies often have abstract base classes and concrete leaf classes

**Example:**
```cpp
// Abstract base class
class AAnimal {
public:
    virtual void makeSound() const = 0; // Makes the class abstract
};

// Concrete derived class
class Dog : public AAnimal {
public:
    // Must implement the pure virtual function
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

// Now valid:
Dog dog;            // Can instantiate concrete class
AAnimal* a = &dog;  // Can refer to it via abstract base pointer
a->makeSound();     // Calls Dog's implementation
```

### Design by Contract
Using abstract classes to establish guarantees about class behavior.

**Key Points:**
- Abstract classes define a contract for derived classes
- Pure virtual functions specify what derived classes must implement
- Regular virtual functions provide default behaviors that can be overridden
- Non-virtual functions impose behavior that can't be changed
- Establishes expectations for both implementers and users of a class

**Example:**
```cpp
class Animal {
public:
    // Contract: All animals must make sound (pure virtual)
    virtual void makeSound() const = 0;

    // Contract: All animals eat this way by default (can override)
    virtual void eat() const {
        std::cout << "Animal eats food" << std::endl;
    }

    // Contract: All animals do this exactly (can't override)
    void breathe() const {
        std::cout << "Animal breathes" << std::endl;
    }
};
```

### Class Naming Conventions
Common patterns for naming abstract and concrete classes.

**Key Points:**
- Abstract classes often prefixed with 'A' or 'Abstract'
- Interface classes (pure abstract) often prefixed with 'I'
- Base classes might have no prefix while derived classes have descriptive names
- Names should clearly communicate the class purpose and abstraction level
- Consistent naming helps understanding of class hierarchies

**Example:**
```cpp
class AAnimal { /* ... */ };     // Abstract animal base class
class Dog : public AAnimal { /* ... */ }; // Concrete dog implementation
class Cat : public AAnimal { /* ... */ }; // Concrete cat implementation
```

## Implementation Notes
- Modify the Animal class to make it abstract by adding at least one pure virtual function
- The makeSound() method is a good candidate to make pure virtual
- Consider renaming the class to AAnimal to follow naming conventions for abstract classes
- Ensure derived classes (Dog and Cat) implement all pure virtual functions
- Verify that attempting to create an Animal object directly causes a compilation error
- Update your tests to ensure all functionality still works through base class pointers
- Keep the deep copy implementation from the previous exercise
- Make sure the Brain management in the derived classes still works correctly
- Confirm that polymorphism still works with the abstract base class

## Related Topics
- Interface classes (pure abstract classes)
- Multiple inheritance
- Template method pattern
- Liskov substitution principle
- Dependency inversion principle