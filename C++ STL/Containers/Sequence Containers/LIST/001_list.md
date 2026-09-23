# C++ `std::list` — Doubly Linked List

## 1. Introduction

`std::list` is a **sequence container** provided by the C++ Standard Library.

It is implemented as a **doubly linked list**, where each node conceptually contains:

- The actual data
- A link to the previous node
- A link to the next node

Unlike `std::vector`, `std::list` does **not** store its elements in contiguous memory.

---

# 2. Header File

```cpp
#include <list>
```

For examples using `std::greater`:

```cpp
#include <functional>
```

---

# 3. Namespace

You can use:

```cpp
using namespace std;
```

Then:

```cpp
list<int> l;
```

Or explicitly use the `std` namespace:

```cpp
std::list<int> l;
```

Using `std::list` explicitly is generally preferred in larger codebases because it avoids namespace pollution.

---

# 4. Basic Syntax

```cpp
list<data_type> name;
```

Examples:

```cpp
list<int> l;

list<string> names;

list<pair<int, int>> p;
```

With explicit namespace:

```cpp
std::list<int> l;
```

---

# 5. Internal Working

A `std::list` is conceptually made of nodes connected in both directions.

A node can be represented as:

```text
+-----------+------------+-----------+
| Prev Ptr  |    Data    | Next Ptr  |
+-----------+------------+-----------+
```

Example:

```text
NULL
  ↑
  |
+-----+-----+-----+     +-----+-----+-----+     +-----+-----+------+
|Prev | 10  |Next | --> |Prev | 20  |Next | --> |Prev | 30  |Next  |
+-----+-----+-----+     +-----+-----+-----+     +-----+-----+------+
                                                   |
                                                   ↓
                                                  NULL
```

The important conceptual property is:

```text
Node 1 ←→ Node 2 ←→ Node 3
```

Every element has links in both directions.

Therefore, the container supports:

```text
Forward traversal
        ↓
Backward traversal
```

> The exact node representation is an implementation detail of the standard library. The doubly linked structure is the useful conceptual model.

---

# 6. Characteristics

`std::list` has the following characteristics:

- Dynamic size
- Non-contiguous memory
- Doubly linked structure
- Bidirectional traversal
- No random access
- Fast insertion and deletion when the position is already known
- Efficient insertion/removal at both ends
- Stable iterators to unaffected elements
- Efficient node transfer using `splice()`
- Poorer cache locality than contiguous containers such as `vector`

---

# 7. Why Use `std::list`?

Consider a vector:

```cpp
vector<int> v = {10, 20, 30};

v.insert(v.begin() + 1, 15);
```

Result:

```text
10 15 20 30
```

For a vector, elements after the insertion position may need to be moved.

The insertion itself is therefore generally:

```text
O(n)
```

For a list:

```cpp
list<int> l = {10, 20, 30};

auto it = l.begin();
++it;

l.insert(it, 15);
```

Conceptually, only links need to be adjusted:

```text
10 ↔ 15 ↔ 20 ↔ 30
```

The insertion after reaching the position is:

```text
O(1)
```

The important distinction is:

```text
Finding the position       → may be O(n)
Insertion once position is known → O(1)
```

---

# 8. Creating a List

## 8.1 Empty List

```cpp
list<int> l;
```

The list initially contains no elements.

---

## 8.2 Fixed Number of Elements

```cpp
list<int> l(5);
```

For `int`, the elements are value-initialized:

```text
0 0 0 0 0
```

---

## 8.3 Fixed Number with Initial Value

```cpp
list<int> l(5, 100);
```

Result:

```text
100 100 100 100 100
```

---

## 8.4 Initializer List

```cpp
list<int> l = {1, 2, 3, 4, 5};
```

Result:

```text
1 2 3 4 5
```

---

## 8.5 Copy Constructor

```cpp
list<int> l1 = {1, 2, 3};

list<int> l2(l1);
```

`l2` contains copies of the elements of `l1`.

