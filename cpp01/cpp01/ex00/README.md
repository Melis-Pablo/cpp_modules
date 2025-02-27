# Exercise 00: BraiiiiiiinnnzzzZ

## Overview
This exercise introduces dynamic memory allocation in C++ through the implementation of a Zombie class. You'll learn to create objects on both the stack and heap, and understand when to use each approach.

## Core Concepts
- Class Implementation
- Stack vs Heap Memory Allocation
- Memory Management
- Object Lifetime
- Function Return Types
- Destructors

## Concepts Explained

### Stack vs Heap Memory Allocation
Memory allocation strategies with different lifetimes and management requirements.

**Key Points:**
- Stack: Fast, automatic memory management
- Heap: Manual memory management using `new` and `delete`
- Stack objects are destroyed when they go out of scope
- Heap objects persist until explicitly deleted

**Example:**
```cpp
// Stack allocation
Zombie stackZombie("Stack Zombie");

// Heap allocation
Zombie* heapZombie = new Zombie("Heap Zombie");
delete heapZombie; // Must manually free heap memory
```

[Documentation Link](http://www.cplusplus.com/doc/tutorial/dynamic/)

### Destructors
Special member functions called when objects are destroyed.

**Key Points:**
- Defined with `~ClassName()` syntax
- Called automatically when objects go out of scope
- Used for cleanup operations (freeing resources)
- Essential for preventing memory leaks

**Example:**
```cpp
class Zombie {
private:
    std::string name;
public:
    ~Zombie() {
        std::cout << name << " is destroyed" << std::endl;
    }
};
```

[Documentation Link](http://www.cplusplus.com/doc/tutorial/classes2/)

### Dynamic Object Creation
Creating objects at runtime using the `new` keyword.

**Key Points:**
- Uses the `new` operator to allocate memory
- Returns a pointer to the created object
- Allows objects to outlive the function they were created in
- Requires manual memory management

**Example:**
```cpp
Zombie* newZombie(std::string name) {
    return new Zombie(name); // Creates zombie on heap
}
```

### Function Return Types
Different ways functions can return objects or references to objects.

**Key Points:**
- Return by value: Creates a copy of the object
- Return by pointer: Returns a memory address, usually from heap allocation
- Return by reference: Returns an alias to an existing object
- Return type determines ownership responsibility

**Example:**
```cpp
// Returns a pointer to a heap-allocated object
Zombie* createOnHeap(std::string name) {
    return new Zombie(name);
}

// Returns a stack object by value (creates a copy)
Zombie createOnStack(std::string name) {
    Zombie z(name);
    return z;
}
```

## Implementation Notes
- Consider when to create Zombies on stack vs heap
- Remember to delete heap-allocated zombies to prevent memory leaks
- Stack objects are automatically destroyed when they go out of scope
- Use the heap when you need the object to persist beyond the function's scope
- Use the stack when the object is only needed within the current scope
- Implement the destructor to print debugging information

## Related Topics
- Memory leaks
- Smart pointers (C++11)
- Resource Acquisition Is Initialization (RAII)
- Constructor overloading