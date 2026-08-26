# `std::multimap` in C++ STL

## Table of Contents

1. Introduction
2. Header File
3. Namespace
4. Syntax
5. Template Parameters
6. What is a Key-Value Pair?
7. Internal Working
8. Characteristics
9. Memory Layout
10. Time Complexity
11. Constructors
12. Assignment Operators
13. Iterators
14. Capacity Functions
15. Element Access
16. Modifiers
17. Lookup Functions
18. Observers
19. Custom Comparator
20. Multimap with Different Key and Value Types
21. Pair and `std::multimap`
22. Multimap of Custom Objects
23. Move Semantics
24. Node Handles: `extract()`
25. `merge()`
26. Comparison
27. `multimap` vs `map`
28. `multimap` vs `unordered_multimap`
29. `insert()` vs `emplace()` vs `try_emplace()`
30. Complete Basic Example
31. Example Using `insert()`
32. Example Using `find()`
33. Example Using `count()`
34. Example Using `lower_bound()`
35. Example Using `upper_bound()`
36. Example Using `equal_range()`
37. Example Using Descending Order
38. Example with Custom Comparator
39. Example with Custom Object
40. Advantages
41. Disadvantages
42. Common Mistakes
43. Common Interview Questions
44. Important C++ Version Features
45. Summary

---

# 1. Introduction

- `std::multimap` is an **ordered associative container** in the C++ STL.
- It stores data as **key-value pairs**.
- Unlike `std::map`, a `multimap` **allows duplicate keys**.
- Elements are maintained in sorted order according to the key.
- By default, keys are sorted in ascending order.
- It is typically implemented using a **self-balancing binary search tree**, commonly a Red-Black Tree.
- Searching, insertion, and deletion generally take **O(log n)** time.
- Each element is represented as:

```cpp
std::pair<const Key, T>
```

### Example

```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    multimap<int, string> students;

    students.insert({101, "Amit"});
    students.insert({101, "Rahul"});
    students.insert({102, "Deep"});

    for (const auto& item : students) {
        cout << item.first << " -> "
             << item.second << endl;
    }
}
```

Possible output:

```text
101 -> Amit
101 -> Rahul
102 -> Deep
```

### Important

```cpp
multimap<int, string>
```

means:

```text
Key   -> int
Value -> string
```

Unlike `map`, multiple values can be associated with the same key:

```text
101 -> Amit
101 -> Rahul
101 -> Deep
```

---

# 2. Header File

Use:

```cpp
#include <map>
```

`std::multimap` is defined in the same header as `std::map`.

### Complete example

```cpp
#include <iostream>
#include <map>
#include <string>
```

---

# 3. Namespace

You can use:

```cpp
using namespace std;

multimap<int, string> students;
```

Or explicitly:

```cpp
std::multimap<int, std::string> students;
```

Using `std::` explicitly is often preferred in larger projects and header files because it avoids namespace collisions.

---

# 4. Syntax

```cpp
multimap<KeyType, ValueType> name;
```

### Examples

```cpp
multimap<int, string> students;
multimap<string, int> marks;
multimap<char, int> frequency;
multimap<int, double> prices;
```

### Key and value

```cpp
multimap<int, string> students;
```

Here:

```text
Key   = int
Value = string
```

---

# 5. Template Parameters

The simplified form is:

```cpp
template<
    class Key,
    class T,
    class Compare = less<Key>,
    class Allocator = allocator<pair<const Key, T>>
>
class multimap;
```

### Meaning

| Parameter | Meaning |
|---|---|
| `Key` | Type used to identify elements |
| `T` | Type of value associated with the key |
| `Compare` | Determines key ordering |
| `Allocator` | Controls memory allocation |

Example:

```cpp
multimap<int, string>
```

means:

```text
Key       = int
Value     = string
Comparator = less<int>
```

Therefore keys are sorted in ascending order.

---

# 6. What is a Key-Value Pair?

A multimap stores information like:

```text
Key -> Value
```

The important difference is that **one key can have multiple values**.

### Example

```cpp
multimap<int, string> employees;

employees.insert({101, "Amit"});
employees.insert({101, "Rahul"});
employees.insert({101, "Deep"});
```

Conceptually:

```text
101 -> Amit
101 -> Rahul
101 -> Deep
```

All three elements are valid.

Each element can be accessed using:

```cpp
item.first
```

for the key and:

```cpp
item.second
```

for the value.

### Example

```cpp
for (const auto& item : employees) {
    cout << item.first
         << " -> "
         << item.second
         << endl;
}
```

---

# 7. Internal Working

`std::multimap` is an **ordered associative container**.

It is typically implemented using a **self-balancing binary search tree**, commonly a **Red-Black Tree**.

Conceptually:

```text
              20
            /    \
          10      40
         /       /  \
        5       30   60
```

The exact tree structure is implementation-dependent.

The important concept is:

```text
Key comparison
      ↓
Ordered tree
      ↓
Self balancing
      ↓
O(log n) operations
```

### Duplicate keys

Suppose:

```cpp
multimap<int, string> m;

m.insert({20, "A"});
m.insert({20, "B"});
m.insert({20, "C"});
```

The multimap contains:

```text
20 -> A
20 -> B
20 -> C
```

