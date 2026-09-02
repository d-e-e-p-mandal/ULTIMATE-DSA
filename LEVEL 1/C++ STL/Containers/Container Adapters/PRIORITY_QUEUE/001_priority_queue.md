# C++ STL `std::priority_queue` — Complete Notes

# Table of Contents

1. Introduction
2. FIFO Queue vs Priority Queue
3. Real-World Examples
4. Header File
5. Namespace
6. Basic Syntax
7. Template Definition
8. Template Parameters
9. What is a Container Adapter?
10. Internal Working
11. Binary Heap
12. Complete Binary Tree
13. Heap Property
14. Max Heap
15. Min Heap
16. Default Underlying Container
17. Supported Underlying Containers
18. Why `vector` Is the Default
19. Characteristics
20. Constructors
21. Default Constructor
22. Comparator Constructor
23. Underlying Container Constructor
24. Range Constructor
25. Copy Constructor
26. Move Constructor
27. `push()`
28. `emplace()`
29. `pop()`
30. `top()`
31. `empty()`
32. `size()`
33. `swap()`
34. `push()` vs `emplace()`
35. `top()` vs `pop()`
36. Empty Priority Queue Safety
37. No Iterators
38. No Random Access
39. No Direct Search
40. Priority Queue Is Not Fully Sorted
41. Max Heap Example
42. Min Heap Example
43. Heap Insertion
44. Heap Removal
45. Sift Up / Bubble Up
46. Sift Down / Heapify Down
47. Priority Queue of `pair`
48. Pair Ordering
49. Pair Min Heap
50. Priority Queue of Structure
51. Custom Comparator Class
52. Comparator Logic
53. Lambda Comparator
54. Multiple-Condition Comparator
55. Custom Object with `emplace()`
56. Priority Queue with `vector`
57. Priority Queue with `deque`
58. Traversing / Printing
59. Traversing Without Destroying
60. Move Semantics
61. Complexity
62. Space Complexity
63. Heap Algorithms
64. `make_heap()`
65. `push_heap()`
66. `pop_heap()`
67. `sort_heap()`
68. `is_heap()`
69. `is_heap_until()`
70. `priority_queue` vs Heap Algorithms
71. Dijkstra's Algorithm
72. Prim's Algorithm
73. Huffman Coding
74. CPU / Task Scheduling
75. Event Scheduling
76. Top-K Largest Elements
77. Top-K Smallest Elements
78. Merge K Sorted Arrays
79. Running Median
80. Common Mistakes
81. Interview Questions
82. C++ Version Features
83. Quick Reference
84. Comparison with Queue
85. Comparison with Stack
86. Comparison with Set / Multiset
87. Comparison with `vector`
88. Comparison with Heap Algorithms
89. Advantages
90. Disadvantages
91. When to Use `priority_queue`
92. When Not to Use `priority_queue`
93. Best Practices
94. Final Summary
95. Mental Model
96. One-Line Definition

---

# 1. Introduction

- `std::priority_queue` is a **container adapter** provided by the C++ Standard Library.

Unlike a normal queue, which follows:
- FIFO
- First In, First Out

a priority queue removes elements according to their **priority**.

By default:

```text
Largest element
      ↓
Highest priority
      ↓
top()
```

Therefore the default `std::priority_queue<int>` is a **max heap**.

Example:

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(40);
pq.push(20);
pq.push(80);
```

The top is:

```text
80
```

because `80` is the largest element.

---

# 2. FIFO Queue vs Priority Queue

## Normal Queue

A normal queue follows:

```text
First In
   ↓
First Out
```

Example:

```text
10 20 30
```

Removal:

```text
10
20
30
```

---

## Priority Queue

A priority queue follows:

```text
Highest Priority
       ↓
First Out
```

For a default max heap:

```text
10 20 30
```

Removal:

```text
30
20
10
```

The insertion order does not determine removal order.

---

# 3. Real-World Examples

Priority queues are useful when some items must be processed before others.

Examples:

- CPU process scheduling
- Hospital emergency systems
- Task scheduling
- Network routing
- Event simulation
- Dijkstra's algorithm
- Prim's algorithm
- Huffman coding
- Top-K problems
- Merge K sorted arrays
- A* search
- Operating-system scheduling

---

# 4. Header File

Include:

```cpp
#include <queue>
```

For a min heap using `greater`:

```cpp
#include <queue>
#include <vector>
#include <functional>
```

---

# 5. Namespace

Using:

```cpp
using namespace std;
```

allows:

```cpp
priority_queue<int> pq;
```

Without it:

```cpp
std::priority_queue<int> pq;
```

For larger projects, explicitly using `std::priority_queue` is often preferable.

---

# 6. Basic Syntax

## Default Max Heap

```cpp
priority_queue<data_type> pq;
```

Examples:

```cpp
priority_queue<int> pq;
priority_queue<double> pq;
priority_queue<string> pq;
```

---

## Min Heap

```cpp
priority_queue<int, vector<int>,greater<int>> pq;
```

This makes the smallest element the top element.

---

# 7. Template Definition

Conceptually:

```cpp
template<
    class T,
    class Container = vector<T>,
    class Compare = less<typename Container::value_type>
>
class priority_queue;
```

The three important template parameters are:

```text
T
Container
Compare
```

---

# 8. Template Parameters

## 8.1 `T`

`T` is the element type.

Examples:

```cpp
priority_queue<int> pq;
priority_queue<double> pq;
priority_queue<string> pq;
```

For:

```cpp
priority_queue<int>
```

the stored element type is:

```text
int
```

---

## 8.2 `Container`

The second parameter specifies the underlying container.

Default:

```cpp
vector<T>
```

Therefore:

```cpp
priority_queue<int>
```

is conceptually:

```cpp
priority_queue<
    int,
    vector<int>
>
```

---

## 8.3 `Compare`

The third parameter determines the priority ordering.

Default:

```cpp
less<T>
```
This creates a: `Max Heap`


**For a min heap:**

```cpp
greater<T>
```

is commonly used.

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
```

