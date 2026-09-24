# Java Map --- 100% Complete Notes

> **Goal:** Complete Java `Map` coverage from beginner to advanced
> level, including the `Map` interface, key-value model, all major
> methods, `HashMap`, `LinkedHashMap`, `TreeMap`, `Hashtable`,
> `ConcurrentHashMap`, `WeakHashMap`, `IdentityHashMap`, `EnumMap`,
> immutable Maps, sorted/navigable Maps, hashing,
> `equals()`/`hashCode()`, collision handling, load factor, resizing,
> iteration, views, concurrency, atomic operations, performance, DSA
> patterns, real-world backend use cases, and interview questions.

------------------------------------------------------------------------

# PART 1 --- MAP FUNDAMENTALS

## 1. What Is a Map?

A **Map** stores data as:

``` text
KEY → VALUE
```

Example:

``` text
101 → "Deep"
102 → "Rahul"
103 → "Amit"
```

A key identifies a value.

``` java
Map<Integer, String> users =
    new HashMap<>();

users.put(101, "Deep");
users.put(102, "Rahul");
```

------------------------------------------------------------------------

## 2. Main Property of Map

The most important Map rule is:

``` text
A key can occur only once.
```

Example:

``` java
map.put(1, "A");
map.put(1, "B");
```

The result is conceptually:

``` text
1 → B
```

The second `put()` replaces the value associated with key `1`.

------------------------------------------------------------------------

## 3. Map Is Not a Collection

Important:

``` java
Map<K, V>
```

does **not** extend:

``` java
Collection<E>
```

Instead, Map is a separate collection-framework abstraction.

Hierarchy:

``` text
Map
├── HashMap
├── LinkedHashMap
├── SortedMap
│   └── NavigableMap
│       └── TreeMap
├── Hashtable
├── WeakHashMap
├── IdentityHashMap
├── EnumMap
└── ConcurrentMap
    └── ConcurrentHashMap
```

------------------------------------------------------------------------

# PART 2 --- KEY-VALUE MODEL

## 4. Generic Types

Map uses two type parameters:

``` java
Map<K, V>
```

where:

``` text
K = Key
V = Value
```

Example:

``` java
Map<Integer, String> map =
    new HashMap<>();
```

means:

``` text
Integer → Key
String  → Value
```

------------------------------------------------------------------------

## 5. Key Uniqueness

``` java
map.put(1, "A");
map.put(2, "B");
map.put(1, "C");
```

Final logical contents:

``` text
1 → C
2 → B
```

Key `1` still occurs once.

------------------------------------------------------------------------

## 6. Values Can Repeat

Keys must be unique, but values do not have to be unique.

``` java
map.put(1, "Java");
map.put(2, "Java");
map.put(3, "Java");
```

Valid:

``` text
1 → Java
2 → Java
3 → Java
```

------------------------------------------------------------------------

# PART 3 --- CREATING MAPS

## 7. HashMap

``` java
Map<Integer, String> map =
    new HashMap<>();
```

------------------------------------------------------------------------

## 8. LinkedHashMap

``` java
Map<Integer, String> map =
    new LinkedHashMap<>();
```

------------------------------------------------------------------------

## 9. TreeMap

``` java
Map<Integer, String> map =
    new TreeMap<>();
```

------------------------------------------------------------------------

## 10. Hashtable

``` java
Map<Integer, String> map =
    new Hashtable<>();
```

This is a legacy synchronized Map implementation.

------------------------------------------------------------------------

## 11. ConcurrentHashMap

``` java
Map<Integer, String> map =
    new ConcurrentHashMap<>();
```

------------------------------------------------------------------------

## 12. EnumMap

``` java
enum Status {
    NEW,
    PROCESSING,
    COMPLETE
}

Map<Status, String> map =
    new EnumMap<>(Status.class);
```

------------------------------------------------------------------------

# PART 4 --- BASIC MAP METHODS

## 13. `put()`

``` java
map.put("name", "Deep");
```

Adds or replaces a mapping.

------------------------------------------------------------------------

## 14. `get()`

``` java
String name =
    map.get("name");
```

Returns the value associated with the key.

If the key does not exist:

``` text
null
```

may be returned.

------------------------------------------------------------------------

## 15. `remove()`

``` java
map.remove("name");
```

Removes the mapping for the key.

------------------------------------------------------------------------

## 16. `containsKey()`

``` java
map.containsKey("name");
```

Checks whether the key exists.

------------------------------------------------------------------------

## 17. `containsValue()`

``` java
map.containsValue("Deep");
```

Checks whether at least one key maps to that value.

For most Maps, value lookup requires scanning values:

``` text
O(n)
```

------------------------------------------------------------------------

## 18. `size()`

``` java
int size =
    map.size();
```

Returns number of key-value mappings.

------------------------------------------------------------------------

## 19. `isEmpty()`

``` java
map.isEmpty();
```

Checks whether the Map has no mappings.

------------------------------------------------------------------------

## 20. `clear()`

``` java
map.clear();
```

Removes all mappings.

------------------------------------------------------------------------

# PART 5 --- PUT BEHAVIOR

## 21. `put()` Returns Previous Value

Example:

``` java
Map<Integer, String> map =
    new HashMap<>();

String old =
    map.put(1, "A");
```

Initially:

``` text
old = null
```

Then:

``` java
old = map.put(1, "B");
```

Now:

``` text
old = "A"
```

and Map contains:

``` text
1 → B
```

This is useful when you need to know whether a mapping was replaced.

------------------------------------------------------------------------

# PART 6 --- PUT IF ABSENT

## 22. `putIfAbsent()`

``` java
map.putIfAbsent(1, "A");
```

Adds the mapping only if key `1` is not already associated with a value.

Example:

``` java
map.put(1, "Existing");

map.putIfAbsent(1, "New");
```

Result:

``` text
1 → Existing
```

------------------------------------------------------------------------

## 23. Difference

``` java
put()
```

can replace.

``` java
putIfAbsent()
```

does not replace an existing mapping when a value is already present.

------------------------------------------------------------------------

# PART 7 --- GET OR DEFAULT

## 24. `getOrDefault()`

``` java
String name =
    map.getOrDefault(
        "name",
        "Unknown"
    );
```

If key exists:

``` text
actual value
```

Otherwise:

``` text
Unknown
```

Important:

`getOrDefault()` does not insert the default value.

------------------------------------------------------------------------

# PART 8 --- REMOVE WITH KEY AND VALUE

## 25. Conditional `remove()`

Map provides:

``` java
remove(key, value)
```

Example:

``` java
map.remove(1, "A");
```

The mapping is removed only if:

``` text
key = 1
AND
value = A
```

matches.

This is especially useful in concurrent programming because the
condition is part of the Map operation.

------------------------------------------------------------------------

# PART 9 --- REPLACE

## 26. `replace()`

``` java
map.replace(1, "NewValue");
```

Replaces the value only if the key exists.

If key does not exist:

``` text
no new mapping is created
```

------------------------------------------------------------------------

## 27. Conditional Replace

``` java
map.replace(
    1,
    "Old",
    "New"
);
```

Replaces only if:

``` text
key = 1
AND
current value = Old
```

------------------------------------------------------------------------

# PART 10 --- REPLACE ALL

## 28. `replaceAll()`

``` java
map.replaceAll(
    (key, value) ->
        value.toUpperCase()
);
```

Every mapping is transformed.

Example:

``` text
1 → java
2 → spring
```

becomes:

``` text
1 → JAVA
2 → SPRING
```

------------------------------------------------------------------------

# PART 11 --- COMPUTE METHODS

## 29. `compute()`

``` java
map.compute(
    "count",
    (key, value) ->
        value == null
            ? 1
            : value + 1
);
```

The remapping function receives:

``` text
key
current value
```

and calculates a new value.

------------------------------------------------------------------------

## 30. `computeIfAbsent()`

One of the most useful Map methods.

``` java
map.computeIfAbsent(
    "users",
    key -> new ArrayList<>()
);
```

If key is absent, the function creates the value.

Common grouping pattern:

``` java
map.computeIfAbsent(
    category,
    key -> new ArrayList<>()
).add(item);
```

------------------------------------------------------------------------

## 31. `computeIfPresent()`

``` java
map.computeIfPresent(
    "count",
    (key, value) ->
        value + 1
);
```

Runs only when a mapping is present.

------------------------------------------------------------------------

# PART 12 --- MERGE

## 32. `merge()`

`merge()` is extremely useful for counters.

``` java
map.merge(
    "Java",
    1,
    Integer::sum
);
```

If absent:

``` text
Java → 1
```

If already:

``` text
Java → 5
```

then:

``` text
Java → 6
```

------------------------------------------------------------------------

## 33. Word Frequency

``` java
Map<String, Integer> frequency =
    new HashMap<>();

for (String word : words) {

    frequency.merge(
        word,
        1,
        Integer::sum
    );
}
```

This is a common DSA and backend pattern.

------------------------------------------------------------------------

# PART 13 --- MAP VIEWS

## 34. `keySet()`

``` java
Set<Integer> keys =
    map.keySet();
```

Provides a view of the keys.

------------------------------------------------------------------------

## 35. `values()`

``` java
Collection<String> values =
    map.values();
```

Provides a view of the values.

Values are not guaranteed to be unique.

------------------------------------------------------------------------

## 36. `entrySet()`

``` java
Set<Map.Entry<Integer, String>> entries =
    map.entrySet();
```

Each entry contains:

``` text
key
value
```

This is generally the best way to iterate over both keys and values.

------------------------------------------------------------------------

# PART 14 --- MAP ENTRY

## 37. `Map.Entry`

Example:

``` java
for (Map.Entry<Integer, String> entry
        : map.entrySet()) {

    System.out.println(
        entry.getKey()
    );

    System.out.println(
        entry.getValue()
    );
}
```

------------------------------------------------------------------------

## 38. Entry Methods

Important methods:

``` java
getKey()
getValue()
setValue()
```

The exact behavior of `setValue()` depends on whether the entry comes
from a modifiable Map/view.

------------------------------------------------------------------------

# PART 15 --- ITERATING MAP

## 39. Iterate Keys

``` java
for (Integer key :
        map.keySet()) {

    System.out.println(key);
}
```

------------------------------------------------------------------------

## 40. Iterate Values

``` java
for (String value :
        map.values()) {

    System.out.println(value);
}
```

------------------------------------------------------------------------

## 41. Iterate Key + Value

``` java
for (Map.Entry<Integer, String> entry :
        map.entrySet()) {

    System.out.println(
        entry.getKey()
        + " = "
        + entry.getValue()
    );
}
```

------------------------------------------------------------------------

## 42. `forEach()`

``` java
map.forEach(
    (key, value) ->
        System.out.println(
            key + " = " + value
        )
);
```

------------------------------------------------------------------------

# PART 16 --- WHY ENTRYSET IS IMPORTANT

## 43. Avoid Extra Lookup

Less direct:

``` java
for (Integer key : map.keySet()) {
    String value = map.get(key);
}
```

Better:

``` java
for (Map.Entry<Integer, String> entry :
        map.entrySet()) {

    Integer key =
        entry.getKey();

    String value =
        entry.getValue();
}
```

The entry already contains both key and value.

------------------------------------------------------------------------

# PART 17 --- HASHMAP

## 44. What Is HashMap?

`HashMap` is the most commonly used general-purpose Map implementation.

Package:

``` java
java.util.HashMap
```

Characteristics:

``` text
Key-value storage
Unique keys
No guaranteed iteration order
Hash-based
Allows one null key
Allows multiple null values
Not thread-safe
```

------------------------------------------------------------------------

# PART 18 --- HASHMAP EXAMPLE

## 45. Basic Example

``` java
Map<Integer, String> employees =
    new HashMap<>();

employees.put(101, "Deep");
employees.put(102, "Rahul");
employees.put(103, "Amit");

System.out.println(
    employees.get(101)
);
```

Output:

``` text
Deep
```

------------------------------------------------------------------------

# PART 19 --- HASHMAP INTERNAL CONCEPT

## 46. Hashing Flow

Conceptually:

``` text
Key
 ↓
hashCode()
 ↓
hash spreading
 ↓
bucket index
 ↓
bucket
 ↓
compare key
 ↓
equals()
 ↓
mapping
```

