# C++ `std::move()` — Complete Notes

> **Important:** `std::move()` does not itself move an object or transfer resources. It is a cast that allows an expression to be treated as an rvalue/xvalue so that move constructors, move assignment operators, and other rvalue overloads can be selected.

---

# Table of Contents

1. Introduction
2. What Is `std::move()`?
3. Header File
4. Basic Syntax
5. Why Do We Need Move Semantics?
6. Copy vs Move
7. What `std::move()` Actually Does
8. `std::move()` Is a Cast
9. Lvalues and Rvalues
10. xvalue
11. Move Constructor
12. Move Assignment Operator
13. Move Constructor vs Move Assignment
14. Complete Move Example
15. Implementing a Move Constructor
16. Implementing Move Assignment
17. Rule of Five
18. Rule of Three
19. Rule of Zero
20. Moved-From Objects
21. Is a Moved-From Object Empty?
22. Valid but Unspecified State
23. Using a Moved-From Object
24. Move vs Copy for `vector`
25. Move vs Copy for `string`
26. Move vs Copy for `pair`
27. Move vs Copy for Containers
28. Move and Dynamic Memory
29. Move and Ownership
30. Move and `unique_ptr`
31. Move and `shared_ptr`
32. Move and `const`
33. Why `std::move(const T&)` Often Does Not Move
34. Move in Function Calls
35. Passing by Value
36. Passing by Reference
37. Rvalue Reference Parameters
38. Returning Objects
39. `std::move` and Return Statements
40. Don't Use `std::move` on Local Return Values Unnecessarily
41. `std::move` and `noexcept`
42. Why Move Constructors Should Often Be `noexcept`
43. Vector Reallocation and Move
44. `std::move_if_noexcept`
45. Move Assignment with Existing Resources
46. Self Move-Assignment
47. Move-Only Types
48. Copyable + Movable Types
49. Deleted Copy Operations
50. Explicitly Defaulted Move Operations
51. Destructor and Move Semantics
52. Resource Ownership Example
53. Custom Class Example
54. Move Constructor Step-by-Step
55. Move Assignment Step-by-Step
56. Deep Copy vs Move
57. Shallow Copy vs Move
58. `std::move` with Arrays
59. `std::move` with Function Arguments
60. `std::move` and Overload Resolution
61. Overload Example
62. `std::move` Does Not Guarantee a Move
63. `std::move` vs Perfect Forwarding
64. `std::move` vs `std::forward`
65. `std::move` vs Copy
66. Common Mistakes
67. Mistake: Thinking `std::move` Performs the Move
68. Mistake: Using `std::move` on `const`
69. Mistake: Using Moved-From Object Incorrectly
70. Mistake: Moving Twice
71. Mistake: Moving an Object You Still Need
72. Mistake: Unnecessary `std::move` in Return
73. Mistake: Forgetting `std::move` for Move-Only Objects
74. Mistake: Writing a Move Constructor Incorrectly
75. Mistake: Not Handling Existing Resources in Move Assignment
76. Performance
77. Complexity
78. Memory Behavior
79. Complete Program 1
80. Complete Program 2
81. Complete Program 3
82. Complete Program 4
83. Complete Program 5
84. Move Semantics Flow
85. Quick Comparison Tables
86. Interview Questions
87. Best Practices
88. Final Summary

---

# 1. Introduction

**Move semantics** was introduced in **C++11**.

It allows objects to transfer ownership of resources instead of making expensive copies.

The main utility used to explicitly enable moving is:

```cpp
std::move()
```

Header:

```cpp
#include <utility>
```

Typical example:

```cpp
std::vector<int> a = {1, 2, 3};

std::vector<int> b = std::move(a);
```

The important idea is:

```text
Copy:
    create new resources + copy data

Move:
    transfer/reuse existing resources when the type supports it
```

---

# 2. What Is `std::move()`?

`std::move()` is a utility introduced with C++11.

It converts an expression into an **xvalue** (an expiring value), allowing overload resolution to select operations that accept rvalue references.

Example:

```cpp
std::string s1 = "Hello";

std::string s2 = std::move(s1);
```

If `std::string` has a suitable move constructor, it can transfer its internal resources instead of copying the characters.

---

# 3. Header File

Use:

```cpp
#include <utility>
```

Example:

```cpp
#include <iostream>
#include <string>
#include <utility>

int main()
{
    std::string s1 = "Hello";

    std::string s2 = std::move(s1);
}
```

---

# 4. Basic Syntax

```cpp
std::move(object);
```

Example:

```cpp
std::vector<int> b =
    std::move(a);
```

Using namespace:

```cpp
using namespace std;

vector<int> b = move(a);
```

Preferred in reusable/library code:

```cpp
std::move(a)
```

---

# 5. Why Do We Need Move Semantics?

Consider:

```cpp
std::vector<int> a = {
    1, 2, 3, 4, 5
};
```

Copy:

```cpp
std::vector<int> b = a;
```

Conceptually:

```text
a → [1 2 3 4 5]
        ↓ copy
b → [1 2 3 4 5]
```

A new vector allocation may be required and the elements are copied.

Now:

```cpp
std::vector<int> b =
    std::move(a);
```

Conceptually, the destination can take over the source's dynamically allocated storage:

```text
Before:

a → [1 2 3 4 5]
b → empty

After:

a → moved-from state
b → [1 2 3 4 5]
```

The exact representation is implementation-dependent, but the move can avoid element-by-element copying.

---

# 6. Copy vs Move

## Copy

```cpp
std::vector<int> b = a;
```

Conceptually:

```text
Allocate new memory
        ↓
Copy elements
        ↓
b owns independent resources
```

---

## Move

```cpp
std::vector<int> b = std::move(a);
```

Conceptually:

```text
Take/reuse transferable resources
        ↓
Leave a valid moved-from object
        ↓
b owns the resources
```

---

# 7. What `std::move()` Actually Does

This is the most important fact:

> **`std::move()` itself does not move anything.**