---

# 9. What is a Container Adapter?

`std::priority_queue` is a **container adapter**.

It is not a general-purpose sequence container such as:

```cpp
vector
deque
list
```

Instead, it provides a restricted interface over an underlying container.

Conceptually:

```text
             priority_queue
                    |
                    v
            Underlying Container
                    |
                    v
              Binary Heap
```

The adapter exposes operations such as:

```cpp
push()
emplace()
pop()
top()
empty()
size()
```

but does not expose general iterator or random-access operations.

---

# 10. Internal Working

By default:

```cpp
priority_queue<int> pq;
```

uses:

```cpp
vector<int>
```

as its underlying container.

The elements are arranged according to the heap property.

Conceptually:

```text
priority_queue
       |
       v
    vector
       |
       v
  Binary Heap
```

The underlying `vector` stores the heap efficiently as an array-like structure.

---

# 11. Binary Heap

A binary heap is a **complete binary tree** satisfying a heap property.

There are two common forms:

```text
Max Heap
Min Heap
```

---

## Max Heap

Every parent is greater than or equal to its children.

Example:

```text
          50
        /    \
      30      40
     /  \
   10    20
```

The largest element is at the root:

```text
50
```

---

## Min Heap

Every parent is less than or equal to its children.

Example:

```text
          10
        /    \
      20      15
     /  \
   40    30
```

The smallest element is at the root:

```text
10
```

---

# 12. Complete Binary Tree

A heap is a **complete binary tree**.

This means:

- Every level is completely filled except possibly the last.
- The last level is filled from left to right.

Example:

```text
          50
        /    \
      40      30
     /  \    /
   20   10  25
```

This structure can be stored efficiently in an array/vector.

---

# 13. Heap Property

## Max Heap Property

For every parent:

```text
parent >= children
```

Example:

```text
        80
       /  \
     50    60
    / \
   20 40
```

The tree does not have to be completely sorted.

For example:

```text
80
50
60
20
40
```

is a valid max heap even though:

```text
50 < 60
```

The only requirement is that each parent has appropriate priority over its children.

---

## Min Heap Property

For every parent:

```text
parent <= children
```

---

# 14. Max Heap

The default `priority_queue` is a max heap.

```cpp
priority_queue<int> pq;
```

Example:

```cpp
pq.push(20);
pq.push(50);
pq.push(10);
pq.push(40);
```

Top:

```text
50
```

Printing by repeatedly popping:

```cpp
while (!pq.empty())
{
    cout << pq.top() << " ";
    pq.pop();
}
```

Output:

```text
50 40 20 10
```

---

# 15. Min Heap

Use:

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
```

Example:

```cpp
pq.push(20);
pq.push(50);
pq.push(10);
pq.push(40);
```

Top:

```text
10
```

Removal order:

```text
10 20 40 50
```

---

# 16. Default Underlying Container

The default underlying container is:

```cpp
std::vector<T>
```

Example:

```cpp
priority_queue<int> pq;
```

is conceptually:

```cpp
priority_queue<
    int,
    vector<int>,
    less<int>
> pq;
```

This means:

```text
T         = int
Container = vector<int>
Compare   = less<int>
```

---

# 17. Supported Underlying Containers

The underlying container must provide the operations required by the priority queue.

Standard choices include:

```cpp
vector
deque
```

Example:

```cpp
priority_queue<int, vector<int>> pq1;
priority_queue<int, deque<int>> pq2;
```

The underlying container needs operations compatible with heap algorithms, including:

```text
front()
push_back()
pop_back()
random-access iterators
```

Therefore `std::list` is not suitable because it does not provide random-access iterators.

---

# 18. Why `vector` Is the Default

`vector` is a natural choice for binary heaps because:

1. It provides contiguous storage.
2. It supports random access.
3. Heap algorithms can work efficiently with random-access iterators.
4. `push_back()` is amortized O(1).
5. `pop_back()` is O(1).

A binary heap can be represented compactly without storing explicit tree pointers.

---

# 19. Characteristics

Important characteristics:

- Container adapter
- Default max heap
- Binary heap based
- Default underlying container is `vector`
- Duplicate elements are allowed
- `top()` gives highest-priority element
- No iterators through the adapter
- No `operator[]`
- No direct search
- No guarantee that all elements are sorted
- `push()` is O(log n)
- `pop()` is O(log n)
- `top()` is O(1)

---

# 20. Constructors

Common constructor categories include:

```text
Default constructor
Comparator constructor
Underlying-container constructor
Comparator + container constructor
Range constructor
Copy constructor
Move constructor
```

The exact overload set depends on the C++ standard version.

---

# 21. Default Constructor

Example:

```cpp
priority_queue<int> pq;
```

Creates an empty max heap.

---

# 22. Comparator Constructor

For a min heap:

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
```

The comparator object can also be passed explicitly.

For a custom comparator:

```cpp
Compare cmp;

priority_queue<
    int,
    vector<int>,
    Compare
> pq(cmp);
```

---

# 23. Underlying Container Constructor

You can construct a priority queue from an existing container.

Example:

```cpp
vector<int> v = {10, 40, 20, 50, 30};

priority_queue<int> pq(
    less<int>(),
    v
);
```

The constructor builds the heap according to the comparator.

---

# 24. Range Constructor

A range of elements can be used to initialize a priority queue.

Example:

```cpp
vector<int> v = {10, 40, 20, 50, 30};

priority_queue<int> pq(v.begin(),v.end());
```

The resulting priority queue has:

```text
top = 50
```

This is useful when you already have data in a container.

---

# 25. Copy Constructor

Example:

```cpp
priority_queue<int> pq1;

pq1.push(10);
pq1.push(20);
pq1.push(50);

priority_queue<int> pq2(pq1);
```

Now `pq1` and `pq2` contain equivalent priority-queue contents.

Modifying `pq2` does not modify `pq1`.

---

# 26. Move Constructor

Example:

