# C++ `std::vector` — Complete Notes

## 1. What is `std::vector`?

`std::vector` is a **sequence container** provided by the C++ Standard Library.

It is commonly described as a **dynamic array** because:

- It stores elements in **contiguous memory**.
- Its size can grow and shrink at runtime.
- It provides **O(1) random access**.
- It automatically manages its allocated memory.
- It works efficiently with standard algorithms.
- It provides iterators.

Example:

```cpp
std::vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);
```

Result:

```text
10 20 30
```

---

# 2. Header File

```cpp
#include <vector>
```

For common algorithms:

```cpp
#include <algorithm>
```

For `std::accumulate()`:

```cpp
#include <numeric>
```

For `std::move()`:

```cpp
#include <utility>
```

For `std::greater`:

```cpp
#include <functional>
```

---

# 3. Namespace

You can write:

```cpp
using namespace std;

vector<int> v;
```

Or preferably use the explicit namespace:

```cpp
std::vector<int> v;
```

---

# 4. Basic Syntax

```cpp
vector<data_type> name;
```

Examples:

```cpp
vector<int> numbers;

vector<double> salary;

vector<char> letters;

vector<string> names;
```

With explicit namespace:

```cpp
std::vector<int> numbers;
```

---

# 5. Template Declaration

Conceptually, `std::vector` is declared as:

```cpp
template<
    class T,
    class Allocator = std::allocator<T>
>
class vector;
```

## Template Parameters

### `T`

The type of element stored in the vector.

Example:

```cpp
vector<int>
vector<double>
vector<string>
```

### `Allocator`

Controls memory allocation.

The default allocator is:

```cpp
std::allocator<T>
```

Most applications do not need to specify an allocator manually.

---

# 6. Why Do We Need `vector`?

A normal C-style array has a fixed size:

```cpp
int arr[3];
```

Its number of elements cannot automatically grow.

A vector can grow dynamically:

```cpp
vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);
v.push_back(40);
```

The vector automatically manages the storage required for the additional elements.

---

# 7. Main Characteristics

`std::vector` provides:

- Dynamic size
- Contiguous storage
- O(1) random access
- Fast access to the first and last element
- Efficient insertion at the end
- Automatic memory management
- Excellent cache locality
- Iterator support
- Compatibility with standard algorithms
- Direct access to underlying storage through `data()`

---

# 8. Contiguous Memory

One of the most important properties of `std::vector` is that its elements are stored contiguously.

Example:

```cpp
vector<int> v = {10, 20, 30, 40, 50};
```

Conceptually:

```text
+----+----+----+----+----+
| 10 | 20 | 30 | 40 | 50 |
+----+----+----+----+----+
```

The elements are adjacent in memory.

This is why:

```cpp
v[0]
v[1]
v[2]
```

can be accessed efficiently.

---

# 9. Why Random Access is O(1)

Suppose the first element starts at address `1000` and each `int` takes 4 bytes.

Conceptually:

```text
Element       Address

v[0]          1000
v[1]          1004
v[2]          1008
v[3]          1012
```

The address of element `i` can conceptually be calculated as:

```text
base_address + i × sizeof(T)
```

Therefore:

```cpp
v[100];
```

does not require traversing elements `0` through `99`.

Complexity:

```text
O(1)
```

---

# 10. Internal Working

A vector is commonly implemented using three pieces of pointer-like state:

```text
begin
end
end_of_storage
```

Conceptually:

```text
begin                         end
  |                            |
  v                            v
+----+----+----+----+----+----+
| 10 | 20 | 30 |    |    |    |
+----+----+----+----+----+----+
                 ^
                 |
          end_of_storage
```

Meaning:

```text
begin
  ↓
Address of the first element

end
  ↓
Position one past the last element

end_of_storage
  ↓
Position one past allocated storage
```

The exact implementation is library-specific, but this is a useful conceptual model.

---

# 11. Size vs Capacity

This is one of the most important vector concepts.

## Size

```cpp
v.size();
```

means:

```text
Number of elements currently stored
```

Example:

```cpp
vector<int> v = {10, 20, 30};
```

Then:

```text
size = 3
```

---

## Capacity

```cpp
v.capacity();
```

means:

```text
Number of elements that can currently be stored
without requiring a reallocation
```

For example, an implementation might have:

```text
size     = 3
capacity = 4
```

The exact capacity is implementation-dependent.

---

# 12. Size vs Capacity Example

```cpp
vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);
```

Conceptually:

```text
Size:

3

Capacity:

possibly 4
```

The important point is:

```text
size <= capacity
```

When:

```text
size == capacity
```

another insertion may require reallocation.

---

# 13. Dynamic Growth

Suppose the vector has:

```text
Size     = 4
Capacity = 4
```

Then:

```cpp
v.push_back(50);
```

may require more storage.

Conceptually:

```text
Old storage:

+----+----+----+----+
| 10 | 20 | 30 | 40 |
+----+----+----+----+

New larger storage:

+----+----+----+----+----+----+----+----+
| 10 | 20 | 30 | 40 | 50 |    |    |    |
+----+----+----+----+----+----+----+----+
```

The implementation generally:

1. Allocates a larger block.
2. Moves or copies existing elements.
3. Constructs the new element.
4. Destroys old elements when appropriate.
5. Releases old storage.
6. Updates its internal storage information.

---

# 14. Growth Factor

The C++ Standard does **not** specify a particular growth factor.

An implementation might use a strategy resembling:

```text
1 → 2 → 4 → 8 → 16 → 32
```

or another growth strategy.

Therefore, do not write:

```text
vector always doubles its capacity
```

as a language guarantee.

The important guarantee is that repeated `push_back()` operations have **amortized O(1)** complexity.

---

# 15. Constructors — Complete Overview

## 15.1 Default Constructor

```cpp
vector<int> v;
```

Creates an empty vector.

```text
size     = 0
capacity = implementation-dependent
```

---

# 16. Size Constructor

```cpp
vector<int> v(5);
```

Creates five value-initialized `int` elements.

Result:

```text
0 0 0 0 0
```

For class types, the elements are value-initialized according to their type.

---

# 17. Fill Constructor

```cpp
vector<int> v(5, 100);
```

Creates five elements, each initialized with `100`.

Result:

```text
100 100 100 100 100
```

Syntax:

```cpp
vector<T> v(count, value);
```

---

# 18. Initializer List Constructor

```cpp
vector<int> v = {1, 2, 3, 4, 5};
```

