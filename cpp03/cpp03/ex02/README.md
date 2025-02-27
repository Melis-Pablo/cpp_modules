# Exercise 02: Repetitive work

## Overview
This exercise extends our inheritance hierarchy by creating another derived class called FragTrap. You'll implement a second descendant of ClapTrap, reinforcing inheritance concepts and creating a family of related but distinct robot types.

## Core Concepts
- Class Hierarchies
- Parallel Inheritance
- Code Reusability
- Specialized Class Behaviors
- Inheritance Design Patterns

## Concepts Explained

### Class Hierarchies
Creating structured relationships between multiple related classes.

**Key Points:**
- Multiple classes can inherit from the same base class
- Forms a tree-like structure of class relationships
- Base class provides common functionality
- Derived classes specialize behavior
- Promotes code organization and reuse

**Example:**
```cpp
// Base class
class ClapTrap {
    // Common functionality
};

// Two different derived classes
class ScavTrap : public ClapTrap {
    // ScavTrap specifics
};

class FragTrap : public ClapTrap {
    // FragTrap specifics
};
```

### Parallel Inheritance
Creating multiple derived classes that share the same base.

**Key Points:**
- "Sibling" classes have similar structure
- Each derived class can have unique attributes and methods
- Derived classes adapt base functionality differently
- Common pattern for creating families of related types
- Allows for specialized behaviors in a consistent framework

**Example:**
```cpp
// Three parallel types:
class ClapTrap { /* ... */ };
class ScavTrap : public ClapTrap { /* ... */ };
class FragTrap : public ClapTrap { /* ... */ };
```

### Code Reuse Through Inheritance
Leveraging inheritance to avoid duplicating code.

**Key Points:**
- Common functionality defined once in base class
- Derived classes automatically inherit common code
- Updates to base class propagate to all derived classes
- Only differences need to be implemented in derived classes
- Reduces maintenance burden

**Example:**
```cpp
// Base class implements core behavior
void ClapTrap::takeDamage(unsigned int amount) {
    if (amount >= hitPoints) {
        hitPoints = 0;
    } else {
        hitPoints -= amount;
    }
    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage!" << std::endl;
}

// Derived classes inherit this implementation
// No need to redefine unless behavior differs
```

### Constructor Parameter Forwarding
Passing constructor parameters from derived class to base class.

**Key Points:**
- Base class constructor parameters are provided in derived class initializer list
- Allows configuring base class part from derived constructor
- Common pattern for inheritance hierarchies
- Simplifies object initialization
- Avoids duplicating parameter handling code

**Example:**
```cpp
// Base constructor
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10),
                                      energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap constructor called" << std::endl;
}

// Derived constructor forwarding parameter
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}
```

### Class-Specific Special Abilities
Differentiating derived classes with unique functionalities.

**Key Points:**
- Each derived class can have its own unique methods
- Special abilities give each class distinct character
- Creates meaningful differences between class types
- Often represents the reason for having different classes
- Allows for specialized behaviors within a common framework

**Example:**
```cpp
// ScavTrap special ability
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}

// FragTrap special ability
void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}
```

## Implementation Notes
- Create a new FragTrap class that inherits from ClapTrap
- Initialize FragTrap attributes to 100 hit points, 100 energy points, 30 attack damage
- Implement constructors and destructor with unique messages
- Add the highFivesGuys() special ability method
- Ensure proper construction/destruction chaining
- Test both inherited functionality and specialized methods
- Create multiple instances of different robot types to demonstrate the class hierarchy
- The bulk of functionality should be inherited from ClapTrap
- Differentiate FragTrap from ScavTrap through messages and special abilities

## Related Topics
- Factory method pattern
- Type hierarchies
- Polymorphism (coming in later modules)
- Design patterns for game character systems
- Avoiding code duplication in inheritance