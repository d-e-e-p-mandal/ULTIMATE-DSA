# C++ STL `std::unordered_set` — Complete Notes

# Table of Contents

1. Introduction
2. What Is `unordered_set`?
3. Header File
4. Namespace
5. Basic Syntax
6. Template Definition
7. Template Parameters
8. Container Type
9. Hash Table
10. Buckets
11. Hash Function
12. Collision
13. Collision Handling
14. Load Factor
15. Rehashing
16. Characteristics
17. Ordering
18. Uniqueness
19. Complexity Overview
20. Constructors
21. Default Constructor
22. Bucket Count Constructor
23. Custom Hash Constructor
24. Range Constructor
25. Initializer List Constructor
26. Copy Constructor
27. Move Constructor
28. Copy Assignment
29. Move Assignment
30. Initializer-List Assignment
31. `begin()` and `end()`
32. `cbegin()` and `cend()`
33. Reverse Iterators
34. `empty()`
35. `size()`
36. `max_size()`
37. `insert()`
38. `insert()` Return Value
39. `insert()` with Hint
40. `insert()` Range
41. `insert()` Initializer List
42. `emplace()`
43. `emplace_hint()`
44. `erase()` by Key
45. `erase()` by Iterator
46. `erase()` by Range
47. `clear()`
48. `swap()`
49. `extract()`
50. `merge()`
51. `find()`
52. `count()`
53. `contains()`
54. `equal_range()`
55. `bucket_count()`
56. `max_bucket_count()`
57. `bucket_size()`
58. `bucket()`
59. `load_factor()`
60. `max_load_factor()`
61. `rehash()`
62. `reserve()`
63. `hash_function()`
64. `key_eq()`
65. Hash Function Concept
66. Equality Predicate Concept
67. Hash + Equality Relationship
68. Why Hashing Must Be Consistent
69. Custom Hash Functor
70. Custom Equality Functor
71. Custom Hash + Equality
72. Hashing `pair`
73. Hashing Custom Structure
74. Hashing Custom Class
75. Lambda Hashing
76. String `unordered_set`
77. Character `unordered_set`
78. Pointer Values
79. `const` Correctness
80. Iterator Behavior
81. Iterator Invalidation
82. Rehash and Iterators
83. Erase and Iterators
84. Reference and Pointer Stability
85. Why Order Changes
86. Why `unordered_set` Is Not Sorted
87. Why `unordered_set` Can Be Faster Than `set`
88. Average vs Worst-Case Complexity
89. Complexity Table
90. Space Complexity
91. Memory Layout
92. Bucket Diagram
93. Collision Diagram
94. Rehash Diagram
95. `unordered_set` vs `set`
96. `unordered_set` vs `unordered_multiset`
97. `unordered_set` vs `vector`
98. `unordered_set` vs `unordered_map`
99. `unordered_set` vs `set` for Lookup
100. Common Use Cases
101. Duplicate Removal
102. Fast Membership Testing
103. Visited Set in Graph Algorithms
104. Detecting Duplicates
105. Unique IDs
106. Dictionary-Style Membership
107. Complete Example
108. Insert and Find Example
109. Duplicate Example
110. `contains()` Example
111. Custom Hash Example
112. Custom Object Example
113. Bucket Inspection Example
114. Load Factor Example
115. Reserve Example
116. Rehash Example
117. Extract Example
118. Merge Example
119. Traversal Example
120. Non-Destructive Processing
121. Common Mistakes
122. Hash Function Mistakes
123. Comparator Confusion
124. Assuming Sorted Order
125. Assuming Stable Order
126. Assuming Worst Case Is Always O(1)
127. Forgetting `reserve()`
128. Bad Custom Hash
129. Incorrect Equality
130. Mutating Keys
131. Using Mutable Data That Affects Hash
132. Pointer/Reference Misuse
133. Interview Questions
134. C++ Version Features
135. Best Practices
136. Quick Reference
137. Advantages
138. Disadvantages
139. When to Use
140. When Not to Use
141. Final Summary
142. Mental Model
143. One-Line Definition

---

# 1. Introduction

`std::unordered_set` is an associative container provided by the C++ Standard Library.

It stores:

- **Unique elements**
- Using a **hash table**
- Without maintaining sorted order

The most important idea is:

```text
Unique + Hash Table + Fast Average Lookup
```

Example:

```cpp
#include <unordered_set>

std::unordered_set<int> s;

s.insert(30);
s.insert(10);
s.insert(20);
s.insert(10);
```

Only one `10` is stored.

The container guarantees uniqueness, but it does **not** guarantee that iteration produces:

```text
10 20 30
```

The iteration order is unspecified.

---

# 2. What Is `unordered_set`?

`std::unordered_set` is a hash-table-based associative container.

It is designed primarily for:

```text
Fast average-case:
    insert
    find
    erase
    contains
```

Typical average complexity:

```text
O(1)
```

Worst case:

```text
O(n)
```

The worst case can occur when many elements collide into the same bucket or when the hash function distributes values poorly.

---

# 3. Header File

```cpp
#include <unordered_set>
```

Example:

```cpp
#include <iostream>
#include <unordered_set>
```

---

# 4. Namespace

With:

```cpp
using namespace std;
```

you can write:

```cpp
unordered_set<int> s;
```

Without it:

```cpp
std::unordered_set<int> s;
```

For larger applications, explicitly using `std::unordered_set` can make code clearer.

---

# 5. Basic Syntax

```cpp
unordered_set<data_type> name;
```

Examples:

```cpp
unordered_set<int> numbers;
unordered_set<double> values;
unordered_set<string> names;
unordered_set<char> letters;
```

---

# 6. Template Definition

Conceptually:

```cpp
template<
    class Key,
    class Hash = hash<Key>,
    class Pred = equal_to<Key>,
    class Allocator = allocator<Key>
>
class unordered_set;
```

The important template parameters are:

```text
Key
Hash
Pred
Allocator
```

---

# 7. Template Parameters

## 7.1 `Key`

The type of element stored.

Example:

```cpp
unordered_set<int>
```

means:

```text
Key = int
```

---

## 7.2 `Hash`

The hash function.

Default:

```cpp
std::hash<Key>
```

It converts a key into a hash value.

Example:

```cpp
unordered_set<int>
```

conceptually uses:

```cpp
std::hash<int>
```

---

## 7.3 `Pred`

The equality predicate.

Default:

```cpp
std::equal_to<Key>
```

It determines whether two keys are considered equivalent.

---

## 7.4 `Allocator`

Controls memory allocation.

Default:

```cpp
std::allocator<Key>
```

Most applications do not need to customize this.

---

# 8. Container Type

`unordered_set` is an:

```text
Associative container
```

and more specifically:

```text
Unordered associative container
```

Unlike:

```cpp
set
```

it does not maintain elements in sorted order.

Unlike:

```cpp
vector
```

it is designed around key lookup rather than positional access.

---

# 9. Hash Table

The core data structure behind `unordered_set` is a:

```text
Hash Table
```

Conceptually:

```text
Key
 |
 v
Hash Function
 |
 v
Hash Value
 |
 v
Bucket Index
 |
 v
Bucket
 |
 v
Stored Element
```

Example:

```text
hash(42)
   |
   v
bucket 5
   |
   v
42
```

---

# 10. Buckets

An `unordered_set` is divided into buckets.

Conceptually:

```text
Bucket 0
Bucket 1
Bucket 2
Bucket 3
Bucket 4
Bucket 5
...
```

Each key is assigned to a bucket based on its hash.

