# C++ STL `std::queue` — Complete Notes

# Table of Contents

1. Introduction
2. FIFO Principle
3. Real-World Examples
4. Header File
5. Namespace
6. Basic Syntax
7. Template Definition
8. Template Parameters
9. What is a Container Adapter?
10. Internal Working
11. Default Underlying Container
12. Supported Underlying Containers
13. Why `vector` Cannot Be Used
14. Queue Structure
15. Main Queue Operations
16. `push()`
17. `emplace()`
18. `pop()`
19. `front()`
20. `back()`
21. `empty()`
22. `size()`
23. `swap()`
24. `push()` vs `emplace()`
25. `front()` vs `back()`
26. `pop()` Behavior
27. Accessing an Empty Queue
28. No Iterators
29. No Random Access
30. No Direct Search
31. Queue with `pair`
32. Queue with Structure
33. Queue of Vectors
34. Queue of Queues
35. Queue Using `list`
36. Queue of Custom Objects
37. Move Semantics
38. Complexity
39. Iterator and Reference Considerations
40. Queue Traversal
41. Emptying a Queue
42. Complete Example
43. BFS Application
44. CPU Scheduling Example
45. Producer-Consumer Concept
46. Queue vs Stack
47. Queue vs Deque
48. Queue vs Priority Queue
49. Queue vs Vector
50. Common Mistakes
51. Important Interview Questions
52. Important C++ Version Features
53. Quick Reference Table
54. Advantages
55. Disadvantages
56. When to Use `std::queue`
57. When Not to Use `std::queue`
58. Final Summary
59. One-Line Definition

---

# 1. Introduction

`std::queue` is a **container adapter** provided by the C++ Standard Template Library (STL).

A queue follows the:

```text
FIFO
```

principle.

FIFO means:

> **First In, First Out**

The first element inserted into the queue is the first element removed.

Example:

```text
push(10)
push(20)
push(30)

Queue:

Front                    Back
  ↓                        ↓
 10   20   30
```

When:

```cpp
q.pop();
```

the `10` is removed.

Remaining:

```text
20 30
```

---

# 2. FIFO Principle

FIFO means:

```text
First element inserted
        ↓
First element removed
```

Example:

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);
```

Queue:

```text
Front                Back
  ↓                    ↓
 10     20     30
```

First:

```cpp
q.pop();
```

removes:

```text
10
```

Now:

```text
20 30
```

Another:

```cpp
q.pop();
```

removes:

```text
20
```

Now:

```text
30
```

---

# 3. Real-World Examples

Queues are used in many real-world situations.

### 3.1 Ticket Counter

```text
Person A
Person B
Person C
```

Person A is served first.

---

### 3.2 Printer Queue

```text
Document A
Document B
Document C
```

Normally, the earlier queued document is processed first.

---

### 3.3 CPU Scheduling

Processes can wait in a queue for CPU service.

---

### 3.4 Call Center

Incoming requests can wait for available agents.

---

### 3.5 Network Packet Processing

Packets may be buffered before processing or transmission.

---

### 3.6 Breadth First Search

BFS uses a queue to process vertices level by level.

---

# 4. Header File

Include:

```cpp
#include <queue>
```

Example:

```cpp
#include <iostream>
#include <queue>
```

---

# 5. Namespace

Using:

```cpp
using namespace std;
```

allows:

```cpp
queue<int> q;
```

Without it:

```cpp
std::queue<int> q;
```

For larger projects, explicitly using `std::queue` is often preferable.

---

# 6. Basic Syntax

Syntax:

```cpp
queue<data_type> queue_name;
```

Examples:

```cpp
queue<int> q;
queue<double> prices;
queue<string> names;
queue<char> letters;
```

---

# 7. Template Definition

Conceptually, `std::queue` is declared like:

```cpp
template<
    class T,
    class Container = deque<T>