It performs a cast.

Conceptually:

```cpp
std::move(x)
```

means:

```text
Treat x as an expiring/rvalue expression.
```

Then overload resolution can select:

```cpp
T(T&&)
```

or:

```cpp
T& operator=(T&&)
```

if available.

The actual resource transfer happens inside the selected move operation.

---

# 8. `std::move()` Is a Cast

Conceptually:

```cpp
std::move(x)
```

performs something equivalent to:

```cpp
static_cast<std::remove_reference_t<decltype(x)>&&>(x)
```

The standard specification is more precise, but this is a useful mental model.

For:

```cpp
std::string s;
```

this:

```cpp
std::move(s)
```

creates an xvalue expression referring to `s`.

It does not create another object.

It does not allocate memory.

It does not immediately transfer resources.

---

# 9. Lvalues and Rvalues

Move semantics relies heavily on value categories.

## Lvalue

An expression that identifies an object with identity.

Example:

```cpp
std::string s = "Hello";

s
```

is an lvalue.

---

## Rvalue

For practical move-semantics discussions, rvalues include:

```text
prvalues
xvalues
```

Examples:

```cpp
std::string("Hello")
```

and:

```cpp
std::move(s)
```

---

# 10. xvalue

`std::move()` produces an **xvalue**.

The name means roughly:

```text
eXpiring value
```

Example:

```cpp
std::string s = "Hello";

std::move(s);
```

The expression:

```cpp
std::move(s)
```

is an xvalue.

It still refers to the existing object `s`.

It does not create a new object.

---

# 11. Move Constructor

A move constructor is used when creating a **new object** from an rvalue/xvalue of the same type.

Typical signature:

```cpp
ClassName(ClassName&& other);
```

Example:

```cpp
class Test
{
public:

    Test(Test&& other)
    {
        // transfer resources
    }
};
```

Usage:

```cpp
Test a;

Test b(std::move(a));
```

or:

```cpp
Test b = std::move(a);
```

---

# 12. Move Constructor Example

```cpp
std::vector<int> a = {
    1, 2, 3
};

std::vector<int> b(
    std::move(a)
);
```

Because `b` is being created, this is move construction.

---

# 13. Move Assignment Operator

Move assignment is used when the destination object **already exists**.

Typical signature:

```cpp
ClassName& operator=(ClassName&& other);
```

Example:

```cpp
std::vector<int> a = {
    1, 2, 3
};

std::vector<int> b;

b = std::move(a);
```

Here:

```text
b already exists
```

so this is move assignment.

---

# 14. Move Constructor vs Move Assignment

| Feature | Move Constructor | Move Assignment |
|---|---|---|
| Destination | New object | Existing object |
| Syntax | `T b(std::move(a));` | `b = std::move(a);` |
| Function | `T(T&&)` | `T& operator=(T&&)` |
| Existing destination resources | None initially | Must be released/replaced safely |
| Main purpose | Initialize from rvalue | Replace existing object's resources |

---

# 15. Complete Move Example

```cpp
#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Test
{
public:

    Test()
    {
        cout << "Default Constructor\n";
    }

    Test(const Test&)
    {
        cout << "Copy Constructor\n";
    }

    Test(Test&&)
    {
        cout << "Move Constructor\n";
    }

    Test& operator=(const Test&)
    {
        cout << "Copy Assignment\n";
        return *this;
    }

    Test& operator=(Test&&)
    {
        cout << "Move Assignment\n";
        return *this;
    }
};

int main()
{
    Test a;

    Test b = std::move(a);

    Test c;

    c = std::move(b);

    return 0;
}
```

Typical output:

```text
Default Constructor
Move Constructor
Default Constructor
Move Assignment
```

---

# 16. Implementing a Move Constructor

Consider a class that owns dynamic memory:

```cpp
class Buffer
{
    int* data;
    size_t size;

public:

    Buffer(size_t n)
        : data(new int[n]),
          size(n)
    {
    }

    ~Buffer()
    {
        delete[] data;
    }
};
```

A copy would need to allocate another array.

A move can transfer the pointer:

```cpp
Buffer(Buffer&& other) noexcept
    : data(other.data),
      size(other.size)
{
    other.data = nullptr;
    other.size = 0;
}
```

The important steps are:

```text
1. Take resource from other
2. Copy resource handle
3. Reset source
4. Leave source valid
```

---

# 17. Implementing Move Assignment

Move assignment is more complicated because the destination may already own a resource.

Example:

```cpp
Buffer& operator=(Buffer&& other) noexcept
{
    if (this != &other)
    {
        delete[] data;

        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;
    }

    return *this;
}
```

Steps:

```text
1. Check self-assignment
2. Release destination's current resource
3. Take source's resource
4. Reset source
5. Return *this
```

---

# 18. Rule of Five

If a class directly manages a resource, declaring one special member function may require considering all five:

```text
1. Destructor
2. Copy Constructor
3. Copy Assignment
4. Move Constructor
5. Move Assignment
```

Example:

```cpp
class Resource
{
public:

    ~Resource();

    Resource(const Resource&);

    Resource& operator=(const Resource&);

    Resource(Resource&&) noexcept;

    Resource& operator=(Resource&&) noexcept;
};
```

This is called the:

```text
Rule of Five
```

---

# 19. Rule of Three

Before C++11, the common rule was the Rule of Three.

If a class needed one of:

```text
Destructor
Copy Constructor
Copy Assignment
```

it often needed all three.

C++11 added move semantics, extending the rule to five.

---

# 20. Rule of Zero

Modern C++ often recommends avoiding manual resource management.

Instead of:

```cpp
new
delete
```

use RAII types such as:

```cpp
std::vector
std::string
std::unique_ptr
std::shared_ptr
```

Then you often need none of the five special member functions.

This is the:

```text
Rule of Zero
```

Example:

```cpp
class Person
{
    std::string name;
    std::vector<int> values;
};
```

The standard library members already handle copying and moving correctly.

---

# 21. Moved-From Objects

