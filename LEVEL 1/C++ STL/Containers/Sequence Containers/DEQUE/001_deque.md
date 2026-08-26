# C++ `std::deque` — Complete Notes

## Table of Contents

1. Introduction
2. Header File
3. Namespace
4. Syntax
5. Template Parameters
6. What is `std::deque`?
7. Internal Working
8. Memory Layout
9. Why Use `deque`?
10. `vector` vs `deque` for Front Insertion
11. Characteristics
12. Creating a `deque`
13. Initialization
14. Constructors
15. Copy Operations
16. Move Operations
17. Element Access
18. `operator[]`
19. `at()`
20. `front()`
21. `back()`
22. `data()` — Important Difference
23. Capacity Functions
24. `empty()`
25. `size()`
26. `max_size()`
27. Modifiers
28. `push_back()`
29. `emplace_back()`
30. `push_front()`
31. `emplace_front()`
32. `pop_back()`
33. `pop_front()`
34. `insert()`
35. `emplace()`
36. `erase()`
37. `clear()`
38. `resize()`
39. `swap()`
40. `assign()`
41. Iterators
42. Traversal
43. Reverse Traversal
44. Random Access
45. STL Algorithms
46. Sorting
47. Searching
48. `deque` as Queue
49. `deque` as Stack
50. `deque` as Double-Ended Queue
51. `deque` with Custom Objects
52. `deque` of Pairs
53. Nested `deque`
54. Function Parameters
55. Return from Functions
56. Iterator Invalidation
57. Time Complexity
58. `deque` vs `vector`
59. `deque` vs `list`
60. `deque` vs `array`
61. `deque` vs `queue`
62. `deque` vs `priority_queue`
63. Advantages
64. Disadvantages
65. Common Mistakes
66. Common Interview Questions
67. Important C++ Version Features
68. Complete Basic Example
69. Complete Example — Both Ends
70. Complete Example — Queue
71. Complete Example — Stack
72. Summary

---

# 1. Introduction

`std::deque` stands for:

```text
Double Ended Queue
```

It is a sequence container provided by the C++ Standard Library.

It allows efficient insertion and deletion from **both the front and the back**.

Example:

```cpp
#include <deque>

std::deque<int> dq;
```

You can perform:

```cpp
dq.push_front(10);
dq.push_back(20);
```

and:

```cpp
dq.pop_front();
dq.pop_back();
```

Both ends are designed for efficient operations.

---

# 2. Header File

Use:

```cpp
#include <deque>
```

Example:

```cpp
#include <iostream>
#include <deque>
```

---

# 3. Namespace

You can use:

```cpp
using namespace std;

deque<int> dq;
```

Or explicitly:

```cpp
std::deque<int> dq;
```

Using `std::` explicitly is generally preferred in larger projects and header files.

---

# 4. Syntax

General syntax:

```cpp
std::deque<DataType> name;
```

Examples:

```cpp
std::deque<int> dq;

std::deque<double> prices;

std::deque<std::string> names;

std::deque<std::pair<int, int>> points;
```

Unlike `std::array`, the size is **not part of the type**.

---

# 5. Template Parameters

The simplified declaration is:

```cpp
template<
    class T,
    class Allocator = std::allocator<T>
>
class deque;
```

### Parameters

| Parameter | Meaning |
|---|---|
| `T` | Type of elements |
| `Allocator` | Controls memory allocation |

Example:

```cpp
std::deque<int>
```

means:

```text
T = int
```

---

# 6. What is `std::deque`?

`std::deque` is a sequence container designed for efficient insertion and deletion at both ends.

Example:

```cpp
std::deque<int> dq;

dq.push_back(20);
dq.push_front(10);
dq.push_back(30);
dq.push_front(5);
```

Result:

```text
5 10 20 30
```

Conceptually:

```text
             front                  back
               ↓                     ↓
        +----+----+----+----+
        | 5  | 10 | 20 | 30 |
        +----+----+----+----+
```

You can add elements at:

```text
front
  ↓
[5][10][20][30]
             ↑
            back
```

---

# 7. Internal Working

A `deque` is **not required to store all elements in one continuous memory block**.

Unlike a `vector`, which normally stores its elements contiguously, a deque typically uses multiple memory blocks.

Conceptually:

```text
Block 1          Block 2          Block 3

+---+---+        +---+---+        +---+---+
| 1 | 2 |        | 3 | 4 |        | 5 | 6 |
+---+---+        +---+---+        +---+---+
```

A separate internal structure keeps track of these blocks.

The exact implementation is implementation-dependent.

### Important

The C++ standard specifies the behavior and complexity requirements of `std::deque`, but does not mandate a particular block layout.

Most implementations use some form of segmented storage.

---

# 8. Memory Layout

### `vector`

Conceptually:

```text
+----+----+----+----+----+----+
| 1  | 2  | 3  | 4  | 5  | 6  |
+----+----+----+----+----+----+
```

One contiguous memory region.

### `deque`

Conceptually:

```text
Block 1       Block 2       Block 3

+----+----+   +----+----+   +----+----+
| 1  | 2  |   | 3  | 4  |   | 5  | 6  |
+----+----+   +----+----+   +----+----+
```

Multiple blocks.

The deque maintains enough internal bookkeeping to locate the appropriate block for an element.

---

# 9. Why Use `deque`?

The main reason to use `deque` is:

```text
Efficient insertion/deletion
at both ends
```

Example:

```cpp
dq.push_front(10);
dq.push_back(20);
```

and:

```cpp
dq.pop_front();
dq.pop_back();
```

are constant-time operations under the standard complexity requirements.

---

# 10. `vector` vs `deque` for Front Insertion

## Vector

Suppose:

```cpp
std::vector<int> v = {
    1, 2, 3
};
```

Insert at front:

```cpp
v.insert(v.begin(), 100);
```

Conceptually:

```text
Before:

1 2 3

After:

100 1 2 3
```

Existing elements may need to move.

Complexity:

