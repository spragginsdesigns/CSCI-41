# CSCI-41 Midterm Study Guide

This study guide covers the key topics and concepts you'll need to understand for the CSCI-41 midterm exam. The material includes complexity analysis, linked lists, the "Big Three" in C++, makefiles, and vectors. Use this guide to review these concepts and ensure you're prepared for the exam.

---

## Table of Contents

- [CSCI-41 Midterm Study Guide](#csci-41-midterm-study-guide)
  - [Table of Contents](#table-of-contents)
  - [Complexity Analysis](#complexity-analysis)
    - [Big O Notation](#big-o-notation)
    - [Counting Steps in Algorithms](#counting-steps-in-algorithms)
    - [Simplifying Big O Expressions](#simplifying-big-o-expressions)
    - [Examples](#examples)
  - [Linked Lists](#linked-lists)
    - [Introduction to Linked Lists](#introduction-to-linked-lists)
    - [Singly vs. Doubly Linked Lists](#singly-vs-doubly-linked-lists)
    - [Operations and Their Complexities](#operations-and-their-complexities)
  - [The Big Three in C++](#the-big-three-in-c)
    - [Destructor](#destructor)
    - [Copy Constructor](#copy-constructor)
    - [Copy Assignment Operator](#copy-assignment-operator)
    - [Example: Implementing the Big Three](#example-implementing-the-big-three)
  - [Makefiles and Separate Compilation](#makefiles-and-separate-compilation)
    - [Introduction to Makefiles](#introduction-to-makefiles)
    - [Compiling Multiple Files](#compiling-multiple-files)
    - [Example Makefile](#example-makefile)
  - [Vectors](#vectors)
    - [Understanding Vectors as Dynamic Arrays](#understanding-vectors-as-dynamic-arrays)
    - [Implementation Details](#implementation-details)
    - [Complexity of Vector Operations](#complexity-of-vector-operations)
    - [Push Back Operation Analysis](#push-back-operation-analysis)
  - [Practice Questions](#practice-questions)

---

## Complexity Analysis

### Big O Notation

- **Purpose**: To describe the upper bound of an algorithm's running time or space requirements in terms of input size (usually denoted as *n*).
- **Notation**: O(f(n)), where f(n) is a function representing the growth rate.

### Counting Steps in Algorithms

1. **Count the Steps**:

   - Focus on the number of fundamental operations.
   - Loops, recursive calls, and significant operations contribute to the count.
2. **Terms to Consider**:

   - **Constant Time Operations**: Operations that take the same amount of time regardless of input size (e.g., simple arithmetic operations).
   - **Linear Time Operations**: Operations whose time scales linearly with input size (e.g., iterating through an array).

### Simplifying Big O Expressions

1. **Drop Lower-Order Terms**:

   - In expressions like `O(n^2 + n)`, drop the `n` term to get `O(n^2)`.
   - Lower-order terms become insignificant as *n* grows large.
2. **Drop Constant Multipliers**:

   - In expressions like `O(44n^3)`, drop the constant to get `O(n^3)`.
   - Constants do not affect the growth rate classification.
3. **Tightest Bound**:

   - Always provide the smallest (tightest) Big O notation that accurately describes the algorithm's complexity.

### Examples

- **Example 1**:

  ```cpp
  for (int i = 0; i < n; ++i) {
      // Constant time operation
  }
  ```

  - **Complexity**: O(n)
- **Example 2**:

  ```cpp
  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
          // Constant time operation
      }
  }
  ```

  - **Complexity**: O(n^2)
- **Example 3** (Counting Steps):

  - Steps: `2 + 42n + 43n^3 + 44n^14`
  - Drop lower-order terms and constants: `O(n^14)`

---

## Linked Lists

### Introduction to Linked Lists

- **Definition**: A data structure consisting of nodes where each node contains data and a reference (pointer) to the next node.
- **Comparison to Arrays**:
  - Arrays are contiguous in memory; linked lists are not.
  - Linked lists allow for efficient insertions and deletions.

### Singly vs. Doubly Linked Lists

- **Singly Linked List**:

  - Each node points only to the next node.
  - Operations like insertion and deletion at the front are efficient (O(1)).
  - Deleting the last node requires traversal (O(n)).
- **Doubly Linked List**:

  - Each node points to both the next and previous nodes.
  - Allows efficient insertion and deletion at both ends (O(1)).

### Operations and Their Complexities

- **Insertion at Front**:

  - Singly: O(1)
  - Doubly: O(1)
- **Insertion at End**:

  - Singly: O(n) unless a tail pointer is maintained.
  - Doubly: O(1)
- **Deletion at Front**:

  - Singly: O(1)
  - Doubly: O(1)
- **Deletion at End**:

  - Singly: O(n)
  - Doubly: O(1)
- **Search for an Element**:

  - Both: O(n)

---

## The Big Three in C++

When managing resources like dynamic memory in C++, you must properly handle copying and destruction to prevent memory leaks and dangling pointers. This involves implementing:

1. **Destructor**
2. **Copy Constructor**
3. **Copy Assignment Operator**

### Destructor

- **Purpose**: To release resources (like memory) when an object goes out of scope.
- **Syntax**:
  ```cpp
  ~ClassName();
  ```
- **Example**:
  ```cpp
  Counter::~Counter() {
      delete count;
  }
  ```

### Copy Constructor

- **Purpose**: To create a new object as a copy of an existing object.
- **Syntax**:

  ```cpp
  ClassName(const ClassName& other);
  ```
- **Deep Copy vs. Shallow Copy**:

  - **Shallow Copy**: Copies pointers as-is, leading to multiple objects pointing to the same memory (dangerous if one modifies or deletes the memory).
  - **Deep Copy**: Allocates new memory and copies the values over, ensuring each object manages its own memory.
- **Example (Deep Copy)**:

  ```cpp
  Counter::Counter(const Counter& other) {
      count = new int(*(other.count));
  }
  ```

### Copy Assignment Operator

- **Purpose**: To assign values from one existing object to another existing object.
- **Syntax**:
  ```cpp
  ClassName& operator=(const ClassName& other);
  ```
- **Self-Assignment Check**: Prevents issues when an object is assigned to itself.
  ```cpp
  if (this == &other) return *this;
  ```
- **Example**:
  ```cpp
  Counter& Counter::operator=(const Counter& other) {
      if (this == &other) return *this;
      delete count;
      count = new int(*(other.count));
      return *this;
  }
  ```

### Example: Implementing the Big Three

Given a `Counter` class that manages a dynamic integer:

```cpp
class Counter {
public:
    Counter();                              // Constructor
    ~Counter();                             // Destructor
    Counter(const Counter& other);          // Copy Constructor
    Counter& operator=(const Counter& other); // Copy Assignment Operator
    void operator++();                      // Increment Operator
    int getCount() const;                   // Getter for count

private:
    int* count;                             // Pointer to count on heap
};
```

---

## Makefiles and Separate Compilation

### Introduction to Makefiles

- **Purpose**: Automate the build process, especially when dealing with multiple files.
- **Benefits**:
  - Only recompile files that have changed.
  - Simplifies complex build commands.

### Compiling Multiple Files

- **Separate Compilation**:
  - Compile each `.cpp` file into an object file (`.o`) separately.
  - Link object files together to create the final executable.

### Example Makefile

```makefile
# Makefile for Counter project

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Targets
main: main.o counter.o
    $(CXX) $(CXXFLAGS) -o main main.o counter.o

main.o: main.cpp counter.h
    $(CXX) $(CXXFLAGS) -c main.cpp

counter.o: counter.cpp counter.h
    $(CXX) $(CXXFLAGS) -c counter.cpp

clean:
    rm -f *.o main
```

- **Usage**:
  - `make`: Builds the project.
  - `make clean`: Removes object files and executable.

---

## Vectors

### Understanding Vectors as Dynamic Arrays

- **Definition**: A sequence container representing arrays that can change in size.
- **Advantages**:
  - Dynamic resizing.
  - Provides array-like access.

### Implementation Details

- **Size vs. Capacity**:

  - **Size**: The number of elements currently stored.
  - **Capacity**: The total amount of space allocated.
- **Resizing Mechanism**:

  - When capacity is reached, the vector allocates a new array with double the capacity and copies the elements over.

### Complexity of Vector Operations

- **Accessing Elements (`at`, `operator[]`)**: O(1)
- **Adding Elements (`push_back`)**:
  - **Average Case**: O(1)
  - **Worst Case**: O(n) when resizing is needed.

### Push Back Operation Analysis

- **Amortized Constant Time**:

  - Although individual `push_back` operations can take O(n) time when resizing, the average time over many insertions remains O(1).
- **Resizing Process**:

  1. Allocate new memory with increased capacity.
  2. Copy existing elements to the new array.
  3. Delete the old array.
  4. Insert the new element.

---

## Practice Questions

1. **Complexity Analysis**:

   - Given a nested loop where the outer loop runs *n* times and the inner loop runs *n* times, what is the complexity?
     - **Answer**: O(n^2)
2. **Linked Lists**:

   - What is the time complexity of inserting an element at the end of a singly linked list without a tail pointer?
     - **Answer**: O(n)
3. **The Big Three**:

   - Why is it important to implement a copy constructor when your class manages dynamic memory?
     - **Answer**: To ensure a deep copy is made, preventing multiple objects from pointing to the same memory and causing potential errors like double deletion.
4. **Vectors**:

   - Explain why the `push_back` operation in a vector is considered O(1) on average.
     - **Answer**: Because resizing happens infrequently (when capacity is reached), the cost of resizing is spread out over many `push_back` operations, making the average time per insertion O(1).
5. **Makefiles**:

   - What command in a makefile specifies how to compile a `.cpp` file into an object file?
     - **Answer**: The compile rule, e.g., `$(CXX) $(CXXFLAGS) -c filename.cpp`

---