>
class queue;
```

The actual standard declaration may include allocator-related implementation details, but the important interface is:

```text
T
+
Underlying Container
```

---

# 8. Template Parameters

## 8.1 `T`

`T` is the type of element stored in the queue.

Examples:

```cpp
queue<int> q;
queue<double> q;
queue<string> q;
```

For:

```cpp
queue<int>
```

the element type is:

```text
int
```

---

## 8.2 `Container`

The second template parameter specifies the underlying container.

Default:

```cpp
deque<T>
```

Therefore:

```cpp
queue<int>
```

is conceptually:

```cpp
queue<int, deque<int>>
```

---

# 9. What is a Container Adapter?

`std::queue` is a **container adapter**.

It is not itself a general-purpose sequence container like:

```cpp
vector
deque
list
```

Instead, it provides a restricted interface over another container.

Conceptually:

```text
             std::queue
                 |
                 v
       Underlying Container
                 |
        +--------+--------+
        |                 |
   push_back()        pop_front()
        |                 |
        +--------+--------+
                 |
              FIFO
```

The queue exposes only operations appropriate for queue behavior.

---

# 10. Internal Working

By default:

```cpp
queue<int> q;
```

uses:

```cpp
deque<int>
```

internally.

Conceptually:

```text
queue<int>
    |
    v
deque<int>
```

When you call:

```cpp
q.push(10);
```

the queue inserts at the back of the underlying container.

Conceptually:

```cpp
c.push_back(10);
```

When you call:

```cpp
q.pop();
```

the queue removes from the front:

```cpp
c.pop_front();
```

Therefore:

```text
push() -> back
pop()  -> front
```

---

# 11. Default Underlying Container

The default underlying container is:

```cpp
std::deque<T>
```

Example:

```cpp
queue<int> q;
```

is conceptually equivalent to:

```cpp
queue<int, deque<int>> q;
```

This is why queue operations are efficient.

---

# 12. Supported Underlying Containers

A queue's underlying container must provide the operations required by the queue adapter.

For standard sequence containers, the practical choices are:

```cpp
deque
list
```

Example:

```cpp
queue<int, list<int>> q;
```

The default is:

```cpp
queue<int> q;
```

which uses:

```cpp
deque<int>
```

---

# 13. Why `vector` Cannot Be Used

You cannot normally write:

```cpp
queue<int, vector<int>> q;
```

because the queue adapter requires efficient support for:

```cpp
push_back()
pop_front()
```

`std::vector` provides:

```cpp
push_back()
```

but does not provide:

```cpp
pop_front()
```

as a member function.

Therefore `vector` is not a valid underlying container for `std::queue`.

---

# 14. Queue Structure

Consider:

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);
q.push(40);
```

Conceptually:

```text
Front                         Back
  ↓                             ↓
+----+----+----+----+
| 10 | 20 | 30 | 40 |
+----+----+----+----+
```

Operations:

```text
pop()
 ↓
10 removed

push(50)
 ↓
50 added at back
```

After:

```text
20 30 40 50
```

---

# 15. Main Queue Operations

The most important `std::queue` functions are:

```cpp
push()
emplace()
pop()
front()
back()
empty()
size()
swap()
```

Remember:

```text
push()    -> insert at back
emplace() -> construct at back
pop()     -> remove from front
front()   -> access first element
back()    -> access last element
empty()   -> check whether empty
size()    -> number of elements
swap()    -> exchange contents
```

---

# 16. `push()`

Adds an element to the back of the queue.

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);
```

Queue:

```text
10 20 30
```

The first inserted element is at the front.

---

## `push()` with String

```cpp
queue<string> q;

q.push("Amit");
q.push("Rahul");
q.push("Deep");
```

Queue:

```text
Amit Rahul Deep
```

---

# 17. `emplace()`

`emplace()` constructs an element directly at the back of the queue.

Example:

```cpp
queue<string> q;

q.emplace("Amit");
q.emplace("Rahul");
```

This is especially useful for complex objects.

---

## Example with Custom Structure

```cpp
struct Student {
    int id;
    string name;
};

queue<Student> q;

q.emplace(101, "Amit");
q.emplace(102, "Rahul");
```

The `Student` objects are constructed directly at the back of the underlying container.

---

# 18. `pop()`

Removes the element at the front.

Example:

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);

q.pop();
```

Before:

```text
10 20 30
```

After:

```text
20 30
```

---

# Important: `pop()` Does Not Return the Element

This is wrong:

```cpp
int x = q.pop();
```

`pop()` returns:

```text
void
```

Correct:

```cpp
int x = q.front();
q.pop();
```

---

# 19. `front()`

Returns a reference to the first element.

Example:

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);

cout << q.front();
```

Output:

```text
10
```

---

## Modify the Front Element

Because `front()` can return a reference:

```cpp
q.front() = 100;
```

Now the front value becomes:

```text
100
```

This is different from `std::set`, where elements cannot be modified through ordinary iterators.

---

# 20. `back()`

Returns a reference to the last element.

Example:

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);

cout << q.back();
```

