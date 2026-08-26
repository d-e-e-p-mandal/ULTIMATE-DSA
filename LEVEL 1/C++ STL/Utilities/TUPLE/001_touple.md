# C++ `std::tuple` — Complete Notes

## Table of Contents

1. Introduction
2. Header File
3. Namespace
4. Syntax
5. Template Declaration
6. Why Use `tuple`?
7. Characteristics
8. Internal Working
9. Memory Layout
10. Creating a Tuple
11. Tuple Constructors
12. Accessing Elements
13. Access by Type
14. Modifying Elements
15. `tuple_size`
16. `tuple_element`
17. `make_tuple()`
18. `tie()`
19. `ignore`
20. `forward_as_tuple()`
21. `tuple_cat()`
22. `swap()`
23. Comparison Operators
24. Structured Binding
25. Returning Multiple Values
26. Passing Tuple to Functions
27. `apply()`
28. `make_from_tuple()`
29. Nested Tuples
30. Tuple with STL Containers
31. Tuple in `map`
32. Tuple in `set`
33. Tuple in `priority_queue`
34. Common Tuple Utilities
35. Tuple Does Not Have Container Functions
36. Copy and Move Semantics
37. `const` Tuples
38. Tuple References
39. Tuple vs Pair
40. Tuple vs Array
41. Tuple vs Struct/Class
42. Time Complexity
43. Advantages
44. Disadvantages
45. Real-World Examples
46. Common Mistakes
47. Interview Questions
48. Complete Programs
49. Final Checklist
50. Summary

---

# 1. Introduction

`std::tuple` is a **fixed-size heterogeneous utility type** introduced in **C++11**.

It allows multiple values of different types to be stored together in one object.

Example:

```cpp
std::tuple<int, std::string, double> student{
    101,
    "Deep",
    9.4
};
```

This single tuple contains:

```text
Element 0 → int
Element 1 → string
Element 2 → double
```

Unlike `std::pair`, which stores exactly two elements, a tuple can contain **zero, one, two, or many elements**.

---

# 2. Header File

The main header is:

```cpp
#include <tuple>
```

For example:

```cpp
#include <iostream>
#include <tuple>
#include <string>
```

---

# 3. Namespace

`tuple` belongs to the `std` namespace.

Without:

```cpp
using namespace std;
```

write:

```cpp
std::tuple<int, std::string, double> t;
```

With:

```cpp
using namespace std;
```

you can write:

```cpp
tuple<int, string, double> t;
```

In production code, `std::` is generally preferred over a global `using namespace std;`.

---

# 4. Basic Syntax

```cpp
std::tuple<T1, T2, T3, ...> variable;
```

Example:

```cpp
std::tuple<int, std::string, double> student;
```

The types and number of elements are determined at compile time.

---

# 5. Template Declaration

Conceptually, `tuple` is a variadic class template:

```cpp
template<class... Types>
class tuple;
```

The `...` means that it accepts a variable number of template type arguments.

Examples:

```cpp
std::tuple<>
std::tuple<int>
std::tuple<int, double>
std::tuple<int, char, std::string>
std::tuple<int, std::string, double, bool>
```

All are valid.

---

# 6. Why Use `tuple`?

Suppose a function needs to return three values:

```cpp
int id;
std::string name;
double salary;
```

Instead of creating a special class just for a temporary result, you can return:

```cpp
std::tuple<int, std::string, double>
```

Example:

```cpp
std::tuple<int, std::string, double> getEmployee()
{
    return {101, "Deep", 50000.0};
}
```

This is particularly useful for:

- Returning multiple values
- Generic programming
- Temporary grouping of values
- Competitive programming
- STL algorithms
- Structured bindings
- Template programming

---

# 7. Characteristics

`std::tuple` is:

- Fixed-size
- Heterogeneous
- Type-safe
- Compile-time sized
- Able to contain different types
- Able to contain repeated types
- Copyable when its elements are copyable
- Movable when its elements are movable
- Comparable when its elements are comparable
- Compatible with structured bindings
- Compatible with `std::apply`
- Compatible with `std::make_from_tuple`

A tuple is **not a dynamically resizable container** like `std::vector`.

---

# 8. Internal Working

A tuple is a library type implemented using templates.

A simplified conceptual representation might look like:

```text
tuple<int, double, string>

    ├── int
    ├── double
    └── string
```

The actual implementation is library-specific and may use techniques such as:

- Template inheritance
- Recursive structures
- Empty Base Optimization
- Variadic templates
- Compile-time indexing

You should not assume that the actual implementation literally looks like:

```cpp
tuple<int, tuple<double, tuple<string>>>
```

That is only a useful conceptual model.

---

# 9. Memory Layout

Consider:

```cpp
std::tuple<int, double, char> t;
```

Conceptually, it contains:

```text
+----------------+
| int            |
+----------------+
| double         |
+----------------+
| char           |
+----------------+
```

However, the exact memory layout is implementation-dependent.

Padding and alignment may be present.

Therefore:

```cpp
sizeof(std::tuple<int, char>)
```

does not necessarily equal:

```cpp
sizeof(int) + sizeof(char)
```

A tuple is an object containing its elements, but its exact physical layout should not be relied upon for serialization or binary-format assumptions.

---

# 10. Creating a Tuple

## 10.1 Empty Tuple

```cpp
std::tuple<> t;
```

It contains zero elements.

Its size is:

```cpp
std::tuple_size_v<decltype(t)>
```

which is:

```text
0
```

