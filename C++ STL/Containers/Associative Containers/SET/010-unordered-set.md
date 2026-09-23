# `std::unordered_set` in C++ STL:

## Table of Contents

1.  Introduction
2.  Real-World Use Cases
3.  Header File
4.  Namespace
5.  Basic Syntax
6.  Template Parameters
7.  What Exactly Does `std::unordered_set` Store?
8.  Unordered Associative Container
9.  Internal Working
10. Hash Table Concept
11. How Uniqueness Works
12. Hash Function
13. Equality Function
14. Buckets
15. Load Factor and Rehashing
16. Characteristics
17. Memory Structure
18. Time Complexity
19. Iterator Invalidation
20. Constructors
21. Assignment Operators
22. Iterators
23. Capacity Functions
24. Element Access
25. Modifiers
26. `insert()`
27. `emplace()`
28. `erase()`
29. `clear()`
30. `swap()`
31. `extract()` --- C++17
32. `merge()` --- C++17
33. Lookup Functions
34. `find()`
35. `count()`
36. `contains()` --- C++20
37. Observers
38. `hash_function()`
39. `key_eq()`
40. Custom Hash
41. Custom Equality
42. Custom Hash + Equality
43. Custom Objects
44. `std::pair` with `unordered_set`
45. Move Semantics
46. Why Unordered Set Elements Cannot Be Modified
47. Changing an Element
48. Bucket Interface
49. Hash Policy
50. Iterator and Reference Rules
51. `unordered_set` vs `set`
52. `unordered_set` vs `unordered_multiset`
53. `unordered_set` vs `vector`
54. `unordered_set` vs `vector + sort + unique`
55. Common Mistakes
56. Practical Examples
57. Interview Questions
58. Important C++ Version Features
59. Quick Reference Table
60. Advantages
61. Disadvantages
62. Decision Guide
63. Summary

------------------------------------------------------------------------

# 1. Introduction

-   `std::unordered_set` is an **unordered associative container**
    provided by the C++ Standard Template Library (STL).

It stores: - Unique elements - Without maintaining sorted order - Using
a hash function and an equality comparison

**Example:**

``` cpp
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {

    unordered_set<int> numbers;

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

**Possible output:**

``` text
20 10 30
```

The exact iteration order is **unspecified** and can differ between
implementations and executions.

The second `10` is not inserted because an `unordered_set` does not
allow duplicate elements.

------------------------------------------------------------------------

# 2. Real-World Use Cases

`std::unordered_set` is useful when you need:

## 2.1 Unique values

``` text
10
20
30
```

-   Duplicate values are automatically rejected.

## 2.2 Fast average-case lookup

If you frequently need to ask:

``` text
Does this value exist?
```

an `unordered_set` provides expected average-case constant-time lookup.

``` cpp
if (s.contains(50)) {
    cout << "Found";
}
```

## 2.3 Membership testing

Examples: - Checking whether a user ID has already been processed. -
Checking whether an item has already appeared. - Maintaining a visited
set in graph algorithms. - Checking duplicate values.

## 2.4 Maintaining a dynamic collection of unique values

Unlike `vector + sort + unique`, the set can reject duplicates as values
arrive.

## 2.5 When ordering is unnecessary

If you do not need: - sorted iteration - `lower_bound()` -
`upper_bound()` - range ordering

then `unordered_set` can often be a good choice.

------------------------------------------------------------------------

# 3. Header File

``` cpp
#include <unordered_set>
```

------------------------------------------------------------------------

# 4. Namespace

You can write:

``` cpp
using namespace std;

unordered_set<int> numbers;
```

Or explicitly:

``` cpp
std::unordered_set<int> numbers;
```

-   Using `std::` explicitly is often preferable in larger projects and
    header files because it avoids namespace pollution.

------------------------------------------------------------------------

# 5. Basic Syntax

``` cpp
unordered_set<data_type> name;
```

Examples:

``` cpp
unordered_set<int> numbers;
unordered_set<string> names;
unordered_set<char> letters;
unordered_set<double> prices;
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
class unordered_set;
```

### Parameters

  Parameter     Meaning
  ------------- ----------------------------------------------------
  `Key`         Type of elements stored
  `Hash`        Hash function used to map keys to buckets
  `Pred`        Equality predicate used to compare equivalent keys
  `Allocator`   Controls memory allocation

Example:

``` cpp
unordered_set<int>
```

Conceptually uses:

``` text
Key       = int
Hash      = hash<int>
Pred      = equal_to<int>
```

------------------------------------------------------------------------

# 7. What Exactly Does `std::unordered_set` Store?

An `unordered_set` stores **values**, not key-value pairs.

Example:

``` cpp
unordered_set<int> s;
```

contains:

``` text
10
20
30
```

There is no separate:

``` text
key -> value
```

relationship.

Compare:

### `unordered_set`

``` cpp
unordered_set<int> s;
```

``` text
10
20
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

This is a fundamental difference between set-like and map-like
containers.

------------------------------------------------------------------------

# 8. Unordered Associative Container

`std::unordered_set` is an **unordered associative container**.

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
unordered_set<int> s = {30, 10, 20};
```

Do not expect:

``` text
10 20 30
```

and do not expect insertion order either.

The iteration order is determined by the container's hashing/bucket
organization and is unspecified.

------------------------------------------------------------------------

# 9. Internal Working

`std::unordered_set` is hash-table based.

Conceptually:

``` text
                Hash Function
                     |
                     v
                  hash(key)
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
     values values values values
```

The standard does not require one particular hash-table implementation.

Implementations may use different internal bucket/node organizations.

The important idea is:

``` text
value
  ↓
hash
  ↓
