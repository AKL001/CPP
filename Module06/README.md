# C++ Casting Reference

## static_cast
**Purpose:** Safe, compile-time type conversion when you know the types involved.

**When to use:**
- Converting between related numeric types
- Converting pointers along an inheritance hierarchy (upcast/downcast)
- Explicit conversions that would normally be implicit

**Example:**
```cpp
double pi = 3.14;
int rounded = static_cast<int>(pi);  // 3

Base* base = new Derived();
Derived* derived = static_cast<Derived*>(base);  // Downcast
```

---

## const_cast
**Purpose:** Add or remove `const` qualifier from a variable.

**When to use:**
- Working with legacy APIs that don't use `const` correctly
- Rare cases where you need to modify a const object (use cautiously!)

**Example:**
```cpp
const int x = 10;
int* ptr = const_cast<int*>(&x);  // Remove const
*ptr = 20;  // Undefined behavior - avoid this!

// More common use case:
void legacyFunction(char* str);  // Old API without const

const char* myStr = "Hello";
legacyFunction(const_cast<char*>(myStr));  // Remove const for compatibility
```

---

## reinterpret_cast
**Purpose:** Low-level reinterpretation of bit patterns. Dangerous and platform-dependent.

**When to use:**
- Converting between pointers and integers
- Converting between unrelated pointer types
- Low-level memory manipulation

**Example:**
```cpp
// Basic usage: pointer to integer
int x = 42;
int* ptr = &x;
uintptr_t address = reinterpret_cast<uintptr_t>(ptr);  // Pointer to integer

// Reading memory as raw bytes
int value = 0x12345678;
char* bytes = reinterpret_cast<char*>(&value);
// Access individual bytes of the integer

// Advanced: Bypassing encapsulation (dangerous!)
class SecretData {
private:
    int secret1 = 100;
    int secret2 = 200;
    double secret3 = 3.14;
public:
    // No getters - data is private
};

SecretData obj;
char* rawBytes = reinterpret_cast<char*>(&obj);

// Read private members as raw bytes
for (size_t i = 0; i < sizeof(SecretData); i++) {
    // Access byte by byte: rawBytes[i]
}

// Even more dangerous: reinterpret as array of ints
int* asInts = reinterpret_cast<int*>(&obj);
// asInts[0] = secret1, asInts[1] = secret2 (platform-dependent!)

// Network programming: serialize objects
struct Packet {
    uint32_t id;
    uint16_t length;
    char data[256];
};

Packet packet;
unsigned char* buffer = reinterpret_cast<unsigned char*>(&packet);
// Send buffer over network: send(socket, buffer, sizeof(Packet), 0);
```

---

## dynamic_cast
**Purpose:** Safe runtime casting for polymorphic types (classes with virtual functions).

**When to use:**
- Downcasting in inheritance hierarchies when you're unsure of the actual type
- Type checking at runtime
- Returns `nullptr` if cast fails (for pointers)

**Example:**
```cpp
class Base { virtual void func() {} };
class Derived1 : public Base { void feature1() {} };
class Derived2 : public Base { void feature2() {} };

Base* basePtr = new Derived1();

// Safe downcast with runtime check
Derived1* d1 = dynamic_cast<Derived1*>(basePtr);
if (d1) {
    d1->feature1();  // Success!
}

Derived2* d2 = dynamic_cast<Derived2*>(basePtr);
if (!d2) {
    // Cast failed - basePtr wasn't pointing to Derived2
}
```

---

## Quick Comparison

| Cast Type | Safety | When Checked | Use Case |
|-----------|--------|--------------|----------|
| `static_cast` | Medium | Compile-time | Known type conversions |
| `const_cast` | Low | Compile-time | Modifying const-ness |
| `reinterpret_cast` | Very Low | None | Low-level bit manipulation |
| `dynamic_cast` | High | Runtime | Polymorphic downcasting |



# 🎯 C++ Casting: Upcast vs Downcast

Quick reference for `static_cast` and `dynamic_cast` with polymorphism rules.

---

## ✅ Upcasting (Derived → Base)
- Always **safe** — derived contains base
- Enables polymorphism

```cpp
Derived* d = new Derived();
Base* b = d; // ✅ safe upcast
```

---

## ⚠️ Downcasting (Base → Derived)
**Risky** — base pointer may not actually point to derived object

### `static_cast` (Compile-time)
- No runtime check — compiler trusts you
- **Wrong cast = UB/crash**

```cpp
Base* b = new Derived();
Derived* d = static_cast<Derived*>(b); // ✅ works (if correct)

Base* b2 = new Base();
Derived* d2 = static_cast<Derived*>(b2); // ❌ UB!
```

### `dynamic_cast` (Runtime)
- Requires virtual function in base (RTTI)
- Returns `nullptr` if wrong type → **safe**

```cpp
Base* b = new Base();
Derived* d = dynamic_cast<Derived*>(b); // ✅ d == nullptr (safe)
```

**How it works:** Uses vtable RTTI to verify actual type at runtime

---

## 📌 Rule
- **Upcast:** Always safe
- **Downcast with `static_cast`:** Fast but dangerous — use only when certain
- **Downcast with `dynamic_cast`:** Safe but requires virtual functions