```cpp
priority_queue<int> pq1;

pq1.push(10);
pq1.push(20);
pq1.push(50);

priority_queue<int> pq2(std::move(pq1));
```

The underlying resources can be transferred to `pq2`.

After the move:
- pq2 -> contains the transferred contents
- pq1 -> valid but unspecified state

**Include:**
```cpp
#include <utility>
```

for:

```cpp
std::move()
```

---

# 27. `push()`
- Adds an element to the priority queue.

Syntax:

```cpp
pq.push(value);
```

Example:

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(50);
pq.push(20);
```
- The heap automatically rearranges itself. `Top: 50`

**Time Complexity:** `O(log n)`
because the new element may move upward through the heap.

---

# 28. `emplace()`

Constructs an element directly in the priority queue.

Syntax:

```cpp
pq.emplace(arguments...);
```

Example:

```cpp
priority_queue<pair<int, string>> pq;

pq.emplace(100, "Amit");
pq.emplace(200, "Rahul");
```

This constructs the pair directly.

### Complexity

Usually: O(log n)

plus the cost of constructing/moving/comparing the element.

---

# 29. `pop()`

Removes the top element.

Example:

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(50);
pq.push(30);

pq.pop();
```

Before:

```text
Top
 ↓
50
30
10
```

After:

```text
Top
 ↓
30
10
```

### Complexity

```text
O(log n)
```

---

# Important

`pop()` does not return the removed element.

Wrong:

```cpp
int x = pq.pop();
```

Correct:

```cpp
int x = pq.top();
pq.pop();
```

---

# 30. `top()`

Returns a reference to the highest-priority element.

For a max heap:

```cpp
pq.top()
```

returns the largest element.

Example:

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(50);
pq.push(20);

cout << pq.top();
```

Output:

```text
50
```

### Complexity

```text
O(1)
```

---

# 31. `empty()`

Checks whether the priority queue contains no elements.

```cpp
if (pq.empty())
{
    cout << "Empty";
}
```

Returns:

```text
true
false
```

Complexity:

```text
O(1)
```

---

# 32. `size()`

Returns the number of stored elements.

Example:

```cpp
cout << pq.size();
```

Complexity:

```text
O(1)
```

---

# 33. `swap()`

Exchanges the contents of two priority queues.

Example:

```cpp
priority_queue<int> pq1;
priority_queue<int> pq2;

pq1.push(10);
pq1.push(20);

pq2.push(100);
pq2.push(200);

pq1.swap(pq2);
```

After:

```text
pq1 -> 200, 100
pq2 -> 20, 10
```

You can also use:

```cpp
swap(pq1, pq2);
```

Complexity is typically:

```text
O(1)
```

subject to the underlying container and allocator characteristics.

---

# 34. `push()` vs `emplace()`

## `push()`

Provide an existing object/value:

```cpp
pair<int, string> p = {100, "Amit"};

pq.push(p);
```

---

## `emplace()`

Provide constructor arguments:

```cpp
pq.emplace(100, "Amit");
```

General idea:

```text
push()
  ↓
Existing object/value

emplace()
  ↓
Constructor arguments
  ↓
Construct at destination
```

For primitive types, the difference is usually not important.

---

# 35. `top()` vs `pop()`

These functions have different purposes.

```cpp
pq.top();
```

means:

```text
Access the highest-priority element.
```

```cpp
pq.pop();
```

means:

```text
Remove the highest-priority element.
```

Example:

```cpp
int value = pq.top();
pq.pop();
```

This:

1. Reads the top.
2. Stores it.
3. Removes it.

---

# 36. Empty Priority Queue Safety

Never call:

```cpp
pq.top();
```

on an empty priority queue.

Never call:

```cpp
pq.pop();
```

on an empty priority queue.

Correct:

```cpp
if (!pq.empty())
{
    cout << pq.top();
}
```

or:

```cpp
while (!pq.empty())
{
    cout << pq.top() << " ";
    pq.pop();
}
```

Calling these operations on an empty priority queue results in undefined behavior.

---

# 37. No Iterators

`std::priority_queue` does not expose:

```cpp
begin()
end()
rbegin()
rend()
```

Therefore:

```cpp
pq.begin();
```

is invalid.

The adapter intentionally hides the underlying container's iterator interface.

If you need iterator access, consider using:

```cpp
vector
deque
```

and the heap algorithms:

```cpp
make_heap()
push_heap()
pop_heap()
sort_heap()
```

---

# 38. No Random Access

You cannot write:

```cpp
pq[0];
pq[1];
```

There is no:

```cpp
operator[]
```

The public adapter interface provides only:

```cpp
top()
```

for element access.

---

# 39. No Direct Search

There is no:

```cpp
pq.find(20);
```

and no:

```cpp
pq.contains(20);
```

as `priority_queue` member functions.

If you need frequent arbitrary searches, another data structure may be more appropriate.

---

# 40. Priority Queue Is Not Fully Sorted

This is one of the most important concepts.

A priority queue is a **heap**, not a sorted container.

Suppose:

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(50);
pq.push(30);
pq.push(20);
pq.push(40);
```

The heap might conceptually look like:

```text
        50
      /    \
    40      30
   /  \
 10   20
```

Notice:

```text
40 > 30
```

but the complete sequence is not necessarily:

```text
50 40 30 20 10
```

inside the underlying storage.

Only this guarantee matters:

```text
top() = highest-priority element
```

Repeatedly calling:

```cpp
top();
pop();
```

produces elements in priority order.

---

# 41. Max Heap Example

```cpp
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> pq;

    pq.push(20);
    pq.push(50);
    pq.push(10);
    pq.push(40);

    cout << "Top: "
         << pq.top()
         << endl;

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
```

Output:

```text
Top: 50
50 40 20 10
```

---

# 42. Min Heap Example

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    priority_queue<
        int,
        vector<int>,
        greater<int>
    > pq;

    pq.push(20);
    pq.push(50);
    pq.push(10);
    pq.push(40);

    cout << "Top: "
         << pq.top()
         << endl;

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
```

Output:

```text
Top: 10
10 20 40 50
```

---

# 43. Heap Insertion

Suppose we have a max heap:

```text
        50
      /    \
    30      40
   /  \
 10   20
