# Java List --- 100% Complete Notes

## 1. List Overview

`List<E>` is an ordered collection interface in `java.util`.

Main properties:

-   Ordered sequence
-   Index-based access
-   Zero-based indexing
-   Duplicate elements allowed
-   `null` support depends on implementation
-   Positional insertion, replacement and removal
-   Generic type safety

Hierarchy:

``` text
Iterable
  |
Collection
  |
List
  +-- ArrayList
  +-- LinkedList
  +-- Vector
       +-- Stack
```

`LinkedList` also implements `Deque`.

------------------------------------------------------------------------

# 2. List vs Other Collections

  Structure   Duplicates    Index       Main purpose
  ----------- ------------- ----------- -----------------------
  List        Yes           Yes         Ordered sequence
  Set         No            No          Uniqueness
  Queue       Usually yes   No          Processing order
  Map         Keys unique   Key-based   Key-value association

------------------------------------------------------------------------

# 3. Generic List

``` java
List<String> names = new ArrayList<>();
List<Integer> numbers = new ArrayList<>();
List<Student> students = new ArrayList<>();
```

Java generics use wrapper classes for primitives:

``` text
int -> Integer
long -> Long
double -> Double
boolean -> Boolean
char -> Character
```

Understand:

-   Generics
-   Type safety
-   Autoboxing
-   Unboxing
-   Wildcards
-   `? extends`
-   `? super`

------------------------------------------------------------------------

# 4. Creating Lists

## Mutable ArrayList

``` java
List<String> list = new ArrayList<>();
```

## Fixed initial values

``` java
List<String> list = new ArrayList<>(List.of("A", "B", "C"));
```

## Unmodifiable factory list

``` java
List<String> list = List.of("A", "B", "C");
```

`List.of()` does not permit structural modification and does not permit
null elements.

------------------------------------------------------------------------

# 5. Complete List API

  Method                        Purpose
  ----------------------------- ------------------------------------
  `add(E)`                      Append
  `add(int,E)`                  Insert at index
  `addAll(Collection)`          Append collection
  `addAll(int,Collection)`      Insert collection
  `get(int)`                    Read
  `set(int,E)`                  Replace
  `remove(int)`                 Remove by index
  `remove(Object)`              Remove first matching value
  `removeAll(Collection)`       Remove matching elements
  `retainAll(Collection)`       Keep matching elements
  `removeIf(Predicate)`         Remove matching predicate elements
  `clear()`                     Remove all
  `size()`                      Count
  `isEmpty()`                   Empty test
  `contains(Object)`            Membership
  `containsAll(Collection)`     Multiple membership
  `indexOf(Object)`             First occurrence
  `lastIndexOf(Object)`         Last occurrence
  `iterator()`                  Iterator
  `listIterator()`              ListIterator
  `subList(int,int)`            Backed range view
  `toArray()`                   Array conversion
  `sort(Comparator)`            Sort
  `replaceAll(UnaryOperator)`   Transform elements
  `spliterator()`               Spliterator

------------------------------------------------------------------------

# 6. `add()`

Appends an element.

``` text
A B C
add(D)
A B C D
```

For ArrayList:

``` text
O(1) amortized
```

------------------------------------------------------------------------

# 7. `add(index,value)`

Inserts at a position.

``` text
A B C D
add(2,X)
A B X C D
```

ArrayList must shift later elements:

``` text
O(n)
```

------------------------------------------------------------------------

# 8. `get(index)`

Returns the element at an index.

``` java
String value = list.get(2);
```

Complexity:

``` text
ArrayList  -> O(1)
LinkedList -> O(n)
```

------------------------------------------------------------------------

# 9. `set(index,value)`

Replaces an existing element.

``` text
A B C
set(1,X)
A X C
```

It does not change list size.

------------------------------------------------------------------------

# 10. `remove(index)` vs `remove(object)`

This is a major Java interview trap.

For:

``` java
List<Integer> numbers;
```

``` java
numbers.remove(2);
```

means:

``` text
remove index 2
```

while:

``` java
numbers.remove(Integer.valueOf(2));
```

means:

``` text
remove value 2
```

