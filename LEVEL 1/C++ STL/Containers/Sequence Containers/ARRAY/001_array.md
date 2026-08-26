# C++ `std::array` — Complete Notes

## Table of Contents

1. Introduction
2. Header File
3. Namespace
4. Syntax
5. Template Parameters
6. What is `std::array`?
7. Internal Working
8. Memory Layout
9. Characteristics
10. Why Use `std::array`?
11. Creating `std::array`
12. Initialization
13. Copy Operations
14. Move Operations
15. Element Access
16. Capacity Functions
17. Modifiers
18. Iterators
19. Traversal
20. Reverse Traversal
21. `data()`
22. `fill()`
23. `swap()`
24. Tuple Interface
25. Structured Bindings
26. STL Algorithms
27. Sorting
28. Searching
29. `std::array` with Strings
30. `std::array` of Custom Objects
31. Multidimensional `std::array`
32. `std::array` of Pairs
33. `std::array` of Arrays
34. Function Parameters
35. Return from Functions
36. Passing by Reference
37. `constexpr` and `std::array`
38. Comparison Operators
39. Iterator Category
40. Time Complexity
41. `std::array` vs C Array
42. `std::array` vs `vector`
43. `std::array` vs `deque`
44. `std::array` vs `list`
45. `std::array` vs `std::vector`
46. Advantages
47. Disadvantages
48. Common Mistakes
49. Common Interview Questions
50. Important C++ Version Features
51. Complete Example
52. Summary

---

# 1. Introduction

`std::array` is a **fixed-size sequence container** provided by the C++ Standard Library.

It was introduced in:

```text
C++11
```

It provides an STL-style interface around a fixed-size array.

Example:

```cpp
#include <array>

std::array<int, 5> numbers = {10, 20, 30, 40, 50};
```

The size is fixed:

```text
5 elements
```

It cannot become:

```text
6 elements
```

or:

```text
4 elements
```

after creation.

---

# 2. Header File

Use:

```cpp
#include <array>
```

Example:

```cpp
#include <iostream>
#include <array>

int main()
{
    std::array<int, 5> arr = {10, 20, 30, 40, 50};
}
```

---

# 3. Namespace

You can use the fully qualified name:

```cpp
std::array<int, 5> arr;
```

Or:

```cpp
using namespace std;

array<int, 5> arr;
```

In larger projects and header files, explicitly using:

```cpp
std::
```

is generally safer because it avoids namespace pollution and name collisions.

---

# 4. Syntax

General syntax:

```cpp
std::array<DataType, Size> variable;
```

Example:

```cpp
std::array<int, 5> arr;
```

Here:

```text
DataType = int
Size     = 5
```

Other examples:

```cpp
std::array<double, 10> marks;

std::array<std::string, 3> names;

std::array<char, 26> alphabet;

std::array<bool, 8> flags;
```

---

# 5. Template Parameters

The simplified declaration is:

```cpp
template<class T, std::size_t N>
struct array;
```

There are two important template parameters:

| Parameter | Meaning |
|---|---|
| `T` | Element type |
| `N` | Number of elements |

Example:

```cpp
std::array<int, 5>
```

means:

```text
T = int
N = 5
```

The size `N` is part of the type.

Therefore:

```cpp
std::array<int, 5>
```

and:

```cpp
std::array<int, 10>
```

are **different types**.

---

# 6. What is `std::array`?

`std::array` is a fixed-size container that combines:

```text
C-style array storage
+
STL container interface
```

For example:

```cpp
std::array<int, 5> arr = {
    10, 20, 30, 40, 50
};
```

Conceptually:

```text
+----+----+----+----+----+
| 10 | 20 | 30 | 40 | 50 |
+----+----+----+----+----+
```

It provides useful functions such as:

```cpp
size()
empty()
at()
front()
back()
data()
fill()
swap()
begin()
end()
```

and works directly with STL algorithms.

---

# 7. Internal Working

`std::array` stores its elements as part of the array object itself.

Unlike `std::vector`, it does not normally need a separate dynamically allocated memory block for its elements.

Example:

```cpp
std::array<int, 5> arr = {
    10, 20, 30, 40, 50
};
```

Conceptually:

```text
arr
 |
 +----+----+----+----+----+
 | 10 | 20 | 30 | 40 | 50 |
 +----+----+----+----+----+
```

The elements are contiguous.

### Important

`std::array` does **not** dynamically allocate storage merely because it is an STL container.

For a normal:

```cpp
std::array<int, 5>
```

the five `int` elements are stored directly within the object.

---

# 8. Memory Layout

Suppose:

```cpp
std::array<int, 5> arr = {
    10, 20, 30, 40, 50
};
```

The elements are stored contiguously:

```text
Address
   |
   v

+---------+---------+---------+---------+---------+
| arr[0]  | arr[1]  | arr[2]  | arr[3]  | arr[4]  |
|   10    |   20    |   30    |   40    |   50    |
+---------+---------+---------+---------+---------+
```

If an `int` occupies 4 bytes on the platform, the conceptual addresses could be:

```text
1000 -> 10
1004 -> 20
1008 -> 30
1012 -> 40
1016 -> 50
```

The exact addresses depend on the program and system.

### Important property

```text
Contiguous storage
        ↓
Random access
        ↓
O(1)
```

---

# 9. Characteristics

Important characteristics of `std::array`:

- Fixed size.
- Size known at compile time.
- Contiguous storage.
- Random access.
- STL-compatible.
- Supports iterators.
- Supports range-based `for`.
- Supports `at()`.
- Supports `front()`.
- Supports `back()`.
- Supports `fill()`.
- Supports `swap()`.
- Supports `data()`.
- Does not support `push_back()`.
- Does not support `pop_back()`.
- Does not support `resize()`.
- Does not dynamically grow.
- Does not dynamically shrink.
- Works with STL algorithms.
- Supports tuple-like access through `std::get`.