The exact internal implementation is implementation-dependent. The standard specifies the behavior and bucket interface, not one mandatory physical hash-table layout.

---

# 11. Hash Function

A hash function maps a key to a hash value.

Conceptually:

```cpp
size_t hash_value = hash(key);
```

The bucket is selected using the hash value and the current bucket count.

Conceptually:

```text
bucket index =
    hash(key) % bucket_count
```

The exact implementation may differ, so treat this as the conceptual model rather than a required implementation formula.

---

# 12. Collision

A collision occurs when two different keys map to the same bucket.

Example:

```text
hash(10) -> bucket 2
hash(20) -> bucket 2
```

Then:

```text
Bucket 2
   |
   +-- 10
   |
   +-- 20
```

A good hash function attempts to distribute keys uniformly to reduce collisions.

---

# 13. Collision Handling

The C++ standard does not require one specific collision-resolution implementation.

A common conceptual model is:

```text
Bucket
  |
  +--> element
  +--> element
  +--> element
```

Many implementations use separate chaining-like structures, but implementations may use other internal strategies.

The important public concept is:

```text
multiple keys can occupy the same bucket
```

and lookup checks the bucket using both:

```text
hash
+
key equality
```

---

# 14. Load Factor

Load factor measures how full the hash table is.

Definition:

```text
load factor =
number of elements
------------------
number of buckets
```

C++ provides:

```cpp
s.load_factor();
```

Example:

```cpp
cout << s.load_factor();
```

A high load factor generally means more elements per bucket and potentially more collisions.

---

# 15. Rehashing

When the hash table needs more buckets, it may perform:

```text
Rehashing
```

Conceptually:

```text
Old table

Bucket 0
Bucket 1
Bucket 2
Bucket 3

       |
       | rehash
       v

New table

Bucket 0
Bucket 1
Bucket 2
Bucket 3
Bucket 4
Bucket 5
Bucket 6
...
```

Elements are redistributed according to the new bucket count.

Rehashing can be expensive, so if you know the expected number of elements, consider:

```cpp
s.reserve(n);
```

---

# 16. Characteristics

Important characteristics:

- Stores unique keys.
- Hash-table based.
- Not sorted.
- Average O(1) lookup.
- Average O(1) insertion.
- Average O(1) erase by key.
- Worst-case O(n) for many operations.
- Supports custom hash functions.
- Supports custom equality predicates.
- Supports bucket inspection.
- Supports load-factor control.
- Supports rehashing.
- Does not provide `operator[]`.
- Does not provide positional access.

---

# 17. Ordering

`unordered_set` does **not** maintain sorted order.

Example:

```cpp
unordered_set<int> s;

s.insert(30);
s.insert(10);
s.insert(20);
```

Iteration could produce:

```text
20 10 30
```

or:

```text
30 20 10
```

or another order.

Do not write code that depends on the iteration order.

---

# 18. Uniqueness

Duplicate keys are not stored.

Example:

```cpp
unordered_set<int> s;

s.insert(10);
s.insert(10);
s.insert(10);
```

The set contains only:

```text
10
```

Therefore:

```cpp
s.size()
```

returns:

```text
1
```

---

# 19. Complexity Overview

Typical average complexity:

```text
insert   -> O(1)
find     -> O(1)
erase    -> O(1)
contains -> O(1)
```

Worst case:

```text
O(n)
```

Why?

Because if many elements end up in the same bucket, searching that bucket can require checking many elements.

---

# 20. Constructors

Common constructor categories:

```text
Default
Bucket-count
Hash + equality
Range
Initializer list
Copy
Move
```

The exact overload set varies by C++ standard version.

---

# 21. Default Constructor

```cpp
unordered_set<int> s;
```

Creates an empty unordered set.

---

# 22. Bucket Count Constructor

You can provide an initial bucket count:

```cpp
unordered_set<int> s(100);
```

This requests an initial bucket count.

Important:

> The actual bucket count may differ from the requested value because the implementation chooses a suitable bucket count.

This is not the same as reserving space for exactly 100 elements.

For expected number of elements, prefer:

```cpp
s.reserve(100);
```

---

# 23. Custom Hash Constructor

Example:

```cpp
struct MyHash
{
    size_t operator()(int x) const
    {
        return std::hash<int>{}(x);
    }
};
```

Then:

```cpp
unordered_set<
    int,
    MyHash
> s;
```

---

# 24. Range Constructor

Example:

```cpp
vector<int> v = {
    10, 20, 30, 20
};

unordered_set<int> s(
    v.begin(),
    v.end()
);
```

The duplicate `20` is stored only once.

---

# 25. Initializer List Constructor

Example:

```cpp
unordered_set<int> s = {
    10,
    20,
    30,
    20
};
```

Result:

```text
10
20
30
```

The iteration order is unspecified.

---

# 26. Copy Constructor

```cpp
unordered_set<int> s1 = {
    10, 20, 30
};

unordered_set<int> s2(s1);
```

Now both contain equivalent keys.

Modifying `s2` does not modify `s1`.

---

# 27. Move Constructor

```cpp
unordered_set<int> s1 = {
    10, 20, 30
};

unordered_set<int> s2(
    std::move(s1)
);
```

The underlying resources can be transferred.

After the move:

```text
s2 -> transferred contents
s1 -> valid but unspecified state
```

Do not assume the moved-from set is empty unless specifically guaranteed by the operation.

---

# 28. Copy Assignment

```cpp
unordered_set<int> s1 = {
    1, 2, 3
};

unordered_set<int> s2;

s2 = s1;
```

Now `s2` contains the same keys as `s1`.

---

# 29. Move Assignment

```cpp
s2 = std::move(s1);
```

The resources can be transferred from `s1` to `s2`.

---

# 30. Initializer-List Assignment

```cpp
unordered_set<int> s;

s = {
    10,
    20,
    30
};
```

The old contents are replaced by the new set of keys.

---

# 31. `begin()` and `end()`

`unordered_set` provides iterators.

```cpp
auto it = s.begin();
auto end = s.end();
```

Example:

```cpp
for (auto it = s.begin();
     it != s.end();
     ++it)
{
    cout << *it << " ";
}
```

Remember:

```text
iteration order is unspecified
```

---

# 32. `cbegin()` and `cend()`

For constant iteration:

```cpp
auto it = s.cbegin();
auto end = s.cend();
```

Example:

```cpp
for (auto it = s.cbegin();
     it != s.cend();
     ++it)
{
    cout << *it << " ";
}
```

---

# 33. Reverse Iterators

Unlike `set`, `unordered_set` does not provide:

```cpp
rbegin()
rend()
```

as a standard member interface.

Why?

Because an unordered container has no meaningful reverse ordering.

You should not treat unordered iteration as forward/reverse sorted traversal.

---

# 34. `empty()`

Checks whether the set contains no elements.

```cpp
if (s.empty())
{
    cout << "Empty";
}
```

Typical complexity:

```text
O(1)
```

---

# 35. `size()`

Returns the number of elements.

```cpp
cout << s.size();
```

Typical complexity:

```text
O(1)
```

---

# 36. `max_size()`

Returns the maximum number of elements the container can theoretically hold, subject to implementation and system limitations.

```cpp
cout << s.max_size();
```

This value is generally much larger than a realistic application requirement.

---

# 37. `insert()`

Adds a unique key.

Example:

```cpp
unordered_set<int> s;

s.insert(10);
s.insert(20);
s.insert(30);
```

---

# 38. `insert()` Return Value

For inserting a single key, the result contains:

```text
iterator
bool
```

