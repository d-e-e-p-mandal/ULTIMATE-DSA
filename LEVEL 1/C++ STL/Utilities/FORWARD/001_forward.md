# C++ Perfect Forwarding (`std::forward`) — Complete Notes

> **Important:** This topic is about **Perfect Forwarding / argument forwarding in C++** using `std::forward`. It is **not** about `std::forward_list`.

---

# Table of Contents

1. Introduction
2. Why Forwarding Is Needed
3. Lvalues and Rvalues
4. Value Categories
5. Move Semantics vs Perfect Forwarding
6. What Is Perfect Forwarding?
7. `std::forward`
8. Header File
9. Basic Syntax
10. How `std::forward` Works
11. Forwarding References
12. Universal Reference Terminology
13. Reference Collapsing
14. Template Type Deduction
15. Lvalue Argument Deduction
16. Rvalue Argument Deduction
17. Named Variables Are Lvalues
18. Without Forwarding
19. With Forwarding
20. `std::move` vs `std::forward`
21. `std::forward` Is a Cast
22. `remove_reference`
23. `decltype` and Value Categories
24. `const` Lvalues
25. `const` Rvalues
26. Explicit Template Arguments
27. Forwarding Reference Restrictions
28. Forwarding Function Parameters
29. Forwarding to Overloaded Functions
30. Forwarding to Constructors
31. Forwarding Constructors
32. Variadic Templates
33. Pack Expansion
34. Fold Expressions
35. `emplace`
36. `make_unique`
37. `make_shared`
38. `pair`
39. `tuple`
40. `optional`
41. `variant`
42. `thread`
43. Generic Factory Functions
44. Wrapper Functions
45. Perfect Forwarding with Member Functions
46. Perfect Forwarding and `std::invoke`
47. Return Value Forwarding
48. `std::forward` and `decltype(auto)`
49. Forwarding the Same Argument Multiple Times
50. Common Mistakes
51. Double Move / Repeated Forwarding
52. Dangling References
53. Lifetime Issues
54. Forwarding Constructor Pitfalls
55. Overload Resolution Pitfalls
56. `initializer_list` Pitfall
57. Braced Initializers
58. `std::forward` vs `std::move`
59. `std::forward` vs Pass-by-Value
60. Perfect Forwarding vs Overloads
61. Performance
62. Complexity
63. Exception Safety
64. Best Practices
65. Complete Program 1
66. Complete Program 2
67. Complete Program 3
68. Complete Program 4
69. Complete Factory Example
70. Interview Questions
71. Quick Comparison Tables
72. Mental Model
73. Final Summary

---

# 1. Introduction

**Perfect forwarding** is a C++ technique used by generic functions to pass arguments to another function while preserving their original value categories.

The goal is:

```text
lvalue received  → lvalue forwarded
rvalue received  → rvalue forwarded
```

The main tool is:

```cpp
std::forward<T>(value)
```

Header:

```cpp
#include <utility>
```

Typical pattern:

```cpp
template<typename T>
void wrapper(T&& value)
{
    foo(std::forward<T>(value));
}
```

This pattern is one of the most important techniques in modern C++ generic programming.

---

# 2. Why Forwarding Is Needed

Consider:

```cpp
void foo(int&)
{
    cout << "Lvalue\n";
}

void foo(int&&)
{
    cout << "Rvalue\n";
}
```

Now create a wrapper:

```cpp
template<typename T>
void wrapper(T&& value)
{
    foo(value);
}
```

Call:

```cpp
wrapper(10);
```

You may expect:

```text
Rvalue
```

But the result is:

```text
Lvalue
```

Why?

Because:

```cpp
value
```

is a **named variable**.

A named variable is an lvalue expression, even when its declared type is:

```cpp
int&&
```

Therefore:

```cpp
foo(value);
```

selects:

```cpp
foo(int&)
```

The original rvalue category has been lost.

---

# 3. Lvalues and Rvalues

Perfect forwarding requires understanding value categories.

## Lvalue

An lvalue expression generally identifies an object with a persistent identity.

Example:

```cpp
int x = 10;

x = 20;
```

Here:

```cpp
x
```

is an lvalue expression.

Another example:

```cpp
int& ref = x;
```

---

## Rvalue

An rvalue expression generally represents a temporary/value expression that can be used as a source for moving when appropriate.

Example:

```cpp
10
```

or:

```cpp
x + y
```

or:

```cpp
std::string("Hello")
```

---

# 4. Value Categories

Modern C++ has a more precise value-category model:

```text
                    Expression
                        |
              +---------+---------+
              |                   |
            glvalue            rvalue
              |                   |
        +-----+-----+       +-----+-----+
        |           |       |           |
     lvalue       xvalue  prvalue    (rvalue)
        |           |       |
        +-----------+-------+
              glvalue/rvalue relationships
```

The most important categories for forwarding are:

```text
lvalue
xvalue
prvalue
```

Together:

```text
xvalue + prvalue = rvalue
```

Perfect forwarding preserves whether the original argument should be treated as an lvalue or rvalue.

---

# 5. Move Semantics vs Perfect Forwarding

Move semantics and perfect forwarding are related but different.

## `std::move`

```cpp
std::move(x)
```

explicitly casts an expression to an rvalue/xvalue so move operations can be selected.

It essentially says:

> I am allowing this object to be treated as movable from here.

---

## `std::forward`

```cpp
std::forward<T>(x)
```

conditionally casts based on `T`.

It says:

> Forward this argument with the same value category with which it was received.

---

# 6. `std::move` vs `std::forward`

| Feature | `std::move` | `std::forward` |
|---|---|---|
| Main purpose | Explicitly enable moving | Preserve original category |
| Converts lvalue to rvalue | Yes | Only when `T` requires it |
| Used mainly in | Move operations | Forwarding functions |
| Requires template deduction | No | Normally yes |
| Typical pattern | `std::move(x)` | `std::forward<T>(x)` |
| Meaning | "Treat as movable" | "Forward as originally received" |

---

# 7. What Is Perfect Forwarding?

Perfect forwarding means forwarding an argument from one function to another while preserving its original value category.

Example:

```cpp
template<typename T>
void wrapper(T&& value)
{
    foo(std::forward<T>(value));
}
```

If the caller provides an lvalue:

```cpp
int x = 10;

wrapper(x);
```

then:

```text
T = int&
```

and:

```cpp
std::forward<T>(value)
```

becomes effectively:

```cpp
int&
```

If the caller provides an rvalue:

```cpp
wrapper(10);
```

then:

```text
T = int
```

and:

```cpp
std::forward<T>(value)
```

becomes effectively:

```cpp
int&&
```

---

# 8. `std::forward`

`std::forward` is provided by:

```cpp
#include <utility>
```

Typical usage:

```cpp
std::forward<T>(value)
```

It is used to preserve the value category of a forwarding-reference parameter.

---

# 9. Basic Syntax

Conceptually, `std::forward` has overloads equivalent to:

```cpp
template<class T>
constexpr T&& forward(
    std::remove_reference_t<T>& value
) noexcept;
```

and:

```cpp
template<class T>
constexpr T&& forward(
    std::remove_reference_t<T>&& value
) noexcept;
```

The actual standard specification should be consulted for the exact library declaration for the C++ version being used.

The important idea is:

```text
T determines whether the result is lvalue or rvalue.
```

---

# 10. How `std::forward` Works

Consider:

```cpp
int x = 10;

wrapper(x);
```

For:

```cpp
template<typename T>
void wrapper(T&& value)
```

template deduction gives:

```text
T = int&
```

Therefore:

```cpp
std::forward<T>(value)
```

becomes:

```cpp
std::forward<int&>(value)
```

Result:

```cpp
int&
```

---

Now:

```cpp
wrapper(10);
```

Deduction gives:

```text
T = int
```

Therefore:

```cpp
std::forward<int>(value)
```

produces:

```cpp
int&&
```

The original category is preserved.

---

# 11. Forwarding References

A parameter of the form:

```cpp
T&&
```

