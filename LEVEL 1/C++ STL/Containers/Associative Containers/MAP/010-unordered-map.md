# `std::unordered_map` in C++ STL — Complete Notes

## Table of Contents
1. Introduction
2. Header File
3. Namespace
4. Syntax
5. Template Parameters
6. Key-Value Pair
7. Internal Working — Hash Table
8. Hash Function
9. Bucket System
10. Load Factor and Rehashing
11. Characteristics
12. Memory Layout
13. Time Complexity
14. Constructors
15. Assignment Operators
16. Iterators
17. Capacity Functions
18. Element Access
19. Modifiers
20. Lookup Functions
21. Bucket Interface
22. Hash Policy
23. Observers
24. Custom Hash
25. Custom Equality
26. Custom Hash + Equality
27. Different Key and Value Types
28. Pair and `unordered_map`
29. Custom Object Key
30. Move Semantics
31. `extract()`
32. `merge()`
33. Comparison
34. `operator[]` vs `at()`
35. `insert()` vs `emplace()` vs `try_emplace()`
36. `insert_or_assign()`
37. `reserve()` vs `rehash()`
38. `load_factor()` vs `max_load_factor()`
39. Complete Basic Example
40. `operator[]` Example
41. `at()` Example
42. `find()` Example
43. `contains()` Example
44. `reserve()` Example
45. Custom Hash Example
46. Custom Object Key Example
47. Frequency Counting
48. Two Sum
49. `unordered_map` vs `map` vs `unordered_multimap`
50. `unordered_map` vs `unordered_set`
51. Advantages
52. Disadvantages
53. Common Mistakes
54. Interview Questions
55. C++ Version Features
56. Practical Usage Guide
57. Summary

---

# 1. Introduction

`std::unordered_map` is an **unordered associative container** that stores:

```text
Key -> Value
```

Important properties:

- Keys are unique.
- Elements are not sorted.
- Average search, insertion and deletion are O(1).
- Worst-case lookup/insertion/deletion can be O(n).
- It is typically implemented using a hash table.
- Elements are organized into buckets.
- A hash function determines where a key is stored.
- Each element has type:

```cpp
std::pair<const Key, T>
```

Example:

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> students;

    students[101] = "Amit";
    students[102] = "Rahul";
    students[103] = "Deep";

    for (const auto& item : students)
        cout << item.first << " " << item.second << endl;
}
```

Possible output:

```text
103 Deep
102 Rahul
101 Amit
```

> The exact iteration order is unspecified.

---

# 2. Header File

```cpp
#include <unordered_map>
```

Typical complete header set:

```cpp
#include <iostream>
#include <unordered_map>
#include <string>
```

---

# 3. Namespace

```cpp
using namespace std;

unordered_map<int, string> m;
```

Or:

```cpp
std::unordered_map<int, std::string> m;
```

Using `std::` explicitly is often preferred in larger projects and header files.

---

# 4. Syntax

```cpp
unordered_map<KeyType, ValueType> name;
```

Examples:

```cpp
unordered_map<int, string> students;
unordered_map<string, int> ages;
unordered_map<char, int> frequency;
unordered_map<int, double> prices;
unordered_map<long long, bool> flags;
```

With custom hash and equality:

```cpp
unordered_map<Key, Value, Hash, KeyEqual> name;
```

---

# 5. Template Parameters

Simplified declaration:

```cpp
template<
    class Key,
    class T,
    class Hash = hash<Key>,
    class KeyEqual = equal_to<Key>,
    class Allocator = allocator<pair<const Key, T>>
>
class unordered_map;
```

| Parameter | Meaning |
|---|---|
| `Key` | Key type |
| `T` | Mapped value type |
| `Hash` | Hash function |
| `KeyEqual` | Key equality function |
| `Allocator` | Memory allocation policy |

Example:

```cpp
unordered_map<int, string>
```

uses approximately:

```text
Key       = int
Value     = string
Hash      = hash<int>
KeyEqual  = equal_to<int>
```

---

# 6. What is a Key-Value Pair?

An unordered map stores:

```text
Key -> Value
```

Example:

```cpp
unordered_map<int, string> employee;

employee[101] = "Amit";
employee[102] = "Rahul";
employee[103] = "Deep";
```

Conceptually:

```text
101 -> Amit
102 -> Rahul
103 -> Deep
```

Each element is:

```cpp
pair<const int, string>
```

Access:

```cpp
item.first
item.second
```

Example:

```cpp
for (const auto& item : employee) {
    cout << item.first << " " << item.second << endl;
}
```

---

# 7. Internal Working — Hash Table

Typical conceptual flow:

```text
Key
 ↓
Hash Function
 ↓
Hash Value
 ↓
Bucket Selection
 ↓
Bucket
 ↓
Element
```

Example:

```cpp
unordered_map<int, string> m;
m[25] = "A";
```

Conceptually:

```text
25
 |