---

# 10. Why Use `std::array`?

Suppose you need exactly five integers.

A C-style array:

```cpp
int arr[5] = {
    10, 20, 30, 40, 50
};
```

works.

But `std::array` provides an STL interface:

```cpp
std::array<int, 5> arr = {
    10, 20, 30, 40, 50
};
```

You can use:

```cpp
arr.size();
arr.at(2);
arr.front();
arr.back();
arr.begin();
arr.end();
arr.fill(10);
```

It can also be passed to standard algorithms naturally:

```cpp
std::sort(arr.begin(), arr.end());
```

---

# 11. Creating `std::array`

## 11.1 Empty Declaration

```cpp
std::array<int, 5> arr;
```

For a local automatic object, the elements are default-initialized. For fundamental types such as `int`, this means their values are indeterminate.

Do not read them before assigning values.

---

## 11.2 Initialization

```cpp
std::array<int, 5> arr = {
    10, 20, 30, 40, 50
};
```

---

## 11.3 Uniform Initialization

```cpp
std::array<int, 5> arr{
    10, 20, 30, 40, 50
};
```

---

## 11.4 Empty Braces

```cpp
std::array<int, 5> arr{};
```

For `int`, all elements become zero:

```text
0 0 0 0 0
```

---

# 12. Initialization

## 12.1 Full Initialization

```cpp
std::array<int, 5> arr = {
    1, 2, 3, 4, 5
};
```

Result:

```text
1 2 3 4 5
```

---

## 12.2 Partial Initialization

```cpp
std::array<int, 5> arr = {
    1, 2
};
```

Remaining elements are value-initialized:

```text
1 2 0 0 0
```

---

## 12.3 All Zero

```cpp
std::array<int, 5> arr{};
```

Result:

```text
0 0 0 0 0
```

---

## 12.4 String Array

```cpp
std::array<std::string, 3> names = {
    "Amit",
    "Rahul",
    "Deep"
};
```

---

## 12.5 Character Array

```cpp
std::array<char, 5> letters = {
    'A', 'B', 'C', 'D', 'E'
};
```

---

# 13. Copy Operations

## 13.1 Copy Constructor

```cpp
std::array<int, 5> a = {
    1, 2, 3, 4, 5
};

std::array<int, 5> b(a);
```

Now:

```text
a = 1 2 3 4 5
b = 1 2 3 4 5
```

---

## 13.2 Copy Assignment

```cpp
std::array<int, 5> a = {
    1, 2, 3, 4, 5
};

std::array<int, 5> b{};

b = a;
```

Now `b` contains the same elements.

---

## 13.3 Different Sizes

This is not allowed:

```cpp
std::array<int, 5> a;
std::array<int, 10> b;

a = b;  // Error
```

Because:

```text
std::array<int, 5>
```

and:

```text
std::array<int, 10>
```

are different types.

---

# 14. Move Operations

`std::array` supports move construction and move assignment.

Example:

```cpp
std::array<std::string, 3> a = {
    "A",
    "B",
    "C"
};

std::array<std::string, 3> b(std::move(a));
```

For an `std::array`, moving means moving each element.

There is no separate dynamically allocated array buffer owned by `std::array` itself.

For primitive types such as:

```cpp
std::array<int, 5>
```

moving is effectively equivalent to copying the individual integers.

After moving:

```text
a -> valid but its elements may be moved-from
b -> contains the moved elements
```

For non-trivial element types, the actual behavior depends on the element's move constructor.

---

# 15. Element Access

`std::array` provides several ways to access elements:

```cpp
operator[]
at()
front()
back()
data()
```

---

# 15.1 `operator[]`

Example:

```cpp
std::array<int, 5> arr = {
    10, 20, 30, 40, 50
};

std::cout << arr[2];
```

Output:

```text
30
```

Complexity:

```text
O(1)
```

### Important

`operator[]` does not perform bounds checking.

This:

```cpp
arr[10]
```

when the array has only five elements, results in undefined behavior.

---

# 15.2 `at()`

Example:

```cpp
std::cout << arr.at(2);
```

Output:

```text
30
```

`at()` performs bounds checking.

Invalid access:

```cpp
arr.at(10);
```

throws:

```cpp
std::out_of_range
```

Example:

```cpp
try {
    std::cout << arr.at(10);
}
catch (const std::out_of_range& e) {
    std::cout << "Invalid index";
}
```

---

# 15.3 `front()`

Returns the first element.

```cpp
std::cout << arr.front();
```

For:

```text
10 20 30 40 50
```

output:

```text
10
```

Complexity:

```text
O(1)
```

---

# 15.4 `back()`

Returns the last element.

```cpp
std::cout << arr.back();
```

Output:

```text
50
```

Complexity:

```text
O(1)
```

---

# 15.5 `data()`

Returns a pointer to the underlying contiguous storage.

```cpp
int* p = arr.data();
```

Then:

```cpp
std::cout << p[0];
```

is equivalent to:

```cpp
std::cout << arr[0];
```

For a non-empty array:

```cpp
arr.data()
```

points to the first element.

For:

```cpp
std::array<int, 0>
```

the array is empty, and there is no element to dereference.

---

# 16. Capacity Functions

## 16.1 `size()`

Returns the number of elements.

```cpp
std::cout << arr.size();
```

For:

```cpp
std::array<int, 5>
```

result:

```text
5
```

Complexity:

```text
O(1)
```

---

# 16.2 `max_size()`

Returns the maximum number of elements.

For a particular `std::array<T, N>`, it is effectively the same fixed size:

```cpp
arr.max_size()
```

returns:

```text
N
```

---

# 16.3 `empty()`

Checks whether the array contains zero elements.

Example:

```cpp
std::array<int, 5> arr;

std::cout << arr.empty();
```

Output:

```text
0
```

An empty array:

```cpp
std::array<int, 0> arr;
```

returns:

```text
true
```

### Important

`std::array` can have size zero:

```cpp
std::array<int, 0>
```

but you must not access:

```cpp
arr[0]
arr.at(0)
arr.front()
arr.back()
```

because there is no element.

---

# 17. Modifiers

`std::array` has a small set of modifiers because its size cannot change.

Important modifiers include:

```cpp
fill()
swap()
```

It does not have:

```cpp
push_back()
pop_back()
resize()
insert()
erase()
```

---

# 18. Iterators

`std::array` provides:

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

Because the storage is contiguous, its iterators are random-access iterators.

In modern C++, they also satisfy the stronger contiguous-iterator requirements.

---

## `begin()`

Returns an iterator to the first element.

```cpp
auto it = arr.begin();
```

---

## `end()`

Returns an iterator one position after the last element.

```cpp
auto it = arr.end();
```

Do not dereference `end()`.

---

## `rbegin()`

Returns a reverse iterator to the last element.

---

## `rend()`

Returns a reverse iterator representing the position before the first element.

---

## `cbegin()`

Returns a constant iterator.

---

## `cend()`

Returns the constant end iterator.

---

## `crbegin()`

Returns a constant reverse iterator.

---

## `crend()`

Returns the constant reverse-end iterator.

---

# 19. Traversal

## 19.1 Iterator

```cpp
for (auto it = arr.begin();
     it != arr.end();
     ++it)
{
    std::cout << *it << " ";
}
```

---

## 19.2 Range-Based `for`

```cpp
for (int x : arr)
{
    std::cout << x << " ";
}
```

---

## 19.3 `const auto&`

Useful when the elements are large objects:

```cpp
for (const auto& item : arr)
{
    std::cout << item << " ";
}
```

---

## 19.4 Modify Elements

```cpp
for (auto& x : arr)
{
    x *= 2;
}
```

---

# 20. Reverse Traversal

Using reverse iterators:

```cpp
for (auto it = arr.rbegin();
     it != arr.rend();
     ++it)
{
    std::cout << *it << " ";
}
```

Suppose:

```text
10 20 30 40 50
```

Output:

```text
50 40 30 20 10
```

---

# 21. `data()`

`data()` provides access to the underlying contiguous storage.

Example:

```cpp
std::array<int, 5> arr = {
    10, 20, 30, 40, 50
};

int* p = arr.data();

std::cout << p[2];
```

Output:

```text
30
```

### Why is `data()` useful?

It can be useful when interacting with APIs that expect a pointer to contiguous elements.

Example:

```cpp
void process(const int* data, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        std::cout << data[i] << " ";
    }
}
```

Call:

```cpp
process(arr.data(), arr.size());
```

---

# 22. `fill()`

`fill()` assigns the same value to every element.

Example:

```cpp
std::array<int, 5> arr;

arr.fill(10);
```

Result:

```text
10 10 10 10 10
```

Complexity:

```text
O(n)
```

where `n` is the number of elements.

---

# 23. `swap()`

Swaps all elements of two arrays having compatible types.

Example:

```cpp
std::array<int, 3> a = {
    1, 2, 3
};

std::array<int, 3> b = {
    4, 5, 6
};

a.swap(b);
```

After:

```text
a = 4 5 6
b = 1 2 3
```

You can also use:

```cpp
std::swap(a, b);
```

For fixed-size arrays, swapping generally involves swapping their elements, so the complexity is:

```text
O(n)
```

---

# 24. Tuple Interface

`std::array` has a tuple-like interface.

You can use:

```cpp
std::get<index>(arr)
```

Example:

```cpp
#include <array>
#include <iostream>
#include <tuple>

int main()
{
    std::array<int, 3> arr = {
        10, 20, 30
    };

    std::cout << std::get<0>(arr) << '\n';
    std::cout << std::get<1>(arr) << '\n';
    std::cout << std::get<2>(arr) << '\n';
}
```

Output:

```text
10
20
30
```

The index must be known at compile time.

This:

```cpp
std::get<2>(arr)
```

is valid.

But this:

```cpp
int index = 2;
std::get<index>(arr);
```

is not valid because the template argument must be a compile-time constant.

---

# 25. Structured Bindings

Structured bindings were introduced in:

```text
C++17
```

Example:

```cpp
std::array<int, 3> arr = {
    10, 20, 30
};

auto [a, b, c] = arr;
```

Now:

```text
a = 10
b = 20
c = 30
```

Output:

```cpp
std::cout << a << " "
          << b << " "
          << c;
```

Output:

```text
10 20 30
```

### Reference structured binding

To refer directly to the elements:

```cpp
auto& [a, b, c] = arr;
```

Now modifying:

```cpp
a = 100;
```

also modifies:

```cpp
arr[0]
```

---

# 26. STL Algorithms

`std::array` provides:

```text
Random-access / contiguous iterators
```

Therefore it works with many standard algorithms.

Include:

```cpp
#include <algorithm>
```

Examples:

```cpp
std::sort()
std::reverse()
std::find()
std::count()
std::binary_search()
std::min_element()
std::max_element()
std::copy()
std::fill()
std::for_each()
```

---

# 27. Sorting

Example:

```cpp
#include <array>
#include <algorithm>
#include <iostream>

int main()
{
    std::array<int, 5> arr = {
        50, 20, 40, 10, 30
    };

    std::sort(arr.begin(), arr.end());

    for (int x : arr)
    {
        std::cout << x << " ";
    }
}
```

Output:

```text
10 20 30 40 50
```

Complexity:

```text
O(n log n)
```

---

# 28. Searching

## 28.1 `find()`

```cpp
auto it = std::find(
    arr.begin(),
    arr.end(),
    30
);
```

If found:

```cpp
if (it != arr.end())
{
    std::cout << "Found";
}
```

Complexity:

```text
O(n)
```

---

## 28.2 `binary_search()`

```cpp
bool found = std::binary_search(
    arr.begin(),
    arr.end(),
    30
);
```

The array must be sorted according to the search ordering.

Complexity:

```text
O(log n)
```

for random-access iterators.

---

## 28.3 `count()`

```cpp
int result = std::count(
    arr.begin(),
    arr.end(),
    10
);
```

Returns the number of occurrences.

Complexity:

```text
O(n)
```

---

# 29. `min_element()`

```cpp
auto it = std::min_element(
    arr.begin(),
    arr.end()
);
```

Then:

```cpp
std::cout << *it;
```

Example:

```text
10 20 30 40 50
```

Output:

```text
10
```

Complexity:

```text
O(n)
```

---

# 30. `max_element()`

```cpp
auto it = std::max_element(
    arr.begin(),
    arr.end()
);
```

Then:

```cpp
std::cout << *it;
```

Output:

```text
50
```

Complexity:

```text
O(n)
```

---

# 31. `accumulate()`

`accumulate()` is provided by:

```cpp
#include <numeric>
```

Example:

```cpp
#include <array>
#include <numeric>
#include <iostream>

int main()
{
    std::array<int, 5> arr = {
        10, 20, 30, 40, 50
    };

    int sum = std::accumulate(
        arr.begin(),
        arr.end(),
        0
    );

    std::cout << sum;
}
```

Output:

```text
150
```

Complexity:

```text
O(n)
```

---

# 32. `std::array` with Strings

Example:

```cpp
#include <array>
#include <string>
#include <iostream>

int main()
{
    std::array<std::string, 3> names = {
        "Amit",
        "Rahul",
        "Deep"
    };

    for (const auto& name : names)
    {
        std::cout << name << '\n';
    }
}
```

Output:

```text
Amit
Rahul
Deep
```

---

# 33. `std::array` of Custom Objects

You can store objects inside an `std::array`.

Example:

```cpp
#include <array>
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
    std::array<Student, 3> students = {{
        {101, "Amit"},
        {102, "Rahul"},
        {103, "Deep"}
    }};

    for (const auto& student : students)
    {
        std::cout << student.id
                  << " "
                  << student.name
                  << '\n';
    }
}
```

Output:

```text
101 Amit
102 Rahul
103 Deep
```

---

# 34. Multidimensional `std::array`

You can create multidimensional arrays using nested `std::array`.

Example:

```cpp
std::array<std::array<int, 3>, 2> matrix = {{
    {1, 2, 3},
    {4, 5, 6}
}};
```

Conceptually:

```text
1 2 3
4 5 6
```

Access:

```cpp
std::cout << matrix[0][1];
```

Output:

```text
2
```

---

## Traversing

```cpp
for (const auto& row : matrix)
{
    for (int value : row)
    {
        std::cout << value << " ";
    }

    std::cout << '\n';
}
```

Output:

```text
1 2 3
4 5 6
```

---

# 35. `std::array` of Pairs

Example:

```cpp
std::array<std::pair<int, std::string>, 3> employees = {{
    {101, "Amit"},
    {102, "Rahul"},
    {103, "Deep"}
}};
```

Access:

```cpp
std::cout << employees[0].first;
std::cout << employees[0].second;
```

Output:

```text
101
Amit
```

---

# 36. `std::array` of Arrays

Nested arrays can be used to represent fixed-size matrices.

```cpp
std::array<std::array<int, 3>, 3> matrix = {{
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
}};
```

Conceptually:

```text
+---+---+---+
| 1 | 2 | 3 |
+---+---+---+
| 4 | 5 | 6 |
+---+---+---+
| 7 | 8 | 9 |
+---+---+---+
```

This is useful when both dimensions are fixed at compile time.

---

# 37. Function Parameters

You can pass an `std::array` to a function.

Because the size is part of its type, the function must normally specify the size.

Example:

```cpp
void print(
    const std::array<int, 5>& arr
)
{
    for (int x : arr)
    {
        std::cout << x << " ";
    }
}
```

Call:

```cpp
std::array<int, 5> arr = {
    1, 2, 3, 4, 5
};

print(arr);
```

---

# 38. Generic Function with Array Size

If you want a function that accepts any `std::array` size:

```cpp
template<typename T, std::size_t N>
void print(const std::array<T, N>& arr)
{
    for (const auto& value : arr)
    {
        std::cout << value << " ";
    }
}
```

Now this works:

```cpp
std::array<int, 3> a = {
    1, 2, 3
};

std::array<int, 5> b = {
    10, 20, 30, 40, 50
};

print(a);
print(b);
```

The compiler deduces:

```text
T = int
N = 3
```

for the first call and:

```text
T = int
N = 5
```

for the second.

---

# 39. Passing by Value vs Reference

## By Value

```cpp
void process(std::array<int, 5> arr)
{
}
```

This copies the entire array.

---

## By Const Reference

```cpp
void process(
    const std::array<int, 5>& arr
)
{
}
```

No array copy is made.

This is usually preferred when the function only needs to read the array.

---

## By Reference

```cpp
void process(
    std::array<int, 5>& arr
)
{
    arr[0] = 100;
}
```

The original array can be modified.

---

# 40. Return from Functions

An `std::array` can be returned by value.

Example:

```cpp
std::array<int, 3> createArray()
{
    return {10, 20, 30};
}
```

Usage:

```cpp
auto arr = createArray();
```

