# C++ Iterators — 100% Complete Notes

## Table of Contents

1. Introduction
2. What Is an Iterator?
3. Iterator as a Generalized Pointer
4. Why Iterators Are Needed
5. Pointer vs Iterator
6. Iterator Range
7. `begin()` and `end()`
8. `cbegin()` and `cend()`
9. Reverse Iterators
10. Iterator Declaration and Syntax
11. Dereferencing
12. Increment and Decrement
13. Iterator Comparison
14. Iterator Arithmetic
15. Iterator Categories
16. Input Iterator
17. Output Iterator
18. Forward Iterator
19. Bidirectional Iterator
20. Random Access Iterator
21. Contiguous Iterator
22. Iterator Category Hierarchy
23. STL Container Iterator Categories
24. `iterator`
25. `const_iterator`
26. `reverse_iterator`
27. `const_reverse_iterator`
28. `auto` with Iterators
29. `std::advance`
30. `std::next`
31. `std::prev`
32. `std::distance`
33. `std::iter_swap`
34. Iterator Utility Functions
35. Iterator Adapters
36. `back_inserter`
37. `front_inserter`
38. `inserter`
39. `istream_iterator`
40. `ostream_iterator`
41. Range-Based `for`
42. Algorithms and Iterator Ranges
43. Read/Write Access
44. Iterator Invalidation
45. Vector Invalidation
46. Deque Invalidation
47. List Invalidation
48. Forward List Invalidation
49. Map/Set Invalidation
50. Unordered Container Invalidation
51. Safe Erasing While Iterating
52. Custom Iterator
53. Iterator Traits
54. `iterator_traits`
55. `std::iterator` Historical Note
56. Iterator Concepts in C++20
57. `iterator_category`
58. `iterator_concept`
59. `sentinel`
60. `default_sentinel`
61. `common_iterator`
62. `counted_iterator`
63. `move_iterator`
64. `reverse_iterator`
65. Insert Iterators
66. Output Iterator Example
67. Input Iterator Example
68. Forward Iterator Example
69. Bidirectional Iterator Example
70. Random Access Iterator Example
71. Contiguous Iterator Example
72. Container-Specific Examples
73. Algorithms Commonly Used with Iterators
74. Sorting
75. Searching
76. Binary Search
77. Bounds
78. Copying
79. Transforming
80. Removing
81. Replacing
82. Partitioning
83. Numeric Algorithms
84. Iterator Complexity
85. Iterator Validity Rules
86. Common Mistakes
87. Correct Erase Pattern
88. Iterator vs Index
89. Iterator vs Pointer
90. Iterator vs Range
91. Iterators and Generic Programming
92. Iterators and Templates
93. Custom Container Iterator Design
94. Common Interview Questions
95. Quick Comparison Tables
96. Complete Example
97. Mental Model
98. Best Practices
99. Quick Revision
100. Final Summary

---

# 1. Introduction
- An **iterator** is an object used to traverse elements stored inside a container.

- The simplest way to think about an iterator is: `Iterator = Generalized Pointer`

An iterator can be used to:
- Access elements
- Traverse elements
- Modify elements when permitted
- Define ranges
- Connect containers to STL algorithms

**Example:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30};
    vector<int>::iterator it = v.begin();

    cout << *it;

    return 0;
}
```

Output: `10`

---

# 2. What Is an Iterator?

- An iterator represents a position in a sequence.

**Example:**

```text
+----+----+----+----+
| 10 | 20 | 30 | 40 |
+----+----+----+----+
  ^
  |
 iterator
```

The iterator can move through the sequence.

```text
10 20 30 40
^
|
it
```

After:

```cpp
++it;
```

it points to:

```text
10 20 30 40
   ^
   |
   it
```

---

# 3. Iterator as a Generalized Pointer

For an array:

```cpp
int arr[] = {10, 20, 30};

int* p = arr;

cout << *p;
```

For a vector:

```cpp
vector<int> v = {10, 20, 30};

auto it = v.begin();

cout << *it;
```

Both use:

```cpp
*
```

to access the element.

But an iterator is not necessarily a raw pointer.

For example:

```cpp
list<int>::iterator
```

is typically a class-like iterator object that internally navigates linked-list nodes.

---

# 4. Why Iterators Are Needed

Different STL containers use different internal data structures.

**Examples:**
- vector           → contiguous dynamic array
- deque            → segmented/block-based sequence
- list             → doubly linked list
- forward_list     → singly linked list
- map              → ordered tree
- set              → ordered tree
- unordered_map    → hash table

Without iterators, every algorithm would need container-specific implementations.

Instead, STL algorithms operate on iterator ranges:

```cpp
algorithm(begin, end);
```

Example:

```cpp
sort(v.begin(), v.end());
```

The algorithm does not need to know the internal details of the vector.

---

# 5. Pointer vs Iterator

| Feature | Pointer | Iterator |
|---|---|---|
| Represents position | Yes | Yes |
| Can dereference | Yes, when valid | Usually |
| Works with arrays | Yes | Yes, raw pointers qualify |
| Works with STL containers | Some contiguous containers | Yes, when supported |
| Arithmetic | Depends on pointer target | Depends on iterator category |
| Implementation | Language primitive | Provided by library/container |
| Generic STL abstraction | Limited | Yes |
| Can be a class object | Raw pointer is not a class object | Often yes |


**Important:**
> A raw pointer can satisfy iterator requirements in appropriate contexts, but an iterator does not have to be a pointer.

---

# 6. Iterator Range

STL algorithms normally use a half-open range:
```cpp
[first, last)
```

**This means:**
- first → included
- last  → excluded

**Example:**
```cpp
vector<int> v = {10, 20, 30, 40};

auto first = v.begin();
auto last = v.end();
```

The range is:

```text
10 20 30 40
^           ^
|           |
first       last
            one-past-end
```

The elements included are:

```text
10 20 30 40
```

The `last` iterator itself is not an element.

---

# 7. Why Does `end()` Point One Past the Last Element?

This makes loops simple:

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
{
    cout << *it << " ";
}
```

It also allows an empty range:

```cpp
begin() == end()
```

For an empty container:

```text
begin()
   |
   v
[ end ]
```

Both represent the same position.

---

# 8. `begin()`

`begin()` returns an iterator referring to the first element.

```cpp
vector<int> v = {10, 20, 30};

auto it = v.begin();

cout << *it;
```

Output: `10`

If the container is empty:

```cpp
v.begin() == v.end()
```

---

# 9. `end()`

`end()` returns the iterator representing the position immediately after the last element.

```cpp
auto it = v.end();
```

Do not dereference it:

```cpp
*it
```

This is undefined behavior.

Wrong:

```cpp
cout << *v.end();
```

Correct:

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
{
    cout << *it;
}
```

---

# 10. `cbegin()`

`cbegin()` returns a const iterator.

```cpp
vector<int> v = {10, 20, 30};

auto it = v.cbegin();

cout << *it;
```

Reading is allowed:

```cpp
cout << *it;
```

Modification through the iterator is not allowed:

```cpp
*it = 100;   // error
```

---

# 11. `cend()`

`cend()` returns the const iterator representing the end position.

```cpp
auto it = v.cend();
```

Like `end()`, it must not be dereferenced.

---

# 12. `rbegin()`

`rbegin()` returns a reverse iterator referring to the last element.

```cpp
vector<int> v = {10, 20, 30};

auto it = v.rbegin();

cout << *it;
```

Output: `30`


---

# 13. `rend()`

`rend()` represents the position before the first element when traversing in reverse.

```cpp
for (auto it = v.rbegin(); it != v.rend(); ++it)
{
    cout << *it << " ";
}
```

Output: `30 20 10`


Do not dereference `rend()`.

---

# 14. `crbegin()` and `crend()`

These return const reverse iterators.

```cpp
auto it = v.crbegin();
auto end = v.crend();
```

Example:

```cpp
for (auto it = v.crbegin(); it != v.crend(); ++it)
{
    cout << *it << " ";
}
```

---

# 15. Iterator Declaration

### Old-style explicit declaration:

```cpp
vector<int>::iterator it;
```

### Const iterator:

```cpp
vector<int>::const_iterator it;
```

## Reverse iterator:

```cpp
vector<int>::reverse_iterator it;
```

### Const reverse iterator:

```cpp
vector<int>::const_reverse_iterator it;
```

### Modern C++ usually prefers:

```cpp
auto it = v.begin();
```

---

# 16. Dereferencing an Iterator

Use: `*it`

Example:
```cpp
vector<int> v = {10, 20, 30};

