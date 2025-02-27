# Exercise 03: Interface & recap

## Overview
This exercise introduces interfaces in C++ through pure abstract classes. You'll implement a fantasy game-like structure with characters and materials, using interface classes to define the contracts that concrete classes must follow. This will reinforce polymorphism, memory management, and abstract class concepts.

## Core Concepts
- Interfaces
- Pure Abstract Classes
- Factory Pattern
- Inventory Management
- Component Design

## Concepts Explained

### Interfaces in C++
Using pure abstract classes to define contracts for implementing classes.

**Key Points:**
- C++ has no explicit interface keyword unlike some languages
- Interfaces are implemented as classes with only pure virtual functions
- Often prefixed with 'I' to indicate their purpose
- Define what derived classes must implement, not how
- Enable programming to an interface, not an implementation

**Example:**
```cpp
// Interface (pure abstract class)
class ICharacter {
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

// Concrete implementation
class Character : public ICharacter {
    // Must implement all methods from the interface
};
```

[Documentation Link](http://www.cplusplus.com/doc/tutorial/polymorphism/)

### Abstract Factory Pattern
A creational design pattern that provides an interface for creating families of related objects.

**Key Points:**
- Creates objects without specifying their concrete classes
- Uses factory methods to create objects
- Concrete factories implement the abstract factory interface
- Clients work with factories and products through abstract interfaces
- Enables swapping entire families of products

**Example:**
```cpp
// Abstract product
class AMateria {
public:
    virtual AMateria* clone() const = 0;
};

// Concrete products
class Ice : public AMateria {
public:
    AMateria* clone() const override {
        return new Ice(*this);
    }
};

// Abstract factory
class IMateriaSource {
public:
    virtual AMateria* createMateria(std::string const & type) = 0;
};

// Concrete factory
class MateriaSource : public IMateriaSource {
public:
    AMateria* createMateria(std::string const & type) override {
        // Create and return the appropriate materia
    }
};
```

### Inventory System Design
Implementing a system to manage collections of objects.

**Key Points:**
- Fixed-size array represents the inventory slots
- Add, remove, and use operations modify the inventory state
- Responsibility for memory management must be clearly defined
- Must handle edge cases (full inventory, invalid indexes)
- Pointer ownership must be carefully tracked

**Example:**
```cpp
class Character : public ICharacter {
private:
    AMateria* inventory[4];
    std::string name;

public:
    void equip(AMateria* m) override {
        // Find first empty slot and store the materia
        for (int i = 0; i < 4; i++) {
            if (inventory[i] == nullptr) {
                inventory[i] = m;
                break;
            }
        }
    }

    void unequip(int idx) override {
        // Remove materia without deleting it
        if (idx >= 0 && idx < 4) {
            inventory[idx] = nullptr;
        }
    }
};
```

### Deep Copy with Polymorphic Objects
Creating independent copies of objects in polymorphic hierarchies.

**Key Points:**
- Must handle copying of derived class objects correctly
- Typically uses virtual clone methods to create proper type
- Each class is responsible for correctly copying its own state
- Must maintain proper ownership semantics
- Prevents unexpected behavior due to shared resources

**Example:**
```cpp
// Base class with virtual clone
class AMateria {
public:
    virtual AMateria* clone() const = 0;
};

// Derived class implementation
class Ice : public AMateria {
public:
    AMateria* clone() const override {
        return new Ice(*this); // Creates new Ice object
    }
};

// Using the clone method for deep copy
Character::Character(const Character& other) {
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i]) {
            this->inventory[i] = other.inventory[i]->clone();
        } else {
            this->inventory[i] = nullptr;
        }
    }
}
```

### Memory Management in Component Systems
Handling memory allocation and deallocation in systems with many interconnected objects.

**Key Points:**
- Clear ownership rules prevent memory leaks and double-free errors
- Consider who creates, who owns, and who destroys objects
- Unequipped items may need separate tracking to avoid leaks
- Destructors must clean up all allocated memory
- Copying must respect memory ownership semantics

**Example:**
```cpp
// Proper cleanup in destructor
Character::~Character() {
    // Clean up all materias in inventory
    for (int i = 0; i < 4; i++) {
        delete inventory[i];
    }
}

// Proper deep copy handling
Character& Character::operator=(const Character& other) {
    if (this != &other) {
        // Clean up current inventory
        for (int i = 0; i < 4; i++) {
            delete inventory[i];
            inventory[i] = nullptr;
        }

        // Copy from other
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i]) {
                inventory[i] = other.inventory[i]->clone();
            }
        }
        name = other.name;
    }
    return *this;
}
```

## Implementation Notes
- Implement the AMateria abstract class with the specified interface
- Create concrete Ice and Cure classes that inherit from AMateria
- Implement the ICharacter interface and a concrete Character class
- Create the IMateriaSource interface and a concrete MateriaSource class
- Handle inventory slots carefully (max 4 materias per character)
- Implement deep copy for Character class
- Manage memory properly, especially for unequipped materias
- Track materias left on the floor to avoid memory leaks
- Ensure all memory is properly freed in destructors
- Implement all required constructors, assignment operators, and destructors
- Test your implementation thoroughly with the provided main function and additional tests

## Related Topics
- Component-based design
- Game object systems
- Resource management
- Dependency injection
- Strategy pattern