The nodes themselves are separate.

```text
l1: 1 ↔ 2 ↔ 3

l2: 1 ↔ 2 ↔ 3
```

---

## 8.6 Move Constructor

```cpp
list<int> l1 = {1, 2, 3};

list<int> l2(std::move(l1));
```

The list's resources can be transferred to `l2`, subject to allocator rules.

After the move, `l1` remains a valid object, but its exact contents should not be assumed unless the operation guarantees them.

Use:

```cpp
#include <utility>
```

for `std::move`.

---

# 9. Access Functions

`std::list` provides direct access to the first and last elements.

---

## 9.1 `front()`

```cpp
cout << l.front();
```

Returns the first element.

Example:

```cpp
list<int> l = {10, 20, 30};

cout << l.front();
```

Output:

```text
10
```

Complexity:

```text
O(1)
```

---

## 9.2 `back()`

```cpp
cout << l.back();
```

Returns the last element.

Example:

```cpp
list<int> l = {10, 20, 30};

cout << l.back();
```

Output:

```text
30
```

Complexity:

```text
O(1)
```

---

## 9.3 `operator[]`

```cpp
l[2];
```

❌ Not supported.

`std::list` does not provide random-access indexing.

---

## 9.4 `at()`

```cpp
l.at(2);
```

❌ Not available.

---

# 10. Why No `operator[]`?

Consider:

```text
10 ↔ 20 ↔ 30 ↔ 40 ↔ 50
```

To access element `4`, the list must traverse:

```text
10 → 20 → 30 → 40 → 50
```

It cannot directly calculate an address like a vector can.

Therefore:

```cpp
l[4]
```

is not supported.

Accessing an element by position requires traversal.

---

# 11. Traversing a List

## 11.1 Forward Traversal with Iterator

```cpp
for (auto it = l.begin(); it != l.end(); ++it)
{
    cout << *it << " ";
}
```

---

## 11.2 Range-Based `for` Loop

```cpp
for (int x : l)
{
    cout << x << " ";
}
```

---

## 11.3 Reverse Traversal

Because `std::list` provides bidirectional iterators, it supports reverse iterators.

```cpp
for (auto it = l.rbegin(); it != l.rend(); ++it)
{
    cout << *it << " ";
}
```

Example:

```text
List:

10 20 30

Reverse:

30 20 10
```

---

## 11.4 Traversal Using `--`

A bidirectional iterator supports both:

```cpp
++it;
--it;
```

Example:

```cpp
auto it = l.end();

--it;

cout << *it;
```

This accesses the last element.

---

# 12. Capacity Functions

## 12.1 `size()`

```cpp
l.size();
```

Returns the number of elements.

Example:

```cpp
cout << l.size();
```

For `std::list`, `size()` is constant time in modern C++ implementations conforming to the standard requirements.

Complexity:

```text
O(1)
```

---

## 12.2 `empty()`

```cpp
l.empty();
```

Returns:

```text
true
```

if the list contains no elements.

Otherwise:

```text
false
```

Example:

```cpp
if (l.empty())
{
    cout << "List is empty";
}
```

Complexity:

```text
O(1)
```

---

## 12.3 `max_size()`

```cpp
l.max_size();
```

Returns the maximum number of elements the container can theoretically hold according to the implementation and allocator constraints.

---

## 12.4 `resize()`

Increase the size:

```cpp
l.resize(7);
```

If the list had fewer than seven elements, additional default-inserted elements are added.

Decrease the size:

```cpp
l.resize(3);
```

Elements at the end are removed until the size becomes three.

You can also provide a value for newly created elements:

```cpp
l.resize(7, 100);
```

---

# 13. Insertion Functions

`std::list` provides efficient insertion at both ends and insertion before a known iterator position.

---

## 13.1 `push_back()`

Adds an element to the end.

```cpp
l.push_back(10);
l.push_back(20);
```

Result:

```text
10 20
```

Complexity:

```text
O(1)
```

---