hash<int>(25)
 |
bucket
 |
25 -> "A"
```

The C++ standard specifies behavior and complexity requirements; it does not require one particular internal data structure. Hash tables are the normal implementation model.

---

# 8. Hash Function

A hash function converts a key into a hash value.

```cpp
#include <functional>
#include <iostream>
using namespace std;

int main() {
    hash<int> h;
    cout << h(42);
}
```

The exact numeric result is implementation-dependent.

Conceptually:

```text
Key
 ↓
Hash function
 ↓
Hash value
 ↓
Bucket
```

Different keys can produce the same bucket. This is a **collision**.

Important requirement:

```text
If two keys are equivalent,
their hash values must be equal.
```

The reverse is not required.

---

# 9. Bucket System

Conceptually:

```text
Bucket 0 -> node
Bucket 1 -> node -> node
Bucket 2 -> empty
Bucket 3 -> node
Bucket 4 -> node
```

Several keys can be placed in the same bucket.

The container manages:

- bucket allocation
- hashing
- collisions
- rehashing

You normally do not manage these manually.

---

# 10. Load Factor and Rehashing

## Load Factor

Approximately:

```text
number of elements / number of buckets
```

Access:

```cpp
m.load_factor();
```

## Maximum Load Factor

```cpp
m.max_load_factor();
```

Set it:

```cpp
m.max_load_factor(0.7f);
```

## Rehashing

When more buckets are required, the container may rehash:

```text
Old buckets
     ↓
New bucket array
     ↓
Elements redistributed
```

Rehashing can invalidate iterators.

---

# 11. Characteristics

- Key-value pairs.
- Unique keys.
- No sorted order.
- Average O(1) lookup.
- Average O(1) insertion.
- Average O(1) deletion.
- Worst-case O(n).
- Hash-based.
- Bucket-based.
- Custom hash supported.
- Custom equality supported.
- Forward iterators.
- No `lower_bound()` or `upper_bound()`.
- `operator[]` can insert.
- `at()` throws for missing keys.
- `contains()` available from C++20.
- `extract()` and `merge()` available from C++17.

---

# 12. Memory Layout

Conceptually:

```text
Bucket Array
+---------+
| Bucket 0| ---> node
+---------+
| Bucket 1| ---> node -> node
+---------+
| Bucket 2| ---> node
+---------+
| Bucket 3| ---> empty
+---------+
```

A typical node needs storage for:

```text
Key
Value
Linkage / bucket metadata
```

Exact representation is implementation-dependent.

Compared with a contiguous container, `unordered_map` usually has significant per-element and bucket-array overhead.

---

# 13. Time Complexity

| Operation | Average | Worst Case |
|---|---:|---:|
| `insert()` | O(1) | O(n) |
| `emplace()` | O(1) | O(n) |
| `try_emplace()` | O(1) | O(n) |
| `insert_or_assign()` | O(1) | O(n) |
| `erase(key)` | O(1) average | O(n) |
| `find()` | O(1) | O(n) |
| `count()` | O(1) | O(n) |
| `contains()` | O(1) | O(n) |
| `size()` | O(1) | O(1) |
| `empty()` | O(1) | O(1) |
| `clear()` | O(n) | O(n) |

Remember:

```text
unordered_map -> O(1) average
map           -> O(log n)
```

---

# 14. Constructors

## Default

```cpp
unordered_map<int, string> m;
```

## Initializer List

```cpp
unordered_map<int, string> m = {
    {101, "Amit"},
    {102, "Rahul"},
    {103, "Deep"}
};
```

Order is unspecified.

## Range

```cpp
vector<pair<int,string>> v = {
    {1,"A"}, {2,"B"}, {3,"C"}
};

unordered_map<int,string> m(v.begin(), v.end());
```

## Copy

```cpp
unordered_map<int,string> m2(m1);
```

## Move

```cpp
unordered_map<int,string> m2(std::move(m1));
```

After moving, `m1` is valid but its state is unspecified.

## Bucket Count

```cpp
unordered_map<int,string> m(100);
```

This requests an initial bucket count; it does not insert 100 elements.

---

# 15. Assignment Operators

## Copy

```cpp
m2 = m1;
```

## Move

```cpp
m2 = std::move(m1);
```

## Initializer List

```cpp
m = {
    {1,"A"},
    {2,"B"}
};
```

---

# 16. Iterators

`unordered_map` provides forward iterators.

Traversal order is unspecified.

## `begin()`

```cpp
auto it = m.begin();
```

This is not necessarily the smallest key.

## `end()`

```cpp
auto it = m.end();
```

Do not dereference it.

## Range-Based Loop

```cpp
for (const auto& item : m) {
    cout << item.first << " " << item.second << endl;
}
```

## `cbegin()` / `cend()`

```cpp
auto it = m.cbegin();
auto end = m.cend();
```

These provide constant iterators.

## No Reverse Iterators

Unlike `std::map`, `unordered_map` does not provide:

```cpp
rbegin()
rend()
```

because its iterators are forward iterators.

---

# 17. Capacity Functions

## `empty()`

```cpp
if (m.empty())
    cout << "Empty";