---

## 10.2 One Element

```cpp
std::tuple<int> t(10);
```

---

## 10.3 Multiple Elements

```cpp
std::tuple<int, std::string, double> t(
    101,
    "Deep",
    9.4
);
```

---

## 10.4 Brace Initialization

```cpp
std::tuple<int, std::string, double> t{
    101,
    "Deep",
    9.4
};
```

This is often the cleanest form.

---

# 11. Tuple Constructors

## 11.1 Default Construction

```cpp
std::tuple<int, std::string> t;
```

The elements are value-initialized.

Conceptually:

```text
int    → 0
string → ""
```

---

## 11.2 Value Construction

```cpp
std::tuple<int, std::string> t{
    101,
    "Deep"
};
```

---

## 11.3 Copy Construction

```cpp
std::tuple<int, std::string> t1{
    101,
    "Deep"
};

std::tuple<int, std::string> t2(t1);
```

or:

```cpp
std::tuple<int, std::string> t2 = t1;
```

---

## 11.4 Move Construction

```cpp
std::tuple<std::string> t1{
    "Hello"
};

std::tuple<std::string> t2{
    std::move(t1)
};
```

`std::move()` is normally available through:

```cpp
#include <utility>
```

---

# 12. Accessing Elements

Tuple elements are accessed using:

```cpp
std::get<index>(tuple)
```

Example:

```cpp
std::tuple<int, std::string, double> t{
    101,
    "Deep",
    9.4
};

std::cout << std::get<0>(t) << '\n';
std::cout << std::get<1>(t) << '\n';
std::cout << std::get<2>(t) << '\n';
```

Output:

```text
101
Deep
9.4
```

---

# 13. Tuple Indexing Starts at 0

For:

```cpp
std::tuple<int, std::string, double> t;
```

the indices are:

```text
0 → int
1 → string
2 → double
```

Therefore:

```cpp
std::get<0>(t);
std::get<1>(t);
std::get<2>(t);
```

There is no:

```cpp
std::get<3>(t);
```

because the tuple has only three elements.

---

# 14. Tuple Index Must Be Known at Compile Time

This is an important property.

This works:

```cpp
std::get<0>(t);
```

But this does not work for an ordinary runtime variable:

```cpp
int index = 1;

std::get<index>(t); // ERROR
```

Why?

Because the tuple element type and location are determined at compile time.

For runtime-indexed heterogeneous access, a tuple is generally not the appropriate abstraction.

---

# 15. Access by Type

C++14 introduced access by type.

Example:

```cpp
std::tuple<int, char, double> t{
    10,
    'A',
    3.14
};

std::cout << std::get<double>(t);
```

Output:

```text
3.14
```

The type must occur **exactly once**.

---

# 16. Duplicate Types

Consider:

```cpp
std::tuple<int, int, double> t{
    10,
    20,
    3.14
};
```

This is invalid:

```cpp
std::get<int>(t); // ERROR
```

because there are two `int` elements.

The compiler cannot determine which `int` you mean.

Use an index instead:

```cpp
std::get<0>(t);
std::get<1>(t);
```

---

# 17. Modifying Tuple Elements

`std::get<>` can return a reference to an element.

Therefore:

```cpp
std::tuple<int, std::string, double> t{
    10,
    "ABC",
    3.14
};

std::get<0>(t) = 100;
std::get<1>(t) = "Deep";
std::get<2>(t) = 9.5;
```

Now:

```text
100
Deep
9.5
```

---

# 18. `const` Tuple

Consider:

```cpp
const std::tuple<int, std::string> t{
    10,
    "Deep"
};
```

You can read:

```cpp
std::cout << std::get<0>(t);
```

But cannot modify:

```cpp
std::get<0>(t) = 100; // ERROR
```

because the tuple is `const`.

---

# 19. `tuple_size`

`std::tuple_size` tells you how many elements a tuple contains.

Example:

```cpp
std::tuple<int, std::string, double> t;

std::cout << std::tuple_size<decltype(t)>::value;
```

Output:

```text
3
```

---

# 20. Modern `tuple_size_v`

C++17 provides the variable template:

```cpp
std::tuple_size_v<T>
```

Example:

```cpp
std::cout << std::tuple_size_v<
    std::tuple<int, std::string, double>
>;
```

Output:

```text
3
```

This is shorter than:

```cpp
std::tuple_size<T>::value
```

---

# 21. `tuple_element`

`std::tuple_element` gives the type of a tuple element.

Example:

```cpp
using T = std::tuple<int, double, char>;

std::tuple_element<1, T>::type x = 5.8;
```

The type of `x` is:

```text
double
```

---

# 22. Modern `tuple_element_t`

C++14 provides:

```cpp
std::tuple_element_t<Index, Tuple>
```

Example:

```cpp
using T = std::tuple<int, double, char>;

std::tuple_element_t<1, T> x = 5.8;
```

This is equivalent to:

```cpp
typename std::tuple_element<1, T>::type
```

but shorter.

---

# 23. `make_tuple()`

`std::make_tuple()` creates a tuple while allowing the compiler to deduce the types.

Example:

```cpp
auto t = std::make_tuple(
    101,
    std::string("Deep"),
    9.4
);
```

The type is approximately:

```cpp
std::tuple<int, std::string, double>
```

---

# 24. `make_tuple()` and String Literals

Consider:

```cpp
auto t = std::make_tuple(10, "Deep", 9.4);
```

The string literal is handled by `make_tuple` so that the resulting tuple element is a suitable decayed type, typically:

```text
const char*
```

Therefore the type is approximately:

```cpp
std::tuple<int, const char*, double>
```

If you specifically want `std::string`:

```cpp
auto t = std::make_tuple(
    10,
    std::string("Deep"),
    9.4
);
```

---

# 25. `make_tuple()` and Type Deduction

Instead of:

```cpp
std::tuple<int, std::string, double> t{
    101,
    "Deep",
    9.4
};
```

you can write:

```cpp
auto t = std::make_tuple(
    101,
    std::string("Deep"),
    9.4
);
```

This is particularly convenient when the types are complicated.

---

# 26. `tie()`

`std::tie()` creates a tuple of references.

It is commonly used to unpack a tuple into existing variables.

Example:

```cpp
std::tuple<int, std::string, double> t{
    101,
    "Deep",
    9.4
};

int id;
std::string name;
double cgpa;

std::tie(id, name, cgpa) = t;
```

Now:

```text
id   = 101
name = Deep
cgpa = 9.4
```

---

# 27. `tie()` with `ignore`

If you do not need an element:

```cpp
int id;
double cgpa;

std::tie(id, std::ignore, cgpa) = t;
```

The string element is ignored.

Example:

```cpp
std::tuple<int, std::string, double> t{
    101,
    "Deep",
    9.4
};

int id;
double cgpa;

std::tie(id, std::ignore, cgpa) = t;
```

Result:

```text
id   = 101
cgpa = 9.4
```

---

# 28. `std::ignore`

`std::ignore` is a special placeholder used with tuple-like assignment operations such as `std::tie`.

Example:

```cpp
std::tie(a, std::ignore, c) = t;
```

It means:

```text
first  → a
second → ignore
third  → c
```

---

# 29. `forward_as_tuple()`

`std::forward_as_tuple()` creates a tuple of forwarding references.

Example:

```cpp
auto t = std::forward_as_tuple(
    10,
    std::string("ABC")
);
```

It is primarily a **template-programming utility**.

Common uses include:

- Perfect forwarding
- `emplace`
- `piecewise_construct`
- Generic library code

---

# 30. Important Lifetime Warning with `forward_as_tuple()`

`forward_as_tuple()` can contain references to temporary objects.

For example:

```cpp
auto t = std::forward_as_tuple(
    std::string("temporary")
);
```

The temporary string may be destroyed at the end of the full expression, leaving a dangling reference inside `t`.

Therefore, do not treat the result as an owning tuple.

Use it primarily for immediate forwarding.

---

# 31. `tuple_cat()`

`std::tuple_cat()` combines multiple tuples into one tuple.

Example:

```cpp
auto t1 = std::make_tuple(1, 2);
auto t2 = std::make_tuple("ABC", 3.5);

auto t3 = std::tuple_cat(t1, t2);
```

Conceptually:

```text
t1 = (1, 2)
t2 = ("ABC", 3.5)

t3 = (1, 2, "ABC", 3.5)
```

---

# 32. `tuple_cat()` with More Tuples

You can concatenate multiple tuples:

```cpp
auto a = std::make_tuple(1);
auto b = std::make_tuple(2.0);
auto c = std::make_tuple('A');
auto d = std::make_tuple("Hello");

auto result = std::tuple_cat(a, b, c, d);
```

Result:

```text
(1, 2.0, 'A', "Hello")
```

---

# 33. `swap()`

Tuples support swapping.

```cpp
std::tuple<int, std::string> t1{
    1,
    "A"
};

std::tuple<int, std::string> t2{
    2,
    "B"
};

std::swap(t1, t2);
```

After:

```text
t1 = (2, B)
t2 = (1, A)
```

---

# 34. Tuple Member `swap()`

A tuple also provides a member swap operation:

```cpp
t1.swap(t2);
```

Example:

```cpp
std::tuple<int, std::string> t1{1, "A"};
std::tuple<int, std::string> t2{2, "B"};

t1.swap(t2);
```

---

# 35. Tuple Comparison

Tuples support comparison when their element types support the required comparisons.

Examples include:

```cpp
t1 == t2
t1 != t2
t1 < t2
t1 <= t2
t1 > t2
t1 >= t2
```

In modern C++, the comparison facilities are specified through the standard relational/comparison machinery, and C++20 also provides three-way comparison where the element types support it.

---

# 36. Lexicographical Comparison

Tuple comparison is lexicographical.

Consider:

```cpp
std::tuple<int, int> a{1, 2};
std::tuple<int, int> b{1, 3};
```

First:

```text
1 == 1
```

So compare the second elements:

```text
2 < 3
```

Therefore:

```cpp
a < b
```

is `true`.

---

# 37. Another Comparison Example

```cpp
std::tuple<int, int, int> a{1, 100, 200};
std::tuple<int, int, int> b{2, 1, 1};
```

Compare first elements:

```text
1 < 2
```

Therefore:

```cpp
a < b
```

is `true`.

The second and third elements do not matter.

---

# 38. Structured Binding — C++17

Structured binding makes tuple extraction very convenient.

```cpp
std::tuple<int, std::string, double> t{
    101,
    "Deep",
    9.4
};

auto [id, name, cgpa] = t;
```

Now:

```text
id   = 101
name = Deep
cgpa = 9.4
```

---

# 39. Structured Binding by Reference

```cpp
auto& [id, name, cgpa] = t;
```

Now the variables refer to the tuple's elements.

Therefore:

```cpp
id = 500;
name = "John";
cgpa = 8.5;
```

changes the original tuple.

---

# 40. `const auto&` Structured Binding

For read-only access without copying:

```cpp
const auto& [id, name, cgpa] = t;
```

This is especially useful when the tuple contains expensive objects.

---

# 41. Returning Multiple Values

A function can return a tuple.

```cpp
std::tuple<int, int, int> getValues()
{
    return {10, 20, 30};
}
```

Use:

```cpp
auto [a, b, c] = getValues();
```

Output:

```text
10
20
30
```

---

# 42. Returning Different Types

```cpp
std::tuple<int, std::string, double> getStudent()
{
    return {
        101,
        "Deep",
        9.4
    };
}
```

Then:

```cpp
auto [id, name, cgpa] = getStudent();
```

This is one of the most common practical uses of tuples.

---

# 43. Passing Tuple to a Function

You can pass a tuple normally.

```cpp
void print(
    const std::tuple<int, std::string>& t
)
{
    std::cout << std::get<0>(t) << '\n';
    std::cout << std::get<1>(t) << '\n';
}
```

Call:

```cpp
print({101, "Deep"});
```

---

# 44. Passing Tuple by Reference

If the function needs to modify the tuple:

```cpp
void modify(
    std::tuple<int, std::string>& t
)
{
    std::get<0>(t) = 200;
}
```

---

# 45. Passing Tuple Generically

A template can accept any tuple-like type:

```cpp
template<typename Tuple>
void printFirst(Tuple& t)
{
    std::cout << std::get<0>(t);
}
```

The exact valid operations depend on the tuple-like type.

---

# 46. `std::apply()`

`std::apply()` is an important tuple utility introduced in C++17.

It invokes a callable using tuple elements as function arguments.

Example:

```cpp
#include <iostream>
#include <tuple>

void print(int a, double b, const std::string& c)
{
    std::cout << a << ' '
              << b << ' '
              << c << '\n';
}
```

Tuple:

```cpp
auto t = std::make_tuple(
    10,
    3.14,
    std::string("Hello")
);
```

Call:

```cpp
std::apply(print, t);
```

Conceptually:

```cpp
print(
    std::get<0>(t),
    std::get<1>(t),
    std::get<2>(t)
);
```

---

# 47. `std::apply()` with Lambda

```cpp
auto t = std::make_tuple(10, 20, 30);

std::apply(
    [](int a, int b, int c)
    {
        std::cout << a + b + c;
    },
    t
);
```

Output:

```text
60
```

---

# 48. `std::apply()` with Generic Lambda

```cpp
auto t = std::make_tuple(
    10,
    std::string("Deep"),
    9.4
);

std::apply(
    [](const auto&... args)
    {
        ((std::cout << args << ' '), ...);
    },
    t
);
```

This is a powerful combination of:

- Tuples
- Variadic templates
- Generic lambdas
- Fold expressions

---

# 49. `std::make_from_tuple()`

C++17 also provides:

```cpp
std::make_from_tuple<T>(tuple)
```

It constructs an object using tuple elements as constructor arguments.

Example:

```cpp
class Student
{
public:
    int id;
    std::string name;

    Student(int id, std::string name)
        : id(id), name(std::move(name))
    {
    }
};
```

Tuple:

```cpp
auto data = std::make_tuple(
    101,
    std::string("Deep")
);
```

Construct:

```cpp
Student s = std::make_from_tuple<Student>(data);
```

Conceptually:

```cpp
Student s(101, "Deep");
```

---

# 50. Nested Tuple

A tuple can contain another tuple.

Example:

```cpp
std::tuple<
    int,
    std::tuple<std::string, double>,
    char
> t{
    10,
    {"Deep", 9.4},
    'A'
};
```

Access first element:

```cpp
std::get<0>(t);
```

Access nested string:

```cpp
std::get<0>(
    std::get<1>(t)
);
```

Access nested double:

```cpp
std::get<1>(
    std::get<1>(t)
);
```

---

# 51. Tuple of Vectors

A tuple can contain containers.

```cpp
std::tuple<
    std::vector<int>,
    std::vector<std::string>
> data;
```

Access:

```cpp
std::get<0>(data);
std::get<1>(data);
```

---

# 52. Vector of Tuples

This is common in competitive programming.

```cpp
std::vector<
    std::tuple<int, std::string, double>
> students;
```

Insert:

```cpp
students.push_back(
    {101, "Deep", 9.4}
);
```

Another:

```cpp
students.emplace_back(
    102,
    "John",
    8.7
);
```

---

# 53. Iterating Over a Vector of Tuples

Using `get`:

```cpp
for (const auto& student : students)
{
    std::cout
        << std::get<0>(student) << ' '
        << std::get<1>(student) << ' '
        << std::get<2>(student)
        << '\n';
}
```

Using structured bindings:

```cpp
for (const auto& [id, name, cgpa] : students)
{
    std::cout
        << id << ' '
        << name << ' '
        << cgpa
        << '\n';
}
```

The structured-binding version is usually easier to read.

---

# 54. Tuple as `map` Key

A tuple can be used as a key in `std::map` when its element types support the necessary ordering.

Example:

```cpp
std::map<
    std::tuple<int, int, int>,
    std::string
> mp;
```

Insert:

```cpp
mp[{1, 2, 3}] = "A";
mp[{1, 2, 4}] = "B";
```

The map orders tuple keys lexicographically.

---

# 55. Tuple as `set` Element