## 13.2 `push_front()`

Adds an element to the beginning.

```cpp
l.push_front(5);
```

Result:

```text
5 10 20
```

Complexity:

```text
O(1)
```

---

## 13.3 `emplace_back()`

Constructs an element directly at the end.

Example:

```cpp
list<pair<int, int>> l;

l.emplace_back(1, 2);
```

The `pair` is constructed directly in the list node.

---

## 13.4 `emplace_front()`

Constructs an element directly at the beginning.

```cpp
list<pair<int, int>> l;

l.emplace_front(3, 4);
```

---

## 13.5 `emplace()`

Constructs an element before the specified iterator position.

```cpp
list<int> l = {10, 20, 30};

auto it = l.begin();
++it;

l.emplace(it, 15);
```

Result:

```text
10 15 20 30
```

---

# 14. `insert()`

## 14.1 Single Element

```cpp
l.insert(it, 50);
```

Inserts `50` immediately before `it`.

---

## 14.2 Multiple Copies

```cpp
l.insert(it, 3, 100);
```

Inserts:

```text
100 100 100
```

before `it`.

---

## 14.3 Range

```cpp
l.insert(it, v.begin(), v.end());
```

Copies the elements in the specified range into the list before `it`.

---

## 14.4 Initializer List

```cpp
l.insert(it, {1, 2, 3});
```

Inserts:

```text
1 2 3
```

before `it`.

---

# 15. Insertion Complexity

For a single insertion using an already-valid iterator:

```cpp
l.insert(it, value);
```

the link manipulation is:

```text
O(1)
```

But if you first need to find the position:

```cpp
auto it = l.begin();

std::advance(it, n);

l.insert(it, value);
```

the traversal can take:

```text
O(n)
```

Therefore:

```text
Find position     → O(n)
Insert             → O(1)
Total              → O(n)
```

This distinction is extremely important in interviews.

---

# 16. Removal Functions

## 16.1 `pop_back()`

Removes the last element.

```cpp
l.pop_back();
```

Complexity:

```text
O(1)
```

---

## 16.2 `pop_front()`

Removes the first element.

```cpp
l.pop_front();
```

Complexity:

```text
O(1)
```

---

## 16.3 `erase()` — Single Element

```cpp
l.erase(it);
```

Removes the element pointed to by `it`.

Complexity:

```text
O(1)
```

for a single element once the iterator is available.

---

## 16.4 `erase()` — Range

```cpp
l.erase(first, last);
```

Removes the elements in:

```text
[first, last)
```

The operation is linear in the number of erased elements.

---

## 16.5 `clear()`

```cpp
l.clear();
```

Removes all elements.

Complexity:

```text
O(n)
```

---

# 17. `remove()`

Removes all elements equal to a specified value.

Example:

```cpp
list<int> l = {1, 2, 3, 2, 4};

l.remove(2);
```

Result:

```text
1 3 4
```

Complexity:

```text
O(n)
```

---

# 18. `remove_if()`

Removes every element satisfying a condition.

Example:

```cpp
l.remove_if([](int x)
{
    return x % 2 == 0;
});
```

This removes all even numbers.

Example:

```text
Before:

1 2 3 4 5 6

After:

1 3 5
```

Complexity:

```text
O(n)
```

---

# 19. `unique()`

`unique()` removes **consecutive equivalent elements**.

Example:

```cpp
list<int> l = {1, 1, 2, 2, 2, 3, 3};

l.unique();
```

Result:

```text
1 2 3
```

Important:

`unique()` does not remove every duplicate from the entire list.

Example:

```text
1 2 1 2
```

contains no consecutive duplicates, so:

```cpp
l.unique();
```

does not remove anything.

To remove all duplicate values:

```cpp
l.sort();
l.unique();
```

Example:

```text
Before:

4 2 1 2 4 3 3

After sort():

1 2 2 3 3 4 4

After unique():

1 2 3 4
```

Complexity:

```text
O(n)
```

---

# 20. `reverse()`

