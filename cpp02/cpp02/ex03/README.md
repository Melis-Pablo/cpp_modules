# Exercise 03: BSP (Binary Space Partitioning)

## Overview
This exercise applies fixed-point arithmetic to computational geometry. You'll implement a Point class to represent 2D coordinates and a Binary Space Partitioning function to determine if a point lies inside a triangle.

## Core Concepts
- 2D Point Representation
- Computational Geometry
- Const Member Variables
- Point-in-Triangle Algorithm
- Binary Space Partitioning

## Concepts Explained

### 2D Point Representation
Creating a class to represent points in a two-dimensional space.

**Key Points:**
- Store x and y coordinates as Fixed-point numbers
- Make coordinates const to prevent modification after creation
- Provide constructors for different initialization methods
- Follow Orthodox Canonical Form requirements
- Use composition with the Fixed class

**Example:**
```cpp
class Point {
private:
    const Fixed x;
    const Fixed y;

public:
    Point();                         // Default constructor
    Point(const float x, const float y);  // Parameterized constructor
    Point(const Point& other);       // Copy constructor
    Point& operator=(const Point& other);  // Copy assignment operator
    ~Point();                        // Destructor
};
```

### Const Member Variables
Class variables that can't be modified after initialization.

**Key Points:**
- Declared with `const` keyword in class definition
- Must be initialized in constructor initialization list
- Can't be modified in class methods
- Creates immutable object properties
- Special handling needed in copy assignment operator

**Example:**
```cpp
class Point {
private:
    const Fixed x;  // Const member variable
    const Fixed y;  // Const member variable

public:
    // Must use initialization list for const members
    Point(float x, float y) : x(x), y(y) {}
};
```

### Binary Space Partitioning
A method for determining spatial relationships by recursively subdividing space.

**Key Points:**
- Divides space into regions using planes/lines
- Used in computer graphics and computational geometry
- Efficient for point location and collision detection
- In 2D, involves checking which side of a line a point lies on
- Applied here to determine if a point is inside a triangle

**Example:**
```cpp
// Determine on which side of a line (a,b) the point p lies
Fixed sideOfLine(Point const& a, Point const& b, Point const& p) {
    // Cross product to determine side
    return (b.getX() - a.getX()) * (p.getY() - a.getY()) -
           (b.getY() - a.getY()) * (p.getX() - a.getX());
}
```

### Point-in-Triangle Algorithm
Method to determine if a point lies inside a triangle.

**Key Points:**
- Can be implemented using barycentric coordinates
- Alternatively, check if point is on same side of all three edges
- Point is inside if and only if it's on same side of all edges
- Vertices and points on edges are typically considered outside
- Uses Fixed-point arithmetic for exact calculations

**Example:**
```cpp
bool bsp(Point const& a, Point const& b, Point const& c, Point const& point) {
    // Check if point is on the same side of all three edges
    // (Implementation details vary based on chosen algorithm)
}
```

### Immutable Object Design
Creating objects whose state cannot be changed after construction.

**Key Points:**
- Use const member variables for immutability
- Rely on initialization rather than assignment
- Special handling needed for copy operations
- Increases program safety and predictability
- Often used for mathematical and geometric objects

**Example:**
```cpp
Point::Point(const Point& other) : x(other.x), y(other.y) {
    // Body can be empty since all initialization is done in the list
}

// Special care needed for assignment of const members
Point& Point::operator=(const Point& other) {
    // Can't modify x and y directly, so often this becomes a no-op
    // or requires a custom implementation
    return *this;
}
```

## Implementation Notes
- Implement the Point class in Orthodox Canonical Form
- Use Fixed x and y coordinates declared as const
- Create a constructor taking two floating-point values
- Handle the assignment operator carefully due to const members
- Implement the bsp() function to check if a point is in a triangle
- Return false for points on triangle vertices or edges
- Create thorough tests to verify your implementation
- Consider edge cases like collinear points or degenerate triangles
- Apply the Fixed-point class from previous exercises

## Related Topics
- Barycentric coordinates
- Vector cross products
- Computational geometry algorithms
- Immutable object patterns
- Geometric primitives