```

Now insert:

```text
60
```

The new element is initially placed at the next available position:

```text
        50
      /    \
    30      40
   /  \    /
 10   20  60
```

But:

```text
60 > 40
```

so the heap property is violated.

The element moves upward.

```text
        60
      /    \
    30      50
   /  \    /
 10   20  40
```

This is called:

```text
Sift Up
```

or:

```text
Bubble Up
```

The number of levels is logarithmic.

Therefore:

```text
push() = O(log n)
```

---

# 44. Heap Removal

Suppose:

```text
        60
      /    \
    30      50
   /  \    /
 10   20  40
```

Top:

```text
60
```

When the top is removed, the last element is moved to the root:

```text
        40
      /    \
    30      50
   /  \
 10   20
```

The heap property is violated because:

```text
50 > 40
```

So the new root moves downward.

Final:

```text
        50
      /    \
    30      40
   /  \
 10   20
```

This is called:

```text
Sift Down
```

or:

```text
Heapify Down
```

Therefore:

```text
pop() = O(log n)
```

---

# 45. Sift Up / Bubble Up

Used mainly after insertion.

Process:

```text
Insert at end
      ↓
Compare with parent
      ↓
If priority is higher
      ↓
Swap
      ↓
Repeat
```

Example:

```text
       50
      /
    30
```

Insert:

```text
60
```

Initially:

```text
       50
      /  \
    30   60
```

Swap:

```text
       60
      /  \
    30   50
```

---

# 46. Sift Down / Heapify Down

Used mainly after removing the top.

Process:

```text
Move last element to root
          ↓
Compare with children
          ↓
Select higher-priority child
          ↓
Swap if necessary
          ↓
Repeat
```

This restores the heap property.

---

# 47. Priority Queue of `pair`

You can store:

```cpp
priority_queue<pair<int, int>> pq;
```

Example:

```cpp
pq.push({10, 1});
pq.push({20, 2});
pq.push({15, 3});
```

Top:

```text
{20, 2}
```

because `20` is the largest first value.

---

# 48. Pair Ordering

`std::pair` uses **lexicographical comparison**.

For:

```cpp
pair<int, int>
```

comparison works as:

```text
Compare first
    ↓
If equal
    ↓
Compare second
```

Example:

```cpp
priority_queue<pair<int,int>> pq;

pq.push({10, 100});
pq.push({20, 1});
pq.push({20, 5});
```

The top is:

```text
{20, 5}
```

because:

```text
20 == 20
```

so the second values are compared:

```text
5 > 1
```

---

# 49. Pair Min Heap

Example:

```cpp
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;
```

Now the smallest pair is at the top according to pair's lexicographical ordering.

Example:

```cpp
pq.push({10, 5});
pq.push({20, 1});
pq.push({10, 2});
```

Top:

```text
{10, 2}
```

because:

```text
10 == 10
```

and:

```text
2 < 5
```

---

# 50. Priority Queue of Structure

Example:

```cpp
struct Student
{
    int id;
    int marks;
};
```

Create a comparator:

```cpp
struct Compare
{
    bool operator()(
        const Student& a,
        const Student& b
    ) const
    {
        return a.marks < b.marks;
    }
};
```

Create the priority queue:

```cpp
priority_queue<
    Student,
    vector<Student>,
    Compare
> pq;
```

Now the student with the highest marks appears at:

```cpp
pq.top()
```

---

# 51. Custom Comparator Class

Example:

```cpp
struct Compare
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};
```

Use:

```cpp
priority_queue<
    int,
    vector<int>,
    Compare
> pq;
```

This creates a min heap.

---

# 52. Comparator Logic

The comparator is often confusing.

For a custom priority queue:

```cpp
return true
```

means that `a` should have lower priority than `b` under the heap ordering.

For example:

```cpp
struct Compare
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};
```

This gives the smaller integer higher priority.

Therefore:

```text
top() -> smallest value
```

### Important

Do not think of the comparator simply as:

```text
"return true if a should be at the top"
```

Instead, understand it as defining the ordering used by the heap.

---

# 53. Lambda Comparator

Modern C++ allows lambdas.

Example:

```cpp
auto cmp = [](int a, int b)
{
    return a > b;
};

priority_queue<
    int,
    vector<int>,
    decltype(cmp)
> pq(cmp);
```

This creates a min heap.

Insert:

```cpp
pq.push(30);
pq.push(10);
pq.push(20);
```

Top:

```text
10
```

---

# 54. Multiple-Condition Comparator

Suppose:

```cpp
struct Student
{
    string name;
    int marks;
};
```

Requirement:

1. Higher marks first.
2. If marks are equal, lexicographically smaller name first.

Comparator:

```cpp
struct Compare
{
    bool operator()(
        const Student& a,
        const Student& b
    ) const
    {
        if (a.marks != b.marks)
            return a.marks < b.marks;

        return a.name > b.name;
    }
};
```

Priority queue:

```cpp
priority_queue<
    Student,
    vector<Student>,
    Compare
> pq;
```

---

# 55. Custom Object with `emplace()`

Example:

```cpp
struct Student
{
    int marks;
    string name;

    Student(int marks, string name)
        : marks(marks), name(name)
    {
    }
};
```

Then:

```cpp
pq.emplace(95, "Amit");
pq.emplace(88, "Rahul");
pq.emplace(99, "Deep");
```

The priority queue constructs the objects directly.

---

# 56. Priority Queue with `vector`

This is the default:

```cpp
priority_queue<
    int,
    vector<int>
> pq;
```

Equivalent to:

```cpp
priority_queue<int> pq;
```

with the default comparator.

---

# 57. Priority Queue with `deque`

A `deque` can also be used:

```cpp
priority_queue<
    int,
    deque<int>
