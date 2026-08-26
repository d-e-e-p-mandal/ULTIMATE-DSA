# `std::multiset` in C++ STL

## Table of Contents

1. Introduction
2. Real-World Use Cases
3. Header File
4. Namespace
5. Basic Syntax
6. Template Parameters
7. What Exactly Does `std::multiset` Store?
8. Ordered Associative Container
9. Internal Working
10. Red-Black Tree Concept
11. How Duplicate Values Work
12. Characteristics
13. Memory Structure
14. Time Complexity
15. Iterator Invalidation
16. Constructors
17. Assignment Operators
18. Iterators
19. Capacity Functions
20. Element Access
21. Modifiers
22. `insert()`
23. `emplace()`
24. `erase()`
25. `clear()`
26. `swap()`
27. `extract()` — C++17
28. `merge()` — C++17
29. Lookup Functions
30. `find()`
31. `count()`
32. `contains()` — C++20
33. `lower_bound()`
34. `upper_bound()`
35. `equal_range()`
36. Observers
37. `key_comp()`
38. `value_comp()`
39. Custom Comparator
40. Descending Order
41. Custom Comparator Class
42. Custom Objects
43. `std::pair` with `multiset`
44. Move Semantics
45. Why Multiset Elements Cannot Be Modified
46. Changing an Element
47. Iterator and Reference Rules
48. `multiset` vs `set`
49. `multiset` vs `unordered_multiset`
50. `multiset` vs `vector`
51. `multiset` vs `vector + sort`
52. Common Mistakes
53. Practical Examples
54. Interview Questions
55. Important C++ Version Features
56. Quick Reference Table
57. Advantages
58. Disadvantages
59. Decision Guide
60. Summary

---

# 1. Introduction

`std::multiset` is an **ordered associative container** provided by the C++ Standard Template Library (STL).

It stores:

- Multiple elements
- In sorted order
- According to a comparison object

Unlike `std::set`, a `multiset` **allows duplicate equivalent elements**.

Example:

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {

    multiset<int> numbers;

    numbers.insert(30);
    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(10);

    for (int x : numbers) {
        cout << x << " ";
    }

    return 0;
}
```

**Output:**

```text
10 10 20 30
```

The second `10` is stored because `std::multiset` allows duplicate values.

---

# 2. Real-World Use Cases

`std::multiset` is useful when you need:

## 2.1 Duplicate values

Example:

```text
10
10
20
20
20
30
```

Duplicates are allowed.

---

## 2.2 Automatically sorted values

If values are inserted in this order:

```text
50
10
30
10
20
```

the multiset maintains:

```text
10
10
20
30
50
```

---

## 2.3 Counting occurrences

A multiset is useful when you need to know how many times a value occurs.

```cpp
multiset<int> scores = {
    10,
    20,
    10,
    30,
    10
};

cout << scores.count(10);
```

Output:

```text
3
```

---

## 2.4 Maintaining sorted duplicate values dynamically

A `vector` can store duplicates, but it does not automatically maintain sorted order.

A `multiset` maintains sorted order while elements are inserted and erased.

---

## 2.5 Ordered range queries

Functions such as:

```cpp
lower_bound()
upper_bound()
equal_range()
```

are useful for finding ranges of duplicate values.

---

## 2.6 Maintaining ordered rankings with duplicates

Example:

```text
100
100
95
95
90
85
```

If multiple users have the same score, a multiset can maintain all scores in sorted order.

---

# 3. Header File

Use:

```cpp
#include <set>
```

Example:

```cpp
#include <iostream>
#include <set>
```

Both `std::set` and `std::multiset` are provided by the `<set>` header.

---

# 4. Namespace

You can write:

```cpp
using namespace std;

multiset<int> numbers;
```

Or explicitly:

```cpp
std::multiset<int> numbers;
```

Using `std::` explicitly is often preferable in larger projects and header files because it avoids namespace pollution.

---

# 5. Basic Syntax

Basic syntax:

```cpp
multiset<data_type> name;
```

Examples:

```cpp
multiset<int> numbers;
multiset<string> names;
multiset<char> letters;
multiset<double> prices;
```

---

## Custom ordering

You can provide a comparator:

```cpp
multiset<int, greater<int>> numbers;
```

This stores values in descending order.

---

# 6. Template Parameters

The simplified declaration is:

```cpp
template<
    class Key,
    class Compare = less<Key>,
    class Allocator = allocator<Key>
>
class multiset;
```

### Parameters

| Parameter | Meaning |
|---|---|
| `Key` | Type of elements stored |
| `Compare` | Determines element ordering |
| `Allocator` | Controls memory allocation |

Example:

```cpp
multiset<int>
```

Conceptually means:

```text
Key       = int
Compare   = less<int>
Allocator = allocator<int>
```

Therefore the default ordering is ascending:

```text
1 2 3 4 5
```

---

# 7. What Exactly Does `std::multiset` Store?

A `multiset` stores **values**, not key-value pairs.

Example:

```cpp
multiset<int> s;
```

contains:

```text
10
10
20
30
30
```

There is no separate:

```text
key -> value
```

relationship.

### Compare

`multiset`:

```cpp
multiset<int> s;
```

```text
10
10
20
30
```

`map`:

```cpp
map<int, string> m;
```

```text
10 -> Ten
20 -> Twenty
30 -> Thirty
```

The fundamental difference is that a multiset stores values directly, while a map stores key-value pairs.

---

# 8. Ordered Associative Container

`std::multiset` is an **ordered associative container**.

This means:

```text
Associative
    ↓
Elements are organized for efficient lookup

Ordered
    ↓
Elements are maintained according to a comparator
```

By default:

```cpp
std::less<Key>
```

is used.

Therefore:

```cpp
multiset<int> s = {
    30,
    10,
    20,
    10
};
```

iterates as:

```text
10 10 20 30
```

The order is not insertion order.

---

# 9. Internal Working

A `multiset` requires an ordering relation between elements.

It is typically implemented using a **self-balancing binary search tree**, commonly a **Red-Black Tree**.

Conceptually:

```text
              20
            /    \
          10      40
         /  \    /  \
        5   10  30   60