Or:

```cpp
vector<int> v{1, 2, 3, 4, 5};
```

Result:

```text
1 2 3 4 5
```

---

# 19. Range Constructor

```cpp
vector<int> a = {10, 20, 30};

vector<int> b(a.begin(), a.end());
```

`b` receives copies of the elements in the specified range.

Syntax:

```cpp
vector<T> v(first, last);
```

The range is:

```text
[first, last)
```

---

# 20. Copy Constructor

```cpp
vector<int> v1 = {1, 2, 3};

vector<int> v2(v1);
```

`v2` receives copies of all elements.

The two vectors have independent storage.

Conceptually:

```text
v1: [1][2][3]

v2: [1][2][3]
```

Changing one vector does not change the other.

---

# 21. Move Constructor

```cpp
vector<int> v1 = {1, 2, 3};

vector<int> v2(std::move(v1));
```

The resources of `v1` can be transferred to `v2`.

This can avoid allocating and copying all elements.

Use:

```cpp
#include <utility>
```

for `std::move`.

After moving, `v1` remains a valid vector, but its exact contents should not be assumed unless specified.

---

# 22. Allocator Constructor

An allocator can be specified explicitly:

```cpp
vector<int, std::allocator<int>> v;
```

This is rarely necessary in normal application code.

The default is:

```cpp
std::allocator<T>
```

---

# 23. Constructor Summary

```cpp
vector<int> a;                    // empty

vector<int> b(5);                 // 5 value-initialized elements

vector<int> c(5, 10);             // 5 elements containing 10

vector<int> d = {1, 2, 3};        // initializer list

vector<int> e(d.begin(), d.end()); // range

vector<int> f(d);                 // copy

vector<int> g(std::move(d));      // move
```

---

# 24. Assignment

## 24.1 Copy Assignment

```cpp
vector<int> v1 = {1, 2, 3};
vector<int> v2;

v2 = v1;
```

Copies the elements.

---

## 24.2 Initializer List Assignment

```cpp
v2 = {10, 20, 30};
```

Replaces the contents.

---

## 24.3 Move Assignment

```cpp
v2 = std::move(v1);
```

Transfers resources where permitted by allocator rules.

---

# 25. `assign()`

`assign()` replaces the current contents.

## Count and Value

```cpp
v.assign(5, 10);
```

Result:

```text
10 10 10 10 10
```

---

## Range

```cpp
v.assign(other.begin(), other.end());
```

---

## Initializer List

```cpp
v.assign({1, 2, 3});
```

---

# 26. Adding Elements

The main insertion operations are:

```cpp
push_back()
emplace_back()

insert()
emplace()
```

---

# 27. `push_back()`

Adds an element at the end.

```cpp
vector<int> v;

v.push_back(10);
v.push_back(20);
```

Result:

```text
10 20
```

### Complexity

```text
Amortized: O(1)
Worst case for one insertion: O(n)
```

The worst case occurs when reallocation is required.

---

# 28. `emplace_back()`

Constructs an element directly at the end.

```cpp
vector<int> v;

v.emplace_back(20);
```

For class types:

```cpp
vector<pair<int, int>> v;

v.emplace_back(1, 2);
```

The pair can be constructed directly in vector storage.

### Complexity

```text
Amortized: O(1)
Worst case: O(n)
```

---

# 29. `push_back()` vs `emplace_back()`

Example:

```cpp
vector<pair<int, int>> v;

v.push_back({1, 2});

v.emplace_back(3, 4);
```

General idea:

```text
push_back()
    ↓
Provides an object/value to insert

emplace_back()
    ↓
Provides constructor arguments
    ↓
Constructs the object in place
```

Do not assume `emplace_back()` is always faster.

For simple types or already-existing objects, the difference may be negligible.

---

# 30. `insert()`

## Single Element

```cpp
vector<int> v = {10, 20, 40};

v.insert(v.begin() + 2, 30);
```

Result:

```text
10 20 30 40
```

Elements after the insertion position must be shifted.

Complexity:

```text
O(n)
```

in the general case.

---

# 31. `insert()` — Multiple Copies

```cpp
v.insert(v.begin(), 3, 5);
```

Inserts:

```text
5 5 5
```

at the beginning.

Example:

```text
Before:

10 20 30

After:

5 5 5 10 20 30
```

Complexity is linear in the amount of movement/construction required.

---

# 32. `insert()` — Range

```cpp
vector<int> source = {1, 2, 3};

v.insert(v.begin(), source.begin(), source.end());
```

Copies the range into `v`.

---

# 33. `insert()` — Initializer List

```cpp
v.insert(v.begin(), {1, 2, 3});
```

Inserts:

```text
1 2 3
```

before the current first element.

---

# 34. `emplace()`

Constructs an element before the specified position.

```cpp
vector<int> v = {10, 20, 40};

v.emplace(v.begin() + 2, 30);
```

Result:

```text
10 20 30 40
```

Because elements after the insertion point may need to move, middle insertion is generally:

```text
O(n)
```

---

# 35. Front, Middle and Back Insertion

Important rule:

```text
Vector is optimized for access and operations at the back.
```

### Back

```cpp
v.push_back(value);
```

Amortized:

```text
O(1)
```

### Front

```cpp
v.insert(v.begin(), value);
```

Generally:

```text
O(n)
```

because existing elements need to move.

### Middle

```cpp
v.insert(v.begin() + index, value);
```

Generally:

```text
O(n)
```

because elements after the insertion position need to move.

---

# 36. Accessing Elements

## 36.1 `operator[]`

```cpp
cout << v[0];
```

Provides direct access without bounds checking.

If the index is outside the valid range, behavior is undefined.

Complexity:

```text
O(1)
```

---

# 37. `at()`

```cpp
cout << v.at(1);
```

Provides bounds checking.

If the index is invalid, `std::out_of_range` is thrown.

Example:

```cpp
try
{
    cout << v.at(100);
}
catch (const out_of_range& e)
{
    cout << "Invalid index";
}
```

Complexity:

```text
O(1)
```

---

# 38. `front()`

```cpp
cout << v.front();
```

Returns the first element.

Complexity:

```text
O(1)
```

Calling `front()` on an empty vector is invalid.

---

# 39. `back()`

```cpp
cout << v.back();
```

Returns the last element.

Complexity:

```text
O(1)
```

Calling `back()` on an empty vector is invalid.

---

# 40. `data()`

```cpp
int* p = v.data();
```