```cpp
std::set<
    std::tuple<int, int, int>
> s;
```

Insert:

```cpp
s.insert({1, 2, 3});
s.insert({2, 3, 4});
```

Tuple comparison determines the ordering.

---

# 56. Tuple in `priority_queue`

A tuple can also be used with a priority queue.

```cpp
std::priority_queue<
    std::tuple<int, int, int>
> pq;
```

Insert:

```cpp
pq.push({1, 2, 3});
pq.push({5, 1, 2});
pq.push({3, 4, 5});
```

By default, the lexicographically largest tuple has the highest priority.

This is useful in algorithms such as:

- Graph algorithms
- Dijkstra variants
- Scheduling
- Competitive programming

---

# 57. Tuple with `unordered_map`

Unlike `map`, an `unordered_map` needs a hash.

A standard `std::hash<std::tuple<...>>` is not generally provided for arbitrary tuples.

Therefore:

```cpp
std::unordered_map<
    std::tuple<int, int>,
    int
> mp;
```

may require a custom hash.

Example:

```cpp
struct TupleHash
{
    std::size_t operator()(
        const std::tuple<int, int>& t
    ) const
    {
        std::size_t h1 =
            std::hash<int>{}(std::get<0>(t));

        std::size_t h2 =
            std::hash<int>{}(std::get<1>(t));

        return h1 ^ (h2 << 1);
    }
};
```

Then:

```cpp
std::unordered_map<
    std::tuple<int, int>,
    int,
    TupleHash
> mp;
```

---

# 58. Common Tuple Utilities

| Utility | Purpose |
|---|---|
| `get<I>(t)` | Access element by index |
| `get<T>(t)` | Access unique element by type |
| `tuple_size<T>` | Number of elements |
| `tuple_size_v<T>` | C++17 shorthand |
| `tuple_element<I, T>` | Type of element |
| `tuple_element_t<I, T>` | C++14 shorthand |
| `make_tuple()` | Create tuple |
| `tie()` | Create tuple of references |
| `ignore` | Ignore an element with `tie()` |
| `forward_as_tuple()` | Create forwarding-reference tuple |
| `tuple_cat()` | Concatenate tuples |
| `swap()` | Exchange two tuples |
| `apply()` | Call function using tuple elements |
| `make_from_tuple()` | Construct object from tuple |

---

# 59. Tuple Does Not Have `size()`

This is an important distinction.

This does not work:

```cpp
t.size(); // ERROR
```

A tuple is not a normal STL container.

Use:

```cpp
std::tuple_size<decltype(t)>::value
```

or:

```cpp
std::tuple_size_v<decltype(t)>
```

---

# 60. Tuple Does Not Have Iterators

A tuple does not provide:

```cpp
t.begin();
t.end();
```

Therefore:

```cpp
for (auto x : t)
{
}
```

does not work like it does for a vector.

A tuple's elements can have completely different types, so ordinary homogeneous iteration is not directly applicable.

For processing all elements generically, `std::apply()` is often useful.

---

# 61. Tuple Does Not Have `push_back()`

This is invalid:

```cpp
t.push_back(10); // ERROR
```

A tuple has a fixed number of elements.

You cannot dynamically add another element.

---

# 62. Tuple Does Not Have `pop_back()`

This is invalid:

```cpp
t.pop_back(); // ERROR
```

Again, the tuple size is fixed at compile time.

---

# 63. Tuple Does Not Have `resize()`

This is invalid:

```cpp
t.resize(10); // ERROR
```

The number of elements is part of the tuple's type.

For example:

```cpp
std::tuple<int, double>
```

and:

```cpp
std::tuple<int, double, char>
```

are different types.

---

# 64. Copy Semantics

If every element is copyable, the tuple is generally copyable.

Example:

```cpp
std::tuple<int, std::string> t1{
    10,
    "Hello"
};

auto t2 = t1;
```

Both tuples contain equivalent values.

---

# 65. Move Semantics

If the elements support moving, tuples support move operations accordingly.

Example:

```cpp
std::tuple<std::string> t1{
    "Hello"
};

auto t2 = std::move(t1);
```

This allows the string resource to be moved rather than necessarily copied.

---

# 66. Tuple Assignment

Example:

```cpp
std::tuple<int, std::string> t1{
    10,
    "A"
};

std::tuple<int, std::string> t2;

t2 = t1;
```

Move assignment:

```cpp
t2 = std::move(t1);
```

---

# 67. Tuple of References

You can create a tuple containing references using `std::tie()`.

Example:

```cpp
int a = 10;
std::string name = "Deep";

auto t = std::tie(a, name);
```

The tuple holds references to:

```text
a
name
```

Therefore:

```cpp
std::get<0>(t) = 100;
```

changes:

```text
a = 100
```

---

# 68. `tuple` vs `pair`

| Feature | `tuple` | `pair` |
|---|---|---|
| Standard | C++11 | C++98 |
| Number of elements | Any fixed number | Exactly 2 |
| Different types | Yes | Yes |
| Access | `get<I>()` | `first`, `second`, `get<I>()` |
| Structured binding | Yes | Yes |
| `make_*` | `make_tuple()` | `make_pair()` |
| `tie()` | Yes | Works with pair |
| Best for | Multiple values | Exactly two values |

Example:

```cpp
std::pair<int, std::string> p;
```

vs:

```cpp
std::tuple<int, std::string, double> t;
```

Use `pair` for two values.

Use `tuple` when more than two heterogeneous values are needed.

---