------------------------------------------------------------------------

# 11. `contains()`

Searches for an element.

Typical List complexity:

``` text
O(n)
```

If membership is the dominant operation and ordering/index is
unnecessary, consider a `Set`.

------------------------------------------------------------------------

# 12. `indexOf()` and `lastIndexOf()`

``` text
A B C B

indexOf(B)     -> 1
lastIndexOf(B) -> 3
```

Both are typically:

``` text
O(n)
```

------------------------------------------------------------------------

# 13. `removeAll()` and `retainAll()`

`removeAll()` removes elements found in another collection.

`retainAll()` keeps only elements found in another collection.

Understand:

-   Equality comparison
-   Complexity
-   Mutation
-   Interaction with duplicates

------------------------------------------------------------------------

# 14. ArrayList

`ArrayList` is a resizable-array implementation of `List`.

Characteristics:

-   Fast random access
-   Good cache locality
-   Ordered
-   Allows duplicates
-   Allows null
-   Not synchronized by default
-   General-purpose default List

------------------------------------------------------------------------

# 15. ArrayList Internal Model

Conceptually:

``` text
ArrayList object
      |
      v
backing array
      |
      +-- reference
      +-- reference
      +-- reference
      +-- empty capacity
```

Understand:

-   Backing array
-   Size
-   Capacity
-   Resizing
-   Reference storage
-   Object allocation

------------------------------------------------------------------------

# 16. Size vs Capacity

``` text
size     = number of elements
capacity = available backing-array storage
```

Example:

``` text
capacity = 10
size     = 4

[A][B][C][D][ ][ ][ ][ ][ ][ ]
```

------------------------------------------------------------------------

# 17. ArrayList Growth

When capacity is insufficient:

``` text
Old array
   ↓
Allocate larger array
   ↓
Copy/move references
   ↓
Use new array
```

Therefore append is:

``` text
O(1) amortized
```

but a particular resize operation can be O(n).

------------------------------------------------------------------------

# 18. ArrayList Complexity

  Operation                Complexity
  ------------------ ----------------
  `get`                          O(1)
  `set`                          O(1)
  Append               O(1) amortized
  Insert beginning               O(n)
  Insert middle                  O(n)
  Remove end                     O(1)
  Remove beginning               O(n)
  Remove middle                  O(n)
  Search                         O(n)

------------------------------------------------------------------------

# 19. `ensureCapacity()`

Useful when expected size is known.

Purpose:

-   Reduce repeated resizing
-   Reduce copying
-   Improve large batch construction

Concept:

``` text
Known expected size
       ↓
ensureCapacity()
       ↓
Fewer reallocations
```

------------------------------------------------------------------------

# 20. `trimToSize()`

Reduces excess capacity toward current size.

Use when:

-   Growth is unlikely
-   Memory footprint matters

Avoid unnecessary use because future growth can become more expensive.

------------------------------------------------------------------------

# 21. ArrayList `subList()`

``` java
List<E> part = list.subList(from, to);
```

Important:

``` text
from = inclusive
to   = exclusive
```

`subList()` is a **view**, not an independent copy.

Therefore:

``` text
Original list
      |
      +---- subList view
```

Changes through the view affect the backing list.

------------------------------------------------------------------------

# 22. ArrayList and Iterators

Structural modification while an iterator is active may cause:

``` text
ConcurrentModificationException
```

Fail-fast behavior is:

-   Best effort
-   Not synchronization
-   Not a concurrency guarantee

Use the iterator's removal mechanism where appropriate.

------------------------------------------------------------------------

# 23. LinkedList

Java `LinkedList` is a doubly linked list and implements `Deque`.

Conceptual node:

``` text
previous
   |
[element]
   |
 next
```

Overall:

``` text
null <- A <-> B <-> C -> null
```

------------------------------------------------------------------------

# 24. LinkedList Operations

  Operation                     Typical complexity
  --------------------------- --------------------
  First insertion                             O(1)
  Last insertion                              O(1)
  First removal                               O(1)
  Last removal                                O(1)
  First/last access                           O(1)
  Arbitrary `get`                             O(n)
  Search                                      O(n)
  Arbitrary index insertion         O(n) to locate
  Arbitrary index removal           O(n) to locate