The exact implementation details are JDK-dependent.

------------------------------------------------------------------------

## 47. Bucket

Conceptually:

``` text
table
--------------------------------
0 → 
1 → [key,value]
2 →
3 → [key,value]
4 →
5 → [key,value]
--------------------------------
```

A Map stores mappings in buckets based on the key's hash.

------------------------------------------------------------------------

# PART 20 --- HASHMAP GET PROCESS

## 48. `get(key)`

Conceptually:

``` text
get(key)
   ↓
hash key
   ↓
calculate bucket
   ↓
search bucket
   ↓
compare keys
   ↓
return value
```

Key comparison uses the Map's key equality rules.

------------------------------------------------------------------------

# PART 21 --- HASHMAP PUT PROCESS

## 49. `put(key, value)`

Conceptually:

``` text
put()
 ↓
hash key
 ↓
find bucket
 ↓
bucket empty?
 ├── yes → insert
 └── no  → compare existing keys
             ↓
          same key?
          ├── yes → replace value
          └── no  → collision handling
```

------------------------------------------------------------------------

# PART 22 --- HASH COLLISION

## 50. Collision

Two different keys can map to the same bucket.

``` text
Key A → bucket 5
Key B → bucket 5
```

This is a collision.

It does not mean:

``` text
A.equals(B)
```

is true.

------------------------------------------------------------------------

## 51. Collision Handling

Modern Java HashMap implementations can use:

``` text
linked nodes
```

and under appropriate conditions:

``` text
tree bins
```

to improve behavior for heavily collided buckets.

The exact thresholds and internal representation are implementation
details and can vary by JDK.

------------------------------------------------------------------------

# PART 23 --- HASHMAP COMPLEXITY

## 52. Typical Complexity

Average expected behavior:

  Operation             Complexity
  ------------------- ------------
  `put()`                     O(1)
  `get()`                     O(1)
  `remove()`                  O(1)
  `containsKey()`             O(1)
  `containsValue()`           O(n)
  iteration                   O(n)

Worst-case behavior depends on collisions and implementation details.

------------------------------------------------------------------------

# PART 24 --- HASHMAP NULL

## 53. Null Key

HashMap permits one null key.

``` java
map.put(null, "value");
```

------------------------------------------------------------------------

## 54. Null Values

Multiple keys can map to null:

``` java
map.put(1, null);
map.put(2, null);
```

Valid.

------------------------------------------------------------------------

## 55. Important Ambiguity

``` java
map.get(key)
```

returns `null` when:

``` text
key is absent
```

but it can also return `null` when:

``` text
key exists with null value
```

Use:

``` java
containsKey(key)
```

when this distinction matters.

------------------------------------------------------------------------

# PART 25 --- HASHMAP CAPACITY

## 56. Initial Capacity

``` java
HashMap<Integer, String> map =
    new HashMap<>(100);
```

The constructor provides an initial-capacity hint.

------------------------------------------------------------------------

## 57. Load Factor

HashMap also has a load factor.

Common default:

``` text
0.75
```

Conceptually:

``` text
threshold ≈ capacity × load factor
```

When the threshold is reached, the table is resized.

The exact resizing behavior is implementation-specific.

------------------------------------------------------------------------

# PART 26 --- HASHMAP RESIZING

## 58. Why Resize?

Suppose a table becomes too full:

``` text
[A][B][C][D][E][F]
```

A larger table is created.

Mappings are redistributed according to the new table size.

Resizing can be expensive at the resize event, but normal operations are
expected to be efficient over time.

------------------------------------------------------------------------

# PART 27 --- HASHMAP TREEIFICATION

## 59. Tree Bins

Modern Java HashMap can convert a heavily collided bucket into a tree
structure under appropriate conditions.

Conceptually:

``` text
bucket
  ↓
tree
 ├── key A
 ├── key B
 └── key C
```

This helps avoid pathological long linked chains in sufficiently large
tables.

Do not code against the exact internal threshold values.

------------------------------------------------------------------------

# PART 28 --- LINKEDHASHMAP

## 60. What Is LinkedHashMap?

`LinkedHashMap` extends HashMap behavior with predictable iteration
order.

Package:

``` java
java.util.LinkedHashMap
```

Characteristics:

``` text
Hash-based lookup
Unique keys
Predictable insertion-order iteration by default
Optional access-order mode
Allows one null key
Allows null values
Not thread-safe
```

------------------------------------------------------------------------

# PART 29 --- LINKEDHASHMAP INSERTION ORDER

## 61. Example

``` java
Map<Integer, String> map =
    new LinkedHashMap<>();

map.put(3, "C");
map.put(1, "A");
map.put(2, "B");
```

Iteration:

``` text
3 → C
1 → A
2 → B
```

The iteration follows insertion order.

------------------------------------------------------------------------

# PART 30 --- LINKEDHASHMAP ACCESS ORDER

## 62. Access-Order Constructor

``` java
LinkedHashMap<Integer, String> map =
    new LinkedHashMap<>(
        16,
        0.75f,
        true
    );
```

The third argument:

``` text
true
```

enables access-order behavior.

Accessing an entry can move it toward the end of the linked ordering.

------------------------------------------------------------------------

# PART 31 --- LRU CACHE

## 63. LinkedHashMap and LRU

`LinkedHashMap` can be used to build a simple LRU-style cache.

Example:

``` java
LinkedHashMap<Integer, String> cache =
    new LinkedHashMap<>(
        16,
        0.75f,
        true
    );
```

Override:

``` java
protected boolean removeEldestEntry(
    Map.Entry<Integer, String> eldest
) {
    return size() > 100;
}
```

This allows the oldest entry according to the chosen ordering policy to
be removed automatically.

------------------------------------------------------------------------

# PART 32 --- TREEMAP

## 64. What Is TreeMap?

`TreeMap` is a sorted Map implementation.

Package:

``` java
java.util.TreeMap
```

Hierarchy:

``` text
Map
 ↓
SortedMap
 ↓
NavigableMap
 ↓
TreeMap
```

------------------------------------------------------------------------

## 65. TreeMap Example

``` java
Map<Integer, String> map =
    new TreeMap<>();

map.put(30, "C");
map.put(10, "A");
map.put(20, "B");
```

Iteration:

``` text
10 → A
20 → B
30 → C
```

Keys are sorted.

------------------------------------------------------------------------

# PART 33 --- TREEMAP INTERNAL STRUCTURE

## 66. Red-Black Tree

Modern Java TreeMap is based on a Red-Black tree.

Conceptually:

``` text
          20
         /  \
       10    30
```

The tree remains approximately balanced.

------------------------------------------------------------------------

# PART 34 --- TREEMAP COMPLEXITY

## 67. Complexity

  Operation           Complexity
  ----------------- ------------
  `put()`               O(log n)
  `get()`               O(log n)
  `remove()`            O(log n)
  `containsKey()`       O(log n)
  `firstKey()`          O(log n)
  `lastKey()`           O(log n)
  iteration                 O(n)

------------------------------------------------------------------------

# PART 35 --- SORTEDMAP

## 68. SortedMap

`SortedMap` provides key-ordering operations.

Important methods:

``` java
comparator()
firstKey()
lastKey()

headMap()
tailMap()
subMap()
```

------------------------------------------------------------------------

# PART 36 --- NAVIGABLEMAP

## 69. NavigableMap

`NavigableMap` extends `SortedMap`.

Important methods:

``` java
lowerKey()
floorKey()
ceilingKey()
higherKey()

lowerEntry()
floorEntry()
ceilingEntry()
higherEntry()

firstEntry()
lastEntry()

pollFirstEntry()
pollLastEntry()

descendingMap()
navigableKeySet()
descendingKeySet()
```

------------------------------------------------------------------------

# PART 37 --- TREEMAP NAVIGATION

## 70. `lowerKey()`

``` java
map.lowerKey(20);
```

Returns greatest key strictly less than `20`.

------------------------------------------------------------------------

## 71. `floorKey()`

``` java
map.floorKey(20);
```

Returns greatest key less than or equal to `20`.

------------------------------------------------------------------------

## 72. `ceilingKey()`

``` java
map.ceilingKey(20);
```

Returns smallest key greater than or equal to `20`.

------------------------------------------------------------------------

## 73. `higherKey()`

``` java
map.higherKey(20);
```

Returns smallest key strictly greater than `20`.

Memory:

``` text
lower   → <
floor   → <=
ceiling → >=
higher  → >
```

------------------------------------------------------------------------

# PART 38 --- TREEMAP ENTRY NAVIGATION

## 74. Entry Versions

You can retrieve the entire mapping:

``` java
map.floorEntry(20);
map.ceilingEntry(20);
map.lowerEntry(20);
map.higherEntry(20);
```

Instead of retrieving only the key.

------------------------------------------------------------------------

# PART 39 --- TREEMAP FIRST/LAST

## 75. `firstKey()`

``` java
map.firstKey();
```

Returns smallest key.

------------------------------------------------------------------------

## 76. `lastKey()`

``` java
map.lastKey();
```

Returns largest key.

------------------------------------------------------------------------

## 77. `firstEntry()` / `lastEntry()`

``` java
map.firstEntry();
map.lastEntry();
```

Return complete Map entries.

------------------------------------------------------------------------

# PART 40 --- TREEMAP POLLING

## 78. `pollFirstEntry()`

``` java
Map.Entry<Integer, String> entry =
    map.pollFirstEntry();
```

Removes and returns the first mapping.

------------------------------------------------------------------------

## 79. `pollLastEntry()`

``` java
Map.Entry<Integer, String> entry =
    map.pollLastEntry();
```

Removes and returns the last mapping.

------------------------------------------------------------------------

# PART 41 --- TREEMAP RANGE VIEWS

## 80. `headMap()`

``` java
SortedMap<Integer, String> result =
    map.headMap(30);
```

Returns keys below `30` by default.

------------------------------------------------------------------------

## 81. `tailMap()`

``` java
SortedMap<Integer, String> result =
    map.tailMap(20);
```

Returns keys from `20` onward according to the `SortedMap` contract.

------------------------------------------------------------------------

## 82. `subMap()`

``` java
SortedMap<Integer, String> result =
    map.subMap(10, 30);
```

Classic form represents:

``` text
10 <= key < 30
```

NavigableMap provides explicit inclusivity controls.

------------------------------------------------------------------------

# PART 42 --- MAP VIEWS

## 83. Range Views Are Views

Methods such as:

``` java
headMap()
tailMap()
subMap()
```

typically return backed views.

Conceptually:

``` text
Original TreeMap
      ↕
Range View
```

Changes can be reflected in the original Map and vice versa.

------------------------------------------------------------------------

# PART 43 --- DESCENDING MAP

## 84. `descendingMap()`

``` java
NavigableMap<Integer, String> reverse =
    treeMap.descendingMap();
```

If original keys:

``` text
10 20 30
```

the view presents:

``` text
30 20 10
```

------------------------------------------------------------------------

# PART 44 --- HASHTABLE

## 85. What Is Hashtable?

`Hashtable` is a legacy Map implementation.

Package:

``` java
java.util.Hashtable
```

Characteristics historically include:

``` text
Synchronized methods
No null key
No null values
Hash-based
Legacy API
```

------------------------------------------------------------------------

## 86. Hashtable Null

This is invalid:

``` java
Hashtable<Integer, String> table =
    new Hashtable<>();

table.put(null, "A");
```

Null keys and null values are not permitted.

------------------------------------------------------------------------

# PART 45 --- HASHMAP VS HASHTABLE

## 87. Comparison

  -----------------------------------------------------------------------
  Feature                 HashMap                 Hashtable
  ----------------------- ----------------------- -----------------------
  Thread-safe             No                      Synchronized/legacy

  Null key                One                     No

  Null values             Yes                     No

  Modern choice           Yes                     Usually no

  Performance under       Use concurrent          Coarse synchronization
  concurrency             collections             

  Legacy                  No                      Yes
  -----------------------------------------------------------------------

For modern concurrent applications, prefer appropriate classes from
`java.util.concurrent`, such as `ConcurrentHashMap`.

------------------------------------------------------------------------

# PART 46 --- CONCURRENTMAP

## 88. ConcurrentMap

Package:

``` java
java.util.concurrent.ConcurrentMap
```

It extends:

``` java
Map
```