The tree structure must therefore support multiple elements with equivalent keys.

### Important

The C++ standard specifies the behavior and complexity requirements of `std::multimap`; it does not require a specific internal tree implementation.

---

# 8. Characteristics

`std::multimap` has these important characteristics:

- Stores key-value pairs.
- Allows duplicate keys.
- Keys are sorted.
- Default sorting is ascending.
- Supports custom comparators.
- Does not provide random access by integer index.
- Supports bidirectional iterators.
- Searching is generally O(log n).
- Insertion is generally O(log n).
- Erasing by key is O(log n + count).
- Supports multiple values for one key.
- Supports `lower_bound()`.
- Supports `upper_bound()`.
- Supports `equal_range()`.
- `operator[]` is **not available**.
- `at()` is **not available**.
- Supports node handles and merging from C++17.

---

# 9. Memory Layout

Suppose:

```cpp
multimap<int, string> m;

m.insert({20, "A"});
m.insert({10, "B"});
m.insert({20, "C"});
```

Conceptually:

```text
             20 -> "A"
            /          \
     10 -> "B"       20 -> "C"
```

The exact tree layout is implementation-specific.

A tree node generally needs information such as:

```text
--------------------------------
Key
Value
Left child pointer/reference
Right child pointer/reference
Parent pointer/reference
Balancing information
--------------------------------
```

Therefore, a multimap usually has more memory overhead per element than a contiguous container.

---

# 10. Time Complexity

| Operation | Complexity |
|---|---:|
| `insert()` | O(log n) |
| `emplace()` | O(log n) |
| `try_emplace()` | O(log n) |
| `erase(key)` | O(log n + k) |
| `erase(iterator)` | Amortized constant for the erase operation itself, plus any required rebalancing |
| `find()` | O(log n) |
| `count()` | O(log n + k) |
| `contains()` | O(log n) |
| `lower_bound()` | O(log n) |
| `upper_bound()` | O(log n) |
| `equal_range()` | O(log n) |
| `size()` | O(1) |
| `empty()` | O(1) |
| `clear()` | O(n) |
| `begin()` | O(1) |
| `end()` | O(1) |

Here:

```text
k = number of elements having the specified key
```

### Important

For `std::multimap`:

```text
Search       -> O(log n)
Insertion    -> O(log n)
Erase key    -> O(log n + k)
```

---

# 11. Constructors

## 11.1 Default Constructor

```cpp
multimap<int, string> m;
```

Creates an empty multimap.

---

## 11.2 Initializer List Constructor

```cpp
multimap<int, string> m = {
    {101, "Amit"},
    {101, "Rahul"},
    {102, "Deep"}
};
```

Result:

```text
101 -> Amit
101 -> Rahul
102 -> Deep
```

Duplicate keys are allowed.

---

## 11.3 Range Constructor

```cpp
vector<pair<int, string>> v = {
    {1, "A"},
    {1, "B"},
    {2, "C"}
};

multimap<int, string> m(v.begin(), v.end());
```

The duplicate key `1` is preserved.

---

## 11.4 Copy Constructor

```cpp
multimap<int, string> m1 = {
    {1, "A"},
    {1, "B"}
};

multimap<int, string> m2(m1);
```

`m2` receives a copy of `m1`.

---

## 11.5 Move Constructor

```cpp
multimap<int, string> m1 = {
    {1, "A"},
    {1, "B"}
};

multimap<int, string> m2(std::move(m1));
```

The resources of `m1` can be transferred to `m2`.

After the move:

```text
m1 -> valid but unspecified state
m2 -> contains transferred contents
```

---

# 12. Assignment Operators

## 12.1 Copy Assignment

```cpp
multimap<int, string> m1 = {
    {1, "A"},
    {1, "B"}
};

multimap<int, string> m2;

m2 = m1;
```

Now `m2` contains a copy of `m1`.

---

## 12.2 Move Assignment

```cpp
m2 = std::move(m1);
```

Resources can be transferred from `m1` to `m2`.

After the move:

```text
m1 -> valid but unspecified state
m2 -> owns transferred contents
```

---

## 12.3 Initializer-List Assignment

```cpp
m = {
    {1, "A"},
    {1, "B"},
    {2, "C"}
};
```

Existing contents are replaced.

---

# 13. Iterators

Iterators allow traversal through multimap elements.

Each iterator refers to:

```cpp
pair<const Key, T>
```

---

## 13.1 `begin()`

```cpp
auto it = m.begin();
```

Points to the first element according to the map's ordering.

---

## 13.2 `end()`

```cpp
auto it = m.end();
```

Points one position after the last element.

Do not dereference `end()`.

---

## 13.3 Traversing

```cpp
for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first
         << " -> "
         << it->second
         << endl;
}
```

---

## 13.4 `rbegin()`

Starts reverse traversal from the last element.

```cpp
for (auto it = m.rbegin(); it != m.rend(); ++it) {
    cout << it->first
         << " -> "
         << it->second
         << endl;
}
```

---

## 13.5 `rend()`

Represents the position before the first element in reverse traversal.

---

## 13.6 `cbegin()`

Returns a constant iterator.

```cpp
auto it = m.cbegin();
```

---

## 13.7 `cend()`

