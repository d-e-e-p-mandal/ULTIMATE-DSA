# Java Set --- 100% Complete Notes

> **Goal:** Complete Java `Set` coverage from beginner to advanced
> level, including `Set` interface, uniqueness, equality, hashing,
> `HashSet`, `LinkedHashSet`, `TreeSet`, `SortedSet`, `NavigableSet`,
> concurrent sets, immutable sets, set operations, ordering,
> comparators, internals, complexity, performance, pitfalls, algorithms,
> real-world usage, and interview questions.

------------------------------------------------------------------------

# PART 1 --- SET FUNDAMENTALS

## 1. What Is a Set?

A **Set** is a collection that does not allow duplicate elements
according to its equality rules.

Example:

``` java
Set<Integer> set = new HashSet<>();

set.add(10);
set.add(20);
set.add(10);
```

Logical contents:

``` text
10
20
```

The second `10` is not added as a distinct element.

------------------------------------------------------------------------

## 2. Main Property of Set

The most important concept is:

``` text
Set → uniqueness
```

A Set is useful when you care about:

-   Unique values
-   Membership testing
-   Removing duplicates
-   Mathematical set operations
-   Fast lookup
-   Ordered unique data, when using an ordered Set implementation

------------------------------------------------------------------------

## 3. Java Set Interface

Package:

``` java
java.util.Set
```

Declaration:

``` java
public interface Set<E> extends Collection<E>
```

Hierarchy:

``` text
Iterable
   ↓
Collection
   ↓
Set
   ↓
Implementations
```

Important implementations:

``` text
Set
├── HashSet
├── LinkedHashSet
├── SortedSet
│   └── NavigableSet
│       └── TreeSet
├── EnumSet
└── ConcurrentHashMap-based Set
```

------------------------------------------------------------------------

# PART 2 --- SET VS COLLECTION

## 4. Set Is a Collection

Because:

``` java
Set<E> extends Collection<E>
```

Set inherits many methods:

``` java
add()
remove()
contains()
size()
isEmpty()
clear()
iterator()
toArray()
addAll()
removeAll()
retainAll()
containsAll()
```

The major semantic difference is uniqueness.

------------------------------------------------------------------------

## 5. Duplicate Example

``` java
Set<String> names = new HashSet<>();

names.add("Deep");
names.add("Rahul");
names.add("Deep");
```

The Set contains only:

``` text
Deep
Rahul
```

------------------------------------------------------------------------

# PART 3 --- CREATING SETS

## 6. HashSet

``` java
Set<Integer> set =
    new HashSet<>();
```

------------------------------------------------------------------------

## 7. LinkedHashSet

``` java
Set<Integer> set =
    new LinkedHashSet<>();
```

------------------------------------------------------------------------

## 8. TreeSet

``` java
Set<Integer> set =
    new TreeSet<>();
```

------------------------------------------------------------------------

## 9. EnumSet

``` java
enum Status {
    NEW,
    PROCESSING,
    COMPLETE
}

Set<Status> statuses =
    EnumSet.of(
        Status.NEW,
        Status.COMPLETE
    );
```

------------------------------------------------------------------------

# PART 4 --- SET ADD

## 10. `add()`

``` java
Set<Integer> set =
    new HashSet<>();

boolean added = set.add(10);
```

Returns:

``` text
true
```

if the Set changed.

------------------------------------------------------------------------

## 11. Duplicate Add

``` java
set.add(10);
```

again returns:

``` text
false
```

because `10` is already present.

This makes `add()` useful for detecting whether an element was newly
inserted.

------------------------------------------------------------------------

# PART 5 --- SET REMOVE

## 12. `remove()`

``` java
set.remove(10);
```

Returns:

``` text
true
```

if an element was removed.

If the element is absent:

``` text
false
```

------------------------------------------------------------------------

## 13. Clear

``` java
set.clear();
```

Removes all elements.

------------------------------------------------------------------------

# PART 6 --- SET LOOKUP

## 14. `contains()`

``` java
if (set.contains(20)) {
    System.out.println("Found");
}
```

`contains()` is one of the most important reasons to use a Set.

For `HashSet`, average lookup is typically:

``` text
O(1)
```

------------------------------------------------------------------------

## 15. `size()`

``` java
int count = set.size();
```

Returns the number of unique elements.

------------------------------------------------------------------------

## 16. `isEmpty()`

``` java
if (set.isEmpty()) {
    System.out.println("Empty");
}
```

------------------------------------------------------------------------

# PART 7 --- SET ITERATION

## 17. Enhanced For Loop

``` java
for (Integer value : set) {
    System.out.println(value);
}
```

The iteration order depends on the implementation.

------------------------------------------------------------------------

## 18. Iterator

``` java
Iterator<Integer> iterator =
    set.iterator();

while (iterator.hasNext()) {
    System.out.println(iterator.next());
}
```

------------------------------------------------------------------------

## 19. Iterator Remove

``` java
Iterator<Integer> iterator =
    set.iterator();

while (iterator.hasNext()) {

    Integer value =
        iterator.next();

    if (value == 20) {
        iterator.remove();
    }
}
```

Use the iterator's `remove()` when removing during iteration is
required.

------------------------------------------------------------------------

# PART 8 --- HASHSET

## 20. What Is HashSet?

`HashSet` is the most commonly used general-purpose Set implementation.

Package:

``` java
java.util.HashSet
```

Characteristics:

``` text
Unique elements
No guaranteed iteration order
Hash-based lookup
Allows one null element
Not thread-safe
```

------------------------------------------------------------------------

## 21. Example

``` java
Set<String> set =
    new HashSet<>();

set.add("A");
set.add("B");
set.add("A");

System.out.println(set);
```

Only one `"A"` is stored.

------------------------------------------------------------------------

# PART 9 --- HASHSET INTERNAL CONCEPT

## 22. Hash-Based Storage

Conceptually:

``` text
Element
   ↓
hashCode()
   ↓
hash
   ↓
bucket
```

Example:

``` text
"Deep"
   ↓
hashCode()
   ↓
bucket index
```

------------------------------------------------------------------------

## 23. Bucket Concept

Conceptually:

``` text
Bucket 0 → ...
Bucket 1 → ...
Bucket 2 → [A]
Bucket 3 → ...
Bucket 4 → [B]
Bucket 5 → ...
```

The actual internal implementation is more detailed, but this is the
core mental model.

------------------------------------------------------------------------

# PART 10 --- HASHCODE AND EQUALS

## 24. Why `equals()` and `hashCode()` Matter

Hash-based Sets depend on:

``` java
hashCode()
equals()
```

For objects considered equal:

``` java
a.equals(b) == true
```

they must have:

``` java
a.hashCode() == b.hashCode()
```

------------------------------------------------------------------------

## 25. Example

``` java
class Employee {

    int id;

    Employee(int id) {
        this.id = id;
    }

    @Override
    public boolean equals(Object obj) {

        if (!(obj instanceof Employee other)) {
            return false;
        }

        return id == other.id;
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(id);
    }
}
```

Now:

``` java
Set<Employee> employees =
    new HashSet<>();

employees.add(new Employee(1));
employees.add(new Employee(1));
```

Only one logical employee is stored.

------------------------------------------------------------------------

# PART 11 --- HASHSET DUPLICATE PROCESS

## 26. What Happens During `add()`?

Conceptually:

``` text
add(element)
    ↓
calculate hash
    ↓
find bucket
    ↓
check existing candidates
    ↓
equals()
    ↓
equal?
 ┌──────┴──────┐
YES           NO
 ↓             ↓
reject       insert
```

This is the key idea behind hash-based uniqueness.

------------------------------------------------------------------------

# PART 12 --- HASH COLLISION

## 27. What Is Collision?

Two different objects can produce the same hash value or map to the same
bucket.

Example conceptually:

``` text
A → bucket 5
B → bucket 5
```

This is a collision.

Hash-based collections handle collisions internally.

------------------------------------------------------------------------

## 28. Collision Does Not Mean Duplicate

Important:

``` text
same hash
≠
same object
```

Two objects can have:

``` java
hashCode() same
```

but:

``` java
equals() false
```

They can still both exist in a Set.

------------------------------------------------------------------------

# PART 13 --- HASHSET COMPLEXITY

