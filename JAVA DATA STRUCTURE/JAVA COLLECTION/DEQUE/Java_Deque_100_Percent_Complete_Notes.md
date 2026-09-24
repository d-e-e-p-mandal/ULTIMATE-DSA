# Java Deque --- 100% Complete Notes

> **Goal:** Complete Java `Deque` coverage from beginner to advanced
> level, including the `Deque` interface, all methods, `ArrayDeque`,
> `LinkedList`, FIFO/LIFO behavior, circular-array concepts, stack
> replacement, iterators, null handling, complexity, concurrency,
> algorithms, practical patterns, pitfalls, and interview questions.

------------------------------------------------------------------------

# PART 1 --- DEQUE FUNDAMENTALS

## 1. What is a Deque?

`Deque` means:

``` text
Double Ended Queue
```

A deque allows insertion and removal from **both ends**.

``` text
                 HEAD
                  ↓
        ┌────┬────┬────┬────┐
        │ 10 │ 20 │ 30 │ 40 │
        └────┴────┴────┴────┘
                  ↑
                 TAIL
```

You can:

-   Add at the front
-   Add at the back
-   Remove from the front
-   Remove from the back
-   Inspect the front
-   Inspect the back

------------------------------------------------------------------------

## 2. Java Deque Interface

Package:

``` java
java.util.Deque
```

Declaration:

``` java
public interface Deque<E> extends Queue<E>
```

Therefore:

``` text
Iterable
   ↓
Collection
   ↓
Queue
   ↓
Deque
```

Common implementations:

``` text
Deque
├── ArrayDeque
└── LinkedList
```

For concurrent/deque-specific use cases, Java also provides:

``` text
BlockingDeque
└── LinkedBlockingDeque
```

------------------------------------------------------------------------

# PART 2 --- DEQUE AS A DATA STRUCTURE

## 3. Two Ends

A deque has:

``` text
FIRST / HEAD
LAST  / TAIL
```

Example:

``` text
FIRST                         LAST
 ↓                              ↓
[10] → [20] → [30] → [40]
 ↑                              ↑
add/remove                     add/remove
```

Operations can happen on either side.

------------------------------------------------------------------------

## 4. Four Fundamental Operations

### Add first

``` java
deque.addFirst(10);
```

### Add last

``` java
deque.addLast(20);
```

### Remove first

``` java
deque.removeFirst();
```

### Remove last

``` java
deque.removeLast();
```

------------------------------------------------------------------------

# PART 3 --- DEQUE INTERFACE METHODS

## 5. Complete Method Families

The most important Deque methods are:

``` java
addFirst()
addLast()

offerFirst()
offerLast()

removeFirst()
removeLast()

pollFirst()
pollLast()

getFirst()
getLast()

peekFirst()
peekLast()

removeFirstOccurrence()
removeLastOccurrence()

push()
pop()
```

Deque also inherits methods from `Queue` and `Collection`.

------------------------------------------------------------------------

# PART 4 --- ADDING ELEMENTS

## 6. `addFirst()`

``` java
Deque<Integer> deque = new ArrayDeque<>();

deque.addFirst(10);
deque.addFirst(20);
deque.addFirst(30);
```

Result:

``` text
30 → 20 → 10
```

Each new element is inserted at the front.

------------------------------------------------------------------------

## 7. `addLast()`

``` java
deque.addLast(40);
deque.addLast(50);
```

Result:

``` text
30 → 20 → 10 → 40 → 50
```

Elements are added at the back.

------------------------------------------------------------------------

## 8. `offerFirst()`

``` java
deque.offerFirst(10);
```

Attempts to insert at the front.

Returns:

``` text
true / false
```

This is the special-value form of `addFirst()`.

------------------------------------------------------------------------

## 9. `offerLast()`

``` java
deque.offerLast(20);
```

Attempts to insert at the back.

Returns:

``` text
true / false
```

------------------------------------------------------------------------

# PART 5 --- REMOVING ELEMENTS

## 10. `removeFirst()`

``` java
int value = deque.removeFirst();
```

Removes the first element.

If empty:

``` text
NoSuchElementException
```

------------------------------------------------------------------------

## 11. `removeLast()`

``` java
int value = deque.removeLast();
```

Removes the last element.

If empty:

``` text
NoSuchElementException
```

------------------------------------------------------------------------

## 12. `pollFirst()`

``` java
Integer value = deque.pollFirst();
```

Removes the first element.

If empty:

``` text
null
```

------------------------------------------------------------------------

## 13. `pollLast()`

``` java
Integer value = deque.pollLast();
```

Removes the last element.

If empty:

``` text
null
```

------------------------------------------------------------------------

# PART 6 --- INSPECTING ELEMENTS

## 14. `getFirst()`

``` java
Integer value = deque.getFirst();
```

Reads the first element without removing it.

Empty deque:

``` text
NoSuchElementException
```

------------------------------------------------------------------------

## 15. `getLast()`

``` java
Integer value = deque.getLast();
```

Reads the last element without removing it.

Empty deque:

``` text
NoSuchElementException
```

------------------------------------------------------------------------

## 16. `peekFirst()`

``` java
Integer value = deque.peekFirst();
```

Reads the first element.

Empty deque:

``` text
null
```

------------------------------------------------------------------------

## 17. `peekLast()`

``` java
Integer value = deque.peekLast();
```

Reads the last element.

Empty deque:

``` text
null
```

------------------------------------------------------------------------

# PART 7 --- METHOD COMPARISON

## 18. Insert Methods

  Method           Position   Failure behavior
  ---------------- ---------- --------------------
  `addFirst()`     Front      Exception possible
  `addLast()`      Back       Exception possible
  `offerFirst()`   Front      `false`
  `offerLast()`    Back       `false`

------------------------------------------------------------------------

## 19. Remove Methods

  Method            Position   Empty behavior
  ----------------- ---------- ----------------
  `removeFirst()`   Front      Exception
  `removeLast()`    Back       Exception
  `pollFirst()`     Front      `null`
  `pollLast()`      Back       `null`

------------------------------------------------------------------------

## 20. Inspect Methods

  Method          Position   Empty behavior
  --------------- ---------- ----------------
  `getFirst()`    Front      Exception
  `getLast()`     Back       Exception
  `peekFirst()`   Front      `null`
  `peekLast()`    Back       `null`

Memory pattern:

``` text
addFirst   ↔ offerFirst
addLast    ↔ offerLast

removeFirst ↔ pollFirst
removeLast  ↔ pollLast

getFirst   ↔ peekFirst
getLast    ↔ peekLast
```