Reverses the order of elements.

```cpp
list<int> l = {1, 2, 3, 4};

l.reverse();
```

Result:

```text
4 3 2 1
```

Complexity:

```text
O(n)
```

The list can reverse its links without moving the stored values between nodes.

---

# 21. `sort()`

`std::list` provides its own member `sort()`.

Ascending:

```cpp
l.sort();
```

Descending:

```cpp
l.sort(std::greater<int>());
```

Example:

```cpp
list<int> l = {5, 2, 4, 1, 3};

l.sort();
```

Result:

```text
1 2 3 4 5
```

---

## 21.1 Why Use `list::sort()`?

This does not work:

```cpp
std::sort(l.begin(), l.end());
```

because `std::sort()` requires **random-access iterators**.

`std::list` provides only **bidirectional iterators**.

Therefore use:

```cpp
l.sort();
```

The member function is designed for linked-list nodes.

Complexity:

```text
O(n log n)
```

---

# 22. `merge()`

`merge()` merges two sorted lists.

Example:

```cpp
list<int> a = {1, 3, 5};

list<int> b = {2, 4, 6};

a.merge(b);
```

Result:

```text
a: 1 2 3 4 5 6
```

After merging:

```text
b: empty
```

The nodes/elements from `b` are transferred into `a`.

The lists should be sorted according to the same comparison ordering.

Complexity:

```text
O(n + m)
```

where:

```text
n = number of elements in a
m = number of elements in b
```

---

# 23. `splice()`

`splice()` transfers nodes from one list to another without copying the stored element values.

This is one of the most important operations provided by `std::list`.

---

## 23.1 Transfer Entire List

```cpp
list<int> a = {1, 2, 3};

list<int> b = {4, 5};

a.splice(a.end(), b);
```

Result:

```text
a: 1 2 3 4 5

b: empty
```

---

## 23.2 Transfer One Element

```cpp
a.splice(pos, b, it);
```

Transfers the element pointed to by `it` from `b` and inserts it before `pos` in `a`.

---

## 23.3 Transfer a Range

```cpp
a.splice(pos, b, first, last);
```

Transfers the range:

```text
[first, last)
```

from `b` to `a`.

---

## 23.4 Why Is `splice()` Useful?

Suppose:

```text
a: 1 2 3
b: 4 5
```

Instead of copying:

```text
4
5
```

into new nodes, the existing nodes can be relinked.

Conceptually:

```text
Before:

a: 1 ↔ 2 ↔ 3

b: 4 ↔ 5


After:

a: 1 ↔ 2 ↔ 3 ↔ 4 ↔ 5

b: empty
```

This can be extremely useful in algorithms that manipulate linked structures.

### Complexity

For whole-list and single-element node transfers, the standard provides constant-time behavior under the appropriate conditions.

Range splicing can additionally depend on the number of transferred elements and the particular overload/allocator requirements.

---

# 24. `assign()`

`assign()` replaces the current contents of the list.

## 24.1 Count and Value

```cpp
l.assign(5, 10);
```

Result:

```text
10 10 10 10 10
```

---

## 24.2 Range

```cpp
l.assign(v.begin(), v.end());
```

Copies elements from the specified range.

---

## 24.3 Initializer List

```cpp
l.assign({1, 2, 3, 4});
```

Result:

```text
1 2 3 4
```

---

# 25. `swap()`

Swaps the contents of two lists.

```cpp
list<int> a = {1, 2};

list<int> b = {10, 20};

a.swap(b);
```

Result:

```text
a: 10 20
b: 1 2
```

You can also use:

```cpp
std::swap(a, b);
```

---

# 26. Iterators

`std::list` provides bidirectional and reverse iterator access.

Important functions:

```cpp
l.begin()
l.end()

l.rbegin()
l.rend()

l.cbegin()
l.cend()

l.crbegin()
l.crend()
```

---

## 26.1 `begin()`

Returns an iterator to the first element.