auto it = v.begin();
cout << *it;
```

Output: `10`

For a mutable iterator:

```cpp
*it = 100;
```

can modify the element if the container permits it.

---

# 17. Increment

**Prefix increment:**
```cpp
++it;
```
- moves to the next position.

**Postfix increment:**
```cpp
it++;
```
- also moves to the next position.

For most traversal loops: `++it` is preferred.

---

# 18. Decrement

Bidirectional and stronger iterators can move backward:

```cpp
--it;
```

or:

```cpp
it--;
```

A forward iterator does not support decrement.

---

# 19. Iterator Comparison

Common operations:

```cpp
it1 == it2
it1 != it2
```

Example:

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
{
    cout << *it << " ";
}
```

Ordering comparisons such as:

```cpp
it1 < it2
```

are available only for iterator categories that support them, such as random-access iterators.

---

# 20. Iterator Arithmetic

Random-access iterators support:

```cpp
it + n
it - n
it += n
it -= n
it[n]
it2 - it1
```

Example:

```cpp
vector<int> v = {10, 20, 30, 40, 50};

auto it = v.begin();

cout << *(it + 2);
```

Output:

```text
30
```

**For a `list` iterator:** `it + 2` is not supported.

---

# 21. Iterator Categories

**C++ has six standard iterator categories/concepts:**
- Input
- Output
- Forward
- Bidirectional
- Random Access
- Contiguous

The traditional category hierarchy is:

```text
Input
   ↓
Forward
   ↓
Bidirectional
   ↓
Random Access
   ↓
Contiguous
```

`Output` is a separate write-oriented category.

Important:

> The C++20 iterator concepts formalize these capabilities more precisely than the older iterator-category tags.

---

# 22. Input Iterator

An input iterator is used for reading a sequence while moving forward.

Typical capabilities include:

```cpp
*it
++it
it++
it1 == it2
it1 != it2
```

Example:

```cpp
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    istream_iterator<int> it(cin);

    cout << *it;

    return 0;
}
```

Input iterators are commonly used for:
- Input streams
- Single-pass input sequences

Important property:

> Traditional input iterators are single-pass.

---

# 23. Output Iterator

An output iterator is used to write values into a destination.

Example:

```cpp
ostream_iterator<int> out(cout, " ");

*out = 10;
++out;

*out = 20;
```

Output:

```text
10 20
```

Output iterators are write-oriented.

Typical operations:

```cpp
*out = value;
++out;
```

They do not provide normal readable traversal semantics.

---

# 24. Forward Iterator

A forward iterator supports forward traversal and can be used for multi-pass traversal.

Typical operations:

```cpp
*
++
==
!=
```

It can read and, when the underlying container permits, modify elements.

Examples:

```text
forward_list
unordered_set
unordered_map
unordered_multiset
unordered_multimap
```

---

# 25. Bidirectional Iterator

A bidirectional iterator supports both directions:

```cpp
++it
--it
```

It also supports dereferencing and equality comparison.

Examples:

```text
list
set
multiset
map
multimap
```

It does not support:

```cpp
it + 3
it - 2
it[4]
```

---

# 26. Random Access Iterator

Random-access iterators support efficient jumps.

Operations include:

```cpp
++it
--it

it + n
it - n

it += n
it -= n

it[n]

it2 - it1

it1 < it2
it1 <= it2
it1 > it2
it1 >= it2
```

Examples:

```text
vector
deque
array
```

---

# 27. Contiguous Iterator

The **contiguous iterator** category was introduced with C++20 concepts.

It guarantees that successive iterator positions refer to elements stored contiguously in memory.

Typical standard-library examples include:

```text
vector
array
string
```

Contiguous iterators provide the strongest iterator guarantees.

They support random access plus contiguous storage.

---

# 28. Iterator Category Capability Table

| Capability | Input | Output | Forward | Bidirectional | Random Access | Contiguous |
|---|---:|---:|---:|---:|---:|---:|
| Read | Yes | No | Yes | Yes | Yes | Yes |
| Write | Limited/No | Yes | Yes* | Yes* | Yes* | Yes* |
| `++` | Yes | Yes | Yes | Yes | Yes | Yes |
| `--` | No | No | No | Yes | Yes | Yes |
| Multi-pass | No | No | Yes | Yes | Yes | Yes |
| `+ n` | No | No | No | No | Yes | Yes |
| `- n` | No | No | No | No | Yes | Yes |
| `it[n]` | No | No | No | No | Yes | Yes |
| Difference | No | No | No | No | Yes | Yes |
| Ordering comparisons | No | No | No | No | Yes | Yes |
| Contiguous memory guarantee | No | No | No | No | No | Yes |

`*` Write capability depends on the actual iterator/reference type and underlying container.

---

# 29. Iterator Category Hierarchy

Conceptually:

```text
                 Iterator
                    |
        +-----------+-----------+
        |                       |
      Input                   Output
        |
     Forward
        |
 Bidirectional
        |
 Random Access
        |
  Contiguous
```

This describes increasing traversal capability.

---

# 30. Iterator Types in STL Containers

| Container | Typical Iterator Capability |
|---|---|
| `vector` | Contiguous |
| `deque` | Random Access |
| `array` | Contiguous |
| `string` | Contiguous |
| `list` | Bidirectional |
| `forward_list` | Forward |
| `set` | Bidirectional |
| `multiset` | Bidirectional |
| `map` | Bidirectional |
| `multimap` | Bidirectional |
| `unordered_set` | Forward |
| `unordered_multiset` | Forward |
| `unordered_map` | Forward |
| `unordered_multimap` | Forward |

---

# 31. `iterator`

A normal iterator generally allows modification if the underlying container permits it.

Example:

```cpp
vector<int> v = {1, 2, 3};

auto it = v.begin();

*it = 100;
```

Now:

```text
100 2 3
```

---

# 32. `const_iterator`

A const iterator allows reading but not modification through the iterator.

```cpp
vector<int> v = {1, 2, 3};

auto it = v.cbegin();

cout << *it;
```

This is invalid:

```cpp
*it = 100;
```

---

# 33. `begin()` vs `cbegin()`

```cpp
auto it1 = v.begin();
```

may provide mutable access for a non-const container.

```cpp
auto it2 = v.cbegin();
```

provides const access.

Example:

```cpp
*it1 = 100;   // allowed if v is mutable
*it2 = 100;   // not allowed
```

---

# 34. `reverse_iterator`

A reverse iterator changes the direction of traversal.

Example:

```cpp
vector<int> v = {10, 20, 30};

for (auto it = v.rbegin(); it != v.rend(); ++it)
{
    cout << *it << " ";
}
```

Output:

```text
30 20 10
```

Important:

```cpp
++reverse_iterator
```

moves toward the previous element in the underlying container.

---

# 35. `const_reverse_iterator`

Example:

```cpp
auto it = v.crbegin();

cout << *it;
```

Modification is not allowed:

```cpp
*it = 100;   // error
```

---

# 36. `auto` with Iterators

Old style:

```cpp
vector<int>::iterator it = v.begin();
```

Modern style:

```cpp
auto it = v.begin();
```

For generic code:

```cpp
auto it = container.begin();
```

is usually clearer.

---

# 37. `std::advance`

Header:

```cpp
#include <iterator>
```

`advance()` moves an iterator by a specified number of positions.

```cpp
auto it = v.begin();

advance(it, 3);
```

Now `it` is three positions from the beginning.

Important:

```text
Random-access iterator → O(1)
Forward/Bidirectional → generally O(n) for n steps
```

For a negative distance, the iterator must support moving backward.

---

# 38. `std::next`

`next()` returns another iterator advanced from the supplied iterator.

```cpp
auto it2 = next(it);
```

It does not modify `it`.

Equivalent idea:

```cpp
auto it2 = it;
++it2;
```

With an offset:

```cpp
auto it2 = next(it, 3);
```

---

# 39. `std::prev`

`prev()` returns an iterator moved backward.

```cpp
auto it2 = prev(it);
```

The iterator must support backward movement.

For example:

```cpp
auto it = v.end();

auto last = prev(it);
```

Now:

```cpp
*last
```

is the last element.

---

# 40. `std::distance`

`distance()` calculates the number of increments needed to reach the second iterator.

```cpp
cout << distance(v.begin(), v.end());
```

If the vector has five elements:

```text
5
```

Complexity:

```text
Random Access → O(1)
Other iterator categories → generally O(n)
```

---

# 41. Important Difference: `distance()` vs `size()`

For a container:

```cpp
v.size()
```

is normally O(1).

But:

```cpp
distance(v.begin(), v.end())
```

may be O(n), depending on iterator category.

For a `list`:

```cpp
distance(l.begin(), l.end())
```

requires traversal.

Use the container's `size()` when you specifically need its element count.

---

# 42. `std::iter_swap`

Header:

```cpp
#include <iterator>
```