bucket
  ↓
search among equivalent elements
```

------------------------------------------------------------------------

# 10. Hash Table Concept

A hash table uses a hash function to convert a key into a hash value.

Conceptually:

``` cpp
hash_value = hash(key);
```

Then the implementation uses the hash value to select a bucket.

For example:

``` text
hash(42) -> some hash value
                    |
                    v
              bucket index
                    |
                    v
                 Bucket 5
```

The goal is to distribute values reasonably across buckets.

A good hash distribution helps maintain expected constant-time
operations.

------------------------------------------------------------------------

# 11. How Uniqueness Works

An `unordered_set` does not determine uniqueness merely by checking:

``` cpp
a == b
```

in isolation.

It uses: 1. Hashing 2. Equality comparison

Two keys are considered equivalent when the equality predicate says they
are equivalent.

For the default:

``` cpp
std::equal_to<Key>
```

this is normally based on:

``` cpp
a == b
```

Important rule:

> If two keys compare equivalent, their hash values must be equal.

Conceptually:

``` text
equivalent keys
       ↓
same hash value
       ↓
same/equivalent bucket search
```

This is essential when creating custom hash and equality functions.

------------------------------------------------------------------------

# 12. Hash Function

The hash function converts a key into a hash value.

Default:

``` cpp
std::hash<Key>
```

Example:

``` cpp
unordered_set<int> s;
```

uses a hash function appropriate for `int`.

You can inspect it:

``` cpp
auto hasher = s.hash_function();

cout << hasher(10);
```

The exact numeric hash value is implementation-dependent.

------------------------------------------------------------------------

# 13. Equality Function

The equality predicate determines whether two keys are equivalent.

Default:

``` cpp
std::equal_to<Key>
```

Example:

``` cpp
unordered_set<int> s;

auto equal = s.key_eq();

cout << equal(10, 10);
```

Output:

``` text
1
```

For custom objects, the equality function must be consistent with the
hash function.

------------------------------------------------------------------------

# 14. Buckets

An `unordered_set` organizes elements into buckets.

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

Multiple values can be placed in the same bucket because different
values can produce the same bucket index.

This is called a **collision**.

------------------------------------------------------------------------

# 15. Load Factor and Rehashing

The load factor is approximately:

``` text
load factor = number of elements / number of buckets
```

You can check it using:

``` cpp
s.load_factor();
```

Example:

``` cpp
unordered_set<int> s;

s.insert(10);
s.insert(20);
s.insert(30);

cout << s.load_factor();
```

The exact result depends on the bucket count.

------------------------------------------------------------------------

## `max_load_factor()`

Controls the maximum desired load factor used by the container's rehash
policy.

``` cpp
s.max_load_factor(0.7);
```

A lower maximum load factor generally means: - More buckets - Lower
average bucket occupancy - Potentially more memory usage

------------------------------------------------------------------------

## Rehashing

When the container needs more buckets, it may rehash.

Conceptually:

``` text
Old bucket table
       ↓
Allocate new bucket table
       ↓
Redistribute elements
       ↓
New bucket organization
```

After rehashing, iteration order can change.

------------------------------------------------------------------------

# 16. Characteristics

`std::unordered_set` has these major characteristics:

-   Stores unique elements.
-   Does not maintain sorted order.
-   Uses hashing.
-   Uses an equality predicate.
-   Average expected search is O(1).
-   Average expected insertion is O(1).
-   Average expected deletion by key is O(1).
-   Worst-case operations can be O(n).
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

------------------------------------------------------------------------

# 17. Memory Structure

Suppose:

``` cpp
unordered_set<int> s;

s.insert(20);
s.insert(10);
s.insert(40);
```

Conceptually:

``` text
Bucket Table
+---------+
| Bucket0 | -> ...
| Bucket1 | -> 20
| Bucket2 | -> ...
| Bucket3 | -> 10 -> 40
+---------+
```

The exact representation is implementation-specific.

A hash-based node container usually has: - A bucket array or equivalent
bucket structure - Nodes containing elements - Links or other
collision-management information

Therefore it can have more memory overhead than a contiguous `vector`.

------------------------------------------------------------------------

# 18. Time Complexity

  -----------------------------------------------------------------------
  Operation                  Average / Expected                Worst Case
  ------------------- ------------------------- -------------------------
  `insert()`                               O(1)                      O(n)

  `emplace()`                              O(1)                      O(n)

  `erase(key)`                     O(1) average                      O(n)

  `erase(iterator)`          Amortized constant           O(n) in general
                                                worst-case considerations

  `find()`                                 O(1)                      O(n)

  `count()`                        O(1) average                      O(n)

  `contains()`                     O(1) average                      O(n)

  `clear()`                                O(n)                      O(n)

  `size()`                                 O(1)                      O(1)

  `empty()`                                O(1)                      O(1)

  `begin()`                                O(1)                      O(1)

  `end()`                                  O(1)                      O(1)
  -----------------------------------------------------------------------

### Important

Remember:

``` text
unordered_set
      |
      +---- Average lookup  -> O(1)
      |
      +---- Average insert  -> O(1)
      |
      +---- Average erase   -> O(1)
      |
      +---- Worst case      -> O(n)
```

The O(1) behavior is expected/average-case, not a guaranteed worst-case
bound.

------------------------------------------------------------------------

# 19. Iterator Invalidation

A key difference from `set` is that **rehashing can invalidate
iterators**.

### Insertion without rehash

If an insertion does not cause rehashing, existing iterators generally
remain valid.

### Insertion that causes rehash

If rehashing occurs:

``` text
old buckets
    ↓
new buckets
    ↓