Important:

> Linked-list link modification may be O(1) after a node is known, but
> locating an arbitrary index can be O(n).

------------------------------------------------------------------------

# 25. LinkedList as Deque

Because it implements `Deque`:

-   `addFirst`
-   `addLast`
-   `removeFirst`
-   `removeLast`
-   `peekFirst`
-   `peekLast`
-   `offerFirst`
-   `offerLast`
-   `pollFirst`
-   `pollLast`

------------------------------------------------------------------------

# 26. Vector

`Vector` is a legacy synchronized dynamic-array implementation.

Characteristics:

-   Resizable array
-   Random access
-   Synchronized legacy methods
-   Ordered
-   Allows duplicates

Important methods:

-   `add`
-   `get`
-   `set`
-   `remove`
-   `capacity`
-   `ensureCapacity`

Modern applications normally prefer `ArrayList` unless legacy
synchronization/API behavior is specifically required.

------------------------------------------------------------------------

# 27. Stack

`Stack<E>` extends `Vector`.

It implements LIFO:

``` text
Last In
   |
First Out
```

Methods:

-   `push`
-   `pop`
-   `peek`
-   `empty`
-   `search`

Typical complexity:

``` text
push -> O(1) amortized
pop  -> O(1)
peek -> O(1)
```

For modern stack behavior, prefer `ArrayDeque`.

------------------------------------------------------------------------

# 28. ArrayList vs LinkedList

  Feature                ArrayList        LinkedList
  ---------------------- ---------------- ----------------
  Representation         Dynamic array    Doubly linked
  Random access          O(1)             O(n)
  Append                 O(1) amortized   O(1)
  Middle insertion       O(n)             O(n) to locate
  Memory locality        Better           Worse
  Per-element overhead   Lower            Higher
  Implements Deque       No               Yes

------------------------------------------------------------------------

# 29. ArrayList vs Array

  Feature             Array     ArrayList
  ------------------- --------- -----------------
  Size                Fixed     Resizable
  Random access       O(1)      O(1)
  Primitive storage   Yes       Wrapper objects
  Rich API            Limited   Extensive
  Automatic growth    No        Yes

For huge primitive datasets, `int[]`, `long[]`, etc. can be much more
memory efficient than wrapper Lists.

------------------------------------------------------------------------

# 30. Primitive and Wrapper Overhead

Java generics use objects:

``` java
List<Integer>
```

rather than:

``` java
List<int>
```

This introduces:

-   Boxing
-   Object references
-   Object allocation
-   Additional memory overhead
-   Potential GC pressure

Compare:

``` text
int[]       -> primitive values
List<Integer> -> references to Integer objects
```

------------------------------------------------------------------------

# 31. Autoboxing and Unboxing

Conceptually:

``` text
int
 ↓ boxing
Integer
 ↓
List<Integer>
```

and:

``` text
Integer
 ↓ unboxing
int
```

Understand performance implications in large loops and large
collections.

------------------------------------------------------------------------

# 32. List Equality

Lists compare:

1.  Size
2.  Corresponding elements
3.  In the same order

``` text
[A,B,C] == [A,B,C]
```

but:

``` text
[A,B,C] != [C,B,A]
```

------------------------------------------------------------------------

# 33. List Hash Code

List hash code depends on the sequence of elements.

Therefore changing list contents can change its hash code.

Avoid using mutable lists carelessly as keys in hash-based collections.

------------------------------------------------------------------------

# 34. List Sorting

Use:

``` java
list.sort(comparator);
```

or:

``` java
Collections.sort(list);
```

Sorting requires:

-   Natural ordering
-   `Comparable`
-   Or `Comparator`

------------------------------------------------------------------------

# 35. Comparable

A class implements its natural ordering:

``` java
class Student implements Comparable<Student> {
    public int compareTo(Student other) {
        return Integer.compare(this.age, other.age);
    }
}
```

Understand:

-   `compareTo`
-   Natural ordering
-   Ordering consistency
-   Sorted collections

------------------------------------------------------------------------

# 36. Comparator

External ordering:

``` java
Comparator<Student> byAge =
    (a, b) -> Integer.compare(a.age, b.age);
```

Multiple orderings can exist:

``` text
by age
by name
by salary
by ID
```

Avoid:

``` java
a.age - b.age
```

because subtraction can overflow.

Prefer:

``` java
Integer.compare(a.age, b.age)
```

------------------------------------------------------------------------

# 37. Iterator

`Iterator<E>` provides sequential traversal.

Methods:

-   `hasNext`
-   `next`
-   `remove`

Understand:

-   Iterator state
-   Structural modification
-   Fail-fast behavior
-   Safe iterator removal

------------------------------------------------------------------------

# 38. ListIterator

`ListIterator<E>` is List-specific.

Supports:

-   Forward traversal
-   Backward traversal
-   Add
-   Set
-   Remove

Methods:

-   `hasNext`
-   `next`
-   `hasPrevious`
-   `previous`
-   `add`
-   `set`
-   `remove`

------------------------------------------------------------------------

# 39. Spliterator

`Spliterator` supports traversal and partitioning, especially for
streams.

Important concepts:

-   Traversal
-   Splitting
-   Parallel processing
-   Characteristics

Important characteristics include concepts such as:

-   ORDERED
-   DISTINCT
-   SORTED
-   SIZED
-   SUBSIZED
-   NONNULL
-   IMMUTABLE
-   CONCURRENT

------------------------------------------------------------------------

# 40. `Arrays.asList()`

Creates a fixed-size list backed by an array.

Supported:

``` text
get
set
```

Not supported structurally:

``` text
add
remove
```

Important:

``` text
Array ↔ List backing relationship
```

Changes to the array can be reflected in the list.

------------------------------------------------------------------------

# 41. `List.of()`

Creates an unmodifiable list.

Characteristics:

-   Unmodifiable
-   Does not allow null elements
-   Convenient for constants/fixed data

Example:

``` java
List<String> names = List.of("A", "B", "C");
```

------------------------------------------------------------------------

# 42. `List.copyOf()`

Creates an unmodifiable list containing elements from another
collection.

Understand:

-   Unmodifiable result
-   Null rejection
-   Copy semantics
-   Difference from unmodifiable view

------------------------------------------------------------------------

# 43. `Collections.unmodifiableList()`

Creates an unmodifiable view.

``` text
Original mutable list
       ↓
unmodifiable view
```

The original list can still change through another reference.

Therefore:

``` text
unmodifiable != necessarily immutable
```

------------------------------------------------------------------------

# 44. Immutable vs Unmodifiable

## Unmodifiable view

You cannot mutate through that reference, but the backing collection may
change elsewhere.

## Immutable

The object state cannot be changed after creation.

Know this distinction for API design.

------------------------------------------------------------------------

# 45. `CopyOnWriteArrayList`

Package:

``` java
java.util.concurrent
```

Designed for:

``` text
Many reads
Few writes
```

Concept:

``` text
Read
 ↓
Read stable array

Write
 ↓
Copy array
 ↓
Modify copy
 ↓
Publish new array
```

Advantages:

-   Safe concurrent iteration
-   Snapshot-style iterators
-   Excellent for read-heavy workloads

Disadvantages:

-   Expensive writes
-   Extra memory during copies
-   Bad for write-heavy workloads

------------------------------------------------------------------------

# 46. Synchronized List

A synchronized wrapper can be created using:

``` java
Collections.synchronizedList(list);
```

Important:

-   Individual operations can be synchronized.
-   A sequence of multiple operations is not automatically atomic.
-   Iteration requires synchronization according to the API contract.

------------------------------------------------------------------------

# 47. Null Handling

Typical behavior:

  Implementation           Null
  ------------------------ --------------------------------
  `ArrayList`              Allows
  `LinkedList`             Allows
  `Vector`                 Allows
  `Stack`                  Allows through Vector behavior
  `ArrayDeque`             Does not allow
  `CopyOnWriteArrayList`   Allows

Always check the specific API contract when null behavior matters.

------------------------------------------------------------------------

# 48. List and Queue/Deque

`LinkedList` implements both:

``` text
List
Deque
```

