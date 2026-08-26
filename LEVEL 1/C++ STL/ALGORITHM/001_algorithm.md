# C++ STL Algorithms (`<algorithm>`) – Complete Notes

## Part 1 – Introduction

- What are STL Algorithms?
- Why use STL Algorithms?
- Header Files (`<algorithm>`, `<numeric>`)
- Categories of Algorithms
- Iterator Requirements
- Time Complexity Basics
- Function Objects (Functors)
- Lambda Expressions
- Predicates
- Binary Predicates
- Comparator Functions
- Execution Policies (C++17)
- `std::invoke`
- Value Categories used in Algorithms
- Algorithm Naming Convention

---

## Part 2 – Non-Modifying Sequence Algorithms

Every function in full detail.

- for_each()
- for_each_n() (C++17)
- all_of()
- any_of()
- none_of()
- count()
- count_if()
- mismatch()
- equal()
- is_permutation()
- search()
- search_n()
- find()
- find_if()
- find_if_not()
- find_end()
- find_first_of()
- adjacent_find()

Each topic includes

- Definition
- Syntax
- Parameters
- Return Type
- Internal Working
- Complexity
- Examples
- Common Mistakes
- Interview Questions

---

## Part 3 – Modifying Sequence Algorithms

Complete details of

- copy()
- copy_if()
- copy_n()
- copy_backward()
- move()
- move_backward()
- swap()
- swap_ranges()
- iter_swap()
- transform()
- replace()
- replace_if()
- replace_copy()
- replace_copy_if()
- fill()
- fill_n()
- generate()
- generate_n()
- remove()
- remove_if()
- remove_copy()
- remove_copy_if()
- unique()
- unique_copy()
- reverse()
- reverse_copy()
- rotate()
- rotate_copy()
- shuffle()
- sample()

---

## Part 4 – Partitioning Algorithms

- partition()
- stable_partition()
- partition_copy()
- partition_point()
- is_partitioned()

Including

- Stable vs Unstable
- Internal Working
- Complexity
- Examples

---

## Part 5 – Sorting Algorithms

Complete details

- sort()
- stable_sort()
- partial_sort()
- partial_sort_copy()
- nth_element()
- is_sorted()
- is_sorted_until()

Topics include

- Introsort
- Quick Sort
- Heap Sort
- Insertion Sort
- Stable Sorting
- Custom Comparator
- Descending Sort
- Pair Sorting
- Structure Sorting
- Lambda Comparator
- Complexity Analysis

---

## Part 6 – Binary Search Algorithms

Complete details

- binary_search()
- lower_bound()
- upper_bound()
- equal_range()

Includes

- Prerequisites
- Sorted Containers
- Iterator Requirements
- Complexity
- Applications
- Competitive Programming Tricks

---

## Part 7 – Heap Algorithms

- make_heap()
- push_heap()
- pop_heap()
- sort_heap()
- is_heap()
- is_heap_until()

Includes

- Binary Heap
- Max Heap
- Min Heap
- Heap Visualization
- Internal Working

---

## Part 8 – Set Algorithms

Works on sorted ranges

- includes()
- set_union()
- set_intersection()
- set_difference()
- set_symmetric_difference()
- merge()
- inplace_merge()

Includes diagrams and examples.

---

## Part 9 – Min/Max & Numeric Algorithms

### Min/Max

- min()
- max()
- minmax()
- min_element()
- max_element()
- minmax_element()
- clamp() (C++17)
- lexicographical_compare()

### Permutations

- next_permutation()
- prev_permutation()

### Numeric (`<numeric>`)

- accumulate()
- reduce()
- inner_product()
- partial_sum()
- adjacent_difference()
- inclusive_scan()
- exclusive_scan()
- transform_reduce()
- transform_inclusive_scan()
- transform_exclusive_scan()
- gcd()
- lcm()
- iota()

---

## Part 10 – Advanced Topics

### Custom Comparators

- Functions
- Lambda
- Functors

### Predicates

- Unary Predicate
- Binary Predicate

### Function Objects

- greater<>
- less<>
- logical_and<>
- logical_or<>

### Execution Policies (C++17)

- seq
- par
- par_unseq
- unseq

### Iterator Categories

- Input Iterator
- Output Iterator
- Forward Iterator
- Bidirectional Iterator
- Random Access Iterator

### Complexity Table

Every STL algorithm complexity.

---

## STL Algorithm Comparison Tables

- sort vs stable_sort
- copy vs move
- remove vs erase
- find vs binary_search
- lower_bound vs upper_bound
- reverse vs rotate
- make_heap vs priority_queue

---

## Applications

- Competitive Programming
- Searching
- Sorting
- Frequency Counting
- Data Processing
- Scheduling
- Graph Algorithms
- Dynamic Programming
- Greedy Algorithms

---

## Common Mistakes

- Forgetting sorted range for binary_search()
- remove() doesn't erase elements
- Wrong comparator
- Invalid iterators
- Iterator invalidation
- Using sort() on list
- Wrong lambda capture
- Using lower_bound() on unsorted data

---

## Interview Questions

- 100+ STL Algorithm Interview Questions
- Frequently asked coding interview patterns
- Complexity-based questions
- Internal implementation questions

---

## Complete Programs

- Frequency Counter
- Student Management System
- Sorting Structures
- Binary Search Examples
- Heap Examples
- Permutation Generator
- Duplicate Removal
- Interval Problems
- Competitive Programming Templates

---

## Revision Notes

- STL Algorithm Cheat Sheet
- Complexity Table
- Best Practices
- Quick Revision Notes
- Most Asked Interview Questions