# 69. Tuple vs Array

`std::array`:

```cpp
std::array<int, 3> a;
```

All elements have the same type.

Tuple:

```cpp
std::tuple<int, std::string, double> t;
```

Elements can have different types.

| Feature | `array` | `tuple` |
|---|---|---|
| Size | Fixed | Fixed |
| Element types | Same | Can differ |
| `size()` | Yes | No |
| Iterators | Yes | No |
| `get<>` | Yes | Yes |
| Range-based `for` | Yes | No |
| `push_back()` | No | No |

---

# 70. Tuple vs Struct/Class

Tuple:

```cpp
std::tuple<int, std::string, double> student;
```

Access:

```cpp
std::get<0>(student);
std::get<1>(student);
std::get<2>(student);
```

Struct:

```cpp
struct Student
{
    int id;
    std::string name;
    double cgpa;
};
```

Access:

```cpp
student.id;
student.name;
student.cgpa;
```

A struct is usually more readable for meaningful domain data.

Tuple is convenient for:

- Temporary grouping
- Generic code
- Multiple return values
- Algorithms
- Competitive programming

---

# 71. Time Complexity

The complexity depends on the operation and element types.

| Operation | Typical Complexity |
|---|---:|
| `get<I>()` | O(1) |
| Modification through `get<I>()` | O(1) |
| `tuple_size` | O(1) |
| `tuple_element` | O(1) compile-time trait |
| `make_tuple()` | Depends on element construction |
| `tie()` | O(1) |
| `tuple_cat()` | Depends on number/type of elements and construction |
| `swap()` | Depends on element swaps |
| Comparison | O(n) worst case |
| `apply()` | Depends on called function |

Here:

```text
n = number of tuple elements
```

Do not interpret every operation as a runtime loop. Many tuple operations are resolved at compile time.

---

# 72. `get<I>()` Complexity

For:

```cpp
std::get<2>(t);
```

the index is compile-time known.

Access is effectively constant-time:

```text
O(1)
```

There is no runtime search through the tuple.

---

# 73. Tuple Comparison Complexity

For:

```cpp
a < b
```

the comparison is lexicographical.

Conceptually:

```text
compare element 0
       ↓
if equal
       ↓
compare element 1
       ↓
if equal
       ↓
compare element 2
       ↓
...
```

Worst-case complexity is proportional to the number of elements:

```text
O(n)
```

---

# 74. Advantages

## 1. Heterogeneous Data

```cpp
std::tuple<int, std::string, double>
```

can contain different types.

## 2. Fixed Size

The size is known at compile time.

## 3. Type Safe

The compiler knows the type of every element.

## 4. Multiple Return Values

Functions can return multiple values conveniently.

## 5. Structured Bindings

C++17 makes extraction very readable.

## 6. Generic Programming

Tuple utilities are heavily used in template programming.

## 7. STL Compatibility

Tuples work naturally with:

- `map`
- `set`
- `vector`
- `priority_queue`
- Algorithms

---

# 75. Disadvantages

## 1. Poor Readability for Complex Data

This:

```cpp
std::get<3>(employee)
```

does not explain what element 3 means.

A struct:

```cpp
employee.salary
```

is clearer.

---

## 2. Fixed Size

You cannot dynamically add elements.

---

## 3. Index-Based Access

You must remember the position of each value.

---

## 4. Duplicate Types Cannot Be Accessed by Type

For:

```cpp
std::tuple<int, int> t;
```

this is ambiguous:

```cpp
std::get<int>(t); // ERROR
```

Use:

```cpp
std::get<0>(t);
std::get<1>(t);
```

---

## 5. Not a Normal Container

No:

```cpp
size()
begin()
end()
push_back()
pop_back()
```

---

# 76. Real-World Example — Student

```cpp
std::tuple<int, std::string, double> student{
    101,
    "Deep",
    9.4
};
```

Structured binding:

```cpp
auto [id, name, cgpa] = student;
```

---

# 77. Real-World Example — Employee

```cpp
std::tuple<
    int,
    std::string,
    int,
    double
> employee{
    101,
    "John",
    30,
    50000.0
};
```

Structured binding:

```cpp
auto [id, name, age, salary] = employee;
```

---

# 78. Real-World Example — 3D Coordinate

```cpp
std::tuple<int, int, int> point{
    10,
    20,
    30
};
```

Structured binding:

```cpp
auto [x, y, z] = point;
```

---

# 79. Real-World Example — Multiple Return Values

```cpp
std::tuple<int, int, int> calculate()
{
    int sum = 30;
    int product = 200;
    int difference = 10;

    return {
        sum,
        product,
        difference
    };
}
```

Usage:

```cpp
auto [sum, product, difference] = calculate();
```

---

# 80. Real-World Example — Database-Like Result

```cpp
std::tuple<
    int,
    std::string,
    double
> record{
    101,
    "Deep",
    50000.0
};
```

Can represent:

```text
ID
Name
Salary
```

For long-lived business/domain models, however, a named struct is often more maintainable.

---

# 81. Real-World Example — Graph Algorithm

A tuple is frequently useful for storing multiple pieces of graph information.

Example:

```cpp
std::tuple<int, int, int> edge{
    1,
    2,
    10
};
```

Conceptually:

```text
source = 1
target = 2
weight = 10
```

Loop:

```cpp
for (const auto& [u, v, weight] : edges)
{
    std::cout
        << u << ' '
        << v << ' '
        << weight << '\n';
}
```

---

# 82. Common Mistakes

