# C++ `std::swap()` — Complete Notes

## 1. Introduction

`std::swap()` is a Standard Library function used to **exchange the values of two objects**.

Instead of manually using a temporary variable:

```cpp
int temp = a;
a = b;
b = temp;
```

you can simply write:

```cpp
std::swap(a, b);
```

After the operation:

```text
a contains the old value of b
b contains the old value of a
```

`swap()` is widely used with:

- Fundamental types
- Pointers
- Strings
- Pairs
- Tuples
- Arrays
- STL containers
- Iterators
- Smart pointers
- User-defined classes

---

# 2. Header File

The primary header for `std::swap()` is:

```cpp
#include <utility>
```

`std::swap()` is also available through:

```cpp
#include <algorithm>
```

For portable code, `<utility>` is the natural header to include when `swap` is what you need.

---

# 3. Namespace

`swap()` belongs to the `std` namespace.

```cpp
std::swap(a, b);
```

If you write:

```cpp
using namespace std;
```

you can write:

```cpp
swap(a, b);
```

Prefer `std::swap()` in general-purpose/library code because it makes the source of the function explicit.

---

# 4. Basic Syntax

```cpp
std::swap(a, b);
```

Parameters:

```text
a → first object
b → second object
```

Both objects must be **swappable**.

---

# 5. Return Type

`std::swap()` returns:

```cpp
void
```

It modifies the two objects directly.

Example:

```cpp
int a = 10;
int b = 20;

std::swap(a, b);
```

There is no returned value:

```cpp
auto x = std::swap(a, b); // ERROR
```

---

# 6. Basic Working

Before:

```text
a = 10
b = 20
```

Execute:

```cpp
std::swap(a, b);
```

After:

```text
a = 20
b = 10
```

---

# 7. Manual Swap vs `std::swap()`

## Manual Swap

```cpp
int temp = a;
a = b;
b = temp;
```

## Using `std::swap()`

```cpp
std::swap(a, b);
```

The second version is shorter, clearer, and works generically for many types.

---

# 8. Basic Example

```cpp
#include <iostream>
#include <utility>

int main()
{
    int a = 5;
    int b = 10;

    std::swap(a, b);

    std::cout << a << '\n';
    std::cout << b << '\n';
}
```

Output:

```text
10
5
```

---

# 9. How `std::swap()` Works

Conceptually, a generic implementation is similar to:

```cpp
template<class T>
void swap(T& a, T& b)
{
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}
```

This is a **conceptual model**, not the exact implementation required by the Standard.

The important idea is:

```text
a
 ↓
temporary

b
 ↓
a

temporary
 ↓
b
```

Modern C++ implementations can use move construction and move assignment where appropriate.

---

# 10. `std::move()` and `swap()`

For a type that supports efficient move operations, swapping can avoid expensive deep copies.

Conceptually:

```cpp
T temp = std::move(a);
a = std::move(b);
b = std::move(temp);
```

For example, `std::vector` owns dynamically allocated storage. Swapping vectors can exchange their internal resources rather than moving every element individually.

---

# 11. Swapping Integers

```cpp
int a = 10;
int b = 20;

std::swap(a, b);
```

Result:

```text
a = 20
b = 10
```

Complexity:

```text
O(1)
```

---

# 12. Swapping `double`

```cpp
double x = 4.5;
double y = 8.9;

std::swap(x, y);
```

Result:

```text
x = 8.9
y = 4.5
```

---

# 13. Swapping Characters

```cpp
char a = 'A';
char b = 'B';

std::swap(a, b);
```

Result:

```text
a = 'B'
b = 'A'
```

---

# 14. Swapping Boolean Values

```cpp
bool a = true;
bool b = false;

std::swap(a, b);
```

Result:

```text
a = false
b = true
```

---

# 15. Swapping Strings

```cpp
#include <iostream>
#include <string>
#include <utility>

int main()
{
    std::string s1 = "Hello";
    std::string s2 = "World";

    std::swap(s1, s2);

    std::cout << s1 << '\n';
    std::cout << s2 << '\n';
}
```