is a **forwarding reference** when:

1. `T` is a template parameter undergoing type deduction.
2. The parameter is an rvalue-reference-to-deduced-type form.

Example:

```cpp
template<typename T>
void func(T&& value)
{
}
```

This is a forwarding reference.

---

# 12. Universal Reference Terminology

The term:

```text
Universal Reference
```

was popularized in older C++ literature.

The modern standard terminology is:

```text
Forwarding Reference
```

Prefer saying:

```text
forwarding reference
```

when discussing modern C++.

---

# 13. Reference Collapsing

Reference collapsing is essential to perfect forwarding.

The rules are:

```text
&  +  &   → &
&  +  &&  → &
&& +  &   → &
&& +  &&  → &&
```

The simplified rule is:

```text
If any participating reference is &
the result is &
```

except:

```text
&& + && = &&
```

---

# 14. Reference Collapsing Table

| First | Second | Result |
|---|---|---|
| `&` | `&` | `&` |
| `&` | `&&` | `&` |
| `&&` | `&` | `&` |
| `&&` | `&&` | `&&` |

---

# 15. Lvalue Argument Deduction

Given:

```cpp
template<typename T>
void func(T&& value)
{
}
```

and:

```cpp
int x = 10;

func(x);
```

`x` is an lvalue.

Therefore:

```text
T = int&
```

Parameter type:

```text
T&&
= int& &&
```

Reference collapsing:

```text
int& && → int&
```

So:

```text
value has type int&
```

---

# 16. Rvalue Argument Deduction

Given:

```cpp
template<typename T>
void func(T&& value)
{
}
```

Call:

```cpp
func(10);
```

`10` is an rvalue.

Therefore:

```text
T = int
```

Parameter:

```text
T&&
= int&&
```

So:

```text
value has type int&&
```

But remember:

```text
named value expression = lvalue
```

Therefore forwarding is still required.

---

# 17. Named Variables Are Lvalues

This is one of the most important rules.

Consider:

```cpp
template<typename T>
void func(T&& value)
{
    cout << "value is a named variable";
}
```

Even if:

```cpp
T = int
```

and:

```cpp
value
```

has type:

```cpp
int&&
```

the expression:

```cpp
value
```

is an lvalue.

Therefore:

```cpp
foo(value);
```

does not automatically preserve the original rvalue category.

Use:

```cpp
foo(std::forward<T>(value));
```

---

# 18. Without Forwarding

```cpp
#include <iostream>

using namespace std;

void show(int&)
{
    cout << "Lvalue\n";
}

void show(int&&)
{
    cout << "Rvalue\n";
}

template<typename T>
void wrapper(T&& value)
{
    show(value);
}

int main()
{
    wrapper(10);

    return 0;
}
```

Output:

```text
Lvalue
```

Why?

Because:

```cpp
value
```

is a named lvalue expression.

---

# 19. With Forwarding

```cpp
#include <iostream>
#include <utility>

using namespace std;

void show(int&)
{
    cout << "Lvalue\n";
}

void show(int&&)
{
    cout << "Rvalue\n";
}

template<typename T>
void wrapper(T&& value)
{
    show(std::forward<T>(value));
}

int main()
{
    wrapper(10);

    return 0;
}
```

Output:

```text
Rvalue
```

Now the original rvalue category is preserved.

---

# 20. Lvalue + Rvalue Complete Example

```cpp
#include <iostream>
#include <utility>

using namespace std;

void show(int&)
{
    cout << "Lvalue\n";
}

void show(int&&)
{
    cout << "Rvalue\n";
}

template<typename T>
void wrapper(T&& value)
{
    show(std::forward<T>(value));
}

int main()
{
    int x = 10;

    wrapper(x);
    wrapper(20);

    return 0;
}
```

Output:

```text
Lvalue
Rvalue
```

---

# 21. `std::forward` Is a Conditional Cast

`std::forward` does not magically move data.

It performs a conditional cast based on the template type.

Conceptually:

```text
T = U&
    ↓
forward<T>(x)
    ↓
U&

T = U
    ↓
forward<T>(x)
    ↓
U&&
```

This is why it preserves the original value category.

---

# 22. `std::move` Is Also a Cast

Neither:

```cpp
std::move()
```

nor:

```cpp
std::forward()
```

actually performs the move operation itself.

They are cast-like utilities.

The actual move happens later when overload resolution selects a move constructor or move assignment operator.

Example:

```cpp
string b = std::move(a);
```

The cast allows:

```cpp
string(string&&)
```

to be selected.

---

# 23. `remove_reference`

`std::forward` uses reference removal internally.

Header:

```cpp
#include <type_traits>
```

Example:

```cpp
using A = std::remove_reference_t<int&>;
```

Result:

```text
int
```

For:

```cpp
std::remove_reference_t<int&&>
```

result:

```text
int
```

---

# 24. Why `remove_reference` Matters

For:

```cpp
T = int&
```

we need to access the underlying type:

```text
int
```

and then construct the appropriate reference result.

Conceptually:

```text
T
 ↓
remove_reference_t<T>
 ↓
int
```

This helps `std::forward` implement conditional forwarding.

---

# 25. `decltype` and Value Categories

`decltype` has special rules that can help inspect expression types.

Example:

```cpp
int x = 10;

decltype(x)
```

is:

```text
int
```

while:

```cpp
decltype((x))
```

is:

```text
int&
```

This distinction is important in advanced forwarding code.

---

# 26. `const` Lvalue

Consider:

```cpp
const int x = 10;

wrapper(x);
```

For:

```cpp
template<typename T>
void wrapper(T&& value)
```

deduction gives:

```text
T = const int&
```

Parameter:

```text
const int& &&
```

collapses to:

```text
const int&
```

Forwarding:

```cpp
std::forward<T>(value)
```

produces a const lvalue.

---

# 27. Rvalue with `const`

Example:

```cpp
const int x = 10;

wrapper(std::move(x));
```

Here the expression is a const rvalue/xvalue.

The deduced type preserves constness:

```text
T = const int
```

and the forwarded expression is:

```text
const int&&
```

This usually prevents moving from the object in the useful sense because move constructors normally require a non-const rvalue reference.

---

# 28. Explicit Template Arguments

Forwarding references have special behavior when `T` is explicitly specified.

Example:

```cpp
template<typename T>
void func(T&& value)
{
}
```

If you explicitly call:

```cpp
func<int>(10);
```

then:

```text
T = int
```

and the parameter is:

```cpp
int&&
```

But:

```cpp
int x = 10;

func<int>(x);
```

does not work because `int&&` cannot bind to the lvalue `x`.

The special forwarding-reference deduction behavior occurs when `T` is actually deduced.

---

# 29. Forwarding Reference Restrictions

This is a forwarding reference:

```cpp
template<typename T>
void func(T&& value);
```

This is not a forwarding reference:

```cpp
void func(int&& value);
```

It is an ordinary rvalue reference.

Also:

```cpp
template<typename T>
void func(const T&& value);
```

is not the usual forwarding-reference form.

The important pattern is:

```cpp
T&&
```

with a deduced `T`.

---

# 30. Forwarding Function Parameters

The standard pattern is:

```cpp
template<typename T>
void wrapper(T&& arg)
{
    target(std::forward<T>(arg));
}
```

This can forward:

```text
lvalue
rvalue
const lvalue
const rvalue
```

while preserving the relevant type and value category.

---

# 31. Forwarding to Overloaded Functions

Suppose:

```cpp
void process(string&);
void process(string&&);
```

Wrapper:

```cpp
template<typename T>
void wrapper(T&& value)
{
    process(std::forward<T>(value));
}
```

Now:

```cpp
string s = "Hello";

wrapper(s);
wrapper(string("World"));
```

selects the appropriate overload.

---

# 32. Forwarding to Constructors

Suppose:

```cpp
class Person
{
    string name;

public:

    Person(string name)
        : name(std::move(name))
    {
    }
};
```

A generic factory can forward constructor arguments.

Example:

```cpp
template<typename T, typename... Args>
T create(Args&&... args)
{
    return T(
        std::forward<Args>(args)...
    );
}
```

---

# 33. Forwarding Constructor

A constructor can itself be a forwarding-reference template:

```cpp
class Person
{
    string name;

public:

    template<typename T>
    Person(T&& n)
        : name(std::forward<T>(n))
    {
    }
};
```

This can accept both:

```cpp
string s = "John";

Person a(s);
Person b(string("John"));
```

The lvalue can be copied, while the rvalue can be moved.

However, forwarding constructors have important overload-resolution pitfalls and should not be added casually to classes.

---

# 34. Forwarding Constructor Pitfall

A constructor like:

```cpp
template<typename T>
Person(T&& value);
```

can be very greedy.

It may compete with:

```cpp
Person(const Person&);
Person(Person&&);
```

and other constructors.

A forwarding constructor can accidentally participate in overload resolution for types that should have been handled by copy/move constructors.

Therefore:

> Forwarding constructors should be constrained when necessary.

Modern C++ can use concepts or `requires`.

---

# 35. Constrained Forwarding Constructor

Example:

```cpp
#include <concepts>
#include <string>
#include <utility>

class Person
{
    std::string name;

public:

    template<typename T>
        requires std::constructible_from<std::string, T>
    Person(T&& n)
        : name(std::forward<T>(n))
    {
    }
};
```

The exact constraint should be designed according to the class's intended API.

---

# 36. Variadic Templates + Perfect Forwarding

Perfect forwarding becomes especially powerful with parameter packs.

Pattern:

```cpp
template<typename... Args>
void wrapper(Args&&... args)
{
    target(
        std::forward<Args>(args)...
    );
}
```

Every argument preserves its own category.

---

# 37. Example — Multiple Arguments

```cpp
#include <iostream>
#include <string>
#include <utility>

using namespace std;

void print(
    int x,
    const string& text
)
{
    cout << x << " " << text;
}

template<typename... Args>
void wrapper(Args&&... args)
{
    print(
        std::forward<Args>(args)...
    );
}

int main()
{
    string s = "Hello";

    wrapper(10, s);

    return 0;
}
```

Output:

```text
10 Hello
```

---

# 38. Pack Expansion

This:

```cpp
std::forward<Args>(args)...
```

means:

```text
forward first argument
forward second argument
forward third argument
...
```

For:

```cpp
Args = {A, B, C}
```

conceptually:

```cpp
std::forward<A>(arg1),
std::forward<B>(arg2),
std::forward<C>(arg3)
```

---

# 39. Fold Expressions + Forwarding

C++17 fold expression:

```cpp
template<typename... Args>
void printAll(Args&&... args)
{
    (
        (cout << std::forward<Args>(args) << " "),
        ...
    );
}
```

Usage:

```cpp
printAll(
    10,
    20,
    "Hello"
);
```

Output:

```text
10 20 Hello
```

Each argument is forwarded individually.

---

# 40. Perfect Forwarding with `emplace`

Container `emplace` functions are classic users of perfect forwarding.

Example:

```cpp
vector<pair<int, string>> v;

v.emplace_back(
    1,
    "Alice"
);
```

Conceptually, the container forwards the constructor arguments to construct the element directly.

Typical pattern:

```cpp
template<typename... Args>
reference emplace_back(Args&&... args);
```

Implementation details vary by container and standard library implementation, but forwarding is central to the interface.

---

# 41. `push_back` vs `emplace_back`

Example:

```cpp
vector<string> v;

string s = "Hello";

v.push_back(s);
```

The existing object is passed to `push_back`.

For an rvalue:

```cpp
v.push_back(std::move(s));
```

the string can be moved.

With:

```cpp
v.emplace_back("Hello");
```

constructor arguments are forwarded to construct the string in place.

Important:

> `emplace_back` is not automatically faster in every situation. It is useful when constructing an element from its constructor arguments.

---

# 42. `std::make_unique`

Example:

```cpp
auto p =
    std::make_unique<string>(
        "Hello"
    );
```

`make_unique` accepts constructor arguments using forwarding references.

Conceptually:

```cpp
template<class T, class... Args>
unique_ptr<T> make_unique(
    Args&&... args
)
{
    return unique_ptr<T>(
        new T(
            std::forward<Args>(args)...
        )
    );
}
```

The actual implementation has additional details.

---

# 43. `std::make_shared`

Example:

```cpp
auto p =
    std::make_shared<vector<int>>(
        5,
        10
    );
```

The arguments are forwarded to the `vector` constructor.

Conceptually:

```cpp
make_shared<T>(
    std::forward<Args>(args)...
);
```

The actual implementation is more complex because shared ownership and control-block allocation are involved.

---

# 44. `pair`

C++ pair factory:

```cpp
auto p = std::make_pair(
    10,
    string("Hello")
);
```

The factory uses forwarding to preserve argument categories.

---

# 45. `tuple`

Example:

```cpp
auto t = std::make_tuple(
    10,
    string("Hello")
);
```

Tuple construction/factory facilities use forwarding to efficiently initialize their stored objects.

---

# 46. `optional`

Modern C++ provides:

```cpp
optional<string> value;

value.emplace(
    "Hello"
);
```

The arguments are forwarded to construct the contained object.

---

# 47. `variant`

Example:

```cpp
variant<string, int> v;

v.emplace<string>(
    "Hello"
);
```

The constructor arguments are forwarded to the selected alternative.

---

# 48. `thread`

When constructing a thread:

```cpp
thread t(
    function,
    arg1,
    arg2
);
```

The thread constructor stores/copies/moves the callable and arguments as required for later invocation.

Forwarding is part of this machinery.

Conceptually:

```cpp
std::forward<Args>(args)...
```

is involved in passing arguments through the generic call machinery.

---

# 49. Generic Factory Function

A factory is a common real-world use.

```cpp
template<typename T, typename... Args>
T create(Args&&... args)
{
    return T(
        std::forward<Args>(args)...
    );
}
```

Usage:

```cpp
string s =
    create<string>(
        "Hello"
    );
```

The constructor arguments are forwarded.

---

# 50. Factory Returning Smart Pointer

```cpp
template<typename T, typename... Args>
auto makeObject(Args&&... args)
{
    return std::make_unique<T>(
        std::forward<Args>(args)...
    );
}
```

Usage:

```cpp
auto p =
    makeObject<string>(
        "Hello"
    );
```

---

# 51. Generic Wrapper Function

Suppose:

```cpp
void process(string&);
void process(string&&);
```

Wrapper:

```cpp
template<typename T>
void wrapper(T&& value)
{
    process(
        std::forward<T>(value)
    );
}
```

This wrapper does not unnecessarily change the argument category.

---

# 52. Forwarding Multiple Parameters

```cpp
template<typename A, typename B>
void wrapper(
    A&& a,
    B&& b
)
{
    target(
        std::forward<A>(a),
        std::forward<B>(b)
    );
}
```

Each parameter has its own deduced type.

Example:

```cpp
string s = "Hello";

wrapper(
    s,
    string("World")
);
```

Then:

```text
a → lvalue
b → rvalue
```

---

# 53. Perfect Forwarding and `std::invoke`

C++ provides:

```cpp
std::invoke
```

for generic invocation of:

- Functions
- Function objects
- Member function pointers
- Member data pointers

A generic wrapper can combine forwarding with `std::invoke`.

```cpp
template<typename F, typename... Args>
decltype(auto) call(
    F&& f,
    Args&&... args
)
{
    return std::invoke(
        std::forward<F>(f),
        std::forward<Args>(args)...
    );
}
```

Header:

```cpp
#include <functional>
```

---

# 54. Why Forward the Callable Too?

Consider:

```cpp
template<typename F, typename... Args>
decltype(auto) call(
    F&& f,
    Args&&... args
)
```

`F` is also a forwarding-reference type.

Therefore:

```cpp
std::forward<F>(f)
```

preserves whether the callable was passed as:

```text
lvalue
```

or:

```text
rvalue
```

This matters when the callable has different overloads or state.

---

# 55. Return Value Forwarding

Forwarding is primarily about function arguments.

Returning requires a different consideration.

Example:

```cpp
template<typename T>
decltype(auto) wrapper(T&& value)
{
    return std::forward<T>(value);
}
```

This can preserve reference/value category in the return expression, but it can also create dangling references if the caller passes a temporary.

Therefore this pattern must be used carefully.

---

# 56. `decltype(auto)` and Forwarding

`decltype(auto)` preserves the exact `decltype` of the return expression.

Example:

```cpp
template<typename T>
decltype(auto) identity(T&& value)
{
    return std::forward<T>(value);
}
```

For an lvalue:

```cpp
int x = 10;

auto&& result = identity(x);
```

The returned expression can preserve the reference.

For a temporary, lifetime and ownership must be considered carefully.

---

# 57. Forwarding Does Not Extend Lifetime

This is important.

```cpp
template<typename T>
T&& bad(T&& value)
{
    return std::forward<T>(value);
}
```

If used with a temporary:

```cpp
auto&& x = bad(10);
```

the returned reference can refer to an object whose lifetime has ended.

Perfect forwarding does not magically extend object lifetime.

---

# 58. Dangling Reference Example

Consider:

```cpp
const string& bad()
{
    return string("Hello");
}
```

This returns a reference to a temporary whose lifetime ends.

Forwarding does not fix this:

```cpp
template<typename T>
T&& bad(T&& value)
{
    return std::forward<T>(value);
}
```

Do not use forwarding as a substitute for ownership/lifetime design.

---

# 59. Forwarding the Same Argument Multiple Times

Be careful:

```cpp
foo(
    std::forward<T>(arg),
    std::forward<T>(arg)
);
```

If `arg` was an rvalue, it may be moved from during the first use.

The second use then sees a moved-from object.

A forwarded rvalue should generally be treated as consumable.

---

# 60. Example of Repeated Forwarding

```cpp
template<typename T>
void bad(T&& value)
{
    consume(
        std::forward<T>(value)
    );

    consume(
        std::forward<T>(value)
    );
}
```

If `value` is an rvalue and `consume()` moves from it:

```text
First call → may consume resources
Second call → moved-from state
```

Only forward multiple times when the semantics are intentionally safe.

---

# 61. `std::move` Inside a Forwarding Function

Wrong in many forwarding wrappers:

```cpp
template<typename T>
void wrapper(T&& value)
{
    foo(std::move(value));
}
```

If caller passes:

```cpp
int x = 10;

wrapper(x);
```

then:

```cpp
x
```

was an lvalue, but:

```cpp
std::move(value)
```

turns it into an rvalue.

The wrapper has changed the original category.

---

# 62. Correct Forwarding

Use:

```cpp
template<typename T>
void wrapper(T&& value)
{
    foo(
        std::forward<T>(value)
    );
}
```

Now:

```text
lvalue → lvalue
rvalue → rvalue
```

---

# 63. `std::forward` Outside a Forwarding Context

Do not blindly write:

```cpp
std::forward<int>(x);
```

just because `forward` exists.

`std::forward` is primarily intended to be used with a type `T` deduced from a forwarding-reference parameter.

Correct:

```cpp
template<typename T>
void wrapper(T&& value)
{
    target(
        std::forward<T>(value)
    );
}
```

---

# 64. `std::forward` Is Not a Faster `std::move`

This is a common misconception.

```cpp
std::move(x)
```

and:

```cpp
std::forward<T>(x)
```

solve different problems.

```text
move
→ explicitly cast to movable/rvalue form

forward
→ preserve the caller's original category
```

---

# 65. Forwarding and Copy Elision

Perfect forwarding does not disable C++ copy elision.

For example:

```cpp
return T(...);
```

may benefit from guaranteed or permitted copy elision depending on the context and language version.

Forwarding is about preserving argument categories during calls.

---

# 66. Forwarding and Move Constructors

Suppose:

```cpp
class Test
{
public:

    Test()
    {
        cout << "Constructor\n";
    }

    Test(const Test&)
    {
        cout << "Copy\n";
    }

    Test(Test&&)
    {
        cout << "Move\n";
    }
};
```

Forwarding wrapper:

```cpp
template<typename T>
void create(T&& obj)
{
    Test t(
        std::forward<T>(obj)
    );
}
```

Then:

```cpp
Test a;

create(a);
```

selects the copy constructor.

But:

```cpp
create(Test{});
```

can select the move constructor.

---

# 67. Complete Program — Copy vs Move

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
        cout << "Copy\n";
    }

    Test(Test&&)
    {
        cout << "Move\n";
    }
};

template<typename T>
void create(T&& obj)
{
    Test t(
        std::forward<T>(obj)
    );
}

int main()
{
    Test a;

    create(a);

    create(Test{});

    return 0;
}
```

Typical output:

```text
Constructor
Copy
Constructor
Move
```

The exact observable output can depend on the context and language version, but the forwarding principle is as shown.

---

# 68. Perfect Forwarding with `string`

```cpp
void process(const string&)
{
    cout << "Copy-compatible path\n";
}

void process(string&&)
{
    cout << "Move-compatible path\n";
}

template<typename T>
void wrapper(T&& value)
{
    process(
        std::forward<T>(value)
    );
}
```

Usage:

```cpp
string s = "Hello";

wrapper(s);
wrapper(string("World"));
```

The first call forwards an lvalue.

The second forwards an rvalue.

---

# 69. Perfect Forwarding with a Callable

```cpp
#include <iostream>
#include <utility>

using namespace std;

struct Printer
{
    void operator()(int x) const
    {
        cout << x << '\n';
    }
};

template<typename F, typename T>
void call(
    F&& f,
    T&& value
)
{
    std::forward<F>(f)(
        std::forward<T>(value)
    );
}

int main()
{
    Printer p;

    call(p, 10);

    call(Printer{}, 20);

    return 0;
}
```

Both the callable and argument are forwarded.

---

# 70. Perfect Forwarding with `std::invoke`

```cpp
#include <functional>
#include <iostream>
#include <utility>

using namespace std;

template<typename F, typename... Args>
decltype(auto) call(
    F&& f,
    Args&&... args
)
{
    return std::invoke(
        std::forward<F>(f),
        std::forward<Args>(args)...
    );
}

int add(int a, int b)
{
    return a + b;
}

int main()
{
    cout << call(add, 10, 20);

    return 0;
}
```

Output:

```text
30
```

---

# 71. Perfect Forwarding with a Factory

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <utility>

using namespace std;

template<typename T, typename... Args>
unique_ptr<T> create(
    Args&&... args
)
{
    return make_unique<T>(
        std::forward<Args>(args)...
    );
}

int main()
{
    auto p =
        create<string>("Hello");

    cout << *p;

    return 0;
}
```

Output:

```text
Hello
```

---

# 72. Perfect Forwarding with `emplace_back`

```cpp
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Person
{
public:

    string name;
    int age;

    Person(
        string n,
        int a
    )
        : name(std::move(n)),
          age(a)
    {
    }
};

int main()
{
    vector<Person> people;

    people.emplace_back(
        "Alice",
        30
    );

    cout
        << people[0].name
        << " "
        << people[0].age;

    return 0;
}
```

`emplace_back` forwards its arguments to the `Person` constructor.

---

# 73. Perfect Forwarding with Variadic Templates

```cpp
#include <iostream>
#include <utility>

using namespace std;

void print(int x)
{
    cout << x << '\n';
}

void print(const string& s)
{
    cout << s << '\n';
}

template<typename... Args>
void wrapper(Args&&... args)
{
    (print(
        std::forward<Args>(args)
    ), ...);
}

int main()
{
    string s = "Hello";

    wrapper(10, s, string("World"));

    return 0;
}
```

Each argument is independently forwarded.

---

# 74. Forwarding and `initializer_list`

Braced initializer lists have special deduction rules.

