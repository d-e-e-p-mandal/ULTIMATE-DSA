# C++ STL `std::unordered_map` — Complete 100% Notes

# Table of Contents

1. Introduction
2. What Is `unordered_map`?
3. Header File
4. Namespace
5. Basic Syntax
6. Basic Examples
7. Key-Value Concept
8. Template Definition
9. Template Parameters
10. Key Type
11. Mapped Type
12. Hash Function
13. Key Equality Predicate
14. Allocator
15. Container Adapter vs Associative Container
16. Hash Table
17. Buckets
18. Hashing Process
19. Collision
20. Collision Handling
21. Load Factor
22. Rehashing
23. Characteristics
24. Unique Keys
25. Unordered Nature
26. Complexity Overview
27. Constructors
28. Default Constructor
29. Bucket Count Constructor
30. Custom Hash Constructor
31. Custom Equality Constructor
32. Range Constructor
33. Initializer List Constructor
34. Copy Constructor
35. Move Constructor
36. Copy Assignment
37. Move Assignment
38. Initializer-List Assignment
39. Iterators
40. `begin()`
41. `end()`
42. `cbegin()`
43. `cend()`
44. Iteration
45. No Reverse Ordering
46. `empty()`
47. `size()`
48. `max_size()`
49. `operator[]`
50. `at()`
51. `find()`
52. `contains()`
53. `count()`
54. `equal_range()`
55. `insert()`
56. `insert()` Return Value
57. `insert()` with Hint
58. `insert()` Range
59. `insert()` Initializer List
60. `emplace()`
61. `emplace_hint()`
62. `try_emplace()`
63. `insert_or_assign()`
64. `erase()` by Key
65. `erase()` by Iterator
66. `erase()` by Range
67. `clear()`
68. `swap()`
69. `extract()`
70. `merge()`
71. Bucket Interface
72. `bucket_count()`
73. `max_bucket_count()`
74. `bucket_size()`
75. `bucket()`
76. Hash Policy
77. `load_factor()`
78. `max_load_factor()`
79. `rehash()`
80. `reserve()`
81. Hash Function
82. `hash_function()`
83. Equality Predicate
84. `key_eq()`
85. Hash + Equality Contract
86. Why Equivalent Keys Need Same Hash
87. Default Hash
88. Default Equality
89. Custom Hash Functor
90. Custom Equality Functor
91. Custom Hash + Equality
92. Hashing `pair`
93. Hashing `tuple`
94. Hashing Custom Structure
95. Hashing Custom Class
96. Lambda Hash
97. Nested `unordered_map`
98. `unordered_map<string,int>`
99. `unordered_map<int,string>`
100. `unordered_map<char,int>`
101. `unordered_map<string,vector<int>>`
102. `unordered_map<int,pair<int,int>>`
103. `unordered_map<int,unordered_set<int>>`
104. `unordered_map<string,unordered_map<string,int>>`
105. `operator[]` Important Behavior
106. `operator[]` and Missing Keys
107. `at()` vs `operator[]`
108. `find()` vs `contains()`
109. `insert()` vs `emplace()`
110. `insert()` vs `insert_or_assign()`
111. `insert_or_assign()` vs `try_emplace()`
112. `try_emplace()` Advantages
113. Updating Values
114. Reading Values
115. Deleting Entries
116. Traversing Key-Value Pairs
117. Structured Bindings
118. `auto` Iteration
119. `const` Iteration
120. Modifying Mapped Values
121. Modifying Keys
122. Why Keys Cannot Be Modified Directly
123. Iterator Invalidation
124. Rehash and Iterators
125. Erase and Iterators
126. Reference and Pointer Stability
127. Node Handles
128. Extracting a Node
129. Modifying a Node Key
130. Reinserting a Node
131. Merge
132. Duplicate Keys During Merge
133. Memory Layout
134. Bucket Diagram
135. Collision Diagram
136. Rehash Diagram
137. Key Lookup Diagram
138. Average vs Worst-Case Complexity
139. Complete Complexity Table
140. Space Complexity
141. Performance Factors
142. Hash Quality
143. Load Factor and Performance
144. Reserve for Performance
145. `unordered_map` vs `unordered_set`
146. `unordered_map` vs `map`
147. `unordered_map` vs `unordered_multimap`
148. `unordered_map` vs `vector`
149. `unordered_map` vs `list`
150. `unordered_map` vs `deque`
151. `unordered_map` vs Array
152. `map` vs `unordered_map` Lookup
153. When Ordering Matters
154. Frequency Counting
155. Duplicate Counting
156. Two Sum
157. Caching
158. Memoization
159. Graph Adjacency List
160. Visited Information
161. Indexing Records
162. Grouping Data
163. Counting Characters
164. Counting Words
165. First Non-Repeating Character
166. Top Frequency Problems
167. Complete Example
168. Frequency Counter Program
169. Word Frequency Program
170. Two Sum Program
171. Student Marks Program
172. Custom Object Program
173. Custom Hash Program
174. `operator[]` Program
175. `at()` Program
176. `contains()` Program
177. `try_emplace()` Program
178. `insert_or_assign()` Program
179. Bucket Inspection Program
180. Load Factor Program
181. Reserve Program
182. Rehash Program
183. Extract Program
184. Merge Program
185. Nested Map Program
186. Common Mistakes
187. Assuming Sorted Order
188. Assuming Insertion Order
189. Assuming `operator[]` Only Reads
190. Accidental Default Insertion
191. Calling `at()` on Missing Key
192. Assuming `find()` Returns Value
193. Assuming `insert()` Updates Existing Value
194. Misusing `try_emplace()`
195. Misusing `insert_or_assign()`
196. Bad Custom Hash
197. Incorrect Equality
198. Mutating Key Identity
199. Forgetting Rehash Effects
200. Assuming Every Operation Is O(1)
201. Poor Reserve Strategy
202. Thread Safety
203. Exception Safety Concepts
204. C++ Version Features
205. Interview Questions
206. Best Practices
207. Quick Reference
208. Advantages
209. Disadvantages
210. When to Use
211. When Not to Use
212. Final Summary
213. Mental Model
214. One-Line Definition

---

# 1. Introduction

`std::unordered_map` is a C++ Standard Library **unordered associative container** that stores data as:

```text
Key -> Value
```

Each key is unique.

Example:

```cpp
unordered_map<int, string> students;

students[101] = "Amit";
students[102] = "Rahul";
students[103] = "Deep";
```

Conceptually:

```text
101 -> Amit
102 -> Rahul
103 -> Deep
```

The container uses hashing to locate keys efficiently.

Typical average complexity:

```text
insert   -> O(1)
find     -> O(1)
erase    -> O(1)
```

Worst case:

```text
O(n)
```

The container does **not** maintain keys in sorted order.

---

# 2. What Is `unordered_map`?

`std::unordered_map` is a hash-table-based associative container.

It stores:

```text
unique key + associated mapped value
```

Example:

```cpp
unordered_map<string, int> age;

age["Amit"] = 25;
age["Rahul"] = 30;
```

Data:

```text
Amit  -> 25
Rahul -> 30
```

The key is used for lookup.

The mapped value stores the information associated with the key.

---

# 3. Header File

```cpp
#include <unordered_map>
```

Typical program:

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;
```

---

# 4. Namespace

With:

```cpp
using namespace std;
```

you can write:

```cpp
unordered_map<int, string> m;
```

Without it:

```cpp
std::unordered_map<int, std::string> m;
```

For production code, explicit `std::` qualification can make ownership of names clearer.

---

# 5. Basic Syntax

```cpp
unordered_map<Key, Value> map_name;
```

Example:

```cpp
unordered_map<int, string> students;
```

Here:

```text
Key   = int
Value = string
```

---

# 6. Basic Examples

## Integer to String

```cpp
unordered_map<int, string> users;

users[1] = "Amit";
users[2] = "Rahul";
```

---

## String to Integer

```cpp
unordered_map<string, int> age;

age["Amit"] = 25;
age["Rahul"] = 30;
```

---

## String to Double

```cpp
unordered_map<string, double> price;

price["Pen"] = 10.5;
price["Book"] = 100.0;
```

---

# 7. Key-Value Concept

A map stores entries like:

```text
+--------+---------+
| Key    | Value   |
+--------+---------+
| 101    | Amit    |
| 102    | Rahul   |
| 103    | Deep    |
+--------+---------+
```

Important:

```text
Key   -> identifies the entry
Value -> data associated with the key
```

Keys are unique.

Values do not need to be unique.

Example:

```cpp
unordered_map<int, string> m;

m[1] = "A";
m[2] = "A";
m[3] = "B";
```

This is valid.

---

# 8. Template Definition

Conceptually:

```cpp
template<
    class Key,
    class T,
    class Hash = hash<Key>,
    class Pred = equal_to<Key>,
    class Allocator = allocator<pair<const Key, T>>
>
class unordered_map;
```

The important parameters are:

```text
Key
Mapped Type
Hash
Equality Predicate
Allocator
```

---

# 9. Template Parameters

## `Key`

Type used to identify entries.

```cpp
unordered_map<int, string>
```

Key:

```text
int
```

---

## `T`

Mapped value type.

```cpp
unordered_map<int, string>
```

Mapped type:

```text
string
```

---

## `Hash`

Hash function for keys.

Default:

```cpp
std::hash<Key>
```

---

## `Pred`

Equality predicate for keys.

Default:

```cpp
std::equal_to<Key>
```

---

## `Allocator`

Controls memory allocation.

Default is an allocator for the map's internal value type, conceptually:

```cpp
std::allocator<std::pair<const Key, T>>
```

---

# 10. Key Type

Example:

```cpp
unordered_map<int, string> m;
```

The key type is:

```text
int
```

Keys are used for:

```text
hashing
equality comparison
lookup
```

---

# 11. Mapped Type

In:

```cpp
unordered_map<int, string>
```

the mapped type is:

```text
string
```

It can be any suitable type.

Examples:

```cpp
unordered_map<int, double>
unordered_map<string, vector<int>>
unordered_map<int, pair<int,int>>
```

---

# 12. Hash Function

The hash function converts the key into a hash value.

Conceptually:

```text
Key
 ↓
