# C++ STL Algorithms — Complete Reference

> **Scope:** This is an algorithm reference, not a theory chapter. It focuses on algorithm/function names, headers, standard versions, signatures, and compact usage. It intentionally does not explain lambdas, functors, `std::less`, `std::greater`, iterator theory, etc.

## 1. Headers

| Header | Main contents |
|---|---|
| `<algorithm>` | General sequence, search, sort, partition, heap, set, permutation and comparison algorithms |
| `<numeric>` | Numeric range algorithms, reductions, scans, `iota`, `gcd`, `lcm`, `midpoint` |
| `<ranges>` | C++20 ranges algorithms, projections and range utilities |
| `<execution>` | Execution policies |
| `<memory>` | Specialized object-lifetime/uninitialized-memory algorithms |
| `<random>` | Random facilities; C++26 `ranges::generate_random` |

---

# 2. Complete `<algorithm>` Algorithms

## Non-Modifying / Search

```cpp
std::for_each
std::for_each_n                  // C++17

std::all_of                     // C++11
std::any_of                     // C++11
std::none_of                    // C++11

std::count
std::count_if

std::mismatch
std::equal
std::is_permutation             // C++11

std::find
std::find_if
std::find_if_not                // C++11
std::find_end
std::find_first_of
std::adjacent_find

std::search
std::search_n
```

## Copy / Move

```cpp
std::copy
std::copy_if                    // C++11
std::copy_n                     // C++11
std::copy_backward

std::move                       // algorithm
std::move_backward
```

## Swap

```cpp
std::swap
std::iter_swap
std::swap_ranges
```

## Transform

```cpp
std::transform
```

## Replace

```cpp
std::replace
std::replace_if
std::replace_copy
std::replace_copy_if
```

## Fill / Generate

```cpp
std::fill
std::fill_n
std::generate
std::generate_n
```

## Remove / Unique

```cpp
std::remove
std::remove_if
std::remove_copy
std::remove_copy_if

std::unique
std::unique_copy
```

## Rearrangement

```cpp
std::reverse
std::reverse_copy

std::rotate
std::rotate_copy

std::shuffle                     // C++11
std::sample                      // C++17

std::shift_left                  // C++20
std::shift_right                 // C++20
```

## Partition

```cpp
std::partition
std::partition_copy              // C++11
std::stable_partition
std::is_partitioned              // C++11
std::partition_point             // C++11
```

## Sorting

```cpp
std::sort
std::stable_sort
std::partial_sort
std::partial_sort_copy
std::nth_element
std::is_sorted                   // C++11
std::is_sorted_until             // C++11
```

## Binary Search

```cpp
std::lower_bound
std::upper_bound
std::equal_range
std::binary_search
```

## Set Operations

```cpp
std::includes
std::set_union
std::set_intersection
std::set_difference
std::set_symmetric_difference
```

## Merge

```cpp
std::merge
std::inplace_merge
```

## Heap

```cpp
std::push_heap
std::pop_heap
std::make_heap
std::sort_heap
std::is_heap                    // C++11
std::is_heap_until              // C++11
```

## Min / Max

```cpp
std::min
std::max
std::minmax                    // C++11

std::min_element
std::max_element
std::minmax_element             // C++11

std::clamp                      // C++17
```

## Lexicographical Comparison

```cpp
std::lexicographical_compare
std::lexicographical_compare_three_way   // C++20
```

## Permutations

```cpp
std::next_permutation
std::prev_permutation
std::is_permutation              // C++11
```

---

# 3. Algorithm Signatures and Usage

## `for_each`

```cpp
std::for_each(first, last, f);
```

## `for_each_n`

```cpp
std::for_each_n(first, n, f);
```

## `all_of`

```cpp
std::all_of(first, last, pred);
```

## `any_of`

```cpp
std::any_of(first, last, pred);
```

## `none_of`

```cpp
std::none_of(first, last, pred);
```

## `count`

```cpp
std::count(first, last, value);
```

## `count_if`

```cpp
std::count_if(first, last, pred);
```

## `find`

```cpp
std::find(first, last, value);
```

## `find_if`

```cpp
std::find_if(first, last, pred);
```