elements redistributed
```

iterators are invalidated.

### Erasing one element

Erasing an element invalidates iterators and references to that erased
element.

### References

References to elements are generally not invalidated by rehashing,
although iterators are. They are invalidated when the referenced element
is erased.

For precise code, always account for the operation's invalidation rules
rather than assuming all unordered-container operations behave like
`set`.

------------------------------------------------------------------------

# 20. Constructors

## 20.1 Default Constructor

``` cpp
unordered_set<int> s;
```

Creates an empty unordered set.

------------------------------------------------------------------------

## 20.2 Initializer List

``` cpp
unordered_set<int> s = {5, 2, 8, 1, 2};
```

Result contains unique values:

``` text
1, 2, 5, 8
```

But iteration order is unspecified.

------------------------------------------------------------------------

## 20.3 Range Constructor

``` cpp
vector<int> v = {10, 20, 30};

unordered_set<int> s(v.begin(), v.end());
```

------------------------------------------------------------------------

## 20.4 Copy Constructor

``` cpp
unordered_set<int> s1 = {1, 2, 3};
unordered_set<int> s2(s1);
```

`s2` becomes a copy of `s1`.

------------------------------------------------------------------------

## 20.5 Move Constructor

``` cpp
unordered_set<int> s1 = {1, 2, 3};
unordered_set<int> s2(std::move(s1));
```

Resources can be transferred from `s1` to `s2`.

After the move:

``` text
s1 -> valid but unspecified state
s2 -> transferred contents
```

------------------------------------------------------------------------

# 21. Assignment Operators

## 21.1 Copy Assignment

``` cpp
unordered_set<int> s1 = {1, 2, 3};
unordered_set<int> s2;

s2 = s1;
```

------------------------------------------------------------------------

## 21.2 Move Assignment

``` cpp
s2 = std::move(s1);
```

Resources can be transferred.

After the move:

``` text
s1 -> valid but unspecified state
s2 -> transferred contents
```

------------------------------------------------------------------------

## 21.3 Initializer List Assignment

``` cpp
s = {10, 20, 30};
```

Replaces the existing contents.

------------------------------------------------------------------------

# 22. Iterators

Unlike `set`, an `unordered_set` provides **forward iterators**.

It does not provide bidirectional tree-order traversal.

------------------------------------------------------------------------

## 22.1 `begin()`

``` cpp
auto it = s.begin();
```

Points to an element in the container.

There is no guaranteed sorted meaning to this position.

------------------------------------------------------------------------

## 22.2 `end()`

``` cpp
auto it = s.end();
```

Represents one position past the last element.

Never dereference `end()`.

------------------------------------------------------------------------

## 22.3 Forward Traversal

``` cpp
for (auto it = s.begin(); it != s.end(); ++it) {
    cout << *it << " ";
}
```

------------------------------------------------------------------------

## 22.4 Range-Based Loop

``` cpp
for (int x : s) {
    cout << x << " ";
}
```

The order is unspecified.

------------------------------------------------------------------------

## 22.5 `cbegin()` and `cend()`

``` cpp
auto it = s.cbegin();
auto end = s.cend();
```

These provide constant iterators.

------------------------------------------------------------------------

# 23. Capacity Functions

## 23.1 `empty()`

``` cpp
if (s.empty()) {
    cout << "Set is empty";
}
```

Returns `true` or `false`.

------------------------------------------------------------------------

## 23.2 `size()`

``` cpp
cout << s.size();
```

Example:

``` cpp
unordered_set<int> s = {10, 20, 30};

cout << s.size();
```

Output:

``` text
3
```

------------------------------------------------------------------------

## 23.3 `max_size()`

``` cpp
cout << s.max_size();
```

Returns the maximum number of elements the container can theoretically
hold, subject to implementation and system limitations.

------------------------------------------------------------------------

# 24. Element Access

`unordered_set` does not provide:

``` cpp
operator[]
```

or:

``` cpp
at()
```

because it is not a positional-access or key-to-value container.

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

# 25. Modifiers

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

------------------------------------------------------------------------

# 26. `insert()`

Inserts an element.

``` cpp
unordered_set<int> s;

s.insert(30);
s.insert(10);
s.insert(20);
```

All three values are stored.

------------------------------------------------------------------------

## 26.1 Return Value

For single-element insertion:

``` cpp
auto result = s.insert(10);
```

The result contains:

``` text
iterator
bool
```

The boolean indicates whether insertion took place.

``` cpp
if (result.second) {
    cout << "Inserted";
}
else {
    cout << "Already exists";
}
```

------------------------------------------------------------------------

## 26.2 Duplicate Insertion

``` cpp
unordered_set<int> s;

s.insert(10);
s.insert(10);
```

Only one `10` exists.

------------------------------------------------------------------------

## 26.3 Range Insert

``` cpp
vector<int> values = {10, 20, 30};

s.insert(values.begin(), values.end());
```

------------------------------------------------------------------------

## 26.4 Insert with Hint

``` cpp
auto hint = s.begin();

s.insert(hint, 25);
```

A hint is accepted, but because this is a hash-based container, it does
not have the same ordered-position meaning as a hint for `set`.

------------------------------------------------------------------------

# 27. `emplace()`

`emplace()` constructs an element in place.

For simple values:

``` cpp
s.emplace(40);
```

For custom objects:

``` cpp
unordered_set<Student> students;

students.emplace(101, "Amit");
```

This can construct the object directly in the container's node.

------------------------------------------------------------------------

# 28. `erase()`

There are several ways to erase elements.

## 28.1 Erase by Value

``` cpp
s.erase(20);
```

For `unordered_set`, the return value is:

``` text
0 -> value did not exist
1 -> value existed and was erased
```

------------------------------------------------------------------------

## 28.2 Erase by Iterator

``` cpp
auto it = s.find(20);

