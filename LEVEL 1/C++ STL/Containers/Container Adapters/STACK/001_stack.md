# C++ STL `std::stack` — Complete Notes

# Table of Contents

1. Introduction
2. LIFO Principle
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
13. Why `vector` Can Be Used
14. Stack Structure
15. Main Stack Operations
16. `push()`
17. `emplace()`
18. `pop()`
19. `top()`
20. `empty()`
21. `size()`
22. `swap()`
23. `push()` vs `emplace()`
24. `top()` and Reference Behavior
25. `pop()` Behavior
26. Accessing an Empty Stack
27. No Iterators
28. No Random Access
29. No Direct Search
30. Stack with `pair`
31. Stack with Structure
32. Stack of Vectors
33. Stack of Stacks
34. Stack Using `vector`
35. Stack Using `list`
36. Stack of Custom Objects
37. Move Semantics
38. Complexity
39. Iterator and Reference Considerations
40. Stack Traversal
41. Emptying a Stack
42. Preserving the Stack While Traversing
43. Complete Example
44. Parentheses Matching
45. Expression Evaluation
46. DFS Application
47. Backtracking
48. Function Call Stack and Recursion
49. Undo/Redo Concept
50. Browser History Concept
51. Stack vs Queue
52. Stack vs Deque
53. Stack vs Vector
54. Stack vs Priority Queue
55. Common Mistakes
56. Important Interview Questions
57. Important C++ Version Features
58. Quick Reference Table
59. Advantages
60. Disadvantages
61. When to Use `std::stack`
62. When Not to Use `std::stack`
63. Final Summary
64. Stack Mental Model
65. Stack vs Queue — Final Memory Trick
66. One-Line Definition

---

# 1. Introduction

`std::stack` is a **container adapter** provided by the C++ Standard Template Library (STL).

A stack follows the:

```text
LIFO
```

principle.

LIFO means:

> **Last In, First Out**

The last element inserted into the stack is the first element removed.

Example:

```cpp
stack<int> st;

st.push(10);
st.push(20);
st.push(30);
```

Stack:

```text
        Top
         ↓
       +----+
       | 30 |
       +----+
       | 20 |
       +----+
       | 10 |
       +----+
```

When:

```cpp
st.pop();
```

`30` is removed.

Remaining:

```text
20
10
```

---

# 2. LIFO Principle

LIFO means:

```text
Last element inserted
        ↓
First element removed
```

Example:

```cpp
stack<int> st;

st.push(10);
st.push(20);
st.push(30);
```

Conceptually:

```text
Push 10

Top
 ↓
10
```

Then:

```text
Push 20

Top
 ↓
20
10
```

Then:

```text
Push 30

Top
 ↓
30
20
10
```

Now:

```cpp
st.pop();
```

removes:

```text
30
```

Next:

```cpp
st.pop();
```

removes:

```text
20
```

Therefore removal order is:

```text
30 20 10
```

---

# 3. Real-World Examples

Stacks appear naturally whenever the most recently added item must be handled first.

## 3.1 Function Call Stack

When functions call other functions, the runtime maintains a call stack.

```text
main()
  ↓
functionA()
  ↓
functionB()
```

`functionB()` finishes first.

---

## 3.2 Undo Operation

Editors can store actions:

```text
Type A
Type B
Type C
```

Undo order:

```text
Type C
Type B
Type A
```

---

## 3.3 Browser History

A simplified history model can use stack-like behavior for navigation states.

---

## 3.4 Parentheses Matching

Stacks are commonly used to check:

```text
()
{}
[]
```

and nested expressions.

---

## 3.5 Depth First Search

DFS can be implemented using a stack.

---

## 3.6 Backtracking

Problems such as maze solving and state exploration can use stack-based backtracking.

---

# 4. Header File

Include:

```cpp
#include <stack>
```

Example:

```cpp
#include <iostream>
#include <stack>
```

---

# 5. Namespace

Using:

```cpp
using namespace std;
```

allows:

```cpp
stack<int> st;
```

Without it:

```cpp
std::stack<int> st;
```

For larger projects, explicitly using `std::stack` is often preferable.

---

# 6. Basic Syntax

Syntax:

```cpp
stack<data_type> stack_name;
```