or through the standard algorithm facilities.

`iter_swap()` swaps the elements referred to by two iterators.

Example:

```cpp
vector<int> v = {10, 20, 30};

iter_swap(v.begin(), v.begin() + 2);
```

Result:

```text
30 20 10
```

---

# 43. Iterator Utility Functions

Header:

```cpp
#include <iterator>
```

Important utilities include:

```cpp
advance()
next()
prev()
distance()
iter_swap()
```

Also important iterator-related types/adapters include:

```cpp
iterator_traits
reverse_iterator
back_insert_iterator
front_insert_iterator
insert_iterator
istream_iterator
ostream_iterator
move_iterator
```

---

# 44. Iterator Adapters

Iterator adapters provide iterator-like interfaces for specialized operations.

Major types:

```text
Insert iterators
Stream iterators
Move iterators
Reverse iterators
```

---

# 45. `back_inserter`

Header:

```cpp
#include <iterator>
```

Creates an output iterator that appends using:

```cpp
push_back()
```

Example:

```cpp
vector<int> source = {1, 2, 3};
vector<int> destination;

copy(
    source.begin(),
    source.end(),
    back_inserter(destination)
);
```

Result:

```text
destination = {1, 2, 3}
```

---

# 46. `front_inserter`

Creates an iterator that inserts using:

```cpp
push_front()
```

Example:

```cpp
list<int> source = {1, 2, 3};
list<int> destination;

copy(
    source.begin(),
    source.end(),
    front_inserter(destination)
);
```

Because every element is inserted at the front, the final order is reversed:

```text
3 2 1
```

---

# 47. `inserter`

`inserter()` creates an iterator that inserts into a container at a specified position.

Example:

```cpp
set<int> destination;

auto pos = destination.begin();

copy(
    source.begin(),
    source.end(),
    inserter(destination, pos)
);
```

It uses the container's insertion operation.

---

# 48. `istream_iterator`

Header:

```cpp
#include <iterator>
```

Reads values from an input stream.

Example:

```cpp
istream_iterator<int> begin(cin);
istream_iterator<int> end;
```

The default-constructed iterator:

```cpp
istream_iterator<int>{}
```

represents end-of-stream.

Example:

```cpp
vector<int> v(
    istream_iterator<int>(cin),
    istream_iterator<int>()
);
```

---

# 49. `ostream_iterator`

Writes values to an output stream.

Example:

```cpp
ostream_iterator<int> out(cout, " ");

*out = 10;
++out;

*out = 20;
```

Output:

```text
10 20
```

---

# 50. `move_iterator`

`move_iterator` converts dereferencing into move-oriented access.

Example:

```cpp
auto first = make_move_iterator(source.begin());
auto last  = make_move_iterator(source.end());
```

Useful when transferring/moving elements rather than copying them.

Example:

```cpp
vector<string> source = {"A", "B", "C"};
vector<string> destination;

destination.insert(
    destination.end(),
    make_move_iterator(source.begin()),
    make_move_iterator(source.end())
);
```

The strings are moved into `destination`.

Afterward, the moved-from strings in `source` remain valid objects but their values are unspecified.

---

# 51. Range-Based `for` Loop

Instead of writing:

```cpp
for (
    auto it = v.begin();
    it != v.end();
    ++it
)
{
    cout << *it << " ";
}
```

you can write:

```cpp
for (auto x : v)
{
    cout << x << " ";
}
```

For modification:

```cpp
for (auto& x : v)
{
    ++x;
}
```

For read-only access without copying:

```cpp
for (const auto& x : v)
{
    cout << x;
}
```

---

# 52. How Range-Based `for` Relates to Iterators

Conceptually, a range-based loop uses begin/end operations and iterator-like traversal.

For a simple range, think approximately:

```cpp
auto&& range = v;

auto begin = begin(range);
auto end = end(range);

for (; begin != end; ++begin)
{
    auto x = *begin;
}
```

The exact language rules are more detailed, especially for arrays and custom ranges, but the iterator model is the important idea.

---

# 53. STL Algorithms and Iterator Ranges

Most classic STL algorithms use:

```cpp
[first, last)
```

Example:

```cpp
sort(v.begin(), v.end());
```

The algorithm receives:

```text
begin
  ↓
10 20 30 40
            ↑
           end
```

The `end` position is excluded.

---

# 54. `sort()`

```cpp
sort(v.begin(), v.end());
```

Requires random-access iterators in the classic algorithm.

Therefore:

```cpp
sort(v.begin(), v.end());
```

works for:

```text
vector
deque
array
```

but not for:

```text
list
forward_list
```

Use:

```cpp
list.sort();
```

for `std::list`.

---

# 55. `find()`

```cpp
auto it = find(
    v.begin(),
    v.end(),
    20
);
```

Check:

```cpp
if (it != v.end())
{
    cout << "Found";
}
```

Complexity:

```text
O(n)
```

---

# 56. `count()`

```cpp
int result = count(
    v.begin(),
    v.end(),
    10
);
```

Counts matching elements.

Complexity:

```text
O(n)
```

---

# 57. `count_if()`

```cpp
int result = count_if(
    v.begin(),
    v.end(),
    [](int x)
    {
        return x % 2 == 0;
    }
);
```

Counts elements satisfying a predicate.

---

# 58. `reverse()`

```cpp
reverse(
    v.begin(),
    v.end()
);
```

Reverses the range.

---

# 59. `copy()`

```cpp
copy(
    v.begin(),
    v.end(),
    destination.begin()
);
```

The destination must have enough valid writable positions.

Alternatively, use:

```cpp
back_inserter(destination)
```

when the destination supports `push_back()`.

---

# 60. `copy_if()`

```cpp
copy_if(
    v.begin(),
    v.end(),
    back_inserter(destination),
    [](int x)
    {
        return x % 2 == 0;
    }
);
```

Copies only elements satisfying the condition.

---

# 61. `remove()` and `remove_if()`

`remove()` rearranges elements so that values equal to the specified value are moved toward the end of the range.

For a vector:

```cpp
auto newEnd = remove(
    v.begin(),
    v.end(),
    5
);

v.erase(newEnd, v.end());
```

This is the classic erase-remove idiom.

`remove_if()` works with a predicate.

---

# 62. C++20 `std::erase` and `std::erase_if`

C++20 provides convenient non-member functions for supported standard containers.

Example:

```cpp
std::erase(v, 5);
```

Or:

```cpp
std::erase_if(
    v,
    [](int x)
    {
        return x % 2 == 0;
    }
);
```

These are often simpler than manually writing the erase-remove idiom.

---

# 63. `replace()`

```cpp
replace(v.begin(), v.end(), 10, 100);
```

Every occurrence of `10` is replaced by `100`.

---

# 64. `replace_if()`

```cpp
replace_if(v.begin(), v.end(),
    [](int x)
    {
        return x < 0;
    },
    0
);
```

Replaces values satisfying the predicate.

---

# 65. `transform()`

Example:

```cpp
vector<int> result(v.size());

transform(
    v.begin(),
    v.end(),
    result.begin(),
    [](int x)
    {
        return x * 2;
    }
);
```

The output range receives transformed values.

---

# 66. `min_element()`

```cpp
auto it = min_element(
    v.begin(),
    v.end()
);

if (it != v.end())
{
    cout << *it;
}
```

Important:

`min_element()` returns an iterator, not the value itself.

---

# 67. `max_element()`

```cpp
auto it = max_element(
    v.begin(),
    v.end()
);

if (it != v.end())
{
    cout << *it;
}
```

Again, the result is an iterator.

---

# 68. `binary_search()`

Works on a sorted range:

```cpp
sort(v.begin(), v.end());

bool found = binary_search(
    v.begin(),
    v.end(),
    20
);
```

Complexity is logarithmic for random-access iterator ranges under the standard algorithm's complexity requirements.

---

# 69. `lower_bound()`

For a sorted range:

```cpp
auto it = lower_bound(
    v.begin(),
    v.end(),
    20
);
```

It returns the first position where `20` could be inserted without violating ordering.

For a vector, iterator movement is logarithmic.

For non-random-access iterators, iterator advancement can make the overall complexity differ.

---

# 70. `upper_bound()`

```cpp
auto it = upper_bound(
    v.begin(),
    v.end(),
    20
);
```

Returns the first position after the range of elements equivalent to `20`.

---

# 71. `equal_range()`

```cpp
auto range = equal_range(
    v.begin(),
    v.end(),
    20
);
```

Returns:

```text
{lower_bound, upper_bound}
```

---

# 72. `accumulate()`

Header:

```cpp
#include <numeric>
```

Example:

```cpp
int sum = accumulate(
    v.begin(),
    v.end(),
    0
);
```

If:

```text
v = {10, 20, 30}
```

then:

```text
sum = 60
```

---

# 73. `for_each()`

```cpp
for_each(
    v.begin(),
    v.end(),
    [](int x)
    {
        cout << x << " ";
    }
);
```

The algorithm invokes the callable for each element.

---

# 74. `fill()`

```cpp
fill(
    v.begin(),
    v.end(),
    10
);
```

All elements become:

```text
10 10 10 ...
```

---

# 75. `generate()`

```cpp
generate(
    v.begin(),
    v.end(),
    []()
    {
        return rand();
    }
);
```

Generates a value for each position.

---

# 76. `all_of()`

```cpp
bool result = all_of(
    v.begin(),
    v.end(),
    [](int x)
    {
        return x > 0;
    }
);
```

Returns true if every element satisfies the condition.

---

# 77. `any_of()`

```cpp
bool result = any_of(
    v.begin(),
    v.end(),
    [](int x)
    {
        return x < 0;
    }
);
```

Returns true if at least one element satisfies the condition.

---

# 78. `none_of()`

```cpp
bool result = none_of(
    v.begin(),
    v.end(),
    [](int x)
    {
        return x < 0;
    }
);
```

Returns true if no element satisfies the condition.

---

# 79. Iterator Invalidation

Iterator invalidation occurs when a container operation makes an existing iterator unusable.

Example:

```cpp
vector<int> v = {1, 2, 3};

auto it = v.begin();

v.push_back(4);

cout << *it;
```

The iterator may have been invalidated by reallocation.

Using an invalidated iterator is undefined behavior.

---

# 80. Why Does Invalidation Happen?

Consider:

```text
Old vector storage:

+----+----+----+
| 1  | 2  | 3  |
+----+----+----+
 ^
 it
```

If the vector needs a larger allocation:

```text
New storage:

+----+----+----+----+----+
| 1  | 2  | 3  | 4  |    |
+----+----+----+----+----+
```

The old storage may be released.

The old iterator points into the old storage and is no longer valid.

---

# 81. Vector Iterator Invalidation

Important general rules:

### Reallocation

Operations such as:

```cpp
push_back()
emplace_back()
insert()
reserve()
resize()
```

can cause reallocation depending on the new size/capacity and operation.

If reallocation occurs:

```text
All iterators
All references
All pointers
```

to vector elements are invalidated.

### Insert/Erase Without Reallocation

Even without reallocation, insertion/erase can invalidate iterators and references at affected positions.

For `vector`, insertion and erasure shift elements, so iterators at or after the affected position can be invalidated.

Always consult the exact operation's invalidation rule when correctness matters.

---

# 82. `reserve()` and Iterator Invalidation

Example:

```cpp
vector<int> v;

v.reserve(100);

auto it = v.begin();
```

If a later operation does not exceed capacity, `push_back()` does not cause reallocation.

This can reduce invalidation caused by growth.

But insertion and erasure can still invalidate iterators according to vector's rules.

---

# 83. `deque` Iterator Invalidation

`deque` has more complicated invalidation rules than vector.

Some operations can invalidate all iterators even though references may have different rules.

For example, insertion in the middle has significant invalidation effects.

Therefore:

> Do not assume vector's invalidation rules apply to deque.

Consult the operation-specific rules.

---

# 84. `list` Iterator Invalidation

`std::list` has stable iterators.

Insertion generally does not invalidate iterators or references to existing elements.

Erasing an element invalidates the iterator/reference to that erased element only.

Example:

```cpp
list<int> l = {1, 2, 3};

auto it = l.begin();

l.push_back(4);

cout << *it;
```

`it` remains valid.

If:

```cpp
it = l.erase(it);
```

then the old iterator has been erased, but `erase()` returns the next valid iterator.

---

# 85. `forward_list` Iterator Invalidation

`forward_list` also provides stable iterators for elements not erased.

Operations that erase a particular element invalidate iterators/references to that erased element.

Node-based insertion generally does not invalidate iterators to existing elements.

---

# 86. `set`, `map`, and Related Containers

For ordered associative containers:

```text
set
multiset
map
multimap
```

insertion generally does not invalidate iterators or references to existing elements.

Erasing an element invalidates the iterator/reference to that erased element.

This stability is one of the advantages of node-based associative containers.

---

# 87. Unordered Container Invalidation

For:

```text
unordered_set
unordered_multiset
unordered_map
unordered_multimap
```

insertion can trigger a **rehash**.

A rehash invalidates iterators.

References and pointers to elements have different guarantees and can remain valid across rehash in standard unordered containers, but iterator invalidation must still be considered.

Erasing an element invalidates the iterator to that erased element.

---

# 88. Safe Erasing While Iterating

Incorrect vector pattern:

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
{
    if (*it == 5)
    {
        v.erase(it);
    }
}
```

After `erase()`, the iterator may be invalid, and the loop increment may operate on an invalid iterator.

Correct:

```cpp
for (auto it = v.begin(); it != v.end();)
{
    if (*it == 5)
    {
        it = v.erase(it);
    }
    else
    {
        ++it;
    }
}
```

---

# 89. Why Does `erase()` Return an Iterator?

For sequence containers such as vector, deque, list, and forward_list, erase operations can return an iterator to the element following the erased element when such an iterator exists.

Example:

```cpp
it = v.erase(it);
```

Flow:

```text
Current iterator
      ↓
   [element]
      ↓
   erase()
      ↓
iterator to next element
```

This makes safe traversal possible.

---

# 90. `erase()` with `list`

```cpp
for (auto it = l.begin(); it != l.end();)
{
    if (*it == 5)
    {
        it = l.erase(it);
    }
    else
    {
        ++it;
    }
}
```

This is a standard safe pattern.

---

# 91. `forward_list` Erasing

`forward_list` is special because it provides:

```cpp
erase_after()
```

instead of a general `erase(iterator)` interface.

Example:

```cpp
auto before = fl.before_begin();

while (next(before) != fl.end())
{
    if (*next(before) == 5)
    {
        fl.erase_after(before);
    }
    else
    {
        ++before;
    }
}
```

The reason is that a singly linked list needs access to the node before the node being erased.

---

# 92. Iterator Invalidation Summary

| Container | General Iterator Stability |
|---|---|
| `vector` | Often invalidated by reallocation/insertion/erasure |
| `deque` | Operation-dependent; more complex |
| `list` | Stable except erased elements |
| `forward_list` | Stable except erased elements |
| `set` | Stable except erased elements |
| `map` | Stable except erased elements |
| `unordered_map` | Rehash can invalidate iterators |
| `unordered_set` | Rehash can invalidate iterators |

Always use the exact standard operation's invalidation rules for production code.

---

# 93. Custom Iterator

A custom iterator can be implemented as a class.

Simple example:

```cpp
#include <iostream>

using namespace std;

class Counter
{
    int value;

public:

    Counter(int v)
        : value(v)
    {
    }

    int operator*() const
    {
        return value;
    }

    Counter& operator++()
    {
        ++value;
        return *this;
    }

    bool operator!=(const Counter& other) const
    {
        return value != other.value;
    }
};

int main()
{
    for (
        Counter it(1);
        it != Counter(6);
        ++it
    )
    {
        cout << *it << " ";
    }

    return 0;
}
```

Output:

```text
1 2 3 4 5
```

This is a simplified iterator-like object.

A production STL-compatible iterator requires more careful design.

---

# 94. Components of a Custom Iterator

A traditional iterator may need operations such as:

```cpp
operator*
operator->
operator++
operator--
operator==
operator!=
```

depending on its category.

Random-access iterators additionally need operations such as:

```cpp
operator+
operator-
operator+=
operator-=
operator[]
operator<
operator>
operator<=
operator>=
```

Modern C++20 code can instead model the appropriate iterator concept.

---

# 95. Iterator Traits

Iterator traits provide information about an iterator type.

Header:

```cpp
#include <iterator>
```

Traditional traits include:

```cpp
iterator_category
value_type
difference_type
pointer
reference
```

Example:

```cpp
using Traits =
    std::iterator_traits<decltype(v.begin())>;

using ValueType =
    Traits::value_type;
```

---

# 96. `std::iterator_traits`

Example:

```cpp
vector<int> v;

using It = vector<int>::iterator;

using Traits = iterator_traits<It>;

using Value = Traits::value_type;
```

Here:

```text
Value = int
```

This is useful in generic programming.

---

# 97. `value_type`

Represents the type of value referred to by the iterator.

For:

```cpp
vector<int>::iterator
```

the value type is:

```cpp
int
```

---

# 98. `difference_type`

Represents the type used for distances between iterators.

Typically:

```cpp
std::ptrdiff_t
```

for many standard iterators.

Example:

```cpp
using Difference =
    iterator_traits<It>::difference_type;