```

## `size()`

```cpp
cout << m.size();
```

## `max_size()`

```cpp
cout << m.max_size();
```

Returns the theoretical maximum number of elements supported by the implementation.

---

# 18. Element Access

## `operator[]`

```cpp
m[key]
```

Example:

```cpp
unordered_map<int,string> m;

m[101] = "Amit";

cout << m[101];
```

Output:

```text
Amit
```

### Missing key

```cpp
cout << m[999];
```

If `999` is absent, it is inserted with a value-initialized mapped value.

For `string`:

```text
999 -> ""
```

Therefore `operator[]` is not a pure lookup.

---

## `at()`

```cpp
cout << m.at(101);
```

If missing:

```cpp
m.at(999);
```

throws:

```cpp
std::out_of_range
```

---

# 19. Modifiers

## `insert()`

```cpp
m.insert({101, "Amit"});
```

Returns an insertion result containing an iterator and a boolean.

## Duplicate Key

```cpp
m.insert({1,"A"});
m.insert({1,"B"});
```

Result:

```text
1 -> A
```

The second insertion does not replace the existing value.

## Insert with Hint

```cpp
m.insert(m.begin(), {5,"Five"});
```

A hint can be supplied, but there is no ordered insertion position.

## Range Insert

```cpp
m.insert(v.begin(), v.end());
```

## `emplace()`

```cpp
m.emplace(101, "Amit");
```

Constructs the element in place.

## `try_emplace()` — C++17

```cpp
m.try_emplace(101, "Amit");
```

If the key exists, the mapped object is not constructed from the supplied arguments.

## `insert_or_assign()` — C++17

```cpp
m.insert_or_assign(101, "Rahul");
```

Missing key:

```text
insert
```

Existing key:

```text
assign/update
```

## `erase(key)`

```cpp
m.erase(101);
```

Returns 0 or 1 for `unordered_map`.

## `erase(iterator)`

```cpp
auto it = m.find(101);

if (it != m.end())
    m.erase(it);
```

## `erase(range)`

```cpp
m.erase(m.begin(), m.end());
```

## `clear()`

```cpp
m.clear();
```

## `swap()`

```cpp
m1.swap(m2);
```

or:

```cpp
swap(m1,m2);
```

---

# 20. Lookup Functions

## `find()`

```cpp
auto it = m.find(101);

if (it != m.end())
    cout << it->second;
```

Returns an iterator.

## `count()`

```cpp
cout << m.count(101);
```

For `unordered_map`:

```text
0 -> absent
1 -> present
```

## `contains()` — C++20

```cpp
if (m.contains(101))
    cout << "Found";
```

Returns:

```text
true / false
```

## No Ordered Lookup

These are not available:

```cpp
m.lower_bound(10);   // Error
m.upper_bound(10);   // Error
```

Because `unordered_map` has no sorted key ordering.

---

# 21. Bucket Interface

Important functions:

```cpp
bucket_count()
max_bucket_count()
bucket(key)
bucket_size(index)
```

## `bucket_count()`

```cpp
cout << m.bucket_count();
```

## `bucket(key)`

```cpp
cout << m.bucket(101);
```

## `bucket_size(index)`

```cpp
cout << m.bucket_size(0);
```

## `max_bucket_count()`

```cpp
cout << m.max_bucket_count();
```

## Iterate One Bucket

```cpp
size_t index = m.bucket(101);

for (auto it = m.begin(index);
     it != m.end(index);
     ++it) {

    cout << it->first << " " << it->second << endl;
}
```

### When to use

Bucket functions are mainly useful for:

- learning hashing;
- inspecting collisions;
- debugging;
- performance analysis.

Most application code does not need them.

---

# 22. Hash Policy

Important functions:

```cpp
load_factor()
max_load_factor()
max_load_factor(value)
rehash(n)
reserve(n)
```

## `load_factor()`

```cpp
cout << m.load_factor();
```

Approximately:

```text
size / bucket_count
```

## `max_load_factor()`

```cpp
cout << m.max_load_factor();
```

Set:

```cpp
m.max_load_factor(0.75f);
```

## `rehash(n)`

Requests at least the requested number of buckets, subject to container requirements.

```cpp
m.rehash(1000);
```

## `reserve(n)`

Requests enough buckets to accommodate at least `n` elements without exceeding the current maximum load factor.

```cpp
m.reserve(10000);
```

---

# 23. Observers

## `hash_function()`

```cpp
auto h = m.hash_function();
```

Example:

```cpp
cout << h(100);
```

Exact result is implementation-dependent.

## `key_eq()`

```cpp
auto eq = m.key_eq();