Examples:

```cpp
stack<int> st;
stack<double> values;
stack<string> names;
stack<char> letters;
```

---

# 7. Template Definition

Conceptually:

```cpp
template<
    class T,
    class Container = deque<T>
>
class stack;
```

The important parts are:

```text
T
+
Underlying Container
```

The standard implementation may include additional implementation details, but the public template is based on the stored type and underlying container.

---

# 8. Template Parameters

## 8.1 `T`

`T` specifies the element type stored in the stack.

Examples:

```cpp
stack<int> st;
stack<double> st;
stack<string> st;
```

For:

```cpp
stack<int>
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
stack<int>
```

is conceptually:

```cpp
stack<int, deque<int>>
```

---

# 9. What is a Container Adapter?

`std::stack` is a **container adapter**.

It is not a general-purpose container like:

```cpp
vector
deque
list
```

Instead, it provides a restricted stack interface over another container.

Conceptually:

```text
              std::stack
                  |
                  v
        Underlying Container
                  |
        +---------+---------+
        |                   |
    push_back()         pop_back()
        |                   |
        +---------+---------+
                  |
                 LIFO
```

The stack intentionally exposes only operations needed for stack behavior.

---

# 10. Internal Working

By default:

```cpp
stack<int> st;
```

uses:

```cpp
deque<int>
```

internally.

Conceptually:

```text
stack<int>
    |
    v
deque<int>
```

When:

```cpp
st.push(10);
```

the adapter inserts at the back of the underlying container.

Conceptually:

```cpp
c.push_back(10);
```

When:

```cpp
st.pop();
```

it removes from the back:

```cpp
c.pop_back();
```

Therefore:

```text
push() -> back
pop()  -> back
top()  -> back
```

The back of the underlying container represents the **top of the stack**.

---

# 11. Default Underlying Container

The default underlying container is:

```cpp
std::deque<T>
```

Example:

```cpp
stack<int> st;
```

is conceptually equivalent to:

```cpp
stack<int, deque<int>> st;
```

The `deque` provides efficient operations at its back, making it suitable for stack behavior.

---

# 12. Supported Underlying Containers

The underlying container must support the operations required by `std::stack`.

Common standard choices are:

```cpp
deque
vector
list
```

Examples:

```cpp
stack<int> st;                 // deque
stack<int, vector<int>> st;    // vector
stack<int, list<int>> st;      // list
```

The required operations are essentially:

```cpp
back()
push_back()
pop_back()
empty()
size()
```

Therefore any suitable container providing the required interface can be used.

---

# 13. Why `vector` Can Be Used

Unlike `std::queue`, `std::stack` **can use `std::vector`**.

Example:

```cpp
stack<int, vector<int>> st;
```

Why?

Because stack operations occur at one end:

```text
push -> back
pop  -> back
top  -> back
```

`vector` provides efficient operations at its back:

```cpp
push_back()
pop_back()
back()
```

Therefore `vector` is a valid underlying container.

---

# 14. Stack Structure

Consider:

```cpp
stack<int> st;

st.push(10);
st.push(20);
st.push(30);
st.push(40);
```

Conceptually:

```text
        Top
         ↓
      +----+
      | 40 |
      +----+
      | 30 |
      +----+
      | 20 |
      +----+
      | 10 |
      +----+
```

Operations:

```text
pop()
 ↓
40 removed

push(50)
 ↓
50 becomes new top
```

After both operations:

```text
        Top
         ↓
      +----+
      | 50 |
      +----+
      | 30 |
      +----+
      | 20 |
      +----+
      | 10 |
      +----+
```

---

# 15. Main Stack Operations

The most important `std::stack` functions are:

```cpp
push()
emplace()
pop()
top()
empty()
size()
swap()
```

Remember:

```text
push()    -> insert at top
emplace() -> construct at top
pop()     -> remove top
top()     -> access top
empty()   -> check whether empty
size()    -> number of elements
swap()    -> exchange contents
```

---

# 16. `push()`

Adds an element to the top of the stack.

Example:

```cpp
stack<int> st;

st.push(10);
st.push(20);
st.push(30);
```

Stack:

```text
Top
 ↓
30
20
10
```

The last inserted element is now at the top.