and provides concurrency-oriented atomic operations.

Examples:

``` java
putIfAbsent()
remove(key, value)
replace()
replace(key, oldValue, newValue)
```

------------------------------------------------------------------------

# PART 47 --- CONCURRENTHASHMAP

## 89. What Is ConcurrentHashMap?

`ConcurrentHashMap` is a thread-safe, high-concurrency Map
implementation.

Package:

``` java
java.util.concurrent.ConcurrentHashMap
```

Characteristics:

``` text
Thread-safe
High concurrency
Hash-based
No null keys
No null values
Weakly consistent iteration
Atomic compound operations
```

------------------------------------------------------------------------

# PART 48 --- CONCURRENTHASHMAP BASIC

## 90. Example

``` java
ConcurrentHashMap<String, Integer> map =
    new ConcurrentHashMap<>();

map.put("Java", 10);
map.put("Spring", 20);
```

------------------------------------------------------------------------

# PART 49 --- CONCURRENTHASHMAP NULL

## 91. Null Is Not Allowed

This is invalid:

``` java
map.put(null, 10);
```

and:

``` java
map.put("Java", null);
```

Both are rejected.

A major reason is that `null` cannot safely represent both:

``` text
absence
```

and:

``` text
present mapping with null value
```

in the concurrent APIs.

------------------------------------------------------------------------

# PART 50 --- CONCURRENTHASHMAP ATOMIC METHODS

## 92. `putIfAbsent()`

``` java
map.putIfAbsent(
    "Java",
    1
);
```

The operation is atomic with respect to the concurrent Map.

------------------------------------------------------------------------

## 93. `computeIfAbsent()`

``` java
map.computeIfAbsent(
    "Java",
    key -> 1
);
```

Very useful for concurrent initialization.

------------------------------------------------------------------------

## 94. `merge()`

``` java
map.merge(
    "Java",
    1,
    Integer::sum
);
```

Useful for concurrent counters.

------------------------------------------------------------------------

# PART 51 --- CONCURRENT COUNTER

## 95. Example

``` java
ConcurrentHashMap<String, Integer> counts =
    new ConcurrentHashMap<>();

for (String word : words) {

    counts.merge(
        word,
        1,
        Integer::sum
    );
}
```

The Map coordinates updates atomically for each key.

For extremely high-frequency counters, specialized structures such as
`LongAdder` may be more scalable than repeatedly replacing `Integer`
values.

------------------------------------------------------------------------

# PART 52 --- CONCURRENT ITERATION

## 96. Weakly Consistent Iterator

ConcurrentHashMap iterators are generally weakly consistent.

They:

-   Do not throw `ConcurrentModificationException` merely because
    concurrent updates occur
-   May reflect some updates made after iterator creation
-   Do not provide a frozen snapshot

------------------------------------------------------------------------

# PART 53 --- CONCURRENT MAP VIEWS

## 97. Key Set

``` java
Set<String> keys =
    map.keySet();
```

For `ConcurrentHashMap`, the views are designed for concurrent use
according to its API contract.

------------------------------------------------------------------------

## 98. Key Set From Map

You can also create a concurrent Set:

``` java
Set<String> set =
    ConcurrentHashMap.newKeySet();
```

------------------------------------------------------------------------

# PART 54 --- WEAKHASHMAP

## 99. What Is WeakHashMap?

`WeakHashMap` uses weak references for its keys.

Package:

``` java
java.util.WeakHashMap
```

Concept:

``` text
Key no longer strongly reachable
        ↓
eligible for garbage collection
        ↓
mapping can disappear
```

------------------------------------------------------------------------

## 100. Why Use WeakHashMap?

Useful when Map entries should not keep keys alive forever.

Potential use cases:

-   Metadata associated with objects
-   Caches with object-lifetime semantics
-   Auxiliary mappings

It is not a general-purpose cache replacement.

------------------------------------------------------------------------

# PART 55 --- WEAKHASHMAP EXAMPLE

## 101. Example

``` java
Map<Object, String> map =
    new WeakHashMap<>();

Object key = new Object();

map.put(key, "data");
```

As long as:

``` text
key
```

is strongly reachable elsewhere, the mapping can remain.

Once no strong references to the key remain, the mapping may eventually
disappear after garbage collection.

------------------------------------------------------------------------

# PART 56 --- WEAKHASHMAP WARNING

## 102. Important

Garbage collection is nondeterministic.

Do not write logic that depends on exactly when a WeakHashMap entry
disappears.

It is a memory-management-oriented collection, not a normal expiration
mechanism.

------------------------------------------------------------------------

# PART 57 --- IDENTITYHASHMAP

## 103. What Is IdentityHashMap?

`IdentityHashMap` compares keys using reference identity:

``` java
==
```

instead of normal logical equality:

``` java
equals()
```

Package:

``` java
java.util.IdentityHashMap
```

------------------------------------------------------------------------

## 104. Example

``` java
String a = new String("Java");
String b = new String("Java");

System.out.println(
    a.equals(b)
);
```

Output:

``` text
true
```

But:

``` java
a == b
```

is normally:

``` text
false
```

IdentityHashMap distinguishes them by reference identity.

------------------------------------------------------------------------

# PART 58 --- IDENTITYHASHMAP USE CASE

## 105. Identity-Based Tracking

Useful when object identity matters rather than logical value equality.

Potential uses include:

-   Object graph processing
-   Identity-sensitive algorithms
-   Serialization/cycle tracking
-   Framework internals

It should not be used as a normal replacement for HashMap.

------------------------------------------------------------------------

# PART 59 --- ENUMMAP

## 106. What Is EnumMap?

`EnumMap` is a specialized Map whose keys must be enum constants.

Example:

``` java
enum Day {
    MONDAY,
    TUESDAY,
    WEDNESDAY
}

EnumMap<Day, String> schedule =
    new EnumMap<>(Day.class);
```

------------------------------------------------------------------------

# PART 60 --- ENUMMAP ADVANTAGES

## 107. Characteristics

EnumMap:

``` text
Enum-only keys
Very compact
Fast
Predictable enum-order iteration
No null keys
Null values allowed
Not thread-safe
```

It is usually preferable to HashMap when the key domain is an enum.

------------------------------------------------------------------------

# PART 61 --- ENUMMAP EXAMPLE

## 108. Example

``` java
EnumMap<Day, String> schedule =
    new EnumMap<>(Day.class);

schedule.put(
    Day.MONDAY,
    "Java"
);

schedule.put(
    Day.TUESDAY,
    "Spring"
);
```

Iteration follows enum declaration order.

------------------------------------------------------------------------

# PART 62 --- IMMUTABLE MAPS

## 109. `Map.of()`

Java provides immutable/unmodifiable Map factory methods.

``` java
Map<Integer, String> map =
    Map.of(
        1, "A",
        2, "B"
    );
```

The returned Map cannot be modified.

------------------------------------------------------------------------

## 110. Duplicate Keys

This is invalid:

``` java
Map.of(
    1, "A",
    1, "B"
);
```

It throws:

``` text
IllegalArgumentException
```

------------------------------------------------------------------------

## 111. Null Keys and Values

`Map.of()` does not allow null keys or null values.

``` java
Map.of(
    1, null
);
```

throws:

``` text
NullPointerException
```

------------------------------------------------------------------------

# PART 63 --- MAP.OFENTRIES

## 112. `Map.ofEntries()`

For larger literal Maps:

``` java
Map<Integer, String> map =
    Map.ofEntries(
        Map.entry(1, "A"),
        Map.entry(2, "B"),
        Map.entry(3, "C")
    );
```

------------------------------------------------------------------------

# PART 64 --- MAP.COPYOF

## 113. `Map.copyOf()`

``` java
Map<Integer, String> copy =
    Map.copyOf(original);
```

The result is unmodifiable.

It rejects null keys/values.

------------------------------------------------------------------------

# PART 65 --- UNMODIFIABLE MAP

## 114. `Collections.unmodifiableMap()`

``` java
Map<Integer, String> view =
    Collections.unmodifiableMap(
        original
    );
```

The returned reference cannot be used to modify the Map.

But the original Map can still change.

Therefore:

``` text
unmodifiable view
≠
independent immutable snapshot
```

------------------------------------------------------------------------

# PART 66 --- IMMUTABLE VS UNMODIFIABLE

## 115. Difference

### Unmodifiable view

``` java
Collections.unmodifiableMap(original);
```

Concept:

``` text
Original Map
     ↑
     |
Unmodifiable View
```

### Copy

``` java
Map.copyOf(original);
```

Returns an unmodifiable Map based on the source contents.

------------------------------------------------------------------------

# PART 67 --- MAP EQUALITY

## 116. Map `equals()`

Two Maps are equal if they contain the same mappings.

Order generally does not determine Map equality.

Example:

``` java
Map<Integer, String> a =
    Map.of(
        1, "A",
        2, "B"
    );

Map<Integer, String> b =
    Map.of(
        2, "B",
        1, "A"
    );

System.out.println(
    a.equals(b)
);
```

Result:

``` text
true
```

------------------------------------------------------------------------

# PART 68 --- MAP HASHCODE

## 117. Map Hash Code

A Map's hash code is based on its mappings.

Two equal Maps should have equal hash codes.

This allows Maps to behave correctly when used in hash-based structures.

------------------------------------------------------------------------

# PART 69 --- MUTABLE MAP KEYS

## 118. Dangerous Mutable Key

Suppose:

``` java
class User {
    int id;

    @Override
    public int hashCode() {
        return Integer.hashCode(id);
    }
}
```

If:

``` java
map.put(user, "data");
```

and later:

``` java
user.id = 999;
```

the key's hash identity changed.

Now:

``` java
map.get(user)
```

may fail to locate the original mapping.

------------------------------------------------------------------------

## 119. Best Practice

Map keys should generally be:

``` text
immutable
or
effectively immutable
```

Examples:

``` text
String
Integer
Long
UUID
Enum
record
immutable value objects
```

------------------------------------------------------------------------

# PART 70 --- TREE MAP KEY MUTABILITY

## 120. TreeMap Keys

For TreeMap, the key's ordering must remain stable.

Do not modify fields used by:

``` java
compareTo()
```

or:

``` java
Comparator
```

while the key is stored in the TreeMap.

Otherwise the tree can become logically inconsistent with the current
key ordering.

------------------------------------------------------------------------

# PART 71 --- MAP KEY NULL SUMMARY

## 121. Null Keys

  Map                 Null key
  ------------------- ------------------------------------
  HashMap             One
  LinkedHashMap       One
  TreeMap             Generally no with natural ordering
  Hashtable           No
  ConcurrentHashMap   No
  WeakHashMap         Yes
  IdentityHashMap     Yes
  EnumMap             No
  `Map.of()`          No
  `Map.copyOf()`      No

------------------------------------------------------------------------

# PART 72 --- MAP VALUE NULL SUMMARY

## 122. Null Values

  Map                 Null values
  ------------------- ---------------------------------------------------
  HashMap             Yes
  LinkedHashMap       Yes
  TreeMap             Generally yes, subject to API/operation semantics
  Hashtable           No
  ConcurrentHashMap   No
  WeakHashMap         Yes
  IdentityHashMap     Yes
  EnumMap             Yes
  `Map.of()`          No
  `Map.copyOf()`      No

------------------------------------------------------------------------

# PART 73 --- MAP ORDERING

## 123. HashMap

``` text
No guaranteed iteration order
```

------------------------------------------------------------------------

## 124. LinkedHashMap

``` text
Insertion order by default
```

or:

``` text
Access order
```

when configured.

------------------------------------------------------------------------

## 125. TreeMap

``` text
Sorted by key
```

------------------------------------------------------------------------

## 126. EnumMap

``` text
Enum declaration order
```

------------------------------------------------------------------------

# PART 74 --- HASHMAP VS LINKEDHASHMAP

## 127. Comparison

  Feature       HashMap           LinkedHashMap
  ------------- ----------------- ------------------------
  Key-value     Yes               Yes
  Unique keys   Yes               Yes
  Hash-based    Yes               Yes
  Order         None guaranteed   Insertion/access order
  Null key      One               One
  Null values   Yes               Yes
  Thread-safe   No                No
  Memory        Lower             Higher

------------------------------------------------------------------------