> pq;
```

The heap operations can use the random-access interface provided by `deque`.

---

# 58. Traversing / Printing

There is no iterator-based traversal.

The normal approach is:

```cpp
while (!pq.empty())
{
    cout << pq.top() << " ";
    pq.pop();
}
```

For a max heap:

```text
Largest
   ↓
Next largest
   ↓
...
Smallest
```

This produces priority order because every removal exposes the next highest-priority element.

---

# 59. Traversing Without Destroying

If you need to preserve the original priority queue:

```cpp
priority_queue<int> temp = pq;

while (!temp.empty())
{
    cout << temp.top() << " ";
    temp.pop();
}
```

The original:

```cpp
pq
```

remains unchanged.

For large priority queues, remember that copying the queue itself requires O(n) time and O(n) additional storage.

---

# 60. Move Semantics

Example:

```cpp
priority_queue<int> pq1;

pq1.push(10);
pq1.push(20);
pq1.push(50);

priority_queue<int> pq2(
    std::move(pq1)
);
```

The underlying resources can be transferred.

After moving:

```text
pq2 -> transferred contents
pq1 -> valid but unspecified state
```

Do not assume that `pq1` is empty unless the specific operation guarantees it.

---

# 61. Complexity

| Operation | Complexity |
|---|---:|
| `push()` | O(log n) |
| `emplace()` | O(log n) |
| `pop()` | O(log n) |
| `top()` | O(1) |
| `empty()` | O(1) |
| `size()` | O(1) |
| `swap()` | Typically O(1) |

For `push()` and `emplace()`, the stated complexity is typically amortized with the default `vector` because the underlying vector can reallocate.

---

# 62. Space Complexity

For `N` elements:

```text
O(N)
```

The priority queue stores every element in its underlying container.

There is no separate pointer-based tree allocation for every node in the normal `vector` implementation.

Conceptually:

```text
priority_queue
      ↓
   vector
      ↓
   N elements
```

Additional temporary stack/algorithmic space for individual heap operations is generally O(1), aside from element moves/comparisons and possible underlying-container reallocation.

---

# 63. Heap Algorithms

The C++ STL also provides heap algorithms in:

```cpp
#include <algorithm>
```

Important functions:

```cpp
make_heap()
push_heap()
pop_heap()
sort_heap()
is_heap()
is_heap_until()
```

These algorithms operate on random-access ranges such as:

```cpp
vector
```

---

# 64. `make_heap()`

Converts a range into a heap.

Example:

```cpp
vector<int> v = {
    10, 50, 20, 40, 30
};

make_heap(v.begin(), v.end());
```

By default, this creates a max heap.

After:

```cpp
v.front()
```

contains the largest element.

Complexity:

```text
O(n)
```

---

# 65. `push_heap()`

Assume:

```cpp
vector<int> v = {
    50, 40, 30
};
```

It is already a max heap.

Add a new value:

```cpp
v.push_back(60);
```

The heap property is temporarily broken.

Call:

```cpp
push_heap(v.begin(), v.end());
```

Now the range is a valid max heap again.

Complexity:

```text
O(log n)
```

---

# 66. `pop_heap()`

For:

```cpp
vector<int> v = {
    50, 40, 30, 20, 10
};
```

Call:

```cpp
pop_heap(v.begin(), v.end());
```

The largest element is moved to the end.

Then:

```cpp
v.pop_back();
```

actually removes it.

Important distinction:

```cpp
pop_heap()
```

does not reduce the vector's size.

It rearranges the range so that the heap's top element moves to the end.

---

# 67. `sort_heap()`

After a range is a heap:

```cpp
sort_heap(v.begin(), v.end());
```

sorts the heap range.

For the default comparator, the result is ascending order.

Example:

```cpp
vector<int> v = {
    10, 50, 20, 40, 30
};

make_heap(v.begin(), v.end());
sort_heap(v.begin(), v.end());
```

Result:

```text
10 20 30 40 50
```

Complexity:

```text
O(n log n)
```

---

# 68. `is_heap()`

Checks whether a range satisfies the heap property.

Example:

```cpp
if (is_heap(v.begin(), v.end()))
{
    cout << "Valid heap";
}
```

Returns:

```text
true
false
```

---

# 69. `is_heap_until()`

Finds the first position where the heap property stops being valid.

Example:

```cpp
auto it =
    is_heap_until(v.begin(), v.end());
```

This is useful when debugging or validating heap ranges.

---

# 70. `priority_queue` vs Heap Algorithms

## `priority_queue`

Use when you want a restricted priority-based container:

```cpp
pq.push();
pq.pop();
pq.top();
```

## Heap Algorithms

Use when you already have a container such as:

```cpp
vector<int>
```

and need direct access to the underlying sequence.

Comparison:

| Feature | `priority_queue` | Heap Algorithms |
|---|---|---|
| Interface | Adapter | Algorithms |
| Iterators | Not exposed | Yes |
| Random access | No | Underlying container supports it |
| Top | `top()` | `front()` |
| Insert | `push()` | `push_back()` + `push_heap()` |
| Remove | `pop()` | `pop_heap()` + `pop_back()` |
| Flexible access | Low | High |

---

# 71. Dijkstra's Algorithm

Dijkstra's shortest-path algorithm commonly uses a min priority queue.

Typical entry:

```cpp
pair<int, int>
```

where:

```text
distance
node
```

Example:

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

Push:

```cpp
pq.push({0, source});
```

The smallest distance appears at the top.

Basic pattern:

```cpp
while (!pq.empty())
{
    auto [distance, node] = pq.top();
    pq.pop();

    // Process node
}
```

This is one of the most important real-world uses of `priority_queue`.

---

# 72. Prim's Algorithm

Prim's minimum spanning tree algorithm can use a min priority queue.

The queue stores candidate edges or:

```text
(weight, vertex)
```

The smallest weight gets processed first.

Example:

```cpp
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;
```

---

# 73. Huffman Coding

Huffman coding repeatedly combines the two smallest frequencies.

A min priority queue is ideal:

```text
frequency
   ↓
smallest first
```

Conceptually:

```text
Push all frequencies
       ↓
