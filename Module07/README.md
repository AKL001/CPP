# C++ Templates: A Quick Guide

This guide covers the key concepts of C++ templates, focusing on why they are used and common implementation patterns.

---

## 1. What are Templates?

Templates are **blueprints** for creating functions or classes. They allow you to write generic code that works with different data types without rewriting the entire logic for each type.

### Defining a Template

You can use either the `typename` or `class` keyword to declare a template parameter. They are **functionally identical** in this context.

* `template<typename T>`
* `template<class T>`

> **Advice:** Modern C++ development often prefers `typename` to avoid confusion with the `class` keyword used for class definitions, but both are valid.

---

## 2. Types of Templates

There are three main types of templates:

* **Function Templates:** Blueprints for generic functions.
* **Class Templates:** Blueprints for generic classes (e.g., `std::vector`, `std::map`).
* **Variable Templates (C++14+):** Blueprints for generic variables (e.g., `template<typename T> constexpr T pi = 3.14159...;`).

---

## 3. Template Instantiation

A template is **not** code. The compiler only generates the actual C++ code (a process called **instantiation**) when you use the template with a specific type.

### Example: Function Template

Here is the blueprint for a generic `print` function.

```cpp
#include <iostream>

// 1. The Template (Blueprint)
template<typename T>
void print(T value)
{
    std::cout << value << std::endl;
}

int main()
{
    // 2. Implicit Instantiation
    // The compiler sees you're using an 'int' and
    // automatically generates a 'print<int>(int)' function.
    print(4);

    // 3. Explicit Instantiation
    // We can also explicitly tell the compiler which version to create.
    print<double>(5.5);
    
    // This is how the STL works, e.g., std::vector<int> v;
    // The compiler deduces the type 'int' and creates the class 'std::vector<int>'.
}
```

---

## 4. The Template Separation Problem

This is the most common point of confusion for developers new to templates.

**The Problem:** You cannot separate a template's definition into a `.cpp` file while keeping its declaration in a `.hpp` file in the way you do with normal functions.

**Why? The Linker Phase.**

C++ compiles files separately (this is the "separate compilation model").

1. **main.cpp is compiled:** The compiler sees you call `myTemplate<int>()`. It only has the declaration from `myTemplate.hpp`, so it trusts that the linker will find the implementation later.

2. **myTemplate.cpp is compiled:** The compiler sees the template definition (the blueprint) but it doesn't see any code using it (like `myTemplate<int>()`). Since templates are only instantiated on use, the compiler generates no code for `myTemplate.cpp`.

3. **Linker Phase:** The linker tries to connect the call to `myTemplate<int>()` from `main.o` with its definition. But the definition was never compiled (from step 2), so it doesn't exist.

**Result:** You get a linker error (like `unresolved external symbol`).

### Common Solutions

There are two primary ways to handle this.

#### Solution 1: The "Header-Only" Approach (Most Common)

Put the entire template definition (declaration and implementation) in the header file (`.hpp`).

**MyArray.hpp**

```cpp
#pragma once

template<typename T>
class MyArray {
public:
    MyArray(int size);
    T& get(int index);
private:
    T* m_data;
};

// --- Implementation ---
// Yes, you put the implementation right in the header.
template<typename T>
MyArray<T>::MyArray(int size) {
    m_data = new T[size];
}

template<typename T>
T& MyArray<T>::get(int index) {
    return m_data[index];
}
```

#### Solution 2: The .tpp File (A Convention for Cleanliness)

If your header file gets too long, you can move the implementation to a separate file, (conventionally named `.tpp` or `.inl`).

**Crucially, you must `#include` this `.tpp` file at the bottom of your `.hpp` file.**

**MyArray.hpp**

```cpp
#pragma once

template<typename T>
class MyArray {
public:
    MyArray(int size);
    T& get(int index);
private:
    T* m_data;
};

// Include the implementation file at the end of the header
#include "MyArray.tpp"
```

**MyArray.tpp**

```cpp
// No header guard or #includes needed here

template<typename T>
MyArray<T>::MyArray(int size) {
    m_data = new T[size];
}

template<typename T>
T& MyArray<T>::get(int index) {
    return m_data[index];
}
```

To the compiler, this is exactly the same as Solution 1. It just copies and pastes the `.tpp` content into the `.hpp` file before compiling. It is purely for code organization.

---

## 5. Key Resources

* **ISO C++ FAQ:** [Why can't I separate the definition of my templates class from its declaration and put it in a .cpp file?](https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl) (The canonical answer)

* **cppreference:** [Templates](https://en.cppreference.com/w/cpp/language/templates) (The definitive technical reference)

* **Learn C++:** [Template classes](https://www.learncpp.com/) (A great tutorial)