Returns the constant end iterator.

---

# 14. Capacity Functions

## 14.1 `empty()`

Checks whether the multimap is empty.

```cpp
if (m.empty()) {
    cout << "Multimap is empty";
}
```

Returns:

```text
true
false
```

---

## 14.2 `size()`

Returns the total number of elements.

Important:

```cpp
multimap<int, string> m = {
    {1, "A"},
    {1, "B"},
    {1, "C"}
};
```

Then:

```cpp
m.size()
```

returns:

```text
3
```

It counts **elements**, not unique keys.

---

## 14.3 `max_size()`

Returns the theoretical maximum number of elements the container can hold, subject to implementation and system limitations.

```cpp
cout << m.max_size();
```

---

# 15. Element Access

This is an important difference between `map` and `multimap`.

## `std::multimap` does NOT provide:

```cpp
operator[]
```

and:

```cpp
at()
```

### Why?

Because a key can correspond to multiple values.

For example:

```text
101 -> Amit
101 -> Rahul
101 -> Deep
```

What should this mean?

```cpp
m[101]
```

Should it return:

```text
Amit?
Rahul?
Deep?
```

There is no single mapped value.

Therefore `multimap` does not provide `operator[]` or `at()`.

### Use lookup functions instead

```cpp
find()
lower_bound()
upper_bound()
equal_range()
```

---

# 16. Modifiers

## 16.1 `insert()`

Inserts a key-value pair.

```cpp
m.insert({101, "Amit"});
m.insert({101, "Rahul"});
```

Both elements are inserted.

Result:

```text
101 -> Amit
101 -> Rahul
```

---

## 16.2 Duplicate Keys with `insert()`

This is the major difference from `map`.

```cpp
multimap<int, string> m;

m.insert({1, "A"});
m.insert({1, "B"});
m.insert({1, "C"});
```

Result:

```text
1 -> A
1 -> B
1 -> C
```

All three entries are stored.

---

## 16.3 Insert with Hint

```cpp
auto hint = m.begin();

m.insert(hint, {5, "Five"});
```

A correct hint can improve insertion performance.

---

## 16.4 Range Insert

```cpp
vector<pair<int, string>> v = {
    {1, "A"},
    {1, "B"},
    {2, "C"}
};

m.insert(v.begin(), v.end());
```

All elements are inserted, including duplicate keys.

---

## 16.5 `emplace()`

Constructs an element in place.

```cpp
m.emplace(101, "Amit");
m.emplace(101, "Rahul");
```

Both are valid.

---

## 16.6 `try_emplace()` — C++17

`try_emplace()` is also available for `multimap`.

```cpp
m.try_emplace(101, "Amit");
m.try_emplace(101, "Rahul");
```

Unlike `map`, there is no unique-key constraint preventing the second insertion.

Therefore both entries can exist:

```text
101 -> Amit
101 -> Rahul
```

The important distinction is that `try_emplace()` can construct the mapped value directly from the supplied arguments.

---

## 16.7 `insert_or_assign()`

**`std::multimap` does not provide `insert_or_assign()`.**

Why?

Because there is no unique element to assign to for a given key.

A key can have:

```text
101 -> A
101 -> B
101 -> C
```

There is no single mapped value associated with `101`.

If you want to modify a particular element, find its iterator and modify:

```cpp
it->second = "New Value";
```

---

## 16.8 `erase(key)`

```cpp
m.erase(101);
```

For a multimap, this removes **all elements with key `101`**.

Example:

```cpp
multimap<int, string> m = {
    {101, "A"},
    {101, "B"},
    {102, "C"}
};

m.erase(101);
```

Result:

```text
102 -> C
```

Return value:

```text
number of elements erased
```

For example:

```cpp
size_t count = m.erase(101);
```

If there were three entries with key `101`:

```text
count = 3
```

---

## 16.9 `erase(iterator)`

Removes one specific element.

```cpp
auto it = m.find(101);

if (it != m.end()) {
    m.erase(it);
}
```

If several `101` entries exist, only the element referred to by `it` is removed.

---

## 16.10 `erase(range)`

You can erase a range:

```cpp
m.erase(first, last);
```

This is particularly useful with:

```cpp
lower_bound()
upper_bound()
equal_range()
```

---

## 16.11 `clear()`

```cpp
m.clear();
```

Removes all elements.

---

## 16.12 `swap()`

```cpp
m1.swap(m2);
```

Swaps the contents of two multimaps.

---

# 17. Lookup Functions

Lookup is especially important in `multimap` because duplicate keys are allowed.

---

# 17.1 `find()`

Searches for a key.

```cpp
auto it = m.find(101);
```

If found:

```cpp
it != m.end()
```

If not found:

```cpp
it == m.end()
```

### Important

For duplicate keys, `find()` returns an iterator to **one element with the specified key**, specifically an element in the equivalent-key range; use `equal_range()` when you need all matching elements.

---

# 17.2 `count()`

Returns the number of elements with a specified key.

Example:

```cpp
multimap<int, string> m = {
    {101, "A"},
    {101, "B"},
    {101, "C"},
    {102, "D"}
};

cout << m.count(101);
```

Output:

```text
3
```

This is different from `map`.

For `map`:

```text
count(key) -> 0 or 1
```