```

The exact internal tree representation is implementation-dependent.

The C++ standard specifies the required behavior and complexity, but it does not require every implementation to use a Red-Black Tree.

A Red-Black Tree is a common implementation choice.

---

# 10. Red-Black Tree Concept

A Red-Black Tree is a self-balancing binary search tree.

A node may conceptually contain:

```text
-------------------------
Element
Left link
Right link
Parent link
Color information
-------------------------
```

The balancing rules prevent the tree from becoming excessively tall.

Therefore operations such as:

```text
Search
Insert
Erase
```

can generally remain:

```text
O(log n)
```

where `n` is the number of elements.

---

# 11. How Duplicate Values Work

This is one of the most important differences between `set` and `multiset`.

For two values `a` and `b`, the comparator considers them equivalent when:

```cpp
!comp(a, b) && !comp(b, a)
```

In a `set`, equivalent values cannot both be stored.

In a `multiset`, equivalent values **can both be stored**.

Example:

```cpp
multiset<int> s;

s.insert(10);
s.insert(10);
s.insert(10);
```

The result is:

```text
10 10 10
```

---

## Important Interview Point

For an ordered associative container, equivalence is determined by the comparator, not necessarily by `operator==`.

This matters especially when storing custom objects.

---

# 12. Characteristics

`std::multiset` has these major characteristics:

- Stores multiple equivalent elements.
- Maintains sorted order.
- Uses a comparison object to define ordering.
- Supports custom comparators.
- Usually implemented with a self-balancing tree.
- Search is O(log n).
- Insertion is O(log n).
- Deletion by key is O(log n + number of erased elements).
- Does not support random indexing.
- Does not provide `operator[]`.
- Provides bidirectional iterators.
- Elements are effectively immutable through normal iterators.
- Supports ordered lookup operations.
- Supports node extraction since C++17.
- Supports `merge()` since C++17.
- Supports `contains()` since C++20.
- Supports duplicate values.

---

# 13. Memory Structure

Suppose:

```cpp
multiset<int> s;

s.insert(20);
s.insert(10);
s.insert(20);
s.insert(40);
```

Conceptually, the tree contains separate nodes for the equivalent `20` values.

For example:

```text
             20
            /  \
          10    20
                  \
                   40
```

The exact tree shape is implementation-dependent.

A tree node generally needs information such as:

```text
-------------------------
Element
Left link
Right link
Parent link
Balancing information
-------------------------
```

Each stored occurrence generally has its own node.

Therefore, compared with a contiguous container such as:

```cpp
vector<int>
```

a multiset generally has higher memory overhead.

---

# 14. Time Complexity

Let:

```text
n = number of elements in the multiset
```

| Operation | Complexity |
|---|---:|
| `insert()` | O(log n) |
| `emplace()` | O(log n) |
| `erase(key)` | O(log n + k) |
| `erase(iterator)` | Amortized constant for the erase operation itself, with tree rebalancing as required |
| `find()` | O(log n) |
| `count()` | O(log n + k) |
| `contains()` | O(log n) |
| `lower_bound()` | O(log n) |
| `upper_bound()` | O(log n) |
| `equal_range()` | O(log n) |
| `clear()` | O(n) |
| `size()` | O(1) |
| `empty()` | O(1) |
| `begin()` | O(1) |
| `end()` | O(1) |

Here:

```text
k = number of elements matching the key
```

For `count()` and `erase(key)`, the `k` term matters because a multiset can contain many equivalent elements.

### Important

Remember:

```text
find()        -> O(log n)
insert()      -> O(log n)
contains()    -> O(log n)
lower_bound() -> O(log n)
upper_bound() -> O(log n)
```

For:

```cpp
count(key)
erase(key)
```

the operation may need to process all matching occurrences.

---

# 15. Iterator Invalidation

A major advantage of node-based associative containers is iterator stability.

In general, inserting elements into a `multiset` does not invalidate existing iterators or references.

Example:

```cpp
auto it = s.find(20);

s.insert(50);

// it remains valid if 20 was not erased
```

Erasing an element invalidates iterators and references to the erased element.

Example:

```cpp
auto it = s.find(20);

s.erase(it);

// it is now invalid
```

Do not use an iterator after erasing the element it referred to.

---

# 16. Constructors

## 16.1 Default Constructor

```cpp
multiset<int> s;
```

Creates an empty multiset.

---

## 16.2 Initializer List

```cpp
multiset<int> s = {
    5,
    2,
    8,
    2,
    1
};
```

Result:

```text
1 2 2 5 8
```

Duplicates are retained.

---

## 16.3 Range Constructor

```cpp
vector<int> v = {
    10,
    20,
    10,
    30
};

multiset<int> s(v.begin(), v.end());
```

Result:

```text
10 10 20 30
```

---

## 16.4 Copy Constructor

```cpp
multiset<int> s1 = {
    1,
    2,
    2,
    3
};

multiset<int> s2(s1);
```

`s2` becomes a copy of `s1`.

---

## 16.5 Move Constructor

```cpp
multiset<int> s1 = {
    1,
    2,
    3
};

multiset<int> s2(std::move(s1));
```

Resources can be transferred from `s1` to `s2`.

After the move:

```text
s1 -> valid but unspecified state
s2 -> contains transferred contents
```

---

# 17. Assignment Operators

## 17.1 Copy Assignment

```cpp
multiset<int> s1 = {
    1,
    2,
    3
};

multiset<int> s2;