Modern C++ efficiently handles return-by-value through copy elision and move semantics where appropriate.

---

# 41. `constexpr` and `std::array`

`std::array` works well with compile-time programming.

Example:

```cpp
constexpr std::array<int, 3> values = {
    10, 20, 30
};
```

The array can be used in constant-expression contexts when the operations involved are `constexpr`.

Example:

```cpp
constexpr auto first = values[0];
```

---

# 42. Comparison Operators

`std::array` supports comparisons.

Example:

```cpp
std::array<int, 3> a = {
    1, 2, 3
};

std::array<int, 3> b = {
    1, 2, 3
};

if (a == b)
{
    std::cout << "Equal";
}
```

Output:

```text
Equal
```

Comparisons are lexicographical.

For example:

```text
a = 1 2 3
b = 1 2 4
```

Then:

```cpp
a < b
```

is true because the first differing element is:

```text
3 < 4
```

### C++20

`std::array` supports the modern three-way comparison framework when its element type supports it.

```cpp
auto result = (a <=> b);
```

---

# 43. Iterator Category

`std::array` provides:

```text
Random Access Iterators
```

and, in modern C++, its iterators satisfy the contiguous iterator requirements.

This means you can perform operations such as:

```cpp
++it;
--it;

it + 2;
it - 2;

it[2];

it1 < it2;
it1 > it2;
it1 <= it2;
it1 >= it2;
```

Example:

```cpp
auto it = arr.begin();

std::cout << *(it + 2);
```

This accesses the third element.

---

# 44. Time Complexity

| Operation | Complexity |
|---|---:|
| `operator[]` | O(1) |
| `at()` | O(1) |
| `front()` | O(1) |
| `back()` | O(1) |
| `data()` | O(1) |
| `size()` | O(1) |
| `max_size()` | O(1) |
| `empty()` | O(1) |
| `begin()` | O(1) |
| `end()` | O(1) |
| `rbegin()` | O(1) |
| `rend()` | O(1) |
| `fill()` | O(n) |
| `swap()` | O(n) |
| `find()` | O(n) |
| `count()` | O(n) |
| `sort()` | O(n log n) |
| `reverse()` | O(n) |
| `binary_search()` | O(log n) |
| `min_element()` | O(n) |
| `max_element()` | O(n) |
| `accumulate()` | O(n) |

Here:

```text
n = number of elements
```

---

# 45. `std::array` vs C Array

| Feature | C Array | `std::array` |
|---|---|---|
| Fixed size | Yes | Yes |
| Compile-time size | Yes | Yes |
| `size()` | No | Yes |
| `at()` | No | Yes |
| `front()` | No | Yes |
| `back()` | No | Yes |
| `data()` | Direct array-to-pointer conversion | Yes |
| `fill()` member | No | Yes |
| `swap()` member | No | Yes |
| STL iterators | No standard member iterators | Yes |
| STL algorithms | Can work through pointers | Directly supported |
| Copy assignment | No built-in array assignment | Yes |
| Copy construction | Not as an array object | Yes |
| Type includes size | In array declarations, yes | Yes |
| Bounds checking | No | `at()` provides it |
| Contiguous | Yes | Yes |

### Important

A C-style array:

```cpp
int a[5];
```

cannot be assigned:

```cpp
int b[5];

b = a;  // Error
```

But `std::array` supports assignment:

```cpp
std::array<int, 5> a;
std::array<int, 5> b;

b = a;
```

---

# 46. `std::array` vs `std::vector`

| Feature | `std::array` | `std::vector` |
|---|---|---|
| Size | Fixed | Dynamic |
| Size known at compile time | Yes | No |
| Contiguous storage | Yes | Yes |
| Random access | O(1) | O(1) |
| `push_back()` | No | Yes |
| `pop_back()` | No | Yes |
| `resize()` | No | Yes |
| `reserve()` | No | Yes |
| `capacity()` | No | Yes |
| `size()` | Yes | Yes |
| `at()` | Yes | Yes |
| `data()` | Yes | Yes |
| Memory allocation | Usually no dynamic allocation for elements | Dynamic storage normally used |
| Best for | Fixed-size data | Dynamic-size data |

### Rule

Use:

```cpp
std::array
```

when the size is fixed.

Use:

```cpp
std::vector
```

when the size can change.

---

# 47. `std::array` vs `std::deque`

| Feature | `std::array` | `std::deque` |
|---|---|---|
| Size | Fixed | Dynamic |
| Contiguous | Yes | No |
| Random access | O(1) | O(1) |
| `push_back()` | No | Yes |
| `push_front()` | No | Yes |
| `pop_back()` | No | Yes |
| `pop_front()` | No | Yes |
| Dynamic growth | No | Yes |

---

# 48. `std::array` vs `std::list`

| Feature | `std::array` | `std::list` |
|---|---|---|
| Storage | Contiguous | Linked nodes |
| Size | Fixed | Dynamic |
| Random access | O(1) | O(n) |
| `push_back()` | No | Yes |
| `push_front()` | No | Yes |
| Insert/erase with iterator | No container operation | O(1) |
| Cache locality | Good | Generally poor |
| Memory overhead | Low | Higher |

---

# 49. `std::array` vs `std::vector` — Simple Rule

Remember:

```text
Known fixed size
       ↓
std::array
```

```text
Size can change
       ↓
std::vector
```

Example:

### Fixed 12 months

```cpp
std::array<int, 12> monthlySales;
```

### Unknown number of transactions

```cpp
std::vector<Transaction> transactions;
```

---

# 50. Advantages

## 1. Fixed Size

The size cannot accidentally change.

```cpp
std::array<int, 5> arr;
```

always contains five elements.

---

## 2. Contiguous Memory

Elements are stored contiguously.