cout << eq(10,10);
```

Output:

```text
1
```

---

# 24. Custom Hash

Example using `pair<int,int>` as a key:

```cpp
#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        size_t h1 = hash<int>{}(p.first);
        size_t h2 = hash<int>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

int main() {
    unordered_map<pair<int,int>, string, PairHash> m;

    m[{1,2}] = "Point A";
    m[{3,4}] = "Point B";

    cout << m[{1,2}];
}
```

Output:

```text
Point A
```

### When to use

Use a custom hash when the key type has no suitable standard hash or when custom hashing is required.

---

# 25. Custom Equality

A custom equality predicate determines when two keys are equivalent.

Example concept:

```cpp
struct Equal {
    bool operator()(const MyKey& a,
                    const MyKey& b) const {
        return a.id == b.id;
    }
};
```

When using custom equality, the hash must satisfy:

```text
if Equal(a,b) is true
then Hash(a) == Hash(b)
```

---

# 26. Custom Hash + Equality

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct Person {
    string name;
    int age;

    bool operator==(const Person& other) const {
        return name == other.name &&
               age == other.age;
    }
};

struct PersonHash {
    size_t operator()(const Person& p) const {
        size_t h1 = hash<string>{}(p.name);
        size_t h2 = hash<int>{}(p.age);
        return h1 ^ (h2 << 1);
    }
};

int main() {
    unordered_map<Person, string, PersonHash> people;

    people[{"Amit",25}] = "Developer";
    people[{"Rahul",30}] = "Manager";

    cout << people[{"Amit",25}];
}
```

Output:

```text
Developer
```

---

# 27. Different Key and Value Types

Examples:

```cpp
unordered_map<int,string> employees;
unordered_map<string,int> ages;
unordered_map<string,double> prices;
unordered_map<char,int> frequency;
unordered_map<long long,bool> flags;
```

Example:

```cpp
unordered_map<string,int> marks;

marks["Amit"] = 85;
marks["Rahul"] = 90;
marks["Deep"] = 95;
```

Possible output:

```text
Deep -> 95
Rahul -> 90
Amit -> 85
```

Order is unspecified.

---

# 28. Pair and `std::unordered_map`

An element is:

```cpp
pair<const Key, T>
```

Example:

```cpp
unordered_map<int,string> m;

m.insert({1,"One"});
```

Access:

```cpp
for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << " " << it->second;
}
```

```text
first  -> key
second -> value
```

The key is effectively const through an iterator.

---

# 29. `unordered_map` with Custom Objects

Custom object as value:

```cpp
struct Student {
    int id;
    string name;
};

unordered_map<int,Student> students;
```

Custom object as key requires hash and equality:

```cpp
struct Student {
    int id;
    string name;

    bool operator==(const Student& other) const {
        return id == other.id;
    }
};

struct StudentHash {
    size_t operator()(const Student& s) const {
        return hash<int>{}(s.id);
    }
};
```

Then:

```cpp
unordered_map<Student,int,StudentHash> marks;
```

---

# 30. Move Semantics

```cpp
unordered_map<int,string> m1 = {
    {1,"A"},
    {2,"B"}
};

unordered_map<int,string> m2(std::move(m1));
```

Resources can be transferred instead of copied element-by-element.

After the move:

```text
m1 -> valid but unspecified
m2 -> transferred contents
```

Use:

```cpp
#include <utility>
```

---

# 31. Node Handles: `extract()` — C++17

```cpp
unordered_map<int,string> m = {
    {1,"A"},
    {2,"B"},
    {3,"C"}
};

auto node = m.extract(2);
```

Now key `2` has been removed from `m`.

The node is held by:

```cpp
node
```

## Changing a Key

This is invalid:

```cpp
it->first = 200;
```

With C++17:

```cpp
auto node = m.extract(2);

node.key() = 200;

m.insert(std::move(node));
```

This allows the key to be changed without reconstructing the mapped object.

---

# 32. `merge()` — C++17

```cpp
unordered_map<int,string> a = {
    {1,"A"},
    {2,"B"},
    {3,"C"}
};

unordered_map<int,string> b = {
    {3,"X"},
    {4,"D"},
    {5,"E"}
};

a.merge(b);
```

Logical result:

```text
a:
1 -> A
2 -> B
3 -> C
4 -> D
5 -> E

b:
3 -> X
```

Key `3` remains in `b` because `a` already contains that key.

`merge()` does not overwrite existing keys.

---

# 33. Comparison

`unordered_map` does not have a sorted ordering for keys.

Equality comparison can still compare the mappings:

```cpp
unordered_map<int,string> a = {
    {1,"A"},
    {2,"B"}
};

unordered_map<int,string> b = {
    {2,"B"},
    {1,"A"}
};

cout << (a == b);
```

Output:

```text
1
```

Different iteration order does not imply inequality.

---

# 34. `operator[]` vs `at()`

