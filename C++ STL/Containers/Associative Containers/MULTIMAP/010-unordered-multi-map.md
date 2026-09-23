# `std::unordered_multimap` in C++ STL

## Table of Contents

1.  Introduction
2.  Header File
3.  Namespace
4.  Syntax
5.  Template Parameters
6.  What is a Key-Value Pair?
7.  Internal Working
8.  Hash Function
9.  Bucket System
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
27. Unordered Multimap with Different Key and Value Types
28. Pair and `std::unordered_multimap`
29. Unordered Multimap of Custom Objects
30. Move Semantics
31. Node Handles: `extract()`
32. `merge()`
33. Comparison
34. `unordered_multimap` vs `multimap`
35. `unordered_multimap` vs `unordered_map`
36. `insert()` vs `emplace()` vs `try_emplace()`
37. `reserve()` vs `rehash()`
38. `load_factor()` vs `max_load_factor()`
39. Complete Basic Example
40. Example Using `insert()`
41. Example Using `find()`
42. Example Using `count()`
43. Example Using `contains()`
44. Example Using `equal_range()`
45. Example Using Buckets
46. Example Using Custom Hash
47. Example Using Custom Object
48. Frequency Counting
49. Advantages
50. Disadvantages
51. Common Mistakes
52. Common Interview Questions
53. Important C++ Version Features
54. Practical Usage Guide
55. Summary

------------------------------------------------------------------------

# 1. Introduction

-   `std::unordered_multimap` is an **unordered associative container**
    in the C++ STL.
-   It stores data as **key-value pairs**.
-   Unlike `std::unordered_map`, an `unordered_multimap` **allows
    duplicate keys**.
-   Elements are **not maintained in sorted key order**.
-   It is typically implemented using a **hash table**.
-   Searching, insertion, and deletion are generally **O(1) average**.
-   In the worst case, these operations can become **O(n)**.
-   Each element is represented as:

``` cpp
std::pair<const Key, T>
```

### Example

``` cpp
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    unordered_multimap<int, string> students;

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

``` text
101 -> Amit
101 -> Rahul
102 -> Deep
```

**Note:** The iteration order of an `unordered_multimap` is not
guaranteed. The displayed order is only an example.

### Important

``` cpp
unordered_multimap<int, string>
```

means:

``` text
Key   -> int
Value -> string
```

Multiple values can be associated with the same key:

``` text
101 -> Amit
101 -> Rahul
101 -> Deep
```

------------------------------------------------------------------------

# 2. Header File

Use:

``` cpp
#include <unordered_map>
```

`std::unordered_multimap` is defined in the `<unordered_map>` header.

### Complete example

``` cpp
#include <iostream>
#include <string>
#include <unordered_map>
```

------------------------------------------------------------------------

# 3. Namespace

You can use:

``` cpp
using namespace std;

unordered_multimap<int, string> students;
```

Or explicitly:

``` cpp
std::unordered_multimap<int, std::string> students;
```

Using `std::` explicitly is often preferred in larger projects and
header files.

------------------------------------------------------------------------

# 4. Syntax

``` cpp
unordered_multimap<KeyType, ValueType> name;
```

### Examples

``` cpp
unordered_multimap<int, string> students;
unordered_multimap<string, int> marks;
unordered_multimap<char, int> values;
unordered_multimap<int, double> prices;
```

### With custom hash and equality

``` cpp
unordered_multimap<
    Key,
    Value,
    Hash,
    KeyEqual
> name;
```

Example:

``` cpp
unordered_multimap<string, int, MyHash, MyEqual> m;
```

------------------------------------------------------------------------

# 5. Template Parameters

The simplified form is:

``` cpp
template<
    class Key,
    class T,
    class Hash = hash<Key>,
    class Pred = equal_to<Key>,
    class Allocator = allocator<pair<const Key, T>>
>
class unordered_multimap;
```

### Meaning

  Parameter     Meaning
  ------------- ----------------------------------------
  `Key`         Type used as the key
  `T`           Type of the mapped value
  `Hash`        Hash function used to calculate bucket
  `Pred`        Equality function used to compare keys
  `Allocator`   Controls memory allocation

Example:

``` cpp
unordered_multimap<int, string>
```

uses approximately:

``` text
Key       = int
Value     = string
Hash      = hash<int>
Equality  = equal_to<int>
```

------------------------------------------------------------------------

# 6. What is a Key-Value Pair?

An unordered multimap stores:

``` text
Key -> Value
```

The important property is:

``` text
One key
   ↓
Multiple values allowed
```

### Example

``` cpp
unordered_multimap<int, string> employees;

employees.insert({101, "Amit"});
employees.insert({101, "Rahul"});
employees.insert({101, "Deep"});
```

Conceptually:

``` text
101 -> Amit
101 -> Rahul
101 -> Deep
```

Each element contains:

``` cpp
item.first
```

for the key and:

``` cpp
item.second
```

for the value.

------------------------------------------------------------------------

# 7. Internal Working

`std::unordered_multimap` is an **unordered associative container**.

It is typically implemented using a **hash table**.

Conceptually:

``` text
                Hash Function
                     |
                     v
                  hash(key)
                     |
                     v
                Bucket Index
                     |
       +-------------+-------------+
       |             |             |
    Bucket 0       Bucket 1      Bucket 2
       |             |             |
       v             v             v
    elements      elements      elements
```

The exact implementation is library-dependent.

### Main process

When inserting:

``` cpp
m.insert({101, "Amit"});
```

conceptually:

``` text
key = 101
   ↓
hash(101)
   ↓
bucket index
   ↓
store element in that bucket
```

When searching:

``` cpp
m.find(101);
```

conceptually:

``` text
101
 ↓
hash(101)
 ↓
bucket
 ↓
compare equivalent keys
 ↓
find matching element
```

This is why lookup is **O(1) average** when the hash table is well
distributed.

------------------------------------------------------------------------

# 8. Hash Function

A hash function converts a key into a hash value.

Example:

``` cpp
std::hash<int> hasher;

