# C++ `std::forward_list` — Singly Linked List

## 1. Introduction

`std::forward_list` is a **sequence container** introduced in **C++11**.

It is implemented as a **singly linked list**, where each node contains:

- The actual data
- A pointer/reference to the next node

Unlike `std::list`, which is a doubly linked list, `std::forward_list` stores only a link to the next node. This makes it more memory-efficient when backward traversal is not required.

---

## 2. Header File

```cpp
#include <forward_list>
```

---x

## 3. Namespace

You can use:

```cpp
using namespace std;
```

Then:

```cpp
forward_list<int> fl;
```

Or avoid `using namespace std`:

```cpp
std::forward_list<int> fl;
```

---

## 4. Basic Syntax

```cpp
forward_list<data_type> name;
```

Examples:

```cpp
forward_list<int> fl;

forward_list<string> names;

forward_list<pair<int, int>> p;
```

---

# 5. Internal Working

A typical singly linked-list node conceptually contains:

```text
+---------+-----------+
|  Data   | Next Ptr  |
+---------+-----------+
```

Example:

```text
Head
 ↓
+------+------+
|  10  |  o---------+
+------+------+
                    |
                    ↓
              +------+------+
              |  20  | o---------+
              +------+-----+     |
                                  |
                                  ↓
                            +------+------+
                            |  30  | NULL |
                            +------+------+
```

Each node knows only the **next node**.

There is no pointer to the previous node.

> Note: The exact node layout is an implementation detail of the standard library. The important conceptual model is that the list provides forward links only.

---

# 6. Characteristics

`std::forward_list` has these important characteristics:

- Dynamic size
- Non-contiguous memory
- Forward-only traversal
- No random access
- Efficient insertion and deletion at the front
- Efficient insertion and deletion after a known position
- Lower per-node link overhead than `std::list`
- Does not provide direct access to the last element
- Does not provide `push_back()`, `pop_back()`, or `back()`
- Provides `before_begin()` specifically for operations involving the position before the first element

---

# 7. Why Use `forward_list`?

Compare the conceptual node structures.

## `std::list`

A doubly linked list normally contains:

```text
Previous Pointer
Data
Next Pointer
```

Conceptually:

```text
+---------+---------+---------+
|  Prev   |  Data   |  Next   |
+---------+---------+---------+
```

## `std::forward_list`

A singly linked list contains:

```text
Data
Next Pointer
```

Conceptually:

```text
+---------+---------+
|  Data   |  Next   |
+---------+---------+
```

Therefore, `forward_list` can use less memory per node than `list`.

The trade-off is that it cannot move backward through the list.

---

# 8. Creating a `forward_list`

## 8.1 Empty Forward List

```cpp
forward_list<int> fl;
```

Initially:

```text
fl → empty
```

---

## 8.2 Fixed Number of Default-Initialized Elements

```cpp
forward_list<int> fl(5);
```

For `int`, the elements are value-initialized:

```text
0 0 0 0 0
```

---

## 8.3 Fixed Number with an Initial Value

```cpp
forward_list<int> fl(5, 100);
```

Result:

```text
100 100 100 100 100
```

---

## 8.4 Initializer List

```cpp
forward_list<int> fl = {1, 2, 3, 4, 5};
```

Result:

```text
1 2 3 4 5
```

---

## 8.5 Copy Constructor

```cpp
forward_list<int> fl1 = {1, 2, 3};

forward_list<int> fl2(fl1);
```

`fl2` receives copies of all elements.

```text
fl1: 1 → 2 → 3
fl2: 1 → 2 → 3
```

The nodes are separate.

---

## 8.6 Move Constructor

```cpp
forward_list<int> fl1 = {1, 2, 3};

forward_list<int> fl2(std::move(fl1));
```

The list resources are transferred to `fl2`.

After the move, `fl1` remains a valid object, but its exact state should not be assumed unless specified by the operation/library guarantees.

Use:

```cpp
#include <utility>
```

for `std::move`.

---

# 9. Access Functions

Unlike `vector`, `deque`, and `list`, `forward_list` provides only direct access to the first element.

## 9.1 `front()`

```cpp
cout << fl.front();
```

Returns the first element.

Example:

```cpp
forward_list<int> fl = {10, 20, 30};

cout << fl.front();
```

Output:

```text
10
```

### Complexity

```text
O(1)
```

---

## 9.2 `back()`

```cpp
fl.back();
```

❌ Not available.

Reason:

`forward_list` does not provide direct access to the last element.

---

## 9.3 `operator[]`