Hash Function
 ↓
Hash Value
 ↓
Bucket
```

Example:

```cpp
hash<int>{}(100);
```

The exact numeric hash result is implementation-dependent.

---

# 13. Key Equality Predicate

The equality predicate determines whether two keys are equivalent.

Default:

```cpp
equal_to<Key>
```

Conceptually:

```cpp
a == b
```

The map uses both:

```text
hash
+
equality
```

to locate the correct key.

---

# 14. Allocator

The allocator controls how nodes/elements are allocated.

Most normal programs simply use the default allocator.

Custom allocators are useful in specialized:

```text
high-performance
memory-managed
embedded
pool-allocation
```

systems.

---

# 15. Container Adapter vs Associative Container

Do not confuse:

```text
queue / stack / priority_queue
```

with:

```text
map / set / unordered_map / unordered_set
```

`unordered_map` is an:

```text
unordered associative container
```

It is not a container adapter.

---

# 16. Hash Table

The fundamental structure is a hash table.

Conceptually:

```text
Key
 |
 v
Hash Function
 |
 v
Bucket Index
 |
 v
Bucket
 |
 v
Key + Value
```

Example:

```text
"Rahul"
   |
   v
hash("Rahul")
   |
   v
Bucket 4
   |
   v
("Rahul", 30)
```

---

# 17. Buckets

The hash table contains buckets.

Conceptually:

```text
Bucket 0
Bucket 1
Bucket 2
Bucket 3
Bucket 4
...
```

The implementation maps each key to a bucket.

Multiple keys can map to the same bucket.

---

# 18. Hashing Process

Suppose:

```cpp
unordered_map<string, int> m;
```

Lookup:

```cpp
m.find("Rahul");
```

Conceptually:

```text
"Rahul"
   |
   v
hash("Rahul")
   |
   v
bucket index
   |
   v
bucket
   |
   v
compare key
   |
   v
find "Rahul"
```

---

# 19. Collision

A collision occurs when different keys map to the same bucket.

Example:

```text
hash("A") -> bucket 2
hash("B") -> bucket 2
```

Then:

```text
Bucket 2

("A", value)
("B", value)
```

A good hash function tries to distribute keys well.

---

# 20. Collision Handling

The standard does not mandate one exact physical collision implementation.

A conceptual model is:

```text
Bucket 5
   |
   +--> Key A -> Value A
   |
   +--> Key B -> Value B
   |
   +--> Key C -> Value C
```

Lookup first identifies the bucket using the hash and then uses key equality to identify the correct entry.

---

# 21. Load Factor

Load factor is approximately:

```text
number of elements
------------------
number of buckets
```

C++ provides:

```cpp
m.load_factor();
```

Example:

```cpp
cout << m.load_factor();
```

---

# 22. Rehashing

When the number of elements grows relative to the bucket count, the container can rehash.

Conceptually:

```text
Old Table
   |
   | Rehash
   v
New Table
   |
   v
Elements redistributed
```

Rehashing can invalidate iterators.

---

# 23. Characteristics

`unordered_map`:

- Stores key-value pairs.
- Keys are unique.
- Values may repeat.
- Uses hashing.
- Does not sort keys.
- Supports average O(1) lookup.
- Worst-case lookup can be O(n).
- Supports custom hash.
- Supports custom equality.
- Supports bucket inspection.
- Supports load-factor management.
- Provides iterators.
- Provides `operator[]`.
- Provides `at()`.
- Provides `find()`.
- Provides `contains()` from C++20.

---

# 24. Unique Keys

Keys must be unique.

Example:

```cpp
unordered_map<int, string> m;

m[1] = "A";
m[1] = "B";
```

There is still only one key:

```text
1
```

but its value becomes:

```text
B
```

Unlike:

```cpp
unordered_multimap
```

which permits duplicate keys.

---

# 25. Unordered Nature

Do not assume:

```text
insertion order
```

or:

```text
sorted order
```

Example:

```cpp
unordered_map<int, string> m;

m[3] = "C";
m[1] = "A";
m[2] = "B";
```

Iteration might produce:

```text
2 B
3 C
1 A
```

The actual order is unspecified.

---

# 26. Complexity Overview

Typical average complexity:

```text
find()        -> O(1)
contains()    -> O(1)
insert()      -> O(1)
erase(key)    -> O(1)
operator[]    -> O(1) average
```

Worst case:

```text
O(n)
```

for many lookup/update operations.

---

# 27. Constructors

Common constructors include:

```text
Default
Bucket count
Hash
Equality
Range
Initializer list
Copy
Move
```

---

# 28. Default Constructor

```cpp
unordered_map<int, string> m;
```

Creates an empty map.

---

# 29. Bucket Count Constructor

```cpp
unordered_map<int, string> m(100);
```

This requests an initial bucket count.

It does **not** mean:

```text
100 elements
```

will be stored.

If you know the expected number of elements, prefer:

```cpp
m.reserve(100);
```

---

# 30. Custom Hash Constructor

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
unordered_map<
    int,
    string,
    MyHash
> m;
```

---

# 31. Custom Equality Constructor

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
unordered_map<
    int,
    string,
    std::hash<int>,
    MyEqual
> m;
```

---

# 32. Range Constructor

```cpp
vector<pair<int,string>> data = {
    {1, "A"},
    {2, "B"},
    {3, "C"}
};

unordered_map<int,string> m(
    data.begin(),
    data.end()
);
```

---

# 33. Initializer List Constructor

```cpp
unordered_map<int,string> m = {
    {1, "A"},
    {2, "B"},
    {3, "C"}
};
```

---

# 34. Copy Constructor

```cpp
unordered_map<int,string> m1 = {
    {1, "A"},
    {2, "B"}
};

unordered_map<int,string> m2(m1);
```

`m2` receives equivalent key-value entries.

---

# 35. Move Constructor

```cpp
unordered_map<int,string> m2(
    std::move(m1)
);
```

Resources may be transferred from `m1`.

The moved-from object remains valid but has an unspecified state.

---

# 36. Copy Assignment

```cpp
m2 = m1;
```

Copies the entries.

---

# 37. Move Assignment

```cpp
m2 = std::move(m1);
```

Moves the contents/resources where possible.

---

# 38. Initializer-List Assignment

```cpp
m = {
    {1, "A"},
    {2, "B"}
};
```

The map is assigned from the initializer list.

---

# 39. Iterators

`unordered_map` provides iterators.

Example:

```cpp
auto it = m.begin();

while (it != m.end())
{
    cout << it->first
         << " "
         << it->second
         << endl;

    ++it;
}
```

---

# 40. `begin()`

Returns an iterator to the beginning of the unordered container's iteration range.

```cpp
auto it = m.begin();
```

The first element is not necessarily the smallest key.

---

# 41. `end()`

Returns the iterator one position past the last element.

```cpp
auto it = m.end();
```

Never dereference:

```cpp
*m.end();
```

---

# 42. `cbegin()`

Returns a constant iterator:

```cpp
auto it = m.cbegin();
```

Use it when you do not want to modify mapped values through the iterator.

---

# 43. `cend()`

Returns the constant end iterator:

```cpp
auto it = m.cend();
```

---

# 44. Iteration

Range-based loop:

```cpp
for (const auto& entry : m)
{
    cout << entry.first
         << " "
         << entry.second
         << endl;
}
```

---

# 45. No Reverse Ordering

`unordered_map` does not provide meaningful sorted/reverse traversal.

Do not expect:

```cpp
rbegin()
rend()
```

style ordered traversal.

If ordered reverse traversal is required, use an appropriate ordered container or create a sequence and sort it.

---

# 46. `empty()`

Checks whether the map contains no entries.

```cpp
if (m.empty())
{
    cout << "Empty";
}
```

Typical complexity:

```text
O(1)
```

---

# 47. `size()`

Returns number of key-value entries.

```cpp
cout << m.size();
```

Typical complexity:

```text
O(1)
```

---

# 48. `max_size()`

Returns the maximum theoretical number of elements supported by the container under implementation/system constraints.

```cpp
cout << m.max_size();
```

---

# 49. `operator[]`

One of the most important functions.

Example:

```cpp
unordered_map<int,string> m;