```text
O(n)
```

---

## Deque

```cpp
std::deque<int> dq = {
    1, 2, 3
};

dq.push_front(100);
```

Result:

```text
100 1 2 3
```

The operation is designed to be:

```text
O(1)
```

No need to shift all existing elements as a contiguous vector would.

---

# 11. Characteristics

Important characteristics:

- Dynamic size.
- Supports insertion at front.
- Supports insertion at back.
- Supports deletion from front.
- Supports deletion from back.
- Supports random access.
- `operator[]` provides O(1) access.
- `at()` provides bounds checking.
- Not necessarily contiguous in memory.
- Does not provide `data()`.
- Supports bidirectional and random-access iteration.
- In modern C++, its iterators satisfy random-access requirements, but they are not contiguous iterators.
- Works with many STL algorithms.
- More flexible at both ends than `vector`.

---

# 12. Creating a `deque`

## Empty Deque

```cpp
std::deque<int> dq;
```

Creates an empty deque.

---

## With Initializer List

```cpp
std::deque<int> dq = {
    10, 20, 30, 40
};
```

Result:

```text
10 20 30 40
```

---

## Uniform Initialization

```cpp
std::deque<int> dq{
    10, 20, 30, 40
};
```

---

## Repeated Value

```cpp
std::deque<int> dq(5, 10);
```

Result:

```text
10 10 10 10 10
```

Five elements, each equal to `10`.

---

## Size Constructor

```cpp
std::deque<int> dq(5);
```

Creates five value-initialized `int` elements:

```text
0 0 0 0 0
```

---

# 13. Initialization

## Empty

```cpp
std::deque<int> dq;
```

---

## Values

```cpp
std::deque<int> dq = {
    10, 20, 30
};
```

---

## Partial Initialization

Unlike `std::array`, there is no fixed compile-time size requiring remaining elements.

For example:

```cpp
std::deque<int> dq = {
    10, 20
};
```

The deque simply contains two elements.

---

## Repeated Values

```cpp
std::deque<int> dq(5, 100);
```

Result:

```text
100 100 100 100 100
```

---

# 14. Constructors

## 14.1 Default Constructor

```cpp
std::deque<int> dq;
```

Creates an empty deque.

---

## 14.2 Size Constructor

```cpp
std::deque<int> dq(5);
```

Creates five value-initialized elements.

For `int`:

```text
0 0 0 0 0
```

---

## 14.3 Size + Value Constructor

```cpp
std::deque<int> dq(5, 10);
```

Result:

```text
10 10 10 10 10
```

---

## 14.4 Initializer List Constructor

```cpp
std::deque<int> dq = {
    10, 20, 30
};
```

---

## 14.5 Range Constructor

```cpp
std::vector<int> v = {
    10, 20, 30
};

std::deque<int> dq(
    v.begin(),
    v.end()
);
```

---

## 14.6 Copy Constructor

```cpp
std::deque<int> a = {
    1, 2, 3
};

std::deque<int> b(a);
```

---

## 14.7 Move Constructor

```cpp
std::deque<int> a = {
    1, 2, 3
};

std::deque<int> b(std::move(a));
```

The deque's resources can be transferred.

After the move:

```text
a -> valid but unspecified state
b -> contains transferred elements
```

---

# 15. Copy Operations

## Copy Assignment

```cpp
std::deque<int> a = {
    1, 2, 3
};

std::deque<int> b;

b = a;
```

Now:

```text
a = 1 2 3
b = 1 2 3
```

---

# 16. Move Operations

```cpp
std::deque<std::string> a = {
    "A", "B", "C"
};

std::deque<std::string> b;

b = std::move(a);
```

Resources can be transferred instead of copying every element.

After the move:

```text
a -> valid but unspecified state
b -> owns transferred contents
```

Include:

```cpp
#include <utility>
```

for:

```cpp
std::move()
```

---

# 17. Element Access

`std::deque` provides:

```text
operator[]
at()
front()
back()
```

Unlike `std::vector` and `std::array`, a deque does **not** provide `data()` because its elements are not required to be contiguous.

---

# 18. `operator[]`

Example:

```cpp
std::deque<int> dq = {
    10, 20, 30, 40
};

std::cout << dq[2];
```

Output:

```text
30
```

Complexity:

```text
O(1)
```

### Bounds checking

`operator[]` does not perform bounds checking.

This:

```cpp
dq[100];
```

when the deque has only four elements results in undefined behavior.

---

# 19. `at()`

Example:

```cpp
std::cout << dq.at(2);
```

Output:

```text
30
```

`at()` checks the index.

Invalid access:

```cpp
dq.at(100);
```

throws:

```cpp
std::out_of_range
```

Example:

```cpp
try
{
    std::cout << dq.at(100);
}
catch (const std::out_of_range& e)
{
    std::cout << "Index out of range";
}
```

---

# 20. `front()`

Returns a reference to the first element.

```cpp
std::cout << dq.front();
```

Example:

```text
10 20 30 40
```

Output:

```text
10
```

Complexity:

```text
O(1)
```

Do not call `front()` on an empty deque.

---

# 21. `back()`

Returns a reference to the last element.

```cpp
std::cout << dq.back();
```

Example:

```text
10 20 30 40
```

Output:

```text
40
```

Complexity:

```text
O(1)
```

Do not call `back()` on an empty deque.

---

# 22. `data()` — Important Difference

`std::deque` does **not** provide:

```cpp
dq.data();
```

Why?

Because deque elements are not required to be stored in one contiguous memory block.

### Compare

```text
vector
   ↓
Contiguous
   ↓
data() available
```

```text
array
   ↓
Contiguous
   ↓
data() available
```

```text
deque
   ↓
Segmented storage
   ↓
No data()
```

Therefore this is invalid:

```cpp
int* p = dq.data();   // Error
```

If a C-style API requires a contiguous `T*`, a deque is generally not the appropriate container.

---

# 23. Capacity Functions

`std::deque` provides:

```cpp
empty()
size()
max_size()
```

It does not provide:

```cpp
capacity()
reserve()
shrink_to_fit()
```

Wait: `shrink_to_fit()` **is provided** by `std::deque`.

Therefore:

```text
empty()
size()
max_size()
shrink_to_fit()
```

are available.

But:

```text
capacity()
reserve()
```

are not.

---

# 24. `empty()`

Checks whether the deque contains no elements.

```cpp
if (dq.empty())
{
    std::cout << "Empty";
}
```

Returns:

```text
true
false
```

Complexity:

```text
O(1)
```

---

# 25. `size()`

Returns the number of elements.

```cpp
std::cout << dq.size();
```

Example:

```text
10 20 30 40
```

returns:

```text
4
```

Complexity:

```text
O(1)
```

---

# 26. `max_size()`

Returns the theoretical maximum number of elements the deque can contain, subject to implementation and system limitations.

```cpp
std::cout << dq.max_size();
```

The exact value is implementation-dependent.

---

# 27. Modifiers

Important deque modifiers include:

```text
push_back()
emplace_back()

push_front()
emplace_front()

pop_back()
pop_front()

insert()
emplace()

erase()

clear()
resize()

swap()
assign()

shrink_to_fit()
```

---

# 28. `push_back()`

Adds an element at the back.

```cpp
std::deque<int> dq;

dq.push_back(10);
dq.push_back(20);
dq.push_back(30);
```

Result:

```text
10 20 30
```

Complexity:

```text
O(1) amortized
```

For `deque`, insertion at either end is specified as constant time.

---

# 29. `emplace_back()`

Constructs an element directly at the back.

Example:

```cpp
std::deque<std::pair<int, std::string>> dq;

dq.emplace_back(101, "Amit");
```

Result:

```text
101 -> Amit
```

It can avoid creating a separate temporary pair in appropriate cases.

---

# 30. `push_front()`

Adds an element at the front.

```cpp
std::deque<int> dq;

dq.push_front(10);
dq.push_front(20);
dq.push_front(30);
```

Result:

```text
30 20 10
```

Complexity:

```text
O(1)
```

---

# 31. `emplace_front()`

Constructs an element directly at the front.

Example:

```cpp
std::deque<std::pair<int, std::string>> dq;

dq.emplace_front(101, "Amit");
```

---

# 32. `pop_back()`

Removes the last element.

```cpp
std::deque<int> dq = {
    10, 20, 30
};

dq.pop_back();
```

Result:

```text
10 20
```

Complexity:

```text
O(1)
```

### Important

`pop_back()` does not return the removed value.

If you need it:

```cpp
int value = dq.back();
dq.pop_back();
```

---

# 33. `pop_front()`

Removes the first element.

```cpp
std::deque<int> dq = {
    10, 20, 30
};

dq.pop_front();
```

Result:

```text
20 30
```

Complexity:

```text
O(1)
```

Again, `pop_front()` does not return the removed element.

---

# 34. `insert()`

`insert()` can insert elements at arbitrary positions.

Example:

```cpp
std::deque<int> dq = {
    10, 20, 30
};

dq.insert(
    dq.begin() + 1,
    100
);
```

Result:

```text
10 100 20 30
```

### Important

Insertion in the middle is not constant time.

The complexity depends on the position and implementation details, but generally requires moving elements and is linear in the number of affected elements.

---

## Insert Multiple Copies

```cpp
dq.insert(
    dq.begin(),
    3,
    100
);
```

Result:

```text
100 100 100 10 20 30
```

---

## Insert Range

```cpp
std::vector<int> values = {
    40, 50
};

dq.insert(
    dq.end(),
    values.begin(),
    values.end()
);
```

---

# 35. `emplace()`

Constructs an element directly at a specified position.

Example:

```cpp
std::deque<std::pair<int, std::string>> dq;

dq.emplace(
    dq.begin(),
    101,
    "Amit"
);
```

The pair is constructed at the insertion position.

---

# 36. `erase()`

Removes elements from the deque.

## Erase One Element

```cpp
std::deque<int> dq = {
    10, 20, 30, 40
};

dq.erase(dq.begin() + 1);
```

Result:

```text
10 30 40
```

---

## Erase Range

```cpp
dq.erase(
    dq.begin(),
    dq.begin() + 2
);
```

Removes the first two elements.

---

### Important

Erasing from the middle can be O(n) because elements may need to be moved.

---

# 37. `clear()`

Removes all elements.

```cpp
dq.clear();
```

After:

```text
dq.empty() == true
```

Complexity:

```text
O(n)
```

because the elements must be destroyed.

---

# 38. `resize()`

Changes the number of elements.

Example:

```cpp
std::deque<int> dq = {
    10, 20, 30
};

dq.resize(5);
```

Two additional value-initialized elements are added.

For `int`:

```text
10 20 30 0 0
```

---

## Resize Smaller

```cpp
dq.resize(2);
```

Result:

```text
10 20
```

---

## Resize with Value

```cpp
dq.resize(5, 100);
```

New elements are initialized with `100`.

---

# 39. `swap()`

Swaps the contents of two deques.

```cpp
std::deque<int> a = {
    1, 2, 3
};

std::deque<int> b = {
    4, 5, 6
};

a.swap(b);
```

Result:

```text
a = 4 5 6
b = 1 2 3
```

Complexity:

```text
O(1)
```

under the standard deque swap requirements, subject to allocator-related conditions.

---

# 40. `assign()`

Replaces the contents of the deque.

## Assign Repeated Value

```cpp
std::deque<int> dq;

dq.assign(5, 100);
```

Result:

```text
100 100 100 100 100
```

---

## Assign Range

```cpp
std::vector<int> v = {
    1, 2, 3
};

dq.assign(
    v.begin(),
    v.end()
);
```

Result:

```text
1 2 3
```

---

## Assign Initializer List

```cpp
dq.assign({
    10, 20, 30
});
```

---