```

---

# 99. `iterator_category`

Traditional iterator traits expose a tag such as:

```cpp
input_iterator_tag
output_iterator_tag
forward_iterator_tag
bidirectional_iterator_tag
random_access_iterator_tag
```

C++20 adds more precise concepts, including:

```cpp
contiguous_iterator
```

---

# 100. `std::iterator` Historical Note

Older C++ code sometimes used:

```cpp
std::iterator
```

as a base class for custom iterators.

This approach is obsolete.

`std::iterator` was deprecated in C++17 and removed in C++20.

Modern code should define the necessary iterator operations and traits/concepts directly.

---

# 101. Iterator Concepts in C++20

C++20 introduced iterator concepts in:

```cpp
<iterator>
```

Important concepts include:

```cpp
std::input_iterator
std::output_iterator
std::forward_iterator
std::bidirectional_iterator
std::random_access_iterator
std::contiguous_iterator
```

They are used to express requirements more precisely in generic code.

---

# 102. Iterator Concepts Example

```cpp
#include <concepts>
#include <iterator>
#include <vector>

template<std::random_access_iterator It>
void process(It first, It last)
{
    // random-access operations are available
}
```

This is clearer than relying only on old tag dispatch.

---

# 103. `iterator_category` vs Iterator Concepts

Older STL style:

```text
iterator_category
```

Modern C++20 style:

```text
iterator concepts
```

Concepts allow generic code to express capabilities directly.

For example:

```cpp
std::forward_iterator<It>
```

asks whether `It` satisfies the forward-iterator concept.

---

# 104. `iterator_concept`

Modern iterator traits can expose:

```cpp
iterator_concept
```

when provided by an iterator.

This can provide a more accurate concept classification than the older:

```cpp
iterator_category
```

For C++20 and later generic code, iterator concepts are generally preferred for expressing constraints.

---

# 105. Sentinel

Modern ranges introduce the idea of a **sentinel**.

Traditionally:

```cpp
begin()
end()
```

often return the same iterator type.

With ranges, the end can be represented by a different sentinel type.

Conceptually:

```text
iterator
   ↓
elements
   ↓
sentinel
```

The iterator and sentinel only need to be comparable.

---

# 106. Why Sentinels Are Useful

A sentinel does not necessarily represent a concrete iterator position.

It can represent:

```text
End condition
```

This is useful for:

- Null-terminated sequences
- Infinite/lazy sequences
- Ranges where end representation differs from iterator
- Generic range abstractions

---

# 107. `std::default_sentinel`

C++20 provides:

```cpp
std::default_sentinel
```

It is used with iterator/sentinel pairs where a default sentinel represents the end.

Example concepts can use:

```cpp
begin
default_sentinel
```

rather than requiring both objects to have the same type.

---

# 108. `std::common_iterator`

`common_iterator` adapts an iterator and sentinel into a common type.

Useful when an interface requires:

```text
begin type == end type
```

even though the underlying range has different iterator and sentinel types.

---

# 109. `std::counted_iterator`

`counted_iterator` associates an iterator with a count.

Conceptually:

```text
iterator + number of remaining elements
```

This is useful when a range is known by length rather than a traditional end iterator.

---

# 110. Iterator Adapter Summary

| Adapter | Purpose |
|---|---|
| `back_inserter` | Insert using `push_back()` |
| `front_inserter` | Insert using `push_front()` |
| `inserter` | Insert at a container position |
| `istream_iterator` | Read from stream |
| `ostream_iterator` | Write to stream |
| `move_iterator` | Move from dereferenced values |
| `reverse_iterator` | Reverse traversal |
| `common_iterator` | Combine iterator/sentinel into common type |
| `counted_iterator` | Track a fixed number of elements |

---

# 111. Iterator and `std::ranges`

C++20 ranges provide a more modern interface.

Traditional:

```cpp
sort(v.begin(), v.end());
```

Ranges:

```cpp
std::ranges::sort(v);
```

The ranges library is built around:

```text
iterators
+
sentinels
+
ranges
+
concepts
```

This reduces some iterator boilerplate.

---

# 112. Iterator and Range

Traditional STL:

```cpp
[first, last)
```

A range is essentially a view of a sequence defined by its beginning and ending conditions.

Modern C++ ranges make this abstraction explicit.

Example:

```cpp
std::ranges::sort(v);
```

instead of:

```cpp
std::sort(v.begin(), v.end());
```

---

# 113. Iterator vs Index

Vector index:

```cpp
for (size_t i = 0; i < v.size(); ++i)
{
    cout << v[i];
}
```

Iterator:

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
{
    cout << *it;
}
```

Indexing is specific to random-access containers.

Iterators work across many different container types.

---

# 114. Why Algorithms Prefer Iterators

Consider:

```cpp
find(
    v.begin(),
    v.end(),
    20
);
```

The same algorithm can work with:

```cpp
vector
deque
list
forward_list
array
```

provided the iterator requirements are satisfied.

This is one of the central ideas of STL generic programming.

---

# 115. Iterator vs Container

A container owns/manages elements.

An iterator represents a position into that container.

Think:

```text
Container
    |
    +---- elements
    |
    +---- begin()
    |
    +---- end()
             |
             ↓
         iterator range
```

The iterator does not generally own the element.

---

# 116. Iterator Lifetime

An iterator's validity depends on the container and its operations.

An iterator can become invalid because:

```text
Element erased
Container reallocated
Container rehashed
Container destroyed
Underlying storage changed
```

Never use an iterator after it has become invalid.

---

# 117. Iterator Validity vs Element Lifetime

These are related but not identical concepts.

An element can remain alive while an iterator to it becomes invalid.

For example, some container operations can invalidate iterators without destroying every element.

Conversely, erasing an element destroys that element and invalidates iterators/references/pointers referring to it.

---

# 118. Iterator and Reference Stability

A container may have different guarantees for:

```text
Iterators
References
Pointers
```

For example, unordered containers can invalidate iterators during rehash while references and pointers to existing elements can remain valid.

Therefore, do not assume:

```text
iterator validity == reference validity
```

---

# 119. Iterator and `const`

Example:

```cpp
vector<int> v = {1, 2, 3};

const vector<int> cv = {1, 2, 3};

auto it = v.begin();
auto cit = cv.begin();
```

For a const vector:

```cpp
cv.begin()
```

returns a const iterator.

Similarly:

```cpp
cv.cbegin()
```

is const.

---

# 120. `const_iterator` Conversion

A mutable iterator can generally be converted to a const iterator.

Conceptually:

```text
iterator
   ↓
const_iterator
```

But the reverse conversion is not allowed because it would remove const protection.

Example:

```cpp
auto it = v.begin();

vector<int>::const_iterator cit = it;
```

Valid.

---

# 121. Iterator and `auto`

Preferred modern style:

```cpp
for (auto it = v.begin();
     it != v.end();
     ++it)
{
    cout << *it;
}
```

For read-only:

```cpp
for (auto it = v.cbegin();
     it != v.cend();
     ++it)
{
    cout << *it;
}
```

---

# 122. Iterator and `decltype`

Sometimes you may want the exact iterator type:

```cpp
using Iterator = decltype(v.begin());
```

Then:

```cpp
Iterator it = v.begin();
```

This is useful in generic code.

---

# 123. `std::begin` and `std::end`

The standard library also provides non-member:

```cpp
std::begin()
std::end()
```

These work with containers and built-in arrays.

Example:

```cpp
int arr[] = {1, 2, 3};

auto first = std::begin(arr);
auto last = std::end(arr);
```

This allows generic code to work with both arrays and containers.

---

# 124. `std::cbegin` and `std::cend`

Similarly:

```cpp
std::cbegin(container)
std::cend(container)
```

provide const iteration.

These are useful in generic code.

---

# 125. `std::rbegin` and `std::rend`

Non-member reverse helpers:

```cpp
std::rbegin(container)
std::rend(container)
```

Example:

```cpp
for (auto it = std::rbegin(v);
     it != std::rend(v);
     ++it)
{
    cout << *it;
}
```

---

# 126. Iterator Operations and Complexity

| Operation | Typical Complexity |
|---|---|
| Dereference `*it` | O(1) |
| Increment `++it` | O(1) for standard iterator categories |
| Decrement `--it` | O(1) when supported |
| `it + n` | O(1) for random access |
| `it - n` | O(1) for random access |
| `it[n]` | O(1) for random access |
| `it2 - it1` | O(1) for random access |
| `distance()` | O(1) random access, O(n) otherwise |
| `advance()` | O(1) random access, O(n) for linear traversal |
| `next()` | Complexity of corresponding advancement |
| `prev()` | Complexity of corresponding backward advancement |