Returns a pointer to the underlying contiguous storage.

For a non-const vector:

```cpp
T* p = v.data();
```

For a const vector:

```cpp
const T* p = v.data();
```

Example:

```cpp
vector<int> v = {10, 20, 30};

int* p = v.data();

cout << p[0];
```

Output:

```text
10
```

This is useful when interfacing with APIs that expect a pointer to contiguous elements.

---

# 41. Capacity Functions

Important functions:

```cpp
v.size();
v.capacity();
v.empty();
v.max_size();

v.reserve(n);
v.resize(n);
v.resize(n, value);

v.shrink_to_fit();
```

---

# 42. `size()`

```cpp
v.size();
```

Returns the number of elements currently stored.

Example:

```cpp
vector<int> v = {10, 20, 30};

cout << v.size();
```

Output:

```text
3
```

Complexity:

```text
O(1)
```

---

# 43. `capacity()`

```cpp
v.capacity();
```

Returns the number of elements that can currently be stored without reallocation.

Example:

```text
size     = 5
capacity = 8
```

The vector currently stores five elements and has room for up to eight before another reallocation is required.

---

# 44. `empty()`

```cpp
if (v.empty())
{
    cout << "Vector is empty";
}
```

Returns `true` if:

```text
size == 0
```

Otherwise returns `false`.

Complexity:

```text
O(1)
```

---

# 45. `max_size()`

```cpp
v.max_size();
```

Returns the maximum number of elements the vector can theoretically contain according to the implementation and allocator constraints.

This is generally much larger than the vector's current `size()`.

---

# 46. `reserve()`

```cpp
v.reserve(100);
```

Requests capacity for at least 100 elements.

Important:

```text
reserve() changes capacity
reserve() does not change size
```

Example:

```cpp
vector<int> v;

v.reserve(100);

cout << v.size();     // 0
cout << v.capacity(); // at least 100
```

This can reduce the number of reallocations when the approximate required size is known in advance.

---

# 47. `resize()`

Changes the number of elements.

```cpp
v.resize(10);
```

If the new size is larger, additional elements are appended and value-initialized.

If the new size is smaller, elements at the end are removed.

---

## Resize with a Value

```cpp
v.resize(10, 100);
```

If additional elements are required, they are initialized with `100`.

Important:

```text
resize() changes size
reserve() changes capacity
```

---

# 48. `reserve()` vs `resize()`

| Function | Changes Size | Changes Capacity |
|---|---:|---:|
| `reserve(n)` | No | May increase |
| `resize(n)` | Yes | May increase or retain |
| `clear()` | Yes | Usually no capacity reduction |
| `shrink_to_fit()` | No | Requests reduction |

Example:

```cpp
vector<int> v;

v.reserve(100);
```

Result conceptually:

```text
size     = 0
capacity >= 100
```

But:

```cpp
v.resize(100);
```

results in:

```text
size = 100
```

---

# 49. `shrink_to_fit()`

```cpp
v.shrink_to_fit();
```

Requests that the vector reduce unused capacity.

Important:

```text
shrink_to_fit() is a non-binding request.
```

The implementation may choose not to reduce the capacity.

It can also cause reallocation, which can invalidate iterators, pointers and references.

---

# 50. Removing Elements

Main removal operations:

```cpp
pop_back()
erase()
clear()
```

C++20 also provides the non-member:

```cpp
std::erase()
std::erase_if()
```

---

# 51. `pop_back()`

Removes the last element.

```cpp
v.pop_back();
```

Example:

```text
Before:

10 20 30

After:

10 20
```

Complexity:

```text
O(1)
```

Calling it on an empty vector is invalid.

---

# 52. `erase()` — Single Element

```cpp
v.erase(v.begin());
```

Removes the first element.

Example:

```text
10 20 30

↓

20 30
```

Another example:

```cpp
v.erase(v.begin() + 2);
```

Removes the third element.

Elements after the erased position are shifted.

Complexity:

```text
O(n)
```

in the general case.

---

# 53. `erase()` — Range

```cpp
v.erase(v.begin(), v.begin() + 3);
```

Removes the first three elements.

The erased range is:

```text
[first, last)
```

The `last` iterator is not erased.

Complexity depends on the number of elements erased and the number of elements that must be moved afterward; overall it is linear in the affected elements.

---

# 54. `clear()`

```cpp
v.clear();
```

Removes all elements.

After:

```text
size = 0
```

But:

```text
capacity
```

is not required to become zero.

Example:

```cpp
vector<int> v = {1, 2, 3, 4, 5};

auto old_capacity = v.capacity();

v.clear();

cout << v.size();
cout << v.capacity();
```

The size becomes zero, while capacity generally remains available.

Important:

```text
clear() destroys elements.
clear() does not guarantee releasing allocated storage.
```

---

# 55. C++20 `erase()` and `erase_if()`

C++20 provides non-member convenience functions.

Remove all matching values:

```cpp
std::erase(v, 10);
```

Remove elements satisfying a predicate:

```cpp
std::erase_if(v, [](int x)
{
    return x % 2 == 0;
});
```

Example:

```cpp
vector<int> v = {1, 2, 3, 4, 5, 6};

std::erase_if(v, [](int x)
{
    return x % 2 == 0;
});
```

Result:

```text
1 3 5
```

Header:

```cpp
#include <vector>
```

For these vector-specific non-member functions, the required declarations are provided through the relevant standard library headers.

---

# 56. Iterators — Complete Set

## Normal Iterators

```cpp
v.begin();
v.end();
```

### `begin()`

Points to the first element.

```text
begin
  ↓
10 20 30
```

### `end()`

Points one position after the last element.

```text
10 20 30
         ↑
        end
```

`end()` is not an actual element and must not be dereferenced.

---

# 57. Const Iterators

```cpp
v.cbegin();
v.cend();
```

These provide const iterators.

You can read elements through them but cannot modify elements through the iterator.

Example:

```cpp
for (auto it = v.cbegin(); it != v.cend(); ++it)
{
    cout << *it;
}
```

---

# 58. Reverse Iterators

```cpp
v.rbegin();
v.rend();
```

### `rbegin()`

Starts at the last element.

```text
10 20 30
      ↑
    rbegin
```

### `rend()`

Represents the position before the first element in reverse iteration.

---

# 59. Const Reverse Iterators

```cpp
v.crbegin();
v.crend();
```

Used for read-only reverse traversal.

---

# 60. Iterator Categories

`std::vector` provides:

```text
Random Access Iterators
```