For `multimap`:

```text
count(key) -> 0, 1, 2, 3, ...
```

---

# 17.3 `contains()` — C++20

Checks whether at least one element with the key exists.

```cpp
if (m.contains(101)) {
    cout << "Key exists";
}
```

Returns:

```text
true
false
```

It does not tell you how many elements have that key.

For the count:

```cpp
m.count(101);
```

---

# 17.4 `lower_bound()`

Returns an iterator to the first element whose key is **not less than** the specified key.

In simple terms:

```text
first key >= target
```

Example:

```cpp
multimap<int, string> m = {
    {10, "A"},
    {20, "B"},
    {20, "C"},
    {30, "D"}
};

auto it = m.lower_bound(20);

cout << it->first
     << " -> "
     << it->second;
```

The iterator points to the first element with key `20`.

---

# 17.5 `upper_bound()`

Returns an iterator to the first element whose key is **greater than** the specified key.

In simple terms:

```text
first key > target
```

Example:

```cpp
auto it = m.upper_bound(20);
```

It points to the first element with key greater than `20`.

In the example:

```text
30 -> D
```

---

# 17.6 `equal_range()`

This is one of the most useful functions for `multimap`.

It returns:

```text
lower_bound(key)
+
upper_bound(key)
```

Conceptually:

```text
                matching keys
                     ↓
       ┌─────────────────────────┐
       ↓                         ↓
 lower_bound                upper_bound
```

Example:

```cpp
multimap<int, string> m = {
    {101, "A"},
    {101, "B"},
    {101, "C"},
    {102, "D"}
};

auto range = m.equal_range(101);
```

Then:

```cpp
range.first
```

points to the first `101`.

And:

```cpp
range.second
```

points just after the last `101`.

---

## Iterating All Values for a Key

```cpp
auto range = m.equal_range(101);

for (auto it = range.first;
     it != range.second;
     ++it) {

    cout << it->first
         << " -> "
         << it->second
         << endl;
}
```

Output:

```text
101 -> A
101 -> B
101 -> C
```

---

# 18. Observers

## 18.1 `key_comp()`

Returns the comparator used to order keys.

```cpp
auto comp = m.key_comp();
```

Example:

```cpp
multimap<int, string> m = {
    {10, "A"},
    {20, "B"}
};

auto comp = m.key_comp();

cout << comp(10, 20);
```

With the default ascending comparator:

```text
true
```

---

## 18.2 `value_comp()`

Returns the comparison object used for map value ordering.

```cpp
auto comp = m.value_comp();
```

The comparison is based on the key.

The element type is:

```cpp
pair<const Key, T>
```

---

# 19. Custom Comparator

By default:

```cpp
multimap<int, string>
```

uses:

```cpp
less<int>
```

Therefore:

```text
10
20
30
```

are ordered ascending.

### Descending order

```cpp
multimap<int, string, greater<int>> m;
```

Example:

```cpp
multimap<int, string, greater<int>> m;

m.insert({10, "Ten"});
m.insert({30, "Thirty"});
m.insert({20, "Twenty"});
m.insert({20, "Twenty Again"});

for (const auto& item : m) {
    cout << item.first
         << " -> "
         << item.second
         << endl;
}
```

Output:

```text
30 -> Thirty
20 -> Twenty
20 -> Twenty Again
10 -> Ten
```

---

# 20. Multimap with Different Key and Value Types

The key and value can have different types.

Examples:

```cpp
multimap<int, string> employees;
multimap<string, int> marks;
multimap<string, double> prices;
multimap<char, int> frequency;
multimap<long long, bool> flags;
```

### Example

```cpp
multimap<string, int> marks;

marks.insert({"Amit", 85});
marks.insert({"Amit", 90});
marks.insert({"Rahul", 80});
```

Result:

```text
Amit -> 85
Amit -> 90
Rahul -> 80
```

This is useful when one key naturally has multiple associated values.

---

# 21. Pair and `std::multimap`

A multimap element is essentially:

```cpp
pair<const Key, T>
```

Example:

```cpp
multimap<int, string> m;

m.insert({1, "One"});
m.insert({1, "Another One"});
```

Each element contains:

```text
first  -> key
second -> value
```

Example:

```cpp
for (const auto& item : m) {
    cout << item.first
         << " "
         << item.second
         << endl;
}
```

---

# 22. Multimap of Custom Objects

Suppose:

```cpp
class Student {
public:
    int id;
    string name;
};
```

We can use `Student` as a value:

```cpp
multimap<int, Student> students;
```

Example:

```cpp
students.insert({101, {101, "Amit"}});
students.insert({101, {102, "Rahul"}});
students.insert({102, {103, "Deep"}});
```

Conceptually:

```text
101 -> Student(Amit)
101 -> Student(Rahul)
102 -> Student(Deep)
```

---

## Custom Object as Key

A custom object can also be used as a key if the multimap has a valid ordering.

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
multimap<Student, string> m;
```

The comparator determines how the keys are ordered.

---

# 23. Move Semantics

Example:

```cpp
multimap<int, string> m1 = {
    {1, "A"},
    {1, "B"},
    {2, "C"}
};