# PART 75 --- HASHMAP VS TREEMAP

## 128. Comparison

  Feature         HashMap           TreeMap
  --------------- ----------------- ------------------------------------
  Ordering        None guaranteed   Sorted keys
  Average get     O(1)              O(log n)
  Add             O(1) avg          O(log n)
  Remove          O(1) avg          O(log n)
  Range queries   No                Yes
  Navigation      No                Yes
  Null key        One               Generally no with natural ordering
  Internal        Hash table        Red-Black tree

------------------------------------------------------------------------

# PART 76 --- LINKEDHASHMAP VS TREEMAP

## 129. Comparison

  Feature            LinkedHashMap      TreeMap
  ------------------ ------------------ ------------------------------------
  Order              Insertion/access   Sorted
  Lookup             O(1) avg           O(log n)
  Range operations   No                 Yes
  Null key           One                Generally no with natural ordering
  Memory             Hash + links       Tree nodes

------------------------------------------------------------------------

# PART 77 --- HASHMAP VS CONCURRENTHASHMAP

## 130. Comparison

  Feature                 HashMap                      ConcurrentHashMap
  ----------------------- ---------------------------- -------------------------
  Thread-safe             No                           Yes
  Null key                Yes                          No
  Null value              Yes                          No
  Concurrent operations   No                           Yes
  Iterator                Fail-fast best-effort        Weakly consistent
  Atomic compute/merge    Map defaults                 Concurrent semantics
  Main use                Normal single-threaded use   Concurrent applications

------------------------------------------------------------------------

# PART 78 --- MAP AND SET RELATIONSHIP

## 131. Set From Map

A useful conceptual relationship:

``` text
HashSet
   ↓
HashMap-like storage

TreeSet
   ↓
TreeMap-like storage
```

The Set uses unique elements where a Map uses keys.

------------------------------------------------------------------------

# PART 79 --- MAP AND COLLECTION VIEWS

## 132. Why `keySet()` Returns Set

Keys are unique.

Therefore:

``` java
map.keySet()
```

is naturally represented as:

``` java
Set<K>
```

------------------------------------------------------------------------

## 133. Why `values()` Returns Collection

Values can repeat.

Therefore:

``` java
map.values()
```

is:

``` java
Collection<V>
```

not:

``` java
Set<V>
```

------------------------------------------------------------------------

## 134. Why `entrySet()` Returns Set

Each key-value mapping is unique by key.

Therefore entries are represented as:

``` java
Set<Map.Entry<K,V>>
```

------------------------------------------------------------------------

# PART 80 --- VIEW BEHAVIOR

## 135. Map Views Are Usually Backed

For normal mutable Maps:

``` java
map.keySet()
map.values()
map.entrySet()
```

are backed views.

Changing the Map affects the view.

Certain supported modifications through the views affect the Map.

------------------------------------------------------------------------

# PART 81 --- REMOVING THROUGH KEYSET

## 136. Example

``` java
Set<Integer> keys =
    map.keySet();

keys.remove(101);
```

For a modifiable Map, this can remove the corresponding mapping from the
Map.

------------------------------------------------------------------------

# PART 82 --- CLEARING VALUES VIEW

## 137. Example

``` java
map.values().clear();
```

For a modifiable Map, clearing the values view removes mappings from the
underlying Map.

This is why these are called views rather than independent collections.

------------------------------------------------------------------------

# PART 83 --- MAP ENTRY SETVALUE

## 138. Update Through Entry

``` java
for (Map.Entry<Integer, String> entry :
        map.entrySet()) {

    entry.setValue(
        entry.getValue().toUpperCase()
    );
}
```

For supported mutable Map implementations, this updates the underlying
mapping.

------------------------------------------------------------------------

# PART 84 --- FAIL-FAST MAP ITERATION

## 139. Structural Modification

This can cause:

``` text
ConcurrentModificationException
```

for ordinary Maps:

``` java
for (Integer key : map.keySet()) {
    map.remove(key);
}
```

Use an iterator or suitable Map methods instead.

------------------------------------------------------------------------

# PART 85 --- REMOVE DURING ITERATION

## 140. Correct Pattern

``` java
Iterator<Integer> iterator =
    map.keySet().iterator();

while (iterator.hasNext()) {

    Integer key =
        iterator.next();

    if (key == 10) {
        iterator.remove();
    }
}
```

------------------------------------------------------------------------

# PART 86 --- REMOVEIF

## 141. Modern Pattern

``` java
map.entrySet().removeIf(
    entry -> entry.getValue() == null
);
```

This is often cleaner than manual iteration for supported mutable Maps.

------------------------------------------------------------------------

# PART 87 --- SORTING MAP DATA

## 142. Sort by Key

TreeMap naturally maintains sorted keys:

``` java
Map<Integer, String> sorted =
    new TreeMap<>(map);
```

------------------------------------------------------------------------

## 143. Sort by Value

Maps are not inherently value-sorted.

One approach:

``` java
List<Map.Entry<Integer, String>> entries =
    new ArrayList<>(
        map.entrySet()
    );

entries.sort(
    Map.Entry.comparingByValue()
);
```

------------------------------------------------------------------------

## 144. Sort Entries With Comparator

``` java
entries.sort(
    Map.Entry
        .comparingByValue()
        .thenComparing(
            Map.Entry.comparingByKey()
        )
);
```

------------------------------------------------------------------------

# PART 88 --- STREAM MAP SORTING

## 145. Sort by Value

``` java
Map<Integer, String> result =
    map.entrySet()
       .stream()
       .sorted(
           Map.Entry.comparingByValue()
       )
       .collect(
           LinkedHashMap::new,
           (m, e) ->
               m.put(
                   e.getKey(),
                   e.getValue()
               ),
           LinkedHashMap::putAll
       );
```

A `LinkedHashMap` can preserve the sorted encounter order of the stream.

------------------------------------------------------------------------

# PART 89 --- GROUPING WITH MAP

## 146. Group Data

Example:

``` java
Map<String, List<Employee>> employeesByDept =
    employees.stream()
        .collect(
            Collectors.groupingBy(
                Employee::getDepartment
            )
        );
```

Concept:

``` text
Department
   ↓
List<Employee>
```

This is one of the most common Map patterns in Java backend code.

------------------------------------------------------------------------

# PART 90 --- COUNTING WITH MAP

## 147. Frequency Map

``` java
Map<String, Integer> count =
    new HashMap<>();

for (String word : words) {
    count.merge(
        word,
        1,
        Integer::sum
    );
}
```

------------------------------------------------------------------------

# PART 91 --- MAP OF LIST

## 148. One-to-Many Relationship

``` java
Map<String, List<String>> map =
    new HashMap<>();
```

Use:

``` java
map.computeIfAbsent(
    "Java",
    key -> new ArrayList<>()
).add("Collections");
```

Result conceptually:

``` text
Java
 ├── Collections
 ├── Streams
 └── Generics
```

------------------------------------------------------------------------

# PART 92 --- MAP OF SET

## 149. Unique Grouped Values

``` java
Map<String, Set<String>> map =
    new HashMap<>();
```

Useful when each group must contain unique values.

``` java
map.computeIfAbsent(
    department,
    key -> new HashSet<>()
).add(employeeName);
```

------------------------------------------------------------------------

# PART 93 --- MAP OF MAP

## 150. Nested Map

``` java
Map<String, Map<String, Integer>> data =
    new HashMap<>();
```

Concept:

``` text
Country
  ↓
State
  ↓
Population
```

Nested Maps are useful but can become difficult to maintain; domain
classes may be clearer for complex models.

------------------------------------------------------------------------

# PART 94 --- MAP FOR CACHING

## 151. Simple Cache

``` java
Map<String, User> cache =
    new HashMap<>();
```

Lookup:

``` java
User user =
    cache.get(id);
```

For concurrent applications use an appropriate concurrent cache/data
structure.

A plain HashMap is not a general-purpose thread-safe cache.

------------------------------------------------------------------------

# PART 95 --- MAP FOR CONFIGURATION

## 152. Configuration Map

``` java
Map<String, String> config =
    new HashMap<>();

config.put(
    "environment",
    "production"
);

config.put(
    "timeout",
    "30"
);
```

For fixed configuration constants, immutable Maps can be useful:

``` java
Map<String, String> config =
    Map.of(
        "environment",
        "production",
        "timeout",
        "30"
    );
```

------------------------------------------------------------------------

# PART 96 --- MAP FOR LOOKUP TABLE

## 153. Lookup Table

Instead of:

``` text
if code == 1
if code == 2
if code == 3
```

use:

``` java
Map<Integer, String> status =
    Map.of(
        1, "SUCCESS",
        2, "FAILED",
        3, "PENDING"
    );
```

Then:

``` java
String result =
    status.get(code);
```

------------------------------------------------------------------------

# PART 97 --- MAP IN DSA

## 154. Common DSA Problems

Map is commonly used for:

-   Frequency counting
-   Two Sum
-   Group Anagrams
-   Prefix Sum
-   Subarray Sum
-   Memoization
-   Coordinate compression
-   Graph adjacency
-   Caching
-   Duplicate detection
-   Character mapping
-   Index lookup

------------------------------------------------------------------------

# PART 98 --- TWO SUM

## 155. Two Sum Pattern

``` java
Map<Integer, Integer> seen =
    new HashMap<>();

for (int i = 0; i < nums.length; i++) {

    int complement =
        target - nums[i];

    if (seen.containsKey(complement)) {
        return new int[] {
            seen.get(complement),
            i
        };
    }

    seen.put(
        nums[i],
        i
    );
}
```

Typical average complexity:

``` text
O(n)
```

------------------------------------------------------------------------

# PART 99 --- PREFIX SUM

## 156. Prefix Sum Map

A Map can store:

``` text
prefix sum → frequency/index
```

Useful for:

``` text
Subarray sum
Subarray count
Longest subarray
```

------------------------------------------------------------------------

# PART 100 --- GRAPH ADJACENCY MAP

## 157. Adjacency List

``` java
Map<Integer, List<Integer>> graph =
    new HashMap<>();
```

Concept:

``` text
1 → [2, 3]
2 → [4]
3 → [4, 5]
```

------------------------------------------------------------------------

# PART 101 --- MEMOIZATION

## 158. Cache Computed Results

``` java
Map<Integer, Long> memo =
    new HashMap<>();

long solve(int n) {

    if (memo.containsKey(n)) {
        return memo.get(n);
    }

    long result = ...;

    memo.put(n, result);

    return result;
}
```

Map stores previously computed results.

------------------------------------------------------------------------

# PART 102 --- ID → OBJECT LOOKUP

## 159. Backend Pattern

``` java
Map<Long, Employee> employeesById =
    new HashMap<>();
```

Then:

``` java
Employee employee =
    employeesById.get(employeeId);
```

This is a common in-memory lookup pattern.

------------------------------------------------------------------------

# PART 103 --- MAP AND DATABASE

## 160. Map vs Database

Map:

``` text
In-memory
Fast local lookup
Usually process-local
```

Database:

``` text
Persistent
Shared
Durable
Queryable
```

A Map is not a replacement for a database.

------------------------------------------------------------------------

# PART 104 --- DISTRIBUTED SYSTEMS

## 161. Local Map

If three application servers have:

``` text
Server A → HashMap
Server B → HashMap
Server C → HashMap
```

each Map is local.

Changes to A do not automatically appear in B or C.

For shared distributed state use an appropriate distributed store/cache.

------------------------------------------------------------------------

# PART 105 --- MAP AND THREAD SAFETY

## 162. Normal Maps

These are not thread-safe by default:

``` text
HashMap
LinkedHashMap
TreeMap
EnumMap
WeakHashMap
IdentityHashMap
```

Use concurrent alternatives when multiple threads modify shared state.

------------------------------------------------------------------------

# PART 106 --- SYNCHRONIZED MAP

## 163. `Collections.synchronizedMap()`

``` java
Map<Integer, String> map =
    Collections.synchronizedMap(
        new HashMap<>()
    );
```

This provides synchronized access through the wrapper.

When iterating, external synchronization is generally required according
to the wrapper's contract:

``` java
synchronized (map) {
    for (Map.Entry<Integer, String> entry :
            map.entrySet()) {

        System.out.println(entry);
    }
}
```

------------------------------------------------------------------------

