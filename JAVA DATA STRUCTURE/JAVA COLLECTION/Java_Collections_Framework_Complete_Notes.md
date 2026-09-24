# Java Collections Framework (JCF) --- Complete Notes

> A structured, interview-friendly reference covering the Java
> Collections Framework: hierarchy, interfaces, implementations,
> methods, complexity, ordering, iterators, hashing, concurrency, and
> important hidden concepts.

------------------------------------------------------------------------

## 1. Java Collections Framework

The **Java Collections Framework (JCF)** is a standardized set of
interfaces, classes, implementations, iterators, and utility methods for
storing and manipulating groups of objects.

### Common packages

``` java
import java.util.*;
```

For concurrent collections:

``` java
import java.util.concurrent.*;
```

------------------------------------------------------------------------

## 2. Collection Hierarchy

``` text
Iterable
   |
   └── Collection
        ├── List
        ├── Set
        │    └── SortedSet
        │         └── NavigableSet
        └── Queue
             └── Deque

Map  ← Separate hierarchy
 |
 ├── SortedMap
 │    └── NavigableMap
 |
 └── ConcurrentMap
```

### Important

`Map` does **not** extend `Collection`.

A `Collection` stores individual elements; a `Map` stores key-value
associations.

------------------------------------------------------------------------

## 3. Core Collection Interfaces

  ------------------------------------------------------------------------
  Interface         Main Property     Duplicates        Typical
                                                        Implementations
  ----------------- ----------------- ----------------- ------------------
  `List`            Ordered sequence  Yes               `ArrayList`,
                                                        `LinkedList`,
                                                        `Vector`

  `Set`             Unique elements   No                `HashSet`,
                                                        `LinkedHashSet`,
                                                        `TreeSet`

  `Queue`           Processing order  Usually yes       `PriorityQueue`,
                                                        `LinkedList`

  `Deque`           Both ends         Usually yes       `ArrayDeque`,
                                                        `LinkedList`
  ------------------------------------------------------------------------

------------------------------------------------------------------------

## 4. `Iterable`

`Iterable` allows an object to be traversed using an iterator and
supports enhanced `for` traversal.

Important method:

``` text
iterator()
```

------------------------------------------------------------------------

## 5. `Collection`

`Collection<E>` is the root interface for collections of individual
elements.

  Method                 Purpose
  ---------------------- --------------------------------------
  `add(E e)`             Add an element
  `addAll(...)`          Add elements from another collection
  `remove(Object o)`     Remove an element
  `removeAll(...)`       Remove matching elements
  `retainAll(...)`       Keep only matching elements
  `clear()`              Remove all elements
  `size()`               Number of elements
  `isEmpty()`            Check whether empty
  `contains(Object o)`   Check membership
  `containsAll(...)`     Check multiple memberships
  `iterator()`           Return iterator
  `toArray()`            Convert to array
  `removeIf(...)`        Remove matching elements
  `stream()`             Create sequential stream
  `parallelStream()`     Create parallel stream

------------------------------------------------------------------------

# 6. List Interface

A `List` represents an ordered sequence.

### Characteristics

-   Maintains positional order.
-   Allows duplicates.
-   Supports index-based operations.
-   Null handling depends on implementation.

### Main implementations

-   `ArrayList`
-   `LinkedList`
-   `Vector`
-   `Stack`

------------------------------------------------------------------------

# 7. ArrayList

`ArrayList` is a resizable-array implementation of `List`.

### Characteristics

-   Dynamic array
-   Fast random access
-   Maintains insertion order
-   Allows duplicates
-   Allows `null`
-   Not synchronized by default

### Important methods

  Method                  Purpose
  ----------------------- -----------------------------
  `add(E e)`              Append
  `add(int, E)`           Insert at index
  `get(int)`              Read element
  `set(int, E)`           Replace element
  `remove(int)`           Remove by index
  `remove(Object)`        Remove matching object
  `indexOf(Object)`       First matching index
  `lastIndexOf(Object)`   Last matching index
  `contains(Object)`      Membership test
  `subList(from,to)`      Range view
  `ensureCapacity()`      Ensure capacity
  `trimToSize()`          Reduce capacity toward size

