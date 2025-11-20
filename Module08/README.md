# C++ Containers & Iterators Reference

A concise guide to C++ STL containers and iterators with practical insights.

---

## 📦 Containers

### Sequential Containers

**`std::vector`** - Dynamic Array
- Contiguous memory block that reallocates when full
- Fast random access, efficient push_back
- ⚠️ Memory addresses may change after reallocation

**`std::list`** - Doubly Linked List
- Non-contiguous memory, each element links to next/previous
- Fast insertion/deletion anywhere
- Stable pointers (addresses never change)

**`std::deque`** - Double-Ended Queue
- Hybrid: multiple memory blocks (chunks)
- Fast push/pop at both ends
- ✅ Stable pointers (no reallocation like vector)

### Associative Containers

**`std::set`** - Ordered Set
- Automatically sorts elements
- No duplicates allowed
- Binary tree implementation

**`std::unordered_set`** - Hash Set
- No automatic sorting
- No duplicates allowed
- Hash table implementation (faster lookup)

### Container Adapters

**`std::stack`** - LIFO Stack
- Default underlying container: `std::deque`
- Customizable with other containers:

```cpp
std::stack<int> s1;                          // Uses deque (default)
std::stack<int, std::vector<int>> s2;        // Uses vector
std::stack<int, std::list<int>> s3;          // Uses list
```

---

## 🔁 Iterators

### What Are Iterators?

Iterators are **smart pointers** that:
- Point to elements inside containers
- Provide a universal interface between containers and algorithms
- Act as a bridge between data structures and functions

### Range-Based For Loop (C++11+)

```cpp
for (int value : myVector) {
    // Direct access to element
}
```

### Iterator-Based Loop

```cpp
for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++) {
    *it;  // Dereference to access value (it is a pointer)
}
```

### Iterator Categories

| Iterator Type | Read | Write | Direction | Jump (+N) | Example Container |
|--------------|------|-------|-----------|-----------|-------------------|
| **Output** | ❌ | ✅ | Forward | ❌ | `back_inserter` |
| **Input** | ✅ | ❌ | Forward | ❌ | `istream_iterator` |
| **Forward** | ✅ | ✅ | Forward | ❌ | `forward_list` |
| **Bidirectional** | ✅ | ✅ | Both | ❌ | `list`, `map`, `set` |
| **Random Access** | ✅ | ✅ | Both | ✅ | `vector`, `deque` |

**Random Access Iterators** are the most powerful:
- Behave like C-style pointers
- Support arithmetic operations (`it + 5`, `it - 3`)
- Allow direct indexing

### Useful Iterator Functions

```cpp
std::distance(first, last);  // Calculate distance between iterators
```

---

## 💡 Key Takeaways

- Use **`vector`** for general-purpose dynamic arrays
- Use **`deque`** when you need stable pointers with dynamic sizing
- Use **`list`** for frequent insertions/deletions in the middle
- Use **`set`** for sorted, unique elements
- Use **`unordered_set`** for fast lookup without ordering
- Iterators provide container-agnostic algorithms
- Random access iterators offer the most flexibility

---

## 📚 Further Reading

- [C++ Reference - Containers](https://en.cppreference.com/w/cpp/container)
- [C++ Reference - Iterators](https://en.cppreference.com/w/cpp/iterator)