Therefore it can be viewed through either abstraction.

For stack/queue use, `ArrayDeque` is commonly preferable when its
restrictions fit the requirement.

------------------------------------------------------------------------

# 49. List Methods That Return Views

Important:

``` text
subList()
```

returns a view.

For Map this idea also appears in:

``` text
keySet()
values()
entrySet()
```

Understand:

-   Backing collection
-   View
-   Structural modification
-   Modification visibility

------------------------------------------------------------------------

# 50. Time Complexity Master Table

  Operation              ArrayList       LinkedList           Vector
  --------------- ---------------- ---------------- ----------------
  `get(index)`                O(1)             O(n)             O(1)
  `set(index)`                O(1)             O(n)             O(1)
  Append            O(1) amortized             O(1)   O(1) amortized
  Add first                   O(n)             O(1)             O(n)
  Remove first                O(n)             O(1)             O(n)
  Remove last                 O(1)             O(1)             O(1)
  Search                      O(n)             O(n)             O(n)
  Middle insert               O(n)   O(n) to locate             O(n)
  Middle delete               O(n)   O(n) to locate             O(n)

------------------------------------------------------------------------

# 51. Memory Comparison

## ArrayList

``` text
List object
   ↓
Backing array
   ↓
References
   ↓
Objects
```

Advantages:

-   Compact structural representation
-   Good locality
-   Low per-element structural overhead

## LinkedList

``` text
List
 ↓
Node
 ↓
Node
 ↓
Node
```

Each node requires additional link/reference fields.

------------------------------------------------------------------------

# 52. Cache Locality

Array-backed lists generally have better locality because
elements/references are stored in a contiguous backing array.

Linked structures involve pointer/reference chasing.

Therefore, even when asymptotic complexity looks similar, real
performance can differ significantly.

------------------------------------------------------------------------

# 53. How to Choose a List

## Need random index access?

``` text
ArrayList
```

## Need general-purpose ordered collection?

``` text
ArrayList
```

## Need frequent operations at both ends?

``` text
ArrayDeque
```

## Need linked representation specifically?

``` text
LinkedList
```

## Need legacy synchronized dynamic array?

``` text
Vector
```

## Need legacy Stack API?

``` text
Stack
```

but prefer `ArrayDeque` for new stack code.

------------------------------------------------------------------------

# 54. List vs Set Decision

Ask:

``` text
Do duplicates matter?
```

Yes:

``` text
List
```

No:

``` text
Set
```

Then ask:

``` text
Do I need index access?
```

Yes:

``` text
List
```

No:

``` text
Set may be better
```

------------------------------------------------------------------------

# 55. List vs Map Decision

Ask:

``` text
Do I identify data by a key?
```

Yes:

``` text
Map
```

If position/order is the primary model:

``` text
List
```

------------------------------------------------------------------------

# 56. List vs PriorityQueue

Need:

``` text
position/order as inserted
```

→ List

Need:

``` text
repeated minimum/maximum priority
```

→ PriorityQueue

------------------------------------------------------------------------

# 57. List Problem-Solving Patterns

## Pattern 1 --- Random access

Many:

``` text
get(index)
```

→ ArrayList.

## Pattern 2 --- Membership

Many:

``` text
contains(value)
```

→ Consider HashSet if order is unnecessary.

## Pattern 3 --- Frequency

Many counts:

``` text
value -> count
```

→ HashMap.

## Pattern 4 --- Sorted values

Need:

``` text
ordered + navigation
```

→ TreeSet/TreeMap.

## Pattern 5 --- LIFO

→ ArrayDeque.

## Pattern 6 --- FIFO

→ ArrayDeque.

## Pattern 7 --- Priority

→ PriorityQueue.

------------------------------------------------------------------------

# 58. Optimization Process

When solving a List problem:

1.  Build the simplest correct solution.
2.  Determine input constraints.
3.  Count repeated operations.
4.  Calculate time complexity.
5.  Find the bottleneck.
6.  Replace expensive operations with appropriate structures.
7.  Reduce unnecessary copying.
8.  Pre-size ArrayList when size is known.
9.  Consider primitive arrays for primitive-heavy workloads.
10. Consider concurrency requirements.
11. Test edge cases.
12. Benchmark if performance matters.