### Complexity

  Operation            Typical complexity
  ------------------ --------------------
  `get()`                            O(1)
  `set()`                            O(1)
  Append                   O(1) amortized
  Middle insertion                   O(n)
  Middle deletion                    O(n)
  Search                             O(n)

### Size vs capacity

``` text
Size     = number of stored elements
Capacity = allocated storage available
```

When capacity is insufficient, the backing storage grows and elements
are moved/copied. This is why append is analyzed as **amortized O(1)**.

------------------------------------------------------------------------

# 8. LinkedList

Java's `LinkedList` is a doubly linked list and also implements `Deque`.

### Characteristics

-   Ordered
-   Allows duplicates
-   Allows `null`
-   Sequential access
-   Efficient operations at the ends

### Important methods

  Method            Purpose
  ----------------- -----------------------
  `add()`           Add element
  `addFirst()`      Add at beginning
  `addLast()`       Add at end
  `removeFirst()`   Remove first
  `removeLast()`    Remove last
  `getFirst()`      Read first
  `getLast()`       Read last
  `peek()`          View first
  `offer()`         Queue-style insertion
  `poll()`          Queue-style removal

### Complexity

  Operation                                  Complexity
  --------------------------- -------------------------
  First/last insertion                             O(1)
  First/last deletion                              O(1)
  Random `get(index)`                              O(n)
  Search                                           O(n)
  Arbitrary index insertion     O(n) to locate position
  Arbitrary index deletion      O(n) to locate position

> Important: Linked-list insertion is not automatically O(1) for an
> arbitrary index. Finding the position may require O(n).

------------------------------------------------------------------------

# 9. Vector

`Vector` is a legacy synchronized dynamic-array implementation.

### Characteristics

-   Resizable array
-   Synchronized legacy methods
-   Ordered
-   Allows duplicates

### Important methods

-   `add()`
-   `get()`
-   `set()`
-   `remove()`
-   `capacity()`
-   `ensureCapacity()`

For new code, choose it only when its specific legacy synchronization
behavior is actually required.

------------------------------------------------------------------------

# 10. Stack

`Stack<E>` is a legacy class extending `Vector`.

It follows **LIFO**:

``` text
Last In → First Out
```

  Method       Purpose
  ------------ -----------------
  `push()`     Add to top
  `pop()`      Remove top
  `peek()`     View top
  `empty()`    Check empty
  `search()`   Search from top

### Modern alternative

Use a `Deque`, commonly `ArrayDeque`, for stack behavior.

------------------------------------------------------------------------

# 11. Set Interface

A `Set` does not permit duplicate elements according to its
equality/ordering semantics.

### Main implementations

-   `HashSet`
-   `LinkedHashSet`
-   `TreeSet`

------------------------------------------------------------------------

# 12. HashSet

Hash-based set.

### Characteristics

-   No duplicates
-   No guaranteed iteration order
-   Allows one `null`
-   Typical average O(1) basic operations

### Complexity

  Operation        Average
  -------------- ---------
  `add()`             O(1)
  `remove()`          O(1)
  `contains()`        O(1)

Worst-case behavior depends on collisions and implementation details.

### Internal concept

`HashSet` uses a hash-based backing structure implemented around a
`HashMap`-style design.

------------------------------------------------------------------------

# 13. LinkedHashSet

Combines:

``` text
Hash-based lookup
        +
Insertion-order tracking
```

### Characteristics

-   No duplicates
-   Maintains insertion order
-   Usually average O(1) basic operations
-   More memory overhead than `HashSet`

------------------------------------------------------------------------

# 14. TreeSet

`TreeSet` is a sorted set.

### Characteristics

-   No duplicates
-   Sorted order
-   Navigable
-   Typically O(log n) basic operations
-   Uses natural ordering or a `Comparator`

### Important methods

  Method          Purpose
  --------------- ---------------------------
  `first()`       Smallest
  `last()`        Largest
  `headSet()`     Values before boundary
  `tailSet()`     Values from boundary
  `subSet()`      Values in range
  `ceiling()`     Smallest value \>= target
  `floor()`       Largest value \<= target
  `higher()`      Smallest value \> target
  `lower()`       Largest value \< target
  `pollFirst()`   Remove smallest
  `pollLast()`    Remove largest

