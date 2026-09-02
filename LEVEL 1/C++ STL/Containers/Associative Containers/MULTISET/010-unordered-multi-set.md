# `std::unordered_multiset` in C++ STL

## Table of Contents

1.  Introduction
2.  Real-World Use Cases
3.  Header File
4.  Namespace
5.  Basic Syntax
6.  Template Parameters
7.  What Exactly Does `std::unordered_multiset` Store?
8.  Unordered Associative Container
9.  Internal Working
10. Hash Table Concept
11. How Duplicate Values Work
12. Hash Function
13. Equality Function
14. Buckets
15. Collisions
16. Load Factor and Rehashing
17. Characteristics
18. Memory Structure
19. Time Complexity
20. Iterator Invalidation
21. Constructors
22. Assignment Operators
23. Iterators
24. Capacity Functions
25. Element Access
26. Modifiers
27. `insert()`
28. `emplace()`
29. `erase()`
30. `clear()`
31. `swap()`
32. `extract()` --- C++17
33. `merge()` --- C++17
34. Lookup Functions
35. `find()`
36. `count()`
37. `contains()` --- C++20
38. Observers
39. `hash_function()`
40. `key_eq()`
41. Custom Hash
42. Custom Equality
43. Custom Hash + Equality
44. Custom Objects
45. `std::pair` with `unordered_multiset`
46. Move Semantics
47. Why Unordered Multiset Elements Cannot Be Modified
48. Changing an Element
49. Bucket Interface
50. Hash Policy
51. Iterator and Reference Rules
52. `unordered_multiset` vs `multiset`
53. `unordered_multiset` vs `unordered_set`
54. `unordered_multiset` vs `vector`
55. `unordered_multiset` vs `vector + sort`
56. Common Mistakes
57. Practical Examples
58. Interview Questions
59. Important C++ Version Features
60. Quick Reference Table
61. Advantages
62. Disadvantages
63. Decision Guide
64. Summary

------------------------------------------------------------------------

# 1. Introduction

`std::unordered_multiset` is an **unordered associative container**
provided by the C++ Standard Template Library (STL).

It stores:

-   Multiple elements
-   Duplicate/equivalent values
-   Without maintaining sorted order
-   Using a hash function and equality predicate

Unlike `std::unordered_set`, an `unordered_multiset` **allows duplicate
equivalent elements**.

Example:

``` cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

    unordered_multiset<int> numbers;

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

Possible output:

``` text
10 20 10 30
```

The exact iteration order is **unspecified**.

The second `10` is stored because `std::unordered_multiset` allows
duplicate values.

------------------------------------------------------------------------

# 2. Real-World Use Cases

`std::unordered_multiset` is useful when you need:

## 2.1 Duplicate values

Example:

``` text
10
10
20
20
20
30
```

All occurrences can be stored.

------------------------------------------------------------------------

## 2.2 Fast average-case membership lookup

If you frequently need to ask:

``` text
Does this value exist?
```

an `unordered_multiset` provides expected average constant-time lookup.

``` cpp
if (s.contains(50)) {
    cout << "Found";
}
```

------------------------------------------------------------------------

## 2.3 Counting occurrences

A multiset can directly maintain repeated values.

``` cpp
unordered_multiset<int> scores = {
    10,
    20,
    10,
    30,
    10
};

cout << scores.count(10);
```

Output:

``` text
3
```

------------------------------------------------------------------------

## 2.4 Dynamic duplicate tracking

Useful when values arrive continuously and you need to retain every
occurrence.

Examples:

-   Repeated event types
-   Duplicate transaction categories
-   Repeated IDs
-   Multiset-like frequency data where ordering is unnecessary

------------------------------------------------------------------------

## 2.5 Fast duplicate-aware lookup

When you need:

``` text
duplicates
+
fast average lookup
+
no sorting requirement
```

`unordered_multiset` can be a natural choice.

------------------------------------------------------------------------

# 3. Header File

Use:

``` cpp
#include <unordered_set>
```

Both:

``` cpp
std::unordered_set
```

and:

``` cpp
std::unordered_multiset
```

are provided by this header.

------------------------------------------------------------------------

# 4. Namespace

You can write:

``` cpp
using namespace std;

unordered_multiset<int> numbers;
```

Or explicitly:

``` cpp
std::unordered_multiset<int> numbers;
```

Using `std::` explicitly is often preferable in larger projects and
header files because it avoids namespace pollution.

------------------------------------------------------------------------

# 5. Basic Syntax

Basic syntax:

``` cpp
unordered_multiset<data_type> name;
```

Examples:

``` cpp
unordered_multiset<int> numbers;
unordered_multiset<string> names;
unordered_multiset<char> letters;
unordered_multiset<double> prices;
```

------------------------------------------------------------------------

## Custom hash and equality

You can provide:

``` cpp
unordered_multiset<Key, Hash, KeyEqual>
```

Example:

``` cpp
unordered_multiset<int, MyHash, MyEqual> s;
```

------------------------------------------------------------------------

# 6. Template Parameters

The simplified declaration is:

``` cpp
template<
    class Key,
    class Hash = hash<Key>,
    class Pred = equal_to<Key>,
    class Allocator = allocator<Key>
>
class unordered_multiset;
```

### Parameters

  Parameter     Meaning
  ------------- ----------------------------
  `Key`         Type of elements stored
  `Hash`        Hash function
  `Pred`        Equality predicate
  `Allocator`   Controls memory allocation

Example:

``` cpp
unordered_multiset<int>
```

Conceptually uses:

``` text
Key       = int
Hash      = hash<int>
Pred      = equal_to<int>
Allocator = allocator<int>
```

------------------------------------------------------------------------

# 7. What Exactly Does `std::unordered_multiset` Store?

An `unordered_multiset` stores **values**, not key-value pairs.

Example:

``` cpp
unordered_multiset<int> s;
```

can contain:

``` text
10
10
20
30
30
```

There is no separate:

``` text
key -> value
```

relationship.

Compare:

### `unordered_multiset`

``` cpp
unordered_multiset<int> s;
```

``` text
10
10
20
30
30
```

### `unordered_map`

``` cpp
unordered_map<int, string> m;
```

``` text
10 -> Ten
20 -> Twenty
30 -> Thirty
```

The fundamental difference is that `unordered_multiset` stores values
directly while `unordered_map` stores key-value pairs.

------------------------------------------------------------------------

# 8. Unordered Associative Container

`std::unordered_multiset` is an **unordered associative container**.

``` text
Associative
    ↓
Designed for efficient lookup by value

Unordered
    ↓
No sorted order is maintained
```

Example:

``` cpp
unordered_multiset<int> s = {
    30,
    10,
    20,
    10
};
```

Do not expect:

``` text
10 10 20 30
```

and do not expect insertion order:

``` text
30 10 20 10
```

The iteration order is unspecified and depends on the implementation and
current hash-table state.

------------------------------------------------------------------------

# 9. Internal Working

An `unordered_multiset` is hash-table based.

Conceptually:

``` text
                 Value
                   |
                   v
              Hash Function
                   |
                   v
                Hash Value
                   |
                   v
             Bucket Selection
                   |
                   v
      +------+------+------+------+
      |      |      |      |      |
   Bucket0 Bucket1 Bucket2 Bucket3
      |      |      |      |
      v      v      v      v
   values  values  values  values