Example:

```cpp
auto result = s.insert(10);
```

Conceptually:

```cpp
result.first
```

is an iterator.

```cpp
result.second
```

is:

```text
true  -> insertion happened
false -> key already existed
```

Example:

```cpp
auto [it, inserted] = s.insert(10);

if (inserted)
{
    cout << "Inserted";
}
else
{
    cout << "Already exists";
}
```

This is extremely useful for duplicate detection.

---

# 39. `insert()` with Hint

You can provide an iterator hint:

```cpp
s.insert(s.begin(), 50);
```

Unlike `set`, the hint is generally less useful for unordered containers because the hash determines the bucket.

Do not expect a hint to provide the same kind of ordering benefit as in a tree-based ordered container.

---

# 40. `insert()` Range

Insert elements from a range:

```cpp
vector<int> v = {
    10, 20, 30
};

s.insert(v.begin(), v.end());
```

Duplicates are ignored.

---

# 41. `insert()` Initializer List

```cpp
s.insert({
    10,
    20,
    30
});
```

---

# 42. `emplace()`

Constructs an element in place.

For simple types:

```cpp
s.emplace(10);
```

For custom objects:

```cpp
s.emplace(
    101,
    "Amit"
);
```

This can avoid constructing a temporary object separately.

---

# 43. `emplace_hint()`

Constructs an element using a hint:

```cpp
s.emplace_hint(
    s.begin(),
    100
);
```

As with `insert` hints, the hint is generally not as important for an unordered container because hashing determines placement.

---

# 44. `erase()` by Key

Remove a key:

```cpp
s.erase(20);
```

Returns the number of elements removed.

For `unordered_set`, it is:

```text
0 or 1
```

because keys are unique.

---

# 45. `erase()` by Iterator

Example:

```cpp
auto it = s.find(20);

if (it != s.end())
{
    s.erase(it);
}
```

The element is removed.

---

# 46. `erase()` by Range

Example:

```cpp
s.erase(
    s.begin(),
    s.end()
);
```

This removes all elements.

Equivalent in effect to:

```cpp
s.clear();
```

although `clear()` expresses the intent more clearly.

---

# 47. `clear()`

Removes all elements:

```cpp
s.clear();
```

After:

```cpp
s.empty()
```

returns:

```text
true
```

Important:

> `clear()` removes elements, but it does not necessarily reduce the bucket count. If you need to control bucket capacity, use `rehash()` appropriately.

---

# 48. `swap()`

Exchange contents:

```cpp
s1.swap(s2);
```

Example:

```cpp
unordered_set<int> s1 = {
    1, 2, 3
};

unordered_set<int> s2 = {
    10, 20
};

s1.swap(s2);
```

---

# 49. `extract()` — C++17

C++17 introduced node handles.

Example:

```cpp
auto node = s.extract(20);
```

This removes the node from the container without destroying the stored object immediately.

You can inspect:

```cpp
node.value();
```

If no such key exists:

```cpp
node.empty()
```

is true.

Node handles can be inserted into another compatible container.

---

# 50. `merge()` — C++17

Moves elements from one unordered set into another when possible.

Example:

```cpp
unordered_set<int> a = {
    1, 2, 3
};

unordered_set<int> b = {
    3, 4, 5
};

a.merge(b);
```

Result:

```text
a:
1 2 3 4 5

b:
3
```

Why does `3` remain in `b`?

Because `a` already contains:

```text
3
```

The duplicate cannot be inserted.

---

# 51. `find()`

Searches for a key.

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
if (s.find(20) != s.end())
{
    cout << "Found";
}
```

Average complexity:

```text
O(1)
```

Worst case:

```text
O(n)
```

---

# 52. `count()`

For `unordered_set`, keys are unique.

Therefore:

```cpp
s.count(20);
```

returns:

```text
0 or 1
```

Example:

```cpp
if (s.count(20))
{
    cout << "Exists";
}
```

Average complexity:

```text
O(1)
```

---

# 53. `contains()` — C++20

Modern C++ provides:

```cpp
s.contains(20)
```

Example:

```cpp
if (s.contains(20))
{
    cout << "Exists";
}
```

This is often clearer than:

```cpp
s.find(20) != s.end()
```

or:

```cpp
s.count(20) != 0
```

Average complexity:

```text
O(1)
```

---

# 54. `equal_range()`

Returns the range of elements equivalent to a key.

For `unordered_set`, there can be at most one equivalent element.

Example:

```cpp
auto range = s.equal_range(20);
```

The result is a pair:

```text
first  -> lower boundary
second -> upper boundary
```

For an unordered set, this range contains either:

```text
zero elements
```

or:

```text
one element
```

---

# 55. `bucket_count()`

Returns the current number of buckets.

```cpp
cout << s.bucket_count();
```

Important:

```text
bucket count != element count
```

Example:

```text
Elements = 10
Buckets  = 13
```

The exact bucket count is implementation-dependent.

---

# 56. `max_bucket_count()`

Returns the maximum number of buckets the container can support.

```cpp
cout << s.max_bucket_count();
```

The value is implementation-dependent.

---

# 57. `bucket_size()`

Returns the number of elements in a specific bucket.

Syntax:

```cpp
s.bucket_size(bucket_index);
```

Example:

```cpp
for (size_t i = 0;
     i < s.bucket_count();
     ++i)
{
    cout << s.bucket_size(i);
}
```

This is useful for understanding collisions and distribution.

---

# 58. `bucket()`

Returns the bucket index for a key.

Example:

```cpp
size_t b = s.bucket(20);

cout << b;
```

This lets you inspect where the container places a key according to its current hashing configuration.

---

# 59. `load_factor()`

Returns:

```text
size / bucket_count
```

Example:

```cpp
cout << s.load_factor();
```

A higher load factor generally means more elements per bucket.

---

# 60. `max_load_factor()`

Gets the maximum load factor:

```cpp
cout << s.max_load_factor();
```

You can also set it:

```cpp
s.max_load_factor(0.7f);
```

This influences when the container needs to rehash.

Lower values can reduce collisions but may require more buckets and memory.

---

# 61. `rehash()`

Requests that the container have at least the specified number of buckets.

Example:

```cpp
s.rehash(100);
```

The implementation chooses an appropriate bucket count satisfying the request.

Rehashing redistributes elements.

### Important

`rehash()` is about:

```text
number of buckets
```

not directly:

```text
number of elements
```

---

# 62. `reserve()`

Reserves enough buckets for at least the specified number of elements without exceeding the current maximum load factor.

Example:

```cpp
s.reserve(1000);
```

This is useful when you know you will insert many elements.

It can reduce the number of automatic rehashes.

---

# 63. `hash_function()`

Returns the hash function object used by the container.

Example:

```cpp
auto hash = s.hash_function();
```

Conceptually:

```cpp
auto value = hash(20);
```

The exact hash value is implementation-dependent.

---

# 64. `key_eq()`

Returns the equality predicate used by the container.

Example:

```cpp
auto equal = s.key_eq();

if (equal(a, b))
{
    // Keys are equivalent
}
```

The default is conceptually:

```cpp
std::equal_to<Key>
```

---

# 65. Hash Function Concept

A hash function should map equivalent keys to the same hash value.

Conceptually:

```text
key
 ↓
hash function
 ↓
hash value
```

Example:

```cpp
std::hash<int> h;

size_t value = h(100);
```

Do not rely on the numeric hash value being portable across implementations or program runs.

---

# 66. Equality Predicate Concept

Hashing alone is not enough.

The container also needs an equality relation.

Conceptually:

```text
Hash
 +
