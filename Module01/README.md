# CPP Module 01 - Memory Management and References

This module covers fundamental C++ concepts including dynamic memory allocation, references, pointers, and file streams. Each exercise builds upon core programming concepts with practical examples.

---

## Table of Contents
- [ex00 - ex01: Dynamic Memory Allocation](#ex00---ex01-dynamic-memory-allocation)
- [ex02 - ex03: References vs Pointers](#ex02---ex03-references-vs-pointers)
- [ex04: File Streams and String Manipulation](#ex04-file-streams-and-string-manipulation)
- [ex05 - ex06: Pointers to Member Functions](#ex05---ex06-pointers-to-member-functions)

---

## ex00 - ex01: Dynamic Memory Allocation

### Concepts Covered
- Allocating objects on the heap using `new`
- Deallocating memory using `delete`
- Array allocation and deallocation
- Destructor call order (LIFO - Last In, First Out)

### Why These Concepts Exist

**Dynamic memory allocation** allows programs to request memory at runtime rather than compile time. This is essential when:
- The size of data structures is unknown until runtime
- Objects need to persist beyond the scope of a function
- You need fine-grained control over object lifetime

### Key Points

#### Single Object Allocation
```cpp
// Allocate a single object on the heap
Zombie* zombie = new Zombie("Foo");

// Always free the memory when done
delete zombie;
```

#### Array Allocation
```cpp
// Allocate an array of objects
Zombie* horde = new Zombie[5];

// Free the entire array (calls destructor for each element)
delete[] horde;  // Note the [] syntax for arrays
```

**Important:** Use `delete[]` for arrays, not `delete`. Using the wrong one causes undefined behavior.

#### Destructor Call Order (Stack Objects)

When objects are created on the stack, destructors are called in **reverse order of construction** (LIFO):

```cpp
{
    Zombie z1("First");   // Created first
    Zombie z2("Second");  // Created second
    Zombie z3("Third");   // Created third
}
// Destructors called in order: z3 → z2 → z1
```

This happens because the stack unwinds from top to bottom. The last object pushed onto the stack is the first to be popped off.

---

## ex02 - ex03: References vs Pointers

### Concepts Covered
- Understanding C++ references
- Differences between references and pointers
- When to use each

### Why These Concepts Exist

**References** provide a safer, more convenient alternative to pointers for many use cases. They prevent common pointer errors like null pointer dereferencing while maintaining efficiency (no copying).

### References

A **reference** is an alias for an existing variable—another name for the same memory location.

```cpp
int original = 42;
int& ref = original;  // ref is now another name for original

ref = 100;  // Changes original to 100
```

**Key characteristics:**
- Must be initialized when declared
- Cannot be reassigned to refer to a different variable
- Cannot be `NULL` or uninitialized
- Automatically dereferenced (no `*` or `->` needed)

### Pointers

**Pointers** work exactly as in C—they store memory addresses.

```cpp
int value = 42;
int* ptr = &value;  // ptr stores the address of value

*ptr = 100;  // Dereference to modify value
ptr = NULL;  // Can be set to NULL
```

**Key characteristics:**
- Can be uninitialized or `NULL`
- Can be reassigned to point to different variables
- Require explicit dereferencing with `*` or `->`
- Support pointer arithmetic

### When to Use Each

| Use Case | Reference | Pointer |
|----------|-----------|---------|
| Function parameters (avoiding copies) | ✓ Preferred | Use for optional params |
| Must support `NULL` / absence of value | ✗ | ✓ |
| Need to reassign | ✗ | ✓ |
| Working with arrays/pointer arithmetic | ✗ | ✓ |
| Simple aliasing | ✓ | ✗ |

---

## ex04: File Streams and String Manipulation

### Concepts Covered
- Reading from files using `std::ifstream`
- Writing to files using `std::ofstream`
- String manipulation and search/replace operations
- File I/O error handling

### Why These Concepts Exist

**File streams** provide a type-safe, object-oriented approach to file I/O in C++. Unlike C's `fopen`/`fclose`, streams use RAII (Resource Acquisition Is Initialization) to automatically manage file handles.

### Basic Usage

```cpp
#include <fstream>
#include <string>

// Reading from a file
std::ifstream infile("input.txt");
if (!infile.is_open()) {
    // Handle error
}

std::string line;
while (std::getline(infile, line)) {
    // Process each line
}
// File automatically closed when infile goes out of scope

// Writing to a file
std::ofstream outfile("output.txt");
if (outfile.is_open()) {
    outfile << "Hello, World!" << std::endl;
}
```

### Why Use Streams Over C File I/O?

1. **Automatic resource management**: No need to manually close files
2. **Type safety**: Handles different data types automatically
3. **Exception support**: Better error handling mechanisms
4. **Consistent interface**: Works like `std::cin` and `std::cout`

### String Manipulation Example

```cpp
std::string text = "Hello World";
size_t pos = text.find("World");
if (pos != std::string::npos) {
    text.replace(pos, 5, "C++");  // "Hello C++"
}
```

---

## ex05 - ex06: Pointers to Member Functions

### Concepts Covered
- Syntax for pointers to member functions
- Calling member functions through pointers
- Pointers to data members

### Why These Concepts Exist

**Pointers to members** enable callback mechanisms, function tables, and design patterns that require indirect function calls within a class context. They're particularly useful for implementing strategy patterns or event handlers.

### Syntax

#### Pointer to Member Function

```cpp
class MyClass {
public:
    void method() { /* ... */ }
    int getValue() { return 42; }
};

// Declaration syntax: ReturnType (ClassName::*pointerName)(Parameters)
void (MyClass::*funcPtr)() = &MyClass::method;

MyClass obj;
(obj.*funcPtr)();  // Call through object

MyClass* objPtr = &obj;
(objPtr->*funcPtr)();  // Call through pointer to object
```

#### Pointer to Data Member

```cpp
class MyClass {
public:
    int value;
};

// Declaration syntax: Type ClassName::*pointerName
int MyClass::*memberPtr = &MyClass::value;

MyClass obj;
obj.*memberPtr = 10;  // Access through object

MyClass* objPtr = &obj;
objPtr->*memberPtr = 20;  // Access through pointer
```

### Practical Example

```cpp
class Calculator {
public:
    int add(int a, int b) { return a + b; }
    int subtract(int a, int b) { return a - b; }
};

// Function pointer type
int (Calculator::*Operation)(int, int);

Operation op = &Calculator::add;
Calculator calc;
int result = (calc.*op)(5, 3);  // result = 8
```

### Key Syntax Elements

- `ClassName::*` declares a pointer to member
- `.*` dereferences a member pointer through an object
- `->*` dereferences a member pointer through a pointer to an object
- Always use `&ClassName::memberName` to get the address

---

## General Notes

- Always match `new` with `delete` and `new[]` with `delete[]`
- Prefer references over pointers when you don't need null values or reassignment
- Use RAII principles: resources should be acquired in constructors and released in destructors
- Modern C++ (C++11 and later) provides smart pointers (`std::unique_ptr`, `std::shared_ptr`) that automate memory management

---

## Compilation

All exercises should compile with:
```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program_name
```