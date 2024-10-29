# General Rules for C++ Exercises

## Compiling
- Compile your code with C++ and the flags `-Wall -Wextra -Werror`.
- Your code should still compile if you add the flag `-std=c++98`.

## Formatting and Naming Conventions
- The exercise directories will be named as follows: `ex00`, `ex01`, ..., `exn`.
- Name your files, classes, functions, member functions, and attributes as required in the guidelines.
- Write class names in UpperCamelCase format. Files containing class code will always be named according to the class name. For example:
  - ClassName.hpp/ClassName.h
  - ClassName.cpp
  - ClassName.tpp
  
  If you have a header file containing the definition of a class `BrickWall` representing a brick wall, its name will be `BrickWall.hpp`.

- Unless specified otherwise, all output messages must end with a new-line character and be displayed to the standard output.
- **Goodbye Norminette!** No coding style is enforced in the C++ modules. You can follow your favorite style, but remember that code your peer evaluators can’t understand is code they can’t grade. Write clean and readable code.

## Allowed/Forbidden Features
- **You are not coding in C anymore, it's time for C++!** Therefore:
  - You are allowed to use almost everything from the standard library. It's encouraged to use C++-specific versions of functions instead of C functions you're familiar with.
  - You cannot use any external libraries such as C++11 (and derived forms) or Boost. The following functions are **forbidden**: 
    - `*printf()`
    - `*alloc()`
    - `free()`
    - If you use any of these, your grade will be **0**.
  
- **Keywords and Libraries:**
  - Unless explicitly stated otherwise, the `using namespace <ns_name>` and `friend` keywords are forbidden. Using them will result in a grade of **-42**.
  - You can only use the STL (Standard Template Library) in **Module 08** and **Module 09**. This means:
    - No Containers (such as vector, list, map, etc.)
    - No Algorithms (anything requiring the inclusion of the `<algorithm>` header)
  - Using these features before the allowed modules will result in a grade of **-42**.

## Design Requirements
- **Memory Management:** Avoid memory leaks when allocating memory using the `new` keyword.
- From **Module 02 to Module 09**, your classes must follow the **Orthodox Canonical Form**, unless explicitly stated otherwise. Then, they will implement the four required member functions below:
  - Default constructor
  - Copy constructor
  - Copy assignment operator
  - Destructor
- Split your class code into two files. The header file (.hpp/.h) contains the class definition whereas the source file (.cpp) contains the implementation.
- Any function implementation placed in a header file (except for function templates) will result in a **0** grade for the exercise.
- Your headers should be usable independently from others, meaning they must include all necessary dependencies. However, you must avoid double inclusion by adding include guards. Otherwise, your grade will be **0**.

## Additional Notes
- You can add extra files if needed (e.g., to split your code). These assignments are not verified by a program, so feel free to do this as long as you turn in the required mandatory files.
- Sometimes the guidelines of an exercise may be short, but the examples provided can show requirements not explicitly stated in the instructions.
- **Read each module completely before starting!** Really, do it.
- **By Odin, by Thor! Use your brain!**

You will have to implement a lot of classes. This can seem tedious, unless you script your favorite text editor. You are given some freedom to complete the exercises, but follow the mandatory rules and avoid laziness. Missing out on important information will hinder your progress. Take the time to read about theoretical concepts as needed.