Equality
 =
Key lookup
```

If two keys are considered equivalent by the equality predicate, their hash values must match.

---

# 67. Hash + Equality Relationship

The fundamental requirement is:

```text
if key_eq(a, b) == true
then
hash(a) == hash(b)
```

The reverse is not required:

```text
hash(a) == hash(b)
```

does not mean:

```text
a == b
```

because collisions are allowed.

---

# 68. Why Hashing Must Be Consistent

Suppose:

```text
a == b
```

but:

```text
hash(a) != hash(b)
```

Then lookup may place the two equivalent keys into different buckets.

That breaks the assumptions required by the unordered container.

Therefore custom hash and equality must be designed together.

---

# 69. Custom Hash Functor

Example:

```cpp
struct MyHash
{
    size_t operator()(int x) const
    {
        return std::hash<int>{}(x);
    }
};
```

Use:

```cpp
unordered_set<
    int,
    MyHash
> s;
```

For simple built-in types, the default hash is usually sufficient.

---

# 70. Custom Equality Functor

Example:

```cpp
struct MyEqual
{
    bool operator()(int a, int b) const
    {
        return a == b;
    }
};
```

Use:

```cpp
unordered_set<
    int,
    std::hash<int>,
    MyEqual
> s;
```

---

# 71. Custom Hash + Equality

For a custom type:

```cpp
struct Student
{
    int id;
    string name;
};
```

Hash:

```cpp
struct StudentHash
{
    size_t operator()(const Student& s) const
    {
        size_t h1 =
            std::hash<int>{}(s.id);

        size_t h2 =
            std::hash<string>{}(s.name);

        return h1 ^
               (h2 + 0x9e3779b9 +
                (h1 << 6) +
                (h1 >> 2));
    }
};
```

Equality:

```cpp
struct StudentEqual
{
    bool operator()(
        const Student& a,
        const Student& b
    ) const
    {
        return a.id == b.id &&
               a.name == b.name;
    }
};
```

Use:

```cpp
unordered_set<
    Student,
    StudentHash,
    StudentEqual
> students;
```

---

# 72. Hashing `pair`

`std::hash` does not universally provide a standard specialization for every compound type such as `std::pair` across all language/library versions.

A portable approach is to provide your own hash.

Example:

```cpp
struct PairHash
{
    size_t operator()(
        const pair<int,int>& p
    ) const
    {
        size_t h1 =
            std::hash<int>{}(p.first);

        size_t h2 =
            std::hash<int>{}(p.second);

        return h1 ^
               (h2 + 0x9e3779b9 +
                (h1 << 6) +
                (h1 >> 2));
    }
};
```

Then:

```cpp
unordered_set<
    pair<int,int>,
    PairHash
> s;
```

---

# 73. Hashing Custom Structure

Example:

```cpp
struct Point
{
    int x;
    int y;
};
```

Hash:

```cpp
struct PointHash
{
    size_t operator()(
        const Point& p
    ) const
    {
        size_t h1 =
            std::hash<int>{}(p.x);

        size_t h2 =
            std::hash<int>{}(p.y);

        return h1 ^
               (h2 + 0x9e3779b9 +
                (h1 << 6) +
                (h1 >> 2));
    }
};
```

Equality:

```cpp
struct PointEqual
{
    bool operator()(
        const Point& a,
        const Point& b
    ) const
    {
        return a.x == b.x &&
               a.y == b.y;
    }
};
```

Use:

```cpp
unordered_set<
    Point,
    PointHash,
    PointEqual
> points;
```

---

# 74. Hashing Custom Class

Example:

```cpp
class Employee
{
public:

    int id;

    string name;
};
```

You need to define:

```text
Hash
+
Equality
```

before using the class as a key in `unordered_set`.

Example:

```cpp
struct EmployeeHash
{
    size_t operator()(
        const Employee& e
    ) const
    {
        return std::hash<int>{}(e.id);
    }
};
```

Equality:

```cpp
struct EmployeeEqual
{
    bool operator()(
        const Employee& a,
        const Employee& b
    ) const
    {
        return a.id == b.id;
    }
};
```

Here, employees are considered equivalent based only on `id`.

---

# 75. Lambda Hashing

You can define a lambda hash:

```cpp
auto hash = [](const pair<int,int>& p)
{
    return std::hash<int>{}(p.first) ^
           (std::hash<int>{}(p.second) << 1);
};
```

Then:

```cpp
using PairSet =
    unordered_set<
        pair<int,int>,
        decltype(hash)
    >;

PairSet s(10, hash);
```

If you need custom equality as well:

```cpp
auto equal =
    [](const pair<int,int>& a,
       const pair<int,int>& b)
    {
        return a == b;
    };
```

Then the constructor/type must include both function-object types.

---

# 76. String `unordered_set`

Example:

```cpp
unordered_set<string> names;

names.insert("Amit");
names.insert("Rahul");
names.insert("Deep");
```

Lookup:

```cpp
if (names.contains("Rahul"))
{
    cout << "Found";
}
```

Common uses:

```text
Unique usernames
Blocked words
Visited URLs
Known IDs
Membership lists
```

---

# 77. Character `unordered_set`

```cpp
unordered_set<char> letters;

letters.insert('a');
letters.insert('b');
letters.insert('c');
```

Check:

```cpp
if (letters.contains('a'))
{
    cout << "Exists";
}
```

---

# 78. Pointer Values

You can create:

```cpp
unordered_set<int*> pointers;
```

But remember:

```text
pointer identity
```

and:

```text
pointed-to object value
```

are different concepts.

If you insert pointers, the default hashing/equality behavior is based on pointer values, not automatically on the contents of the pointed-to objects.

For ownership and lifetime, use appropriate smart pointers or other ownership designs rather than using raw pointers merely as storage.

---

# 79. `const` Correctness

Elements of an `unordered_set` are treated as keys.

You should not modify an element in a way that changes its hash/equality identity while it is inside the container.

For example, if a custom object's:

```text
id
```

participates in hashing and equality, changing `id` while the object is stored would invalidate the container's assumptions.

This is why set elements are effectively immutable through normal iterators.

---

# 80. Iterator Behavior

`unordered_set` iterators allow traversal:

```cpp
for (auto it = s.begin();
     it != s.end();
     ++it)
{
    cout << *it << " ";
}
```

But iteration order is unspecified.

Do not write:

```cpp
for (...)
{
    // Assume sorted order
}
```

---

# 81. Iterator Invalidation

This is important.

Operations that may rehash can invalidate iterators.

Examples:

```cpp
insert()
emplace()
reserve()
rehash()
```

may cause rehashing.

If rehashing occurs, iterators are invalidated.

Therefore:

```cpp
auto it = s.begin();

s.insert(...);

// Do not assume it is still valid if rehash occurred.
```

---

# 82. Rehash and Iterators

Suppose:

```text
Old buckets
   |
   v
Iterator -> element
```

After rehash:

```text
New buckets
   |
   v
element redistributed
```

The old iterator may no longer be valid.

Therefore, avoid holding iterators across operations that can trigger rehash unless you know the relevant invalidation guarantees.

---

# 83. Erase and Iterators

If you erase an element:

```cpp
auto it = s.find(20);

s.erase(it);
```

the erased iterator is invalid.

Other iterators are generally unaffected by erasing one element, but always consult the exact container invalidation rules when writing iterator-sensitive code.

---

# 84. Reference and Pointer Stability

A useful property of unordered associative containers is that references and pointers to elements generally remain valid across rehashing, even though iterators are invalidated.

However, references/pointers become invalid when their specific element is erased.

Therefore:

```text
Rehash:
    iterators -> invalidated
    references/pointers to existing elements -> generally remain valid