multimap<int, string> m2(std::move(m1));
```

Resources can be transferred instead of copying every element.

After the move:

```text
m1 -> valid but unspecified state
m2 -> contains transferred contents
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

# 24. Node Handles: `extract()` — C++17

`extract()` removes a node from the multimap and returns a node handle.

Example:

```cpp
multimap<int, string> m = {
    {1, "A"},
    {1, "B"},
    {2, "C"}
};

auto node = m.extract(m.begin());
```

The extracted node is now owned by:

```cpp
node
```

and is no longer inside `m`.

---

## Extract by Key

```cpp
auto node = m.extract(1);
```

For an associative container with equivalent keys, extraction by key removes and returns **one matching node**.

It does not remove every element with that key.

To remove all matching elements:

```cpp
m.erase(1);
```

---

## Changing a Key

Map and multimap keys cannot normally be modified through an iterator:

```cpp
it->first = 100;   // Error
```

With C++17 node handles:

```cpp
auto node = m.extract(m.begin());

node.key() = 100;

m.insert(std::move(node));
```

This allows the key of the extracted node to be changed.

---

# 25. `merge()` — C++17

`merge()` transfers nodes from one compatible associative container to another.

Example:

```cpp
multimap<int, string> a = {
    {1, "A"},
    {1, "B"}
};

multimap<int, string> b = {
    {2, "C"},
    {2, "D"}
};

a.merge(b);
```

Result:

```text
a:
1 -> A
1 -> B
2 -> C
2 -> D
```

Because `multimap` allows duplicate keys, destination key collisions do not prevent transfer.

### Important

For a `multimap`, all nodes can generally be transferred when the source and destination types are compatible, subject to allocator and comparator compatibility rules.

---

# 26. Comparison

Multimaps can be compared using the standard comparison facilities supported by the C++ version in use.

For example:

```cpp
if (m1 == m2) {
    cout << "Equal";
}
```

Equality comparison considers the elements of the containers.

The ordering of equivalent-key elements can matter when comparing the sequences of elements.

---

# 27. `multimap` vs `map`

This is one of the most important comparisons.

| Feature | `map` | `multimap` |
|---|---|---|
| Header | `<map>` | `<map>` |
| Key-value pairs | Yes | Yes |
| Unique keys | Yes | No |
| Duplicate keys | No | Yes |
| Sorted keys | Yes | Yes |
| Default order | Ascending | Ascending |
| Typical structure | Balanced tree | Balanced tree |
| `operator[]` | Yes | No |
| `at()` | Yes | No |
| `find()` | Yes | Yes |
| `count()` | 0 or 1 | 0 or more |
| `contains()` | Yes | Yes |
| `lower_bound()` | Yes | Yes |
| `upper_bound()` | Yes | Yes |
| `equal_range()` | Yes | Yes |
| `insert_or_assign()` | Yes | No |
| `try_emplace()` | Yes | Yes |
| `extract()` | Yes | Yes |
| `merge()` | Yes | Yes |

### Main difference

```text
map
 ↓
One key -> one value
```

```text
multimap
 ↓
One key -> multiple values
```

Example:

### `map`

```text
101 -> Amit
```

Cannot have:

```text
101 -> Rahul
```

as another element.

### `multimap`

```text
101 -> Amit
101 -> Rahul
101 -> Deep
```

All are valid.

---

# 28. `multimap` vs `unordered_multimap`

| Feature | `multimap` | `unordered_multimap` |
|---|---|---|
| Header | `<map>` | `<unordered_map>` |
| Duplicate keys | Yes | Yes |
| Sorted | Yes | No |
| Typical structure | Balanced tree | Hash table |
| Search | O(log n) | O(1) average |
| Insert | O(log n) | O(1) average |
| Erase by key | O(log n + k) | O(k) average |
| `lower_bound()` | Yes | No |
| `upper_bound()` | Yes | No |
| Ordered iteration | Yes | No |
| Custom ordering | Yes | No |
| Hash required | No | Yes |

### Choose `multimap` when:

```text
Need duplicate keys
        +
Need sorted keys
        +
Need ordered lookup
```

### Choose `unordered_multimap` when:

```text
Need duplicate keys
        +
Ordering is not required
        +
Average O(1) lookup is desirable
```

---

# 29. `insert()` vs `emplace()` vs `try_emplace()`

## `insert()`

```cpp
m.insert({101, "Amit"});
```

Good when you already have a pair or object to insert.

Duplicate keys are allowed.

---

## `emplace()`

```cpp
m.emplace(101, "Amit");
```

Constructs the element in place.

Multiple calls with the same key insert multiple elements.

---

## `try_emplace()` — C++17

```cpp
m.try_emplace(101, "Amit");
m.try_emplace(101, "Rahul");
```

Both can be inserted because `multimap` allows duplicate keys.

The useful property is direct construction of the mapped value from the supplied arguments.

### Important difference from `map`

For `map`:

```text
Existing key
    ↓
try_emplace() does not insert
```

For `multimap`:

```text
Existing equivalent key
    ↓
try_emplace() can still insert another element
```

because duplicate keys are allowed.

---

# 30. Complete Basic Example