# 41. `shrink_to_fit()`

`std::deque` provides:

```cpp
dq.shrink_to_fit();
```

It is a **non-binding request** to reduce unused memory.

Important:

```text
request ≠ guarantee
```

The implementation may choose not to reduce memory.

Unlike `vector`, deque does not expose a `capacity()` member, so there is no direct capacity value to inspect.

---

# 42. Iterators

`std::deque` provides:

```cpp
begin()
end()

rbegin()
rend()

cbegin()
cend()

crbegin()
crend()
```

Its iterators are **random-access iterators**.

However:

```text
deque iterators are NOT contiguous iterators
```

because deque storage is segmented.

---

# 43. `begin()`

Returns iterator to the first element.

```cpp
auto it = dq.begin();
```

---

# 44. `end()`

Returns iterator one position after the last element.

```cpp
auto it = dq.end();
```

Do not dereference:

```cpp
*dq.end();   // Invalid
```

---

# 45. `rbegin()`

Starts reverse traversal from the last element.

```cpp
auto it = dq.rbegin();
```

---

# 46. `rend()`

Represents the position before the first element during reverse traversal.

---

# 47. Constant Iterators

```cpp
dq.cbegin();
dq.cend();

dq.crbegin();
dq.crend();
```

These prevent modification through the iterator.

---

# 48. Traversal

## Range-Based Loop

```cpp
for (int x : dq)
{
    std::cout << x << " ";
}
```

---

## Iterator

```cpp
for (auto it = dq.begin();
     it != dq.end();
     ++it)
{
    std::cout << *it << " ";
}
```

---

## Modify Elements

```cpp
for (auto& x : dq)
{
    x *= 2;
}
```

---

# 49. Reverse Traversal

```cpp
for (auto it = dq.rbegin();
     it != dq.rend();
     ++it)
{
    std::cout << *it << " ";
}
```

Example:

```text
10 20 30 40
```

Output:

```text
40 30 20 10
```

---

# 50. Random Access

Unlike `std::list`, `deque` supports random access.

Example:

```cpp
std::cout << dq[3];
```

Complexity:

```text
O(1)
```

You can also perform iterator arithmetic:

```cpp
auto it = dq.begin();

std::cout << *(it + 3);
```

---

# 51. STL Algorithms

`std::deque` provides random-access iterators, so it works with many standard algorithms.

Examples:

```cpp
std::sort()
std::reverse()
std::find()
std::count()
std::binary_search()
std::min_element()
std::max_element()
std::accumulate()
```

---

# 52. Sorting

```cpp
#include <algorithm>

std::deque<int> dq = {
    50, 20, 40, 10, 30
};

std::sort(
    dq.begin(),
    dq.end()
);
```

Result:

```text
10 20 30 40 50
```

Complexity:

```text
O(n log n)
```

---

# 53. Searching

## `find()`

```cpp
auto it = std::find(
    dq.begin(),
    dq.end(),
    30
);
```

Complexity:

```text
O(n)
```

---

## `binary_search()`

```cpp
bool found = std::binary_search(
    dq.begin(),
    dq.end(),
    30
);
```

The deque must be sorted according to the same ordering.

Complexity:

```text
O(log n)
```

---

# 54. `count()`

```cpp
int result = std::count(
    dq.begin(),
    dq.end(),
    10
);
```

Returns the number of occurrences.

Complexity:

```text
O(n)
```

---

# 55. `min_element()`

```cpp
auto it = std::min_element(
    dq.begin(),
    dq.end()
);
```

Then:

```cpp
std::cout << *it;
```

Complexity:

```text
O(n)
```

---

# 56. `max_element()`

```cpp
auto it = std::max_element(
    dq.begin(),
    dq.end()
);
```

Complexity:

```text
O(n)
```

---

# 57. `accumulate()`

Include:

```cpp
#include <numeric>
```

Example:

```cpp
std::deque<int> dq = {
    10, 20, 30, 40
};

int sum = std::accumulate(
    dq.begin(),
    dq.end(),
    0
);
```

Result:

```text
100
```

---

# 58. `deque` as a Queue

A deque can behave like a normal FIFO queue.

FIFO means:

```text
First In
First Out
```

Example:

```cpp
std::deque<int> dq;

dq.push_back(10);
dq.push_back(20);
dq.push_back(30);
```

Deque:

```text
10 20 30
```

Remove from front:

```cpp
dq.pop_front();
```

Result:

```text
20 30
```

This is exactly the typical queue behavior.

---

# 59. `deque` as a Stack

A deque can also behave like a stack.

Stack means:

```text
LIFO
Last In
First Out
```

Example:

```cpp
std::deque<int> dq;

dq.push_back(10);
dq.push_back(20);
dq.push_back(30);
```

Remove from back:

```cpp
dq.pop_back();
```

Result:

```text
10 20
```

The last inserted element `30` is removed first.

---

# 60. `deque` as a Double-Ended Queue

This is where the name comes from.

You can insert at both ends:

```cpp
dq.push_front(10);
dq.push_back(20);
```

And remove from both ends:

```cpp
dq.pop_front();
dq.pop_back();
```

Conceptually:

```text
             FRONT
               ↓
        +----+----+----+----+
        | 10 | 20 | 30 | 40 |
        +----+----+----+----+
                              ↑
                             BACK

push_front()  → add here
pop_front()   → remove here

push_back()   → add here
pop_back()    → remove here
```

---

# 61. `deque` with Custom Objects

You can store custom objects.

Example:

```cpp
#include <deque>
#include <string>
#include <iostream>

class Student
{
public:
    int id;
    std::string name;
};

int main()
{
    std::deque<Student> students;

    students.push_back({
        101,
        "Amit"
    });

    students.push_front({
        102,
        "Rahul"
    });

    for (const auto& student : students)
    {
        std::cout << student.id
                  << " "
                  << student.name
                  << '\n';
    }
}
```

Possible output:

```text
102 Rahul
101 Amit
```

---