Erase element:
    reference/pointer to erased element -> invalid
```

Use this carefully and follow the standard's exact invalidation guarantees for your operation.

---

# 85. Why Order Changes

Iteration order can change after:

```cpp
insert()
erase()
rehash()
reserve()
```

especially when a rehash occurs.

Even without a visible rehash, you should never depend on unordered iteration order.

---

# 86. Why `unordered_set` Is Not Sorted

A `set` uses an ordering relation such as:

```cpp
less<int>
```

and maintains tree order.

An `unordered_set` uses:

```text
hash
+
equality
```

It does not maintain a global sorted sequence.

Therefore:

```text
set:
    sorted

unordered_set:
    unordered
```

---

# 87. Why `unordered_set` Can Be Faster Than `set`

`set` typically uses a balanced tree.

Search:

```text
O(log n)
```

`unordered_set` uses hashing.

Average search:

```text
O(1)
```

Therefore, for pure membership lookup where ordering is not needed:

```cpp
unordered_set
```

can be significantly faster.

But performance depends on:

- Hash quality
- Key type
- Memory behavior
- Load factor
- Number of elements
- Implementation
- Workload

Do not assume `unordered_set` is always faster.

---

# 88. Average vs Worst-Case Complexity

This distinction is essential.

## Average Case

Good hash distribution:

```text
find -> O(1)
insert -> O(1)
erase -> O(1)
```

## Worst Case

Many collisions:

```text
find -> O(n)
insert -> O(n)
erase -> O(n)
```

The hash function strongly affects practical performance.

---

# 89. Complexity Table

| Operation | Average | Worst Case |
|---|---:|---:|
| `insert()` | O(1) | O(n) |
| `emplace()` | O(1) | O(n) |
| `find()` | O(1) | O(n) |
| `contains()` | O(1) | O(n) |
| `count()` | O(1) | O(n) |
| `erase(key)` | O(1) | O(n) |
| `erase(iterator)` | O(1) average | Depends on operation context |
| `clear()` | O(n) | O(n) |
| `size()` | O(1) | O(1) |
| `empty()` | O(1) | O(1) |
| `swap()` | O(1) | O(1) |
| `rehash()` | Average linear in size | O(n) |
| `reserve()` | Average linear in size when rehashing | O(n) |

Exact standard complexity wording can distinguish average and worst-case behavior; the table above is the practical model.

---

# 90. Space Complexity

For:

```text
N elements
```

space is:

```text
O(N)
```

The container also maintains bucket-related metadata.

Compared with a `set`, an `unordered_set` generally needs:

```text
element storage
+
bucket array
+
collision-management metadata
```

Actual memory overhead depends on the implementation.

---

# 91. Memory Layout

Conceptual model:

```text
unordered_set
       |
       v
+---------------------+
| Bucket Array        |
+---------------------+
| 0                   |
| 1                   |
| 2                   |
| 3                   |
| 4                   |
| 5                   |
+---------------------+
       |
       v
Elements distributed among buckets
```

Do not assume a particular node representation because implementations differ.

---

# 92. Bucket Diagram

Example:

```text
Bucket 0
   |
   +--> 30

Bucket 1
   |
   +--> 11
   +--> 41

Bucket 2
   |
   +--> empty

Bucket 3
   |
   +--> 23

Bucket 4
   |
   +--> 14
```

The elements are not globally sorted.

---

# 93. Collision Diagram

Suppose:

```text
hash(10) -> bucket 2
hash(20) -> bucket 2
hash(30) -> bucket 2
```

Then:

```text
Bucket 2
   |
   +--> 10
   +--> 20
   +--> 30
```

Lookup:

```cpp
s.find(20);
```

uses the hash to identify the relevant bucket and equality to identify the matching key.

---

# 94. Rehash Diagram

Before:

```text
4 buckets

0 -> 10
1 -> 20, 30
2 -> 40
3 -> 50
```

After rehash:

```text
8 buckets

0 -> ...
1 -> ...
2 -> ...
3 -> ...
4 -> ...
5 -> ...
6 -> ...
7 -> ...
```

The elements are redistributed.

---

# 95. `unordered_set` vs `set`

| Feature | `unordered_set` | `set` |
|---|---|---|
| Ordering | No | Sorted |
| Structure | Hash table | Balanced tree |
| Average find | O(1) | O(log n) |
| Worst find | O(n) | O(log n) |
| Duplicates | No | No |
| Iterators | Yes | Yes |
| Sorted traversal | No | Yes |
| Custom hash | Yes | No |
| Custom comparator | Equality/hash | Yes |
| `contains()` | C++20 | C++20 |
| Bucket interface | Yes | No |

Use `unordered_set` when order is unnecessary and fast average lookup is the priority.

Use `set` when sorted order or predictable logarithmic complexity is needed.

---

# 96. `unordered_set` vs `unordered_multiset`

| Feature | `unordered_set` | `unordered_multiset` |
|---|---|---|
| Unique keys | Yes | No |
| Duplicates | No | Yes |
| Hash based | Yes | Yes |
| Average find | O(1) | O(1) |
| `count()` | 0 or 1 | Can be > 1 |

Example:

```cpp
unordered_set<int> s;
```

stores:

```text
10
```

once.

```cpp
unordered_multiset<int> ms;
```

can store:

```text
10
10
10
```

---

# 97. `unordered_set` vs `vector`

| Feature | `unordered_set` | `vector` |
|---|---|---|
| Unique automatically | Yes | No |
| Search | Average O(1) | O(n) |
| Random access | No | Yes |
| Iterators | Yes | Yes |
| Sorted | No | No |
| Memory layout | Hash structure | Contiguous |
| Cache locality | Usually lower | Usually high |
| `push_back()` | No | Yes |

If you only need to scan a small collection, a vector can sometimes be faster despite O(n) lookup because of excellent cache locality.

---

# 98. `unordered_set` vs `unordered_map`

| Feature | `unordered_set` | `unordered_map` |
|---|---|---|
| Stores | Keys | Key-value pairs |
| Unique key | Yes | Yes |
| Value associated with key | No | Yes |
| `operator[]` | No | Yes |
| `find()` | Yes | Yes |
| `contains()` | Yes | Yes |

Use:

```cpp
unordered_set
```

when you only care whether a key exists.

Use:

```cpp
unordered_map
```

when each key needs an associated value.

---

# 99. `unordered_set` vs `set` for Lookup

If the requirement is:

```text
Does this value exist?
```

and no order is needed:

```cpp
unordered_set
```

is often a strong choice.

If the requirement includes:

```text
Find smallest
Find largest
Sorted traversal
Lower/upper bound
Range queries
```

use:

```cpp
set
```

---

# 100. Common Use Cases

`unordered_set` is especially useful for:

- Membership testing
- Duplicate detection
- Unique values
- Visited nodes
- IDs already processed
- Fast exclusion lists
- Unique words
- Unique usernames
- Caching membership information
- Graph traversal
- Tracking active items

---

# 101. Duplicate Removal

Example:

```cpp
vector<int> v = {
    10, 20, 10, 30, 20
};

unordered_set<int> unique(
    v.begin(),
    v.end()
);
```

Now the set contains:

```text
10
20
30
```

The iteration order is unspecified.

If sorted unique values are required, use:

```cpp
set<int>
```

or sort the vector after deduplication depending on the problem.

---

# 102. Fast Membership Testing

Example:

```cpp
unordered_set<string> blocked;