and, in modern C++ terminology, its iterators also satisfy stronger iterator concepts including contiguous iteration.

Because vector storage is contiguous, the iterator supports:

```cpp
++it
--it

it + n
it - n

it[n]

it1 - it2

it1 < it2
it1 <= it2
it1 > it2
it1 >= it2
```

This is a major difference from `list` and `forward_list`.

---

# 61. Traversing a Vector

## Simple Index Loop

```cpp
for (size_t i = 0; i < v.size(); ++i)
{
    cout << v[i] << " ";
}
```

---

## Range-Based Loop

```cpp
for (int x : v)
{
    cout << x << " ";
}
```

---

## Iterator Loop

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
{
    cout << *it << " ";
}
```

---

## Reverse Iterator Loop

```cpp
for (auto it = v.rbegin(); it != v.rend(); ++it)
{
    cout << *it << " ";
}
```

---

# 62. Sorting a Vector

Use:

```cpp
#include <algorithm>
```

Ascending:

```cpp
sort(v.begin(), v.end());
```

Descending:

```cpp
sort(v.begin(), v.end(), greater<int>());
```

Example:

```cpp
vector<int> v = {5, 2, 9, 1};

sort(v.begin(), v.end());
```

Result:

```text
1 2 5 9
```

Complexity:

```text
O(n log n)
```

---

# 63. Searching

## `find()`

```cpp
auto it = find(v.begin(), v.end(), 10);

if (it != v.end())
{
    cout << "Found";
}
```

`find()` performs a linear search.

Complexity:

```text
O(n)
```

---

# 64. Binary Search

For a sorted vector:

```cpp
bool found = binary_search(v.begin(), v.end(), 10);
```

Returns:

```text
true
```

or:

```text
false
```

Complexity:

```text
O(log n)
```

Requirement:

```text
The range must be sorted according to the appropriate ordering.
```

---

# 65. `lower_bound()`

For a sorted vector:

```cpp
auto it = lower_bound(v.begin(), v.end(), 10);
```

Returns an iterator to the first element that is:

```text
>= 10
```

Complexity:

```text
O(log n)
```

for vector/random-access iterators.

---

# 66. `upper_bound()`

```cpp
auto it = upper_bound(v.begin(), v.end(), 10);
```

Returns an iterator to the first element that is:

```text
> 10
```

Complexity:

```text
O(log n)
```

for vector iterators.

---

# 67. `equal_range()`

```cpp
auto range = equal_range(v.begin(), v.end(), 10);
```

Returns:

```text
{lower_bound, upper_bound}
```

for the specified value.

---

# 68. Minimum and Maximum

Use:

```cpp
#include <algorithm>
```

Minimum:

```cpp
*min_element(v.begin(), v.end());
```

Maximum:

```cpp
*max_element(v.begin(), v.end());
```

Example:

```cpp
vector<int> v = {5, 2, 9, 1};

cout << *min_element(v.begin(), v.end());
cout << *max_element(v.begin(), v.end());
```

---

# 69. `count()`

Counts occurrences of a value.

```cpp
count(v.begin(), v.end(), 5);
```

Example:

```cpp
vector<int> v = {1, 5, 2, 5, 3, 5};

cout << count(v.begin(), v.end(), 5);
```

Output:

```text
3
```

Complexity:

```text
O(n)
```

---

# 70. `accumulate()`

Use:

```cpp
#include <numeric>
```

Example:

```cpp
vector<int> v = {1, 2, 3, 4};

int sum = accumulate(v.begin(), v.end(), 0);
```

Result:

```text
10
```

Complexity:

```text
O(n)
```

---

# 71. `swap()`

Two vectors can exchange their contents.

```cpp
vector<int> a = {1, 2};
vector<int> b = {3, 4};

a.swap(b);
```

Result:

```text
a: 3 4
b: 1 2
```

You can also use:

```cpp
swap(a, b);
```

The non-member `swap()` calls the appropriate vector swap operation.

---

# 72. Relational and Comparison Operators

Vectors support equality and lexicographical comparison.

Common operators include:

```cpp
v1 == v2
v1 != v2

v1 <  v2
v1 <= v2

v1 >  v2
v1 >= v2
```

Example:

```cpp
vector<int> a = {1, 2, 3};
vector<int> b = {1, 2, 3};

if (a == b)
{
    cout << "Equal";
}
```

---

# 73. How Vector Comparison Works

Comparison is generally lexicographical.

Example:

```text
a = {1, 2, 3}
b = {1, 3, 2}
```

Compare:

```text
1 == 1
2 < 3
```

Therefore:

```text
a < b
```

For equality, vectors must have:

```text
Same size
+
Corresponding equal elements
```

---

# 74. C++20 Three-Way Comparison

Modern C++ also provides the spaceship operator:

```cpp
v1 <=> v2
```

when the element type supports the required comparison.

It can be used for ordering comparisons in C++20 and later.

The traditional relational operators remain useful and familiar.

---

# 75. Allocator

A vector provides:

```cpp
v.get_allocator();
```

Example:

```cpp
auto alloc = v.get_allocator();
```

The allocator is responsible for memory allocation behavior.

Most normal programs use the default allocator:

```cpp
std::allocator<T>
```

---

# 76. `data()` and C-Style APIs

Because vector storage is contiguous:

```cpp
vector<int> v = {10, 20, 30};

int* p = v.data();
```

You can pass:

```cpp
p
```

to an API expecting a pointer to contiguous `int` elements.

For example:

```cpp
some_c_api(v.data(), v.size());
```

For a non-empty vector, `data()` points to the first element.

---

# 77. Memory Management

A vector automatically manages its dynamic storage.

When the vector grows beyond its current capacity, it may allocate a new block.

When the vector is destroyed:

```cpp
{
    vector<int> v = {1, 2, 3};
}
```

its elements are destroyed and its allocated storage is released.

You normally do not call:

```cpp
delete
free()
```

for vector storage.

---

# 78. `clear()` and Memory

A common interview question:

### Does `clear()` free the vector's capacity?

Not necessarily.

```cpp
v.clear();
```

does:

```text
size → 0
```

but does not guarantee:

```text
capacity → 0
```

If storage reduction is desired, one can request:

```cpp
v.shrink_to_fit();
```

However, `shrink_to_fit()` is non-binding.

---

# 79. `reserve()` and Reallocation

Suppose you know approximately how many elements will be inserted:

```cpp
vector<int> v;