In OpenJDK, `TreeSet` is backed by a `TreeMap`, whose implementation is
a Red-Black tree.

------------------------------------------------------------------------

# 15. Queue Interface

A queue represents elements waiting for processing.

Traditional queue behavior:

``` text
FIFO
First In → First Out
```

However, `PriorityQueue` is priority-based rather than simple FIFO.

### Common implementations

-   `PriorityQueue`
-   `LinkedList`
-   `ArrayDeque`

------------------------------------------------------------------------

# 16. PriorityQueue

Java's `PriorityQueue` is heap-based.

By default, the head is the least element according to natural ordering.

``` text
PriorityQueue
      ↓
Min-heap behavior by default
```

### Methods

  Method       Purpose
  ------------ -------------
  `offer()`    Insert
  `add()`      Insert
  `poll()`     Remove head
  `peek()`     View head
  `remove()`   Remove head

### Complexity

  Operation            Complexity
  ------------------ ------------
  `offer()`              O(log n)
  `poll()`               O(log n)
  `peek()`                   O(1)
  `remove(Object)`           O(n)
  `contains()`               O(n)

> Iterating through a `PriorityQueue` does not produce globally sorted
> order. Only the head is guaranteed to be the highest-priority element
> according to the queue's ordering.

------------------------------------------------------------------------

# 17. Deque

`Deque` means **Double Ended Queue**.

It supports insertion and removal at both ends.

  Method            Purpose
  ----------------- --------------------
  `addFirst()`      Insert front
  `addLast()`       Insert back
  `offerFirst()`    Front insertion
  `offerLast()`     Back insertion
  `removeFirst()`   Remove front
  `removeLast()`    Remove back
  `pollFirst()`     Safe front removal
  `pollLast()`      Safe back removal
  `peekFirst()`     View front
  `peekLast()`      View back

------------------------------------------------------------------------

# 18. ArrayDeque

`ArrayDeque` is a resizable-array implementation of `Deque`.

### Characteristics

-   Efficient at both ends
-   Can act as stack
-   Can act as queue
-   Does not allow `null`
-   Not thread-safe by default

### Stack usage

``` text
push()
pop()
peek()
```

### Queue usage

``` text
offer()
poll()
peek()
```

### Why use it instead of Stack?

`Stack` is a legacy class. `ArrayDeque` provides a more general and
efficient deque abstraction for typical stack use.

------------------------------------------------------------------------

# 19. Map Interface

`Map<K,V>` is separate from `Collection`.

It stores:

``` text
Key → Value
```

### Properties

-   Keys are unique.
-   Values may repeat.
-   Ordering depends on implementation.

### Major implementations

-   `HashMap`
-   `LinkedHashMap`
-   `TreeMap`
-   `Hashtable`
-   `ConcurrentHashMap`

------------------------------------------------------------------------

# 20. HashMap

`HashMap` is a general-purpose hash-based map.

### Characteristics

-   No guaranteed iteration order
-   Allows one `null` key
-   Allows multiple `null` values
-   Not thread-safe by default

### Important methods

  Method                 Purpose
  ---------------------- --------------------------
  `put()`                Insert/replace
  `putIfAbsent()`        Insert if missing
  `get()`                Retrieve
  `getOrDefault()`       Retrieve with fallback
  `remove()`             Delete mapping
  `replace()`            Replace value
  `containsKey()`        Test key
  `containsValue()`      Test value
  `keySet()`             Key view
  `values()`             Value view
  `entrySet()`           Entry view
  `forEach()`            Process mappings
  `compute()`            Compute mapping
  `computeIfAbsent()`    Compute missing mapping
  `computeIfPresent()`   Compute existing mapping
  `merge()`              Merge mapping

### Typical average complexity

  Operation           Average
  ----------------- ---------
  `put()`                O(1)
  `get()`                O(1)
  `remove()`             O(1)
  `containsKey()`        O(1)

Actual performance depends on hashing, collisions, resizing, and
implementation details.

------------------------------------------------------------------------

# 21. HashMap Internal Concepts

Understand these deeply:

## Hashing