------------------------------------------------------------------------

# PART 8 --- BASIC DEQUE EXAMPLE

## 21. Complete Example

``` java
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    public static void main(String[] args) {

        Deque<Integer> deque = new ArrayDeque<>();

        deque.addFirst(20);
        deque.addLast(30);
        deque.addFirst(10);
        deque.addLast(40);

        System.out.println(deque);
    }
}
```

Conceptual result:

``` text
[10, 20, 30, 40]
```

------------------------------------------------------------------------

# PART 9 --- DEQUE AS FIFO QUEUE

## 22. Queue Behavior

A Deque can behave exactly like a normal FIFO queue.

Use:

``` java
offerLast()
pollFirst()
```

Example:

``` java
Deque<Integer> queue = new ArrayDeque<>();

queue.offerLast(10);
queue.offerLast(20);
queue.offerLast(30);

System.out.println(queue.pollFirst());
```

Output:

``` text
10
```

------------------------------------------------------------------------

## 23. FIFO Pattern

``` text
Insert at LAST
      ↓
[10] [20] [30]
 ↑
Remove from FIRST
```

Therefore:

``` text
offerLast()
    +
pollFirst()
    =
FIFO
```

------------------------------------------------------------------------

# PART 10 --- DEQUE AS STACK

## 24. LIFO Behavior

A Deque can also behave as a stack.

Use:

``` java
push()
pop()
```

Example:

``` java
Deque<Integer> stack = new ArrayDeque<>();

stack.push(10);
stack.push(20);
stack.push(30);

System.out.println(stack.pop());
```

Output:

``` text
30
```

------------------------------------------------------------------------

## 25. Stack Pattern

``` text
push(10)
push(20)
push(30)

       TOP
        ↓
      [30]
      [20]
      [10]

pop()
 ↓

30
```

Therefore:

``` text
push()
 +
pop()
 =
LIFO
```

------------------------------------------------------------------------

# PART 11 --- DEQUE AS BOTH

## 26. One Deque, Two Behaviors

``` text
                 Deque
                   |
          ┌────────┴────────┐
          ↓                 ↓
        Queue             Stack
        FIFO              LIFO
          |                 |
offerLast/pollFirst     push/pop
```

This is one of the most important concepts in Java collections.

------------------------------------------------------------------------

# PART 12 --- PUSH AND POP

## 27. `push()`

`push(e)` is equivalent to:

``` java
addFirst(e)
```

Example:

``` java
deque.push(10);
```

Conceptually:

``` java
deque.addFirst(10);
```

------------------------------------------------------------------------

## 28. `pop()`

`pop()` is equivalent to:

``` java
removeFirst()
```

Example:

``` java
int value = deque.pop();
```

If empty:

``` text
NoSuchElementException
```

------------------------------------------------------------------------

# PART 13 --- STACK VS DEQUE

## 29. Legacy Stack

Java has:

``` java
java.util.Stack
```

But for new code, a `Deque` implementation such as `ArrayDeque` is
generally preferred for stack behavior.

Example:

``` java
Deque<Integer> stack =
    new ArrayDeque<>();

stack.push(10);
stack.push(20);

int value = stack.pop();
```

Advantages include a simpler modern abstraction and efficient end
operations without the legacy `Stack` synchronization behavior.

------------------------------------------------------------------------

# PART 14 --- ARRAYDEQUE

## 30. What Is ArrayDeque?

`ArrayDeque` is a resizable-array implementation of `Deque`.

Package:

``` java
java.util.ArrayDeque
```

Declaration conceptually:

``` java
public class ArrayDeque<E>
    extends AbstractCollection<E>
    implements Deque<E>, Cloneable, Serializable
```

------------------------------------------------------------------------

## 31. Main Characteristics

`ArrayDeque`:

-   Is resizable
-   Supports both ends
-   Can act as Queue
-   Can act as Stack
-   Does not allow `null`
-   Is not thread-safe
-   Generally provides efficient end operations
-   Uses an array-backed circular-buffer style design

------------------------------------------------------------------------

# PART 15 --- ARRAYDEQUE INTERNAL STRUCTURE

## 32. Circular Array Concept

A deque can use an array where the logical beginning and end move around
the physical array.

Conceptually:

``` text
index:
 0   1   2   3   4   5   6

[ ] [ ] [A] [B] [C] [ ] [ ]
        ↑           ↑
       head        tail
```

When an end reaches the boundary, the logical position can wrap around.

------------------------------------------------------------------------

## 33. Why Circular Storage?

Without circular storage, repeatedly removing from the front could
require shifting elements.

Circular storage allows the implementation to move the logical
front/back positions instead.

Conceptually:

``` text
remove first
     ↓
move head
```

instead of:

``` text
remove first
     ↓
shift every remaining element
```

------------------------------------------------------------------------

# PART 16 --- ARRAYDEQUE RESIZING

## 34. Dynamic Capacity

`ArrayDeque` grows when more room is needed.

Conceptually:

``` text
Small array
[10][20][30]

        ↓ resize

Larger array
[10][20][30][ ][ ][ ]
```

The exact growth details are implementation-specific and should not be
treated as a fixed public API guarantee.

------------------------------------------------------------------------

## 35. Amortized Complexity

Adding at an end is generally:

``` text
O(1) amortized
```

Occasionally resizing requires:

``` text
O(n)
```

but over many operations the average cost remains amortized O(1).

------------------------------------------------------------------------

# PART 17 --- ARRAYDEQUE COMPLEXITY

## 36. Time Complexity

Typical complexity:

  Operation                Complexity
  ------------------ ----------------
  `addFirst()`         O(1) amortized
  `addLast()`          O(1) amortized
  `offerFirst()`       O(1) amortized
  `offerLast()`        O(1) amortized
  `removeFirst()`                O(1)
  `removeLast()`                 O(1)
  `pollFirst()`                  O(1)
  `pollLast()`                   O(1)
  `peekFirst()`                  O(1)
  `peekLast()`                   O(1)
  `getFirst()`                   O(1)
  `getLast()`                    O(1)
  `contains()`                   O(n)
  `remove(Object)`               O(n)
  iteration                      O(n)

------------------------------------------------------------------------

# PART 18 --- ARRAYDEQUE NULL

## 37. Null Is Not Allowed

``` java
Deque<String> deque = new ArrayDeque<>();

deque.add(null);
```

Results in:

``` text
NullPointerException
```

This is intentional.

------------------------------------------------------------------------

## 38. Why No Null?