v.reserve(1000);
```

Then insert:

```cpp
for (int i = 0; i < 1000; ++i)
{
    v.push_back(i);
}
```

This can prevent repeated reallocations while growing up to the reserved capacity.

Important:

```text
reserve() does not create 1000 elements.
```

It only requests storage.

Therefore:

```cpp
v[0]
```

is still invalid when:

```text
size() == 0
```

after only `reserve(1000)`.

---

# 80. `resize()` and Elements

```cpp
vector<int> v;

v.resize(5);
```

Now:

```text
size = 5
```

and the five elements exist.

You can access:

```cpp
v[0]
v[1]
...
v[4]
```

This is different from:

```cpp
v.reserve(5);
```

where:

```text
size = 0
```

---

# 81. Iterator and Reference Invalidation

This is an important vector topic.

## Reallocation

When vector storage is reallocated, references, pointers, and iterators to elements in the old storage are invalidated.

Example:

```cpp
vector<int> v = {1, 2, 3};

int* p = &v[0];

v.push_back(4);
```

If `push_back()` causes reallocation, `p` is no longer valid.

---

# 82. `reserve()` and Iterator Invalidation

If:

```cpp
v.reserve(100);
```

and the current capacity was smaller than 100, reallocation occurs.

Existing iterators, pointers, and references are invalidated.

If the requested capacity does not require reallocation, existing element references/iterators are not invalidated by `reserve()`.

---

# 83. `push_back()` Invalidation

If `push_back()` causes reallocation:

```text
All iterators
All references
All pointers
to the old elements
```

are invalidated.

If no reallocation occurs, insertion at the end does not invalidate references and pointers to existing elements, although the past-the-end iterator is invalidated.

---

# 84. `insert()` and `emplace()`

Insertion can invalidate iterators/references/pointers at or after the insertion position, and if reallocation occurs, all iterators/references/pointers are invalidated.

Therefore, after vector insertion, do not blindly continue using an old iterator.

The insertion function returns an iterator to the inserted element, which can be used when appropriate.

---

# 85. `erase()` Invalidation

After:

```cpp
v.erase(it);
```

iterators and references to the erased element and elements after it are invalidated because those later elements may be shifted.

Iterators/references before the erased position remain valid.

---

# 86. `clear()` Invalidation

After:

```cpp
v.clear();
```

iterators, pointers, and references to the erased elements are invalid.

The allocated capacity may remain.

---

# 87. Vector and Exception Safety During Growth

When vector needs to reallocate, it has to transfer existing elements into new storage.

Depending on the element type's constructors, move/copy capabilities, and exception guarantees, the implementation chooses appropriate operations.

For common types such as:

```cpp
int
double
std::string
```

the standard library provides appropriate mechanisms to maintain the required exception guarantees.

The practical lesson is:

```text
Reallocation is not just a pointer update.
Existing objects may need to be moved or copied.
```

---

# 88. `vector<bool>`

`std::vector<bool>` is a special standard-library specialization.

Unlike:

```cpp
vector<int>
```

it is commonly implemented as a packed bit representation rather than storing each `bool` as a normal byte-sized object.

Therefore:

```cpp
vector<bool>
```

has behavior that differs from a normal `vector<T>` in some details.

For example, `operator[]` returns a proxy-like reference rather than a normal `bool&`.

Use it when its packed representation is useful, but be aware that it is not a completely ordinary `vector<bool>` object model.

---

# 89. Vector of Strings

Example:

```cpp
vector<string> names =
{
    "Deep",
    "Amit",
    "Rahul"
};
```

Traversal:

```cpp
for (const string& name : names)
{
    cout << name << endl;
}
```

Using `const string&` avoids copying each string during traversal.

---

# 90. Vector of Pairs

Declaration:

```cpp
vector<pair<int, int>> vp;
```

Add elements:

```cpp
vp.push_back({1, 2});

vp.emplace_back(3, 4);
```

Result:

```text
(1, 2)
(3, 4)
```

Access:

```cpp
cout << vp[0].first;
cout << vp[0].second;
```

---

# 91. 2D Vector / Matrix

A 2D vector is a vector whose elements are themselves vectors.

```cpp
vector<vector<int>> mat;
```

---

## Empty 2D Vector

```cpp
vector<vector<int>> mat;
```

---

## Ten Rows

```cpp
vector<vector<int>> mat(10);
```

This creates ten inner vectors.

It does **not** create ten columns of a fixed matrix.

Conceptually:

```text
row 0 → empty
row 1 → empty
...
row 9 → empty
```

---

## 3 × 4 Matrix

```cpp
vector<vector<int>> mat(3, vector<int>(4));
```

Result:

```text
0 0 0 0
0 0 0 0
0 0 0 0
```

---

## 3 × 4 Matrix Filled with Zero

```cpp
vector<vector<int>> mat(3, vector<int>(4, 0));
```

Result:

```text
0 0 0 0
0 0 0 0
0 0 0 0
```

---

# 92. Traversing a 2D Vector

```cpp
for (size_t i = 0; i < mat.size(); ++i)
{
    for (size_t j = 0; j < mat[i].size(); ++j)
    {
        cout << mat[i][j] << " ";
    }

    cout << endl;
}
```

Range-based version:

```cpp
for (const auto& row : mat)
{
    for (int x : row)
    {
        cout << x << " ";
    }

    cout << endl;
}
```

---

# 93. Important 2D Vector Property

A:

```cpp
vector<vector<int>>
```

is **not necessarily one contiguous 2D memory block**.

Each inner vector manages its own storage.

Conceptually:

```text
outer vector
    |
    +----> inner vector → [1][2][3]
    |
    +----> inner vector → [4][5]
    |
    +----> inner vector → [6][7][8][9]
```

Rows can have different sizes.

Example:

```cpp
vector<vector<int>> mat =
{
    {1, 2, 3},
    {4, 5},
    {6, 7, 8, 9}
};
```

This is a valid jagged structure.

---

# 94. Vector of Vectors vs Fixed 2D Array

```cpp
int arr[3][4];
```

has a contiguous 2D array representation.

But:

```cpp
vector<vector<int>> mat(3, vector<int>(4));
```

contains separate inner vectors.

This distinction matters when interfacing with low-level APIs that require one contiguous block.

---

# 95. Vector of Objects

You can store class objects:

```cpp
class Employee
{
public:
    int id;
    string name;
};