---

## `push()` with String

```cpp
stack<string> st;

st.push("Amit");
st.push("Rahul");
st.push("Deep");
```

Top:

```text
Deep
```

Removal order:

```text
Deep
Rahul
Amit
```

---

# 17. `emplace()`

`emplace()` constructs an object directly at the top of the stack.

Example:

```cpp
stack<string> st;

st.emplace("Amit");
st.emplace("Rahul");
```

This is especially useful for custom objects.

---

## Example with Custom Structure

```cpp
struct Student {

    int id;
    string name;

    Student(int id, string name)
        : id(id), name(name) {}
};

stack<Student> st;

st.emplace(101, "Amit");
st.emplace(102, "Rahul");
```

The `Student` object is constructed directly at the destination.

---

# 18. `pop()`

Removes the top element.

Example:

```cpp
stack<int> st;

st.push(10);
st.push(20);
st.push(30);

st.pop();
```

Before:

```text
30
20
10
```

After:

```text
20
10
```

---

# Important: `pop()` Does Not Return the Element

This is wrong:

```cpp
int x = st.pop();
```

`pop()` returns:

```text
void
```

Correct:

```cpp
int x = st.top();
st.pop();
```

---

# 19. `top()`

Returns a reference to the top element.

Example:

```cpp
stack<int> st;

st.push(10);
st.push(20);
st.push(30);

cout << st.top();
```

Output:

```text
30
```

---

## Modify the Top Element

Because `top()` can return a reference:

```cpp
st.top() = 100;
```

Now:

```text
Top = 100
```

This modifies the element currently at the top.

---

# 20. `empty()`

Checks whether the stack contains no elements.

```cpp
if (st.empty()) {
    cout << "Stack is empty";
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

# 21. `size()`

Returns the number of elements.

Example:

```cpp
stack<int> st;

st.push(10);
st.push(20);
st.push(30);

cout << st.size();
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

# 22. `swap()`

Swaps the contents of two stacks.

Example:

```cpp
stack<int> st1;

st1.push(10);
st1.push(20);

stack<int> st2;

st2.push(100);
st2.push(200);

st1.swap(st2);
```

After:

```text
st1:
200
100

st2:
20
10
```

You can also use:

```cpp
swap(st1, st2);
```

---

# 23. `push()` vs `emplace()`

## `push()`

You provide an object/value:

```cpp
Student s{101, "Amit"};

st.push(s);
```

or:

```cpp
st.push(Student{101, "Amit"});
```

---

## `emplace()`

You provide constructor arguments:

```cpp
st.emplace(101, "Amit");
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

For simple types such as `int`, the practical difference is usually not important.

---

# 24. `top()` and Reference Behavior

`top()` provides access to the top element.

For a non-const stack:

```cpp
T& top();
```

For a const stack:

```cpp
const T& top() const;
```

Therefore:

```cpp
st.top() = 100;
```

is allowed for a non-const stack when `T` is assignable.

Example:

```cpp
stack<int> st;

st.push(10);

st.top() = 50;
```

Now the top is:

```text
50
```

---

# 25. `pop()` Behavior

`pop()`:

```cpp
st.pop();
```

removes only the top element.

It does not:

- Return the removed element.
- Remove the bottom element.
- Return a value.

Correct pattern:

```cpp
if (!st.empty()) {

    int value = st.top();

    st.pop();
}
```

---

# 26. Accessing an Empty Stack

Do not call:

```cpp
st.top();
```

when the stack is empty.

Also do not call:

```cpp
st.pop();
```

on an empty stack.

Always check:

```cpp
if (!st.empty()) {
    cout << st.top();
}
```

or:

```cpp
while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
}
```

Calling `top()` or `pop()` on an empty stack results in undefined behavior.

---

# 27. No Iterators

`std::stack` does not expose:

```cpp
begin()
end()
rbegin()
rend()
```

Therefore:

```cpp
st.begin();
```

is invalid.

The adapter intentionally hides the underlying container's iterator interface.

If you need iterator-based traversal, use the underlying container directly, such as:

```cpp
vector
deque
list
```

depending on your requirements.

---

# 28. No Random Access

You cannot write:

```cpp
st[0];
st[1];
st[2];
```

There is no:

```cpp
operator[]
```

You can access only:

```cpp
top()
```

through the stack interface.

---

# 29. No Direct Search

There is no:

```cpp
st.find(20);
```

and no:

```cpp
st.contains(20);
```

as `std::stack` member functions.

If arbitrary search is a requirement, `std::stack` is generally not the correct abstraction.

---

# 30. Stack with `pair`

You can store pairs:

```cpp
stack<pair<int, int>> st;
```

Example:

```cpp
st.push({1, 2});
st.push({3, 4});
```

Top pair:

```text
(3, 4)
```

Access:

```cpp
cout << st.top().first << " ";
cout << st.top().second;
```

Output:

```text
3 4
```

---

# 31. Stack with Structure

Example:

```cpp
struct Student {

