# `std::pair` in C++ — Complete Notes

## 1. Introduction

`std::pair` is a class template in the C++ Standard Library that stores **exactly two values** together.

The two values can have **different data types**.

```cpp
#include <utility>
using namespace std;

pair<int, string> p;
```

Here:

```text
first  → int
second → string
```

Conceptually:

```cpp
template<class T1, class T2>
struct pair {
    T1 first;
    T2 second;
};
```

`std::pair` is defined in the `<utility>` header.

---

# 2. Header File

```cpp
#include <utility>
```

You can also use:

```cpp
#include <bits/stdc++.h>
```

in competitive programming.

---

# 3. Basic Syntax

```cpp
pair<T1, T2> variable;
```

Example:

```cpp
pair<int, string> p;
```

This pair contains:

```text
first  → int
second → string
```

---

# 4. Creating a Pair

## 4.1 Default Construction

```cpp
pair<int, string> p;
```

For fundamental types, the members are value-initialized:

```cpp
cout << p.first;
cout << p.second;
```

For `int`, the value is `0`.

For `string`, the value is an empty string.

---

## 4.2 Constructor with Values

```cpp
pair<int, string> p(10, "Deep");
```

Now:

```cpp
p.first  = 10
p.second = "Deep"
```

Example:

```cpp
cout << p.first << endl;
cout << p.second << endl;
```

Output:

```text
10
Deep
```

---

## 4.3 Brace Initialization

Modern C++ allows:

```cpp
pair<int, string> p{10, "Deep"};
```

This is commonly preferred.

---

## 4.4 `make_pair()`

C++ provides `std::make_pair()`.

```cpp
auto p = make_pair(10, "Deep");
```

The compiler automatically determines the types.

Conceptually:

```text
10       → int
"Deep"   → const char*
```

Another example:

```cpp
auto p = make_pair(10, string("Deep"));
```

Result:

```cpp
pair<int, string>
```

---

# 5. Accessing Pair Elements

A pair has two public data members:

```cpp
first
second
```

## `first`

```cpp
pair<int, string> p{10, "Deep"};

cout << p.first;
```

Output:

```text
10
```

## `second`

```cpp
cout << p.second;
```

Output:

```text
Deep
```

---

# 6. Modifying Pair Elements

Both members can be modified.

```cpp
pair<int, string> p{10, "Deep"};

p.first = 20;
p.second = "Mandal";
```

Now:

```text
first  = 20
second = Mandal
```

---

# 7. Pair with Same Types

Both types can be the same.

```cpp
pair<int, int> p{10, 20};
```

Example:

```cpp
cout << p.first << " " << p.second;
```

Output:

```text
10 20
```

---

# 8. Pair with Different Types

The main advantage of `pair` is that the two values can have different types.

```cpp
pair<int, string> p{101, "Deep"};
```

Other examples:

```cpp
pair<int, double> p1;
pair<string, int> p2;
pair<char, bool> p3;
pair<double, string> p4;
```

---

# 9. Pair of Pairs

A pair can contain another pair.

```cpp
pair<int, pair<int, int>> p;
```

Example:

```cpp
p.first = 10;
p.second.first = 20;
p.second.second = 30;
```

Structure:

```text
p
├── first
│   └── 10
│
└── second
    ├── first  → 20
    └── second → 30
```

---

# 10. Assignment

Pairs can be assigned to each other when their types are compatible.

```cpp
pair<int, string> p1{10, "Deep"};
pair<int, string> p2;

p2 = p1;
```

Now:

```text
p2.first  = 10
p2.second = Deep
```

---

# 11. Copy Assignment

```cpp
pair<int, string> p1{10, "Deep"};
pair<int, string> p2;

p2 = p1;
```

This copies both members.

Equivalent conceptually to:

```cpp
p2.first = p1.first;
p2.second = p1.second;
```

---

# 12. Move Assignment

Pairs also support move semantics.

```cpp
pair<int, string> p1{10, "Deep"};
pair<int, string> p2;

p2 = std::move(p1);
```

The contents are moved from `p1` to `p2`.

For objects such as `string`, move semantics can avoid unnecessary copying.

Required header:

```cpp
#include <utility>
```

---

# 13. Copy Construction

```cpp
pair<int, string> p1{10, "Deep"};

pair<int, string> p2(p1);
```

or:

```cpp
pair<int, string> p2 = p1;
```

---