```cpp
auto it = l.begin();
```

---

## 26.2 `end()`

Returns an iterator representing the position after the last element.

It is not an actual element.

```cpp
for (auto it = l.begin(); it != l.end(); ++it)
{
    cout << *it << " ";
}
```

---

## 26.3 `rbegin()`

Returns a reverse iterator to the last element.

```cpp
auto it = l.rbegin();
```

---

## 26.4 `rend()`

Represents the position before the first element when using reverse iteration.

---

## 26.5 `cbegin()` and `cend()`

Provide const iterators.

```cpp
auto it = l.cbegin();
```

The elements cannot be modified through the iterator.

---

# 27. Iterator Category

`std::list` provides:

```text
Bidirectional Iterator
```

Supported:

```cpp
++it;
--it;
```

Not supported:

```cpp
it + 2;
it - 3;
it[5];
```

Therefore:

```text
Forward traversal      ✓
Backward traversal     ✓
Random access          ✗
```

---

# 28. Random Access

This is invalid:

```cpp
l[5];
```

To reach an element at a position, use an iterator and advance it:

```cpp
auto it = l.begin();

std::advance(it, 5);

cout << *it;
```

For a list, `std::advance()` takes:

```text
O(n)
```

when moving forward five or more positions.

Therefore list positional access is linear.

---

# 29. Copy Operations

## 29.1 Copy Constructor

```cpp
list<int> l1 = {1, 2, 3};

list<int> l2(l1);
```

Copies the elements into new nodes.

---

## 29.2 Copy Assignment

```cpp
l2 = l1;
```

Replaces the contents of `l2` with copies of `l1`'s elements.

---

# 30. Move Operations

## 30.1 Move Constructor

```cpp
list<int> l1 = {1, 2, 3};

list<int> l2(std::move(l1));
```

Transfers resources where permitted by the allocator rules.

---

## 30.2 Move Assignment

```cpp
list<int> l2;

l2 = std::move(l1);
```

Moves the contents/resources of `l1` into `l2`, subject to allocator behavior.

---

# 31. Iterator Invalidation

One major advantage of `std::list` is iterator stability.

In general:

- Inserting elements does not invalidate iterators to existing elements.
- Erasing an element invalidates iterators referring to that erased element.
- Iterators to other elements remain valid.
- `splice()` can transfer nodes while preserving iterators to the transferred elements, subject to the operation's rules.
- `clear()` invalidates iterators to all erased elements.

This makes `std::list` useful when long-lived iterators or references to elements are important.

---

# 32. Time Complexity

| Operation | Complexity |
|---|---:|
| `front()` | O(1) |
| `back()` | O(1) |
| `size()` | O(1) |
| `empty()` | O(1) |
| `push_front()` | O(1) |
| `push_back()` | O(1) |
| `pop_front()` | O(1) |
| `pop_back()` | O(1) |
| Single `insert()` with iterator | O(1) |
| Single `erase()` with iterator | O(1) |
| `remove()` | O(n) |
| `remove_if()` | O(n) |
| `unique()` | O(n) |
| `reverse()` | O(n) |
| `sort()` | O(n log n) |
| `merge()` | O(n + m) |
| `clear()` | O(n) |
| Find/search | O(n) |
| Positional access | O(n) |
| `splice()` whole-list/single-node transfer | O(1) under applicable standard conditions |

### Important

Do not write:

```text
list insertion = always O(1)
```

The accurate statement is:

```text
Insertion after the position is known = O(1)
Finding the position = O(n)
```

So:

```cpp
auto it = l.begin();

std::advance(it, n);

l.insert(it, value);
```

has overall complexity:

```text
O(n)
```

---

# 33. Advantages

## 33.1 Fast Insertion

Once the iterator is known:

```cpp
l.insert(it, value);
```

is constant time for a single element.

---

## 33.2 Fast Deletion

Once the iterator is known:

```cpp
l.erase(it);
```

is constant time for a single element.

---

## 33.3 No Element Shifting