size_t h = hasher(101);
```

The implementation then uses the hash value to determine an appropriate
bucket.

For standard key types, the STL provides standard hash specializations.

Example:

``` cpp
unordered_multimap<int, string> m;
```

uses:

``` cpp
std::hash<int>
```

by default.

### Important

The hash function does not need to produce unique values.

Two different keys can have the same hash value.

This is called a:

``` text
Hash collision
```

The container handles collisions internally.

------------------------------------------------------------------------

# 9. Bucket System

An unordered multimap stores elements in **buckets**.

You can inspect the bucket structure using:

``` cpp
bucket_count()
```

and:

``` cpp
bucket()
```

Example:

``` cpp
cout << m.bucket_count();
```

returns the number of buckets.

For a specific key:

``` cpp
cout << m.bucket(101);
```

returns the bucket index for key `101`.

### Bucket traversal

``` cpp
size_t b = m.bucket(101);

for (auto it = m.begin(b);
     it != m.end(b);
     ++it) {

    cout << it->first
         << " -> "
         << it->second
         << endl;
}
```

------------------------------------------------------------------------

# 10. Load Factor and Rehashing

The **load factor** represents the average number of elements per
bucket.

Formula:

``` text
load_factor =
number of elements / number of buckets
```

C++ provides:

``` cpp
m.load_factor();
```

### Example

Suppose:

``` text
elements = 10
buckets  = 5
```

Then:

``` text
load factor = 10 / 5
            = 2.0
```

------------------------------------------------------------------------

## `max_load_factor()`

Controls the maximum allowed load factor before automatic rehashing is
triggered.

``` cpp
m.max_load_factor();
```

To change it:

``` cpp
m.max_load_factor(0.7);
```

------------------------------------------------------------------------

## Rehashing

When the table needs more buckets, it can perform:

``` text
Rehash
  ↓
Create larger bucket array
  ↓
Redistribute elements
```

Rehashing can be expensive for that operation, but it helps maintain
efficient average lookup.

------------------------------------------------------------------------

# 11. Characteristics

`std::unordered_multimap` has these important characteristics:

-   Stores key-value pairs.
-   Allows duplicate keys.
-   Does not maintain sorted order.
-   Uses hashing.
-   Average search is O(1).
-   Average insertion is O(1).
-   Average erase by key is O(k), where `k` is the number of
    equivalent-key elements.
-   Worst-case operations can be O(n).
-   Supports custom hash functions.
-   Supports custom equality predicates.
-   Supports buckets.
-   Supports load-factor management.
-   Supports `find()`.
-   Supports `count()`.
-   Supports `contains()` from C++20.
-   Supports `equal_range()`.
-   Does not provide `lower_bound()`.
-   Does not provide `upper_bound()`.
-   `operator[]` is **not available**.
-   `at()` is **not available**.
-   Supports node handles and merging from C++17.

------------------------------------------------------------------------

# 12. Memory Layout

Suppose:

``` cpp
unordered_multimap<int, string> m;

m.insert({20, "A"});
m.insert({10, "B"});
m.insert({20, "C"});
```

Conceptually:

``` text
Bucket 0
   |
   +--> elements

Bucket 1
   |
   +--> 10 -> "B"

Bucket 2
   |
   +--> 20 -> "A"
   +--> 20 -> "C"

Bucket 3
   |
   +--> elements
```

The exact bucket numbers and node arrangement are
implementation-dependent.

A typical hash-table implementation has:

``` text
Bucket array
     |
     +--> node
     +--> node
     +--> node
```

A node generally contains information such as:

``` text
--------------------------------
Key
Value
Hash-table linkage
--------------------------------
```

The exact representation is implementation-specific.

------------------------------------------------------------------------

# 13. Time Complexity

Let:

``` text
n = total number of elements
k = number of elements with the specified key
```

  Operation                    Average   Worst Case
  ------------------- ---------------- ------------
  `insert()`                      O(1)         O(n)
  `emplace()`                     O(1)         O(n)
  `try_emplace()`                 O(1)         O(n)
  `find()`                        O(1)         O(n)
  `count()`                       O(k)         O(n)
  `contains()`                    O(1)         O(n)
  `erase(key)`                    O(k)         O(n)
  `erase(iterator)`     Amortized O(1)         O(n)
  `equal_range()`                 O(k)         O(n)
  `size()`                        O(1)         O(1)
  `empty()`                       O(1)         O(1)
  `clear()`                       O(n)         O(n)
  `bucket()`                      O(1)         O(1)
  `bucket_count()`                O(1)         O(1)
  `load_factor()`                 O(1)         O(1)

### Important

For a good hash distribution:

``` text
Search       -> O(1) average
Insertion    -> O(1) average
```

But:

``` text
Worst case -> O(n)
```

------------------------------------------------------------------------

# 14. Constructors

## 14.1 Default Constructor

``` cpp
unordered_multimap<int, string> m;
```

Creates an empty unordered multimap.

------------------------------------------------------------------------

## 14.2 Initializer List Constructor

``` cpp
unordered_multimap<int, string> m = {
    {101, "Amit"},
    {101, "Rahul"},
    {102, "Deep"}
};
```

Duplicate keys are preserved.

------------------------------------------------------------------------

## 14.3 Range Constructor

``` cpp
vector<pair<int, string>> v = {
    {1, "A"},
    {1, "B"},
    {2, "C"}
};

unordered_multimap<int, string> m(v.begin(), v.end());
```

All elements are inserted.

------------------------------------------------------------------------

## 14.4 Copy Constructor

``` cpp
unordered_multimap<int, string> m1 = {
    {1, "A"},
    {1, "B"}
};

unordered_multimap<int, string> m2(m1);
```

Creates a copy.

------------------------------------------------------------------------

## 14.5 Move Constructor

``` cpp
unordered_multimap<int, string> m1 = {
    {1, "A"},
    {1, "B"}
};