```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    multimap<int, string> students;

    students.insert({101, "Amit"});
    students.insert({101, "Rahul"});
    students.insert({102, "Deep"});
    students.insert({101, "Rohit"});

    cout << "Students:\n";

    for (const auto& item : students) {
        cout << item.first
             << " -> "
             << item.second
             << endl;
    }

    cout << "\nTotal elements: "
         << students.size()
         << endl;

    cout << "Count for key 101: "
         << students.count(101)
         << endl;

    students.erase(102);

    cout << "\nAfter erase(102):\n";

    for (const auto& item : students) {
        cout << item.first
             << " -> "
             << item.second
             << endl;
    }

    return 0;
}
```

Possible output:

```text
Students:
101 -> Amit
101 -> Rahul
101 -> Rohit
102 -> Deep

Total elements: 4
Count for key 101: 3

After erase(102):
101 -> Amit
101 -> Rahul
101 -> Rohit
```

---

# 31. Example Using `insert()`

```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    multimap<int, string> employees;

    employees.insert({101, "Amit"});
    employees.insert({101, "Rahul"});
    employees.insert({102, "Deep"});

    for (const auto& item : employees) {
        cout << item.first
             << " -> "
             << item.second
             << endl;
    }
}
```

Output:

```text
101 -> Amit
101 -> Rahul
102 -> Deep
```

---

# 32. Example Using `find()`

```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    multimap<int, string> employees = {
        {101, "Amit"},
        {101, "Rahul"},
        {102, "Deep"}
    };

    auto it = employees.find(101);

    if (it != employees.end()) {
        cout << "Found: "
             << it->first
             << " -> "
             << it->second
             << endl;
    }
}
```

`find()` gives an iterator to one matching element.

If you need **all** values for `101`, use:

```cpp
equal_range()
```

---

# 33. Example Using `count()`

```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    multimap<int, string> employees = {
        {101, "Amit"},
        {101, "Rahul"},
        {101, "Deep"},
        {102, "Rohit"}
    };

    cout << employees.count(101);
}
```

Output:

```text
3
```

Because there are three elements with key `101`.

---

# 34. Example Using `lower_bound()`

```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    multimap<int, string> m = {
        {10, "Ten"},
        {20, "Twenty A"},
        {20, "Twenty B"},
        {30, "Thirty"}
    };

    auto it = m.lower_bound(20);

    if (it != m.end()) {
        cout << it->first
             << " -> "
             << it->second;
    }
}
```

Output:

```text
20 -> Twenty A
```

`lower_bound(20)` points to the first element whose key is:

```text
>= 20
```

---

# 35. Example Using `upper_bound()`

```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    multimap<int, string> m = {
        {10, "Ten"},
        {20, "Twenty A"},
        {20, "Twenty B"},
        {30, "Thirty"}
    };

    auto it = m.upper_bound(20);

    if (it != m.end()) {
        cout << it->first
             << " -> "
             << it->second;
    }
}
```

Output:

```text
30 -> Thirty
```

`upper_bound(20)` points to the first element whose key is:

```text
> 20
```

---

# 36. Example Using `equal_range()`

This is one of the most important `multimap` examples.

```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    multimap<int, string> employees = {
        {101, "Amit"},
        {101, "Rahul"},
        {101, "Deep"},
        {102, "Rohit"}
    };

    auto range = employees.equal_range(101);

    for (auto it = range.first;
         it != range.second;
         ++it) {

        cout << it->first
             << " -> "
             << it->second
             << endl;
    }
}
```

Output:

```text
101 -> Amit
101 -> Rahul
101 -> Deep
```

### Concept

```text
equal_range(101)
       |
       +---- first
       |       ↓
       |     101 -> Amit
       |     101 -> Rahul
       |     101 -> Deep
       |       ↑
       +---- second
```

`first` points to the beginning of the matching range.

`second` points one position after the matching range.

---

# 37. Example Using Descending Order

```cpp
#include <iostream>
#include <map>
#include <functional>
#include <string>

using namespace std;

int main() {

    multimap<int, string, greater<int>> m;

    m.insert({10, "Ten"});
    m.insert({30, "Thirty"});
    m.insert({20, "Twenty A"});
    m.insert({20, "Twenty B"});

    for (const auto& item : m) {
        cout << item.first
             << " -> "
             << item.second
             << endl;
    }
}
```

Output:

```text
30 -> Thirty
20 -> Twenty A
20 -> Twenty B
10 -> Ten
```

---

# 38. Example with Custom Comparator

```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Compare {

    bool operator()(int a, int b) const {
        return a > b;
    }

};

int main() {

    multimap<int, string, Compare> m;

    m.insert({10, "Ten"});
    m.insert({20, "Twenty A"});
    m.insert({20, "Twenty B"});
    m.insert({30, "Thirty"});

    for (const auto& item : m) {
        cout << item.first
             << " -> "
             << item.second
             << endl;
    }
}
```

Output:

```text
30 -> Thirty
20 -> Twenty A
20 -> Twenty B
10 -> Ten
```

The comparator controls the ordering of keys.

---

# 39. Example with Custom Object