For example:

```cpp
template<typename T>
void func(T&& value)
{
}
```

This may not deduce `T` from:

```cpp
func({1, 2, 3});
```

because a braced initializer list does not have an ordinary type that can be deduced in this context.

You may need:

```cpp
func(vector<int>{1, 2, 3});
```

or an overload specifically accepting:

```cpp
std::initializer_list<T>
```

---

# 75. `initializer_list` Example

```cpp
template<typename T>
void func(initializer_list<T> values)
{
    for (T x : values)
    {
        cout << x << " ";
    }
}
```

Now:

```cpp
func({1, 2, 3});
```

can deduce:

```text
T = int
```

---

# 76. Forwarding and Arrays

Array types can participate in forwarding-reference deduction without automatically decaying to pointers in the same way as pass-by-value parameters.

Example:

```cpp
template<typename T>
void func(T&& value)
{
}
```

For:

```cpp
int arr[3];

func(arr);
```

`T` can preserve the array type as an lvalue reference.

This is one reason forwarding references are useful for generic wrappers.

---

# 77. Forwarding and Function Types

Similarly, function names can be preserved through forwarding-reference deduction rather than immediately decaying to function pointers in the same way as ordinary by-value parameters.

This enables generic callable wrappers.

---

# 78. Forwarding Reference vs Rvalue Reference

This distinction is critical.

## Rvalue reference

```cpp
void func(string&& value);
```

Only accepts suitable rvalues.

---

## Forwarding reference

```cpp
template<typename T>
void func(T&& value);
```

Can accept both:

```text
lvalue
rvalue
```

when `T` is deduced.

---

# 79. Forwarding Reference Example

```cpp
string s = "Hello";

func(s);             // T = string&
func(string("Hi"));  // T = string
```

This dual behavior is the foundation of perfect forwarding.

---

# 80. Forwarding Reference Does Not Mean "Always Move"

A forwarding reference:

```cpp
T&&
```

does not mean:

```text
Always rvalue
```

Instead:

```text
T = U&  → parameter collapses to U&
T = U   → parameter is U&&
```

Therefore it can bind to both categories.

---

# 81. Perfect Forwarding and `const`

Consider:

```cpp
const string s = "Hello";

wrapper(s);
```

Deduction:

```text
T = const string&
```

Forwarding preserves:

```text
const string&
```

Therefore the target function cannot modify the object.

---

# 82. Perfect Forwarding and Volatile

Forwarding also preserves cv-qualifiers such as `volatile` when type deduction permits them.

Example:

```cpp
volatile int x = 10;

wrapper(x);
```

The deduced type preserves the relevant qualification.

However, `volatile` has special semantics and is generally not used as a general-purpose synchronization mechanism.

---

# 83. Perfect Forwarding and Type Preservation

Perfect forwarding preserves more than just lvalue/rvalue category.

It can preserve:

```text
const
volatile
references
array types
function types
```

subject to template deduction rules.

The key concept is:

```text
Preserve the argument's deduced type/category information.
```

---

# 84. Perfect Forwarding and Overload Resolution

Forwarding is useful because it lets the final target function perform overload resolution based on the original category.

Example:

```cpp
void foo(string&);
void foo(const string&);
void foo(string&&);
```

A forwarding wrapper can preserve enough information for the correct overload to be selected.

---

# 85. Perfect Forwarding vs Explicit Overloads

Without forwarding:

```cpp
void wrapper(string& x)
{
    foo(x);
}

void wrapper(string&& x)
{
    foo(std::move(x));
}
```

This works but requires separate overloads.

Perfect forwarding provides one generic wrapper:

```cpp
template<typename T>
void wrapper(T&& x)
{
    foo(std::forward<T>(x));
}
```

This is particularly useful for generic libraries.

---

# 86. Perfect Forwarding vs Pass-by-Value

Pass-by-value:

```cpp
template<typename T>
void wrapper(T value)
{
    foo(value);
}
```

may involve a copy or move into `value`.

Perfect forwarding:

```cpp
template<typename T>
void wrapper(T&& value)
{
    foo(std::forward<T>(value));
}
```

can avoid that extra parameter copy and preserve the original category.

But:

> Perfect forwarding is not automatically the best API for every function.

For simple APIs, pass-by-value or a normal reference can be clearer.

---

# 87. When Not to Use Perfect Forwarding

Do not use perfect forwarding merely because it exists.

For example, if a function only needs to read a string:

```cpp
void print(const string& s);
```

is often clearer than:

```cpp
template<typename T>
void print(T&& s);
```

Perfect forwarding is most valuable when building:

```text
generic wrappers
factories
emplace-style APIs
generic dispatch functions
library infrastructure
```

---

# 88. Perfect Forwarding and Performance

Potential benefits:

- Avoid unnecessary copies
- Preserve move opportunities
- Preserve overload selection
- Enable in-place construction
- Build efficient generic wrappers

But the actual performance depends on:

```text
object type
constructor
move constructor
allocator
container
compiler
optimization
```

Perfect forwarding itself is generally a compile-time technique with no meaningful runtime cost for the forwarding operation.

---

# 89. Complexity

`std::forward` itself is effectively:

```text
O(1)
```

It does not allocate memory.

It does not copy the object.

It does not move the object's resources by itself.

Conceptually:

```text
std::forward
    ↓
cast
    ↓
target function
```

The target function determines whether a copy or move actually occurs.

---

# 90. `std::forward` and `noexcept`

`std::forward` is specified as `noexcept`.

Therefore the forwarding cast itself does not throw.

However:

```cpp
foo(std::forward<T>(value));
```

may throw if `foo` or a constructor/move operation invoked by it throws.

Do not confuse:

```text
forward itself is noexcept
```

with:

```text
the whole operation is noexcept
```

---

# 91. Exception Safety

Perfect forwarding can preserve exception behavior of the target operation.

For example:

```cpp
template<typename T>
void wrapper(T&& value)
{
    target(
        std::forward<T>(value)
    );
}
```

If `target()` throws, `wrapper()` can throw too unless it handles the exception.

If writing a `noexcept` generic wrapper, consider:

```cpp
noexcept(
    std::is_nothrow_invocable_v<
        F,
        Args...
    >
)
```

or modern concepts/traits appropriate to the API.

---

# 92. Conditional `noexcept` Example

```cpp
template<typename F, typename... Args>
decltype(auto) call(
    F&& f,
    Args&&... args
)
noexcept(
    std::is_nothrow_invocable_v<
        F,
        Args...
    >
)
{
    return std::invoke(
        std::forward<F>(f),
        std::forward<Args>(args)...
    );
}
```

This is a common generic-library technique.

---

# 93. Perfect Forwarding and Lifetime

Forwarding preserves reference/category information.

It does **not** manage ownership.

This means:

```cpp
template<typename T>
void wrapper(T&& value)
{
    storeReference(
        std::forward<T>(value)
    );
}
```

can be dangerous if `storeReference()` stores the reference beyond the argument's lifetime.

Always separate:

```text
value category
```

from:

```text
object lifetime
```

---

# 94. Forwarding and Temporary Objects

Example:

```cpp
wrapper(
    string("Hello")
);
```

The argument is a temporary.

Inside:

```cpp
template<typename T>
void wrapper(T&& value)
```

`value` is a named variable, so:

```cpp
value
```

is an lvalue expression.

Only:

```cpp
std::forward<T>(value)
```

restores its rvalue category.

---

# 95. Forwarding and Moved-From Objects

If an rvalue is forwarded to a target that moves from it:

```cpp
consume(
    std::forward<T>(value)
);
```

the object may become moved-from.

A moved-from object remains valid in the general C++ library sense unless a specific type states otherwise, but its value is generally unspecified.

Do not assume it retains its original contents.

---

# 96. `std::forward` Does Not Guarantee a Move

This is very important.

Calling:

```cpp
std::forward<T>(value)
```

does not guarantee that a move constructor will execute.

It only preserves the category.

Then overload resolution decides what happens.

For example, if the target only has:

```cpp
void foo(const string&);
```

an rvalue can bind to that overload without moving the string.

---

# 97. Perfect Forwarding Does Not Mean Zero Copies Everywhere

The phrase:

```text
zero overhead
```

should be interpreted carefully.

Perfect forwarding can avoid unnecessary copies caused by wrappers, but the target operation may still:

- Copy
- Move
- Allocate
- Construct
- Reallocate

depending on the code.

Therefore:

```text
Perfect forwarding removes avoidable wrapper overhead.
```

It does not guarantee zero copies in the entire program.

---

# 98. Forwarding and `emplace`

`emplace` functions commonly look conceptually like:

```cpp
template<typename... Args>
reference emplace(
    Args&&... args
);
```

They forward:

```cpp
std::forward<Args>(args)...
```

to the element's constructor.

This is why:

```cpp
v.emplace_back(
    constructor_arg1,
    constructor_arg2
);
```

can construct an element directly from its arguments.

---

# 99. Perfect Forwarding in the STL

Common places where forwarding techniques are used include:

```text
container::emplace
container::emplace_back
container::emplace_front

make_unique
make_shared
make_pair
make_tuple

optional::emplace
variant::emplace

thread construction
generic invocation utilities
```

Implementation details can vary by C++ version and standard-library implementation.

---

# 100. Common Mistake — Missing `std::forward`

Wrong:

```cpp
template<typename T>
void wrapper(T&& arg)
{
    target(arg);
}
```

Correct:

```cpp
template<typename T>
void wrapper(T&& arg)
{
    target(
        std::forward<T>(arg)
    );
}
```

---

# 101. Common Mistake — Using `std::move`

Wrong for a transparent forwarding wrapper:

```cpp
template<typename T>
void wrapper(T&& arg)
{
    target(
        std::move(arg)
    );
}
```

This turns an lvalue argument into an rvalue.

Correct:

```cpp
target(
    std::forward<T>(arg)
);
```

---

# 102. Common Mistake — Missing `&&`

Wrong:

```cpp
template<typename T>
void wrapper(T arg)
{
    target(
        std::forward<T>(arg)
    );
}
```

This is not the standard forwarding-reference pattern because:

```cpp
T arg
```

is pass-by-value.

Correct:

```cpp
template<typename T>
void wrapper(T&& arg)
{
    target(
        std::forward<T>(arg)
    );
}
```

---

# 103. Common Mistake — Treating `T&&` as Always Rvalue

Wrong mental model:

```text
T&& = always rvalue reference
```

Correct:

```text
T&& with deduced T
=
forwarding reference
```

It can become:

```text
T = U&
parameter = U&
```

or:

```text
T = U
parameter = U&&
```

---

# 104. Common Mistake — Forgetting Reference Collapsing

For:

```cpp
T = int&
```

parameter:

```cpp
T&&
```

becomes:

```cpp
int& &&
```

which collapses to:

```cpp
int&
```

This explains why forwarding references accept lvalues.

---

# 105. Common Mistake — Forwarding Without Knowing `T`

This:

```cpp
std::forward<T>(value)
```

must use the correct `T` associated with the original deduction.

Do not arbitrarily substitute another type.

The whole mechanism depends on the relationship between:

```text
T
+
T&&
+
reference collapsing
+
std::forward<T>()
```

---

# 106. Common Mistake — Forwarding a Local Variable as an Unrelated Type

Avoid:

```cpp
std::forward<SomeOtherType>(value);
```

unless the conversion is deliberately designed.

Usually use:

```cpp
std::forward<T>(value);
```

where `T` is the deduced forwarding-reference type.

---

# 107. Common Mistake — Forwarding Multiple Times

Potentially dangerous:

```cpp
target(
    std::forward<T>(value),
    std::forward<T>(value)
);
```

If the first use consumes the rvalue, the second receives a moved-from object.

---

# 108. Common Mistake — Storing a Forwarded Reference

Example:

```cpp
template<typename T>
void store(T&& value)
{
    global_reference =
        std::forward<T>(value);
}
```

This may create a dangling reference when:

```cpp
store(string("temporary"));
```

The temporary can be destroyed after the full expression.

Forwarding is not lifetime management.

---

# 109. Common Mistake — Overusing Forwarding Constructors

This:

```cpp
template<typename T>
Person(T&& value);
```

can interfere with copy/move constructors and unrelated overloads.

Prefer explicit constructors when possible.

Constrain forwarding constructors when needed.

---

# 110. Common Mistake — Assuming `emplace` Is Always Faster

Perfect forwarding helps construct objects directly, but:

```cpp
emplace_back()
```

is not universally faster than:

```cpp
push_back()
```

For an already-created object:

```cpp
v.push_back(obj);
```

may be the natural and efficient choice.

Use `emplace` when you have constructor arguments and want direct construction.

---

# 111. Common Mistake — Assuming Forwarding Prevents All Copies

It does not.

Example:

```cpp
void foo(const string&);
```

If an rvalue is forwarded:

```cpp
foo(std::forward<T>(value));
```

the target can still simply bind to a const reference.

No move necessarily occurs.

Forwarding only preserves the category.

---

# 112. Perfect Forwarding and API Design

Use perfect forwarding when:

```text
The function is generic.
The function passes arguments onward.
The exact value category matters.
You want to preserve overload resolution.
You want efficient construction.
```

Do not use it merely to make an API look advanced.

---

# 113. Best Practice — Use `std::forward<T>`

Standard pattern:

```cpp
template<typename T>
void wrapper(T&& arg)
{
    target(
        std::forward<T>(arg)
    );
}
```

---

# 114. Best Practice — Forward Every Parameter

For:

```cpp
template<typename... Args>
void wrapper(Args&&... args)
{
    target(
        std::forward<Args>(args)...
    );
}
```

Do not forward only some parameters unless that behavior is intentional.

---

# 115. Best Practice — Forward the Callable

For generic invocation:

```cpp
template<typename F, typename... Args>
decltype(auto) call(
    F&& f,
    Args&&... args
)
{
    return std::invoke(
        std::forward<F>(f),
        std::forward<Args>(args)...
    );
}
```

---

# 116. Best Practice — Use `decltype(auto)` Carefully

When returning a forwarded result:

```cpp
template<typename F, typename... Args>
decltype(auto) call(
    F&& f,
    Args&&... args
)
{
    return std::invoke(
        std::forward<F>(f),
        std::forward<Args>(args)...
    );
}
```

This preserves the exact return type of `invoke`.

But verify lifetime and ownership.

---

# 117. Best Practice — Prefer Concepts in C++20+

Instead of unconstrained templates:

```cpp
template<typename T>
void wrapper(T&& value);
```

modern library code can use concepts/requirements when appropriate.

This improves diagnostics and prevents unintended overload matches.

---

# 118. Best Practice — Keep Forwarding Wrappers Thin

A forwarding wrapper should generally:

```text
receive
→ forward
→ call target
```

Avoid modifying the argument before forwarding unless intentionally changing its semantics.

---

# 119. Best Practice — Understand Ownership Separately

Before forwarding, ask:

```text
Who owns the object?
How long does it live?
Will the target store the reference?
Will the target move from it?
```

Perfect forwarding answers:

```text
How should the argument category be preserved?
```

It does not answer ownership or lifetime questions.

---

# 120. Best Practice — Use `std::move` When You Intentionally Consume

If you own a local object and intentionally want to move from it:

```cpp
string value = "Hello";

consume(
    std::move(value)
);
```

Use `std::move`.

If you are transparently passing through a forwarding reference:

```cpp
template<typename T>
void wrapper(T&& value)
{
    consume(
        std::forward<T>(value)
    );
}
```

Use `std::forward`.

---

# 121. Complete Program 1 — Lvalue and Rvalue

```cpp
#include <iostream>
#include <utility>

using namespace std;

void foo(int&)
{
    cout << "Lvalue\n";
}

void foo(int&&)
{
    cout << "Rvalue\n";
}

template<typename T>
void wrapper(T&& value)
{
    foo(
        std::forward<T>(value)
    );
}

int main()
{
    int x = 10;

    wrapper(x);
    wrapper(20);

    return 0;
}
```