unordered_multimap<int, string> m2(std::move(m1));
```

Resources can be transferred to `m2`.

After the move:

``` text
m1 -> valid but unspecified state
m2 -> contains transferred contents
```

------------------------------------------------------------------------

# 15. Assignment Operators

## 15.1 Copy Assignment

``` cpp
m2 = m1;
```

Copies the contents.

------------------------------------------------------------------------

## 15.2 Move Assignment

``` cpp
m2 = std::move(m1);
```

Transfers resources when possible.

------------------------------------------------------------------------

## 15.3 Initializer-List Assignment

``` cpp
m = {
    {1, "A"},
    {1, "B"},
    {2, "C"}
};
```

Existing contents are replaced.

------------------------------------------------------------------------

# 16. Iterators

`unordered_multimap` provides iterators for traversing elements.

Unlike `multimap`, these iterators do **not** traverse elements in
sorted key order.

------------------------------------------------------------------------

## 16.1 `begin()`

``` cpp
auto it = m.begin();
```

Returns an iterator to an element.

The specific element is not a sorted first element.

------------------------------------------------------------------------

## 16.2 `end()`

``` cpp
auto it = m.end();
```

Represents the end of the container.

Do not dereference it.

------------------------------------------------------------------------

## 16.3 Traversing

``` cpp
for (auto it = m.begin();
     it != m.end();
     ++it) {

    cout << it->first
         << " -> "
         << it->second
         << endl;
}
```

The order is unspecified.

------------------------------------------------------------------------

## 16.4 Range-Based Loop

``` cpp
for (const auto& item : m) {
    cout << item.first
         << " -> "
         << item.second
         << endl;
}
```

This is usually the simplest way to traverse.

------------------------------------------------------------------------

## 16.5 `cbegin()` and `cend()`

``` cpp
auto it = m.cbegin();
```

and:

``` cpp
auto it = m.cend();
```

provide constant iterators.

------------------------------------------------------------------------

# 17. Capacity Functions

## 17.1 `empty()`

``` cpp
if (m.empty()) {
    cout << "Empty";
}
```

Returns:

``` text
true
false
```

------------------------------------------------------------------------

## 17.2 `size()`

Returns the total number of elements.

Example:

``` cpp
unordered_multimap<int, string> m = {
    {1, "A"},
    {1, "B"},
    {1, "C"}
};

cout << m.size();
```

Output:

``` text
3
```

It counts elements, not unique keys.

------------------------------------------------------------------------

## 17.3 `max_size()`

Returns the maximum number of elements the container can theoretically
hold, subject to implementation limitations.

``` cpp
cout << m.max_size();
```

------------------------------------------------------------------------

# 18. Element Access

Like `multimap`, `unordered_multimap` does **not** provide:

``` cpp
operator[]
```

or:

``` cpp
at()
```

### Why?

Because duplicate keys are allowed.

For example:

``` text
101 -> Amit
101 -> Rahul
101 -> Deep
```

What should:

``` cpp
m[101]
```

return?

There is no single mapped value.

Therefore use:

``` cpp
find()
count()
contains()
equal_range()
```

------------------------------------------------------------------------

# 19. Modifiers

## 19.1 `insert()`

``` cpp
m.insert({101, "Amit"});
m.insert({101, "Rahul"});
```

Both entries can be inserted.

------------------------------------------------------------------------

## 19.2 Duplicate Keys

``` cpp
unordered_multimap<int, string> m;

m.insert({1, "A"});
m.insert({1, "B"});
m.insert({1, "C"});
```

Result conceptually:

``` text
1 -> A
1 -> B
1 -> C
```

All entries are valid.

------------------------------------------------------------------------

## 19.3 Insert with Hint

``` cpp
auto hint = m.begin();

m.insert(hint, {5, "Five"});
```

For an unordered container, a hint generally provides little or no
meaningful ordering advantage because the container is hash-based.

------------------------------------------------------------------------

## 19.4 Range Insert

``` cpp
vector<pair<int, string>> v = {
    {1, "A"},
    {1, "B"},
    {2, "C"}
};

m.insert(v.begin(), v.end());
```

All elements can be inserted.

------------------------------------------------------------------------

## 19.5 `emplace()`

``` cpp
m.emplace(101, "Amit");
m.emplace(101, "Rahul");
```

Constructs elements in place.

Both entries can exist.

------------------------------------------------------------------------

## 19.6 `try_emplace()` --- C++17

``` cpp
m.try_emplace(101, "Amit");
m.try_emplace(101, "Rahul");
```

Both can be inserted because duplicate keys are allowed.

The useful property is direct construction of the mapped value from
supplied arguments.

------------------------------------------------------------------------

## 19.7 `insert_or_assign()`

**`std::unordered_multimap` does not provide `insert_or_assign()`.**

There is no single mapped element associated with a key because
duplicate keys are allowed.

To modify a particular element:

``` cpp
auto it = m.find(101);

if (it != m.end()) {
    it->second = "New Value";
}
```

------------------------------------------------------------------------

## 19.8 `erase(key)`

``` cpp
m.erase(101);
```

Removes **all elements whose keys are equivalent to `101`**.

Example:

``` cpp
unordered_multimap<int, string> m = {
    {101, "A"},
    {101, "B"},
    {102, "C"}
};

m.erase(101);
```

Result:

``` text
102 -> C
```

Return value:

``` text
number of elements erased
```

If three matching elements exist:

``` text
count = 3
```

------------------------------------------------------------------------

## 19.9 `erase(iterator)`

Removes one specific element.

``` cpp
auto it = m.find(101);

if (it != m.end()) {
    m.erase(it);
}
```

If multiple elements have key `101`, only the selected iterator's
element is removed.

------------------------------------------------------------------------

## 19.10 `erase(range)`

You can erase a range:

``` cpp
m.erase(first, last);
```

This is useful with:

``` cpp
equal_range()
```

------------------------------------------------------------------------

## 19.11 `clear()`

``` cpp
m.clear();
```

Removes all elements.

------------------------------------------------------------------------

## 19.12 `swap()`

``` cpp
m1.swap(m2);
```

Swaps the contents of two unordered multimaps.

------------------------------------------------------------------------

# 20. Lookup Functions

Lookup is especially important because duplicate keys are allowed.

------------------------------------------------------------------------

## 20.1 `find()`

Searches for a key:

``` cpp
auto it = m.find(101);
```

If found:

``` cpp
it != m.end()
```

If not found:

``` cpp
it == m.end()
```

For duplicate keys, `find()` returns one matching element.

Use:

``` cpp
equal_range()
```

to retrieve the complete equivalent-key range.

------------------------------------------------------------------------

## 20.2 `count()`

Returns the number of elements with a key.

Example:

``` cpp
unordered_multimap<int, string> m = {
    {101, "A"},
    {101, "B"},
    {101, "C"},
    {102, "D"}
};

