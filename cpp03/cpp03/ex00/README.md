# Exercise 00: Aaaaand... OPEN!

## Overview
This exercise introduces object-oriented programming concepts through the creation of a ClapTrap robot class. You'll implement a character with various attributes and actions, laying the groundwork for inheritance in later exercises.

## Core Concepts
- Class Definition
- Member Functions
- Object State Management
- Resource Tracking
- Action Implementation
- Object Lifecycle Messages

## Concepts Explained

### Class Implementation
Creating a complete class with attributes and behaviors.

**Key Points:**
- Private attributes store the object's state
- Public methods expose controlled functionality
- Constructor initializes object with proper values
- Destructor cleans up resources when object is destroyed
- Orthodox Canonical Form ensures proper resource management

**Example:**
```cpp
class ClapTrap {
private:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    // Action methods
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
```

### Resource Management
Tracking and controlling limited resources within a class.

**Key Points:**
- Resources (hit points, energy points) have initial values
- Actions consume resources (attacking/repairing costs energy)
- Actions are conditional on having sufficient resources
- Resources can be lost (taking damage) or gained (repairs)
- Actions should check resource availability before executing

**Example:**
```cpp
void ClapTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!"
                  << std::endl;
        energyPoints--;
    } else {
        std::cout << "ClapTrap " << name << " can't attack! No energy or hit points left."
                  << std::endl;
    }
}
```

### State Validation
Ensuring object actions respect the current state of the object.

**Key Points:**
- Check for sufficient resources before performing actions
- Prevent actions when the object is in an invalid state
- Update state appropriately after actions
- Provide informative messages about state changes
- Maintain object invariants throughout its lifecycle

**Example:**
```cpp
void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " repairs itself for "
                  << amount << " hit points!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " can't repair! No energy or hit points left."
                  << std::endl;
    }
}
```

### Lifecycle Messaging
Using messages to track object creation and destruction.

**Key Points:**
- Constructors print creation messages
- Destructor prints destruction message
- Messages help visualize object lifecycle
- Useful for debugging and understanding program flow
- Demonstrates when objects are created and destroyed

**Example:**
```cpp
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10),
                                      energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap constructor called for " << name << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << name << std::endl;
}
```

## Implementation Notes
- Initialize default values as specified (10 hit points, 10 energy points, 0 attack damage)
- Implement all required member functions with appropriate behavior
- Include proper output messages for all actions
- Check resource availability before performing actions
- Add messages in constructors and destructor to track object lifecycle
- Ensure proper Orthodox Canonical Form implementation
- Create comprehensive tests to verify all functionality
- Validate behavior when resources are depleted

## Related Topics
- Game character design patterns
- State management in objects
- Resource systems in games
- Proper message formatting
- Conditional actions based on state