After:

```cpp
std::vector<int> a = {
    1, 2, 3
};

std::vector<int> b =
    std::move(a);
```

`a` is called:

```text
moved-from object
```

The object still exists.

It has not been destroyed.

---

# 22. Is a Moved-From Object Empty?

Not necessarily.

For many standard-library types, the moved-from state is often empty in common implementations.

For example:

```cpp
std::string s = "Hello";

std::string t = std::move(s);
```

`s` is commonly empty afterward.

But you should **not write generic code that assumes every moved-from object is empty**.

The standard generally specifies that moved-from standard-library objects are valid but their value may be unspecified unless a stronger postcondition is documented.

---

# 23. Valid but Unspecified State

The safest general rule is:

> After moving from an object, it remains valid, but its value is generally unspecified unless the type documents a specific post-move state.

You can usually:

```cpp
object.clear();
object = newValue;
object.push_back(...);
```

when the type's API permits these operations.

But do not assume:

```cpp
object == oldValue
```

or:

```cpp
object.empty()
```

unless documented.

---

# 24. Example of Using a Moved-From Vector

```cpp
std::vector<int> a = {
    1, 2, 3
};

std::vector<int> b =
    std::move(a);

a.clear();

a.push_back(10);
```

This is fine because `a` still exists and remains a valid vector.

But:

```cpp
std::cout << a[0];
```

is unsafe if you have not established that `a` contains an element.

---

# 25. Move vs Copy for `vector`

Copy:

```cpp
std::vector<int> a = {
    1, 2, 3
};

std::vector<int> b = a;
```

Conceptually:

```text
a → memory A → [1 2 3]

b → memory B → [1 2 3]
```

Move:

```cpp
std::vector<int> b =
    std::move(a);
```

Conceptually:

```text
Before:
a → memory A → [1 2 3]
b → empty

After:
a → moved-from state
b → memory A → [1 2 3]
```

The exact implementation is library-dependent.

---

# 26. Move vs Copy for `string`

Copy:

```cpp
std::string s1 = "Hello";

std::string s2 = s1;
```

Move:

```cpp
std::string s2 =
    std::move(s1);
```

For a dynamically allocated string representation, moving can transfer the internal buffer instead of copying every character.

However, modern strings may use techniques such as **Small String Optimization (SSO)**, so the actual implementation behavior can differ.

---

# 27. Move vs Copy for `pair`

```cpp
std::pair<int, std::string> p1{
    10,
    "Hello"
};

auto p2 =
    std::move(p1);
```

The pair's move constructor moves its members.

Conceptually:

```text
pair move
   ↓
move first
   +
move second
```

For `int`, moving is effectively the same as copying the integer value.

For `std::string`, moving can transfer resources.

---

# 28. Move vs Copy for Containers

Many STL containers support move construction and move assignment.

Examples:

```cpp
std::vector
std::deque
std::list
std::map
std::set
std::unordered_map
std::unordered_set
std::string
```

Example:

```cpp
std::map<int, std::string> a;

auto b = std::move(a);
```

The container can transfer its internal resources according to its allocator and implementation rules.

---

# 29. Move and Dynamic Memory

Consider:

```cpp
class Buffer
{
    int* data;
};
```

Copying may require:

```text
new memory
+
copy values
```

Moving can often require:

```text
copy pointer
+
reset source pointer
```

Example:

```text
Before:

A.data → [100 200 300]
B.data → null

After:

A.data → null
B.data ─────┐
            ↓
         [100 200 300]
```

This is why move operations can be much cheaper than deep copies.

---

# 30. Move and Ownership

Move semantics is especially useful for objects that own resources.

Examples:

```text
Dynamic memory
File handles
Sockets
Locks
Operating-system handles
Large buffers
Database connections
Other RAII-managed resources
```

The resource should have a clear ownership model.

---

# 31. Move and `unique_ptr`

`std::unique_ptr` is move-only.

Example:

```cpp
std::unique_ptr<int> p1 =
    std::make_unique<int>(10);

std::unique_ptr<int> p2 =
    std::move(p1);
```

After the move:

```text
p1 → nullptr
p2 → owned object
```

This is a case where `std::move` is required because copying a `unique_ptr` is prohibited.

---

# 32. Move and `shared_ptr`

`std::shared_ptr` can be copied or moved.

Copy:

```cpp
auto p2 = p1;
```

This increases shared ownership.

Move:

```cpp
auto p2 = std::move(p1);
```

This transfers the `shared_ptr` handle and typically leaves `p1` empty.

The managed object itself is not necessarily moved.

Important:

> Moving a `shared_ptr` is not the same thing as moving the object it points to.

---

# 33. Move and `const`

Consider:

```cpp
const std::string s =
    "Hello";

std::string t =
    std::move(s);
```

`std::move(s)` produces a `const std::string&&`.

Most move constructors are:

```cpp
std::string(std::string&&)
```

not:

```cpp
std::string(const std::string&&)
```

Therefore the ordinary move constructor generally cannot be selected.

A copy constructor accepting:

```cpp
const std::string&
```

can usually bind instead.

---

# 34. Why `std::move(const T&)` Often Does Not Move

A move operation generally needs permission to modify the source.

For example, moving a string may modify:

```text
source pointer
source size
source ownership
```

A `const` object cannot normally be modified.

Therefore:

```cpp
std::move(constObject)
```

usually does not enable a useful move.

---

# 35. Move in Function Calls

Suppose:

```cpp
void process(std::string&& s)
{
}
```

Then:

```cpp
std::string s = "Hello";

process(std::move(s));
```

allows `s` to bind to the rvalue-reference parameter.

If you write:

```cpp
process(s);
```

it does not bind to:

```cpp
std::string&&
```

because `s` is an lvalue.

---

# 36. Passing by Value

Consider:

```cpp
void process(std::string s)
{
}
```

Call:

```cpp
std::string name = "Alice";

process(std::move(name));
```

The parameter can be initialized using move construction.