# PART 107 --- SYNCHRONIZED MAP VS CONCURRENTHASHMAP

## 164. Comparison

``` text
synchronizedMap
    ↓
coarse synchronization wrapper

ConcurrentHashMap
    ↓
designed for high concurrent access
```

For high-concurrency workloads, ConcurrentHashMap is generally the more
appropriate abstraction.

------------------------------------------------------------------------

# PART 108 --- ATOMIC COMPOUND OPERATIONS

## 165. Race Condition

This pattern is not automatically atomic:

``` java
if (!map.containsKey(key)) {
    map.put(key, value);
}
```

Two threads can both observe absence.

Instead:

``` java
map.putIfAbsent(
    key,
    value
);
```

provides the intended atomic Map operation where supported.

------------------------------------------------------------------------

# PART 109 --- COMPUTE ATOMICITY

## 166. Concurrent `computeIfAbsent()`

For ConcurrentHashMap:

``` java
map.computeIfAbsent(
    key,
    k -> createValue(k)
);
```

is designed as a concurrent Map operation.

Be careful that mapping functions should be short and should not
recursively update the same Map in unsupported ways.

------------------------------------------------------------------------

# PART 110 --- MAP MERGE

## 167. Why `merge()` Is Useful

Instead of:

``` java
if (map.containsKey(word)) {
    map.put(
        word,
        map.get(word) + 1
    );
} else {
    map.put(word, 1);
}
```

use:

``` java
map.merge(
    word,
    1,
    Integer::sum
);
```

This is shorter and expresses the intended operation directly.

------------------------------------------------------------------------

# PART 111 --- MERGE REMOVAL RULE

## 168. Important `merge()` Rule

If the remapping function returns:

``` text
null
```

the mapping can be removed.

Example:

``` java
map.merge(
    key,
    value,
    (oldValue, newValue) -> null
);
```

This removes the mapping when the key exists.

This behavior is important when designing merge functions.

------------------------------------------------------------------------

# PART 112 --- COMPUTE REMOVAL RULE

## 169. `compute()` and Null

For Map implementations that allow null semantics, if the remapping
function returns `null`, the mapping may be removed.

For `ConcurrentHashMap`, null values are not allowed, so returning null
from a compute/remapping function has removal semantics rather than
creating a null mapping.

------------------------------------------------------------------------

# PART 113 --- MAP API MASTER LIST

## 170. Core

``` java
put()
get()
remove()

containsKey()
containsValue()

size()
isEmpty()
clear()
```

------------------------------------------------------------------------

## 171. Conditional

``` java
putIfAbsent()

remove(key, value)

replace(key, value)

replace(key, oldValue, newValue)

replaceAll()
```

------------------------------------------------------------------------

## 172. Defaulting

``` java
getOrDefault()
```

------------------------------------------------------------------------

## 173. Computation

``` java
compute()
computeIfAbsent()
computeIfPresent()
merge()
```

------------------------------------------------------------------------

## 174. Views

``` java
keySet()
values()
entrySet()
```

------------------------------------------------------------------------

## 175. Traversal

``` java
forEach()
```

------------------------------------------------------------------------

# PART 114 --- SORTEDMAP API

## 176. SortedMap

``` java
comparator()
firstKey()
lastKey()

headMap()
tailMap()
subMap()
```

------------------------------------------------------------------------

# PART 115 --- NAVIGABLEMAP API

## 177. NavigableMap

``` java
lowerKey()
floorKey()
ceilingKey()
higherKey()

lowerEntry()
floorEntry()
ceilingEntry()
higherEntry()

firstEntry()
lastEntry()

pollFirstEntry()
pollLastEntry()

descendingMap()
navigableKeySet()
descendingKeySet()
```

------------------------------------------------------------------------

# PART 116 --- MAP FACTORY METHODS

## 178. Java Immutable Factory APIs

``` java
Map.of()
Map.ofEntries()
Map.entry()
Map.copyOf()
```

These are useful for immutable/unmodifiable Map creation.

------------------------------------------------------------------------

# PART 117 --- MAP ENTRY FACTORY

## 179. `Map.entry()`

``` java
Map.Entry<String, Integer> entry =
    Map.entry(
        "Java",
        100
    );
```

Commonly used with:

``` java
Map.ofEntries()
```

------------------------------------------------------------------------

# PART 118 --- MAP ORDERING AND COMPARATORS

## 180. TreeMap Comparator

``` java
TreeMap<Integer, String> map =
    new TreeMap<>(
        Comparator.reverseOrder()
    );
```

Keys are now ordered in descending order.

------------------------------------------------------------------------

## 181. Custom Key Comparator

``` java
TreeMap<String, Integer> map =
    new TreeMap<>(
        String.CASE_INSENSITIVE_ORDER
    );
```

The comparator defines key ordering and equivalence for the sorted Map.

------------------------------------------------------------------------

# PART 119 --- COMPARATOR CONSISTENCY

## 182. Important Rule

If:

``` java
compare(a, b) == 0
```

TreeMap treats the keys as equivalent for Map insertion/order purposes.

This can differ from:

``` java
a.equals(b)
```

Therefore, ideally the comparator should be consistent with equals when
that is the intended domain semantics.

------------------------------------------------------------------------

# PART 120 --- MAP WITH CUSTOM KEYS

## 183. HashMap Custom Key

``` java
record EmployeeId(
    long value
) {}
```

Then:

``` java
Map<EmployeeId, String> employees =
    new HashMap<>();
```

Records provide suitable value-based equality and hash code.

------------------------------------------------------------------------

# PART 121 --- MAP MEMORY

## 184. HashMap Memory

HashMap needs:

``` text
table
+
mapping nodes
+
key references
+
value references
```

Memory usage is more than just the key and value objects themselves.

------------------------------------------------------------------------

## 185. LinkedHashMap Memory

Adds ordering links:

``` text
previous
next
```

to support predictable iteration order.

Therefore it generally uses more memory than HashMap.

------------------------------------------------------------------------

## 186. TreeMap Memory

Uses tree nodes with:

``` text
key
value
left
right
parent
color
```

conceptually.

Therefore it has different memory characteristics from HashMap.

------------------------------------------------------------------------

# PART 122 --- CACHE LOCALITY

## 187. Hash vs Tree

HashMap:

``` text
bucket array
+
nodes
```

TreeMap:

``` text
tree nodes
```

Real performance depends on:

-   CPU cache
-   allocation
-   branch behavior
-   key comparison
-   hash calculation
-   workload
-   JVM

Big-O alone does not describe every performance characteristic.

------------------------------------------------------------------------

# PART 123 --- INITIAL CAPACITY

## 188. Pre-Sizing

If you know approximately how many entries will be inserted, pre-sizing
a HashMap can reduce resizing.

Example:

``` java
Map<Integer, String> map =
    new HashMap<>(1000);
```

Choose capacity carefully rather than blindly allocating huge tables.

------------------------------------------------------------------------

# PART 124 --- HASHMAP PERFORMANCE

## 189. Good Hash Functions

A good key's hash distribution should spread entries across buckets.

Bad distribution:

``` text
many keys → same bucket
```

can increase collision handling work.

Good distribution:

``` text
keys → spread across buckets
```

usually gives better average performance.

------------------------------------------------------------------------

# PART 125 --- MAP KEY DESIGN

## 190. Good Map Keys

Good keys are generally:

``` text
Immutable
Stable hashCode
Stable equals
Correctly implemented
```

Examples:

``` text
String
Integer
Long
UUID
Enum
record
immutable value object
```

------------------------------------------------------------------------

# PART 126 --- MAP VALUE DESIGN

## 191. Values

Values do not have to be unique.

They can be:

``` text
null
mutable
duplicate
complex objects
collections
```

depending on the Map implementation and application requirements.

------------------------------------------------------------------------

# PART 127 --- MAP OF COLLECTIONS

## 192. Common Backend Pattern

``` java
Map<Long, List<Order>> ordersByCustomer =
    new HashMap<>();
```

Or:

``` java
Map<Long, Set<String>> permissionsByUser =
    new HashMap<>();
```

Use:

``` java
computeIfAbsent()
```

to initialize collections safely and concisely.

------------------------------------------------------------------------

# PART 128 --- MAP AND STREAM COLLECTORS

## 193. `Collectors.toMap()`

Example:

``` java
Map<Long, Employee> map =
    employees.stream()
        .collect(
            Collectors.toMap(
                Employee::getId,
                employee -> employee
            )
        );
```

------------------------------------------------------------------------

## 194. Duplicate Key Problem

If two employees have the same ID, `toMap()` can throw an exception
unless a merge function is provided.

Example:

``` java
Collectors.toMap(
    Employee::getId,
    employee -> employee,
    (oldValue, newValue) ->
        newValue
)
```

------------------------------------------------------------------------

# PART 129 --- GROUPINGBY

## 195. `groupingBy()`

``` java
Map<String, List<Employee>> grouped =
    employees.stream()
        .collect(
            Collectors.groupingBy(
                Employee::getDepartment
            )
        );
```

Concept:

``` text
department
    ↓
employees
```

------------------------------------------------------------------------

# PART 130 --- PARTITIONINGBY

## 196. `partitioningBy()`

For a boolean condition:

``` java
Map<Boolean, List<Employee>> result =
    employees.stream()
        .collect(
            Collectors.partitioningBy(
                Employee::isActive
            )
        );
```

Concept:

``` text
true  → active
false → inactive
```

------------------------------------------------------------------------

# PART 131 --- MAP TO LIST

## 197. Convert Entries

``` java
List<Map.Entry<Integer, String>> list =
    new ArrayList<>(
        map.entrySet()
    );
```

Useful for custom sorting.

------------------------------------------------------------------------

# PART 132 --- MAP TO JSON CONCEPT

## 198. Backend APIs

Maps are commonly used as intermediate data structures for JSON-like
key-value data.

Example:

``` java
Map<String, Object> response =
    new HashMap<>();
```

But for strongly typed APIs, DTO/record classes are usually clearer and
safer than large `Map<String, Object>` structures.

------------------------------------------------------------------------

# PART 133 --- MAP AS REQUEST PARAMETERS

## 199. Dynamic Parameters

A Map can represent:

``` text
parameter name → value
```

Example:

``` java
Map<String, String> params =
    new HashMap<>();
```

This is useful for truly dynamic parameter sets, but typed request
objects are preferable when the schema is known.

------------------------------------------------------------------------

# PART 134 --- MAP AS CACHE KEY

## 200. Composite Key

Instead of:

``` text
userId + productId
```

you can create a value object:

``` java
record CacheKey(
    long userId,
    long productId
) {}
```

Then:

``` java
Map<CacheKey, Product> cache =
    new HashMap<>();
```

Records provide appropriate equality/hash behavior.

------------------------------------------------------------------------

# PART 135 --- IDENTITY VS EQUALITY

## 201. Normal Map

HashMap uses logical equality:

``` text
hashCode()
+
equals()
```

------------------------------------------------------------------------

## 202. IdentityHashMap

Uses identity semantics:

``` text
==
```

This is a specialized behavior and should only be used when reference
identity is intentionally part of the algorithm.

------------------------------------------------------------------------

# PART 136 --- WEAK REFERENCES

## 203. WeakHashMap Mental Model

Normal HashMap:

``` text
Map → strongly references key
```

WeakHashMap:

``` text
Map → weakly references key
```

Therefore a key can become eligible for garbage collection when no
strong references remain elsewhere.

------------------------------------------------------------------------

# PART 137 --- MAP AND GARBAGE COLLECTION

## 204. Strong Map Reference

If:

``` java
HashMap<Object, Object> map
```

contains:

``` java
map.put(key, value);
```

the Map strongly references the key and value.

The entry can therefore keep those objects reachable.

------------------------------------------------------------------------

## 205. WeakHashMap

WeakHashMap changes the key-reference behavior.

This can help avoid certain memory-retention problems, but it does not
provide general cache eviction policies.

------------------------------------------------------------------------

# PART 138 --- CONCURRENT MAP PERFORMANCE

## 206. ConcurrentHashMap

ConcurrentHashMap is designed to allow multiple threads to operate
concurrently with much less contention than a single global lock around
an ordinary HashMap.

It uses sophisticated synchronization and atomic mechanisms internally.

Exact implementation details vary across JDK versions.