if (it != s.end()) {
    s.erase(it);
}
```

------------------------------------------------------------------------

## 28.3 Erase Range

``` cpp
s.erase(s.begin(), s.end());
```

This removes all elements.

------------------------------------------------------------------------

# 29. `clear()`

Removes all elements.

``` cpp
s.clear();
```

After this:

``` text
s.empty() -> true
```

------------------------------------------------------------------------

# 30. `swap()`

Swaps two unordered sets.

``` cpp
unordered_set<int> s1 = {1, 2, 3};
unordered_set<int> s2 = {10, 20, 30};

s1.swap(s2);
```

After:

``` text
s1 -> 10 20 30
s2 -> 1 2 3
```

------------------------------------------------------------------------

# 31. `extract()` --- C++17

`extract()` removes a node and returns a node handle.

``` cpp
unordered_set<int> s = {10, 20, 30};

auto node = s.extract(20);
```

Now:

``` text
s:
10
30
```

The extracted value is owned by:

``` cpp
node
```

The node can be inserted into another compatible unordered associative
container.

------------------------------------------------------------------------

# 32. `merge()` --- C++17

`merge()` transfers compatible nodes from one unordered set to another.

Example:

``` cpp
unordered_set<int> a = {1, 2, 3};
unordered_set<int> b = {3, 4, 5};

a.merge(b);
```

Result:

``` text
a:
1 2 3 4 5
```

and:

``` text
b:
3
```

Why does `3` remain in `b`?

Because `a` already contains `3`.

`unordered_set` cannot contain duplicates.

------------------------------------------------------------------------

# 33. Lookup Functions

Important lookup functions include:

``` cpp
find()
count()
contains()
```

Unlike `set`, `unordered_set` does not provide:

``` cpp
lower_bound()
upper_bound()
equal_range()
```

because it does not maintain an ordering relation.

------------------------------------------------------------------------

# 34. `find()`

Searches for an element.

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
unordered_set<int> s = {10, 20, 30};

auto it = s.find(20);

if (it != s.end()) {
    cout << "Found: " << *it;
}
```

Output:

``` text
Found: 20
```

------------------------------------------------------------------------

# 35. `count()`

For `unordered_set`, values are unique.

Therefore:

``` cpp
s.count(20);
```

returns:

``` text
0 -> value does not exist
1 -> value exists
```

Example:

``` cpp
if (s.count(20)) {
    cout << "Found";
}
```

------------------------------------------------------------------------

# 36. `contains()` --- C++20

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

When you only need an existence check, `contains()` is often the
clearest choice.

------------------------------------------------------------------------

# 37. Observers

`std::unordered_set` provides:

``` cpp
hash_function()
key_eq()
```

These expose the hash and equality objects used by the container.

------------------------------------------------------------------------

# 38. `hash_function()`

Returns the hash function object.

Example:

``` cpp
unordered_set<int> s;

auto hasher = s.hash_function();

cout << hasher(10);
```

The exact numeric result is implementation-dependent.

For custom hash types:

``` cpp
struct MyHash {

    size_t operator()(int x) const {
        return std::hash<int>{}(x);
    }
};
```

------------------------------------------------------------------------

# 39. `key_eq()`

Returns the equality predicate.

Example:

``` cpp
unordered_set<int> s;

auto equal = s.key_eq();

cout << equal(10, 10);
```

Output:

``` text
1
```

The predicate determines whether two keys are considered equivalent.

------------------------------------------------------------------------

# 40. Custom Hash

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
unordered_set<int, MyHash> s;
```

The hash functor should generally be: - Callable with the key type -
Consistent - Suitable for distributing values

------------------------------------------------------------------------

# 41. Custom Equality

You can also provide a custom equality predicate.

``` cpp
struct MyEqual {

    bool operator()(int a, int b) const {
        return a == b;
    }

};
```

Then:

``` cpp
unordered_set<int, MyHash, MyEqual> s;
```

------------------------------------------------------------------------

# 42. Custom Hash + Equality

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

Then:

``` cpp
unordered_set<Student, StudentHash> students;
```

Here:

``` text
Equality -> compares id
Hash     -> hashes id
```

Therefore the two functions agree on the same notion of equivalence.

------------------------------------------------------------------------

# Important Rule

If:

``` cpp
a == b
```

is true according to the equality predicate, then:

``` text
hash(a) == hash(b)
```

must also be true.

The reverse is not required:

``` text
hash(a) == hash(b)
```

does not mean:

``` text
a == b
```

because hash collisions are allowed.

------------------------------------------------------------------------

# 43. Custom Objects

`unordered_set` can store custom objects.

Example:

``` cpp
class Student {

public:

    int id;
    string name;

    bool operator==(const Student& other) const {
        return id == other.id;
    }
};
```

Then provide a hash:

``` cpp
struct StudentHash {

    size_t operator()(const Student& s) const {
        return std::hash<int>{}(s.id);
    }
};
```

Use:

``` cpp
unordered_set<Student, StudentHash> students;
```

Now uniqueness is based on:

``` text
id
```

So:

``` text
Student{101, "Amit"}
Student{101, "Rahul"}
```

are considered equivalent if the equality predicate compares only `id`.

Only one can be stored.

------------------------------------------------------------------------

# 44. `std::pair` with `unordered_set`

You can store pairs, but the standard library does not universally
provide a `std::hash<std::pair<...>>` specialization suitable for every
standard/version combination.

A custom hash is a portable approach.

Example:

``` cpp
struct PairHash {

