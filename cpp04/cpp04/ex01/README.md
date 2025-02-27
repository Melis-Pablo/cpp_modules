# Exercise 01: I don't want to set the world on fire

## Overview
This exercise expands on polymorphism by adding object composition and memory management. You'll implement a Brain class that will be used by Dog and Cat classes, demonstrating deep copying and proper resource management in derived classes.

## Core Concepts
- Deep vs. Shallow Copying
- Object Composition
- Dynamic Memory Management
- Copy Constructors and Assignment
- Destructor Chains

## Concepts Explained

### Deep vs. Shallow Copying
Two different approaches to copying objects that contain pointers to other objects.

**Key Points:**
- Shallow copy: copies only the pointer values, resulting in two objects pointing to the same memory
- Deep copy: creates new copies of the pointed-to objects, resulting in completely independent objects
- Shallow copies lead to double-free errors and undefined behavior
- Deep copies are necessary when objects own resources
- Must be implemented manually for pointers

**Example:**
```cpp
// Shallow copy (problematic)
Dog shallowDog = originalDog; // Default copy just copies the Brain pointer
// Both dogs now point to the same Brain!

// Deep copy (correct)
Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other); // Copy the base part
        delete brain;            // Delete current brain
        brain = new Brain(*other.brain); // Create a new copy of the brain
    }
    return *this;
}
```

### Object Composition
Building complex objects by combining simpler ones.

**Key Points:**
- "Has-a" relationship (e.g., Dog has a Brain)
- Implemented using member variables that are objects or pointers to objects
- Allows for code reuse without inheritance
- Creates ownership relationships that must be managed
- Requires special attention in copy operations and destructors

**Example:**
```cpp
class Brain {
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain& other);
    ~Brain();
    // Methods to manage ideas
};

class Dog : public Animal {
private:
    Brain* brain; // Dog has-a Brain relationship
public:
    Dog();
    ~Dog();
    // Other methods
};
```

### Dynamic Memory Management
Allocating and deallocating memory at runtime.

**Key Points:**
- Use `new` to allocate memory and `delete` to free it
- Always pair `new` with `delete` to prevent memory leaks
- Handle memory allocation failures
- Ensure proper cleanup in all exit paths
- Use ownership semantics to determine who is responsible for deletion

**Example:**
```cpp
Dog::Dog() : Animal("Dog") {
    std::cout << "Dog constructor called" << std::endl;
    this->brain = new Brain(); // Dynamically allocate a Brain
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain; // Free the dynamically allocated Brain
}
```

### Copy Constructors and Assignment Operators
Special member functions that create copies of objects.

**Key Points:**
- Copy constructor: creates a new object as a copy of an existing one
- Copy assignment operator: replaces the contents of an existing object
- Both need to perform deep copies of owned resources
- Must handle self-assignment in the assignment operator
- Should maintain class invariants after operation

**Example:**
```cpp
// Copy constructor
Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain); // Deep copy
}

// Copy assignment operator
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other); // Handle base class part
        delete brain;             // Delete old brain
        brain = new Brain(*other.brain); // Create a new brain copy
    }
    return *this;
}
```

### Array of Polymorphic Objects
Creating and managing collections of objects with different concrete types.

**Key Points:**
- Uses base class pointers to store different derived types
- Enables uniform handling of heterogeneous objects
- Requires care when allocating and deallocating
- Must ensure proper virtual destruction
- Useful for grouping related but different objects

**Example:**
```cpp
// Creating an array of Animal pointers
Animal* animals[10];

// Fill with Dogs and Cats
for (int i = 0; i < 5; i++) {
    animals[i] = new Dog();
}
for (int i = 5; i < 10; i++) {
    animals[i] = new Cat();
}

// Using the animals polymorphically
for (int i = 0; i < 10; i++) {
    animals[i]->makeSound();
}

// Cleanup
for (int i = 0; i < 10; i++) {
    delete animals[i];
}
```

## Implementation Notes
- Implement the Brain class with an array of 100 strings for ideas
- Modify Dog and Cat to have a private Brain pointer
- Allocate a new Brain in the Dog and Cat constructors
- Delete the Brain in the Dog and Cat destructors
- Implement deep copying for Dog and Cat (copy constructor and assignment operator)
- Create an array of Animal pointers, half Dogs and half Cats
- Test that deleting through the Animal pointer calls the correct destructors
- Verify deep copying by modifying a copy and checking the original remains unchanged
- Check for memory leaks using appropriate tools (valgrind, leaks, etc.)
- Ensure all destructors print appropriate messages to track destruction order

## Related Topics
- Resource Acquisition Is Initialization (RAII)
- Smart pointers (not available in C++98)
- Move semantics (C++11)
- Rule of Three/Five
- Memory leak detection