Output:

```text
30
```

---

## Modify the Back Element

```cpp
q.back() = 100;
```

Now the last element is:

```text
100
```

---

# 21. `empty()`

Checks whether the queue contains no elements.

```cpp
if (q.empty()) {
    cout << "Queue is empty";
}
```

Returns:

```text
true
false
```

Typical complexity:

```text
O(1)
```

---

# 22. `size()`

Returns the number of elements.

Example:

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);

cout << q.size();
```

Output:

```text
3
```

Typical complexity:

```text
O(1)
```

---

# 23. `swap()`

Swaps the contents of two queues.

Example:

```cpp
queue<int> q1;

q1.push(10);
q1.push(20);

queue<int> q2;

q2.push(100);
q2.push(200);

q1.swap(q2);
```

After:

```text
q1:
100 200

q2:
10 20
```

You can also use:

```cpp
swap(q1, q2);
```

---

# 24. `push()` vs `emplace()`

## `push()`

You provide an already-created object/value:

```cpp
Student s{101, "Amit"};

q.push(s);
```

or:

```cpp
q.push(Student{101, "Amit"});
```

---

## `emplace()`

You provide constructor arguments:

```cpp
q.emplace(101, "Amit");
```

The object is constructed directly at the destination.

### General idea

```text
push()
   ↓
Provide an object/value

emplace()
   ↓
Provide constructor arguments
   ↓
Construct object in place
```

---

# 25. `front()` vs `back()`

For:

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);
```

Queue:

```text
Front                Back
 ↓                     ↓
10      20      30
```

Therefore:

```cpp
q.front()
```

returns:

```text
10
```

and:

```cpp
q.back()
```

returns:

```text
30
```

---

# 26. `pop()` Behavior

`pop()`:

```cpp
q.pop();
```

removes only the front element.

It does not:

- Return the removed element.
- Remove the back element.
- Return a value.

Correct pattern:

```cpp
if (!q.empty()) {

    int value = q.front();

    q.pop();
}
```

---

# 27. Accessing an Empty Queue

Do not call:

```cpp
q.front();
```

when the queue is empty.

Also avoid:

```cpp
q.back();
```

on an empty queue.

And do not call:

```cpp
q.pop();
```

on an empty queue.

Always check:

```cpp
if (!q.empty()) {
    cout << q.front();
}
```

or:

```cpp
while (!q.empty()) {
    cout << q.front();
    q.pop();
}
```

Calling these operations on an empty queue leads to undefined behavior.

---

# 28. No Iterators

`std::queue` does not expose:

```cpp
begin()
end()
rbegin()
rend()
```

Therefore this is invalid:

```cpp
q.begin();
```

The queue intentionally provides a restricted interface.

If you need general traversal and iterator access, consider using:

```cpp
deque
list
vector
```

depending on your requirements.

---

# 29. No Random Access

You cannot do:

```cpp
q[0];
q[1];
q[2];
```

There is no `operator[]`.

You can access only:

```cpp
front()
back()
```

and remove through:

```cpp
pop()
```

---

# 30. No Direct Search

There is no:

```cpp
q.find(20);
```

and no:

```cpp
q.contains(20);
```

as queue member functions.

If you need arbitrary searching, a queue is generally not the appropriate abstraction.

If necessary, you can repeatedly inspect and remove elements, or work with the underlying data structure directly in a design where such access is appropriate.

---

# 31. Queue with `pair`

You can store pairs:

```cpp
queue<pair<int, int>> q;
```

Example:

```cpp
q.push({1, 2});
q.push({3, 4});
```

Access:

```cpp
cout << q.front().first << " ";
cout << q.front().second;
```

Output:

```text
1 2
```

Common use cases include:

```text
row, column
x, y
source, destination
id, priority
```

---

# 32. Queue with Structure

Example:

```cpp
struct Student {

    int id;
    string name;
};

queue<Student> q;

q.push({1, "Rahul"});
q.push({2, "Amit"});
```

Access:

```cpp
cout << q.front().id;
cout << q.front().name;
```

---

# 33. Queue of Vectors

A queue can store vectors:

```cpp
queue<vector<int>> q;
```

Example:

```cpp
q.push({1, 2, 3});
q.push({4, 5, 6});
```

Access:

```cpp
cout << q.front()[0];
```

Output:

```text
1
```

This is useful when each queue element represents a collection of values.

---

# 34. Queue of Queues

You can have:

```cpp
queue<queue<int>> q;
```

Example:

```cpp
queue<int> q1;
q1.push(10);
q1.push(20);

queue<int> q2;
q2.push(30);
q2.push(40);

queue<queue<int>> mainQueue;

mainQueue.push(q1);
mainQueue.push(q2);
```

This creates a queue whose elements are themselves queues.

---

# 35. Queue Using `list`

You can specify `list` as the underlying container:

```cpp
queue<int, list<int>> q;
```

Example:

```cpp
#include <iostream>
#include <queue>
#include <list>

using namespace std;

int main() {

    queue<int, list<int>> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.front();

    return 0;
}
```

Output:

```text
10
```

---

# 36. Queue of Custom Objects

Example:

```cpp
class Employee {

public:

    int id;
    string name;

    Employee(int id, string name)
        : id(id), name(name) {}
};

queue<Employee> employees;

employees.emplace(101, "Amit");
employees.emplace(102, "Rahul");
```

Access:

```cpp
cout << employees.front().id;
cout << employees.front().name;
```

---

# 37. Move Semantics

A queue supports move construction and move assignment.

Example:

```cpp
queue<int> q1;

q1.push(10);
q1.push(20);

queue<int> q2(std::move(q1));
```

The contents can be transferred from `q1` to `q2`.

After the move:

```text
q1 -> valid but unspecified state
q2 -> contains transferred contents
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

# 38. Complexity

For the default underlying container `deque`, the primary queue operations are constant time.

| Operation | Typical Complexity |
|---|---:|
| `push()` | O(1) |
| `emplace()` | O(1) |
| `pop()` | O(1) |
| `front()` | O(1) |
| `back()` | O(1) |
| `empty()` | O(1) |
| `size()` | O(1) |
| `swap()` | O(1) under normal allocator/container conditions |

The exact complexity of `swap()` can depend on the underlying container and allocator configuration.

### Important

Remember:

```text
push()    -> O(1)
pop()     -> O(1)
front()   -> O(1)
back()    -> O(1)
empty()   -> O(1)
size()    -> O(1)
```

These are the key queue complexities.

---

# 39. Iterator and Reference Considerations

`std::queue` itself does not expose iterators.

Iterator invalidation rules are therefore not directly part of its public interface.

If you need to reason about references returned by:

```cpp
front()
back()
```

remember that modifying the queue can invalidate references depending on what happens to the underlying container and element.

For example:

```cpp
auto& x = q.front();

q.pop();
```

After `pop()`, `x` refers to an element that has been removed and must not be used.

General rule:

> Do not keep references or pointers to queue elements across operations that may remove or invalidate those elements unless you have verified the underlying-container guarantees.

---

# 40. Queue Traversal

There is no direct iterator-based traversal.

The standard way to process all elements is:

```cpp
while (!q.empty()) {

    cout << q.front() << " ";

    q.pop();
}
```

Example:

```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);

while (!q.empty()) {

    cout << q.front() << " ";

    q.pop();
}
```

Output:

```text
10 20 30
```

### Important

This traversal **destroys the queue** because every element is popped.

---

# 41. Emptying a Queue

To remove all elements:

```cpp
while (!q.empty()) {
    q.pop();
}
```

After the loop:

```cpp
q.empty()
```

returns:

```text
true
```

---

# 42. Complete Example

```cpp
#include <iostream>
#include <queue>

using namespace std;

int main() {

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Front : "
         << q.front()
         << endl;

    cout << "Back  : "
         << q.back()
         << endl;

    cout << "Size  : "
         << q.size()
         << endl;

    cout << "Elements : ";

    while (!q.empty()) {

        cout << q.front() << " ";

        q.pop();
    }

    cout << endl;

    cout << "Empty : "
         << boolalpha
         << q.empty();

    return 0;
}
```

Output:

```text
Front : 10
Back  : 40
Size  : 4
Elements : 10 20 30 40
Empty : true
```

---

# 43. BFS Application

One of the most important applications of a queue is:

```text
Breadth First Search
```

BFS processes nodes level by level.

Example graph:

```text
        1
       / \
      2   3
     / \
    4   5