## `find_if_not`

```cpp
std::find_if_not(first, last, pred);
```

## `find_end`

```cpp
std::find_end(first1, last1, first2, last2);
```

## `find_first_of`

```cpp
std::find_first_of(first1, last1, first2, last2);
```

## `adjacent_find`

```cpp
std::adjacent_find(first, last);
std::adjacent_find(first, last, pred);
```

## `search`

```cpp
std::search(first1, last1, first2, last2);
```

## `search_n`

```cpp
std::search_n(first, last, count, value);
```

## `mismatch`

```cpp
std::mismatch(first1, last1, first2);
std::mismatch(first1, last1, first2, last2);
```

## `equal`

```cpp
std::equal(first1, last1, first2);
std::equal(first1, last1, first2, last2);
```

## `is_permutation`

```cpp
std::is_permutation(first1, last1, first2);
std::is_permutation(first1, last1, first2, last2);
```

---

# 4. Copy / Move

## `copy`

```cpp
std::copy(first, last, destination);
```

## `copy_if`

```cpp
std::copy_if(first, last, destination, pred);
```

## `copy_n`

```cpp
std::copy_n(first, n, destination);
```

## `copy_backward`

```cpp
std::copy_backward(first, last, destination_last);
```

## `move`

```cpp
std::move(first, last, destination);
```

> This is the `<algorithm>` move algorithm, not `std::move(object)`.

## `move_backward`

```cpp
std::move_backward(first, last, destination_last);
```

---

# 5. Swap

## `swap`

```cpp
std::swap(a, b);
```

## `iter_swap`

```cpp
std::iter_swap(i, j);
```

## `swap_ranges`

```cpp
std::swap_ranges(first1, last1, first2);
```

---

# 6. Transform

## Unary

```cpp
std::transform(first, last, destination, op);
```

## Binary

```cpp
std::transform(
    first1, last1,
    first2,
    destination,
    op
);
```

---

# 7. Replace

```cpp
std::replace(first, last, old_value, new_value);

std::replace_if(first, last, pred, new_value);

std::replace_copy(
    first, last,
    destination,
    old_value,
    new_value
);

std::replace_copy_if(
    first, last,
    destination,
    pred,
    new_value
);
```

---

# 8. Fill / Generate

```cpp
std::fill(first, last, value);

std::fill_n(first, n, value);

std::generate(first, last, generator);

std::generate_n(first, n, generator);
```

---

# 9. Remove / Unique

```cpp
std::remove(first, last, value);

std::remove_if(first, last, pred);

std::remove_copy(first, last, destination, value);

std::remove_copy_if(first, last, destination, pred);

std::unique(first, last);

std::unique_copy(first, last, destination);
```

Typical erase pattern:

```cpp
v.erase(
    std::remove(v.begin(), v.end(), value),
    v.end()
);
```

---

# 10. Reverse / Rotate / Shuffle / Shift

```cpp
std::reverse(first, last);

std::reverse_copy(
    first, last,
    destination
);

std::rotate(first, middle, last);

std::rotate_copy(
    first, middle, last,
    destination
);

std::shuffle(first, last, generator);       // C++11

std::sample(
    first, last,
    destination, n,
    generator
);                                           // C++17

std::shift_left(first, last, n);             // C++20

std::shift_right(first, last, n);            // C++20
```

`std::random_shuffle` was removed in C++17; use `std::shuffle`.

---

# 11. Partition

```cpp
std::partition(first, last, pred);

std::stable_partition(first, last, pred);

std::partition_copy(
    first, last,
    true_destination,
    false_destination,
    pred
);

std::is_partitioned(first, last, pred);

std::partition_point(first, last, pred);
```

---

# 12. Sorting

```cpp
std::sort(first, last);

std::sort(first, last, comp);

std::stable_sort(first, last);

std::stable_sort(first, last, comp);

std::partial_sort(first, middle, last);

std::partial_sort(first, middle, last, comp);

std::partial_sort_copy(
    first, last,
    destination_first,
    destination_last
);

std::partial_sort_copy(
    first, last,
    destination_first,
    destination_last,
    comp
);

std::nth_element(first, nth, last);

std::nth_element(first, nth, last, comp);

std::is_sorted(first, last);

std::is_sorted(first, last, comp);

std::is_sorted_until(first, last);

std::is_sorted_until(first, last, comp);
```