s2 = s1;
```

---

## 17.2 Move Assignment

```cpp
s2 = std::move(s1);
```

Resources can be transferred.

After the move:

```text
s1 -> valid but unspecified state
s2 -> transferred contents
```

---

## 17.3 Initializer List Assignment

```cpp
s = {
    10,
    20,
    20,
    30
};
```

This replaces the existing contents.

---

# 18. Iterators

A `multiset` provides **bidirectional iterators**.

---

## 18.1 `begin()`

```cpp
auto it = s.begin();
```

Points to the first element according to the comparator's ordering.

---

## 18.2 `end()`

```cpp
auto it = s.end();
```

Represents one position past the last element.

It must not be dereferenced.

---

## 18.3 Forward Traversal

```cpp
for (auto it = s.begin(); it != s.end(); ++it) {
    cout << *it << " ";
}
```

---

## 18.4 Range-Based Loop

Usually the simplest approach:

```cpp
for (int x : s) {
    cout << x << " ";
}
```

---

## 18.5 `rbegin()`

Returns a reverse iterator.

```cpp
for (auto it = s.rbegin(); it != s.rend(); ++it) {
    cout << *it << " ";
}
```

This visits elements in reverse comparator order.

For the default ascending comparator:

```text
40 30 20 20 10
```

---

## 18.6 `rend()`

Represents the position before the first element during reverse traversal.

---

## 18.7 `cbegin()`

Returns a constant iterator.

```cpp
auto it = s.cbegin();
```

---

## 18.8 `cend()`

Returns the constant end iterator.

---

## 18.9 `crbegin()` and `crend()`

These provide constant reverse iterators.

```cpp
auto it = s.crbegin();
```

and:

```cpp
auto it = s.crend();
```

---

# 19. Capacity Functions

## 19.1 `empty()`

```cpp
if (s.empty()) {
    cout << "Multiset is empty";
}
```

Returns:

```text
true
false
```

---

## 19.2 `size()`

```cpp
cout << s.size();
```

Example:

```cpp
multiset<int> s = {
    10,
    20,
    20,
    30
};

cout << s.size();
```

Output:

```text
4
```

Important:

`size()` counts **all occurrences**, including duplicates.

---

## 19.3 `max_size()`

```cpp
cout << s.max_size();
```

Returns the maximum number of elements the container can theoretically hold, subject to implementation and system limitations.

---

# 20. Element Access

Unlike `vector`, `multiset` does not provide:

```cpp
operator[]
```

or:

```cpp
at()
```

This is because a multiset is not designed for positional access.

Example:

```cpp
multiset<int> s = {
    10,
    20,
    20,
    30
};

cout << *s.begin();
```

Output:

```text
10
```

To access elements, use iterators.

---

# 21. Modifiers

Important modifier functions include:

```cpp
insert()
emplace()
erase()
clear()
swap()
extract()
merge()
```

Unlike `set`, `multiset` allows multiple equivalent elements to be inserted.

---

# 22. `insert()`

Inserts an element.

```cpp
multiset<int> s;

s.insert(30);
s.insert(10);
s.insert(20);
s.insert(10);
```

Result:

```text
10 10 20 30
```

---

## 22.1 Return Value

For a single-element insertion into a `multiset`, the return value is an iterator to the inserted element.

Example:

```cpp
auto it = s.insert(20);

cout << *it;
```

Possible output:

```text
20
```

Unlike `set`, insertion does not return a pair containing a success boolean because insertion of an equivalent element is allowed.

---

## 22.2 Duplicate Insertion

```cpp
multiset<int> s;

s.insert(10);
s.insert(10);
s.insert(10);
```

Result:

```text
10 10 10
```

---

## 22.3 Insert with Hint

```cpp
auto hint = s.begin();

s.insert(hint, 25);
```

A correct hint can potentially improve insertion efficiency.

The hint does not force the value into an arbitrary position.

---

## 22.4 Range Insert

```cpp
vector<int> values = {
    10,
    20,
    20,
    30
};

s.insert(values.begin(), values.end());
```

All values, including duplicates, can be inserted.

---

# 23. `emplace()`

`emplace()` constructs an element in place.

For simple values:

```cpp
s.emplace(40);
```

For custom objects, it can construct the object directly in the tree node.

Example:

```cpp
multiset<string> names;

names.emplace("Amit");
names.emplace("Rahul");
names.emplace("Amit");
```

Result:

```text
Amit Amit Rahul
```

---

# 24. `erase()`

There are several ways to erase elements.

---

## 24.1 Erase by Value

```cpp
s.erase(20);
```

Important difference from `set`:

If:

```text
20
20
20
```

exists, then:

```cpp
s.erase(20);
```

removes **all elements equivalent to `20`**.

The return value is the number of elements erased.

Example:

```cpp
multiset<int> s = {
    10,
    20,
    20,
    20,
    30
};

size_t removed = s.erase(20);

cout << removed;
```

Output:

```text
3
```

Afterward:

```text
10 30
```

---

## 24.2 Erase One Occurrence by Iterator

If you want to remove only one `20`:

```cpp
auto it = s.find(20);

if (it != s.end()) {
    s.erase(it);
}
```

Only the element referred to by `it` is erased.

---

## 24.3 Erase Range

```cpp
s.erase(s.begin(), s.find(30));
```

This removes elements from:

```text
begin()
```

up to but excluding:

```text
find(30)
```

---

# 25. `clear()`

Removes all elements.

```cpp
s.clear();
```

After:

```cpp
s.clear();
```

the multiset is empty.

All occurrences are removed.

---

# 26. `swap()`

Swaps the contents of two multisets.

```cpp
multiset<int> s1 = {
    1,
    2,
    2,
    3
};

multiset<int> s2 = {
    10,
    20,
    20
};

s1.swap(s2);
```

After:

```text
s1 -> 10 20 20
s2 -> 1 2 2 3
```

---

# 27. `extract()` — C++17

`extract()` removes a node from the multiset and returns a node handle.

Example:

```cpp
multiset<int> s = {
    10,
    20,
    20,
    30
};

auto node = s.extract(s.find(20));
```

Only the particular node referred to by the iterator is extracted.

The multiset can now contain:

```text
10 20 30
```

The extracted occurrence is held by:

```cpp
node
```

A node handle can be inserted into another compatible associative container.

---

## Extract by key

```cpp
auto node = s.extract(20);
```

This extracts one matching node if one exists.

If multiple `20` values exist, only one node is extracted by a key-based `extract()` call.

---

# 28. `merge()` — C++17

`merge()` transfers elements from one compatible associative container to another.

Example:

```cpp
multiset<int> a = {
    1,
    2,
    3
};

multiset<int> b = {
    2,
    4,
    5
};

a.merge(b);
```

Result:

```text
a:
1 2 2 3 4 5

b:
empty
```

Why can both `2` values exist in `a`?

Because `multiset` permits duplicates.

This differs from:

```cpp
set
```

where an equivalent value already present in the destination cannot be transferred as a duplicate.

---

## Merge between `set` and `multiset`

Compatible associative containers can also transfer nodes between `set` and `multiset`, subject to compatible key, comparator, and allocator requirements.

Example conceptually:

```cpp
set<int> source = {
    1,
    2,
    3
};