| Feature | `operator[]` | `at()` |
|---|---|---|
| Existing key | Returns reference | Returns reference |
| Missing key | Inserts | Throws |
| Exception for missing key | No | `out_of_range` |
| Good for pure lookup | No | Yes |
| Can modify value | Yes | Yes |
| Average complexity | O(1) | O(1) |

For lookup without insertion:

```cpp
m.find(key)
```

or:

```cpp
m.contains(key)
```

---

# 35. `insert()` vs `emplace()` vs `try_emplace()`

## `insert()`

```cpp
m.insert({1,"A"});
```

Use when you already have an object/pair to insert.

## `emplace()`

```cpp
m.emplace(1,"A");
```

Constructs the element in place.

## `try_emplace()` — C++17

```cpp
m.try_emplace(1,"A");
```

Constructs the mapped value from the supplied arguments only if insertion occurs.

### Summary

```text
insert
    -> insert an existing pair/object

emplace
    -> construct element in place

try_emplace
    -> construct mapped value only if key is absent
```

---

# 36. `insert_or_assign()` — C++17

Use:

```cpp
m.insert_or_assign(1,"A");
```

Behavior:

```text
Missing key
    -> insert

Existing key
    -> assign/update
```

Example:

```cpp
unordered_map<int,string> m;

m.insert_or_assign(1,"A");
m.insert_or_assign(1,"B");
```

Final:

```text
1 -> B
```

---

# 37. `reserve()` vs `rehash()`

## `reserve(n)`

Think:

```text
"I expect approximately n elements."
```

Example:

```cpp
m.reserve(10000);
```

Useful before a large known insertion.

## `rehash(n)`

Think:

```text
"I want at least n buckets."
```

Example:

```cpp
m.rehash(1000);
```

### Difference

```text
reserve(n)
    -> element capacity

rehash(n)
    -> bucket count
```

---

# 38. `load_factor()` vs `max_load_factor()`

## `load_factor()`

Current approximate:

```text
elements / buckets
```

```cpp
cout << m.load_factor();
```

## `max_load_factor()`

Current configured maximum:

```cpp
cout << m.max_load_factor();
```

Set:

```cpp
m.max_load_factor(0.75f);
```

Conceptually:

```text
Elements
   /
Buckets
   =
Load Factor
```

---

# 39. Complete Basic Example

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<int,string> employees;

    employees.insert({101,"Amit"});
    employees.insert({102,"Rahul"});
    employees.insert({103,"Deep"});

    cout << "Employees:
";

    for (const auto& item : employees) {
        cout << item.first
             << " -> "
             << item.second
             << endl;
    }

    cout << "Size: " << employees.size() << endl;

    if (employees.find(102) != employees.end())
        cout << "Employee 102 found
";

    employees.erase(102);
}
```

Possible output:

```text
Employees:
103 -> Deep
102 -> Rahul
101 -> Amit
Size: 3
Employee 102 found
```

---

# 40. Example Using `operator[]`

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int,string> employees;

    employees[101] = "Amit";
    employees[102] = "Rahul";
    employees[103] = "Deep";

    cout << employees[101];
}
```

Output:

```text
Amit
```

---

# 41. Example Using `at()`

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int,string> employees = {
        {101,"Amit"},
        {102,"Rahul"}
    };

    cout << employees.at(101) << endl;

    try {
        cout << employees.at(999);
    }
    catch (const out_of_range&) {
        cout << "Key not found";
    }
}
```

Output:

```text
Amit
Key not found
```

---

# 42. Example Using `find()`

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int,string> employees = {
        {101,"Amit"},
        {102,"Rahul"},
        {103,"Deep"}
    };

    auto it = employees.find(102);

    if (it != employees.end())
        cout << "Found: " << it->second;
}
```

Output:

```text
Found: Rahul
```

---

# 43. Example Using `contains()` — C++20

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int,string> employees = {
        {101,"Amit"},
        {102,"Rahul"}
    };

    if (employees.contains(102))
        cout << "Employee found";
}
```

Output:

```text
Employee found
```

Use `contains()` when you only need a yes/no existence check.

---

# 44. Example Using `reserve()`

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int,string> m;

    m.reserve(1000);

    for (int i = 1; i <= 1000; ++i)
        m[i] = "Value";

    cout << m.size();
}
```

Output:

```text
1000
```

### Why?

Reservation can reduce repeated rehashing when many elements are expected.

---

# 45. Example with Custom Hash

```cpp
#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>{}(p.first) ^
               (hash<int>{}(p.second) << 1);
    }
};

int main() {
    unordered_map<pair<int,int>,string,PairHash> points;

    points[{10,20}] = "Point A";
    points[{30,40}] = "Point B";

    cout << points[{10,20}];
}
```

Output:

```text
Point A
```

---

# 46. Example with Custom Object Key