``` text
Key
 ↓
hash computation
 ↓
bucket selection
 ↓
stored entry
```

## Collision

Different keys can map to the same bucket.

## Collision handling

Modern Java implementations can use linked-node bins and may treeify
heavily collided bins under appropriate conditions.

## Load factor

A commonly used default load factor is:

``` text
0.75
```

## Capacity

A commonly known default initial capacity is:

``` text
16
```

However, the internal table is lazily initialized, so do not assume a
16-bucket table is allocated immediately after construction.

## Resizing

``` text
Table becomes sufficiently full
        ↓
Capacity grows
        ↓
Entries are redistributed
```

------------------------------------------------------------------------

# 22. LinkedHashMap

`LinkedHashMap` combines:

-   Hash-based lookup
-   Predictable iteration order

It can maintain:

-   Insertion order
-   Access order

### Important application

Access-order `LinkedHashMap` can be used as a building block for an
LRU-cache-style implementation.

------------------------------------------------------------------------

# 23. TreeMap

`TreeMap` stores mappings ordered by key.

### Characteristics

-   Sorted keys
-   Navigable
-   Typically O(log n) operations
-   Natural ordering or custom `Comparator`

### Important methods

  Method           Purpose
  ---------------- -------------------------
  `firstKey()`     Smallest key
  `lastKey()`      Largest key
  `headMap()`      Keys before boundary
  `tailMap()`      Keys from boundary
  `subMap()`       Keys in range
  `ceilingKey()`   Smallest key \>= target
  `floorKey()`     Largest key \<= target
  `higherKey()`    Smallest key \> target
  `lowerKey()`     Largest key \< target

In OpenJDK, `TreeMap` uses a Red-Black tree.

------------------------------------------------------------------------

# 24. Hashtable

`Hashtable` is a legacy synchronized hash-table implementation.

### Characteristics

-   Synchronized legacy API
-   No `null` keys
-   No `null` values

It is not the modern replacement for `HashMap` in concurrent
applications.

------------------------------------------------------------------------

# 25. ConcurrentHashMap

`ConcurrentHashMap` is designed for concurrent access.

Package:

``` java
import java.util.concurrent.*;
```

### Characteristics

-   Thread-safe
-   Supports concurrent operations
-   Does not allow `null` keys
-   Does not allow `null` values
-   Supports atomic compound operations

### Important methods

-   `putIfAbsent()`
-   `compute()`
-   `computeIfAbsent()`
-   `computeIfPresent()`
-   `merge()`
-   `replace()`

### Historical vs modern implementation

Older Java versions used a segmented-lock architecture.

Modern Java implementations use a table with fine-grained
synchronization and CAS-based mechanisms rather than the old fixed
`Segment[]` model.

------------------------------------------------------------------------

# 26. Iterator

`Iterator<E>` provides sequential traversal.

  Method        Purpose
  ------------- ----------------------------------------------
  `hasNext()`   Check for another element
  `next()`      Return next element
  `remove()`    Remove last returned element where supported

------------------------------------------------------------------------

# 27. ListIterator

`ListIterator<E>` is specialized for lists and supports bidirectional
traversal.

  Method            Purpose
  ----------------- ----------------
  `hasNext()`       Check forward
  `next()`          Move forward
  `hasPrevious()`   Check backward
  `previous()`      Move backward
  `add()`           Insert
  `set()`           Replace
  `remove()`        Remove

------------------------------------------------------------------------

# 28. Fail-Fast and Concurrent Iteration

## Fail-Fast

Some iterators detect structural modification and may throw:

``` text
ConcurrentModificationException
```

This is a **best-effort debugging behavior**, not a synchronization
guarantee.

## Weakly Consistent

Some concurrent collections permit traversal while concurrent
modification occurs without requiring immediate failure.

`ConcurrentHashMap` provides weakly consistent iterators.

## Snapshot Iteration

Some collections iterate over a snapshot/copy.

Important example:

``` text
CopyOnWriteArrayList
```

------------------------------------------------------------------------

# 29. Collections Utility Class