Methods such as:

``` java
pollFirst()
pollLast()
```

can return:

``` text
null
```

when no element exists.

Allowing null elements would make this ambiguous:

``` text
null = empty?
```

or:

``` text
null = actual element?
```

Therefore `ArrayDeque` rejects null.

------------------------------------------------------------------------

# PART 19 --- LINKEDLIST AS DEQUE

## 39. LinkedList Implements Deque

`LinkedList` implements:

``` text
List
Deque
Queue
```

Therefore:

``` java
Deque<Integer> deque =
    new LinkedList<>();
```

works.

------------------------------------------------------------------------

## 40. LinkedList Structure

Conceptually:

``` text
head
 ↓
[10] ↔ [20] ↔ [30] ↔ [40]
                              ↑
                             tail
```

Each node has links to neighboring nodes.

------------------------------------------------------------------------

## 41. LinkedList Deque Complexity

Typical end operations:

  Operation           Complexity
  ----------------- ------------
  `addFirst()`              O(1)
  `addLast()`               O(1)
  `removeFirst()`           O(1)
  `removeLast()`            O(1)
  `peekFirst()`             O(1)
  `peekLast()`              O(1)
  `contains()`              O(n)

------------------------------------------------------------------------

# PART 20 --- ARRAYDEQUE VS LINKEDLIST

## 42. Comparison

  Feature                   ArrayDeque         LinkedList
  ------------------------- ------------------ ------------------
  Deque                     Yes                Yes
  Queue                     Yes                Yes
  Stack behavior            Yes                Yes
  Backing                   Array              Linked nodes
  Null                      No                 Yes
  Per-element node object   No                 Yes
  Cache locality            Generally better   Generally worse
  Memory overhead           Generally lower    Generally higher
  Thread-safe               No                 No

For a typical in-memory deque, `ArrayDeque` is generally the
implementation to consider first unless you have a specific reason to
use `LinkedList`.

------------------------------------------------------------------------

# PART 21 --- ITERATION

## 43. Forward Iterator

``` java
Deque<Integer> deque =
    new ArrayDeque<>();

deque.addLast(10);
deque.addLast(20);
deque.addLast(30);

for (Integer value : deque) {
    System.out.println(value);
}
```

Conceptually:

``` text
10
20
30
```

------------------------------------------------------------------------

## 44. Reverse Iterator

Deque provides:

``` java
descendingIterator()
```

Example:

``` java
Iterator<Integer> iterator =
    deque.descendingIterator();

while (iterator.hasNext()) {
    System.out.println(iterator.next());
}
```

For:

``` text
10 20 30
```

the reverse iteration is:

``` text
30
20
10
```

------------------------------------------------------------------------

# PART 22 --- REMOVE OCCURRENCES

## 45. `removeFirstOccurrence()`

``` java
deque.removeFirstOccurrence(20);
```

Removes the first matching occurrence.

Example:

``` text
10 20 30 20 40
```

After:

``` java
removeFirstOccurrence(20);
```

becomes:

``` text
10 30 20 40
```

------------------------------------------------------------------------

## 46. `removeLastOccurrence()`

``` java
deque.removeLastOccurrence(20);
```

Removes the last matching occurrence.

Example:

``` text
10 20 30 20 40
```

becomes:

``` text
10 20 30 40
```

------------------------------------------------------------------------

# PART 23 --- OCCURRENCE COMPLEXITY

## 47. Search-Based Operations

These operations generally require traversal:

``` java
contains()
remove(Object)
removeFirstOccurrence()
removeLastOccurrence()
```

Typical complexity:

``` text
O(n)
```

This is different from end operations:

``` text
addFirst()  → O(1) amortized
addLast()   → O(1) amortized
pollFirst() → O(1)
pollLast()  → O(1)
```

------------------------------------------------------------------------

# PART 24 --- DEQUE COLLECTION METHODS

## 48. Inherited Methods

Deque inherits many `Collection` methods:

``` java
size()
isEmpty()
contains()
iterator()
toArray()
addAll()
remove()
removeAll()
retainAll()
containsAll()
clear()
removeIf()
stream()
parallelStream()
spliterator()
```

It also inherits queue behavior.

------------------------------------------------------------------------

# PART 25 --- `remove()` AMBIGUITY

## 49. Deque `remove()`

Deque inherits:

``` java
remove()
```

from Queue/Collection behavior.

For a deque, the no-argument queue removal corresponds to removing the
first element.

Equivalent conceptual behavior:

``` java
remove()
≈
removeFirst()
```

It throws when the deque is empty.

------------------------------------------------------------------------

## 50. `poll()` Behavior

Similarly:

``` java
poll()
```

corresponds to:

``` java
pollFirst()
```

It returns `null` when empty.

------------------------------------------------------------------------

# PART 26 --- `element()` AND `peek()`

## 51. `element()`

Conceptually:

``` java
element()
≈
getFirst()
```

Empty:

``` text
NoSuchElementException
```

------------------------------------------------------------------------

## 52. `peek()`

Conceptually:

``` java
peek()
≈
peekFirst()
```

Empty:

``` text
null
```

------------------------------------------------------------------------

# PART 27 --- COMPLETE METHOD MAPPING

## 53. Queue-to-Deque Mapping

  Queue method   Deque equivalent
  -------------- ------------------
  `add(e)`       `addLast(e)`
  `offer(e)`     `offerLast(e)`
  `remove()`     `removeFirst()`
  `poll()`       `pollFirst()`
  `element()`    `getFirst()`
  `peek()`       `peekFirst()`

This mapping is extremely important for understanding the interface.

------------------------------------------------------------------------

# PART 28 --- DEQUE AS STACK MAPPING

## 54. Stack-to-Deque Mapping

  Stack concept   Deque
  --------------- ---------------------------
  push            `push()` / `addFirst()`
  pop             `pop()` / `removeFirst()`
  peek            `peek()` / `peekFirst()`

Use the first end consistently.

------------------------------------------------------------------------

# PART 29 --- DEQUE ORDERING

## 55. Does Deque Always Mean FIFO?

No.

A `Deque` provides the ability to operate at both ends.

Whether your algorithm behaves as:

``` text
FIFO
```

or:

``` text
LIFO
```

depends on which operations you use.

------------------------------------------------------------------------

## 56. FIFO Configuration

``` java
offerLast()
pollFirst()
```

------------------------------------------------------------------------

## 57. LIFO Configuration

``` java
push()
pop()
```

or:

``` java
addFirst()
removeFirst()
```

------------------------------------------------------------------------