```cpp
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;

    bool operator==(const Student& other) const {
        return id == other.id;
    }
};

struct StudentHash {
    size_t operator()(const Student& s) const {
        return hash<int>{}(s.id);
    }
};

int main() {
    unordered_map<Student,int,StudentHash> marks;

    marks[{101,"Amit"}] = 85;
    marks[{102,"Rahul"}] = 90;

    cout << marks[{101,"Anything"}];
}
```

Output:

```text
85
```

Why?

Equality compares only `id`, so both objects with `id == 101` are equivalent keys.

---

# 47. Frequency Counting Example

One of the most common uses:

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1,2,3,2,1,2,4};

    unordered_map<int,int> freq;

    for (int x : v)
        ++freq[x];

    for (const auto& [value,count] : freq)
        cout << value << " -> " << count << endl;
}
```

Possible output:

```text
4 -> 1
3 -> 1
2 -> 3
1 -> 2
```

### When to use

Use this pattern for:

```text
value -> frequency
```

when sorted order is unnecessary.

---

# 48. Two Sum Example

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {2,7,11,15};
    int target = 9;

    unordered_map<int,int> seen;

    for (int i = 0; i < static_cast<int>(v.size()); ++i) {
        int need = target - v[i];

        auto it = seen.find(need);

        if (it != seen.end()) {
            cout << it->second << " " << i;
            return 0;
        }

        seen[v[i]] = i;
    }
}
```

Output:

```text
0 1
```

Meaning:

```text
v[0] + v[1]
= 2 + 7
= 9
```

Average complexity:

```text
Time  -> O(n)
Space -> O(n)
```

---

# 49. `unordered_map` vs `map` vs `unordered_multimap`

| Feature | `unordered_map` | `map` | `unordered_multimap` |
|---|---|---|---|
| Header | `<unordered_map>` | `<map>` | `<unordered_map>` |
| Unique keys | Yes | Yes | No |
| Duplicate keys | No | No | Yes |
| Sorted | No | Yes | No |
| Typical structure | Hash table | Balanced tree | Hash table |
| Average search | O(1) | O(log n) | O(1) |
| Worst search | O(n) | O(log n) | O(n) |
| Average insert | O(1) | O(log n) | O(1) |
| Ordered traversal | No | Yes | No |
| `lower_bound()` | No | Yes | No |
| `upper_bound()` | No | Yes | No |
| `contains()` | C++20 | C++20 | C++20 |
| `reserve()` | Yes | No | Yes |
| `rehash()` | Yes | No | Yes |

### Choose `unordered_map`

```text
Unique keys
+
No ordering needed
+
Average O(1) lookup desired
```

### Choose `map`

```text
Unique keys
+
Sorted/ordered keys required
```

### Choose `unordered_multimap`

```text
Duplicate keys
+
No ordering required
```

---

# 50. `unordered_map` vs `unordered_set`

| Feature | `unordered_map` | `unordered_set` |
|---|---|---|
| Stores | Key-value pairs | Values |
| Example | `unordered_map<int,string>` | `unordered_set<int>` |
| Associated value | Yes | No |
| Unique | Keys | Values |
| `operator[]` | Yes | No |
| `at()` | Yes | No |
| `find()` | Yes | Yes |
| `contains()` | Yes | Yes |
| Hash-based | Yes | Yes |
| Sorted | No | No |

Use `unordered_set` when you only need unique values/membership.

Use `unordered_map` when you need:

```text
key -> associated value
```

---

# 51. Advantages

- Average O(1) lookup.
- Average O(1) insertion.
- Average O(1) deletion.
- Excellent for key-based lookup.
- Very useful for frequency counting.
- Very useful for caching.
- Very useful for membership plus associated data.
- Supports custom hash.
- Supports custom equality.
- `try_emplace()` since C++17.
- `insert_or_assign()` since C++17.
- `extract()` and `merge()` since C++17.
- `contains()` since C++20.
- `reserve()` can reduce repeated rehashing.

---

# 52. Disadvantages

- No sorted order.
- No `lower_bound()`.
- No `upper_bound()`.
- No ordered traversal.
- Worst-case operations can be O(n).
- Hash quality affects performance.
- Collisions affect performance.
- Rehashing can be expensive.
- Significant memory overhead.
- Poorer cache locality than contiguous containers.
- Iteration order is unspecified.
- Custom key types may require custom hash/equality.
- Iterator invalidation must be considered.

---

# 53. Common Mistakes

## Mistake 1: Assuming sorted order

Wrong assumption:

```cpp
unordered_map<int,string> m;
m[30] = "C";
m[10] = "A";
m[20] = "B";
```

Do not expect:

```text
10
20
30
```

Use `map` if ordering is required.

---

## Mistake 2: Assuming O(1) is guaranteed

Correct:

```text
Average expected -> O(1)
Worst case       -> O(n)
```

---

## Mistake 3: Using `operator[]` for lookup

Avoid:

```cpp
if (m[100] == "A")
```