------------------------------------------------------------------------

# PART 139 --- CONCURRENT MAP USE CASES

## 207. Examples

Use ConcurrentHashMap for:

-   Shared lookup tables
-   Concurrent caches
-   Counters with suitable atomic operations
-   Session-like in-memory state
-   Deduplication state
-   Concurrent registries

------------------------------------------------------------------------

# PART 140 --- MAP AND ATOMICITY

## 208. Atomic vs Thread-Safe

Important distinction:

``` text
Thread-safe Map
≠
Every multi-step sequence is automatically atomic
```

Example:

``` java
if (!map.containsKey(k)) {
    map.put(k, v);
}
```

is a multi-step sequence.

Use:

``` java
putIfAbsent()
computeIfAbsent()
merge()
```

when those operations express the required atomic behavior.

------------------------------------------------------------------------

# PART 141 --- MAP AND THREAD VISIBILITY

## 209. Memory Visibility

Concurrent Map implementations provide appropriate memory visibility
guarantees for their operations.

This matters when one thread writes:

``` text
key → value
```

and another thread reads it.

Do not attempt to reproduce these guarantees by simply using a normal
HashMap across threads without proper synchronization.

------------------------------------------------------------------------

# PART 142 --- MAP AND SYNCHRONIZATION

## 210. Manual Synchronization

You can synchronize access:

``` java
synchronized (map) {
    map.put(key, value);
}
```

But this is application-level synchronization.

For high-concurrency access, use a collection designed for the workload
when possible.

------------------------------------------------------------------------

# PART 143 --- MAP AND ORDER

## 211. Choosing Order

Ask:

``` text
Do I need order?
```

If no:

``` text
HashMap
```

If insertion order:

``` text
LinkedHashMap
```

If sorted key order:

``` text
TreeMap
```

If enum key order:

``` text
EnumMap
```

------------------------------------------------------------------------

# PART 144 --- MAP AND PERFORMANCE

## 212. Selection

``` text
Fast average lookup
→ HashMap

Predictable insertion/access order
→ LinkedHashMap

Sorted keys / range queries
→ TreeMap

Concurrent access
→ ConcurrentHashMap

Enum keys
→ EnumMap

Weak-key lifetime semantics
→ WeakHashMap

Identity-based keys
→ IdentityHashMap
```

------------------------------------------------------------------------

# PART 145 --- COMMON MISTAKES

## 213. Mistake: Assuming HashMap Is Ordered

Wrong:

``` text
HashMap preserves insertion order
```

Correct:

``` text
HashMap provides no guaranteed iteration order.
```

------------------------------------------------------------------------

## 214. Mistake: Using `get()` to Test Existence

Wrong when null values are possible:

``` java
if (map.get(key) != null) {
    ...
}
```

This cannot distinguish:

``` text
key absent
```

from:

``` text
key present → null
```

Use:

``` java
map.containsKey(key)
```

when needed.

------------------------------------------------------------------------

## 215. Mistake: Mutable Keys

Avoid changing fields that affect:

``` java
equals()
hashCode()
```

after insertion into HashMap.

------------------------------------------------------------------------

## 216. Mistake: TreeMap Comparator

Do not accidentally make distinct logical objects compare as:

``` text
0
```

unless they are intentionally equivalent for the Map's ordering.

------------------------------------------------------------------------

## 217. Mistake: HashMap in Multi-Threading

Do not use a plain HashMap for unsynchronized concurrent mutation.

Use:

``` java
ConcurrentHashMap
```

or another correctly synchronized design.

------------------------------------------------------------------------

# PART 146 --- MAP AND NULL

## 218. Null Summary

``` text
HashMap:
1 null key
multiple null values

LinkedHashMap:
1 null key
multiple null values

TreeMap:
natural ordering generally rejects null key

Hashtable:
no null key/value

ConcurrentHashMap:
no null key/value

WeakHashMap:
null key supported

IdentityHashMap:
null key supported

EnumMap:
no null key

Map.of():
no null key/value
```

------------------------------------------------------------------------

# PART 147 --- MAP ITERATION COMPLEXITY

## 219. Iteration

For most Map implementations:

``` text
iteration → O(n)
```

But iteration order differs:

``` text
HashMap       → unspecified
LinkedHashMap → predictable insertion/access
TreeMap       → sorted key order
EnumMap       → enum order
```

------------------------------------------------------------------------

# PART 148 --- MAP AND MEMORY

## 220. Big-O Space

A Map storing `n` mappings generally requires:

``` text
O(n)
```

additional storage.

Actual memory depends heavily on implementation.

HashMap, LinkedHashMap, TreeMap, and concurrent Maps have different
node/table overheads.

------------------------------------------------------------------------

# PART 149 --- MAP API DESIGN

## 221. Return Map vs Specific Implementation

Prefer:

``` java
Map<String, User> getUsers()
```

when callers only need Map behavior.

Avoid unnecessarily exposing:

``` java
HashMap<String, User>
```

unless implementation-specific behavior is part of the API contract.

------------------------------------------------------------------------

# PART 150 --- MAP AND IMMUTABILITY

## 222. Defensive Copy

If a method should not expose a mutable internal Map:

``` java
return Map.copyOf(internalMap);
```

This protects the caller from modifying the returned Map.

------------------------------------------------------------------------

# PART 151 --- MAP OF CONSTANTS

## 223. Immutable Lookup Table

``` java
private static final Map<Integer, String> STATUS =
    Map.of(
        200, "OK",
        400, "BAD_REQUEST",
        404, "NOT_FOUND"
    );
```

This is a useful pattern for fixed mappings.

------------------------------------------------------------------------

# PART 152 --- MAP AND ENUM

## 224. Prefer EnumMap

If:

``` java
Map<Status, String>
```

where `Status` is an enum, consider:

``` java
EnumMap<Status, String>
```

instead of HashMap when the requirements fit.

------------------------------------------------------------------------

# PART 153 --- MAP AND SORTING

## 225. Sort Keys

``` java
TreeMap<Integer, String> sorted =
    new TreeMap<>(map);
```

------------------------------------------------------------------------

## 226. Sort Entries by Value

``` java
List<Map.Entry<Integer, String>> entries =
    new ArrayList<>(
        map.entrySet()
    );

entries.sort(
    Map.Entry.comparingByValue()
);
```

------------------------------------------------------------------------

# PART 154 --- MAP AND DUPLICATE VALUES

## 227. Finding Duplicate Values

Values are not unique.

To find unique values:

``` java
Set<String> uniqueValues =
    new HashSet<>(
        map.values()
    );
```

------------------------------------------------------------------------

# PART 155 --- INVERTING MAP

## 228. Reverse Mapping

Original:

``` text
1 → A
2 → B
```

Reverse:

``` text
A → 1
B → 2
```

Only safe if values are unique.

``` java
Map<String, Integer> reverse =
    new HashMap<>();

for (Map.Entry<Integer, String> entry :
        map.entrySet()) {

    reverse.put(
        entry.getValue(),
        entry.getKey()
    );
}
```

If values repeat, later entries can overwrite earlier keys.

------------------------------------------------------------------------

# PART 156 --- MAP FREQUENCY

## 229. Character Frequency

``` java
Map<Character, Integer> frequency =
    new HashMap<>();

for (char c :
        text.toCharArray()) {

    frequency.merge(
        c,
        1,
        Integer::sum
    );
}
```

------------------------------------------------------------------------

# PART 157 --- ANAGRAM

## 230. Anagram Pattern

Two strings can be compared using frequency Maps.

``` text
listen
silent
```

Build:

``` text
character → count
```

for both strings and compare Maps.

------------------------------------------------------------------------

# PART 158 --- GROUP ANAGRAMS

## 231. Map as Grouping Key

Concept:

``` text
sorted characters
       ↓
Map key
       ↓
list of original words
```

Example:

``` text
"eat"  → "aet"
"tea"  → "aet"
"ate"  → "aet"
```

Map:

``` text
aet → [eat, tea, ate]
```

------------------------------------------------------------------------

# PART 159 --- MAP AND TWO SUM

## 232. Why Map Works

Map provides:

``` text
value → index
```

Then complement lookup is fast on average.

This converts a nested O(n²) search into an average O(n) solution.

------------------------------------------------------------------------

# PART 160 --- MAP AND MEMOIZATION

## 233. Dynamic Programming

Map can store states:

``` text
state → answer
```

Example:

``` java
Map<Integer, Long> memo =
    new HashMap<>();
```

For multidimensional state, use a record key:

``` java
record State(int row, int col) {}

Map<State, Integer> memo =
    new HashMap<>();
```

------------------------------------------------------------------------

# PART 161 --- MAP AS GRAPH

## 234. Graph

``` java
Map<String, List<String>> graph =
    new HashMap<>();
```

Example:

``` text
A → [B, C]
B → [D]
C → [D]
```

This is common in graph algorithms and dependency processing.

------------------------------------------------------------------------

# PART 162 --- MAP FOR INDEXING

## 235. Index Map

``` java
Map<String, Integer> index =
    new HashMap<>();

for (int i = 0; i < names.size(); i++) {
    index.put(
        names.get(i),
        i
    );
}
```

Then:

``` java
int position =
    index.get("Deep");
```

Average lookup is O(1) with HashMap.

------------------------------------------------------------------------

# PART 163 --- MAP FOR DATABASE RESULTS

## 236. Row Mapping Concept

A database row can conceptually be represented as:

``` text
column → value
```

Example:

``` java
Map<String, Object> row =
    new HashMap<>();
```

But for fixed database schemas, strongly typed entities/DTOs are usually
preferable.

------------------------------------------------------------------------

# PART 164 --- MAP FOR HTTP HEADERS

## 237. Key-Value Headers

HTTP headers naturally resemble:

``` text
header-name → header-value
```

A Map-like structure is therefore useful conceptually.

Be aware that real HTTP APIs can have duplicate header names or
multi-valued headers, so a plain `Map<String, String>` may not always
model HTTP headers correctly.

------------------------------------------------------------------------

# PART 165 --- MAP AND CONFIGURATION

## 238. Dynamic Configuration

``` java
Map<String, String> settings =
    new HashMap<>();
```

Useful when keys are dynamic.

For a known schema:

``` text
DTO / record
```

is often better.

------------------------------------------------------------------------

# PART 166 --- MAP AND JSON

## 239. Dynamic JSON

A Map can represent object-like data:

``` java
Map<String, Object> json =
    new HashMap<>();
```

But nested dynamic JSON can become difficult to type-check.

Use typed classes when the schema is known.

------------------------------------------------------------------------

# PART 167 --- MAP AND LRU CACHE

## 240. Simple LRU Pattern

``` java
LinkedHashMap<String, User> cache =
    new LinkedHashMap<>(
        100,
        0.75f,
        true
    ) {
        @Override
        protected boolean removeEldestEntry(
                Map.Entry<String, User> eldest) {

            return size() > 100;
        }
    };
```

This provides a simple in-memory LRU-like cache.

For production caching, consider dedicated cache libraries/systems when
requirements include expiration, distributed operation, refresh,
persistence, or advanced eviction policies.

------------------------------------------------------------------------

# PART 168 --- MAP AND CACHE THREAD SAFETY

## 241. Important

A `LinkedHashMap` LRU cache is not automatically thread-safe.

Concurrent access requires synchronization or a purpose-built
cache/concurrent design.

------------------------------------------------------------------------

# PART 169 --- MAP AND WEAK REFERENCES

## 242. WeakHashMap vs Cache

WeakHashMap:

``` text
key lifetime determines possible removal
```

Cache expiration:

``` text
time / size / policy determines removal
```

These are different concepts.

------------------------------------------------------------------------

# PART 170 --- MAP AND IDENTITY

## 243. IdentityHashMap vs HashMap

``` text
HashMap:
logical equality

IdentityHashMap:
reference identity
```

Example:

``` java
a.equals(b) == true
a == b       == false
```

HashMap treats them as equal keys.

IdentityHashMap can treat them as different keys.

------------------------------------------------------------------------

# PART 171 --- MAP AND ENUMMAP

## 244. Why EnumMap Is Efficient

Enums have a fixed finite universe.

EnumMap can therefore use a specialized representation instead of
general-purpose hashing.

This provides compact storage and efficient operations.

------------------------------------------------------------------------

