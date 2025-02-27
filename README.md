# C++ Modules (00-04)

## Introduction

This repository contains five C++ modules from the 42 curriculum, designed to introduce Object-Oriented Programming concepts through progressive exercises. Each module builds upon the knowledge of previous ones, gradually introducing more complex OOP principles.

These modules comply with the C++98 standard and focus on foundational programming concepts rather than modern C++ features.

## Module Overview

### [Module 00: Namespace, class, member functions, stdio streams, initialization lists, static, const](./cpp00)

An introduction to the basic concepts of C++, making the transition from C to C++.

**Key concepts:**
- Classes and instances
- Member functions
- Visibility (public/private)
- Basic I/O with iostream
- Initialization lists
- Static class members
- Const qualifier

### [Module 01: Memory allocation, pointers to members, references, switch statement](./cpp01)

Deepening C++ knowledge with memory management and references.

**Key concepts:**
- Memory allocation (stack vs. heap)
- Pointers and references
- Creating and manipulating objects
- Switch statements
- Member function pointers
- Class scope

### [Module 02: Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form](./cpp02)

Learning operator overloading and canonical form class design.

**Key concepts:**
- Orthodox Canonical Form
- Operator overloading
- Fixed-point numbers
- Copy constructors
- Assignment operators
- Binary Space Partitioning

### [Module 03: Inheritance](./cpp03)

Introduction to inheritance and the creation of class hierarchies.

**Key concepts:**
- Class inheritance
- Access specifiers
- Method overriding
- Constructor/destructor behavior in inheritance
- Multiple inheritance
- The diamond problem

### [Module 04: Subtype polymorphism, abstract classes, interfaces](./cpp04)

Advanced OOP concepts including polymorphism and abstraction.

**Key concepts:**
- Polymorphism
- Virtual functions
- Abstract classes
- Pure virtual functions
- Interfaces
- Deep copying in polymorphic classes

## Compilation and Usage

Each module contains multiple exercises, each with its own Makefile. To compile an exercise:

```bash
cd cpp_module_XX/exYY
make
```

This will create an executable that you can run to test the functionality.

## Requirements

- C++ compiler with C++98 support (g++, clang++)
- Make

## Resources

Each module directory contains detailed explanations of the concepts covered and the specific requirements for each exercise. Refer to the individual READMEs within each module for more information.

## Notes

- All code complies with the C++98 standard
- No external libraries are used beyond the C++ standard library
- Classes follow the Orthodox Canonical Form unless specified otherwise
- Memory management is handled manually (no smart pointers)