blocked.insert("spam");
blocked.insert("fraud");
blocked.insert("bot");

if (blocked.contains("spam"))
{
    cout << "Blocked";
}
```

Average membership lookup:

```text
O(1)
```

---

# 103. Visited Set in Graph Algorithms

A graph traversal can track visited nodes:

```cpp
unordered_set<int> visited;
```

When visiting:

```cpp
visited.insert(node);
```

Check:

```cpp
if (visited.contains(node))
{
    // Already visited
}
```

This is useful in:

```text
DFS
BFS
Graph traversal
Cycle-related algorithms
```

---

# 104. Detecting Duplicates

Example:

```cpp
vector<int> values = {
    10, 20, 30, 20
};

unordered_set<int> seen;

for (int x : values)
{
    if (seen.contains(x))
    {
        cout << "Duplicate: "
             << x;
    }

    seen.insert(x);
}
```

---

# 105. Unique IDs

Example:

```cpp
unordered_set<int> ids;

if (!ids.insert(1001).second)
{
    cout << "Duplicate ID";
}
```

This uses the return value of `insert()`.

---

# 106. Dictionary-Style Membership

Suppose a system has allowed commands:

```cpp
unordered_set<string> commands = {
    "start",
    "stop",
    "restart"
};
```

Then:

```cpp
if (commands.contains(input))
{
    // Valid command
}
```

This is often more appropriate than scanning a vector for every lookup.

---

# 107. Complete Example

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(10);

    cout << "Size: "
         << s.size()
         << endl;

    if (s.find(20) != s.end())
    {
        cout << "20 Found"
             << endl;
    }

    cout << "Elements: ";

    for (int x : s)
    {
        cout << x << " ";
    }

    return 0;
}
```

Important:

```text
The output order is unspecified.
```

---

# 108. Insert and Find Example

```cpp
unordered_set<int> s;

auto result = s.insert(100);

if (result.second)
{
    cout << "Inserted";
}

auto it = s.find(100);

if (it != s.end())
{
    cout << "Found";
}
```

---

# 109. Duplicate Example

```cpp
unordered_set<int> s;

auto r1 = s.insert(10);
auto r2 = s.insert(10);

cout << boolalpha;

cout << r1.second << endl;
cout << r2.second << endl;
```

Output:

```text
true
false
```

---

# 110. `contains()` Example

C++20:

```cpp
unordered_set<string> names = {
    "Amit",
    "Rahul",
    "Deep"
};

if (names.contains("Rahul"))
{
    cout << "Rahul exists";
}
```

---

# 111. Custom Hash Example

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

struct IntHash
{
    size_t operator()(int x) const
    {
        return hash<int>{}(x);
    }
};

int main()
{
    unordered_set<
        int,
        IntHash
    > s;

    s.insert(10);
    s.insert(20);
    s.insert(30);

    cout << s.contains(20);

    return 0;
}
```

---

# 112. Custom Object Example

```cpp
#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

struct Student
{
    int id;
    string name;
};

struct StudentHash
{
    size_t operator()(
        const Student& s
    ) const
    {
        size_t h1 =
            hash<int>{}(s.id);

        size_t h2 =
            hash<string>{}(s.name);

        return h1 ^
               (h2 + 0x9e3779b9 +
                (h1 << 6) +
                (h1 >> 2));
    }
};

struct StudentEqual
{
    bool operator()(
        const Student& a,
        const Student& b
    ) const
    {
        return a.id == b.id &&
               a.name == b.name;
    }
};

int main()
{
    unordered_set<
        Student,
        StudentHash,
        StudentEqual
    > students;

    students.insert({
        1,
        "Amit"
    });

    students.insert({
        2,
        "Rahul"
    });

    return 0;
}
```

---

# 113. Bucket Inspection Example

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> s = {
        10, 20, 30, 40, 50
    };

    cout << "Bucket count: "
         << s.bucket_count()
         << endl;

    for (size_t i = 0;
         i < s.bucket_count();
         ++i)
    {
        cout << "Bucket "
             << i
             << " size = "
             << s.bucket_size(i)
             << endl;
    }

    return 0;
}
```

This is useful for learning:

```text
hash distribution
collisions
bucket usage
```

---

# 114. Load Factor Example

```cpp
unordered_set<int> s;

for (int i = 0; i < 100; ++i)
{
    s.insert(i);
}

cout << "Size: "
     << s.size()
     << endl;

cout << "Buckets: "
     << s.bucket_count()
     << endl;

cout << "Load factor: "
     << s.load_factor()
     << endl;
```

---

# 115. Reserve Example

If you know that many elements will be inserted:

```cpp
unordered_set<int> s;

s.reserve(10000);

for (int i = 0; i < 10000; ++i)
{
    s.insert(i);
}
```

This can reduce repeated automatic rehashing.

Important:

```text
reserve()
    ↓
capacity planning in terms of elements
```

whereas:

```text
rehash()
    ↓
bucket-count control
```

---

# 116. Rehash Example

```cpp
unordered_set<int> s;

s.insert(10);
s.insert(20);
s.insert(30);

cout << "Before: "
     << s.bucket_count()
     << endl;

s.rehash(100);

cout << "After: "
     << s.bucket_count()
     << endl;
```

The actual bucket count may be greater than or otherwise implementation-selected based on the requested minimum.

---

# 117. Extract Example

C++17:

```cpp
unordered_set<int> s = {
    10, 20, 30
};

auto node = s.extract(20);

if (!node.empty())
{
    cout << node.value();
}
```

After extraction:

```text
s no longer contains 20
```

The node can be inserted into another compatible unordered container:

```cpp
unordered_set<int> other;

other.insert(
    std::move(node)
);
```

---

# 118. Merge Example

```cpp
unordered_set<int> a = {
    1, 2, 3
};

unordered_set<int> b = {
    3, 4, 5
};

a.merge(b);
```

After:

```text
a = {1,2,3,4,5}
b = {3}
```

Iteration order is unspecified.

---

# 119. Traversal Example

```cpp
unordered_set<int> s = {
    10, 20, 30, 40
};

for (auto it = s.begin();
     it != s.end();
     ++it)
{
    cout << *it << " ";
}
```

Or range-for:

```cpp
for (int x : s)
{
    cout << x << " ";
}
```

The second form is usually simpler.

---

# 120. Non-Destructive Processing

Unlike `queue` or `priority_queue`, you do not need to erase elements simply to traverse an `unordered_set`.

You can normally write:

```cpp
for (const auto& x : s)
{
    cout << x << " ";
}
```

The set remains unchanged.

---

# 121. Common Mistakes

## Mistake 1: Assuming Sorted Order

Wrong:

```text
unordered_set = sorted set
```

Correct:

```text
unordered_set = hash-based unordered container
```

---

## Mistake 2: Assuming Iteration Order Is Stable

Do not rely on:

```text
insertion order
```

or:

```text
sorted order
```

---

## Mistake 3: Assuming Every Operation Is Always O(1)

The correct statement is:

```text
Average -> O(1)
Worst   -> O(n)
```

---

# 122. Hash Function Mistakes

A poor hash function can cause:

```text
many collisions
```

which can degrade performance.

Bad distribution:

```text
Bucket 0 -> 1000 elements
Bucket 1 -> empty
Bucket 2 -> empty
...
```

Better:

```text
Elements distributed across many buckets
```

---

# 123. Comparator Confusion