# 62. `deque` of Pairs

Example:

```cpp
std::deque<std::pair<int, std::string>> employees;

employees.push_back({
    101,
    "Amit"
});

employees.push_front({
    102,
    "Rahul"
});
```

Access:

```cpp
for (const auto& employee : employees)
{
    std::cout << employee.first
              << " -> "
              << employee.second
              << '\n';
}
```

---

# 63. Nested `deque`

A deque can contain another deque.

Example:

```cpp
std::deque<std::deque<int>> matrix;
```

Add rows:

```cpp
matrix.push_back({
    1, 2, 3
});

matrix.push_back({
    4, 5, 6
});
```

Result:

```text
1 2 3
4 5 6
```

---

# 64. Function Parameters

You can pass a deque by value:

```cpp
void process(
    std::deque<int> dq
)
{
}
```

This copies the deque.

Usually, if you only need to read it, use:

```cpp
void process(
    const std::deque<int>& dq
)
{
}
```

This avoids copying the elements.

---

# 65. Modifying Through Reference

```cpp
void process(
    std::deque<int>& dq
)
{
    dq.push_front(100);
}
```

Now the original deque is modified.

---

# 66. Return from Functions

A deque can be returned by value.

```cpp
std::deque<int> createDeque()
{
    return {
        10, 20, 30
    };
}
```

Usage:

```cpp
auto dq = createDeque();
```

Modern C++ efficiently handles return-by-value through copy elision and move semantics where appropriate.

---

# 67. Iterator Invalidation

Iterator invalidation is an important topic.

Operations on a deque can invalidate iterators and references.

The exact invalidation behavior depends on the operation.

### General rule

Operations at either end can affect iterator validity because deque storage may need to be reorganized.

In particular:

- Inserting at either end can invalidate iterators.
- Erasing at either end has specific guarantees for references/iterators to unaffected elements, but iterator behavior must be considered carefully.
- Inserting or erasing in the middle can invalidate iterators and references to affected elements and may invalidate more broadly.
- `clear()` invalidates iterators and references to the erased elements.
- `resize()` may invalidate iterators/references depending on whether elements are added or removed.

### Safe rule

After a structural modification, do not assume an old iterator remains valid unless the standard explicitly guarantees it.

Example:

```cpp
auto it = dq.begin();

dq.push_back(100);

// Do not blindly assume `it` remains valid.
```

For production code, consult the exact iterator-invalidation guarantees for the operation being used.

---

# 68. Time Complexity

| Operation | Complexity |
|---|---:|
| `operator[]` | O(1) |
| `at()` | O(1) |
| `front()` | O(1) |
| `back()` | O(1) |
| `begin()` | O(1) |
| `end()` | O(1) |
| `rbegin()` | O(1) |
| `rend()` | O(1) |
| `empty()` | O(1) |
| `size()` | O(1) |
| `push_front()` | O(1) |
| `push_back()` | O(1) |
| `emplace_front()` | O(1) |
| `emplace_back()` | O(1) |
| `pop_front()` | O(1) |
| `pop_back()` | O(1) |
| `insert()` middle | O(n) |
| `erase()` middle | O(n) |
| `clear()` | O(n) |
| `resize()` | O(n) in the number of affected elements |
| `sort()` | O(n log n) |
| `find()` | O(n) |
| `count()` | O(n) |
| `binary_search()` | O(log n) |
| `min_element()` | O(n) |
| `max_element()` | O(n) |
| `accumulate()` | O(n) |
| `swap()` | O(1) |
| `shrink_to_fit()` | Non-binding; complexity is implementation-dependent |

### Most important

```text
Front insertion    → O(1)
Back insertion     → O(1)
Front deletion     → O(1)
Back deletion      → O(1)
Random access      → O(1)
Middle insertion   → O(n)
Middle deletion    → O(n)
```

---

# 69. `deque` vs `vector`

| Feature | `deque` | `vector` |
|---|---|---|
| Dynamic size | Yes | Yes |
| Random access | O(1) | O(1) |
| Front insertion | O(1) | O(n) |
| Back insertion | O(1) | O(1) amortized |
| Front deletion | O(1) | O(n) |
| Back deletion | O(1) | O(1) |
| Contiguous storage | No | Yes |
| `data()` | No | Yes |
| `capacity()` | No | Yes |
| `reserve()` | No | Yes |
| `push_front()` | Yes | No |
| `push_back()` | Yes | Yes |
| Cache locality | Generally less favorable than vector | Generally excellent |
| Best use | Both-end operations | Mostly end/back operations |

### Simple rule

Use:

```text
vector
```

when:

```text
Mostly accessing elements
+
Appending/removing at back
+
Contiguous memory required
```

Use:

```text
deque
```

when:

```text
Need efficient front and back operations
+
Random access is still required
```

---

# 70. `deque` vs `list`

| Feature | `deque` | `list` |
|---|---|---|
| Storage | Segmented | Linked nodes |
| Random access | O(1) | O(n) |
| Front insertion | O(1) | O(1) |
| Back insertion | O(1) | O(1) |
| Front deletion | O(1) | O(1) |
| Back deletion | O(1) | O(1) |
| Middle insertion with iterator | Linear movement may be required | O(1) after position is known |
| Memory overhead | Moderate | Higher |
| Cache locality | Better than linked list generally | Poorer |
| `data()` | No | No |

### Important

Do not automatically choose `list` just because you need insertion.

If you need:

```text
Random access
+
Both-end operations
```

`deque` is usually more suitable.

---

# 71. `deque` vs `array`

| Feature | `deque` | `array` |
|---|---|---|
| Size | Dynamic | Fixed |
| Memory | Segmented | Contiguous |
| Random access | O(1) | O(1) |
| Front insertion | O(1) | Not supported |
| Back insertion | O(1) | Not supported |
| `push_back()` | Yes | No |
| `push_front()` | Yes | No |
| `resize()` | Yes | No |
| `data()` | No | Yes |
| Best use | Dynamic double-ended sequence | Fixed-size sequence |