```cpp
fl[2];
```

❌ Not supported.

---

## 9.4 `at()`

```cpp
fl.at(2);
```

❌ Not supported.

---

# 10. Capacity Functions

## 10.1 `empty()`

```cpp
fl.empty();
```

Returns:

```text
true
```

if the list is empty, otherwise:

```text
false
```

Example:

```cpp
if (fl.empty())
{
    cout << "List is empty";
}
```

### Complexity

```text
O(1)
```

---

## 10.2 `max_size()`

```cpp
fl.max_size();
```

Returns the maximum number of elements the container can theoretically hold according to the implementation and available constraints.

---

## 10.3 `size()`

Historically, `std::forward_list` intentionally did not provide `size()` because maintaining a stored element count would add overhead to a container designed to be lightweight.

In **C++23**, `forward_list::size()` is available.

Example:

```cpp
auto n = fl.size();
```

For older language standards, count elements using:

```cpp
auto n = std::distance(fl.begin(), fl.end());
```

Complexity of `std::distance()` for a forward iterator:

```text
O(n)
```

So for modern code, whether `size()` is available depends on the C++ standard being used.

---

# 11. Iterators

Important iterators include:

```cpp
fl.begin()
fl.end()

fl.before_begin()

fl.cbegin()
fl.cend()

fl.cbefore_begin()
```

---

## 11.1 `begin()`

Returns an iterator referring to the first element.

```cpp
auto it = fl.begin();
```

Conceptually:

```text
begin()
  ↓
10 → 20 → 30 → end
```

---

## 11.2 `end()`

Represents the position after the last element.

It is not an actual element.

```cpp
for (auto it = fl.begin(); it != fl.end(); ++it)
{
    cout << *it << " ";
}
```

---

## 11.3 `before_begin()`

`before_begin()` returns an iterator representing the position immediately before the first element.

Example:

```text
before_begin()
      ↓
      10 → 20 → 30
```

This is especially important because `forward_list` insertion and erasure operations are generally expressed as operations **after** a position.

For example:

```cpp
fl.insert_after(fl.before_begin(), 5);
```

This inserts `5` at the front.

Result:

```text
5 → 10 → 20 → 30
```

---

# 12. Traversing a `forward_list`

## 12.1 Using an Iterator

```cpp
for (auto it = fl.begin(); it != fl.end(); ++it)
{
    cout << *it << " ";
}
```

---

## 12.2 Range-Based `for` Loop

```cpp
for (int x : fl)
{
    cout << x << " ";
}
```

---

## 12.3 Reverse Traversal

```cpp
fl.rbegin();
```

❌ Not supported.

Reason:

`forward_list` supports only forward traversal.

It does not provide reverse iterators.

---

# 13. Iterator Category

`std::forward_list` provides **Forward Iterators**.

Supported:

```cpp
++it
```

Not supported:

```cpp
--it
it + 2
it - 3
it[5]
```

Therefore:

```text
Forward traversal      Yes
Backward traversal     No
Random access          No
```

---

# 14. Insertion Functions

The major difference between `forward_list` and containers such as `vector` is that insertion is expressed using `insert_after()`.

---

## 14.1 `push_front()`

Adds an element at the beginning.

```cpp
fl.push_front(10);
fl.push_front(5);
```

Result:

```text
5 10
```

### Complexity

```text
O(1)
```

---

## 14.2 `emplace_front()`

Constructs an element directly at the front.

Example:

```cpp
forward_list<pair<int, int>> fl;

fl.emplace_front(1, 2);
```

The pair is constructed directly in the list node.

---

## 14.3 `insert_after()` — Single Element

```cpp
auto it = fl.begin();

fl.insert_after(it, 50);
```

If:

```text
10 → 20 → 30
```

then after insertion:

```text
10 → 50 → 20 → 30
```

The iterator `it` points to `10`, so the new element is inserted after `10`.

---

## 14.4 `insert_after()` — Multiple Copies

```cpp
fl.insert_after(it, 3, 100);
```

Inserts three copies of `100` after `it`.

Example:

```text
10 → 20
```

becomes:

```text
10 → 100 → 100 → 100 → 20
```

---

## 14.5 `insert_after()` — Initializer List

```cpp
fl.insert_after(it, {1, 2, 3});
```

Inserts:

```text
1 → 2 → 3
```

after `it`.

---

## 14.6 `insert_after()` — Range

```cpp
fl.insert_after(it, v.begin(), v.end());
```

Copies elements from the specified range into the list.

---