```

BFS traversal:

```text
1 2 3 4 5
```

Conceptually:

```text
Queue:
1

Process 1
↓
Push 2, 3

Queue:
2 3

Process 2
↓
Push 4, 5

Queue:
3 4 5

Process 3

Queue:
4 5

...
```

Basic BFS structure:

```cpp
queue<int> q;

q.push(start);

while (!q.empty()) {

    int node = q.front();
    q.pop();

    // Process node

    // Add neighboring nodes
}
```

---

# 44. CPU Scheduling Example

Suppose processes arrive:

```text
P1
P2
P3
P4
```

A simple FIFO scheduling model can process them in arrival order:

```text
P1 -> P2 -> P3 -> P4
```

Conceptually:

```cpp
queue<string> processes;

processes.push("P1");
processes.push("P2");
processes.push("P3");
processes.push("P4");

while (!processes.empty()) {

    string process = processes.front();

    processes.pop();

    // Execute process
}
```

Actual operating-system scheduling algorithms can be more complex and may use priorities, time slices, or other policies.

---

# 45. Producer-Consumer Concept

A queue is commonly used between:

```text
Producer
    ↓
 Queue
    ↓
Consumer
```

Example concept:

```text
Producer
   |
   | push()
   v
+--------+
| Queue  |
+--------+
   |
   | pop()
   v
Consumer
```

The producer adds work:

```cpp
q.push(task);
```

The consumer removes work:

```cpp
task = q.front();
q.pop();
```

In multithreaded applications, `std::queue` by itself is **not thread-safe**. Synchronization such as mutexes and condition variables is required when multiple threads concurrently access the same queue.

---

# 46. Queue vs Stack

| Feature | Queue | Stack |
|---|---|---|
| Principle | FIFO | LIFO |
| Insert | Back | Top |
| Remove | Front | Top |
| Insert function | `push()` | `push()` |
| Remove function | `pop()` | `pop()` |
| First access | `front()` | `top()` |
| Last access | `back()` | `top()` |
| Iterators | No | No |
| Random access | No | No |
| Typical use | BFS, scheduling | DFS, undo |

---

# 47. Queue vs Deque

| Feature | Queue | Deque |
|---|---|---|
| Type | Container adapter | Container |
| Insert front | No | Yes |
| Insert back | Yes | Yes |
| Remove front | Yes | Yes |
| Remove back | No | Yes |
| `front()` | Yes | Yes |
| `back()` | Yes | Yes |
| Iterators | No | Yes |
| Random access | No | Yes |
| Flexibility | Restricted | More flexible |

A `queue` intentionally restricts access to enforce FIFO behavior.

A `deque` provides operations at both ends and direct element access.

---

# 48. Queue vs Priority Queue

| Feature | Queue | Priority Queue |
|---|---|---|
| Ordering | FIFO | Priority |
| First removed | Oldest element | Highest/lowest priority |
| Insert | `push()` | `push()` |
| Remove | `pop()` | `pop()` |
| Access | `front()` | `top()` |
| Main principle | Arrival order | Priority order |

Example queue:

```text
10
20
30
```

Pop order:

```text
10
20
30
```

Priority queue:

```text
10 priority
50 priority
20 priority
```

Depending on comparator, highest or lowest priority is removed first.

---

# 49. Queue vs Vector

| Feature | Queue | Vector |
|---|---|---|
| FIFO interface | Yes | No |
| Random access | No | Yes |
| `operator[]` | No | Yes |
| Iterators | No | Yes |
| `front()` | Yes | Yes |
| `back()` | Yes | Yes |
| `push_back()` | Hidden behind `push()` | Yes |
| `pop_front()` | Provided through `pop()` | No |
| Automatic sorting | No | No |

Use `vector` when you need random access.

Use `queue` when you specifically need FIFO behavior.

---

# 50. Common Mistakes

## Mistake 1: Accessing an Empty Queue

Wrong:

```cpp
cout << q.front();
```

when:

```cpp
q.empty() == true
```

Correct:

```cpp
if (!q.empty()) {
    cout << q.front();
}
```

---

## Mistake 2: Calling `pop()` on an Empty Queue

Wrong:

```cpp
q.pop();
```

without checking whether the queue contains an element.

Correct:

```cpp
if (!q.empty()) {
    q.pop();
}
```

---

## Mistake 3: Assuming `pop()` Returns the Value

Wrong:

```cpp
int x = q.pop();
```

Correct:

```cpp
int x = q.front();
q.pop();
```

---

## Mistake 4: Trying to Use Iterators

Wrong:

```cpp
q.begin();
```

`std::queue` does not provide iterators.

---

## Mistake 5: Trying Random Access

Wrong:

```cpp
cout << q[2];
```

A queue does not provide indexing.

---

## Mistake 6: Assuming `queue<int, vector<int>>` Works

It does not, because `vector` does not provide the required `pop_front()` interface.

---

## Mistake 7: Assuming `queue` Is Thread-Safe

It is not.

If multiple threads access the same queue concurrently, external synchronization is required.

---

## Mistake 8: Traversing Without Realizing the Queue Is Destroyed

This:

```cpp
while (!q.empty()) {
    cout << q.front();
    q.pop();
}
```

processes all elements but leaves:

```text
q = empty
```

If you need to preserve the queue, copy it first:

```cpp
auto copy = q;