## Mistake 1 — Wrong Index

```cpp
std::tuple<int, double> t;

std::get<2>(t); // ERROR
```

Valid indices:

```text
0
1
```

---

## Mistake 2 — Runtime Index

```cpp
int index = 1;

std::get<index>(t); // ERROR
```

Tuple indices must be compile-time constants.

---

## Mistake 3 — Duplicate Type Access

```cpp
std::tuple<int, int> t;

std::get<int>(t); // ERROR
```

Use:

```cpp
std::get<0>(t);
std::get<1>(t);
```

---

## Mistake 4 — Expecting `size()`

```cpp
t.size(); // ERROR
```

Use:

```cpp
std::tuple_size_v<decltype(t)>
```

---

## Mistake 5 — Expecting Iterators

```cpp
t.begin(); // ERROR
```

A tuple is not a range/container in the ordinary STL sense.

---

## Mistake 6 — Expecting Dynamic Growth

```cpp
t.push_back(10); // ERROR
```

Tuple size is fixed by its type.

---

# 83. Complete Program — Basic Tuple

```cpp
#include <iostream>
#include <string>
#include <tuple>

int main()
{
    std::tuple<int, std::string, double> student{
        101,
        "Deep",
        9.4
    };

    std::cout << "ID: "
              << std::get<0>(student)
              << '\n';

    std::cout << "Name: "
              << std::get<1>(student)
              << '\n';

    std::cout << "CGPA: "
              << std::get<2>(student)
              << '\n';

    return 0;
}
```

Output:

```text
ID: 101
Name: Deep
CGPA: 9.4
```

---

# 84. Complete Program — Structured Binding

```cpp
#include <iostream>
#include <string>
#include <tuple>

int main()
{
    std::tuple<int, std::string, double> student{
        101,
        "Deep",
        9.4
    };

    auto [id, name, cgpa] = student;

    std::cout << id << '\n';
    std::cout << name << '\n';
    std::cout << cgpa << '\n';

    return 0;
}
```

---

# 85. Complete Program — `tie()`

```cpp
#include <iostream>
#include <string>
#include <tuple>

int main()
{
    std::tuple<int, std::string, double> student{
        101,
        "Deep",
        9.4
    };

    int id;
    std::string name;
    double cgpa;

    std::tie(id, name, cgpa) = student;

    std::cout << id << '\n';
    std::cout << name << '\n';
    std::cout << cgpa << '\n';

    return 0;
}
```

---

# 86. Complete Program — `ignore`

```cpp
#include <iostream>
#include <string>
#include <tuple>

int main()
{
    std::tuple<int, std::string, double> student{
        101,
        "Deep",
        9.4
    };

    int id;
    double cgpa;

    std::tie(
        id,
        std::ignore,
        cgpa
    ) = student;

    std::cout << "ID: "
              << id
              << '\n';

    std::cout << "CGPA: "
              << cgpa
              << '\n';

    return 0;
}
```

Output:

```text
ID: 101
CGPA: 9.4
```

---

# 87. Complete Program — Multiple Return Values

```cpp
#include <iostream>
#include <tuple>

std::tuple<int, int, int> calculate()
{
    int sum = 30;
    int product = 200;
    int difference = 10;

    return {
        sum,
        product,
        difference
    };
}

int main()
{
    auto [sum, product, difference] = calculate();

    std::cout << "Sum: "
              << sum
              << '\n';

    std::cout << "Product: "
              << product
              << '\n';

    std::cout << "Difference: "
              << difference
              << '\n';

    return 0;
}
```

---

# 88. Complete Program — `tuple_cat()`

```cpp
#include <iostream>
#include <tuple>
#include <string>

int main()
{
    auto t1 = std::make_tuple(
        10,
        20
    );

    auto t2 = std::make_tuple(
        std::string("Deep"),
        9.4
    );

    auto result = std::tuple_cat(
        t1,
        t2
    );

    auto [a, b, name, cgpa] = result;

    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << name << '\n';
    std::cout << cgpa << '\n';

    return 0;
}
```

---

# 89. Complete Program — `apply()`

```cpp
#include <iostream>
#include <tuple>
#include <string>

void print(
    int id,
    const std::string& name,
    double cgpa
)
{
    std::cout
        << id << ' '
        << name << ' '
        << cgpa
        << '\n';
}

int main()
{
    auto student = std::make_tuple(
        101,
        std::string("Deep"),
        9.4
    );

    std::apply(
        print,
        student
    );

    return 0;
}
```

Output:

```text
101 Deep 9.4
```

---

# 90. Complete Program — Vector of Tuples

```cpp
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

int main()
{
    std::vector<
        std::tuple<int, std::string, double>
    > students;

    students.emplace_back(
        101,
        "Deep",
        9.4
    );

    students.emplace_back(
        102,
        "John",
        8.7
    );

    students.emplace_back(
        103,
        "Alex",
        9.1
    );

    for (const auto& [id, name, cgpa] : students)
    {
        std::cout
            << id << ' '
            << name << ' '
            << cgpa
            << '\n';
    }

    return 0;
}
```

Output:

```text
101 Deep 9.4
102 John 8.7
103 Alex 9.1
```

---

# 91. Complete Program — Tuple Comparison

```cpp
#include <iostream>
#include <tuple>

int main()
{
    std::tuple<int, int> a{
        1,
        2
    };

    std::tuple<int, int> b{
        1,
        3
    };

    if (a < b)
    {
        std::cout << "a is smaller";
    }
    else
    {
        std::cout << "a is not smaller";
    }

    return 0;
}
```