vector<Employee> employees;
```

Add:

```cpp
employees.push_back({1, "Deep"});
```

or:

```cpp
employees.emplace_back(Employee{2, "Amit"});
```

For a constructor:

```cpp
class Employee
{
public:
    Employee(int id, string name)
        : id(id), name(std::move(name))
    {
    }

    int id;
    string name;
};

vector<Employee> employees;

employees.emplace_back(1, "Deep");
```

---

# 96. Vector of Pointers

You can store pointers:

```cpp
vector<int*> v;
```

But remember:

```text
vector manages the pointer objects,
not necessarily the dynamically allocated objects they point to.
```

For example:

```cpp
int* p = new int(10);

vector<int*> v;
v.push_back(p);
```

Destroying the vector does not automatically perform:

```cpp
delete p;
```

Modern C++ should generally prefer smart pointers when ownership is required.

---

# 97. Vector of Smart Pointers

Example:

```cpp
vector<unique_ptr<int>> v;

v.push_back(make_unique<int>(10));
```

A vector can own dynamically allocated objects through smart pointers.

This is often preferable to raw owning pointers.

---

# 98. Vector of `const` Objects

You generally cannot use:

```cpp
vector<const int>
```

as a normal vector element type because vector requires an appropriate object type for its storage and modification requirements.

If you need a read-only view, use:

- `const vector<int>&`
- `std::span<const int>` in C++20
- const iterators

Example:

```cpp
const vector<int> v = {1, 2, 3};
```

---

# 99. `const vector`

```cpp
const vector<int> v = {1, 2, 3};
```

You cannot modify it:

```cpp
v.push_back(4); // error
```

You can read:

```cpp
cout << v[0];
```

Use:

```cpp
v.cbegin();
v.cend();
```

for const iteration.

---

# 100. `vector` and `std::span`

In C++20, `std::span` can provide a non-owning view over contiguous vector data.

Example:

```cpp
vector<int> v = {1, 2, 3, 4};

std::span<int> view(v);
```

`span` does not own the elements.

It simply provides a view over existing contiguous storage.

Header:

```cpp
#include <span>
```

This is useful when passing vector data to functions without copying.

---

# 101. Vector with Algorithms

Because vector provides random-access/contiguous iterators, it works very well with standard algorithms.

Examples:

```cpp
sort(v.begin(), v.end());

reverse(v.begin(), v.end());

find(v.begin(), v.end(), 10);

count(v.begin(), v.end(), 10);

binary_search(v.begin(), v.end(), 10);

min_element(v.begin(), v.end());

max_element(v.begin(), v.end());
```

---

# 102. `find()` vs `binary_search()`

## `find()`

Works on an unsorted vector:

```cpp
find(v.begin(), v.end(), value);
```

Complexity:

```text
O(n)
```

---

## `binary_search()`

Requires sorted data:

```cpp
binary_search(v.begin(), v.end(), value);
```

Complexity:

```text
O(log n)
```

Therefore:

```text
Unsorted data → find()
Sorted data   → binary_search()
```

---

# 103. `lower_bound()` Example

```cpp
vector<int> v = {1, 3, 3, 5, 7};

auto it = lower_bound(v.begin(), v.end(), 3);
```

`it` points to the first `3`.

Conceptually:

```text
1 3 3 5 7
  ↑
lower_bound(3)
```

---

# 104. `upper_bound()` Example

```cpp
auto it = upper_bound(v.begin(), v.end(), 3);
```

It points to the first element greater than `3`.

```text
1 3 3 5 7
      ↑
upper_bound(3)
```

The iterator points to `5`.

---

# 105. `data()` vs `&v[0]`

For a non-empty vector:

```cpp
v.data()
```

points to the first element.

Conceptually:

```cpp
v.data() == &v[0]
```

for a non-empty vector.

`data()` is the preferred general interface for obtaining the underlying pointer.

---

# 106. Empty Vector and `data()`

For an empty vector:

```cpp
vector<int> v;

int* p = v.data();
```

The returned pointer must not be dereferenced because there is no element.

Do not do:

```cpp
cout << *v.data();
```

when:

```text
v.empty() == true
```

---

# 107. `reserve()` Does Not Initialize Elements

This is a common interview trap.

```cpp
vector<int> v;

v.reserve(10);
```

Now:

```text
size = 0
capacity >= 10
```

This is invalid:

```cpp
v[0] = 10;
```

because element zero does not exist.

Correct:

```cpp
v.push_back(10);
```

or:

```cpp
v.resize(10);
v[0] = 10;
```

---

# 108. `resize()` Creates Elements

```cpp
vector<int> v;

v.resize(10);
```

Now:

```text
size = 10
```

The elements exist.

Therefore:

```cpp
v[0] = 10;
```

is valid.

---

# 109. `clear()` vs `resize(0)`

Both result in:

```text
size = 0
```

Examples:

```cpp
v.clear();
```

or:

```cpp
v.resize(0);
```

Neither is guaranteed to reduce capacity to zero.

---

# 110. `reserve()` vs `shrink_to_fit()`

```cpp
v.reserve(100);
```

requests at least 100 capacity.

```cpp
v.shrink_to_fit();
```

requests that unused capacity be reduced.

Important:

```text
reserve() is a capacity-growth request.
shrink_to_fit() is a non-binding capacity-reduction request.
```

---

# 111. `push_back()` Reallocation Example

Suppose:

```text
size = 3
capacity = 3
```

Then:

```cpp
v.push_back(4);
```

may cause:

```text
Old storage
[1][2][3]

        ↓ reallocate