This provides:

- Fast random access.
- Good cache locality.
- Easy interoperability with pointer-based APIs.

---

## 3. STL Compatible

Works naturally with:

```cpp
std::sort()
std::find()
std::reverse()
std::count()
std::accumulate()
```

and many other algorithms.

---

## 4. Random Access

```cpp
arr[3]
```

takes:

```text
O(1)
```

---

## 5. Better Interface than C Arrays

Provides:

```cpp
size()
empty()
at()
front()
back()
begin()
end()
fill()
swap()
data()
```

---

## 6. Copy Assignment

Unlike raw C arrays:

```cpp
std::array<int, 5> a;
std::array<int, 5> b;

b = a;
```

is valid.

---

## 7. Low Overhead

For ordinary element types, an `std::array<T, N>` has essentially the storage needed for its `N` elements, plus any implementation-required representation details.

It does not require a separate dynamic allocation merely to hold the elements.

---

# 51. Disadvantages

## 1. Fixed Size

Cannot grow:

```cpp
arr.push_back(10);   // Error
```

---

## 2. Cannot Resize

```cpp
arr.resize(10);      // Error
```

---

## 3. No Insert Operation

```cpp
arr.insert(...);     // Error
```

---

## 4. No Erase Operation

```cpp
arr.erase(...);      // Error
```

---

## 5. Not Suitable for Unknown Size

If the number of elements is unknown or changes during runtime, use:

```cpp
std::vector
```

instead.

---

# 52. Common Mistakes

## Mistake 1: Expecting Dynamic Size

This is invalid:

```cpp
std::array<int, 5> arr;

arr.resize(10);
```

`std::array` has fixed size.

---

## Mistake 2: Using `push_back()`

Invalid:

```cpp
arr.push_back(100);
```

Use `std::vector` if elements need to be appended dynamically.

---

## Mistake 3: Using `pop_back()`

Invalid:

```cpp
arr.pop_back();
```

The container size cannot change.

---

## Mistake 4: Out-of-Bounds Access

This is dangerous:

```cpp
std::array<int, 5> arr;

arr[10] = 100;
```

`operator[]` does not perform bounds checking.

Use:

```cpp
arr.at(10);
```

if bounds checking is required.

---

## Mistake 5: Reading an Uninitialized Local Array

This:

```cpp
std::array<int, 5> arr;

std::cout << arr[0];
```

reads an indeterminate `int` value.

Prefer:

```cpp
std::array<int, 5> arr{};
```

which initializes the integers to zero.

Or assign values before reading them.

---

## Mistake 6: Thinking `max_size()` Is a Larger Capacity

For:

```cpp
std::array<int, 5>
```

there is no dynamic capacity separate from its fixed size.

```cpp
arr.max_size()
```

is effectively:

```text
5
```

---

## Mistake 7: Forgetting Size Is Part of the Type

These are different types:

```cpp
std::array<int, 5>
std::array<int, 10>
```

Therefore:

```cpp
std::array<int, 5> a;
std::array<int, 10> b;

a = b;  // Error
```

---

## Mistake 8: Accessing an Empty Array

This is invalid:

```cpp
std::array<int, 0> arr;

arr.front();
```

There is no first element.

---

# 53. Common Interview Questions

## Q1. What is `std::array`?

`std::array` is a fixed-size sequence container introduced in C++11 that provides STL functionality and contiguous storage.

---

## Q2. Is `std::array` dynamic?

No.

Its size is fixed at compile time.

---

## Q3. Is `std::array` contiguous?

Yes.

Its elements are stored contiguously.

---

## Q4. Does `std::array` support random access?

Yes.

Both:

```cpp
arr[index]
```

and:

```cpp
arr.at(index)
```

provide constant-time element access.

---

## Q5. Difference between `[]` and `at()`?

| `operator[]` | `at()` |
|---|---|
| No bounds checking | Bounds checking |
| O(1) | O(1) |
| Invalid index → undefined behavior | Invalid index → `std::out_of_range` |

---

## Q6. Can the size of `std::array` change?

No.

---

## Q7. Does `std::array` support `push_back()`?

No.

---

## Q8. Does `std::array` support `resize()`?

No.

---

## Q9. What is the difference between `std::array<int, 5>` and `std::array<int, 10>`?

They are different C++ types.

The second template argument is part of the type.

---

## Q10. Does `std::array` allocate memory dynamically?

The elements of an ordinary `std::array<T, N>` are stored directly within the array object; it does not perform a separate dynamic allocation for those elements.

If `T` itself manages dynamic memory, that is a property of `T`.

---

## Q11. What iterator category does `std::array` provide?

It provides random-access iterators and, in modern C++, contiguous iterators.

---

## Q12. Can `std::array` be copied?

Yes.

```cpp
std::array<int, 5> a;
std::array<int, 5> b = a;
```

---

## Q13. Can arrays with different sizes be assigned?

No.

```cpp
std::array<int, 5> a;
std::array<int, 10> b;

a = b;   // Error
```

---

## Q14. What is `data()`?

`data()` returns a pointer to the underlying contiguous storage.

```cpp
int* p = arr.data();
```

---

## Q15. What does `fill()` do?

It assigns the same value to every element.

```cpp
arr.fill(10);
```

Result:

```text
10 10 10 10 10
```

---

## Q16. What does `empty()` return?

It returns `true` only when the array size is zero.

```cpp
std::array<int, 0> arr;

arr.empty();   // true
```

---

## Q17. Can an `std::array` have zero elements?

Yes.

```cpp
std::array<int, 0> arr;
```

It is a valid type, but there are no elements to access.

---

## Q18. What is the difference between `std::array` and a C array?

`std::array` provides:

```text
size()
at()
front()
back()
begin()
end()
fill()
swap()
```