## 29. Typical Complexity

Average-case:

  Operation        Complexity
  -------------- ------------
  `add()`                O(1)
  `contains()`           O(1)
  `remove()`             O(1)
  `size()`               O(1)
  iteration              O(n)

Worst-case behavior depends on collisions and implementation details.

Modern Java implementations can treeify heavily contended hash buckets
under appropriate conditions.

------------------------------------------------------------------------

# PART 14 --- HASHSET NULL

## 30. Does HashSet Allow Null?

Yes.

A `HashSet` can contain one `null` element.

Example:

``` java
Set<String> set =
    new HashSet<>();

set.add(null);
set.add(null);
```

Only one `null` can exist because the Set still enforces uniqueness.

------------------------------------------------------------------------

# PART 15 --- LINKEDHASHSET

## 31. What Is LinkedHashSet?

`LinkedHashSet` is a Set that maintains insertion order during
iteration.

Package:

``` java
java.util.LinkedHashSet
```

Example:

``` java
Set<Integer> set =
    new LinkedHashSet<>();

set.add(30);
set.add(10);
set.add(20);
```

Iteration:

``` text
30
10
20
```

------------------------------------------------------------------------

## 32. LinkedHashSet Internal Concept

It combines:

``` text
Hash-based lookup
+
linked ordering information
```

Conceptually:

``` text
Hash structure

plus

30 ↔ 10 ↔ 20
```

The linked structure maintains iteration order.

------------------------------------------------------------------------

# PART 16 --- LINKEDHASHSET CHARACTERISTICS

## 33. Features

``` text
Unique
Insertion-order iteration
Hash-based
Allows one null
Not thread-safe
```

------------------------------------------------------------------------

## 34. LinkedHashSet Complexity

Typical:

  Operation          Complexity
  -------------- --------------
  `add()`          O(1) average
  `contains()`     O(1) average
  `remove()`       O(1) average
  iteration                O(n)

It generally has more memory overhead than `HashSet` because ordering
information is maintained.

------------------------------------------------------------------------

# PART 17 --- HASHSET VS LINKEDHASHSET

## 35. Comparison

  Feature           HashSet        LinkedHashSet
  ----------------- -------------- ---------------
  Unique            Yes            Yes
  Hash-based        Yes            Yes
  Insertion order   No guarantee   Yes
  Null              One            One
  Thread-safe       No             No
  Memory            Lower          Higher
  Typical lookup    O(1) avg       O(1) avg

Use:

``` text
HashSet → order does not matter
LinkedHashSet → insertion order matters
```

------------------------------------------------------------------------

# PART 18 --- SORTEDSET

## 36. What Is SortedSet?

`SortedSet` is an interface for Sets that maintain elements according to
an ordering.

Package:

``` java
java.util.SortedSet
```

Declaration:

``` java
public interface SortedSet<E>
    extends Set<E>
```

Important methods:

``` java
comparator()
first()
last()
headSet()
tailSet()
subSet()
```

------------------------------------------------------------------------

# PART 19 --- TREESET

## 37. What Is TreeSet?

`TreeSet` is a sorted, navigable Set implementation.

Package:

``` java
java.util.TreeSet
```

Hierarchy:

``` text
Set
 ↓
SortedSet
 ↓
NavigableSet
 ↓
TreeSet
```

------------------------------------------------------------------------

## 38. TreeSet Example

``` java
Set<Integer> set =
    new TreeSet<>();

set.add(30);
set.add(10);
set.add(20);
```

Iteration:

``` text
10
20
30
```

------------------------------------------------------------------------

# PART 20 --- TREESET INTERNAL STRUCTURE

## 39. Tree-Based Ordering

`TreeSet` is backed by a tree-based map structure.

Conceptually:

``` text
       20
      /  \
    10    30
```

The tree maintains ordering.

Modern Java's `TreeMap`, which backs `TreeSet`, is a Red-Black tree.

------------------------------------------------------------------------

# PART 21 --- TREESET COMPLEXITY

## 40. Complexity

Typical:

  Operation        Complexity
  -------------- ------------
  `add()`            O(log n)
  `contains()`       O(log n)
  `remove()`         O(log n)
  `first()`          O(log n)
  `last()`           O(log n)
  iteration              O(n)

TreeSet trades hash-based average O(1) lookup for ordered O(log n)
operations.

------------------------------------------------------------------------

# PART 22 --- TREESET NATURAL ORDERING

## 41. Comparable

TreeSet can use natural ordering.

Example:

``` java
TreeSet<Integer> set =
    new TreeSet<>();

set.add(30);
set.add(10);
set.add(20);
```

The elements are ordered according to their natural ordering.

------------------------------------------------------------------------

## 42. Strings

``` java
TreeSet<String> set =
    new TreeSet<>();

set.add("Banana");
set.add("Apple");
set.add("Mango");
```

Result:

``` text
Apple
Banana
Mango
```

------------------------------------------------------------------------

# PART 23 --- COMPARATOR

## 43. TreeSet With Comparator

``` java
TreeSet<Integer> set =
    new TreeSet<>(Comparator.reverseOrder());
```

Now:

``` text
30
20
10
```

------------------------------------------------------------------------

## 44. Custom Object Comparator

``` java
class Employee {

    String name;
    int salary;

    Employee(String name, int salary) {
        this.name = name;
        this.salary = salary;
    }
}
```

Create:

``` java
TreeSet<Employee> employees =
    new TreeSet<>(
        Comparator.comparingInt(
            employee -> employee.salary
        )
    );
```

Elements are ordered by salary.

------------------------------------------------------------------------

# PART 24 --- TREESET AND EQUALITY

## 45. Important TreeSet Difference

For a `TreeSet`, ordering comparison determines whether an element is
considered duplicate for Set purposes.

If:

``` java
compare(a, b) == 0
```

the TreeSet treats them as equivalent for its sorted-set ordering.

Therefore:

``` text
compareTo() / Comparator
```

must be designed carefully.

------------------------------------------------------------------------

## 46. Comparable Consistency

Ideally, natural ordering should be consistent with `equals()`.

If ordering is inconsistent with equality, Set behavior can surprise
developers.

Example concept:

``` text
equals() → false
compareTo() → 0
```

TreeSet may store only one of them.

------------------------------------------------------------------------

# PART 25 --- TREESET NAVIGATION

## 47. NavigableSet

`TreeSet` implements:

``` java
NavigableSet<E>
```

This adds navigation operations.

Important methods:

``` java
lower()
floor()
ceiling()
higher()
```

------------------------------------------------------------------------

## 48. `lower()`

``` java
set.lower(20);
```

Returns the greatest element strictly less than `20`.

Example:

``` text
10 20 30
```

Result:

``` text
10
```

------------------------------------------------------------------------

## 49. `floor()`

``` java
set.floor(20);
```

Returns the greatest element less than or equal to `20`.

Example:

``` text
10 20 30
```

Result:

``` text
20
```

If `20` does not exist:

``` text
floor(25) → 20
```

------------------------------------------------------------------------

## 50. `ceiling()`

``` java
set.ceiling(20);
```

Returns the smallest element greater than or equal to `20`.

Example:

``` text
10 20 30
```

Result:

``` text
20
```

------------------------------------------------------------------------

## 51. `higher()`

``` java
set.higher(20);
```

Returns the smallest element strictly greater than `20`.

Result:

``` text
30
```

------------------------------------------------------------------------

# PART 26 --- NAVIGATION TABLE

## 52. Navigation

For:

``` text
10 20 30
```

  Method            Query   Result
  --------------- ------- --------
  `lower(20)`          20       10
  `floor(20)`          20       20
  `ceiling(20)`        20       20
  `higher(20)`         20       30

Memory trick:

``` text
lower   → <
floor   → <=
ceiling → >=
higher  → >
```

------------------------------------------------------------------------

# PART 27 --- FIRST AND LAST

## 53. `first()`

``` java
set.first();
```

Returns the smallest element according to the Set's ordering.

------------------------------------------------------------------------

## 54. `last()`

``` java
set.last();
```

Returns the largest element according to the Set's ordering.

For an empty TreeSet these methods throw `NoSuchElementException`.

------------------------------------------------------------------------

# PART 28 --- POLLING TREESET

