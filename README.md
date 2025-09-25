# C++ Modules Notes

> This repository contains my personal notes and learning materials for C++ modules. Each module is organized in its own directory with a dedicated README file that contains my notes for that specific module.

---

## Module 00 – Basics
- C++ `static_cast` are checked by the compiler. `C style casts`  aren't and can fail at runtime.
- C++ `dynamic_cast` can fail at runtime.
- C++ `reinterpret_cast` tells the compiler to threat a value of one type to another type with out changing the undelying bits in memory  , we can read an object as block of memory . despite if the member is private or not. (its a low level cast , and also carefull to use it)
- C++ style cast are checked at compiling time , most like C-types cast (but dynamic cast and reinterpret_cast are not actualy may cuz  SEGFAULT) 
- use `std::endl` for debuging or log file.
- `std::endl` prints a new line and flushes the stream buffer.
- `std::'\n'` Adds a newline, but does not flush the buffer.Faster, preferred in performance-critical code.
- 'int &ref = x' This is like another name for 'x'
- 'instance' of class is the object 
- 'class' is a blueprint of an object , in another word how we gonna create that object
- 'static members' are created once , and stored in static memory area
- 'static methods' can only access static variables from memeory 
- namespace && using namespace : (using namespace math;) -> we call "add()" without "math::add"
- using namespace: import all names from x;
- using : brings one specific name like : (using std::string) -> "string" instead of "std::string"
- using N::foo ; import only foo from N; 


---

## Module 01 – Functions & Program Structure
- [ ]  

---

## Module 02 – Strings & Memory
- [ ]  

---

## Module 03 – Classes & Encapsulation
- [ ]  

---

## Module 04 – Operator Overloading
- [ ]  

---

## Module 05 – Inheritance & Polymorphism
- [ ]  

---

## Module 06 – Templates & Exceptions
- [ ]  

---

## Module 07 – STL Containers & Algorithms
- [ ]  

---

## Module 08 – Advanced OOP & Projects
- [ ]  

---