Output:

```text
a is smaller
```

---

# 92. Complete Program — Tuple Swap

```cpp
#include <iostream>
#include <string>
#include <tuple>
#include <utility>

int main()
{
    std::tuple<int, std::string> t1{
        1,
        "One"
    };

    std::tuple<int, std::string> t2{
        2,
        "Two"
    };

    std::swap(t1, t2);

    std::cout
        << std::get<0>(t1)
        << ' '
        << std::get<1>(t1)
        << '\n';

    std::cout
        << std::get<0>(t2)
        << ' '
        << std::get<1>(t2)
        << '\n';

    return 0;
}
```

Output:

```text
2 Two
1 One
```

---

# 93. Important C++ Version Reference

| Feature | C++ Version |
|---|---|
| `std::tuple` | C++11 |
| `get<I>()` | C++11 |
| `tuple_size` | C++11 |
| `tuple_element` | C++11 |
| `make_tuple()` | C++11 |
| `tie()` | C++11 |
| `ignore` | C++11 |
| `forward_as_tuple()` | C++11 |
| `tuple_cat()` | C++11 |
| `tuple` comparisons | C++11 |
| `get<T>()` | C++14 |
| `tuple_element_t` | C++14 |
| `tuple_size_v` | C++17 |
| Structured binding | C++17 |
| `std::apply()` | C++17 |
| `std::make_from_tuple()` | C++17 |
| Three-way comparison support | C++20 |

---

# 94. Most Important Tuple Functions

The most important functions/utilities to remember are:

```cpp
std::get<I>(t)
std::get<T>(t)

std::make_tuple(...)

std::tie(...)

std::ignore

std::forward_as_tuple(...)

std::tuple_cat(...)

std::swap(t1, t2)

std::apply(function, tuple)

std::make_from_tuple<T>(tuple)
```

And type traits:

```cpp
std::tuple_size<T>
std::tuple_size_v<T>

std::tuple_element<I, T>
std::tuple_element_t<I, T>
```

---

# 95. Final Mental Model

Think of:

```cpp
std::tuple<int, std::string, double> t{
    101,
    "Deep",
    9.4
};
```

as:

```text
                tuple
                  │
       ┌──────────┼──────────┐
       │          │          │
       ↓          ↓          ↓
     index 0    index 1    index 2
       │          │          │
      101       "Deep"      9.4
       │          │          │
      int       string     double
```

Access:

```cpp
std::get<0>(t);
std::get<1>(t);
std::get<2>(t);
```

Unpack:

```cpp
auto [id, name, cgpa] = t;
```

Number of elements:

```cpp
std::tuple_size_v<decltype(t)>
```

Type of an element:

```cpp
std::tuple_element_t<0, decltype(t)>
```

Create:

```cpp
auto t = std::make_tuple(...);
```

Unpack into existing variables:

```cpp
std::tie(a, b, c) = t;
```

Ignore:

```cpp
std::tie(a, std::ignore, c) = t;
```

Combine:

```cpp
std::tuple_cat(t1, t2);
```

Call a function using tuple elements:

```cpp
std::apply(function, t);
```

Construct an object from tuple elements:

```cpp
std::make_from_tuple<Type>(t);
```

Swap:

```cpp
std::swap(t1, t2);
```

---

# 96. Final Checklist

- [x] `std::tuple`
- [x] `<tuple>` header
- [x] `std` namespace
- [x] Variadic template
- [x] Fixed size
- [x] Heterogeneous values
- [x] Empty tuple
- [x] One-element tuple
- [x] Multi-element tuple
- [x] Default constructor
- [x] Value construction
- [x] Copy construction
- [x] Move construction
- [x] Copy assignment
- [x] Move assignment
- [x] `get<I>()`
- [x] `get<T>()`
- [x] Compile-time index
- [x] Unique-type access
- [x] Duplicate-type restriction
- [x] Modifying elements
- [x] `tuple_size`
- [x] `tuple_size_v`
- [x] `tuple_element`
- [x] `tuple_element_t`
- [x] `make_tuple()`
- [x] `tie()`
- [x] `ignore`
- [x] `forward_as_tuple()`
- [x] Lifetime warning for forwarding tuples
- [x] `tuple_cat()`
- [x] `swap()`
- [x] Lexicographical comparison
- [x] Structured binding
- [x] Returning multiple values
- [x] Passing tuples to functions
- [x] `std::apply()`
- [x] `std::make_from_tuple()`
- [x] Nested tuples
- [x] Tuple of containers
- [x] Vector of tuples
- [x] Tuple with `map`
- [x] Tuple with `set`
- [x] Tuple with `priority_queue`
- [x] Tuple with `unordered_map` and custom hashing
- [x] No `size()` member
- [x] No iterators
- [x] No `push_back()`
- [x] No `pop_back()`
- [x] Copy semantics
- [x] Move semantics
- [x] `const` tuples
- [x] Tuple references
- [x] Tuple vs pair
- [x] Tuple vs array
- [x] Tuple vs struct
- [x] Complexity
- [x] Advantages
- [x] Disadvantages
- [x] Real-world examples
- [x] Common mistakes
- [x] C++ version reference
- [x] Interview questions
- [x] Complete programs

---

# 97. One-Line Definition

> **`std::tuple` is a C++ Standard Library utility that stores a fixed number of heterogeneous values, with the number and types of its elements determined at compile time.**