---

# 72. `deque` vs `queue`

This is an important distinction.

`std::queue` is a **container adaptor**.

```cpp
std::queue<int> q;
```

It normally uses `std::deque` as its underlying container by default.

A queue provides a restricted interface:

```text
push()
pop()
front()
back()
```

A deque provides much more:

```text
push_front()
push_back()

pop_front()
pop_back()

operator[]
at()

begin()
end()

insert()
erase()
resize()
```

### Simple difference

```text
queue
   ↓
Restricted FIFO interface
```

```text
deque
   ↓
Full double-ended sequence container
```

---

# 73. `deque` vs `priority_queue`

`priority_queue` is also a container adaptor.

It is designed for:

```text
Highest/lowest priority first
```

A deque is designed for:

```text
Front + Back operations
```

Example:

```text
deque:
10 20 30 40

priority_queue:
highest priority element is accessed first
```

They solve different problems.

---

# 74. Advantages

## 1. Efficient Front Insertion

```cpp
dq.push_front(value);
```

Complexity:

```text
O(1)
```

---

## 2. Efficient Back Insertion

```cpp
dq.push_back(value);
```

Complexity:

```text
O(1)
```

---

## 3. Efficient Front Deletion

```cpp
dq.pop_front();
```

Complexity:

```text
O(1)
```

---

## 4. Efficient Back Deletion

```cpp
dq.pop_back();
```

Complexity:

```text
O(1)
```

---

## 5. Random Access

```cpp
dq[index];
```

Complexity:

```text
O(1)
```

---

## 6. Dynamic Size

Unlike `std::array`, a deque can grow and shrink.

---

## 7. STL Compatibility

Works with many standard algorithms.

---

# 75. Disadvantages

## 1. Not Contiguous

Unlike:

```text
vector
array
```

deque elements are not guaranteed to be in one continuous memory block.

---

## 2. No `data()`

You cannot directly obtain a pointer to all elements:

```cpp
dq.data();  // Error
```

---

## 3. More Memory Overhead

The segmented structure requires additional bookkeeping.

---

## 4. Worse Cache Locality Than Vector

Because the elements are segmented, vector often has better cache locality.

---

## 5. Middle Operations Are Expensive

Insertion and deletion in the middle can be O(n).

---

## 6. No `reserve()`

Unlike `vector`:

```cpp
dq.reserve(100);  // Error
```

A deque does not provide `reserve()`.

---

# 76. Common Mistakes

## Mistake 1: Using `vector` for Frequent Front Insertion

Avoid:

```cpp
std::vector<int> v;

v.insert(v.begin(), 100);
```

repeatedly when front insertion is a core requirement.

Prefer:

```cpp
std::deque<int> dq;

dq.push_front(100);
```

---

## Mistake 2: Expecting `data()`

This is invalid:

```cpp
dq.data();
```

Deque does not guarantee contiguous storage.

---

## Mistake 3: Calling `front()` on an Empty Deque

Bad:

```cpp
std::deque<int> dq;

std::cout << dq.front();
```

Check:

```cpp
if (!dq.empty())
{
    std::cout << dq.front();
}
```

---

## Mistake 4: Calling `back()` on an Empty Deque

Bad:

```cpp
dq.back();
```

when empty.

Use:

```cpp
if (!dq.empty())
{
    std::cout << dq.back();
}
```

---

## Mistake 5: Calling `pop_front()` on an Empty Deque

Bad:

```cpp
dq.pop_front();
```

when the deque is empty.

Always ensure:

```cpp
!dq.empty()
```

before removing an element.

---

## Mistake 6: Assuming Middle Insertion Is O(1)

This:

```cpp
dq.insert(
    dq.begin() + 5,
    100
);
```

is not generally O(1).

Middle operations require element movement.

---

## Mistake 7: Assuming Deque Is Contiguous

Do not assume:

```cpp
&dq[0] + 1
```

points to the same memory region as `&dq[1]`.

A deque's elements are not guaranteed to be contiguous.

---

## Mistake 8: Assuming Iterators Never Invalidate

Deque structural modifications can invalidate iterators.

Do not blindly reuse an iterator after insertion or erasure.

---

# 77. Common Interview Questions

## Q1. What is `std::deque`?

`std::deque` is a dynamic sequence container that supports efficient insertion and deletion at both the front and back.

---

## Q2. What does deque stand for?

```text
Double Ended Queue
```

It is commonly pronounced:

```text
"deck"
```

---

## Q3. Is deque contiguous?

No.

Its elements are not required to occupy one continuous memory block.

---

## Q4. What is the complexity of `push_front()`?

```text
O(1)
```

---

## Q5. What is the complexity of `push_back()`?

```text
O(1)
```

---

## Q6. What is the complexity of random access?

```text
O(1)
```

Using:

```cpp
dq[index]
```

or:

```cpp
dq.at(index)
```

---

## Q7. Does deque support random access?

Yes.

---

## Q8. Does deque have `data()`?

No.

Because deque does not guarantee contiguous storage.

---

## Q9. Difference between deque and vector?

```text
vector:
    Contiguous
    Efficient back insertion
    Front insertion is O(n)

deque:
    Segmented
    Efficient front insertion
    Efficient back insertion
    Random access
```

---

## Q10. Difference between deque and list?

```text
deque:
    Random access O(1)

list:
    Random access O(n)
```

`list` provides efficient insertion/erasure when the iterator to the position is already known.

---

## Q11. Can deque grow dynamically?

Yes.

```cpp
dq.push_back(10);
dq.push_front(20);
```

The size changes dynamically.

---

## Q12. Does deque support `push_front()`?

Yes.

```cpp
dq.push_front(10);
```

---

## Q13. Does deque support `push_back()`?

Yes.

```cpp
dq.push_back(10);
```

---

## Q14. Does deque support `pop_front()`?

Yes.

```cpp
dq.pop_front();
```

---