# PART 172 --- MAP IMPLEMENTATION MASTER TABLE

## 245. Main Implementations

  -----------------------------------------------------------------------------------------------
  Map                   Ordering           Thread-safe    Null key    Null values  Typical use
  --------------------- ------------------ -------------- ----------- ------------ --------------
  `HashMap`             None guaranteed    No             One         Yes          General
                                                                                   purpose

  `LinkedHashMap`       Insertion/access   No             One         Yes          Predictable
                                                                                   order/LRU
                                                                                   pattern

  `TreeMap`             Sorted             No             Generally   Yes, subject Sorted/range
                                                          no with     to           
                                                          natural     comparison   
                                                          ordering    operations   

  `Hashtable`           None guaranteed    Legacy         No          No           Legacy
                                           synchronized                            

  `ConcurrentHashMap`   None guaranteed    Yes            No          No           Concurrent

  `WeakHashMap`         None guaranteed    No             Yes         Yes          Weak-key
                                                                                   mappings

  `IdentityHashMap`     None guaranteed    No             Yes         Yes          Identity
                                                                                   semantics

  `EnumMap`             Enum order         No             No          Yes          Enum keys
  -----------------------------------------------------------------------------------------------

------------------------------------------------------------------------

# PART 173 --- MAP FACTORY TABLE

## 246. Immutable/Unmodifiable APIs

  ---------------------------------------------------------------------------------------
  API                               Mutable result    Null              Duplicate keys
  --------------------------------- ----------------- ----------------- -----------------
  `Map.of()`                        No                No                No

  `Map.ofEntries()`                 No                No                No

  `Map.copyOf()`                    No                No                No

  `Collections.unmodifiableMap()`   No through view   Depends on source Depends on source
  ---------------------------------------------------------------------------------------

------------------------------------------------------------------------

# PART 174 --- MAP COMPLEXITY MASTER TABLE

## 247. Main Operations

  ----------------------------------------------------------------------------
  Operation                  HashMap avg  LinkedHashMap avg            TreeMap
  ------------------- ------------------ ------------------ ------------------
  `put()`                           O(1)               O(1)           O(log n)

  `get()`                           O(1)               O(1)           O(log n)

  `remove()`                        O(1)               O(1)           O(log n)

  `containsKey()`                   O(1)               O(1)           O(log n)

  `containsValue()`                 O(n)               O(n)               O(n)

  Iteration                         O(n)               O(n)               O(n)

  First/last key       Not meaningful as  No sorted-key API           O(log n)
                             ordered API                    

  Range query                         No                 No                Yes
  ----------------------------------------------------------------------------

These are typical complexity characteristics, not guarantees about every
internal operation under every workload.

------------------------------------------------------------------------

# PART 175 --- MAP INTERVIEW QUESTIONS

## 248. What Is Map?

A key-value data structure where keys are unique.

------------------------------------------------------------------------

## 249. Can Map Have Duplicate Keys?

No.

A new value for an existing key replaces the previous mapping.

------------------------------------------------------------------------

## 250. Can Map Have Duplicate Values?

Yes.

------------------------------------------------------------------------

## 251. Is Map a Collection?

No.

`Map` is a separate interface in the Java Collections Framework.

------------------------------------------------------------------------

## 252. HashMap vs Hashtable?

``` text
HashMap:
modern
not synchronized
one null key
null values

Hashtable:
legacy
synchronized
no null key/value
```

------------------------------------------------------------------------

## 253. HashMap vs LinkedHashMap?

``` text
HashMap
→ no guaranteed order

LinkedHashMap
→ insertion/access order
```

------------------------------------------------------------------------

## 254. HashMap vs TreeMap?

``` text
HashMap
→ average O(1)
→ no ordering guarantee

TreeMap
→ O(log n)
→ sorted keys
→ navigation/range
```

------------------------------------------------------------------------

## 255. Why Use `entrySet()`?

It provides direct access to both:

``` text
key
value
```

without separately looking up each value by key.

------------------------------------------------------------------------

## 256. Difference Between `get()` and `containsKey()`?

`get()` returns the value and can return null for both:

``` text
absent key
```

and:

``` text
present key with null value
```

`containsKey()` explicitly tests key presence.

------------------------------------------------------------------------

# PART 176 --- ADVANCED INTERVIEW QUESTIONS

## 257. How Does HashMap Work?

Conceptually:

``` text
key
 ↓
hashCode
 ↓
bucket
 ↓
key comparison
 ↓
value
```

------------------------------------------------------------------------

## 258. Why Override `equals()` and `hashCode()` Together?

Because hash-based Maps need consistent hashing and equality.

Equal keys must have equal hash codes.

------------------------------------------------------------------------

## 259. What Is Hash Collision?

Different keys can map to the same bucket.

------------------------------------------------------------------------

## 260. What Is Load Factor?

A threshold-related ratio used by hash tables to determine when resizing
should occur.

Common HashMap default:

``` text
0.75
```

------------------------------------------------------------------------

## 261. What Is Treeification?

Under appropriate conditions, a heavily collided HashMap bucket can be
represented using a tree structure to improve lookup behavior.

------------------------------------------------------------------------

## 262. Why Does ConcurrentHashMap Reject Null?

Because null cannot cleanly represent both:

``` text
absence
```

and:

``` text
present null mapping
```

in its concurrent retrieval/update semantics.

------------------------------------------------------------------------

## 263. What Is WeakHashMap?

A Map whose keys are weakly referenced, allowing mappings to disappear
when keys are no longer strongly reachable and garbage collection
occurs.

------------------------------------------------------------------------

## 264. What Is IdentityHashMap?

A Map that uses reference identity (`==`) rather than normal logical
equality for keys.

------------------------------------------------------------------------

## 265. What Is EnumMap?

A specialized Map for enum keys, optimized for the finite enum key
domain.

------------------------------------------------------------------------

# PART 177 --- EXPERT MAP CONCEPTS

## 266. Map Key Stability

A key's identity as defined by:

``` text
hashCode + equals
```

must remain stable while stored in a HashMap.

For TreeMap:

``` text
Comparator / Comparable
```

ordering must remain stable.

------------------------------------------------------------------------

## 267. View vs Copy

These are different:

``` java
map.keySet()
```

→ view

``` java
new HashSet<>(map.keySet())
```

→ independent Set copy

Similarly:

``` java
new HashMap<>(map)
```

creates a new Map structure.

------------------------------------------------------------------------

## 268. Shallow Copy

``` java
Map<String, User> copy =
    new HashMap<>(original);
```

creates a new Map container but does not automatically deep-copy each
`User`.

Conceptually:

``` text
new Map
   ↓
same key references
same value references
```

------------------------------------------------------------------------

# PART 178 --- MAP CONCURRENCY PATTERNS

## 269. Unsafe Check-Then-Act

``` java
if (!map.containsKey(key)) {
    map.put(key, value);
}
```

Not atomic across threads.

------------------------------------------------------------------------

## 270. Atomic Alternative

``` java
map.putIfAbsent(
    key,
    value
);
```

------------------------------------------------------------------------

## 271. Atomic Initialization

``` java
map.computeIfAbsent(
    key,
    k -> createValue(k)
);
```

------------------------------------------------------------------------

## 272. Atomic Counter

``` java
map.merge(
    key,
    1,
    Integer::sum
);
```

------------------------------------------------------------------------

# PART 179 --- CONCURRENT COUNTERS

## 273. Integer vs LongAdder

For a moderate concurrent Map:

``` java
ConcurrentHashMap<String, Integer>
```

with `merge()` may be sufficient.

For very high-contention counters:

``` java
ConcurrentHashMap<String, LongAdder>
```

can reduce contention.

Example:

``` java
ConcurrentHashMap<String, LongAdder> counts =
    new ConcurrentHashMap<>();

counts.computeIfAbsent(
    word,
    k -> new LongAdder()
).increment();
```

------------------------------------------------------------------------

# PART 180 --- MAP AND THREAD POOLS

## 274. Registry Pattern

A concurrent Map can maintain:

``` text
worker ID → worker object
```

Example:

``` java
ConcurrentHashMap<String, Worker> workers =
    new ConcurrentHashMap<>();
```

Useful for thread-safe registries.

------------------------------------------------------------------------

# PART 181 --- MAP AND DATABASE CACHING

## 275. Local Cache Pattern

``` text
Request
   ↓
Map cache
   ↓
found?
 ├── yes → return
 └── no  → database
             ↓
          cache.put()
```

For production systems, cache invalidation, memory limits, concurrency,
expiration, and distributed consistency must be considered.

------------------------------------------------------------------------

# PART 182 --- MAP AND SECURITY

## 276. Security-Related Lookup

Maps can hold:

``` text
token → metadata
permission → policy
userId → session
```

But sensitive credentials/tokens should not be stored casually in
process memory without considering lifecycle, security, expiration, and
exposure risks.

------------------------------------------------------------------------

# PART 183 --- MAP AND BACKEND DESIGN

## 277. Typical Backend Uses

``` text
ID → Entity
Code → Description
User → Permissions
Department → Employees
Category → Products
Token → Session
Prefix → Count
State → Result
```

------------------------------------------------------------------------

# PART 184 --- MAP AND MICROSERVICES

## 278. Local Map vs Distributed Cache

Local:

``` text
HashMap
ConcurrentHashMap
```

Distributed:

``` text
Redis
Distributed cache
Database
```

A Java Map lives inside the process unless explicitly connected to an
external system.

------------------------------------------------------------------------

# PART 185 --- MAP AND SERIALIZATION

## 279. Map Serialization

Maps can be serialized through frameworks such as:

``` text
JSON
XML
Java serialization
```

The exact serialized structure depends on the framework.

For APIs, typed DTOs are generally preferable when the schema is stable.

------------------------------------------------------------------------

# PART 186 --- MAP AND JSON OBJECTS

## 280. JSON-Like Structure

Conceptually:

``` json
{
  "name": "Deep",
  "age": 25
}
```

can be modeled dynamically as:

``` java
Map<String, Object>
```

But typed Java classes provide better compile-time safety when the
schema is known.

------------------------------------------------------------------------

# PART 187 --- MAP API BEST PRACTICES

## 281. Prefer Interface Types

Use:

``` java
Map<String, User> users =
    new HashMap<>();
```

instead of exposing implementation types unnecessarily.

------------------------------------------------------------------------

## 282. Choose Implementation by Requirement

``` text
No ordering
→ HashMap

Insertion/access ordering
→ LinkedHashMap

Sorted keys
→ TreeMap

Concurrent access
→ ConcurrentHashMap

Enum keys
→ EnumMap
```

------------------------------------------------------------------------

## 283. Use Immutable Maps for Constants

``` java
private static final Map<String, Integer> STATUS =
    Map.of(
        "OK", 200,
        "ERROR", 500
    );
```

------------------------------------------------------------------------

## 284. Avoid Mutable Keys

Use immutable key objects whenever possible.

------------------------------------------------------------------------

# PART 188 --- COMMON MAP MISTAKES

## 285. Mistake: Using `containsValue()` for Frequent Lookup

`containsValue()` usually requires scanning values.

If you need fast value lookup, consider maintaining a reverse Map when
values are unique.

------------------------------------------------------------------------

## 286. Mistake: Using TreeMap Without Needing Ordering

TreeMap adds ordering/comparison overhead.

If only average fast key lookup is required:

``` text
HashMap
```

may be more appropriate.

------------------------------------------------------------------------

## 287. Mistake: Using HashMap for Sorted Output

Do not rely on HashMap iteration order.

Use:

``` java
TreeMap
```

or sort entries explicitly.

------------------------------------------------------------------------

## 288. Mistake: Using Map\<String,Object\> Everywhere

Dynamic Maps are flexible but can weaken:

``` text
type safety
refactoring
documentation
validation
```

Use DTOs/records for stable schemas.

------------------------------------------------------------------------

# PART 189 --- MAP AND RECORDS

## 289. Record as Key

``` java
record UserKey(
    long tenantId,
    long userId
) {}
```

Then:

``` java
Map<UserKey, User> users =
    new HashMap<>();
```

Records are excellent value-object keys because they provide value-based
equality and hash code.

------------------------------------------------------------------------

# PART 190 --- MAP OF ENUMS

## 290. EnumMap