Take smallest
       ↓
Take second smallest
       ↓
Combine
       ↓
Push combined frequency
       ↓
Repeat
```

This naturally maps to a min heap.

---

# 74. CPU / Task Scheduling

Suppose tasks have priorities:

```text
Task A -> priority 5
Task B -> priority 10
Task C -> priority 3
```

A priority queue can process:

```text
Task B
Task A
Task C
```

when larger numbers represent higher priority.

The exact scheduling policy in a real operating system may be more complex.

---

# 75. Event Scheduling

Simulation systems often have events with timestamps:

```text
Event A -> time 100
Event B -> time 20
Event C -> time 50
```

A min priority queue can process the earliest event first:

```text
20
50
100
```

This is useful in:

- Discrete-event simulation
- Network simulation
- Scheduling systems
- Time-based event processing

---

# 76. Top-K Largest Elements

Suppose:

```text
10 5 30 20 50 40
```

You want the largest `K` values.

A common technique is a **min heap of size K**.

For:

```text
K = 3
```

keep:

```text
largest 3
```

Conceptually:

```text
min heap
      ↓
smallest among current top K
```

If a new element is larger than the top:

```text
remove smallest
insert new element
```

Complexity:

```text
O(n log k)
```

---

# 77. Top-K Smallest Elements

For the smallest K elements, a common technique is a **max heap of size K**.

The heap top represents the largest value among the current K smallest elements.

If a new value is smaller:

```text
remove current largest
insert new smaller value
```

Complexity:

```text
O(n log k)
```

---

# 78. Merge K Sorted Arrays

Suppose:

```text
A: 1 4 7
B: 2 5 8
C: 3 6 9
```

A min priority queue can store:

```text
value
array index
position index
```

Then repeatedly:

1. Take the smallest current element.
2. Add it to the result.
3. Insert the next element from that same array.

Typical complexity:

```text
O(N log K)
```

where:

```text
N = total number of elements
K = number of arrays
```

---

# 79. Running Median

A common running-median technique uses **two heaps**:

```text
Max Heap
   +
Min Heap
```

Conceptually:

```text
Smaller half
    ↓
Max Heap

Larger half
    ↓
Min Heap
```

The two heaps are balanced so the median can be obtained efficiently.

This is a classic interview problem.

---

# 80. Common Mistakes

## Mistake 1: Assuming It Is Fully Sorted

Wrong idea:

```text
priority_queue = sorted vector
```

Correct:

```text
priority_queue = heap
```

Only the highest-priority element is guaranteed at the top.

---

## Mistake 2: Assuming `pop()` Returns the Element

Wrong:

```cpp
int x = pq.pop();
```

Correct:

```cpp
int x = pq.top();
pq.pop();
```

---

## Mistake 3: Accessing an Empty Queue

Wrong:

```cpp
cout << pq.top();
```

Correct:

```cpp
if (!pq.empty())
{
    cout << pq.top();
}
```

---

## Mistake 4: Trying Iterators

Wrong:

```cpp
pq.begin();
```

`std::priority_queue` does not provide iterators.

---

## Mistake 5: Trying Indexing

Wrong:

```cpp
pq[0];
```

No `operator[]`.

---

## Mistake 6: Wrong Min-Heap Syntax

Correct:

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
```

---

## Mistake 7: Wrong Custom Comparator

Comparator logic is not the same as writing:

```text
"Which element should be top?"
```

You must understand the heap ordering relation.

Test your comparator carefully with:

```text
a < b
a == b
a > b
```

---

## Mistake 8: Assuming Duplicate Elements Are Removed

Duplicates are allowed.

Example:

```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(10);
pq.push(10);
```

All three elements are stored.

---

## Mistake 9: Assuming Equal-Priority Elements Are Stable

A `priority_queue` does not guarantee stable ordering among equivalent-priority elements.

If equal-priority elements must be processed in insertion order, add an explicit tie-breaker such as a sequence number.

---

# 81. Interview Questions

## Q1. What is `std::priority_queue`?

It is a C++ STL container adapter that provides priority-based access to elements.

---

## Q2. What is the default priority queue?

A max heap.

---

## Q3. What is the default top element?

The largest element, according to the default comparator.

---

## Q4. Which container is used by default?

```cpp
vector
```

---

## Q5. Which data structure is used internally?

A binary heap.

---

## Q6. Does priority queue allow duplicates?

Yes.

---

## Q7. Does priority queue maintain all elements in sorted order?

No.

It maintains the heap property.

---

## Q8. Why is `top()` O(1)?

The highest-priority element is stored at the heap root.

---

## Q9. Why is `push()` O(log n)?

The new element may need to move upward through the heap.

---

## Q10. Why is `pop()` O(log n)?

After removing the root, the replacement element may need to move downward.

---