    int id;
    string name;
};

stack<Student> st;

st.push({1, "Rahul"});
st.push({2, "Amit"});
```

Access:

```cpp
cout << st.top().id;
cout << st.top().name;
```

The most recently pushed student is accessed first.

---

# 32. Stack of Vectors

A stack can store vectors:

```cpp
stack<vector<int>> st;
```

Example:

```cpp
st.push({1, 2, 3});
st.push({4, 5, 6});
```

Access:

```cpp
cout << st.top()[0];
```

Output:

```text
4
```

The vector itself can still provide its own indexing:

```cpp
st.top()[0]
```

but the **stack** itself does not support indexing.

---

# 33. Stack of Stacks

You can create:

```cpp
stack<stack<int>> st;
```

Example:

```cpp
stack<int> s1;

s1.push(10);
s1.push(20);

stack<int> s2;

s2.push(30);
s2.push(40);

stack<stack<int>> mainStack;

mainStack.push(s1);
mainStack.push(s2);
```

The top element of `mainStack` is itself a stack.

---

# 34. Stack Using `vector`

`vector` is a valid underlying container.

```cpp
stack<int, vector<int>> st;
```

Example:

```cpp
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

    stack<int, vector<int>> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top();

    return 0;
}
```

Output:

```text
30
```

### Why is `vector` suitable?

Stack requires:

```text
back()
push_back()
pop_back()
```

`vector` provides all of these.

---

# 35. Stack Using `list`

You can also use:

```cpp
stack<int, list<int>> st;
```

Example:

```cpp
#include <iostream>
#include <stack>
#include <list>

using namespace std;

int main() {

    stack<int, list<int>> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top();

    return 0;
}
```

Output:

```text
30
```

---

# 36. Stack of Custom Objects

Example:

```cpp
class Employee {

public:

    int id;
    string name;

    Employee(int id, string name)
        : id(id), name(name) {}
};

stack<Employee> employees;

employees.emplace(101, "Amit");
employees.emplace(102, "Rahul");
```

Access:

```cpp
cout << employees.top().id;
cout << employees.top().name;
```

Output:

```text
102
Rahul
```

---

# 37. Move Semantics

A stack supports move construction and move assignment.

Example:

```cpp
stack<int> st1;

st1.push(10);
st1.push(20);

stack<int> st2(std::move(st1));
```

The contents can be transferred from `st1` to `st2`.

After the move:

```text
st1 -> valid but unspecified state
st2 -> contains transferred contents
```

Include:

```cpp
#include <utility>
```

for:

```cpp
std::move()
```

---

# 38. Complexity

For the default underlying container `deque`, the primary stack operations are constant time.

| Operation | Typical Complexity |
|---|---:|
| `push()` | O(1) amortized |
| `emplace()` | O(1) amortized |
| `pop()` | O(1) |
| `top()` | O(1) |
| `empty()` | O(1) |
| `size()` | O(1) |
| `swap()` | Typically O(1) |

### Important

Remember:

```text
push()    -> O(1) amortized
pop()     -> O(1)
top()     -> O(1)
empty()   -> O(1)
size()    -> O(1)
```

If `vector` is used as the underlying container, `push()` is also amortized O(1), while individual reallocation events can take O(n).

---

# 39. Iterator and Reference Considerations

`std::stack` itself does not expose iterators.

References returned by:

```cpp
top()
```

refer to the current top element.

Example:

```cpp
auto& x = st.top();
```

If that top element is subsequently removed:

```cpp
st.pop();
```

then `x` refers to an object that no longer exists and must not be used.

General rule:

> Do not keep references or pointers to stack elements across operations that may remove or invalidate those elements unless the relevant underlying-container guarantees have been verified.

---

# 40. Stack Traversal

There is no iterator-based traversal through `std::stack`.

The standard way to process all elements is:

```cpp
while (!st.empty()) {

    cout << st.top() << " ";

    st.pop();
}
```

Example:

```cpp
stack<int> st;

