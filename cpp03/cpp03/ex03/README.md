# Exercise 03: Now it's weird!

## Overview
This exercise introduces multiple inheritance in C++. You'll create a DiamondTrap class that inherits from both FragTrap and ScavTrap, demonstrating the diamond problem and how to resolve it using virtual inheritance.

## Core Concepts
- Multiple Inheritance
- Diamond Problem
- Virtual Inheritance
- Name Shadowing
- Attribute Selection

## Concepts Explained

### Multiple Inheritance
Creating a class that inherits from more than one parent class.

**Key Points:**
- Use `: public Base1, public Base2` syntax to inherit from multiple classes
- Inherits attributes and methods from all parent classes
- Can lead to ambiguity if parents have methods/attributes with same name
- Must resolve conflicts explicitly
- Allows combining functionality from different sources

**Example:**
```cpp
class DiamondTrap : public FragTrap, public ScavTrap {
    // DiamondTrap implementation
};
```

[Documentation Link](http://www.cplusplus.com/doc/tutorial/inheritance/)

### The Diamond Problem
The issue that arises when a class inherits from two classes that share a common ancestor.

**Key Points:**
- Without virtual inheritance, common ancestor appears twice in the hierarchy
- Leads to duplicate members and ambiguity
- ClapTrap would be included twice in DiamondTrap
- Ambiguous which ClapTrap member to access
- Requires special handling to resolve

**Example:**
```
    ClapTrap
    /      \
ScavTrap  FragTrap
    \      /
   DiamondTrap
```

### Virtual Inheritance
A mechanism to solve the diamond problem by ensuring a single instance of the common base class.

**Key Points:**
- Use `virtual` keyword in intermediate class inheritance declaration
- Ensures only one instance of common base exists in the hierarchy
- Resolves ambiguity in multiple inheritance
- Required for both intermediate classes
- Makes inheritance relationships more complex

**Example:**
```cpp
class ScavTrap : virtual public ClapTrap {
    // ScavTrap implementation
};

class FragTrap : virtual public ClapTrap {
    // FragTrap implementation
};

class DiamondTrap : public ScavTrap, public FragTrap {
    // DiamondTrap implementation with single ClapTrap instance
};
```

### Name Shadowing
When a derived class has a member with the same name as a member in the base class.

**Key Points:**
- Derived class member "shadows" or hides the base class member
- Accessing the base member requires scope resolution operator
- Compiler flags can help identify shadowing (-Wshadow)
- Can be intentional to create class-specific versions
- Requires careful documentation

**Example:**
```cpp
class ClapTrap {
protected:
    std::string name;
};

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string name; // Shadows the name from ClapTrap
};
```

### Constructor Initialization in Multiple Inheritance
Managing initialization when inheriting from multiple classes.

**Key Points:**
- Must call constructors of all direct parent classes
- With virtual inheritance, must also explicitly call common base constructor
- Order in initializer list doesn't affect construction order
- Construction order follows declaration order in class definition
- Requires careful planning for proper initialization

**Example:**
```cpp
DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), // Explicitly calling the virtual base
      ScavTrap(name),
      FragTrap(name),
      name(name) {
    // Initialize with attributes from different parents
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;

    std::cout << "DiamondTrap constructor called" << std::endl;
}
```

## Implementation Notes
- Create DiamondTrap class inheriting from both FragTrap and ScavTrap
- Modify ScavTrap and FragTrap to use virtual inheritance from ClapTrap
- Add a name private attribute in DiamondTrap (same variable name as in ClapTrap)
- Set ClapTrap's name to parameter + "_clap_name" suffix
- Take attributes selectively from parents (hitPoints and attackDamage from FragTrap, energyPoints from ScavTrap)
- Use ScavTrap's attack() method
- Implement the whoAmI() method that displays both the DiamondTrap name and ClapTrap name
- Ensure proper constructor/destructor chaining
- Pay attention to which members come from which parent class
- Test all functionality including inherited methods and special abilities
- Use the -Wshadow compiler flag to check for name shadowing

## Related Topics
- Virtual functions
- Abstract classes
- Multiple inheritance alternatives
- Mixins and composition
- Complex inheritance hierarchies