## 14.7 `emplace_after()`

```cpp
auto it = fl.begin();

fl.emplace_after(it, 100);
```

Constructs the new element directly after `it`.

For class types, this can avoid creating a separate temporary object.

---

# 15. Why `insert_after()` Instead of `insert()`?

Because the container is singly linked.

Suppose:

```text
10 → 20 → 30
```

If you have an iterator pointing to `10`, the list can easily change the links to:

```text
10 → 15 → 20 → 30
```

The operation only needs to know the node before the insertion point.

For this reason, `forward_list` provides:

```cpp
insert_after()
erase_after()
emplace_after()
splice_after()
```

---

# 16. Removal Functions

## 16.1 `pop_front()`

Removes the first element.

```cpp
fl.pop_front();
```

### Complexity

```text
O(1)
```

---

## 16.2 `pop_back()`

```cpp
fl.pop_back();
```

❌ Not available.

There is no efficient direct operation for removing the last node because the list does not maintain backward links or direct last-node access.

---

## 16.3 `erase_after()` — Single Element

```cpp
fl.erase_after(it);
```

Removes the element immediately after `it`.

Example:

```text
10 → 20 → 30
```

If `it` points to `10`:

```cpp
fl.erase_after(it);
```

Result:

```text
10 → 30
```

---

## 16.4 `erase_after()` — Range

```cpp
fl.erase_after(first, last);
```

Erases elements after `first` and before `last` according to the `forward_list` range semantics.

---

## 16.5 `clear()`

```cpp
fl.clear();
```

Removes all elements.

After:

```text
empty
```

Complexity:

```text
O(n)
```

---

## 16.6 `remove()`

Removes all elements equal to a specified value.

```cpp
forward_list<int> fl = {1, 2, 3, 2, 4};

fl.remove(2);
```

Result:

```text
1 3 4
```

---

## 16.7 `remove_if()`

Removes every element satisfying a condition.

Example:

```cpp
fl.remove_if([](int x)
{
    return x % 2 == 0;
});
```

This removes even numbers.

---

# 17. `assign()`

Replaces the current contents.

## 17.1 Count and Value

```cpp
fl.assign(5, 10);
```

Result:

```text
10 10 10 10 10
```

---

## 17.2 Range

```cpp
fl.assign(v.begin(), v.end());
```

Copies elements from the range.

---

## 17.3 Initializer List

```cpp
fl.assign({1, 2, 3, 4});
```

Result:

```text
1 2 3 4
```

---

# 18. `reverse()`

Reverses the order of the elements.

```cpp
forward_list<int> fl = {1, 2, 3, 4};

fl.reverse();
```

Result:

```text
4 3 2 1
```

Complexity:

```text
O(n)
```

The operation relinks nodes rather than requiring random access.

---

# 19. `sort()`

Sorts the elements.

```cpp
fl.sort();
```

Example:

```cpp
forward_list<int> fl = {5, 2, 4, 1, 3};

fl.sort();
```

Result:

```text
1 2 3 4 5
```

Descending order:

```cpp
fl.sort(std::greater<int>());
```

Remember to include:

```cpp
#include <functional>
```

### Complexity

```text
O(n log n)
```

The standard library implements sorting in a way appropriate for linked-list iterators; it is not based on random-access algorithms such as the usual vector-oriented `std::sort`.

---

# 20. `merge()`

Merges two sorted `forward_list` containers.

Example:

```cpp
forward_list<int> a = {1, 3, 5};
forward_list<int> b = {2, 4, 6};

a.merge(b);
```

Result:

```text
a: 1 2 3 4 5 6
```

The elements of `b` are transferred into `a`.

After the operation:

```text
b: empty
```

The lists should be sorted according to the same ordering.

### Complexity

```text
O(n + m)
```

where `n` and `m` are the sizes of the two lists.

---

# 21. `splice_after()`

`splice_after()` transfers nodes from one `forward_list` to another without copying the transferred element values.

This is one of the important advantages of linked-list containers.

---

## 21.1 Transfer Entire List

```cpp
forward_list<int> a = {1, 2};
forward_list<int> b = {10, 20};

a.splice_after(a.before_begin(), b);
```

Result:

```text
a: 10 20 1 2
b: empty
```

---

## 21.2 Transfer a Single Element

```cpp
a.splice_after(pos, b, it);
```

The node after `it` in `b` is transferred to `a` after `pos`.

---

## 21.3 Transfer a Range

```cpp
a.splice_after(pos, b, first, last);
```

Transfers the specified node range.