Output:

```text
World
Hello
```

For standard strings, swapping is designed to be efficient.

---

# 16. Swapping Vectors

```cpp
#include <vector>
#include <utility>

std::vector<int> a = {1, 2, 3};
std::vector<int> b = {4, 5, 6};

std::swap(a, b);
```

After:

```text
a = {4, 5, 6}
b = {1, 2, 3}
```

For `std::vector`, swapping is constant-time in the standard complexity model.

It does not need to individually exchange every element.

---

# 17. Vector Member `swap()`

`std::vector` also provides a member function:

```cpp
a.swap(b);
```

Example:

```cpp
std::vector<int> a = {1, 2, 3};
std::vector<int> b = {4, 5, 6};

a.swap(b);
```

---

# 18. `std::swap()` vs Member `swap()`

Generic form:

```cpp
std::swap(a, b);
```

Member form:

```cpp
a.swap(b);
```

For standard containers, both are designed to swap the containers efficiently.

Prefer the generic form when writing generic code:

```cpp
std::swap(a, b);
```

A container's member `swap()` is also useful when you specifically know that the object provides it.

---

# 19. Swapping `std::pair`

```cpp
#include <iostream>
#include <string>
#include <utility>

std::pair<int, std::string> p1 = {1, "One"};
std::pair<int, std::string> p2 = {2, "Two"};

std::swap(p1, p2);
```

Before:

```text
p1 = (1, One)
p2 = (2, Two)
```

After:

```text
p1 = (2, Two)
p2 = (1, One)
```

---

# 20. Pair Member `swap()`

`std::pair` also provides a member function:

```cpp
p1.swap(p2);
```

Example:

```cpp
std::pair<int, std::string> p1 = {1, "One"};
std::pair<int, std::string> p2 = {2, "Two"};

p1.swap(p2);
```

---

# 21. Swapping Tuples

```cpp
#include <tuple>
#include <utility>

std::tuple<int, int, int> t1 = {1, 2, 3};
std::tuple<int, int, int> t2 = {4, 5, 6};

std::swap(t1, t2);
```

After:

```text
t1 = (4, 5, 6)
t2 = (1, 2, 3)
```

---

# 22. Swapping `std::array`

Unlike a raw C-style array, `std::array` is a class type and supports swapping.

```cpp
#include <array>
#include <utility>

std::array<int, 4> a = {1, 2, 3, 4};
std::array<int, 4> b = {5, 6, 7, 8};

std::swap(a, b);
```

After:

```text
a = {5, 6, 7, 8}
b = {1, 2, 3, 4}
```

Complexity:

```text
O(n)
```

where `n` is the number of elements.

Unlike `vector`, the elements of `std::array` are stored directly inside the object, so swapping generally involves swapping the elements.

---

# 23. Raw Arrays

Consider:

```cpp
int a[3] = {1, 2, 3};
int b[3] = {4, 5, 6};
```

A raw array cannot be assigned:

```cpp
a = b; // ERROR
```

However, an important C++ detail is that `std::swap` **does provide an array overload**.

So this can be used:

```cpp
std::swap(a, b);
```

and the elements are exchanged.

The operation is:

```text
O(n)
```

For three elements, conceptually:

```text
a[0] ↔ b[0]
a[1] ↔ b[1]
a[2] ↔ b[2]
```

Another option is:

```cpp
std::swap_ranges(a, a + 3, b);
```

---

# 24. `std::swap_ranges()`

`swap_ranges()` swaps corresponding elements in two ranges.

Syntax:

```cpp
std::swap_ranges(first1, last1, first2);
```

Example:

```cpp
int a[] = {1, 2, 3};
int b[] = {4, 5, 6};

std::swap_ranges(a, a + 3, b);
```

Result:

```text
a = {4, 5, 6}
b = {1, 2, 3}
```

---

# 25. Swapping `std::set`