and supports normal STL container operations and algorithms.

---

## Q19. What is the difference between `std::array` and `std::vector`?

```text
std::array
    ↓
Fixed size

std::vector
    ↓
Dynamic size
```

Both provide contiguous storage and random access.

---

## Q20. When should you use `std::array`?

Use it when:

```text
Size is known at compile time
+
Size will not change
+
Contiguous storage is desired
+
STL functionality is useful
```

---

# 54. Important C++ Version Features

| Feature | Standard |
|---|---|
| `std::array` | C++11 |
| Range-based `for` | C++11 |
| `cbegin()` / `cend()` | C++11 |
| `crbegin()` / `crend()` | C++14 |
| `std::get()` tuple interface | C++11 |
| Structured bindings | C++17 |
| `std::array` `constexpr` improvements | C++14/C++17/C++20 depending on operation |
| Three-way comparison support | C++20 |
| `std::to_array()` | C++20 |

---

# 55. `std::to_array()` — C++20

C++20 provides:

```cpp
std::to_array()
```

It can create an `std::array` from a built-in array or from a braced initializer.

Example:

```cpp
#include <array>

auto arr = std::to_array({
    10, 20, 30, 40, 50
});
```

The type is deduced as approximately:

```cpp
std::array<int, 5>
```

You can also convert a C-style array:

```cpp
int values[] = {
    10, 20, 30
};

auto arr = std::to_array(values);
```

Now:

```text
arr
 ↓
std::array<int, 3>
```

This is useful when you want to convert fixed-size built-in arrays into an STL container.

---

# 56. `std::array` with `constexpr`

Example:

```cpp
#include <array>

constexpr std::array<int, 5> values = {
    10, 20, 30, 40, 50
};

constexpr int first = values[0];
```

The compiler can evaluate appropriate operations at compile time.

This makes `std::array` useful for:

- Lookup tables.
- Compile-time configuration.
- Constant data.
- Embedded programming.
- Template metaprogramming.

---

# 57. `std::array` and C-Style API

Because the elements are contiguous:

```cpp
std::array<int, 5> arr = {
    10, 20, 30, 40, 50
};
```

you can pass:

```cpp
arr.data()
```

to a function expecting:

```cpp
int*
```

Example:

```cpp
void process(const int* data, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        std::cout << data[i] << " ";
    }
}
```

Call:

```cpp
process(arr.data(), arr.size());
```

Output:

```text
10 20 30 40 50
```

---

# 58. Complete Example — Basic

```cpp
#include <iostream>
#include <array>

int main()
{
    std::array<int, 5> arr = {
        50, 20, 40, 10, 30
    };

    std::cout << "Elements: ";

    for (int x : arr)
    {
        std::cout << x << " ";
    }

    std::cout << '\n';

    std::cout << "First: "
              << arr.front()
              << '\n';

    std::cout << "Last: "
              << arr.back()
              << '\n';

    std::cout << "Size: "
              << arr.size()
              << '\n';

    std::cout << "Element at index 2: "
              << arr.at(2)
              << '\n';

    return 0;
}
```

Possible output:

```text
Elements: 50 20 40 10 30
First: 50
Last: 30
Size: 5
Element at index 2: 40
```

---

# 59. Complete Example — STL Algorithms

```cpp
#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

int main()
{
    std::array<int, 5> arr = {
        50, 20, 40, 10, 30
    };

    std::sort(arr.begin(), arr.end());

    std::cout << "Sorted: ";

    for (int x : arr)
    {
        std::cout << x << " ";
    }

    std::cout << '\n';

    auto minIt = std::min_element(
        arr.begin(),
        arr.end()
    );

    auto maxIt = std::max_element(
        arr.begin(),
        arr.end()
    );

    int sum = std::accumulate(
        arr.begin(),
        arr.end(),
        0
    );

    std::cout << "Minimum: "
              << *minIt
              << '\n';

    std::cout << "Maximum: "
              << *maxIt
              << '\n';

    std::cout << "Sum: "
              << sum
              << '\n';

    return 0;
}
```

Output:

```text
Sorted: 10 20 30 40 50
Minimum: 10
Maximum: 50
Sum: 150
```

---

# 60. Complete Example — `at()` vs `[]`

```cpp
#include <iostream>
#include <array>
#include <stdexcept>

int main()
{
    std::array<int, 3> arr = {
        10, 20, 30
    };

    std::cout << arr[1] << '\n';

    try
    {
        std::cout << arr.at(10) << '\n';
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Index out of range\n";
    }

    return 0;
}
```

Output:

```text
20
Index out of range
```

---

# 61. Complete Example — `fill()`

```cpp
#include <iostream>
#include <array>

int main()
{
    std::array<int, 5> arr;

    arr.fill(100);

    for (int x : arr)
    {
        std::cout << x << " ";
    }

    return 0;
}
```

Output:

```text
100 100 100 100 100
```

---

# 62. Complete Example — `swap()`

```cpp
#include <iostream>
#include <array>

int main()
{
    std::array<int, 3> a = {
        1, 2, 3
    };

    std::array<int, 3> b = {
        4, 5, 6
    };

    a.swap(b);

    std::cout << "A: ";

    for (int x : a)
    {
        std::cout << x << " ";
    }

    std::cout << '\n';

    std::cout << "B: ";

    for (int x : b)
    {
        std::cout << x << " ";
    }

    return 0;
}
```

Output:

```text
A: 4 5 6
B: 1 2 3
```

---

# 63. Complete Example — `std::array` as Function Parameter