## 55. `pollFirst()`

``` java
NavigableSet<Integer> set =
    new TreeSet<>();

set.add(10);
set.add(20);
set.add(30);

set.pollFirst();
```

Removes and returns the smallest element.

------------------------------------------------------------------------

## 56. `pollLast()`

``` java
set.pollLast();
```

Removes and returns the largest element.

If empty, these polling methods return `null`.

------------------------------------------------------------------------

# PART 29 --- HEADSET

## 57. `headSet()`

``` java
SortedSet<Integer> result =
    set.headSet(30);
```

The returned view contains elements less than `30` by default.

With `NavigableSet`:

``` java
set.headSet(30, true);
```

can include `30`.

------------------------------------------------------------------------

# PART 30 --- TAILSET

## 58. `tailSet()`

``` java
SortedSet<Integer> result =
    set.tailSet(20);
```

Contains elements greater than or equal to `20` under the `SortedSet`
contract.

------------------------------------------------------------------------

# PART 31 --- SUBSET

## 59. `subSet()`

``` java
SortedSet<Integer> result =
    set.subSet(10, 30);
```

The classic `SortedSet` form represents:

``` text
10 <= x < 30
```

With `NavigableSet`, inclusive/exclusive endpoints can be explicitly
selected:

``` java
set.subSet(10, true, 30, true);
```

------------------------------------------------------------------------

# PART 32 --- SET VIEWS

## 60. Important: Views

Methods such as:

``` java
headSet()
tailSet()
subSet()
```

return views rather than necessarily independent copies.

Changing a view can affect the original Set.

Example concept:

``` text
Original TreeSet
      ↕
Subset View
```

Always remember this when modifying sorted-set ranges.

------------------------------------------------------------------------

# PART 33 --- DESCENDINGSET

## 61. `descendingSet()`

`NavigableSet` provides:

``` java
NavigableSet<Integer> reverse =
    treeSet.descendingSet();
```

If original order:

``` text
10 20 30
```

descending view:

``` text
30 20 10
```

It is a view of the same underlying Set.

------------------------------------------------------------------------

# PART 34 --- DESCENDINGITERATOR

## 62. Reverse Iteration

``` java
Iterator<Integer> iterator =
    treeSet.descendingIterator();

while (iterator.hasNext()) {
    System.out.println(iterator.next());
}
```

Useful when processing sorted data from largest to smallest.

------------------------------------------------------------------------

# PART 35 --- TREESET NULL

## 63. Null in TreeSet

A `TreeSet` generally cannot contain `null` when natural ordering is
used because comparisons are required.

Example:

``` java
TreeSet<Integer> set =
    new TreeSet<>();

set.add(null);
```

can result in:

``` text
NullPointerException
```

Do not use null in a TreeSet unless the chosen comparator and
implementation semantics explicitly support it and you understand the
consequences.

------------------------------------------------------------------------

# PART 36 --- ENUMSET

## 64. What Is EnumSet?

`EnumSet` is a specialized Set for enum values.

Package:

``` java
java.util.EnumSet
```

Example:

``` java
enum Permission {
    READ,
    WRITE,
    DELETE
}

EnumSet<Permission> permissions =
    EnumSet.of(
        Permission.READ,
        Permission.WRITE
    );
```

------------------------------------------------------------------------

## 65. EnumSet Advantages

Because enum values come from a fixed universe, `EnumSet` can use a
compact bit-based representation.

It is generally very efficient for enum sets.

------------------------------------------------------------------------

# PART 37 --- ENUMSET FACTORY METHODS

## 66. `EnumSet.of()`

``` java
EnumSet<Permission> set =
    EnumSet.of(
        Permission.READ,
        Permission.WRITE
    );
```

------------------------------------------------------------------------

## 67. `EnumSet.allOf()`

``` java
EnumSet<Permission> set =
    EnumSet.allOf(Permission.class);
```

Contains every enum constant.

------------------------------------------------------------------------

## 68. `EnumSet.noneOf()`

``` java
EnumSet<Permission> set =
    EnumSet.noneOf(Permission.class);
```

Starts empty.

------------------------------------------------------------------------

## 69. `EnumSet.range()`

``` java
EnumSet<Permission> set =
    EnumSet.range(
        Permission.READ,
        Permission.DELETE
    );
```

Includes enum constants between the specified endpoints in declaration
order.

------------------------------------------------------------------------

# PART 38 --- ENUMSET CHARACTERISTICS

## 70. EnumSet

``` text
Unique
Enum-only
Very compact
Fast
Ordered according to enum declaration order
Not thread-safe
```

EnumSet should generally be preferred over general-purpose Sets when the
domain is specifically an enum.

------------------------------------------------------------------------

# PART 39 --- IMMUTABLE SETS

## 71. `Set.of()`

Java provides factory methods for unmodifiable Sets.

Example:

``` java
Set<String> set =
    Set.of(
        "A",
        "B",
        "C"
    );
```

------------------------------------------------------------------------

## 72. Duplicate Values With `Set.of()`

This is invalid:

``` java
Set.of(
    "A",
    "A"
);
```

It throws:

``` text
IllegalArgumentException
```

because duplicate elements are not allowed.

------------------------------------------------------------------------

## 73. Null With `Set.of()`

This is invalid:

``` java
Set.of(
    "A",
    null
);
```

It throws:

``` text
NullPointerException
```

------------------------------------------------------------------------

# PART 40 --- `Set.copyOf()`

## 74. Copying a Set

``` java
Set<String> copy =
    Set.copyOf(original);
```

The result is unmodifiable.

It does not create a mutable Set.

------------------------------------------------------------------------

# PART 41 --- UNMODIFIABLE SET

## 75. `Collections.unmodifiableSet()`

``` java
Set<String> view =
    Collections.unmodifiableSet(
        original
    );
```

This prevents modification through the returned reference.

However, if `original` changes, the unmodifiable view can reflect those
changes.

This is different from creating an independent immutable snapshot.

------------------------------------------------------------------------

# PART 42 --- IMMUTABLE VS UNMODIFIABLE

## 76. Important Difference

### Unmodifiable view

``` java
Collections.unmodifiableSet(original);
```

Concept:

``` text
Original Set
    ↑
    |
Unmodifiable View
```

The original can still change.

### `Set.copyOf()`

Creates an unmodifiable result based on the source contents.

The returned Set itself cannot be modified.

------------------------------------------------------------------------

# PART 43 --- CONCURRENT SETS

## 77. Thread-Safe Set From ConcurrentHashMap

Java provides:

``` java
ConcurrentHashMap.newKeySet()
```

Example:

``` java
Set<String> set =
    ConcurrentHashMap.newKeySet();

set.add("A");
set.add("B");
```

This is a concurrent Set suitable for many concurrent workloads.

------------------------------------------------------------------------

## 78. Concurrent Set Characteristics

``` text
Thread-safe
High concurrency
Hash-based
No null elements
No blocking
```

It is different from:

``` java
Collections.synchronizedSet(...)
```

which uses synchronization around a normal Set.

------------------------------------------------------------------------

# PART 44 --- SYNCHRONIZED SET

## 79. `Collections.synchronizedSet()`

``` java
Set<Integer> set =
    Collections.synchronizedSet(
        new HashSet<>()
    );
```

The wrapper synchronizes access to the underlying Set.

When iterating, external synchronization is generally required according
to the wrapper's contract:

``` java
synchronized (set) {
    for (Integer value : set) {
        System.out.println(value);
    }
}
```

------------------------------------------------------------------------

# PART 45 --- CONCURRENT SET COMPARISON

## 80. Concurrent Choices

  ----------------------------------------------------------------------------------------
  Type                              Thread-safe       Blocking          Typical purpose
  --------------------------------- ----------------- ----------------- ------------------
  `HashSet`                         No                No                Normal Set

  `Collections.synchronizedSet`     Yes               No                Simple
                                                                        synchronized
                                                                        wrapper

  `ConcurrentHashMap.newKeySet()`   Yes               No                High-concurrency
                                                                        Set

  `CopyOnWriteArraySet`             Yes               No                Read-heavy,
                                                                        infrequent writes
  ----------------------------------------------------------------------------------------

------------------------------------------------------------------------