cout << m.count(101);
```

Output:

``` text
3
```

------------------------------------------------------------------------

## 20.3 `contains()` --- C++20

Checks whether at least one element with the key exists.

``` cpp
if (m.contains(101)) {
    cout << "Key exists";
}
```

Returns:

``` text
true
false
```

It does not return the number of matching elements.

Use:

``` cpp
m.count(101);
```

for that.

------------------------------------------------------------------------

## 20.4 `equal_range()`

Returns the range of elements whose keys are equivalent to the specified
key.

Example:

``` cpp
unordered_multimap<int, string> m = {
    {101, "A"},
    {101, "B"},
    {101, "C"},
    {102, "D"}
};

auto range = m.equal_range(101);
```

Then:

``` cpp
range.first
```

is the beginning of the matching range.

And:

``` cpp
range.second
```

is one position after the matching range.

### Iterate all matching elements

``` cpp
for (auto it = range.first;
     it != range.second;
     ++it) {

    cout << it->first
         << " -> "
         << it->second
         << endl;
}
```

The order within the range is not a sorted key order.

------------------------------------------------------------------------

## 20.5 `lower_bound()` and `upper_bound()`

`std::unordered_multimap` does **not** provide:

``` cpp
lower_bound()
upper_bound()
```

These functions require an ordering relationship, which an unordered
container does not maintain.

Use:

``` cpp
find()
count()
contains()
equal_range()
```

instead.

------------------------------------------------------------------------

# 21. Bucket Interface

The bucket interface lets you inspect the hash-table structure.

## 21.1 `bucket_count()`

Returns the number of buckets.

``` cpp
cout << m.bucket_count();
```

------------------------------------------------------------------------

## 21.2 `max_bucket_count()`

Returns the maximum number of buckets supported by the container
implementation.

``` cpp
cout << m.max_bucket_count();
```

------------------------------------------------------------------------

## 21.3 `bucket(key)`

Returns the bucket index associated with a key.

``` cpp
cout << m.bucket(101);
```

------------------------------------------------------------------------

## 21.4 `bucket_size(index)`

Returns the number of elements in a bucket.

``` cpp
size_t b = m.bucket(101);

cout << m.bucket_size(b);
```

------------------------------------------------------------------------

## 21.5 `begin(bucket)`

Returns a local iterator to the beginning of a bucket.

``` cpp
auto b = m.bucket(101);

for (auto it = m.begin(b);
     it != m.end(b);
     ++it) {

    cout << it->first
         << " -> "
         << it->second
         << endl;
}
```

------------------------------------------------------------------------

## 21.6 `end(bucket)`

Returns the local end iterator for the bucket.

------------------------------------------------------------------------

## 21.7 `cbegin(bucket)` and `cend(bucket)`

Provide constant local iterators for bucket traversal.

------------------------------------------------------------------------

# 22. Hash Policy

Hash policy functions control or inspect bucket allocation.

## 22.1 `load_factor()`

``` cpp
cout << m.load_factor();
```

Formula:

``` text
load_factor =
size() / bucket_count()
```

------------------------------------------------------------------------

## 22.2 `max_load_factor()`

Gets the current maximum load factor:

``` cpp
cout << m.max_load_factor();
```

Sets it:

``` cpp
m.max_load_factor(0.7);
```

------------------------------------------------------------------------

## 22.3 `rehash()`

Requests that the container have at least a specified number of buckets.

``` cpp
m.rehash(100);
```

The implementation may choose a bucket count greater than requested.

### Important

`rehash()` changes the bucket structure and can invalidate iterators.

------------------------------------------------------------------------

## 22.4 `reserve()`

Reserves enough buckets for at least the specified number of elements
without exceeding the current maximum load factor.

``` cpp
m.reserve(1000);
```

This is useful when you know approximately how many elements will be
inserted.

### Example

``` cpp
unordered_multimap<int, string> m;

m.reserve(10000);

for (int i = 0; i < 10000; ++i) {
    m.emplace(i, "value");
}
```

This can reduce repeated rehashing.

------------------------------------------------------------------------

# 23. Observers

## 23.1 `hash_function()`

Returns the hash function object.

``` cpp
auto hasher = m.hash_function();
```

Example:

``` cpp
cout << hasher(101);
```

------------------------------------------------------------------------

## 23.2 `key_eq()`

Returns the key equality predicate.

``` cpp
auto equal = m.key_eq();
```

Example:

``` cpp
cout << equal(10, 10);
```

Output:

``` text
1
```

------------------------------------------------------------------------

# 24. Custom Hash

A custom hash function can be used when the key is a custom type or when
a specialized hash is needed.

Example:

``` cpp
struct MyHash {

    size_t operator()(int x) const {
        return std::hash<int>{}(x);
    }

};
```

Then:

``` cpp
unordered_multimap<int, string, MyHash> m;
```

------------------------------------------------------------------------

# 25. Custom Equality

You can also provide a custom key equality predicate.

Example:

``` cpp
struct MyEqual {

    bool operator()(int a, int b) const {
        return a == b;
    }

};
```

Then:

``` cpp
unordered_multimap<
    int,
    string,
    MyHash,
    MyEqual
> m;
```

------------------------------------------------------------------------

# 26. Custom Hash + Equality

When using a custom key type, you commonly provide both:

``` text
Hash
+
Equality
```

Example:

``` cpp
struct Student {

    int id;
    string name;
};

struct StudentHash {

    size_t operator()(const Student& s) const {
        return std::hash<int>{}(s.id);
    }

};

struct StudentEqual {

    bool operator()(const Student& a,
                    const Student& b) const {

        return a.id == b.id;
    }

};
```

Then:

``` cpp
unordered_multimap<
    Student,
    int,
    StudentHash,
    StudentEqual