------------------------------------------------------------------------

# 59. Hidden Concepts

A complete List study must include:

-   ADT vs implementation
-   Interface-based programming
-   Generics
-   Type erasure concept
-   Autoboxing
-   Unboxing
-   Size vs capacity
-   Array growth
-   Amortized complexity
-   Cache locality
-   Object/reference overhead
-   Iterator state
-   Fail-fast behavior
-   `subList` views
-   `Arrays.asList`
-   `List.of`
-   `List.copyOf`
-   Unmodifiable views
-   Immutable collections
-   Copy-on-write
-   Synchronized wrappers
-   Concurrent modification
-   Comparator overflow
-   `equals`/`hashCode`
-   `Comparable`
-   `Comparator`
-   Spliterator
-   Primitive arrays vs wrapper Lists

------------------------------------------------------------------------

# 60. Common Mistakes

-   Assuming LinkedList insertion is always O(1).
-   Assuming ArrayList capacity equals size.
-   Assuming `subList()` is a copy.
-   Assuming `Arrays.asList()` is resizable.
-   Assuming `List.of()` is mutable.
-   Calling `remove(2)` when value 2 should be removed.
-   Using `a.age - b.age` in a comparator.
-   Modifying a list directly during fail-fast iteration.
-   Ignoring boxing overhead.
-   Choosing LinkedList only because insertion is "O(1)".
-   Using List for heavy membership queries.
-   Using List when a Map is required.
-   Ignoring thread-safety requirements.

------------------------------------------------------------------------

# 61. Interview Questions --- Basic

1.  What is Java List?
2.  Why are duplicates allowed?
3.  Is List ordered?
4.  What is the first index?
5.  Which classes implement List?
6.  What is ArrayList?
7.  What is LinkedList?
8.  What is Vector?
9.  What is Stack?
10. Difference between List and Set?
11. Can a List contain null?
12. What is generic List?

------------------------------------------------------------------------

# 62. Interview Questions --- ArrayList

1.  How does ArrayList work internally?
2.  What is backing array?
3.  Difference between size and capacity?
4.  Why is get O(1)?
5.  Why is insertion in middle O(n)?
6.  Why is append amortized O(1)?
7.  What happens when capacity is exhausted?
8.  What does ensureCapacity do?
9.  What does trimToSize do?
10. Why is ArrayList usually preferred over LinkedList?

------------------------------------------------------------------------

# 63. Interview Questions --- LinkedList

1.  Is Java LinkedList singly or doubly linked?
2.  Why is get(index) O(n)?
3.  Is insertion always O(1)?
4.  What is the role of head/tail?
5.  Why does LinkedList implement Deque?
6.  Why can ArrayList be faster in practice?
7.  What is the memory overhead of linked nodes?

------------------------------------------------------------------------

# 64. Interview Questions --- Mutability

1.  Is List.of mutable?
2.  Is Arrays.asList resizable?
3.  What is Collections.unmodifiableList?
4.  Difference between immutable and unmodifiable?
5.  What does List.copyOf do?
6.  What is a backed view?
7.  What is subList?

------------------------------------------------------------------------

# 65. Interview Questions --- Iteration

1.  What is Iterator?
2.  What is ListIterator?
3.  What is Spliterator?
4.  What is fail-fast?
5.  Is fail-fast guaranteed?
6.  How should elements be removed while iterating?
7.  What is snapshot iteration?
8.  What is CopyOnWriteArrayList?

------------------------------------------------------------------------

# 66. Interview Questions --- Performance

1.  Why is ArrayList cache-friendly?
2.  Why does LinkedList have more memory overhead?
3.  What is amortized complexity?
4.  Why can int\[\] be more memory efficient than
    List`<Integer>`{=html}?
5.  What is boxing?
6.  What is unboxing?
7.  When should ArrayList be pre-sized?
8.  When should a List be replaced by Set or Map?

------------------------------------------------------------------------

# 67. Practical Coding Checklist

## Basic