Unlike vector insertion, list insertion does not require shifting all subsequent stored values.

---

## 33.4 Fast Operations at Both Ends

```cpp
push_front()
push_back()

pop_front()
pop_back()
```

are O(1).

---

## 33.5 Efficient Node Transfer

```cpp
splice()
```

can transfer existing nodes without copying the stored values.

---

## 33.6 Stable Iterators

Iterators to unaffected elements generally remain valid after insertion and erasure.

---

## 33.7 Bidirectional Traversal

The container supports:

```cpp
++it;
--it;
```

---

# 34. Disadvantages

## 34.1 No Random Access

You cannot use:

```cpp
l[5];
```

---

## 34.2 Higher Memory Usage

Each node needs links for both directions.

Conceptually:

```text
Prev + Data + Next
```

---

## 34.3 Poor Cache Locality

Nodes are generally allocated separately and may be scattered throughout memory.

Compared with a vector:

```text
vector:

[10][20][30][40][50]
```

List:

```text
Node 10 → memory location A
Node 20 → memory location X
Node 30 → memory location C
Node 40 → memory location M
Node 50 → memory location Z
```

The scattered layout can make traversal slower even when the algorithmic complexity is O(n).

---

## 34.4 Linear Search

Searching for an element requires traversal:

```cpp
std::find(l.begin(), l.end(), value);
```

Complexity:

```text
O(n)
```

---

## 34.5 Binary Search Is Not a Good Fit

Even if a list is sorted, repeatedly moving to the middle is not constant time.

Algorithms that rely on random access are generally much more suitable for containers such as `vector`.

---

# 35. `vector` vs `deque` vs `list`

| Feature | `vector` | `deque` | `list` |
|---|---|---|---|
| Basic structure | Dynamic array | Segmented array | Doubly linked list |
| Memory layout | Contiguous | Block-based | Non-contiguous nodes |
| Random access | O(1) | O(1) | No |
| `front()` | O(1) | O(1) | O(1) |
| `back()` | O(1) | O(1) | O(1) |
| `push_front()` | O(n) | O(1) | O(1) |
| `push_back()` | Amortized O(1) | O(1) | O(1) |
| `pop_front()` | O(n) | O(1) | O(1) |
| `pop_back()` | O(1) | O(1) | O(1) |
| Middle insertion | O(n) | O(n) | O(1)* |
| Middle erasure | O(n) | O(n) | O(1)* |
| Forward traversal | Yes | Yes | Yes |
| Backward traversal | Yes | Yes | Yes |
| Per-element links | None | None | Prev + Next |
| Cache locality | Excellent | Good | Poorer |
| Best use | General-purpose sequence | Both-end operations + indexing | Frequent node insertion/erasure with stable iterators |

`*` Assumes the iterator to the position is already available.

---

# 36. `list` vs `forward_list`

| Feature | `std::list` | `std::forward_list` |
|---|---|---|
| Structure | Doubly linked | Singly linked |
| Previous link | Yes | No |
| Next link | Yes | Yes |
| Forward traversal | Yes | Yes |
| Backward traversal | Yes | No |
| Iterator category | Bidirectional | Forward |
| `front()` | Yes | Yes |
| `back()` | Yes | No |
| `push_front()` | Yes | Yes |
| `push_back()` | Yes | No |
| `pop_front()` | Yes | Yes |
| `pop_back()` | Yes | No |
| `insert()` | Yes | No direct equivalent |
| `insert_after()` | No | Yes |
| `erase()` | Yes | No direct equivalent |
| `erase_after()` | No | Yes |
| Splicing | `splice()` | `splice_after()` |
| Per-node link overhead | Higher | Lower |
| Backward movement | Yes | No |

---

# 37. When to Use `std::list`

Use `std::list` when:

- Frequent insertion and deletion are required at known positions.
- Frequent insertion/removal at both ends is required.
- Stable iterators/references to elements are important.
- Bidirectional traversal is required.
- You need efficient `splice()`.
- You need linked-list-specific `sort()` or `merge()`.
- Random access is not required.