m[101] = "Amit";
```

If the key does not exist, `operator[]` inserts a new element with a **value-initialized mapped value**, then returns a reference to that mapped value.

For:

```cpp
unordered_map<int,int>
```

a missing key gets:

```text
0
```

For:

```cpp
unordered_map<int,string>
```

a missing key gets:

```text
""
```

Example:

```cpp
cout << m[500];
```

If `500` does not exist, this expression can insert:

```text
500 -> ""
```

This is a very important behavior.

---

# 50. `at()`

Accesses the mapped value for an existing key.

```cpp
cout << m.at(101);
```

If the key does not exist:

```text
std::out_of_range
```

is thrown.

Unlike `operator[]`, `at()` does not insert a missing key.

---

# 51. `find()`

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

Example:

```cpp
if (it != m.end())
{
    cout << it->second;
}
```

Average complexity:

```text
O(1)
```

---

# 52. `contains()` — C++20

Checks whether a key exists.

```cpp
if (m.contains(101))
{
    cout << "Found";
}
```

It does not insert a missing key.

Average complexity:

```text
O(1)
```

---

# 53. `count()`

For `unordered_map`, keys are unique.

Therefore:

```cpp
m.count(101);
```

returns:

```text
0 or 1
```

Example:

```cpp
if (m.count(101))
{
    cout << "Exists";
}
```

---

# 54. `equal_range()`

Returns the range of entries whose keys are equivalent to the supplied key.

For `unordered_map`, there can be at most one matching key.

```cpp
auto range = m.equal_range(101);
```

The result is:

```text
first
second
```

For a unique-key map, the range contains zero or one element.

---

# 55. `insert()`

Inserts a key-value pair.

```cpp
m.insert({
    101,
    "Amit"
});
```

Another form:

```cpp
m.insert(
    pair<int,string>(
        102,
        "Rahul"
    )
);
```

---

# 56. `insert()` Return Value

Single-element insertion returns:

```text
iterator + bool
```

Example:

```cpp
auto [it, inserted] =
    m.insert({101, "Amit"});
```

If key did not exist:

```text
inserted = true
```

If key already existed:

```text
inserted = false
```

The existing mapped value is not overwritten by `insert()`.

---

# 57. `insert()` with Hint

Example:

```cpp
m.insert(
    m.begin(),
    {100, "A"}
);
```

The hint is generally less important for unordered containers because hashing determines the bucket.

---

# 58. `insert()` Range

```cpp
vector<pair<int,string>> data = {
    {1, "A"},
    {2, "B"},
    {3, "C"}
};

m.insert(
    data.begin(),
    data.end()
);
```

---

# 59. `insert()` Initializer List

```cpp
m.insert({
    {1, "A"},
    {2, "B"},
    {3, "C"}
});
```

---

# 60. `emplace()`

Constructs the map entry in place.

Example:

```cpp
m.emplace(
    101,
    "Amit"
);
```

This is useful for complex mapped values.

---

# 61. `emplace_hint()`

Example:

```cpp
m.emplace_hint(
    m.begin(),
    102,
    "Rahul"
);
```

Again, hints are less important in an unordered container.

---

# 62. `try_emplace()` — C++17

`try_emplace()` inserts only if the key does not already exist.

Example:

```cpp
m.try_emplace(
    101,
    "Amit"
);
```

If `101` already exists, the mapped object is not replaced.

A major advantage is that constructor arguments for the mapped value are only used to construct a value when insertion actually occurs.

---

# 63. `insert_or_assign()` — C++17

This operation:

```text
insert if missing
OR
assign if existing
```

Example:

```cpp
m.insert_or_assign(
    101,
    "Amit"
);
```

If `101` does not exist:

```text
insert
```

If it exists:

```text
replace mapped value
```

---

# 64. `erase()` by Key

```cpp
m.erase(101);
```

Returns the number of elements removed:

```text
0 or 1
```

because keys are unique.

---

# 65. `erase()` by Iterator

```cpp
auto it = m.find(101);

if (it != m.end())
{
    m.erase(it);
}
```

---

# 66. `erase()` by Range

```cpp
m.erase(
    m.begin(),
    m.end()
);
```

This removes all entries.

For clarity, use:

```cpp
m.clear();
```

when the intent is simply to clear everything.

---

# 67. `clear()`

Removes all elements:

```cpp
m.clear();
```

Afterward:

```cpp
m.empty()
```

returns:

```text
true
```

`clear()` does not necessarily reduce the bucket count.

---

# 68. `swap()`

```cpp
m1.swap(m2);
```

Exchanges contents.

Example:

```cpp
unordered_map<int,string> m1 = {
    {1, "A"}
};

unordered_map<int,string> m2 = {
    {2, "B"}
};

m1.swap(m2);
```

---

# 69. `extract()` — C++17

Removes a node and returns a node handle.

```cpp
auto node = m.extract(101);
```

If successful:

```cpp
node.empty()
```

is false.

You can access:

```cpp
node.key();
node.mapped();
```

This is powerful because a node's key can be changed before reinsertion.

---

# 70. `merge()` — C++17

Transfers entries from another compatible map.

```cpp
m1.merge(m2);
```

If a key already exists in `m1`, the conflicting element remains in `m2`.

---

# 71. Bucket Interface

`unordered_map` provides functions to inspect buckets:

```cpp
bucket_count()
max_bucket_count()
bucket_size()
bucket()
```

These are useful for understanding hashing behavior.

---

# 72. `bucket_count()`

Returns current number of buckets.

```cpp
cout << m.bucket_count();
```

Do not confuse:

```text
bucket count
```

with:

```text
number of entries
```

---

# 73. `max_bucket_count()`

Returns the maximum number of buckets supported by the implementation.

```cpp
cout << m.max_bucket_count();
```

---

# 74. `bucket_size()`

Returns the number of entries in a specific bucket.

```cpp
m.bucket_size(i);
```

Example:

```cpp
for (size_t i = 0;
     i < m.bucket_count();
     ++i)
{
    cout << m.bucket_size(i);
}
```

---

# 75. `bucket()`

Returns the bucket index for a key.

```cpp
size_t index =
    m.bucket(101);
```

---

# 76. Hash Policy

Hash-policy functions control or inspect bucket behavior:

```cpp
load_factor()
max_load_factor()
rehash()
reserve()
```

These are important for performance tuning.

---

# 77. `load_factor()`

Returns approximately:

```text
size / bucket_count
```

Example:

```cpp
cout << m.load_factor();
```

---

# 78. `max_load_factor()`

Read:

```cpp
cout << m.max_load_factor();
```

Set:

```cpp
m.max_load_factor(0.7f);
```

A lower maximum load factor may reduce collisions at the cost of additional buckets/memory.

---

# 79. `rehash()`

Requests at least a specified number of buckets:

```cpp
m.rehash(100);
```

The implementation chooses an appropriate actual bucket count.

Rehashing redistributes entries.

---

# 80. `reserve()`

Requests enough buckets to accommodate at least the specified number of elements without exceeding the current maximum load factor.

Example:

```cpp
m.reserve(100000);
```

This is often useful before inserting many entries.

---

# 81. Hash Function

The hash function determines bucket placement.

Conceptually:

```text
Key
 ↓
hash(key)
 ↓
bucket
```

---

# 82. `hash_function()`

Returns the hash function object:

```cpp
auto h = m.hash_function();
```

Then conceptually:

```cpp
auto hashValue = h(101);
```

Exact hash values are implementation-dependent.

---

# 83. Equality Predicate

The equality predicate compares keys.

Default:

```cpp
std::equal_to<Key>
```

---

# 84. `key_eq()`

Returns the equality predicate:

```cpp
auto eq = m.key_eq();
```

Example:

```cpp
if (eq(a, b))
{
    // Keys equivalent
}
```

---

# 85. Hash + Equality Contract

The most important rule:

```text
If two keys are equivalent,
their hash values must be equal.
```

Formally:

```text
key_eq(a,b) == true
        =>
hash(a) == hash(b)
```

The reverse is not required.

Two different keys can have the same hash.

---

# 86. Why Equivalent Keys Need Same Hash

Suppose:

```text
A == B
```

but:

```text
hash(A) != hash(B)
```

Then the two equivalent keys could be placed in different buckets.

That breaks the lookup model.

Therefore:

```text
Equivalent
    ↓
Same hash
```

is mandatory.

---

# 87. Default Hash

For:

```cpp
unordered_map<int,string>
```

the default hash is conceptually:

```cpp
std::hash<int>
```

For:

```cpp
unordered_map<string,int>
```

it is:

```cpp
std::hash<string>
```

---

# 88. Default Equality

The default key equality predicate is conceptually:

```cpp
std::equal_to<Key>
```

For most ordinary types, this corresponds to equality using:

```cpp
operator==
```

---

# 89. Custom Hash Functor

Example:

```cpp
struct IntHash
{
    size_t operator()(int x) const
    {
        return std::hash<int>{}(x);
    }
};
```

Use:

```cpp
unordered_map<
    int,
    string,
    IntHash
> m;
```

---

# 90. Custom Equality Functor

```cpp
struct IntEqual
{
    bool operator()(int a, int b) const
    {
        return a == b;
    }
};
```

Use:

```cpp
unordered_map<
    int,
    string,
    std::hash<int>,
    IntEqual
> m;
```

---

# 91. Custom Hash + Equality

Example:

```cpp
struct Person
{
    int id;
    string name;
};

struct PersonHash
{
    size_t operator()(
        const Person& p
    ) const
    {
        size_t h1 =
            std::hash<int>{}(p.id);

        size_t h2 =
            std::hash<string>{}(p.name);

        return h1 ^
               (h2 + 0x9e3779b9 +
                (h1 << 6) +
                (h1 >> 2));
    }
};

struct PersonEqual
{
    bool operator()(
        const Person& a,
        const Person& b
    ) const
    {
        return a.id == b.id &&
               a.name == b.name;
    }
};
```

Use:

```cpp
unordered_map<
    Person,
    int,
    PersonHash,
    PersonEqual
> people;
```

---

# 92. Hashing `pair`

For compound keys such as:

```cpp
pair<int,int>
```

provide a hash if your standard library does not supply the required specialization.

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

Use:

```cpp
unordered_map<
    pair<int,int>,
    string,
    PairHash