## Q11. How do you create a min heap?

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
```

---

## Q12. Does `pop()` return the removed element?

No.

It returns `void`.

---

## Q13. Does priority queue support iterators?

No.

---

## Q14. Does priority queue support random access?

No.

---

## Q15. Can `vector` be the underlying container?

Yes.

It is the default.

---

## Q16. Can `deque` be used?

Yes.

```cpp
priority_queue<int, deque<int>> pq;
```

---

## Q17. Can `list` be used?

No, because the heap operations require random-access iterators.

---

## Q18. How are pairs compared?

Lexicographically:

```text
first
then second
```

if the first values are equal.

---

## Q19. Can custom objects be stored?

Yes, with an appropriate comparator.

---

## Q20. Can a lambda be used as a comparator?

Yes.

```cpp
auto cmp = [](int a, int b)
{
    return a > b;
};
```

---

## Q21. Is priority queue stable?

No.

Equal-priority elements do not have guaranteed insertion-order preservation.

---

## Q22. What is the complexity of `top()`?

```text
O(1)
```

---

## Q23. What is the complexity of `push()`?

```text
O(log n)
```

amortized with the default vector-based implementation.

---

## Q24. What is the complexity of `pop()`?

```text
O(log n)
```

---

## Q25. What is the complexity of building a heap?

For heap algorithms:

```text
O(n)
```

using:

```cpp
make_heap()
```

---

## Q26. Is `priority_queue` thread-safe?

No.

Concurrent access to the same priority queue requires appropriate synchronization.

---

## Q27. What is the difference between `queue` and `priority_queue`?

```text
queue          -> FIFO
priority_queue -> priority order
```

---

## Q28. What is the difference between `set` and `priority_queue`?

`set` maintains all elements in sorted order and supports ordered lookup.

`priority_queue` exposes only the highest-priority element and supports efficient priority insertion/removal.

---

## Q29. Can a priority queue be used for Dijkstra?

Yes.

A min priority queue is commonly used.

---

## Q30. Why is `greater<int>` used?

It reverses the normal ordering so the smallest integer receives the highest heap priority.

---

## Q31. What is heapify?

Heapify is the process of restoring the heap property after a change.

---

## Q32. What is sift up?

Moving a newly inserted element upward until the heap property is restored.

---

## Q33. What is sift down?

Moving an element downward until the heap property is restored.

---

## Q34. What is a complete binary tree?

A binary tree where all levels are full except possibly the last, and the last level is filled from left to right.

---

## Q35. Why are heaps stored in arrays?

A complete binary tree can be represented compactly without explicit left/right pointers.

---

## Q36. How do you get sorted output from a priority queue?

Repeatedly:

```cpp
cout << pq.top();
pq.pop();
```

This produces priority order but destroys the queue.

---

## Q37. How do you traverse without destroying it?

Copy it:

```cpp
auto temp = pq;
```

then repeatedly pop from the copy.

---

## Q38. Can priority queue store strings?

Yes.

```cpp
priority_queue<string> pq;
```

The default ordering places the lexicographically largest string at the top.

---

## Q39. Can priority queue store pairs?

Yes.

```cpp
priority_queue<pair<int,int>> pq;
```

---

## Q40. Can priority queue store vectors?

Yes, provided the element type and comparison support the required ordering.

---

## Q41. What happens if two elements have equal priority?

Both remain in the priority queue, but their relative removal order is not guaranteed to be stable.

---

## Q42. Can the comparator contain multiple conditions?

Yes.

Example:

```cpp
if (a.marks != b.marks)
    return a.marks < b.marks;

return a.name > b.name;
```

---

## Q43. What is `make_heap()`?

It converts a random-access range into a heap.

---

## Q44. Difference between `pop_heap()` and `priority_queue::pop()`?

`priority_queue::pop()` removes the top element from the adapter.

`std::pop_heap()` rearranges a heap range so the top element moves to the end; it does not reduce the container's size. You normally follow it with `pop_back()`.

---

## Q45. What is the difference between `priority_queue` and `make_heap()`?

`priority_queue` is a container adapter.

`make_heap()` is an STL algorithm that operates on an existing range.

---

## Q46. What is a min heap?

A heap where the smallest element has highest priority and appears at the root/top.

---

## Q47. What is a max heap?

A heap where the largest element has highest priority and appears at the root/top.

---

## Q48. Is a binary heap a binary search tree?

No.

A heap satisfies the heap property, not the BST ordering property.

---

## Q49. Can you search efficiently for an arbitrary value in a priority queue?

No.

The adapter does not provide efficient arbitrary lookup.

---

## Q50. What are common applications of priority queues?

```text
Dijkstra
Prim
Huffman
Scheduling
Event simulation
Top-K
Merge K sorted lists
A*
```

---

# 82. C++ Version Features

| Feature | Standard |
|---|---|
| `std::priority_queue` | C++98 |
| `push()` | C++98 |
| `pop()` | C++98 |
| `top()` | C++98 |
| `empty()` | C++98 |
| `size()` | C++98 |
| `swap()` | C++98 |
| `emplace()` | C++11 |
| Move construction/assignment | C++11 |
| Range constructors | C++98 |
| `constexpr` support | C++26 |

The basic priority-queue design remains intentionally small.

---

# 83. Quick Reference

## Max Heap

```cpp
priority_queue<int> pq;
```

Top:

```text
Largest
```

---

## Min Heap

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
```

Top:

```text
Smallest
```

---

## Insert

```cpp
pq.push(value);
pq.emplace(arguments...);
```

---

## Access

```cpp
pq.top();
```

---

## Remove

```cpp
pq.pop();
```

---

## Capacity

```cpp
pq.empty();
pq.size();
```

---

## Swap

```cpp
pq.swap(other);
```

---

# 84. Comparison with Queue

| Feature | `queue` | `priority_queue` |
|---|---|---|
| Ordering | FIFO | Priority |
| Insert | Back | Heap insertion |
| Remove | Front | Top |
| Access | `front()` | `top()` |
| Push | O(1) | O(log n) |
| Pop | O(1) | O(log n) |
| Top access | O(1) | O(1) |
| Duplicates | Yes | Yes |
| Iterators | No | No |

---

# 85. Comparison with Stack

| Feature | `stack` | `priority_queue` |
|---|---|---|
| Ordering | LIFO | Priority |
| Insert | Top | Heap |
| Remove | Top | Highest priority |
| Access | `top()` | `top()` |
| Push | O(1) | O(log n) |
| Pop | O(1) | O(log n) |
| Main use | DFS, undo | Scheduling, Dijkstra |

---

# 86. Comparison with Set / Multiset

| Feature | `priority_queue` | `set` | `multiset` |
|---|---|---|---|
| Main structure | Heap | Balanced tree | Balanced tree |
| Top/min access | O(1) | O(1) with `begin()` | O(1) with `begin()` |
| Insert | O(log n) | O(log n) | O(log n) |
| Remove top | O(log n) | O(log n) | O(log n) |
| Arbitrary search | No direct member | Yes | Yes |
| Iterators | No | Yes | Yes |
| Duplicates | Yes | No | Yes |
| Fully ordered traversal | No | Yes | Yes |

`set`/`multiset` are better when you need ordered iteration and lookup.