# PART 30 --- THREAD SAFETY

## 58. Is Deque Thread-Safe?

`Deque` itself does not guarantee thread safety.

Examples:

``` text
ArrayDeque  → not thread-safe
LinkedList  → not thread-safe
```

For concurrent deque requirements, use an appropriate concurrent
implementation.

------------------------------------------------------------------------

# PART 31 --- BLOCKINGDEQUE

## 59. What Is BlockingDeque?

Package:

``` java
java.util.concurrent.BlockingDeque
```

Declaration:

``` java
public interface BlockingDeque<E>
    extends BlockingQueue<E>, Deque<E>
```

It combines:

``` text
Deque
+
BlockingQueue
```

------------------------------------------------------------------------

## 60. BlockingDeque

It supports blocking operations from both ends.

Examples include:

``` java
putFirst()
putLast()

takeFirst()
takeLast()

offerFirst(timeout)
offerLast(timeout)

pollFirst(timeout)
pollLast(timeout)
```

------------------------------------------------------------------------

# PART 32 --- LINKEDBLOCKINGDEQUE

## 61. LinkedBlockingDeque

Implementation:

``` java
java.util.concurrent.LinkedBlockingDeque
```

Example:

``` java
BlockingDeque<Integer> deque =
    new LinkedBlockingDeque<>(100);
```

It supports:

``` text
thread-safe
blocking
double-ended
```

operations.

------------------------------------------------------------------------

## 62. Producer-Consumer With Both Ends

Conceptually:

``` text
Producer A
    ↓
putFirst()
    ↓
┌──────────────┐
│ BlockingDeque│
└──────────────┘
    ↑
takeLast()
    ↑
Consumer B
```

This can be useful when tasks need to be inserted or processed from
either end.

------------------------------------------------------------------------

# PART 33 --- ARRAYDEQUE VS LINKEDBLOCKINGDEQUE

## 63. Important Difference

``` text
ArrayDeque
```

is:

``` text
non-thread-safe
non-blocking
```

while:

``` text
LinkedBlockingDeque
```

is:

``` text
thread-safe
blocking
```

Do not substitute one for the other without considering concurrency
requirements.

------------------------------------------------------------------------

# PART 34 --- DEQUE AND BFS

## 64. BFS

Breadth-First Search normally uses FIFO behavior.

``` java
Deque<Node> deque =
    new ArrayDeque<>();

deque.offerLast(start);

while (!deque.isEmpty()) {
    Node current =
        deque.pollFirst();

    // process
}
```

This behaves as a queue.

------------------------------------------------------------------------

# PART 35 --- DEQUE AND DFS

## 65. DFS

Depth-First Search can use LIFO behavior.

``` java
Deque<Node> stack =
    new ArrayDeque<>();

stack.push(start);

while (!stack.isEmpty()) {
    Node current =
        stack.pop();

    // process
}
```

This behaves as a stack.

------------------------------------------------------------------------

# PART 36 --- SLIDING WINDOW

## 66. Deque in Sliding Window

A deque is extremely useful for:

``` text
Sliding Window Maximum
Sliding Window Minimum
Monotonic Queue
```

The deque stores candidate indexes/elements.

------------------------------------------------------------------------

## 67. Sliding Window Maximum Concept

For:

``` text
[1, 3, -1, -3, 5, 3, 6, 7]
```

A monotonic deque can keep the largest candidates.

Conceptually:

``` text
front = best candidate
back  = newest candidate
```

When a new value makes old candidates impossible to use, remove them
from the back.

------------------------------------------------------------------------

# PART 37 --- MONOTONIC DEQUE

## 68. What Is a Monotonic Deque?

A monotonic deque maintains elements in increasing or decreasing order.

For maximum:

``` text
decreasing
```

For minimum:

``` text
increasing
```

This can reduce some sliding-window algorithms from:

``` text
O(nk)
```

to:

``` text
O(n)
```

because each element is inserted and removed a bounded number of times.

------------------------------------------------------------------------

# PART 38 --- PALINDROME CHECK

## 69. Deque for Palindrome

Example:

``` text
madam
```

Add characters:

``` java
Deque<Character> deque =
    new ArrayDeque<>();

for (char c : text.toCharArray()) {
    deque.addLast(c);
}
```

Then compare:

``` java
while (deque.size() > 1) {
    char first = deque.removeFirst();
    char last = deque.removeLast();

    if (first != last) {
        return false;
    }
}
```

------------------------------------------------------------------------

# PART 39 --- EXPRESSION PROCESSING

## 70. Deque in Parsing

Deque can be useful in algorithms involving:

-   Expression evaluation
-   Token processing
-   Parentheses
-   Operator handling
-   Undo/redo structures
-   Parser state

The correct end operations depend on the algorithm.

------------------------------------------------------------------------

# PART 40 --- UNDO / REDO

## 71. Undo/Redo Concept

Two stacks can be represented using deques:

``` text
Undo Stack
Deque

Redo Stack
Deque
```

Example:

``` java
Deque<String> undo =
    new ArrayDeque<>();

Deque<String> redo =
    new ArrayDeque<>();
```

Undo:

``` java
String state = undo.pop();
redo.push(state);
```

------------------------------------------------------------------------

# PART 41 --- TASK SCHEDULING

## 72. Work Queue

A deque can support:

``` text
Normal tasks → back
Urgent tasks → front
```

Example:

``` java
deque.offerLast(normalTask);
deque.offerFirst(urgentTask);
```

This creates a simple priority-by-position mechanism.

For complex priorities, use a real priority queue instead.

------------------------------------------------------------------------

# PART 42 --- WORK STEALING CONCEPT

## 73. Work-Stealing

Deque structures are important in work-stealing designs.

Conceptually:

``` text
Worker A
┌──────────────┐
│ local deque  │
└──────────────┘
     ↑
 owner takes from one end

Worker B
     ↓
 steals from opposite end
```

Java's fork/join framework uses work-stealing concepts internally.

A deque is suitable for this pattern because different operations can
occur at opposite ends.

------------------------------------------------------------------------

# PART 43 --- DEQUE MEMORY

## 74. ArrayDeque Memory

ArrayDeque uses an array-backed structure.

Advantages:

``` text
fewer per-element node objects
good locality
compact reference storage
```

The actual memory footprint depends on the JVM, object references,
capacity, and element objects.

------------------------------------------------------------------------

## 75. LinkedList Memory

LinkedList requires node objects.

Conceptually:

``` text
Node
 ├── previous
 ├── item
 └── next
```

