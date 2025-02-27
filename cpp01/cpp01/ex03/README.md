# Exercise 03: Unnecessary violence

## Overview
This exercise demonstrates practical differences between pointers and references through class composition. You'll implement weapon-wielding human classes to understand when to use references versus pointers as class members.

## Core Concepts
- Class Composition
- Reference Members
- Pointer Members
- Const References
- Object Lifetime Dependencies
- Conditional Ownership

## Concepts Explained

### Class Composition
Building classes that contain other objects as member variables.

**Key Points:**
- A class can contain instances of other classes
- Composition establishes a "has-a" relationship
- Member objects can be stored directly, by reference, or by pointer
- The choice affects initialization requirements and lifetime management

**Example:**
```cpp
class Car {
private:
    Engine engine;  // Composition: Car has an Engine
};
```

### Reference Members
Using references as class member variables.

**Key Points:**
- Must be initialized in the constructor's initialization list
- Cannot be reassigned after initialization
- Cannot have null value
- Reference members require the referenced object to exist for the lifetime of the containing object
- Useful when the member always exists and won't change

**Example:**
```cpp
class HumanA {
private:
    std::string name;
    Weapon& weapon;  // Reference member
public:
    HumanA(std::string name, Weapon& w) : name(name), weapon(w) {}
};
```

[Documentation Link](http://www.cplusplus.com/doc/tutorial/classes2/)

### Pointer Members
Using pointers as class member variables.

**Key Points:**
- Can be initialized in constructor body or initialization list
- Can be reassigned to point to different objects
- Can be null (no object referenced)
- Useful when the member might not exist or might change

**Example:**
```cpp
class HumanB {
private:
    std::string name;
    Weapon* weapon;  // Pointer member
public:
    HumanB(std::string name) : name(name), weapon(nullptr) {}
    void setWeapon(Weapon& w) { weapon = &w; }
};
```

### Const References
Using const references to prevent modification of referenced objects.

**Key Points:**
- Declared with `const` before the type
- Prevents modification of the referenced object
- Provides read-only access
- Used for efficient parameter passing and return values
- Beneficial for access methods that shouldn't modify data

**Example:**
```cpp
const std::string& getName() const {
    return name;  // Returns a const reference, can't be modified
}
```

[Documentation Link](http://www.cplusplus.com/doc/tutorial/classes2/)

### Optional vs Required Dependencies
Handling class members that may or may not be present.

**Key Points:**
- References must always refer to valid objects
- Pointers can be null to indicate absence
- Choose based on whether the dependency is optional
- Initialize pointer members to nullptr when they start empty
- Check pointer validity before dereferencing

**Example:**
```cpp
void HumanB::attack() {
    if (weapon) {  // Check if weapon exists
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " attacks with bare hands" << std::endl;
    }
}
```

## Implementation Notes
- HumanA always has a Weapon: use a reference member
- HumanB might not have a Weapon: use a pointer member
- Initialize reference members in the constructor initialization list
- Check pointer validity before use to avoid null pointer dereferencing
- Implement getType() to return a const reference for efficiency
- Using the right member type (pointer vs reference) for the relationship semantics is crucial

## Related Topics
- Dependency injection
- Smart pointers
- Const correctness
- Initialization lists
- Null safety