when missing-key insertion is unwanted.

Prefer:

```cpp
m.find(100)
```

or:

```cpp
m.contains(100)
```

---

## Mistake 4: Expecting `lower_bound()`

This is invalid:

```cpp
m.lower_bound(10);
```

because unordered containers have no sorted order.

---

## Mistake 5: Depending on iteration order

Never build logic around a particular order from:

```cpp
for (auto& x : m)
```

---

## Mistake 6: Forgetting rehashing

Insertion can trigger rehashing.

Rehashing invalidates iterators.

Use:

```cpp
m.reserve(expected_size);
```

when a large size is known in advance.

---

## Mistake 7: Invalid custom hash/equality combination

If:

```cpp
key_equal(a,b) == true
```

then:

```cpp
hash(a) == hash(b)
```

must also be true.

---

## Mistake 8: Modifying the key directly

Invalid:

```cpp
it->first = 200;
```

Use:

```cpp
auto node = m.extract(oldKey);
node.key() = newKey;
m.insert(std::move(node));
```

---

## Mistake 9: Dereferencing `end()`

Invalid:

```cpp
cout << m.end()->first;
```

Correct:

```cpp
auto it = m.find(10);

if (it != m.end())
    cout << it->first;
```

---

# 54. Common Interview Questions

## Q1. What is `std::unordered_map`?

An unordered associative container storing unique key-value pairs, typically implemented using a hash table.

## Q2. Is it sorted?

No. Iteration order is unspecified.

## Q3. Does it allow duplicate keys?

No. Use `unordered_multimap` for duplicate keys.

## Q4. Average complexity of `find()`?

```text
O(1)
```

## Q5. Worst-case complexity of `find()`?

```text
O(n)
```

## Q6. Why can lookup become O(n)?

Because multiple keys can collide into the same bucket.

## Q7. What is hashing?

Converting a key into a hash value used to determine bucket placement.

## Q8. What is a collision?

Different keys being mapped to the same bucket/hash location.

## Q9. What is load factor?

Approximately:

```text
size / bucket_count
```

## Q10. What is rehashing?

Changing the bucket structure and redistributing elements.

## Q11. What is `reserve()`?

Requests enough capacity/buckets for an expected number of elements.

## Q12. Difference between `reserve()` and `rehash()`?

```text
reserve(n) -> think in elements
rehash(n)  -> think in buckets
```

## Q13. `map` vs `unordered_map`?

```text
map
    -> ordered
    -> O(log n)

unordered_map
    -> unordered
    -> O(1) average
```

## Q14. When use `unordered_map`?

When ordering is unnecessary and fast average lookup is useful.

## Q15. When use `map`?

When sorted keys or ordered range queries are needed.

## Q16. `operator[]` vs `at()`?

```text
operator[] -> inserts missing key
at()       -> throws for missing key
```

## Q17. `find()` vs `contains()`?

```text
find()    -> iterator
contains()-> bool
```

## Q18. What is `try_emplace()`?

C++17 insertion that constructs the mapped value only if the key is absent.

## Q19. What is `insert_or_assign()`?

C++17 operation that inserts a missing key or updates an existing key.

## Q20. Can a custom class be a key?

Yes, with suitable hash and equality.

## Q21. What is required of hash/equality?

Equivalent keys must produce equal hash values.

## Q22. Does unordered_map have `lower_bound()`?

No.

## Q23. Does it have reverse iterators?

No standard `rbegin()`/`rend()` interface because its iterators are forward iterators.

## Q24. Does rehash invalidate iterators?

Yes.

## Q25. Can a map key be changed?

Not through an ordinary iterator. C++17 `extract()` can be used to modify a node's key.

---

# 55. Important C++ Version Features

| Feature | Standard |
|---|---|
| `std::unordered_map` | C++11 |
| Range constructors | C++11 |
| Move construction/assignment | C++11 |
| `cbegin()` / `cend()` | C++11 |
| `emplace()` | C++11 |
| `try_emplace()` | C++17 |
| `insert_or_assign()` | C++17 |
| `extract()` | C++17 |
| `merge()` | C++17 |
| `contains()` | C++20 |
| Heterogeneous lookup with suitable transparent hash/equality | C++20 |

---

# 56. Practical Usage Guide

## Frequency Counting

```cpp
unordered_map<int,int> freq;

for (int x : v)
    ++freq[x];
```

Use for:

```text
value -> count
```

---

## Caching

```cpp
unordered_map<int,string> cache;

cache[id] = result;
```

Use for:

```text
ID -> cached result
```

---

## Fast Association

```cpp
unordered_map<string,int> userId;

userId["Amit"] = 101;
```

Use for:

```text
name -> ID
```

---

## Two Sum

```cpp
unordered_map<int,int> seen;
```

Use for:

```text
value -> index
```

or:

```text
value -> previously seen information
```

---

## Use `map` instead when ordering matters

If you need:

```text
smallest key
largest key
next key
previous key
lower_bound
upper_bound
ordered range queries
```

use:

```cpp
std::map
```

---

# 57. Summary

## Definition

```cpp
unordered_map<Key, Value>
```

stores:

```text
Key -> Value
```

with:

```text
Unique keys
+
Hash-based lookup
+
No sorted order
+
Average O(1) lookup
```

### Main properties

```text
Unique keys
No ordering
Hash table
Average O(1) search
Average O(1) insertion
Average O(1) deletion
Worst-case O(n)
Bucket-based
Custom hash
Custom equality
```

### Important functions

```cpp
insert()
emplace()
try_emplace()
insert_or_assign()

erase()
clear()
swap()
extract()
merge()

find()
count()
contains()

operator[]
at()

begin()
end()
cbegin()
cend()

empty()
size()
max_size()

bucket_count()
max_bucket_count()
bucket()
bucket_size()

load_factor()
max_load_factor()
rehash()
reserve()

hash_function()
key_eq()
```

### Core mental model

```text
std::unordered_map
        |
        v
   Key + Value
        |
        v
    Hash(Key)
        |
        v
     Bucket
        |
        v
     Element
        |
        v
Average O(1) Lookup
```

### Decision Guide

```text
Need key-value pairs?
        |
        +-- No --> unordered_set / other container
        |
       Yes
        |
        +-- Duplicate keys?
        |       |
        |       +-- Yes --> unordered_multimap
        |       |
        |       +-- No
        |
        +-- Need sorted keys?
                |
                +-- Yes --> map
                |
                +-- No --> unordered_map
```

### `map` vs `unordered_map`

```text
std::map
    |
    +-- Ordered
    +-- Unique keys
    +-- O(log n)
    +-- lower_bound()
    +-- upper_bound()
    +-- Ordered iteration

std::unordered_map
    |
    +-- Unordered
    +-- Unique keys
    +-- O(1) average
    +-- Hash table
    +-- Buckets
    +-- reserve()
    +-- rehash()
```

### One-line Definition

> **`std::unordered_map` is an unordered associative STL container that stores unique key-value pairs using hashing and provides average O(1) lookup, insertion, and deletion.**

---

# Final Complete Example

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {

    unordered_map<int,string> employees;

    // Insert
    employees.insert({101,"Amit"});
    employees.insert({102,"Rahul"});

    // Insert / update
    employees[103] = "Deep";

    // Lookup without insertion
    if (employees.contains(102))
        cout << "Employee found
";

    // Access
    cout << employees.at(101) << endl;

    // Traversal
    for (const auto& [id,name] : employees)
        cout << id << " -> " << name << endl;

    // Reserve
    employees.reserve(1000);

    // Erase
    employees.erase(102);
}
```

Possible output:

```text
Employee found
Amit
103 -> Deep
102 -> Rahul
101 -> Amit
```

> The employee iteration order is unspecified.

---

# Complete Checklist

## Core
- [x] Introduction
- [x] Header
- [x] Namespace
- [x] Syntax
- [x] Template parameters
- [x] Key-value pair
- [x] Hash-table working
- [x] Hash function
- [x] Buckets
- [x] Load factor
- [x] Rehashing
- [x] Characteristics
- [x] Memory layout
- [x] Complexity

## Constructors / Assignment
- [x] Default constructor
- [x] Initializer-list constructor
- [x] Range constructor
- [x] Copy constructor
- [x] Move constructor
- [x] Copy assignment
- [x] Move assignment
- [x] Initializer-list assignment

## Iterators / Capacity
- [x] `begin`
- [x] `end`
- [x] `cbegin`
- [x] `cend`
- [x] `empty`
- [x] `size`
- [x] `max_size`

## Access / Modifiers
- [x] `operator[]`
- [x] `at`
- [x] `insert`
- [x] `emplace`
- [x] `try_emplace`
- [x] `insert_or_assign`
- [x] `erase`
- [x] `clear`
- [x] `swap`

## Lookup
- [x] `find`
- [x] `count`
- [x] `contains`
- [x] Why `lower_bound` is unavailable

## Hash / Bucket
- [x] `bucket_count`
- [x] `max_bucket_count`
- [x] `bucket`
- [x] `bucket_size`
- [x] `load_factor`
- [x] `max_load_factor`
- [x] `reserve`
- [x] `rehash`
- [x] `hash_function`
- [x] `key_eq`

## Advanced
- [x] Custom hash
- [x] Custom equality
- [x] Custom object key
- [x] Move semantics
- [x] `extract`
- [x] `merge`
- [x] `reserve` vs `rehash`
- [x] `load_factor` vs `max_load_factor`
- [x] `map` vs `unordered_map`
- [x] `unordered_map` vs `unordered_set`
- [x] Frequency counting
- [x] Two Sum
- [x] Interview questions
- [x] Common mistakes
- [x] C++ version features