---

# 127. Important Complexity Detail

Do not assume:

```cpp
++it
```

has the same implementation cost for every iterator.

For standard iterator categories, increment is required to have appropriate constant-time behavior for the iterator abstraction.

But jumping:

```cpp
advance(it, n)
```

can be:

```text
O(1)
```

for random access and:

```text
O(n)
```

for forward/bidirectional iterators.

---

# 128. Example: `vector` vs `list` with `advance`

Vector:

```cpp
auto it = v.begin();

advance(it, 1000);
```

Random-access iterator:

```text
O(1)
```

List:

```cpp
auto it = l.begin();

advance(it, 1000);
```

Bidirectional iterator:

```text
O(1000)
```

The iterator category determines the efficient operations available.

---

# 129. Iterator Requirements for Algorithms

Different algorithms require different iterator capabilities.

Examples:

```text
find()
    → input-style traversal

sort()
    → random access in classic std::sort

reverse()
    → bidirectional traversal

binary_search()
    → forward iterator requirement, with performance depending on iterator category

distance()
    → works broadly, but complexity depends on category
```

Always check an algorithm's iterator requirements.

---

# 130. `std::sort` and `std::list`

This does not work:

```cpp
std::sort(l.begin(), l.end());
```

because `std::list::iterator` is bidirectional, not random access.

Use:

```cpp
l.sort();
```

Similarly, for `forward_list`:

```cpp
fl.sort();
```

---

# 131. Iterator and Algorithms — General Pattern

Most classic algorithms follow:

```cpp
algorithm(
    first,
    last,
    optional_arguments
);
```

Example:

```cpp
find(
    v.begin(),
    v.end(),
    20
);
```

Think:

```text
[first, last)
      ↓
algorithm processes this range
```

---

# 132. Output Iterator Example with `copy`

```cpp
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {10, 20, 30};

    copy(
        v.begin(),
        v.end(),
        ostream_iterator<int>(cout, " ")
    );

    return 0;
}
```

Output:

```text
10 20 30
```

---

# 133. `back_inserter` Example

```cpp
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    vector<int> source = {1, 2, 3};

    vector<int> destination;

    copy(
        source.begin(),
        source.end(),
        back_inserter(destination)
    );

    for (int x : destination)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
1 2 3
```

---

# 134. `front_inserter` Example

```cpp
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

using namespace std;

int main()
{
    list<int> source = {1, 2, 3};

    list<int> destination;

    copy(
        source.begin(),
        source.end(),
        front_inserter(destination)
    );

    for (int x : destination)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
3 2 1
```

---

# 135. Iterator with `set`

```cpp
set<int> s = {10, 20, 30};

for (auto it = s.begin(); it != s.end(); ++it)
{
    cout << *it << " ";
}
```

A set iterator is bidirectional.

Values cannot be modified through the iterator because modifying a key could violate the container's ordering invariants.

---

# 136. Iterator with `map`

```cpp
map<int, string> m =
{
    {1, "One"},
    {2, "Two"}
};

for (auto it = m.begin(); it != m.end(); ++it)
{
    cout << it->first
         << " "
         << it->second
         << "\n";
}
```

For a map:

```cpp
it->first
```

is the key.

```cpp
it->second
```

is the mapped value.

---

# 137. Iterator with `unordered_map`

```cpp
unordered_map<int, string> m =
{
    {1, "One"},
    {2, "Two"}
};

for (auto it = m.begin(); it != m.end(); ++it)
{
    cout << it->first
         << " "
         << it->second
         << "\n";
}
```

The iterator category is forward.

The order is not sorted.

---

# 138. Iterator with `forward_list`

```cpp
forward_list<int> fl =
{
    10, 20, 30
};

for (auto it = fl.begin();
     it != fl.end();
     ++it)
{
    cout << *it << " ";
}
```

A `forward_list` iterator supports forward movement but not:

```cpp
--it
```

---

# 139. Iterator with `list`

```cpp
list<int> l =
{
    10, 20, 30
};

auto it = l.begin();

++it;
cout << *it;

--it;
cout << *it;
```

Both forward and backward traversal are supported.

---

# 140. Iterator with `deque`

```cpp
deque<int> d =
{
    10, 20, 30, 40
};

auto it = d.begin();

cout << it[2];
```

`deque` iterators are random-access iterators.

However, unlike vector iterators, deque storage is not one contiguous array.

---

# 141. Iterator with `array`

```cpp
array<int, 3> a =
{
    10, 20, 30
};

auto it = a.begin();

cout << it[2];
```

`array` provides contiguous iterators.

---

# 142. Iterator with `string`

```cpp
string s = "Hello";

for (auto it = s.begin(); it != s.end(); ++it)
{
    cout << *it;
}
```

`std::string` iterators are contiguous.

---

# 143. Iterator and `data()`

For contiguous containers such as vector:

```cpp
vector<int> v = {10, 20, 30};

int* p = v.data();
```

A vector iterator is conceptually much more pointer-like than a list iterator.

But generic code should use iterators instead of assuming the implementation is a raw pointer.

---

# 144. Iterator and Raw Pointer

Built-in arrays:

```cpp
int arr[] = {10, 20, 30};

int* begin = arr;
int* end = arr + 3;
```

This can be used with STL algorithms:

```cpp
sort(begin, end);
```

Raw pointers satisfy the appropriate random-access and contiguous iterator requirements.

---

# 145. Iterator and `nullptr`

An iterator is not generally equivalent to a pointer that can be compared with:

```cpp
nullptr
```

Instead, container iterators use their container's end representation:

```cpp
it == container.end()
```

This is an important difference.

---

# 146. Comparing Iterators from Different Containers

Do not generally compare iterators from unrelated containers.

Wrong:

```cpp
vector<int> a = {1, 2};
vector<int> b = {1, 2};

if (a.begin() == b.begin())
{
}
```

Iterator equality is defined for compatible iterators referring into the same sequence/range context as required by the iterator model.

Do not use unrelated container iterators as a way to compare values.

---

# 147. Invalid Iterator After Container Destruction

Wrong:

```cpp
auto getIterator()
{
    vector<int> v = {1, 2, 3};

    return v.begin();
}
```

After returning:

```text
v is destroyed
```

The returned iterator is invalid.

An iterator generally does not own the container or its element.

---

# 148. Iterator Does Not Own the Element

Example:

```cpp
vector<int> v = {10, 20, 30};

auto it = v.begin();
```

The vector owns its storage.

The iterator merely provides access to a position.

Conceptually:

```text
vector
  |
  +---- owns elements
  |
iterator
  |
  +---- refers to position
```

---

# 149. Iterator and Container Lifetime

For an iterator to remain valid:

```text
Container must remain alive
+
Element/position must remain valid
+
No invalidating operation should occur
```

All three should be considered.

---

# 150. Generic Programming with Iterators

One major purpose of iterators is generic programming.

Example:

```cpp
template<typename Iterator>
void print(
    Iterator first,
    Iterator last
)
{
    while (first != last)
    {
        cout << *first << " ";
        ++first;
    }
}
```

Usage:

```cpp
vector<int> v = {1, 2, 3};

print(v.begin(), v.end());
```

The function does not care whether the iterator belongs to a vector, list, or another compatible sequence.

---

# 151. Generic Sum Function

```cpp
template<typename Iterator>
auto sum(
    Iterator first,
    Iterator last
)
{
    using Value =
        typename std::iterator_traits<Iterator>::value_type;

    Value result{};

    while (first != last)
    {
        result += *first;
        ++first;
    }

    return result;
}
```

Usage:

```cpp
vector<int> v = {1, 2, 3};

cout << sum(v.begin(), v.end());
```

Output:

```text
6
```

---

# 152. Modern Generic Code with Concepts

C++20 can constrain iterator types:

```cpp
template<std::input_iterator Iterator>
void print(
    Iterator first,
    Iterator last
)
{
    while (first != last)
    {
        cout << *first << " ";
        ++first;
    }
}
```

This communicates that the function needs input-iterator capability.

---

# 153. Custom Container Design

When designing a custom container, providing iterators allows the container to work with STL algorithms.

A typical container provides:

```cpp
begin()
end()

cbegin()
cend()

rbegin()
rend()

crbegin()
crend()
```

depending on its capabilities.

---

# 154. Custom Container Iterator Design

A container may define:

```cpp
class iterator
{
    // iterator implementation
};
```

and:

```cpp
iterator begin();
iterator end();
```

Then users can write:

```cpp
for (auto it = container.begin();
     it != container.end();
     ++it)
{
    cout << *it;
}
```

This is the fundamental STL container/iterator interface.

---

# 155. Custom Iterator Design — Key Requirements

The exact requirements depend on the category.

