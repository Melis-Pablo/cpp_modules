# C++ Modules (00-04)

## 🎓 Project Overview

This repository contains five foundational C++ modules from the 42 School curriculum, designed to provide a comprehensive introduction to Object-Oriented Programming. Each module builds progressively on the previous ones, guiding you through the transition from procedural C programming to object-oriented C++ development.

All modules adhere to the C++98 standard, focusing on core language concepts rather than modern features. This approach ensures a solid understanding of OOP fundamentals that remain relevant regardless of the C++ version used.

## 📚 Module Contents

### [Module 00: Namespace, Classes & Basic C++](./cpp00)

An introduction to the fundamental building blocks of C++ and object-oriented design.

**Key Concepts:**
- **Classes and Objects**: Creating your own data types with methods
- **Access Control**: Public and private members
- **I/O Streams**: Using `iostream` for input and output
- **Initialization Lists**: Efficient object initialization
- **Static Members**: Class-wide data and functions
- **Constant Objects**: Immutability in C++

### [Module 01: Memory Allocation & References](./cpp01)

Diving deeper into C++ memory management and reference semantics.

**Key Concepts:**
- **Memory Models**: Stack vs heap allocation
- **Pointers vs References**: When and how to use each
- **Dynamic Memory**: Working with `new` and `delete`
- **Object Lifecycle**: Construction, usage, destruction
- **Member Function Pointers**: Advanced function callbacks
- **Scope Management**: Understanding variable lifetimes

### [Module 02: Operator Overloading & Canonical Form](./cpp02)

Customizing operator behavior and establishing best practices for class design.

**Key Concepts:**
- **Orthodox Canonical Form**: The four essential class functions
- **Operator Overloading**: Creating intuitive interfaces
- **Fixed-Point Numbers**: Implementation and representation
- **Copy Semantics**: Deep vs shallow copying
- **Conversion Operators**: Type conversion control
- **Function Overloading**: Same name, different parameters

### [Module 03: Inheritance & Class Hierarchies](./cpp03)

Building relationships between classes to model complex systems.

**Key Concepts:**
- **Class Inheritance**: Extending functionality
- **Access Control**: Public, protected, and private inheritance
- **Method Overriding**: Customizing inherited behavior
- **Constructor Chaining**: Parent-child initialization
- **Multiple Inheritance**: Combining multiple parent classes
- **Inheritance Pitfalls**: Avoiding common problems

### [Module 04: Polymorphism & Abstractions](./cpp04)

Implementing advanced OOP techniques for flexible code architecture.

**Key Concepts:**
- **Runtime Polymorphism**: Interface-based programming
- **Virtual Functions**: Dynamic method dispatch
- **Abstract Classes**: Partial and complete abstraction
- **Pure Virtual Functions**: Creating interfaces
- **Virtual Destructors**: Proper cleanup in inheritance chains
- **Type Introspection**: Identifying object types at runtime

## 🛠️ Technical Implementation

### Class Design Principles

All exercises follow these fundamental principles:
- **Orthodox Canonical Form**: Including default constructor, copy constructor, assignment operator, and destructor
- **Memory Management**: Proper allocation and deallocation to prevent leaks
- **Encapsulation**: Clear boundaries between interface and implementation

### Compilation and Usage

Each module contains multiple exercises with their own Makefiles:

```bash
# Navigate to the exercise directory
cd cpp_module_XX/exYY

# Compile the exercise
make

# Run the executable
./executable_name
```

## 📝 Learning Outcomes

Through these modules, I gained practical knowledge in:

- **Object-Oriented Design**: Modeling real-world entities as classes
- **Memory Management**: Understanding and controlling object lifecycle
- **Code Organization**: Structuring programs for maintainability
- **Inheritance Hierarchies**: Building flexible class relationships
- **Abstraction Techniques**: Creating adaptable interfaces
- **C++ Language Features**: Working with the core building blocks of C++

## ⚠️ Note

- All code strictly complies with the C++98 standard
- External libraries are not used beyond the C++ standard library
- Memory management is handled manually without smart pointers
- Exercises focus on educational concepts rather than production-ready code

For detailed information about each module, refer to the individual READMEs within each module directory.

---

*These projects are part of the 42 School Common Core curriculum.*