while (!copy.empty()) {
    cout << copy.front() << " ";
    copy.pop();
}
```

---

# 51. Important Interview Questions

## Q1. What is `std::queue`?

`std::queue` is a C++ STL **container adapter** that provides FIFO behavior.

---

## Q2. What does FIFO mean?

```text
First In
First Out
```

The first inserted element is the first removed.

---

## Q3. Where are elements inserted?

At the:

```text
back / rear
```

using:

```cpp
push()
```

or:

```cpp
emplace()
```

---

## Q4. Where are elements removed?

From the:

```text
front
```

using:

```cpp
pop()
```

---

## Q5. Which container does queue use by default?

```cpp
std::deque<T>
```

---

## Q6. Can `vector` be used as the underlying container?

No.

`std::vector` does not provide the required `pop_front()` member function.

---

## Q7. Can `list` be used?

Yes.

```cpp
queue<int, list<int>> q;
```

---

## Q8. Does `pop()` return the removed element?

No.

It returns `void`.

Use:

```cpp
auto value = q.front();
q.pop();
```

---

## Q9. What is the difference between `front()` and `back()`?

```text
front() -> first element
back()  -> last element
```

---

## Q10. Does queue support random access?

No.

There is no:

```cpp
q[index]
```

---

## Q11. Does queue provide iterators?

No.

---

## Q12. What is the complexity of `push()`?

For the default `deque` implementation:

```text
O(1) amortized
```

---

## Q13. What is the complexity of `pop()`?

```text
O(1)
```

for the normal queue/deque model.

---

## Q14. What is the complexity of `front()`?

```text
O(1)
```

---

## Q15. What is the complexity of `back()`?

```text
O(1)
```

---

## Q16. What happens when `front()` is called on an empty queue?

The behavior is undefined.

Therefore check:

```cpp
if (!q.empty())
```

before accessing it.

---

## Q17. What happens when `pop()` is called on an empty queue?

The behavior is undefined.

Always check:

```cpp
if (!q.empty())
```

---

## Q18. What is a container adapter?

A container adapter provides a restricted interface over an underlying container.

Examples:

```text
stack
queue
priority_queue
```

---

## Q19. Can a queue store custom objects?

Yes.

```cpp
queue<Student> q;
```

---

## Q20. Can a queue store pairs?

Yes.

```cpp
queue<pair<int, int>> q;
```

---

## Q21. Can a queue store vectors?

Yes.

```cpp
queue<vector<int>> q;
```

---

## Q22. What is the difference between queue and deque?

```text
queue -> restricted FIFO interface
deque  -> double-ended sequence container
```

---

## Q23. What is the difference between queue and stack?

```text
queue -> FIFO
stack -> LIFO
```

---

## Q24. What is the main application of queue in graph algorithms?

```text
Breadth First Search (BFS)
```

---

## Q25. Is `std::queue` thread-safe?

No.

Concurrent access requires appropriate synchronization.

---

# 52. Important C++ Version Features

| Feature | Standard |
|---|---|
| `std::queue` | C++98 |
| `push()` | C++98 |
| `pop()` | C++98 |
| `front()` | C++98 |
| `back()` | C++98 |
| `empty()` | C++98 |
| `size()` | C++98 |
| `emplace()` | C++11 |
| Move construction/assignment | C++11 |
| `swap()` | C++98 / standardized container support |
| `constexpr` support for `queue` | C++26 |

### Important

`std::queue` has a relatively small interface by design.

Modern additions do not change its fundamental FIFO behavior.

---

# 53. Quick Reference Table

## Main Functions

| Function | Purpose | Typical Complexity |
|---|---|---:|
| `push()` | Add at back | O(1) amortized |
| `emplace()` | Construct at back | O(1) amortized |
| `pop()` | Remove from front | O(1) |
| `front()` | Access first element | O(1) |
| `back()` | Access last element | O(1) |
| `empty()` | Check empty | O(1) |
| `size()` | Number of elements | O(1) |
| `swap()` | Exchange contents | Typically O(1) |

---

## Access

```cpp
q.front();
q.back();
```

---

## Insert

```cpp
q.push(value);
q.emplace(arguments...);
```

---

## Remove

```cpp
q.pop();
```

---

## Capacity

```cpp
q.empty();
q.size();
```

---

# 54. Advantages

- Simple FIFO behavior.
- Fast insertion at the back.
- Fast removal from the front.
- Constant-time front/back access.
- Useful for scheduling.
- Useful for BFS.
- Useful for buffering.
- Encapsulates the underlying container.
- Prevents accidental random access.
- Provides a clear interface for queue-based algorithms.

---

# 55. Disadvantages

- No random access.
- No iterators.
- No direct search.
- No direct insertion in the middle.
- No direct removal from the back.
- Cannot inspect arbitrary elements through the queue interface.
- Not thread-safe by itself.
- `pop()` does not return the removed value.
- If you need more flexibility, `deque` may be more appropriate.

---

# 56. When to Use `std::queue`

Use `std::queue` when your problem naturally follows:

```text
First In
   ↓
