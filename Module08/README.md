+++Containers:
+std::vector -> dynamic array , start at a memory point and when it all filled up , it reallocat all to another block , and keeps going , memory of an index could changes , if we changed in the array meaning if added some thing in the back or front

+std::list -> double linked list 

+std::deque -> (double ended q) its like a vector and list at the same time , so the pointer is not changed , like having multiple blocks of memory adjustable, we only allocat a new block if needed , pointer are the same , memory of an index doesnt change

+std::set -> sorts the insertions , also doesnt duplicate the data 
+std::unordred_set -> doesnt sort the insertion 

+++Iterators:

// aranged based for loops C++11
    for (int <name> : <array u want to interat>)
        // 
// just like the above look but with iterators
for (std::vector<int>::iterator it = value.begin(); it != value.end() ; it++)
{
    // it is a pointer 
    *it;
}

Iterator  is a smart pointer:
    1- points to a specific element in the container 

when would interator help us , example :
    vector when it switch block we can just use 

NOTES:
    +What is an Iterator : iterator is an object that points to an element inside a container (vector , list , deque , map .....).
    +Iterators provide a universal interface. They act as a bridge between Containers (data) and Algorithms (functions).
    Iterators are categories:
        - output_iterator => write-only stream, u can only write to it,
            you cannot read from  it (value = *it) , movement ++ only step at a time ,
        - forward_iterator
        -bidirectional_iterator
        -random_access_iterator => most powerfull iterators , it behave exactly  like c-style pointer :
            - can read and write 
            - can jump anywehere
            - 
        -iterator
<iterator>::distance -> calculate the istance between first and last

Quick Summary table: 
Iterator Type,Read,Write,Direction,Jump (+N),Example Container
Output,No,Yes,Forward,No,back_inserter
Input,Yes,No,Forward,No,istream_iterator
Forward,Yes,Yes,Forward,No,forward_list
Bidirectional,Yes,Yes,Fwd / Back,No,"list, map, set"
Random Access,Yes,Yes,Fwd / Back,Yes,"vector, deque"


<algorithm>
```
Algorithms (Function Templates) - <algorithm>
These are the functions that operate on ranges of iterators (begin, end).

A. Non-Modifying (Read-Only)
for_each: Apply a function to every element.

find: Find the first element matching a value.

find_if: Find the first element matching a predicate (condition).

count: Count occurrences of a value.

count_if: Count occurrences matching a predicate.

mismatch: Find the first position where two ranges differ.

equal: Check if two ranges are identical.

search: Search for a subsequence within a sequence.

find_end: Find the last occurrence of a subsequence.

find_first_of: Find the first occurrence of any element from a set.

adjacent_find: Find two identical adjacent elements.

B. Modifying (Changes Data)
copy: Copy a range to another location.

copy_backward: Copy starting from the end.

swap: Exchange two values.

iter_swap: Exchange values pointed to by two iterators.

transform: Apply a function to elements and store the result.

replace: Replace all instances of a value.

replace_if: Replace elements matching a condition.

fill: Fill a range with a specific value.

fill_n: Fill N elements with a value.

generate: Fill a range using a generator function.

remove: Remove elements (logically, by shifting them).

remove_if: Remove elements matching a condition.

unique: Remove consecutive duplicates.

reverse: Reverse the order of elements.

rotate: Rotate elements (shift left/right).

random_shuffle: Randomly reorder elements (Note: C++98 specific; removed in C++17).

C. Sorting & Ordering
sort: Sort elements (usually Quicksort/Introsort).

stable_sort: Sort preserving order of equal elements (Merge sort).

partial_sort: Sort only the top N elements.

nth_element: Put the nth element in its sorted position (everything before is smaller).

D. Binary Search (On Sorted Ranges)
lower_bound: First element not less than value.

upper_bound: First element greater than value.

equal_range: Returns pair {lower_bound, upper_bound}.

binary_search: Returns true if value exists.

E. Set Operations (On Sorted Ranges)
includes: Check if one set is a subset of another.

set_union: Combine two sets.

set_intersection: Keep only elements found in both.

set_difference: Elements in Set A but not in Set B.

set_symmetric_difference: Elements in either A or B, but not both (XOR).

F. Heap Operations
make_heap: Turn a range into a heap.

push_heap: Add element to heap.

pop_heap: Remove top element from heap.

sort_heap: Sort the heap.

G. Min/Max
min / max: Return the smaller/larger of two values.

min_element: Find the smallest element in a range.

max_element: Find the largest element in a range.

lexicographical_compare: Compare two ranges like words in a dictionary.

H. Permutations
next_permutation: Rearrange to the next lexicographical permutation.

prev_permutation: Rearrange to the previous permutation.

3. Numeric Algorithms - <numeric>
accumulate: Sum up a range (or fold with custom op).

inner_product: Dot product of two ranges.

adjacent_difference: Compute difference between neighboring elements.

partial_sum: Running total (prefix sum).
```


for the stack container we can change the default underlying container for 
stack (deque)

```
// Uses std::deque (the default)
std::stack<int> s1; 

// Explicitly use std::vector
std::stack<int, std::vector<int>> s2; 

// Explicitly use std::list
std::stack<int, std::list<int>> s3;
``` 