> m;
```

---

# 93. Hashing `tuple`

For:

```cpp
tuple<int,string,double>
```

a custom hash can combine the hashes of all fields.

Conceptually:

```text
hash(field1)
+
hash(field2)
+
hash(field3)
```

then combine them into one hash value.

---

# 94. Hashing Custom Structure

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

Map:

```cpp
unordered_map<
    Point,
    string,
    PointHash
> points;
```

You also need a compatible equality predicate if the type does not already provide an appropriate equality operation for the container.

---

# 95. Hashing Custom Class

Example:

```cpp
class Employee
{
public:

    int id;

    string name;
};
```

Hash:

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

Here the logical key identity is:

```text
id
```

not:

```text
name
```

---

# 96. Lambda Hash

Example:

```cpp
auto hashPair =
    [](const pair<int,int>& p)
    {
        return std::hash<int>{}(p.first) ^
               (std::hash<int>{}(p.second) << 1);
    };
```

Type:

```cpp
decltype(hashPair)
```

Map:

```cpp
using PairMap =
    unordered_map<
        pair<int,int>,
        string,
        decltype(hashPair)
    >;
```

Construct:

```cpp
PairMap m(
    10,
    hashPair
);
```

---

# 97. Nested `unordered_map`

You can store another unordered map as the value.

```cpp
unordered_map<
    int,
    unordered_map<int,string>
> data;
```

Example:

```text
Department
   |
   +--> Employee ID -> Name
```

---

# 98. `unordered_map<string,int>`

Common frequency table:

```cpp
unordered_map<string,int> frequency;

frequency["apple"]++;
frequency["banana"]++;
frequency["apple"]++;
```

Result conceptually:

```text
apple  -> 2
banana -> 1
```

This is one of the most common uses of `unordered_map`.

---

# 99. `unordered_map<int,string>`

Example:

```cpp
unordered_map<int,string> students;

students[101] = "Amit";
students[102] = "Rahul";
```

Lookup:

```cpp
cout << students[101];
```

---

# 100. `unordered_map<char,int>`

Useful for character frequency:

```cpp
unordered_map<char,int> freq;

string s = "banana";

for (char c : s)
{
    freq[c]++;
}
```

Result:

```text
b -> 1
a -> 3
n -> 2
```

---

# 101. `unordered_map<string,vector<int>>`

Useful for grouping.

```cpp
unordered_map<
    string,
    vector<int>
> groups;
```

Example:

```cpp
groups["A"].push_back(10);
groups["A"].push_back(20);
groups["B"].push_back(30);
```

Conceptually:

```text
A -> [10,20]
B -> [30]
```

---

# 102. `unordered_map<int,pair<int,int>>`

Example:

```cpp
unordered_map<
    int,
    pair<int,int>
> points;

points[1] = {10,20};
points[2] = {30,40};
```

---

# 103. `unordered_map<int,unordered_set<int>>`

Useful for graph adjacency or unique neighbor relationships:

```cpp
unordered_map<
    int,
    unordered_set<int>
> graph;
```

Example:

```cpp
graph[1].insert(2);
graph[1].insert(3);
```

Conceptually:

```text
1 -> {2,3}
```

---

# 104. Nested `unordered_map`

Example:

```cpp
unordered_map<
    string,
    unordered_map<
        string,
        int
    >
> data;
```

Usage:

```cpp
data["A"]["Math"] = 90;
data["A"]["Science"] = 85;
```

---

# 105. `operator[]` Important Behavior

This is critical.

Consider:

```cpp
unordered_map<int,int> m;

cout << m[100];
```

If `100` does not exist, the expression inserts:

```text
100 -> 0
```

Then returns a reference to `0`.

Afterward:

```cpp
m.size()
```

is:

```text
1
```

---

# 106. `operator[]` and Missing Keys

For:

```cpp
unordered_map<int,string> m;

m[10];
```

a missing key creates:

```text
10 -> ""
```

For:

```cpp
unordered_map<int,vector<int>> m;

m[10];
```

a missing key creates:

```text
10 -> empty vector
```

The mapped type must be usable with value-initialization/default construction for this operation.

---

# 107. `at()` vs `operator[]`

| Feature | `operator[]` | `at()` |
|---|---|---|
| Missing key | Inserts | Throws |
| Reads value | Yes | Yes |
| Writes value | Yes | Yes |
| Returns reference | Yes | Yes |
| Exception on missing | No | `std::out_of_range` |
| Use for lookup without insertion | No | Yes |

Example:

```cpp
m[10];
```

can insert.

Whereas:

```cpp
m.at(10);
```

does not insert.

---

# 108. `find()` vs `contains()`

`find()`:

```cpp
auto it = m.find(10);

if (it != m.end())
{
    cout << it->second;
}
```

`contains()`:

```cpp
if (m.contains(10))
{
    cout << "Exists";
}
```

Use:

```text
contains()
```

when you only need existence.

Use:

```text
find()
```

when you also need the iterator/value.

---

# 109. `insert()` vs `emplace()`

`insert()`:

```cpp
m.insert({
    1,
    "Amit"
});
```

`emplace()`:

```cpp
m.emplace(
    1,
    "Amit"
);
```

`emplace()` constructs the entry from supplied arguments.

For simple types, the practical performance difference may be small.

---

# 110. `insert()` vs `insert_or_assign()`

`insert()`:

```text
If key exists:
    do not replace value
```

`insert_or_assign()`:

```text
If key exists:
    replace value
```

Example:

```cpp
m.insert({1, "A"});
m.insert({1, "B"});
```

Result:

```text
1 -> A
```

But:

```cpp
m.insert_or_assign(1, "B");
```

Result:

```text
1 -> B
```

---

# 111. `insert_or_assign()` vs `try_emplace()`

`insert_or_assign()`:

```text
insert if missing
assign if existing
```

`try_emplace()`:

```text
insert if missing
do nothing if existing
```

Use:

```text
try_emplace
```

when you want to avoid replacing an existing mapped value.

---

# 112. `try_emplace()` Advantages

Suppose the mapped type is expensive to construct.

```cpp
m.try_emplace(
    key,
    constructor_arguments...
);
```

If the key already exists, the mapped object does not need to be constructed from those arguments.

This can be more efficient than constructing a temporary mapped object before calling `insert()`.

---

# 113. Updating Values

Simple:

```cpp
m[101] = "New Name";
```

If the key exists:

```text
value updated
```

If it does not:

```text
new entry created
```

If you require the key to already exist:

```cpp
m.at(101) = "New Name";
```

---

# 114. Reading Values

Safe lookup without insertion:

```cpp
auto it = m.find(101);

if (it != m.end())
{
    cout << it->second;
}
```

Or C++20:

```cpp
if (m.contains(101))
{
    cout << m.at(101);
}
```

But if you need both existence and value, `find()` is often preferable because it avoids a second lookup.

---

# 115. Deleting Entries

By key:

```cpp
m.erase(101);
```

By iterator:

```cpp
auto it = m.find(101);

if (it != m.end())
{
    m.erase(it);
}
```

All:

```cpp
m.clear();
```

---

# 116. Traversing Key-Value Pairs

```cpp
for (const auto& entry : m)
{
    cout << entry.first
         << " -> "
         << entry.second
         << endl;
}
```

---

# 117. Structured Bindings

C++17:

```cpp
for (const auto& [key, value] : m)
{
    cout << key
         << " -> "
         << value
         << endl;
}
```

This is often the cleanest way to read both key and value.

---

# 118. `auto` Iteration

```cpp
for (auto& entry : m)
{
    cout << entry.first
         << " "
         << entry.second;
}
```

Remember:

```text
entry.first  -> key
entry.second -> mapped value
```

---

# 119. `const` Iteration

If you only read:

```cpp
for (const auto& [key, value] : m)
{
    cout << key
         << value;
}
```

This prevents modification through the loop variables.

---

# 120. Modifying Mapped Values

Mapped values can be modified.

```cpp
unordered_map<int,int> m;

m[1] = 10;

auto it = m.find(1);

if (it != m.end())
{
    it->second = 100;
}
```

Now:

```text
1 -> 100
```

---

# 121. Modifying Keys

You cannot normally modify the key through an ordinary iterator.

Example:

```cpp
it->first = 200;
```

is not allowed.

---

# 122. Why Keys Cannot Be Modified Directly

The key determines:

```text
hash
bucket
identity
```

If the key changed while the element stayed in the same bucket, the container could become inconsistent.

Therefore the map's stored pair is conceptually:

```cpp
pair<const Key, T>
```

The key is effectively immutable through normal access.

If you need to change a key:

```text
extract
modify node key
reinsert
```

---

# 123. Iterator Invalidation

Operations that trigger rehash can invalidate iterators.

Potentially affected operations include:

```cpp
insert()
emplace()
try_emplace()
insert_or_assign()
reserve()
rehash()
```

if they cause rehashing.

---

# 124. Rehash and Iterators

Before:

```text
Iterator
   |
   v
Bucket A
```

After rehash:

```text
New bucket organization
   |
   +--> entry moved logically to another bucket
```

Existing iterators are invalidated by rehash.

---

# 125. Erase and Iterators

If:

```cpp
auto it = m.find(10);
```

then:

```cpp
m.erase(it);
```

invalidates that iterator.

Other iterators remain valid unless another operation, such as rehash, invalidates them.

---

# 126. Reference and Pointer Stability

For unordered associative containers, references and pointers to elements generally remain valid across rehashing, while iterators are invalidated.

However:

```text
erase(element)
```

invalidates references/pointers to that erased element.

This distinction is important in advanced C++.

---

# 127. Node Handles

C++17 introduced node handles.

They allow you to extract a map entry without immediately destroying it:

```cpp
auto node = m.extract(key);
```

The node contains:

```text
key
mapped value
```

and can be transferred/reinserted.

---

# 128. Extracting a Node

```cpp
unordered_map<int,string> m = {
    {1, "A"},
    {2, "B"}
};