This is useful when the function intends to take ownership of its own copy/moved value.

---

# 37. Passing by Reference

If:

```cpp
void process(const std::string& s)
{
}
```

then:

```cpp
process(std::move(name));
```

does not necessarily move anything.

The rvalue can simply bind to the const reference.

This is why:

> `std::move()` does not guarantee a move.

The receiving function determines what happens.

---

# 38. Rvalue Reference Parameters

Example:

```cpp
void process(std::string&& value)
{
    std::string local =
        std::move(value);
}
```

Important:

Inside the function:

```cpp
value
```

is a named variable, so the expression:

```cpp
value
```

is an lvalue.

Therefore, if you want to move from the rvalue-reference parameter again, you often need:

```cpp
std::move(value)
```

---

# 39. Example — Named Rvalue Reference

```cpp
void consume(std::string&& value)
{
    std::string other =
        std::move(value);
}
```

Without `std::move`:

```cpp
std::string other = value;
```

the named parameter `value` is an lvalue expression, so the copy constructor may be selected.

With:

```cpp
std::move(value)
```

the move constructor can be selected.

---

# 40. Returning Objects

Modern C++ has powerful return-value optimization and move support.

Example:

```cpp
std::string create()
{
    return std::string("Hello");
}
```

The compiler can use copy elision.

You normally do not need:

```cpp
return std::move(local);
```

for a local object.

---

# 41. `std::move` and Return Statements

Avoid unnecessary:

```cpp
std::move`
```

in return statements such as:

```cpp
std::string create()
{
    std::string result = "Hello";

    return std::move(result);
}
```

Prefer:

```cpp
std::string create()
{
    std::string result = "Hello";

    return result;
}
```

The language provides special treatment for returning local objects, enabling move construction when appropriate and allowing copy elision.

---

# 42. Why Avoid `return std::move(local)`?

`return std::move(local);`

can interfere with some forms of guaranteed/eligible copy elision.

Therefore:

```cpp
return local;
```

is generally preferred for a local automatic object.

Let the language and compiler optimize the return.

---

# 43. When `std::move` in Return Can Be Appropriate

There are cases where an explicit move can be intentional, such as returning a subobject or an expression whose implicit move rules do not provide the desired result.

But for the common pattern:

```cpp
T func()
{
    T local;

    return local;
}
```

prefer:

```cpp
return local;
```

---

# 44. `std::move` and `noexcept`

Move constructors are often declared:

```cpp
noexcept
```

Example:

```cpp
class Test
{
public:

    Test(Test&& other) noexcept
    {
    }
};
```

Why?

Standard containers may prefer moving elements during reallocation only when the move constructor is known not to throw, or when copying is unavailable.

---

# 45. Why Move Constructors Should Often Be `noexcept`

Consider:

```cpp
std::vector<Test> v;
```

When vector grows, it may need to relocate existing elements.

If moving a `Test` can throw, vector may prefer copying when a safe copy constructor is available to preserve the strong exception guarantee.

If moving is:

```cpp
noexcept
```

the container can safely use the move operation when appropriate.

Therefore:

> If your move constructor truly cannot throw, mark it `noexcept`.

---

# 46. Vector Reallocation and Move

Suppose:

```cpp
std::vector<Test> v;
```

When capacity is exhausted, vector may:

```text
1. Allocate new storage
2. Transfer existing elements
3. Destroy old elements
4. Release old storage
```

For each element it may use:

```text
move constructor
```

or:

```text
copy constructor
```

depending on type properties and exception guarantees.

---

# 47. `std::move_if_noexcept`

C++ provides:

```cpp
std::move_if_noexcept
```

Header:

```cpp
#include <utility>
```

It can return:

```text
T&&
```

when moving is safe, otherwise:

```text
const T&
```

when copying is preferred.

This is useful in generic code concerned with exception guarantees.

---

# 48. `move_if_noexcept` Example

```cpp
template<typename T>
void transfer(T& value)
{
    use(
        std::move_if_noexcept(value)
    );
}
```

Conceptually:

```text
nothrow move
     ↓
move

throwing move + copy available
     ↓
copy-compatible const reference
```

The exact type-trait conditions are defined by the standard.

---

# 49. Move Assignment with Existing Resources

Move assignment must handle the destination's current resources.

Example:

```cpp
Buffer a(100);
Buffer b(200);

b = std::move(a);
```

Before assignment:

```text
a → resource A
b → resource B
```

After:

```text
a → moved-from state
b → resource A
```

Resource B must not leak.

Therefore move assignment generally needs to release or otherwise correctly handle the destination's previous resource.

---

# 50. Self Move-Assignment

Potentially:

```cpp
obj = std::move(obj);
```

This is unusual, but a well-designed move assignment should not cause resource corruption.

A common implementation uses:

```cpp
if (this != &other)
{
    ...
}
```

However, exact implementation strategies vary, and robust move assignment should preserve the class invariants even in self-move scenarios where practical.

---

# 51. Move-Only Types

Some types cannot be copied but can be moved.

Example:

```cpp
std::unique_ptr<int>
```

This:

```cpp
std::unique_ptr<int> p1 =
    std::make_unique<int>(10);
```

is valid.

This is not:

```cpp
std::unique_ptr<int> p2 = p1;
```

because copying is deleted.

Instead:

```cpp
std::unique_ptr<int> p2 =
    std::move(p1);
```

---

# 52. Copyable + Movable Types

Many standard types support both:

```text
copy
move
```

Example:

```cpp
std::vector<int>
std::string
std::pair
std::tuple
```

Then you choose:

```cpp
b = a;
```

for copying.

Or:

```cpp
b = std::move(a);
```

when you intentionally want to allow moving from `a`.

---

# 53. Deleted Copy Operations

A move-only class can explicitly delete copying:

```cpp
class Resource
{
public:

    Resource() = default;

    Resource(
        const Resource&
    ) = delete;

    Resource& operator=(
        const Resource&
    ) = delete;

    Resource(Resource&&) noexcept = default;

