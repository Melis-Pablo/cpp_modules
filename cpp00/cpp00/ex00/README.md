# Exercise 00: Megaphone

## Overview
This exercise introduces basic C++ syntax and standard I/O operations. You'll implement a simple program that converts command-line arguments to uppercase, demonstrating fundamental C++ functionality.

## Core Concepts
- C++ Standard I/O Streams
- String Manipulation
- Command Line Arguments
- Basic Program Structure

## Concepts Explained

### C++ Standard I/O Streams
Brief introduction to C++'s input/output stream library that replaces C's printf/scanf functions.

**Key Points:**
- Uses `iostream` header (`#include <iostream>`)
- Standard output through `std::cout` object
- Uses the insertion operator `<<` for output
- Flush or add newline with `std::endl`

**Example:**
```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

[Documentation Link](http://www.cplusplus.com/reference/iostream/)

### String Handling in C++
C++ offers improved string handling compared to C-style character arrays.

**Key Points:**
- `<string>` header provides the `std::string` class
- String objects manage their own memory
- Rich set of string manipulation methods
- Can be easily converted to uppercase/lowercase

**Example:**
```cpp
#include <string>
#include <iostream>

std::string str = "hello";
std::cout << str.length() << std::endl; // Outputs: 5
```

[Documentation Link](http://www.cplusplus.com/reference/string/string/)

### Command Line Arguments
How to process arguments passed to a C++ program when executed.

**Key Points:**
- Main function accepts arguments: `int main(int argc, char **argv)`
- `argc` is the count of arguments (program name is the first)
- `argv` is an array of C-style strings
- Always validate argument count before using

**Example:**
```cpp
int main(int argc, char **argv) {
    if (argc > 1) {
        std::cout << "First argument: " << argv[1] << std::endl;
    }
    return 0;
}
```

### Character Case Conversion
Converting text between lowercase and uppercase forms.

**Key Points:**
- Use `<cctype>` header (C++'s version of C's ctype.h)
- `std::toupper()` converts a character to uppercase
- Must be applied to each character individually for strings
- ASCII-based transformations

**Example:**
```cpp
#include <cctype>
#include <iostream>

char c = 'a';
char upper_c = std::toupper(c); // Converts to 'A'
```

[Documentation Link](http://www.cplusplus.com/reference/cctype/)

## Implementation Notes
- Remember to check if any arguments were provided
- Process each argument separately
- Apply uppercase conversion to each character
- Use `std::cout` instead of printf for C++ idiomatic code
- Consider string concatenation for multiple arguments

## Related Topics
- String streams (`<sstream>`)
- Iterating through collections (loops)
- String algorithms from `<algorithm>` (not allowed in this module)