st.push(10);
st.push(20);
st.push(30);

while (!st.empty()) {

    cout << st.top() << " ";

    st.pop();
}
```

Output:

```text
30 20 10
```

### Important

This traversal **destroys the stack**.

After the loop:

```cpp
st.empty()
```

is:

```text
true
```

---

# 41. Emptying a Stack

To remove all elements:

```cpp
while (!st.empty()) {
    st.pop();
}
```

After the loop:

```cpp
st.empty()
```

returns:

```text
true
```

---

# 42. Preserving the Stack While Traversing

If you want to inspect the stack without destroying the original, make a copy:

```cpp
stack<int> copy = st;

while (!copy.empty()) {

    cout << copy.top() << " ";

    copy.pop();
}
```

The original:

```cpp
st
```

remains unchanged.

This is useful when you need to inspect all stack elements but still need the original stack later.

---

# 43. Complete Example

```cpp
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Top : "
         << st.top()
         << endl;

    cout << "Size : "
         << st.size()
         << endl;

    cout << "Elements : ";

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;

    cout << "Empty : "
         << boolalpha
         << st.empty();

    return 0;
}
```

Output:

```text
Top : 40
Size : 4
Elements : 40 30 20 10
Empty : true
```

---

# 44. Parentheses Matching

A stack is commonly used to check whether parentheses are balanced.

Example:

```text
{ [ ( ) ] }
```

Basic idea:

```text
Opening bracket
      ↓
    push

Closing bracket
      ↓
 compare with top
      ↓
    pop
```

Example:

```cpp
stack<char> st;

string s = "{[()]}";

for (char c : s)
{
    if (c == '(' ||
        c == '[' ||
        c == '{')
    {
        st.push(c);
    }
    else if (c == ')' ||
             c == ']' ||
             c == '}')
    {
        if (st.empty())
        {
            cout << "Invalid";
            return 0;
        }

        st.pop();
    }
}
```

A complete matching algorithm should also verify that the closing bracket matches the correct opening bracket and that the stack is empty at the end.

---

# 45. Expression Evaluation

Stacks are used in expression processing.

Examples:

```text
Infix:
A + B

Postfix:
A B +

Prefix:
+ A B
```

Stacks are commonly used for:

```text
Postfix evaluation
Infix-to-postfix conversion
Infix-to-prefix conversion
Expression parsing
```

For example, postfix:

```text
2 3 +
```

can be evaluated using:

```text
push 2
push 3
pop 3
pop 2
calculate 2 + 3
push 5
```

Result:

```text
5
```

---

# 46. DFS Application

A stack can be used to implement:

```text
Depth First Search
```

Example:

```text
        1
       / \
      2   3
     / \
    4   5
```

A simplified iterative DFS can use:

```cpp
stack<int> st;

st.push(start);

while (!st.empty())
{
    int node = st.top();
    st.pop();

    // Process node

    // Push unvisited neighbors
}
```

Because the most recently pushed node is processed first, the search naturally follows depth-oriented behavior.

---

# 47. Backtracking

Stack behavior is useful when solving problems that require:

```text
Make a choice
    ↓
Explore
    ↓
If unsuccessful
    ↓
Undo last choice
```

Examples:

```text
Maze solving
N-Queens
Path finding
Combinatorial search
Puzzle solving
```

The most recent decision is undone first, which naturally matches LIFO behavior.

---

# 48. Function Call Stack and Recursion

When a function calls another function, the runtime maintains a call stack.

Example:

```cpp
void A()
{
    B();
}

void B()
{
    C();
}

void C()
{
}
```

Conceptually:

```text
A()
 ↓
B()
 ↓
