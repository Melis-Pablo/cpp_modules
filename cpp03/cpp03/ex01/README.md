# Exercise 01: Serena, my love!

## Overview
This exercise introduces inheritance in C++. You'll create a ScavTrap class that inherits from ClapTrap, demonstrating how derived classes can extend and override base class functionality while maintaining the core implementation.

## Core Concepts
- Inheritance
- Constructor/Destructor Chaining
- Method Overriding
- Derived Class Attributes
- Specialized Functionality

## Concepts Explained

### Inheritance in C++
Creating a class that inherits attributes and behaviors from another class.

**Key Points:**
- Use `: public BaseClass` syntax to inherit
- Derived class inherits all members (respecting access modifiers)
- Derived class can override inherited methods
- Derived class can add new methods and attributes
- Inheritance creates an "is-a" relationship

**Example:**
```cpp
// Base class
class ClapTrap {
    // ClapTrap implementation
};

// Derived class
class ScavTrap : public ClapTrap {
    // ScavTrap implementation
};
```

[Documentation Link](http://www.cplusplus.com/doc/tutorial/inheritance/)

### Constructor and Destructor Chaining
How constructors and destructors are called in inheritance hierarchies.

**Key Points:**
- Base class constructor is called before derived class constructor
- Derived class destructor is called before base class destructor
- Chaining follows object construction/destruction logic
- Parent parts are built before child parts
- Child parts are destroyed before parent parts

**Example:**
```cpp
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    // Base class constructor is called first
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << name << std::endl;
    // Base class destructor will be called automatically after this
}
```

### Method Overriding
Replacing inherited method implementations with class-specific versions.

**Key Points:**
- Use same method signature as in base class
- No special keyword needed in C++98 (unlike `override` in C++11)
- Calls to the method will use the most derived version
- Can still access base implementation using scope resolution operator
- Overridden methods should maintain the expected behavior pattern

**Example:**
```cpp
// Base class version
void ClapTrap::attack(const std::string& target) {
    std::cout << "ClapTrap " << name << " attacks " << target << std::endl;
}

// Derived class override
void ScavTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "ScavTrap " << name << " savagely attacks " << target
                  << ", causing " << attackDamage << " points of damage!"
                  << std::endl;
        energyPoints--;
    } else {
        std::cout << "ScavTrap " << name << " can't attack! No energy or hit points left."
                  << std::endl;
    }
}
```

### Attribute Initialization in Derived Classes
Setting up derived class-specific attribute values.

**Key Points:**
- Initial values can be set in the constructor
- Base class constructor is called first
- Derived class constructor can then modify inherited attributes
- Attribute access depends on access specifiers in base class
- Consider making attributes protected in base class for derived access

**Example:**
```cpp
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    // Initialize ScavTrap-specific attribute values
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}
```

### Special Class Capabilities
Adding unique functionality to derived classes.

**Key Points:**
- Derived classes can have unique methods
- Special abilities differentiate derived types
- Pattern creates variety while maintaining common base
- New methods are only available for the specific class type
- Promotes class specialization

**Example:**
```cpp
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
```

## Implementation Notes
- Inherit ScavTrap from ClapTrap using `class ScavTrap : public ClapTrap`
- Initialize ScavTrap with specified values (100 hit points, 50 energy, 20 attack damage)
- Override the attack() method with ScavTrap-specific messages
- Implement the guardGate() special capacity
- Add appropriate constructor and destructor messages
- Demonstrate proper construction/destruction chaining in your tests
- Ensure ScavTrap both inherits base ClapTrap functionality and has its own identity
- Test both inherited methods and unique methods
- Verify resource management still functions correctly

## Related Topics
- Access specifiers in inheritance
- Inheritance hierarchies
- Base class pointer to derived objects
- Virtual functions (preview for later modules)
- Object slicing