auto node = m.extract(1);
```

Now:

```text
m no longer contains key 1
```

---

# 129. Modifying a Node Key

One of the important reasons to use node handles:

```cpp
auto node = m.extract(1);

if (!node.empty())
{
    node.key() = 100;
    m.insert(std::move(node));
}
```

This effectively changes:

```text
1 -> A
```

into:

```text
100 -> A
```

without creating a separate mapped object.

---

# 130. Reinserting a Node

```cpp
m.insert(std::move(node));
```

If insertion succeeds, the node handle becomes empty.

If insertion fails because the destination already contains an equivalent key, the node can remain available through the returned insertion result.

---

# 131. Merge

Example:

```cpp
unordered_map<int,string> a = {
    {1, "A"},
    {2, "B"}
};

unordered_map<int,string> b = {
    {2, "X"},
    {3, "C"}
};

a.merge(b);
```

Result conceptually:

```text
a:
1 -> A
2 -> B
3 -> C

b:
2 -> X
```

The existing `2` in `a` prevents `b`'s `2` from being transferred.

---

# 132. Duplicate Keys During Merge

Important:

```text
Destination already has key
        ↓
Source entry is not transferred
```

No automatic replacement occurs.

If you need replacement behavior, use explicit logic.

---

# 133. Memory Layout

Conceptual structure:

```text
unordered_map
      |
      v
Bucket Array
      |
      +----------------+
      |                |
      v                v
   Bucket 0         Bucket 1
      |                |
      v                v
 Key/Value         Key/Value
```

Actual node and bucket representation is implementation-dependent.

---

# 134. Bucket Diagram

```text
Bucket 0
   |
   +--> (101, "Amit")

Bucket 1
   |
   +--> empty

Bucket 2
   |
   +--> (205, "Rahul")
   +--> (310, "Deep")

Bucket 3
   |
   +--> (401, "Sam")
```

Two entries in the same bucket represent a collision situation.

---

# 135. Collision Diagram

```text
hash(101) -> bucket 2
hash(205) -> bucket 2
hash(310) -> bucket 2

Bucket 2
   |
   +--> 101 -> Amit
   +--> 205 -> Rahul
   +--> 310 -> Deep
```

Lookup uses:

```text
hash
+
key equality
```

to identify the correct entry.

---

# 136. Rehash Diagram

Before:

```text
4 Buckets

0 -> A
1 -> B,C
2 -> D
3 -> E
```

After rehash:

```text
8 Buckets

0 -> ...
1 -> ...
2 -> ...
3 -> ...
4 -> ...
5 -> ...
6 -> ...
7 -> ...
```

Entries are redistributed.

---

# 137. Key Lookup Diagram

```text
find(key)
    |
    v
Hash key
    |
    v
Find bucket
    |
    v
Compare candidate keys
    |
    +---- equal ----> iterator
    |
    +---- none -----> end()
```

---

# 138. Average vs Worst-Case Complexity

## Average

With good distribution:

```text
find()      O(1)
insert()    O(1)
erase()     O(1)
contains()  O(1)
```

## Worst Case

With severe collisions:

```text
find()      O(n)
insert()    O(n)
erase()     O(n)
```

---

# 139. Complete Complexity Table

| Operation | Average | Worst Case |
|---|---:|---:|
| `operator[]` | O(1) | O(n) |
| `at()` | O(1) | O(n) |
| `find()` | O(1) | O(n) |
| `contains()` | O(1) | O(n) |
| `count()` | O(1) | O(n) |
| `insert()` | O(1) | O(n) |
| `emplace()` | O(1) | O(n) |
| `try_emplace()` | O(1) | O(n) |
| `insert_or_assign()` | O(1) | O(n) |
| `erase(key)` | O(1) | O(n) |
| `erase(iterator)` | O(1) average | Depends on operation/context |
| `size()` | O(1) | O(1) |
| `empty()` | O(1) | O(1) |
| `clear()` | O(n) | O(n) |
| `swap()` | O(1) | O(1) |
| `reserve()` | Depends on rehash | O(n) |
| `rehash()` | Linear in size on rehash | O(n) |

---

# 140. Space Complexity

For:

```text
N entries
```

space complexity is:

```text
O(N)
```

There is additional overhead for:

```text
buckets
nodes
hash-table metadata
```

Actual memory usage depends on the implementation and allocator.

---

# 141. Performance Factors

Performance depends on:

- Hash function quality.
- Key type.
- Equality comparison cost.
- Load factor.
- Number of buckets.
- Number of elements.
- Memory allocation.
- Cache behavior.
- Implementation.
- Hardware.

Therefore Big-O alone does not tell the complete performance story.

---

# 142. Hash Quality

Good hash distribution:

```text
Keys spread across buckets
```

Bad distribution:

```text
Many keys -> same bucket
```

A poor hash can make average-case behavior much worse in practice.

---

# 143. Load Factor and Performance

Higher load factor:

```text
more entries per bucket
```

Potential result:

```text
more collisions
```

Lower load factor:

```text
more buckets
```

Potential result:

```text
fewer collisions
more memory
```

The correct setting depends on workload.

---

# 144. Reserve for Performance

If you expect:

```text
1,000,000 entries
```

consider:

```cpp
m.reserve(1'000'000);
```

before insertion.

This can reduce repeated rehashing.

---

# 145. `unordered_map` vs `unordered_set`

| Feature | `unordered_map` | `unordered_set` |
|---|---|---|
| Stores | Key + Value | Key only |
| Unique keys | Yes | Yes |
| `operator[]` | Yes | No |
| `at()` | Yes | No |
| `find()` | Yes | Yes |
| `contains()` | Yes | Yes |
| Main purpose | Key-value lookup | Membership |
| Hash based | Yes | Yes |

---

# 146. `unordered_map` vs `map`

| Feature | `unordered_map` | `map` |
|---|---|---|
| Ordering | No | Sorted by key |
| Structure | Hash table | Balanced tree |
| Average lookup | O(1) | O(log n) |
| Worst lookup | O(n) | O(log n) |
| `operator[]` | Yes | Yes |
| `lower_bound()` | No | Yes |
| `upper_bound()` | No | Yes |
| Sorted traversal | No | Yes |
| Custom hash | Yes | No |
| Custom comparator | No ordering comparator | Yes |

---

# 147. `unordered_map` vs `unordered_multimap`

| Feature | `unordered_map` | `unordered_multimap` |
|---|---|---|
| Duplicate keys | No | Yes |
| One value per key | Yes | No |
| `count(key)` | 0 or 1 | Can be greater than 1 |
| Hash based | Yes | Yes |

Use `unordered_multimap` when multiple entries may share the same key.

---

# 148. `unordered_map` vs `vector`

| Feature | `unordered_map` | `vector` |
|---|---|---|
| Key lookup | Average O(1) | Usually O(n) scan |
| Key-value storage | Natural | Manual |
| Random access by index | No | Yes |
| Iterators | Yes | Yes |
| Sorted | No | No |
| Contiguous storage | No | Yes |
| Cache locality | Usually lower | Usually high |

---

# 149. `unordered_map` vs `list`

A list is useful for:

```text
sequence
stable node-based storage
insertion/erasure with iterator
```

An unordered map is useful for:

```text
key-based lookup
```

They solve different problems.

---

# 150. `unordered_map` vs `deque`

A deque is a sequence container with:

```text
front
back
random access
```

An unordered map is a key-value associative container.

Use:

```text
deque -> sequence operations
unordered_map -> key lookup
```

---

# 151. `unordered_map` vs Array

For small fixed integer keys:

```cpp
array<int, N>
```

or:

```cpp
vector<int>
```

may be much faster and simpler.

Example:

```cpp
array<int, 26> freq{};
```

for lowercase English letters.

A hash map is useful when keys are:

```text
large
sparse
dynamic
strings
non-contiguous
```

---

# 152. `map` vs `unordered_map` Lookup

If you need:

```text
fast average membership
```

and no ordering:

```cpp
unordered_map
```

If you need:

```text
sorted keys
lower_bound
upper_bound
range queries
```

use:

```cpp
map
```

---

# 153. When Ordering Matters

Use:

```cpp
map
```

when you need:

```text
smallest key
largest key
sorted iteration
lower_bound
upper_bound
ordered ranges
```

Do not try to use `unordered_map` for these requirements.

---

# 154. Frequency Counting

One of the most common uses:

```cpp
unordered_map<int,int> freq;

for (int x : values)
{
    freq[x]++;
}
```

Conceptually:

```text
value -> count
```

---

# 155. Duplicate Counting

Example:

```cpp
unordered_map<int,int> count;

for (int x : values)
{
    count[x]++;
}
```

Then:

```cpp
if (count[x] > 1)
{
    // duplicate
}
```

---

# 156. Two Sum

Given:

```text
numbers
target
```

store previously seen values:

```cpp
unordered_map<int,int> seen;
```

Concept:

```text
current = x
needed = target - x
```

If:

```cpp
seen.contains(needed)
```

then a matching pair exists.

---

# 157. Caching

Example:

```cpp
unordered_map<string,string> cache;
```

Concept:

```text
request -> result
```

If a request is already in the cache:

```cpp
cache.contains(request)
```

return the cached value.

---

# 158. Memoization

Dynamic programming or recursive functions can cache results:

```cpp
unordered_map<int,long long> memo;
```

Example:

```cpp
if (memo.contains(n))
{
    return memo[n];
}
```

Then calculate and store.

---

# 159. Graph Adjacency List

Example:

```cpp
unordered_map<
    int,
    vector<int>
