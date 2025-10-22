# C++ Inheritance - Quick Reference

## Types of Inheritance

```cpp
// 1. Single Inheritance
class Base { };
class Derived : public Base { };

// 2. Multiple Inheritance
class A { };
class B { };
class C : public A, public B { };

// 3. Multilevel Inheritance
class A { };
class B : public A { };
class C : public B { };

// 4. Hierarchical Inheritance
class Base { };
class Derived1 : public Base { };
class Derived2 : public Base { };

// 5. Hybrid Inheritance (combination of above)
class A { };
class B : public A { };
class C : public A { };
class D : public B, public C { };  // Diamond problem!
```

---

## Key Terms

- **Base Class** (Parent): The class being inherited from
- **Derived Class** (Child): The class that inherits from base class

---

## Access Specifiers in Inheritance

| Inheritance Type | Base `public` becomes | Base `protected` becomes | Base `private` |
|------------------|----------------------|-------------------------|----------------|
| **public** | `public` | `protected` | Not accessible |
| **protected** | `protected` | `protected` | Not accessible |
| **private** | `private` | `private` | Not accessible |

```cpp
class Base {
public:
    int pub;
protected:
    int prot;
private:
    int priv;
};

class PublicDerived : public Base {
    // pub is public
    // prot is protected
    // priv is not accessible
};

class ProtectedDerived : protected Base {
    // pub is protected
    // prot is protected
    // priv is not accessible
};

class PrivateDerived : private Base {
    // pub is private
    // prot is private
    // priv is not accessible
};
```

---

## Virtual Destructor

**Rule:** Always use a virtual destructor in the base class when using polymorphism.

```cpp
class Base {
public:
    virtual ~Base() { }  // Virtual destructor
};

class Derived : public Base {
public:
    ~Derived() { }  // Called correctly via dynamic dispatch
};

// Usage
Base* ptr = new Derived();
delete ptr;  // Calls Derived destructor, then Base destructor
```

**Why?** C++ uses **dynamic dispatch** (runtime polymorphism) to find the actual destructor of the object type — even if the pointer is of base type.

---

## The Diamond Problem

Occurs when two superclasses of a class have a common base class.

```cpp
class Person {
public:
    string name;
};

class Student : public Person { };
class Employee : public Person { };

class TA : public Student, public Employee {
    // Problem: TA gets TWO copies of 'name' from Person
    // Causes ambiguities!
};

// Solution: Virtual inheritance
class Student : virtual public Person { };
class Employee : virtual public Person { };
class TA : public Student, public Employee {
    // Now TA has only ONE copy of Person
};
```

---

## Dynamic Dispatch & Virtual Tables

### How Virtual Functions Work

```cpp
class Base {
public:
    virtual void method() { }
};

class Child : public Base {
public:
    void method() override { }  // Override keyword is important!
};
```

**Without `override`:**
- Compiler doesn't create a new virtual method entry for the child class
- The vptr (virtual pointer table) points to the parent class virtual table

**With `override`:**
- Compiler creates a new child virtual table
- Contains `Child::method()` entry
- Dynamic dispatch works correctly at runtime

### Key Points

- ✅ **We can only override virtual functions**
- ✅ Use `override` keyword to ensure correct dynamic dispatch
- ✅ Without `override`, the child's vptr points to parent's vtable
- ✅ With `override`, the child gets its own vtable with updated function pointers

```cpp
Base* ptr = new Child();
ptr->method();  // Calls Child::method() if overridden correctly
```

---

## Quick Rules

- 🔴 Always make base class destructor virtual when using inheritance
- 🔴 Use virtual inheritance to solve diamond problem
- 🟢 Use `override` keyword for clarity and correctness
- 🟢 Only virtual functions can be overridden
- 🟢 Dynamic dispatch happens at runtime, static dispatch at compile-time