```cpp
#include <set>
#include <utility>

std::set<int> s1 = {1, 2, 3};
std::set<int> s2 = {4, 5, 6};

std::swap(s1, s2);
```

The sets exchange their contents.

For standard associative containers, `swap` is constant-time.

---

# 26. Swapping `std::map`

```cpp
#include <map>
#include <string>
#include <utility>

std::map<int, std::string> m1;
std::map<int, std::string> m2;

std::swap(m1, m2);
```

The maps exchange their internal contents.

Complexity:

```text
O(1)
```

for standard `map` swapping.

---

# 27. Swapping `std::unordered_map`

```cpp
#include <unordered_map>
#include <utility>

std::unordered_map<int, int> m1;
std::unordered_map<int, int> m2;

std::swap(m1, m2);
```

The two unordered maps exchange their contents.

Standard container `swap` is designed to be constant-time.

---

# 28. Swapping `std::deque`

```cpp
#include <deque>
#include <utility>

std::deque<int> d1 = {1, 2, 3};
std::deque<int> d2 = {4, 5, 6};

std::swap(d1, d2);
```

---

# 29. Swapping `std::list`

```cpp
#include <list>
#include <utility>

std::list<int> l1 = {1, 2, 3};
std::list<int> l2 = {4, 5, 6};

std::swap(l1, l2);
```

The list nodes do not need to be individually copied.

---

# 30. Swapping `std::forward_list`

```cpp
#include <forward_list>
#include <utility>

std::forward_list<int> a = {1, 2, 3};
std::forward_list<int> b = {4, 5, 6};

std::swap(a, b);
```

---

# 31. Swapping `std::queue`

```cpp
#include <queue>
#include <utility>

std::queue<int> q1;
std::queue<int> q2;

std::swap(q1, q2);
```

There is also:

```cpp
q1.swap(q2);
```

---

# 32. Swapping `std::stack`

```cpp
#include <stack>
#include <utility>

std::stack<int> s1;
std::stack<int> s2;

std::swap(s1, s2);
```

Or:

```cpp
s1.swap(s2);
```

---

# 33. Swapping `std::priority_queue`

```cpp
#include <queue>
#include <utility>

std::priority_queue<int> p1;
std::priority_queue<int> p2;

std::swap(p1, p2);
```

Or:

```cpp
p1.swap(p2);
```

---

# 34. Swapping Iterators

Iterators themselves are objects, so they can also be swapped when they are swappable.

```cpp
std::vector<int> v = {10, 20, 30};

auto it1 = v.begin();
auto it2 = v.end();

std::swap(it1, it2);
```

This swaps the iterator objects.

It does **not** swap the elements in the vector.

---

# 35. Swapping Pointers

Consider:

```cpp
int a = 10;
int b = 20;

int* p = &a;
int* q = &b;
```

Now:

```cpp
std::swap(p, q);
```

The pointer values are exchanged.

Before:

```text
p → a
q → b
```

After:

```text
p → b
q → a
```

The actual integers are not changed.

```text
a = 10
b = 20
```

remain unchanged.

---

# 36. Swapping References

Consider:

```cpp
int a = 5;
int b = 10;

int& x = a;
int& y = b;
```

Then:

```cpp
std::swap(x, y);
```

This swaps the **values of `a` and `b`**.

After:

```text
a = 10
b = 5
```

It does **not** change which object the references refer to.

References cannot be reseated.

Therefore:

```text
x still refers to a
y still refers to b
```

---

# 37. Swapping `const` Objects

This is not allowed:

```cpp
const int a = 10;
const int b = 20;

std::swap(a, b); // ERROR
```

Why?

`swap()` needs to modify both objects, but `const` objects cannot be modified.

---

# 38. Swapping Custom Classes

User-defined classes can also be swapped if they are swappable.

Example:

```cpp
#include <string>
#include <utility>

class Student
{
public:
    int id;
    std::string name;
};

int main()
{
    Student s1{1, "A"};
    Student s2{2, "B"};

    std::swap(s1, s2);
}
```