# PART 46 --- COPYONWRITEARRAYSET

## 81. What Is CopyOnWriteArraySet?

Package:

``` java
java.util.concurrent.CopyOnWriteArraySet
```

It is a thread-safe Set backed by copy-on-write behavior.

When a mutation occurs, a new backing array is created.

------------------------------------------------------------------------

## 82. Best Use Case

Good when:

``` text
Reads are very frequent
Writes are rare
```

Examples:

-   Listener collections
-   Observer registrations
-   Small configuration sets

Not ideal for:

``` text
frequent writes
large sets
```

because each write can require copying.

------------------------------------------------------------------------

# PART 47 --- SET OPERATIONS

## 83. Union

Mathematical union:

``` text
A ∪ B
```

contains all unique elements from both sets.

Java:

``` java
Set<Integer> union =
    new HashSet<>(a);

union.addAll(b);
```

------------------------------------------------------------------------

## 84. Intersection

Mathematical intersection:

``` text
A ∩ B
```

contains elements common to both.

Java:

``` java
Set<Integer> intersection =
    new HashSet<>(a);

intersection.retainAll(b);
```

------------------------------------------------------------------------

## 85. Difference

Mathematical difference:

``` text
A - B
```

Java:

``` java
Set<Integer> difference =
    new HashSet<>(a);

difference.removeAll(b);
```

------------------------------------------------------------------------

# PART 48 --- SYMMETRIC DIFFERENCE

## 86. Symmetric Difference

Elements present in exactly one of the two Sets.

Concept:

``` text
(A - B) ∪ (B - A)
```

Java:

``` java
Set<Integer> result =
    new HashSet<>(a);

result.addAll(b);

Set<Integer> common =
    new HashSet<>(a);

common.retainAll(b);

result.removeAll(common);
```

------------------------------------------------------------------------

# PART 49 --- SUBSET

## 87. `containsAll()`

To check whether:

``` text
A ⊇ B
```

use:

``` java
a.containsAll(b);
```

If true:

``` text
B is a subset of A
```

------------------------------------------------------------------------

# PART 50 --- DISJOINT SETS

## 88. `Collections.disjoint()`

Check whether two collections have no common elements:

``` java
boolean disjoint =
    Collections.disjoint(a, b);
```

Returns:

``` text
true
```

if they share no elements.

------------------------------------------------------------------------

# PART 51 --- SET EQUALITY

## 89. Set `equals()`

Two Sets are equal if they contain the same elements according to Set
equality semantics, regardless of iteration order.

Example:

``` java
Set<Integer> a =
    new HashSet<>(
        List.of(1, 2, 3)
    );

Set<Integer> b =
    new LinkedHashSet<>(
        List.of(3, 2, 1)
    );

System.out.println(a.equals(b));
```

Output:

``` text
true
```

------------------------------------------------------------------------

# PART 52 --- SET HASHCODE

## 90. Set Hash Code

Set implementations follow the Set contract for `hashCode()`.

The hash code is based on the elements rather than iteration order.

Therefore Sets containing the same elements should have the same hash
code.

------------------------------------------------------------------------

# PART 53 --- MUTABLE ELEMENTS

## 91. Dangerous Mutable Keys

Be careful when adding mutable objects to a hash-based Set.

Example:

``` java
class User {
    int id;

    @Override
    public int hashCode() {
        return Integer.hashCode(id);
    }
}
```

If `id` changes after insertion:

``` java
set.add(user);

user.id = 100;
```

the object may become difficult to locate because its hash-related
identity changed.

------------------------------------------------------------------------

## 92. Best Practice

Fields used in:

``` java
equals()
hashCode()
```

should generally remain stable while an object is stored in a hash-based
Set.

------------------------------------------------------------------------

# PART 54 --- MUTABLE TREESET ELEMENTS

## 93. TreeSet Ordering Must Stay Stable

If fields used by:

``` java
compareTo()
```

or the Set's `Comparator`

change while the object is inside a TreeSet, the tree's ordering can
become inconsistent with the object's new comparison result.

Avoid mutating ordering fields while the object is stored.

------------------------------------------------------------------------

# PART 55 --- HASHSET CAPACITY

## 94. Initial Capacity

HashSet has constructors allowing initial capacity and load factor.

Example:

``` java
HashSet<Integer> set =
    new HashSet<>(
        100,
        0.75f
    );
```

Parameters conceptually:

``` text
initial capacity
load factor
```

------------------------------------------------------------------------

# PART 56 --- LOAD FACTOR

## 95. What Is Load Factor?

Load factor controls when a hash table is resized.

Conceptually:

``` text
entries / capacity
```

When the threshold is exceeded, the table is resized.

The commonly used default load factor in HashMap/HashSet implementations
is:

``` text
0.75
```

but code should rely on API behavior rather than assuming internal
implementation details.

------------------------------------------------------------------------

# PART 57 --- RESIZING

## 96. HashSet Resize Concept

Conceptually:

``` text
small table
[ ][A][ ][B]

        ↓ threshold reached

larger table
[ ][ ][A][ ][B][ ][ ][ ]
```

Resizing can be expensive at the moment it occurs.

Over many insertions, normal insertion remains approximately O(1) on
average.

------------------------------------------------------------------------

# PART 58 --- TREESET COMPARATOR

## 97. Comparator Must Be Consistent

Example:

``` java
Comparator<Employee> comparator =
    Comparator.comparingInt(
        employee -> employee.id
    );
```

If two employees have the same ID:

``` text
compare() == 0
```

TreeSet treats them as equivalent for Set insertion.

Therefore choose comparator fields carefully.

------------------------------------------------------------------------

# PART 59 --- HASHSET VS TREESET

## 98. Comparison

  Feature            HashSet               TreeSet
  ------------------ --------------------- -----------------------------------------
  Unique             Yes                   Yes
  Ordering           No guaranteed order   Sorted
  Lookup average     O(1)                  O(log n)
  Add average        O(1)                  O(log n)
  Remove average     O(1)                  O(log n)
  Null               One null              Generally no null with natural ordering
  Range queries      No                    Yes
  Navigation         No                    Yes
  Internal concept   Hash table            Red-Black tree

Use:

``` text
HashSet → fast membership, order not needed
TreeSet → sorted data / range navigation
```

------------------------------------------------------------------------

# PART 60 --- LINKEDHASHSET VS TREESET

## 99. Comparison

  Feature            LinkedHashSet   TreeSet
  ------------------ --------------- -----------------------------------------
  Unique             Yes             Yes
  Insertion order    Yes             No
  Sorted order       No              Yes
  Average add        O(1)            O(log n)
  Average contains   O(1)            O(log n)
  Range operations   No              Yes
  Null               One             Generally no null with natural ordering

------------------------------------------------------------------------

# PART 61 --- ENUMSET VS HASHSET

## 100. Comparison

  Feature        EnumSet                  HashSet
  -------------- ------------------------ ---------------------
  Element type   Enum only                Any object
  Storage        Specialized              Hash-based
  Performance    Very efficient           General-purpose
  Null           No                       One
  Ordering       Enum declaration order   No guaranteed order
  Use case       Enum flags/states        General unique data

------------------------------------------------------------------------

# PART 62 --- SET AND MAP

## 101. HashSet Internally Uses Map Concepts

A useful mental model is:

``` text
HashSet
   ↓
HashMap
   ↓
keys = Set elements
```

The Set cares about keys and uses a dummy value concept internally.

Do not rely on internal implementation details as public API guarantees,
but this is useful for understanding why HashSet has hash-map-like
behavior.

------------------------------------------------------------------------

# PART 63 --- TREESET AND TREEMAP

## 102. TreeSet Relationship

Conceptually:

``` text
TreeSet
   ↓
TreeMap
   ↓
keys = Set elements
```

The TreeSet exposes Set semantics while TreeMap maintains sorted keys.

------------------------------------------------------------------------

# PART 64 --- SET AND NULL

## 103. Null Behavior Summary

  Set                               Null
  --------------------------------- ------------------------------------
  `HashSet`                         One
  `LinkedHashSet`                   One
  `TreeSet`                         Generally no with natural ordering
  `EnumSet`                         No
  `Set.of()`                        No
  `Set.copyOf()`                    No
  `ConcurrentHashMap.newKeySet()`   No
  `CopyOnWriteArraySet`             No

