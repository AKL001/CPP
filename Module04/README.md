# C++ Polymorphism & Abstract Classes - Quick Reference

## 1. Subtype Polymorphism

**What it is:** Achieved through inheritance and virtual functions. When a base class has a virtual function, derived classes can override it. The correct function is determined at runtime using a virtual table pointer (vptr).

```cpp
class Animal {
public:
    virtual void makeSound() { cout << "Some sound"; }
    virtual ~Animal() {}  // Always virtual!
};

class Dog : public Animal {
public:
    void makeSound() override { cout << "Woof!"; }
};

// Usage
Animal* pet = new Dog();
pet->makeSound();  // Calls Dog::makeSound() at runtime
delete pet;        // Calls Dog destructor, then Animal destructor
```

**Why use it:**
- Runtime flexibility - decide behavior dynamically
- Extensibility - add new types without modifying existing code

**Key Notes:**
- ✅ Always make base class destructor virtual when using polymorphism
- ✅ Polymorphism works with **pointers and references**, not value types
- **Dynamic binding** (runtime) vs **Static binding** (compile-time)
- The vptr ensures the correct destructor chain is called at runtime

---

## 2. Abstract Base Classes & Interfaces

**Abstract Base Class (ABC):** Cannot instantiate directly. Must derive from it and implement pure virtual functions.

**Pure Virtual Function:** Declared with `= 0`, must be overridden in derived classes.

```cpp
// Abstract Base Class
class Shape {
public:
    virtual double area() = 0;      // Pure virtual
    virtual void draw() { }         // Regular virtual (optional override)
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    double area() override { return 3.14 * r * r; }
private:
    double r = 1.0;
};
```

### Override vs Redefine

| Term | Meaning |
|------|---------|
| **Override** | Implement a virtual function in a subclass |
| **Redefine** | Implement a non-virtual function (no polymorphism) |

### Virtual vs Pure Virtual

| `virtual` | `virtual ... = 0` (Pure Virtual) |
|-----------|----------------------------------|
| Can be overridden | Must be overridden |
| Base class can be instantiated | Base class becomes abstract |

### Interface vs Abstract Class

```cpp
// Interface (pure contract)
class IDrawable {
public:
    virtual void draw() = 0;
    virtual ~IDrawable() {}
};

// Abstract Class (partial implementation)
class Shape {
protected:
    int id;  // Can have data members
public:
    virtual double area() = 0;           // Pure virtual
    void setID(int i) { id = i; }        // Concrete method
    virtual ~Shape() {}
};
```

| Interface | Abstract Class |
|-----------|----------------|
| Only pure virtual functions | At least one pure virtual function |
| No data members | Can have data members |
| No implemented methods | Can have implemented methods |

---

## Quick Rules
- 🔴 Abstract class = has ≥1 pure virtual function
- 🔴 Can't instantiate abstract classes
- 🟢 Can use pointers/references to abstract types
- 🟢 Derived classes must implement all pure virtual functions to be instantiable