## Q15. Does deque support `pop_back()`?

Yes.

```cpp
dq.pop_back();
```

---

## Q16. Does deque support `resize()`?

Yes.

```cpp
dq.resize(10);
```

---

## Q17. Does deque support `reserve()`?

No.

```cpp
dq.reserve(100);   // Error
```

---

## Q18. Does deque support `capacity()`?

No.

Unlike `vector`, deque does not expose a `capacity()` member.

---

## Q19. Can deque be sorted?

Yes.

Because deque provides random-access iterators:

```cpp
std::sort(
    dq.begin(),
    dq.end()
);
```

---

## Q20. Can deque be used as a queue?

Yes.

For FIFO behavior:

```cpp
dq.push_back(value);
dq.pop_front();
```

---

## Q21. Can deque be used as a stack?

Yes.

For LIFO behavior:

```cpp
dq.push_back(value);
dq.pop_back();
```

---

## Q22. Why is deque faster than vector for front insertion?

A vector stores elements contiguously, so inserting at the front requires moving existing elements.

A deque uses segmented storage and can add an element at the front without shifting the entire sequence.

---

## Q23. Is deque always faster than vector?

No.

It depends on the workload.

`vector` often has:

- Better cache locality.
- Lower overhead.
- Faster sequential traversal.

`deque` is useful when frequent operations at both ends are required.

---

## Q24. What happens to iterators after modifying a deque?

Iterator invalidation depends on the operation. Structural modifications can invalidate iterators, so you should not assume an old iterator remains valid after insertion or erasure unless the standard explicitly guarantees it.

---

## Q25. What is the best use case for deque?

When you need:

```text
Dynamic size
+
Efficient front operations
+
Efficient back operations
+
Random access
```

---

# 78. Important C++ Version Features

| Feature | Standard |
|---|---|
| `std::deque` | C++98 |
| `push_front()` | C++98 |
| `push_back()` | C++98 |
| `emplace()` | C++11 |
| `emplace_front()` | C++11 |
| `emplace_back()` | C++11 |
| Move construction/assignment | C++11 |
| `cbegin()` / `cend()` | C++11 |
| `crbegin()` / `crend()` | C++14 |
| `shrink_to_fit()` | C++11 |
| `erase_if()` | C++20 |

---

# 79. C++20 `erase_if()`

C++20 provides:

```cpp
std::erase_if()
```

for standard containers including `deque`.

Example:

```cpp
#include <deque>
#include <iostream>

int main()
{
    std::deque<int> dq = {
        10, 15, 20, 25, 30
    };

    std::erase_if(
        dq,
        [](int x)
        {
            return x % 2 == 0;
        }
    );

    for (int x : dq)
    {
        std::cout << x << " ";
    }
}
```

Result:

```text
15 25
```

It removes all elements satisfying the predicate.

---

# 80. Complete Basic Example

```cpp
#include <iostream>
#include <deque>

int main()
{
    std::deque<int> dq;

    dq.push_back(20);
    dq.push_back(30);

    dq.push_front(10);

    std::cout << "Deque: ";

    for (int x : dq)
    {
        std::cout << x << " ";
    }

    std::cout << '\n';

    std::cout << "Front: "
              << dq.front()
              << '\n';

    std::cout << "Back: "
              << dq.back()
              << '\n';

    std::cout << "Size: "
              << dq.size()
              << '\n';

    dq.pop_front();
    dq.pop_back();

    std::cout << "After removing both ends: ";

    for (int x : dq)
    {
        std::cout << x << " ";
    }

    return 0;
}
```

Output:

```text
Deque: 10 20 30
Front: 10
Back: 30
Size: 3
After removing both ends: 20
```

---

# 81. Complete Example — Both Ends

```cpp
#include <iostream>
#include <deque>

int main()
{
    std::deque<int> dq;

    dq.push_front(30);
    dq.push_front(20);
    dq.push_front(10);

    dq.push_back(40);
    dq.push_back(50);

    std::cout << "Deque: ";

    for (int x : dq)
    {
        std::cout << x << " ";
    }

    std::cout << '\n';

    dq.pop_front();
    dq.pop_back();

    std::cout << "After pop operations: ";

    for (int x : dq)
    {
        std::cout << x << " ";
    }

    return 0;
}
```

Output:

```text
Deque: 10 20 30 40 50
After pop operations: 20 30 40
```

---

# 82. Complete Example — Queue Behavior

```cpp
#include <iostream>
#include <deque>

int main()
{
    std::deque<int> dq;

    // Enqueue
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // Dequeue
    while (!dq.empty())
    {
        std::cout << dq.front() << " ";

        dq.pop_front();
    }

    return 0;
}
```

Output:

```text
10 20 30
```

This is FIFO:

```text
First In
   ↓
First Out
```

---

# 83. Complete Example — Stack Behavior

```cpp
#include <iostream>
#include <deque>

int main()
{
    std::deque<int> dq;

    // Push
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // Pop
    while (!dq.empty())
    {
        std::cout << dq.back() << " ";

        dq.pop_back();
    }

    return 0;
}
```

Output:

```text
30 20 10
```

This is LIFO:

```text
Last In
   ↓
First Out
```

---

# 84. Complete Example — STL Algorithms

```cpp
#include <iostream>
#include <deque>
#include <algorithm>
#include <numeric>

int main()
{
    std::deque<int> dq = {
        50, 20, 40, 10, 30
    };

    std::sort(
        dq.begin(),
        dq.end()
    );

    std::cout << "Sorted: ";

    for (int x : dq)
    {
        std::cout << x << " ";
    }

    std::cout << '\n';

    auto it = std::find(
        dq.begin(),
        dq.end(),
        30
    );

    if (it != dq.end())
    {
        std::cout << "30 found\n";
    }

    int sum = std::accumulate(
        dq.begin(),
        dq.end(),
        0
    );

    std::cout << "Sum: "
              << sum
              << '\n';

    return 0;
}
```

Output:

