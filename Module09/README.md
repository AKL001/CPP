# C++ Implementation Guide

This README provides implementation details for two algorithms: **RPN (Reverse Polish Notation) Calculator** and **Ford-Johnson Merge-Insertion Sort**.

---

## Table of Contents
- [RPN Calculator](#rpn-calculator)
- [Ford-Johnson Sort Algorithm](#ford-johnson-sort-algorithm)
- [Testing Commands](#testing-commands)

---

## RPN Calculator

### Overview
RPN is a mathematical notation where operators follow their operands. For example, `3 4 +` equals `7`.

### Implementation Strategy

**Basic Algorithm:**
1. Use a stack (or any container like `std::vector` or `std::deque`)
2. When you encounter a **number**, push it onto the stack
3. When you encounter an **operator**, pop two numbers, calculate the result, and push it back
4. Continue until the expression is fully evaluated

### Validation Rule

The key to parsing RPN correctly is tracking **depth**:
- **Depth** = number of operands currently available
- For each operator encountered, depth must be **at least 2** (since operators work on 2 operands)
- Final validation: `number_of_numbers = number_of_operators + 1`

**Why?** Each operator consumes 2 operands and produces 1 result, so you always need one more number than operators.

### Example

```
Input: 3 4 + 2 *

Step-by-step:
1. Push 3           → Stack: [3]
2. Push 4           → Stack: [3, 4]
3. Operator '+'     → Pop 4, 3 → Calculate 3+4=7 → Push 7 → Stack: [7]
4. Push 2           → Stack: [7, 2]
5. Operator '*'     → Pop 2, 7 → Calculate 7*2=14 → Push 14 → Stack: [14]

Result: 14
```

### Edge Cases
- **Invalid**: `3 + 4` (operator comes before having 2 operands)
- **Invalid**: `3 4 5 +` (too many operands, depth check fails)
- **Valid**: `3 4 + 5 *` (valid RPN expression)

---

## Ford-Johnson Sort Algorithm

The Ford-Johnson algorithm (also called **merge-insertion sort**) minimizes comparisons by strategically pairing, sorting, and inserting elements.

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/c5/Merge-insertion_sort_example.svg/800px-Merge-insertion_sort_example.svg.png" alt="Ford-Johnson visualization" width="500"/>

### Step-by-Step Breakdown

#### Step 1: Pair Elements
- Group your input into pairs of 2 elements
- If there's an **odd element** left over, store it separately (we'll handle it at the end)

**Example:**
```
Input: [5, 9, 1, 3, 7]
Pairs: (5, 9), (1, 3)
Straggler: 7
```

#### Step 2: Organize Pairs
- Within each pair, identify the **larger** element (call it the "winner")
- Create two lists:
  - **Main chain**: all winning (larger) elements from each pair
  - **Pending chain**: all losing (smaller) elements, aligned with their pair partners

**Example:**
```
Pairs: (5, 9), (1, 3)

Main chain:    [9, 3]
Pending chain: [5, 1]
```

#### Step 3: Recursive Sort (on Main Chain)
- Take the **main chain** and recursively apply the same algorithm
- **Base case**: when you have only 1 element, return it (already sorted)
- This ensures the main chain becomes sorted

**Example:**
```
Main chain: [9, 3]
Recursively sort → [3, 9]
Pending chain: [1, 5]  (aligned with original pairs)
```

After recursion returns:
```
Main chain: [3, 9]
Pending:    [1, 5]
```

#### Step 4: Insert First Pending Element (b₁)
- The first element in the pending chain (`b₁`) is **guaranteed** to be smaller than the first element in the main chain (`a₁`)
- Insert `b₁` before `a₁` in the main chain
- **Keep** `b₁` in the pending list for Jacobsthal indexing

**Example:**
```
Before: Main = [3, 9], Pending = [1, 5]
After:  Main = [1, 3, 9], Pending = [1, 5]
```

#### Step 5: Insert Remaining Elements Using Jacobsthal Sequence
The Jacobsthal sequence determines the optimal insertion order to minimize comparisons:

**Jacobsthal numbers:** 1, 3, 5, 11, 21, 43, 85...

**Insertion strategy:**
- Skip the first pending element (already inserted in Step 4)
- Use Jacobsthal indices to determine insertion order
- For Jacobsthal number `J(k)`:
  - Insert elements from index `J(k)` down to `J(k-1) + 1` (in reverse)
  - If pending list is smaller, insert remaining elements in reverse order

**Example with Jacobsthal:**
```
Pending = [1, 5, 8, 12]  (excluding already-inserted b₁)
Jacobsthal: 3, 5, 11...

1. J(1) = 3: Insert index 3 down to 2 → Insert pending[2], then pending[1]
2. J(2) = 5: Since pending has only 4 elements, insert pending[3]
```

Use **binary search** (or `std::lower_bound`) to find the correct position for each insertion.

#### Step 6: Insert the Straggler
- If there was an odd element left over from Step 1, insert it using binary search
- This is the only potentially expensive comparison

---

### Visual Example

```
Input: [5, 9, 1, 3, 7]

Step 1-2: Pairing
(5, 9), (1, 3), straggler=7
Main: [9, 3]
Pend: [5, 1]

Step 3: Recursively sort main chain
Main: [3, 9]
Pend: [1, 5]  (realigned)

Step 4: Insert b₁
Main: [1, 3, 9]

Step 5: Insert pending[1]=5 using binary search
Main: [1, 3, 5, 9]

Step 6: Insert straggler=7 using binary search
Main: [1, 3, 5, 7, 9]

Final sorted: [1, 3, 5, 7, 9]
```

---

## Testing Commands

### Quick Sort Verification

Test if your implementation produces sorted output:

```bash
# Test with small input
./PmergeMe 3 5 9 7 4 | grep "After" | python3 -c "import sys; line = sys.stdin.read().split()[1:]; nums = [int(n) for n in line]; print('Sorted:', nums == sorted(nums))"

# Test with large random input (3000 numbers)
./PmergeMe `shuf -i 1-1000000 -n 3000 | tr "\n" " "` | grep "After" | python3 -c "import sys; line = sys.stdin.read().split()[1:]; nums = [int(n) for n in line]; print('Sorted:', nums == sorted(nums))"
```

### Alternative: File-based Verification

```bash
# Save output to file
./PmergeMe 5 2 3 1 4 | grep "After" | cut -d ':' -f 2 | tr ' ' '\n' | grep -v "^$" > output.txt

# Large input test
./PmergeMe `shuf -i 1-1000000 -n 30000 | tr "\n" " "` | grep "After" | cut -d ':' -f 2 | tr ' ' '\n' | grep -v "^$" > output.txt

# Check if sorted
sort -n -c output.txt
```

If `sort -n -c` returns nothing, the output is correctly sorted. Any error message indicates incorrect sorting.

---

## Implementation Notes

- Both algorithms work with standard containers (`std::vector`, `std::deque`, `std::list`)
- For Ford-Johnson, use `std::lower_bound` for binary insertion if your container supports it
- RPN requires constant depth tracking to validate expressions before evaluation
- Ford-Johnson's efficiency comes from the Jacobsthal sequence minimizing comparisons

---

## References

- [Reverse Polish Notation - Wikipedia](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
- [Ford-Johnson Algorithm - Wikipedia](https://en.wikipedia.org/wiki/Merge-insertion_sort)
- [Jacobsthal Sequence](https://en.wikipedia.org/wiki/Jacobsthal_number)