    size_t operator()(const pair<int, int>& p) const {

        size_t h1 = std::hash<int>{}(p.first);
        size_t h2 = std::hash<int>{}(p.second);

        return h1 ^ (h2 << 1);
    }
};
```

Then:

``` cpp
unordered_set<pair<int, int>, PairHash> s;
```

Example:

``` cpp
s.insert({1, 2});
s.insert({2, 3});
s.insert({1, 2});
```

Only unique pairs remain.

------------------------------------------------------------------------

# 45. Move Semantics

Example:

``` cpp
unordered_set<int> s1 = {1, 2, 3};
unordered_set<int> s2(std::move(s1));
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

# 46. Why Unordered Set Elements Cannot Be Modified

Suppose:

``` cpp
unordered_set<int> s = {10, 20, 30};
```

You might try:

``` cpp
auto it = s.find(20);
*it = 50;
```

This is not allowed.

Why?

Because changing an element can change its hash value and therefore its
correct bucket.

For example:

``` text
20
 ↓
hash(20)
 ↓
Bucket 3
```

If changed to:

``` text
50
 ↓
hash(50)
 ↓
Bucket 7
```

the element would be in the wrong bucket.

Therefore unordered associative container elements are treated as const
through ordinary iterators.

------------------------------------------------------------------------

# 47. Changing an Element

Suppose you want:

``` text
20 -> 50
```

You cannot directly modify it.

### Traditional method

``` cpp
auto it = s.find(20);

if (it != s.end()) {
    s.erase(it);
    s.insert(50);
}
```

### C++17 Node Handle Method

``` cpp
auto node = s.extract(20);

if (!node.empty()) {

    node.value() = 50;

    s.insert(std::move(node));
}
```

The node can be modified while it is outside the container.

The value is reinserted so the container can place it according to the
new hash/equality state.

------------------------------------------------------------------------

# 48. Bucket Interface

Useful bucket functions:

``` cpp
bucket_count()
bucket(key)
bucket_size(n)
```

------------------------------------------------------------------------

## 48.1 `bucket_count()`

Returns the number of buckets.

``` cpp
cout << s.bucket_count();
```

------------------------------------------------------------------------

## 48.2 `bucket(key)`

Returns the bucket index for a key.

``` cpp
cout << s.bucket(20);
```

The exact bucket index depends on the current container state.

------------------------------------------------------------------------

## 48.3 `bucket_size(n)`

Returns the number of elements in bucket `n`.

``` cpp
size_t b = s.bucket(20);

cout << s.bucket_size(b);
```

------------------------------------------------------------------------

## 48.4 Iterating a Bucket

You can inspect elements in a specific bucket:

``` cpp
size_t b = s.bucket(20);

for (auto it = s.begin(b); it != s.end(b); ++it) {
    cout << *it << " ";
}
```

These are local iterators.

------------------------------------------------------------------------

# 49. Hash Policy

Important hash-policy functions include:

``` cpp
load_factor()
max_load_factor()
rehash()
reserve()
```

------------------------------------------------------------------------

## 49.1 `load_factor()`

``` cpp
cout << s.load_factor();
```

Conceptually:

``` text
size / bucket_count
```

------------------------------------------------------------------------

## 49.2 `max_load_factor()`

Read:

``` cpp
cout << s.max_load_factor();
```

Set:

``` cpp
s.max_load_factor(0.7);
```

------------------------------------------------------------------------

## 49.3 `rehash()`

Requests at least enough buckets for a specified bucket count.

``` cpp
s.rehash(100);
```

This may cause elements to be redistributed.

------------------------------------------------------------------------

## 49.4 `reserve()`

Requests enough buckets to accommodate at least the specified number of
elements without exceeding the current maximum load factor.

``` cpp
s.reserve(1000);
```

Useful when you know approximately how many elements you will insert.

Example:

``` cpp
unordered_set<int> s;

s.reserve(100000);

for (int i = 0; i < 100000; ++i) {
    s.insert(i);
}
```

This can reduce the number of rehashes.

------------------------------------------------------------------------

# 50. Iterator and Reference Rules

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

These may trigger rehashing and therefore invalidate iterators.

A useful mental model:

``` text
unordered_set
      |
      +--> rehash?
             |
          yes -> iterators invalidated
          no  -> existing iterators generally survive insertion
```

------------------------------------------------------------------------

# 51. `unordered_set` vs `set`

  Feature             `unordered_set`     `set`
  ------------------- ------------------- ---------------
  Header              `<unordered_set>`   `<set>`
  Unique              Yes                 Yes
  Sorted              No                  Yes
  Typical structure   Hash table          Balanced tree
  Search              O(1) average        O(log n)
  Insert              O(1) average        O(log n)
  Erase               O(1) average        O(log n)
  Worst-case search   O(n)                O(log n)
  `lower_bound()`     No                  Yes
  `upper_bound()`     No                  Yes
  `contains()`        C++20               C++20
  Requires hash       Yes                 No
  Requires ordering   No                  Yes
  Ordered iteration   No                  Yes

### Use `unordered_set` when:

``` text
Need unique values
+
Ordering is unnecessary
+
Fast average membership lookup is important
```

### Use `set` when:

``` text
Need unique values
+
Need sorted order
+
Need range queries
```

------------------------------------------------------------------------

# 52. `unordered_set` vs `unordered_multiset`

  Feature            `unordered_set`   `unordered_multiset`
  ------------------ ----------------- ----------------------
  Ordered            No                No
  Duplicate values   No                Yes
  Hash table         Yes               Yes
  Search             O(1) average      O(1) average
  `count()`          0 or 1            Can be \> 1
  `contains()`       C++20             C++20