`unordered_set` does not use a sorting comparator like:

```cpp
set<int, Compare>
```

It uses:

```text
Hash
+
Equality Predicate
```

Template parameters:

```cpp
unordered_set<
    Key,
    Hash,
    Pred
>
```

Do not confuse:

```text
set -> ordering comparator
unordered_set -> hash + equality
```

---

# 124. Assuming Sorted Order

This is one of the most common mistakes.

Wrong:

```cpp
for (int x : s)
{
    // Assume x is increasing
}
```

Correct:

```text
Order is unspecified.
```

If sorted order is required, use:

```cpp
set
```

or sort a separate sequence.

---

# 125. Assuming Stable Order

Even if a particular implementation appears to produce:

```text
10 20 30
```

do not assume future operations preserve that order.

Insertions and rehashes can change the iteration sequence.

---

# 126. Assuming Worst Case Is Always O(1)

Correct interview answer:

```text
Average:
O(1)

Worst case:
O(n)
```

This distinction is essential.

---

# 127. Forgetting `reserve()`

If you know:

```text
approximately 1,000,000 elements
```

will be inserted, consider:

```cpp
s.reserve(1'000'000);
```

This can reduce repeated rehashes and improve construction performance.

---

# 128. Bad Custom Hash

A hash such as:

```cpp
return 1;
```

for every key is technically possible but terrible.

Then:

```text
All keys -> same bucket
```

which can cause poor performance.

---

# 129. Incorrect Equality

Suppose:

```cpp
a == b
```

according to the equality predicate, but:

```text
hash(a) != hash(b)
```

This violates the required relationship.

Always ensure:

```text
Equivalent keys
      ↓
Same hash value
```

---

# 130. Mutating Keys

Do not mutate a stored key in a way that changes its hash or equality result while it remains in the container.

Example concept:

```cpp
struct User
{
    int id;
};
```

If `id` is part of the hash and equality, changing:

```cpp
id
```

while the object is stored can make the object effectively unreachable through normal lookup.

The correct approach is generally:

```text
erase old key
insert new key
```

---

# 131. Using Mutable Data That Affects Hash

If your hash uses:

```cpp
id
name
```

then both must remain logically stable while the key is stored.

For a new identity:

```text
remove old key
insert updated key
```

---

# 132. Pointer/Reference Misuse

If you keep:

```cpp
auto& ref = *it;
```

and then erase that element:

```cpp
s.erase(it);
```

the reference is invalid.

Likewise, a pointer/reference to an erased element must not be used afterward.

---

# 133. Interview Questions

## Q1. What is `unordered_set`?

A hash-table-based unordered associative container that stores unique keys.

---

## Q2. Does `unordered_set` store duplicates?

No.

---

## Q3. Is `unordered_set` sorted?

No.

---

## Q4. What is the average complexity of `find()`?

```text
O(1)
```

---

## Q5. What is the worst-case complexity of `find()`?

```text
O(n)
```

---

## Q6. Why can lookup become O(n)?

Because many keys can collide into the same bucket.

---

## Q7. What is the difference between `set` and `unordered_set`?

```text
set:
    ordered
    O(log n)

unordered_set:
    unordered
    O(1) average
```

---

## Q8. Does `unordered_set` use a binary search tree?

No.

It is hash-table based.

---

## Q9. What is a bucket?

A bucket is a hash-table slot/group associated with a bucket index.

---

## Q10. What is a collision?

When multiple keys map to the same bucket.

---

## Q11. What is load factor?

Conceptually:

```text
size / bucket_count
```

---

## Q12. What is rehashing?

Rebuilding the bucket organization with a new bucket count and redistributing elements.

---

## Q13. What does `reserve()` do?

Requests enough bucket capacity for at least the specified number of elements without exceeding the current maximum load factor.

---

## Q14. Difference between `reserve()` and `rehash()`?

```text
reserve(n)
    -> plan for at least n elements

rehash(n)
    -> request at least n buckets
```

---

## Q15. What is `max_load_factor()`?

It controls the maximum load factor threshold used to trigger rehashing.

---

## Q16. What is `bucket_count()`?

Returns the current number of buckets.

---

## Q17. What is `bucket_size(i)`?

Returns the number of elements in bucket `i`.

---

## Q18. What is `bucket(key)`?

Returns the bucket index associated with the key.

---

## Q19. Does `unordered_set` provide iterators?

Yes.

---

## Q20. Does `unordered_set` provide reverse iterators?

It does not provide the standard reverse-iterator interface because there is no intrinsic ordering to reverse.

---

## Q21. Does `unordered_set` support `operator[]`?

No.

---

## Q22. Does `unordered_set` support `contains()`?

Yes, from C++20.

---

## Q23. What does `count()` return?

For `unordered_set`:

```text
0 or 1
```

---

## Q24. What does `insert()` return?

For a single-element insertion, it returns an iterator and a Boolean indicating whether insertion took place.

---

## Q25. Can custom objects be stored?

Yes, if a suitable hash and equality operation are provided.

---

## Q26. What is the default hash?

Conceptually:

```cpp
std::hash<Key>
```

---

## Q27. What is the default equality predicate?

Conceptually:

```cpp
std::equal_to<Key>
```

---

## Q28. What must be true about equivalent keys?

If:

```text
key_eq(a,b) == true
```

then:

```text
hash(a) == hash(b)
```

must hold.

---

## Q29. Can two different keys have the same hash?

Yes.

That is a collision.

---

## Q30. Is the hash value guaranteed to be portable?

No.

Do not rely on exact numeric hash values across implementations or runs.

---

## Q31. Can `pair` be used directly?

Depending on the standard library/version, a hash may not be available automatically. A custom hash is a portable solution.

---

## Q32. What is `extract()`?

C++17 node-handle operation that removes a node without immediately destroying its contained value.

---

## Q33. What is `merge()`?

C++17 operation that transfers compatible elements from one unordered container to another when they are not already present in the destination.

---

## Q34. Are duplicate elements allowed in `unordered_set`?

No.

For duplicates use:

```cpp
unordered_multiset
```

---

## Q35. Is `unordered_set` thread-safe?

The container itself does not provide synchronization for concurrent mutation.

Use appropriate synchronization when multiple threads access the same container and at least one thread modifies it.

---

## Q36. Why can `unordered_set` be faster than `set`?

Average hash lookup is O(1), while tree lookup is O(log n).

---

## Q37. Is `unordered_set` always faster than `set`?

No.

Constant factors, memory locality, hash quality, key type, workload, and implementation matter.

---

## Q38. What happens during rehash?

Elements are redistributed among a new bucket arrangement.

---

## Q39. What happens to iterators during rehash?

They are invalidated.

---

## Q40. What happens to references/pointers during rehash?

References and pointers to elements generally remain valid across rehash, unlike iterators, as long as the elements themselves are not erased.

---

## Q41. Does `clear()` necessarily reduce bucket count?

No.

It removes elements, but bucket capacity is not necessarily reduced.

---

## Q42. How do you force a smaller bucket count?

Use:

```cpp
rehash(n)
```

with an appropriate value.

---

## Q43. What is the average insertion complexity?

```text
O(1)
```

---

## Q44. What is the worst-case insertion complexity?

```text
O(n)
```

---

## Q45. What is the average erase-by-key complexity?

```text
O(1)
```

---

## Q46. What is the worst-case erase-by-key complexity?

```text
O(n)
```

---

## Q47. Why does `unordered_set` not use a comparator?

It does not need a global ordering. It uses hashing and equality.

---

## Q48. Can you get the smallest element efficiently?