For a simple class such as this, the compiler-generated operations make swapping possible.

After the swap:

```text
s1.id   = 2
s1.name = "B"

s2.id   = 1
s2.name = "A"
```

---

# 39. Custom `swap()` Function

A class can provide its own optimized `swap`.

```cpp
class Student
{
public:
    int id;
    std::string name;

    friend void swap(Student& a, Student& b) noexcept
    {
        using std::swap;

        swap(a.id, b.id);
        swap(a.name, b.name);
    }
};
```

Now:

```cpp
Student s1{1, "A"};
Student s2{2, "B"};

swap(s1, s2);
```

The custom `swap()` can provide class-specific behavior.

---

# 40. Why Custom `swap()` Can Be Useful

Custom swap is especially useful for classes that manage resources such as:

- Dynamic memory
- File handles
- Network resources
- Locks
- Other ownership-based resources

A class can implement a swap operation that exchanges its internal resources efficiently.

---

# 41. `using std::swap`

A common pattern inside generic code or custom `swap` functions is:

```cpp
using std::swap;
swap(a, b);
```

Why?

It makes the standard `std::swap` available while also allowing **argument-dependent lookup (ADL)** to find a more specialized `swap` associated with the object's type.

Example:

```cpp
friend void swap(Student& a, Student& b) noexcept
{
    using std::swap;

    swap(a.id, b.id);
    swap(a.name, b.name);
}
```

This is an important generic-programming pattern.

---

# 42. `noexcept` and Swap

Many standard-library types provide a `swap()` that is `noexcept` when their contained types can also be swapped without throwing.

You may see:

```cpp
void swap(...) noexcept;
```

or conditionally `noexcept`.

For custom classes, you can mark your `swap`:

```cpp
friend void swap(Student& a, Student& b) noexcept
{
    using std::swap;

    swap(a.id, b.id);
    swap(a.name, b.name);
}
```

provided the operations used are actually non-throwing.

---

# 43. Swap and Move Semantics

A conceptual generic implementation can be thought of as:

```cpp
template<class T>
void swap(T& a, T& b)
{
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}
```

The important operations are:

```text
move construction
       ↓
move assignment
       ↓
move assignment
```

This can be much more efficient than copying large resources.

Again, the exact standard-library implementation is implementation-dependent.

---

# 44. `std::swap` Is Generic

The standard function is designed to work with many different types.

For example:

```cpp
std::swap(int1, int2);
std::swap(string1, string2);
std::swap(vector1, vector2);
std::swap(pair1, pair2);
std::swap(tuple1, tuple2);
```

The actual behavior depends on the type.

---

# 45. Swap and STL Containers

Many STL containers provide:

```cpp
container.swap(other);
```

Examples:

```cpp
vector
deque
list
forward_list
set
map
multiset
multimap
unordered_set
unordered_map
stack
queue
priority_queue
```

The exact complexity and exception guarantees are determined by each container's specification.

---

# 46. Complexity

Do **not** assume that every `std::swap()` is automatically `O(1)`.

The complexity depends on the type.

Typical examples:

| Type | Typical/Specified Swap Complexity |
|---|---:|
| `int` | O(1) |
| `double` | O(1) |
| `char` | O(1) |
| Pointer | O(1) |
| `std::string` | O(1) |
| `std::vector` | O(1) |
| `std::deque` | O(1) |
| `std::list` | O(1) |
| `std::forward_list` | O(1) |
| `std::set` | O(1) |
| `std::map` | O(1) |
| `std::unordered_map` | O(1) |
| `std::queue` | Depends on underlying container; typically O(1) |
| `std::stack` | Depends on underlying container; typically O(1) |
| `std::priority_queue` | Depends on underlying container; typically O(1) |
| `std::array<T, N>` | O(N) |
| Raw array `T[N]` | O(N) |

The important rule is:

> **`std::swap()` complexity is determined by the type being swapped.**

---

# 47. Space Complexity

For an ordinary swap operation, auxiliary space is generally:

```text
O(1)
```

However, the exact implementation and type can affect the practical behavior.

For standard containers such as `vector`, swapping the container objects does not require an additional array proportional to the number of elements.

---

# 48. Swap in Sorting Algorithms

`swap()` is heavily used in algorithms.

Example:

```cpp
for (int i = 0; i < n; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        if (arr[i] > arr[j])
        {
            std::swap(arr[i], arr[j]);
        }
    }
}
```

This is a common pattern in simple sorting algorithms such as:

- Selection sort
- Bubble sort
- Quick sort implementations
- Heap-related algorithms

---

# 49. `std::swap()` and `std::sort()`

You do not normally implement:

```cpp
std::sort()
```

using manual swapping yourself.

The sorting algorithm may internally perform swaps or other rearrangements as part of its implementation.

Example:

```cpp
std::sort(v.begin(), v.end());
```

The important point is that `swap()` is a fundamental building block used by many algorithms.

---

# 50. `std::reverse()`

Example:

```cpp
std::reverse(v.begin(), v.end());
```

An implementation can exchange elements from opposite ends:

```text
first ↔ last
second ↔ second-last
...
```

`swap()` is a natural operation for this type of rearrangement.

---

# 51. `std::next_permutation()`

Example:

```cpp
std::next_permutation(v.begin(), v.end());
```

Permutation algorithms perform rearrangements of elements and use swapping as part of their implementation.

---

# 52. Swap Does Not Create a New Object

Consider:

```cpp
int a = 10;
int b = 20;

std::swap(a, b);
```

`swap()` does not create two new integers for the user.

It modifies the existing objects:

```text
Object A → value changes from 10 to 20
Object B → value changes from 20 to 10
```

---

# 53. Swap Does Not Exchange Variable Names

This is an important concept.

```cpp
int a = 10;
int b = 20;

std::swap(a, b);
```

It does not change the names:

```text
a remains a
b remains b
```

Only their stored values change:

```text
a = 20
b = 10
```

---

# 54. Swapping Pointers vs Pointed Objects

Consider:

```cpp
int a = 10;
int b = 20;

int* p = &a;
int* q = &b;
```

### Swap pointers

```cpp
std::swap(p, q);
```

Result:

```text
p → b
q → a
```

Values:

```text
a = 10
b = 20
```

### Swap pointed values

```cpp
std::swap(*p, *q);
```

This exchanges the values of the objects pointed to.

The distinction is:

```text
swap(p, q)       → swap addresses/pointer values
swap(*p, *q)     → swap pointed-to values
```

---

# 55. Swap With Function Parameters

Because `swap()` modifies objects, it receives references.

Example:

```cpp
void exchange(int& a, int& b)
{
    std::swap(a, b);
}
```

Usage:

```cpp
int x = 10;
int y = 20;

exchange(x, y);
```

After:

```text
x = 20
y = 10
```

---

# 56. Generic Function Using `swap`

```cpp
template<typename T>
void exchange(T& a, T& b)
{
    std::swap(a, b);
}
```

Now:

```cpp
exchange(10, 20);
```

would not work because those are temporary values, but:

```cpp
int a = 10;
int b = 20;

exchange(a, b);
```

works.

It can also work for many other swappable types.

---

# 57. `swap()` and Temporary Values

This is invalid:

```cpp
std::swap(10, 20);
```

because `swap()` needs objects that can be modified, and integer literals are not modifiable lvalues.

Similarly:

```cpp
std::swap(a, 20); // invalid
```

when `a` is an ordinary variable.

Use actual modifiable objects:

```cpp
int x = 20;
std::swap(a, x);
```

---

# 58. `swap()` and `const`

This is invalid:

```cpp
const int a = 10;
const int b = 20;

std::swap(a, b);
```

because `swap()` must modify both arguments.

---

# 59. Raw Array vs `std::array`

This distinction is important.

## Raw array

```cpp
int a[3] = {1, 2, 3};
int b[3] = {4, 5, 6};

std::swap(a, b);
```