New storage
[1][2][3][4]
```

Pointers/references/iterators to the old storage become invalid.

---

# 112. Why `vector` is Usually Fast

Although vector insertion in the middle is O(n), vector is often extremely fast in real applications because:

- Elements are contiguous.
- CPU caches work well with sequential memory.
- Random access is simple.
- Allocations happen for the vector as a whole.
- Standard algorithms work efficiently with random-access/contiguous iterators.

Therefore:

```text
Big-O alone does not determine practical performance.
```

---

# 113. Advantages of `vector`

- Dynamic size
- O(1) random access
- Contiguous memory
- Excellent cache locality
- Efficient `push_back()` amortized O(1)
- Efficient `pop_back()` O(1)
- Works well with STL algorithms
- Simple interface
- `data()` provides contiguous storage access
- Usually the default sequence container to consider

---

# 114. Disadvantages of `vector`

- Front insertion is O(n)
- Middle insertion is O(n)
- Front deletion is O(n)
- Middle deletion is O(n)
- Reallocation can be expensive
- Reallocation invalidates iterators, pointers and references
- Capacity can exceed size, causing unused allocated storage
- A vector of vectors is not one contiguous 2D block

---

# 115. Vector vs Array

| Feature | C-style Array | `std::vector` |
|---|---|---|
| Size | Fixed | Dynamic |
| Contiguous | Yes | Yes |
| Random access | O(1) | O(1) |
| Automatic growth | No | Yes |
| `push_back()` | No | Yes |
| `size()` | No member function | Yes |
| Iterators | No STL iterator interface | Yes |
| Memory management | Manual/static | Automatic |
| STL algorithms | Can work with pointers | Directly supported |

---

# 116. Vector vs Deque vs List vs Forward List

| Feature | `vector` | `deque` | `list` | `forward_list` |
|---|---|---|---|---|
| Basic structure | Dynamic array | Segmented array | Doubly linked list | Singly linked list |
| Memory | Contiguous | Block-based | Non-contiguous | Non-contiguous |
| Random access | O(1) | O(1) | No | No |
| Push front | O(n) | O(1) | O(1) | O(1) |
| Push back | Amortized O(1) | O(1) | O(1) | No direct operation |
| Pop front | O(n) | O(1) | O(1) | O(1) |
| Pop back | O(1) | O(1) | O(1) | No direct operation |
| Iterator | Random access / contiguous | Random access | Bidirectional | Forward |
| Cache locality | Excellent | Good | Poorer | Poorer |
| Best use | General-purpose dynamic array | Efficient both-end operations + indexing | Frequent linked-node insertion/erasure | Lightweight forward-only linked operations |

---

# 117. Time Complexity — Complete Reference

| Operation | Complexity |
|---|---:|
| `operator[]` | O(1) |
| `at()` | O(1) |
| `front()` | O(1) |
| `back()` | O(1) |
| `data()` | O(1) |
| `size()` | O(1) |
| `empty()` | O(1) |
| `capacity()` | O(1) |
| `max_size()` | O(1) |
| `push_back()` | Amortized O(1) |
| `emplace_back()` | Amortized O(1) |
| `pop_back()` | O(1) |
| Single `insert()` | O(n) generally |
| Single `emplace()` | O(n) generally |
| `erase()` | O(n) generally |
| `clear()` | O(n) |
| `reserve()` | O(n) if reallocation occurs |
| `resize()` | O(n) when elements are added/removed |
| `shrink_to_fit()` | Implementation-dependent; may reallocate |
| `find()` | O(n) |
| `count()` | O(n) |
| `sort()` | O(n log n) |
| `binary_search()` | O(log n) |
| `lower_bound()` | O(log n) |
| `upper_bound()` | O(log n) |
| `min_element()` | O(n) |
| `max_element()` | O(n) |
| `accumulate()` | O(n) |

---

# 118. Iterator Category Comparison

| Container | Iterator Category |
|---|---|
| `vector` | Random Access / Contiguous |
| `deque` | Random Access |
| `list` | Bidirectional |
| `forward_list` | Forward |

This explains:

```text
vector:
it + 5       ✓
it[5]         ✓

list:
it + 5       ✗
it[5]         ✗

forward_list:
it + 5       ✗
it[5]         ✗
```

---

# 119. Common Interview Questions

## Q1. What is `std::vector`?

```text
A dynamic sequence container that stores elements contiguously.
```

---

## Q2. Is vector contiguous?

```text
Yes.
```

This is one of its defining properties.

---

## Q3. Why is random access O(1)?

Because elements are stored contiguously.

---

## Q4. What is the difference between size and capacity?

```text
size     = number of elements currently stored
capacity = number of elements that can be stored without reallocation
```

---

## Q5. What happens when capacity is full?

The vector may allocate a larger storage block and move/copy the existing elements into it.

---

## Q6. Does vector always double its capacity?

```text
No.
```

The C++ Standard does not specify a fixed growth factor.

---

## Q7. What is the complexity of `push_back()`?

```text
Amortized O(1)
```

A particular insertion can be:

```text
O(n)
```

when reallocation is required.

---

## Q8. What is the complexity of `insert()` in the middle?

Generally:

```text
O(n)
```

because elements after the insertion position may need to move.

---

## Q9. Does `clear()` reduce capacity?

```text
Not necessarily.
```

It destroys all elements and makes the size zero.

---

## Q10. What is `reserve()` used for?

To request storage for at least a specified number of elements before insertion.

Example:

```cpp
v.reserve(1000);
```

It can reduce reallocations.

---

## Q11. Does `reserve()` change size?

```text
No.
```

---

## Q12. Does `resize()` change size?

```text
Yes.
```

---

## Q13. Does `resize()` change capacity?

It may increase capacity if necessary, but reducing size does not necessarily reduce capacity.

---

## Q14. `push_back()` vs `emplace_back()`?

```text
push_back()    → inserts an existing value/object
emplace_back() → constructs an element from constructor arguments
```

`emplace_back()` can avoid an unnecessary temporary in suitable cases, but it is not automatically faster in every situation.

---

## Q15. Why is `vector` faster than `list` in many cases?

Because vector provides:

```text
Contiguous memory
+
Better cache locality
+
Fewer per-element allocation/link overheads
```

---

## Q16. Can we use `std::sort()` with vector?

Yes:

```cpp
std::sort(v.begin(), v.end());
```

because vector provides random-access iterators.

---

## Q17. Can we use `std::sort()` with list?

No.

Use:

```cpp
l.sort();
```

because `list` has bidirectional iterators.

---

## Q18. What is iterator invalidation?

Iterator invalidation means an existing iterator, pointer, or reference can no longer safely refer to the intended vector element after a vector operation.

The most important cause is reallocation.

---

## Q19. What is `data()`?

```cpp
v.data();
```

returns a pointer to the vector's contiguous underlying storage.

---

## Q20. Is `vector<vector<int>>` a contiguous 2D matrix?

```text
No.
```

The outer vector is contiguous in its inner-vector objects, but each inner vector manages its own separate storage.

---

# 120. Common Mistakes

## Mistake 1: Assuming `reserve()` creates elements

Wrong:

```cpp
vector<int> v;

v.reserve(10);

v[0] = 100;
```

Correct:

```cpp
v.resize(10);

v[0] = 100;
```

or:

```cpp
v.reserve(10);