multiset<int> destination = {
    2,
    4
};

destination.merge(source);
```

The destination can accept all transferred values because duplicates are allowed.

---

# 29. Lookup Functions

Important lookup functions:

```cpp
find()
count()
contains()
lower_bound()
upper_bound()
equal_range()
```

These are especially useful with duplicates.

---

# 30. `find()`

Searches for an element.

```cpp
auto it = s.find(20);
```

If found:

```cpp
it != s.end()
```

If not found:

```cpp
it == s.end()
```

Example:

```cpp
multiset<int> s = {
    10,
    20,
    20,
    30
};

auto it = s.find(20);

if (it != s.end()) {
    cout << "Found: " << *it;
}
```

Output:

```text
Found: 20
```

If duplicates exist, `find()` returns an iterator to one matching occurrence.

---

# 31. `count()`

This is particularly important for `multiset`.

```cpp
s.count(20);
```

returns the number of elements equivalent to `20`.

Example:

```cpp
multiset<int> s = {
    10,
    20,
    20,
    20,
    30
};

cout << s.count(20);
```

Output:

```text
3
```

Unlike `set`, `count()` can return:

```text
0
1
2
3
...
```

---

# 32. `contains()` — C++20

C++20 provides:

```cpp
s.contains(20)
```

Example:

```cpp
if (s.contains(20)) {
    cout << "20 exists";
}
```

Returns:

```text
true
false
```

`contains()` only answers whether at least one equivalent value exists.

It does not tell you how many occurrences exist.

For the number of occurrences, use:

```cpp
s.count(20);
```

---

# 33. `lower_bound()`

Returns an iterator to the first element that is:

```text
>= target
```

Example:

```cpp
multiset<int> s = {
    10,
    20,
    20,
    30,
    40
};

auto it = s.lower_bound(20);

if (it != s.end()) {
    cout << *it;
}
```

Output:

```text
20
```

For:

```cpp
auto it = s.lower_bound(25);
```

the result is:

```text
30
```

because `30` is the first element satisfying:

```text
element >= 25
```

---

# 34. `upper_bound()`

Returns the first element that is:

```text
> target
```

Example:

```cpp
multiset<int> s = {
    10,
    20,
    20,
    30,
    40
};

auto it = s.upper_bound(20);

if (it != s.end()) {
    cout << *it;
}
```

Output:

```text
30
```

This is especially useful for finding the end of a duplicate range.

---

# 35. `equal_range()`

Returns:

```text
lower_bound()
upper_bound()
```

as a pair of iterators.

Example:

```cpp
multiset<int> s = {
    10,
    20,
    20,
    20,
    30
};

auto range = s.equal_range(20);
```

Conceptually:

```text
range.first
    ↓
first 20

range.second
    ↓
first element greater than 20
```

Therefore:

```cpp
for (auto it = range.first; it != range.second; ++it) {
    cout << *it << " ";
}
```

Output:

```text
20 20 20
```

This is one of the most useful operations for a multiset.

---

# 36. Observers

`std::multiset` provides:

```cpp
key_comp()
value_comp()
```

These expose comparison objects.

---

# 37. `key_comp()`

Returns the comparison object used to order elements.

Example:

```cpp
multiset<int> s = {
    10,
    20,
    30
};

auto comp = s.key_comp();

cout << comp(10, 20);
```

Output:

```text
1
```

because:

```cpp
less<int>(10, 20)
```

is true.

Although the name is `key_comp()`, `multiset` stores values directly and does not have separate key/value pairs like `map`.

---

# 38. `value_comp()`

Returns the comparison object used for values.

Example:

```cpp
auto comp = s.value_comp();

cout << comp(10, 20);
```

For `multiset`, the key and value are conceptually the same element.

Therefore the ordering relationship is the same.

---

# 39. Custom Comparator

The comparator controls the ordering.

Default:

```cpp
multiset<int>
```

uses:

```cpp
less<int>
```

Therefore:

```text
1 1 2 3 3 5
```

---

# 40. Descending Order

Use:

```cpp
greater<int>
```

Example:

```cpp
#include <iostream>
#include <set>
#include <functional>

using namespace std;

int main() {

    multiset<int, greater<int>> s;

    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(20);
    s.insert(30);

    for (int x : s) {
        cout << x << " ";
    }
}
```

Output:

```text
50 30 20 20 10
```

Duplicates are retained while the ordering is descending.

---

# 41. Custom Comparator Class

You can create your own comparator.

```cpp
struct Compare {

    bool operator()(int a, int b) const {
        return a > b;
    }

};
```

Then:

```cpp
multiset<int, Compare> s;
```

Example:

```cpp
#include <iostream>
#include <set>

using namespace std;

struct Compare {

    bool operator()(int a, int b) const {
        return a > b;
    }

};

int main() {

    multiset<int, Compare> s = {
        10,
        30,
        20,
        20
    };

    for (int x : s) {
        cout << x << " ";
    }
}
```

Output:

```text
30 20 20 10
```

---

# 42. Custom Objects

A multiset can store custom objects.

Example:

```cpp
class Student {

public:

    int id;
    string name;

    bool operator<(const Student& other) const {
        return id < other.id;
    }
};
```

Then:

```cpp
multiset<Student> students;
```

Example:

```cpp
students.insert({101, "Amit"});
students.insert({101, "Rahul"});
students.insert({102, "Deep"});
```

All three objects can be stored if the comparator considers them equivalent.

For the comparator:

```cpp
return id < other.id;
```

both:

```text
{101, "Amit"}
{101, "Rahul"}
```

are equivalent under ordering.

Unlike `set`, `multiset` allows both.

Conceptually:

```text
101 Amit
101 Rahul
102 Deep
```

---

# 43. `std::pair` with `multiset`

You can store pairs:

```cpp
multiset<pair<int, string>> s;
```

Example:

```cpp
s.insert({2, "Two"});
s.insert({1, "One"});
s.insert({1, "Another"});
s.insert({2, "Two"});
```

The default `std::pair` comparison is lexicographical.

It first compares:

```text
first
```

If the first values are equal, it compares:

```text
second
```

Therefore the result is ordered by:

```text
first
then
second
```

Example:

```text
1 Another
1 One
2 Two
2 Two
```

The duplicate pair is retained because this is a multiset.

---

# 44. Move Semantics

Example:

```cpp
multiset<int> s1 = {
    1,
    2,
    2,
    3
};

