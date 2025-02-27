# Exercise 00: Polymorphism

## Overview
This exercise introduces polymorphism in C++. You'll implement a hierarchy of animal classes that demonstrates how virtual functions enable derived classes to provide their own implementations of methods defined in the base class.

## Core Concepts
- Polymorphism
- Virtual Functions
- Method Overriding
- Base and Derived Classes
- Runtime Type Determination

## Concepts Explained

### Polymorphism
The ability of different objects to respond to the same function call in ways specific to their actual types.

**Key Points:**
- Allows objects of different classes to be treated through a common interface
- Enables code that works with the base class to operate on derived classes
- Fundamental to object-oriented programming
- Runtime (dynamic) polymorphism in C++ is implemented through virtual functions
- Requires inheritance relationships between classes

**Example:**
```cpp
// Base class reference/pointer can refer to derived class objects
Animal* animalPtr = new Dog();  // A Dog in Animal's clothing
animalPtr->makeSound();        // Will call Dog's implementation
```

[Documentation Link](http://www.cplusplus.com/doc/tutorial/polymorphism/)

### Virtual Functions
Functions that can be overridden in derived classes and are resolved at runtime.

**Key Points:**
- Declared with `virtual` keyword in the base class
- Allow derived classes to provide their own implementations
- Function calls are resolved based on the actual object type at runtime
- Enable polymorphic behavior through base class pointers/references
- Slight runtime overhead compared to non-virtual functions

**Example:**
```cpp
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "..." << std::endl;
    }
};

class Dog : public Animal {
public:
    // Override the base class function
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};
```

### Method Overriding
Providing a different implementation in a derived class for a method already defined in the base class.

**Key Points:**
- Method signature must be identical to the base class method
- `override` keyword (C++11) helps catch errors but is not required in C++98
- Overridden method is called when invoked through base class pointer/reference
- Not to be confused with method overloading (different parameters)
- Forms the basis for polymorphic behavior

**Example:**
```cpp
// Base class
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Some generic sound" << std::endl;
    }
};

// Derived class
class Cat : public Animal {
public:
    // This overrides the base class method
    void makeSound() const {
        std::cout << "Meow!" << std::endl;
    }
};
```

### Virtual Destructors
Destructors that ensure proper cleanup of derived class resources when deleting through a base class pointer.

**Key Points:**
- Essential when deleting derived objects through base class pointers
- Without virtual destructors, derived class destructors won't be called
- Can cause memory leaks and undefined behavior if missing
- Incurs a small overhead (vtable pointer)
- Should be included in any class designed for inheritance

**Example:**
```cpp
class Animal {
public:
    // Virtual destructor ensures proper cleanup
    virtual ~Animal() {
        std::cout << "Animal destructor called" << std::endl;
    }
};

class Dog : public Animal {
public:
    ~Dog() {
        std::cout << "Dog destructor called" << std::endl;
    }
};

// With virtual destructor, both destructors will be called
Animal* pet = new Dog();
delete pet; // Calls both Dog and Animal destructors
```

### Non-Polymorphic Classes
Classes designed without virtual functions, demonstrating the difference in behavior.

**Key Points:**
- Methods are resolved at compile time, not runtime
- Derived class methods won't be called through base class pointers
- More efficient (no vtable lookup) but less flexible
- Used to demonstrate the necessity of virtual functions
- Common source of bugs when polymorphism is intended but not implemented

**Example:**
```cpp
class WrongAnimal {
public:
    // Not virtual - will always call this version regardless of actual type
    void makeSound() const {
        std::cout << "Wrong animal sound" << std::endl;
    }
};

class WrongCat : public WrongAnimal {
public:
    // This doesn't override, it hides the base class version
    void makeSound() const {
        std::cout << "Wrong meow!" << std::endl;
    }
};

// Will call WrongAnimal's makeSound, not WrongCat's
WrongAnimal* wrongPet = new WrongCat();
wrongPet->makeSound(); // Outputs "Wrong animal sound"
```

## Implementation Notes
- Create an Animal base class with a protected string attribute for type
- Implement Dog and Cat classes that inherit from Animal
- Make the makeSound() method virtual in the Animal class
- Override makeSound() in both Dog and Cat with appropriate sounds
- Include a virtual destructor in the Animal class
- Also implement WrongAnimal and WrongCat without virtual functions
- Create a getType() method to return the animal's type
- Use const correctness for methods that don't modify the object
- Test with pointers to base class containing derived class objects
- Verify that proper sounds are produced based on actual object types
- Compare behavior between the virtual and non-virtual implementations

## Related Topics
- Pure virtual functions
- Abstract classes
- Virtual tables (vtables)
- Runtime type identification (RTTI)
- Object slicing