`priority_queue` is better when you mainly need the highest/lowest-priority element.

---

# 87. Comparison with `vector`

| Feature | `priority_queue` | `vector` |
|---|---|---|
| Main model | Heap | Dynamic array |
| Top | `top()` | `back()` |
| Random access | No | Yes |
| Iterators | No | Yes |
| Automatic heap maintenance | Yes | No |
| Search | No direct member | Can search with algorithms |
| Sorted | No | No |
| Priority access | Yes | No |

---

# 88. Comparison with Heap Algorithms

| Feature | `priority_queue` | Heap Algorithms |
|---|---|---|
| Type | Container adapter | Algorithms |
| Main interface | `push/pop/top` | Iterator ranges |
| Iterators exposed | No | Yes through container |
| Random access | No | Underlying range |
| `make_heap()` | Internal concept | Explicit algorithm |
| Flexible access | Limited | High |
| Best for | Priority abstraction | Custom heap manipulation |

---

# 89. Advantages

- Fast access to the highest-priority element.
- O(1) `top()`.
- O(log n) insertion.
- O(log n) removal.
- Efficient binary heap implementation.
- Supports duplicate elements.
- Supports custom comparators.
- Supports custom objects.
- Useful in many graph algorithms.
- Useful for scheduling.
- Useful for Top-K problems.
- Uses memory efficiently compared with pointer-based tree structures for a heap.

---

# 90. Disadvantages

- No iterators.
- No random access.
- No direct search.
- Not fully sorted.
- Cannot efficiently remove an arbitrary element through the adapter interface.
- Equal-priority elements are not stable.
- Custom comparator logic can be difficult to understand.
- If you need ordered traversal and lookup, a tree-based container may be better.
- If you need arbitrary element access, a vector/deque may be better.

---

# 91. When to Use `priority_queue`

Use it when your problem requires:

```text
Repeatedly access the highest-priority item
```

Examples:

```text
Largest item first
Smallest item first
Shortest distance first
Earliest event first
Highest task priority first
```

Common algorithms:

```text
Dijkstra
Prim
Huffman
A*
Top-K
Merge K sorted sequences
```

---

# 92. When Not to Use `priority_queue`

Do not use it when you need:

## FIFO

Use:

```cpp
queue
```

## LIFO

Use:

```cpp
stack
```

## Fully sorted elements + ordered iteration

Use:

```cpp
set
multiset
```

## Random access

Use:

```cpp
vector
deque
```

## Efficient arbitrary key lookup

Consider:

```cpp
set
unordered_set
map
unordered_map
```

depending on the requirement.

---

# 93. Best Practices

## 1. Choose the correct heap

Max heap:

```cpp
priority_queue<int> pq;
```

Min heap:

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
```

---

## 2. Always check `empty()`

Before:

```cpp
top()
pop()
```

use:

```cpp
if (!pq.empty())
```

when emptiness is possible.

---

## 3. Remember `pop()` returns void

Use:

```cpp
auto x = pq.top();
pq.pop();
```

---

## 4. Do not assume complete sorting

Only the top is guaranteed to have highest priority.

---

## 5. Use a copy for non-destructive traversal

```cpp
auto temp = pq;
```

---

## 6. Keep comparator logic strict

Comparators should define a valid ordering. Avoid inconsistent comparisons such as:

```text
a < b
b < a
```

both being true.

For custom types, use `const` references where appropriate:

```cpp
bool operator()(
    const Student& a,
    const Student& b
) const
```

---

## 7. Use tie-breakers when required

If equal-priority elements require deterministic ordering, include another field:

```text
priority
sequence_number
```

For example:

```cpp
pair<int, int>
```

can represent:

```text
priority
insertion order
```

with an appropriate comparator.

---

# 94. Final Summary

`std::priority_queue` is a C++ STL **container adapter** that provides priority-based access.

The default:

```cpp
priority_queue<int>
```

is a:

```text
Max Heap
```

where:

```text
largest element = top
```

A min heap can be created using:

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
```

where:

```text
smallest element = top
```

The default underlying container is:

```cpp
vector<T>
```

The internal data structure is a:

```text
Binary Heap
```

Important operations:

```cpp
push()
emplace()
pop()
top()
empty()
size()
swap()
```

Complexities:

```text
push()    -> O(log n) amortized
emplace() -> O(log n) amortized
pop()     -> O(log n)
top()     -> O(1)
empty()   -> O(1)
size()    -> O(1)
```

Priority queues are especially useful for:

```text
Dijkstra
Prim
Huffman
Scheduling
Top-K
Merge K sorted sequences
Event simulation
```

---

# 95. Mental Model

```text
                    std::priority_queue
                             |
                             v
                    Container Adapter
                             |
                             v
                    Underlying Container
                       default = vector
                             |
                             v
                       Binary Heap
                             |
              +--------------+--------------+
              |                             |
              v                             v
          Max Heap                       Min Heap
       default behavior             greater<T>
              |                             |
              v                             v
       largest at top              smallest at top
```

---

# Heap Mental Model

## Max Heap

```text
             80
           /    \
         50      60
        /  \
      20    40
```

Top:

```text
80
```

---

## Min Heap

```text
             10
           /    \
         20      15
        /  \
      40    30
```

Top:

```text
10
```

---

# Push Mental Model

```text
New element
     |
     v
Insert at end
     |
     v
Compare with parent
     |
     v
Higher priority?
     |
    Yes
     |
     v
Swap upward
     |
     v
Repeat
```

Complexity:

```text
O(log n)
```

---

# Pop Mental Model

```text
Top element
     |
     v
Remove root
     |
     v
Move last element to root
     |
     v
Compare with children
     |
     v
Swap downward
     |
     v
Repeat
```

Complexity:

```text
O(log n)
```

---

# 96. One-Line Definition

> **`std::priority_queue` is a C++ STL container adapter that maintains a heap so that the highest-priority element is always accessible through `top()`, with `std::vector` as its default underlying container and a max-heap ordering by default.**