---

# 13. Binary Search

```cpp
std::lower_bound(first, last, value);

std::lower_bound(first, last, value, comp);

std::upper_bound(first, last, value);

std::upper_bound(first, last, value, comp);

std::equal_range(first, last, value);

std::equal_range(first, last, value, comp);

std::binary_search(first, last, value);

std::binary_search(first, last, value, comp);
```

For ascending ranges:

```text
lower_bound -> first position >= value
upper_bound -> first position > value
equal_range -> [lower_bound, upper_bound)
binary_search -> true/false
```

---

# 14. Set Algorithms

```cpp
std::includes(
    first1, last1,
    first2, last2
);

std::set_union(
    first1, last1,
    first2, last2,
    destination
);

std::set_intersection(
    first1, last1,
    first2, last2,
    destination
);

std::set_difference(
    first1, last1,
    first2, last2,
    destination
);

std::set_symmetric_difference(
    first1, last1,
    first2, last2,
    destination
);
```

---

# 15. Merge

```cpp
std::merge(
    first1, last1,
    first2, last2,
    destination
);

std::inplace_merge(
    first,
    middle,
    last
);
```

---

# 16. Heap

```cpp
std::make_heap(first, last);

std::make_heap(first, last, comp);

std::push_heap(first, last);

std::push_heap(first, last, comp);

std::pop_heap(first, last);

std::pop_heap(first, last, comp);

std::sort_heap(first, last);

std::sort_heap(first, last, comp);

std::is_heap(first, last);

std::is_heap(first, last, comp);

std::is_heap_until(first, last);

std::is_heap_until(first, last, comp);
```

---

# 17. Min / Max

```cpp
std::min(a, b);

std::max(a, b);

std::minmax(a, b);

std::min_element(first, last);

std::max_element(first, last);

std::minmax_element(first, last);

std::clamp(value, low, high);                // C++17
```

Comparator overloads exist for the applicable algorithms.

Initializer-list forms exist for `min`, `max`, and `minmax`:

```cpp
std::min({a, b, c});

std::max({a, b, c});

std::minmax({a, b, c});
```

---

# 18. Comparison

```cpp
std::lexicographical_compare(
    first1, last1,
    first2, last2
);

std::lexicographical_compare(
    first1, last1,
    first2, last2,
    comp
);

std::lexicographical_compare_three_way(
    first1, last1,
    first2, last2
);                                             // C++20
```

---

# 19. Permutation

```cpp
std::next_permutation(first, last);

std::next_permutation(first, last, comp);

std::prev_permutation(first, last);

std::prev_permutation(first, last, comp);

std::is_permutation(
    first1, last1,
    first2
);

std::is_permutation(
    first1, last1,
    first2, last2
);
```

---

# 20. `<numeric>` — Complete Numeric Algorithms

Header:

```cpp
#include <numeric>
```

```cpp
std::iota
std::accumulate
std::reduce                       // C++17
std::inner_product
std::partial_sum
std::adjacent_difference

std::inclusive_scan               // C++17
std::exclusive_scan               // C++17

std::transform_reduce             // C++17
std::transform_inclusive_scan     // C++17
std::transform_exclusive_scan     // C++17

std::gcd                          // C++17
std::lcm                          // C++17
std::midpoint                     // C++20
```

## Signatures