# 14. Move Construction

```cpp
pair<int, string> p1{10, "Deep"};

pair<int, string> p2(std::move(p1));
```

or:

```cpp
pair<int, string> p2 = std::move(p1);
```

---

# 15. `std::make_pair()`

`make_pair()` creates a pair while allowing the compiler to deduce the types.

```cpp
auto p = make_pair(10, string("Deep"));
```

The resulting type is:

```cpp
pair<int, string>
```

Instead of:

```cpp
pair<int, string> p(10, "Deep");
```

you can write:

```cpp
auto p = make_pair(10, string("Deep"));
```

---

# 16. `swap()` — Member Function

A pair has a member `swap()` function.

```cpp
pair<int, string> p1{1, "one"};
pair<int, string> p2{2, "two"};

p1.swap(p2);
```

Before:

```text
p1 → (1, one)
p2 → (2, two)
```

After:

```text
p1 → (2, two)
p2 → (1, one)
```

Syntax:

```cpp
p1.swap(p2);
```

---

# 17. `swap()` — Non-Member Function

There is also a non-member `std::swap()`.

```cpp
swap(p1, p2);
```

Example:

```cpp
pair<int, string> p1{1, "one"};
pair<int, string> p2{2, "two"};

swap(p1, p2);
```

Both forms exchange the contents:

```cpp
p1.swap(p2);
```

and:

```cpp
swap(p1, p2);
```

---

# 18. Comparison Operators

Pairs support relational comparisons.

For example:

```cpp
p1 == p2
p1 != p2
p1 < p2
p1 <= p2
p1 > p2
p1 >= p2
```

The comparison is performed **lexicographically**.

---

# 19. Lexicographical Comparison

Suppose:

```cpp
pair<int, int> p1{1, 5};
pair<int, int> p2{2, 3};
```

Compare:

```text
p1.first = 1
p2.first = 2
```

Since:

```text
1 < 2
```

we have:

```cpp
p1 < p2
```

The second elements do not need to determine the result.

---

# 20. If First Elements Are Equal

Consider:

```cpp
pair<int, int> p1{1, 5};
pair<int, int> p2{1, 8};
```

First elements:

```text
1 == 1
```

Therefore C++ compares the second elements:

```text
5 < 8
```

So:

```cpp
p1 < p2
```

is `true`.

---

# 21. Comparison Algorithm

Conceptually:

```cpp
if (p1.first < p2.first)
    p1 < p2;

else if (p1.first == p2.first)
    compare p1.second and p2.second;
```

Therefore:

```text
first → primary comparison
second → secondary comparison
```

This is extremely useful in sorting.

---

# 22. Sorting a `vector<pair<...>>`

Example:

```cpp
vector<pair<int, int>> v = {
    {3, 10},
    {1, 20},
    {2, 15},
    {1, 5}
};

sort(v.begin(), v.end());
```

Result:

```text
(1, 5)
(1, 20)
(2, 15)
(3, 10)
```

Because pairs are sorted lexicographically.

First:

```text
first
```

then:

```text
second
```

---

# 23. Structured Binding

C++17 introduced structured bindings.

```cpp
pair<int, string> p{10, "Deep"};

auto [x, y] = p;
```

Now:

```text
x = 10
y = "Deep"
```

Example:

```cpp
cout << x << " " << y;
```

Output:

```text
10 Deep
```

---

# 24. Structured Binding by Reference

You can bind references:

```cpp
auto& [x, y] = p;
```

Now `x` refers to `p.first` and `y` refers to `p.second`.

Therefore:

```cpp
x = 100;
y = "Mandal";
```

changes:

```cpp
p.first
p.second
```

as well.

---

# 25. Structured Binding with `const`

```cpp
const auto& [x, y] = p;
```

This allows read-only access without copying the pair.

This is commonly useful when iterating.

Example:

```cpp
for (const auto& [key, value] : data) {
    cout << key << " " << value << endl;
}
```

---

# 26. Tuple Interface

`std::pair` also provides a tuple-like interface.

You can use:

```cpp
get<>
```

with a pair.

---

# 27. `get<0>()`

```cpp
pair<int, string> p{10, "Deep"};

cout << get<0>(p);
```

Output:

```text
10
```

`get<0>()` accesses:

```cpp
p.first
```

---

# 28. `get<1>()`

```cpp
cout << get<1>(p);
```

Output:

```text
Deep
```

`get<1>()` accesses:

```cpp
p.second
```

---

# 29. `get<>` vs `first` / `second`

These are equivalent for a pair:

```cpp
p.first
```

and:

```cpp
get<0>(p)
```

Similarly:

```cpp
p.second
```

and:

```cpp
get<1>(p)
```

---

# 30. `tuple_size`

Because `pair` has a tuple interface, `tuple_size` can be used.

```cpp
cout << tuple_size<pair<int, int>>::value;
```

Output:

```text
2
```

A pair always contains exactly:

```text
2 elements
```

---

# 31. `tuple_element`

`tuple_element` can determine the type of a particular pair element.

Example:

```cpp
tuple_element<0, pair<int, string>>::type x;
```

The type of `x` is:

```cpp
int
```

For the second element:

```cpp
tuple_element<1, pair<int, string>>::type y;
```

The type of `y` is:

```cpp
string
```

---

# 32. `std::tie()`

`std::tie()` can unpack a pair into existing variables.

```cpp
int a, b;

pair<int, int> p{10, 20};

tie(a, b) = p;
```

Now:

```text
a = 10
b = 20
```

---

# 33. `tie()` Example

```cpp
int age;
string name;

pair<int, string> p{25, "Deep"};

tie(age, name) = p;
```

Now:

```text
age  = 25
name = Deep
```

---

# 34. `tie()` with Ignored Values

You can use `std::ignore` when you do not need one element.

```cpp
int age;

pair<int, string> p{25, "Deep"};

tie(age, ignore) = p;
```

Now:

```text
age = 25
```

The string is ignored.

---

# 35. Pair in `unordered_map`

A common misconception is:

```cpp
unordered_map<pair<int, int>, int> mp;
```

This does **not generally work directly with the standard library's default hash support**, because a standard `std::hash<pair<...>>` specialization is not provided.

You normally need a custom hash.

Example:

```cpp
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>{}(p.first) ^
               (hash<int>{}(p.second) << 1);
    }
};
```

Then:

```cpp
unordered_map<pair<int, int>, int, PairHash> mp;
```

Now a pair can be used as the key.

---

# 36. Pair as a Key in `map`

Unlike `unordered_map`, `std::map` can directly use a pair as a key.

```cpp
map<pair<int, int>, string> mp;
```

Example:

```cpp
mp[{1, 2}] = "A";
mp[{2, 3}] = "B";
```

This works because `map` uses ordering, and pairs provide lexicographical comparison.

---

# 37. Pair in Competitive Programming

`pair` is heavily used in competitive programming.

Common examples:

```cpp
vector<pair<int, int>>
map<pair<int, int>, int>
set<pair<int, int>>
priority_queue<pair<int, int>>
```

---

# 38. Pair with `vector`

```cpp
vector<pair<int, int>> v;

v.push_back({10, 20});
v.push_back({30, 40});
```

Access:

```cpp
cout << v[0].first;
cout << v[0].second;
```

---

# 39. Pair with `set`

```cpp
set<pair<int, int>> s;

s.insert({1, 10});
s.insert({2, 20});
s.insert({1, 5});
```

The pairs are automatically ordered lexicographically.

Order:

```text
(1, 5)
(1, 10)
(2, 20)
```

---

# 40. Pair with `priority_queue`

Example:

```cpp
priority_queue<pair<int, int>> pq;

pq.push({10, 1});
pq.push({20, 2});
pq.push({15, 3});
```

By default, the largest pair has the highest priority.

Because pair comparison is lexicographical:

```text
first → priority
second → tie-breaker
```

---

# 41. Pair in Function Return Values

A function can return two values using a pair.

```cpp
pair<int, int> getValues() {
    return {10, 20};
}
```

Usage:

```cpp
auto p = getValues();

cout << p.first << " " << p.second;
```

---

# 42. Pair with Structured Binding from Function

```cpp
pair<int, int> getValues() {
    return {10, 20};
}

int main() {
    auto [x, y] = getValues();

    cout << x << " " << y;
}
```

Output:

```text
10 20
```

This is a clean way to return two values from a function.

---

# 43. Pair of Different Objects

A pair can contain almost any suitable types.

```cpp
pair<int, vector<int>> p;
```

or:

```cpp
pair<string, vector<int>> p;
```

or:

```cpp
pair<int, pair<string, double>> p;
```

The contained types determine what operations are available.