> marks;
```

### Important hash/equality rule

If two keys are considered equivalent by the equality predicate:

``` cpp
key_equal(a, b) == true
```

then they must produce the same hash value:

``` text
hash(a) == hash(b)
```

This is an essential requirement for correct unordered-container
behavior.

------------------------------------------------------------------------

# 27. Unordered Multimap with Different Key and Value Types

Examples:

``` cpp
unordered_multimap<int, string> employees;
unordered_multimap<string, int> marks;
unordered_multimap<string, double> prices;
unordered_multimap<char, int> values;
unordered_multimap<long long, bool> flags;
```

### Example

``` cpp
unordered_multimap<string, int> marks;

marks.insert({"Amit", 85});
marks.insert({"Amit", 90});
marks.insert({"Rahul", 80});
```

Conceptually:

``` text
Amit -> 85
Amit -> 90
Rahul -> 80
```

The order is not guaranteed.

------------------------------------------------------------------------

# 28. Pair and `std::unordered_multimap`

An element is essentially:

``` cpp
pair<const Key, T>
```

Example:

``` cpp
unordered_multimap<int, string> m;

m.insert({1, "One"});
m.insert({1, "Another One"});
```

Each element contains:

``` text
first  -> key
second -> value
```

Example:

``` cpp
for (const auto& item : m) {
    cout << item.first
         << " "
         << item.second
         << endl;
}
```

------------------------------------------------------------------------

# 29. Unordered Multimap of Custom Objects

Suppose:

``` cpp
struct Student {

    int id;
    string name;
};
```

We can use it as a value:

``` cpp
unordered_multimap<int, Student> students;
```

Example:

``` cpp
students.insert({101, {101, "Amit"}});
students.insert({101, {102, "Rahul"}});
students.insert({102, {103, "Deep"}});
```

Conceptually:

``` text
101 -> Student(Amit)
101 -> Student(Rahul)
102 -> Student(Deep)
```

------------------------------------------------------------------------

## Custom Object as Key

For a custom key:

``` cpp
struct Student {

    int id;
    string name;
};
```

provide a hash:

``` cpp
struct StudentHash {

    size_t operator()(const Student& s) const {
        return std::hash<int>{}(s.id);
    }
};
```

and equality:

``` cpp
struct StudentEqual {

    bool operator()(const Student& a,
                    const Student& b) const {

        return a.id == b.id;
    }
};
```

Then:

``` cpp
unordered_multimap<
    Student,
    string,
    StudentHash,
    StudentEqual
> students;
```

------------------------------------------------------------------------

# 30. Move Semantics

Example:

``` cpp
unordered_multimap<int, string> m1 = {
    {1, "A"},
    {1, "B"},
    {2, "C"}
};

unordered_multimap<int, string> m2(std::move(m1));
```

Resources can be transferred instead of copying every element.

After the move:

``` text
m1 -> valid but unspecified state
m2 -> contains transferred contents
```

Use:

``` cpp
#include <utility>
```

for:

``` cpp
std::move()
```

------------------------------------------------------------------------

# 31. Node Handles: `extract()` --- C++17

`extract()` removes a node and returns a node handle.

Example:

``` cpp
unordered_multimap<int, string> m = {
    {1, "A"},
    {1, "B"},
    {2, "C"}
};

auto node = m.extract(m.begin());
```

The extracted element is no longer in `m`.

------------------------------------------------------------------------

## Extract by Key

``` cpp
auto node = m.extract(1);
```

For equivalent keys, this removes and returns **one matching node**.

It does not remove all elements with that key.

To remove all:

``` cpp
m.erase(1);
```

------------------------------------------------------------------------

## Changing a Key

Normally:

``` cpp
it->first = 100;   // Error
```

because the key is const.

With C++17:

``` cpp
auto node = m.extract(m.begin());

node.key() = 100;

m.insert(std::move(node));
```

The key can be changed while the node is outside the container.

------------------------------------------------------------------------

# 32. `merge()` --- C++17

`merge()` transfers nodes between compatible associative containers.

Example:

``` cpp
unordered_multimap<int, string> a = {
    {1, "A"},
    {1, "B"}
};

unordered_multimap<int, string> b = {
    {2, "C"},
    {2, "D"}
};

a.merge(b);
```

Conceptually:

``` text
a:
1 -> A
1 -> B
2 -> C
2 -> D
```

Because duplicate keys are allowed, equivalent keys in the destination
do not prevent transfer.

------------------------------------------------------------------------

# 33. Comparison

Unordered associative containers do not provide a sorted sequence
comparison in the same way ordered containers do.

For equality comparisons supported by the C++ version and library:

``` cpp
if (m1 == m2) {
    cout << "Equal";
}
```

Equality is based on equivalent key-value elements rather than iteration
order.

The exact comparison facilities available depend on the C++ standard
version and library.

------------------------------------------------------------------------

# 34. `unordered_multimap` vs `multimap`

  Feature             `multimap`      `unordered_multimap`
  ------------------- --------------- ----------------------
  Header              `<map>`         `<unordered_map>`
  Duplicate keys      Yes             Yes
  Sorted              Yes             No
  Typical structure   Balanced tree   Hash table
  Search              O(log n)        O(1) average
  Insert              O(log n)        O(1) average
  Erase by key        O(log n + k)    O(k) average
  `lower_bound()`     Yes             No
  `upper_bound()`     Yes             No
  `equal_range()`     Yes             Yes
  Ordered iteration   Yes             No
  Custom comparator   Yes             No
  Custom hash         No              Yes
  Buckets             No              Yes
  Load factor         No              Yes

### Choose `multimap` when:

``` text
Need duplicate keys
        +
Need sorted keys
        +
Need ordered range operations
```

### Choose `unordered_multimap` when:

``` text
Need duplicate keys
        +
Ordering is not required
        +
Average O(1) lookup is desirable
```

------------------------------------------------------------------------

# 35. `unordered_multimap` vs `unordered_map`

  Feature                `unordered_map`   `unordered_multimap`
  ---------------------- ----------------- ----------------------
  Duplicate keys         No                Yes
  Hash table             Yes               Yes
  Sorted                 No                No
  Average search         O(1)              O(1)
  `operator[]`           Yes               No
  `at()`                 Yes               No
  `find()`               Yes               Yes
  `count()`              0 or 1            0 or more
  `contains()`           Yes               Yes
  `equal_range()`        Yes               Yes
  `insert_or_assign()`   Yes               No
  `try_emplace()`        Yes               Yes
  `reserve()`            Yes               Yes
  `rehash()`             Yes               Yes

### Main difference

``` text
unordered_map
        ↓