`Collections` provides static utility methods.

  Method                 Purpose
  ---------------------- ---------------------------
  `sort()`               Sort list
  `reverse()`            Reverse list
  `shuffle()`            Randomize order
  `binarySearch()`       Binary search sorted list
  `min()`                Minimum
  `max()`                Maximum
  `frequency()`          Count occurrences
  `copy()`               Copy between lists
  `fill()`               Fill list
  `swap()`               Swap elements
  `rotate()`             Rotate elements
  `replaceAll()`         Replace matching values
  `synchronizedList()`   Synchronized wrapper
  `unmodifiableList()`   Unmodifiable view

------------------------------------------------------------------------

# 30. Comparable vs Comparator

## Comparable

Defines the object's natural ordering.

``` java
class Student implements Comparable<Student> {
    @Override
    public int compareTo(Student other) {
        return Integer.compare(this.age, other.age);
    }
}
```

## Comparator

Defines an ordering externally.

``` java
Comparator<Student> byAge =
    (a, b) -> Integer.compare(a.age, b.age);
```

Another ordering can also be defined:

``` java
Comparator<Student> byName =
    Comparator.comparing(s -> s.name);
```

## Comparison

  Comparable                     Comparator
  ------------------------------ -----------------------------
  Natural ordering               External ordering
  `compareTo()`                  `compare()`
  Usually one natural ordering   Multiple orderings possible
  Implemented by the class       Separate comparator

------------------------------------------------------------------------

# 31. Ordering and Equality

For sorted structures such as `TreeSet` and `TreeMap`, ordering
determines equivalence for collection operations.

Understand:

-   `equals()`
-   `hashCode()`
-   `compareTo()`
-   `Comparator`
-   Comparator consistency

If a comparator returns:

``` text
0
```

the objects are equivalent according to that ordering.

This can cause two objects that are not `equals()`-equal to be treated
as the same element/key by a sorted collection.

------------------------------------------------------------------------

# 32. `equals()` and `hashCode()`

Hash-based collections rely on the contract between:

``` text
equals()
+
hashCode()
```

### Core rule

If:

``` java
a.equals(b)
```

is `true`, then:

``` java
a.hashCode() == b.hashCode()
```

must also be true.

The reverse is not required.

Therefore:

``` text
Same hash code
      ≠
Objects must be equal
```

This is why hash collisions are possible.

------------------------------------------------------------------------

# 33. Map.Entry

A `Map.Entry<K,V>` represents one key-value mapping.

Important methods:

-   `getKey()`
-   `getValue()`
-   `setValue()`

`entrySet()` is especially useful when both key and value are required.

------------------------------------------------------------------------

# 34. Collection Views

Some methods return **views** rather than independent copies.

Examples:

``` text
Map.keySet()
Map.values()
Map.entrySet()
List.subList()
```

A change to a mutable backing collection can therefore affect its view.

This is an important hidden JCF concept.

------------------------------------------------------------------------

# 35. Null Handling

Null behavior differs by implementation.

  Collection            Null behavior
  --------------------- --------------------------------------------------
  `ArrayList`           Allows `null`
  `LinkedList`          Allows `null`
  `HashSet`             Allows one `null`
  `HashMap`             Allows one `null` key and multiple `null` values
  `TreeSet`             Natural ordering does not support `null`
  `TreeMap`             Natural ordering does not support `null` keys
  `ArrayDeque`          Does not allow `null`
  `PriorityQueue`       Does not allow `null`
  `ConcurrentHashMap`   Does not allow `null` keys/values
  `Hashtable`           Does not allow `null` keys/values

------------------------------------------------------------------------

# 36. Thread Safety

Distinguish carefully between:

-   Not thread-safe
-   Synchronized
-   Concurrent
-   Immutable
-   Unmodifiable

### Usually not synchronized

-   `ArrayList`
-   `HashMap`
-   `HashSet`
-   `ArrayDeque`

### Legacy synchronized

-   `Vector`
-   `Hashtable`

### Concurrent

-   `ConcurrentHashMap`
-   Classes in `java.util.concurrent`

### Important distinction

An **unmodifiable view** is not necessarily immutable.

A **synchronized wrapper** is not the same thing as a purpose-built
concurrent data structure.

------------------------------------------------------------------------