multiset<int> s2(std::move(s1));
```

Resources can be transferred instead of copied.

After the move:

```text
s1 -> valid but unspecified state
s2 -> transferred contents
```

Use:

```cpp
#include <utility>
```

for:

```cpp
std::move()
```

---

# 45. Why Multiset Elements Cannot Be Modified

Suppose:

```cpp
multiset<int> s = {
    10,
    20,
    20,
    30
};
```

You might try:

```cpp
auto it = s.find(20);

*it = 50;
```

This is not allowed.

Why?

Because changing:

```text
20 -> 50
```

could break the ordering of the tree.

The multiset's ordering invariant must remain valid.

Therefore elements are treated as const through ordinary iterators.

Conceptually:

```cpp
multiset<int>::iterator
```

provides access to:

```cpp
const int
```

for the stored element.

---

# 46. Changing an Element

Suppose you want to change one occurrence:

```text
20 -> 50
```

You cannot directly modify it.

## Traditional method

```cpp
auto it = s.find(20);

if (it != s.end()) {
    s.erase(it);
    s.insert(50);
}
```

This changes one occurrence.

If you instead do:

```cpp
s.erase(20);
```

all occurrences of `20` are removed, so use the iterator form when you want to change only one occurrence.

---

## C++17 Node Handle Method

```cpp
auto node = s.extract(s.find(20));

if (!node.empty()) {

    node.value() = 50;

    s.insert(std::move(node));
}
```

This extracts one node, changes its value, and inserts it back.

The inserted value is placed according to the multiset's ordering.

---

# 47. Iterator and Reference Rules

## Insertion

Inserting an element generally does not invalidate existing iterators or references.

```cpp
auto it = s.find(20);

s.insert(50);

cout << *it;
```

The iterator remains valid if the referred element was not erased.

---

## Erasing one element

```cpp
auto it = s.find(20);

s.erase(it);
```

Now:

```cpp
it
```

is invalid.

Do not use it afterward.

---

## Clearing

```cpp
s.clear();
```

All elements are erased, so iterators and references to those elements become invalid.

---

# 48. `multiset` vs `set`

| Feature | `set` | `multiset` |
|---|---|---|
| Header | `<set>` | `<set>` |
| Sorted | Yes | Yes |
| Duplicate values | No | Yes |
| Unique values | Yes | No |
| Typical structure | Balanced tree | Balanced tree |
| Search | O(log n) | O(log n) |
| Insert | O(log n) | O(log n) |
| `erase(key)` | O(log n) | O(log n + k) |
| `count(key)` | 0 or 1 | 0 or more |
| `contains()` | C++20 | C++20 |
| `lower_bound()` | Yes | Yes |
| `upper_bound()` | Yes | Yes |
| `equal_range()` | Yes | Very useful for duplicate ranges |

### Main difference

```text
set
    -> unique values

multiset
    -> duplicate values allowed
```

---

# 49. `multiset` vs `unordered_multiset`

| Feature | `multiset` | `unordered_multiset` |
|---|---|---|
| Sorted | Yes | No |
| Duplicates | Yes | Yes |
| Typical structure | Balanced tree | Hash table |
| Search | O(log n) | O(1) average |
| Insert | O(log n) | O(1) average |
| Erase | O(log n + k) by key | O(k) average for all matching elements |
| Ordered iteration | Yes | No |
| `lower_bound()` | Yes | No |
| `upper_bound()` | Yes | No |
| `contains()` | C++20 | C++20 |
| Ordering comparator | Required | Not required |
| Hash function | Not required | Required |

### Use `multiset` when:

```text
Need duplicates
+
Need sorted order
+
Need ordered/range queries
```

### Use `unordered_multiset` when:

```text
Need duplicates
+
Ordering is unnecessary
+
Average O(1) lookup is preferred
```

---

# 50. `multiset` vs `vector`

| Feature | `multiset` | `vector` |
|---|---|---|
| Storage | Tree nodes | Contiguous memory |
| Sorted automatically | Yes | No |
| Duplicate values | Yes | Yes |
| Random access | No | Yes |
| `operator[]` | No | Yes |
| Search | O(log n) | O(n), unless sorted + binary search |
| Insert | O(log n) | Depends on position |
| Erase | O(log n + k) by key | O(n) depending on position |
| Memory overhead | Higher | Lower |
| Cache locality | Usually poorer | Usually better |

Use `vector` when:

- You need random access.
- Data is mostly sequential.
- Cache locality is important.
- You do not need automatic sorted insertion.

Use `multiset` when:

- Duplicate values are required.
- Automatic sorted ordering is required.
- Dynamic insertion and deletion are common.
- Ordered lookup is important.

---

# 51. `multiset` vs `vector + sort`

Another common approach is:

```cpp
vector<int> v;
```

followed by:

```cpp
sort(v.begin(), v.end());
```

A vector can be useful when data is collected in batches.

### `multiset`

```text
Insert value
     ↓
Immediately placed according to ordering
     ↓
Duplicates retained
```

### `vector + sort`

```text
Collect values
     ↓
Duplicates retained
     ↓
Sort later
```

For large batch operations, `vector + sort` can sometimes be faster because vector storage is contiguous and has better cache locality.

If the data must remain dynamically ordered between insertions, `multiset` is usually a more natural choice.

---

# 52. Common Mistakes

## Mistake 1: Expecting insertion order

```cpp
multiset<int> s;

s.insert(30);
s.insert(10);
s.insert(20);
```

Do not expect:

```text
30 10 20
```

Iteration follows comparator order:

```text
10 20 30
```

---

## Mistake 2: Assuming duplicates are rejected

Wrong assumption:

```cpp
multiset<int> s;

s.insert(10);
s.insert(10);
```

Result is not:

```text
10
```

It is:

```text
10 10
```

---

## Mistake 3: Using `erase(value)` when you only want one occurrence

Suppose:

```text
10 20 20 20 30
```

This:

```cpp
s.erase(20);
```

removes all three `20` values.

To remove only one:

```cpp
auto it = s.find(20);