---

# 44. Pair with References

A pair can be constructed using reference-related types, although for ordinary reference binding, `std::reference_wrapper` or `std::tie` is often more appropriate.

Example:

```cpp
int a = 10;
int b = 20;

auto p = tie(a, b);
```

Here `p` is effectively a tuple of references.

---

# 45. `pair` and `const`

A pair can be declared `const`.

```cpp
const pair<int, string> p{10, "Deep"};
```

You can read:

```cpp
cout << p.first;
cout << p.second;
```

But you cannot modify:

```cpp
p.first = 20;   // ERROR
```

---

# 46. Nested Pair Example

```cpp
pair<int, pair<int, int>> p{
    10,
    {20, 30}
};
```

Access:

```cpp
cout << p.first << endl;
cout << p.second.first << endl;
cout << p.second.second << endl;
```

Output:

```text
10
20
30
```

---

# 47. Pair of Strings

```cpp
pair<string, string> p{
    "Hello",
    "World"
};
```

Access:

```cpp
cout << p.first << " " << p.second;
```

Output:

```text
Hello World
```

---

# 48. Pair of Pointers

Pairs can also contain pointers.

```cpp
int a = 10;
int b = 20;

pair<int*, int*> p{&a, &b};
```

Access:

```cpp
cout << *p.first << endl;
cout << *p.second << endl;
```

Output:

```text
10
20
```

---

# 49. Pair Does Not Have `size()`

A pair does not provide:

```cpp
p.size();
```

There is no `size()` member function.

Instead, its size is always known to be:

```text
2
```

You can use:

```cpp
tuple_size<pair<int, int>>::value
```

which returns:

```text
2
```

---

# 50. Pair Does Not Have Iterators

A pair is not a container.

Therefore it does not have:

```cpp
begin()
end()
```

and you cannot normally write:

```cpp
for (auto x : p)
```

A pair simply stores two values.

---

# 51. Pair Does Not Have `push_back()` or `pop_back()`

These do not exist:

```cpp
p.push_back(...);   // ERROR
p.pop_back();       // ERROR
```

Those operations belong to containers such as:

```cpp
vector
deque
list
```

---

# 52. Pair Does Not Have Container Member Algorithms

There is no:

```cpp
p.sort();
p.find();
p.erase();
p.clear();
```

A pair is not a general-purpose container.

---

# 53. Pair vs Tuple

Both can store multiple values, but their purposes differ.

### `pair`

Stores exactly two values:

```cpp
pair<int, string> p;
```

### `tuple`

Can store any fixed number of values:

```cpp
tuple<int, string, double> t;
```

Use `pair` when there are exactly two logically related values.

Use `tuple` when there are more than two values.

---

# 54. Pair vs Struct

A pair:

```cpp
pair<int, string> employee;
```

uses generic names:

```cpp
employee.first
employee.second
```

A struct can use meaningful names:

```cpp
struct Employee {
    int id;
    string name;
};
```

Then:

```cpp
Employee e;

e.id;
e.name;
```

For simple temporary relationships, `pair` is convenient.

For domain-specific data, a named `struct` is often clearer.

---

# 55. Complete Example

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

    pair<int, string> p1(1, "one");

    pair<int, string> p2 = make_pair(2, "two");

    // Access
    cout << p1.first << " " << p1.second << endl;

    // Modify
    p1.first = 10;
    p1.second = "TEN";

    cout << p1.first << " " << p1.second << endl;

    // Swap
    p1.swap(p2);

    cout << p1.first << " " << p1.second << endl;

    // Structured binding
    auto [x, y] = p1;

    cout << x << " " << y << endl;

    // Comparison
    cout << (p1 < p2) << endl;

    // Tuple interface
    cout << get<0>(p1) << " ";
    cout << get<1>(p1) << endl;

    // tuple_size
    cout << tuple_size<pair<int, string>>::value << endl;

    return 0;
}
```

---

# 56. Complete `std::pair` Feature List

## Construction

```cpp
pair<int, string> p;
pair<int, string> p(10, "Deep");
pair<int, string> p{10, "Deep"};
auto p = make_pair(10, string("Deep"));
```

## Access

```cpp
p.first
p.second