For a forward iterator, think about:

```text
Dereference
Increment
Equality
Multi-pass behavior
```

For a bidirectional iterator:

```text
Forward iterator requirements
+
Decrement
```

For random access:

```text
Bidirectional capabilities
+
Jumping
+
Difference
+
Indexing
+
Ordering
```

For contiguous iterators:

```text
Random-access capabilities
+
Contiguous storage guarantee
```

---

# 156. `operator->` in Custom Iterators

If an iterator refers to an object:

```cpp
it->member
```

may be supported.

For example:

```cpp
struct Person
{
    string name;
};

auto it = people.begin();

cout << it->name;
```

A custom iterator should implement the appropriate arrow behavior when required.

---

# 157. `operator[]` in Random Access Iterators

A random-access iterator supports:

```cpp
it[n]
```

Conceptually:

```cpp
it[n]
```

is equivalent to:

```cpp
*(it + n)
```

Example:

```cpp
auto it = v.begin();

cout << it[2];
```

---

# 158. Iterator Difference

For random-access iterators:

```cpp
auto first = v.begin();
auto last = v.end();

auto n = last - first;
```

If there are five elements:

```text
n = 5
```

The result uses the iterator's `difference_type`.

---

# 159. `difference_type`

Use:

```cpp
using Difference =
    iterator_traits<It>::difference_type;
```

rather than assuming:

```cpp
int
```

for iterator distances.

This is especially important for generic code.

---

# 160. Iterator and `size_t`

Do not automatically use:

```cpp
size_t
```

for iterator differences.

Iterator difference is conceptually represented by:

```cpp
difference_type
```

because distances may need to represent negative values.

For example:

```cpp
auto distance = it2 - it1;
```

can be negative.

---

# 161. Iterator and `std::distance`

Example:

```cpp
auto first = v.begin();
auto last = v.end();

auto n = std::distance(first, last);
```

The return type is the iterator's difference type.

---

# 162. Reverse Iterator Base

A reverse iterator has an underlying iterator accessible through:

```cpp
it.base()
```

Example:

```cpp
vector<int> v = {10, 20, 30};

auto rit = v.rbegin();

auto base = rit.base();
```

Important:

```text
rit points to 30
rit.base() points to end()
```

The base iterator is one position ahead of the element referenced by the reverse iterator.

---

# 163. Why Is `rbegin().base() == end()`?

For:

```cpp
vector<int> v = {10, 20, 30};
```

```cpp
auto rit = v.rbegin();
```

`rit` refers to:

```text
30
```

But:

```cpp
rit.base()
```

is:

```text
v.end()
```

because reverse iteration is implemented conceptually by referring to the element immediately before the base iterator.

---

# 164. Erasing with a Reverse Iterator

Suppose:

```cpp
auto rit = find(
    v.rbegin(),
    v.rend(),
    20
);
```

If you need the corresponding forward iterator:

```cpp
auto it = rit.base();
```

But remember:

```text
it points one position after the element referred to by rit
```

To erase the actual element:

```cpp
v.erase(std::prev(rit.base()));
```

when valid.

---

# 165. Iterator Debugging

When debugging iterator problems, check:

```text
1. Is the container still alive?
2. Is the iterator initialized?
3. Is it equal to end()?
4. Was the element erased?
5. Did the container reallocate?
6. Did an unordered container rehash?
7. Are the iterators from the same container?
8. Is the iterator category sufficient?
9. Is the operation within its valid range?
```

---

# 166. Common Mistake — Dereferencing `end()`

Wrong:

```cpp
auto it = v.end();

cout << *it;
```

Correct:

```cpp
auto it = v.begin();

if (it != v.end())
{
    cout << *it;
}
```

---

# 167. Common Mistake — Dereferencing `rend()`

Wrong:

```cpp
cout << *v.rend();
```

`rend()` is a boundary, not an element.

Correct:

```cpp
cout << *v.rbegin();
```

if the container is non-empty.

---

# 168. Common Mistake — Incrementing End

Wrong:

```cpp
auto it = v.end();

++it;
```

This does not represent a valid traversal operation.

---

# 169. Common Mistake — Decrementing Begin

Wrong:

```cpp
auto it = v.begin();

--it;
```

This is invalid because there is no valid iterator position before the beginning for ordinary container iteration.

For reverse traversal use:

```cpp
rbegin()
```

---

# 170. Common Mistake — Using `it + n` on a List

Wrong:

```cpp
list<int> l = {1, 2, 3};

auto it = l.begin();

it = it + 2;
```

`list` provides bidirectional iterators, not random-access iterators.

Correct:

```cpp
advance(it, 2);
```

or:

```cpp
auto it2 = next(l.begin(), 2);
```

---

# 171. Common Mistake — Assuming `distance()` Is Always O(1)

Wrong assumption:

```text
distance() = O(1) everywhere
```

Correct:

```text
Random access → O(1)
Other iterator categories → generally O(n)
```

---

# 172. Common Mistake — Using Invalidated Iterator

Wrong:

```cpp
auto it = v.begin();

v.push_back(100);

cout << *it;
```

The iterator may have been invalidated.

---

# 173. Common Mistake — Erasing and Incrementing

Wrong:

```cpp
for (auto it = v.begin();
     it != v.end();
     ++it)
{
    if (*it == 5)
    {
        v.erase(it);
    }
}
```

Correct:

```cpp
for (auto it = v.begin();
     it != v.end();)
{
    if (*it == 5)
    {
        it = v.erase(it);
    }
    else
    {
        ++it;
    }
}
```

---

# 174. Common Mistake — Modifying Set Keys

Wrong:

```cpp
set<int> s = {1, 2, 3};

auto it = s.begin();

*it = 100;
```

A set's keys are part of its ordering invariant and cannot be modified through its iterator.

Use:

```cpp
s.erase(it);
s.insert(100);
```

if replacement is needed.

---

# 175. Common Mistake — Assuming Map Keys Are Mutable

For:

```cpp
map<int, string> m;
```

The iterator's value type is effectively:

```cpp
pair<const int, string>
```

Therefore:

```cpp
it->first = 10;
```

is invalid.

But:

```cpp
it->second = "New Value";
```

is allowed for a non-const iterator.

---

# 176. Common Mistake — Assuming All Iterators Support `<`

This is wrong:

```cpp
if (it1 < it2)
```

for arbitrary iterators.

Ordering comparison is a random-access capability.

For general iterators, use:

```cpp
it1 == it2
it1 != it2
```

as appropriate.

---

# 177. Common Mistake — Treating Iterator as Index

Wrong for a list:

```cpp
l[3]
```

Correct:

```cpp
auto it = next(l.begin(), 3);
```

This is O(n), because list iterators cannot jump directly.

---

# 178. Common Mistake — Comparing Values Using Iterators

This:

```cpp
a.begin() == b.begin()
```

does not mean:

```text
first element of a == first element of b
```

To compare values:

```cpp
*a.begin() == *b.begin()
```

assuming both containers are non-empty.

---

# 179. Iterator vs Index — Detailed Comparison

| Feature | Index | Iterator |
|---|---|---|
| Mainly sequence containers | Yes | No |
| Works with list | No | Yes |
| Works with map | No | Yes |
| Random access | Required | Not required |
| Generic STL algorithms | Limited | Excellent |
| Represents position | Numeric position | Iterator object |
| Supports `[]` | Yes for suitable containers | Only random-access iterators |

---

# 180. Iterator vs Pointer — Detailed Comparison

```text
Pointer
  ↓
Memory address abstraction

Iterator
  ↓
Container/range position abstraction
```

A raw pointer can be used as an iterator for arrays and contiguous memory.

But a list iterator may contain enough information to navigate linked nodes and is not a raw pointer.

---

# 181. Iterator vs Range

Iterator:

```text
One position
```

Range:

```text
Beginning + ending boundary
```

Classic STL range:

```cpp
[first, last)
```

Modern C++:

```cpp
std::ranges
```

can package range information more conveniently.

---

# 182. Algorithms and Iterator Category

The iterator category can determine whether an algorithm is efficient or even applicable.

Example:

```cpp
sort()
```

requires random-access iterators in its classic form.

But:

```cpp
find()
```

works with much weaker iterator capabilities.

This lets the STL use the weakest sufficient abstraction for each algorithm.

---

# 183. Algorithm Requirement Principle

Think:

```text
Algorithm
   ↓
What operations does it need?
   ↓
Choose minimum iterator capability
```

Examples:

```text
find
→ input-style traversal

reverse
→ bidirectional traversal

sort
→ random access
```

This is a core STL design principle.

---

# 184. Iterator and Performance

Using iterators does not automatically mean slower code.