if (it != s.end()) {
    s.erase(it);
}
```

---

## Mistake 4: Trying to use indexing

Invalid:

```cpp
cout << s[0];
```

A multiset does not provide random indexing.

---

## Mistake 5: Trying to modify an element

Invalid:

```cpp
auto it = s.find(20);
*it = 50;
```

Use erase/insert or C++17 node handles.

---

## Mistake 6: Dereferencing `end()`

Invalid:

```cpp
cout << *s.end();
```

`end()` does not point to an element.

---

## Mistake 7: Using `find()` without checking

Wrong:

```cpp
cout << *s.find(100);
```

If `100` does not exist:

```cpp
s.find(100) == s.end()
```

Correct:

```cpp
auto it = s.find(100);

if (it != s.end()) {
    cout << *it;
}
```

---

## Mistake 8: Assuming `count()` returns only 0 or 1

That is true for `set`, but not for `multiset`.

For:

```cpp
multiset<int> s = {
    10,
    10,
    10
};
```

```cpp
s.count(10);
```

returns:

```text
3
```

---

## Mistake 9: Incorrect custom comparator

A comparator must provide a valid **strict weak ordering**.

Do not write arbitrary comparison logic.

A broken comparator can cause incorrect behavior in the ordered container.

---

# 53. Practical Examples

## Example 1 — Store Duplicate Values

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {

    multiset<int> scores;

    scores.insert(90);
    scores.insert(80);
    scores.insert(90);
    scores.insert(70);
    scores.insert(80);

    for (int x : scores) {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
70 80 80 90 90
```

---

# Example 2 — Count Occurrences

```cpp
multiset<int> scores = {
    90,
    80,
    90,
    70,
    90
};

cout << scores.count(90);
```

Output:

```text
3
```

---

# Example 3 — Remove Only One Duplicate

```cpp
multiset<int> scores = {
    70,
    80,
    80,
    80,
    90
};

auto it = scores.find(80);

if (it != scores.end()) {
    scores.erase(it);
}
```

Result:

```text
70 80 80 90
```

Only one occurrence was removed.

---

# Example 4 — Remove All Duplicates of a Value

```cpp
multiset<int> scores = {
    70,
    80,
    80,
    80,
    90
};

scores.erase(80);
```

Result:

```text
70 90
```

All `80` occurrences are removed.

---

# Example 5 — Find All Occurrences

```cpp
multiset<int> s = {
    10,
    20,
    20,
    20,
    30
};

auto range = s.equal_range(20);

for (auto it = range.first; it != range.second; ++it) {
    cout << *it << " ";
}
```

Output:

```text
20 20 20
```

---

# Example 6 — Range Query

Suppose:

```cpp
multiset<int> s = {
    10,
    20,
    20,
    30,
    40,
    50,
    50,
    60
};
```

Find values:

```text
30 <= x < 50
```

Use:

```cpp
auto first = s.lower_bound(30);
auto last = s.lower_bound(50);

for (auto it = first; it != last; ++it) {
    cout << *it << " ";
}
```

Output:

```text
30 40
```

---

# Example 7 — Range Including Duplicates

Suppose:

```cpp
multiset<int> s = {
    20,
    20,
    30,
    30,
    30,
    40
};
```

Find all values from `20` through `30`, inclusive:

```cpp
auto first = s.lower_bound(20);
auto last = s.upper_bound(30);

for (auto it = first; it != last; ++it) {
    cout << *it << " ";
}
```

Output:

```text
20 20 30 30 30
```

---

# Example 8 — Descending Multiset

```cpp
multiset<int, greater<int>> s = {
    10,
    30,
    20,
    20,
    40
};

for (int x : s) {
    cout << x << " ";
}
```

Output:

```text
40 30 20 20 10
```

---

# Example 9 — Erase While Iterating

A safe pattern is:

```cpp
for (auto it = s.begin(); it != s.end(); ) {

    if (*it % 2 == 0) {
        it = s.erase(it);
    }
    else {
        ++it;
    }
}
```

This removes every even-valued occurrence.

For example:

```text
10 10 15 20 20 25
```

becomes:

```text
15 25
```

---

# Example 10 — Complete Program

```cpp
#include <iostream>
#include <set>

using namespace std;

int main() {

    multiset<int> numbers;

    // Insert
    numbers.insert(30);
    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(20);
    numbers.insert(10);

    cout << "Elements:\n";

    for (int x : numbers) {
        cout << x << " ";
    }

    cout << "\n";

    // Size
    cout << "Size: "
         << numbers.size()
         << "\n";

    // Count
    cout << "Count of 20: "
         << numbers.count(20)
         << "\n";

    // Find
    auto it = numbers.find(20);

    if (it != numbers.end()) {
        cout << "20 found\n";
    }

    // Contains
    if (numbers.contains(30)) {
        cout << "30 exists\n";
    }

    // Lower bound
    auto lower = numbers.lower_bound(15);

    if (lower != numbers.end()) {
        cout << "Lower bound of 15: "
             << *lower << "\n";
    }

    // Upper bound
    auto upper = numbers.upper_bound(20);

    if (upper != numbers.end()) {
        cout << "Upper bound of 20: "
             << *upper << "\n";
    }

    // Erase one occurrence
    auto eraseIt = numbers.find(20);

    if (eraseIt != numbers.end()) {
        numbers.erase(eraseIt);
    }

    cout << "After erasing one 20:\n";

    for (int x : numbers) {
        cout << x << " ";
    }

    return 0;
}
```

Possible output:

```text
Elements:
10 10 20 20 30

Size: 5
Count of 20: 2
20 found
30 exists
Lower bound of 15: 20
Upper bound of 20: 30
After erasing one 20:
10 10 20 30
```

---

# 54. Interview Questions

## Q1. What is `std::multiset`?

`std::multiset` is an ordered associative STL container that stores multiple equivalent elements according to a comparison object.

---

## Q2. Does a multiset allow duplicates?

Yes.

```cpp
multiset<int> s;

s.insert(10);
s.insert(10);
s.insert(10);
```

Result:

```text
10 10 10
```

---

## Q3. Is `multiset` sorted?

Yes.

By default, elements are ordered using:

```cpp
std::less<Key>
```

which normally gives ascending order.

---

## Q4. What is the default comparator?