```cpp
std::iota(first, last, value);

std::accumulate(first, last, init);

std::accumulate(first, last, init, op);

std::reduce(first, last);

std::reduce(first, last, init);

std::reduce(first, last, init, op);

std::inner_product(
    first1, last1,
    first2,
    init
);

std::inner_product(
    first1, last1,
    first2,
    init,
    reduce_op,
    transform_op
);

std::partial_sum(
    first, last,
    destination
);

std::partial_sum(
    first, last,
    destination,
    op
);

std::adjacent_difference(
    first, last,
    destination
);

std::adjacent_difference(
    first, last,
    destination,
    op
);

std::inclusive_scan(
    first, last,
    destination
);

std::inclusive_scan(
    first, last,
    destination,
    op
);

std::inclusive_scan(
    first, last,
    destination,
    op,
    init
);

std::exclusive_scan(
    first, last,
    destination,
    init
);

std::exclusive_scan(
    first, last,
    destination,
    init,
    op
);

std::transform_reduce(
    first, last,
    init,
    reduce_op,
    transform_op
);

std::transform_reduce(
    first1, last1,
    first2,
    init
);

std::transform_reduce(
    first1, last1,
    first2,
    init,
    reduce_op,
    transform_op
);

std::transform_inclusive_scan(
    first, last,
    destination,
    binary_op,
    unary_op
);

std::transform_exclusive_scan(
    first, last,
    destination,
    init,
    binary_op,
    unary_op
);

std::gcd(a, b);

std::lcm(a, b);

std::midpoint(a, b);
```

---

# 21. `<numeric>` Quick Selection

```text
Sequential fill
    -> iota

Left-to-right accumulation
    -> accumulate

Reduction where operation may be reordered
    -> reduce

Dot product
    -> inner_product

Prefix sum
    -> partial_sum / inclusive_scan

Exclusive prefix
    -> exclusive_scan

Difference between adjacent values
    -> adjacent_difference

Transform + reduction
    -> transform_reduce

Transform + inclusive scan
    -> transform_inclusive_scan

Transform + exclusive scan
    -> transform_exclusive_scan

Greatest common divisor
    -> gcd

Least common multiple
    -> lcm

Midpoint
    -> midpoint
```

---

# 22. C++20 `std::ranges` Algorithms

Header:

```cpp
#include <algorithm>
#include <ranges>
```

## Search / Non-modifying

```cpp
std::ranges::for_each
std::ranges::for_each_n

std::ranges::all_of
std::ranges::any_of
std::ranges::none_of

std::ranges::count
std::ranges::count_if

std::ranges::mismatch
std::ranges::equal

std::ranges::find
std::ranges::find_if
std::ranges::find_if_not
std::ranges::find_end
std::ranges::find_first_of
std::ranges::adjacent_find

std::ranges::search
std::ranges::search_n
```

## Copy / Move

```cpp
std::ranges::copy
std::ranges::copy_if
std::ranges::copy_n
std::ranges::copy_backward

std::ranges::move
std::ranges::move_backward
```

## Swap

```cpp
std::ranges::swap
std::ranges::swap_ranges
std::ranges::iter_swap
```

## Transform / Replace

```cpp
std::ranges::transform

std::ranges::replace
std::ranges::replace_if
std::ranges::replace_copy
std::ranges::replace_copy_if
```

## Fill / Generate

```cpp
std::ranges::fill
std::ranges::fill_n
std::ranges::generate
std::ranges::generate_n
```

## Remove / Unique

```cpp
std::ranges::remove
std::ranges::remove_if
std::ranges::remove_copy
std::ranges::remove_copy_if

std::ranges::unique
std::ranges::unique_copy
```

## Rearrangement

```cpp
std::ranges::reverse
std::ranges::reverse_copy

std::ranges::rotate
std::ranges::rotate_copy

std::ranges::shuffle
std::ranges::sample

std::ranges::shift_left
std::ranges::shift_right
```

## Partition

```cpp
std::ranges::partition
std::ranges::stable_partition
std::ranges::partition_copy
std::ranges::is_partitioned
std::ranges::partition_point
```

## Sorting

```cpp
std::ranges::sort
std::ranges::stable_sort
std::ranges::partial_sort
std::ranges::partial_sort_copy
std::ranges::nth_element
std::ranges::is_sorted
std::ranges::is_sorted_until
```

## Binary Search

```cpp
std::ranges::lower_bound
std::ranges::upper_bound
std::ranges::equal_range
std::ranges::binary_search
```

## Set

```cpp
std::ranges::includes
std::ranges::set_union
std::ranges::set_intersection
std::ranges::set_difference
std::ranges::set_symmetric_difference
```

## Merge

```cpp
std::ranges::merge
std::ranges::inplace_merge
```

## Heap

