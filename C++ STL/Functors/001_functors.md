# C++ Functors (Function Objects) — Complete Notes

## 1. What is a Functor?

A **Functor**, also called a **Function Object**, is an object that can be used like a function.

A class becomes callable like a function by overloading the **function-call operator**:

```cpp
operator()
```

Example:

```cpp
class Add
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};
```

Create an object:

```cpp
Add obj;
```

Call it like a function:

```cpp
cout << obj(10, 20);
```

Output: `30`

Conceptually:

```cpp
obj(10, 20);
```

means:

```cpp
obj.operator()(10, 20);
```

---

# 2. Why is it Called a Function Object?

Normally, a function is called like:

```cpp
add(10, 20);
```

A functor is an object:

```cpp
Add obj;
```

but the object can be called:

```cpp
obj(10, 20);
```

Therefore:

```text
Object
  +
operator()
  =
Function-like Object
```

---

# 3. Basic Syntax

```cpp
class ClassName {
public:
    ReturnType operator()(parameters)
    {
        // implementation
    }
};
```

Example:

```cpp
class Square
{
public:

    int operator()(int x)
    {
        return x * x;
    }
};
```

Usage:

```cpp
Square sq;

cout << sq(5);
```

Output:

```text
25
```

---

# 4. How `operator()` Works

Consider:

```cpp
Square sq;

sq(5);
```

The compiler treats the call conceptually as:

```cpp
sq.operator()(5);
```

The function-call operator is one of C++'s overloaded operators.

Unlike operators such as:

```cpp
+
-
*
==
<
```

`operator()` allows an object to be invoked using function-call syntax.

---

# 5. Simple Functor Example

```cpp
#include <iostream>

using namespace std;

class Square
{
public:

    int operator()(int x)
    {
        return x * x;
    }
};

int main()
{
    Square sq;

    cout << sq(5);

    return 0;
}
```

Output:

```text
25
```

---

# 6. Functor vs Normal Function

## Normal Function

```cpp
int add(int a, int b)
{
    return a + b;
}
```

Usage:

```cpp
cout << add(5, 6);
```

---

## Functor

```cpp
class Add
{
public:

    int operator()(int a, int b)
    {
        return a + b;
    }
};
```

Usage:

```cpp
Add obj;

cout << obj(5, 6);
```

Both produce the same result, but the functor is an object and can contain state.

---

# 7. Function Pointer vs Functor

## Function Pointer

```cpp
int square(int x)
{
    return x * x;
}

int (*ptr)(int) = square;

cout << ptr(5);
```

A function pointer stores the address of a function.

---

## Functor

```cpp
class Square
{
public:

    int operator()(int x)
    {
        return x * x;
    }
};

Square obj;

cout << obj(5);
```

The functor is an object that contains callable behavior.

---

# 8. Main Difference

| Feature | Function | Function Pointer | Functor |
|---|---|---|---|
| Callable | Yes | Yes | Yes |
| Is an object | No | No | Yes |
| Stores state | Not naturally | No | Yes |
| Member variables | No | No | Yes |
| Constructor | No | No | Yes |
| Multiple `operator()` overloads | No | No | Yes |
| Can inherit | No | No | Yes |
| Can be templated | Through templates | Through types/templates | Yes |
| Reusable behavior | Yes | Yes | Yes |
| STL-friendly | Yes | Yes | Yes |

---

# 9. Why Use Functors?

Functors are useful because they can combine: `Data + Behavior` inside one object.

A functor can:
- Store state
- Remember previous calls
- Have member variables
- Have constructors
- Accept configuration
- Be passed to algorithms
- Provide overloaded call operators
- Be templated
- Inherit from other classes
- Be copied or moved
- Work naturally with STL algorithms

---

# 10. Functor with Member Variables

A functor can store data.

Example:

```cpp
#include <iostream>
using namespace std;

class Multiplier {
    int factor;
  public:

    Multiplier(int x)
    {
        factor = x;
    }

    int operator()(int value)
    {
        return value * factor;
    }
};

int main()
{
    Multiplier triple(3);

    cout << triple(10);

    return 0;
}
```

Output: `30`

The object contains:

```text
factor = 3
```

So:

```cpp
triple(10)
```

uses the stored state.

---

# 11. Stateful Functor

A **stateful functor** stores information that can change between calls.

Example:

```cpp
#include <iostream>
using namespace std;

class Counter
{
    int count;

public:

    Counter(): count(0)
    {
    }

    void operator()()
    {
        ++count;

        cout << "Called " << count << " times\n";
    }
};

int main()
{
    Counter c;

    c();
    c();
    c();

    return 0;
}
```

Output:

```text
Called 1 times
Called 2 times
Called 3 times
```

The same object maintains:

```text
count = 1
count = 2
count = 3
```

across calls.

---

# 12. Stateful vs Stateless Functor

## Stateless

```cpp
class Square
{
public:
    int operator()(int x) const
    {
        return x * x;
    }
};
```

The object does not need to store changing state.

---

## Stateful

```cpp
class Counter
{
    int count = 0;

public:
    void operator()()
    {
        ++count;
    }
};
```

The object maintains state.

---

# 13. `const operator()`

A functor can make its call operator `const`:

```cpp
class Counter {
    int count = 0;

public:
    bool operator()(int x) {
        count++;       // modifies object
        return x > 10;
    }
};
```

```cpp
bool operator()(int x) const {
    count++; // ❌ cannot modify count
}
```

```cpp
class Square
{
public:

    int operator()(int x) const
    {
        return x * x;
    }
};
```

The `const` means that calling the functor through a const object cannot modify the object's non-mutable data members.

Example:

```cpp
const Square sq;

cout << sq(5);
```

This is valid because:

```cpp
operator() const
```

can be called on a const object.

---

# 14. Why `const` Functors Are Useful

Many algorithms can work with callable objects as const objects.

A stateless or logically immutable functor often uses:

```cpp
operator()(...) const
```

This communicates:

```text
Calling this object does not modify its observable state.
```

---

# 15. Mutable State in a Const Functor
- **Important exception:** const on operator() does not mean the entire object can never change.
- `mutable int count` So mutable specifically says: “This member is allowed to change even when the object is const.”

A data member declared:

```cpp
mutable
```

can be modified even from a const member function.

Example:

```cpp
#include <iostream>
using namespace std;

class Counter
{
    mutable int count;

public:

    Counter(): count(0)
    {
    }

    void operator()() const
    {
        ++count;

        cout << count << "\n";
    }
};

int main()
{
    const Counter c;

    c();
    c();
    c();

    return 0;
}
```

Output:

```text
1
2
3
```

