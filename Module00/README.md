# Module 00 – C++ / MY NOTES

> This module covers the fundamental concepts of C++ for beginners, including casting, references, classes, static members, and namespaces.

## 📚 Table of Contents
- [🔄 C++ Casting](#-c-casting)
- [💻 Output in C++](#-output-in-c)
- [🔗 References](#-references)
- [🏗️ Classes and Objects](#️-classes-and-objects)
- [📦 Namespaces](#-namespaces)

---

## 🔄 C++ Casting

C++ provides several ways to cast values between types. Each has its own rules and use cases:

### ⚡ `static_cast`
- ✅ Checked by the compiler at compile-time
- ✅ Safer than C-style casts
- ✅ Used for well-defined conversions (e.g., numeric conversions)

```cpp
double d = 3.14;
int i = static_cast<int>(d); // i = 3
```

### ⚠️ C-style casts `(type)value`
- ❌ Not checked by the compiler
- ❌ Can fail at runtime without warning
- ❌ Generally discouraged in modern C++

```cpp
double d = 3.14;
int i = (int)d; // works, but less safe
```

### 🔍 `dynamic_cast`
- ✅ Checked at runtime
- ✅ Used for safe downcasting in class hierarchies (requires polymorphism)
- ✅ Returns `nullptr` for pointers or throws `std::bad_cast` for references if cast fails

```cpp
Base* basePtr = new Derived();
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
if (derivedPtr != nullptr) {
    // Safe to use derivedPtr
}
```

### ⚡ `reinterpret_cast`
- ⚠️ Low-level cast: treats memory as a different type without changing the bits
- ❌ **Warning**: Use with extreme caution - can cause undefined behavior or segmentation faults
- ❌ Cannot access private members (this is a misconception in the original notes)

```cpp
long l = 0x12345678;
int* p = reinterpret_cast<int*>(&l); 
// Dangerous: interpreting a long's memory as an int pointer
```

---

## 💻 Output in C++

### 🚿 `std::endl`
- ✅ Adds a newline **and** flushes the output stream
- ✅ Useful for debugging or when you need immediate output
- ⚠️ Can impact performance due to frequent flushing

```cpp
std::cout << "Hello" << std::endl;
```

### ⚡ `\n`
- ✅ Adds a newline **without** flushing the buffer
- ✅ Faster and preferred in performance-critical code
- ✅ Buffer is flushed automatically when full or when program ends

```cpp
std::cout << "Hello\n";
```

---

## 🔗 References

References provide an alternative name (alias) for an existing variable.

### 📝 Syntax and Usage
```cpp
int x = 10;
int &ref = x; // ref is another name for x
ref = 20;     // modifies x through ref
std::cout << x; // prints 20
```

### 🔑 Key Properties
- ✅ References are aliases to existing variables
- ✅ Unlike pointers, they **cannot** be null
- ✅ Unlike pointers, they **cannot** be reseated (reassigned to refer to another variable)
- ✅ Must be initialized when declared

---

## 🏗️ Classes and Objects

### 📖 Basic Concepts
- **Class**: A blueprint or template for creating objects
- **Instance/Object**: An actual variable created from a class

```cpp
class Dog {
private:
    std::string name;
public:
    void setName(const std::string& n) { name = n; }
    std::string getName() const { return name; }
};

Dog myDog; // myDog is an instance/object of Dog class
```

### 🏛️ Static Members

#### 📊 Static Variables
- ✅ Stored once in memory (not per instance)
- ✅ Shared by all instances of the class
- ✅ Exist even before any objects are created

```cpp
class Counter {
private:
    static int count; // shared by all Counter objects
public:
    Counter() { count++; }
    static int getCount() { return count; }
};

int Counter::count = 0; // Definition required outside class
```

#### ⚙️ Static Methods
- ✅ Can only access static variables and other static methods
- ❌ Cannot access instance (non-static) variables
- ✅ Can be called without creating an object

```cpp
int total = Counter::getCount(); // Called without object
```

---

## 📦 Namespaces

Namespaces help organize code and avoid name conflicts by grouping related functionality.

### 🌐 `using namespace N;`
- ✅ Imports **all** names from namespace N into the current scope
- ⚠️ Convenient but can lead to name conflicts in large projects

```cpp
using namespace std;
cout << "Hello"; // instead of std::cout
string s = "Hello"; // instead of std::string
```

### 🎯 `using N::name;`
- ✅ Imports only **one specific** name from a namespace
- ✅ More precise and safer approach

```cpp
using std::string;
using std::cout;

string s = "Hello";
cout << s; // but still need std::endl
```

### 💡 Best Practices
- ❌ Avoid `using namespace std;` in header files
- ✅ Prefer explicit namespace qualification (`std::cout`) or selective using declarations
- ✅ Use namespaces to organize your own code

---

## 📝 Additional Notes

- ✅ Always prefer C++ style casts over C-style casts for better type safety
- ✅ Use `const` wherever possible to make your intentions clear

## 🚀 Example Program

```cpp
#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    static int totalStudents;
    
public:
    Student(const std::string& n) : name(n) {
        totalStudents++;
    }
    
    const std::string& getName() const { return name; }
    static int getTotalStudents() { return totalStudents; }
};

int Student::totalStudents = 0;

int main() {
    Student s1("Alice");
    Student s2("Bob");
    
    std::cout << "Total students: " << Student::getTotalStudents() << '\n';
    
    return 0;
}
```

This example demonstrates classes, constructors, static members, and proper C++ output practices.

---

## 🤝 Contributing

Feel free to contribute by:
- 🐛 Reporting bugs
- 💡 Suggesting improvements
- 📖 Adding more examples
- ✏️ Fixing typos or errors