---

# 38. When NOT to Use `std::list`

Do not automatically choose `list` simply because insertion/deletion is frequent.

Prefer another container when:

- You need random access → usually `vector` or `deque`
- You need excellent cache locality → usually `vector`
- You mainly append elements → usually `vector`
- You need indexing → `vector` or `deque`
- You need a hash-based lookup → `unordered_map` / `unordered_set`
- You need ordered key lookup → `map` / `set`

A linked list can have worse real-world performance than a vector because of allocation overhead and poor cache locality, even when both operations have apparently favorable Big-O characteristics.

---

# 39. Common Interview Questions

## Q1. What is `std::list`?

```text
A C++ STL sequence container implemented as a doubly linked list.
```

---

## Q2. Does `std::list` support random access?

```text
No.
```

You cannot use:

```cpp
l[2];
```

---

## Q3. Can we use `operator[]` with `list`?

```text
No.
```

---

## Q4. Does `list` have `at()`?

```text
No.
```

---

## Q5. Which iterator category does `list` provide?

```text
Bidirectional Iterator
```

It supports:

```cpp
++it;
--it;
```

but not:

```cpp
it + 2;
it - 2;
```

---

## Q6. Why is insertion into a list O(1)?

If the iterator to the insertion position is already available, only a fixed number of links need to be changed.

Therefore:

```text
Insertion itself = O(1)
```

But finding the position can be:

```text
O(n)
```

---

## Q7. Why is `std::sort()` not used directly with `list`?

This is invalid:

```cpp
std::sort(l.begin(), l.end());
```

because `std::sort()` requires random-access iterators.

Use:

```cpp
l.sort();
```

instead.

---

## Q8. What is `splice()`?

`splice()` transfers existing nodes from one list to another without copying the stored element values.

---

## Q9. What is the difference between `remove()` and `erase()`?

`remove(value)` searches the list and removes all matching values.

```cpp
l.remove(10);
```

`erase(iterator)` removes the element at a known iterator position.

```cpp
l.erase(it);
```

Therefore:

```text
remove() → search + remove matching values
erase()  → remove at known iterator/range
```

---

## Q10. What does `unique()` remove?

It removes consecutive equivalent elements.

It does not remove all duplicates unless duplicates have first been made adjacent, for example by sorting.

---

## Q11. Is `list::size()` O(1)?

Yes. Standard `std::list` requirements provide constant-time `size()`.

---

## Q12. Does inserting into a list invalidate existing iterators?

Insertion does not invalidate iterators to existing elements.

---

## Q13. Does erasing a list element invalidate all iterators?

No.

The iterator referring to the erased element is invalidated. Iterators to other elements remain valid.

---

# 40. Complete Example

```cpp
#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> l;

    l.push_back(20);
    l.push_back(30);
    l.push_front(10);

    cout << "Front : " << l.front() << endl;
    cout << "Back  : " << l.back() << endl;

    cout << "Elements : ";

    for (int x : l)
    {
        cout << x << " ";
    }

    cout << endl;

    l.pop_front();
    l.push_back(40);
    l.sort();

    cout << "After operations : ";

    for (int x : l)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
```

Output:

```text
Front : 10
Back  : 30
Elements : 10 20 30
After operations : 20 30 40
```

---

# 41. Practical Example: Insert at a Known Position

```cpp
#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> l = {10, 20, 30};

    auto it = l.begin();

    ++it;

    l.insert(it, 15);

    for (int x : l)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
10 15 20 30
```

The iterator initially points to:

```text
10
```

After:

```cpp
++it;
```

it points to:

```text
20
```

Then:

```cpp
l.insert(it, 15);
```

inserts `15` before `20`.

---

# 42. Practical Example: Erase an Element

```cpp
#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> l = {10, 20, 30, 40};

    auto it = l.begin();

    ++it;

    l.erase(it);

    for (int x : l)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
10 30 40
```