This is useful for logically const operations that maintain internal bookkeeping.

---

# 16. Overloading `operator()`

A functor can have multiple overloads of `operator()`.

Example:

```cpp
#include <iostream>
#include <string>

using namespace std;

class Print
{
public:

    void operator()()
    {
        cout << "Hello\n";
    }

    void operator()(int x)
    {
        cout << x << "\n";
    }

    void operator()(const string& s)
    {
        cout << s << "\n";
    }
};

int main()
{
    Print p;

    p();
    p(100);
    p("Programming");

    return 0;
}
```

Output:

```text
Hello
100
Programming
```

The compiler selects the appropriate overload based on the arguments.

---

# 17. Functor Returning a Value

```cpp
class Cube
{
public:

    int operator()(int x) const
    {
        return x * x * x;
    }
};
```

Usage:

```cpp
Cube cube;

cout << cube(3);
```

Output:

```text
27
```

---

# 18. Generic Functor Using Templates

Functors can be class templates.

```cpp
#include <iostream>
using namespace std;

template<typename T>
class Add
{
public:

    T operator()(T a, T b) const
    {
        return a + b;
    }
};

int main()
{
    Add<int> a;

    cout << a(10, 20) << endl;

    Add<double> b;

    cout << b(5.5, 4.5) << endl;

    return 0;
}
```

Output:

```text
30
10
```

---

# 19. Generic `operator()` Functor

The class itself does not have to be a template.

The call operator can be templated:

```cpp
class Add
{
public:

    template<typename T>
    T operator()(T a, T b) const
    {
        return a + b;
    }
};
```

Usage:

```cpp
Add add;

cout << add(10, 20) << endl;
cout << add(2.5, 3.5) << endl;
```

This allows one functor object to work with multiple types.

---

# 20. Functor with Different Return Type

A functor can return any appropriate type.

```cpp
class IsEven
{
public:

    bool operator()(int x) const
    {
        return x % 2 == 0;
    }
};
```

Usage:

```cpp
IsEven check;

if (check(10))
{
    cout << "Even";
}
```

---

# 21. Functor as Predicate

A **predicate** is a callable that returns a boolean result and is commonly used to test a condition.

Example:

```cpp
class IsEven
{
public:

    bool operator()(int x) const
    {
        return x % 2 == 0;
    }
};
```

Usage:

```cpp
IsEven predicate;

cout << predicate(10);
```

Result:

```text
true
```

Predicates are heavily used with STL algorithms.

---

# 22. Unary and Binary Functors

## Unary Functor

A unary functor accepts one main argument.

```cpp
class Square
{
public:

    int operator()(int x) const
    {
        return x * x;
    }
};
```

---

## Binary Functor

A binary functor accepts two arguments.

```cpp
class Add
{
public:

    int operator()(int a, int b) const
    {
        return a + b;
    }
};
```

---

# 23. Functor with `std::sort`

STL algorithms can receive callable objects.

