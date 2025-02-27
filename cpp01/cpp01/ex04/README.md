# Exercise 04: Sed is for losers

## Overview
This exercise introduces file I/O operations in C++ and string manipulation without using the replace function. You'll create a program that performs text replacement in a file, similar to the sed command.

## Core Concepts
- File I/O Operations
- String Manipulation
- Error Handling
- Stream Processing
- Text Parsing

## Concepts Explained

### File I/O in C++
Reading from and writing to files using C++ streams.

**Key Points:**
- Uses `<fstream>` header
- `std::ifstream` for reading files
- `std::ofstream` for writing files
- Always check if files opened successfully
- Close files when done

**Example:**
```cpp
#include <fstream>

std::ifstream inFile("input.txt");
if (!inFile.is_open()) {
    // Handle error
}

std::ofstream outFile("output.txt");
if (!outFile.is_open()) {
    // Handle error
}
```

[Documentation Link](http://www.cplusplus.com/reference/fstream/ifstream/)

### String Search and Substring Replacement
Finding and replacing occurrences of substrings without using the replace function.

**Key Points:**
- `std::string::find()` locates substring positions
- When not found, returns `std::string::npos`
- Manual replacement requires tracking positions
- Can use a combination of substring and concatenation operations
- Repeat until all occurrences are replaced

**Example:**
```cpp
std::string replaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t pos = 0;
    while ((pos = str.find(from, pos)) != std::string::npos) {
        std::string before = str.substr(0, pos);
        std::string after = str.substr(pos + from.length());
        str = before + to + after;
        pos += to.length();
    }
    return str;
}
```

[Documentation Link](http://www.cplusplus.com/reference/string/string/find/)

### Error Handling
Detecting and responding to errors in file operations and user input.

**Key Points:**
- Check file open operations
- Validate command-line arguments
- Provide meaningful error messages
- Exit with appropriate error codes
- Handle edge cases (empty strings, missing files)

**Example:**
```cpp
if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
    return 1;
}

std::ifstream inFile(argv[1]);
if (!inFile.is_open()) {
    std::cerr << "Error: Could not open file " << argv[1] << std::endl;
    return 1;
}
```

### Stream Processing
Processing data line by line or character by character from streams.

**Key Points:**
- Can read entire file into a string
- Can process line by line for large files
- Use `std::getline()` for line-by-line reading
- Check stream state after operations
- String streams can convert between types

**Example:**
```cpp
std::string line;
while (std::getline(inFile, line)) {
    // Process line
    outFile << processLine(line) << std::endl;
}
```

[Documentation Link](http://www.cplusplus.com/reference/string/string/getline/)

## Implementation Notes
- Verify three command-line arguments are provided
- Open the input file for reading
- Create an output file with ".replace" extension
- Read the file content (line by line or all at once)
- Replace all occurrences of s1 with s2
- Write the modified content to the output file
- Handle errors appropriately (file not found, permission issues)
- Remember to close file streams
- Test with various inputs including edge cases

## Related Topics
- File permissions
- Binary file I/O
- Stream manipulators
- String view (C++17)
- Regular expressions