---

# 43. Practical Example: Remove Even Numbers

```cpp
#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> l = {1, 2, 3, 4, 5, 6};

    l.remove_if([](int x)
    {
        return x % 2 == 0;
    });

    for (int x : l)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
1 3 5
```

---

# 44. Practical Example: Sort and Remove Duplicates

```cpp
#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> l = {4, 2, 1, 2, 4, 3, 3};

    l.sort();
    l.unique();

    for (int x : l)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
1 2 3 4
```

Process:

```text
Original:
4 2 1 2 4 3 3

After sort():
1 2 2 3 3 4 4

After unique():
1 2 3 4
```

---

# 45. Practical Example: Reverse Traversal

```cpp
#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> l = {10, 20, 30, 40};

    for (auto it = l.rbegin(); it != l.rend(); ++it)
    {
        cout << *it << " ";
    }

    return 0;
}
```

Output:

```text
40 30 20 10
```

---

# 46. Practical Example: `splice()`

```cpp
#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> a = {1, 2, 3};
    list<int> b = {4, 5, 6};

    a.splice(a.end(), b);

    cout << "a: ";

    for (int x : a)
    {
        cout << x << " ";
    }

    cout << endl;

    cout << "b: ";

    for (int x : b)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
a: 1 2 3 4 5 6
b:
```

The nodes from `b` are transferred into `a`.

---

# 47. Important Mental Model

Think of `std::list` as:

```text
NULL ← NODE ⇄ NODE ⇄ NODE → NULL
```

Each node conceptually knows:

```text
Previous node
      +
Next node
```

Therefore:

```text
Forward traversal       ✓
Backward traversal      ✓
Random access           ✗

push_front()            ✓
push_back()             ✓

pop_front()             ✓
pop_back()              ✓

insert()                ✓
erase()                 ✓

sort()                  ✓
merge()                 ✓
splice()                ✓
```

---

# 48. Quick Revision

```text
Header
------
#include <list>

Container
---------
std::list<T>

Structure
---------
Doubly Linked List

Memory
------
Non-contiguous

Links per node
--------------
Previous + Next

Iterator
--------
Bidirectional Iterator

Random Access
-------------
No

front()
--------
O(1)

back()
------
O(1)

push_front()
------------
O(1)

push_back()
-----------
O(1)

pop_front()
-----------
O(1)

pop_back()
----------
O(1)

insert()
--------
O(1) after position is known

erase()
-------
O(1) for a single known element

Search
------
O(n)

Positional Access
-----------------
O(n)

sort()
------
O(n log n)

merge()
-------
O(n + m)

splice()
--------
Efficient node transfer

remove()
--------
O(n)

remove_if()
-----------
O(n)

unique()
--------
O(n)

reverse()
---------
O(n)

clear()
-------
O(n)

Main Advantage
--------------
Fast node insertion/deletion at known positions
and efficient linked-list operations

Main Limitation
---------------
No random access and poorer cache locality
```

---

# 49. Final Summary

`std::list` is the C++ Standard Library's **doubly linked list** container.

Its key design characteristics are:

```text
std::list
    ↓
Doubly Linked List
    ↓
Non-contiguous memory
    ↓
Bidirectional Iterator
    ↓
No random access
```

Important operations:

```cpp
front()
back()

push_front()
push_back()

pop_front()
pop_back()

insert()
emplace()

erase()
clear()

remove()
remove_if()

unique()
reverse()
sort()
merge()
splice()

assign()
swap()
```

The most important complexity rule is:

```text
Known iterator + insertion/erasure
                ↓
               O(1)
```

but:

```text
Finding a position
        ↓
       O(n)
```

Therefore, `std::list` is useful when you genuinely need linked-list behavior, stable iterators, frequent insertion/erasure at known positions, bidirectional traversal, or efficient node transfer. It is **not automatically faster than `vector`**; for many normal workloads, `vector` is faster because of contiguous memory and better cache locality.