```

The standard does not require one specific hash-table implementation.

The important idea is:

``` text
value
  ↓
hash
  ↓
bucket
  ↓
compare equivalent values
```

Because duplicates are allowed, multiple equivalent values can be
stored.

------------------------------------------------------------------------

# 10. Hash Table Concept

A hash table uses a hash function to convert a key into a hash value.

Conceptually:

``` cpp
hash_value = hash(value);
```

The implementation then uses the hash value to determine a bucket.

Example:

``` text
hash(42)
   ↓
hash value
   ↓
bucket index
   ↓
Bucket 5
```

A good hash function attempts to distribute values across buckets.

------------------------------------------------------------------------

# 11. How Duplicate Values Work

This is the major difference between:

``` cpp
unordered_set
```

and:

``` cpp
unordered_multiset
```

For the equality predicate, two values are equivalent when:

``` cpp
key_eq(a, b)
```

returns `true`.

In an `unordered_set`:

``` text
Equivalent value already exists
        ↓
New value is rejected
```

In an `unordered_multiset`:

``` text
Equivalent value already exists
        ↓
New value is still inserted
```

Example:

``` cpp
unordered_multiset<int> s;

s.insert(10);
s.insert(10);
s.insert(10);
```

Result contains:

``` text
10
10
10
```

------------------------------------------------------------------------

# 12. Hash Function

The default hash function is:

``` cpp
std::hash<Key>
```

Example:

``` cpp
unordered_multiset<int> s;

auto hasher = s.hash_function();

cout << hasher(10);
```

The exact numeric hash result is implementation-dependent.

The hash function should provide a reasonable distribution of values.

------------------------------------------------------------------------

# 13. Equality Function

The default equality predicate is:

``` cpp
std::equal_to<Key>
```

Example:

``` cpp
unordered_multiset<int> s;

auto equal = s.key_eq();

cout << equal(10, 10);
```

Output:

``` text
1
```

For custom objects, the equality predicate determines which values are
considered equivalent.

------------------------------------------------------------------------

# 14. Buckets

An `unordered_multiset` organizes elements into buckets.

Useful functions include:

``` cpp
bucket_count()
bucket()
bucket_size()
```

Conceptually:

``` text
Bucket 0 -> values
Bucket 1 -> values
Bucket 2 -> values
Bucket 3 -> values
...
```

Multiple values can occupy the same bucket.

------------------------------------------------------------------------

# 15. Collisions

A **collision** occurs when different values map to the same bucket.

Example:

``` text
Value A
   ↓
hash
   ↓
Bucket 5

Value B
   ↓
hash
   ↓
Bucket 5
```

Both values are stored.

The container uses its collision-handling mechanism to distinguish them.

Important:

``` text
Same bucket
    !=
Equivalent values
```

Two different values can be in the same bucket.

------------------------------------------------------------------------

# 16. Load Factor and Rehashing

The load factor is approximately:

``` text
load factor = number of elements / number of buckets
```

Check it with:

``` cpp
s.load_factor();
```

Example:

``` cpp
unordered_multiset<int> s;

s.insert(10);
s.insert(20);
s.insert(30);

cout << s.load_factor();
```

The exact result depends on the current bucket count.

------------------------------------------------------------------------

## `max_load_factor()`

You can inspect it:

``` cpp
cout << s.max_load_factor();
```

Or change it:

``` cpp
s.max_load_factor(0.7);
```

A lower maximum load factor generally means: - More buckets - Lower
average bucket occupancy - Potentially more memory usage

------------------------------------------------------------------------

## Rehashing

When the container needs to change its bucket organization, it may
rehash.

Conceptually:

``` text
Old bucket table
       ↓
New bucket table
       ↓
Redistribute elements
       ↓
New bucket organization
```

Rehashing can change iteration order.

------------------------------------------------------------------------

# 17. Characteristics

`std::unordered_multiset` has these major characteristics:

-   Stores duplicate/equivalent elements.
-   Does not maintain sorted order.
-   Uses hashing.
-   Uses an equality predicate.
-   Average expected search is O(1).
-   Average expected insertion is O(1).
-   Average expected deletion by key depends on the number of matching
    elements.
-   Worst-case lookup/insertion can be O(n).
-   Does not support random indexing.
-   Does not provide `operator[]`.
-   Provides forward iterators.
-   Supports custom hash functions.
-   Supports custom equality predicates.
-   Supports bucket inspection.
-   Supports hash-policy controls.
-   Supports node extraction since C++17.
-   Supports `merge()` since C++17.
-   Supports `contains()` since C++20.
-   Allows multiple equivalent values.

------------------------------------------------------------------------

# 18. Memory Structure

Suppose:

``` cpp
unordered_multiset<int> s;

s.insert(20);
s.insert(10);
s.insert(20);
s.insert(40);
```

Conceptually:

``` text
Bucket Table
+---------+
| Bucket0 | -> ...
| Bucket1 | -> 20 -> 20
| Bucket2 | -> ...
| Bucket3 | -> 10 -> 40
+---------+
```

The exact structure is implementation-dependent.

A hash-based node container commonly needs:

``` text
Bucket storage
Element nodes
Collision-management metadata/links
Allocator-related overhead
```

Each occurrence of an equivalent value is stored separately.

Therefore an `unordered_multiset` generally uses more memory than a
contiguous `vector`.

------------------------------------------------------------------------

# 19. Time Complexity

Let:

``` text
n = total number of elements
k = number of elements equivalent to the searched key
```

  -----------------------------------------------------------------------
  Operation                  Average / Expected                Worst Case
  ------------------- ------------------------- -------------------------
  `insert()`                               O(1)                      O(n)

  `emplace()`                              O(1)                      O(n)

  `erase(key)`                     O(k) average                      O(n)

  `erase(iterator)`          Amortized constant           O(n) in general
                                                worst-case considerations

  `find()`                                 O(1)                      O(n)

  `count()`                        O(k) average                      O(n)

  `contains()`                     O(1) average                      O(n)

  `clear()`                                O(n)                      O(n)

  `size()`                                 O(1)                      O(1)

  `empty()`                                O(1)                      O(1)

  `begin()`                                O(1)                      O(1)

  `end()`                                  O(1)                      O(1)
  -----------------------------------------------------------------------

### Important

For a multiset-like hash container, duplicate count matters.

For example:

``` text
1 occurrence
    -> find/count work on a small equivalent range

1,000,000 equivalent occurrences
    -> count() must account for all of them
```

So remember:

``` text
find()
    -> O(1) average

contains()
    -> O(1) average

count()
    -> O(k) average

erase(key)
    -> O(k) average
```

where `k` is the number of matching elements.

------------------------------------------------------------------------

# 20. Iterator Invalidation

A major point for unordered containers is rehashing.

## Insertion without rehash

Existing iterators generally remain valid if insertion does not trigger
rehash.

## Insertion with rehash

If insertion causes rehashing:

``` text
old buckets
    ↓