Therefore, there is additional per-node memory overhead.

------------------------------------------------------------------------

# PART 44 --- CACHE LOCALITY

## 76. Array vs Linked Nodes

Array-backed:

``` text
[A][B][C][D][E]
```

Linked:

``` text
A → C → E → B → D
```

Array-backed storage often provides better spatial locality.

This is one reason `ArrayDeque` can perform well in real applications
even when both structures have O(1) end operations.

------------------------------------------------------------------------

# PART 45 --- ARRAYDEQUE CAPACITY

## 77. Capacity Is Implementation Detail

Do not write code that depends on internal array size or exact resizing
rules.

The public abstraction guarantees deque behavior, not a specific
internal growth algorithm.

Use the API rather than relying on internal fields.

------------------------------------------------------------------------

# PART 46 --- CLONING

## 78. Clone

`ArrayDeque` supports cloning.

Conceptually:

``` java
ArrayDeque<Integer> copy =
    original.clone();
```

The clone is a separate deque structure.

The elements themselves are not automatically deep-cloned.

Therefore:

``` text
new deque structure
+
same element references
```

is the normal object-copy model.

------------------------------------------------------------------------

# PART 47 --- SERIALIZATION

## 79. Serialization

Some Deque implementations implement `Serializable`.

Do not assume every implementation has identical serialization behavior.

For long-term persistence, explicit serialization formats are often
preferable to relying directly on Java native serialization.

------------------------------------------------------------------------

# PART 48 --- GENERICS

## 80. Generic Deque

Use:

``` java
Deque<String> deque =
    new ArrayDeque<>();
```

instead of:

``` java
Deque deque =
    new ArrayDeque();
```

Generics provide compile-time type safety.

------------------------------------------------------------------------

## 81. Custom Object Deque

``` java
Deque<Employee> employees =
    new ArrayDeque<>();

employees.offerLast(employee);
```

This allows the compiler to enforce element type.

------------------------------------------------------------------------

# PART 49 --- PRIMITIVE TYPES

## 82. Deque Cannot Store Primitive Types Directly

This is invalid:

``` java
Deque<int> deque;
```

Java collections use objects.

Use:

``` java
Deque<Integer> deque =
    new ArrayDeque<>();
```

Autoboxing converts:

``` text
int → Integer
```

and unboxing converts:

``` text
Integer → int
```

------------------------------------------------------------------------

# PART 50 --- NULL AND EMPTY

## 83. Empty Deque

Check:

``` java
deque.isEmpty();
```

or:

``` java
deque.size() == 0
```

Prefer:

``` java
isEmpty()
```

for readability.

------------------------------------------------------------------------

## 84. Safe Removal

When empty is a normal state:

``` java
Integer value =
    deque.pollFirst();
```

is often preferable to:

``` java
Integer value =
    deque.removeFirst();
```

because `pollFirst()` returns `null`.

------------------------------------------------------------------------

# PART 51 --- EXCEPTIONS

## 85. `NoSuchElementException`

Possible with:

``` java
removeFirst()
removeLast()
getFirst()
getLast()
remove()
element()
pop()
```

when no element exists.

------------------------------------------------------------------------

## 86. `NullPointerException`

Possible when adding null to an implementation that rejects null, such
as:

``` java
ArrayDeque
```

------------------------------------------------------------------------

## 87. `IllegalStateException`

May occur with insertion APIs in bounded deque implementations when
capacity prevents insertion and the exception-based operation is used.

------------------------------------------------------------------------

# PART 52 --- ITERATOR REMOVAL

## 88. Iterator Remove

``` java
Iterator<Integer> iterator =
    deque.iterator();

while (iterator.hasNext()) {

    Integer value = iterator.next();

    if (value == 20) {
        iterator.remove();
    }
}
```

Use the iterator's `remove()` when removing during iteration is required
and supported.

------------------------------------------------------------------------

# PART 53 --- DESCENDING ITERATOR

## 89. Reverse Traversal

``` java
Iterator<Integer> iterator =
    deque.descendingIterator();

while (iterator.hasNext()) {
    System.out.println(iterator.next());
}
```

This traverses from the deque's last element toward its first element.

------------------------------------------------------------------------

# PART 54 --- STREAM

## 90. Stream Does Not Consume Deque

``` java
deque.stream()
     .forEach(System.out::println);
```

This processes elements but does not remove them.

To consume:

``` java
while (!deque.isEmpty()) {
    Integer value =
        deque.pollFirst();
}
```

------------------------------------------------------------------------

# PART 55 --- SPLITERATOR

## 91. Spliterator

Deque inherits:

``` java
spliterator()
```

Example:

``` java
deque.spliterator()
     .forEachRemaining(System.out::println);
```

The exact spliterator characteristics and parallel behavior depend on
the implementation.

------------------------------------------------------------------------

# PART 56 --- THREAD-SAFE WRAPPER

## 92. Synchronized Collection

A collection can sometimes be wrapped using:

``` java
Collections.synchronizedCollection(...)
```

However, this exposes the collection abstraction rather than
specifically creating a full `Deque` API.

For a true concurrent deque requirement, prefer a dedicated concurrent
implementation such as:

``` java
LinkedBlockingDeque
```

when blocking semantics are needed.

------------------------------------------------------------------------

# PART 57 --- DEQUE VS QUEUE

## 93. Comparison

  -----------------------------------------------------------------------
  Feature                 Queue                   Deque
  ----------------------- ----------------------- -----------------------
  Main ends               Usually one logical     Both ends
                          insertion/removal       
                          direction               

  FIFO                    Common                  Possible

  LIFO                    Not primary             Possible

  `addFirst()`            No                      Yes

  `addLast()`             No                      Yes

  `removeFirst()`         No direct Queue method  Yes

  `removeLast()`          No                      Yes

  Stack behavior          Not primary             Yes
  -----------------------------------------------------------------------

------------------------------------------------------------------------

# PART 58 --- DEQUE VS STACK

## 94. Comparison

  -----------------------------------------------------------------------
  Feature                 Stack                   Deque
  ----------------------- ----------------------- -----------------------
  LIFO                    Yes                     Yes

  Both ends               No                      Yes

  Modern collection       Legacy class            Modern interface
  design                                          

  `push()`                Yes                     Yes

  `pop()`                 Yes                     Yes

  Thread-safe             `Stack` methods         Depends on
                          synchronized            implementation

  Recommended for new     Usually no              Usually yes
  stack code                                      
  -----------------------------------------------------------------------

------------------------------------------------------------------------