Example:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Descending
{
public:
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

int main()
{
    vector<int> v = {5, 1, 8, 3, 9};

    sort(v.begin(), v.end(), Descending());

    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
9 8 5 3 1
```

The comparator tells `sort()`:

```text
a should appear before b
if a > b
```

---

# 24. Passing a Named Functor to `sort()`

Instead of creating a temporary:

```cpp
sort(v.begin(), v.end(), Descending());
```

you can create an object:

```cpp
Descending compare;

sort(v.begin(), v.end(), compare);
```

Both are valid.



### Custom Sorting:
```cpp
#include <iostream>
#include <vector>
using namespace std;

class Ascending
{
public:
    bool operator()(int a, int b) const
    {
        return a < b;
    }
};

class Descending
{
public:
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

template <typename Iterator, typename Compare = Ascending>
void mySort(Iterator first, Iterator last, Compare comp = Compare{})
{
    for (auto i = first; i != last; ++i)
    {
        for (auto j = i + 1; j != last; ++j)
        {
            if (comp(*j, *i))
            {
                swap(*i, *j);
            }
        }
    }
}

int main()
{
    vector<int> v = {5, 1, 8, 3, 9};

    // Default → Ascending
    mySort(v.begin(), v.end());

    for (int x : v)
        cout << x << " ";

    return 0;
}
```

---

# 25. Stateful Comparator

A functor can contain configuration.

Example:

```cpp
class CompareByFactor
{
    int factor;

public:

    CompareByFactor(int f)
        : factor(f)
    {
    }

    bool operator()(int a, int b) const
    {
        return (a * factor) < (b * factor);
    }
};
```

Usage:

```cpp
CompareByFactor compare(1);

sort(v.begin(), v.end(), compare);
```

This demonstrates why callable objects can be useful when behavior needs configuration.

---

# 26. Functor with `for_each()`

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Display
{
public:

    void operator()(int x) const
    {
        cout << x << " ";
    }
};

int main()
{
    vector<int> v = {10, 20, 30, 40};

    for_each(v.begin(), v.end(), Display());

    return 0;
}
```

Output:

```text
10 20 30 40
```

---

# 27. Functor Counting Elements

A functor can keep state while an algorithm invokes it.

Example:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class CountEven
{
public:

    int count = 0;

    void operator()(int x)
    {
        if (x % 2 == 0)
        {
            ++count;
        }
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};

    CountEven obj;

    obj = for_each(v.begin(), v.end(), obj);

    cout << obj.count;

    return 0;
}
```

Output:

```text
3
```

## Important Point

`std::for_each()` returns the callable object after applying it to the elements.

That makes it possible to retrieve state from a stateful functor.

---

# 28. Why Does `for_each()` Return the Functor?

Consider:

```cpp
CountEven obj;

obj = for_each(v.begin(), v.end(), obj);
```

Conceptually:

```text
obj
 ↓
algorithm calls obj(element)
 ↓
obj.count changes
 ↓
algorithm returns the callable
 ↓
obj receives the returned state
```

This is useful when the callable stores accumulated information.

---

# 29. Functor with `count_if()`

Example:

```cpp
class IsEven
{
public:

    bool operator()(int x) const
    {
        return x % 2 == 0;
    }
};
```

Use:

```cpp
int count = count_if(
    v.begin(),
    v.end(),
    IsEven()
);
```

If:

```text
v = {1, 2, 3, 4, 5, 6}
```

then:

```text
count = 3
```

---

# 30. Functor with `find_if()`

```cpp
class IsGreaterThan10
{
public:

    bool operator()(int x) const
    {
        return x > 10;
    }
};
```

Use:

```cpp
auto it = find_if(v.begin(), v.end(), IsGreaterThan10());
```

If found:

```cpp
if (it != v.end())
{
    cout << *it;
}
```

---

# 31. Functor with `remove_if()`

```cpp
class IsEven
{
public:

    bool operator()(int x) const
    {
        return x % 2 == 0;
    }
};
```

Usage:

```cpp
v.erase(remove_if(v.begin(), v.end(), IsEven()),v.end());
```

This is the traditional erase-remove idiom for a vector.

In C++20, the simpler form is:

```cpp
std::erase_if(v, IsEven());
```

---

# 32. Functor with `transform()`

Example:

```cpp
class Square
{
public:

    int operator()(int x) const
    {
        return x * x;
    }
};
```

Use:

```cpp
vector<int> result(v.size());

transform(
    v.begin(),
    v.end(),
    result.begin(),
    Square()
);
```

If:

```text
v = {1, 2, 3, 4}
```

then:

```text
result = {1, 4, 9, 16}
```

---

# 33. Functor with `partition()`

```cpp
class IsEven
{
public:

    bool operator()(int x) const
    {
        return x % 2 == 0;
    }
};
```

Use:

```cpp
partition(
    v.begin(),
    v.end(),
    IsEven()
);
```

The algorithm rearranges the range so that elements satisfying the predicate come before elements that do not.

---

# 34. Common STL Algorithms Using Callables

Examples include:

```text
sort()
stable_sort()

for_each()
for_each_n()

count_if()
find_if()

remove_if()
replace_if()

transform()

partition()
stable_partition()

all_of()
any_of()
none_of()
```

The callable can be:

```text
Function
Function pointer
Functor
Lambda
Other callable object
```

---

# 35. STL Containers and Comparators

Functors are also useful with ordered associative containers such as:

```cpp
std::set
std::map
std::multiset
std::multimap
```

Example:

```cpp
#include <functional>
#include <set>

std::set<int, std::greater<int>> s;
```

This creates a set ordered using:

```cpp
std::greater<int>
```

---

# 36. Custom Comparator for `set`

```cpp
class Descending
{
public:
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

std::set<int, Descending> s;
```

The set uses the functor to determine its ordering.

---

# 37. Custom Comparator for `map`

Example:

```cpp
class Descending
{
public:

    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

std::map<int, string, Descending> m;
```

The keys are ordered according to the comparator.

---

# 38. Predefined STL Function Objects

The C++ Standard Library provides many function objects in:

```cpp
#include <functional>
```

Important examples:

```cpp
std::less
std::greater

std::equal_to
std::not_equal_to

std::less_equal
std::greater_equal

std::plus
std::minus
std::multiplies
std::divides
std::modulus
std::negate

std::logical_and
std::logical_or
std::logical_not
```

---

# 39. `std::greater`

Example:

```cpp
std::greater<int>()(10, 5);
```

Result:

```text
true
```

Used for descending sort:

```cpp
sort(v.begin(), v.end(), std::greater<int>());
```

---

# 40. `std::less`

```cpp
std::less<int>()(5, 10);
```

Result:

```text
true
```

Commonly used for ascending ordering:

```cpp
sort(v.begin(), v.end(), std::less<int>());
```

---

# 41. `std::plus`

```cpp
std::plus<int>()(10, 20);
```

Result:

```text
30
```

Equivalent conceptually to:

```cpp
10 + 20
```

---

# 42. `std::minus`

```cpp
std::minus<int>()(20, 5);
```

Result:

```text
15
```

---

# 43. `std::multiplies`

```cpp
std::multiplies<int>()(4, 5);
```

Result:

```text
20
```

---

# 44. `std::divides`

```cpp
std::divides<int>()(20, 5);
```

Result:

```text
4
```

---

# 45. `std::modulus`

```cpp
std::modulus<int>()(20, 6);
```

Result:

```text
2
```

---

# 46. `std::negate`

```cpp
std::negate<int>()(10);
```

Result:

```text
-10
```

---

# 47. `std::equal_to`

```cpp
std::equal_to<int>()(5, 5);
```

Result:

```text
true
```

---

# 48. `std::not_equal_to`

```cpp
std::not_equal_to<int>()(5, 7);
```

Result:

```text
true
```

---

# 49. `std::greater_equal`

```cpp
std::greater_equal<int>()(5, 5);
```

Result:

```text
true
```

---

# 50. `std::less_equal`

```cpp
std::less_equal<int>()(5, 7);
```

Result:

```text
true
```

---

# 51. `std::logical_and`

```cpp
std::logical_and<bool>()(true, false);
```

Result:

```text
false
```

---

# 52. `std::logical_or`

```cpp
std::logical_or<bool>()(true, false);
```

Result:

```text
true
```

---

# 53. `std::logical_not`

```cpp
std::logical_not<bool>()(true);
```

Result:

```text
false
```

---

# 54. Predefined Function Object Summary

| Functor | Operation |
|---|---|
| `std::plus<T>` | `a + b` |
| `std::minus<T>` | `a - b` |
| `std::multiplies<T>` | `a * b` |
| `std::divides<T>` | `a / b` |
| `std::modulus<T>` | `a % b` |
| `std::negate<T>` | `-a` |
| `std::equal_to<T>` | `a == b` |
| `std::not_equal_to<T>` | `a != b` |
| `std::greater<T>` | `a > b` |
| `std::less<T>` | `a < b` |
| `std::greater_equal<T>` | `a >= b` |
| `std::less_equal<T>` | `a <= b` |
| `std::logical_and<T>` | `a && b` |
| `std::logical_or<T>` | `a \|\| b` |
| `std::logical_not<T>` | `!a` |

Header:

```cpp
#include <functional>
```

---

# 55. Transparent Comparators

Modern standard-library comparison function objects can be used without explicitly specifying the type.

For example:

```cpp
std::greater<>
```

instead of:

```cpp
std::greater<int>
```

Example:

```cpp
sort(v.begin(), v.end(), std::greater<>());
```

The transparent form can work with different compatible argument types.

This is particularly useful with heterogeneous comparisons.

---

# 56. Functor vs Lambda

A lambda is another way to create a callable object.

Functor:

```cpp
class Compare
{
public:

    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

sort(v.begin(), v.end(), Compare());
```

Lambda:

```cpp
sort(
    v.begin(),
    v.end(),
    [](int a, int b)
    {
        return a > b;
    }
);
```

For small one-off operations, lambdas are usually shorter.

For reusable or more complex callable behavior, a named functor type can be clearer.

---

# 57. Are Lambdas Functors?

A lambda expression creates a unique **closure object** of an unnamed class type.

Conceptually, that closure type provides an appropriate:

```cpp
operator()
```

Therefore, a lambda behaves like a function object.

Example:

```cpp
auto square = [](int x)
{
    return x * x;
};
```

Conceptually:

```text
lambda expression
       ↓
unnamed closure type
       ↓
closure object
       ↓
operator()
```

It is more precise to say:

```text
A lambda expression creates a closure object.
```

That closure object is function-object-like and callable.

---

# 58. Lambda State vs Functor State

Functor:

```cpp
class Multiplier
{
    int factor;

public:

    Multiplier(int f)
        : factor(f)
    {
    }

    int operator()(int x) const
    {
        return x * factor;
    }
};
```

Lambda with captured state:

```cpp
int factor = 3;

auto multiplier = [factor](int x)
{
    return x * factor;
};
```

Both can carry state.

The difference is mainly in how the callable type is expressed and managed.

---

# 59. Functor with Constructor

A functor can have a constructor to configure its behavior.

```cpp
class Multiply
{
    int factor;

public:
    Multiply(int f): factor(f) {}

    int operator()(int x) const
    {
        return x * factor;
    }
};
```

Usage:

```cpp
Multiply triple(3);

cout << triple(10);
```

Output: `30`

---

# 60. Functor with Multiple Constructors

Because a functor is a class, it can have overloaded constructors.

```cpp
class Multiplier
{
    int factor;

public:

    Multiplier(): factor(1)
    {
    }

    Multiplier(int f) : factor(f)
    {
    }

    int operator()(int x) const
    {
        return x * factor;
    }
};
```

Usage:

```cpp
Multiplier a;
Multiplier b(5);
```

---

# 61. Functor with Inheritance

A functor is a normal class and can participate in inheritance.

```cpp
class Base
{
public:

    virtual int operator()(int x) const
    {
        return x;
    }

    virtual ~Base() = default;
};

class Square : public Base
{
public:

    int operator()(int x) const override
    {
        return x * x;
    }
};
```

Usage:

```cpp
Square sq;

cout << sq(5);
```

Output:

```text
25
```

However, virtual dispatch is not usually needed for simple STL comparator/predicate functors.

---

# 62. Polymorphic Functors

Callable behavior can be polymorphic.

```cpp
class Operation
{
public:

    virtual int operator()(int a, int b) const = 0;

    virtual ~Operation() = default;
};

class Add : public Operation
{
public:

    int operator()(int a, int b) const override
    {
        return a + b;
    }
};

class Multiply : public Operation
{
public:

    int operator()(int a, int b) const override
    {
        return a * b;
    }
};
```

This allows different callable objects to implement the same interface.

---

# 63. Functor and `std::function`

A functor can be stored in `std::function`.

```cpp
#include <functional>

class Square
{
public:

    int operator()(int x) const
    {
        return x * x;
    }
};

std::function<int(int)> operation = Square();

cout << operation(5);
```

Output: `25`

`std::function` provides a type-erased wrapper for callable objects.

---

# 64. `std::function` vs Functor

Functor:

```cpp
Square sq;

sq(5);
```

Concrete type:

```text
Square
```

`std::function`:

```cpp
std::function<int(int)> f = Square();

f(5);
```

Type:

```text
std::function<int(int)>
```

`std::function` can hold different compatible callable types, such as:

```text
Function pointer
Functor
Lambda
Bind expression
```

The trade-off is that type erasure can introduce overhead compared with directly invoking a concrete functor type.

---

# 65. Functor as a Callback

A functor can be passed to another function.

```cpp
template<typename Func>
void execute(Func f)
{
    cout << f(10);
}
```

Call:

```cpp
Square sq;

execute(sq);
```

Output:

```text
100
```

This is a common generic-programming pattern.

---

# 66. Generic Algorithm with a Functor

```cpp
template<typename Container, typename Function>
void process(const Container& c, Function f)
{
    for (const auto& value : c)
    {
        f(value);
    }
}
```

Usage:

```cpp
class Display
{
public:

    void operator()(int x) const
    {
        cout << x << " ";
    }
};

vector<int> v = {1, 2, 3};

process(v, Display());
```

Output:

```text
1 2 3
```

This demonstrates how templates can accept arbitrary callable objects.

---

# 67. Passing Functor by Value

STL algorithms commonly receive callable objects by value.

Example:

```cpp
sort(v.begin(), v.end(), Compare());
```

The algorithm receives a copy/moved callable object according to its implementation and requirements.

For stateless functors, this is normally inexpensive.

---

# 68. Stateful Functors and Copies

When a functor stores state, understand copying behavior.

Example:

```cpp
class Counter
{
public:

    int count = 0;

    void operator()(int)
    {
        ++count;
    }
};
```

If the algorithm receives a copy of the functor, modifying that copy does not automatically modify the original.

This is why algorithms such as `for_each()` returning the callable are useful when you want to retrieve accumulated state.

---

# 69. `std::ref` with Stateful Functors

If you intentionally want an algorithm to operate on the same functor object, you can use `std::ref()`.

```cpp
#include <functional>

CountEven counter;

for_each(v.begin(), v.end(), std::ref(counter));
```

Now the algorithm receives a reference wrapper referring to the original object.

Afterward:

```cpp
cout << counter.count;
```

contains the updated state.

---

# 70. Functor and `std::ref`

`std::ref()` is useful when a callable should not be copied.

Example:

```cpp
Counter counter;

std::for_each(v.begin(), v.end(), std::ref(counter));
```

Conceptually:

```text
algorithm
    ↓
reference wrapper
    ↓
original counter object
```

---

# 71. Empty Functors

A functor does not need member variables.

Example:

```cpp
struct IsEven
{
    bool operator()(int x) const
    {
        return x % 2 == 0;
    }
};
```

This is a **stateless functor**.

Because it has no state, the object can be extremely small, and compilers can often optimize calls effectively.

---

# 72. `struct` vs `class` Functor

Both can be used.

Using `struct`:

```cpp
struct Square
{
    int operator()(int x) const
    {
        return x * x;
    }
};
```

Using `class`:

```cpp
class Square
{
public:

    int operator()(int x) const
    {
        return x * x;
    }
};
```

The main difference is default access:

```text
struct → public
class  → private
```

Both can create functors.

---

# 73. `operator()` Can Be Templated

Example:

```cpp
struct Printer
{
    template<typename T>
    void operator()(const T& value) const
    {
        cout << value << "\n";
    }
};
```

This can accept different types:

```cpp
Printer p;

p(10);
p(3.14);
p("Hello");
```

---

# 74. `operator()` with Perfect Forwarding

Advanced generic functors can use forwarding references.

```cpp
struct Forwarder
{
    template<typename T>
    void operator()(T&& value) const
    {
        // process value
    }
};
```

This allows the functor to accept lvalues and rvalues while preserving value-category information.

For practical STL use, this technique is mainly relevant when writing generic library components.

---

# 75. Functor with Multiple `operator()` Templates

A functor can provide several overloads.

```cpp
struct Printer
{
    void operator()(int x) const
    {
        cout << "int: " << x << "\n";
    }

    void operator()(double x) const
    {
        cout << "double: " << x << "\n";
    }

    void operator()(const string& s) const
    {
        cout << "string: " << s << "\n";
    }
};
```

Usage:

```cpp
Printer p;

p(10);
p(3.14);
p("Hello");
```

---

# 76. Function Object vs Callable

A **callable** is a broader concept.

Examples include:

```text
Normal function
Function pointer
Functor
Lambda closure
Pointer to member function with suitable invocation
std::function
```

A functor is specifically an object whose type provides callable behavior, commonly through:

```cpp
operator()
```

So:

```text
Functor ⊂ Callable Objects / Callables
```

---

# 77. `std::invoke`

Modern C++ provides:

```cpp
std::invoke()
```

which provides a uniform way to invoke many callable forms.

Example:

```cpp
#include <functional>

Square sq;

cout << std::invoke(sq, 5);
```

Output:

```text
25
```

`std::invoke()` can also handle other callable forms such as function pointers and pointers to member functions.

---

# 78. Functors and Algorithms — General Flow

When an algorithm receives a functor:

```cpp
sort(v.begin(), v.end(), Compare());
```

conceptually:

```text
vector
  ↓
STL algorithm
  ↓
Compare object
  ↓
operator()
  ↓
true / false
```

For each comparison, the algorithm invokes the callable.

---

# 79. Comparator Requirements

A comparator used for ordering should provide a consistent ordering relation.

For standard sorting/ordered containers, the comparator should satisfy the requirements expected by the algorithm/container.

A common comparator:

```cpp
struct Descending
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};
```

The meaning is:

```text
a comes before b
if a > b
```

The comparator should not behave inconsistently or randomly.

---

# 80. Comparator Should Not Usually Modify Arguments

Prefer:

```cpp
bool operator()(const T& a, const T& b) const
```

for class/object comparisons when the comparison does not need to modify the values.

Example:

```cpp
struct CompareName
{
    bool operator()(const string& a, const string& b) const
    {
        return a < b;
    }
};
```

This avoids unnecessary copying and communicates that comparison does not modify the values.

---

# 81. Transparent Custom Comparator

A custom comparator can also provide heterogeneous comparison if designed appropriately.

Example:

```cpp
struct Compare
{
    using is_transparent = void;

    bool operator()(const string& a, const string& b) const
    {
        return a < b;
    }

    bool operator()(const string& a, std::string_view b) const
    {
        return a < b;
    }

    bool operator()(std::string_view a, const string& b) const
    {
        return a < b;
    }
};
```

This is an advanced technique commonly useful with associative containers.

---

# 82. Functor with `map`

Example:

```cpp
#include <iostream>
#include <map>
using namespace std;

struct Descending
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

int main()
{
    map<int, string, Descending> m;

    m[1] = "One";
    m[2] = "Two";
    m[3] = "Three";

    for (const auto& [key, value] : m)
    {
        cout << key << " " << value << "\n";
    }

    return 0;
}
```

The keys are ordered according to `Descending`.

---

# 83. Functor with `priority_queue`

Functors can also customize priority queues.

Example:

```cpp
#include <queue>
#include <vector>
#include <functional>

std::priority_queue<
    int,
    std::vector<int>,
    std::greater<int>
> pq;
```

This creates a min-heap behavior.

The comparator/function object determines priority ordering.

---

# 84. Functor with `set`

```cpp
std::set<int, std::greater<int>> s;
```

Resulting iteration order:

```text
9 8 7 6 5
```

instead of the default ascending order.

---

# 85. Functor with `multiset`

```cpp
std::multiset<int, std::greater<int>> ms;
```

Duplicates are allowed and values are ordered according to `greater`.

---

# 86. Functor with `multimap`

```cpp
std::multimap<int, string, std::greater<int>> mm;
```

Keys are ordered descending.

---

# 87. Functor vs Lambda — Detailed Comparison

| Feature | Functor | Lambda |
|---|---|---|
| Named type | Yes | No explicit user-written type name |
| Callable | Yes | Yes |
| State | Yes | Yes through captures |
| Constructor | Yes | Closure initialization through captures |
| Multiple overloads | Yes | One call operator per closure type, though generic/overloaded techniques exist |
| Reusable | Excellent | Usually best for local use |
| Complex logic | Excellent | Can become verbose |
| Small one-off logic | More verbose | Excellent |
| Template support | Yes | Generic lambdas support templates |
| Inheritance | Yes | Closure type cannot be named directly for normal inheritance |
| STL usage | Excellent | Excellent |
| Custom named API | Excellent | Less suitable |
| Readability for simple predicates | Good | Usually better |

---

# 88. Functor vs Lambda Example

Functor:

```cpp
struct IsEven
{
    bool operator()(int x) const
    {
        return x % 2 == 0;
    }
};

int count = count_if(
    v.begin(),
    v.end(),
    IsEven()
);
```

Lambda:

```cpp
int count = count_if(
    v.begin(),
    v.end(),
    [](int x)
    {
        return x % 2 == 0;
    }
);
```

For a one-time operation, the lambda is usually more concise.

For a reusable named operation:

```cpp
IsEven()
```

can be more descriptive.

---

# 89. Advantages of Functors

## 89.1 Can Store State

```cpp
class Counter
{
    int count = 0;

public:
    void operator()()
    {
        ++count;
    }
};
```

---

## 89.2 Can Be Configured

```cpp
Multiplier triple(3);
Multiplier fiveTimes(5);
```

---

## 89.3 Reusable

A named functor can be used throughout a program.

---

## 89.4 Works Naturally with STL

Examples:

```cpp
sort()
find_if()
count_if()
transform()
remove_if()
partition()
```

---

## 89.5 Can Be Templated

```cpp
template<typename T>
struct Add
{
    T operator()(T a, T b) const
    {
        return a + b;
    }
};
```

---

## 89.6 Can Have Multiple Call Signatures

```cpp
operator()()
operator()(int)
operator()(string)
```

---

## 89.7 Can Have Constructors

This makes configurable behavior easy.

---

## 89.8 Can Be Optimized Well

A concrete functor type is known at compile time.

For many direct STL uses, the compiler can inline the call and optimize it effectively.

Do not interpret this as a guarantee that functors are always faster than functions, lambdas, or function pointers. Performance depends on the callable and how it is used.

---

# 90. Disadvantages

- More code than a simple lambda
- Requires defining a type
- Can be unnecessarily verbose for one-line operations
- Stateful behavior can make copying semantics important
- Complex functors can become difficult to understand
- Type-erased wrappers such as `std::function` can add overhead when compared with direct invocation

---

# 91. Memory Usage

A functor's memory usage depends on its data members.

Stateless:

```cpp
struct Square
{
    int operator()(int x) const
    {
        return x * x;
    }
};
```

The object can be empty.

Stateful:

```cpp
struct Multiplier
{
    int factor;
};
```

The object stores the state:

```text
factor
```

So:

```text
Functor memory ≈ size of its data members + object-layout requirements
```

---

# 92. Time Complexity

There is no single complexity for "a functor".

## Object construction

Depends on the constructor:

```text
O(1)
```

for simple constant-size state is common, but it can be more expensive if construction performs additional work.

## `operator()`

Complexity is determined by the implementation of the call operator.

Example:

```cpp
int operator()(int x)
{
    return x * x;
}
```

is:

```text
O(1)
```

A functor that searches a vector could be:

```text
O(n)
```

Therefore:

```text
Functor complexity = complexity of operator()
```

---

# 93. Functor Lifetime

A functor is an ordinary object.

Example:

```cpp
Square sq;
```

Its lifetime follows normal C++ object-lifetime rules.

When the object goes out of scope:

```cpp
{
    Square sq;
}
```

its destructor is invoked if applicable.

---

# 94. Functor Copying

Functors can be copied if their class is copyable.

```cpp
Multiplier a(3);

Multiplier b = a;
```

Now:

```text
a.factor = 3
b.factor = 3
```

They are separate objects.

Changing one object's state does not automatically change the other.

---

# 95. Functor Moving

A functor can support move semantics like any other class.

```cpp
Multiplier a(3);

Multiplier b(std::move(a));
```

Whether moving is meaningfully different from copying depends on the functor's members.

For simple types such as `int`, copying is already inexpensive.

---

# 96. Stateful Functor Copy Pitfall

Consider:

```cpp
class Counter
{
public:

    int count = 0;

    void operator()(int)
    {
        ++count;
    }
};
```

Then:

```cpp
Counter a;

Counter b = a;
```

creates:

```text
a.count = 0
b.count = 0
```

After:

```cpp
b(10);
```

we have:

```text
a.count = 0
b.count = 1
```

State belongs to each object independently.

---

# 97. Functor as Strategy

A functor can implement a strategy.

Example:

```cpp
struct Add
{
    int operator()(int a, int b) const
    {
        return a + b;
    }
};

struct Multiply
{
    int operator()(int a, int b) const
    {
        return a * b;
    }
};
```

A generic function can accept either:

```cpp
template<typename Operation>
int calculate(int a, int b, Operation op)
{
    return op(a, b);
}
```

Usage:

```cpp
cout << calculate(5, 3, Add());
cout << calculate(5, 3, Multiply());
```

Output:

```text
8
15
```

This is an example of the **Strategy Pattern** using templates and callable objects.

---

# 98. Runtime Strategy with `std::function`

If runtime selection is required:

```cpp
std::function<int(int, int)> operation;

operation = Add();

cout << operation(5, 3);
```

Later:

```cpp
operation = Multiply();
```

This allows the callable implementation to change at runtime.

---

# 99. Compile-Time vs Runtime Callable Selection

## Template / Functor

```cpp
template<typename Operation>
int calculate(int a, int b, Operation op)
{
    return op(a, b);
}
```

The concrete type is known at compile time.

Advantages:

```text
No type-erasure requirement
Often easy to inline
Strong type checking
```

---

## `std::function`

```cpp
std::function<int(int, int)> operation;
```

The concrete callable can vary at runtime.

Advantages:

```text
Flexible storage
One common callable type
```

Potential trade-off:

```text
Type-erasure overhead
```

---

# 100. Function Object Naming Conventions

Common names include:

```cpp
struct IsEven;
struct IsGreater;
struct Compare;
struct Descending;
struct Square;
struct Multiply;
struct Printer;
struct Counter;
```

A good functor name should communicate its behavior.

---

# 101. Functor with User-Defined Type

Functors are not limited to `int`.

Example:

```cpp
struct Employee
{
    int id;
    string name;
};
```

Comparator:

```cpp
struct CompareEmployee
{
    bool operator()(
        const Employee& a,
        const Employee& b
    ) const
    {
        return a.id < b.id;
    }
};
```

Usage:

```cpp
sort(
    employees.begin(),
    employees.end(),
    CompareEmployee()
);
```

---

# 102. Sorting Objects with a Functor

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Employee
{
    int id;
    string name;
};

struct CompareEmployee
{
    bool operator()(
        const Employee& a,
        const Employee& b
    ) const
    {
        return a.id < b.id;
    }
};

int main()
{
    vector<Employee> employees =
    {
        {3, "C"},
        {1, "A"},
        {2, "B"}
    };

    sort(
        employees.begin(),
        employees.end(),
        CompareEmployee()
    );

    for (const auto& e : employees)
    {
        cout << e.id << " " << e.name << "\n";
    }

    return 0;
}
```

Output:

```text
1 A
2 B
3 C
```

---

# 103. Functor with Multiple Sorting Rules

A functor can be configured.

```cpp
struct CompareEmployee
{
    bool byId;

    CompareEmployee(bool value)
        : byId(value)
    {
    }

    bool operator()(
        const Employee& a,
        const Employee& b
    ) const
    {
        if (byId)
        {
            return a.id < b.id;
        }

        return a.name < b.name;
    }
};
```

Usage:

```cpp
sort(
    employees.begin(),
    employees.end(),
    CompareEmployee(true)
);
```

This demonstrates stateful/configurable behavior.

---

# 104. Important Note About `std::sort` Comparators

A comparator should provide a valid ordering relation expected by `std::sort`.

A typical comparator:

```cpp
bool operator()(const T& a, const T& b) const
{
    return a.key < b.key;
}
```

Do not write a comparator that randomly changes behavior.

Bad example:

```cpp
bool operator()(int a, int b)
{
    return rand() % 2;
}
```

Such a comparator does not provide a consistent ordering and can lead to incorrect behavior.

---

# 105. Functor and Strict Weak Ordering

For sorting and ordered containers, comparison functions are expected to satisfy the required ordering properties.

For `std::sort`, the comparator must model the required **strict weak ordering**.

For example:

```cpp
struct Less
{
    bool operator()(int a, int b) const
    {
        return a < b;
    }
};
```

This provides the standard ordering behavior expected by the algorithm.

---

# 106. Common Interview Questions

## Q1. What is a functor?

A functor is an object that behaves like a function by providing `operator()`.

---

## Q2. What operator makes a class callable?

```cpp
operator()
```

---

## Q3. Can a functor store state?

Yes.

```cpp
class Counter
{
    int count = 0;

public:

    void operator()()
    {
        ++count;
    }
};
```

---

## Q4. Can a functor have a constructor?

Yes.

```cpp
class Multiply
{
    int factor;

public:

    Multiply(int f)
        : factor(f)
    {
    }
};
```

---

## Q5. Can a functor have multiple `operator()` overloads?

Yes.

```cpp
operator()()
operator()(int)
operator()(string)
```

---

## Q6. Can a functor be a template?

Yes.

```cpp
template<typename T>
struct Add
{
    T operator()(T a, T b) const
    {
        return a + b;
    }
};
```

---

## Q7. What is a stateful functor?

A functor whose object stores information that can change or persist between calls.

---

## Q8. What is a stateless functor?

A functor that does not require stored per-object state.

Example:

```cpp
struct Square
{
    int operator()(int x) const
    {
        return x * x;
    }
};
```

---

## Q9. What is a predicate?

A callable, commonly returning `bool`, that tests a condition.

Example:

```cpp
bool operator()(int x) const
{
    return x % 2 == 0;
}
```

---

## Q10. Why are functors used in STL?

They allow algorithms and containers to receive customizable behavior such as:

```text
Comparison
Predicate
Transformation
Operation
```

---

## Q11. Which header contains predefined function objects?

```cpp
#include <functional>
```

---

## Q12. Name common predefined function objects.

```text
greater
less

equal_to
not_equal_to

greater_equal
less_equal

plus
minus
multiplies
divides
modulus
negate

logical_and
logical_or
logical_not
```

---

## Q13. Are lambdas functors?

A lambda creates a unique closure object with callable behavior. It is function-object-like and has an `operator()` in its generated closure type.

---

## Q14. Functor vs lambda?

```text
Functor:
Named reusable callable type

Lambda:
Convenient local callable expression
```

Both can store state and work with STL algorithms.

---

## Q15. Functor vs function pointer?

```text
Function pointer:
Stores address of a function

Functor:
Object containing callable behavior and potentially state
```

---

## Q16. Can a functor inherit from another class?

Yes. It is a normal C++ class/struct.

---

## Q17. Can a functor be polymorphic?

Yes, through normal virtual-function mechanisms.

---

## Q18. Can a functor be stored in `std::function`?

Yes.

```cpp
std::function<int(int)> f = Square();
```

---

## Q19. What is the complexity of calling a functor?

There is no universal complexity.

It is the complexity of the implementation of:

```cpp
operator()
```

---

## Q20. Why can a functor be efficiently optimized?

The concrete type is often known at compile time, allowing the compiler to inline and optimize direct calls.

This is an optimization opportunity, not a guarantee that functors are always faster.

---

# 107. Common Mistakes

## Mistake 1: Forgetting `operator()`

Wrong:

```cpp
class Square
{
    int square(int x)
    {
        return x * x;
    }
};
```

This is a normal member function, not a function-call functor interface.

Correct:

```cpp
class Square
{
public:

    int operator()(int x) const
    {
        return x * x;
    }
};
```

---

## Mistake 2: Calling the Object Incorrectly

Correct:

```cpp
Square sq;

sq(5);
```

Equivalent conceptually to:

```cpp
sq.operator()(5);
```

---

## Mistake 3: Forgetting `const` on a Comparator

Prefer:

```cpp
bool operator()(const T& a, const T& b) const
```

when the comparator does not modify the functor or its arguments.

---

## Mistake 4: Assuming Functors Are Always Faster

It is not correct to say:

```text
Functor is always faster than lambda/function.
```

Performance depends on:

```text
Callable type
Inlining
Optimization
State
Type erasure
Algorithm
Compiler
Usage
```

---

## Mistake 5: Ignoring Functor Copies

A stateful functor may be copied.

If state matters, understand how the algorithm receives and stores the callable.

---

# 108. Best Practices

## Use `const operator()` When Appropriate

Prefer:

```cpp
bool operator()(int a, int b) const
```

for read-only comparators and predicates.

---

## Pass Large Objects by `const&`

Instead of:

```cpp
bool operator()(Employee a, Employee b) const
```

prefer:

```cpp
bool operator()(
    const Employee& a,
    const Employee& b
) const
```

when copying is unnecessary.

---

## Keep Comparators Simple

Good:

```cpp
struct Compare
{
    bool operator()(const Employee& a,
                    const Employee& b) const
    {
        return a.id < b.id;
    }
};
```

---

## Use Lambdas for Small One-Off Operations

Example:

```cpp
sort(
    v.begin(),
    v.end(),
    [](int a, int b)
    {
        return a > b;
    }
);
```

---

## Use Named Functors for Reusable Behavior

Example:

```cpp
struct CompareEmployeeById
{
    bool operator()(
        const Employee& a,
        const Employee& b
    ) const
    {
        return a.id < b.id;
    }
};
```

---

# 109. Functor Decision Guide

Use a:

```text
Lambda
```

when:

```text
Small
+
Local
+
One-time behavior
```

Use a:

```text
Named Functor
```

when:

```text
Reusable
+
Complex
+
Configurable
+
Stateful
```

Use:

```text
Function
```

when:

```text
Simple named operation
+
No object state needed
```

Use:

```text
std::function
```

when:

```text
You need one type-erased callable interface
+
The concrete callable may vary at runtime
```

---

# 110. Real-World Uses

Functors can be useful for:

- Custom sorting
- Comparators
- Predicates
- Event handling
- Callbacks
- Mathematical operations
- State machines
- Counters
- Logging
- Filtering
- Transformation
- Parsing
- Caching policies
- Strategy pattern
- Custom container ordering
- Priority queues
- `set`/`map` ordering
- Generic algorithms

---

# 111. Complete Example — Stateful Functor

```cpp
#include <iostream>

using namespace std;

class Counter
{
    int count = 0;

public:

    void operator()()
    {
        ++count;

        cout << "Count = "
             << count
             << '\n';
    }
};

int main()
{
    Counter counter;

    counter();
    counter();
    counter();

    return 0;
}
```

Output:

```text
Count = 1
Count = 2
Count = 3
```

---

# 112. Complete Example — Custom Sort Functor

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Descending
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

int main()
{
    vector<int> v = {5, 1, 8, 3, 9};

    sort(
        v.begin(),
        v.end(),
        Descending()
    );

    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
9 8 5 3 1
```

---

# 113. Complete Example — Stateful `for_each`

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class CountEven
{
public:

    int count = 0;

    void operator()(int x)
    {
        if (x % 2 == 0)
        {
            ++count;
        }
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};

    CountEven counter;

    counter = for_each(
        v.begin(),
        v.end(),
        counter
    );

    cout << "Even count = "
         << counter.count;

    return 0;
}
```

Output:

```text
Even count = 3
```

---

# 114. Complete Example — Configurable Functor

```cpp
#include <iostream>

using namespace std;

class Multiplier
{
    int factor;

public:

    explicit Multiplier(int factor)
        : factor(factor)
    {
    }

    int operator()(int value) const
    {
        return value * factor;
    }
};

int main()
{
    Multiplier triple(3);
    Multiplier fiveTimes(5);

    cout << triple(10) << '\n';
    cout << fiveTimes(10) << '\n';

    return 0;
}
```

Output:

```text
30
50
```

---

# 115. Complete Example — Functor with `count_if`

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct IsEven
{
    bool operator()(int x) const
    {
        return x % 2 == 0;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};

    int count = count_if(
        v.begin(),
        v.end(),
        IsEven()
    );

    cout << count;

    return 0;
}
```

Output:

```text
3
```

---

# 116. Complete Example — Functor with `transform`

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Square
{
    int operator()(int x) const
    {
        return x * x;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4};
    vector<int> result(v.size());

    transform(
        v.begin(),
        v.end(),
        result.begin(),
        Square()
    );

    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
1 4 9 16
```

---

# 117. Complete Example — Functor with `std::function`

```cpp
#include <functional>
#include <iostream>

using namespace std;

struct Square
{
    int operator()(int x) const
    {
        return x * x;
    }
};

int main()
{
    function<int(int)> operation = Square();

    cout << operation(5);

    return 0;
}
```

Output:

```text
25
```

---

# 118. Complete Example — Functor as Strategy

```cpp
#include <iostream>

using namespace std;

struct Add
{
    int operator()(int a, int b) const
    {
        return a + b;
    }
};

struct Multiply
{
    int operator()(int a, int b) const
    {
        return a * b;
    }
};

template<typename Operation>
int calculate(int a, int b, Operation operation)
{
    return operation(a, b);
}

int main()
{
    cout << calculate(5, 3, Add()) << '\n';
    cout << calculate(5, 3, Multiply()) << '\n';

    return 0;
}
```

Output:

```text
8
15
```

---

# 119. Complete Example — Functor with `set`

```cpp
#include <functional>
#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int, greater<int>> s =
    {
        5, 1, 9, 3
    };

    for (int x : s)
    {
        cout << x << " ";
    }

    return 0;
}
```

Output:

```text
9 5 3 1
```

Here:

```cpp
greater<int>
```

is a standard-library function object.

---

# 120. Important Mental Model

Think of a functor as:

```text
          CLASS / STRUCT
                |
                |
         operator()
                |
                ↓
        +---------------+
        |    OBJECT     |
        |               |
        |   state       |
        |   behavior    |
        +---------------+
                |
                ↓
          object(args)
```

The key transformation is:

```cpp
object(args)
```

conceptually becomes:

```cpp
object.operator()(args)
```

---

# 121. Functor with STL — Mental Flow

For:

```cpp
sort(
    v.begin(),
    v.end(),
    Compare()
);
```

think:

```text
Vector
  ↓
sort()
  ↓
Compare object
  ↓
operator()(a, b)
  ↓
true / false
  ↓
Ordering decision
```

For:

```cpp
count_if(
    v.begin(),
    v.end(),
    IsEven()
);
```

think:

```text
Vector
  ↓
count_if()
  ↓
IsEven object
  ↓
operator()(x)
  ↓
true / false
  ↓
Count
```

---

# 122. Quick Revision

```text
Functor
-------
Function Object

Main Requirement
----------------
operator()

Call
----
obj(args)

Equivalent
----------
obj.operator()(args)

Can store state
---------------
Yes

Can have constructors
---------------------
Yes

Can have member variables
-------------------------
Yes

Can be templated
----------------
Yes

Can inherit
-----------
Yes

Can be polymorphic
------------------
Yes

Can overload operator()
-----------------------
Yes

STL Usage
---------
sort()
for_each()
find_if()
count_if()
remove_if()
transform()
partition()

Header for predefined function objects
--------------------------------------
#include <functional>

Common predefined functors
--------------------------
greater
less
equal_to
not_equal_to
greater_equal
less_equal
plus
minus
multiplies
divides
modulus
negate
logical_and
logical_or
logical_not

Stateful
--------
Stores changing/internal state

Stateless
---------
No per-object state required

Predicate
---------
Callable commonly returning bool

Unary
-----
One argument

Binary
------
Two arguments

Lambda
------
Creates a closure object with callable behavior

std::function
-------------
Type-erased callable wrapper

std::ref
--------
Can make algorithms operate on an existing callable object by reference

Main Advantage
--------------
Reusable and configurable callable behavior

Main Limitation
---------------
More code than lambdas for simple operations
```

---

# 123. Final Summary

A **functor** is a C++ object that behaves like a function.

The essential feature is:

```cpp
operator()
```

Example:

```cpp
struct Square
{
    int operator()(int x) const
    {
        return x * x;
    }
};
```

Usage:

```cpp
Square square;

cout << square(5);
```

Conceptually:

```cpp
square(5);
```

becomes:

```cpp
square.operator()(5);
```

Functors are powerful because they combine:

```text
Object
+
State
+
Behavior
```

They can be:

```text
Stateless
Stateful
Configurable
Templated
Polymorphic
Reusable
```

They are heavily used with the C++ Standard Library:

```cpp
sort()
find_if()
count_if()
for_each()
transform()
remove_if()
partition()
set
map
multiset
multimap
priority_queue
```

Modern C++ also provides convenient alternatives and complementary callable mechanisms:

```text
Lambda
std::function
std::invoke
std::ref
```

The most important concepts to remember are:

```text
Functor
   ↓
Object that is callable
   ↓
operator()
   ↓
Can store state
   ↓
Can be passed to algorithms
   ↓
Can customize STL behavior
```

For practical C++:

```text
Small one-time callable
        ↓
      Lambda

Reusable/configurable/stateful callable
        ↓
      Functor

Runtime type-erased callable
        ↓
    std::function

Simple named operation without state
        ↓
      Function
```