```text
Sorted: 10 20 30 40 50
30 found
Sum: 150
```

---

# 85. Complete Example — `at()` and `[]`

```cpp
#include <iostream>
#include <deque>
#include <stdexcept>

int main()
{
    std::deque<int> dq = {
        10, 20, 30
    };

    std::cout << dq[1] << '\n';

    try
    {
        std::cout << dq.at(10) << '\n';
    }
    catch (const std::out_of_range&)
    {
        std::cout << "Invalid index\n";
    }

    return 0;
}
```

Output:

```text
20
Invalid index
```

---

# 86. Complete Example — Custom Object

```cpp
#include <iostream>
#include <deque>
#include <string>

class Employee
{
public:
    int id;
    std::string name;
};

int main()
{
    std::deque<Employee> employees;

    employees.emplace_back(
        Employee{101, "Amit"}
    );

    employees.emplace_front(
        Employee{102, "Rahul"}
    );

    for (const auto& employee : employees)
    {
        std::cout << employee.id
                  << " -> "
                  << employee.name
                  << '\n';
    }

    return 0;
}
```

Output:

```text
102 -> Rahul
101 -> Amit
```

---

# 87. Complete Example — `insert()` and `erase()`

```cpp
#include <iostream>
#include <deque>

int main()
{
    std::deque<int> dq = {
        10, 20, 30
    };

    dq.insert(
        dq.begin() + 1,
        100
    );

    std::cout << "After insert: ";

    for (int x : dq)
    {
        std::cout << x << " ";
    }

    std::cout << '\n';

    dq.erase(
        dq.begin() + 1
    );

    std::cout << "After erase: ";

    for (int x : dq)
    {
        std::cout << x << " ";
    }

    return 0;
}
```

Output:

```text
After insert: 10 100 20 30
After erase: 10 20 30
```

---

# 88. Complete Comparison

## `std::array`

```text
Fixed size
Contiguous
Random access
O(1)
```

## `std::vector`

```text
Dynamic size
Contiguous
Random access
O(1)
Efficient back operations
```

## `std::deque`

```text
Dynamic size
Segmented
Random access
O(1)
Efficient front operations
Efficient back operations
```

## `std::list`

```text
Dynamic size
Linked nodes
No random access
O(n) access
Efficient insertion/erasure at known positions
```

---

# 89. Quick Decision Guide

```text
Need a sequence?
       |
       +---- Fixed size?
       |       |
       |       +---- Yes --> std::array
       |
       +---- Dynamic size
               |
               +---- Mostly back operations?
               |        |
               |        +---- Yes --> std::vector
               |
               +---- Front + back operations?
                        |
                        +---- Yes --> std::deque
```

If you need frequent insertion/erasure in the middle **and already have an iterator to the position**, consider:

```text
std::list
```

or:

```text
std::forward_list
```

depending on the requirements.

---

# 90. Most Important Functions

## Add

```cpp
dq.push_front(value);
dq.push_back(value);

dq.emplace_front(...);
dq.emplace_back(...);
```

## Remove

```cpp
dq.pop_front();
dq.pop_back();

dq.erase(...);
dq.clear();
```

## Access

```cpp
dq[index];
dq.at(index);

dq.front();
dq.back();
```

## Size

```cpp
dq.size();
dq.empty();
dq.max_size();
```

## Modification

```cpp
dq.insert(...);
dq.emplace(...);
dq.resize(...);
dq.assign(...);
dq.swap(...);
dq.shrink_to_fit();
```

## Iteration

```cpp
dq.begin();
dq.end();

dq.rbegin();
dq.rend();

dq.cbegin();
dq.cend();

dq.crbegin();
dq.crend();
```

---

# 91. Most Important Complexity Table

```text
push_front()     -> O(1)
push_back()      -> O(1)

pop_front()      -> O(1)
pop_back()       -> O(1)

operator[]       -> O(1)
at()             -> O(1)

front()          -> O(1)
back()           -> O(1)

size()           -> O(1)
empty()          -> O(1)

middle insert    -> O(n)
middle erase     -> O(n)

find()           -> O(n)
sort()           -> O(n log n)
```

---

# 92. Final Summary

`std::deque` is a **dynamic double-ended sequence container**.

Its biggest advantage is efficient operations at both ends:

```text
push_front() -> O(1)
push_back()  -> O(1)

pop_front()  -> O(1)
pop_back()   -> O(1)
```

It also supports:

```text
Random access -> O(1)
```

But unlike `vector` and `array`:

```text
deque is NOT guaranteed to be contiguous
```

Therefore:

```text
data() -> Not available
```

### Main properties

```text
Header              : <deque>

Introduced          : C++98

Container type      : Sequence container

Size                : Dynamic

Memory              : Segmented / non-contiguous

Random access       : Yes

Random access       : O(1)

Front insertion     : O(1)

Back insertion      : O(1)

Front deletion      : O(1)

Back deletion       : O(1)

Middle insertion    : O(n)

Middle deletion     : O(n)

data()              : No

push_front()        : Yes

push_back()         : Yes

pop_front()         : Yes

pop_back()          : Yes

resize()            : Yes

reserve()           : No

capacity()          : No

STL algorithms      : Yes

Best use            : Dynamic sequence requiring efficient
                      operations at both ends
```

## One-Line Definition

> **`std::deque` is a dynamic STL sequence container that provides O(1) insertion and deletion at both ends, O(1) random access, and segmented rather than guaranteed contiguous storage.**

## Easy Memory Trick

```text
std::deque
    ↓
Dynamic Size
    ↓
Front + Back
    ↓
O(1) End Operations
    ↓
Random Access
    ↓
O(1)
    ↓
NOT Contiguous
```

## Final Decision

```text
Need fixed-size sequence?
        |
        +---- Yes --> std::array

Need dynamic sequence?
        |
        +---- Mostly back operations
        |          |
        |          +---- std::vector
        |
        +---- Front + Back operations
                   |
                   +---- std::deque
```