# 37. Choosing the Right Collection

  Requirement                                      Typical choice
  ------------------------------------------------ ---------------------
  Indexed access                                   `ArrayList`
  Insert/remove at both ends                       `ArrayDeque`
  Unique unordered values                          `HashSet`
  Unique values + insertion order                  `LinkedHashSet`
  Sorted unique values                             `TreeSet`
  General key-value lookup                         `HashMap`
  Key-value + predictable insertion/access order   `LinkedHashMap`
  Sorted keys                                      `TreeMap`
  Priority-based retrieval                         `PriorityQueue`
  Concurrent key-value operations                  `ConcurrentHashMap`

------------------------------------------------------------------------

# 38. Important Comparisons

## ArrayList vs LinkedList

  Feature                ArrayList        LinkedList
  ---------------------- ---------------- -----------------------------------
  Representation         Dynamic array    Doubly linked list
  Random access          Fast             Slow
  Append                 O(1) amortized   O(1)
  Arbitrary insertion    O(n)             O(n) to locate + O(1) link change
  Memory locality        Better           Worse
  Per-element overhead   Lower            Higher
  `Deque` support        No               Yes

### Key interview point

Do not say:

> LinkedList insertion is always O(1).

The link modification can be O(1) once the position is known, but
locating an arbitrary position can be O(n).

------------------------------------------------------------------------

## HashMap vs Hashtable

  Feature                         HashMap       Hashtable
  ------------------------------- ------------- ---------------------
  Legacy                          No            Yes
  Synchronized                    No            Yes
  Null key                        One allowed   Not allowed
  Null values                     Allowed       Not allowed
  Modern concurrent alternative   ---           `ConcurrentHashMap`

------------------------------------------------------------------------

## HashMap vs LinkedHashMap vs TreeMap

  Feature                       HashMap     LinkedHashMap   TreeMap
  ----------------------------- ----------- --------------- -----------
  Hash-based                    Yes         Yes             No
  Sorted                        No          No              Yes
  Predictable insertion order   No          Yes             Key order
  Access order                  No          Yes             No
  Typical lookup                O(1) avg.   O(1) avg.       O(log n)
  Navigation/range operations   No          Limited         Yes

------------------------------------------------------------------------

## HashSet vs LinkedHashSet vs TreeSet

  Feature            HashSet           LinkedHashSet   TreeSet
  ------------------ ----------------- --------------- ----------
  Duplicates         No                No              No
  Ordering           None guaranteed   Insertion       Sorted
  Typical add        O(1) avg.         O(1) avg.       O(log n)
  Navigation         No                No              Yes
  Range operations   No                No              Yes

------------------------------------------------------------------------

## Queue vs Deque vs PriorityQueue

  Structure       Main behavior
  --------------- ------------------
  Queue           Processing order
  Deque           Both ends
  PriorityQueue   Priority order

Do not assume `PriorityQueue` is FIFO.

------------------------------------------------------------------------

# 39. Hidden JCF Topics

A complete JCF study should also cover:

-   `Collection` vs `Collections`
-   `Collections` vs `Arrays`
-   `Iterable`
-   `Iterator`
-   `ListIterator`
-   `Spliterator`
-   Fail-fast behavior
-   Weakly consistent iteration
-   Snapshot iteration
-   Structural modification
-   Collection views
-   Backed views
-   `subList()`
-   `keySet()`
-   `values()`
-   `entrySet()`
-   `equals()` / `hashCode()`
-   `Comparable`
-   `Comparator`
-   Comparator consistency
-   Null policies
-   Generics
-   Wildcards
-   `? extends`
-   `? super`
-   Immutable collections
-   Unmodifiable views
-   Copy-on-write collections
-   Synchronized wrappers
-   Concurrent collections
-   Blocking queues
-   Concurrent maps
-   Hash collisions
-   Load factor
-   Capacity
-   Resizing
-   Tree ordering
-   Memory overhead
-   Boxing/unboxing
-   Primitive arrays vs wrapper collections

------------------------------------------------------------------------

# 40. Java 8+ Collection Features

Important collection-related features include:

## Collection methods

-   `forEach`
-   `removeIf`
-   `replaceAll`
-   `stream`
-   `parallelStream`

## Map methods