Output:

```text
Lvalue
Rvalue
```

---

# 122. Complete Program 2 — Without vs With Forwarding

```cpp
#include <iostream>
#include <utility>

using namespace std;

void show(int&)
{
    cout << "Lvalue\n";
}

void show(int&&)
{
    cout << "Rvalue\n";
}

template<typename T>
void withoutForward(T&& value)
{
    show(value);
}

template<typename T>
void withForward(T&& value)
{
    show(
        std::forward<T>(value)
    );
}

int main()
{
    cout << "Without forwarding:\n";

    withoutForward(10);

    cout << "\nWith forwarding:\n";

    withForward(10);

    return 0;
}
```

Output:

```text
Without forwarding:
Lvalue

With forwarding:
Rvalue
```

---

# 123. Complete Program 3 — Copy vs Move

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
        cout << "Copy\n";
    }

    Test(Test&&)
    {
        cout << "Move\n";
    }
};

template<typename T>
void create(T&& obj)
{
    Test t(
        std::forward<T>(obj)
    );
}

int main()
{
    Test a;

    create(a);

    create(Test{});

    return 0;
}
```

Typical output:

```text
Constructor
Copy
Constructor
Move
```

---

# 124. Complete Program 4 — Variadic Forwarding

```cpp
#include <iostream>
#include <utility>

using namespace std;

void print(int x)
{
    cout << "int: " << x << '\n';
}

void print(const string& s)
{
    cout << "string: " << s << '\n';
}

template<typename... Args>
void wrapper(Args&&... args)
{
    (
        print(
            std::forward<Args>(args)
        ),
        ...
    );
}

int main()
{
    string s = "Hello";

    wrapper(
        10,
        s,
        string("World")
    );

    return 0;
}
```

---

# 125. Complete Program 5 — Generic Factory

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <utility>

using namespace std;

template<typename T, typename... Args>
unique_ptr<T> create(
    Args&&... args
)
{
    return make_unique<T>(
        std::forward<Args>(args)...
    );
}

int main()
{
    auto p =
        create<string>(
            "Hello World"
        );

    cout << *p;

    return 0;
}
```

Output:

```text
Hello World
```

---

# 126. Complete Program 6 — Generic Invocation

```cpp
#include <functional>
#include <iostream>
#include <utility>

using namespace std;

template<typename F, typename... Args>
decltype(auto) call(
    F&& f,
    Args&&... args
)
{
    return std::invoke(
        std::forward<F>(f),
        std::forward<Args>(args)...
    );
}

int add(int a, int b)
{
    return a + b;
}

int main()
{
    cout << call(
        add,
        10,
        20
    );

    return 0;
}
```

Output:

```text
30
```

---

# 127. Complete Program 7 — Stateful Callable

```cpp
#include <iostream>
#include <utility>

using namespace std;

class Counter
{
    int value = 0;

public:

    void operator()()
    {
        ++value;

        cout << value << '\n';
    }
};

template<typename F>
void invokeTwice(F&& f)
{
    std::forward<F>(f)();
    std::forward<F>(f)();
}

int main()
{
    Counter c;

    invokeTwice(c);

    return 0;
}
```

For stateful callables, be careful about whether forwarding an rvalue callable twice is semantically appropriate. Forwarding preserves the category; it does not guarantee that repeated consumption is safe.

---

# 128. Complete Program 8 — `emplace_back`

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:

    string name;
    int age;

    Person(
        string n,
        int a
    )
        : name(std::move(n)),
          age(a)
    {
    }
};

int main()
{
    vector<Person> people;

    people.emplace_back(
        "Alice",
        25
    );

    people.emplace_back(
        "Bob",
        30
    );

    for (const auto& person : people)
    {
        cout
            << person.name
            << " "
            << person.age
            << '\n';
    }

    return 0;
}
```

---

# 129. Perfect Forwarding Flow

For:

```cpp
wrapper(x);
```

where `x` is an lvalue:

```text
Caller
  |
  | x
  ↓
T = U&
  |
  ↓
parameter T&&
  |
  ↓
U& && 
  |
  ↓
U&
  |
  ↓
std::forward<T>(value)
  |
  ↓
U&
  |
  ↓
target receives lvalue
```

---

# 130. Perfect Forwarding Flow for Rvalue

For:

```cpp
wrapper(U{});
```

```text
Caller
  |
  | rvalue
  ↓
T = U
  |
  ↓
parameter T&&
  |
  ↓
U&&
  |
  ↓
named parameter expression is lvalue
  |
  ↓
std::forward<T>(value)
  |
  ↓
U&&
  |
  ↓
target receives rvalue
```

This is the heart of perfect forwarding.

---

# 131. The Four Main Pieces

Perfect forwarding depends on four concepts:

```text
1. Forwarding reference
       ↓
2. Template type deduction
       ↓
3. Reference collapsing
       ↓
4. std::forward<T>()
```

If you understand these four, you understand the core of perfect forwarding.

---

# 132. `std::move` Mental Model

Think:

```cpp
std::move(x)
```

as:

```text
"I explicitly allow x to be treated as an rvalue."
```

It does not preserve whether `x` originally was an lvalue.

---

# 133. `std::forward` Mental Model

Think:

```cpp
std::forward<T>(x)
```

as:

```text
"Give x back to the next function in the same value category in which it entered this forwarding function."
```

That is the most useful mental model.

---

# 134. Quick Comparison

| Code | Meaning |
|---|---|
| `x` | Normal expression; if named variable, it is an lvalue |
| `std::move(x)` | Treat `x` as an rvalue/xvalue |
| `std::forward<T>(x)` | Preserve category represented by `T` |
| `T&&` with deduced `T` | Forwarding reference |
| `const T&&` | Not the standard forwarding-reference pattern |

---

# 135. Quick Deduction Table

For:

```cpp
template<typename T>
void f(T&& arg);
```

| Call | Deduced `T` | Parameter Type | Forwarded Category |
|---|---|---|---|
| `int x; f(x)` | `int&` | `int&` | lvalue |
| `f(10)` | `int` | `int&&` | rvalue |
| `const int x; f(x)` | `const int&` | `const int&` | const lvalue |
| `f(std::move(x))` | `int` | `int&&` | rvalue |
| `const int x; f(std::move(x))` | `const int` | `const int&&` | const rvalue |

---

# 136. Quick Reference-Collapsing Table

```text
T = U&
T&& = U& && = U&

T = U
T&& = U&&
```

Rules:

```text
&  &   → &
&  &&  → &
&& &   → &
&& &&  → &&
```

---

# 137. `std::move` vs `std::forward` Example

```cpp
string s = "Hello";

void consume(string&&);
void consume(string&);

template<typename T>
void wrapper(T&& value)
{
    consume(
        std::forward<T>(value)
    );
}
```

Call:

```cpp
wrapper(s);
```

Result:

```text
string&
```

Call:

```cpp
wrapper(string("Hello"));
```

Result:

```text
string&&
```

If the wrapper instead used:

```cpp
std::move(value)
```

both calls would be treated as rvalues.

---

# 138. Perfect Forwarding Checklist

When writing a forwarding wrapper, check:

```text
[ ] Is T deduced?
[ ] Is the parameter T&&?
[ ] Is the parameter a forwarding reference?
[ ] Is std::forward<T>() used?
[ ] Is the correct T forwarded?
[ ] Are all parameter packs forwarded?
[ ] Is object lifetime safe?
[ ] Could the target consume the rvalue?
[ ] Could forwarding create overload surprises?
[ ] Does the function need constraints?
```

---

# 139. Interview Questions

## Q1. What is perfect forwarding?

Perfect forwarding is a technique for passing function arguments through a generic function while preserving their original value categories and relevant type qualifiers.

---

## Q2. Which function is used for perfect forwarding?

```cpp
std::forward
```

Header:

```cpp
#include <utility>
```

---

## Q3. What is a forwarding reference?

A `T&&` parameter where `T` is a deduced template parameter.

Example:

```cpp
template<typename T>
void f(T&& value);
```

---

## Q4. Is every `T&&` a forwarding reference?

No.

It must be a deduced template parameter in the appropriate form.

This:

```cpp
void f(int&&);
```

is an ordinary rvalue reference.

---

## Q5. What happens when an lvalue is passed to `T&&`?

For:

```cpp
int x;