    Resource& operator=(
        Resource&&
    ) noexcept = default;
};
```

This creates a move-only type.

---

# 54. Defaulted Move Operations

If members already support correct moving, you can often use:

```cpp
class Person
{
    std::string name;
    std::vector<int> data;

public:

    Person(Person&&) noexcept = default;

    Person& operator=(Person&&) noexcept = default;
};
```

But often you do not even need to declare these explicitly because of the Rule of Zero.

---

# 55. Destructor and Move Semantics

A user-declared destructor can affect implicit generation of move operations.

For example, if you write:

```cpp
class Test
{
public:

    ~Test()
    {
    }
};
```

you should understand that implicit move constructor/assignment generation rules are affected.

Do not assume:

```text
"I have a destructor, so the compiler automatically gives me all move operations."
```

It does not.

This is one reason the Rule of Zero is preferred when possible.

---

# 56. Resource Ownership Example

Imagine:

```text
Object A
   |
   ↓
Resource #100
```

Copy:

```text
Object A → Resource #100

Object B → Resource #200
```

Move:

```text
Object A → moved-from state

Object B → Resource #100
```

The resource ownership is transferred or efficiently reused.

---

# 57. Custom Class Example

```cpp
#include <iostream>
#include <utility>

using namespace std;

class Buffer
{
    int* data;
    size_t size;

public:

    Buffer(size_t n)
        : data(new int[n]),
          size(n)
    {
        cout << "Construct\n";
    }

    ~Buffer()
    {
        delete[] data;
    }

    Buffer(const Buffer& other)
        : data(new int[other.size]),
          size(other.size)
    {
        cout << "Copy\n";

        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    Buffer(Buffer&& other) noexcept
        : data(other.data),
          size(other.size)
    {
        cout << "Move\n";

        other.data = nullptr;
        other.size = 0;
    }

    Buffer& operator=(
        Buffer&& other
    ) noexcept
    {
        cout << "Move Assignment\n";

        if (this != &other)
        {
            delete[] data;

            data = other.data;
            size = other.size;

            other.data = nullptr;
            other.size = 0;
        }

        return *this;
    }
};
```

---

# 58. Move Constructor Step-by-Step

Given:

```cpp
Buffer a(100);

Buffer b =
    std::move(a);
```

Move constructor:

```cpp
Buffer(Buffer&& other)
```

Steps:

```text
1. other refers to a
2. b takes a.data
3. b takes a.size
4. a.data becomes nullptr
5. a.size becomes 0
6. b owns the original resource
```

---

# 59. Move Assignment Step-by-Step

Given:

```cpp
Buffer a(100);
Buffer b(200);

b = std::move(a);
```

Steps:

```text
1. b already owns resource B
2. Release resource B
3. Take resource A from a
4. Reset a
5. b now owns resource A
```

---

# 60. Deep Copy vs Move

Deep copy:

```text
A → Resource A
B → New Resource B

Data copied
```

Move:

```text
A → moved-from
B → Resource A

Resource transferred/reused
```

For large resources, move can be much cheaper.

---

# 61. Shallow Copy vs Move

A shallow copy might simply copy a pointer:

```text
A.data → Resource X
B.data → Resource X
```

This can cause:

```text
double delete
dangling pointers
shared ownership bugs
```

Move semantics is different.

A proper move transfers ownership and leaves the source in a valid state:

```text
A.data → null
B.data → Resource X
```

---

# 62. `std::move` with Arrays

`std::move` can be used on expressions of many types, including arrays, but what happens depends on the receiving operation.

Example:

```cpp
int arr[3] = {
    1, 2, 3
};

auto&& x =
    std::move(arr);
```

The expression is an xvalue referring to the array.

For built-in arrays, there is no special "array move" that transfers memory ownership.

---

# 63. `std::move` with Function Arguments

Example:

```cpp
void process(std::string&& value)
{
}

std::string name = "Alice";

process(
    std::move(name)
);
```

This allows the function to consume/move from `name`.

Afterward, do not assume `name` contains `"Alice"`.

---

# 64. `std::move` and Overload Resolution

Suppose:

```cpp
void process(const std::string&);
void process(std::string&&);
```

Call:

```cpp
std::string s = "Hello";

process(s);
```

The lvalue overload is selected.

Call:

```cpp
process(std::move(s));
```

The rvalue overload can be selected.

---

# 65. Overload Example

```cpp
#include <iostream>
#include <string>
#include <utility>

using namespace std;

void process(const string&)
{
    cout << "Lvalue/const-reference overload\n";
}

void process(string&&)
{
    cout << "Rvalue-reference overload\n";
}

int main()
{
    string s = "Hello";

    process(s);

    process(std::move(s));

    return 0;
}
```

Output:

```text
Lvalue/const-reference overload
Rvalue-reference overload
```

---

# 66. `std::move` Does Not Guarantee a Move

Consider:

```cpp
void process(const std::string& value)
{
}
```

Then:

```cpp
std::string s = "Hello";

process(std::move(s));
```

No move constructor is necessarily called.

The function simply receives a const reference.

Therefore:

```text
std::move
    ↓
enables rvalue overload selection
    ↓
actual overload determines what happens
```

---

# 67. `std::move` vs Perfect Forwarding

`std::move` and `std::forward` are different.

## `std::move`

```cpp
std::move(x)
```

says:

```text
Treat x as an rvalue/xvalue.
```

---

## `std::forward`

```cpp
std::forward<T>(x)
```

says:

```text
Preserve the value category represented by T.
```

---

# 68. `std::move` vs `std::forward` Table

| Feature | `std::move` | `std::forward` |
|---|---|---|
| Header | `<utility>` | `<utility>` |
| Main purpose | Enable moving | Perfect forwarding |
| Category | Produces xvalue | Conditionally lvalue/xvalue |
| Requires template deduction | No | Usually used with it |
| Typical use | Owning/local object | Forwarding-reference parameter |
| Converts lvalue to xvalue | Yes | Only when `T` indicates rvalue |
| Performs move itself | No | No |

---

# 69. `std::move` vs Copy

Copy:

```cpp
T b = a;
```

Move-enabled construction:

```cpp
T b = std::move(a);
```

Conceptually:

```text
Copy:
a → data
b → copied data

Move:
a → moved-from
b → original/transferable resources
```

The exact resource behavior depends on the type.

---

# 70. Common Mistake — Thinking `std::move` Performs the Move

Wrong:

```text
std::move()
    ↓
moves object
```

Correct:

```text
std::move()
    ↓
casts expression
    ↓
rvalue overload selected
    ↓
move constructor/assignment may execute
    ↓
resources may be transferred
```

---

# 71. Common Mistake — Using `std::move` on `const`

Avoid expecting:

```cpp
std::move(constObject)
```

to invoke a normal move constructor.

Usually:

```text
const T&&
```

cannot bind to:

```text
T&&
```

because the move operation normally needs to modify the source.

---

# 72. Common Mistake — Using Moved-From Object Incorrectly

Wrong assumption:

```cpp
std::vector<int> a = {
    1, 2, 3
};

std::vector<int> b =
    std::move(a);

cout << a[0];
```

Do not assume `a` still contains its old data.

Correct approach:

```cpp
a.clear();
a.push_back(10);
```

if you want to reuse it.

---

# 73. Common Mistake — Moving Twice

Example:

```cpp
std::string s = "Hello";

foo(std::move(s));

bar(std::move(s));
```

If `foo` consumes `s`, then `bar` receives a moved-from object.

Only do this if the semantics are intentionally designed for it.

---

# 74. Common Mistake — Moving an Object You Still Need

Example:

```cpp
std::string name = "Alice";

save(
    std::move(name)
);

cout << name;
```

The output of `name` after the move is not guaranteed to be the original value.

If you still need the original value, do not move from it.

---

# 75. Common Mistake — Unnecessary `std::move` in Return

Avoid:

```cpp
std::string makeName()
{
    std::string name = "Alice";

    return std::move(name);
}
```

Prefer:

```cpp
std::string makeName()
{
    std::string name = "Alice";

    return name;
}
```

This allows normal return-value optimization and implicit move behavior where applicable.

---

# 76. Common Mistake — Forgetting `std::move` for Move-Only Objects

This does not compile:

```cpp
std::unique_ptr<int> p1 =
    std::make_unique<int>(10);

std::unique_ptr<int> p2 = p1;
```

Correct:

```cpp
std::unique_ptr<int> p2 =
    std::move(p1);
```

---

# 77. Common Mistake — Incorrect Move Constructor

Bad:

```cpp
Buffer(Buffer&& other)
    : data(other.data)
{
}
```

If `other.data` is not reset, both objects may believe they own the same resource.

Correct ownership transfer:

```cpp
Buffer(Buffer&& other) noexcept
    : data(other.data)
{
    other.data = nullptr;
}
```

---

# 78. Common Mistake — Incorrect Move Assignment

Bad:

```cpp
Buffer& operator=(Buffer&& other)
{
    data = other.data;

    return *this;
}
```

This can leak the destination's old resource and create double ownership.

Correct implementation must account for the destination's existing resource.

---

# 79. Performance

Move semantics can provide major performance improvements for resource-owning objects.

Copy may involve:

```text
allocation
+
element copy
+
resource duplication
```

Move may involve:

```text
pointer/handle transfer
+
source reset
```

Therefore, for large resource-owning objects:

```text
Move ≪ Copy
```

can be possible.

But not every type benefits equally.

---

# 80. Complexity

`std::move()` itself:

```text
O(1)
```

because it is effectively a cast.

The complexity of the actual move operation depends on the type.

For example:

```text
vector move constructor → typically O(1)
string move constructor → often O(1), but implementation details such as SSO matter
array<int,N> move → O(N), because elements are individually moved/copied
```

Do not assume every move is O(1).

---

# 81. Memory Behavior

`std::move()` itself:

```text
Does not allocate memory
Does not free memory
Does not copy memory
Does not transfer resources
```

The selected move operation may do any of those things as required by the type.

For a typical heap-owning vector, move construction can transfer the allocation without moving every element.

---

# 82. Complete Program 1 — Vector Move

```cpp
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    vector<int> a = {
        1, 2, 3
    };