```cpp
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Student {

public:

    int id;
    string name;

    bool operator<(const Student& other) const {
        return id < other.id;
    }
};

int main() {

    multimap<Student, int> marks;

    Student s1{101, "Amit"};
    Student s2{101, "Rahul"};
    Student s3{102, "Deep"};

    marks.insert({s1, 85});
    marks.insert({s2, 90});
    marks.insert({s3, 95});

    for (const auto& item : marks) {

        cout << item.first.id
             << " "
             << item.first.name
             << " -> "
             << item.second
             << endl;
    }
}
```

Possible output:

```text
101 Amit -> 85
101 Rahul -> 90
102 Deep -> 95
```

The custom key type must have a valid ordering.

---

# 40. Advantages

- Allows duplicate keys.
- Maintains keys in sorted order.
- Supports efficient ordered lookup.
- Search is generally O(log n).
- Insertion is generally O(log n).
- Supports:
  - `lower_bound()`
  - `upper_bound()`
  - `equal_range()`
- Useful when one key can have multiple associated values.
- Supports custom comparators.
- Supports node extraction.
- Supports merging.
- Does not require manual sorting.

### Common use cases

```text
Student ID -> multiple records
Employee ID -> multiple assignments
Category -> multiple products
Department -> multiple employees
Customer ID -> multiple transactions
Date -> multiple events
```

---

# 41. Disadvantages

- No random access by index.
- Typically slower than average O(1) `unordered_multimap` lookup.
- More memory overhead than contiguous containers.
- Tree nodes have poorer cache locality.
- Keys must have a valid ordering.
- Iteration is ordered, which may be unnecessary overhead if ordering is not required.
- `operator[]` and `at()` are not available.
- Removing all values for a key may remove multiple elements unexpectedly if `erase(key)` is used without considering duplicates.

---

# 42. Common Mistakes

## Mistake 1: Expecting unique keys

```cpp
multimap<int, string> m;

m.insert({1, "A"});
m.insert({1, "B"});
```

Both entries exist.

Result:

```text
1 -> A
1 -> B
```

---

## Mistake 2: Trying to use `operator[]`

This is invalid:

```cpp
m[101] = "A";   // Error
```

`multimap` does not provide `operator[]`.

Use:

```cpp
m.insert({101, "A"});
```

or:

```cpp
m.emplace(101, "A");
```

---

## Mistake 3: Trying to use `at()`

This is also invalid:

```cpp
m.at(101);   // Error
```

Use:

```cpp
m.find(101);
```

or:

```cpp
m.equal_range(101);
```

---

## Mistake 4: Assuming `find()` returns all matching elements

For:

```text
101 -> A
101 -> B
101 -> C
```

this:

```cpp
auto it = m.find(101);
```

does not give all three elements.

Use:

```cpp
auto range = m.equal_range(101);
```

and iterate through the range.

---

## Mistake 5: Using `erase(key)` when only one element should be removed

```cpp
m.erase(101);
```

removes **all elements with key `101`**.

If you want to remove one specific element:

```cpp
auto it = m.find(101);

if (it != m.end()) {
    m.erase(it);
}
```

---

## Mistake 6: Dereferencing `end()`

Do not write:

```cpp
cout << m.end()->first;
```

Correct:

```cpp
auto it = m.find(101);

if (it != m.end()) {
    cout << it->first;
}
```

---

## Mistake 7: Modifying the key directly

This is invalid:

```cpp
it->first = 200;
```

Map and multimap elements use:

```cpp
pair<const Key, T>
```

Use `extract()` in C++17 if you need to change a key.

---

# 43. Common Interview Questions

## Q1. What is `std::multimap`?

`std::multimap` is an ordered associative STL container that stores key-value pairs and allows multiple elements with equivalent keys.

---

## Q2. Does `multimap` allow duplicate keys?

Yes.

Example:

```cpp
m.insert({1, "A"});
m.insert({1, "B"});
m.insert({1, "C"});
```

All three elements can exist.

---

## Q3. Is `multimap` sorted?

Yes.

Keys are sorted according to the comparator.

By default:

```cpp
std::less<Key>
```

is used.

---

## Q4. What is the difference between `map` and `multimap`?

```text
map
    ↓
Unique keys

multimap
    ↓
Duplicate keys allowed
```

---

## Q5. Why does `multimap` not have `operator[]`?

Because one key can have multiple values.

For example:

```text
101 -> A
101 -> B
101 -> C
```

There is no single mapped value that `operator[]` could naturally return.

---

## Q6. Does `multimap` have `at()`?

No.

Use lookup functions such as:

```cpp
find()
lower_bound()
upper_bound()
equal_range()
```

---

## Q7. What does `count()` return for a multimap?

It returns the number of elements with the specified key.

Example:

```cpp
multimap<int, string> m = {
    {1, "A"},
    {1, "B"},
    {1, "C"}
};

m.count(1);
```

Returns:

```text
3
```

---

## Q8. What does `find()` return?

It returns an iterator to an element with the specified key, or:

```cpp
m.end()
```

if no matching element exists.

For all matching elements, use:

```cpp
equal_range()
```

---

## Q9. How do you get all values for a key?

Use:

```cpp
auto range = m.equal_range(key);

for (auto it = range.first;
     it != range.second;
     ++it) {

    cout << it->second;
}
```

---

## Q10. What does `erase(key)` do?

For `multimap`:

```cpp
m.erase(key);
```

removes **all elements whose key is equivalent to `key`**.