```cpp
std::ranges::push_heap
std::ranges::pop_heap
std::ranges::make_heap
std::ranges::sort_heap
std::ranges::is_heap
std::ranges::is_heap_until
```

## Min / Max

```cpp
std::ranges::min
std::ranges::max
std::ranges::minmax

std::ranges::min_element
std::ranges::max_element
std::ranges::minmax_element

std::ranges::clamp
```

## Comparison

```cpp
std::ranges::lexicographical_compare
std::ranges::lexicographical_compare_three_way
```

## Permutation

```cpp
std::ranges::next_permutation
std::ranges::prev_permutation
std::ranges::is_permutation
```

---

# 23. C++23 Ranges Additions

```cpp
std::ranges::contains
std::ranges::contains_subrange

std::ranges::find_last
std::ranges::find_last_if
std::ranges::find_last_if_not

std::ranges::starts_with
std::ranges::ends_with

std::ranges::fold_left
std::ranges::fold_left_first
std::ranges::fold_right
std::ranges::fold_right_last
std::ranges::fold_left_with_iter
std::ranges::fold_left_first_with_iter
```

From `<numeric>`:

```cpp
std::ranges::iota
```

---

# 24. C++20/23 Ranges with Projections

Many ranges algorithms support a projection parameter.

Examples:

```cpp
std::ranges::sort(
    students,
    {},
    &Student::marks
);

std::ranges::find(
    students,
    90,
    &Student::marks
);

std::ranges::lower_bound(
    students,
    80,
    {},
    &Student::marks
);
```

This section only lists usage; projection theory is a separate topic.

---

# 25. Execution Policies

Header:

```cpp
#include <execution>
```

```cpp
std::execution::seq
std::execution::par
std::execution::par_unseq
std::execution::unseq              // C++20
```

Execution-policy overloads exist for many classic algorithms.

Example:

```cpp
std::sort(
    std::execution::par,
    v.begin(),
    v.end()
);
```

---

# 26. `<memory>` Specialized Algorithms

These are specialized object-lifetime algorithms rather than the main
`<algorithm>` list.

```cpp
std::uninitialized_copy
std::uninitialized_copy_n

std::uninitialized_move
std::uninitialized_move_n

std::uninitialized_fill
std::uninitialized_fill_n

std::uninitialized_default_construct
std::uninitialized_default_construct_n

std::uninitialized_value_construct
std::uninitialized_value_construct_n

std::destroy
std::destroy_n

std::destroy_at                  // C++17
std::construct_at                // C++20
```

---

# 27. C++26 Additions

C++26 library support is implementation-dependent.

## Random range generation

```cpp
std::ranges::generate_random
```

Header:

```cpp
#include <random>
```

## Saturating integer arithmetic

Header:

```cpp
#include <numeric>
```

```cpp
std::saturating_add
std::saturating_sub
std::saturating_mul
std::saturating_div
std::saturate_cast
```

## Parallel range algorithms

C++26 extends execution-policy support to range algorithms. Check the
specific compiler/library implementation for availability.

---

# 28. Removed / Deprecated Algorithm

## `std::random_shuffle`

```cpp
std::random_shuffle(first, last);
```

Status:

```text
C++11       available
C++14       deprecated
C++17       removed
```

Replacement:

```cpp
std::shuffle(first, last, generator);
```

---

# 29. Complexity Quick Reference

| Algorithm | Typical complexity |
|---|---:|
| `find` | O(n) |
| `count` | O(n) |
| `count_if` | O(n) |
| `all_of` | O(n), early termination |
| `any_of` | O(n), early termination |
| `none_of` | O(n), early termination |
| `copy` | O(n) |
| `transform` | O(n) |
| `replace` | O(n) |
| `fill` | O(n) |
| `remove` | O(n) |
| `unique` | O(n) |
| `reverse` | O(n) |
| `rotate` | O(n) |
| `partition` | O(n) |
| `sort` | O(n log n) comparisons |
| `stable_sort` | O(n log n) comparisons with sufficient memory |
| `partial_sort` | O(n log k) typical |
| `nth_element` | O(n) average comparisons |
| `lower_bound` | O(log n) comparisons |
| `upper_bound` | O(log n) comparisons |
| `binary_search` | O(log n) comparisons |
| `make_heap` | O(n) |
| `push_heap` | O(log n) |
| `pop_heap` | O(log n) |
| `sort_heap` | O(n log n) |
| `min_element` | O(n) |
| `max_element` | O(n) |
| `next_permutation` | O(n) |
| `accumulate` | O(n) operations |
| `reduce` | O(n) operations |
| `partial_sum` | O(n) |
| `iota` | O(n) |