Not through the unordered-set interface.

If you need ordered minimum access, consider:

```cpp
set
```

---

## Q49. Can you get sorted traversal efficiently?

Not directly.

Use:

```cpp
set
```

or copy to a vector and sort.

---

## Q50. What is the main use of `unordered_set`?

Fast average-case membership testing for unique keys.

---

# 134. C++ Version Features

| Feature | Standard |
|---|---|
| `std::unordered_set` | C++11 |
| `insert()` | C++11 |
| `find()` | C++11 |
| `count()` | C++11 |
| Bucket interface | C++11 |
| `load_factor()` | C++11 |
| `rehash()` | C++11 |
| `reserve()` | C++11 |
| `emplace()` | C++11 |
| Move operations | C++11 |
| `extract()` | C++17 |
| `merge()` | C++17 |
| `contains()` | C++20 |
| `erase_if()` | C++20 |
| `constexpr` support improvements | C++26 |

---

# 135. Best Practices

## 1. Use `unordered_set` when ordering is unnecessary

Good:

```cpp
unordered_set<int> ids;
```

when you only need:

```text
Does ID exist?
```

---

## 2. Use `contains()` in C++20+

Prefer:

```cpp
if (s.contains(x))
```

when you only need a membership check.

---

## 3. Use `reserve()` when the approximate size is known

```cpp
s.reserve(100000);
```

This can reduce rehashing.

---

## 4. Design custom hashes carefully

Good hash:

```text
Distributes keys reasonably uniformly
```

Bad hash:

```text
All keys -> same bucket
```

---

## 5. Keep key identity stable

Do not modify data that affects:

```text
hash
equality
```

while the key is stored.

---

## 6. Do not rely on iteration order

Never write correctness logic based on the current iteration order.

---

## 7. Use `set` when ordering matters

If you need:

```text
sorted traversal
lower_bound
upper_bound
minimum
maximum
```

prefer:

```cpp
set
```

---

## 8. Consider memory behavior

For very small collections, a vector scan can sometimes outperform a hash table because of cache locality and lower overhead.

Choose based on actual requirements and workload.

---

# 136. Quick Reference

## Declaration

```cpp
unordered_set<int> s;
```

---

## Insert

```cpp
s.insert(10);
```

---

## Emplace

```cpp
s.emplace(10);
```

---

## Find

```cpp
auto it = s.find(10);
```

---

## Contains — C++20

```cpp
s.contains(10);
```

---

## Count

```cpp
s.count(10);
```

---

## Erase

```cpp
s.erase(10);
```

---

## Clear

```cpp
s.clear();
```

---

## Size

```cpp
s.size();
```

---

## Empty

```cpp
s.empty();
```

---

## Iterate

```cpp
for (const auto& x : s)
{
    cout << x;
}
```

---

## Buckets

```cpp
s.bucket_count();
s.bucket_size(i);
s.bucket(key);
```

---

## Load Factor

```cpp
s.load_factor();
s.max_load_factor();
```

---

## Capacity Planning

```cpp
s.reserve(n);
```

---

## Rehash

```cpp
s.rehash(n);
```

---

## Hash

```cpp
s.hash_function();
```

---

## Equality

```cpp
s.key_eq();
```

---

# 137. Advantages

- Fast average-case membership lookup.
- Fast average-case insertion.
- Fast average-case deletion.
- Automatically enforces uniqueness.
- No need to sort manually.
- Supports custom hashing.
- Supports custom equality.
- Useful for large membership sets.
- Excellent for duplicate detection.
- Excellent for visited-node tracking.
- Supports bucket and load-factor inspection.
- C++20 provides convenient `contains()`.

---

# 138. Disadvantages

- No sorted order.
- No predictable iteration order.
- Worst-case operations can be O(n).
- Requires hashing.
- Hash quality affects performance.
- Can use significant memory.
- Bucket storage adds overhead.
- No efficient minimum/maximum operation.
- No `lower_bound()` / `upper_bound()`.
- Iterator invalidation can occur during rehash.
- Custom hashing can be complicated.
- For small collections, vector scanning may sometimes be faster.

---

# 139. When to Use

Use `unordered_set` when:

```text
1. Elements must be unique.
2. You primarily need membership tests.
3. Ordering is not required.
4. Average O(1) lookup is desirable.
5. You need efficient duplicate detection.
6. You need a visited set.
```

Typical examples:

```cpp
unordered_set<int> visited;
unordered_set<string> usernames;
unordered_set<string> blockedWords;
unordered_set<int> processedIds;
```

---

# 140. When Not to Use

Do not choose it when you need:

## Sorted order

Use:

```cpp
set
```

## Duplicates

Use:

```cpp
unordered_multiset
```

## Key-value pairs

Use:

```cpp
unordered_map
```

## Random access

Use:

```cpp
vector
deque
```

## Predictable logarithmic worst-case lookup

Use:

```cpp
set
```

## Small collection with frequent full scans

Consider:

```cpp
vector
```

because cache locality may make it faster.

---

# 141. Final Summary

`std::unordered_set` is a C++ STL **unordered associative container** that stores **unique keys** using a hash table.

Core model:

```text
Key
 ↓
Hash Function
 ↓
Bucket
 ↓
Equality Check
 ↓
Found / Not Found
```

Important properties:

```text
Unique elements
No sorting
Hash based
Average O(1) lookup
Worst O(n) lookup
```

Main operations:

```cpp
insert()
emplace()
erase()
find()
count()
contains()
clear()
swap()
```

Hash-table management:

```cpp
bucket_count()
bucket_size()
bucket()
load_factor()
max_load_factor()
rehash()
reserve()
```

Customization:

```cpp
Hash
Equality Predicate
```

Modern features:

```cpp
extract()   // C++17
merge()     // C++17
contains()  // C++20
erase_if()  // C++20
```

---

# 142. Mental Model

```text
                 std::unordered_set
                         |
                         v
              Unordered Associative
                    Container
                         |
                         v
                    Hash Table
                         |
              +----------+----------+
              |                     |
              v                     v
         Hash Function        Equality Predicate
              |                     |
              v                     v
          Bucket                 Key Match
              |
              v
          Element
```

---

# Membership Lookup Mental Model

```text
contains(50)
     |
     v
hash(50)
     |
     v
find bucket
     |
     v
compare candidate keys
     |
     +---- found ----> true
     |
     +---- not found -> false
```

---

# Collision Mental Model

```text
              Hash Table

Bucket 0
   |
   +--> A

Bucket 1
   |
   +--> B
   +--> C
   +--> D

Bucket 2
   |
   +--> E
```

`B`, `C`, and `D` are in the same bucket.

This is a collision situation.

---

# Rehash Mental Model

```text
Small Bucket Array
        |
        | too many elements /
        | load-factor threshold
        v
     Rehash
        |
        v
Larger Bucket Array
        |
        v
Redistribute Elements
```

---

# `set` vs `unordered_set` Mental Model

```text
set
 |
 +--> Balanced Tree
 |
 +--> Sorted
 |
 +--> O(log n)
 |
 +--> lower_bound()
 +--> upper_bound()
```

```text
unordered_set
 |
 +--> Hash Table
 |
 +--> Unordered
 |
 +--> O(1) average
 |
 +--> contains()
 +--> bucket_count()
 +--> load_factor()
```

---

# 143. One-Line Definition

> **`std::unordered_set` is a C++ STL unordered associative container that stores unique keys in a hash table and provides average O(1) insertion, lookup, and deletion without maintaining sorted order.**