Always check the chosen implementation's contract before relying on null
behavior.

------------------------------------------------------------------------

# PART 65 --- SET ORDERING SUMMARY

## 104. Ordering

### HashSet

``` text
No guaranteed iteration order
```

### LinkedHashSet

``` text
Insertion order
```

### TreeSet

``` text
Sorted order
```

### EnumSet

``` text
Enum declaration order
```

This distinction is one of the most important Set interview topics.

------------------------------------------------------------------------

# PART 66 --- FAIL-FAST ITERATORS

## 105. Structural Modification

Many ordinary collection iterators are fail-fast on a best-effort basis.

Example:

``` java
for (Integer value : set) {
    set.remove(value);
}
```

This can result in:

``` text
ConcurrentModificationException
```

------------------------------------------------------------------------

## 106. Correct Removal

Use:

``` java
Iterator<Integer> iterator =
    set.iterator();

while (iterator.hasNext()) {

    Integer value =
        iterator.next();

    if (value == 10) {
        iterator.remove();
    }
}
```

------------------------------------------------------------------------

# PART 67 --- CONCURRENT SET ITERATORS

## 107. Concurrent Collections

Concurrent collections have different iterator semantics.

For example:

``` java
ConcurrentHashMap.newKeySet()
```

provides weakly consistent iteration behavior rather than the fail-fast
behavior typical of ordinary collections.

This means an iterator can safely operate while concurrent updates
occur, but it does not represent a frozen snapshot.

------------------------------------------------------------------------

# PART 68 --- COPYONWRITE SET ITERATORS

## 108. Copy-On-Write Iteration

`CopyOnWriteArraySet` iterators operate over a snapshot-like backing
array from iterator creation time.

Therefore modifications after iterator creation are not reflected in
that iterator's traversal.

This is one reason it is useful for read-heavy workloads.

------------------------------------------------------------------------

# PART 69 --- SET STREAMS

## 109. Stream

``` java
set.stream()
   .filter(x -> x > 10)
   .forEach(System.out::println);
```

Streams do not automatically modify the Set.

------------------------------------------------------------------------

## 110. Convert Set to List

``` java
List<Integer> list =
    set.stream().toList();
```

Note:

`Stream.toList()` returns an unmodifiable List in modern Java.

------------------------------------------------------------------------

# PART 70 --- SET TO ARRAY

## 111. `toArray()`

``` java
Object[] array =
    set.toArray();
```

Typed:

``` java
Integer[] array =
    set.toArray(new Integer[0]);
```

------------------------------------------------------------------------

# PART 71 --- SET AND DUPLICATE REMOVAL

## 112. Remove Duplicates From List

One common use:

``` java
List<Integer> list =
    List.of(1, 2, 2, 3, 3, 4);

Set<Integer> unique =
    new LinkedHashSet<>(list);
```

Result:

``` text
1 2 3 4
```

Using `LinkedHashSet` preserves the original encounter/insertion order.

------------------------------------------------------------------------

# PART 72 --- CONVERT SET BACK TO LIST

## 113. Conversion

``` java
List<Integer> result =
    new ArrayList<>(set);
```

The resulting List follows the Set's iteration order.

Therefore:

``` text
HashSet → unspecified order
LinkedHashSet → insertion order
TreeSet → sorted order
```

------------------------------------------------------------------------

# PART 73 --- SET MEMBERSHIP

## 114. Why Use Set Instead of List?

Suppose:

``` text
100,000 elements
```

and you repeatedly ask:

``` text
Does this value exist?
```

A HashSet is generally much better suited than repeatedly scanning an
ArrayList.

List search:

``` text
O(n)
```

HashSet average lookup:

``` text
O(1)
```

------------------------------------------------------------------------

# PART 74 --- DEDUPLICATION PATTERN

## 115. Duplicate Detection

``` java
Set<Integer> seen =
    new HashSet<>();

for (Integer value : values) {

    if (!seen.add(value)) {
        System.out.println(
            "Duplicate: " + value
        );
    }
}
```

This is a common DSA pattern.

------------------------------------------------------------------------

# PART 75 --- FIRST DUPLICATE

## 116. Find First Duplicate

``` java
Set<Integer> seen =
    new HashSet<>();

for (Integer value : values) {

    if (!seen.add(value)) {
        return value;
    }
}
```

Time complexity:

``` text
O(n) average
```

Space:

``` text
O(n)
```

------------------------------------------------------------------------

# PART 76 --- UNIQUE CHARACTERS

## 117. Character Uniqueness

``` java
Set<Character> set =
    new HashSet<>();

for (char c : text.toCharArray()) {
    set.add(c);
}
```

If:

``` java
set.size() == text.length()
```

for the chosen character representation, all processed characters are
unique.

For Unicode text, be careful about the difference between Java `char`
values and Unicode code points.

------------------------------------------------------------------------

# PART 77 --- TWO SET COMPARISON

## 118. Compare Sets

``` java
if (setA.equals(setB)) {
    System.out.println("Same");
}
```

Order does not matter.

------------------------------------------------------------------------

# PART 78 --- SET UNION CODE

## 119. Union

``` java
Set<Integer> union =
    new HashSet<>(a);

union.addAll(b);
```

------------------------------------------------------------------------

# PART 79 --- SET INTERSECTION CODE

## 120. Intersection

``` java
Set<Integer> intersection =
    new HashSet<>(a);

intersection.retainAll(b);
```

------------------------------------------------------------------------

# PART 80 --- SET DIFFERENCE CODE

## 121. Difference

``` java
Set<Integer> difference =
    new HashSet<>(a);

difference.removeAll(b);
```

------------------------------------------------------------------------

# PART 81 --- DISJOINT CHECK

## 122. Disjoint

``` java
boolean result =
    Collections.disjoint(a, b);
```

Useful when you only need to know whether the two collections share any
element.

------------------------------------------------------------------------

# PART 82 --- TREESET RANGE QUERIES

## 123. Range Query

``` java
TreeSet<Integer> set =
    new TreeSet<>(
        List.of(
            10, 20, 30, 40, 50
        )
    );
```

Get values below 40:

``` java
set.headSet(40);
```

Get values from 30 onward:

``` java
set.tailSet(30);
```

Get values in a range:

``` java
set.subSet(20, 50);
```

------------------------------------------------------------------------

# PART 83 --- TREESET NEAREST VALUE

## 124. Nearest Navigation

Suppose:

``` text
10 20 30 40
```

Query:

``` java
set.floor(25);
```

Result:

``` text
20
```

Query:

``` java
set.ceiling(25);
```

Result:

``` text
30
```

This makes TreeSet useful for nearest-value/range problems.

------------------------------------------------------------------------

# PART 84 --- TREESET POLLING

## 125. Remove Extremes

Smallest:

``` java
set.pollFirst();
```

Largest:

``` java
set.pollLast();
```

This is useful for repeatedly processing sorted extremes.

------------------------------------------------------------------------

# PART 85 --- SET WITH CUSTOM OBJECTS

## 126. HashSet Custom Objects

If uniqueness is based on object content, implement:

``` java
equals()
hashCode()
```

Example:

``` java
class User {

    private final int id;

    User(int id) {
        this.id = id;
    }

    @Override
    public boolean equals(Object obj) {

        if (this == obj) {
            return true;
        }

        if (!(obj instanceof User other)) {
            return false;
        }

        return id == other.id;
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(id);
    }
}
```

------------------------------------------------------------------------

# PART 86 --- RECORDS AND SETS

## 127. Java Records

Records automatically provide appropriate:

``` text
equals()
hashCode()
```

based on their components.

Example:

``` java
record User(int id, String name) {}

Set<User> users =
    new HashSet<>();
```

Two records with the same component values compare equal.

------------------------------------------------------------------------

# PART 87 --- IDENTITY VS EQUALITY

## 128. Set Does Not Normally Use `==`

For normal Sets, logical uniqueness is based on the implementation's
equality semantics, not object identity.

For HashSet:

``` text
hashCode + equals
```

For TreeSet:

``` text
Comparator / Comparable ordering
```

------------------------------------------------------------------------

# PART 88 --- SET OF SETS

## 129. Nested Sets

Possible:

``` java
Set<Set<Integer>> sets =
    new HashSet<>();
```

The inner Sets must have suitable equality/hash-code semantics.

Example:

``` java
Set<Integer> a =
    new HashSet<>(List.of(1, 2));

Set<Integer> b =
    new HashSet<>(List.of(2, 1));
```

As Sets, `a.equals(b)` is true.

------------------------------------------------------------------------

# PART 89 --- SET AS MAP KEYS

## 130. Set as Map Key

A Set can technically be used as a Map key if it has stable
equality/hash-code behavior.

Example:

``` java
Map<Set<Integer>, String> map =
    new HashMap<>();
```

But do not mutate a key after insertion if the mutation changes its hash
code.

------------------------------------------------------------------------

# PART 90 --- PERFORMANCE AND MEMORY

## 131. HashSet

Advantages:

``` text
Fast average membership
Fast average insertion
Fast average removal
```

Costs:

``` text
Hash table memory
Unused capacity
Hash computation
```

------------------------------------------------------------------------

## 132. LinkedHashSet

Adds:

``` text
Insertion-order tracking
```

Therefore memory usage is generally higher than HashSet.

------------------------------------------------------------------------

## 133. TreeSet

Advantages:

``` text
Sorted order
Range operations
Nearest-value navigation
```

Costs:

``` text
O(log n) operations
Tree node overhead
Comparator/comparison cost
```

------------------------------------------------------------------------

# PART 91 --- CHOOSING A SET

## 134. Decision Tree

``` text
Need unique elements?
        |
       YES
        ↓
Need ordering?
   ┌────┴─────┐
   NO        YES
   ↓          ↓
HashSet    Which order?
              |
       ┌──────┴───────┐
       ↓              ↓
 insertion          sorted
    ↓                 ↓
LinkedHashSet      TreeSet
```

For enum-only values:

``` text
EnumSet
```

For concurrent workloads:

``` text
ConcurrentHashMap.newKeySet()
CopyOnWriteArraySet
```

depending on workload.

------------------------------------------------------------------------

# PART 92 --- HASHSET VS LINKEDHASHSET VS TREESET

## 135. Master Comparison

  Feature            HashSet           LinkedHashSet   TreeSet
  ------------------ ----------------- --------------- ------------------------------------
  Unique             Yes               Yes             Yes
  Order              None guaranteed   Insertion       Sorted
  Average add        O(1)              O(1)            O(log n)
  Average contains   O(1)              O(1)            O(log n)
  Average remove     O(1)              O(1)            O(log n)
  Range queries      No                No              Yes
  Navigation         No                No              Yes
  Null               One               One             Generally no with natural ordering
  Thread-safe        No                No              No
  Memory             Moderate          Higher          Tree-based

------------------------------------------------------------------------

# PART 93 --- IMMUTABLE SET COMPARISON

## 136. Set Factory Methods

  ---------------------------------------------------------------------------------------
  Method                            Mutable?          Duplicates        Null
  --------------------------------- ----------------- ----------------- -----------------
  `Set.of()`                        No                No                No

  `Set.copyOf()`                    No                No                No

  `Collections.unmodifiableSet()`   No through view   Depends on source Depends on source
  ---------------------------------------------------------------------------------------

Important:

``` text
unmodifiable != necessarily immutable source
```

------------------------------------------------------------------------

# PART 94 --- CONCURRENT SET COMPARISON

## 137. Concurrent Choices

### `ConcurrentHashMap.newKeySet()`

Good general-purpose concurrent Set.

### `CopyOnWriteArraySet`

Good when:

``` text
reads >> writes
```

### `Collections.synchronizedSet()`

Simple synchronization wrapper around a Set.

Choose based on workload rather than assuming one is universally best.

------------------------------------------------------------------------

# PART 95 --- FAIL-FAST VS WEAKLY CONSISTENT

## 138. Iterator Models

Ordinary Sets such as:

``` text
HashSet
LinkedHashSet
TreeSet
```

typically provide fail-fast iterators on a best-effort basis.

Concurrent collections such as:

``` text
ConcurrentHashMap.newKeySet()
```

provide weakly consistent iterators.

Copy-on-write collections provide snapshot-style iteration.

------------------------------------------------------------------------

# PART 96 --- THREAD SAFETY SUMMARY

## 139. Thread Safety

  Set                             Thread-safe
  ------------------------------- ------------------------
  HashSet                         No
  LinkedHashSet                   No
  TreeSet                         No
  EnumSet                         No
  Set.of()                        Immutable/unmodifiable
  ConcurrentHashMap.newKeySet()   Yes
  CopyOnWriteArraySet             Yes
  synchronizedSet                 Yes

------------------------------------------------------------------------

# PART 97 --- SET AND DATABASE CONCEPT

## 140. Unique Data

Sets are conceptually similar to a database uniqueness constraint:

``` text
Set
→ unique values
```

Database:

``` sql
UNIQUE
```

But they are not interchangeable.

A Java Set only enforces uniqueness inside its own collection according
to Java equality/order rules.

A database constraint enforces uniqueness at the database level.

------------------------------------------------------------------------

# PART 98 --- SET IN BACKEND APPLICATIONS

## 141. Example: Permissions

``` java
Set<String> permissions =
    new HashSet<>();

permissions.add("READ");
permissions.add("WRITE");
permissions.add("READ");
```

Result:

``` text
READ
WRITE
```

------------------------------------------------------------------------

## 142. Example: Unique IDs

``` java
Set<Long> processedIds =
    new HashSet<>();

if (processedIds.add(id)) {
    // first time
} else {
    // duplicate
}
```

------------------------------------------------------------------------

# PART 99 --- SET IN API DEVELOPMENT

## 143. Request Validation

Suppose an API receives:

``` text
["READ", "WRITE", "READ"]
```

A Set can be used to detect duplicates:

``` java
Set<String> permissions =
    new HashSet<>(permissionsList);

if (permissions.size()
        != permissionsList.size()) {

    // duplicate input
}
```

------------------------------------------------------------------------

# PART 100 --- SET IN DSA

## 144. Common DSA Problems

Set is commonly used for:

-   Duplicate detection
-   Two Sum variants
-   Longest consecutive sequence
-   Unique characters
-   Intersection
-   Union
-   Cycle detection
-   Visited nodes
-   Graph traversal
-   Subset checking
-   Frequency-related preprocessing

------------------------------------------------------------------------

# PART 101 --- LONGEST CONSECUTIVE SEQUENCE

## 145. Why HashSet?

Example:

``` text
100, 4, 200, 1, 3, 2
```

Put all values into:

``` java
Set<Integer> set =
    new HashSet<>(values);
```

Then test starts of sequences:

``` text
1 → 2 → 3 → 4
```

Average complexity can be:

``` text
O(n)
```

with O(n) extra space.

------------------------------------------------------------------------

# PART 102 --- VISITED SET

## 146. Graph Traversal

A Set can track visited nodes:

``` java
Set<Node> visited =
    new HashSet<>();
```

Before processing:

``` java
if (!visited.add(node)) {
    continue;
}
```

This is a common BFS/DFS pattern.

------------------------------------------------------------------------

# PART 103 --- CYCLE DETECTION

## 147. Visited Tracking

For graph traversal:

``` text
Node
 ↓
visited?
 ├── yes → skip
 └── no  → process
```

A Set is often used to avoid revisiting nodes.

------------------------------------------------------------------------

# PART 104 --- SET AND HASHING CONTRACT

## 148. `equals()` Contract

If:

``` java
a.equals(b)
```

is true, then:

``` java
a.hashCode() == b.hashCode()
```

must be true.

The reverse is not required:

``` text
same hash
≠
equal
```

------------------------------------------------------------------------

# PART 105 --- HASHSET DEBUGGING

## 149. Common Bug

You create:

``` java
class Employee {
    int id;
}
```

but do not override:

``` java
equals()
hashCode()
```

Then:

``` java
set.add(new Employee(1));
set.add(new Employee(1));
```

may result in two objects because default Object equality is
identity-based.

If logical uniqueness is based on `id`, define equality accordingly.

------------------------------------------------------------------------

# PART 106 --- TREESET DEBUGGING

## 150. Common Bug

You create:

``` java
TreeSet<Employee> set =
    new TreeSet<>(
        Comparator.comparingInt(
            Employee::getDepartment
        )
    );
```

If multiple employees share the same department, the comparator returns:

``` text
0
```

and TreeSet may treat them as duplicates.

If employees should remain distinct, the comparator must include enough
fields to distinguish them according to the intended ordering.

------------------------------------------------------------------------

# PART 107 --- COMPARATOR CHAINING

## 151. Multiple Sort Fields

``` java
Comparator<Employee> comparator =
    Comparator
        .comparing(Employee::getDepartment)
        .thenComparing(Employee::getName)
        .thenComparingInt(Employee::getId);
```

Then:

``` java
TreeSet<Employee> employees =
    new TreeSet<>(comparator);
```

This can maintain a more precise ordering.

------------------------------------------------------------------------

# PART 108 --- SET AND IMMUTABLE ELEMENTS

## 152. Best Practice

Prefer stable/immutable objects as Set elements when possible.

Good candidates:

``` text
String
Integer
UUID
Enum
record
immutable domain objects
```

This reduces problems with mutable equality or ordering fields.

------------------------------------------------------------------------

# PART 109 --- SET AND UUID

## 153. UUID Set

``` java
Set<UUID> ids =
    new HashSet<>();
```

Useful for:

-   Tracking processed IDs
-   Deduplicating identifiers
-   Membership checks
-   Request correlation

------------------------------------------------------------------------

# PART 110 --- SET AND ENUM FLAGS

## 154. EnumSet Example

``` java
enum Role {
    ADMIN,
    USER,
    AUDITOR
}

EnumSet<Role> roles =
    EnumSet.of(
        Role.ADMIN,
        Role.AUDITOR
    );
```

Check:

``` java
roles.contains(Role.ADMIN);
```

------------------------------------------------------------------------

# PART 111 --- SET API MASTER LIST

## 155. Core Collection Methods

``` java
add()
remove()
contains()
size()
isEmpty()
clear()

addAll()
removeAll()
retainAll()
containsAll()

iterator()
toArray()
toArray(T[])

removeIf()

stream()
parallelStream()
spliterator()
```

------------------------------------------------------------------------

## 156. SortedSet Methods

``` java
comparator()
first()
last()

headSet()
tailSet()
subSet()
```

------------------------------------------------------------------------

## 157. NavigableSet Methods

``` java
lower()
floor()
ceiling()
higher()

pollFirst()
pollLast()

descendingSet()
descendingIterator()

headSet(from, inclusive)
tailSet(from, inclusive)

subSet(
    from,
    fromInclusive,
    to,
    toInclusive
)
```

------------------------------------------------------------------------

# PART 112 --- COMPLETE SET HIERARCHY

## 158. Hierarchy

``` text
Iterable
   ↓
Collection
   ↓
Set
   ├── HashSet
   │
   ├── LinkedHashSet
   │
   ├── SortedSet
   │     ↓
   │   NavigableSet
   │     ↓
   │   TreeSet
   │
   ├── EnumSet
   │
   └── Concurrent implementations
         ├── ConcurrentHashMap.newKeySet()
         └── CopyOnWriteArraySet
```

------------------------------------------------------------------------

# PART 113 --- MASTER COMPLEXITY TABLE

## 159. Main Set Implementations

  -----------------------------------------------------------------------
  Operation                 HashSet      LinkedHashSet            TreeSet
  -------------- ------------------ ------------------ ------------------
  Add                      O(1) avg           O(1) avg           O(log n)

  Contains                 O(1) avg           O(1) avg           O(log n)

  Remove                   O(1) avg           O(1) avg           O(log n)

  First                 Not ordered    First insertion           O(log n)
                                              position 
                                     conceptually, but 
                                        no first() API 

  Last                  Not ordered     Last insertion           O(log n)
                                              position 
                                     conceptually, but 
                                         no last() API 

  Iteration                    O(n)               O(n)               O(n)

  Range query                    No                 No                Yes
  -----------------------------------------------------------------------

------------------------------------------------------------------------

# PART 114 --- WHAT NOT TO ASSUME

## 160. HashSet Ordering

Never assume:

``` java
HashSet
```

will iterate in insertion order.

Even if a particular run appears ordered, that is not a guaranteed
contract.

------------------------------------------------------------------------

## 161. TreeSet Equality

Do not assume TreeSet uses only:

``` java
equals()
```

for duplicate determination.

Its ordering comparison is fundamental.

------------------------------------------------------------------------

## 162. Concurrent Collection Snapshot

Do not assume a concurrent Set iterator represents an immutable snapshot
unless the collection specifically provides that behavior.

------------------------------------------------------------------------

# PART 115 --- BEST PRACTICES

## 163. Program to Interface

Prefer:

``` java
Set<String> set =
    new HashSet<>();
```

rather than exposing:

``` java
HashSet<String>
```

when callers only need Set operations.

------------------------------------------------------------------------

## 164. Select Based on Requirement

``` text
Fast unique lookup
→ HashSet

Unique + insertion order
→ LinkedHashSet

Unique + sorted/range operations
→ TreeSet

Enum values
→ EnumSet

Concurrent high-throughput Set
→ ConcurrentHashMap.newKeySet()

Read-heavy concurrent Set
→ CopyOnWriteArraySet
```

------------------------------------------------------------------------

# PART 116 --- COMMON MISTAKES

## 165. Mistake: Using List for Membership

If the main operation is:

``` text
contains(x)
```

and order/index is not required, a Set may be a better abstraction.

------------------------------------------------------------------------

## 166. Mistake: Forgetting `equals()` and `hashCode()`

Custom objects in HashSet require correct equality/hash-code design.

------------------------------------------------------------------------

## 167. Mistake: Mutating Hash Fields

Do not change fields used by:

``` java
hashCode()
equals()
```

while an object is stored in a HashSet.

------------------------------------------------------------------------

## 168. Mistake: Mutating Tree Ordering Fields

Do not change fields used by:

``` java
compareTo()
Comparator
```

while an object is stored in TreeSet.

------------------------------------------------------------------------

## 169. Mistake: Assuming TreeSet Is Faster

TreeSet is not generally faster for plain membership lookup than
HashSet.

Typical:

``` text
HashSet → O(1) average
TreeSet → O(log n)
```

TreeSet provides ordering and navigation.

------------------------------------------------------------------------

# PART 117 --- INTERVIEW QUESTIONS

## 170. What Is Set?

A Collection that does not contain duplicate elements according to its
equality/ordering semantics.

------------------------------------------------------------------------

## 171. Does Set Allow Duplicates?

No.

------------------------------------------------------------------------

## 172. Does Set Maintain Order?

The `Set` interface itself does not promise a specific iteration order.

Implementation determines ordering.

------------------------------------------------------------------------

## 173. HashSet Order?

No guaranteed order.

------------------------------------------------------------------------

## 174. LinkedHashSet Order?

Insertion order.

------------------------------------------------------------------------

## 175. TreeSet Order?

Sorted order according to natural ordering or a Comparator.

------------------------------------------------------------------------

## 176. HashSet Complexity?

Typical average:

``` text
add → O(1)
contains → O(1)
remove → O(1)
```

------------------------------------------------------------------------

## 177. TreeSet Complexity?

Typically:

``` text
add → O(log n)
contains → O(log n)
remove → O(log n)
```

------------------------------------------------------------------------

## 178. HashSet vs TreeSet?

``` text
HashSet → hashing, average O(1), no ordering guarantee
TreeSet → sorted tree, O(log n), navigation/range operations
```

------------------------------------------------------------------------

## 179. HashSet vs LinkedHashSet?

``` text
HashSet → no guaranteed order
LinkedHashSet → insertion order
```

------------------------------------------------------------------------

## 180. Why Override `hashCode()` With `equals()`?

Because equal objects must have equal hash codes for hash-based
collections to work correctly.

------------------------------------------------------------------------

# PART 118 --- ADVANCED INTERVIEW QUESTIONS

## 181. Can Two Objects Have Same Hash Code?

Yes.

This is called a hash collision.

``` text
same hash
≠
same object
```

------------------------------------------------------------------------

## 182. What Happens If `equals()` Is True But Hash Codes Differ?