# PART 59 --- DEQUE VS ARRAYLIST

## 95. Comparison

  Feature                 Deque                                ArrayList
  ----------------------- ------------------------------------ ------------------------
  End insertion/removal   Yes                                  Back only efficient
  Front removal           Efficient in deque implementations   Usually O(n)
  Random access           Not part of Deque API                Yes
  Stack behavior          Yes                                  Possible but not ideal
  Queue behavior          Yes                                  Possible but not ideal
  Main purpose            End-based processing                 Indexed sequence

------------------------------------------------------------------------

# PART 60 --- DEQUE VS LINKEDLIST

## 96. Comparison

Both:

``` text
ArrayDeque
LinkedList
```

implement:

``` text
Deque
```

But:

``` text
ArrayDeque
→ array-backed
→ no null
→ generally better locality
→ commonly preferred
```

while:

``` text
LinkedList
→ linked nodes
→ allows null
→ also implements List
→ higher node overhead
```

------------------------------------------------------------------------

# PART 61 --- DEQUE VS PRIORITYQUEUE

## 97. Comparison

  Feature              Deque                          PriorityQueue
  -------------------- ------------------------------ ---------------
  FIFO                 Yes, with correct operations   No
  LIFO                 Yes                            No
  Both ends            Yes                            No
  Priority ordering    No                             Yes
  Heap                 No                             Yes
  Arbitrary priority   No                             Yes

------------------------------------------------------------------------

# PART 62 --- COMPLEXITY MASTER TABLE

## 98. ArrayDeque

  Operation                 Complexity
  ------------------- ----------------
  Add first             O(1) amortized
  Add last              O(1) amortized
  Remove first                    O(1)
  Remove last                     O(1)
  Peek first                      O(1)
  Peek last                       O(1)
  Search                          O(n)
  Remove occurrence               O(n)
  Iteration                       O(n)

------------------------------------------------------------------------

## 99. LinkedList as Deque

  Operation        Complexity
  -------------- ------------
  Add first              O(1)
  Add last               O(1)
  Remove first           O(1)
  Remove last            O(1)
  Peek first             O(1)
  Peek last              O(1)
  Search                 O(n)
  Iteration              O(n)

------------------------------------------------------------------------

# PART 63 --- PRACTICAL SELECTION

## 100. Which Deque Should You Use?

### Normal deque

``` java
Deque<T> deque =
    new ArrayDeque<>();
```

### Stack

``` java
Deque<T> stack =
    new ArrayDeque<>();
```

### FIFO queue

``` java
Deque<T> queue =
    new ArrayDeque<>();
```

### Concurrent blocking deque

``` java
BlockingDeque<T> deque =
    new LinkedBlockingDeque<>();
```

------------------------------------------------------------------------

# PART 64 --- DSA PATTERNS

## 101. Important Deque Patterns

Master these:

``` text
Stack
Queue
BFS
DFS
Sliding Window
Monotonic Queue
Palindrome
Undo/Redo
Work Stealing
Task Scheduling
Expression Processing
```

------------------------------------------------------------------------

# PART 65 --- FIFO CODE TEMPLATE

## 102. Queue Template

``` java
Deque<Integer> queue =
    new ArrayDeque<>();

queue.offerLast(10);
queue.offerLast(20);
queue.offerLast(30);

while (!queue.isEmpty()) {

    int value =
        queue.pollFirst();

    System.out.println(value);
}
```

------------------------------------------------------------------------

# PART 66 --- STACK CODE TEMPLATE

## 103. Stack Template

``` java
Deque<Integer> stack =
    new ArrayDeque<>();

stack.push(10);
stack.push(20);
stack.push(30);

while (!stack.isEmpty()) {

    int value =
        stack.pop();

    System.out.println(value);
}
```

Output:

``` text
30
20
10
```

------------------------------------------------------------------------

# PART 67 --- DOUBLE-ENDED TEMPLATE

## 104. Both Ends

``` java
Deque<Integer> deque =
    new ArrayDeque<>();

deque.offerFirst(10);
deque.offerLast(20);

System.out.println(
    deque.peekFirst()
);

System.out.println(
    deque.peekLast()
);

deque.pollFirst();
deque.pollLast();
```

------------------------------------------------------------------------

# PART 68 --- PALINDROME TEMPLATE

## 105. Palindrome

``` java
boolean isPalindrome(String text) {

    Deque<Character> deque =
        new ArrayDeque<>();

    for (char c : text.toCharArray()) {
        deque.addLast(c);
    }

    while (deque.size() > 1) {

        char first =
            deque.removeFirst();

        char last =
            deque.removeLast();

        if (first != last) {
            return false;
        }
    }

    return true;
}
```

------------------------------------------------------------------------

# PART 69 --- BFS TEMPLATE

## 106. BFS

``` java
Deque<Node> queue =
    new ArrayDeque<>();

queue.offerLast(start);

while (!queue.isEmpty()) {

    Node current =
        queue.pollFirst();

    for (Node next : current.neighbors) {
        queue.offerLast(next);
    }
}
```

------------------------------------------------------------------------

# PART 70 --- DFS TEMPLATE

## 107. DFS

``` java
Deque<Node> stack =
    new ArrayDeque<>();

stack.push(start);

while (!stack.isEmpty()) {

    Node current =
        stack.pop();

    for (Node next : current.neighbors) {
        stack.push(next);
    }
}
```

------------------------------------------------------------------------

# PART 71 --- MONOTONIC DEQUE TEMPLATE

## 108. Basic Pattern

For a decreasing monotonic deque:

``` java
while (!deque.isEmpty()
       && values[deque.peekLast()]
          <= values[i]) {

    deque.pollLast();
}

deque.offerLast(i);
```

The deque stores indexes.

The front represents the current best candidate.

------------------------------------------------------------------------

# PART 72 --- REAL-WORLD USE CASES

## 109. Use Cases

Deque is useful for:

-   Browser history
-   Undo/redo
-   Task processing
-   BFS
-   DFS
-   Sliding windows
-   Palindrome checking
-   Scheduling
-   Parser algorithms
-   Cache algorithms
-   Work-stealing designs
-   Double-ended task processing

------------------------------------------------------------------------

# PART 73 --- LRU CACHE CONCEPT

## 110. Deque and Cache Ordering

A deque can help maintain an ordering of recently used items.

Conceptually:

``` text
Most Recent
     ↓
[A][B][C][D]
           ↑
       Least Recent
```

Accessing an item may move it toward the front.