Modern C++ `std::swap` supports array overloads and swaps corresponding elements.

Complexity:

```text
O(n)
```

## `std::array`

```cpp
std::array<int, 3> a = {1, 2, 3};
std::array<int, 3> b = {4, 5, 6};

std::swap(a, b);
```

Also works.

Complexity:

```text
O(n)
```

---

# 60. `std::swap()` vs `std::swap_ranges()`

### `std::swap()`

Swaps two objects:

```cpp
std::swap(a, b);
```

### `std::swap_ranges()`

Swaps corresponding elements in two ranges:

```cpp
std::swap_ranges(first1, last1, first2);
```

Example:

```cpp
int a[] = {1, 2, 3};
int b[] = {4, 5, 6};

std::swap_ranges(a, a + 3, b);
```

Use:

```text
swap()        → object-to-object
swap_ranges() → range-to-range
```

---

# 61. Pair Member Swap vs `std::swap`

For:

```cpp
std::pair<int, std::string> p1;
std::pair<int, std::string> p2;
```

You can write:

```cpp
p1.swap(p2);
```

or:

```cpp
std::swap(p1, p2);
```

Both exchange the pair's two members.

---

# 62. Container Member Swap vs `std::swap`

For a vector:

```cpp
std::vector<int> a;
std::vector<int> b;
```

You can write:

```cpp
a.swap(b);
```

or:

```cpp
std::swap(a, b);
```

For standard containers, the free `swap` is generally specified in terms of the container's efficient swap operation.

---

# 63. Swap and Exception Safety

For many standard-library types, `swap()` is designed to be non-throwing or conditionally non-throwing.

For example, many container swaps are `noexcept` under their allocator/type requirements.

This makes `swap()` useful in exception-safe programming.

Do not assume every user-defined `swap()` is `noexcept`; its guarantee depends on its implementation and the types involved.

---

# 64. Important Correction About "Different Data Types"

This:

```cpp
int a = 10;
double b = 5.5;

std::swap(a, b);
```

does **not** work as a normal `std::swap` call.

The usual `std::swap<T>` expects both arguments to have the same `T`.

However, the more general concept is not simply "must have exactly the same type"; a type can define suitable swapping support.

For normal usage, remember:

```text
same type → normal std::swap usage
different types → not normally swappable with std::swap
```

For example:

```cpp
std::swap(a, b); // int and double → ERROR
```

---

# 65. Swappable Types

C++ provides the concept:

```cpp
std::swappable<T>
```

in C++20.

A type is considered swappable when the required swap expressions are valid.

Example:

```cpp
#include <concepts>
#include <utility>

static_assert(std::swappable<int>);
```

This is useful when writing generic C++20 code.

---

# 66. `std::is_swappable`

Before C++20 concepts, type traits can be used.

```cpp
#include <type_traits>
#include <utility>

static_assert(std::is_swappable_v<int>);
```

This checks whether the type is swappable.

For a type `T`:

```cpp
std::is_swappable_v<T>
```

returns a compile-time boolean.

---

# 67. `std::is_nothrow_swappable`

You can also test whether swapping is non-throwing:

```cpp
std::is_nothrow_swappable_v<T>
```

Example:

```cpp
static_assert(std::is_nothrow_swappable_v<int>);
```

This is useful in generic programming.

---

# 68. `std::ranges::swap` in C++20

C++20 also provides:

```cpp
std::ranges::swap(a, b);
```

through the ranges library.

It is designed for modern generic programming and follows the C++20 swappability rules.

Example:

```cpp
#include <ranges>

std::ranges::swap(a, b);
```

For ordinary code:

```cpp
std::swap(a, b);
```

is still the familiar choice.

---

# 69. ADL and `swap`

For generic code, this pattern is important:

```cpp
using std::swap;
swap(a, b);
```

Why not always:

```cpp
std::swap(a, b);
```

inside generic code?

Because unqualified:

```cpp
swap(a, b);
```

after:

```cpp
using std::swap;
```

