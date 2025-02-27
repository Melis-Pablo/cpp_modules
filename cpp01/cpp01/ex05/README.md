# Exercise 05: Harl 2.0

## Overview
This exercise introduces pointers to member functions as an alternative to if/else chains. You'll implement a class that selects and executes different member functions based on a string parameter.

## Core Concepts
- Pointers to Member Functions
- Function Tables
- Function Dispatch
- String Comparison
- Design Patterns

## Concepts Explained

### Pointers to Member Functions
Variables that can store references to class member functions.

**Key Points:**
- Syntax: `returnType (ClassName::*pointerName)(parameterTypes)`
- Called with object instance and dereference: `(object.*pointerName)(arguments)`
- Enable runtime selection of which method to call
- Allow creation of dispatch tables and command patterns
- More type-safe than void pointers to functions

**Example:**
```cpp
class MyClass {
public:
    void foo() { std::cout << "foo called" << std::endl; }
    void bar() { std::cout << "bar called" << std::endl; }
};

// Declare a pointer to member function
void (MyClass::*funcPtr)();

// Assign and call
MyClass obj;
funcPtr = &MyClass::foo;
(obj.*funcPtr)();  // Calls obj.foo()
```

[Documentation Link](http://www.cplusplus.com/doc/tutorial/pointers/)

### Function Tables/Maps
Data structures that associate identifiers with functions for lookup.

**Key Points:**
- Can use arrays or maps to store function pointers
- Allow O(1) or O(log n) lookup instead of if/else chains
- Easily extensible by adding new entries
- Separate the dispatch logic from function implementation
- Can map strings or enums to functions

**Example:**
```cpp
struct FuncEntry {
    std::string level;
    void (Harl::*func)();
};

FuncEntry funcTable[4] = {
    {"DEBUG", &Harl::debug},
    {"INFO", &Harl::info},
    {"WARNING", &Harl::warning},
    {"ERROR", &Harl::error}
};
```

### Command Pattern
A behavioral design pattern that encapsulates a request as an object.

**Key Points:**
- Decouples sender from receiver
- Transforms requests into stand-alone objects
- Allows parameterization of objects with operations
- Enables queueing, logging, and undoing operations
- Function pointers implement a simplified version

**Example:**
```cpp
void Harl::complain(std::string level) {
    for (int i = 0; i < 4; i++) {
        if (level == funcTable[i].level) {
            (this->*funcTable[i].func)();
            return;
        }
    }
}
```

### String Comparison and Matching
Techniques for matching string inputs to predefined values.

**Key Points:**
- Can use direct comparison with `==` operator
- Case sensitivity matters in C++ string comparisons
- Consider using a map for more complex lookups
- String comparison is typically O(n) where n is string length
- Can convert to lowercase/uppercase for case-insensitive comparison

**Example:**
```cpp
if (level == "DEBUG") {
    // Handle debug level
}
```

## Implementation Notes
- Define four private member functions for different complaint levels
- Implement a complain function that takes a level string
- Use pointers to member functions to call the appropriate function
- Avoid using if/else if/else chains for dispatch
- Create a table/array/map to store the mapping between strings and functions
- Loop through the mapping structure to find the matching function
- Consider handling invalid level inputs gracefully
- Test with all defined levels to ensure correct behavior

## Related Topics
- Function objects (functors)
- Lambda expressions (C++11)
- std::function (C++11)
- Visitor pattern
- Strategy pattern