Example:

``` cpp
unordered_set<int> s = {10, 10, 20};
```

Contains:

``` text
10 20
```

While:

``` cpp
unordered_multiset<int> ms = {10, 10, 20};
```

contains:

``` text
10 10 20
```

------------------------------------------------------------------------

# 53. `unordered_set` vs `vector`

  Feature                `unordered_set`                 `vector`
  ---------------------- ------------------------------- ----------------
  Unique automatically   Yes                             No
  Sorted automatically   No                              No
  Random access          No                              Yes
  Typical lookup         O(1) average                    O(n)
  Storage                Hash buckets + nodes/metadata   Contiguous
  Cache locality         Usually poorer                  Usually better
  Memory overhead        Higher                          Lower
  Duplicate handling     Automatic                       Manual

Use `vector` when: - You need indexing. - You need contiguous storage. -
Data is mostly sequential. - You do not need fast dynamic membership
lookup.

Use `unordered_set` when: - You need uniqueness. - You frequently check
membership. - Ordering is unnecessary.

------------------------------------------------------------------------

# 54. `unordered_set` vs `vector + sort + unique`

For batch data:

``` cpp
vector<int> v;
```

can be processed with:

``` cpp
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```

This may be preferable when: - Data arrives as one large batch. - You
need sorted unique output. - Cache locality matters. - You do not need
incremental membership checks.

Use `unordered_set` when: - Values arrive dynamically. - You need
frequent membership checks during insertion. - Sorted order is not
required.

------------------------------------------------------------------------

# 55. Common Mistakes

## Mistake 1: Expecting sorted order

``` cpp
unordered_set<int> s = {30, 10, 20};
```

Do not expect:

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

`unordered_set` does not provide ordered lookup functions.

Use:

``` cpp
find()
contains()
```

------------------------------------------------------------------------

## Mistake 4: Using indexing

Invalid:

``` cpp
s[0];
```

There is no random access.

------------------------------------------------------------------------

## Mistake 5: Modifying an element directly

Invalid:

``` cpp
auto it = s.find(20);
*it = 50;
```

Use erase/insert or C++17 node handles.

------------------------------------------------------------------------

## Mistake 6: Bad custom hash

A poor hash distribution can cause many collisions.

That can degrade performance toward:

``` text
O(n)
```

for lookup-like operations.

------------------------------------------------------------------------

## Mistake 7: Inconsistent hash and equality

Wrong design:

``` text
a == b
but
hash(a) != hash(b)
```

Equivalent keys must have equal hash values.

------------------------------------------------------------------------

## Mistake 8: Assuming O(1) is guaranteed

The correct statement is:

``` text
Expected average -> O(1)
Worst case       -> O(n)
```

------------------------------------------------------------------------

## Mistake 9: Assuming iterators survive rehash

Operations such as:

``` cpp
reserve()
rehash()
```

can invalidate iterators.

Insertion can also trigger rehashing.

------------------------------------------------------------------------

## Mistake 10: Dereferencing `end()`

Invalid:

``` cpp
cout << *s.end();
```

Always check lookup results.

------------------------------------------------------------------------

# 56. Practical Examples

# Example 1 --- Remove Duplicates

``` cpp
vector<int> values = {
    10, 20, 10, 30, 20, 40
};

unordered_set<int> uniqueValues(
    values.begin(),
    values.end()
);
```

The set contains:

``` text
10
20
30
40
```

Iteration order is unspecified.

------------------------------------------------------------------------

# Example 2 --- Check Existence

