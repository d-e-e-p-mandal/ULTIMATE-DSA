# C++ STL Algorithms (`<algorithm>`) -- Complete Notes

> **Purpose:** This is a practical, interview-oriented,
> implementation-focused reference for the C++ Standard Library
> algorithms. It covers the requested topics from fundamentals through
> C++20 ranges, execution policies, complexity, iterator requirements,
> comparisons, patterns, programs, debugging, and revision.
>
> **Standard coverage:** C++11, C++14, C++17, C++20, with selected C++23
> notes.
>
> **Important:** The exact overload and complexity guarantee can differ
> by standard version and iterator category. For production code, verify
> the exact overload in the standard/library documentation.

------------------------------------------------------------------------

# Table of Contents

1.  [STL Algorithms Introduction](#part-1--stl-algorithms-introduction)
2.  [Algorithm Fundamentals](#part-2--algorithm-fundamentals)
3.  [Algorithm Categories](#part-3--algorithm-categories)
4.  [Function Objects](#part-4--function-objects)
5.  [Lambda Expressions](#part-5--lambda-expressions)
6.  [Predicates](#part-6--predicates)
7.  [`std::invoke`](#part-7--stdinvoke)
8.  [Value Categories Used by Algorithms](#part-8--value-categories-used-by-algorithms)
9.  [Non-Modifying Sequence Algorithms](#part-9--non-modifying-sequence-algorithms)
10. [Detailed Non-Modifying Concepts](#part-10--detailed-non-modifying-algorithm-concepts)
11. [Modifying Sequence Algorithms](#part-11--modifying-sequence-algorithms)
12. [Copy Algorithms](#part-12--copy-algorithms)
13. [Move Algorithms](#part-13--move-algorithms)
14. [Transform Algorithms](#part-14--transform-algorithms)
15. [Remove Algorithms](#part-15--remove-algorithms)
16. [Unique Algorithms](#part-16--unique-algorithms)
17. [Reverse and Rotate](#part-17--reverse-and-rotate)
18. [Partitioning Algorithms](#part-18--partitioning-algorithms)
19. [Sorting Algorithms](#part-19--sorting-algorithms)
20. [Sorting Fundamentals](#part-20--sorting-fundamentals)
21. [Internal Sorting Algorithms](#part-21--internal-sorting-algorithms)
22. [`sort()` in Detail](#part-22--sort-in-detail)
23. [`stable_sort()`](#part-23--stable_sort)
24. [Partial Sorting](#part-24--partial-sorting)
25. [`nth_element()`](#part-25--nth_element)
26. [Binary Search Algorithms](#part-26--binary-search-algorithms)
27. [Binary Search Prerequisites](#part-27--binary-search-prerequisites)
28. [`binary_search()`](#part-28--binary_search)
29. [`lower_bound()`](#part-29--lower_bound)
30. [`upper_bound()`](#part-30--upper_bound)
31. [`equal_range()`](#part-31--equal_range)
32. [Heap Fundamentals](#part-32--heap-fundamentals)
33. [Heap Algorithms](#part-33--heap-algorithms)
34. [Heap Internal Working](#part-34--heap-internal-working)
35. [Set Algorithms](#part-35--set-algorithms)
36. [Set Algorithm Concepts](#part-36--set-algorithm-concepts)
37. [Min/Max Algorithms](#part-37--minmax-algorithms)
38. [Comparison Algorithms](#part-38--comparison-algorithms)
39. [Permutation Algorithms](#part-39--permutation-algorithms)
40. [Numeric Algorithms](#part-40--numeric-algorithms)
41. [`accumulate()`](#part-41--accumulate)
42. [`reduce()`](#part-42--reduce)
43. [Prefix and Scan Algorithms](#part-43--prefix-and-scan-algorithms)
44. [Mathematical Algorithms](#part-44--mathematical-algorithms)
45. [Custom Comparators](#part-45--custom-comparators)
46. [Strict Weak Ordering](#part-46--strict-weak-ordering)
47. [Iterator Categories](#part-47--iterator-categories)
48. [Iterator Requirements by Algorithm](#part-48--iterator-requirements-by-algorithm)
49. [Execution Policies](#part-49--execution-policies)
50. [Parallel Algorithms](#part-50--parallel-algorithms)
51. [C++20 Ranges](#part-51--c20-ranges)
52. [C++20 Ranges Algorithms](#part-52--c20-ranges-algorithms)
53. [C++20 Ranges Modifying Algorithms](#part-53--c20-ranges-modifying-algorithms)
54. [C++20 Ranges Sorting](#part-54--c20-ranges-sorting)
55. [C++20 Ranges Binary Search](#part-55--c20-ranges-binary-search)
56. [C++20 Ranges Partitioning](#part-56--c20-ranges-partitioning)
57. [C++20 Ranges Heap Algorithms](#part-57--c20-ranges-heap-algorithms)
58. [C++20 Ranges Set Algorithms](#part-58--c20-ranges-set-algorithms)
59. [C++20 Ranges Projections](#part-59--c20-ranges-projections)
60. [C++20 Concepts Used by Algorithms](#part-60--c20-concepts-used-by-algorithms)
61. [Algorithm Complexity](#part-61--algorithm-complexity)
62. [Complete Complexity Table](#part-62--complete-complexity-table)
63. [Iterator Invalidation](#part-63--iterator-invalidation)
64. [Algorithm Behavior and Guarantees](#part-64--algorithm-behavior-and-guarantees)
65. [STL Algorithm Comparisons](#part-65--stl-algorithm-comparisons)
66. [Container and Algorithm Compatibility](#part-66--container-and-algorithm-compatibility)
67. [`sort()` and Containers](#part-67--sort-and-containers)
68. [Remove-Erase Idiom](#part-68--remove-erase-idiom)
69. [Algorithm Design Patterns](#part-69--algorithm-design-patterns)
70. [Competitive Programming Applications](#part-70--competitive-programming-applications)
71. [Greedy Algorithms Using STL](#part-71--greedy-algorithms-using-stl)
72. [Heap-Based Problems](#part-72--heap-based-problems)
73. [Binary Search Problems](#part-73--binary-search-problems)
74. [Sorting Problems](#part-74--sorting-problems)
75. [Permutation Problems](#part-75--permutation-problems)
76. [Data Processing Applications](#part-76--data-processing-applications)
77. [Scheduling Applications](#part-77--scheduling-applications)
78. [Common Mistakes](#part-78--common-mistakes)
79. [Interview Questions](#part-79--interview-questions)
80. [100+ Interview Question Categories](#part-80--100-interview-question-categories)
81. [Complete Programs](#part-81--complete-programs)
82. [Advanced Complete Programs](#part-82--advanced-complete-programs)
83. [Real-World STL Algorithm Usage](#part-83--real-world-stl-algorithm-usage)
84. [Algorithm Selection Guide](#part-84--algorithm-selection-guide)
85. [Algorithm Decision Patterns](#part-85--algorithm-decision-patterns)
86. [STL Algorithm Performance](#part-86--stl-algorithm-performance)
87. [Advanced Performance Topics](#part-87--advanced-performance-topics)
88. [STL Algorithms with User-Defined Types](#part-88--stl-algorithms-with-user-defined-types)
89. [Algorithms with Strings](#part-89--algorithms-with-strings)
90. [Algorithms with Maps and Sets](#part-90--algorithms-with-maps-and-sets)
91. [Algorithms with Vectors](#part-91--algorithms-with-vectors)
92. [Algorithms with Arrays](#part-92--algorithms-with-arrays)
93. [Algorithms with Linked Lists](#part-93--algorithms-with-linked-lists)
94. [C++ Standard Version Coverage](#part-94--c-standard-version-coverage)
95. [STL Algorithm Best Practices](#part-95--stl-algorithm-best-practices)
96. [STL Algorithm Cheat Sheet](#part-96--stl-algorithm-cheat-sheet)
97. [Most Important Algorithms for Interviews](#part-97--most-important-algorithms-for-interviews)
98. [Problem-Solving Templates](#part-98--problem-solving-templates)
99. [Debugging STL Algorithms](#part-99--debugging-stl-algorithms)
100. [Master Revision Notes](#part-100--master-revision-notes)
101. [Complete Algorithm Master Checklist](#part-101--complete-algorithm-master-checklist)

------------------------------------------------------------------------

# Part 1 -- STL Algorithms Introduction

## 1.1 What Are STL Algorithms?

STL algorithms are generic functions provided by the C++ Standard
Library that operate on ranges of elements. They are usually implemented
in terms of iterators, so the algorithm is separated from the container
that stores the data.

Example:

``` cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{5, 2, 9, 1, 3};

    std::sort(v.begin(), v.end());

    for (int x : v)
        std::cout << x << ' ';
}
```

Output:

``` text
1 2 3 5 9
```

The important idea is:

``` text
Container -> provides data + iterators
Algorithm -> performs operation
Iterator  -> connects the two
```

## 1.2 Why Use STL Algorithms?

Advantages:

-   Less code.
-   Well-tested implementations.
-   Generic design.
-   Clear intent.
-   Standard complexity guarantees.
-   Works with many containers.
-   Supports custom predicates and comparators.
-   Integrates with lambdas.
-   Modern versions support ranges and projections.

Instead of:

``` cpp
for (auto it = v.begin(); it != v.end(); ++it) {
    if (*it == 10) {
        // ...
    }
}
```

you can write:

``` cpp
auto it = std::find(v.begin(), v.end(), 10);
```

## 1.3 Standard Template Library

The STL is commonly discussed as a collection of:
- Containers
- Iterators
- Algorithms
- Function Objects
- Allocators

Modern C++ additionally provides ranges, concepts, views, and many newer  library abstractions.

## 1.4 Algorithm Library

The most important headers are:

  -----------------------------------------------------------------------
  Header                              Main purpose
  ----------------------------------- -----------------------------------
  `<algorithm>`                       General sequence, sorting,
                                      searching, heap, set, permutation
                                      algorithms

  `<numeric>`                         Numeric operations and scans

  `<functional>`                      Function objects such as `less`,
                                      `greater`

  `<iterator>`                        Iterator utilities

  `<execution>`                       Execution policies

  `<ranges>`                          C++20 ranges and range algorithms
  -----------------------------------------------------------------------

## 1.5 Generic Algorithms

Generic means the same algorithm can operate on different types when their requirements are satisfied.

``` cpp
std::sort(v.begin(), v.end());
std::sort(a.begin(), a.end());
```

The algorithm does not need to know whether the elements came from a `vector` or `array`.

## 1.6 Iterator-Based Design

Classic STL algorithms generally use:

``` cpp
algorithm(first, last);
```

The range is:

``` text
[first, last)
```

**`first` is included; `last` is excluded.**

## 1.7 Algorithm and Container Separation

A `vector` stores values. `sort()` sorts values. The iterator range connects them.

This separation allows:

```cpp
std::sort(v.begin(), v.end());
std::sort(a.begin(), a.end());
```

where `v` can be a vector and `a` an array.

## 1.8 Algorithm and Data Structure Separation

Algorithms are not containers. A container controls storage and ownership; an algorithm generally performs an operation over an existing range.

## 1.9 Advantages and Limitations

### Advantages

- Reusable.
- Standardized.
- Expressive.
- Efficient.
- Composable.

### Limitations

-   You must understand iterator requirements.
-   Preconditions such as sorted ranges matter.
-   Incorrect comparators can break behavior.
-   Some algorithms require specific iterator categories.
-   `remove()` does not erase a container element by itself.

------------------------------------------------------------------------

# Part 2 -- Algorithm Fundamentals

## 2.1 Algorithm Syntax

Typical classic syntax:

``` cpp
std::sort(first, last);
std::find(first, last, value);
std::count_if(first, last, predicate);
```

With a comparator:

``` cpp
std::sort(first, last, comp);
```

## 2.2 Iterator Ranges

The standard STL range convention is:

``` text
[first, last)
```

Example:

``` cpp
std::vector<int> v{10, 20, 30, 40};
std::cout << *v.begin(); // 10
```

`v.end()` points one position past the final element and must not be dereferenced.

## 2.3 Half-Open Range

A half-open range has these properties:
- first -> included
- last  -> excluded

For `v.begin(), v.end()`, every element is covered exactly once.


This convention makes empty ranges natural:
``` cpp
[first, first)
```

## 2.4 Source and Destination Ranges

Copying:

``` cpp
std::copy(src.begin(), src.end(), dst.begin());
```

Source:

``` text
[src.begin(), src.end())
```

Destination starts at:

``` text
dst.begin()
```

The destination must have enough valid storage/elements unless an inserting output iterator is used.

## 2.5 Return Values

Algorithms can return:

-   Iterator.
-   Pair of iterators.
-   Boolean.
-   Count.
-   Algorithm-specific result structure.
-   Output iterator.
-   Reference/value for scalar algorithms.

Example:

``` cpp
auto it = std::find(v.begin(), v.end(), 30);

if (it != v.end())
    std::cout << "Found";
```

## 2.6 Complexity

Always ask:

``` text
How many elements are processed?
How many comparisons?
How many moves?
How much extra memory?
What iterator category is used?
```

`std::find()` is generally linear:

``` text
O(n)
```

Binary-search algorithms make logarithmically many comparisons on suitable random-access ranges, although iterator movement can have different costs for non-random-access iterators.

## 2.7 Stable vs Unstable

A stable operation preserves the relative order of equivalent elements.

Example:

``` text
(Alice, 90)
(Bob,   90)
```

After a stable sort by marks:

``` text
Alice before Bob
```

An unstable sort does not promise this.

## 2.8 In-Place

An in-place algorithm generally rearranges the existing range instead of
requiring a separate full-size result range.

Examples:

``` cpp
std::sort(v.begin(), v.end());
std::reverse(v.begin(), v.end());
std::partition(v.begin(), v.end(), pred);
```

"In-place" does not mean zero temporary memory in every implementation;
it means the algorithm operates primarily within the original range.

------------------------------------------------------------------------

# Part 3 -- Algorithm Categories

## 3.1 Non-Modifying

These inspect data without changing the source range:

``` cpp
find
count
all_of
any_of
none_of
equal
mismatch
search
```

## 3.2 Modifying

These can rearrange or change elements:

``` cpp
copy
move
transform
replace
fill
generate
remove
unique
reverse
rotate
shuffle
```

## 3.3 Partitioning

Partitioning divides a range according to a predicate:

``` cpp
partition
stable_partition
partition_copy
partition_point
is_partitioned
```

## 3.4 Sorting

``` cpp
sort
stable_sort
partial_sort
partial_sort_copy
nth_element
is_sorted
is_sorted_until
```

## 3.5 Binary Search

``` cpp
binary_search
lower_bound
upper_bound
equal_range
```

## 3.6 Heap

``` cpp
make_heap
push_heap
pop_heap
sort_heap
is_heap
is_heap_until
```

## 3.7 Set

These generally require sorted input ranges:

``` cpp
includes
merge
inplace_merge
set_union
set_intersection
set_difference
set_symmetric_difference
```

## 3.8 Min/Max

``` cpp
min
max
minmax
min_element
max_element
minmax_element
clamp
```

## 3.9 Comparison

``` cpp
equal
mismatch
lexicographical_compare
lexicographical_compare_three_way
```

## 3.10 Permutation

``` cpp
next_permutation
prev_permutation
is_permutation
```

## 3.11 Numeric

From `<numeric>`:

``` cpp
iota
accumulate
reduce
inner_product
partial_sum
adjacent_difference
inclusive_scan
exclusive_scan
transform_reduce
transform_inclusive_scan
transform_exclusive_scan
gcd
lcm
midpoint
```

------------------------------------------------------------------------

# Part 4 -- Function Objects

## 4.1 Function Object Fundamentals

A function object, or functor, is an object that can be called like a function.

## 4.2 Functor

``` cpp
struct IsEven {
    bool operator()(int x) const {
        return x % 2 == 0;
    }
};

std::vector<int> v{1,2,3,4};
int c = std::count_if(v.begin(), v.end(), IsEven{});
```

## 4.3 `operator()`

The call operator makes an object callable:

``` cpp
obj(value);
```

which invokes:

``` cpp
obj.operator()(value);
```

## 4.4 Unary and Binary Function Objects

Unary:

``` cpp
bool operator()(int x) const;
```

Binary:

``` cpp
bool operator()(int a, int b) const;
```

Comparators used by sorting are commonly binary callables.

## 4.5 Standard Function Objects

Useful objects include:

``` cpp
std::less<>
std::greater<>
std::equal_to<>
std::not_equal_to<>
std::less_equal<>
std::greater_equal<>
std::logical_and<>
std::logical_or<>
std::logical_not<>
```

Example:

``` cpp
std::sort(v.begin(), v.end(), std::greater<int>{});
```

For transparent comparators:

``` cpp
std::greater<> comp;
```

the argument types can be deduced.

------------------------------------------------------------------------

# Part 5 -- Lambda Expressions

## 5.1 Lambda Fundamentals

A lambda creates an unnamed function object.

Syntax:

``` cpp
[capture](parameters) -> return_type {
    // body
};
```

Example:

``` cpp
auto isEven = [](int x) {
    return x % 2 == 0;
};
```

## 5.2 Capture

### Empty capture

``` cpp
[] (int x) { return x > 0; }
```

### Value capture

``` cpp
int limit = 10;
auto f = [limit](int x) {
    return x > limit;
};
```

### Reference capture

``` cpp
int count = 0;

auto f = [&count]() {
    ++count;
};
```

### Mixed

``` cpp
int a = 10;
int b = 20;

auto f = [a, &b]() {
    // a copied, b referenced
};
```

## 5.3 Generic Lambda

C++14:

``` cpp
auto print = [](const auto& x) {
    std::cout << x << '\n';
};
```

## 5.4 Mutable Lambda

A value capture is normally treated as const inside the lambda's call operator. `mutable` permits modifying the lambda's captured copy:

``` cpp
int x = 10;

auto f = [x]() mutable {
    ++x;
    return x;
};
```

The original `x` remains 10.

## 5.5 Lambda as Predicate

``` cpp
std::count_if(v.begin(), v.end(),
              [](int x) { return x > 10; });
```

## 5.6 Lambda as Comparator

``` cpp
std::sort(v.begin(), v.end(),
          [](int a, int b) {
              return a > b;
          });
```

**The comparator means:**
- `a should appear before b`
- not simply "a is less than b" unless that is the chosen ordering.

## 5.7 Common Lambda Mistakes

-   Capturing a local variable by reference and using it after its
    lifetime.
-   Returning inconsistent types.
-   Writing a comparator that violates strict weak ordering.
-   Capturing more variables than necessary.
-   Accidentally modifying a captured reference.

------------------------------------------------------------------------

# Part 6 -- Predicates

## 6.1 Predicate Definition

A predicate is a callable that produces a Boolean-like result for a condition.

**Unary predicate:**
``` cpp
[](int x) { return x % 2 == 0; }
```

**Binary predicate:**
``` cpp
[](int a, int b) { return a < b; }
```

## 6.2 Predicate Requirements

The predicate should obey the requirements of the algorithm using it. For common algorithms, it should not unexpectedly modify elements and should provide logically consistent results.

Example:

``` cpp
std::all_of(v.begin(), v.end(), [](int x) { return x >= 0; });
```

## 6.3 Stateless vs Stateful

Stateless:

``` cpp
[](int x) { return x > 0; }
```

Stateful:

``` cpp
int threshold = 50;

auto pred = [threshold](int x) {
    return x >= threshold;
};
```

## 6.4 Function, Functor, Lambda

All can be used when they meet the required callable interface.

``` cpp
bool positive(int x) {
    return x > 0;
}

struct Positive {
    bool operator()(int x) const {
        return x > 0;
    }
};

auto positiveLambda = [](int x) {
    return x > 0;
};
```

------------------------------------------------------------------------

# Part 7 -- `std::invoke`

`std::invoke` (C++17, `<functional>`) provides a uniform way to invoke:

-   Free functions.
-   Function objects.
-   Function pointers.
-   Member function pointers.
-   Member data pointers.
-   Reference wrappers.

Example:

``` cpp
#include <functional>
#include <iostream>

struct User {
    int id = 42;

    int getId() const {
        return id;
    }
};

int main() {
    User u;

    auto mf = &User::getId;
    std::cout << std::invoke(mf, u) << '\n';

    auto md = &User::id;
    std::cout << std::invoke(md, u) << '\n';
}
```

`std::invoke_result_t<F, Args...>` can determine the invocation result type.

Algorithms and ranges internally rely heavily on the same general callable model.

------------------------------------------------------------------------

# Part 8 -- Value Categories Used by Algorithms

## 8.1 Lvalue

An lvalue identifies an object with a persistent identity.

``` cpp
int x = 10;
int& r = x;
```

## 8.2 Rvalue

An rvalue generally represents a value that can be moved from.

``` cpp
std::string("hello")
```

## 8.3 Prvalue

A pure rvalue such as:

``` cpp
42
std::string("abc")
```

## 8.4 Xvalue

An expiring object, often produced by:

``` cpp
std::move(x)
```

## 8.5 Move Semantics

Move operations transfer resources where possible rather than copying
them.

``` cpp
std::string a = "large string";
std::string b = std::move(a);
```

## 8.6 Algorithm Interaction

The move algorithm:

``` cpp
std::move(first, last, destination);
```

moves from each source element into the destination.

Do not confuse this algorithm with `std::move(x)` from `<utility>`.

------------------------------------------------------------------------

# Part 9 -- Non-Modifying Sequence Algorithms

Every algorithm below is presented with purpose, syntax, requirements,
complexity, example, and important behavior.

## 9.1 `for_each()`

### Purpose

Apply a callable to every element.

### Header

``` cpp
#include <algorithm>
```

### Syntax

``` cpp
std::for_each(first, last, function);
```

### Example

``` cpp
std::vector<int> v{1,2,3,4};

std::for_each(v.begin(), v.end(), [](int& x) {
    x *= 2;
});
```

Although called "non-modifying sequence algorithms" in many
classifications, `for_each` itself can modify elements if the callable
receives references. The classification concerns the algorithm's general
role rather than an absolute prohibition on mutation.

### Complexity

O(n) applications.

### Important

The callable can maintain state:

``` cpp
int sum = 0;

std::for_each(v.begin(), v.end(), [&](int x) {
    sum += x;
});
```

## 9.2 `for_each_n()` --- C++17

Applies a callable to the first `n` elements.

``` cpp
std::for_each_n(v.begin(), 3, [](int x) {
    std::cout << x << ' ';
});
```

Requires at least `n` valid elements in the range.

## 9.3 `all_of()`

Returns true if every tested element satisfies the predicate.

``` cpp
bool ok = std::all_of(v.begin(), v.end(),
                      [](int x) { return x > 0; });
```

Early terminates when false is found.

## 9.4 `any_of()`

Returns true if at least one element satisfies the predicate.

``` cpp
bool hasEven = std::any_of(v.begin(), v.end(),
                           [](int x) { return x % 2 == 0; });
```

Early terminates when true is found.

## 9.5 `none_of()`

Returns true if no element satisfies the predicate.

``` cpp
bool noneNegative =
    std::none_of(v.begin(), v.end(),
                 [](int x) { return x < 0; });
```

## 9.6 `count()`

Counts values equal to a specified value.

``` cpp
int n = std::count(v.begin(), v.end(), 5);
```

Complexity: O(n).

## 9.7 `count_if()`

Counts elements satisfying a predicate.

``` cpp
int evenCount =
    std::count_if(v.begin(), v.end(),
                  [](int x) { return x % 2 == 0; });
```

## 9.8 `mismatch()`

Finds the first position where two ranges differ.

Conceptually:

``` text
A: 1 2 3 4
B: 1 2 9 4
      ^
```

Example:

``` cpp
auto [a, b] = std::mismatch(
    v1.begin(), v1.end(),
    v2.begin()
);
```

The exact overload determines how much of the second range must be
valid.

## 9.9 `equal()`

Checks whether two ranges contain equivalent elements.

``` cpp
bool same = std::equal(v1.begin(), v1.end(), v2.begin());
```

Modern overloads can compare two ranges with known bounds.

## 9.10 `is_permutation()`

Checks whether two ranges contain equivalent elements in different
order.

``` cpp
std::vector<int> a{1,2,3};
std::vector<int> b{3,1,2};

bool ok = std::is_permutation(
    a.begin(), a.end(), b.begin()
);
```

## 9.11 `search()`

Finds the first occurrence of one sequence inside another.

``` cpp
std::vector<int> pattern{3,4};

auto it = std::search(
    v.begin(), v.end(),
    pattern.begin(), pattern.end()
);
```

## 9.12 `search_n()`

Finds `count` consecutive values equal to a target.

``` cpp
auto it = std::search_n(
    v.begin(), v.end(),
    3, 7
);
```

Meaning: find three consecutive `7`s.

## 9.13 `find()`

Find first equal value.

``` cpp
auto it = std::find(v.begin(), v.end(), 20);
```

If not found:

``` cpp
it == v.end()
```

## 9.14 `find_if()`

Find first element satisfying a predicate.

``` cpp
auto it = std::find_if(
    v.begin(), v.end(),
    [](int x) { return x > 100; }
);
```

## 9.15 `find_if_not()`

Find first element that does not satisfy a predicate.

``` cpp
auto it = std::find_if_not(
    v.begin(), v.end(),
    [](int x) { return x % 2 == 0; }
);
```

## 9.16 `find_end()`

Finds the last occurrence of a subsequence.

``` cpp
auto it = std::find_end(
    v.begin(), v.end(),
    pattern.begin(), pattern.end()
);
```

## 9.17 `find_first_of()`

Finds the first element in the first range that matches any element in
the second range.

``` cpp
std::vector<int> wanted{7, 9};

auto it = std::find_first_of(
    v.begin(), v.end(),
    wanted.begin(), wanted.end()
);
```

## 9.18 `adjacent_find()`

Finds the first adjacent pair satisfying equality by default.

``` cpp
std::vector<int> v{1,2,2,4};

auto it = std::adjacent_find(v.begin(), v.end());
// points to first 2
```

Custom condition:

``` cpp
auto it = std::adjacent_find(
    v.begin(), v.end(),
    [](int a, int b) {
        return a > b;
    }
);
```

------------------------------------------------------------------------

# Part 10 -- Detailed Non-Modifying Algorithm Concepts

## 10.1 Linear Search

Linear search checks elements sequentially.

``` text
0 -> 1 -> 2 -> 3 -> ...
```

Typical complexity:

``` text
O(n)
```

Use:

``` cpp
find()
find_if()
find_if_not()
```

## 10.2 Predicate Search

Use a predicate when equality is not enough.

Example:

``` cpp
auto it = std::find_if(
    v.begin(), v.end(),
    [](int x) { return x > 50; }
);
```

## 10.3 Sequence Matching

For subsequences:

``` cpp
search()
find_end()
search_n()
```

## 10.4 Repeated Element Search

`search_n()` is the direct algorithm.

``` cpp
std::search_n(v.begin(), v.end(), 4, 0);
```

## 10.5 Adjacent Search

`adjacent_find()` is useful for detecting duplicates or ordering
violations.

## 10.6 Range Comparison

Use:

``` cpp
equal()
mismatch()
lexicographical_compare()
is_permutation()
```

## 10.7 Early Termination

Algorithms such as:

``` cpp
any_of
all_of
none_of
find
find_if
```

can stop before scanning the entire range.

------------------------------------------------------------------------

# Part 11 -- Modifying Sequence Algorithms

## 11.1 `copy()`

Copies a source range.

``` cpp
std::copy(v.begin(), v.end(), out.begin());
```

Destination must not overlap source in an unsafe way; use
`copy_backward` when the specified overlap direction is appropriate.

## 11.2 `copy_if()`

Copies only elements satisfying a predicate.

``` cpp
std::copy_if(
    v.begin(), v.end(),
    out.begin(),
    [](int x) { return x % 2 == 0; }
);
```

Returns an output iterator positioned after the last copied element.

## 11.3 `copy_n()`

Copies exactly `n` elements.

``` cpp
std::copy_n(v.begin(), 3, out.begin());
```

The source must contain at least `n` elements and the destination must
have sufficient valid space.

## 11.4 `copy_backward()`

Copies a range backward so the destination ends at the specified
destination iterator.

``` cpp
std::copy_backward(
    v.begin(), v.end(),
    v.end()
);
```

The source and destination may overlap in the way intended for backward
copying.

## 11.5 `move()`

Moves elements from one range to another.

``` cpp
std::move(src.begin(), src.end(), dst.begin());
```

Source elements remain valid but are generally in moved-from states.

## 11.6 `move_backward()`

Backward equivalent for suitable overlapping arrangements.

## 11.7 `swap()`

Swaps two objects.

``` cpp
int a = 10, b = 20;
std::swap(a, b);
```

## 11.8 `swap_ranges()`

Swaps corresponding elements of two ranges.

``` cpp
std::swap_ranges(a.begin(), a.end(), b.begin());
```

## 11.9 `iter_swap()`

Swaps the objects referred to by two iterators.

``` cpp
std::iter_swap(i, j);
```

Useful in sorting/partition implementations.

## 11.10 `transform()`

Unary:

``` cpp
std::transform(
    v.begin(), v.end(),
    v.begin(),
    [](int x) { return x * x; }
);
```

Binary:

``` cpp
std::transform(
    a.begin(), a.end(),
    b.begin(),
    out.begin(),
    std::plus<>()
);
```

## 11.11 `replace()`

``` cpp
std::replace(v.begin(), v.end(), 0, -1);
```

## 11.12 `replace_if()`

``` cpp
std::replace_if(
    v.begin(), v.end(),
    [](int x) { return x < 0; },
    0
);
```

## 11.13 `replace_copy()`

Copies while replacing matching values.

## 11.14 `replace_copy_if()`

Copies while replacing values satisfying a predicate.

## 11.15 `fill()`

``` cpp
std::fill(v.begin(), v.end(), 0);
```

## 11.16 `fill_n()`

``` cpp
std::fill_n(v.begin(), 5, 7);
```

Requires five valid output positions.

## 11.17 `generate()`

Generates values using a nullary callable.

``` cpp
int x = 1;

std::generate(v.begin(), v.end(), [&x] {
    return x++;
});
```

## 11.18 `generate_n()`

Generates `n` values.

## 11.19 `remove()`

`remove()` does not change the container's physical size. It moves
unwanted values toward the end and returns the new logical end.

``` cpp
auto newEnd = std::remove(
    v.begin(), v.end(), 5
);

v.erase(newEnd, v.end());
```

## 11.20 `remove_if()`

``` cpp
v.erase(
    std::remove_if(
        v.begin(), v.end(),
        [](int x) { return x < 0; }
    ),
    v.end()
);
```

## 11.21 `remove_copy()`

Copies all values except the target.

## 11.22 `remove_copy_if()`

Copies values for which the predicate is false.

## 11.23 `unique()`

Removes consecutive duplicates logically.

``` cpp
std::vector<int> v{1,1,2,2,3,3};

auto last = std::unique(v.begin(), v.end());
v.erase(last, v.end());
```

For arbitrary duplicate removal:

``` cpp
std::sort(v.begin(), v.end());
v.erase(std::unique(v.begin(), v.end()), v.end());
```

## 11.24 `unique_copy()`

Copies one representative from each consecutive equivalent group.

## 11.25 `reverse()`

``` cpp
std::reverse(v.begin(), v.end());
```

## 11.26 `reverse_copy()`

Writes reversed elements into a destination.

## 11.27 `rotate()`

``` cpp
std::rotate(v.begin(), v.begin() + 2, v.end());
```

For:

``` text
1 2 3 4 5
```

result:

``` text
3 4 5 1 2
```

## 11.28 `rotate_copy()`

Copies a rotated range without changing the source.

## 11.29 `shuffle()`

Randomly rearranges elements using a random number generator.

``` cpp
std::mt19937 rng(std::random_device{}());
std::shuffle(v.begin(), v.end(), rng);
```

## 11.30 `sample()` --- C++17

Selects a sample of elements.

``` cpp
std::vector<int> sample(3);

std::sample(
    v.begin(), v.end(),
    sample.begin(), sample.size(),
    rng
);
```

## 11.31 `shift_left()` --- C++20

Moves elements left by `n` positions.

``` cpp
std::shift_left(v.begin(), v.end(), 2);
```

## 11.32 `shift_right()` --- C++20

Moves elements right by `n` positions.

``` cpp
std::shift_right(v.begin(), v.end(), 2);
```

Moved-from/unspecified portions must be handled according to the
algorithm's specification; do not assume every vacated position contains
a particular value.

------------------------------------------------------------------------

# Part 12 -- Copy Algorithms

## 12.1 Copying One Range

``` cpp
std::copy(src.begin(), src.end(), dst.begin());
```

## 12.2 Conditional Copy

``` cpp
std::copy_if(
    src.begin(), src.end(),
    dst.begin(),
    [](int x) { return x > 0; }
);
```

## 12.3 Fixed-Count Copy

``` cpp
std::copy_n(src.begin(), 5, dst.begin());
```

## 12.4 Backward Copy

Use when the destination endpoint and overlap direction require backward
movement.

## 12.5 Overlapping Ranges

For overlapping ranges, choose the algorithm whose direction is
compatible with the overlap. Do not blindly use `copy()` as a
replacement for `memmove()`.

## 12.6 `copy()` vs `memcpy()`

`std::copy()` works with typed objects and iterators. `memcpy()` copies
raw bytes and has stricter requirements regarding object representation
and lifetime.

For ordinary C++ objects, prefer the type-safe STL operation.

## 12.7 Copying Objects

``` cpp
std::vector<std::string> a{"A","B"};
std::vector<std::string> b(2);

std::copy(a.begin(), a.end(), b.begin());
```

## 12.8 Copying Move-Only Objects

Copying move-only objects such as `std::unique_ptr` is not possible. Use
the move algorithm:

``` cpp
std::vector<std::unique_ptr<int>> src;
std::vector<std::unique_ptr<int>> dst(2);

std::move(src.begin(), src.end(), dst.begin());
```

------------------------------------------------------------------------

# Part 13 -- Move Algorithms

## 13.1 `std::move()` Algorithm vs `std::move()` Cast

Algorithm:

``` cpp
std::move(first, last, destination);
```

Header:

``` cpp
<algorithm>
```

Cast:

``` cpp
std::move(object)
```

Header:

``` cpp
<utility>
```

They are different.

## 13.2 Move Assignment

The move algorithm performs move assignment into destination elements.

## 13.3 Moved-From Objects

A moved-from standard-library object is generally valid but its value is
unspecified unless its type specifies more.

You may safely destroy it, assign a new value, or use operations allowed
for its valid state.

## 13.4 `move()` vs `copy()`

Use copy when the source must retain its original value. Use move when
ownership/resource transfer is intended and the source can be left
moved-from.

## 13.5 Move-Only Types

Classic example:

``` cpp
std::vector<std::unique_ptr<int>> src;
std::vector<std::unique_ptr<int>> dst(src.size());

std::move(src.begin(), src.end(), dst.begin());
```

------------------------------------------------------------------------

# Part 14 -- Transform Algorithms

## 14.1 Unary Transform

One input range:

``` cpp
std::transform(
    v.begin(), v.end(),
    v.begin(),
    [](int x) { return x * 2; }
);
```

## 14.2 Binary Transform

Two input ranges:

``` cpp
std::transform(
    a.begin(), a.end(),
    b.begin(),
    out.begin(),
    [](int x, int y) { return x + y; }
);
```

## 14.3 Transform In-Place

The destination can be the source when the operation is compatible:

``` cpp
std::transform(
    v.begin(), v.end(),
    v.begin(),
    [](int x) { return x + 1; }
);
```

## 14.4 Transform with Functor

``` cpp
struct Square {
    int operator()(int x) const {
        return x * x;
    }
};

std::transform(v.begin(), v.end(), v.begin(), Square{});
```

## 14.5 Transform with Function Pointer

``` cpp
int square(int x) {
    return x * x;
}

std::transform(v.begin(), v.end(), v.begin(), square);
```

------------------------------------------------------------------------

# Part 15 -- Remove Algorithms

## 15.1 `remove()`

Logical operation:

``` text
Before:
1 2 3 2 4

remove 2

Logical range:
1 3 4
```

The vector's size is still 5 until `erase()` is called.

## 15.2 Remove-Erase Idiom

``` cpp
v.erase(
    std::remove(v.begin(), v.end(), value),
    v.end()
);
```

## 15.3 `erase()` vs `remove()`

`remove()` is an algorithm.

`erase()` is a container member function for containers that support
erasure.

Therefore:

``` cpp
remove -> rearranges range
erase  -> changes container size
```

## 15.4 C++20 `std::erase`

For containers supporting the C++20 non-member erase utilities:

``` cpp
std::erase(v, 5);
```

## 15.5 C++20 `std::erase_if`

``` cpp
std::erase_if(v, [](int x) {
    return x < 0;
});
```

## 15.6 Iterator Validity

After erasing from a vector, iterators/references at or after the erased
region may be invalidated. Always consult the specific container's
invalidation rules.

------------------------------------------------------------------------

# Part 16 -- Unique Algorithms

## 16.1 `unique()`

`unique()` removes consecutive equivalent values logically.

Input:

``` text
1 1 2 2 2 3
```

After `unique()`:

``` text
1 2 3 ? ? ?
```

The returned iterator marks the new logical end.

## 16.2 Sorting Before `unique()`

To remove all duplicates regardless of original order:

``` cpp
std::sort(v.begin(), v.end());
v.erase(std::unique(v.begin(), v.end()), v.end());
```

Complexity:

``` text
sort       O(n log n)
unique     O(n)
```

## 16.3 Custom Equality Predicate

``` cpp
std::unique(
    v.begin(), v.end(),
    [](int a, int b) {
        return std::abs(a - b) <= 1;
    }
);
```

The predicate defines equivalence for adjacent elements; it must meet the algorithm's requirements.

------------------------------------------------------------------------

# Part 17 -- Reverse and Rotate

## 17.1 Reverse

``` cpp
std::reverse(v.begin(), v.end());
```

## 17.2 Left Rotation

``` cpp
std::rotate(v.begin(), v.begin() + k, v.end());
```

For `k < size`, this rotates left by `k`.

## 17.3 Right Rotation

A right rotation by `k` can be expressed as:

``` cpp
k %= v.size();

std::rotate(
    v.begin(),
    v.end() - k,
    v.end()
);
```

Handle an empty vector before using `v.size() - k`.

## 17.4 Three-Reverse Rotation

Left rotate by `k`:

``` text
reverse(first, middle)
reverse(middle, last)
reverse(first, last)
```

This is a useful conceptual pattern, although `std::rotate` is normally
preferable.

------------------------------------------------------------------------

# Part 18 -- Partitioning Algorithms

## 18.1 `partition()`

Rearranges elements so that all elements satisfying the predicate come
before those that do not.

``` cpp
auto mid = std::partition(
    v.begin(), v.end(),
    [](int x) { return x % 2 == 0; }
);
```

The order within groups is not preserved.

## 18.2 `stable_partition()`

Preserves relative order within both groups.

``` cpp
std::stable_partition(
    v.begin(), v.end(),
    [](int x) { return x % 2 == 0; }
);
```

May use additional memory; complexity guarantees differ depending on
available memory/iterator category.

## 18.3 `partition_copy()`

Produces two output ranges:

``` cpp
std::partition_copy(
    v.begin(), v.end(),
    evens.begin(),
    odds.begin(),
    [](int x) { return x % 2 == 0; }
);
```

## 18.4 `partition_point()`

For a range partitioned according to a predicate, finds the partition
boundary.

``` cpp
auto p = std::partition_point(
    v.begin(), v.end(),
    [](int x) { return x < 10; }
);
```

## 18.5 `is_partitioned()`

Checks whether all elements satisfying a predicate occur before all
elements that do not.

## 18.6 Two-Pointer Partition

Typical manual partition:

``` text
left -> find wrong element
right -> find wrong element
swap
```

This idea is used in quicksort and Dutch National Flag solutions.

## 18.7 Dutch National Flag

For values `0`, `1`, `2`:

``` text
low    = 0
mid    = 0
high   = n-1

0 -> low region
1 -> middle region
2 -> high region
```

This gives O(n) time and O(1) extra space.

------------------------------------------------------------------------

# Part 19 -- Sorting Algorithms

## 19.1 `sort()`

``` cpp
std::sort(v.begin(), v.end());
```

Requires random-access iterators in the classic form.

Typical complexity guarantee is O(n log n) comparisons in modern C++
standards.

## 19.2 `stable_sort()`

Preserves relative order of equivalent elements.

``` cpp
std::stable_sort(v.begin(), v.end(), comp);
```

## 19.3 `partial_sort()`

Places the smallest `k` elements in sorted order at the front.

``` cpp
std::partial_sort(
    v.begin(),
    v.begin() + k,
    v.end()
);
```

## 19.4 `partial_sort_copy()`

Copies the smallest portion into a separate output range.

## 19.5 `nth_element()`

Places the element that would occur at position `n` if fully sorted at
`n`.

Elements before it are not necessarily sorted, but are not greater than
it under the ordering; elements after it are not necessarily sorted, but
are not less than it under the ordering.

``` cpp
std::nth_element(v.begin(), v.begin() + k, v.end());
```

## 19.6 `is_sorted()`

``` cpp
bool ok = std::is_sorted(v.begin(), v.end());
```

## 19.7 `is_sorted_until()`

Returns the first iterator where sortedness stops.

``` cpp
auto it = std::is_sorted_until(v.begin(), v.end());
```

------------------------------------------------------------------------

# Part 20 -- Sorting Fundamentals

## 20.1 Ascending

``` cpp
std::sort(v.begin(), v.end());
```

## 20.2 Descending

``` cpp
std::sort(
    v.begin(), v.end(),
    std::greater<>()
);
```

## 20.3 Custom Ordering

``` cpp
std::sort(
    v.begin(), v.end(),
    [](const Item& a, const Item& b) {
        return a.score > b.score;
    }
);
```

## 20.4 Strict Weak Ordering

A comparator must define a consistent ordering relation. Do not write:

``` cpp
return a <= b; // wrong for sort comparator
```

Prefer:

``` cpp
return a < b;
```

## 20.5 Sorting Objects

``` cpp
struct Student {
    std::string name;
    int marks;
};

std::sort(
    students.begin(),
    students.end(),
    [](const Student& a, const Student& b) {
        return a.marks > b.marks;
    }
);
```

## 20.6 Multi-Level Sorting

``` cpp
std::sort(
    students.begin(), students.end(),
    [](const Student& a, const Student& b) {
        if (a.marks != b.marks)
            return a.marks > b.marks;

        return a.name < b.name;
    }
);
```

This means:

``` text
marks descending
then name ascending
```

## 20.7 Pairs and Tuples

Pairs already have lexicographical comparison:

``` cpp
std::sort(v.begin(), v.end());
```

For custom ordering, provide a comparator.

------------------------------------------------------------------------

# Part 21 -- Internal Sorting Algorithms

## 21.1 Introsort

A common implementation strategy for `std::sort()` is introspective
sorting, combining techniques such as:

``` text
Quicksort-like partitioning
        ↓
Depth monitoring
        ↓
Heapsort fallback
        ↓
Small-range optimization
```

The exact implementation is library-specific.

## 21.2 Quicksort

Typical partition-based sort:

``` text
Choose pivot
Partition
Sort left
Sort right
```

Average:

``` text
O(n log n)
```

Worst case for naive quicksort:

``` text
O(n²)
```

## 21.3 Heapsort

Build heap and repeatedly move the largest/smallest element into its
final position.

Complexity:

``` text
O(n log n)
```

## 21.4 Insertion Sort

Efficient for small/nearly sorted ranges.

``` text
Take next element
Insert into sorted prefix
```

Typical worst case:

``` text
O(n²)
```

## 21.5 Why Hybrid Techniques?

Different algorithms have different strengths:

``` text
Quick partitioning -> fast average performance
Heap fallback      -> protects worst-case comparison complexity
Insertion strategy -> efficient for small ranges
```

The standard does not require one particular internal implementation.

------------------------------------------------------------------------

# Part 22 -- `sort()` in Detail

## 22.1 Syntax

``` cpp
std::sort(first, last);
std::sort(first, last, comp);
```

## 22.2 Default Comparator

Equivalent ordering is based on `std::less<>`-like semantics for the
element type.

## 22.3 Custom Comparator

``` cpp
std::sort(v.begin(), v.end(),
          [](int a, int b) {
              return a > b;
          });
```

## 22.4 Function Comparator

``` cpp
bool desc(int a, int b) {
    return a > b;
}

std::sort(v.begin(), v.end(), desc);
```

## 22.5 Functor Comparator

``` cpp
struct Desc {
    bool operator()(int a, int b) const {
        return a > b;
    }
};
```

## 22.6 Strings

``` cpp
std::sort(words.begin(), words.end());
```

## 22.7 Case-Insensitive Example

``` cpp
std::sort(
    words.begin(), words.end(),
    [](const std::string& a, const std::string& b) {
        return std::lexicographical_compare(
            a.begin(), a.end(),
            b.begin(), b.end(),
            [](unsigned char x, unsigned char y) {
                return std::tolower(x) < std::tolower(y);
            }
        );
    }
);
```

For production code, be careful with locale and character encoding.

------------------------------------------------------------------------

# Part 23 -- `stable_sort()`

## 23.1 Meaning

Stable sorting preserves the order of equivalent elements.

Example:

``` text
A: score 80
B: score 70
C: score 80
```

After stable sort descending:

``` text
A 80
C 80
B 70
```

A and C remain in their original relative order.

## 23.2 Use Cases

Use stable sorting when:

-   A previous ordering is meaningful.
-   Multiple sorting passes are used.
-   Records have equal keys and original order matters.

## 23.3 `sort()` vs `stable_sort()`

  ---------------------------------------------------------------------------
  Property                `sort()`                    `stable_sort()`
  ----------------------- --------------------------- -----------------------
  Stable                  No guarantee                Yes

  Typical complexity      O(n log n)                  O(n log n) comparisons
                                                      with sufficient memory

  Memory                  Implementation-dependent,   May use additional
                          generally in-place-oriented memory

  Use                     General sorting             Preserve equivalent
                                                      order
  ---------------------------------------------------------------------------

------------------------------------------------------------------------

# Part 24 -- Partial Sorting

## 24.1 `partial_sort()`

If you need the smallest `k` values sorted:

``` cpp
std::partial_sort(
    v.begin(),
    v.begin() + k,
    v.end()
);
```

The first `k` elements are sorted.

The remainder is not sorted.

## 24.2 Top-K

For top K largest:

``` cpp
std::partial_sort(
    v.begin(),
    v.begin() + k,
    v.end(),
    std::greater<>()
);
```

## 24.3 Partial Sort vs Full Sort

If only a small prefix matters, partial sorting may avoid fully sorting
the entire range.

Typical complexity:

``` text
O(n log k)
```

for `partial_sort`.

------------------------------------------------------------------------

# Part 25 -- `nth_element()`

## 25.1 Definition

`nth_element(first, nth, last)` rearranges a range so that the element
at `nth` is the element that would occur there after sorting.

Example:

``` cpp
std::vector<int> v{7,1,5,2,9,3};

std::nth_element(v.begin(), v.begin() + 2, v.end());
```

Now `v[2]` is the third-smallest element, although the entire vector is
not sorted.

## 25.2 Kth Smallest

For 1-based k:

``` cpp
std::nth_element(
    v.begin(),
    v.begin() + (k - 1),
    v.end()
);

int kth = v[k - 1];
```

## 25.3 Kth Largest

``` cpp
std::nth_element(
    v.begin(),
    v.end() - k,
    v.end()
);

int kthLargest = v[v.size() - k];
```

## 25.4 Median

For odd `n`:

``` cpp
std::nth_element(
    v.begin(),
    v.begin() + n / 2,
    v.end()
);

int median = v[n / 2];
```

## 25.5 Complexity

The standard gives an average linear-time complexity guarantee for
comparisons for the classic algorithm. Do not assume the whole range
becomes sorted.

------------------------------------------------------------------------

# Part 26 -- Binary Search Algorithms

Binary-search algorithms require a suitable sorted/partitioned range
under the ordering used.

Main algorithms:

``` cpp
binary_search()
lower_bound()
upper_bound()
equal_range()
```

------------------------------------------------------------------------

# Part 27 -- Binary Search Prerequisites

## 27.1 Sorted Range

Example:

``` text
1 2 2 4 7 9
```

is sorted ascending.

Then:

``` cpp
std::lower_bound(...)
std::upper_bound(...)
```

can be used with matching ordering.

## 27.2 Partitioned Range

The most precise requirement for several standard algorithms is that the
range be partitioned with respect to the tested ordering/expression.

## 27.3 Iterator Requirements

The number of comparisons is logarithmic for appropriate random-access
ranges. For forward iterators, iterator increments can make total
traversal work linear even though the comparison count remains
logarithmic.

## 27.4 Comparator Requirements

The comparator/order used to search must agree with the ordering used to
organize the range.

Wrong:

``` cpp
std::sort(v.begin(), v.end(), std::greater<>());
std::lower_bound(v.begin(), v.end(), 5); // wrong ordering
```

Correct:

``` cpp
std::lower_bound(
    v.begin(), v.end(), 5,
    std::greater<>()
);
```

------------------------------------------------------------------------

# Part 28 -- `binary_search()`

## 28.1 Definition

Returns whether a value exists.

``` cpp
bool found = std::binary_search(
    v.begin(), v.end(), 7
);
```

## 28.2 Return Type

``` cpp
bool
```

## 28.3 Internal Working

Conceptually:

``` text
middle
  |
  +-- target smaller -> search left
  |
  +-- target larger  -> search right
```

## 28.4 Complexity

Logarithmic comparisons for suitable random-access ranges.

## 28.5 Custom Comparator

``` cpp
bool found = std::binary_search(
    v.begin(), v.end(), 7,
    std::greater<>()
);
```

------------------------------------------------------------------------

# Part 29 -- `lower_bound()`

## 29.1 Definition

Returns the first iterator `it` such that the element is **not less
than** the target under the chosen ordering.

For ascending values, it is the first position where:

``` text
value >= target
```

Example:

``` text
1 2 2 2 5 8
      ^
lower_bound(2)
```

points to the first `2`.

## 29.2 Syntax

``` cpp
auto it = std::lower_bound(
    v.begin(), v.end(), target
);
```

## 29.3 Index

``` cpp
int index = static_cast<int>(
    it - v.begin()
);
```

This subtraction requires random-access iterators.

For generic iterators:

``` cpp
auto index = std::distance(v.begin(), it);
```

## 29.4 Insertion Position

In a sorted vector, `lower_bound` gives the conventional insertion
position for placing a target before equivalent elements.

## 29.5 Frequency

``` cpp
auto first = std::lower_bound(v.begin(), v.end(), x);
auto last  = std::upper_bound(v.begin(), v.end(), x);

std::size_t freq = last - first;
```

------------------------------------------------------------------------

# Part 30 -- `upper_bound()`

## 30.1 Definition

Returns the first position after all elements equivalent to the target.

For ascending values, it is the first position where:

``` text
value > target
```

Example:

``` text
1 2 2 2 5
      ^
upper_bound(2)
```

points to `5`.

## 30.2 Frequency

``` cpp
auto freq =
    std::upper_bound(v.begin(), v.end(), x)
    - std::lower_bound(v.begin(), v.end(), x);
```

------------------------------------------------------------------------

# Part 31 -- `equal_range()`

Returns both boundaries:

``` cpp
auto [first, last] =
    std::equal_range(v.begin(), v.end(), x);
```

Equivalent conceptually to:

``` cpp
lower_bound(x)
upper_bound(x)
```

Frequency for random-access iterators:

``` cpp
auto count = last - first;
```

------------------------------------------------------------------------

# Part 32 -- Heap Fundamentals

## 32.1 Binary Heap

A binary heap is a complete binary tree satisfying a heap ordering property.

**Max heap:**
``` text
parent >= children
```

**Min heap:**
``` text
parent <= children
```

## 32.2 Array Representation

For zero-based index `i`:

``` text
parent = (i - 1) / 2
left   = 2*i + 1
right  = 2*i + 2
```

for valid nodes.

## 32.3 Max Heap

Default heap algorithms use `operator<`-based ordering, giving the
largest element at the front.

``` cpp
std::make_heap(v.begin(), v.end());
```

## 32.4 Min Heap

Use `std::greater<>`:

``` cpp
std::make_heap(
    v.begin(), v.end(),
    std::greater<>()
);
```

------------------------------------------------------------------------

# Part 33 -- Heap Algorithms

## 33.1 `make_heap()`

Builds a heap in linear time.

``` cpp
std::make_heap(v.begin(), v.end());
```

## 33.2 `push_heap()`

Assuming `[begin, end-1)` is already a heap, place the newly appended
element into the heap:

``` cpp
v.push_back(x);
std::push_heap(v.begin(), v.end());
```

## 33.3 `pop_heap()`

Moves the heap's top element to the last position and restores the heap
property in the remaining range.

``` cpp
std::pop_heap(v.begin(), v.end());

int top = v.back();
v.pop_back();
```

## 33.4 `sort_heap()`

Sorts a heap range.

``` cpp
std::sort_heap(v.begin(), v.end());
```

The range must already be a heap.

## 33.5 `is_heap()`

``` cpp
bool ok = std::is_heap(v.begin(), v.end());
```

## 33.6 `is_heap_until()`

Returns the first position where the heap property is violated.

------------------------------------------------------------------------

# Part 34 -- Heap Internal Working

## 34.1 Heapify

`make_heap()` organizes the array so the heap property holds.

A conceptual bottom-up heap construction starts from the last parent and
sifts elements downward.

## 34.2 Sift Up

Used after insertion:

``` text
insert at end
compare with parent
swap while heap property is violated
```

## 34.3 Sift Down

Used after removing the root:

``` text
move replacement to root
compare with children
swap with appropriate child
continue
```

## 34.4 Push

``` cpp
v.push_back(value);
std::push_heap(v.begin(), v.end());
```

## 34.5 Pop

``` cpp
std::pop_heap(v.begin(), v.end());
auto top = v.back();
v.pop_back();
```

## 34.6 Heap Sort

Conceptually:

``` text
build heap
repeat:
    move top to final position
    restore heap
```

Complexity:

``` text
O(n log n)
```

------------------------------------------------------------------------

# Part 35 -- Set Algorithms

Set algorithms operate on sorted ranges under a consistent ordering.

## 35.1 `includes()`

Checks whether every element in one sorted range is present in another.

``` cpp
bool ok = std::includes(
    a.begin(), a.end(),
    b.begin(), b.end()
);
```

## 35.2 `set_union()`

Produces all elements from both ranges while respecting multiplicities.

``` cpp
std::set_union(
    a.begin(), a.end(),
    b.begin(), b.end(),
    out.begin()
);
```

## 35.3 `set_intersection()`

Produces common elements, with duplicate multiplicity handled according
to multiset-style set algorithm semantics.

## 35.4 `set_difference()`

Elements present in first range but not the second.

## 35.5 `set_symmetric_difference()`

Elements present in exactly one of the two ranges.

## 35.6 `merge()`

Merges two sorted ranges into a destination range.

Unlike set union, duplicate values from both ranges are retained.

## 35.7 `inplace_merge()`

Merges two consecutive sorted subranges:

``` text
[first, middle)
[middle, last)
```

into one sorted range.

------------------------------------------------------------------------

# Part 36 -- Set Algorithm Concepts

## 36.1 Sorted Input

Example:

``` text
A: 1 2 4 6
B: 2 3 4 7
```

## 36.2 Two-Pointer Technique

Conceptually:

``` text
i -> A
j -> B

if A[i] < B[j] -> advance i
if B[j] < A[i] -> advance j
equal           -> process both
```

This is why these algorithms are generally linear in the input sizes.

## 36.3 Union

``` text
A = {1,2,4}
B = {2,3,4}

union = {1,2,3,4}
```

## 36.4 Intersection

``` text
intersection = {2,4}
```

## 36.5 Difference

``` text
A - B = {1}
```

## 36.6 Symmetric Difference

``` text
{1,3}
```

------------------------------------------------------------------------

# Part 37 -- Min/Max Algorithms

## 37.1 `min()`

``` cpp
int x = std::min(a, b);
```

## 37.2 `max()`

``` cpp
int x = std::max(a, b);
```

## 37.3 `minmax()`

``` cpp
auto [lo, hi] = std::minmax(a, b);
```

## 37.4 `min_element()`

``` cpp
auto it = std::min_element(v.begin(), v.end());
```

## 37.5 `max_element()`

``` cpp
auto it = std::max_element(v.begin(), v.end());
```

## 37.6 `minmax_element()`

Finds both in one algorithmic pass, using fewer comparisons than independently finding both in common cases.

``` cpp
auto [mn, mx] = std::minmax_element(v.begin(), v.end());
```

## 37.7 `clamp()` --- C++17

``` cpp
int x = std::clamp(value, low, high);
```

If `value < low`, returns `low`; if `value > high`, returns `high`; otherwise returns `value`.

------------------------------------------------------------------------

# Part 38 -- Comparison Algorithms

## 38.1 `equal()`

Tests element-wise equality.

## 38.2 `mismatch()`

Returns the first differing pair of positions.

## 38.3 `lexicographical_compare()`

Compares sequences like dictionary order.

Example:

``` text
"apple" < "banana"
```

Also:

``` text
[1,2,3] < [1,2,4]
```

because the first differing element is `3 < 4`.

## 38.4 Three-Way Comparison

C++20 provides:

``` cpp
std::lexicographical_compare_three_way(
    a.begin(), a.end(),
    b.begin(), b.end()
);
```

It returns a comparison category result when the element types support
the necessary three-way comparison.

------------------------------------------------------------------------

# Part 39 -- Permutation Algorithms

## 39.1 `next_permutation()`

Transforms a sequence into its next lexicographical permutation.

``` cpp
std::vector<int> v{1,2,3};

do {
    // use v
} while (std::next_permutation(v.begin(), v.end()));
```

## 39.2 `prev_permutation()`

Generates the previous lexicographical permutation.

## 39.3 Next Permutation Algorithm

For:

``` text
1 2 3 5 4
```

1.  Find the longest non-increasing suffix.
2.  Find the pivot just before it.
3.  Find the smallest successor larger than the pivot.
4.  Swap pivot and successor.
5.  Reverse the suffix.

## 39.4 Duplicate Elements

Duplicates are handled naturally when the input is ordered.

To generate all unique permutations:

``` cpp
std::sort(v.begin(), v.end());

do {
    // unique lexicographical permutation
} while (std::next_permutation(v.begin(), v.end()));
```

------------------------------------------------------------------------

# Part 40 -- Numeric Algorithms (`<numeric>`)

## 40.1 `iota()`

Fills with sequentially increasing values.

``` cpp
std::iota(v.begin(), v.end(), 1);
```

Result:

``` text
1 2 3 4 5
```

## 40.2 `accumulate()`

Left-to-right accumulation.

``` cpp
int sum = std::accumulate(
    v.begin(), v.end(), 0
);
```

## 40.3 `reduce()`

Reduction that is designed to work with execution policies and may
reorder operations.

``` cpp
int sum = std::reduce(
    v.begin(), v.end(), 0
);
```

## 40.4 `inner_product()`

Combines corresponding elements of two ranges into one accumulated
result.

``` cpp
int dot = std::inner_product(
    a.begin(), a.end(),
    b.begin(),
    0
);
```

## 40.5 `partial_sum()`

Produces cumulative results:

``` text
1 2 3 4
```

becomes:

``` text
1 3 6 10
```

## 40.6 `adjacent_difference()`

For:

``` text
1 4 9 16
```

produces:

``` text
1 3 5 7
```

with the first output equal to the first input under the default
operation.

## 40.7 `inclusive_scan()`

Prefix operation where the current input participates.

## 40.8 `exclusive_scan()`

Prefix operation where the current input is excluded.

## 40.9 `transform_reduce()`

Combines transformation and reduction, conceptually:

``` text
transform each input
then reduce
```

Useful for dot products and parallel numeric work.

## 40.10 Transform Scans

`transform_inclusive_scan()` and `transform_exclusive_scan()` combine
transformation with prefix scanning.

## 40.11 `gcd()` and `lcm()` --- C++17

``` cpp
std::gcd(24, 18); // 6
std::lcm(12, 18); // 36
```

## 40.12 `midpoint()` --- C++20

Computes a midpoint while avoiding some overflow issues associated with
naive:

``` cpp
(a + b) / 2
```

Example:

``` cpp
auto m = std::midpoint(a, b);
```

------------------------------------------------------------------------

# Part 41 -- `accumulate()`

## 41.1 Sum

``` cpp
int sum =
    std::accumulate(v.begin(), v.end(), 0);
```

## 41.2 Product

``` cpp
long long product =
    std::accumulate(
        v.begin(), v.end(),
        1LL,
        std::multiplies<long long>()
    );
```

## 41.3 String Concatenation

``` cpp
std::string result =
    std::accumulate(
        words.begin(), words.end(),
        std::string{},
        [](std::string acc, const std::string& s) {
            return acc + s;
        }
    );
```

For many strings, repeated concatenation can be inefficient; prefer a
suitable builder/output strategy when performance matters.

## 41.4 Custom Operation

``` cpp
int result = std::accumulate(
    v.begin(), v.end(),
    0,
    [](int acc, int x) {
        return acc + x * x;
    }
);
```

## 41.5 Initial Value Controls Result Type

This is important:

``` cpp
std::accumulate(v.begin(), v.end(), 0);
```

accumulates as `int`.

For larger totals:

``` cpp
std::accumulate(v.begin(), v.end(), 0LL);
```

------------------------------------------------------------------------

# Part 42 -- `reduce()`

## 42.1 Difference from `accumulate()`

`accumulate()` performs ordered left-to-right accumulation.

`reduce()` permits grouping/reordering and therefore is more suitable
for parallel reduction.

For operations where grouping changes the result, results can differ.

## 42.2 Associativity

Parallel/reordered reduction works best when the operation is
associative:

``` text
(a op b) op c == a op (b op c)
```

Addition over mathematical integers is associative; floating-point
addition is not exactly associative due to rounding.

## 42.3 Commutativity

For arbitrary reordering, commutativity can also be important depending
on the overload/operation and execution policy.

## 42.4 Floating Point

Do not expect bit-for-bit identical results when a floating-point
reduction changes the grouping/order of additions.

------------------------------------------------------------------------

# Part 43 -- Prefix and Scan Algorithms

## 43.1 Prefix Sum

``` cpp
std::vector<int> prefix(n);

std::partial_sum(
    v.begin(), v.end(),
    prefix.begin()
);
```

## 43.2 `partial_sum()` vs `inclusive_scan()`

Both can produce inclusive cumulative results, but scans are designed as
part of the modern numeric/parallel algorithm family.

## 43.3 Exclusive Scan

``` cpp
std::exclusive_scan(
    v.begin(), v.end(),
    out.begin(),
    0
);
```

For:

``` text
1 2 3 4
```

result is:

``` text
0 1 3 6
```

## 43.4 Prefix Product

``` cpp
std::inclusive_scan(
    v.begin(), v.end(),
    out.begin(),
    std::multiplies<>()
);
```

## 43.5 Prefix Maximum

``` cpp
std::inclusive_scan(
    v.begin(), v.end(),
    out.begin(),
    [](int a, int b) {
        return std::max(a, b);
    }
);
```

------------------------------------------------------------------------

# Part 44 -- Mathematical Algorithms

## 44.1 Euclidean Algorithm

`gcd(a,b)` repeatedly uses remainders:

``` text
gcd(a,b) = gcd(b, a % b)
```

until the remainder becomes zero.

## 44.2 Overflow

Even if inputs fit in a type, arithmetic such as:

``` cpp
a + b
```

can overflow. Use suitable types and `std::midpoint()` when calculating
a midpoint.

## 44.3 Signed and Unsigned

Be careful when mixing:

``` cpp
int
std::size_t
unsigned
```

Conversions can produce unexpected results.

------------------------------------------------------------------------

# Part 45 -- Custom Comparators

## 45.1 Function Comparator

``` cpp
bool cmp(int a, int b) {
    return a < b;
}
```

## 45.2 Lambda

``` cpp
auto cmp = [](int a, int b) {
    return a > b;
};
```

## 45.3 Functor

``` cpp
struct Compare {
    bool operator()(int a, int b) const {
        return a > b;
    }
};
```

## 45.4 Multi-Level Comparator

``` cpp
[](const Employee& a, const Employee& b) {
    if (a.department != b.department)
        return a.department < b.department;

    if (a.salary != b.salary)
        return a.salary > b.salary;

    return a.name < b.name;
}
```

## 45.5 Comparator Consistency

The comparator must not change its answer unpredictably for the same
pair while an algorithm is operating.

------------------------------------------------------------------------

# Part 46 -- Strict Weak Ordering

For sorting and many ordered STL facilities, a comparator is expected to
establish a strict weak ordering.

## 46.1 Irreflexivity

For every `x`:

``` text
comp(x, x) == false
```

## 46.2 Asymmetry

If:

``` text
comp(a,b) == true
```

then:

``` text
comp(b,a) == false
```

## 46.3 Transitivity

If:

``` text
a < b
b < c
```

then:

``` text
a < c
```

## 46.4 Equivalence

Two values can be considered equivalent when:

``` text
!comp(a,b) && !comp(b,a)
```

This does not necessarily mean `a == b`.

## 46.5 Common Wrong Comparator

Wrong:

``` cpp
[](int a, int b) {
    return a <= b;
}
```

Correct:

``` cpp
[](int a, int b) {
    return a < b;
}
```

------------------------------------------------------------------------

# Part 47 -- Iterator Categories

## 47.1 Input Iterator

Supports reading sequentially.

Typical operations:

``` text
read
increment
compare
```

## 47.2 Output Iterator

Supports writing through an iterator.

## 47.3 Forward Iterator

Supports multi-pass traversal and forward movement.

## 47.4 Bidirectional Iterator

Adds:

``` cpp
--it;
```

Examples include `list`, `set`, and `map` iterators.

## 47.5 Random Access Iterator

Supports:

``` cpp
it + n
it - n
it[n]
it1 - it2
it1 < it2
```

`vector`, `deque`, and `array` iterators satisfy random-access
requirements.

## 47.6 Contiguous Iterator

C++20 concept/category related to iterators whose referenced objects
occupy contiguous storage.

`vector`, `array`, and built-in arrays provide contiguous iteration.

------------------------------------------------------------------------

# Part 48 -- Iterator Requirements by Algorithm

  Algorithm         Typical minimum requirement
  ----------------- --------------------------------
  `find`            Input
  `count`           Input
  `for_each`        Input
  `copy`            Input + output
  `reverse`         Bidirectional
  `rotate`          Forward in general
  `partition`       Bidirectional
  `sort`            Random access
  `nth_element`     Random access
  `make_heap`       Random access
  `binary_search`   Forward
  `lower_bound`     Forward
  `list::sort`      List's bidirectional iterators

Important: minimum iterator category is not the same as total runtime. A
forward iterator can support binary search comparisons but may require
linear iterator movement.

------------------------------------------------------------------------

# Part 49 -- Execution Policies

C++17 introduced standard execution policies.

## 49.1 `seq`

``` cpp
std::execution::seq
```

Sequential execution.

## 49.2 `par`

``` cpp
std::execution::par
```

Permits parallel execution.

## 49.3 `par_unseq`

Permits parallel and unsequenced execution under stricter callable
requirements.

## 49.4 `unseq` --- C++20

Allows unsequenced execution for supported algorithms.

Example:

``` cpp
std::sort(
    std::execution::par,
    v.begin(), v.end()
);
```

Not every algorithm/overload supports every execution policy.

## 49.5 Thread Safety and Data Races

A parallel algorithm can execute callable invocations concurrently.
Avoid unsynchronized shared mutable state.

Bad pattern:

``` cpp
int total = 0;

std::for_each(
    std::execution::par,
    v.begin(), v.end(),
    [&](int x) {
        total += x; // data race
    }
);
```

Prefer a reduction algorithm:

``` cpp
auto total = std::reduce(
    std::execution::par,
    v.begin(), v.end(),
    0LL
);
```

## 49.6 Exceptions

Execution-policy overloads have special exception behavior. Do not
assume exceptions behave exactly like sequential overloads. Consult the
standard/library documentation for the specific policy and
implementation.

------------------------------------------------------------------------

# Part 50 -- Parallel Algorithms

Examples include policy-enabled forms of many algorithms such as:

``` cpp
for_each
sort
reduce
transform
copy
```

## When Parallel Helps

-   Large data.
-   Expensive per-element work.
-   Multiple cores available.
-   Low synchronization overhead.

## When Parallel Hurts

-   Tiny input.
-   Cheap operations.
-   High synchronization cost.
-   Poor memory locality.
-   Heavy contention.
-   Work that is inherently sequential.

------------------------------------------------------------------------

# Part 51 -- C++20 Ranges

Ranges improve readability and type constraints.

Classic:

``` cpp
std::sort(v.begin(), v.end());
```

Ranges:

``` cpp
std::ranges::sort(v);
```

## 51.1 `<ranges>`

``` cpp
#include <ranges>
```

Many range algorithms are available in `std::ranges`.

## 51.2 Iterator-Sentinel Model

A range does not always require begin/end to have exactly the same type.
A sentinel can mark the end.

## 51.3 Concepts

Ranges algorithms use concepts to constrain valid types.

This produces clearer compile-time diagnostics and documents
requirements.

## 51.4 Projections

A projection lets an algorithm operate on a selected property without
manually writing a comparator in many cases.

Example:

``` cpp
std::ranges::sort(
    students,
    {},
    &Student::marks
);
```

## 51.5 Views

Views represent lazy range transformations.

Common views:

``` cpp
std::views::filter
std::views::transform
std::views::take
std::views::drop
```

Example:

``` cpp
auto evens =
    v | std::views::filter([](int x) {
        return x % 2 == 0;
    });
```

------------------------------------------------------------------------

# Part 52 -- C++20 Ranges Algorithms

Common ranges versions include:

``` cpp
std::ranges::for_each
std::ranges::for_each_n
std::ranges::all_of
std::ranges::any_of
std::ranges::none_of
std::ranges::count
std::ranges::count_if
std::ranges::find
std::ranges::find_if
std::ranges::find_if_not
std::ranges::find_end
std::ranges::find_first_of
std::ranges::adjacent_find
std::ranges::search
std::ranges::search_n
```

Example:

``` cpp
auto it = std::ranges::find(v, 10);
```

No explicit `begin()`/`end()` is required.

------------------------------------------------------------------------

# Part 53 -- C++20 Ranges Modifying Algorithms

Common examples:

``` cpp
std::ranges::copy
std::ranges::copy_if
std::ranges::copy_n
std::ranges::copy_backward
std::ranges::move
std::ranges::move_backward
std::ranges::fill
std::ranges::fill_n
std::ranges::generate
std::ranges::generate_n
std::ranges::remove
std::ranges::remove_if
std::ranges::replace
std::ranges::replace_if
std::ranges::reverse
std::ranges::rotate
std::ranges::shuffle
std::ranges::unique
std::ranges::transform
```

Example:

``` cpp
std::ranges::transform(
    v, v.begin(),
    [](int x) { return x * x; }
);
```

------------------------------------------------------------------------

# Part 54 -- C++20 Ranges Sorting

``` cpp
std::ranges::sort(v);
std::ranges::stable_sort(v);
std::ranges::partial_sort(v, v.begin() + k);
std::ranges::nth_element(v, v.begin() + k);
std::ranges::is_sorted(v);
std::ranges::is_sorted_until(v);
```

The range overloads are usually easier to read and can use projections.

------------------------------------------------------------------------

# Part 55 -- C++20 Ranges Binary Search

``` cpp
std::ranges::binary_search(v, x);
std::ranges::lower_bound(v, x);
std::ranges::upper_bound(v, x);
std::ranges::equal_range(v, x);
```

Projection example:

``` cpp
auto it = std::ranges::lower_bound(
    students,
    80,
    {},
    &Student::marks
);
```

The students must be ordered according to the projected marks and
comparator.

------------------------------------------------------------------------

# Part 56 -- C++20 Ranges Partitioning

``` cpp
std::ranges::partition(v, pred);
std::ranges::stable_partition(v, pred);
std::ranges::partition_copy(v, out1, out2, pred);
std::ranges::partition_point(v, pred);
std::ranges::is_partitioned(v, pred);
```

------------------------------------------------------------------------

# Part 57 -- C++20 Ranges Heap Algorithms

``` cpp
std::ranges::make_heap(v);
std::ranges::push_heap(v);
std::ranges::pop_heap(v);
std::ranges::sort_heap(v);
std::ranges::is_heap(v);
std::ranges::is_heap_until(v);
```

Custom ordering:

``` cpp
std::ranges::make_heap(v, std::greater<>());
```

------------------------------------------------------------------------

# Part 58 -- C++20 Ranges Set Algorithms

Common range algorithms:

``` cpp
std::ranges::merge
std::ranges::includes
std::ranges::set_union
std::ranges::set_intersection
std::ranges::set_difference
std::ranges::set_symmetric_difference
```

These require appropriately ordered input ranges and compatible output
storage.

------------------------------------------------------------------------

# Part 59 -- C++20 Ranges Projections

## 59.1 What Is a Projection?

A projection maps an element to the property used by an algorithm.

``` cpp
struct Student {
    std::string name;
    int marks;
};
```

Instead of:

``` cpp
std::ranges::sort(
    students,
    [](const Student& a, const Student& b) {
        return a.marks < b.marks;
    }
);
```

you can use:

``` cpp
std::ranges::sort(
    students,
    {},
    &Student::marks
);
```

## 59.2 Projection vs Comparator

Comparator:

``` text
comp(a,b)
```

Projection:

``` text
proj(a) -> key
proj(b) -> key
```

The algorithm compares the projected keys according to its ordering.

## 59.3 Searching by Member

``` cpp
auto it = std::ranges::find(
    students,
    90,
    &Student::marks
);
```

This searches for a student whose projected marks equal 90.

------------------------------------------------------------------------

# Part 60 -- C++20 Concepts Used by Algorithms

Important concepts include:

``` text
sortable
predicate
indirect_unary_predicate
indirect_binary_predicate
indirect_strict_weak_order
permutable
mergeable
indirectly_copyable
```

Concepts formally describe requirements on iterators, values,
predicates, and operations.

For example, `sortable` expresses that an iterator can be permuted
according to a valid ordering relation.

------------------------------------------------------------------------

# Part 61 -- Algorithm Complexity

## O(1)

Constant work.

Example:

``` cpp
std::min(a,b);
```

## O(log n)

Binary-search-style comparison complexity on suitable ranges.

## O(n)

Linear scan:

``` cpp
find
count
fill
reverse
```

## O(n log n)

Typical full sorting:

``` cpp
sort
stable_sort
```

## O(n²)

Some naive manual algorithms.

The goal is not to memorize only Big-O. Also consider:

``` text
constant factors
cache locality
allocation
iterator category
comparison cost
move/copy cost
```

------------------------------------------------------------------------

# Part 62 -- Complete Complexity Table

  -----------------------------------------------------------------------
  Algorithm                           Typical/standard complexity summary
  ------------------------------ ----------------------------------------
  `find`                                                             O(n)

  `find_if`                                                          O(n)

  `count`                                                            O(n)

  `count_if`                                                         O(n)

  `all_of`                                           O(n), may stop early

  `any_of`                                           O(n), may stop early

  `none_of`                                          O(n), may stop early

  `for_each`                                                         O(n)

  `copy`                                                             O(n)

  `copy_if`                                                          O(n)

  `transform`                                                        O(n)

  `replace`                                                          O(n)

  `fill`                                                             O(n)

  `remove`                                                           O(n)

  `unique`                                                           O(n)

  `reverse`                                                          O(n)

  `rotate`                                                           O(n)

  `partition`                                                        O(n)

  `sort`                                           O(n log n) comparisons

  `stable_sort`                    O(n log n) comparisons with sufficient
                                   memory; may differ with limited memory

  `partial_sort`                                               O(n log k)

  `nth_element`                                  O(n) average comparisons

  `binary_search`                                    O(log n) comparisons

  `lower_bound`                                      O(log n) comparisons

  `upper_bound`                                      O(log n) comparisons

  `make_heap`                                                        O(n)

  `push_heap`                                                    O(log n)

  `pop_heap`                                                     O(log n)

  `sort_heap`                                                  O(n log n)

  `min_element`                                                      O(n)

  `max_element`                                                      O(n)

  `next_permutation`                                                 O(n)

  `accumulate`                                            O(n) operations

  `reduce`                              O(n) operations, order may differ

  `partial_sum`                                                      O(n)

  `iota`                                                             O(n)
  -----------------------------------------------------------------------

**Important:** Iterator movement and exact overload requirements can
alter the total practical cost. Always consult the exact algorithm
specification for strict guarantees.

------------------------------------------------------------------------

# Part 63 -- Iterator Invalidation

Iterator invalidation occurs when an iterator no longer refers to the
same valid element after a container operation.

## Vector

Operations that reallocate invalidate all iterators/references/pointers.
Erasing also invalidates iterators/references at or after the erase
point.

## Deque

Invalidation rules are more complicated and depend on the operation.

## List

Insertion/erasure generally preserves iterators to other elements.

## Set/Map

Insertion generally preserves existing iterators; erasing an element
invalidates iterators to that element.

## Unordered Containers

Rehashing invalidates iterators; references/pointers have different
guarantees. Consult the exact operation.

## Algorithms

Algorithms that rearrange elements can change values associated with
iterators without necessarily invalidating the iterators themselves.
Container-modifying operations are a separate concern.

------------------------------------------------------------------------

# Part 64 -- Algorithm Behavior and Guarantees

## Stable

Examples:

``` cpp
stable_sort
stable_partition
```

## Return Iterator

Examples:

``` cpp
find
remove
unique
lower_bound
upper_bound
```

## Return Pair

Examples:

``` cpp
mismatch
equal_range
minmax
minmax_element
```

## Return Boolean

Examples:

``` cpp
binary_search
is_sorted
all_of
any_of
none_of
is_heap
```

## Require Sorted Input

Examples:

``` cpp
binary_search
lower_bound
upper_bound
equal_range
set algorithms
merge
```

## Require Partitioned Input

Examples include:

``` cpp
partition_point
lower_bound
upper_bound
binary_search
```

where partitioning is relative to the supplied ordering/test.

------------------------------------------------------------------------

# Part 65 -- STL Algorithm Comparisons

## `sort()` vs `stable_sort()`

Use `sort()` unless relative ordering of equivalent elements matters.

## `sort()` vs `partial_sort()`

Use `partial_sort()` when only a sorted prefix of size `k` is required.

## `sort()` vs `nth_element()`

Use `nth_element()` when you only need the element/rank partition, not
full ordering.

## `copy()` vs `move()`

Copy retains source values; move transfers resources where possible.

## `copy()` vs `copy_backward()`

Both copy, but `copy_backward()` writes from the end and is designed for
the appropriate overlapping direction.

## `remove()` vs `erase()`

`remove()` rearranges/logically removes; `erase()` changes container
size.

## `find()` vs `binary_search()`

`find()` works on unsorted ranges and is linear. `binary_search()`
requires suitable ordering and provides logarithmic comparisons.

## `lower_bound()` vs `upper_bound()`

``` text
lower_bound -> first >= x
upper_bound -> first > x
```

for ascending order.

## `equal_range()`

Returns both boundaries.

## `make_heap()` vs `priority_queue`

Heap algorithms operate on an existing range. `priority_queue` is a
container adaptor that manages heap behavior for you.

## `accumulate()` vs `reduce()`

`accumulate()` is ordered; `reduce()` allows reordering and is designed
for parallel reduction.

------------------------------------------------------------------------

# Part 66 -- Container and Algorithm Compatibility

## Vector

Excellent with:

``` text
sort
binary search
heap
random access
ranges
```

## Array

Excellent with algorithms; contiguous and fixed-size.

## Deque

Random-access iterators, so many algorithms work.

## List

Bidirectional iterators. Use:

``` cpp
list.sort();
```

rather than `std::sort`.

## Forward List

Forward iterators; fewer algorithms are available because
bidirectional/random access operations are unavailable.

## Set / Map

Ordered associative containers have bidirectional iterators. Their
iterators cannot be used with `std::sort`.

## Unordered Containers

Forward-iterator-like traversal; no ordering is guaranteed.

------------------------------------------------------------------------

# Part 67 -- `sort()` and Containers

## Why `sort(vector)` Works

`vector` provides random-access iterators.

## Why `sort(array)` Works

`array` provides random-access iterators.

## Why `sort(deque)` Works

`deque` provides random-access iterators.

## Why `sort(list)` Does Not Work

`list` provides bidirectional iterators, not random-access iterators.

Use:

``` cpp
myList.sort();
```

## Why Linked Lists Need Member Sort

A linked list can efficiently rearrange nodes by relinking them without
requiring random access.

------------------------------------------------------------------------

# Part 68 -- Remove-Erase Idiom

The classic pattern:

``` cpp
v.erase(
    std::remove(v.begin(), v.end(), value),
    v.end()
);
```

For a predicate:

``` cpp
v.erase(
    std::remove_if(
        v.begin(), v.end(),
        [](int x) { return x < 0; }
    ),
    v.end()
);
```

For duplicates:

``` cpp
std::sort(v.begin(), v.end());
v.erase(
    std::unique(v.begin(), v.end()),
    v.end()
);
```

C++20:

``` cpp
std::erase(v, value);
std::erase_if(v, pred);
```

------------------------------------------------------------------------

# Part 69 -- Algorithm Design Patterns

## 69.1 Two Pointer

Use sorted data or opposing ends.

Example:

``` text
left -> 
        sum
<- right
```

## 69.2 Sliding Window

Maintain a changing subrange.

## 69.3 Sorting + Greedy

Many interval problems become simple after sorting by end time.

## 69.4 Binary Search on Sorted Data

Use:

``` cpp
lower_bound
upper_bound
binary_search
```

## 69.5 Binary Search on Answer

Search a numeric answer space when a feasibility predicate is monotonic.

## 69.6 Prefix Sum

``` cpp
prefix[i] = prefix[i-1] + a[i];
```

Use `partial_sum`/`inclusive_scan` when appropriate.

## 69.7 Difference Array

For range updates:

``` text
diff[l] += x
diff[r+1] -= x
```

then prefix-sum the difference array.

## 69.8 Partition

Use `partition`, `stable_partition`, or manual two-pointer logic.

## 69.9 Heap

Use for:

``` text
top K
priority scheduling
running extremes
merge K sorted sequences
```

## 69.10 Coordinate Compression

``` text
copy values
sort
unique
map original values to lower_bound positions
```

------------------------------------------------------------------------

# Part 70 -- Competitive Programming Applications

STL algorithms frequently simplify:

-   Searching.
-   Sorting.
-   Frequency calculations.
-   Duplicate removal.
-   Kth-element problems.
-   Top-K problems.
-   Range queries.
-   Prefix sums.
-   Permutation generation.
-   Greedy scheduling.
-   Interval merging.
-   String processing.

Example coordinate compression:

``` cpp
std::vector<int> b = a;
std::sort(b.begin(), b.end());
b.erase(std::unique(b.begin(), b.end()), b.end());

for (int x : a) {
    int compressed =
        std::lower_bound(b.begin(), b.end(), x) - b.begin();
}
```

------------------------------------------------------------------------

# Part 71 -- Greedy Algorithms Using STL

## Activity Selection

Sort intervals by finish time:

``` cpp
std::sort(
    jobs.begin(), jobs.end(),
    [](const auto& a, const auto& b) {
        return a.end < b.end;
    }
);
```

Then repeatedly choose the next compatible activity.

## Merge Intervals

Sort by start:

``` cpp
std::sort(
    intervals.begin(), intervals.end()
);
```

Then merge overlapping intervals.

## Fractional Knapsack

Sort by:

``` text
value / weight
```

descending.

## Job Sequencing

Sort by profit/deadline and use an appropriate scheduling structure.

------------------------------------------------------------------------

# Part 72 -- Heap-Based Problems

## Kth Largest

For one-off selection:

``` cpp
std::nth_element(
    v.begin(),
    v.end() - k,
    v.end()
);
```

For streaming data, a heap is often more appropriate.

## Top K Frequent

Typical approach:

``` text
frequency map
    ↓
heap of K
```

## K Closest

Use a max heap of size K.

## Merge K Sorted Arrays

Use a min heap containing the current smallest element from each array.

## Running Median

Maintain:

``` text
max heap -> lower half
min heap -> upper half
```

Balance sizes.

------------------------------------------------------------------------

# Part 73 -- Binary Search Problems

## First Occurrence

``` cpp
auto it = std::lower_bound(v.begin(), v.end(), x);
```

Check equality.

## Last Occurrence

Use:

``` cpp
auto it = std::upper_bound(v.begin(), v.end(), x);
if (it != v.begin()) {
    --it;
    // check *it
}
```

## Frequency

``` cpp
auto l = std::lower_bound(v.begin(), v.end(), x);
auto r = std::upper_bound(v.begin(), v.end(), x);
auto count = r - l;
```

## Search Insert Position

``` cpp
auto pos = std::lower_bound(v.begin(), v.end(), x);
```

## Binary Search on Answer

Define:

``` cpp
bool feasible(answer)
```

such that feasibility is monotonic, then binary search the answer range.

------------------------------------------------------------------------

# Part 74 -- Sorting Problems

## Sort 0/1/2

Use `std::sort` for simplicity:

``` cpp
std::sort(v.begin(), v.end());
```

For strict O(n) constant-space constraints, use Dutch National Flag.

## Sort by Frequency

Build frequency map and custom-sort values.

## Sort Structures

``` cpp
std::sort(
    users.begin(), users.end(),
    [](const User& a, const User& b) {
        return a.age < b.age;
    }
);
```

## Sort Intervals

Usually:

``` cpp
std::sort(intervals.begin(), intervals.end());
```

with pair's lexicographical order or custom comparator.

## Sort Characters

``` cpp
std::sort(s.begin(), s.end());
```

------------------------------------------------------------------------

# Part 75 -- Permutation Problems

## Generate All Permutations

``` cpp
std::sort(v.begin(), v.end());

do {
    // process
} while (std::next_permutation(v.begin(), v.end()));
```

Number of permutations for distinct `n` elements:

``` text
n!
```

## Unique Permutations

Sorting first plus `next_permutation()` naturally avoids duplicate
permutation outputs for equal values.

## Permutation Ranking

Can be solved using factorial-number-system concepts and data structures
such as Fenwick trees for efficient large-n variants.

------------------------------------------------------------------------

# Part 76 -- Data Processing Applications

STL algorithms map naturally to pipelines:

``` text
filter -> transform -> sort -> aggregate
```

Example:

``` cpp
std::vector<int> values{1,2,3,4,5,6};

std::vector<int> result;

std::copy_if(
    values.begin(), values.end(),
    std::back_inserter(result),
    [](int x) { return x % 2 == 0; }
);

std::transform(
    result.begin(), result.end(),
    result.begin(),
    [](int x) { return x * x; }
);
```

------------------------------------------------------------------------

# Part 77 -- Scheduling Applications

Common workflow:

``` text
Input jobs
    ↓
Sort by start/end/deadline
    ↓
Use heap for active resources
    ↓
Process intervals
    ↓
Produce schedule
```

Meeting rooms:

``` text
sort intervals by start
min heap of ending times
reuse room when earliest ending <= current start
```

CPU scheduling:

``` text
sort by arrival
heap by priority
process next available job
```

------------------------------------------------------------------------

# Part 78 -- Common Mistakes

## 78.1 Unsorted Input to Binary Search

Wrong:

``` cpp
std::binary_search(v.begin(), v.end(), x);
```

when `v` is unsorted.

## 78.2 Wrong Comparator

Do not mix sort ordering and search ordering.

## 78.3 `<=` Comparator

Avoid:

``` cpp
return a <= b;
```

for strict ordering.

## 78.4 Dereferencing `end()`

Wrong:

``` cpp
auto it = std::find(...);
std::cout << *it;
```

without checking `it != end`.

## 78.5 Remove Does Not Erase

Wrong assumption:

``` cpp
std::remove(v.begin(), v.end(), x);
```

and expecting `v.size()` to shrink.

## 78.6 Wrong Iterator Category

`std::sort` cannot use list iterators.

## 78.7 Integer Overflow

Use:

``` cpp
long long
```

or another appropriate type when totals may exceed `int`.

## 78.8 Wrong Lambda Capture

Reference captures can dangle if used beyond the referenced object's
lifetime.

## 78.9 Duplicate Handling

`unique()` only removes consecutive equivalent values.

## 78.10 Heap Assumptions

After:

``` cpp
std::pop_heap(v.begin(), v.end());
```

the maximum element is at `v.back()`, but the container still contains
it until `pop_back()`.

------------------------------------------------------------------------

# Part 79 -- Interview Questions

## Basic

1.  What are STL algorithms?
2.  Why are algorithms iterator-based?
3.  What is `[first,last)`?
4.  What is a predicate?
5.  What is a comparator?
6.  What is a functor?
7.  What is a lambda?
8.  What is strict weak ordering?
9.  What is iterator invalidation?
10. What is the remove-erase idiom?

## Search

11. Difference between `find` and `binary_search`?
12. What does `lower_bound` return?
13. What does `upper_bound` return?
14. How do you count duplicates?
15. What happens if binary search input is unsorted?
16. Why can binary search have linear total iterator movement for
    forward iterators?

## Sorting

17. How does `sort` work conceptually?
18. What is introsort?
19. Difference between `sort` and `stable_sort`?
20. When do you use `nth_element`?
21. What is a strict weak ordering?
22. How do you sort by multiple fields?

## Heap

23. What is a heap?
24. Max heap vs min heap?
25. What does `make_heap` do?
26. What does `pop_heap` do?
27. Why call `pop_back` after `pop_heap`?

## Numeric

28. Difference between `accumulate` and `reduce`?
29. What is a prefix sum?
30. Difference between `partial_sum` and `inclusive_scan`?
31. What is `transform_reduce`?
32. Why can floating-point `reduce` differ from `accumulate`?

------------------------------------------------------------------------

# Part 80 -- 100+ Interview Question Categories

Use these categories for structured interview preparation.

## Definition

-   What is an STL algorithm?
-   What is a range?
-   What is a predicate?
-   What is a projection?
-   What is a comparator?

## Syntax

-   How is `sort` called?
-   How is `find_if` called?
-   How is a custom comparator supplied?
-   How is a ranges algorithm called?

## Complexity

-   Complexity of `find`.
-   Complexity of `sort`.
-   Complexity of `nth_element`.
-   Complexity of `make_heap`.
-   Complexity of `lower_bound`.

## Internal Working

-   How does `next_permutation` work?
-   How does heapify work?
-   How does partition work?
-   How does binary search work?
-   How does remove rearrange elements?

## Debugging

-   Why is `lower_bound` returning unexpected output?
-   Why does `remove` not reduce vector size?
-   Why does sorting with a comparator fail?
-   Why is `std::sort` rejected for `list`?

## Modern C++

-   What are ranges?
-   What is a projection?
-   What are concepts?
-   What is a sentinel?
-   What are execution policies?

------------------------------------------------------------------------

# Part 81 -- Complete Programs

## 81.1 Frequency Counter

``` cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {
    std::vector<int> v{1,2,2,3,3,3};

    std::map<int,int> freq;

    for (int x : v)
        ++freq[x];

    for (const auto& [x, c] : freq)
        std::cout << x << " -> " << c << '\n';
}
```

## 81.2 Sort Students

``` cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int marks;
};

int main() {
    std::vector<Student> students{
        {"Bob", 80},
        {"Alice", 95},
        {"Tom", 80}
    };

    std::stable_sort(
        students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.marks > b.marks;
        }
    );

    for (const auto& s : students)
        std::cout << s.name << ' ' << s.marks << '\n';
}
```

## 81.3 Binary Search

``` cpp
std::vector<int> v{1,3,5,7,9};

if (std::binary_search(v.begin(), v.end(), 7))
    std::cout << "Found\n";
```

## 81.4 Lower Bound

``` cpp
auto it = std::lower_bound(v.begin(), v.end(), 6);

if (it != v.end())
    std::cout << "Position = " << it - v.begin() << '\n';
```

## 81.5 Upper Bound

``` cpp
auto it = std::upper_bound(v.begin(), v.end(), 5);
```

## 81.6 Frequency Using Bounds

``` cpp
auto l = std::lower_bound(v.begin(), v.end(), x);
auto r = std::upper_bound(v.begin(), v.end(), x);

std::cout << r - l << '\n';
```

## 81.7 Remove Duplicates

``` cpp
std::sort(v.begin(), v.end());
v.erase(std::unique(v.begin(), v.end()), v.end());
```

## 81.8 Rotate

``` cpp
int k = 2;
k %= static_cast<int>(v.size());

std::rotate(
    v.begin(),
    v.begin() + k,
    v.end()
);
```

Handle an empty vector before using modulo by its size.

## 81.9 Kth Smallest

``` cpp
int k = 3;

std::nth_element(
    v.begin(),
    v.begin() + (k - 1),
    v.end()
);

std::cout << v[k - 1];
```

## 81.10 Max Heap

``` cpp
std::make_heap(v.begin(), v.end());

std::cout << v.front();
```

## 81.11 Min Heap

``` cpp
std::make_heap(
    v.begin(), v.end(),
    std::greater<>()
);
```

## 81.12 Prefix Sum

``` cpp
std::vector<int> prefix(v.size());

std::partial_sum(
    v.begin(), v.end(),
    prefix.begin()
);
```

## 81.13 Next Permutation

``` cpp
std::sort(v.begin(), v.end());

do {
    for (int x : v)
        std::cout << x << ' ';
    std::cout << '\n';
} while (std::next_permutation(v.begin(), v.end()));
```

## 81.14 Interval Merge

``` cpp
#include <algorithm>
#include <vector>

using Interval = std::pair<int,int>;

std::vector<Interval>
mergeIntervals(std::vector<Interval> intervals) {
    if (intervals.empty())
        return {};

    std::sort(intervals.begin(), intervals.end());

    std::vector<Interval> result;
    result.push_back(intervals[0]);

    for (std::size_t i = 1; i < intervals.size(); ++i) {
        auto& back = result.back();

        if (intervals[i].first <= back.second) {
            back.second =
                std::max(back.second, intervals[i].second);
        } else {
            result.push_back(intervals[i]);
        }
    }

    return result;
}
```

------------------------------------------------------------------------

# Part 82 -- Advanced Complete Programs

## 82.1 Generic Filtering

``` cpp
template<class Range, class Predicate>
auto filter_copy(const Range& range, Predicate pred) {
    using T = typename Range::value_type;

    std::vector<T> result;

    std::copy_if(
        range.begin(), range.end(),
        std::back_inserter(result),
        pred
    );

    return result;
}
```

## 82.2 Generic Transformation

``` cpp
template<class Range, class Function>
auto transform_copy(const Range& range, Function f) {
    using Result =
        std::decay_t<decltype(f(*range.begin()))>;

    std::vector<Result> result;
    result.reserve(range.size());

    std::transform(
        range.begin(), range.end(),
        std::back_inserter(result),
        f
    );

    return result;
}
```

For generic production utilities, account for empty ranges and
containers without `size()` as needed.

## 82.3 Generic Aggregation

``` cpp
template<class Range, class T, class Op>
T aggregate(const Range& r, T init, Op op) {
    return std::accumulate(
        r.begin(), r.end(), init, op
    );
}
```

## 82.4 Generic Search

``` cpp
template<class Range, class T>
bool contains(const Range& r, const T& value) {
    return std::find(
        r.begin(), r.end(), value
    ) != r.end();
}
```

## 82.5 Generic Binary Search

``` cpp
template<class Range, class T>
bool containsSorted(const Range& r, const T& value) {
    return std::binary_search(
        r.begin(), r.end(), value
    );
}
```

The caller must satisfy the sorted-range precondition.

## 82.6 Priority Scheduling

``` cpp
#include <queue>
#include <vector>

struct Job {
    int priority;
    int id;
};

struct Compare {
    bool operator()(const Job& a, const Job& b) const {
        return a.priority < b.priority;
    }
};

std::priority_queue<Job, std::vector<Job>, Compare> q;
```

## 82.7 Leaderboard

``` cpp
std::sort(
    players.begin(), players.end(),
    [](const Player& a, const Player& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.name < b.name;
    }
);
```

------------------------------------------------------------------------

# Part 83 -- Real-World STL Algorithm Usage

## Backend Development

-   Sort API results.
-   Filter records.
-   Validate collections.
-   Aggregate totals.
-   Deduplicate IDs.
-   Find matching transactions.

## Financial Systems

Typical examples:

``` text
sort transactions
filter status
find account
aggregate amount
partition valid/invalid
```

Use appropriate numeric types; do not use floating-point casually for
monetary values.

## Scheduling Systems

``` text
sort by time
heap by next event
partition active/inactive
```

## Ranking Systems

``` text
sort by score
nth_element for cutoff
lower_bound for rank boundaries
```

## Search Systems

``` text
sort indexed keys
lower_bound
upper_bound
equal_range
```

## Analytics

``` text
transform
reduce
accumulate
sort
partial_sort
```

## Games

-   Shuffle decks.
-   Sort entities by distance/priority.
-   Find nearest object.
-   Partition visible/invisible objects.

## Embedded Systems

Prefer predictable complexity, bounded memory, and careful allocation
behavior.

------------------------------------------------------------------------

# Part 84 -- Algorithm Selection Guide

## Need to Find an Element?

``` text
Unsorted exact value
        ↓
find()

Unsorted condition
        ↓
find_if()

Sorted exact existence
        ↓
binary_search()

Sorted first valid position
        ↓
lower_bound()

Sorted position after equal values
        ↓
upper_bound()

Both boundaries
        ↓
equal_range()
```

## Need to Sort?

``` text
Everything
    ↓
sort()

Stable
    ↓
stable_sort()

Sorted first K
    ↓
partial_sort()

Only kth position / partition
    ↓
nth_element()
```

## Need to Remove?

``` text
Value
    ↓
remove + erase

Condition
    ↓
remove_if + erase

C++20
    ↓
erase / erase_if
```

## Need a Heap?

``` text
Build -> make_heap
Insert -> push_heap
Top removal -> pop_heap + pop_back
Sort heap -> sort_heap
```

------------------------------------------------------------------------

# Part 85 -- Algorithm Decision Patterns

## Find

``` cpp
find();
find_if();
find_if_not();
```

## Count

``` cpp
count();
count_if();
```

## Validate

``` cpp
all_of();
any_of();
none_of();
```

## Transform

``` cpp
transform();
```

## Replace

``` cpp
replace();
replace_if();
replace_copy();
replace_copy_if();
```

## Copy

``` cpp
copy();
copy_if();
copy_n();
copy_backward();
```

## Reverse

``` cpp
reverse();
reverse_copy();
```

## Rotate

``` cpp
rotate();
rotate_copy();
```

------------------------------------------------------------------------

# Part 86 -- STL Algorithm Performance

## Cache Locality

Contiguous containers such as vectors often perform very well because
sequential traversal uses cache-friendly memory access.

## Branch Prediction

Predicates with unpredictable branches may cost more than simple
arithmetic.

## Memory Allocation

Prefer algorithms that reuse existing storage when appropriate.

## Copy Cost

Copying large objects can dominate the algorithm itself.

## Move Cost

Move operations can be cheaper, but this depends on the type.

## Comparator Cost

A sorting algorithm may call the comparator O(n log n) times. Avoid
unnecessarily expensive comparator work.

Bad:

``` cpp
std::sort(v.begin(), v.end(),
    [](const Item& a, const Item& b) {
        return expensiveCalculation(a) <
               expensiveCalculation(b);
    });
```

For expensive keys, precompute keys when appropriate.

------------------------------------------------------------------------

# Part 87 -- Advanced Performance Topics

## Cache-Friendly Algorithms

Prefer contiguous data for workloads dominated by sequential processing.

## Vectorization

Simple transformations may be easier for compilers to optimize:

``` cpp
std::transform(
    v.begin(), v.end(),
    v.begin(),
    [](float x) { return x * 2.0f; }
);
```

Actual vectorization depends on compiler, target, aliasing, callable
complexity, and build options.

## SIMD

SIMD processes multiple values per instruction. STL algorithms do not
guarantee SIMD automatically.

## Branchless Algorithms

Sometimes replacing unpredictable branches with arithmetic/masking can
help, but benchmark before using such techniques.

## Allocation Avoidance

Reserve capacity:

``` cpp
result.reserve(input.size());
```

before repeated insertion when the size is predictable.

## Profiling

Do not optimize by intuition alone.

Measure:

``` text
CPU time
allocations
cache misses
branch misses
memory bandwidth
```

------------------------------------------------------------------------

# Part 88 -- STL Algorithms with User-Defined Types

## Structure Sorting

``` cpp
struct Employee {
    std::string name;
    double salary;
};
```

Sort:

``` cpp
std::sort(
    employees.begin(),
    employees.end(),
    [](const Employee& a, const Employee& b) {
        return a.salary > b.salary;
    }
);
```

## Smart Pointers

``` cpp
std::vector<std::unique_ptr<Employee>> employees;

std::sort(
    employees.begin(),
    employees.end(),
    [](const auto& a, const auto& b) {
        return a->salary > b->salary;
    }
);
```

## Move-Only Objects

Use move algorithms where copying is impossible.

------------------------------------------------------------------------

# Part 89 -- Algorithms with Strings

## Character Search

``` cpp
auto it = std::find(
    s.begin(), s.end(), 'a'
);
```

## Character Count

``` cpp
auto count =
    std::count(s.begin(), s.end(), 'a');
```

## Transform Characters

``` cpp
std::transform(
    s.begin(), s.end(),
    s.begin(),
    [](unsigned char c) {
        return static_cast<char>(std::toupper(c));
    }
);
```

## Reverse

``` cpp
std::reverse(s.begin(), s.end());
```

## Sort Characters

``` cpp
std::sort(s.begin(), s.end());
```

## Remove Consecutive Duplicates

``` cpp
s.erase(
    std::unique(s.begin(), s.end()),
    s.end()
);
```

------------------------------------------------------------------------

# Part 90 -- Algorithms with Maps and Sets

Associative containers already provide member functions optimized for
their structure:

``` cpp
map.find(key);
map.lower_bound(key);
map.upper_bound(key);
set.find(value);
```

Do not automatically replace these with generic algorithms.

For example:

``` cpp
std::find(myMap.begin(), myMap.end(), pairValue);
```

is generally linear, while:

``` cpp
myMap.find(key);
```

uses the map's tree structure.

For `unordered_map`, use its `find()` for hash lookup.

------------------------------------------------------------------------

# Part 91 -- Algorithms with Vectors

Vectors are the most common STL-algorithm container.

Typical workflow:

``` cpp
sort
lower_bound
transform
remove_if
unique
partition
heap
accumulate
```

Example:

``` cpp
std::vector<int> v{5,3,3,1,4,2};

std::sort(v.begin(), v.end());
v.erase(std::unique(v.begin(), v.end()), v.end());

int sum =
    std::accumulate(v.begin(), v.end(), 0);
```

------------------------------------------------------------------------

# Part 92 -- Algorithms with Arrays

`std::array` works with standard algorithms:

``` cpp
std::array<int,5> a{5,4,3,2,1};

std::sort(a.begin(), a.end());
std::reverse(a.begin(), a.end());
```

Built-in arrays can also be used with:

``` cpp
std::begin(a)
std::end(a)
```

------------------------------------------------------------------------

# Part 93 -- Algorithms with Linked Lists

`std::list` provides member algorithms such as:

``` cpp
list.sort();
list.remove(value);
list.unique();
list.merge(other);
list.reverse();
```

The reason is that list-specific operations can exploit node links
efficiently.

`std::sort(list.begin(), list.end())` does not work because `std::sort`
requires random-access iterators.

------------------------------------------------------------------------

# Part 94 -- C++ Standard Version Coverage

## C++11

Major foundation:

``` text
STL algorithms
lambda expressions
move semantics
begin/end
type inference
```

## C++14

``` text
generic lambdas
transparent standard function objects
```

## C++17

Important additions:

``` text
for_each_n
sample
clamp
execution policies
gcd
lcm
```

Also many improvements to existing algorithms and library facilities.

## C++20

Major modern layer:

``` text
ranges
range algorithms
concepts
projections
sentinels
shift_left
shift_right
unsequenced execution support
three-way comparison facilities
```

## C++23

C++23 continues the ranges ecosystem and modern library additions. The
exact set of algorithms/utilities should be checked against the
implementation and standard version being used.

------------------------------------------------------------------------

# Part 95 -- STL Algorithm Best Practices

1.  Prefer STL algorithms when they clearly express the intent.
2.  Use meaningful predicates.
3.  Use strict weak ordering for sorting/ordered algorithms.
4.  Check sorted/partitioned preconditions.
5.  Check returned iterators.
6.  Never dereference `end()`.
7.  Understand iterator invalidation.
8.  Avoid unnecessary copies.
9.  Use move semantics when ownership transfer is intended.
10. Prefer ranges in modern C++ when appropriate.
11. Understand complexity before selecting an algorithm.
12. Measure before optimizing.
13. Prefer container member functions when they exploit
    container-specific structure.
14. Keep predicates/comparators simple and deterministic.
15. Use `std::erase`/`std::erase_if` where appropriate in C++20.
16. Handle empty ranges explicitly when arithmetic depends on size.
17. Use appropriate numeric types.
18. Do not assume implementation details such as the exact internal
    sorting algorithm.

------------------------------------------------------------------------

# Part 96 -- STL Algorithm Cheat Sheet

## Searching

``` cpp
find()
find_if()
find_if_not()
binary_search()
lower_bound()
upper_bound()
equal_range()
```

## Counting

``` cpp
count()
count_if()
```

## Conditions

``` cpp
all_of()
any_of()
none_of()
```

## Sorting

``` cpp
sort()
stable_sort()
partial_sort()
partial_sort_copy()
nth_element()
is_sorted()
is_sorted_until()
```

## Copying

``` cpp
copy()
copy_if()
copy_n()
copy_backward()
move()
move_backward()
```

## Modification

``` cpp
transform()
replace()
replace_if()
replace_copy()
replace_copy_if()
fill()
fill_n()
generate()
generate_n()
```

## Removal

``` cpp
remove()
remove_if()
remove_copy()
remove_copy_if()
unique()
unique_copy()
```

## Rearrangement

``` cpp
reverse()
reverse_copy()
rotate()
rotate_copy()
shuffle()
sample()
shift_left()
shift_right()
```

## Partition

``` cpp
partition()
stable_partition()
partition_copy()
partition_point()
is_partitioned()
```

## Heap

``` cpp
make_heap()
push_heap()
pop_heap()
sort_heap()
is_heap()
is_heap_until()
```

## Set

``` cpp
merge()
inplace_merge()
includes()
set_union()
set_intersection()
set_difference()
set_symmetric_difference()
```

## Permutation

``` cpp
next_permutation()
prev_permutation()
is_permutation()
```

## Numeric

``` cpp
accumulate()
reduce()
inner_product()
partial_sum()
adjacent_difference()
inclusive_scan()
exclusive_scan()
transform_reduce()
transform_inclusive_scan()
transform_exclusive_scan()
iota()
gcd()
lcm()
midpoint()
```

------------------------------------------------------------------------

# Part 97 -- Most Important Algorithms for Interviews

## Tier 1 --- Must Know

``` text
sort
find
find_if
count
count_if
all_of
any_of
none_of
binary_search
lower_bound
upper_bound
reverse
rotate
remove
unique
transform
```

## Tier 2 --- Important

``` text
stable_sort
partial_sort
nth_element
partition
merge
set_union
set_intersection
next_permutation
make_heap
push_heap
pop_heap
```

## Tier 3 --- Advanced

``` text
reduce
transform_reduce
inclusive_scan
exclusive_scan
execution policies
ranges algorithms
projections
concepts
parallel algorithms
```

------------------------------------------------------------------------

# Part 98 -- Problem-Solving Templates

## Frequency

``` cpp
std::map<int,int> freq;
for (int x : v)
    ++freq[x];
```

Or for a sorted vector:

``` cpp
auto l = std::lower_bound(v.begin(), v.end(), x);
auto r = std::upper_bound(v.begin(), v.end(), x);
auto frequency = r - l;
```

## Remove Duplicates

``` cpp
std::sort(v.begin(), v.end());
v.erase(std::unique(v.begin(), v.end()), v.end());
```

## Kth Element

``` cpp
std::nth_element(v.begin(), v.begin() + k, v.end());
```

Remember zero-based indexing.

## Top K

Use:

``` text
partial_sort
nth_element
heap
```

depending on whether the first K elements must be fully sorted, only
partitioned, or processed as a stream.

## Interval Merge

``` text
sort by start
for each interval:
    overlap -> extend
    otherwise -> append
```

## Custom Sort

``` cpp
std::sort(
    v.begin(), v.end(),
    [](const auto& a, const auto& b) {
        // strict weak ordering
    }
);
```

------------------------------------------------------------------------

# Part 99 -- Debugging STL Algorithms

## Wrong Range

Check:

``` cpp
first
last
```

and whether `last` is actually reachable from `first`.

## Invalid Iterator

Check whether a vector reallocation or erase invalidated the iterator.

## Dereferencing End

Always:

``` cpp
if (it != v.end())
    use(*it);
```

## Incorrect Comparator

Verify:

``` text
comp(x,x) == false
asymmetry
transitivity
```

## Unsorted Input

Before:

``` cpp
binary_search
lower_bound
upper_bound
equal_range
```

verify ordering.

## Wrong Return Interpretation

Examples:

``` text
remove -> new logical end
unique -> new logical end
find -> iterator or end
lower_bound -> insertion/boundary iterator
equal_range -> pair
```

## Unexpected Container Size

Remember:

``` text
remove does not erase
unique does not erase
```

## Move-From Objects

Do not rely on the previous value of a moved-from object.

------------------------------------------------------------------------

# Part 100 -- Master Revision Notes

## Search

``` text
Unsorted exact value -> find()
Unsorted condition   -> find_if()
Sorted existence      -> binary_search()
First >= x            -> lower_bound()
First > x             -> upper_bound()
Both boundaries       -> equal_range()
```

## Sort

``` text
Full ordering -> sort()
Stable ordering -> stable_sort()
Sorted prefix -> partial_sort()
Nth position -> nth_element()
```

## Remove

``` text
Logical removal -> remove/remove_if
Physical deletion -> erase
C++20 -> erase/erase_if
```

## Heap

``` text
Create -> make_heap()
Insert -> push_heap()
Top to end -> pop_heap()
Sort heap -> sort_heap()
```

## Conditions

``` text
Every -> all_of()
At least one -> any_of()
None -> none_of()
```

## Transform

``` text
One input -> unary transform
Two inputs -> binary transform
```

## Numeric

``` text
Ordered accumulation -> accumulate()
Reorderable/parallel reduction -> reduce()
Prefix -> inclusive_scan/exclusive_scan
Sequence generation -> iota()
```

------------------------------------------------------------------------

# Part 101 -- Complete Algorithm Master Checklist

## Non-Modifying

-   [ ] `for_each`
-   [ ] `for_each_n`
-   [ ] `all_of`
-   [ ] `any_of`
-   [ ] `none_of`
-   [ ] `count`
-   [ ] `count_if`
-   [ ] `mismatch`
-   [ ] `equal`
-   [ ] `is_permutation`
-   [ ] `search`
-   [ ] `search_n`
-   [ ] `find`
-   [ ] `find_if`
-   [ ] `find_if_not`
-   [ ] `find_end`
-   [ ] `find_first_of`
-   [ ] `adjacent_find`

## Modifying

-   [ ] `copy`
-   [ ] `copy_if`
-   [ ] `copy_n`
-   [ ] `copy_backward`
-   [ ] `move`
-   [ ] `move_backward`
-   [ ] `swap`
-   [ ] `swap_ranges`
-   [ ] `iter_swap`
-   [ ] `transform`
-   [ ] `replace`
-   [ ] `replace_if`
-   [ ] `replace_copy`
-   [ ] `replace_copy_if`
-   [ ] `fill`
-   [ ] `fill_n`
-   [ ] `generate`
-   [ ] `generate_n`
-   [ ] `remove`
-   [ ] `remove_if`
-   [ ] `remove_copy`
-   [ ] `remove_copy_if`
-   [ ] `unique`
-   [ ] `unique_copy`
-   [ ] `reverse`
-   [ ] `reverse_copy`
-   [ ] `rotate`
-   [ ] `rotate_copy`
-   [ ] `shuffle`
-   [ ] `sample`
-   [ ] `shift_left`
-   [ ] `shift_right`

## Partition

-   [ ] `partition`
-   [ ] `stable_partition`
-   [ ] `partition_copy`
-   [ ] `partition_point`
-   [ ] `is_partitioned`

## Sorting

-   [ ] `sort`
-   [ ] `stable_sort`
-   [ ] `partial_sort`
-   [ ] `partial_sort_copy`
-   [ ] `nth_element`
-   [ ] `is_sorted`
-   [ ] `is_sorted_until`

## Binary Search

-   [ ] `binary_search`
-   [ ] `lower_bound`
-   [ ] `upper_bound`
-   [ ] `equal_range`

## Heap

-   [ ] `make_heap`
-   [ ] `push_heap`
-   [ ] `pop_heap`
-   [ ] `sort_heap`
-   [ ] `is_heap`
-   [ ] `is_heap_until`

## Set

-   [ ] `includes`
-   [ ] `merge`
-   [ ] `inplace_merge`
-   [ ] `set_union`
-   [ ] `set_intersection`
-   [ ] `set_difference`
-   [ ] `set_symmetric_difference`

## Min/Max

-   [ ] `min`
-   [ ] `max`
-   [ ] `minmax`
-   [ ] `min_element`
-   [ ] `max_element`
-   [ ] `minmax_element`
-   [ ] `clamp`

## Permutations

-   [ ] `next_permutation`
-   [ ] `prev_permutation`
-   [ ] `is_permutation`

## Numeric

-   [ ] `accumulate`
-   [ ] `reduce`
-   [ ] `inner_product`
-   [ ] `partial_sum`
-   [ ] `adjacent_difference`
-   [ ] `inclusive_scan`
-   [ ] `exclusive_scan`
-   [ ] `transform_reduce`
-   [ ] `transform_inclusive_scan`
-   [ ] `transform_exclusive_scan`
-   [ ] `iota`
-   [ ] `gcd`
-   [ ] `lcm`
-   [ ] `midpoint`

## Modern C++

-   [ ] Execution policies
-   [ ] Parallel algorithms
-   [ ] C++20 ranges
-   [ ] Range algorithms
-   [ ] Concepts
-   [ ] Projections
-   [ ] Sentinels
-   [ ] Range adaptors
-   [ ] Views
-   [ ] Modern comparator objects
-   [ ] `std::invoke`

------------------------------------------------------------------------

# Final STL Algorithms Learning Path

``` text
STL Fundamentals
        ↓
Iterators
        ↓
Predicates
        ↓
Lambdas
        ↓
Comparators
        ↓
Non-Modifying Algorithms
        ↓
Modifying Algorithms
        ↓
Partitioning
        ↓
Sorting
        ↓
Binary Search
        ↓
Heap
        ↓
Set Algorithms
        ↓
Min / Max
        ↓
Permutations
        ↓
Numeric Algorithms
        ↓
Execution Policies
        ↓
Parallel Algorithms
        ↓
C++20 Ranges
        ↓
Concepts
        ↓
Projections
        ↓
Complexity Analysis
        ↓
Competitive Programming
        ↓
Real-World Applications
        ↓
Interview Problems
        ↓
Advanced STL Mastery
```

# Final Goal

After completing this guide, you should be able to:

-   Understand the purpose of STL algorithms.
-   Select the correct algorithm for a problem.
-   Understand iterator requirements.
-   Write predicates.
-   Write comparators.
-   Use lambdas.
-   Understand functors.
-   Analyze complexity.
-   Understand the major algorithmic techniques behind STL
    implementations.
-   Use sorting and searching correctly.
-   Work with heaps and set algorithms.
-   Use numeric algorithms.
-   Understand execution policies.
-   Use C++20 ranges and projections.
-   Avoid iterator and comparator mistakes.
-   Solve common competitive-programming patterns.
-   Apply STL algorithms in backend, data-processing, scheduling,
    ranking, analytics, and other software.
-   Prepare for STL-focused C++ interviews.

------------------------------------------------------------------------

# Appendix A -- One-Page Algorithm Mental Model

``` text
                 STL ALGORITHMS
                       |
       +---------------+---------------+
       |               |               |
   Inspect          Modify          Rearrange
       |               |               |
 find/count       copy/transform    sort/reverse
 all/any/none     replace/fill      rotate/partition
 compare          remove/unique     shuffle
       |
       +-------------------------------+
                       |
                   Search Data
                       |
            +----------+----------+
            |                     |
        Unsorted                Sorted
            |                     |
         find()          binary_search()
         find_if()       lower_bound()
                         upper_bound()
                         equal_range()
                       |
                     Heap
                       |
              make/push/pop/sort
                       |
                    Numeric
                       |
       accumulate/reduce/scan/iota
                       |
                  Modern C++
                       |
              ranges/concepts/
                 projections
```

# Appendix B -- Fast Interview Revision

### `find`

``` cpp
auto it = std::find(v.begin(), v.end(), x);
```

### `count`

``` cpp
auto n = std::count(v.begin(), v.end(), x);
```

### `count_if`

``` cpp
auto n = std::count_if(
    v.begin(), v.end(),
    [](int x){ return x > 0; }
);
```

### `sort`

``` cpp
std::sort(v.begin(), v.end());
```

### Descending

``` cpp
std::sort(v.begin(), v.end(), std::greater<>());
```

### Lower Bound

``` cpp
auto it = std::lower_bound(v.begin(), v.end(), x);
```

### Upper Bound

``` cpp
auto it = std::upper_bound(v.begin(), v.end(), x);
```

### Remove-Erase

``` cpp
v.erase(
    std::remove(v.begin(), v.end(), x),
    v.end()
);
```

### Unique-Erase

``` cpp
v.erase(
    std::unique(v.begin(), v.end()),
    v.end()
);
```

### Kth Element

``` cpp
std::nth_element(
    v.begin(),
    v.begin() + k,
    v.end()
);
```

### Heap

``` cpp
std::make_heap(v.begin(), v.end());
std::pop_heap(v.begin(), v.end());
v.pop_back();
```

### Prefix Sum

``` cpp
std::partial_sum(
    v.begin(), v.end(),
    out.begin()
);
```

### Modern Ranges

``` cpp
std::ranges::sort(v);
auto it = std::ranges::find(v, x);
```

------------------------------------------------------------------------

# Appendix C -- Recommended Practice Order

## Level 1

Master:

``` text
find
count
all_of
any_of
none_of
sort
reverse
transform
remove
unique
```

## Level 2

Master:

``` text
lower_bound
upper_bound
binary_search
equal_range
partition
rotate
nth_element
```

## Level 3

Master:

``` text
heap algorithms
set algorithms
permutations
numeric algorithms
```

## Level 4

Master:

``` text
comparators
predicates
iterator categories
strict weak ordering
execution policies
```

## Level 5

Master:

``` text
ranges
concepts
projections
views
sentinels
parallel algorithms
```

## Level 6

Solve problems using:

``` text
sort + greedy
sort + two pointer
sort + binary search
heap + streaming
nth_element + selection
prefix scan
partition
permutation
```

------------------------------------------------------------------------

# Appendix D -- Core Rules to Memorize

``` text
1. STL algorithms normally operate on ranges.
2. Classic ranges are [first, last).
3. end() is one-past-the-end and is not dereferenceable.
4. find() does not require sorting.
5. binary_search/lower_bound/upper_bound require appropriate ordering.
6. sort() requires random-access iterators.
7. list has list::sort().
8. remove() does not shrink a container.
9. unique() removes consecutive duplicates logically.
10. Use erase after remove/unique when container size must shrink.
11. sort comparators must provide strict weak ordering.
12. nth_element does not fully sort the range.
13. make_heap is linear; push/pop are logarithmic.
14. Set algorithms require sorted compatible ranges.
15. accumulate is ordered; reduce may reorder operations.
16. Parallel reductions require operations suitable for reordering.
17. C++20 ranges reduce iterator boilerplate.
18. Projections let algorithms operate on object properties.
19. Iterator category affects which algorithms are valid and can affect total runtime.
20. Always understand the algorithm's preconditions before using it.
```

------------------------------------------------------------------------

# End of C++ STL Algorithms Complete Notes

This document is designed as a study/reference guide. For production
software, always verify exact overload requirements, invalidation
guarantees, complexity guarantees, and C++ standard-version availability
against the standard library implementation and the C++ standard in use.