For a production LRU cache, Java's `LinkedHashMap` is usually a more
direct standard-library abstraction, but deque concepts are important
for understanding cache algorithms.

------------------------------------------------------------------------

# PART 74 --- PERFORMANCE

## 111. Big-O Is Not Everything

Two structures can both provide:

``` text
O(1)
```

end operations but still have different real performance.

Factors include:

-   CPU cache locality
-   Object allocation
-   Garbage collection
-   Memory layout
-   Branch prediction
-   Thread contention
-   Resizing
-   JVM implementation

This is why `ArrayDeque` can outperform a linked structure for many
workloads.

------------------------------------------------------------------------

# PART 75 --- CONCURRENCY

## 112. Deque in Multi-Threading

For multiple threads, decide:

``` text
Do I need synchronization?
Do I need blocking?
Do I need capacity?
Do I need both ends?
```

Then choose an appropriate implementation.

Examples:

``` text
Single-threaded
→ ArrayDeque

Concurrent non-blocking queue
→ ConcurrentLinkedQueue

Concurrent blocking deque
→ LinkedBlockingDeque
```

------------------------------------------------------------------------

# PART 76 --- INTERRUPTION

## 113. BlockingDeque Interruption

Blocking methods can throw:

``` java
InterruptedException
```

Example:

``` java
try {
    Integer value =
        blockingDeque.takeFirst();
} catch (InterruptedException e) {
    Thread.currentThread().interrupt();
}
```

Restoring the interrupt status is important when the current method
cannot fully handle the interruption.

------------------------------------------------------------------------

# PART 77 --- BOUNDED DEQUE

## 114. Capacity

A bounded blocking deque can limit the number of elements.

Example:

``` java
BlockingDeque<Integer> deque =
    new LinkedBlockingDeque<>(100);
```

Capacity:

``` text
100
```

This can help provide backpressure.

------------------------------------------------------------------------

# PART 78 --- BACKPRESSURE

## 115. Deque Backpressure

Suppose:

``` text
Producer → 1000 tasks/sec
Consumer → 100 tasks/sec
```

An unbounded backlog can consume increasing memory.

A bounded blocking deque can make the producer wait or reject/timed-out
insertion according to the chosen API.

------------------------------------------------------------------------

# PART 79 --- COMMON MISTAKES

## 116. Mistake: Thinking Deque Means FIFO Only

Incorrect:

``` text
Deque = FIFO only
```

Correct:

``` text
Deque = operations at both ends
```

It can implement:

``` text
FIFO
LIFO
```

------------------------------------------------------------------------

## 117. Mistake: Using ArrayList as Queue

Repeated:

``` java
list.remove(0);
```

is usually inefficient because elements must be shifted.

Use:

``` java
Deque<T> queue =
    new ArrayDeque<>();
```

for queue-style processing.

------------------------------------------------------------------------

## 118. Mistake: Assuming ArrayDeque Is Thread-Safe

It is not.

Use a concurrent implementation when needed.

------------------------------------------------------------------------

## 119. Mistake: Adding Null

``` java
ArrayDeque.add(null);
```

is invalid.

------------------------------------------------------------------------

## 120. Mistake: Assuming Random Access

Deque does not provide:

``` java
get(index)
```

as a core interface operation.

If indexed random access is the primary requirement, consider a `List`.

------------------------------------------------------------------------

# PART 80 --- INTERVIEW QUESTIONS

## 121. What Is Deque?

A double-ended queue allowing insertion, removal, and inspection at both
the front and back.

------------------------------------------------------------------------

## 122. Is Deque FIFO?

Not necessarily.

It can be used as:

``` text
FIFO
```

or:

``` text
LIFO
```

depending on operations.

------------------------------------------------------------------------

## 123. Difference Between Queue and Deque?

Queue provides a single-ended queue abstraction.

Deque extends Queue and exposes both ends.

------------------------------------------------------------------------

## 124. Difference Between `pollFirst()` and `removeFirst()`?

``` text
pollFirst()
→ null if empty

removeFirst()
→ NoSuchElementException if empty
```

------------------------------------------------------------------------

## 125. Difference Between `peekFirst()` and `getFirst()`?

``` text
peekFirst()
→ null if empty

getFirst()
→ exception if empty
```

------------------------------------------------------------------------

## 126. Is ArrayDeque Thread-Safe?

No.

------------------------------------------------------------------------

## 127. Does ArrayDeque Allow Null?

No.

------------------------------------------------------------------------

## 128. How Does Deque Work as Stack?

Use:

``` java
push()
pop()
```

Both operate at the front.

------------------------------------------------------------------------

## 129. How Does Deque Work as Queue?

Use:

``` java
offerLast()
pollFirst()
```

------------------------------------------------------------------------

## 130. Why Is ArrayDeque Usually Preferred Over LinkedList for Deque Use?

For many general in-memory workloads, its array-backed structure
provides good locality and avoids the per-element linked-node overhead
of `LinkedList`.

------------------------------------------------------------------------

# PART 81 --- ADVANCED INTERVIEW QUESTIONS

## 131. Why Does ArrayDeque Use Circular Storage?

To support efficient operations at both ends without shifting all
elements whenever the logical front changes.

------------------------------------------------------------------------

## 132. Why Are End Operations O(1)?

The implementation maintains logical positions for the front and back
instead of searching through the structure.

------------------------------------------------------------------------

## 133. Why Is Add O(1) Amortized Rather Than Always O(1)?

Because occasional resizing can require copying/rearranging storage.

Most insertions are constant time, but a resize can cost O(n).

------------------------------------------------------------------------

## 134. What Is a Monotonic Deque?

A deque maintained in monotonic order to efficiently solve problems such
as sliding-window maximum/minimum.

------------------------------------------------------------------------

## 135. Why Use Deque in Sliding Window Maximum?

Because elements that can no longer become the maximum can be removed
from the back, while the current best candidate remains at the front.

------------------------------------------------------------------------

# PART 82 --- DEQUE AND JAVA COLLECTION HIERARCHY

## 136. Hierarchy

``` text
Iterable
   ↓
Collection
   ↓
Queue
   ↓
Deque
   ↓
Implementations
   ├── ArrayDeque
   └── LinkedList
```

Concurrent branch:

``` text
BlockingQueue
   ↓
BlockingDeque
   ↓
LinkedBlockingDeque
```

------------------------------------------------------------------------

# PART 83 --- COMPLETE API CHECKLIST

## 137. Insertion

``` java
addFirst()
addLast()

offerFirst()
offerLast()
```

------------------------------------------------------------------------