It returns the number of elements removed.

---

## Q11. How do you remove only one matching element?

Use an iterator:

```cpp
auto it = m.find(key);

if (it != m.end()) {
    m.erase(it);
}
```

---

## Q12. What is `lower_bound()`?

It returns the first element whose key is:

```text
>= target
```

---

## Q13. What is `upper_bound()`?

It returns the first element whose key is:

```text
> target
```

---

## Q14. What is `equal_range()`?

It returns the range containing all elements whose keys are equivalent to the specified key.

Conceptually:

```text
equal_range(key)
    =
lower_bound(key)
+
upper_bound(key)
```

---

## Q15. What is the complexity of searching in `multimap`?

Generally:

```text
O(log n)
```

---

## Q16. What is the complexity of `erase(key)`?

For `multimap`:

```text
O(log n + k)
```

where:

```text
k = number of elements with that key
```

---

## Q17. Can a custom object be used as a multimap key?

Yes.

The key type must have a valid ordering through:

```cpp
operator<
```

or a custom comparator.

---

## Q18. Can a multimap key be modified directly?

No.

This is invalid:

```cpp
it->first = newKey;
```

Use C++17 `extract()` if the key needs to be changed.

---

## Q19. What is the difference between `multimap` and `unordered_multimap`?

```text
multimap
    ↓
Ordered
    ↓
O(log n)

unordered_multimap
    ↓
Unordered
    ↓
O(1) average lookup
```

---

## Q20. When should you use `multimap`?

Use `multimap` when:

```text
One key can have multiple values
+
Keys must remain sorted
```

Example:

```text
Department -> Employees

IT -> Amit
IT -> Rahul
IT -> Deep
HR -> Rohit
```

---

# 44. Important C++ Version Features

| Feature | Standard |
|---|---|
| `std::multimap` | C++98 |
| `emplace()` | C++11 |
| Move construction/assignment | C++11 |
| `cbegin()` / `cend()` | C++11 |
| `try_emplace()` | C++17 |
| `extract()` | C++17 |
| `merge()` | C++17 |
| `contains()` | C++20 |
| Heterogeneous lookup with transparent comparator support | C++14 onward for applicable lookup functions; `contains()` support in C++20 |

### Important difference

`insert_or_assign()` is available for:

```cpp
std::map
```

but **not** for:

```cpp
std::multimap
```

because a multimap can contain multiple elements with the same key.

---

# 45. Summary

## What is `std::multimap`?

```cpp
multimap<Key, Value>
```

stores:

```text
Key -> Value
```

with:

```text
Duplicate keys allowed
+
Sorted keys
+
Efficient ordered lookup
```

### Main properties

```text
Duplicate keys allowed
Sorted order
Ordered associative container
Typically tree-based
O(log n) search
O(log n) insertion
O(log n + k) erase by key
No integer indexing
No operator[]
No at()
Supports custom comparator
```

### Important functions

```cpp
insert()
emplace()
try_emplace()

erase()
clear()
swap()
extract()
merge()

find()
count()
contains()

lower_bound()
upper_bound()
equal_range()

begin()
end()
rbegin()
rend()

empty()
size()
max_size()

key_comp()
value_comp()
```

### Most important concept

```text
std::multimap
       ↓
Key + Value
       ↓
Duplicate Keys Allowed
       ↓
Sorted by Key
       ↓
Balanced Tree
       ↓
O(log n) Search / Insert
```

### `map` vs `multimap`

```text
std::map
   ↓
101 -> Amit
102 -> Rahul
103 -> Deep

Same key cannot occur twice.
```

```text
std::multimap
   ↓
101 -> Amit
101 -> Rahul
101 -> Deep
102 -> Rohit

Same key can occur multiple times.
```

### Quick decision guide

```text
Need key-value pairs?
        |
        +-- No --> set / multiset / other container
        |
       Yes
        |
        +-- Need duplicate keys?
        |       |
        |       +-- No
        |       |    |
        |       |    +-- Need sorted keys? --> map
        |       |    |
        |       |    +-- No ordering needed --> unordered_map
        |       |
        |       +-- Yes
        |            |
        |            +-- Need sorted keys? --> multimap
        |            |
        |            +-- No ordering needed --> unordered_multimap
```

## Real-World Example

Suppose a company stores employee assignments:

```text
Department -> Employee
```

One department can have multiple employees:

```text
IT -> Amit
IT -> Rahul
IT -> Deep
HR -> Rohit
HR -> Priya
```

A `multimap` is a natural fit:

```cpp
multimap<string, string> employees;

employees.insert({"IT", "Amit"});
employees.insert({"IT", "Rahul"});
employees.insert({"IT", "Deep"});

employees.insert({"HR", "Rohit"});
employees.insert({"HR", "Priya"});
```

To retrieve all employees from `IT`:

```cpp
auto range = employees.equal_range("IT");

for (auto it = range.first;
     it != range.second;
     ++it) {

    cout << it->second << endl;
}
```

Output:

```text
Amit
Rahul
Deep
```

---

# One-Line Definition

> **`std::multimap` is an ordered associative STL container that stores key-value pairs, allows multiple elements with equivalent keys, and typically provides O(log n) search and insertion while maintaining keys in sorted order.**