allows both:

```text
std::swap
```

and an appropriate type-specific `swap` found through argument-dependent lookup.

This can select an optimized custom swap.

---

# 70. Common Mistakes

## Mistake 1 — Forgetting the Header

```cpp
std::swap(a, b);
```

Include:

```cpp
#include <utility>
```

---

## Mistake 2 — Assuming Every Type Is O(1)

Do not assume:

```text
swap → always O(1)
```

For example:

```cpp
std::array<int, 1000>
```

requires swapping its elements and is therefore:

```text
O(n)
```

---

## Mistake 3 — Confusing Pointer Swap and Value Swap

```cpp
std::swap(p, q);
```

swaps pointer objects.

While:

```cpp
std::swap(*p, *q);
```

swaps the pointed-to values.

---

## Mistake 4 — Trying to Swap `const` Objects

```cpp
const int a = 10;
const int b = 20;

std::swap(a, b); // ERROR
```

---

## Mistake 5 — Expecting Different Types to Swap

```cpp
int a = 10;
double b = 20.5;

std::swap(a, b); // ERROR
```

---

## Mistake 6 — Thinking References Can Be Reseated

```cpp
int a = 10;
int b = 20;

int& x = a;
int& y = b;

std::swap(x, y);
```

This changes the values:

```text
a = 20
b = 10
```

It does not make `x` refer to `b` or `y` refer to `a`.

---

# 71. Complete Example

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <utility>

int main()
{
    // Integer
    int a = 10;
    int b = 20;

    std::swap(a, b);

    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';


    // String
    std::string s1 = "Hello";
    std::string s2 = "World";

    std::swap(s1, s2);

    std::cout << s1 << '\n';
    std::cout << s2 << '\n';


    // Vector
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};

    std::swap(v1, v2);


    // Pair
    std::pair<int, std::string> p1 = {1, "One"};
    std::pair<int, std::string> p2 = {2, "Two"};

    std::swap(p1, p2);


    // Array
    std::array<int, 3> arr1 = {1, 2, 3};
    std::array<int, 3> arr2 = {4, 5, 6};

    std::swap(arr1, arr2);


    return 0;
}
```

---

# 72. `std::swap()` Quick Reference

```cpp
#include <utility>

std::swap(a, b);
```

### Return type

```text
void
```

### Main purpose

```text
Exchange two swappable objects
```

### Basic example

```cpp
int a = 10;
int b = 20;

std::swap(a, b);
```

Result:

```text
a = 20
b = 10
```

### Containers

```cpp
std::swap(v1, v2);
```

### Pair

```cpp
std::swap(p1, p2);
```

### Tuple

```cpp
std::swap(t1, t2);
```

### Array

```cpp
std::swap(arr1, arr2);
```

### Raw array

```cpp
std::swap(a, b);
```

swaps the corresponding elements.

### Range

```cpp
std::swap_ranges(first1, last1, first2);
```

---

# 73. `std::swap()` vs Related Operations

| Function | Purpose |
|---|---|
| `std::swap(a, b)` | Swap two objects |
| `a.swap(b)` | Member swap for types that provide it |
| `std::swap_ranges()` | Swap corresponding elements of two ranges |
| `std::ranges::swap()` | C++20 ranges-aware swap |
| `std::move()` | Cast an expression to an xvalue; does not itself swap |
| `std::exchange()` | Replace one value and return its old value |

Important:

```cpp
std::move(a);
```

does **not** move `a` by itself.

It is a cast used to enable move operations.

---

# 74. `swap()` vs `exchange()`

These are different.

### `swap`

```cpp
std::swap(a, b);
```

Result:

```text
a ← old b
b ← old a
```

### `exchange`

```cpp
auto old = std::exchange(a, newValue);
```

Result:

```text
old     = old a
a       = newValue
```

So:

```text
swap      → exchange two objects
exchange  → replace one object's value and return its old value
```

---

# 75. Interview Questions

## Q1. What is `std::swap()`?

`std::swap()` is a Standard Library function that exchanges the values/resources of two swappable objects.

---

## Q2. Which header provides `std::swap()`?

Primary header:

```cpp
#include <utility>
```

It is also available through `<algorithm>`.

---

## Q3. What is the return type?

```cpp
void
```

---

## Q4. Does `swap()` return the exchanged values?

No.

It modifies both objects directly and returns nothing.

---

## Q5. Does `swap()` always have O(1) complexity?

No.

The complexity depends on the type.

Examples:

```text
vector → O(1)
map → O(1)
set → O(1)
array → O(n)
```

---

## Q6. Why is vector swap O(1)?

A vector owns dynamically allocated storage. Swapping vectors can exchange their internal ownership/state instead of moving every element individually.

---

## Q7. Why is `std::array` swap O(n)?

`std::array` contains its elements directly as part of the object, so its elements need to be swapped.

---

## Q8. Can raw arrays be swapped using `std::swap()`?

Yes. `std::swap` has an array overload that swaps corresponding elements.

For example:

```cpp
int a[3] = {1, 2, 3};
int b[3] = {4, 5, 6};