f(x);
```

deduction gives:

```text
T = int&
```

and:

```text
T&& → int& && → int&
```

---

## Q6. What happens when an rvalue is passed?

```cpp
f(10);
```

gives:

```text
T = int
T&& = int&&
```

---

## Q7. Why is `std::forward` necessary?

Because a named function parameter is an lvalue expression even if its type is an rvalue reference.

`std::forward` restores the original category.

---

## Q8. Difference between `std::move` and `std::forward`?

```text
move     → explicitly cast to rvalue/xvalue
forward  → preserve the category represented by T
```

---

## Q9. Does `std::forward` perform a move?

No.

It is a conditional cast.

A later operation may perform a move.

---

## Q10. What is reference collapsing?

Rules that determine the resulting reference type when references combine.

```text
&  &   → &
&  &&  → &
&& &   → &
&& &&  → &&
```

---

## Q11. Why are forwarding references useful?

They allow one generic function to accept both lvalues and rvalues while preserving their categories.

---

## Q12. Where is perfect forwarding commonly used?

Examples:

```text
emplace()
emplace_back()
make_unique()
make_shared()
make_pair()
make_tuple()
optional::emplace()
variant::emplace()
generic factories
generic wrappers
generic invocation
```

---

## Q13. Can perfect forwarding prevent all copies?

No.

It prevents unnecessary copies introduced by forwarding layers when possible, but the target operation may still copy or move.

---

## Q14. Does `std::forward` always produce an rvalue?

No.

If:

```text
T = U&
```

then:

```cpp
std::forward<T>(x)
```

produces an lvalue.

If:

```text
T = U
```

it produces an rvalue.

---

## Q15. Why should you not use `std::move` in a transparent wrapper?

Because it converts lvalue arguments into rvalues and changes their original semantics.

---

## Q16. What header contains `std::forward`?

```cpp
#include <utility>
```

---

## Q17. What is the main pattern?

```cpp
template<typename T>
void wrapper(T&& value)
{
    target(
        std::forward<T>(value)
    );
}
```

---

# 140. Interview Question — Explain the Complete Flow

Question:

> What happens when `wrapper(x)` is called?

Given:

```cpp
template<typename T>
void wrapper(T&& x)
{
    foo(std::forward<T>(x));
}
```

and:

```cpp
int value = 10;

wrapper(value);
```

Answer:

```text
1. value is an lvalue.
2. T is deduced as int&.
3. Parameter T&& becomes int& &&.
4. Reference collapsing makes it int&.
5. x is a named variable, so x is an lvalue expression.
6. std::forward<T>(x) restores the lvalue category.
7. foo receives int&.
```

For:

```cpp
wrapper(10);
```

the flow is:

```text
1. 10 is an rvalue.
2. T is deduced as int.
3. Parameter becomes int&&.
4. x is still an lvalue expression because it is named.
5. std::forward<int>(x) casts it back to int&&.
6. foo receives an rvalue.
```

---

# 141. Important Headers

Perfect forwarding itself:

```cpp
#include <utility>
```

Type traits:

```cpp
#include <type_traits>
```

Generic invocation:

```cpp
#include <functional>
```

Smart pointers:

```cpp
#include <memory>
```

Containers:

```cpp
#include <vector>
#include <list>
#include <map>
#include <set>
```

Threads:

```cpp
#include <thread>
```

---

# 142. Real-World Uses

Perfect forwarding is especially useful in:

- Generic wrapper functions
- Factory functions
- Dependency injection
- Generic libraries
- Container `emplace` functions
- Smart-pointer factories
- Generic callable wrappers
- Tuple/pair construction
- Thread argument handling
- High-performance libraries
- Template metaprogramming
- Generic object construction

---

# 143. Perfect Forwarding Architecture

```text
Caller
  |
  | argument
  ↓
Forwarding Reference
  |
  ↓
Template Type Deduction
  |
  ↓
Reference Collapsing
  |
  ↓
std::forward<T>()
  |
  ↓
Target Function / Constructor
  |
  ↓
Correct overload
```

---

# 144. Perfect Forwarding vs Move Semantics

Move semantics:

```text
Object
  |
std::move()
  |
rvalue/xvalue
  |
move constructor / move assignment
```

Perfect forwarding:

```text
Caller
  |
lvalue or rvalue
  |
T&&
  |
std::forward<T>()
  |
same category
```

They work together but solve different problems.

---

# 145. The Most Important Rules

Remember these:

### Rule 1

```cpp
T&&
```

with deduced `T` can be a forwarding reference.

### Rule 2

For lvalue:

```text
T = U&
```

### Rule 3

For rvalue:

```text
T = U
```

### Rule 4

Named variables are lvalues.

### Rule 5

Use:

```cpp
std::forward<T>(value)
```

to restore the original category.

### Rule 6

`std::move` does not preserve the original category.

### Rule 7

Forwarding does not manage lifetime.

### Rule 8

Forwarding an rvalue multiple times may repeatedly expose a moved-from object.

---

# 146. One-Line Definition

> **Perfect forwarding is the technique of forwarding a function argument through a generic interface while preserving its original value category using a forwarding reference and `std::forward`.**

---

# 147. Final Summary

Perfect forwarding is one of the foundations of modern C++ generic programming.

The standard pattern is:

```cpp
template<typename T>
void wrapper(T&& value)
{
    target(
        std::forward<T>(value)
    );
}
```

The mechanism depends on:

```text
Forwarding Reference
        +
Template Type Deduction
        +
Reference Collapsing
        +
std::forward<T>()
```

For an lvalue:

```text
T = U&
T&& = U&
forward<T>() = U&
```

For an rvalue:

```text
T = U
T&& = U&&
forward<T>() = U&&
```

The critical difference is:

```cpp
std::move(x)
```

means:

```text
Treat x as an rvalue.
```

while:

```cpp
std::forward<T>(x)
```

means:

```text
Treat x according to the value category represented by T.
```

`std::forward` itself does not:

```text
allocate memory
copy objects
move resources
```

It is effectively a compile-time cast. The eventual target operation determines whether a copy, move, construction, or other operation occurs.

Perfect forwarding is widely used by modern C++ library facilities such as:

```text
emplace
make_unique
make_shared
make_pair
make_tuple
optional::emplace
variant::emplace
thread
generic invocation
factory functions
```

However, perfect forwarding should be used carefully. Always consider:

```text
value category
type deduction
reference collapsing
overload resolution
object lifetime
ownership
moved-from state
constructor behavior
```

The most important mental model is:

```text
std::move
    ↓
"I want this expression treated as movable."

std::forward<T>
    ↓
"Pass this expression onward with the category represented by T."
```

And the most important code to remember is:

```cpp
template<typename T>
void wrapper(T&& arg)
{
    target(
        std::forward<T>(arg)
    );
}
```

## Quick Revision

```text
Header:
    <utility>

Main function:
    std::forward<T>()

Forwarding reference:
    T&&

Lvalue:
    T = U&

Rvalue:
    T = U

Named parameter:
    always an lvalue expression

Reference collapsing:
    &  &   → &
    &  &&  → &
    && &   → &
    && &&  → &&

std::move:
    forces rvalue/xvalue treatment

std::forward:
    preserves category represented by T

Main uses:
    generic wrappers
    factories
    emplace
    smart-pointer factories
    generic invocation

Complexity:
    O(1)

Allocation:
    None by std::forward itself

Main warning:
    Perfect forwarding preserves value category,
    not object lifetime.
```