``` cpp
unordered_set<int> s = {
    10, 20, 30
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

# Example 3 --- Find a Value

``` cpp
unordered_set<int> s = {
    10, 20, 30
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

------------------------------------------------------------------------

# Example 4 --- Duplicate Detection

``` cpp
vector<int> values = {
    10, 20, 30, 20, 40
};

unordered_set<int> seen;

for (int x : values) {

    if (seen.contains(x)) {
        cout << "Duplicate: " << x << "\n";
    }
    else {
        seen.insert(x);
    }
}
```

Output:

``` text
Duplicate: 20
```

------------------------------------------------------------------------

# Example 5 --- Visited Nodes

A common graph algorithm pattern:

``` cpp
unordered_set<int> visited;

visited.insert(1);

if (!visited.contains(5)) {
    // Visit node 5
}
```

This is useful when node IDs are hashable and ordering is unnecessary.

------------------------------------------------------------------------

# Example 6 --- Reserve Before Many Insertions

``` cpp
unordered_set<int> s;

s.reserve(100000);

for (int i = 0; i < 100000; ++i) {
    s.insert(i);
}
```

This can reduce repeated rehashing.

------------------------------------------------------------------------

# Example 7 --- Erase While Iterating

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

`erase(it)` returns an iterator to the next element.

The remaining set contains the odd values.

------------------------------------------------------------------------

# Example 8 --- Custom Object

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

    unordered_set<Student, StudentHash> students;

    students.insert({101, "Amit"});
    students.insert({102, "Rahul"});
    students.insert({101, "Other"});

    cout << students.size();

    return 0;
}
```

Output:

``` text
2
```

Why?

Because both students with ID `101` are equivalent according to the
equality predicate.

------------------------------------------------------------------------

# Example 9 --- Inspect Buckets

``` cpp
unordered_set<int> s = {
    10, 20, 30, 40
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

This is useful for learning how hash tables are organized.

The actual bucket distribution is implementation-dependent.

------------------------------------------------------------------------

# Example 10 --- Complete Program

``` cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {

    unordered_set<int> numbers;

    // Insert
    numbers.insert(30);
    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(40);
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

    // Find
    if (numbers.find(20) != numbers.end()) {
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

    // Erase
    numbers.erase(20);

    cout << "After erase:\n";

    for (int x : numbers) {
        cout << x << " ";
    }

    return 0;
}
```

The exact element order and bucket statistics are
implementation-dependent.

------------------------------------------------------------------------

# 57. Interview Questions

## Q1. What is `std::unordered_set`?

`std::unordered_set` is an unordered associative STL container that
stores unique elements using hashing.

------------------------------------------------------------------------

## Q2. Does `unordered_set` allow duplicates?

No.

``` cpp
unordered_set<int> s;

s.insert(10);
s.insert(10);
```

Only one `10` exists.

------------------------------------------------------------------------

## Q3. Is `unordered_set` sorted?

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

## Q6. Why can lookup become O(n)?

Because multiple elements can collide into the same bucket.

If the hash distribution is poor or an adversarial input causes many
collisions, lookup can degrade.

------------------------------------------------------------------------

## Q7. What is the difference between `set` and `unordered_set`?

``` text
set
    -> ordered
    -> typically tree-based
    -> O(log n)

unordered_set
    -> unordered
    -> hash-based
    -> O(1) average
```

------------------------------------------------------------------------

## Q8. Why does `unordered_set` not provide `lower_bound()`?

Because it does not maintain elements according to an ordering relation.

`lower_bound()` requires ordered data.

------------------------------------------------------------------------

## Q9. Why can't elements be modified directly?

Because changing a value can change its hash and therefore its correct
bucket.

------------------------------------------------------------------------

## Q10. How do you modify an element?

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
auto node = s.extract(oldValue);

if (!node.empty()) {
    node.value() = newValue;
    s.insert(std::move(node));
}
```

------------------------------------------------------------------------

## Q11. What is `contains()`?

C++20:

``` cpp
s.contains(value)
```

returns whether the value exists.

------------------------------------------------------------------------

## Q12. What is `count()` for `unordered_set`?

Because values are unique:

``` text
0 -> absent
1 -> present
```

------------------------------------------------------------------------

## Q13. What is a bucket?

A bucket is a logical grouping/location in the hash table where elements
associated with a bucket index are organized.

------------------------------------------------------------------------

## Q14. What is a collision?

A collision occurs when different keys lead to the same bucket.

For example:

``` text
key A -> bucket 5
key B -> bucket 5
```

The implementation must handle both elements.

------------------------------------------------------------------------

## Q15. What is load factor?

Conceptually:

``` text
load factor = size / bucket_count
```

It indicates average bucket occupancy.

------------------------------------------------------------------------

## Q16. What is rehashing?

Rehashing changes the bucket organization, usually by creating a new
bucket table and redistributing elements.

------------------------------------------------------------------------

## Q17. Does rehashing change element values?

No.

It changes where the elements are organized internally.

------------------------------------------------------------------------

## Q18. Does rehashing invalidate iterators?

Yes.

A rehash invalidates all iterators.

------------------------------------------------------------------------

## Q19. What is `reserve()`?

It requests enough bucket capacity for at least a specified number of
elements without exceeding the current maximum load factor.

------------------------------------------------------------------------

## Q20. What is `rehash()`?

It requests a bucket count of at least the specified amount, subject to
the container's hash policy.

------------------------------------------------------------------------

## Q21. What is the difference between `reserve()` and `rehash()`?

``` text
reserve(n)
    -> thinks in terms of number of elements

rehash(n)
    -> thinks in terms of number of buckets
```

------------------------------------------------------------------------

## Q22. What is `max_load_factor()`?

It gets or sets the maximum load factor used by the container's
automatic rehash policy.

------------------------------------------------------------------------

## Q23. Can `unordered_set` store custom objects?

Yes, if the type has a suitable hash and equality relation available.

------------------------------------------------------------------------

## Q24. What must be true about custom hash and equality?

If:

``` text
key1 and key2 are equivalent
```

then:

``` text
hash(key1) == hash(key2)
```

must hold.

------------------------------------------------------------------------

## Q25. Can `unordered_set` store `pair`?

Yes, with an appropriate hash function.

------------------------------------------------------------------------

## Q26. Does insertion always have O(1) complexity?

No.

Expected average is O(1), but worst-case can be O(n).

------------------------------------------------------------------------

## Q27. Can `unordered_set` preserve insertion order?

No.

If insertion order is required, use an appropriate
sequence/order-preserving data structure.

------------------------------------------------------------------------

## Q28. Why can `unordered_set` use more memory than vector?

Because hash-based node containers may require: - bucket storage - node
metadata - links or collision-management structures - allocator overhead

------------------------------------------------------------------------

## Q29. When should you use `unordered_set`?

Use it when you need:

``` text
Unique values
+
Fast average membership lookup
+
No ordering requirement
```

------------------------------------------------------------------------

## Q30. When should you use `set` instead?

Use `set` when you need:

``` text
Unique values
+
Sorted order
+
lower_bound()
+
upper_bound()
+
Ordered range queries
```

------------------------------------------------------------------------

# 58. Important C++ Version Features

  Feature                        Standard
  ------------------------------ -----------------------------------
  `std::unordered_set`           C++11
  Range-based `for`              C++11
  `emplace()`                    C++11
  Move construction/assignment   C++11
  `cbegin()` / `cend()`          C++11
  Bucket interface               C++11
  Hash policy functions          C++11
  `extract()`                    C++17
  `merge()`                      C++17
  `contains()`                   C++20
  `try_emplace()`                Not applicable to `unordered_set`
  `insert_or_assign()`           Not applicable to `unordered_set`
  `operator[]`                   Not applicable
  `lower_bound()`                Not applicable
  `upper_bound()`                Not applicable

### Important

Do not copy map or ordered-set APIs blindly into `unordered_set`.

For example:

``` cpp
operator[]
at()
lower_bound()
upper_bound()
```

are not provided by `std::unordered_set`.

------------------------------------------------------------------------

# 59. Quick Reference Table

## Constructors

  Function                            Purpose
  ----------------------------------- ------------------------
  `unordered_set()`                   Empty container
  `unordered_set(initializer_list)`   Initialize from values
  `unordered_set(first, last)`        Initialize from range
  Copy constructor                    Copy container
  Move constructor                    Move container

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
  -------------- -----------------------
  `empty()`      Check empty
  `size()`       Number of elements
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
  `extract()`   Extract node
  `merge()`     Transfer nodes

------------------------------------------------------------------------

## Lookup

  Function       Purpose
  -------------- -------------------------
  `find()`       Find element
  `count()`      Count matching elements
  `contains()`   Check existence

------------------------------------------------------------------------

## Bucket Interface

  Function           Purpose
  ------------------ ----------------------
  `bucket_count()`   Number of buckets
  `bucket(key)`      Bucket index for key
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

# 60. Advantages

## 60.1 Fast Average Lookup

``` text
Expected O(1)
```

This is the primary reason to use `unordered_set`.

------------------------------------------------------------------------

## 60.2 Unique Elements

Duplicates are automatically rejected.

------------------------------------------------------------------------

## 60.3 Fast Average Insertion

Expected:

``` text
O(1)
```

------------------------------------------------------------------------

## 60.4 Fast Average Deletion

Expected:

``` text
O(1)
```

------------------------------------------------------------------------

## 60.5 Dynamic Membership Testing

Excellent for:

``` text
visited
seen
exists
duplicate detection
```

patterns.

------------------------------------------------------------------------

## 60.6 Custom Hashing

You can define hashing for custom data types.

------------------------------------------------------------------------

# 61. Disadvantages

## 61.1 No Ordering

You cannot rely on sorted or insertion order.

------------------------------------------------------------------------

## 61.2 Worst-Case O(n)

Hash collisions can degrade performance.

------------------------------------------------------------------------

## 61.3 More Memory Overhead

Hash buckets and nodes require additional memory.

------------------------------------------------------------------------

## 61.4 Poorer Cache Locality

Compared with contiguous containers such as `vector`, node-based hash
containers often have poorer locality.

------------------------------------------------------------------------

## 61.5 No Range-Based Ordered Operations

No:

``` cpp
lower_bound()
upper_bound()
```

------------------------------------------------------------------------

## 61.6 Rehashing Can Invalidate Iterators

Care is required when holding iterators across operations that may
rehash.

------------------------------------------------------------------------

# 62. Decision Guide

Use this mental model:

``` text
Need a collection of values?
          |
          +-----------------------+
          |                       |
          |                       |
      Unique?                  Duplicates?
          |                       |
         Yes                     Yes
          |                       |
          v                       v
      Need order?             Need order?
          |                       |
       +--+--+                 +--+--+
       |     |                 |     |
      Yes    No               Yes    No
       |      |                 |      |
       v      v                 v      v
      set  unordered_set    multiset unordered_multiset
```

For unique values:

``` text
Need sorted order?
       |
      Yes
       |
       v
      set

Need only fast average membership?
       |
      No ordering
       |
       v
unordered_set
```

------------------------------------------------------------------------

# 63. Summary

## Definition

> `std::unordered_set` is an unordered associative C++ STL container
> that stores unique elements using hashing and provides expected
> average constant-time lookup, insertion, and deletion.

------------------------------------------------------------------------

## Main Properties

``` text
Unique elements
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
O(1) average deletion
       +
O(n) worst case
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

# `std::unordered_set` Mental Model

Remember:

``` text
             std::unordered_set
                     |
                     v
             Unique Values Only
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
          -----------------------
          |          |          |
          v          v          v
       find()     insert()    erase()
          |          |          |
          +----------+----------+
                     |
                     v
              O(1) Average
                     |
                     v
               O(n) Worst Case
```

------------------------------------------------------------------------

# Most Important Interview Points

``` text
1. unordered_set stores unique values.

2. unordered_set does not maintain sorted order.

3. It is hash-table based.

4. It uses a hash function.

5. It uses an equality predicate.

6. find() is O(1) average.

7. insert() is O(1) average.

8. erase() is O(1) average by key.

9. Worst-case lookup can be O(n).

10. unordered_set has no operator[].

11. unordered_set has no at().

12. unordered_set has no lower_bound().

13. unordered_set has no upper_bound().

14. Elements cannot be modified directly through normal iterators.

15. Changing an element can change its hash and bucket.

16. extract() is available from C++17.

17. merge() is available from C++17.

18. contains() is available from C++20.

19. count() returns 0 or 1 for unordered_set.

20. Multiple values can collide into one bucket.

21. Equivalent keys must have equal hash values.

22. Rehashing can invalidate iterators.

23. reserve() prepares for a number of elements.

24. rehash() requests a number of buckets.

25. load_factor() is approximately size / bucket_count.

26. set is ordered; unordered_set is not.

27. unordered_multiset allows duplicate values.

28. vector provides random access; unordered_set does not.

29. Use unordered_set for unique + fast average membership lookup.

30. Use set when ordering or ordered range queries are required.
```

------------------------------------------------------------------------

# Final One-Line Definition

> **`std::unordered_set` is an unordered associative C++ STL container
> that stores unique elements using a hash function and equality
> comparison, providing expected average O(1) lookup, insertion, and
> deletion.**