new buckets
    ↓
elements redistributed
```

all iterators are invalidated.

## Erasing one element

Erasing an element invalidates iterators and references to that erased
element.

## `reserve()` / `rehash()`

These can cause rehashing and therefore invalidate iterators.

## References

References to elements generally remain valid across rehashing, but
become invalid when their element is erased.

------------------------------------------------------------------------

# 21. Constructors

## 21.1 Default Constructor

``` cpp
unordered_multiset<int> s;
```

Creates an empty unordered multiset.

------------------------------------------------------------------------

## 21.2 Initializer List

``` cpp
unordered_multiset<int> s = {
    5,
    2,
    8,
    2,
    1
};
```

All values are retained:

``` text
5
2
8
2
1
```

The iteration order is unspecified.

------------------------------------------------------------------------

## 21.3 Range Constructor

``` cpp
vector<int> v = {
    10,
    20,
    10,
    30
};

unordered_multiset<int> s(
    v.begin(),
    v.end()
);
```

All four values are stored.

------------------------------------------------------------------------

## 21.4 Copy Constructor

``` cpp
unordered_multiset<int> s1 = {
    1,
    2,
    2,
    3
};

unordered_multiset<int> s2(s1);
```

`s2` becomes a copy.

------------------------------------------------------------------------

## 21.5 Move Constructor

``` cpp
unordered_multiset<int> s1 = {
    1,
    2,
    3
};

unordered_multiset<int> s2(std::move(s1));
```

Resources can be transferred.

After the move:

``` text
s1 -> valid but unspecified state
s2 -> transferred contents
```

------------------------------------------------------------------------

# 22. Assignment Operators

## 22.1 Copy Assignment

``` cpp
unordered_multiset<int> s1 = {
    1,
    2,
    3
};

unordered_multiset<int> s2;

s2 = s1;
```

------------------------------------------------------------------------

## 22.2 Move Assignment

``` cpp
s2 = std::move(s1);
```

Resources can be transferred.

------------------------------------------------------------------------

## 22.3 Initializer List Assignment

``` cpp
s = {
    10,
    20,
    20,
    30
};
```

This replaces the existing contents.

------------------------------------------------------------------------

# 23. Iterators

`unordered_multiset` provides **forward iterators**.

Unlike `multiset`, it does not provide bidirectional tree traversal.

------------------------------------------------------------------------

## 23.1 `begin()`

``` cpp
auto it = s.begin();
```

Points to an element.

It does not mean the smallest element.

------------------------------------------------------------------------

## 23.2 `end()`

``` cpp
auto it = s.end();
```

Represents one position past the last element.

Never dereference it.

------------------------------------------------------------------------

## 23.3 Forward Traversal

``` cpp
for (auto it = s.begin(); it != s.end(); ++it) {
    cout << *it << " ";
}
```

------------------------------------------------------------------------

## 23.4 Range-Based Loop

``` cpp
for (int x : s) {
    cout << x << " ";
}
```

The order is unspecified.

------------------------------------------------------------------------

## 23.5 `cbegin()` and `cend()`

``` cpp
auto it = s.cbegin();
auto end = s.cend();
```

These provide constant iterators.

------------------------------------------------------------------------

# 24. Capacity Functions

## 24.1 `empty()`

``` cpp
if (s.empty()) {
    cout << "Container is empty";
}
```

------------------------------------------------------------------------

## 24.2 `size()`

``` cpp
cout << s.size();
```

Example:

``` cpp
unordered_multiset<int> s = {
    10,
    20,
    20,
    30
};

cout << s.size();
```

Output:

``` text
4
```

Important:

`size()` counts **all occurrences**.

------------------------------------------------------------------------

## 24.3 `max_size()`

``` cpp
cout << s.max_size();
```

Returns the maximum number of elements the container can theoretically
hold, subject to implementation and system limitations.

------------------------------------------------------------------------

# 25. Element Access

`unordered_multiset` does not provide:

``` cpp
operator[]
```

or:

``` cpp
at()
```

It is not a positional-access container.

Use:

``` cpp
find()
contains()
```

for membership checks.

Example:

``` cpp
auto it = s.find(20);

if (it != s.end()) {
    cout << *it;
}
```

------------------------------------------------------------------------

# 26. Modifiers

Important modifier functions include:

``` cpp
insert()
emplace()
erase()
clear()
swap()
extract()
merge()
```

Unlike `unordered_set`, equivalent values are allowed to be inserted
multiple times.

------------------------------------------------------------------------

# 27. `insert()`

Inserts an element.

``` cpp
unordered_multiset<int> s;

s.insert(30);
s.insert(10);
s.insert(20);
s.insert(10);
```

All four occurrences are stored.

------------------------------------------------------------------------

## 27.1 Return Value

For single-element insertion:

``` cpp
auto it = s.insert(10);
```

The return value is an iterator to the inserted element.

Unlike `unordered_set`, there is no insertion-success boolean because an
equivalent element does not prevent insertion.

------------------------------------------------------------------------

## 27.2 Duplicate Insertion

``` cpp
unordered_multiset<int> s;

s.insert(10);
s.insert(10);
s.insert(10);
```

All three are stored.

------------------------------------------------------------------------

## 27.3 Insert with Hint

``` cpp
auto hint = s.begin();

s.insert(hint, 25);
```

A hint can be supplied, but unlike `multiset`, it does not represent an
ordered insertion position.

------------------------------------------------------------------------

## 27.4 Range Insert

``` cpp
vector<int> values = {
    10,
    20,
    20,
    30
};

