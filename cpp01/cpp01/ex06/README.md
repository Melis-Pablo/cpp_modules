# Exercise 06: Harl filter

## Overview
This exercise builds on Harl 2.0 to introduce the switch statement and message filtering. You'll create a program that displays Harl's complaints based on a minimum severity level provided as a command-line argument.

## Core Concepts
- Switch Statement
- Enumeration Types
- Message Filtering
- Command-line Arguments
- Fall-through Behavior

## Concepts Explained

### Switch Statement
A control flow statement that selects one of many code blocks to execute.

**Key Points:**
- More efficient than multiple if/else statements
- Tests a variable against multiple constant values
- Uses `case` labels and `break` statements
- Can use fall-through behavior by omitting `break`
- Requires a `default` case for unexpected values

**Example:**
```cpp
switch (level) {
    case DEBUG:
        std::cout << "Debug message" << std::endl;
        break;
    case INFO:
        std::cout << "Info message" << std::endl;
        break;
    default:
        std::cout << "Unknown level" << std::endl;
}
```

[Documentation Link](http://www.cplusplus.com/doc/tutorial/control/)

### Enumeration Types
User-defined data types that consist of named constant values.

**Key Points:**
- Define a set of related constants
- Improve code readability and type safety
- Often used with switch statements
- Compiler treats enum values as integers
- Can specify underlying values explicitly

**Example:**
```cpp
enum Level {
    DEBUG,    // 0
    INFO,     // 1
    WARNING,  // 2
    ERROR     // 3
};

Level getLevel(const std::string& levelStr) {
    if (levelStr == "DEBUG") return DEBUG;
    if (levelStr == "INFO") return INFO;
    if (levelStr == "WARNING") return WARNING;
    if (levelStr == "ERROR") return ERROR;
    return Level(-1); // Invalid level
}
```

### Switch Fall-through
Using the natural flow of a switch statement without break statements.

**Key Points:**
- When a break is omitted, execution continues to the next case
- Useful for implementing "this level and above" logic
- Can reduce redundant code
- Requires careful documentation for clarity
- May trigger compiler warnings if unintentional

**Example:**
```cpp
switch (level) {
    case DEBUG:
        debug();
        // Fall through to INFO
    case INFO:
        info();
        // Fall through to WARNING
    case WARNING:
        warning();
        // Fall through to ERROR
    case ERROR:
        error();
        break;
    default:
        std::cout << "Invalid level" << std::endl;
}
```

### Command-line Argument Processing
Handling program inputs provided through command-line arguments.

**Key Points:**
- Arguments are passed to main as `argc` (count) and `argv` (array of strings)
- First argument (`argv[0]`) is the program name
- Check `argc` to ensure required arguments are provided
- Convert string arguments to appropriate types as needed
- Validate arguments before use

**Example:**
```cpp
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }

    std::string level = argv[1];
    // Process level...
    return 0;
}
```

## Implementation Notes
- Modify the Harl class to implement filtering based on level
- Use an enum or similar mapping to convert level strings to numeric values
- Implement a switch statement that uses fall-through behavior
- Start displaying messages from the specified level through ERROR
- Display a default message for invalid levels
- Take the minimum level as a command-line argument
- Ensure the executable is named "harlFilter"
- Test with all levels to verify correct filtering behavior

## Related Topics
- State machine implementation
- Logging frameworks
- Severity levels in logging
- String to enum conversion
- Default arguments