Unique key
        ↓
One key -> one value
```

``` text
unordered_multimap
        ↓
Duplicate keys allowed
        ↓
One key -> multiple values
```

------------------------------------------------------------------------

# 36. `insert()` vs `emplace()` vs `try_emplace()`

## `insert()`

``` cpp
m.insert({101, "Amit"});
```

Good when you already have a pair or object.

------------------------------------------------------------------------

## `emplace()`

``` cpp
m.emplace(101, "Amit");
```

Constructs the element in place.

------------------------------------------------------------------------

## `try_emplace()` --- C++17

``` cpp
m.try_emplace(101, "Amit");
m.try_emplace(101, "Rahul");
```

Both can be inserted because duplicate keys are allowed.

The mapped value can be constructed directly from the provided
arguments.

------------------------------------------------------------------------

# 37. `reserve()` vs `rehash()`

These are important hash-table functions.

## `reserve(n)`

``` cpp
m.reserve(1000);
```

Means:

``` text
Prepare enough buckets
for at least about 1000 elements
while respecting max_load_factor().
```

Useful before many insertions.

------------------------------------------------------------------------

## `rehash(n)`

``` cpp
m.rehash(1000);
```

Requests at least the specified number of buckets.

### Difference

``` text
reserve()
    ↓
Think in terms of ELEMENTS

rehash()
    ↓
Think in terms of BUCKETS
```

Example:

``` cpp
m.reserve(10000);
```

means:

``` text
I expect around 10000 elements.
```

Whereas:

``` cpp
m.rehash(10000);
```

means:

``` text
I want at least about 10000 buckets.
```

------------------------------------------------------------------------

# 38. `load_factor()` vs `max_load_factor()`

## `load_factor()`

Current load:

``` cpp
m.load_factor();
```

Formula:

``` text
size / bucket_count
```

------------------------------------------------------------------------

## `max_load_factor()`

Maximum target load factor:

``` cpp
m.max_load_factor();
```

Change it:

``` cpp
m.max_load_factor(0.7);
```

### Concept

``` text
load_factor()
       ↓
Current state

max_load_factor()
       ↓
Configured threshold
```

------------------------------------------------------------------------

# 39. Complete Basic Example

``` cpp
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    unordered_multimap<int, string> students;

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

``` text
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

**Important:** The actual iteration order of an `unordered_multimap` is
not guaranteed.

------------------------------------------------------------------------

# 40. Example Using `insert()`

``` cpp
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    unordered_multimap<int, string> employees;

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

Possible output:

``` text
102 -> Deep
101 -> Rahul
101 -> Amit
```

The order may differ on another implementation or after a rehash.

------------------------------------------------------------------------

# 41. Example Using `find()`