    vector<int> b =
        std::move(a);

    cout << "b: ";

    for (int x : b)
    {
        cout << x << " ";
    }

    cout << "\n";

    cout << "a size: "
         << a.size()
         << "\n";

    return 0;
}
```

Do not depend on a specific post-move `a.size()` value for generic code unless the type's specification guarantees it.

---

# 83. Complete Program 2 — Move Constructor

```cpp
#include <iostream>
#include <utility>

using namespace std;

class Test
{
public:

    Test()
    {
        cout << "Default Constructor\n";
    }

    Test(const Test&)
    {
        cout << "Copy Constructor\n";
    }

    Test(Test&&)
        noexcept
    {
        cout << "Move Constructor\n";
    }
};

int main()
{
    Test a;

    Test b =
        std::move(a);

    return 0;
}
```

Output:

```text
Default Constructor
Move Constructor
```

---

# 84. Complete Program 3 — Move Assignment

```cpp
#include <iostream>
#include <utility>

using namespace std;

class Test
{
public:

    Test()
    {
        cout << "Constructor\n";
    }

    Test(const Test&)
    {
        cout << "Copy Constructor\n";
    }

    Test(Test&&)
        noexcept
    {
        cout << "Move Constructor\n";
    }

    Test& operator=(const Test&)
    {
        cout << "Copy Assignment\n";

        return *this;
    }

    Test& operator=(Test&&)
        noexcept
    {
        cout << "Move Assignment\n";

        return *this;
    }
};

int main()
{
    Test a;

    Test b;

    b = std::move(a);

    return 0;
}
```

Output:

```text
Constructor
Constructor
Move Assignment
```

---

# 85. Complete Program 4 — `unique_ptr`

```cpp
#include <iostream>
#include <memory>
#include <utility>