-   `getOrDefault`
-   `putIfAbsent`
-   `replace`
-   `replaceAll`
-   `compute`
-   `computeIfAbsent`
-   `computeIfPresent`
-   `merge`

------------------------------------------------------------------------

# 41. Advanced JCF Study Order

``` text
Generics
   ↓
Iterable
   ↓
Collection
   ↓
List
   ↓
ArrayList
   ↓
LinkedList
   ↓
Set
   ↓
HashSet
   ↓
LinkedHashSet
   ↓
TreeSet
   ↓
Queue
   ↓
Deque
   ↓
ArrayDeque
   ↓
PriorityQueue
   ↓
Map
   ↓
HashMap
   ↓
LinkedHashMap
   ↓
TreeMap
   ↓
Hashtable
   ↓
ConcurrentHashMap
   ↓
Iterator / ListIterator / Spliterator
   ↓
Comparable / Comparator
   ↓
Collections utilities
   ↓
Hashing internals
   ↓
Ordering internals
   ↓
Concurrent collections
   ↓
Performance + memory
```

------------------------------------------------------------------------

# 42. Final JCF Mastery Checklist

## Interfaces

-   [ ] `Iterable`
-   [ ] `Collection`
-   [ ] `List`
-   [ ] `Set`
-   [ ] `SortedSet`
-   [ ] `NavigableSet`
-   [ ] `Queue`
-   [ ] `Deque`
-   [ ] `Map`
-   [ ] `SortedMap`
-   [ ] `NavigableMap`
-   [ ] `ConcurrentMap`

## List

-   [ ] `ArrayList`
-   [ ] `LinkedList`
-   [ ] `Vector`
-   [ ] `Stack`

## Set

-   [ ] `HashSet`
-   [ ] `LinkedHashSet`
-   [ ] `TreeSet`

## Queue / Deque

-   [ ] `PriorityQueue`
-   [ ] `ArrayDeque`
-   [ ] `LinkedList`

## Map

-   [ ] `HashMap`
-   [ ] `LinkedHashMap`
-   [ ] `TreeMap`
-   [ ] `Hashtable`
-   [ ] `ConcurrentHashMap`

## Traversal

-   [ ] Iterator
-   [ ] ListIterator
-   [ ] Spliterator
-   [ ] Fail-fast
-   [ ] Weakly consistent iteration
-   [ ] Snapshot iteration

## Ordering

-   [ ] Comparable
-   [ ] Comparator
-   [ ] Natural ordering
-   [ ] Custom ordering
-   [ ] Comparator consistency

## Hashing

-   [ ] Hash function
-   [ ] Collision
-   [ ] Bucket
-   [ ] Load factor
-   [ ] Capacity
-   [ ] Resizing
-   [ ] Rehashing
-   [ ] `equals()`
-   [ ] `hashCode()`

## Concurrency

-   [ ] Synchronized collections
-   [ ] Concurrent collections
-   [ ] ConcurrentHashMap
-   [ ] Blocking queues
-   [ ] Copy-on-write collections
-   [ ] Weakly consistent iteration

## Performance

-   [ ] Time complexity
-   [ ] Space complexity
-   [ ] Amortized complexity
-   [ ] Memory overhead
-   [ ] Cache locality
-   [ ] Boxing/unboxing

------------------------------------------------------------------------

# 43. One-Page Mental Model

``` text
                         JAVA COLLECTIONS
                                |
             +------------------+------------------+
             |                                     |
        Collection                              Map
             |                                     |
      +------+------+                    +---------+---------+
      |      |      |                    |         |         |
     List   Set   Queue               HashMap  LinkedHash  TreeMap
      |      |      |                              |
      |      |      +---- Deque                    |
      |      |             |                       |
      |      |        ArrayDeque                   |
      |      |                                     |
      |      +---- HashSet                         |
      |      +---- LinkedHashSet                  |
      |      +---- TreeSet                         |
      |                                            |
      +---- ArrayList                              |
      +---- LinkedList                             |
      +---- Vector                                 |
      +---- Stack                                  |
                                                   |
                                      ConcurrentHashMap
                                      Hashtable
```

------------------------------------------------------------------------

# END --- JAVA COLLECTIONS FRAMEWORK