std::swap(a, b);
```

This performs an element-wise swap.

---

## Q9. Can `const` objects be swapped?

No.

```cpp
const int a = 10;
const int b = 20;

std::swap(a, b); // ERROR
```

---

## Q10. Can an `int` and `double` normally be swapped?

No:

```cpp
int a = 10;
double b = 20.5;

std::swap(a, b); // ERROR
```

---

## Q11. What is the difference between:

```cpp
std::swap(p, q);
```

and:

```cpp
std::swap(*p, *q);
```

If `p` and `q` are pointers:

```text
std::swap(p, q)
```

swaps the pointer values.

```text
std::swap(*p, *q)
```

swaps the values of the objects they point to.

---

## Q12. What is the difference between `swap()` and `std::swap_ranges()`?

```cpp
std::swap(a, b);
```

swaps two objects.

```cpp
std::swap_ranges(...);
```

swaps corresponding elements in two ranges.

---

# 76. Final Mental Model

Think of:

```cpp
std::swap(a, b);
```

as:

```text
BEFORE

a ──→ Value A
b ──→ Value B


AFTER

a ──→ Value B
b ──→ Value A
```

The objects themselves remain the same objects.

Only their values/resources are exchanged.

---

# 77. Final Checklist

- [x] What `std::swap()` is
- [x] `<utility>` header
- [x] `<algorithm>` availability
- [x] `std::swap(a, b)` syntax
- [x] Parameters
- [x] `void` return type
- [x] Basic swapping
- [x] Manual swap comparison
- [x] Conceptual implementation
- [x] Move semantics
- [x] Integers
- [x] Floating-point values
- [x] Characters
- [x] Booleans
- [x] Strings
- [x] Vectors
- [x] Pairs
- [x] Tuples
- [x] `std::array`
- [x] Raw arrays
- [x] `std::swap_ranges()`
- [x] Sets
- [x] Maps
- [x] Unordered maps
- [x] Deques
- [x] Lists
- [x] Forward lists
- [x] Queues
- [x] Stacks
- [x] Priority queues
- [x] Iterators
- [x] Pointers
- [x] References
- [x] Custom classes
- [x] Custom `swap()`
- [x] `using std::swap`
- [x] ADL
- [x] `noexcept`
- [x] Swappable types
- [x] `std::is_swappable`
- [x] `std::is_nothrow_swappable`
- [x] C++20 `std::swappable`
- [x] C++20 `std::ranges::swap`
- [x] Sorting use cases
- [x] Complexity
- [x] Space complexity
- [x] Common mistakes
- [x] Interview questions
- [x] `swap()` vs `swap_ranges()`
- [x] `swap()` vs `exchange()`
- [x] `swap()` vs `move()`

## One-Line Definition

> **`std::swap(a, b)` is a generic C++ Standard Library operation that exchanges two swappable objects, with the actual complexity and behavior determined by their types.**