Exact complexity depends on the overload, iterator category and standard
version.

---

# 30. Final Algorithm Checklist

## `<algorithm>`

- [ ] `for_each`
- [ ] `for_each_n`
- [ ] `all_of`
- [ ] `any_of`
- [ ] `none_of`
- [ ] `count`
- [ ] `count_if`
- [ ] `mismatch`
- [ ] `equal`
- [ ] `is_permutation`
- [ ] `find`
- [ ] `find_if`
- [ ] `find_if_not`
- [ ] `find_end`
- [ ] `find_first_of`
- [ ] `adjacent_find`
- [ ] `search`
- [ ] `search_n`
- [ ] `copy`
- [ ] `copy_if`
- [ ] `copy_n`
- [ ] `copy_backward`
- [ ] `move`
- [ ] `move_backward`
- [ ] `swap`
- [ ] `iter_swap`
- [ ] `swap_ranges`
- [ ] `transform`
- [ ] `replace`
- [ ] `replace_if`
- [ ] `replace_copy`
- [ ] `replace_copy_if`
- [ ] `fill`
- [ ] `fill_n`
- [ ] `generate`
- [ ] `generate_n`
- [ ] `remove`
- [ ] `remove_if`
- [ ] `remove_copy`
- [ ] `remove_copy_if`
- [ ] `unique`
- [ ] `unique_copy`
- [ ] `reverse`
- [ ] `reverse_copy`
- [ ] `rotate`
- [ ] `rotate_copy`
- [ ] `shuffle`
- [ ] `sample`
- [ ] `shift_left`
- [ ] `shift_right`
- [ ] `partition`
- [ ] `partition_copy`
- [ ] `stable_partition`
- [ ] `is_partitioned`
- [ ] `partition_point`
- [ ] `sort`
- [ ] `stable_sort`
- [ ] `partial_sort`
- [ ] `partial_sort_copy`
- [ ] `nth_element`
- [ ] `is_sorted`
- [ ] `is_sorted_until`
- [ ] `lower_bound`
- [ ] `upper_bound`
- [ ] `equal_range`
- [ ] `binary_search`
- [ ] `includes`
- [ ] `set_union`
- [ ] `set_intersection`
- [ ] `set_difference`
- [ ] `set_symmetric_difference`
- [ ] `merge`
- [ ] `inplace_merge`
- [ ] `push_heap`
- [ ] `pop_heap`
- [ ] `make_heap`
- [ ] `sort_heap`
- [ ] `is_heap`
- [ ] `is_heap_until`
- [ ] `min`
- [ ] `max`
- [ ] `minmax`
- [ ] `min_element`
- [ ] `max_element`
- [ ] `minmax_element`
- [ ] `clamp`
- [ ] `lexicographical_compare`
- [ ] `lexicographical_compare_three_way`
- [ ] `next_permutation`
- [ ] `prev_permutation`
- [ ] `is_permutation`

## `<numeric>`

- [ ] `iota`
- [ ] `accumulate`
- [ ] `reduce`
- [ ] `inner_product`
- [ ] `partial_sum`
- [ ] `adjacent_difference`
- [ ] `inclusive_scan`
- [ ] `exclusive_scan`
- [ ] `transform_reduce`
- [ ] `transform_inclusive_scan`
- [ ] `transform_exclusive_scan`
- [ ] `gcd`
- [ ] `lcm`
- [ ] `midpoint`

## C++20/23 Ranges