First Out
```

Typical cases:

```text
BFS
Task scheduling
Request processing
Printer jobs
Message buffering
Producer-consumer design
Simulation
Level-order processing
```

---

# 57. When Not to Use `std::queue`

Do not use `std::queue` when you need:

### Random access

Use:

```cpp
vector
deque
```

---

### Access from both ends

Use:

```cpp
deque
```

---

### LIFO behavior

Use:

```cpp
stack
```

---

### Priority-based processing

Use:

```cpp
priority_queue
```

---

### Direct search and ordered lookup

Consider:

```cpp
set
unordered_set
map
unordered_map
```

depending on your requirements.

---

# 58. Final Summary

## Core Concept

```text
std::queue
    ↓
Container Adapter
    ↓
FIFO
    ↓
Insert at Back
    ↓
Remove from Front
```

---

## Most Important Functions

```cpp
push()
emplace()
pop()
front()
back()
empty()
size()
swap()
```

---

## Most Important Rules

```text
1. Queue follows FIFO.

2. Insert at the back.

3. Remove from the front.

4. front() gives the first element.

5. back() gives the last element.

6. pop() removes the front element.

7. pop() does not return the removed element.

8. Check empty() before front(), back(), or pop().

9. Queue has no iterators.

10. Queue has no operator[].

11. Queue has no direct find() or contains().

12. Default underlying container is deque.

13. list can also be used.

14. vector cannot be used as the underlying container.

15. push() is O(1) amortized with the default deque.

16. pop() is O(1).

17. front() and back() are O(1).

18. size() and empty() are O(1).

19. Queue is commonly used in BFS.

20. std::queue itself is not thread-safe.
```

---

# Queue Mental Model

```text
                    std::queue
                        |
                        v
                Container Adapter
                        |
                        v
                 FIFO Principle
                        |
             +----------+----------+
             |                     |
             v                     v
       Insert at Back        Remove at Front
             |                     |
             v                     v
          push()                 pop()
             |                     |
             +----------+----------+
                        |
                        v
                +-------------+
                |  10 20 30   |
                +-------------+
                  ↑         ↑
                front      back
```

---

# Queue vs Stack — Final Memory Trick

```text
QUEUE

First In
   ↓
First Out

10 -> 20 -> 30
↑             ↑
Front         Back
```

```text
STACK

Last In
   ↓
First Out

10 -> 20 -> 30
            ↑
           Top
```

Therefore:

```text
Queue  = FIFO
Stack  = LIFO
```

---

# One-Line Definition

> **`std::queue` is a C++ STL container adapter that provides FIFO behavior by inserting elements at the back and removing elements from the front, using `std::deque` as its default underlying container.**