v.push_back(100);
```

---

## Mistake 2: Assuming `clear()` frees all memory

```cpp
v.clear();
```

sets:

```text
size = 0
```

but does not guarantee:

```text
capacity = 0
```

---

## Mistake 3: Assuming vector insertion is always O(1)

Only operations at the end are amortized O(1).

Middle/front insertion is generally O(n).

---

## Mistake 4: Using an Invalidated Iterator

Example:

```cpp
auto it = v.begin();

v.push_back(100);
```

If reallocation occurs, `it` may be invalid.

Do not continue using it without considering invalidation rules.

---

## Mistake 5: Dereferencing `end()`

Wrong:

```cpp
cout << *v.end();
```

`end()` is one past the last element.

Correct:

```cpp
cout << v.back();
```

when the vector is non-empty.

---

## Mistake 6: Accessing an Empty Vector

These require a non-empty vector:

```cpp
v.front();
v.back();
```

Do not call them when:

```cpp
v.empty() == true
```

---

# 121. Complete Example Program

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {5, 2, 9, 1};

    v.push_back(10);

    sort(v.begin(), v.end());

    cout << "Elements: ";

    for (int x : v)
    {
        cout << x << " ";
    }

    cout << endl;

    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Front: " << v.front() << endl;
    cout << "Back: " << v.back() << endl;

    return 0;
}
```

Possible output:

```text
Elements: 1 2 5 9 10
Size: 5
Capacity: implementation-dependent
Front: 1
Back: 10
```

The exact capacity is implementation-dependent.

---

# 122. Complete Example — `reserve()` vs `resize()`

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    v.reserve(5);

    cout << "After reserve:" << endl;
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    v.resize(5);

    cout << "\nAfter resize:" << endl;
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    v[0] = 100;

    cout << "\nFirst element: " << v[0] << endl;

    return 0;
}
```

Key concept:

```text
reserve(5)
    ↓
capacity >= 5
size = 0

resize(5)
    ↓
size = 5
```

---

# 123. Complete Example — Searching

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};

    auto it = find(v.begin(), v.end(), 30);

    if (it != v.end())
    {
        cout << "Found: " << *it << endl;
    }

    return 0;
}
```

Output:

```text
Found: 30
```

---

# 124. Complete Example — Binary Search

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};

    if (binary_search(v.begin(), v.end(), 30))
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }

    return 0;
}
```

Output:

```text
Found
```

Important:

```text
binary_search()
requires sorted data.
```

---

# 125. Complete Example — Vector of Pairs

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<pair<int, int>> vp;

    vp.push_back({1, 2});
    vp.emplace_back(3, 4);

    for (const auto& p : vp)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
```

Output:

```text
1 2
3 4
```

---

# 126. Complete Example — 2D Vector

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> mat(3, vector<int>(4, 0));

    for (size_t i = 0; i < mat.size(); ++i)
    {
        for (size_t j = 0; j < mat[i].size(); ++j)
        {
            cout << mat[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
```

Output:

```text
0 0 0 0
0 0 0 0
0 0 0 0
```

---

# 127. Complete Example — Remove Even Values

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};

    std::erase_if(v, [](int x)
    {
        return x % 2 == 0;
    });

    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
1 3 5
```

Requires C++20.

---

# 128. Complete Example — Move Vector

```cpp
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    vector<int> v1 = {10, 20, 30};

    vector<int> v2 = std::move(v1);

    cout << "v2: ";

    for (int x : v2)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
v2: 10 20 30
```

After the move, `v1` is valid but its exact state should not be assumed.

---

# 129. Important Mental Model

Think of `std::vector` as:

```text
                 VECTOR
                    |
        +-----------+-----------+
        |           |           |
      begin        end      capacity end
        |           |           |
        v           v           v

     +----+----+----+----+----+----+
     | 10 | 20 | 30 |    |    |    |
     +----+----+----+----+----+----+
      used elements       unused capacity
```

The most important relationship is:

```text
size <= capacity
```

---

# 130. Quick Revision

```text
Header
------
#include <vector>

Container
---------
std::vector<T>

Structure
---------
Dynamic Array

Memory
------
Contiguous

Random Access
-------------
O(1)

Iterator
--------
Random Access / Contiguous

front()
--------
O(1)

back()
------
O(1)

push_back()
-----------
Amortized O(1)

emplace_back()
--------------
Amortized O(1)

pop_back()
----------
O(1)

Front insertion
---------------
O(n)

Middle insertion
----------------
O(n)

Erase
-----
O(n) generally

Search
------
O(n)

Binary Search
-------------
O(log n) on sorted vector

Sort
----
O(n log n)

size()
------
O(1)

capacity()
----------
O(1)

reserve()
---------
Changes/request capacity
Does not change size

resize()
--------
Changes size

clear()
-------
Removes elements
Does not guarantee capacity reduction

shrink_to_fit()
---------------
Non-binding capacity reduction request

data()
------
Pointer to contiguous storage

Main Advantage
--------------
Fast random access + excellent cache locality

Main Limitation
---------------
Expensive front/middle insertion and
possible reallocation
```

---

# 131. Final Summary

`std::vector` is a **dynamic contiguous sequence container** and is often the first container to consider for general-purpose collection storage.

Its key properties are:

```text
std::vector
    ↓
Dynamic Array
    ↓
Contiguous Memory
    ↓
Random Access
    ↓
O(1) Access
    ↓
Amortized O(1) push_back()
```

Important functions:

```cpp
// Access
operator[]
at()
front()
back()
data()

// Size / capacity
size()
capacity()
empty()
max_size()
reserve()
resize()
shrink_to_fit()

// Insertion
push_back()
emplace_back()
insert()
emplace()

// Removal
pop_back()
erase()
clear()

// Iterators
begin()
end()
cbegin()
cend()
rbegin()
rend()
crbegin()
crend()

// Algorithms
sort()
find()
binary_search()
lower_bound()
upper_bound()
min_element()
max_element()
count()
accumulate()

// Other
assign()
swap()
get_allocator()
```

The most important interview concepts are:

```text
size != capacity

reserve() != resize()

push_back() = amortized O(1)

middle insertion = O(n)

vector storage = contiguous

random access = O(1)

reallocation can invalidate iterators,
pointers and references

clear() does not guarantee capacity reduction

shrink_to_fit() is non-binding

vector is usually cache-friendly

vector<vector<T>> is not one contiguous 2D block
```

For most general-purpose sequence storage, `std::vector` is an excellent default because its contiguous memory provides efficient access and strong cache locality while still allowing dynamic growth.