C()
```

When `C()` finishes:

```text
C removed
```

Then:

```text
B continues
```

Then:

```text
B removed
```

Then:

```text
A continues
```

This follows LIFO-like behavior.

### Important

The C++ runtime's actual call stack is not implemented by `std::stack`. `std::stack` is an STL container adapter, while the language/runtime manages function-call stack behavior separately.

---

# 49. Undo/Redo Concept

A simple undo system can use a stack.

Suppose:

```text
Action A
Action B
Action C
```

Undo:

```text
Undo C
Undo B
Undo A
```

Conceptually:

```cpp
stack<string> actions;

actions.push("Action A");
actions.push("Action B");
actions.push("Action C");

cout << "Undo: " << actions.top();
actions.pop();
```

Output:

```text
Undo: Action C
```

A real undo/redo system commonly uses **two stacks**:

```text
Undo Stack
    ↓
Redo Stack
```

---

# 50. Browser History Concept

A simplified browser-history model can use stack-like structures.

For example:

```text
Page A
Page B
Page C
```

Going backward can conceptually remove:

```text
Page C
```

then:

```text
Page B
```

A real browser history system is more sophisticated and may support forward/back navigation using multiple states or stacks.

---

# 51. Stack vs Queue

| Feature | Stack | Queue |
|---|---|---|
| Principle | LIFO | FIFO |
| Insert | Top | Back |
| Remove | Top | Front |
| Insert function | `push()` | `push()` |
| Remove function | `pop()` | `pop()` |
| Access | `top()` | `front()`, `back()` |
| Iterators | No | No |
| Random access | No | No |
| Typical use | DFS, undo | BFS, scheduling |

Example:

### Stack

```text
Push:
10
20
30

Pop:
30
20
10
```

### Queue

```text
Push:
10
20
30

Pop:
10
20
30
```

---

# 52. Stack vs Deque

| Feature | Stack | Deque |
|---|---|---|
| Type | Container adapter | Container |
| Insert front | No | Yes |
| Insert back | Yes through `push()` | Yes |
| Remove front | No | Yes |
| Remove back | Yes through `pop()` | Yes |
| Top | `top()` | `back()` can represent top |
| Iterators | No | Yes |
| Random access | No | Yes |
| Interface | Restricted | Flexible |

Use `stack` when you specifically want LIFO behavior.

Use `deque` when you need flexible operations at both ends or random access.

---

# 53. Stack vs Vector

| Feature | Stack | Vector |
|---|---|---|
| Main model | LIFO | Dynamic array |
| Top access | `top()` | `back()` |
| Random access | No | Yes |
| `operator[]` | No | Yes |
| Iterators | No | Yes |
| `push_back()` | Hidden behind `push()` | Yes |
| `pop_back()` | Hidden behind `pop()` | Yes |
| Flexibility | Restricted | Flexible |

Example:

```cpp
stack<int> st;
```

is preferable when you want to enforce LIFO behavior.

Example:

```cpp
vector<int> v;
```

is preferable when you need:

```cpp
v[5]
```

or iterator-based traversal.

---

# 54. Stack vs Priority Queue

| Feature | Stack | Priority Queue |
|---|---|---|
| Ordering | LIFO | Priority |
| Access | `top()` | `top()` |
| Insert | `push()` | `push()` |
| Remove | `pop()` | `pop()` |
| First removed | Most recently inserted | Highest/lowest priority |
| Main use | LIFO processing | Priority-based processing |

---

# 55. Common Mistakes

## Mistake 1: Accessing an Empty Stack

Wrong:

```cpp
cout << st.top();
```

when:

```cpp
st.empty() == true
```

Correct:

```cpp
if (!st.empty())
{
    cout << st.top();
}
```

---

## Mistake 2: Calling `pop()` on an Empty Stack

Wrong:

```cpp
st.pop();
```

without checking.

Correct:

```cpp
if (!st.empty())
{
    st.pop();
}
```

---

## Mistake 3: Assuming `pop()` Returns the Value

Wrong:

```cpp
int x = st.pop();
```

Correct:

```cpp
int x = st.top();
st.pop();
```

---

## Mistake 4: Trying to Use Iterators

Wrong:

```cpp
st.begin();
```

`std::stack` does not provide iterators.

---

## Mistake 5: Trying Random Access

Wrong:

```cpp
cout << st[2];
```

A stack does not provide indexing.

---

## Mistake 6: Assuming the Stack Uses `vector` by Default

Wrong assumption:

```text
stack -> vector
```

Correct:

```text
stack -> deque by default
```

You can explicitly choose:

```cpp
stack<int, vector<int>> st;
```

---

## Mistake 7: Assuming `std::stack` Is the Runtime Call Stack

`std::stack` is an STL container adapter.

The runtime's function call stack is a separate mechanism.

---

## Mistake 8: Traversing Without Realizing the Stack Is Destroyed

This:

```cpp
while (!st.empty())
{
    cout << st.top();
    st.pop();
}
```

processes all elements but leaves the stack empty.

If you need to preserve it:

```cpp
auto copy = st;