> graph;
```

Add edge:

```cpp
graph[1].push_back(2);
graph[1].push_back(3);
```

Conceptually:

```text
1 -> 2,3
```

This is useful when graph vertex IDs are sparse or non-contiguous.

---

# 160. Visited Information

Example:

```cpp
unordered_map<int,bool> visited;
```

However, if you only need membership, often:

```cpp
unordered_set<int> visited;
```

is cleaner.

If you need additional state:

```cpp
unordered_map<int,int> state;
```

may be appropriate.

---

# 161. Indexing Records

Suppose:

```text
Employee ID -> Employee object
```

Use:

```cpp
unordered_map<int, Employee> employees;
```

Then:

```cpp
auto it = employees.find(id);
```

can locate the employee efficiently on average.

---

# 162. Grouping Data

Example:

```cpp
unordered_map<
    string,
    vector<string>
> groups;
```

Usage:

```cpp
groups["Engineering"].push_back("Amit");
groups["Engineering"].push_back("Rahul");
```

---

# 163. Counting Characters

```cpp
unordered_map<char,int> freq;

for (char c : text)
{
    freq[c]++;
}
```

---

# 164. Counting Words

```cpp
unordered_map<string,int> freq;

string word;

while (cin >> word)
{
    freq[word]++;
}
```

---

# 165. First Non-Repeating Character

Concept:

```text
1. Count every character.
2. Scan original string.
3. Find first character with count == 1.
```

Use:

```cpp
unordered_map<char,int> freq;
```

---

# 166. Top Frequency Problems

Typical pattern:

```text
unordered_map
      ↓
frequency counting
      ↓
priority_queue
      ↓
top K
```

This combination is extremely common in coding problems.

---

# 167. Complete Example

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    unordered_map<int, string> students;

    students[101] = "Amit";
    students[102] = "Rahul";
    students[103] = "Deep";

    cout << "Students:" << endl;

    for (const auto& [id, name] : students)
    {
        cout << id
             << " -> "
             << name
             << endl;
    }

    return 0;
}
```

Remember:

```text
Output order is unspecified.
```

---

# 168. Frequency Counter Program

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int values[] = {
        10, 20, 10, 30, 20, 10
    };

    unordered_map<int,int> freq;

    for (int x : values)
    {
        freq[x]++;
    }

    for (const auto& [value, count] : freq)
    {
        cout << value
             << " -> "
             << count
             << endl;
    }

    return 0;
}
```

---

# 169. Word Frequency Program

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    unordered_map<string,int> freq;

    string word;

    while (cin >> word)
    {
        freq[word]++;
    }

    for (const auto& [wordValue, count] : freq)
    {
        cout << wordValue
             << " -> "
             << count
             << endl;
    }

    return 0;
}
```

---

# 170. Two Sum Program

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    vector<int> values = {
        2, 7, 11, 15
    };

    int target = 9;

    unordered_map<int,int> seen;

    for (int i = 0;
         i < static_cast<int>(values.size());
         ++i)
    {
        int needed =
            target - values[i];

        auto it = seen.find(needed);

        if (it != seen.end())
        {
            cout << "Indexes: "
                 << it->second
                 << " "
                 << i;

            return 0;
        }

        seen[values[i]] = i;
    }

    cout << "No pair";

    return 0;
}
```

---

# 171. Student Marks Program

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    unordered_map<int,int> marks;

    marks[101] = 90;
    marks[102] = 85;
    marks[103] = 95;

    int id = 103;

    if (marks.contains(id))
    {
        cout << "Marks: "
             << marks.at(id);
    }

    return 0;
}
```

---

# 172. Custom Object Program

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct Employee
{
    int id;
    string name;
};

int main()
{
    unordered_map<int, Employee> employees;

    employees.emplace(
        101,
        Employee{101, "Amit"}
    );

    employees.emplace(
        102,
        Employee{102, "Rahul"}
    );

    for (const auto& [id, employee]
         : employees)
    {
        cout << id
             << " -> "
             << employee.name
             << endl;
    }

    return 0;
}
```

---

# 173. Custom Hash Program

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

struct MyHash
{
    size_t operator()(int x) const
    {
        return hash<int>{}(x);
    }
};

int main()
{
    unordered_map<
        int,
        string,
        MyHash
    > m;

    m[1] = "A";
    m[2] = "B";

    cout << m[1];

    return 0;
}
```

---

# 174. `operator[]` Program

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int,int> m;

    cout << "Before: "
         << m.size()
         << endl;

    cout << m[100]
         << endl;

    cout << "After: "
         << m.size()
         << endl;

    return 0;
}
```

Output:

```text
Before: 0
0
After: 1
```

This demonstrates accidental insertion.

---

# 175. `at()` Program

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int,string> m;

    m[1] = "Amit";

    cout << m.at(1)
         << endl;

    try
    {
        cout << m.at(2);
    }
    catch (const out_of_range& e)
    {
        cout << "Key not found";
    }

    return 0;
}
```

---

# 176. `contains()` Program

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int,string> m = {
        {1, "A"},
        {2, "B"}
    };

    if (m.contains(2))
    {
        cout << "Key exists";
    }

    return 0;
}
```

---

# 177. `try_emplace()` Program

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int,string> m;

    m.try_emplace(
        1,
        "A"
    );

    m.try_emplace(
        1,
        "B"
    );

    cout << m.at(1);

    return 0;
}
```

Output:

```text
A
```

The existing value is not replaced.

---

# 178. `insert_or_assign()` Program

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int,string> m;

    m.insert_or_assign(
        1,
        "A"
    );

    m.insert_or_assign(
        1,
        "B"
    );

    cout << m.at(1);

    return 0;
}
```

Output:

```text
B
```

---

# 179. Bucket Inspection Program

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int,string> m = {
        {1, "A"},
        {2, "B"},
        {3, "C"},
        {4, "D"}
    };

    cout << "Buckets: "
         << m.bucket_count()
         << endl;

    for (size_t i = 0;
         i < m.bucket_count();
         ++i)
    {
        cout << "Bucket "
             << i
             << ": "
             << m.bucket_size(i)
             << endl;
    }

    return 0;
}
```

---

# 180. Load Factor Program

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int,int> m;

    for (int i = 0;
         i < 100;
         ++i)
    {
        m[i] = i * 10;
    }

    cout << "Size: "
         << m.size()
         << endl;

    cout << "Buckets: "
         << m.bucket_count()
         << endl;

    cout << "Load factor: "
         << m.load_factor()
         << endl;

    return 0;
}
```

---

# 181. Reserve Program

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int,int> m;

    m.reserve(10000);

    for (int i = 0;
         i < 10000;
         ++i)
    {
        m[i] = i;
    }

    cout << m.size();

    return 0;
}
```

---

# 182. Rehash Program

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int,string> m;

    m[1] = "A";
    m[2] = "B";
    m[3] = "C";

    cout << "Before: "
         << m.bucket_count()
         << endl;

    m.rehash(100);

    cout << "After: "
         << m.bucket_count()
         << endl;

    return 0;
}
```

---

# 183. Extract Program

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int,string> m = {
        {1, "A"},
        {2, "B"}
    };

    auto node = m.extract(1);

    if (!node.empty())
    {
        node.key() = 100;

        m.insert(
            std::move(node)
        );
    }

    cout << m.at(100);

    return 0;
}
```

---

# 184. Merge Program

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int,string> a = {
        {1, "A"},
        {2, "B"}
    };

    unordered_map<int,string> b = {
        {2, "X"},
        {3, "C"}
    };

    a.merge(b);

    cout << "A:" << endl;

    for (const auto& [key, value] : a)
    {
        cout << key
             << " -> "
             << value
             << endl;
    }

    cout << "B size: "
         << b.size()
         << endl;

    return 0;
}
```

---

# 185. Nested Map Program

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    unordered_map<
        string,
        unordered_map<string,int>
    > marks;

    marks["Amit"]["Math"] = 90;
    marks["Amit"]["Science"] = 85;

    marks["Rahul"]["Math"] = 80;

    cout << marks["Amit"]["Math"];

    return 0;
}
```

---

# 186. Common Mistakes

Common mistakes include:

```text
1. Assuming sorted order.
2. Assuming insertion order.
3. Forgetting operator[] inserts.
4. Calling at() without handling missing keys.
5. Assuming insert() overwrites.
6. Using the wrong custom hash.
7. Using the wrong equality predicate.
8. Modifying key identity.
9. Ignoring iterator invalidation.
10. Assuming every operation is always O(1).
```

---

# 187. Assuming Sorted Order

Wrong:

```cpp
for (const auto& [key, value] : m)
{
    // Assume key increases
}
```

Correct:

```text
unordered_map has no sorted iteration order.
```

Use:

```cpp
map
```

for sorted keys.

---

# 188. Assuming Insertion Order

Wrong:

```text
insert A
insert B
insert C

expect:
A B C
```

`unordered_map` does not guarantee insertion order.

---

# 189. Assuming `operator[]` Only Reads

Wrong assumption:

```cpp
cout << m[key];
```

is always a read.

Correct:

```text
If key is missing,
operator[] inserts it.
```

---

# 190. Accidental Default Insertion

This:

```cpp
if (m[key] == 10)
{
}
```

can create `key` if it does not exist.

If you only want to check existence:

```cpp
m.contains(key)
```

or:

```cpp
m.find(key)
```

---

# 191. Calling `at()` on Missing Key

This:

```cpp
m.at(100);
```

throws if `100` is absent.

Use:

```cpp
if (m.contains(100))
{
    cout << m.at(100);
}
```

or use `find()` when you need the value.

---

# 192. Assuming `find()` Returns Value

Wrong:

```cpp
string name = m.find(1);
```

`find()` returns an iterator.

Correct:

```cpp
auto it = m.find(1);

if (it != m.end())
{
    string name = it->second;
}
```

---

# 193. Assuming `insert()` Updates Existing Value

Wrong assumption:

```cpp
m.insert({1, "A"});
m.insert({1, "B"});
```

expecting:

```text
1 -> B
```

Actual:

```text
1 -> A
```

Use:

```cpp
m.insert_or_assign(1, "B");
```

if replacement is desired.

---

# 194. Misusing `try_emplace()`

Remember:

```text
try_emplace:
    existing key -> do not replace
```

If replacement is required:

```cpp
insert_or_assign()
```

is the clearer operation.

---

# 195. Misusing `insert_or_assign()`

Remember:

```text
insert_or_assign:
    existing key -> replace mapped value
```

Do not use it when existing values must be preserved.

Use:

```cpp
try_emplace()
```

instead.

---

# 196. Bad Custom Hash

Avoid:

```cpp
return 1;
```

for all keys.

That causes severe collision concentration.

---

# 197. Incorrect Equality

If:

```text
a and b are equivalent
```

then:

```text
hash(a) must equal hash(b)
```

Violating this requirement can produce incorrect lookup behavior.

---

# 198. Mutating Key Identity

Never change key identity while the entry is stored.

If:

```text
id
```

participates in hashing, do not modify it in place.

Use:

```text
extract -> change key -> insert
```

---

# 199. Forgetting Rehash Effects

An insertion can trigger rehash.

After rehash:

```text
iterators are invalid
```

Do not hold iterators across potentially rehashing operations without checking the guarantees.

---

# 200. Assuming Every Operation Is O(1)

Correct:

```text
Average:
O(1)

Worst:
O(n)
```

Hash tables are not guaranteed constant-time in every case.

---

# 201. Poor Reserve Strategy

Calling:

```cpp
reserve(1);
reserve(2);
reserve(3);
...
```

repeatedly can be unnecessary.

If the expected size is known, reserve approximately once:

```cpp
m.reserve(expectedSize);
```

before bulk insertion.

---

# 202. Thread Safety

`std::unordered_map` is not a synchronized concurrent map.

If multiple threads access the same map concurrently and at least one thread modifies it, external synchronization is required.

Possible synchronization tools include:

```cpp
std::mutex
std::shared_mutex
```

depending on the design.

Do not assume:

```cpp
unordered_map
```

is automatically thread-safe.

---

# 203. Exception Safety Concepts

Operations involving allocation or user-provided hash/equality/mapped-type operations can throw exceptions.

For example:

```cpp
m.at(key)
```

can throw:

```text
std::out_of_range
```

if the key is absent.

Custom hash functions and mapped-type constructors can also potentially throw.

When writing exception-sensitive code, use the exact standard guarantees for the operation and your types.

---

# 204. C++ Version Features

| Feature | Standard |
|---|---|
| `std::unordered_map` | C++11 |
| `insert()` | C++11 |
| `emplace()` | C++11 |
| `operator[]` | C++11 |
| `at()` | C++11 |
| `find()` | C++11 |
| `bucket interface` | C++11 |
| `load_factor()` | C++11 |
| `reserve()` | C++11 |
| `rehash()` | C++11 |
| Move operations | C++11 |
| `try_emplace()` | C++17 |
| `insert_or_assign()` | C++17 |
| `extract()` | C++17 |
| `merge()` | C++17 |
| `contains()` | C++20 |
| `erase_if()` | C++20 |
| Expanded `constexpr` support | C++26 |

---

# 205. Interview Questions

## Q1. What is `unordered_map`?

A hash-table-based unordered associative container storing unique keys with associated mapped values.

---

## Q2. Is `unordered_map` sorted?

No.

---

## Q3. Does it preserve insertion order?

No.

---

## Q4. What is the average lookup complexity?

```text
O(1)
```

---

## Q5. What is the worst-case lookup complexity?

```text
O(n)
```

---

## Q6. Why can lookup become O(n)?

Because of collisions and poor hash distribution.

---

## Q7. Does `unordered_map` allow duplicate keys?

No.

---

## Q8. What container allows duplicate keys?

```cpp
unordered_multimap
```

---

## Q9. What is the difference between `map` and `unordered_map`?

```text
map:
    ordered
    O(log n)

unordered_map:
    unordered
    O(1) average
```

---

## Q10. What is the default hash?

```cpp
std::hash<Key>
```

---

## Q11. What is the default equality predicate?

```cpp
std::equal_to<Key>
```

---

## Q12. What happens when `operator[]` accesses a missing key?

It inserts the key with a value-initialized mapped value.

---

## Q13. What happens when `at()` accesses a missing key?

It throws:

```cpp
std::out_of_range
```

---

## Q14. Does `find()` insert?

No.

---

## Q15. Does `contains()` insert?

No.

---

## Q16. What does `count()` return for `unordered_map`?

```text
0 or 1
```

---

## Q17. Does `insert()` replace an existing value?

No.

---

## Q18. Which operation replaces an existing value?

```cpp
insert_or_assign()
```

---

## Q19. Which operation inserts only if the key is absent?

```cpp
try_emplace()
```

---

## Q20. Why use `try_emplace()`?

It can avoid constructing the mapped value when the key already exists.

---

## Q21. What is a bucket?

A hash-table bucket associated with a bucket index.

---

## Q22. What is a collision?

Multiple different keys mapping to the same bucket.

---

## Q23. What is load factor?

Conceptually:

```text
size / bucket_count
```

---

## Q24. What is rehashing?

Redistributing entries into a new bucket organization with a different bucket count.

---

## Q25. What does `reserve()` do?

Requests enough bucket capacity for at least a specified number of elements under the current maximum load factor.

---

## Q26. Difference between `reserve()` and `rehash()`?

```text
reserve(n)
    -> based on expected element count

rehash(n)
    -> based on requested bucket count
```

---

## Q27. Does `unordered_map` have iterators?

Yes.

---

## Q28. Does it have sorted iterators?

No.

---

## Q29. Can you modify a key through an iterator?

No.

---

## Q30. Can you modify the mapped value?

Yes.

Example:

```cpp
it->second = value;
```

---

## Q31. Why is the key effectively const?

Because changing the key would change its hash/bucket identity.

---

## Q32. How can a key be changed?

C++17:

```text
extract
modify key
insert
```

---

## Q33. What is `extract()`?

A C++17 node-handle operation that removes an entry without destroying the node's stored value.

---

## Q34. What is `merge()`?

A C++17 operation that transfers non-conflicting nodes between compatible containers.

---

## Q35. What happens if a merge encounters an existing key?

The source entry remains in the source container.

---

## Q36. What happens to iterators during rehash?

They are invalidated.

---

## Q37. Are references/pointers invalidated by rehash?

They generally remain valid for elements that still exist, although iterators are invalidated.

---

## Q38. Is `unordered_map` thread-safe?

No synchronization is provided for concurrent mutation.

---

## Q39. Can custom objects be keys?

Yes, with compatible hashing and equality.

---

## Q40. Can two different keys have the same hash?

Yes.

That is a collision.

---

## Q41. If two keys are equal, must their hashes be equal?

Yes.

---

## Q42. If two hashes are equal, must the keys be equal?

No.

---

## Q43. Why is `unordered_map` sometimes faster than `map`?

Average lookup is O(1) versus O(log n).

---

## Q44. Is `unordered_map` always faster?

No.

Memory locality, hashing cost, key size, workload, implementation, and collision behavior matter.

---

## Q45. Can `unordered_map` get the smallest key efficiently?

No.

Use `map` if ordered minimum access is required.

---

## Q46. Does `unordered_map` support `lower_bound()`?

No.

---

## Q47. What should be used for sorted range queries?

Usually:

```cpp
map
```

---

## Q48. What is `unordered_map` commonly used for?

```text
frequency counting
caching
indexing
membership-associated data
memoization
grouping
graph adjacency
```

---

## Q49. What is the difference between `unordered_map` and `unordered_set`?

```text
unordered_map:
    key -> value

unordered_set:
    key only
```

---

## Q50. What is the most dangerous `unordered_map` mistake for beginners?

Usually misunderstanding:

```cpp
operator[]
```

because reading a missing key inserts a new entry.

---

## Q51. What is the complexity of `operator[]`?

Average:

```text
O(1)
```

Worst:

```text
O(n)
```

---

## Q52. What is the complexity of `at()`?

Average:

```text
O(1)
```

Worst:

```text
O(n)
```

---

## Q53. What is the complexity of `size()`?

```text
O(1)
```

---

## Q54. What is the complexity of `empty()`?

```text
O(1)
```

---

## Q55. Does `clear()` reduce bucket count?

Not necessarily.

---

## Q56. How can you inspect bucket distribution?

Use:

```cpp
bucket_count()
bucket_size()
bucket()
```

---

## Q57. How can you inspect load factor?

```cpp
load_factor()
```

---

## Q58. How can you change maximum load factor?

```cpp
max_load_factor(value)
```