Conceptually:

```cpp
std::less<Key>
```

---

## Q5. What is the typical internal implementation?

A self-balancing binary search tree, commonly a Red-Black Tree.

The C++ standard does not mandate a particular tree implementation.

---

## Q6. What is the complexity of `find()`?

```text
O(log n)
```

---

## Q7. What is the complexity of `insert()`?

Typically:

```text
O(log n)
```

---

## Q8. What is the difference between `set` and `multiset`?

```text
set
    -> equivalent elements are not duplicated

multiset
    -> equivalent elements are allowed
```

---

## Q9. What does `count()` return for a multiset?

It returns the number of elements equivalent to the specified key.

Example:

```cpp
multiset<int> s = {
    10,
    10,
    10
};

s.count(10);
```

returns:

```text
3
```

---

## Q10. What is the difference between `find()` and `count()`?

`find()` returns an iterator to one matching occurrence:

```cpp
auto it = s.find(20);
```

`count()` returns the number of matching occurrences:

```cpp
size_t n = s.count(20);
```

---

## Q11. What is `contains()`?

C++20:

```cpp
s.contains(value)
```

returns a boolean indicating whether at least one equivalent value exists.

---

## Q12. What is the complexity of `count()`?

For a multiset:

```text
O(log n + k)
```

where:

```text
k = number of matching elements
```

because all matching occurrences may need to be traversed.

---

## Q13. What happens when `erase(key)` is called?

All elements equivalent to the key are erased.

Example:

```cpp
multiset<int> s = {
    10,
    20,
    20,
    20,
    30
};

s.erase(20);
```

Result:

```text
10 30
```

and the return value is:

```text
3
```

---

## Q14. How do you erase only one occurrence?

Use an iterator:

```cpp
auto it = s.find(20);

if (it != s.end()) {
    s.erase(it);
}
```

---

## Q15. What is `lower_bound()`?

It returns the first element satisfying:

```text
element >= target
```

---

## Q16. What is `upper_bound()`?

It returns the first element satisfying:

```text
element > target
```

---

## Q17. How can you find all duplicate occurrences of a value?

Use:

```cpp
auto range = s.equal_range(value);

for (auto it = range.first; it != range.second; ++it) {
    // matching element
}
```

---

## Q18. Why can't multiset elements be modified directly?

Changing an element could break the container's ordering invariant.

Therefore normal iterators expose the stored value as const.

---

## Q19. How can you modify one multiset element?

Traditional:

```cpp
auto it = s.find(oldValue);

if (it != s.end()) {
    s.erase(it);
    s.insert(newValue);
}
```

C++17 node handle:

```cpp
auto node = s.extract(s.find(oldValue));

if (!node.empty()) {
    node.value() = newValue;
    s.insert(std::move(node));
}
```

---

## Q20. Can a multiset use descending order?

Yes:

```cpp
multiset<int, greater<int>> s;
```

---

## Q21. What is the difference between `multiset` and `unordered_multiset`?

```text
multiset
    -> ordered
    -> O(log n) lookup
    -> range queries available

unordered_multiset
    -> unordered
    -> O(1) average lookup
    -> no lower_bound()/upper_bound()
```

---

## Q22. Can a multiset store custom objects?

Yes, if an appropriate comparison relation is available.

Example:

```cpp
multiset<Student> students;
```

---

## Q23. How does multiset determine equivalent objects?

Two objects are equivalent according to the comparator when:

```cpp
!comp(a, b) && !comp(b, a)
```

Equivalent objects can all be stored because `multiset` allows duplicates.

---

## Q24. Does insertion invalidate existing multiset iterators?

In general, no.

Existing iterators and references remain valid after insertion.

An iterator/reference to an erased element becomes invalid after that element is erased.

---

## Q25. Does `multiset` provide `operator[]`?

No.

It is not a random-access container.

---

## Q26. Can `multiset` contain multiple identical values?

Yes.

For example:

```cpp
multiset<int> s = {
    5,
    5,
    5
};
```

All three values are stored as separate occurrences.

---

## Q27. What does `equal_range()` return?

A pair of iterators:

```text
first  -> lower_bound(key)
second -> upper_bound(key)
```

For a multiset, the range contains all equivalent elements.

---

## Q28. What is `extract()`?

C++17 node-handle functionality that removes one node from the multiset and returns ownership of that node through a node handle.

---

## Q29. What is `merge()`?

C++17 functionality that transfers compatible nodes from one associative container to another.

Since `multiset` allows duplicates, equivalent elements can also be transferred into the destination.

---

# 55. Important C++ Version Features

| Feature | Standard |
|---|---|
| `std::multiset` | C++98 |
| Range-based `for` | C++11 |
| `emplace()` | C++11 |
| Move construction/assignment | C++11 |
| `cbegin()` / `cend()` | C++11 |
| `crbegin()` / `crend()` | C++11 |
| `extract()` | C++17 |
| `merge()` | C++17 |
| `contains()` | C++20 |
| Heterogeneous lookup with transparent comparator support | Available through ordered-container library facilities depending on operation and comparator |

### Important

Do not copy map-only APIs into `multiset`.

These are not normal `multiset` operations:

```cpp
operator[]
at()
try_emplace()
insert_or_assign()
```

They are associated with map-like containers.

---

# 56. Quick Reference Table

## Constructors

| Function | Purpose |
|---|---|
| `multiset()` | Empty multiset |
| `multiset(initializer_list)` | Initialize from values |
| `multiset(first, last)` | Initialize from range |
| `multiset(other)` | Copy |
| `multiset(std::move(other))` | Move |

---

## Assignment

| Function | Purpose |
|---|---|
| `operator=` | Copy/move assignment |
| Initializer-list assignment | Replace contents |

---

## Iterators

| Function | Purpose |
|---|---|
| `begin()` | First element |
| `end()` | After last |
| `rbegin()` | Reverse first |
| `rend()` | Reverse end |
| `cbegin()` | Constant begin |
| `cend()` | Constant end |
| `crbegin()` | Constant reverse begin |
| `crend()` | Constant reverse end |

---

## Capacity

| Function | Purpose |
|---|---|
| `empty()` | Check empty |
| `size()` | Number of all occurrences |
| `max_size()` | Maximum possible size |

---