while (!copy.empty())
{
    cout << copy.top() << " ";
    copy.pop();
}
```

---

# 56. Important Interview Questions

## Q1. What is `std::stack`?

`std::stack` is a C++ STL **container adapter** that provides LIFO behavior.

---

## Q2. What does LIFO mean?

```text
Last In
First Out
```

The last inserted element is the first removed.

---

## Q3. Where are elements inserted?

At the:

```text
top
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
top
```

using:

```cpp
pop()
```

---

## Q5. Which container does stack use by default?

```cpp
std::deque<T>
```

---

## Q6. Can `vector` be used as the underlying container?

Yes.

```cpp
stack<int, vector<int>> st;
```

---

## Q7. Can `list` be used?

Yes.

```cpp
stack<int, list<int>> st;
```

---

## Q8. Does `pop()` return the removed element?

No.

It returns `void`.

Use:

```cpp
auto value = st.top();
st.pop();
```

---

## Q9. What is the difference between `top()` and `pop()`?

```text
top() -> access top element
pop() -> remove top element
```

---

## Q10. Does stack support random access?

No.

There is no:

```cpp
st[index]
```

---

## Q11. Does stack provide iterators?

No.

---

## Q12. What is the complexity of `push()`?

With the default `deque`:

```text
O(1) amortized
```

---

## Q13. What is the complexity of `pop()`?

```text
O(1)
```

---

## Q14. What is the complexity of `top()`?

```text
O(1)
```

---

## Q15. What happens when `top()` is called on an empty stack?

The behavior is undefined.

Check:

```cpp
if (!st.empty())
```

first.

---

## Q16. What happens when `pop()` is called on an empty stack?

The behavior is undefined.

Check:

```cpp
if (!st.empty())
```

first.

---

## Q17. What is a container adapter?

A container adapter provides a restricted interface over another container.

Examples:

```text
stack
queue
priority_queue
```

---

## Q18. Can a stack store custom objects?

Yes.

```cpp
stack<Student> st;
```

---

## Q19. Can a stack store pairs?

Yes.

```cpp
stack<pair<int, int>> st;
```

---

## Q20. Can a stack store vectors?

Yes.

```cpp
stack<vector<int>> st;
```

---

## Q21. What is the difference between stack and queue?

```text
stack -> LIFO
queue -> FIFO
```

---

## Q22. What is the main graph application of stack?

```text
Depth First Search (DFS)
```

---

## Q23. What is the difference between stack and deque?

```text
stack -> restricted LIFO adapter
deque  -> flexible double-ended container
```

---

## Q24. Is `std::stack` thread-safe?

No.

Concurrent access to the same stack requires appropriate synchronization.

---

# 57. Important C++ Version Features

| Feature | Standard |
|---|---|
| `std::stack` | C++98 |
| `push()` | C++98 |
| `pop()` | C++98 |
| `top()` | C++98 |
| `empty()` | C++98 |
| `size()` | C++98 |
| `swap()` | C++98 |
| `emplace()` | C++11 |
| Move construction/assignment | C++11 |
| `constexpr` support for `stack` | C++26 |

### Important

The basic stack interface has remained intentionally small because its purpose is to enforce LIFO access.

---

# 58. Quick Reference Table

## Main Functions

| Function | Purpose | Typical Complexity |
|---|---|---:|
| `push()` | Add at top | O(1) amortized |
| `emplace()` | Construct at top | O(1) amortized |
| `pop()` | Remove top | O(1) |
| `top()` | Access top | O(1) |
| `empty()` | Check empty | O(1) |
| `size()` | Number of elements | O(1) |
| `swap()` | Exchange contents | Typically O(1) |

---

## Insert

```cpp
st.push(value);
st.emplace(arguments...);
```

---

## Access

```cpp
st.top();
```

---

## Remove

```cpp
st.pop();
```

---

## Capacity

```cpp
st.empty();
st.size();
```

---

# 59. Advantages

- Simple LIFO behavior.
- Fast insertion.
- Fast removal.
- Constant-time top access.
- Useful for DFS.
- Useful for recursion-related algorithms.
- Useful for backtracking.
- Useful for expression evaluation.
- Useful for parentheses matching.
- Useful for undo/redo concepts.
- Encapsulates the underlying container.
- Prevents accidental random access.

---

# 60. Disadvantages

- No random access.
- No iterators.
- No direct search.
- No access to arbitrary elements.
- Only the top element is directly accessible.
- Cannot insert or remove from the middle through the adapter interface.
- Not thread-safe by itself.
- `pop()` does not return the removed value.
- If you need flexible access, `deque` or `vector` may be more appropriate.

---

# 61. When to Use `std::stack`

Use `std::stack` when your problem naturally follows:

```text
Last In
   ↓