- [ ] `ranges::for_each`
- [ ] `ranges::all_of`
- [ ] `ranges::any_of`
- [ ] `ranges::none_of`
- [ ] `ranges::count`
- [ ] `ranges::count_if`
- [ ] `ranges::find`
- [ ] `ranges::find_if`
- [ ] `ranges::find_if_not`
- [ ] `ranges::find_end`
- [ ] `ranges::find_first_of`
- [ ] `ranges::adjacent_find`
- [ ] `ranges::search`
- [ ] `ranges::search_n`
- [ ] `ranges::copy`
- [ ] `ranges::copy_if`
- [ ] `ranges::copy_n`
- [ ] `ranges::copy_backward`
- [ ] `ranges::move`
- [ ] `ranges::move_backward`
- [ ] `ranges::swap_ranges`
- [ ] `ranges::transform`
- [ ] `ranges::replace`
- [ ] `ranges::replace_if`
- [ ] `ranges::replace_copy`
- [ ] `ranges::replace_copy_if`
- [ ] `ranges::fill`
- [ ] `ranges::fill_n`
- [ ] `ranges::generate`
- [ ] `ranges::generate_n`
- [ ] `ranges::remove`
- [ ] `ranges::remove_if`
- [ ] `ranges::remove_copy`
- [ ] `ranges::remove_copy_if`
- [ ] `ranges::unique`
- [ ] `ranges::unique_copy`
- [ ] `ranges::reverse`
- [ ] `ranges::reverse_copy`
- [ ] `ranges::rotate`
- [ ] `ranges::rotate_copy`
- [ ] `ranges::shuffle`
- [ ] `ranges::sample`
- [ ] `ranges::shift_left`
- [ ] `ranges::shift_right`
- [ ] `ranges::partition`
- [ ] `ranges::stable_partition`
- [ ] `ranges::partition_copy`
- [ ] `ranges::is_partitioned`
- [ ] `ranges::partition_point`
- [ ] `ranges::sort`
- [ ] `ranges::stable_sort`
- [ ] `ranges::partial_sort`
- [ ] `ranges::partial_sort_copy`
- [ ] `ranges::nth_element`
- [ ] `ranges::is_sorted`
- [ ] `ranges::is_sorted_until`
- [ ] `ranges::lower_bound`
- [ ] `ranges::upper_bound`
- [ ] `ranges::equal_range`
- [ ] `ranges::binary_search`
- [ ] `ranges::includes`
- [ ] `ranges::set_union`
- [ ] `ranges::set_intersection`
- [ ] `ranges::set_difference`
- [ ] `ranges::set_symmetric_difference`
- [ ] `ranges::merge`
- [ ] `ranges::inplace_merge`
- [ ] `ranges::make_heap`
- [ ] `ranges::push_heap`
- [ ] `ranges::pop_heap`
- [ ] `ranges::sort_heap`
- [ ] `ranges::is_heap`
- [ ] `ranges::is_heap_until`
- [ ] `ranges::min`
- [ ] `ranges::max`
- [ ] `ranges::minmax`
- [ ] `ranges::min_element`
- [ ] `ranges::max_element`
- [ ] `ranges::minmax_element`
- [ ] `ranges::clamp`
- [ ] `ranges::lexicographical_compare`
- [ ] `ranges::lexicographical_compare_three_way`
- [ ] `ranges::next_permutation`
- [ ] `ranges::prev_permutation`
- [ ] `ranges::is_permutation`
- [ ] `ranges::contains`
- [ ] `ranges::contains_subrange`
- [ ] `ranges::find_last`
- [ ] `ranges::find_last_if`
- [ ] `ranges::find_last_if_not`
- [ ] `ranges::starts_with`
- [ ] `ranges::ends_with`
- [ ] `ranges::fold_left`
- [ ] `ranges::fold_left_first`
- [ ] `ranges::fold_right`
- [ ] `ranges::fold_right_last`
- [ ] `ranges::fold_left_with_iter`
- [ ] `ranges::fold_left_first_with_iter`
- [ ] `ranges::iota`

---

# Important Scope

This document covers **STL/range algorithms**, not every function in the
entire C++ Standard Library.

These are separate library topics and should have their own notes:

```text
std::less
std::greater
std::equal_to
std::less_equal
std::greater_equal
std::function
std::bind
std::invoke
lambda expressions
functors
iterators
containers
views
random distributions
math functions
string functions
```

They can be used with algorithms but are not themselves the complete
algorithm inventory.