## 138. Removal

``` java
removeFirst()
removeLast()

pollFirst()
pollLast()
```

------------------------------------------------------------------------

## 139. Inspection

``` java
getFirst()
getLast()

peekFirst()
peekLast()
```

------------------------------------------------------------------------

## 140. Occurrence Removal

``` java
removeFirstOccurrence()
removeLastOccurrence()
```

------------------------------------------------------------------------

## 141. Stack Operations

``` java
push()
pop()
```

------------------------------------------------------------------------

## 142. Queue Operations

``` java
add()
offer()

remove()
poll()

element()
peek()
```

------------------------------------------------------------------------

## 143. Collection Operations

``` java
size()
isEmpty()
contains()
iterator()
descendingIterator()
toArray()
addAll()
remove(Object)
removeAll()
retainAll()
containsAll()
clear()
removeIf()
stream()
parallelStream()
spliterator()
```

------------------------------------------------------------------------

# PART 84 --- MASTER COMPARISON

## 144. Deque Implementations

  Implementation          Deque   Thread-safe   Blocking   Null
  ----------------------- ------- ------------- ---------- ------
  `ArrayDeque`            Yes     No            No         No
  `LinkedList`            Yes     No            No         Yes
  `LinkedBlockingDeque`   Yes     Yes           Yes        No

------------------------------------------------------------------------

# PART 85 --- DECISION TREE

## 145. Which One?

``` text
Need normal double-ended operations?
             |
            YES
             ↓
         ArrayDeque
```

``` text
Need List + Deque behavior?
             |
            YES
             ↓
         LinkedList
```

``` text
Need concurrent blocking deque?
             |
            YES
             ↓
     LinkedBlockingDeque
```

------------------------------------------------------------------------

# PART 86 --- DEQUE MENTAL MODEL

## 146. Remember This

``` text
Deque
 │
 ├── First
 │    ├── addFirst
 │    ├── offerFirst
 │    ├── removeFirst
 │    ├── pollFirst
 │    ├── getFirst
 │    └── peekFirst
 │
 └── Last
      ├── addLast
      ├── offerLast
      ├── removeLast
      ├── pollLast
      ├── getLast
      └── peekLast
```

Stack:

``` text
push()
pop()
```

Queue:

``` text
offerLast()
pollFirst()
```

------------------------------------------------------------------------

# PART 87 --- 100% MASTER CHECKLIST

## 147. Beginner

-   [ ] What is Deque?
-   [ ] Double-ended queue
-   [ ] `Deque<E>`
-   [ ] First and last
-   [ ] `addFirst()`
-   [ ] `addLast()`
-   [ ] `offerFirst()`
-   [ ] `offerLast()`
-   [ ] `removeFirst()`
-   [ ] `removeLast()`
-   [ ] `pollFirst()`
-   [ ] `pollLast()`
-   [ ] `getFirst()`
-   [ ] `getLast()`
-   [ ] `peekFirst()`
-   [ ] `peekLast()`

------------------------------------------------------------------------

## 148. Intermediate

-   [ ] `ArrayDeque`
-   [ ] `LinkedList`
-   [ ] FIFO using Deque
-   [ ] LIFO using Deque
-   [ ] `push()`
-   [ ] `pop()`
-   [ ] `removeFirstOccurrence()`
-   [ ] `removeLastOccurrence()`
-   [ ] Iterator
-   [ ] Descending iterator
-   [ ] Null handling
-   [ ] Complexity
-   [ ] Memory behavior
-   [ ] Queue vs Deque
-   [ ] Stack vs Deque

------------------------------------------------------------------------

## 149. Advanced

-   [ ] Circular array concept
-   [ ] Resizing
-   [ ] Amortized complexity
-   [ ] Cache locality
-   [ ] Object allocation
-   [ ] `BlockingDeque`
-   [ ] `LinkedBlockingDeque`
-   [ ] Blocking operations
-   [ ] Bounded deque
-   [ ] Backpressure
-   [ ] Thread interruption
-   [ ] Concurrent design

------------------------------------------------------------------------

## 150. Expert

-   [ ] BFS
-   [ ] DFS
-   [ ] Sliding window
-   [ ] Monotonic deque
-   [ ] Palindrome algorithms
-   [ ] Undo/redo
-   [ ] Work stealing
-   [ ] Task scheduling
-   [ ] Cache algorithms
-   [ ] Concurrent work processing
-   [ ] Producer-consumer
-   [ ] Memory visibility
-   [ ] Performance analysis

------------------------------------------------------------------------

# PART 88 --- FINAL SUMMARY

`Deque` is one of the most useful Java collection abstractions because
it supports both ends.

### Normal Deque

``` java
Deque<T> deque =
    new ArrayDeque<>();
```

### FIFO Queue

``` java
deque.offerLast(value);
deque.pollFirst();
```

### LIFO Stack

``` java
deque.push(value);
deque.pop();
```

### Both Ends

``` java
deque.offerFirst(value);
deque.offerLast(value);

deque.pollFirst();
deque.pollLast();
```

### Concurrent Blocking Deque

``` java
BlockingDeque<T> deque =
    new LinkedBlockingDeque<>();
```

The most important mental model:

``` text
                 DEQUE
                   |
          ┌────────┴────────┐
          ↓                 ↓
        FRONT              BACK
          ↑                 ↑
       add/remove        add/remove
```

And:

``` text
FIFO:
offerLast() + pollFirst()

LIFO:
push() + pop()

Double-ended:
First + Last
```

------------------------------------------------------------------------

# QUICK REVISION

``` text
Deque = Double Ended Queue

Deque extends Queue.

ArrayDeque:
- fast general-purpose deque
- array-backed
- no null
- not thread-safe

LinkedList:
- implements List + Deque
- linked nodes
- allows null
- not thread-safe

BlockingDeque:
- concurrent
- blocking
- both ends

Queue behavior:
offerLast()
pollFirst()

Stack behavior:
push()
pop()

First:
addFirst()
offerFirst()
removeFirst()
pollFirst()
getFirst()
peekFirst()

Last:
addLast()
offerLast()
removeLast()
pollLast()
getLast()
peekLast()

Occurrence:
removeFirstOccurrence()
removeLastOccurrence()

Important algorithms:
BFS
DFS
Sliding Window
Monotonic Queue
Palindrome
Undo/Redo
Work Stealing

Main rule:

If your algorithm needs efficient operations
at both ends, think DEQUE.
```

------------------------------------------------------------------------

# END --- JAVA DEQUE 100% COMPLETE NOTES