```cpp
#include <iostream>
#include <array>

template<typename T, std::size_t N>
void print(const std::array<T, N>& arr)
{
    for (const auto& value : arr)
    {
        std::cout << value << " ";
    }

    std::cout << '\n';
}

int main()
{
    std::array<int, 3> a = {
        1, 2, 3
    };

    std::array<int, 5> b = {
        10, 20, 30, 40, 50
    };

    print(a);
    print(b);

    return 0;
}
```

Output:

```text
1 2 3
10 20 30 40 50
```

---

# 64. Complete Example — Multidimensional Array

```cpp
#include <iostream>
#include <array>

int main()
{
    std::array<std::array<int, 3>, 2> matrix = {{
        {1, 2, 3},
        {4, 5, 6}
    }};

    for (const auto& row : matrix)
    {
        for (int value : row)
        {
            std::cout << value << " ";
        }

        std::cout << '\n';
    }

    return 0;
}
```

Output:

```text
1 2 3
4 5 6
```

---

# 65. Complete Example — Structured Binding

```cpp
#include <iostream>
#include <array>

int main()
{
    std::array<int, 3> arr = {
        10, 20, 30
    };

    auto [a, b, c] = arr;

    std::cout << a << " "
              << b << " "
              << c
              << '\n';

    return 0;
}
```

Output:

```text
10 20 30
```

---

# 66. Complete Example — C++20 `to_array()`

```cpp
#include <iostream>
#include <array>

int main()
{
    auto arr = std::to_array({
        10, 20, 30, 40, 50
    });

    for (int x : arr)
    {
        std::cout << x << " ";
    }

    return 0;
}
```

Output:

```text
10 20 30 40 50
```

The compiler deduces:

```cpp
std::array<int, 5>
```

---

# 67. Quick Comparison

## `std::array`

```text
Fixed size
     ↓
Contiguous memory
     ↓
Random access
     ↓
O(1)
     ↓
STL compatible
```

## `std::vector`

```text
Dynamic size
     ↓
Contiguous memory
     ↓
Random access
     ↓
O(1)
     ↓
push_back()
resize()
```

## `std::list`

```text
Dynamic size
     ↓
Linked nodes
     ↓
No random access
     ↓
O(n) access
```

---

# 68. When to Use `std::array`

Use `std::array` when:

```text
Size is known at compile time
        +
Size will not change
        +
Contiguous storage is desired
        +
Random access is required
        +
STL algorithms are useful
```

### Examples

Fixed number of:

```text
Months           -> 12
Days in week     -> 7
RGB channels     -> 3
Coordinates      -> 2 or 3
Matrix dimensions
Lookup tables
Fixed configuration values
Hardware registers
Compile-time data
```

Example:

```cpp
std::array<int, 7> days = {
    1, 2, 3, 4, 5, 6, 7
};
```

---

# 69. When NOT to Use `std::array`

Do not use `std::array` when the number of elements changes during execution.

For example:

```text
User enters unknown number of records
```

Use:

```cpp
std::vector<Record>
```

instead.

If you need frequent insertion/removal from both ends:

```cpp
std::deque
```

may be appropriate.

If you need linked-list-specific insertion/erasure behavior:

```cpp
std::list
```

may be appropriate.

---

# 70. Important Differences to Remember

### `std::array` vs C array

```text
Both:
    Fixed size
    Contiguous

std::array additionally:
    size()
    at()
    front()
    back()
    begin()
    end()
    fill()
    swap()
    copy assignment
    STL container interface
```

### `std::array` vs `vector`

```text
array:
    Fixed size

vector:
    Dynamic size
```

### `std::array` vs `map`

These are completely different containers.

```text
std::array
    ↓
Sequence container
    ↓
Access by index

std::map
    ↓
Associative container
    ↓
Access by key
```

---

# 71. Important Interview Summary

Remember these points:

```text
std::array
    ↓
C++11
    ↓
Fixed-size container
    ↓
Size is part of the type
    ↓
Contiguous memory
    ↓
Random access
    ↓
O(1) element access
    ↓
STL compatible
```

### Access

```cpp
arr[index]
```

No bounds checking.

```cpp
arr.at(index)
```

Bounds checking.

### First and last

```cpp
arr.front()
arr.back()
```

### Underlying memory

```cpp
arr.data()
```

### Size

```cpp
arr.size()
```

### Fill

```cpp
arr.fill(value)
```

### Swap

```cpp
arr.swap(other)
```

### Iteration

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

### Tuple-style access

```cpp
std::get<0>(arr)
```

### C++17

```cpp
auto [a, b, c] = arr;
```

### C++20

```cpp
std::to_array(...)
```

---

# 72. Final Summary

`std::array` is the STL solution when you need a **fixed-size array**.

```cpp
std::array<int, 5> arr = {
    10, 20, 30, 40, 50
};
```

Its most important properties are:

```text
Header             : <array>

Introduced         : C++11

Container type     : Sequence container

Size               : Fixed

Size known         : Compile time

Memory             : Contiguous

Random access      : Yes

Element access     : O(1)

Bounds checking    : at()

First element      : front()

Last element       : back()

Raw pointer        : data()

Number of elements : size()

Fill               : fill()

Swap               : swap()

Iterator           : Random-access / contiguous

push_back()        : No

pop_back()         : No

resize()           : No

insert()           : No

erase()            : No

Best use           : Fixed-size collections
```

## One-Line Definition

> **`std::array` is a C++11 fixed-size sequence container that stores elements contiguously and provides O(1) random access together with the standard STL container interface.**

## Easy Memory Trick

```text
std::array
     ↓
Fixed Size
     ↓
Contiguous Memory
     ↓
Index Access
     ↓
O(1)
     ↓
STL Functions
```

### Final Decision

```text
Do I know the size at compile time?
              |
             Yes
              |
              v
        Will the size change?
              |
             No
              |
              v
        Use std::array
```

If the size can change:

```text
Use std::vector
```