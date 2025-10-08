# C++ Concepts Reference

## Ad-Hoc Polymorphism

Ad-hoc polymorphism allows different function implementations to be selected based on argument types at compile time.

### 1. Function Overloading

Function overloading allows multiple functions with the same name but different parameter types or counts.

```cpp
int add(int a, int b) {
    cout << "int version\n";
    return a + b;
}

double add(double a, double b) {
    cout << "double version\n";
    return a + b;
}
```

### 2. Operator Overloading

Operator overloading redefines how operators (+, -, ==, etc.) work for user-defined types.

```cpp
class Complex {
    double real, imag;
public:
    Complex(double r, double i): real(r), imag(i) {}

    // Overload '+' operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2.5, 3.0);
    Complex c2(1.5, 2.0);
    Complex sum = c1 + c2; // Invokes overloaded '+'
    sum.display();
}
```

## Types of Polymorphism Comparison

| Type                        | Example                       | When Decided | How It Works                                       |
| --------------------------- | ----------------------------- | ------------ | -------------------------------------------------- |
| **Ad-hoc polymorphism**     | Function/operator overloading | Compile-time | Multiple implementations, chosen by argument types |
| **Parametric polymorphism** | Templates                     | Compile-time | One generic code for all types                     |
| **Subtype polymorphism**    | Virtual functions             | Runtime      | Derived classes override base class functions      |

## Copy Constructor

A copy constructor creates a new object as a copy of an existing object.

**Syntax:**
```cpp
ClassName(const ClassName& name) {}
```

**Usage:**
```cpp
Class f = g;  // Equivalent to: f(g)
```

## Overloading the Assignment Operator

The assignment operator allows you to define custom behavior when assigning one object to another.

**Syntax:**
```cpp
ClassName& operator=(const ClassName& ref) {
    // Implementation
    return *this;
}
```

**Usage:**
```cpp
f = g;  // Equivalent to: f.operator=(g)
```

## Fixed-Point vs Floating-Point Representation

### Fixed-Point Format

Fixed-point numbers have a fixed decimal point position determined at design time.

**Example format:** `00000000.000` (8 bits integer, 3 bits fraction)

**Key characteristics:**
- No exponent (the decimal point cannot move)
- Position of decimal point is decided at design time

```cpp
// Store numbers as fixed-point with 8 fractional bits
int x = 3 << 8;        // 3.0 - reserve 8 bits for fractional part by shifting left
int y = 0.5 * 256;     // 0.5 - multiply by 2^8 to scale the fractional value
int result = x + y;    // 3.5 in fixed-point representation
```

### Floating-Point Format

#### IEEE 754 Single Precision (32-bit)

**Format:** `Sign (1 bit) | Exponent (8 bits) | Mantissa (23 bits)`

**Formula:** value = (-1)^sign × 1.mantissa × 2^(exponent - 127)

**Example:**
```
0 | 10000001 | 01110000000000000000000
```

#### IEEE 754 Double Precision (64-bit)

**Format:** `Sign (1 bit) | Exponent (11 bits) | Mantissa (52 bits)`

**Formula:** value = (-1)^sign × 1.mantissa × 2^(exponent - 1023)

**Example:**
```
0 | 10000000001 | 0111000000000000000000000000000000000000000000000000
```


#### ⚙️ **Special Values**

| Exponent (E) | Mantissa (M) | Meaning |
|---------------|---------------|----------|
| 0 | 0 | **±0** |
| 0 | ≠ 0 | **Subnormal number** (very small values close to 0) |
| 2047 (all 1s) | 0 | **±Infinity** |
| 2047 (all 1s) | ≠ 0 | **NaN** (Not a Number) |

---

#### 💡 Notes

- **Sign bit (S)** → `0` = positive, `1` = negative  
- **Exponent bias** → 1023 (so actual exponent = stored exponent − 1023)  
- **Mantissa** → represents fractional binary digits after the leading 1 (implicit)  

---

#### 🔹 **Single Precision (32-bit)** — quick reference

| Field | Bits | Bias |
|--------|------|------|
| Sign | 1 | — |
| Exponent | 8 | 127 |
| Mantissa | 23 | — |

**Formula:**

```value = (-1)^sign × 1.mantissa × 2^(exponent - 127)```

> 🧠 Floating-point numbers use **base-2 scientific notation** (`1.xxxxx × 2^n`)  
> to efficiently represent both **very large** and **very small** values using limited bits.