s.insert(
    values.begin(),
    values.end()
);
```

All values are inserted.

------------------------------------------------------------------------

# 28. `emplace()`

`emplace()` constructs an element in place.

For simple values:

``` cpp
s.emplace(40);
```

For custom objects:

``` cpp
unordered_multiset<Student> students;
```

can construct objects directly in their storage.

Example:

``` cpp
students.emplace(101, "Amit");
students.emplace(101, "Rahul");
```

Both equivalent objects can be stored if the equality predicate
considers them equivalent.

------------------------------------------------------------------------

# 29. `erase()`

There are several ways to erase elements.

------------------------------------------------------------------------

## 29.1 Erase by Value

``` cpp
s.erase(20);
```

Important:

For `unordered_multiset`, this removes **all elements equivalent to
`20`**.

Example:

``` cpp
unordered_multiset<int> s = {
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

``` text
3
```

Afterward:

``` text
10 30
```

------------------------------------------------------------------------

## 29.2 Erase One Occurrence by Iterator

If you want to remove only one occurrence:

``` cpp
auto it = s.find(20);

if (it != s.end()) {
    s.erase(it);
}
```

Only that selected occurrence is erased.

------------------------------------------------------------------------

## 29.3 Erase Range

``` cpp
s.erase(s.begin(), s.end());
```

This removes all elements.

------------------------------------------------------------------------

# 30. `clear()`

Removes all elements.

``` cpp
s.clear();
```

Afterward:

``` text
s.empty() -> true
```

All occurrences are removed.

------------------------------------------------------------------------

# 31. `swap()`

Swaps the contents of two unordered multisets.

``` cpp
unordered_multiset<int> s1 = {
    1,
    2,
    2,
    3
};

unordered_multiset<int> s2 = {
    10,
    20,
    20
};

s1.swap(s2);
```

After:

``` text
s1 -> 10 20 20
s2 -> 1 2 2 3
```

------------------------------------------------------------------------

# 32. `extract()` --- C++17

`extract()` removes a node and returns a node handle.

Example:

``` cpp
unordered_multiset<int> s = {
    10,
    20,
    20,
    30
};

auto node = s.extract(s.find(20));
```

Only the selected occurrence is extracted.

The remaining container contains:

``` text
10 20 30
```

The extracted node is held by:

``` cpp
node
```

------------------------------------------------------------------------

## Extract by key

``` cpp
auto node = s.extract(20);
```

This extracts one matching node if one exists.

If several `20` values exist, only one node is extracted by a key-based
call.

------------------------------------------------------------------------

# 33. `merge()` --- C++17

`merge()` transfers nodes from another compatible unordered associative
container.

Example:

``` cpp
unordered_multiset<int> a = {
    1,
    2,
    3
};

unordered_multiset<int> b = {
    2,
    4,
    5
};

a.merge(b);
```

Result:

``` text
a:
1 2 2 3 4 5

b:
empty
```

Because `unordered_multiset` allows duplicates, the second `2` is
transferred.

------------------------------------------------------------------------

## Merge from `unordered_set`

Compatible unordered associative containers can also transfer nodes
between `unordered_set` and `unordered_multiset`.

Example:

``` cpp
unordered_set<int> source = {
    1,
    2,
    3
};

unordered_multiset<int> destination = {
    2,
    4
};

destination.merge(source);
```

The destination can accept all transferred values because duplicate
values are allowed.

------------------------------------------------------------------------

# 34. Lookup Functions

Important lookup functions include:

``` cpp
find()
count()
contains()
```

Unlike `multiset`, `unordered_multiset` does not provide:

``` cpp
lower_bound()
upper_bound()
equal_range()
```

because it does not maintain sorted order.

------------------------------------------------------------------------

# 35. `find()`

Searches for one matching element.

``` cpp
auto it = s.find(20);
```

If found:

``` cpp
it != s.end()
```

If not found:

``` cpp
it == s.end()
```

Example:

``` cpp
unordered_multiset<int> s = {
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

``` text
Found: 20
```

If multiple equivalent values exist, `find()` returns an iterator to one
matching occurrence.

------------------------------------------------------------------------

# 36. `count()`

This is especially useful for `unordered_multiset`.

``` cpp
s.count(20);
```

returns the number of elements equivalent to `20`.

Example:

``` cpp
unordered_multiset<int> s = {
    10,
    20,
    20,
    20,
    30
};

cout << s.count(20);
```

Output:

``` text
3
```

Unlike `unordered_set`, the result can be:

``` text
0
1
2
3
...
```

------------------------------------------------------------------------

# 37. `contains()` --- C++20

C++20 provides:

``` cpp
s.contains(20)
```

Example:

``` cpp
if (s.contains(20)) {
    cout << "20 exists";
}
```

Returns:

``` text
true
false
```

Important:

`contains()` only tells you whether at least one equivalent value
exists.

It does not return the number of occurrences.

For that:

``` cpp
s.count(20);
```

------------------------------------------------------------------------

# 38. Observers

`std::unordered_multiset` provides:

``` cpp
hash_function()
key_eq()
```

These expose the hash and equality objects used by the container.

------------------------------------------------------------------------

# 39. `hash_function()`

Returns the hash function object.

Example:

``` cpp
unordered_multiset<int> s;

auto hasher = s.hash_function();

cout << hasher(10);
```

The exact numeric result is implementation-dependent.

------------------------------------------------------------------------

# 40. `key_eq()`

Returns the equality predicate.

Example:

``` cpp
unordered_multiset<int> s;

auto equal = s.key_eq();

cout << equal(10, 10);
```

Output:

``` text
1
```

For custom objects, this determines equivalence.

------------------------------------------------------------------------

# 41. Custom Hash

You can provide a custom hash function.

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
unordered_multiset<int, MyHash> s;
```

The hash function should be suitable for distributing values across
buckets.

------------------------------------------------------------------------

# 42. Custom Equality

You can provide a custom equality predicate.

``` cpp
struct MyEqual {

    bool operator()(int a, int b) const {
        return a == b;
    }

};
```

Then:

``` cpp
unordered_multiset<int, MyHash, MyEqual> s;
```

------------------------------------------------------------------------

# 43. Custom Hash + Equality

For custom objects, you commonly provide both.

Example:

``` cpp
struct Student {

    int id;
    string name;

    bool operator==(const Student& other) const {
        return id == other.id;
    }
};
```

Hash:

``` cpp
struct StudentHash {

    size_t operator()(const Student& s) const {
        return std::hash<int>{}(s.id);
    }
};
```

Use:

``` cpp
unordered_multiset<Student, StudentHash> students;
```

Then:

``` text
Student{101, "Amit"}
Student{101, "Rahul"}
```

are equivalent according to the equality predicate, so both can be
stored.

This is different from `unordered_set`, where the second equivalent
object would be rejected.

------------------------------------------------------------------------

# Important Rule

If two keys are equivalent according to the equality predicate:

``` cpp
key_eq(a, b) == true
```

then:

``` text
hash(a) == hash(b)
```

must hold.

But:

``` text
hash(a) == hash(b)
```

does not imply that:

``` text
key_eq(a, b)
```

is true.

That situation is a normal hash collision.

------------------------------------------------------------------------

# 44. Custom Objects

An `unordered_multiset` can store custom objects.

Example:

``` cpp
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

Use:

``` cpp
unordered_multiset<Student, StudentHash> students;
```

Insert:

``` cpp
students.insert({101, "Amit"});
students.insert({101, "Rahul"});
students.insert({102, "Deep"});
```

All three objects can be stored.

Conceptually:

``` text
101 Amit
101 Rahul
102 Deep
```

because `unordered_multiset` allows equivalent values.

------------------------------------------------------------------------

# 45. `std::pair` with `unordered_multiset`

You can store pairs with a suitable hash.

Example:

``` cpp
struct PairHash {

    size_t operator()(const pair<int, int>& p) const {

        size_t h1 = hash<int>{}(p.first);
        size_t h2 = hash<int>{}(p.second);

        return h1 ^ (h2 << 1);
    }
};
```

Then:

``` cpp
unordered_multiset<pair<int, int>, PairHash> s;
```

Example:

``` cpp
s.insert({1, 2});
s.insert({2, 3});
s.insert({1, 2});
```

All three occurrences are stored.

`count({1, 2})` can return:

``` text
2
```

------------------------------------------------------------------------

# 46. Move Semantics

Example:

``` cpp
unordered_multiset<int> s1 = {
    1,
    2,
    2,
    3
};

unordered_multiset<int> s2(std::move(s1));
```

Resources can be transferred instead of copied.

After the move:

``` text
s1 -> valid but unspecified state
s2 -> transferred contents
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

# 47. Why Unordered Multiset Elements Cannot Be Modified

Suppose:

``` cpp
unordered_multiset<int> s = {
    10,
    20,
    20,
    30
};
```

You might try:

``` cpp
auto it = s.find(20);

*it = 50;
```

This is not allowed.

Why?

Because changing:

``` text
20 -> 50
```

may change:

``` text
hash(20)
```

to:

``` text
hash(50)
```

and therefore change the element's correct bucket.

For example:

``` text
20
 ↓
hash(20)
 ↓
Bucket 3
```

After modification:

``` text
50
 ↓
hash(50)
 ↓
Bucket 7
```

The container cannot allow an element to be arbitrarily changed while it
remains in the wrong bucket.

Therefore elements are treated as const through normal iterators.

------------------------------------------------------------------------

# 48. Changing an Element

Suppose you want to change one occurrence:

``` text
20 -> 50
```

## Traditional Method

``` cpp
auto it = s.find(20);

if (it != s.end()) {
    s.erase(it);
    s.insert(50);
}
```

Only one occurrence is changed.

------------------------------------------------------------------------

## C++17 Node Handle Method

``` cpp
auto node = s.extract(s.find(20));

if (!node.empty()) {

    node.value() = 50;

    s.insert(std::move(node));
}
```

This extracts one node, changes it outside the container, and inserts it
again according to the new hash/equality state.

------------------------------------------------------------------------

# 49. Bucket Interface

Important bucket functions include:

``` cpp
bucket_count()
bucket()
bucket_size()
```

------------------------------------------------------------------------

## 49.1 `bucket_count()`

Returns the number of buckets.

``` cpp
cout << s.bucket_count();
```

------------------------------------------------------------------------

## 49.2 `bucket(key)`

Returns the bucket index for a key.

``` cpp
cout << s.bucket(20);
```

The exact result depends on the current bucket configuration.

------------------------------------------------------------------------

## 49.3 `bucket_size(n)`

Returns the number of elements in bucket `n`.

``` cpp
size_t b = s.bucket(20);

cout << s.bucket_size(b);
```

------------------------------------------------------------------------

## 49.4 Bucket Iteration

You can inspect one bucket:

``` cpp
size_t b = s.bucket(20);

for (auto it = s.begin(b);
     it != s.end(b);
     ++it) {

    cout << *it << " ";
}
```

These are local iterators.

------------------------------------------------------------------------

# 50. Hash Policy

Important functions:

``` cpp
load_factor()
max_load_factor()
rehash()
reserve()
```

------------------------------------------------------------------------

## 50.1 `load_factor()`

``` cpp
cout << s.load_factor();
```

Conceptually:

``` text
size / bucket_count
```

------------------------------------------------------------------------

## 50.2 `max_load_factor()`

Read:

``` cpp
cout << s.max_load_factor();
```

Set:

``` cpp
s.max_load_factor(0.7);
```

------------------------------------------------------------------------

## 50.3 `rehash()`

Requests at least a specified number of buckets.

``` cpp
s.rehash(100);
```

This can redistribute elements.

------------------------------------------------------------------------

## 50.4 `reserve()`

Requests enough buckets to accommodate at least a specified number of
elements without exceeding the current maximum load factor.

``` cpp
s.reserve(1000);
```

Useful when you know many elements will be inserted.

Example:

``` cpp
unordered_multiset<int> s;

s.reserve(100000);

for (int i = 0; i < 100000; ++i) {
    s.insert(i % 100);
}
```

This can reduce repeated rehashing.

------------------------------------------------------------------------

# 51. Iterator and Reference Rules

Important rules:

### Insertion without rehash

Existing iterators generally remain valid if no rehash occurs.

### Insertion with rehash

A rehash invalidates all iterators.

### Erasing an element

The iterator/reference to the erased element becomes invalid.

### `clear()`

All element iterators and references become invalid.

### `reserve()` / `rehash()`

These can cause rehashing and invalidate iterators.

A useful mental model:

``` text
unordered_multiset
        |
        +--> rehash?
               |
            yes -> all iterators invalidated
            no  -> existing iterators generally survive insertion
```

------------------------------------------------------------------------

# 52. `unordered_multiset` vs `multiset`

  Feature               `unordered_multiset`   `multiset`
  --------------------- ---------------------- ---------------
  Header                `<unordered_set>`      `<set>`
  Duplicates            Yes                    Yes
  Sorted                No                     Yes
  Typical structure     Hash table             Balanced tree
  Search                O(1) average           O(log n)
  Insert                O(1) average           O(log n)
  Count                 O(k) average           O(log n + k)
  Erase by key          O(k) average           O(log n + k)
  Worst-case lookup     O(n)                   O(log n)
  `lower_bound()`       No                     Yes
  `upper_bound()`       No                     Yes
  Ordered iteration     No                     Yes
  Requires hash         Yes                    No
  Requires comparator   No                     Yes
  `contains()`          C++20                  C++20

### Use `unordered_multiset` when:

``` text
Need duplicates
+
Need fast average lookup
+
Ordering is unnecessary
```

### Use `multiset` when:

``` text
Need duplicates
+
Need sorted order
+
Need range queries
```

------------------------------------------------------------------------

# 53. `unordered_multiset` vs `unordered_set`

  Feature            `unordered_set`       `unordered_multiset`
  ------------------ --------------------- ----------------------
  Ordered            No                    No
  Duplicate values   No                    Yes
  Hash table         Yes                   Yes
  Search             O(1) average          O(1) average
  `count()`          0 or 1                0 or more
  `erase(key)`       Removes at most one   Removes all matching
  `contains()`       C++20                 C++20
  `lower_bound()`    No                    No

Main difference:

``` text
unordered_set
    -> unique values

unordered_multiset
    -> duplicate values allowed
```

------------------------------------------------------------------------

# 54. `unordered_multiset` vs `vector`

  Feature                  `unordered_multiset`            `vector`
  ------------------------ ------------------------------- ----------------
  Duplicate values         Yes                             Yes
  Sorted automatically     No                              No
  Random access            No                              Yes
  Typical lookup           O(1) average                    O(n)
  Storage                  Hash buckets + nodes/metadata   Contiguous
  Cache locality           Usually poorer                  Usually better
  Memory overhead          Higher                          Lower
  Fast membership lookup   Yes                             No
  Insertion at end         Expected O(1)                   Amortized O(1)

Use `vector` when: - You need indexing. - You need contiguous storage. -
Data is mostly sequential. - Membership lookup is not the main
operation.

Use `unordered_multiset` when: - Duplicates are required. - Fast average
lookup is important. - Ordering is unnecessary.

------------------------------------------------------------------------

# 55. `unordered_multiset` vs `vector + sort`

For batch data:

``` cpp
vector<int> v;
```

can be processed later using:

``` cpp
sort(v.begin(), v.end());
```

### `unordered_multiset`

``` text
Insert
   ↓
Hash
   ↓
Bucket
   ↓
Immediately available for lookup
```

### `vector + sort`

``` text
Collect
   ↓
Store contiguously
   ↓
Sort later
```

Use `vector + sort` when: - You receive a large batch. - You need
ordered output eventually. - You do not need frequent membership lookup
while collecting. - Cache efficiency is important.

Use `unordered_multiset` when: - You need dynamic membership lookup. -
Duplicates must be retained. - Ordering is unnecessary.

------------------------------------------------------------------------

# 56. Common Mistakes

## Mistake 1: Expecting sorted order

Wrong expectation:

``` cpp
unordered_multiset<int> s = {
    30,
    10,
    20
};
```

expecting:

``` text
10 20 30
```

Iteration order is unspecified.

------------------------------------------------------------------------

## Mistake 2: Expecting insertion order

Do not assume:

``` text
insert 30
insert 10
insert 20

iteration -> 30 10 20
```

The container does not preserve insertion order.

------------------------------------------------------------------------

## Mistake 3: Using `lower_bound()`

Invalid:

``` cpp
s.lower_bound(20);
```

`unordered_multiset` has no ordered lookup.

Use:

``` cpp
find()
contains()
count()
```

------------------------------------------------------------------------

## Mistake 4: Assuming duplicates are rejected

Wrong:

``` cpp
unordered_multiset<int> s;

s.insert(10);
s.insert(10);
```

Both values are stored.

------------------------------------------------------------------------

## Mistake 5: Assuming `count()` returns only 0 or 1

That is true for:

``` cpp
unordered_set
```

but not:

``` cpp
unordered_multiset
```

Example:

``` cpp
s.count(10);
```

can return:

``` text
0
1
2
3
...
```

------------------------------------------------------------------------

## Mistake 6: Using `erase(key)` when you want one occurrence

Suppose:

``` text
10 20 20 20 30
```

This:

``` cpp
s.erase(20);
```

removes all three `20` values.

To remove one:

``` cpp
auto it = s.find(20);

if (it != s.end()) {
    s.erase(it);
}
```

------------------------------------------------------------------------

## Mistake 7: Modifying an element directly

Invalid:

``` cpp
auto it = s.find(20);

*it = 50;
```

Use erase/insert or C++17 node handles.

------------------------------------------------------------------------

## Mistake 8: Bad custom hash

A poor hash function can create many collisions.

That can degrade performance.

------------------------------------------------------------------------

## Mistake 9: Inconsistent hash and equality

Wrong:

``` text
a and b are equivalent
but
hash(a) != hash(b)
```

Equivalent values must have equal hash values.

------------------------------------------------------------------------

## Mistake 10: Assuming O(1) is guaranteed

Correct:

``` text
Expected average -> O(1)
Worst case       -> O(n)
```

For duplicate-aware operations, the number of equivalent elements also
matters.

------------------------------------------------------------------------

## Mistake 11: Forgetting rehash invalidates iterators

Operations such as:

``` cpp
reserve()
rehash()
```

can invalidate iterators.

Insertion can also trigger rehashing.

------------------------------------------------------------------------

## Mistake 12: Dereferencing `end()`

Invalid:

``` cpp
cout << *s.end();
```

Always check lookup results.

------------------------------------------------------------------------

# 57. Practical Examples

## Example 1 --- Store Duplicate Values

``` cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

    unordered_multiset<int> scores;

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

Possible output:

``` text
80 90 70 90 80
```

The exact order is unspecified.

------------------------------------------------------------------------

# Example 2 --- Count Occurrences

``` cpp
unordered_multiset<int> scores = {
    90,
    80,
    90,
    70,
    90
};

cout << scores.count(90);
```

Output:

``` text
3
```

------------------------------------------------------------------------

# Example 3 --- Remove Only One Duplicate

``` cpp
unordered_multiset<int> scores = {
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

The number of `80` occurrences decreases from:

``` text
3
```

to:

``` text
2
```

------------------------------------------------------------------------

# Example 4 --- Remove All Duplicates of a Value

``` cpp
unordered_multiset<int> scores = {
    70,
    80,
    80,
    80,
    90
};

scores.erase(80);
```

All `80` occurrences are removed.

------------------------------------------------------------------------

# Example 5 --- Check Existence

``` cpp
unordered_multiset<int> s = {
    10,
    20,
    20,
    30
};

if (s.contains(20)) {
    cout << "20 exists";
}
```

Output:

``` text
20 exists
```

------------------------------------------------------------------------

# Example 6 --- Duplicate Detection

``` cpp
vector<int> values = {
    10,
    20,
    30,
    20,
    40
};

unordered_multiset<int> valuesSet;

for (int x : values) {
    valuesSet.insert(x);
}

for (int x : valuesSet) {
    if (valuesSet.count(x) > 1) {
        // x has duplicates
    }
}
```

For simply detecting duplicates during input, an `unordered_set` is
often more appropriate if you do not need to retain every occurrence.

------------------------------------------------------------------------

# Example 7 --- Reserve Before Many Insertions

``` cpp
unordered_multiset<int> s;

s.reserve(100000);

for (int i = 0; i < 100000; ++i) {
    s.insert(i % 1000);
}
```

This can reduce repeated rehashing.

------------------------------------------------------------------------

# Example 8 --- Erase While Iterating

A safe pattern is:

``` cpp
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

``` text
10 10 15 20 20 25
```

becomes:

``` text
15 25
```

------------------------------------------------------------------------

# Example 9 --- Custom Object

``` cpp
#include <iostream>
#include <string>
#include <unordered_set>

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

    unordered_multiset<Student, StudentHash> students;

    students.insert({101, "Amit"});
    students.insert({101, "Rahul"});
    students.insert({102, "Deep"});

    cout << students.size();

    return 0;
}
```

Output:

``` text
3
```

Why?

Because all three occurrences are allowed, including the two equivalent
ID `101` objects.

------------------------------------------------------------------------

# Example 10 --- Inspect Buckets

``` cpp
unordered_multiset<int> s = {
    10,
    20,
    20,
    30,
    40
};

cout << "Bucket count: "
     << s.bucket_count()
     << "\n";

for (size_t i = 0; i < s.bucket_count(); ++i) {

    cout << "Bucket " << i << ": ";

    for (auto it = s.begin(i);
         it != s.end(i);
         ++it) {

        cout << *it << " ";
    }

    cout << "\n";
}
```

The exact bucket distribution is implementation-dependent.

------------------------------------------------------------------------

# Example 11 --- Complete Program

``` cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

    unordered_multiset<int> numbers;

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

    // Bucket information
    cout << "Bucket count: "
         << numbers.bucket_count()
         << "\n";

    cout << "Load factor: "
         << numbers.load_factor()
         << "\n";

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

``` text
Elements:
10 20 10 20 30

Size: 5
Count of 20: 2
20 found
30 exists
Bucket count: ...
Load factor: ...
After erasing one 20:
10 20 10 30
```

The exact iteration order, bucket count, and load factor are
implementation-dependent.

------------------------------------------------------------------------

# 58. Interview Questions

## Q1. What is `std::unordered_multiset`?

`std::unordered_multiset` is an unordered associative STL container that
stores multiple equivalent values using hashing.

------------------------------------------------------------------------

## Q2. Does unordered multiset allow duplicates?

Yes.

``` cpp
unordered_multiset<int> s;

s.insert(10);
s.insert(10);
s.insert(10);
```

All three are stored.

------------------------------------------------------------------------

## Q3. Is unordered multiset sorted?

No.

Its iteration order is unspecified.

------------------------------------------------------------------------

## Q4. What is the typical internal structure?

A hash table.

The exact implementation is implementation-dependent.

------------------------------------------------------------------------

## Q5. What is the average complexity of `find()`?

Expected average:

``` text
O(1)
```

Worst case:

``` text
O(n)
```

------------------------------------------------------------------------

## Q6. What is the difference between `unordered_set` and `unordered_multiset`?

``` text
unordered_set
    -> unique values

unordered_multiset
    -> duplicate values allowed
```

Both are hash-based and unordered.

------------------------------------------------------------------------

## Q7. What does `count()` return?

It returns the number of elements equivalent to the supplied value.

Example:

``` cpp
unordered_multiset<int> s = {
    10,
    10,
    10
};

s.count(10);
```

returns:

``` text
3
```

------------------------------------------------------------------------

## Q8. What does `erase(key)` do?

It removes all elements equivalent to the key.

Example:

``` cpp
s.erase(10);
```

If there are five equivalent `10` values, all five are removed.

------------------------------------------------------------------------

## Q9. How do you erase only one occurrence?

Use an iterator:

``` cpp
auto it = s.find(10);

if (it != s.end()) {
    s.erase(it);
}
```

------------------------------------------------------------------------

## Q10. Does unordered multiset provide `lower_bound()`?

No.

Because it does not maintain sorted order.

------------------------------------------------------------------------

## Q11. Why can't unordered multiset elements be modified directly?

Because modifying a value can change its hash and therefore its bucket.

------------------------------------------------------------------------

## Q12. How do you modify an element?

Traditional:

``` cpp
auto it = s.find(oldValue);

if (it != s.end()) {
    s.erase(it);
    s.insert(newValue);
}
```

C++17:

``` cpp
auto node = s.extract(s.find(oldValue));

if (!node.empty()) {
    node.value() = newValue;
    s.insert(std::move(node));
}
```

------------------------------------------------------------------------

## Q13. What is a collision?

A collision occurs when different values map to the same bucket.

``` text
A -> Bucket 5
B -> Bucket 5
```

They can still be different values.

------------------------------------------------------------------------

## Q14. What is load factor?

Approximately:

``` text
size / bucket_count
```

It represents average bucket occupancy.

------------------------------------------------------------------------

## Q15. What is rehashing?

Rehashing changes the bucket organization and redistributes elements.

------------------------------------------------------------------------

## Q16. Does rehashing invalidate iterators?

Yes.

A rehash invalidates all iterators.

------------------------------------------------------------------------

## Q17. What is `reserve()`?

It requests enough buckets to accommodate at least a specified number of
elements without exceeding the current maximum load factor.

------------------------------------------------------------------------

## Q18. What is `rehash()`?

It requests at least a specified number of buckets.

------------------------------------------------------------------------

## Q19. Difference between `reserve()` and `rehash()`?

``` text
reserve(n)
    -> based on number of elements

rehash(n)
    -> based on number of buckets
```

------------------------------------------------------------------------

## Q20. What is `max_load_factor()`?

It gets or sets the maximum load factor used by the container's
automatic rehash policy.

------------------------------------------------------------------------

## Q21. Can unordered multiset store custom objects?

Yes, if suitable hash and equality functions are available.

------------------------------------------------------------------------

## Q22. What is the rule for custom hash and equality?

If:

``` text
a and b are equivalent
```

then:

``` text
hash(a) == hash(b)
```

must hold.

------------------------------------------------------------------------

## Q23. Can unordered multiset store pairs?

Yes, with an appropriate hash function.

------------------------------------------------------------------------

## Q24. Does insertion always have O(1) complexity?

No.

Expected average:

``` text
O(1)
```

Worst case:

``` text
O(n)
```

------------------------------------------------------------------------

## Q25. Can unordered multiset preserve insertion order?

No.

------------------------------------------------------------------------

## Q26. Why can unordered multiset use more memory than vector?

Because it may require:

``` text
bucket storage
+
element nodes
+
collision-management metadata
+
allocator overhead
```

------------------------------------------------------------------------

## Q27. What is `contains()`?

C++20:

``` cpp
s.contains(value)
```

returns whether at least one equivalent value exists.

------------------------------------------------------------------------

## Q28. What is `extract()`?

C++17 node-handle functionality that removes one node and returns it as
a node handle.

------------------------------------------------------------------------

## Q29. What is `merge()`?

C++17 functionality that transfers compatible nodes from another
associative container.

For `unordered_multiset`, equivalent nodes can also be transferred
because duplicates are allowed.

------------------------------------------------------------------------

## Q30. When should you use `unordered_multiset`?

Use it when you need:

``` text
Duplicate values
+
Fast average membership lookup
+
No ordering requirement
```

------------------------------------------------------------------------

# 59. Important C++ Version Features

  Feature                        Standard
  ------------------------------ ----------------
  `std::unordered_multiset`      C++11
  Range-based `for`              C++11
  `emplace()`                    C++11
  Move construction/assignment   C++11
  `cbegin()` / `cend()`          C++11
  Bucket interface               C++11
  Hash policy functions          C++11
  `extract()`                    C++17
  `merge()`                      C++17
  `contains()`                   C++20
  `operator[]`                   Not applicable
  `at()`                         Not applicable
  `lower_bound()`                Not applicable
  `upper_bound()`                Not applicable

### Important

Do not copy ordered-container APIs into `unordered_multiset`.

These are not provided:

``` cpp
lower_bound()
upper_bound()
```

And these are not provided because this is not a map:

``` cpp
operator[]
at()
```

------------------------------------------------------------------------

# 60. Quick Reference Table

## Constructors

  Function                                 Purpose
  ---------------------------------------- ------------------------
  `unordered_multiset()`                   Empty container
  `unordered_multiset(initializer_list)`   Initialize from values
  `unordered_multiset(first, last)`        Initialize from range
  Copy constructor                         Copy
  Move constructor                         Move

------------------------------------------------------------------------

## Assignment

  Function                      Purpose
  ----------------------------- ----------------------
  `operator=`                   Copy/move assignment
  Initializer-list assignment   Replace contents

------------------------------------------------------------------------

## Iterators

  Function     Purpose
  ------------ -----------------
  `begin()`    Begin iteration
  `end()`      One past end
  `cbegin()`   Constant begin
  `cend()`     Constant end

------------------------------------------------------------------------

## Capacity

  Function       Purpose
  -------------- ---------------------------
  `empty()`      Check empty
  `size()`       Number of all occurrences
  `max_size()`   Maximum possible size

------------------------------------------------------------------------

## Modifiers

  Function      Purpose
  ------------- -------------------
  `insert()`    Insert element
  `emplace()`   Construct element
  `erase()`     Remove element(s)
  `clear()`     Remove all
  `swap()`      Exchange contents
  `extract()`   Extract one node
  `merge()`     Transfer nodes

------------------------------------------------------------------------

## Lookup

  Function       Purpose
  -------------- -----------------------------------
  `find()`       Find one matching occurrence
  `count()`      Count all matching occurrences
  `contains()`   Check whether at least one exists

------------------------------------------------------------------------

## Bucket Interface

  Function           Purpose
  ------------------ --------------------
  `bucket_count()`   Number of buckets
  `bucket(key)`      Bucket index
  `bucket_size(n)`   Elements in bucket
  `begin(n)`         Local bucket begin
  `end(n)`           Local bucket end

------------------------------------------------------------------------

## Hash Policy

  Function              Purpose
  --------------------- -----------------------------
  `load_factor()`       Current load factor
  `max_load_factor()`   Get/set maximum load factor
  `rehash()`            Request bucket count
  `reserve()`           Prepare for element count

------------------------------------------------------------------------

## Observers

  Function            Purpose
  ------------------- --------------------
  `hash_function()`   Hash object
  `key_eq()`          Equality predicate

------------------------------------------------------------------------

# 61. Advantages

## 61.1 Duplicate Values

Unlike `unordered_set`, duplicates are allowed.

``` cpp
unordered_multiset<int> s = {
    10,
    10,
    20
};
```

All three occurrences are stored.

------------------------------------------------------------------------

## 61.2 Fast Average Lookup

Expected:

``` text
O(1)
```

------------------------------------------------------------------------

## 61.3 Fast Average Insertion

Expected:

``` text
O(1)
```

------------------------------------------------------------------------

## 61.4 Dynamic Duplicate Storage

Values can be inserted as they arrive while retaining every occurrence.

------------------------------------------------------------------------

## 61.5 Easy Frequency Counting

``` cpp
s.count(value);
```

can directly return the number of equivalent occurrences.

------------------------------------------------------------------------

## 61.6 Custom Hashing

Custom objects can be supported with a suitable hash function.

------------------------------------------------------------------------

# 62. Disadvantages

## 62.1 No Ordering

You cannot rely on sorted order.

------------------------------------------------------------------------

## 62.2 Worst-Case O(n)

Heavy collisions can degrade hash-table operations.

------------------------------------------------------------------------

## 62.3 More Memory Overhead

Buckets and nodes require additional memory.

------------------------------------------------------------------------

## 62.4 Poorer Cache Locality

Compared with contiguous containers such as `vector`, node-based hash
containers usually have poorer locality.

------------------------------------------------------------------------

## 62.5 No Ordered Range Queries

There is no:

``` cpp
lower_bound()
upper_bound()
```

------------------------------------------------------------------------

## 62.6 Rehashing Can Invalidate Iterators

Code holding iterators must account for operations that can trigger
rehashing.

------------------------------------------------------------------------

## 62.7 Duplicate Count Can Increase Operation Cost

Operations such as:

``` cpp
count()
erase(key)
```

may need to process many equivalent elements.

------------------------------------------------------------------------

# 63. Decision Guide

Use this mental model:

``` text
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

------------------------------------------------------------------------

## Another Decision Rule

Use:

``` cpp
unordered_multiset
```

when you need:

``` text
Duplicates
+
Fast average lookup
+
No ordering
```

Use:

``` cpp
multiset
```

when you need:

``` text
Duplicates
+
Sorted order
+
Range queries
```

Use:

``` cpp
unordered_set
```

when you need:

``` text
Unique values
+
Fast average lookup
+
No ordering
```

Use:

``` cpp
vector
```

when you need:

``` text
Duplicates
+
Random access
+
Contiguous storage
```

------------------------------------------------------------------------

# 64. Summary

## Definition

> `std::unordered_multiset` is an unordered associative STL container
> that stores multiple equivalent elements using hashing and provides
> expected average constant-time lookup and insertion.

------------------------------------------------------------------------

## Main Properties

``` text
Duplicate elements allowed
          +
No sorted order
          +
Hash table
          +
Hash function
          +
Equality predicate
          +
O(1) average lookup
          +
O(1) average insertion
          +
O(k) average duplicate-aware count/erase
          +
O(n) worst case
```

where:

``` text
k = number of matching elements
```

------------------------------------------------------------------------

## Main Functions

``` cpp
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

// Capacity
empty()
size()
max_size()

// Buckets
bucket_count()
bucket()
bucket_size()
begin(bucket)
end(bucket)

// Hash policy
load_factor()
max_load_factor()
rehash()
reserve()

// Observers
hash_function()
key_eq()

// Utility
swap()
```

------------------------------------------------------------------------

# `std::unordered_multiset` Mental Model

Remember:

``` text
             std::unordered_multiset
                       |
                       v
              Duplicate Values
                   Allowed
                       |
                       v
                 Hash Function
                       |
                       v
                    Bucket
                       |
                       v
                Equality Check
                       |
                       v
          -------------------------
          |           |           |
          v           v           v
       find()      insert()    erase()
          |           |           |
          +-----------+-----------+
                      |
                      v
               O(1) Average
                      |
                      v
                 O(n) Worst
                      |
                      v
          count/erase depend on
          number of matches
```

------------------------------------------------------------------------

# Most Important Interview Points

``` text
1. unordered_multiset stores values.

2. unordered_multiset allows duplicate/equivalent values.

3. unordered_multiset does not maintain sorted order.

4. It is hash-table based.

5. It uses a hash function.

6. It uses an equality predicate.

7. find() is O(1) average.

8. insert() is O(1) average.

9. Worst-case lookup can be O(n).

10. count() can return 0, 1, 2, 3, ... .

11. count() depends on the number of matching elements.

12. erase(key) removes all matching elements.

13. erase(iterator) removes one selected occurrence.

14. unordered_multiset has no lower_bound().

15. unordered_multiset has no upper_bound().

16. unordered_multiset has no operator[].

17. unordered_multiset has no at().

18. Elements cannot be modified directly through normal iterators.

19. Changing a value can change its hash and bucket.

20. extract() is available from C++17.

21. merge() is available from C++17.

22. contains() is available from C++20.

23. Multiple values can occupy one bucket because collisions are allowed.

24. Equivalent values must have equal hash values.

25. Rehashing invalidates all iterators.

26. reserve() prepares for a number of elements.

27. rehash() requests a number of buckets.

28. load_factor() is approximately size / bucket_count.

29. unordered_set stores unique values; unordered_multiset allows duplicates.

30. multiset is ordered; unordered_multiset is not.

31. Use unordered_multiset when you need duplicate + fast average lookup + no ordering.
```

------------------------------------------------------------------------

# Final One-Line Definition

> **`std::unordered_multiset` is an unordered associative C++ STL
> container that stores multiple equivalent/duplicate elements using a
> hash function and equality predicate, providing expected average O(1)
> lookup and insertion without maintaining sorted order.**