get<0>(p)
get<1>(p)
```

## Assignment

```cpp
p2 = p1;
p2 = std::move(p1);
```

## Swap

```cpp
p1.swap(p2);
swap(p1, p2);
```

## Comparison

```cpp
p1 == p2
p1 != p2
p1 < p2
p1 <= p2
p1 > p2
p1 >= p2
```

## Structured Binding

```cpp
auto [x, y] = p;
auto& [x, y] = p;
const auto& [x, y] = p;
```

## Tuple Interface

```cpp
get<0>(p)
get<1>(p)

tuple_size<pair<int, int>>::value

tuple_element<0, pair<int, int>>::type
tuple_element<1, pair<int, int>>::type
```

## `tie`

```cpp
tie(a, b) = p;
tie(a, ignore) = p;
```

## Move Semantics

```cpp
pair<int, string> p2 = std::move(p1);
p2 = std::move(p1);
```

---

# 57. Important Headers

For `std::pair`:

```cpp
#include <utility>
```

For `std::tie`:

```cpp
#include <tuple>
```

For tuple-related utilities:

```cpp
#include <tuple>
```

For `std::move`:

```cpp
#include <utility>
```

For containers:

```cpp
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
```

---

# 58. Important Notes About `unordered_map`

This:

```cpp
unordered_map<pair<int, int>, int> mp;
```

does not have a portable standard-library default hash for `std::pair`.

Use a custom hash:

```cpp
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>{}(p.first) ^
               (hash<int>{}(p.second) << 1);
    }
};

unordered_map<pair<int, int>, int, PairHash> mp;
```

But this works directly:

```cpp
map<pair<int, int>, int> mp;
```

because `map` uses ordering rather than hashing.

---

# 59. Most Important Interview Point

Remember:

```cpp
pair<T1, T2>
```

contains exactly two public members:

```cpp
T1 first;
T2 second;
```

The simplest mental model is:

```text
std::pair
   │
   ├── first
   └── second
```

It is a lightweight object for grouping two related values.

---

# 60. What `std::pair` Does NOT Have

`std::pair` does **not** have:

```cpp
size()
begin()
end()
push_back()
pop_back()
clear()
erase()
find()
sort()
```

because `std::pair` is **not a container**.

It stores exactly two values.

---

# 61. Final Mental Model

```cpp
pair<int, string> p{100, "Deep"};
```

Think:

```text
             std::pair
          ┌───────────────┐
          │ first         │
          │     100       │
          ├───────────────┤
          │ second        │
          │     "Deep"    │
          └───────────────┘
```

Access:

```cpp
p.first
p.second
```

or:

```cpp
get<0>(p)
get<1>(p)
```

Unpack:

```cpp
auto [x, y] = p;
```

Swap:

```cpp
p1.swap(p2);
```

Compare:

```cpp
p1 < p2
```

The comparison is:

```text
first first
   ↓
if equal
   ↓
second second
```

Use with ordered containers:

```cpp
map<pair<int, int>, int>
set<pair<int, int>>
```

For `unordered_map`, provide a suitable hash:

```cpp
unordered_map<pair<int, int>, int, PairHash>
```

---

# 62. Final Checklist

- [x] `std::pair`
- [x] `<utility>` header
- [x] `first`
- [x] `second`
- [x] Default construction
- [x] Value construction
- [x] Brace initialization
- [x] `make_pair()`
- [x] Copy construction
- [x] Move construction
- [x] Copy assignment
- [x] Move assignment
- [x] Member `swap()`
- [x] Non-member `swap()`
- [x] `==`
- [x] `!=`
- [x] `<`
- [x] `<=`
- [x] `>`
- [x] `>=`
- [x] Lexicographical comparison
- [x] Structured binding
- [x] `get<0>()`
- [x] `get<1>()`
- [x] `tuple_size`
- [x] `tuple_element`
- [x] `std::tie()`
- [x] `std::ignore`
- [x] Move semantics
- [x] Pair of pairs
- [x] Pair with vectors
- [x] Pair with maps
- [x] Pair with sets
- [x] Pair with priority queues
- [x] Pair as function return value
- [x] Pair as `map` key
- [x] Custom hash for `unordered_map`
- [x] No `size()`
- [x] No iterators
- [x] No `push_back()`
- [x] No `pop_back()`
- [x] No container member algorithms
- [x] Pair vs tuple
- [x] Pair vs struct
- [x] Complete example

## One-Line Definition

> **`std::pair<T1, T2>` is a standard-library utility that stores exactly two values, possibly of different types, accessible through `first` and `second`.**