That violates the Java contract and can cause incorrect behavior in
hash-based collections.

------------------------------------------------------------------------

## 183. What Happens If Hash Codes Match But Equals Is False?

Both objects can still exist in a HashSet.

------------------------------------------------------------------------

## 184. Why Does TreeSet Treat `compareTo() == 0` as Duplicate?

Because the sorted-set contract uses ordering equivalence to determine
whether an element is already represented.

------------------------------------------------------------------------

## 185. Can HashSet Store Null?

Yes, one null element.

------------------------------------------------------------------------

## 186. Can TreeSet Store Null?

Generally not when natural ordering is used.

------------------------------------------------------------------------

## 187. Can EnumSet Store Null?

No.

------------------------------------------------------------------------

## 188. Is HashSet Thread-Safe?

No.

------------------------------------------------------------------------

## 189. How Do You Create a Concurrent Set?

``` java
Set<T> set =
    ConcurrentHashMap.newKeySet();
```

------------------------------------------------------------------------

## 190. When Use CopyOnWriteArraySet?

When:

``` text
reads are frequent
writes are rare
```

------------------------------------------------------------------------

# PART 119 --- REAL-WORLD ARCHITECTURE

## 191. Deduplication Layer

``` text
Incoming Events
      ↓
    HashSet
      ↓
Unique Events
      ↓
Database
```

Useful for local duplicate detection.

------------------------------------------------------------------------

## 192. Permission Management

``` text
User
 ↓
Set<Permission>
 ↓
READ
WRITE
DELETE
```

Set naturally models unique permissions.

------------------------------------------------------------------------

## 193. Visited URL Tracking

``` text
Crawler
  ↓
visited Set
  ↓
already seen?
 ├── yes → skip
 └── no  → crawl
```

------------------------------------------------------------------------

# PART 120 --- SET VS DATABASE UNIQUE CONSTRAINT

## 194. Important Difference

Java Set:

``` text
in-memory
```

Database:

``` text
persistent
multi-process/system-wide
```

For real database uniqueness, use a database constraint:

``` sql
UNIQUE
```

A Java Set can help before the database operation but cannot replace the
database constraint.

------------------------------------------------------------------------

# PART 121 --- SET AND DISTRIBUTED SYSTEMS

## 195. Distributed Uniqueness

A local:

``` java
HashSet
```

only knows about one JVM/process.

In distributed systems:

``` text
Server A → Set A
Server B → Set B
Server C → Set C
```

They do not automatically share state.

For distributed uniqueness, use an appropriate shared
system/database/cache.

------------------------------------------------------------------------

# PART 122 --- SET AND CACHE

## 196. Membership Cache

A Set can represent:

``` text
currently blocked IDs
```

or:

``` text
already processed IDs
```

Example:

``` java
Set<String> processed =
    ConcurrentHashMap.newKeySet();
```

------------------------------------------------------------------------

# PART 123 --- PERFORMANCE CHECKLIST

## 197. Ask These Questions

Before selecting a Set:

1.  Do I need uniqueness?
2.  Do I need insertion order?
3.  Do I need sorted order?
4.  Do I need range queries?
5.  Do I need nearest-value queries?
6.  Are elements enums?
7.  Is the Set accessed concurrently?
8.  Are writes frequent?
9.  Are reads frequent?
10. Can elements mutate?
11. Is null required?
12. Is memory usage important?
13. Is predictable iteration order required?

------------------------------------------------------------------------

# PART 124 --- FINAL DECISION TABLE

## 198. Quick Selection

  Requirement                 Choose
  --------------------------- ---------------------------------
  General unique values       `HashSet`
  Unique + insertion order    `LinkedHashSet`
  Unique + sorted             `TreeSet`
  Enum values                 `EnumSet`
  Concurrent unique values    `ConcurrentHashMap.newKeySet()`
  Read-heavy concurrent Set   `CopyOnWriteArraySet`
  Simple synchronized Set     `Collections.synchronizedSet()`
  Immutable literals          `Set.of()`
  Unmodifiable copy           `Set.copyOf()`

------------------------------------------------------------------------

# PART 125 --- 100% MASTER CHECKLIST

## 199. Beginner

-   [ ] What is Set?
-   [ ] Uniqueness
-   [ ] Set interface
-   [ ] `add()`
-   [ ] `remove()`
-   [ ] `contains()`
-   [ ] `size()`
-   [ ] `isEmpty()`
-   [ ] `clear()`
-   [ ] Iteration
-   [ ] Iterator

------------------------------------------------------------------------

## 200. Intermediate

-   [ ] HashSet
-   [ ] Hashing
-   [ ] Hash collision
-   [ ] equals()
-   [ ] hashCode()
-   [ ] LinkedHashSet
-   [ ] insertion order
-   [ ] TreeSet
-   [ ] sorted order
-   [ ] Comparable
-   [ ] Comparator
-   [ ] Null behavior
-   [ ] Complexity

------------------------------------------------------------------------

## 201. Advanced

-   [ ] SortedSet
-   [ ] NavigableSet
-   [ ] lower()
-   [ ] floor()
-   [ ] ceiling()
-   [ ] higher()
-   [ ] first()
-   [ ] last()
-   [ ] pollFirst()
-   [ ] pollLast()
-   [ ] headSet()
-   [ ] tailSet()
-   [ ] subSet()
-   [ ] descendingSet()
-   [ ] views
-   [ ] EnumSet
-   [ ] immutable Sets
-   [ ] concurrent Sets

------------------------------------------------------------------------

## 202. Expert

-   [ ] HashSet internals
-   [ ] Bucket concept
-   [ ] Load factor
-   [ ] Resizing
-   [ ] Hash collisions
-   [ ] Treeification concept
-   [ ] TreeSet Red-Black tree
-   [ ] Comparator consistency
-   [ ] Mutable-element hazards
-   [ ] Concurrent iteration
-   [ ] Copy-on-write
-   [ ] Set algebra
-   [ ] Deduplication algorithms
-   [ ] Visited Sets
-   [ ] Distributed uniqueness
-   [ ] Performance and memory analysis

------------------------------------------------------------------------

# PART 126 --- FINAL MENTAL MODEL

``` text
                         SET
                          |
             Unique elements only
                          |
       ┌──────────────────┼──────────────────┐
       ↓                  ↓                  ↓
    HashSet         LinkedHashSet        TreeSet
       |                  |                  |
   Hashing          Hash + order       Sorted tree
       |                  |                  |
   O(1) avg          O(1) avg           O(log n)
       |                  |                  |
 no order guarantee   insertion order    sorted order
```

Specialized:

``` text
EnumSet
   ↓
Enum-only optimized Set

ConcurrentHashMap.newKeySet()
   ↓
Concurrent Set

CopyOnWriteArraySet
   ↓
Read-heavy concurrent Set
```

Immutable/unmodifiable:

``` text
Set.of()
Set.copyOf()
Collections.unmodifiableSet()
```

------------------------------------------------------------------------

# QUICK INTERVIEW REVISION

``` text
Set
→ unique elements

HashSet
→ hash-based
→ average O(1)
→ no guaranteed order
→ one null

LinkedHashSet
→ HashSet + insertion order
→ average O(1)
→ one null

TreeSet
→ sorted Set
→ O(log n)
→ NavigableSet
→ range queries
→ lower/floor/ceiling/higher
→ generally no null with natural ordering

EnumSet
→ enum-only
→ compact and efficient

ConcurrentHashMap.newKeySet()
→ concurrent Set

CopyOnWriteArraySet
→ read-heavy concurrent Set

Set.of()
→ unmodifiable
→ no duplicates
→ no null

Set.copyOf()
→ unmodifiable copy
→ no duplicates
→ no null

HashSet uniqueness:
hashCode() + equals()

TreeSet uniqueness:
Comparator / Comparable ordering

Set operations:
union        → addAll()
intersection → retainAll()
difference   → removeAll()
subset       → containsAll()

Main rule:

If you need UNIQUE elements,
think SET.

Then choose:

HashSet        → speed
LinkedHashSet  → insertion order
TreeSet        → sorted/range
EnumSet        → enums
Concurrent Set → multithreading
```

------------------------------------------------------------------------

# END --- JAVA SET 100% COMPLETE NOTES