For a vector:

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
```

is typically optimized very well.

For a list:

```cpp
for (auto it = l.begin(); it != l.end(); ++it)
```

the traversal follows linked nodes.

The container's memory layout has a much larger impact than the syntax used to traverse it.

---

# 185. Iterator and Cache Locality

Vector iterators traverse contiguous memory:

```text
10 20 30 40 50
```

This generally provides good cache locality.

List iterators traverse separate nodes:

```text
node → node → node → node
```

which generally has poorer cache locality.

Therefore:

```text
Iterator abstraction ≠ memory layout
```

The underlying container still determines performance characteristics.

---

# 186. Complete Example — Basic Iteration

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v =
    {
        10, 20, 30, 40
    };

    for (
        auto it = v.begin();
        it != v.end();
        ++it
    )
    {
        cout << *it << " ";
    }

    return 0;
}
```

Output:

```text
10 20 30 40
```

---

# 187. Complete Example — Modify Using Iterator

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v =
    {
        1, 2, 3, 4
    };

    for (auto it = v.begin();
         it != v.end();
         ++it)
    {
        *it *= 2;
    }

    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
2 4 6 8
```

---

# 188. Complete Example — Const Iterator

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v =
    {
        10, 20, 30
    };

    for (auto it = v.cbegin();
         it != v.cend();
         ++it)
    {
        cout << *it << " ";
    }

    return 0;
}
```

Output:

```text
10 20 30
```

---

# 189. Complete Example — Reverse Iterator

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v =
    {
        10, 20, 30
    };

    for (auto it = v.rbegin();
         it != v.rend();
         ++it)
    {
        cout << *it << " ";
    }

    return 0;
}
```

Output:

```text
30 20 10
```

---

# 190. Complete Example — `advance`, `next`, `prev`

```cpp
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    vector<int> v =
    {
        10, 20, 30, 40, 50
    };

    auto it = v.begin();

    advance(it, 2);

    cout << *it << '\n';

    auto nextIt = next(it);

    cout << *nextIt << '\n';

    auto prevIt = prev(it);

    cout << *prevIt << '\n';

    return 0;
}
```

Output:

```text
30
40
20
```

---

# 191. Complete Example — Safe Erase

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v =
    {
        1, 2, 5, 3, 5, 4
    };

    for (auto it = v.begin();
         it != v.end();)
    {
        if (*it == 5)
        {
            it = v.erase(it);
        }
        else
        {
            ++it;
        }
    }

    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
1 2 3 4
```

---

# 192. Complete Example — Algorithms with Iterators

```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    vector<int> v =
    {
        5, 2, 9, 1, 7
    };

    sort(v.begin(), v.end());

    auto it = find(
        v.begin(),
        v.end(),
        7
    );

    if (it != v.end())
    {
        cout << "Found: "
             << *it
             << '\n';
    }

    cout << "Sum: "
         << accumulate(
                v.begin(),
                v.end(),
                0
            )
         << '\n';

    return 0;
}
```

---

# 193. Complete Example — `map` Iterator

```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<int, string> employees =
    {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"}
    };

    for (
        auto it = employees.begin();
        it != employees.end();
        ++it
    )
    {
        cout << it->first
             << " "
             << it->second
             << '\n';
    }

    return 0;
}
```

Output:

```text
1 Alice
2 Bob
3 Charlie
```

---

# 194. Complete Example — Custom Generic Function

```cpp
#include <iostream>
#include <vector>

using namespace std;

template<typename Iterator>
void print(
    Iterator first,
    Iterator last
)
{
    while (first != last)
    {
        cout << *first << " ";
        ++first;
    }

    cout << '\n';
}

int main()
{
    vector<int> v =
    {
        10, 20, 30
    };

    print(
        v.begin(),
        v.end()
    );

    return 0;
}
```

Output:

```text
10 20 30
```

---

# 195. Complete Example — Stream Iterators

```cpp
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    vector<int> v =
    {
        10, 20, 30
    };

    copy(
        v.begin(),
        v.end(),
        ostream_iterator<int>(
            cout,
            " "
        )
    );

    return 0;
}
```

Output:

```text
10 20 30
```

---

# 196. Complete Example — Copy with `back_inserter`

```cpp
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    vector<int> source =
    {
        1, 2, 3, 4
    };

    vector<int> destination;

    copy(
        source.begin(),
        source.end(),
        back_inserter(destination)
    );

    for (int x : destination)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
1 2 3 4
```

---

# 197. Iterator Mental Model

Think of a container:

```text
+----+----+----+----+
| 10 | 20 | 30 | 40 |
+----+----+----+----+
  ^                   ^
  |                   |
begin()              end()
```

Iterator:

```text
it
 ↓
10
```

Dereference:

```cpp
*it
```

gives:

```text
10
```

Move:

```cpp
++it
```

gives:

```text
20
```

The iterator is a position, not the element itself.

---

# 198. Iterator + Algorithm Mental Model

Think:

```text
Container
    |
    +---- begin()
    |
    +---- end()
           |
           ↓
      [first,last)
           |
           ↓
       STL Algorithm
```

Example:

```cpp
find(
    v.begin(),
    v.end(),
    20
);
```

The algorithm operates on the iterator-defined range.

---

# 199. Best Practices

## 1. Prefer `auto`

Use:

```cpp
auto it = container.begin();
```

instead of writing long iterator types.

---

## 2. Use `const_iterator` for read-only traversal

```cpp
for (auto it = v.cbegin();
     it != v.cend();
     ++it)
{
    cout << *it;
}
```

---

## 3. Prefer range-based `for` when iterator manipulation is unnecessary

```cpp
for (const auto& x : v)
{
    cout << x;
}
```

---

## 4. Use `std::next`/`std::prev` when you need a moved copy

Instead of:

```cpp
auto x = it;
advance(x, 3);
```

you can write:

```cpp
auto x = next(it, 3);
```

---

## 5. Respect iterator category

Do not use:

```cpp
it + 5
```

unless the iterator supports random access.

Use:

```cpp
advance(it, 5);
```

for generic traversal.

---

## 6. Respect invalidation rules

After:

```cpp
insert()
erase()
push_back()
reserve()
rehash()
```

check whether your iterator remains valid.

---

## 7. Do not dereference boundary iterators

Never dereference:

```cpp
end()
rend()
```

or equivalent sentinel/end positions.

---

# 200. Final Summary

An **iterator** is a generalized position abstraction used to traverse elements in C++ containers and ranges.

The fundamental model is:

```text
begin()
   ↓
element
   ↓
++iterator
   ↓
next element
   ↓
...
   ↓
end()
```

The most important iterator categories are:

```text
Input
Output
Forward
Bidirectional
Random Access
Contiguous
```

Their capabilities increase roughly as:

```text
Input
  ↓
Forward
  ↓
Bidirectional
  ↓
Random Access
  ↓
Contiguous
```

Important examples:

```text
vector       → Contiguous
deque        → Random Access
array        → Contiguous
list         → Bidirectional
forward_list → Forward
map          → Bidirectional
set          → Bidirectional
unordered_map → Forward
unordered_set → Forward
```

Core operations:

```cpp
*it
++it
--it
it + n
it - n
it[n]
it1 - it2
```

Only use operations supported by the iterator category.

Important functions:

```cpp
begin()
end()

cbegin()
cend()

rbegin()
rend()

crbegin()
crend()

advance()
next()
prev()
distance()
iter_swap()
```

Important adapters:

```cpp
back_inserter()
front_inserter()
inserter()

istream_iterator
ostream_iterator

move_iterator
reverse_iterator
```

Classic STL algorithms operate on ranges:

```cpp
[first, last)
```

Examples:

```cpp
sort()
find()
count()
copy()
copy_if()
reverse()
remove()
remove_if()
replace()
replace_if()
transform()
partition()
binary_search()
lower_bound()
upper_bound()
equal_range()
accumulate()
for_each()
fill()
generate()
min_element()
max_element()
all_of()
any_of()
none_of()
```

The most important safety concept is **iterator invalidation**.

An iterator can become invalid after:

```text
container reallocation
element erasure
container rehash
container destruction
```

Therefore:

```text
Never use an iterator after an operation that invalidates it.
```

The most important STL design idea is:

```text
Container
    ↓
Iterator
    ↓
Range
    ↓
Algorithm
```

This separation allows the same generic algorithm to operate on many different containers.

For modern C++, also understand:

```text
Iterator concepts
Ranges
Sentinels
std::ranges
```

The key mental model to remember is:

```text
Iterator
=
Position in a sequence/range

begin()
=
first position

end()
=
one-past-end boundary

*it
=
element at the iterator position

++it
=
move forward

--it
=
move backward when supported

[first,last)
=
STL range

Iterator category
=
determines what operations are available and their complexity
```