## Modifiers

| Function | Purpose |
|---|---|
| `insert()` | Insert element |
| `emplace()` | Construct element in place |
| `erase()` | Remove element(s) |
| `clear()` | Remove all |
| `swap()` | Exchange contents |
| `extract()` | Extract one node |
| `merge()` | Transfer nodes |

---

## Lookup

| Function | Purpose |
|---|---|
| `find()` | Find one matching occurrence |
| `count()` | Count matching occurrences |
| `contains()` | Check whether at least one exists |
| `lower_bound()` | First value >= target |
| `upper_bound()` | First value > target |
| `equal_range()` | Range of equivalent values |

---

## Observers

| Function | Purpose |
|---|---|
| `key_comp()` | Element comparator |
| `value_comp()` | Value comparator |

---

# 57. Advantages

## 57.1 Duplicate Elements

Unlike `set`, duplicates are allowed.

```cpp
multiset<int> s = {
    10,
    10,
    20
};
```

Result:

```text
10 10 20
```

---

## 57.2 Automatic Sorting

No manual sorting is required.

---

## 57.3 Efficient Search

Search is:

```text
O(log n)
```

---

## 57.4 Efficient Dynamic Insertion and Deletion

Elements can be inserted and erased while maintaining sorted order.

---

## 57.5 Easy Frequency Counting

```cpp
s.count(value);
```

directly tells you how many equivalent values exist.

---

## 57.6 Powerful Range Queries

Functions such as:

```cpp
lower_bound()
upper_bound()
equal_range()
```

make ordered range operations convenient.

---

## 57.7 Custom Ordering

You can define:

```text
Ascending
Descending
Custom business rule
```

ordering.

---

# 58. Disadvantages

## 58.1 No Random Access

You cannot do:

```cpp
s[0]
```

---

## 58.2 Higher Memory Overhead

Tree nodes require links and balancing information.

---

## 58.3 Poorer Cache Locality

Compared with contiguous containers such as `vector`, tree nodes are usually scattered in memory.

---

## 58.4 Usually Slower Than `unordered_multiset` for Average Lookup

If ordering is unnecessary, `unordered_multiset` may provide faster average lookup.

---

## 58.5 More Complex Than a Vector for Simple Batch Data

If you only need to collect values and sort them once, a `vector` followed by `sort()` may be simpler and more cache-friendly.

---

# 59. Decision Guide

Use this mental model:

```text
Need a collection of values?
          |
          +-------------------------+
          |                         |
          |                         |
      Duplicates?               Unique only?
          |                         |
         Yes                       No
          |                         |
          v                         v
      Need sorted?              Need sorted?
          |                         |
       +--+--+                   +--+--+
       |     |                   |     |
      Yes    No                 Yes    No
       |      |                  |      |
       v      v                  v      v
   multiset unordered_multiset  set  unordered_set
```

---

## Another Decision Rule

Use:

```cpp
multiset
```

when you need:

```text
Duplicates
+
Sorted order
+
Dynamic insertion/deletion
+
Ordered lookup
```

Use:

```cpp
unordered_multiset
```

when you need:

```text
Duplicates
+
Fast average lookup
+
No ordering requirement
```

Use:

```cpp
vector
```

when you need:

```text
Duplicates
+
Random access
+
Contiguous storage
+
Batch processing
```

---

# 60. Summary

## Definition

> `std::multiset` is an ordered associative STL container that stores multiple equivalent elements according to a comparison object.

---

## Main Properties

```text
Duplicate elements allowed
          +
Sorted order
          +
Comparator defines ordering
          +
O(log n) search
          +
O(log n) insertion
          +
Ordered deletion
          +
Range queries
```

---

## Main Functions

```cpp
// Insert
insert()
emplace()

// Remove
erase()
clear()

// Node operations
extract()
merge()

// Search
find()
count()
contains()

// Ordered lookup
lower_bound()
upper_bound()
equal_range()

// Iterators
begin()
end()
rbegin()
rend()
cbegin()
cend()

// Capacity
empty()
size()
max_size()

// Comparison
key_comp()
value_comp()

// Utility
swap()
```

---

# `std::multiset` Mental Model

Remember:

```text
                 std::multiset
                       |
                       v
              Duplicate Values
                   Allowed
                       |
                       v
                 Sorted Order
                       |
                       v
              Comparator Defines
                   the Order
                       |
                       v
             Self-Balancing Tree
              (commonly Red-Black)
                       |
                       v
       --------------------------------
       |              |               |
       v              v               v
    find()         insert()        erase()
       |              |               |
       +--------------+---------------+
                      |
                      v
                  O(log n)
```

---

# Most Important Interview Points

```text
1. multiset stores values.

2. multiset allows duplicate/equivalent values.

3. multiset maintains sorted order.

4. Default order is ascending.

5. Ordering is controlled by a comparator.

6. A typical implementation uses a Red-Black Tree.

7. The standard does not mandate Red-Black Tree specifically.

8. find() is O(log n).

9. insert() is O(log n).

10. contains() is O(log n).

11. count() can return 0, 1, 2, 3, ... .

12. count() is O(log n + k), where k is the number of matching elements.

13. erase(key) removes all equivalent elements.

14. erase(iterator) removes only the selected occurrence.

15. lower_bound(x) returns the first element >= x.

16. upper_bound(x) returns the first element > x.

17. equal_range(x) gives the range of all elements equivalent to x.

18. contains(x) is available from C++20.

19. extract() is available from C++17.

20. merge() is available from C++17.

21. Elements cannot be modified directly through normal iterators.

22. Existing iterators generally survive insertion.

23. Erasing an element invalidates iterators/references to that element.

24. multiset does not provide operator[].

25. multiset does not provide at().

26. set stores unique values; multiset allows duplicates.

27. unordered_multiset allows duplicates but does not maintain sorted order.

28. Uniqueness/equivalence is determined by comparator ordering.

29. Use equal_range() to iterate over all occurrences of a value.

30. Use multiset when you need duplicate + ordered data.
```

---

# Final One-Line Definition

> **`std::multiset` is an ordered associative C++ STL container that stores duplicate/equivalent elements, maintains them according to a comparator, and provides efficient logarithmic-time ordered lookup and insertion while supporting multiple occurrences of the same value.**