### Complexity

For node transfer itself, the operation is designed to be constant-time where the particular overload and allocator conditions permit it; range operations can additionally depend on the number of transferred elements.

---

# 22. `unique()`

Removes **consecutive duplicate elements**.

Example:

```cpp
forward_list<int> fl = {1, 1, 2, 2, 2, 3};

fl.unique();
```

Result:

```text
1 2 3
```

Important:

`unique()` does not remove every duplicate value from the entire list.

Example:

```text
1 2 1 2
```

After `unique()`:

```text
1 2 1 2
```

because no equal elements are consecutive.

If you want all duplicates grouped first, you can sort:

```cpp
fl.sort();
fl.unique();
```

---

# 23. `swap()`

Swaps the contents of two lists.

```cpp
forward_list<int> a = {1, 2};
forward_list<int> b = {10, 20};

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

# 24. Copy Operations

## 24.1 Copy Constructor

```cpp
forward_list<int> fl1 = {1, 2, 3};

forward_list<int> fl2(fl1);
```

Copies the elements.

---

## 24.2 Copy Assignment

```cpp
fl2 = fl1;
```

Replaces the contents of `fl2` with copies of `fl1`'s elements.

---

# 25. Move Operations

## 25.1 Move Constructor

```cpp
forward_list<int> fl1 = {1, 2, 3};

forward_list<int> fl2(std::move(fl1));
```

Transfers the list's resources when permitted by the allocator and implementation.

---

## 25.2 Move Assignment

```cpp
forward_list<int> fl2;

fl2 = std::move(fl1);
```

Moves the contents/resources of `fl1` into `fl2`, subject to the standard allocator rules.

---

# 26. Important Functions Summary

| Function | Purpose |
|---|---|
| `front()` | Access first element |
| `empty()` | Check whether list is empty |
| `max_size()` | Maximum possible size |
| `size()` | Number of elements in C++23 and later |
| `begin()` | Iterator to first element |
| `end()` | Iterator after last element |
| `before_begin()` | Iterator before first element |
| `push_front()` | Add at front |
| `emplace_front()` | Construct at front |
| `insert_after()` | Insert after a position |
| `emplace_after()` | Construct after a position |
| `pop_front()` | Remove first element |
| `erase_after()` | Remove after a position |
| `clear()` | Remove all elements |
| `remove()` | Remove matching values |
| `remove_if()` | Remove values matching a condition |
| `assign()` | Replace contents |
| `reverse()` | Reverse element order |
| `sort()` | Sort elements |
| `merge()` | Merge sorted lists |
| `splice_after()` | Transfer nodes |
| `unique()` | Remove consecutive duplicates |
| `swap()` | Exchange contents |

---

# 27. Time Complexity

| Operation | Typical Complexity |
|---|---:|
| `front()` | O(1) |
| `empty()` | O(1) |
| `push_front()` | O(1) |
| `pop_front()` | O(1) |
| `insert_after()` | O(1) for a single insertion |
| `emplace_after()` | O(1) for a single insertion |
| `erase_after()` | O(1) for a single element |
| `reverse()` | O(n) |
| `remove()` | O(n) |
| `remove_if()` | O(n) |
| `sort()` | O(n log n) |
| `merge()` | O(n + m) |
| `splice_after()` | Depends on overload/range; node transfer itself can be O(1) |
| `clear()` | O(n) |
| `find()` | O(n) |
| `distance(begin, end)` | O(n) |
| `size()` in C++23 | O(1) |

---

# 28. Iterator Invalidation

One useful property of linked-list containers is that insertion and deletion generally do not invalidate iterators to unaffected elements.

For `forward_list`:

- Inserting nodes does not invalidate iterators to existing elements.
- Erasing a node invalidates iterators referring to the erased node.
- Iterators to other elements remain valid.
- Operations such as `splice_after()` transfer nodes while preserving iterators to the transferred nodes, subject to the standard operation rules.

Always check the specific operation when iterator validity is critical.

---

# 29. Advantages

## 29.1 Lower Per-Node Link Overhead

Compared with `std::list`, each node conceptually needs only one link.

```text
forward_list:

Data + Next
```

instead of:

```text
list:

Prev + Data + Next
```

---

## 29.2 Fast Front Insertion

```cpp
fl.push_front(value);
```

Complexity:

```text
O(1)
```

---

## 29.3 Fast Front Removal

```cpp
fl.pop_front();
```

Complexity:

```text
O(1)
```

---

## 29.4 Efficient Insertion After a Known Node

```cpp
fl.insert_after(it, value);
```

A single insertion after a known position is constant time.

---

## 29.5 Efficient Node Transfer

```cpp
a.splice_after(...);
```

Nodes can be transferred without copying the stored values.

---

## 29.6 Stable Iterators

Insertion and removal generally preserve iterators to unaffected nodes.

---

# 30. Disadvantages

- No random access
- No backward traversal
- No `back()`
- No `push_back()`
- No `pop_back()`
- No `rbegin()` / `rend()`
- `find()` is linear
- Accessing the nth element requires traversal
- Historically no `size()` before C++23
- Poorer cache locality than contiguous containers such as `vector`
- Each node requires dynamic allocation/link information, so despite lower link overhead than `list`, it can still have substantial per-element allocation overhead

---

# 31. `vector` vs `deque` vs `list` vs `forward_list`

| Feature | `vector` | `deque` | `list` | `forward_list` |
|---|---|---|---|---|
| Basic structure | Dynamic array | Double-ended segmented array | Doubly linked list | Singly linked list |
| Memory layout | Contiguous | Block-based | Non-contiguous | Non-contiguous |
| Random access | O(1) | O(1) | No | No |
| Push front | O(n) | O(1) | O(1) | O(1) |
| Push back | Amortized O(1) | O(1) | O(1) | No direct operation |
| Pop front | O(n) | O(1) | O(1) | O(1) |
| Pop back | O(1) | O(1) | O(1) | No direct operation |
| Backward traversal | Yes | Yes | Yes | No |
| Forward traversal | Yes | Yes | Yes | Yes |
| Per-node links | None | None per element | Prev + Next | Next |
| Cache locality | Excellent | Good | Poorer | Poorer |
| Best for | General sequence storage | Efficient both-end operations + indexing | Frequent insertion/erasure with bidirectional traversal | Lightweight forward-only linked operations |

> Complexity for `vector::push_back()` is amortized O(1), not guaranteed O(1) for every individual insertion.

---

# 32. `list` vs `forward_list`

| Feature | `std::list` | `std::forward_list` |
|---|---|---|
| Implementation | Doubly linked list | Singly linked list |
| Previous pointer | Yes | No |
| Next pointer | Yes | Yes |
| Backward traversal | Yes | No |
| Random access | No | No |
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
| `splice()` | Yes | `splice_after()` |
| Per-node link overhead | Higher | Lower |
| Iterator category | Bidirectional | Forward |

---

# 33. When to Use `forward_list`

Use `std::forward_list` when:

- Memory usage per node matters
- You frequently insert elements at the front
- You frequently erase or insert after known nodes
- You only need forward traversal
- You do not need random access
- You do not need direct access to the last element
- You need linked-node operations such as `splice_after()`
- A singly linked list is a natural fit for the algorithm

Avoid it when:

- You frequently need `container[i]`
- You need backward traversal
- You frequently need the last element
- You need `push_back()`/`pop_back()`
- You need excellent cache locality
- A `vector` or `deque` provides the operations you actually need more efficiently

---

# 34. Common Interview Questions

## Q1. What is `forward_list`?

`std::forward_list` is a C++ STL sequence container that provides a singly linked list.

---

## Q2. Which standard introduced `forward_list`?

```text
C++11
```

---

## Q3. Does `forward_list` support random access?

```text
No.
```

It does not support:

```cpp
fl[2];
fl.at(2);
```

---

## Q4. Why does `forward_list` not have `push_back()`?

A `forward_list` is designed as a singly linked list and does not provide direct last-element access.

---

## Q5. Why does `forward_list` not have `back()`?

Because the container does not provide direct access to the last element.

---

## Q6. Why is `before_begin()` needed?

Because many modifying operations are expressed as operations **after** a position.

For example:

```cpp
fl.insert_after(fl.before_begin(), 10);
```

This inserts `10` before the current first element.

---

## Q7. Which iterator category does `forward_list` provide?

```text
Forward Iterator
```

---

## Q8. Can you decrement a `forward_list` iterator?

No.

```cpp
--it;
```

is not supported.

---

## Q9. Does `forward_list` support `rbegin()`?

No.

It supports forward traversal only.

---

## Q10. Does `forward_list` have `size()`?

The historical answer is:

```text
No, before C++23.
```

Since **C++23**, `forward_list::size()` is available.

For older standards:

```cpp
auto count = std::distance(fl.begin(), fl.end());
```

This takes O(n).

---

## Q11. What is the difference between `remove()` and `unique()`?

`remove(value)` removes all elements equal to the specified value.

```cpp
fl.remove(2);
```

`unique()` removes only consecutive equivalent elements.

```cpp
fl.unique();
```

---

## Q12. What is `splice_after()`?

It transfers nodes from one `forward_list` to another without copying the stored element values.

---

## Q13. What is the difference between `insert_after()` and `emplace_after()`?

`insert_after()` inserts an existing value or values.

```cpp
fl.insert_after(it, value);
```

`emplace_after()` constructs the element directly in the list node.

```cpp
fl.emplace_after(it, constructor_arguments...);
```

---

# 35. Complete Example

```cpp
#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> fl = {20, 30};

    // Add element at front
    fl.push_front(10);

    cout << "Front : " << fl.front() << endl;

    cout << "Elements : ";

    for (int x : fl)
    {
        cout << x << " ";
    }

    cout << endl;

    // Remove first element
    fl.pop_front();

    // Insert after first element
    fl.insert_after(fl.begin(), 40);

    cout << "After operations : ";

    for (int x : fl)
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
Elements : 10 20 30
After operations : 20 40 30
```

---

# 36. Practical Example: Remove Even Numbers

```cpp
#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> fl = {1, 2, 3, 4, 5, 6};

    fl.remove_if([](int x)
    {
        return x % 2 == 0;
    });

    for (int x : fl)
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