-   [ ] Create List
-   [ ] Add
-   [ ] Insert
-   [ ] Get
-   [ ] Set
-   [ ] Remove by index
-   [ ] Remove by value
-   [ ] Search
-   [ ] Count
-   [ ] Clear
-   [ ] Traverse

## ArrayList

-   [ ] Capacity
-   [ ] Size
-   [ ] `ensureCapacity`
-   [ ] `trimToSize`
-   [ ] `subList`
-   [ ] Sorting
-   [ ] Iterator
-   [ ] ListIterator

## LinkedList

-   [ ] Add first
-   [ ] Add last
-   [ ] Remove first
-   [ ] Remove last
-   [ ] Peek first
-   [ ] Peek last
-   [ ] Queue operations
-   [ ] Deque operations

## Advanced

-   [ ] Comparable
-   [ ] Comparator
-   [ ] Spliterator
-   [ ] `Arrays.asList`
-   [ ] `List.of`
-   [ ] `List.copyOf`
-   [ ] Unmodifiable view
-   [ ] CopyOnWriteArrayList
-   [ ] Synchronized list
-   [ ] Generic wildcards
-   [ ] Boxing/unboxing
-   [ ] Performance analysis

------------------------------------------------------------------------

# 68. Complete Mastery Checklist

## List Core

-   [ ] List ADT
-   [ ] Ordering
-   [ ] Duplicates
-   [ ] Indexing
-   [ ] Positional operations
-   [ ] Generic types
-   [ ] Null behavior

## ArrayList

-   [ ] Dynamic array
-   [ ] Backing array
-   [ ] Size
-   [ ] Capacity
-   [ ] Growth
-   [ ] Resizing
-   [ ] Amortized append
-   [ ] `ensureCapacity`
-   [ ] `trimToSize`
-   [ ] `subList`
-   [ ] Cache locality

## LinkedList

-   [ ] Doubly linked list
-   [ ] Nodes
-   [ ] Previous/next
-   [ ] Head/tail
-   [ ] End operations
-   [ ] Random access
-   [ ] Deque behavior

## Vector/Stack

-   [ ] Vector
-   [ ] Synchronization
-   [ ] Legacy API
-   [ ] Stack
-   [ ] LIFO
-   [ ] ArrayDeque alternative

## Iteration

-   [ ] Iterator
-   [ ] ListIterator
-   [ ] Spliterator
-   [ ] Fail-fast
-   [ ] Snapshot iteration

## Mutability

-   [ ] `List.of`
-   [ ] `List.copyOf`
-   [ ] `Arrays.asList`
-   [ ] `Collections.unmodifiableList`
-   [ ] Immutable vs unmodifiable

## Ordering

-   [ ] Comparable
-   [ ] Comparator
-   [ ] Natural ordering
-   [ ] Custom ordering
-   [ ] Comparator overflow
-   [ ] Ordering consistency

## Performance

-   [ ] Time complexity
-   [ ] Space complexity
-   [ ] Amortized complexity
-   [ ] Memory overhead
-   [ ] Cache locality
-   [ ] Boxing overhead

## Concurrency

-   [ ] Synchronized wrapper
-   [ ] CopyOnWriteArrayList
-   [ ] Concurrent modification
-   [ ] Snapshot iterator
-   [ ] Read-heavy vs write-heavy workload

------------------------------------------------------------------------

# 69. Final Mental Model

``` text
                         JAVA LIST
                            |
                         List<E>
                            |
          +-----------------+-----------------+
          |                 |                 |
      ArrayList         LinkedList         Vector
          |                 |                 |
   Dynamic array       Doubly linked      Legacy array
          |                 |
          |               Deque
          |
       General
       default
       choice
                            |
                          Stack
                            |
                       Legacy LIFO
```

## Selection Flow

``` text
Need ordered sequence?
        |
       YES
        ↓
Need fast index access?
        |
       YES
        ↓
    ArrayList

Need operations at both ends?
        |
       YES
        ↓
    ArrayDeque
```

For a general-purpose `List`, start with `ArrayList` unless the workload
gives a specific reason to choose another implementation.

------------------------------------------------------------------------

# END --- JAVA LIST 100% COMPLETE NOTES