using namespace std;

int main()
{
    unique_ptr<int> p1 =
        make_unique<int>(100);

    unique_ptr<int> p2 =
        std::move(p1);

    cout << *p2 << '\n';

    if (!p1)
    {
        cout << "p1 is empty\n";
    }

    return 0;
}
```

Output:

```text
100
p1 is empty
```

`unique_ptr` specifically guarantees that a moved-from `unique_ptr` is empty.

---

# 86. Complete Program 5 — Move vs Copy

```cpp
#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Test
{
public:

    Test()
    {
        cout << "Constructor\n";
    }

    Test(const Test&)
    {
        cout << "Copy Constructor\n";
    }

    Test(Test&&)
        noexcept
    {
        cout << "Move Constructor\n";
    }
};

int main()
{
    Test a;

    cout << "\nCopy:\n";

    Test b = a;

    cout << "\nMove:\n";

    Test c = std::move(a);

    return 0;
}
```

Typical output:

```text
Constructor

Copy:
Copy Constructor

Move:
Move Constructor
```

---

# 87. Complete Program 6 — Named Rvalue Reference

```cpp
#include <iostream>
#include <string>
#include <utility>

using namespace std;

void consume(string&& value)
{
    string other =
        std::move(value);

    cout << other;
}

int main()
{
    consume(
        string("Hello")
    );

    return 0;
}
```

The important point is that inside:

```cpp
consume(string&& value)
```

the expression:

```cpp
value
```

is an lvalue because it is named.

Therefore:

```cpp
std::move(value)
```

is needed if we want to move from it.

---

# 88. Complete Program 7 — Copy vs Move of Vector

```cpp
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    vector<int> a = {
        1, 2, 3
    };

    vector<int> copy = a;

    vector<int> moved =
        std::move(a);

    cout << "copy: ";

    for (int x : copy)
    {
        cout << x << " ";
    }

    cout << "\nmoved: ";

    for (int x : moved)
    {
        cout << x << " ";
    }

    cout << '\n';

    return 0;
}
```

---

# 89. Move Semantics Flow

When writing:

```cpp
T b = std::move(a);
```

the conceptual flow is:

```text
a
↓
std::move(a)
↓
xvalue
↓
overload resolution
↓
T(T&&)
↓
move constructor
↓
resource transfer/reuse
↓
a = valid moved-from state
b = destination
```

---

# 90. Move Assignment Flow

When writing:

```cpp
b = std::move(a);
```

the flow is:

```text
a
↓
std::move(a)
↓
xvalue
↓
overload resolution
↓
operator=(T&&)
↓
release/replace b's old resources
↓
transfer a's resources
↓
reset a
```

---

# 91. Copy Flow

When writing:

```cpp
T b = a;
```

the flow is:

```text
a
↓
lvalue
↓
copy constructor
↓
new independent resources
↓
a remains unchanged
```

---

# 92. Quick Comparison Table

| Operation | Expression | Typical Function |
|---|---|---|
| Copy construction | `T b = a;` | `T(const T&)` |
| Move construction | `T b = std::move(a);` | `T(T&&)` |
| Copy assignment | `b = a;` | `operator=(const T&)` |
| Move assignment | `b = std::move(a);` | `operator=(T&&)` |
| Explicit cast | `std::move(a)` | xvalue expression |

---

# 93. Copy vs Move Table

| Feature | Copy | Move |
|---|---|---|
| Source | Usually remains unchanged | Becomes moved-from |
| Resource duplication | Usually yes | Often no |
| Large object cost | Can be expensive | Often cheaper |
| Requires copy constructor | Yes | No |
| Requires move constructor | No | Yes, when applicable |
| Ownership transfer | No | Often |
| Source usable afterward | Yes with original value | Yes, but value may be unspecified |

---

# 94. Move Constructor vs Move Assignment Table

| | Move Constructor | Move Assignment |
|---|---|---|
| Destination | New | Existing |
| Example | `T b(std::move(a));` | `b = std::move(a);` |
| Signature | `T(T&&)` | `T& operator=(T&&)` |
| Destination old resource | None | Must be handled |
| Common use | Initialization | Reassignment |

---

# 95. `std::move` vs `std::forward`

```text
std::move(x)
    ↓
Always casts x to xvalue/rvalue form.

std::forward<T>(x)
    ↓