---

## Q59. How can you force a rehash?

```cpp
rehash(n)
```

---

## Q60. How can you reduce repeated rehashing before bulk insertion?

```cpp
reserve(expectedSize)
```

---

# 206. Best Practices

## 1. Use `contains()` for simple existence checks

C++20:

```cpp
if (m.contains(key))
{
}
```

---

## 2. Use `find()` when you need the value

```cpp
auto it = m.find(key);

if (it != m.end())
{
    use(it->second);
}
```

This avoids doing a separate lookup after `contains()`.

---

## 3. Avoid accidental `operator[]` insertion

If you only want to read:

```cpp
m.at(key)
```

or:

```cpp
m.find(key)
```

depending on desired missing-key behavior.

---

## 4. Use `try_emplace()` for conditional construction

```cpp
m.try_emplace(
    key,
    constructorArgs...
);
```

---

## 5. Use `insert_or_assign()` when replacement is intended

```cpp
m.insert_or_assign(
    key,
    value
);
```

---

## 6. Reserve for known large workloads

```cpp
m.reserve(expectedSize);
```

---

## 7. Do not rely on order

If sorted order matters:

```cpp
map
```

is usually the correct abstraction.

---

## 8. Keep key identity stable

Do not mutate data involved in:

```text
hash
equality
```

while the key is stored.

---

## 9. Use a good hash

Custom hashes should distribute keys reasonably well.

---

## 10. Benchmark when performance matters

Big-O is not enough.

Consider:

```text
hash cost
cache locality
memory allocations
load factor
key size
compiler
standard library implementation
```

---

# 207. Quick Reference

## Declaration

```cpp
unordered_map<int, string> m;
```

---

## Insert

```cpp
m.insert({1, "A"});
```

---

## Emplace

```cpp
m.emplace(1, "A");
```

---

## Try Emplace

```cpp
m.try_emplace(1, "A");
```

---

## Insert or Assign

```cpp
m.insert_or_assign(1, "B");
```

---

## Access

```cpp
m[1];
m.at(1);
```

---

## Find

```cpp
auto it = m.find(1);
```

---

## Contains

```cpp
m.contains(1);
```

---

## Count

```cpp
m.count(1);
```

---

## Erase

```cpp
m.erase(1);
```

---

## Clear

```cpp
m.clear();
```

---

## Size

```cpp
m.size();
```

---

## Empty

```cpp
m.empty();
```

---

## Iterate

```cpp
for (const auto& [key, value] : m)
{
    cout << key << " "
         << value;
}
```

---

## Buckets

```cpp
m.bucket_count();
m.bucket_size(i);
m.bucket(key);
```

---

## Load Factor

```cpp
m.load_factor();
m.max_load_factor();
```

---

## Reserve

```cpp
m.reserve(n);
```

---

## Rehash

```cpp
m.rehash(n);
```

---

## Node Handle

```cpp
auto node = m.extract(key);
```

---

## Merge

```cpp
m1.merge(m2);
```

---

# 208. Advantages

- Fast average-case key lookup.
- Fast average-case insertion.
- Fast average-case deletion.
- Stores key-value relationships naturally.
- Automatically enforces unique keys.
- Supports custom hash functions.
- Supports custom equality.
- Supports efficient frequency counting.
- Excellent for caching and indexing.
- Useful for graph algorithms.
- Supports bucket inspection.
- Supports load-factor management.
- C++20 provides convenient `contains()`.
- C++17 provides `try_emplace()`, `insert_or_assign()`, `extract()`, and `merge()`.

---

# 209. Disadvantages

- No sorted order.
- No insertion-order guarantee.
- Worst-case operations can be O(n).
- Hash quality affects performance.
- Can have significant memory overhead.
- Bucket storage consumes memory.
- No `lower_bound()` or `upper_bound()`.
- No efficient smallest/largest-key operation.
- Iterator invalidation can occur during rehash.
- Custom key hashing can require additional code.
- For tiny collections, a vector scan may sometimes outperform a hash map due to cache locality.

---

# 210. When to Use

Use `unordered_map` when:

```text
1. You need key -> value lookup.
2. Keys are unique.
3. Ordering is unnecessary.
4. Fast average lookup is important.
5. You need frequency counting.
6. You need caching.
7. You need indexing.
8. You need grouping.
9. You need memoization.
```

Examples:

```cpp
unordered_map<int,string> users;
unordered_map<string,int> frequency;
unordered_map<int,Employee> employees;
unordered_map<string,vector<int>> groups;
```

---

# 211. When Not to Use

Do not use `unordered_map` when:

## Sorted keys are required

Use:

```cpp
map
```

## Duplicate keys are required

Use:

```cpp
unordered_multimap
```

## Only membership is required

Use:

```cpp
unordered_set
```

## Random positional access is required

Use:

```cpp
vector
deque
```

## Smallest/largest key is frequently needed

Use:

```cpp
map
```

## Ordered range queries are required

Use:

```cpp
map
```

---

# 212. Final Summary

`std::unordered_map` is one of the most important C++ STL containers for key-value data.

Core idea:

```text
Key
 ↓
Hash
 ↓
Bucket
 ↓
Key Equality
 ↓
Mapped Value
```

It stores:

```text
unique key -> value
```

Main operations:

```cpp
operator[]
at()
insert()
emplace()
try_emplace()
insert_or_assign()
find()
contains()
count()
erase()
clear()
swap()
```

Hash-management operations:

```cpp
bucket_count()
bucket_size()
bucket()
load_factor()
max_load_factor()
reserve()
rehash()
```

Modern C++ features:

```cpp
try_emplace()      // C++17
insert_or_assign() // C++17
extract()          // C++17
merge()            // C++17
contains()         // C++20
erase_if()         // C++20
```

Key complexity:

```text
Average:
lookup   O(1)
insert   O(1)
erase    O(1)

Worst:
lookup   O(n)
insert   O(n)
erase    O(n)
```

---

# 213. Mental Model

```text
                    std::unordered_map
                            |
                            v
              Unordered Associative Container
                            |
                            v
                       Hash Table
                            |
                +-----------+-----------+
                |                       |
                v                       v
          Hash Function          Equality Predicate
                |                       |
                v                       v
             Bucket                  Key Match
                |
                v
          +-----------+
          | Key Value |
          +-----------+
```

---

# Key-Value Mental Model

```text
Key                Value

101  ------------> Amit
102  ------------> Rahul
103  ------------> Deep
```

The key identifies the entry.

The value stores associated data.

---

# Lookup Mental Model

```text
find(102)
    |
    v
hash(102)
    |
    v
bucket
    |
    v
compare keys
    |
    +---- 102 found ----> value
    |
    +---- not found ----> end()
```

---

# `operator[]` Mental Model

```text
m[key]
   |
   +---- key exists
   |       |
   |       v
   |     value
   |
   +---- key missing
           |
           v
    create key + default value
           |
           v
        value
```

This is why:

```cpp
m[key]
```

can modify the map even when you think you are only reading.

---

# `map` vs `unordered_map` Mental Model

```text
map
 |
 +--> Balanced Tree
 |
 +--> Sorted keys
 |
 +--> O(log n)
 |
 +--> lower_bound()
 +--> upper_bound()
```

```text
unordered_map
 |
 +--> Hash Table
 |
 +--> Unordered keys
 |
 +--> O(1) average
 |
 +--> contains()
 +--> bucket_count()
 +--> load_factor()
```

---

# `unordered_map` vs `unordered_set`

```text
unordered_set

Key
 |
 v
Exists?
```

```text
unordered_map

Key
 |
 v
Value
```

Use:

```text
unordered_set -> membership
unordered_map -> key-value association
```

---

# `insert()` / `try_emplace()` / `insert_or_assign()` Memory Trick

```text
insert()
    |
    +--> key missing -> INSERT
    |
    +--> key exists  -> DO NOTHING
```

```text
try_emplace()
    |
    +--> key missing -> CONSTRUCT + INSERT
    |
    +--> key exists  -> DO NOTHING
```

```text
insert_or_assign()
    |
    +--> key missing -> INSERT
    |
    +--> key exists  -> REPLACE VALUE
```

---

# Final Rules to Remember

```text
1. unordered_map stores key-value pairs.

2. Keys are unique.

3. Values can be duplicated.

4. It uses hashing.

5. It does not maintain sorted order.

6. It does not guarantee insertion order.

7. Average lookup is O(1).

8. Worst-case lookup is O(n).

9. operator[] inserts a missing key.

10. at() throws if a key is missing.

11. find() does not insert.

12. contains() does not insert.

13. insert() does not replace an existing value.

14. insert_or_assign() replaces an existing value.

15. try_emplace() inserts only when the key is absent.

16. Keys cannot normally be modified through iterators.

17. Mapped values can be modified.

18. Rehashing can invalidate iterators.

19. References/pointers to existing elements generally survive rehash.

20. Erasing an element invalidates references/pointers to that element.

21. reserve() is useful before bulk insertion.

22. rehash() controls the requested bucket count.

23. load_factor() reports hash-table density.

24. max_load_factor() controls the rehash threshold.

25. Good hash distribution is important.

26. Equivalent keys must have equal hash values.

27. Different keys can have the same hash.

28. unordered_map is not automatically thread-safe.

29. Use map when sorted order matters.

30. Use unordered_set when only membership is required.
```

---

# 214. One-Line Definition

> **`std::unordered_map` is a C++ STL unordered associative container that stores unique keys with associated mapped values in a hash table, providing average O(1) lookup, insertion, and deletion without maintaining sorted key order.**