First Out
```

Typical applications:

```text
DFS
Backtracking
Parentheses matching
Expression evaluation
Undo operations
Parsing
State exploration
Algorithmic state management
```

---

# 62. When Not to Use `std::stack`

Do not use `std::stack` when you need:

### FIFO behavior

Use:

```cpp
queue
```

---

### Access from both ends

Use:

```cpp
deque
```

---

### Random access

Use:

```cpp
vector
deque
```

---

### Priority-based processing

Use:

```cpp
priority_queue
```

---

### Direct ordered/search operations

Consider:

```cpp
set
unordered_set
map
unordered_map
```

depending on the problem.

---

# 63. Final Summary

## Core Concept

```text
std::stack
    ↓
Container Adapter
    ↓
LIFO
    ↓
Insert at Top
    ↓
Remove from Top
```

---

## Most Important Functions

```cpp
push()
emplace()
pop()
top()
empty()
size()
swap()
```

---

## Most Important Rules

```text
1. Stack follows LIFO.

2. Insert at the top.

3. Remove from the top.

4. top() gives the top element.

5. pop() removes the top element.

6. pop() does not return the removed element.

7. Check empty() before top() or pop().

8. Stack has no iterators.

9. Stack has no operator[].

10. Stack has no direct find() or contains().

11. Default underlying container is deque.

12. vector can be used as the underlying container.

13. list can also be used.

14. push() is O(1) amortized with the default deque.

15. pop() is O(1).

16. top() is O(1).

17. size() and empty() are O(1).

18. Stack is commonly used in DFS.

19. Stack is useful for backtracking.

20. std::stack itself is not thread-safe.
```

---

# 64. Stack Mental Model

```text
                    std::stack
                        |
                        v
                Container Adapter
                        |
                        v
                  LIFO Principle
                        |
             +----------+----------+
             |                     |
             v                     v
          Push                    Pop
             |                     |
             v                     v
       Insert at Top         Remove from Top
             |                     |
             +----------+----------+
                        |
                        v
                      Top
                       ↓
                   +-------+
                   |  40   |
                   +-------+
                   |  30   |
                   +-------+
                   |  20   |
                   +-------+
                   |  10   |
                   +-------+
```

---

# 65. Stack vs Queue — Final Memory Trick

## STACK

```text
Last In
   ↓
First Out

Push:

10
20
30  ← Top

Pop order:

30
20
10
```

Therefore:

```text
Stack = LIFO
```

---

## QUEUE

```text
First In
   ↓
First Out

Queue:

10 20 30
↑       ↑
Front   Back

Pop order:

10
20
30
```

Therefore:

```text
Queue = FIFO
```

---

# 66. One-Line Definition

> **`std::stack` is a C++ STL container adapter that provides LIFO behavior by inserting, accessing, and removing elements from the top, using `std::deque` as its default underlying container.**