Returns x as lvalue or xvalue based on T.
```

Use:

```cpp
std::move
```

when you intentionally want to consume/move from an object.

Use:

```cpp
std::forward
```

inside a forwarding-reference function when you want to preserve the caller's value category.

---

# 96. Interview Questions

## Q1. What is `std::move()`?

`std::move()` is a C++11 utility that casts an expression to an xvalue, allowing rvalue-reference overloads such as move constructors and move assignment operators to be selected.

---

## Q2. Does `std::move()` actually move an object?

No.

It is a cast.

The actual move occurs when the selected operation transfers or reuses resources.

---

## Q3. Which header contains `std::move`?

```cpp
#include <utility>
```

---

## Q4. What is the return type of `std::move`?

Conceptually, it returns:

```cpp
remove_reference_t<T>&&
```

for the relevant deduced type.

---

## Q5. What is a move constructor?

A constructor that initializes a new object from an rvalue/xvalue:

```cpp
ClassName(ClassName&& other);
```

---

## Q6. What is move assignment?

An assignment operator that transfers resources to an existing object:

```cpp
ClassName& operator=(ClassName&& other);
```

---

## Q7. Difference between move constructor and move assignment?

Move constructor creates a new object.

Move assignment operates on an already-existing destination object.

---

## Q8. What happens to an object after moving?

It remains a valid object, but its value is generally unspecified unless the type documents a stronger postcondition.

---

## Q9. Is a moved-from vector always empty?

Do not assume that generically.

A moved-from standard-library vector is valid, but you should not rely on a particular post-move value unless guaranteed by the type's specification.

---

## Q10. Can we use a moved-from object?

Yes, provided the operation is valid for the object's resulting state.

For example:

```cpp
v.clear();
v.push_back(10);
```

is valid for a moved-from `std::vector`.

---

## Q11. Why is `std::move` useful?

It can avoid expensive copies by enabling move constructors and move assignment operators to transfer/reuse resources.

---

## Q12. Does `std::move` guarantee that a move constructor is called?

No.

It only produces an xvalue.

Overload resolution decides which operation is selected.

---

## Q13. What happens if the class has no move constructor?

Depending on the available constructors and language rules, an rvalue may bind to a copy constructor such as:

```cpp
T(const T&);
```

if one exists.

---

## Q14. Why should move constructors often be `noexcept`?

Standard containers can use the information to prefer moving during operations such as reallocation when doing so preserves exception-safety guarantees.

---

## Q15. What is `std::move_if_noexcept`?

A utility that conditionally produces an rvalue when moving is safe and otherwise may provide a const lvalue reference so copying can be preferred.

---

## Q16. Can `std::move` be used with `const` objects?

Yes, syntactically.

But:

```cpp
std::move(constObject)
```

produces a const rvalue, which usually cannot bind to an ordinary move constructor requiring `T&&`.

---

## Q17. What is a move-only type?

A type that can be moved but cannot be copied.

Example:

```cpp
std::unique_ptr<int>
```

---

## Q18. Why is `unique_ptr` moved?

Because ownership must have one owner.

```cpp
auto p2 = std::move(p1);
```

transfers ownership.

---

## Q19. Does moving a `shared_ptr` move the pointed-to object?

No.

It moves the smart-pointer handle/control information. The managed object remains where it is.

---

## Q20. Should we write `return std::move(local);`?

Usually no.

Prefer:

```cpp
return local;
```

for a local object, allowing copy elision and implicit move rules to work appropriately.

---

# 97. Best Practices

### 1. Use `std::move` when you intentionally give up the current value

```cpp
consume(
    std::move(value)
);
```

---

### 2. Do not use `std::move` just because an object is large

Moving an object you still need is a logic error.

---

### 3. Mark non-throwing move operations `noexcept`

If true:

```cpp
T(T&&) noexcept;
```

and:

```cpp
T& operator=(T&&) noexcept;
```

---

### 4. Prefer Rule of Zero

Use standard RAII types whenever possible:

```cpp
std::vector
std::string
std::unique_ptr
std::shared_ptr
```

---

### 5. Do not assume moved-from values

Use only operations that are valid for the type's documented moved-from state.

---

### 6. Avoid unnecessary `std::move` in return statements

Prefer:

```cpp
return local;
```

over:

```cpp
return std::move(local);
```

for ordinary local-return cases.

---

### 7. Use `std::forward` for forwarding references

Do not replace:

```cpp
std::forward<T>(value)
```

with:

```cpp
std::move(value)
```

in a transparent forwarding wrapper.

---

### 8. Understand ownership

Move semantics is most useful when an object owns a transferable resource.

---

### 9. Make moved-from states valid

For custom move constructors and assignments, preserve class invariants.

---

### 10. Do not create double ownership

If a raw pointer represents ownership, a move must transfer ownership correctly and leave the source in a safe state.

---

# 98. One-Line Definition

> **`std::move()` is a C++ utility that casts an expression to an xvalue, enabling move constructors, move assignment operators, or other rvalue overloads to be selected; it does not itself perform the move.**

---

# 99. Most Important Mental Model

Remember:

```text
std::move(x)
```

does **not** mean:

```text
Move x now.
```

It means:

```text
I am finished with x's current value;
allow operations to treat x as an expiring object.
```

Then:

```text
overload resolution
        ↓
move constructor / move assignment
        ↓
resource transfer
```

---

# 100. Final Summary

## `std::move`

Header:

```cpp
#include <utility>
```

Purpose:

```text
Convert an expression to an xvalue.
```

It enables:

```text
Move Constructor
Move Assignment Operator
Rvalue Overloads
```

But:

```text
std::move itself does not move resources.
```

---

## Move Constructor

Used when creating a new object:

```cpp
T b(std::move(a));
```

or:

```cpp
T b = std::move(a);
```

Signature:

```cpp
T(T&& other);
```

---

## Move Assignment

Used when the destination already exists:

```cpp
b = std::move(a);
```

Signature:

```cpp
T& operator=(T&& other);
```

---

## After Moving

The source:

```text
still exists
+
remains valid
+
usually has an unspecified value
```

Do not assume it is empty unless the type guarantees that.

---

## Copy vs Move

```text
COPY
a ──────────→ original resource
              ↓
          duplicate resource
              ↓
b ──────────→ copied resource


MOVE
a ──────────→ resource
              ↓
          transfer/reuse
              ↓
b ──────────→ resource
a ──────────→ moved-from state
```

---

## `std::move` vs `std::forward`

```text
std::move
    ↓
Explicitly treat expression as rvalue/xvalue.

std::forward<T>
    ↓
Preserve the value category represented by T.
```

---

## Final Quick Revision

```text
Header:
    <utility>

Introduced:
    C++11

std::move:
    Cast to xvalue

Does std::move itself move?
    No

Move Constructor:
    T(T&&)

Move Assignment:
    T& operator=(T&&)

Move Constructor:
    Creates new object

Move Assignment:
    Existing destination

Moved-from object:
    Valid but generally unspecified value

Move-only example:
    std::unique_ptr

Important:
    Move constructor should often be noexcept

Vector/string:
    Move can often avoid expensive element/data copying

Return local object:
    Prefer return local;

Perfect forwarding:
    Use std::forward<T>(), not std::move()

Main benefit:
    Efficient transfer/reuse of resources
```

# Final Interview One-Liner

> **`std::move()` does not move an object by itself; it casts an expression to an xvalue so that move-enabled overloads can be selected, allowing the object's resources to be transferred or efficiently reused instead of copied.**