# 37. Practical Example: Sort and Remove Duplicates

```cpp
#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> fl = {4, 2, 1, 2, 4, 3, 3};

    fl.sort();
    fl.unique();

    for (int x : fl)
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

Why?

First:

```text
4 2 1 2 4 3 3
```

After `sort()`:

```text
1 2 2 3 3 4 4
```

After `unique()`:

```text
1 2 3 4
```

---

# 38. Practical Example: Insert at Front Using `before_begin()`

```cpp
#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> fl = {20, 30};

    auto pos = fl.before_begin();

    fl.insert_after(pos, 10);

    for (int x : fl)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
10 20 30
```

This demonstrates why `before_begin()` is important.

---

# 39. Important Mental Model

Think of `forward_list` as:

```text
HEAD
 ↓
NODE → NODE → NODE → NULL
```

Each node knows:

```text
"Where is the next node?"
```

It does not know:

```text
"Where is the previous node?"
```

Therefore:

```text
Forward traversal     ✓
Backward traversal    ✗
Random access         ✗
Front insertion       ✓
Front deletion        ✓
Insert after node     ✓
Erase after node      ✓
Back access           ✗
```

---

# 40. Quick Revision

```text
Header
------
#include <forward_list>

Container
---------
std::forward_list<T>

Introduced
----------
C++11

Structure
---------
Singly Linked List

Memory
------
Non-contiguous

Links per node
--------------
One conceptual next link

Iterator
--------
Forward Iterator

Random Access
-------------
No

front()
--------
Yes

back()
------
No

push_front()
------------
Yes

push_back()
-----------
No

pop_front()
-----------
Yes

pop_back()
----------
No

insert_after()
--------------
Yes

erase_after()
-------------
Yes

before_begin()
--------------
Yes

reverse()
---------
Yes

sort()
------
Yes

merge()
-------
Yes

splice_after()
--------------
Yes

unique()
--------
Yes

size()
------
C++23 and later

Older standards
---------------
Use distance(begin, end)

Random Access Complexity
-----------------------
Not supported

Front Operations
----------------
O(1)

Search
------
O(n)

Sort
----
O(n log n)

Merge
-----
O(n + m)

Main Advantage
--------------
Lower node-link overhead than std::list

Main Limitation
---------------
Forward traversal only
```

---

# 41. Final Summary

`std::forward_list` is the STL's **singly linked list** container.

Its main design goal is to provide linked-list operations with minimal per-node overhead while supporting only forward traversal.

The most important functions to remember are:

```cpp
front()
push_front()
pop_front()

before_begin()
begin()
end()

insert_after()
emplace_after()
erase_after()

remove()
remove_if()

reverse()
sort()
merge()
splice_after()
unique()

empty()
max_size()
size()       // C++23+
```

The most important concept is:

```text
forward_list
     ↓
Singly Linked List
     ↓
One-way traversal
     ↓
Forward Iterator
     ↓
No random access
     ↓
No back()
     ↓
No push_back()
     ↓
No pop_back()
     ↓
insert_after() / erase_after()
```

`std::forward_list` is a good choice when you need a lightweight linked structure and **forward traversal is sufficient**.