``` java
enum Environment {
    DEV,
    TEST,
    PROD
}

EnumMap<Environment, String> urls =
    new EnumMap<>(
        Environment.class
    );
```

------------------------------------------------------------------------

# PART 191 --- MAP RANGE QUERIES

## 291. TreeMap

TreeMap is useful for:

``` text
scores between X and Y
timestamps before T
timestamps after T
nearest key
first/last key
```

Example:

``` java
treeMap.floorEntry(timestamp);
```

------------------------------------------------------------------------

# PART 192 --- TIMESTAMP MAP

## 292. Example

``` java
TreeMap<Long, String> events =
    new TreeMap<>();

events.put(1000L, "A");
events.put(2000L, "B");
events.put(3000L, "C");
```

Find event at or before:

``` java
events.floorEntry(2500L);
```

Result:

``` text
2000 → B
```

This is a powerful real-world TreeMap pattern.

------------------------------------------------------------------------

# PART 193 --- MAP AS PRIORITY INDEX

## 294. TreeMap vs PriorityQueue

TreeMap can maintain:

``` text
priority → collection of items
```

while PriorityQueue directly models:

``` text
next highest/lowest priority
```

Choose based on whether you need:

``` text
ordered key navigation
```

or:

``` text
repeated priority extraction
```

------------------------------------------------------------------------

# PART 194 --- MAP AND CACHE INVALIDATION

## 295. In-Memory Cache

``` java
Map<Long, User> cache =
    new ConcurrentHashMap<>();
```

Potential operations:

``` text
get
put
remove
computeIfAbsent
```

But production caching often needs:

``` text
TTL
LRU
size limits
eviction
refresh
distributed invalidation
```

A plain Map does not provide these automatically.

------------------------------------------------------------------------

# PART 195 --- MAP AND MEMORY LEAKS

## 296. Long-Lived Map

A static or long-lived HashMap can retain objects indefinitely:

``` java
static final Map<String, Object> cache =
    new HashMap<>();
```

If entries are never removed, memory can grow continuously.

Consider:

``` text
bounded cache
expiration
explicit cleanup
WeakHashMap
dedicated cache
```

depending on requirements.

------------------------------------------------------------------------

# PART 196 --- MAP AND WEAKHASHMAP

## 297. When WeakHashMap Helps

If the key's lifetime should control whether auxiliary metadata remains:

``` text
Object
 ↓
WeakHashMap
 ↓
metadata
```

When the object is no longer strongly reachable, the entry can disappear
after GC.

------------------------------------------------------------------------

# PART 197 --- MAP AND IDENTITY

## 298. Object Graph Example

For graph processing where two distinct objects may be logically equal
but must still be treated as separate nodes:

``` java
Map<Object, Boolean> visited =
    new IdentityHashMap<>();
```

This tracks identity rather than logical equality.

------------------------------------------------------------------------

# PART 198 --- MAP API QUICK REFERENCE

## 299. Most Important Methods

``` java
put()
get()
remove()

containsKey()
containsValue()

putIfAbsent()
getOrDefault()

replace()
replaceAll()

compute()
computeIfAbsent()
computeIfPresent()
merge()

keySet()
values()
entrySet()

forEach()
```

------------------------------------------------------------------------

# PART 199 --- SORTED/NAVIGABLE QUICK REFERENCE

## 300. TreeMap Methods

``` java
firstKey()
lastKey()

firstEntry()
lastEntry()

lowerKey()
floorKey()
ceilingKey()
higherKey()

lowerEntry()
floorEntry()
ceilingEntry()
higherEntry()

pollFirstEntry()
pollLastEntry()

headMap()
tailMap()
subMap()

descendingMap()
navigableKeySet()
descendingKeySet()
```

------------------------------------------------------------------------

# PART 200 --- MASTER MAP HIERARCHY

## 301. Complete Mental Model

``` text
Map
│
├── HashMap
│
├── LinkedHashMap
│
├── SortedMap
│    │
│    └── NavigableMap
│          │
│          └── TreeMap
│
├── Hashtable
│
├── WeakHashMap
│
├── IdentityHashMap
│
├── EnumMap
│
└── ConcurrentMap
     │
     └── ConcurrentHashMap
```

------------------------------------------------------------------------

# PART 201 --- MASTER DECISION TREE

## 302. Which Map Should You Use?

``` text
Need key-value mapping?
        |
       YES
        ↓
Need ordering?
   ┌────┴─────┐
   NO        YES
   ↓          ↓
HashMap    What order?
             |
       ┌─────┴──────┐
       ↓            ↓
 insertion/access  sorted
       ↓            ↓
LinkedHashMap     TreeMap
```

Special cases:

``` text
Enum keys
   ↓
EnumMap

Concurrent access
   ↓
ConcurrentHashMap

Weak key lifetime
   ↓
WeakHashMap

Identity semantics
   ↓
IdentityHashMap

Fixed immutable mappings
   ↓
Map.of()
```

------------------------------------------------------------------------

# PART 202 --- MAP VS SET

## 303. Comparison

  -----------------------------------------------------------------------
  Feature                 Map                     Set
  ----------------------- ----------------------- -----------------------
  Stores                  Key-value               Values/elements

  Unique key/element      Key                     Element

  Lookup                  Key → value             Element membership

  Example                 `HashMap`               `HashSet`

  Multiple values per key Possible with           Not applicable
                          collection value        
  -----------------------------------------------------------------------

Mental model:

``` text
Set:
A
B
C

Map:
A → 100
B → 200
C → 300
```

------------------------------------------------------------------------

# PART 203 --- MAP VS LIST

## 304. Comparison

  Feature                   Map                List
  ------------------------- ------------------ --------------
  Key lookup                Yes                No
  Index                     Not primary        Yes
  Duplicate keys/elements   Keys no            Elements yes
  Main purpose              Association        Sequence
  Typical lookup            HashMap O(1) avg   List O(n)

------------------------------------------------------------------------

# PART 204 --- MAP VS QUEUE

## 305. Comparison

``` text
Map
→ key-value association

Queue
→ processing order
```

Example:

``` text
Map:
employeeId → Employee

Queue:
Employee → waiting for processing
```

------------------------------------------------------------------------

# PART 205 --- MAP PERFORMANCE CHECKLIST

## 306. Before Choosing

Ask:

1.  Do I need key-value association?
2.  Are keys unique?
3.  Do I need insertion order?
4.  Do I need access order?
5.  Do I need sorted keys?
6.  Do I need range queries?
7.  Do I need nearest-key lookup?
8.  Are keys enums?
9.  Do I need concurrency?
10. Can keys be null?
11. Can values be null?
12. Are keys mutable?
13. Is memory usage important?
14. Is this a local cache?
15. Is state distributed?
16. Is the Map immutable?
17. Are reads or writes dominant?

------------------------------------------------------------------------

# PART 206 --- INTERVIEW MASTER CHECKLIST

## 307. Beginner

-   [ ] What is Map?
-   [ ] Key-value pair
-   [ ] Unique keys
-   [ ] Duplicate values
-   [ ] `put()`
-   [ ] `get()`
-   [ ] `remove()`
-   [ ] `containsKey()`
-   [ ] `containsValue()`
-   [ ] `size()`
-   [ ] `isEmpty()`
-   [ ] `clear()`
-   [ ] `keySet()`
-   [ ] `values()`
-   [ ] `entrySet()`

------------------------------------------------------------------------

## 308. Intermediate

-   [ ] HashMap
-   [ ] LinkedHashMap
-   [ ] TreeMap
-   [ ] Hashtable
-   [ ] Null behavior
-   [ ] Hashing
-   [ ] Collision
-   [ ] equals()
-   [ ] hashCode()
-   [ ] Load factor
-   [ ] Resizing
-   [ ] Iteration
-   [ ] Map.Entry
-   [ ] Sorting
-   [ ] Views

------------------------------------------------------------------------

## 309. Advanced

-   [ ] SortedMap
-   [ ] NavigableMap
-   [ ] lowerKey()
-   [ ] floorKey()
-   [ ] ceilingKey()
-   [ ] higherKey()
-   [ ] Range views
-   [ ] descendingMap()
-   [ ] ConcurrentMap
-   [ ] ConcurrentHashMap
-   [ ] WeakHashMap
-   [ ] IdentityHashMap
-   [ ] EnumMap
-   [ ] Immutable Maps
-   [ ] Unmodifiable views
-   [ ] Atomic compute/merge operations

------------------------------------------------------------------------

## 310. Expert

-   [ ] HashMap bucket model
-   [ ] Collision handling
-   [ ] Tree bins
-   [ ] Load factor
-   [ ] Capacity planning
-   [ ] Mutable key hazards
-   [ ] Comparator consistency
-   [ ] Weak references
-   [ ] Identity semantics
-   [ ] Concurrent memory visibility
-   [ ] Weakly consistent iterators
-   [ ] Concurrent counters
-   [ ] LRU with LinkedHashMap
-   [ ] Memoization
-   [ ] Frequency maps
-   [ ] Grouping
-   [ ] Prefix-sum Maps
-   [ ] Graph adjacency Maps
-   [ ] Local vs distributed state
-   [ ] Cache design

------------------------------------------------------------------------

# PART 207 --- FINAL SUMMARY

Java `Map` is the main abstraction for associating:

``` text
KEY → VALUE
```

The most important implementations are:

### HashMap

``` java
Map<K, V> map =
    new HashMap<>();
```

Use for general-purpose key-value storage.

``` text
Average lookup → O(1)
No guaranteed order
One null key
Null values allowed
```

### LinkedHashMap

``` java
Map<K, V> map =
    new LinkedHashMap<>();
```

Use when predictable insertion/access ordering matters.

### TreeMap

``` java
NavigableMap<K, V> map =
    new TreeMap<>();
```

Use when keys must be sorted or range/navigation operations are
required.

``` text
Operations → O(log n)
```

### ConcurrentHashMap

``` java
ConcurrentMap<K, V> map =
    new ConcurrentHashMap<>();
```

Use for concurrent access.

``` text
Thread-safe
No null key/value
Atomic compute/merge operations
```

### EnumMap

``` java
EnumMap<Status, String> map =
    new EnumMap<>(Status.class);
```

Use when keys are enum constants.

### WeakHashMap

Use when key lifetime should influence mapping lifetime.

### IdentityHashMap

Use when key identity (`==`) rather than logical equality is
intentionally required.

### Immutable Map

``` java
Map.of(...)
Map.ofEntries(...)
Map.copyOf(...)
```

Use for fixed unmodifiable mappings.

------------------------------------------------------------------------

# QUICK INTERVIEW REVISION

``` text
Map
→ key-value
→ keys are unique
→ values can repeat

HashMap
→ hash-based
→ average O(1)
→ no guaranteed order
→ one null key
→ null values allowed

LinkedHashMap
→ HashMap behavior
→ insertion/access order

TreeMap
→ sorted keys
→ O(log n)
→ NavigableMap
→ range queries
→ lower/floor/ceiling/higher

Hashtable
→ legacy synchronized Map
→ no null key/value

ConcurrentHashMap
→ concurrent
→ high concurrency
→ no null key/value
→ weakly consistent iterators

WeakHashMap
→ weakly referenced keys

IdentityHashMap
→ identity comparison (==)

EnumMap
→ enum keys
→ compact and efficient

Map.of()
→ unmodifiable
→ no duplicate keys
→ no null key/value

Map.copyOf()
→ unmodifiable copy
→ no null key/value

Most important methods:
put()
get()
remove()
containsKey()
containsValue()

putIfAbsent()
getOrDefault()

replace()
replaceAll()

compute()
computeIfAbsent()
computeIfPresent()
merge()

keySet()
values()
entrySet()

TreeMap navigation:
lower  → <
floor  → <=
ceiling → >=
higher → >

Set relation:
keySet() → Set
values() → Collection
entrySet() → Set<Map.Entry<K,V>>

Important rule:
Use immutable/stable keys.

For normal Map:
equals() + hashCode()

For TreeMap:
Comparable / Comparator ordering

For concurrent updates:
prefer atomic operations such as
putIfAbsent(), computeIfAbsent(), merge()
instead of unsafe check-then-act sequences.
```

------------------------------------------------------------------------

# END --- JAVA MAP 100% COMPLETE NOTES