``` cpp
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    unordered_multimap<int, string> employees = {
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

`find()` returns one matching element.

If you need all values for key `101`, use:

``` cpp
equal_range()
```

------------------------------------------------------------------------

# 42. Example Using `count()`

``` cpp
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    unordered_multimap<int, string> employees = {
        {101, "Amit"},
        {101, "Rahul"},
        {101, "Deep"},
        {102, "Rohit"}
    };

    cout << employees.count(101);
}
```

Output:

``` text
3
```

------------------------------------------------------------------------

# 43. Example Using `contains()`

``` cpp
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    unordered_multimap<int, string> employees = {
        {101, "Amit"},
        {101, "Rahul"},
        {102, "Deep"}
    };

    if (employees.contains(101)) {
        cout << "Key exists";
    }
}
```

Output:

``` text
Key exists
```

`contains()` only checks existence.

For the number of matching elements:

``` cpp
employees.count(101);
```

------------------------------------------------------------------------

# 44. Example Using `equal_range()`

``` cpp
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    unordered_multimap<int, string> employees = {
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

Possible output:

``` text
101 -> Deep
101 -> Rahul
101 -> Amit
```

The order is not guaranteed.

------------------------------------------------------------------------

# 45. Example Using Buckets

``` cpp
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    unordered_multimap<int, string> m;

    m.insert({101, "Amit"});
    m.insert({101, "Rahul"});
    m.insert({102, "Deep"});

    cout << "Bucket count: "
         << m.bucket_count()
         << endl;

    size_t b = m.bucket(101);

    cout << "Bucket for 101: "
         << b
         << endl;

    cout << "Bucket size: "
         << m.bucket_size(b)
         << endl;
}
```

Possible output:

``` text
Bucket count: 13
Bucket for 101: 10
Bucket size: 2
```

The actual numbers depend on the implementation and container state.

------------------------------------------------------------------------

# 46. Example Using Custom Hash

``` cpp
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct MyHash {

    size_t operator()(int x) const {
        return hash<int>{}(x);
    }

};

int main() {

    unordered_multimap<int, string, MyHash> m;

    m.insert({101, "Amit"});
    m.insert({101, "Rahul"});
    m.insert({102, "Deep"});

    for (const auto& item : m) {
        cout << item.first
             << " -> "
             << item.second
             << endl;
    }
}
```

A custom hash can be supplied as the third template parameter.

------------------------------------------------------------------------

# 47. Example Using Custom Object

``` cpp
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Student {

    int id;
    string name;
};

struct StudentHash {

    size_t operator()(const Student& s) const {
        return hash<int>{}(s.id);
    }
};

struct StudentEqual {

    bool operator()(const Student& a,
                    const Student& b) const {

        return a.id == b.id;
    }
};

int main() {

    unordered_multimap<
        Student,
        int,
        StudentHash,
        StudentEqual
    > marks;

    marks.insert({{101, "Amit"}, 85});
    marks.insert({{101, "Rahul"}, 90});
    marks.insert({{102, "Deep"}, 95});

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

The custom hash and equality predicate define how keys are stored and
compared.

------------------------------------------------------------------------

# 48. Frequency Counting

`unordered_multimap` can represent multiple records for the same key,
but if the actual goal is only to count frequencies, an `unordered_map`
is usually simpler.

Example with `unordered_map`:

``` cpp
unordered_map<int, int> frequency;

frequency[10]++;
frequency[10]++;
frequency[20]++;
```

Result:

``` text
10 -> 2
20 -> 1
```

With `unordered_multimap`, you would instead store separate entries:

``` cpp
unordered_multimap<int, string> records;

records.insert({10, "A"});
records.insert({10, "B"});
records.insert({20, "C"});
```

Use `unordered_multimap` when you need the **individual values**, not
just the count.

------------------------------------------------------------------------

# 49. Advantages

-   Allows duplicate keys.
-   Average O(1) lookup.
-   Average O(1) insertion.
-   Average O(1) search.
-   Does not require keys to be sortable.
-   Supports custom hash functions.
-   Supports custom equality predicates.
-   Useful for grouping multiple values by a key.
-   Supports buckets and hash-policy controls.
-   Supports `equal_range()`.
-   Supports node extraction.
-   Supports merging.
-   Can be faster than tree-based associative containers when ordering
    is unnecessary.

### Common use cases

``` text
Department -> Employees
Customer ID -> Transactions
Category -> Products
IP Address -> Multiple Records
Tag -> Documents
User ID -> Sessions
Key -> Multiple Events
```

------------------------------------------------------------------------

# 50. Disadvantages

-   No sorted order.
-   No `lower_bound()`.
-   No `upper_bound()`.
-   No random access by index.
-   No `operator[]`.
-   No `at()`.
-   Worst-case lookup can be O(n).
-   Hash quality affects performance.
-   Rehashing can be expensive.
-   Bucket memory overhead can be significant.
-   Iteration order can change after rehashing.
-   Not appropriate when ordered traversal is required.

------------------------------------------------------------------------

# 51. Common Mistakes

## Mistake 1: Assuming iteration is sorted

This is wrong:

``` text
10
20
30
```

is not guaranteed.

`unordered_multimap` has no sorted iteration order.

------------------------------------------------------------------------

## Mistake 2: Expecting duplicate keys to be rejected

``` cpp
m.insert({1, "A"});
m.insert({1, "B"});
```

Both can exist.

------------------------------------------------------------------------

## Mistake 3: Using `operator[]`

Invalid:

``` cpp
m[101] = "A";   // Error
```

Use:

``` cpp
m.insert({101, "A"});
```

or:

``` cpp
m.emplace(101, "A");
```

------------------------------------------------------------------------

## Mistake 4: Using `at()`

Invalid:

``` cpp
m.at(101);   // Error
```

Use:

``` cpp
m.find(101);
```

or:

``` cpp
m.equal_range(101);
```

------------------------------------------------------------------------

## Mistake 5: Assuming `find()` returns all matching elements

For:

``` text
101 -> A
101 -> B
101 -> C
```

this:

``` cpp
auto it = m.find(101);
```

returns one matching element.

Use:

``` cpp
auto range = m.equal_range(101);
```

for all equivalent-key elements.

------------------------------------------------------------------------

## Mistake 6: Using `erase(key)` when only one element should be removed

``` cpp
m.erase(101);
```

removes all elements with key `101`.

To remove one:

``` cpp
auto it = m.find(101);

if (it != m.end()) {
    m.erase(it);
}
```

------------------------------------------------------------------------

## Mistake 7: Forgetting hash/equality consistency

If:

``` cpp
key_equal(a, b)
```

is true, then:

``` text
hash(a) == hash(b)
```

must also hold.

------------------------------------------------------------------------

## Mistake 8: Ignoring rehashing

Insertion can trigger rehashing.

After rehashing:

``` text
bucket placement changes
```

and iterators can be invalidated.

Do not assume bucket positions remain stable after operations that may
rehash.

------------------------------------------------------------------------

# 52. Common Interview Questions

## Q1. What is `std::unordered_multimap`?

It is an unordered associative STL container that stores key-value pairs
and allows multiple elements with equivalent keys.

------------------------------------------------------------------------

## Q2. Does `unordered_multimap` allow duplicate keys?

Yes.

``` cpp
m.insert({1, "A"});
m.insert({1, "B"});
```

Both are valid.

------------------------------------------------------------------------

## Q3. Is `unordered_multimap` sorted?

No.

The iteration order is not sorted by key.

------------------------------------------------------------------------

## Q4. What data structure is typically used internally?

A hash table.

------------------------------------------------------------------------

## Q5. What is the average search complexity?

``` text
O(1)
```

------------------------------------------------------------------------

## Q6. What is the worst-case search complexity?

``` text
O(n)
```

A poor hash distribution or many collisions can cause this.

------------------------------------------------------------------------

## Q7. Does `unordered_multimap` have `operator[]`?

No.

------------------------------------------------------------------------

## Q8. Does `unordered_multimap` have `at()`?

No.

------------------------------------------------------------------------

## Q9. Why are `operator[]` and `at()` unavailable?

Because one key can have multiple values.

There is no unique mapped value to return.

------------------------------------------------------------------------

## Q10. How do you find one element?

Use:

``` cpp
auto it = m.find(key);
```

------------------------------------------------------------------------

## Q11. How do you find all elements for a key?

Use:

``` cpp
auto range = m.equal_range(key);

for (auto it = range.first;
     it != range.second;
     ++it) {

    cout << it->second;
}
```

------------------------------------------------------------------------

## Q12. What does `count()` return?

The number of elements with an equivalent key.

``` cpp
m.count(key);
```

------------------------------------------------------------------------

## Q13. What does `contains()` do?

Checks whether at least one equivalent key exists.

``` cpp
m.contains(key);
```

Available from C++20.

------------------------------------------------------------------------

## Q14. Does `unordered_multimap` provide `lower_bound()`?

No.

------------------------------------------------------------------------

## Q15. Does `unordered_multimap` provide `upper_bound()`?

No.

------------------------------------------------------------------------

## Q16. What is the difference between `multimap` and `unordered_multimap`?

``` text
multimap
    ↓
Ordered
    ↓
O(log n)
```

``` text
unordered_multimap
    ↓
Unordered
    ↓
O(1) average
```

------------------------------------------------------------------------

## Q17. What is the difference between `unordered_map` and `unordered_multimap`?

``` text
unordered_map
    ↓
Unique keys
```

``` text
unordered_multimap
    ↓
Duplicate keys allowed
```

------------------------------------------------------------------------

## Q18. What is a bucket?

A bucket is a position or group in the hash table where elements whose
hashes map to that bucket are stored.

------------------------------------------------------------------------

## Q19. What is load factor?

``` text
load_factor =
number of elements / number of buckets
```

------------------------------------------------------------------------

## Q20. What is `reserve()` used for?

To prepare the hash table for approximately a specified number of
elements and reduce unnecessary rehashing.

------------------------------------------------------------------------

## Q21. What is `rehash()` used for?

To request a specified minimum number of buckets.

------------------------------------------------------------------------

## Q22. What is a hash collision?

When different keys produce the same bucket location or hash-derived
bucket index.

------------------------------------------------------------------------

## Q23. Can a custom object be used as a key?

Yes, if an appropriate hash function and equality predicate are
provided.

------------------------------------------------------------------------

## Q24. What is the hash/equality rule?

If:

``` cpp
key_equal(a, b) == true
```

then:

``` text
hash(a) == hash(b)
```

must hold.

------------------------------------------------------------------------

## Q25. What does `erase(key)` do?

It removes all elements whose keys are equivalent to the specified key.

------------------------------------------------------------------------

## Q26. How do you erase only one matching element?

Use an iterator:

``` cpp
auto it = m.find(key);

if (it != m.end()) {
    m.erase(it);
}
```

------------------------------------------------------------------------

## Q27. Can the key be modified directly?

No.

``` cpp
it->first = 100;   // Error
```

Use `extract()` in C++17.

------------------------------------------------------------------------

## Q28. What is `merge()`?

It transfers nodes from one compatible unordered associative container
to another.

------------------------------------------------------------------------

## Q29. When should you use `unordered_multimap`?

Use it when:

``` text
One key can have multiple values
+
Ordering is not required
+
Average O(1) lookup is useful
```

------------------------------------------------------------------------

# 53. Important C++ Version Features

  Feature                                                       Standard
  ------------------------------------------------------------- ----------
  `std::unordered_multimap`                                     C++11
  `emplace()`                                                   C++11
  Move construction/assignment                                  C++11
  `cbegin()` / `cend()`                                         C++11
  `reserve()`                                                   C++11
  `rehash()`                                                    C++11
  Bucket interface                                              C++11
  `try_emplace()`                                               C++17
  `extract()`                                                   C++17
  `merge()`                                                     C++17
  `contains()`                                                  C++20
  Heterogeneous lookup with transparent hash/equality support   C++20

### Important difference

`insert_or_assign()` is available for:

``` cpp
std::unordered_map
```

but **not** for:

``` cpp
std::unordered_multimap
```

because duplicate keys are allowed.

------------------------------------------------------------------------

# 54. Practical Usage Guide

Use:

``` cpp
unordered_multimap<Key, Value>
```

when the relationship is:

``` text
One Key
   ↓
Multiple Values
```

and:

``` text
Ordering is NOT important
```

### Example

``` text
Customer ID -> Transactions
```

Data:

``` text
1001 -> Transaction A
1001 -> Transaction B
1001 -> Transaction C
1002 -> Transaction D
```

Use:

``` cpp
unordered_multimap<int, string> transactions;

transactions.insert({1001, "Transaction A"});
transactions.insert({1001, "Transaction B"});
transactions.insert({1001, "Transaction C"});
transactions.insert({1002, "Transaction D"});
```

To retrieve all transactions:

``` cpp
auto range = transactions.equal_range(1001);

for (auto it = range.first;
     it != range.second;
     ++it) {

    cout << it->second << endl;
}
```

------------------------------------------------------------------------

# 55. Summary

## What is `std::unordered_multimap`?

``` cpp
unordered_multimap<Key, Value>
```

stores:

``` text
Key -> Value
```

with:

``` text
Duplicate keys allowed
+
No sorted order
+
Hash-table based lookup
+
O(1) average search
```

### Main properties

``` text
Duplicate keys allowed
Unordered
Hash table
O(1) average search
O(1) average insertion
O(n) worst-case search
No integer indexing
No operator[]
No at()
Supports custom hash
Supports custom equality
Supports buckets
Supports load factor
Supports reserve()
Supports rehash()
Supports equal_range()
```

### Important functions

``` cpp
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
equal_range()

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
reserve()
rehash()

hash_function()
key_eq()
```

### Most important concept

``` text
std::unordered_multimap
          ↓
     Key + Value
          ↓
  Duplicate Keys Allowed
          ↓
      Hash Table
          ↓
   No Sorted Ordering
          ↓
 O(1) Average Search/Insert
```

### `multimap` vs `unordered_multimap`

``` text
std::multimap
      ↓
Duplicate keys
      +
Sorted keys
      +
O(log n)
```

``` text
std::unordered_multimap
      ↓
Duplicate keys
      +
No sorted order
      +
O(1) average
```

### `unordered_map` vs `unordered_multimap`

``` text
std::unordered_map
      ↓
Unique key
      ↓
One key -> one value
```

``` text
std::unordered_multimap
      ↓
Duplicate keys
      ↓
One key -> multiple values
```

### Quick decision guide

``` text
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

Suppose a system stores multiple transactions for each customer:

``` text
Customer ID -> Transaction
```

``` text
1001 -> TXN001
1001 -> TXN002
1001 -> TXN003
1002 -> TXN004
```

A natural representation is:

``` cpp
unordered_multimap<int, string> transactions;

transactions.insert({1001, "TXN001"});
transactions.insert({1001, "TXN002"});
transactions.insert({1001, "TXN003"});
transactions.insert({1002, "TXN004"});
```

Retrieve all transactions for customer `1001`:

``` cpp
auto range = transactions.equal_range(1001);

for (auto it = range.first;
     it != range.second;
     ++it) {

    cout << it->second << endl;
}
```

Possible output:

``` text
TXN003
TXN002
TXN001
```

The order is not guaranteed.

------------------------------------------------------------------------

# One-Line Definition

> **`std::unordered_multimap` is an unordered associative STL container
> that stores key-value pairs, allows multiple elements with equivalent
> keys, and typically provides O(1) average search and insertion using a
> hash table, without maintaining sorted key order.**
