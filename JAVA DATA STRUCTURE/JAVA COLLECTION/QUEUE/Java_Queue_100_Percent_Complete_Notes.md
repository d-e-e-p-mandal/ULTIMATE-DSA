# Java Queue --- 100% Complete Notes

> **Goal:** Complete Java `Queue` coverage from beginner to advanced
> level, including interfaces, implementations, internal behavior,
> complexity, ordering, blocking queues, concurrent queues, priority
> queues, dequeues, iterators, null handling, performance, use cases,
> pitfalls, and interview concepts.

------------------------------------------------------------------------

# PART 1 --- QUEUE FUNDAMENTALS

## 1. What is a Queue?

A **Queue** is a data structure used to hold elements waiting to be
processed.

The traditional queue follows:

``` text
FIFO = First In, First Out
```

Example:

``` text
Insert:
10 → 20 → 30 → 40

Remove:
10 first
20 second
30 third
40 fourth
```

Real-world examples:

-   Printer jobs
-   Customer service lines
-   CPU scheduling
-   Network packet processing
-   Message processing
-   Task scheduling
-   Background jobs

Java provides the `Queue<E>` interface for queue-like data structures.

------------------------------------------------------------------------

## 2. Queue Interface

Package:

``` java
java.util.Queue
```

Declaration:

``` java
public interface Queue<E> extends Collection<E>
```

Therefore:

``` text
Iterable
   ↓
Collection
   ↓
Queue
   ↓
Implementations
```

Important implementations:

``` text
Queue
├── PriorityQueue
├── LinkedList
├── ArrayDeque
├── ConcurrentLinkedQueue
├── BlockingQueue
│   ├── ArrayBlockingQueue
│   ├── LinkedBlockingQueue
│   ├── PriorityBlockingQueue
│   ├── DelayQueue
│   └── SynchronousQueue
└── TransferQueue
    └── LinkedTransferQueue
```

------------------------------------------------------------------------

# PART 2 --- QUEUE API

## 3. Core Queue Methods

The most important methods are:

  Method        Meaning
  ------------- -----------------
  `add(e)`      Inserts element
  `offer(e)`    Inserts element
  `remove()`    Removes head
  `poll()`      Removes head
  `element()`   Reads head
  `peek()`      Reads head

There are two related method families.

### Exception-based

``` java
add()
remove()
element()
```

### Special-value-based

``` java
offer()
poll()
peek()
```

------------------------------------------------------------------------

## 4. `add()`

``` java
queue.add(10);
```

Adds an element.

If insertion cannot be performed, `add()` may throw an exception.

For bounded queues:

``` java
IllegalStateException
```

can be thrown when the queue is full.

------------------------------------------------------------------------

## 5. `offer()`

``` java
queue.offer(10);
```

Attempts to insert an element.

Unlike `add()`, it normally returns a result:

``` java
boolean result = queue.offer(10);
```

For a bounded queue:

``` text
success → true
failure → false
```

------------------------------------------------------------------------

## 6. `remove()`

``` java
int x = queue.remove();
```

Removes and returns the head.

If queue is empty:

``` text
NoSuchElementException
```

------------------------------------------------------------------------

## 7. `poll()`

``` java
Integer x = queue.poll();
```

Removes and returns the head.

If queue is empty:

``` text
null
```

is returned.

------------------------------------------------------------------------

## 8. `element()`

``` java
int x = queue.element();
```

Reads the head without removing it.

If empty:

``` text
NoSuchElementException
```

------------------------------------------------------------------------

## 9. `peek()`

``` java
Integer x = queue.peek();
```

Reads the head without removing it.

If empty:

``` text
null
```

------------------------------------------------------------------------

# PART 3 --- QUEUE METHOD TABLE

## 10. Queue Method Comparison

  Operation   Exception on failure/empty   Special value
  ----------- ---------------------------- ---------------
  Insert      `add()`                      `offer()`
  Remove      `remove()`                   `poll()`
  Inspect     `element()`                  `peek()`

Memory trick:

``` text
ADD     → OFFER
REMOVE  → POLL
ELEMENT → PEEK
```

For normal application code, `offer()`, `poll()`, and `peek()` are often
convenient because they communicate failure/empty states without
exceptions.

------------------------------------------------------------------------

# PART 4 --- CREATING A QUEUE

## 11. Queue Using LinkedList

``` java
Queue<Integer> queue = new LinkedList<>();

queue.offer(10);
queue.offer(20);
queue.offer(30);
```

------------------------------------------------------------------------

## 12. Queue Using ArrayDeque

``` java
Queue<Integer> queue = new ArrayDeque<>();

queue.offer(10);
queue.offer(20);
queue.offer(30);
```

For a normal non-concurrent FIFO queue, `ArrayDeque` is commonly
preferred over `LinkedList`.

------------------------------------------------------------------------

## 13. Queue Using PriorityQueue

``` java
Queue<Integer> queue = new PriorityQueue<>();

queue.offer(30);
queue.offer(10);
queue.offer(20);
```

Important:

`PriorityQueue` is **not FIFO**.

The head is determined by priority/natural ordering.

``` text
10
20
30
```

------------------------------------------------------------------------

# PART 5 --- FIFO BEHAVIOR

## 14. FIFO Queue Example

``` java
Queue<Integer> queue = new ArrayDeque<>();

queue.offer(10);
queue.offer(20);
queue.offer(30);

System.out.println(queue.poll());
System.out.println(queue.poll());
System.out.println(queue.poll());
```

Output:

``` text
10
20
30
```

Because:

``` text
10 entered first
10 leaves first
```

------------------------------------------------------------------------

## 15. Queue Visualization

``` text
             FIFO

offer(10)
offer(20)
offer(30)

HEAD                       TAIL
 ↓                           ↓
[10] → [20] → [30]
 ↑
poll()
```

After `poll()`:

``` text
HEAD
 ↓
[20] → [30]
```

------------------------------------------------------------------------

# PART 6 --- ITERATING A QUEUE

## 16. Enhanced For Loop

``` java
for (Integer value : queue) {
    System.out.println(value);
}
```

------------------------------------------------------------------------

## 17. Iterator

``` java
Iterator<Integer> iterator = queue.iterator();

while (iterator.hasNext()) {
    System.out.println(iterator.next());
}
```

Iteration order depends on the implementation.

Do not assume every `Queue` implementation iterates in FIFO order.

------------------------------------------------------------------------

## 18. Removing Through Iterator

``` java
Iterator<Integer> iterator = queue.iterator();

while (iterator.hasNext()) {
    Integer value = iterator.next();

    if (value == 20) {
        iterator.remove();
    }
}
```

Using the iterator's `remove()` is safer than structurally modifying
many collections directly during iteration.

------------------------------------------------------------------------

# PART 7 --- LINKEDLIST AS QUEUE

## 19. LinkedList

`LinkedList` implements:

``` text
List
Deque
Queue
```

Example:

``` java
Queue<String> queue = new LinkedList<>();

queue.offer("A");
queue.offer("B");
queue.offer("C");
```

------------------------------------------------------------------------

## 20. LinkedList Internal Structure

Conceptually:

``` text
head
 ↓
Node A ↔ Node B ↔ Node C
                         ↑
                        tail
```

Each node contains references to neighboring nodes.

Conceptually:

``` java
class Node<E> {
    E item;
    Node<E> next;
    Node<E> previous;
}
```

------------------------------------------------------------------------

## 21. LinkedList Queue Complexity

Typical operations:

  Operation                 Complexity
  ----------------------- ------------
  `offer()` at end                O(1)
  `poll()` at beginning           O(1)
  `peek()`                        O(1)
  `contains()`                    O(n)
  iteration                       O(n)
  indexed access                  O(n)

`LinkedList` is therefore capable of efficient queue-end operations.

However, node allocation and pointer chasing can make it less
cache-friendly than `ArrayDeque`.

------------------------------------------------------------------------

# PART 8 --- ARRAYDEQUE

## 22. What is ArrayDeque?

`ArrayDeque` is a resizable-array implementation of `Deque`.

Package:

``` java
java.util.ArrayDeque
```

It can be used as:

``` text
Queue
Deque
Stack
```

------------------------------------------------------------------------

## 23. ArrayDeque as Queue

``` java
Queue<Integer> queue = new ArrayDeque<>();

queue.offer(10);
queue.offer(20);
queue.offer(30);

System.out.println(queue.poll());
```

Output:

``` text
10
```

------------------------------------------------------------------------

## 24. ArrayDeque Internal Idea

It uses a circular/resizable array concept.

Conceptually:

``` text
       ┌───────────────┐
       ↓               │
[ ] [20] [30] [40] [ ] [ ]
 ↑                       ↑
head                    tail
```

The implementation can wrap around the underlying array.

When more capacity is needed, it grows.

------------------------------------------------------------------------

## 25. Why ArrayDeque Is Fast

Advantages include:

-   Array-based storage
-   Good cache locality
-   No per-element linked node object
-   Efficient insertion/removal at both ends
-   No synchronization overhead

Typical queue operations are amortized O(1).

------------------------------------------------------------------------

## 26. ArrayDeque Does Not Allow Null

This is important:

``` java
Queue<String> queue = new ArrayDeque<>();

queue.offer(null);
```

This throws:

``` text
NullPointerException
```

Why?

Because `poll()` uses `null` as the empty-queue result.

If `null` were allowed, it would be difficult to distinguish:

``` text
queue is empty
```

from:

``` text
queue contains null
```

------------------------------------------------------------------------

# PART 9 --- PRIORITYQUEUE

## 27. What is PriorityQueue?

Package:

``` java
java.util.PriorityQueue
```

It implements:

``` java
Queue<E>
```

But it does **not** represent a normal FIFO queue.

The head is the element with the highest priority according to the
queue's ordering.

With natural ordering, the smallest element is normally at the head.

------------------------------------------------------------------------

## 28. PriorityQueue Example

``` java
PriorityQueue<Integer> pq = new PriorityQueue<>();

pq.offer(30);
pq.offer(10);
pq.offer(20);

System.out.println(pq.poll());
```

Output:

``` text
10
```

------------------------------------------------------------------------

## 29. PriorityQueue Internal Structure

`PriorityQueue` is based on a **binary heap**.

For natural ordering it behaves as a min-heap.

Example:

``` text
        10
       /  \
     20    30
    / \
   40  50
```

The smallest element is at the root.

------------------------------------------------------------------------

## 30. PriorityQueue Complexity

  Operation            Complexity
  ------------------ ------------
  `peek()`                   O(1)
  `offer()`              O(log n)
  `poll()`               O(log n)
  `remove(Object)`           O(n)
  `contains()`               O(n)
  iteration                  O(n)

------------------------------------------------------------------------

## 31. PriorityQueue Does Not Sort Everything

Consider:

``` java
PriorityQueue<Integer> pq = new PriorityQueue<>();

pq.offer(30);
pq.offer(10);
pq.offer(20);
pq.offer(40);
```

Do not assume:

``` text
30 10 20 40
```

iteration is sorted.

The heap only guarantees the required ordering at the head.

To retrieve elements according to priority:

``` java
while (!pq.isEmpty()) {
    System.out.println(pq.poll());
}
```

------------------------------------------------------------------------

# PART 10 --- CUSTOM PRIORITY

## 32. Comparator With PriorityQueue

``` java
PriorityQueue<Integer> pq =
    new PriorityQueue<>(Comparator.reverseOrder());
```

Now the largest element has highest priority.

Example:

``` java
pq.offer(10);
pq.offer(30);
pq.offer(20);

System.out.println(pq.poll());
```

Output:

``` text
30
```

------------------------------------------------------------------------

## 33. PriorityQueue With Objects

``` java
class Task {
    String name;
    int priority;

    Task(String name, int priority) {
        this.name = name;
        this.priority = priority;
    }
}
```

Create:

``` java
PriorityQueue<Task> queue =
    new PriorityQueue<>(
        Comparator.comparingInt(task -> task.priority)
    );
```

Then:

``` java
queue.offer(new Task("Task A", 3));
queue.offer(new Task("Task B", 1));
queue.offer(new Task("Task C", 2));
```

The task with priority `1` is retrieved first.

------------------------------------------------------------------------

# PART 11 --- DEQUE

## 34. What is Deque?

`Deque` means:

``` text
Double Ended Queue
```

Package:

``` java
java.util.Deque
```

Declaration:

``` java
public interface Deque<E> extends Queue<E>
```

It allows insertion and removal from both ends.

``` text
HEAD                         TAIL
 ↓                             ↓
[10] → [20] → [30] → [40]
 ↑                             ↑
remove                         remove
add                            add
```

------------------------------------------------------------------------

## 35. Deque Methods

Important methods:

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
```

------------------------------------------------------------------------

# PART 12 --- DEQUE AS FIFO QUEUE

## 36. Using Deque as Queue

``` java
Deque<Integer> deque = new ArrayDeque<>();

deque.offerLast(10);
deque.offerLast(20);
deque.offerLast(30);

System.out.println(deque.pollFirst());
```

Output:

``` text
10
```

This gives FIFO behavior.

------------------------------------------------------------------------

# PART 13 --- DEQUE AS STACK

## 37. Using Deque as Stack

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

Therefore:

``` text
ArrayDeque
   ↓
Deque
   ├── FIFO Queue
   └── LIFO Stack
```

For modern Java code, `Deque` + `ArrayDeque` is generally preferred over
the legacy `Stack` class.

------------------------------------------------------------------------

# PART 14 --- BLOCKINGQUEUE

## 38. What is BlockingQueue?

Package:

``` java
java.util.concurrent.BlockingQueue
```

A `BlockingQueue` is designed for concurrent producer-consumer systems.

It can block a thread when:

``` text
queue is empty
```

or:

``` text
queue is full
```

depending on the operation and queue capacity.

------------------------------------------------------------------------

## 39. Producer-Consumer Model

``` text
Producer
   |
   | put()
   ↓
[ BlockingQueue ]
   |
   | take()
   ↓
Consumer
```

The queue becomes the communication mechanism between threads.

------------------------------------------------------------------------

# PART 15 --- BLOCKINGQUEUE METHODS

## 40. Four Operation Families

`BlockingQueue` has four major behavior types.

  Operation   Throws        Returns special value   Blocks     Times out
  ----------- ------------- ----------------------- ---------- ----------------------
  Insert      `add()`       `offer()`               `put()`    `offer(e,time,unit)`
  Remove      `remove()`    `poll()`                `take()`   `poll(time,unit)`
  Inspect     `element()`   `peek()`                ---        ---

------------------------------------------------------------------------

## 41. `put()`

``` java
queue.put(value);
```

If the bounded queue is full:

``` text
thread waits
```

until space becomes available or the thread is interrupted.

------------------------------------------------------------------------

## 42. `take()`

``` java
T value = queue.take();
```

If queue is empty:

``` text
thread waits
```

until an element becomes available or the thread is interrupted.

------------------------------------------------------------------------

## 43. Timed Operations

``` java
queue.offer(
    value,
    5,
    TimeUnit.SECONDS
);
```

And:

``` java
queue.poll(
    5,
    TimeUnit.SECONDS
);
```

The operation waits up to the specified duration.

------------------------------------------------------------------------

# PART 16 --- ARRAYBLOCKINGQUEUE

## 44. ArrayBlockingQueue

`ArrayBlockingQueue` is a bounded blocking queue backed by an array.

Example:

``` java
BlockingQueue<Integer> queue =
    new ArrayBlockingQueue<>(3);
```

Capacity:

``` text
3
```

------------------------------------------------------------------------

## 45. ArrayBlockingQueue Example

``` java
queue.put(10);
queue.put(20);
queue.put(30);
```

Now the queue is full.

Another:

``` java
queue.put(40);
```

will block until space becomes available.

------------------------------------------------------------------------

## 46. Fairness

`ArrayBlockingQueue` can optionally use fairness.

``` java
new ArrayBlockingQueue<>(10, true);
```

The fairness setting affects thread scheduling/order under contention.

Fairness can have performance implications, so it should be enabled when
its ordering semantics are actually required.

------------------------------------------------------------------------

# PART 17 --- LINKEDBLOCKINGQUEUE

## 47. LinkedBlockingQueue

`LinkedBlockingQueue` is a blocking queue based on linked nodes.

Example:

``` java
BlockingQueue<Integer> queue =
    new LinkedBlockingQueue<>();
```

It can be bounded:

``` java
BlockingQueue<Integer> queue =
    new LinkedBlockingQueue<>(100);
```

------------------------------------------------------------------------

## 48. Producer Example

``` java
class Producer implements Runnable {

    private final BlockingQueue<Integer> queue;

    Producer(BlockingQueue<Integer> queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        try {
            for (int i = 1; i <= 10; i++) {
                queue.put(i);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
```

------------------------------------------------------------------------

## 49. Consumer Example

``` java
class Consumer implements Runnable {

    private final BlockingQueue<Integer> queue;

    Consumer(BlockingQueue<Integer> queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        try {
            while (true) {
                Integer value = queue.take();
                System.out.println(value);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
```

------------------------------------------------------------------------

# PART 18 --- PRIORITYBLOCKINGQUEUE

## 50. PriorityBlockingQueue

`PriorityBlockingQueue` combines:

``` text
PriorityQueue
+
BlockingQueue
```

It provides priority-based retrieval for concurrent applications.

Example:

``` java
BlockingQueue<Integer> queue =
    new PriorityBlockingQueue<>();
```

------------------------------------------------------------------------

## 51. PriorityBlockingQueue Characteristics

Important:

-   Priority ordering
-   Thread-safe
-   Blocking retrieval
-   Normally unbounded
-   Uses priority-queue/heap concepts
-   `take()` waits when empty

Because it is not a bounded queue by default, it does not provide the
same bounded backpressure semantics as `ArrayBlockingQueue`.

------------------------------------------------------------------------

# PART 19 --- DELAYQUEUE

## 52. DelayQueue

`DelayQueue` is a specialized blocking queue.

Elements become available only after their delay expires.

Elements must implement:

``` java
Delayed
```

Concept:

``` text
Task
 ↓
delay not expired
 ↓
wait
 ↓
delay expires
 ↓
take()
```

------------------------------------------------------------------------

## 53. Delayed Example

``` java
class Job implements Delayed {

    private final long executeAt;

    Job(long delayMillis) {
        this.executeAt =
            System.currentTimeMillis() + delayMillis;
    }

    @Override
    public long getDelay(TimeUnit unit) {
        long delay =
            executeAt - System.currentTimeMillis();

        return unit.convert(
            delay,
            TimeUnit.MILLISECONDS
        );
    }

    @Override
    public int compareTo(Delayed other) {
        return Long.compare(
            getDelay(TimeUnit.MILLISECONDS),
            other.getDelay(TimeUnit.MILLISECONDS)
        );
    }
}
```

------------------------------------------------------------------------

# PART 20 --- SYNCHRONOUSQUEUE

## 54. SynchronousQueue

`SynchronousQueue` has no normal internal storage capacity.

Conceptually:

``` text
Producer
   |
   | handoff
   ↓
Consumer
```

A producer's insertion generally requires a corresponding consumer
operation.

Example:

``` java
BlockingQueue<String> queue =
    new SynchronousQueue<>();
```

------------------------------------------------------------------------

## 55. Use Cases

Useful for:

-   Direct thread handoff
-   Worker coordination
-   Thread-pool style designs
-   Message passing where no buffering is desired

------------------------------------------------------------------------

# PART 21 --- TRANSFERQUEUE

## 56. TransferQueue

`TransferQueue` extends `BlockingQueue`.

It provides:

``` java
transfer(E e)
```

The producer can wait until another thread receives the element.

Implementation:

``` java
LinkedTransferQueue
```

------------------------------------------------------------------------

## 57. LinkedTransferQueue

Example:

``` java
TransferQueue<String> queue =
    new LinkedTransferQueue<>();
```

Transfer:

``` java
queue.transfer("Hello");
```

The producer can wait for a consumer to receive the transferred element.

------------------------------------------------------------------------

# PART 22 --- CONCURRENTLINKEDQUEUE

## 58. ConcurrentLinkedQueue

Package:

``` java
java.util.concurrent.ConcurrentLinkedQueue
```

It is a thread-safe, non-blocking FIFO queue.

Example:

``` java
Queue<Integer> queue =
    new ConcurrentLinkedQueue<>();
```

------------------------------------------------------------------------

## 59. ConcurrentLinkedQueue Characteristics

It is:

-   Thread-safe
-   Non-blocking
-   FIFO
-   Suitable for concurrent producers/consumers
-   Unbounded in its normal API model

It does not provide:

``` java
take()
put()
```

because it is not a blocking queue.

------------------------------------------------------------------------

## 60. Example

``` java
ConcurrentLinkedQueue<Integer> queue =
    new ConcurrentLinkedQueue<>();

queue.offer(10);
queue.offer(20);

Integer value = queue.poll();
```

------------------------------------------------------------------------

# PART 23 --- THREAD SAFETY

## 61. Is Queue Thread-Safe?

Not every queue is thread-safe.

Examples:

``` text
ArrayDeque            → No
LinkedList             → No
PriorityQueue          → No
ConcurrentLinkedQueue  → Yes
ArrayBlockingQueue     → Yes
LinkedBlockingQueue    → Yes
PriorityBlockingQueue  → Yes
```

Do not assume that implementing `Queue` automatically makes an
implementation thread-safe.

------------------------------------------------------------------------

# PART 24 --- SYNCHRONIZED QUEUE WRAPPER

## 62. Collections.synchronizedCollection

You can wrap a queue:

``` java
Queue<Integer> queue =
    Collections.synchronizedCollection(
        new LinkedList<>()
    );
```

However, the exact generic type and API exposure should be considered
when choosing a wrapper.

For concurrent queue workloads, using a purpose-built concurrent
collection is often clearer.

------------------------------------------------------------------------

# PART 25 --- NULL HANDLING

## 63. Queue Null Rules

Null support depends on the implementation.

Examples:

``` text
ArrayDeque            → null not allowed
PriorityQueue          → null not allowed
ConcurrentLinkedQueue  → null not allowed
BlockingQueue          → null generally not allowed
LinkedList             → null allowed
```

------------------------------------------------------------------------

## 64. Why Concurrent Queues Reject Null

Methods such as:

``` java
poll()
```

may use:

``` text
null
```

to mean:

``` text
no element available
```

Therefore concurrent queue implementations generally reject null
elements to avoid ambiguity.

------------------------------------------------------------------------

# PART 26 --- QUEUE VS LIST

## 65. Queue vs List

  Feature            Queue                   List
  ------------------ ----------------------- ----------------------------
  Main purpose       Processing order        Ordered collection
  FIFO semantics     Common                  Not required
  Indexed access     Not part of Queue API   Supported
  Head operation     Yes                     No standard queue head API
  Duplicate values   Usually allowed         Usually allowed
  Examples           ArrayDeque              ArrayList

Use:

``` text
List → collection of elements
Queue → elements waiting for processing
```

------------------------------------------------------------------------

# PART 27 --- QUEUE VS DEQUE

## 66. Queue vs Deque

``` text
Queue
  ↓
Primarily one logical processing direction

Deque
  ↓
Both ends available
```

Example:

``` java
Queue<Integer> queue =
    new ArrayDeque<>();
```

versus:

``` java
Deque<Integer> deque =
    new ArrayDeque<>();
```

If you need both ends, use `Deque`.

------------------------------------------------------------------------

# PART 28 --- QUEUE VS PRIORITYQUEUE

## 67. FIFO vs Priority

Normal queue:

``` text
10 → 20 → 30

poll()
→ 10
```

Priority queue:

``` text
30
10
20

poll()
→ 10
```

The first inserted item is not necessarily the first removed item in
`PriorityQueue`.

------------------------------------------------------------------------

# PART 29 --- QUEUE VS STACK

## 68. FIFO vs LIFO

Queue:

``` text
FIFO

10 → 20 → 30
poll() → 10
```

Stack:

``` text
LIFO

10 → 20 → 30
pop() → 30
```

Modern Java:

``` java
Deque<Integer> stack = new ArrayDeque<>();
```

is generally preferred for stack behavior.

------------------------------------------------------------------------

# PART 30 --- QUEUE COMPLEXITY

## 69. Main Implementations

Typical complexity summary:

  ----------------------------------------------------------------------------------
  Implementation                        Insert        Remove head               Peek
  ------------------------- ------------------ ------------------ ------------------
  `LinkedList`                            O(1)               O(1)               O(1)

  `ArrayDeque`                  Amortized O(1)               O(1)               O(1)

  `PriorityQueue`                     O(log n)           O(log n)               O(1)

  `ConcurrentLinkedQueue`       Typically O(1)     Typically O(1)               O(1)
                               amortized-style                    
                                      behavior                    

  `ArrayBlockingQueue`                    O(1)               O(1)               O(1)

  `LinkedBlockingQueue`                   O(1)               O(1)               O(1)
  ----------------------------------------------------------------------------------

Exact concurrent-collection performance depends on contention,
implementation details, hardware, and workload.

------------------------------------------------------------------------

# PART 31 --- QUEUE MEMORY

## 70. Array-Based Queue

`ArrayDeque` stores references in an array.

Conceptually:

``` text
Object references
┌────┬────┬────┬────┐
│ 10 │ 20 │ 30 │ 40 │
└────┴────┴────┴────┘
```

Advantages:

-   Good locality
-   Less node-object overhead
-   Efficient traversal

------------------------------------------------------------------------

## 71. Linked Queue

`LinkedList` uses nodes.

``` text
Node → Node → Node
```

Each node carries references and object overhead.

This can increase memory usage compared with an array-backed structure.

------------------------------------------------------------------------

# PART 32 --- CAPACITY

## 72. Bounded Queue

A bounded queue has a maximum capacity.

Example:

``` java
BlockingQueue<Integer> queue =
    new ArrayBlockingQueue<>(100);
```

Maximum elements:

``` text
100
```

------------------------------------------------------------------------

## 73. Why Bounded Queues Matter

Bounded queues can provide:

``` text
Backpressure
```

Example:

``` text
Producer
   ↓
[capacity = 100]
   ↓
Consumer
```

If consumers are slower than producers, the queue eventually fills.

The producer can then:

``` text
block
or
reject/timeout
```

depending on the API used.

------------------------------------------------------------------------

# PART 33 --- BACKPRESSURE

## 74. What is Backpressure?

Backpressure means slowing or limiting producers when consumers cannot
keep up.

Example:

``` text
Producer: 1000 tasks/sec
Consumer: 100 tasks/sec
```

Without limits:

``` text
Queue → grows continuously
Memory → increases
```

With a bounded queue:

``` text
Queue → reaches capacity
Producer → waits/rejects
```

This helps control resource usage.

------------------------------------------------------------------------

# PART 34 --- PRODUCER CONSUMER

## 75. Complete Producer-Consumer Example

``` java
import java.util.concurrent.*;

public class Main {

    public static void main(String[] args)
            throws InterruptedException {

        BlockingQueue<Integer> queue =
            new ArrayBlockingQueue<>(5);

        Thread producer = new Thread(() -> {
            try {
                for (int i = 1; i <= 10; i++) {
                    queue.put(i);
                    System.out.println(
                        "Produced: " + i
                    );
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        });

        Thread consumer = new Thread(() -> {
            try {
                for (int i = 1; i <= 10; i++) {
                    Integer value = queue.take();

                    System.out.println(
                        "Consumed: " + value
                    );
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        });

        producer.start();
        consumer.start();

        producer.join();
        consumer.join();
    }
}
```

------------------------------------------------------------------------

# PART 35 --- QUEUE WITH EXECUTOR

## 76. ExecutorService and Queues

Java executors internally use task queues.

Example:

``` java
ExecutorService executor =
    Executors.newFixedThreadPool(4);
```

Tasks submitted using:

``` java
executor.submit(task);
```

can be queued until worker threads are able to execute them.

This is one reason queues are fundamental to concurrent systems.

------------------------------------------------------------------------

# PART 36 --- QUEUE IN WEB APPLICATIONS

## 77. Real-World Backend Example

Suppose an application receives:

``` text
1000 requests/sec
```

but a downstream service can process:

``` text
200 tasks/sec
```

A queue can separate:

``` text
Request intake
      ↓
    Queue
      ↓
Workers
      ↓
Database/API
```

This is asynchronous processing.

------------------------------------------------------------------------

# PART 37 --- MESSAGE QUEUES

## 78. Java Queue vs Message Broker

A Java queue:

``` text
JVM memory
```

Example:

``` java
BlockingQueue
```

A distributed message broker:

``` text
External service
```

Examples:

``` text
Kafka
RabbitMQ
ActiveMQ
Amazon SQS
Azure Service Bus
```

A Java `Queue` is not automatically a distributed messaging system.

------------------------------------------------------------------------

# PART 38 --- QUEUE ORDERING

## 79. FIFO Ordering

`ArrayDeque`:

``` text
FIFO
```

`LinkedList` used through Queue:

``` text
FIFO
```

`ConcurrentLinkedQueue`:

``` text
FIFO
```

------------------------------------------------------------------------

## 80. Priority Ordering

`PriorityQueue`:

``` text
Priority-based head
```

not strict FIFO.

If two elements have equivalent priority, application code should not
assume a stable insertion order unless the specific implementation/API
contract provides that guarantee.

------------------------------------------------------------------------

# PART 39 --- EQUALITY AND CONTAINS

## 81. `contains()`

``` java
queue.contains(20);
```

Most general queue implementations do not provide O(1) lookup by
arbitrary value.

Typical:

``` text
O(n)
```

If frequent membership lookup is required, a `Set` may be more
appropriate.

------------------------------------------------------------------------

# PART 40 --- REMOVE SPECIFIC ELEMENT

## 82. `remove(Object)`

``` java
queue.remove(20);
```

This removes a matching element.

For many queue implementations:

``` text
O(n)
```

This is different from:

``` java
poll();
```

which removes the head.

------------------------------------------------------------------------

# PART 41 --- CLEARING QUEUE

## 83. Clear

``` java
queue.clear();
```

Removes all elements.

After:

``` java
queue.isEmpty();
```

returns:

``` text
true
```

------------------------------------------------------------------------

# PART 42 --- SIZE

## 84. Queue Size

``` java
int size = queue.size();
```

For ordinary collections, this is typically O(1), though concurrent
collection semantics can differ and some concurrent size operations may
be approximate or expensive under concurrent mutation depending on the
implementation.

------------------------------------------------------------------------

# PART 43 --- DRAINING A BLOCKING QUEUE

## 85. `drainTo()`

`BlockingQueue` provides:

``` java
drainTo(Collection<? super E> c)
```

Example:

``` java
List<Integer> list = new ArrayList<>();

queue.drainTo(list);
```

This transfers available elements into another collection.

There is also:

``` java
queue.drainTo(list, 10);
```

to transfer up to a specified number.

------------------------------------------------------------------------

# PART 44 --- ARRAYDEQUE VS LINKEDLIST

## 86. Comparison

  Feature             ArrayDeque                    LinkedList
  ------------------- ----------------------------- -----------------
  Queue               Yes                           Yes
  Deque               Yes                           Yes
  Array-backed        Yes                           No
  Node objects        No per-element linked nodes   Yes
  Null                No                            Yes
  Cache locality      Generally better              Generally worse
  Queue performance   Excellent general choice      Good
  Stack use           Yes                           Yes

For a normal in-memory FIFO queue, `ArrayDeque` is generally the first
implementation to consider.

------------------------------------------------------------------------

# PART 45 --- PRIORITYQUEUE VS ARRAYDEQUE

## 87. Comparison

  Feature       ArrayDeque       PriorityQueue
  ------------- ---------------- ---------------
  FIFO          Yes              No
  Priority      No               Yes
  Head peek     O(1)             O(1)
  Insert        Amortized O(1)   O(log n)
  Remove head   O(1)             O(log n)
  Null          No               No
  Heap          No               Yes

Use:

``` text
ArrayDeque → FIFO
PriorityQueue → priority processing
```

------------------------------------------------------------------------

# PART 46 --- BLOCKINGQUEUE VS CONCURRENTLINKEDQUEUE

## 88. Comparison

  -----------------------------------------------------------------------
  Feature                 BlockingQueue           ConcurrentLinkedQueue
  ----------------------- ----------------------- -----------------------
  Thread-safe             Yes                     Yes

  Blocking                Yes                     No

  `put()`                 Yes                     No

  `take()`                Yes                     No

  Non-blocking            Some methods            Yes

  Backpressure            Can provide bounded     No built-in capacity
                          behavior                bound

  Producer-consumer       Excellent               Useful for non-blocking
                                                  designs
  -----------------------------------------------------------------------

------------------------------------------------------------------------

# PART 47 --- COMMON QUEUE MISTAKES

## 89. Mistake: Assuming PriorityQueue Is FIFO

Wrong:

``` text
PriorityQueue = FIFO
```

Correct:

``` text
PriorityQueue = priority-based
```

------------------------------------------------------------------------

## 90. Mistake: Assuming Every Queue Is Thread-Safe

Wrong:

``` java
Queue<Integer> q = new ArrayDeque<>();
```

and assuming multiple threads can safely modify it.

Correct:

Use an appropriate concurrent implementation when multiple threads
access the queue concurrently.

------------------------------------------------------------------------

## 91. Mistake: Using `remove()` When Empty Is Normal

If emptiness is expected:

``` java
Integer value = queue.poll();
```

may be clearer than:

``` java
queue.remove();
```

because `poll()` returns `null` when empty.

------------------------------------------------------------------------

## 92. Mistake: Adding Null to ArrayDeque

``` java
queue.offer(null);
```

is invalid for `ArrayDeque`.

------------------------------------------------------------------------

## 93. Mistake: Assuming Queue Iteration Is Sorted

For `PriorityQueue`:

``` java
for (Integer x : pq) {
    System.out.println(x);
}
```

does not mean sorted output.

Use:

``` java
while (!pq.isEmpty()) {
    System.out.println(pq.poll());
}
```

when you need repeated priority-order removal.

------------------------------------------------------------------------

# PART 48 --- QUEUE DESIGN CHOICE

## 94. Which Queue Should You Use?

### Normal FIFO

``` java
Queue<T> q = new ArrayDeque<>();
```

### Double-ended queue

``` java
Deque<T> q = new ArrayDeque<>();
```

### Priority processing

``` java
Queue<T> q = new PriorityQueue<>();
```

### Thread-safe non-blocking FIFO

``` java
Queue<T> q = new ConcurrentLinkedQueue<>();
```

### Bounded producer-consumer

``` java
BlockingQueue<T> q =
    new ArrayBlockingQueue<>(capacity);
```

### Linked blocking queue

``` java
BlockingQueue<T> q =
    new LinkedBlockingQueue<>(capacity);
```

### Delayed tasks

``` java
BlockingQueue<T> q =
    new DelayQueue<>();
```

### Direct handoff

``` java
BlockingQueue<T> q =
    new SynchronousQueue<>();
```

------------------------------------------------------------------------

# PART 49 --- INTERVIEW QUESTIONS

## 95. What Is Queue?

A collection designed for holding elements before processing, commonly
using FIFO ordering.

------------------------------------------------------------------------

## 96. Difference Between `poll()` and `remove()`?

``` text
poll()   → null if empty
remove() → exception if empty
```

------------------------------------------------------------------------

## 97. Difference Between `peek()` and `element()`?

``` text
peek()    → null if empty
element() → exception if empty
```

------------------------------------------------------------------------

## 98. Difference Between `add()` and `offer()`?

Both insert elements, but their behavior when insertion cannot be
completed differs:

``` text
add()   → may throw exception
offer() → returns false when insertion cannot be performed
```

This distinction is particularly important for bounded queues.

------------------------------------------------------------------------

## 99. Is PriorityQueue FIFO?

No.

It retrieves elements according to its ordering.

------------------------------------------------------------------------

## 100. Is ArrayDeque Thread-Safe?

No.

------------------------------------------------------------------------

## 101. Is ConcurrentLinkedQueue Blocking?

No.

It is a non-blocking concurrent queue.

------------------------------------------------------------------------

## 102. Which Queue Is Best for Producer-Consumer?

A suitable `BlockingQueue`, such as:

``` java
ArrayBlockingQueue
```

or:

``` java
LinkedBlockingQueue
```

depending on requirements.

------------------------------------------------------------------------

## 103. Why Does ArrayDeque Reject Null?

Because queue operations use `null` as an empty/failure result in APIs
such as `poll()`.

------------------------------------------------------------------------

## 104. Which Queue Uses Heap?

``` text
PriorityQueue
```

uses heap-based priority ordering.

------------------------------------------------------------------------

## 105. What Is a Blocking Queue?

A thread-safe queue that provides operations that can wait when
insertion/removal cannot proceed.

------------------------------------------------------------------------

# PART 50 --- ADVANCED QUEUE CONCEPTS

## 106. Blocking vs Non-Blocking

### Blocking

``` java
queue.take();
```

Thread can wait.

### Non-blocking

``` java
queue.poll();
```

Returns immediately.

For concurrent queues:

``` java
ConcurrentLinkedQueue
```

provides non-blocking operations.

------------------------------------------------------------------------

## 107. Lock-Based vs Lock-Free Concepts

Some concurrent queue implementations use synchronization/locks, while
others use non-blocking algorithms based on atomic operations and
compare-and-set techniques.

For example:

``` text
ConcurrentLinkedQueue
```

is designed as a non-blocking concurrent queue.

Understanding these implementation strategies is useful for
high-concurrency system design.

------------------------------------------------------------------------

# PART 51 --- ATOMIC OPERATIONS

## 108. Concurrent Queue Concept

In concurrent programming, operations may use atomic primitives such as:

``` text
CAS
Compare-And-Set
```

Conceptually:

``` text
read current value
      ↓
calculate new value
      ↓
CAS(old, new)
      ↓
success?
 ├── yes → done
 └── no  → retry
```

The exact implementation details are JDK-version dependent.

------------------------------------------------------------------------

# PART 52 --- QUEUE AND MEMORY VISIBILITY

## 109. Thread Communication

Concurrent queue implementations establish appropriate
memory-ordering/visibility guarantees through their concurrency
mechanisms.

Therefore, a correctly used concurrent queue can act as a communication
mechanism between threads.

Conceptually:

``` text
Producer
   ↓
Queue
   ↓
Consumer
```

The queue is more than storage; it can coordinate concurrent work.

------------------------------------------------------------------------

# PART 53 --- QUEUE AND CPU CACHE

## 110. Cache Locality

Array-backed structures generally have better spatial locality:

``` text
[element][element][element][element]
```

Linked structures may require pointer traversal:

``` text
Node → Node → Node → Node
```

This can affect real-world performance even when Big-O complexity is
similar.

Therefore:

``` text
O(1) != automatically fastest
```

Big-O and actual hardware behavior are different concepts.

------------------------------------------------------------------------

# PART 54 --- QUEUE AND GARBAGE COLLECTION

## 111. Object Allocation

Linked queues may create node objects.

Example conceptual structure:

``` text
Node
 ├── item
 └── next
```

More objects can mean more allocation and garbage-collection overhead.

Array-backed queues can reduce per-element object overhead because the
queue stores references in an array.

The element objects themselves still exist.

------------------------------------------------------------------------

# PART 55 --- QUEUE WITH GENERICS

## 112. Generic Queue

Prefer:

``` java
Queue<String> queue =
    new ArrayDeque<>();
```

instead of raw types:

``` java
Queue queue =
    new ArrayDeque();
```

Generics provide compile-time type safety.

------------------------------------------------------------------------

## 113. Queue of Custom Objects

``` java
Queue<Employee> employees =
    new ArrayDeque<>();

employees.offer(new Employee());
```

This is preferable to using `Object`:

``` java
Queue<Object>
```

when all elements have a known domain type.

------------------------------------------------------------------------

# PART 56 --- QUEUE AND IMMUTABILITY

## 114. Queue Mutability

Most queue implementations are mutable.

``` java
queue.offer(value);
queue.poll();
```

There is no general immutable `Queue` interface implementation analogous
to `List.of()` specifically for all queue semantics.

If immutability is required, design the API so callers do not receive
mutation access, or use an appropriate immutable/custom abstraction.

------------------------------------------------------------------------

# PART 57 --- QUEUE WITH STREAMS

## 115. Stream From Queue

``` java
queue.stream()
     .forEach(System.out::println);
```

Important:

A stream does not automatically consume the queue.

The queue remains unchanged.

------------------------------------------------------------------------

## 116. Polling Is Different

``` java
while (!queue.isEmpty()) {
    System.out.println(queue.poll());
}
```

This consumes/removes elements.

Compare:

``` text
stream() → read/process
poll()   → remove/process
```

------------------------------------------------------------------------

# PART 58 --- QUEUE AND SPLITERATOR

## 117. Spliterator

Queues inherit:

``` java
spliterator()
```

from the collection hierarchy.

Example:

``` java
queue.spliterator()
     .forEachRemaining(System.out::println);
```

The exact splitting and ordering characteristics depend on the
implementation.

------------------------------------------------------------------------

# PART 59 --- QUEUE API INHERITANCE

## 118. Queue Inheritance

``` text
Iterable
   ↓
Collection
   ↓
Queue
   ↓
Implementation
```

Therefore Queue inherits many Collection operations:

``` java
size()
isEmpty()
contains()
iterator()
toArray()
remove(Object)
containsAll()
addAll()
removeAll()
retainAll()
clear()
```

Queue adds:

``` java
add()
offer()
remove()
poll()
element()
peek()
```

------------------------------------------------------------------------

# PART 60 --- COMPLETE QUEUE API CHECKLIST

## 119. Core Methods

``` java
add(E e)
offer(E e)

remove()
poll()

element()
peek()
```

## Collection Methods

``` java
size()
isEmpty()
contains()
iterator()
toArray()
toArray(T[])
addAll()
remove(Object)
containsAll()
addAll()
removeAll()
retainAll()
clear()
removeIf()
stream()
parallelStream()
spliterator()
```

## Deque Methods

When using `Deque`:

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

push()
pop()
```

------------------------------------------------------------------------

# PART 61 --- MASTER COMPARISON

## 120. Java Queue Family

  Type                      FIFO            Priority   Blocking   Thread-Safe   Null
  ------------------------- --------------- ---------- ---------- ------------- ------
  `ArrayDeque`              Yes             No         No         No            No
  `LinkedList`              Yes             No         No         No            Yes
  `PriorityQueue`           No              Yes        No         No            No
  `ConcurrentLinkedQueue`   Yes             No         No         Yes           No
  `ArrayBlockingQueue`      Yes             No         Yes        Yes           No
  `LinkedBlockingQueue`     Yes             No         Yes        Yes           No
  `PriorityBlockingQueue`   No              Yes        Yes        Yes           No
  `DelayQueue`              Delay-based     Yes        Yes        Yes           No
  `SynchronousQueue`        Handoff         No         Yes        Yes           No
  `LinkedTransferQueue`     FIFO-oriented   No         Yes        Yes           No

------------------------------------------------------------------------

# PART 62 --- PRACTICAL DECISION TREE

## 121. Selecting a Queue

``` text
Need normal FIFO?
        |
       YES
        ↓
    ArrayDeque
```

``` text
Need both ends?
        |
       YES
        ↓
       Deque
        ↓
    ArrayDeque
```

``` text
Need priority?
        |
       YES
        ↓
  PriorityQueue
```

``` text
Need thread-safe non-blocking FIFO?
        |
       YES
        ↓
ConcurrentLinkedQueue
```

``` text
Need producer-consumer blocking?
        |
       YES
        ↓
  BlockingQueue
```

``` text
Need bounded capacity?
        |
       YES
        ↓
ArrayBlockingQueue
```

``` text
Need delayed availability?
        |
       YES
        ↓
   DelayQueue
```

``` text
Need direct handoff?
        |
       YES
        ↓
 SynchronousQueue
```

------------------------------------------------------------------------

# PART 63 --- REAL-WORLD EXAMPLES

## 122. Print Queue

``` text
User A → Job 1
User B → Job 2
User C → Job 3

Printer:
Job 1
Job 2
Job 3
```

Use FIFO queue semantics.

------------------------------------------------------------------------

## 123. Background Jobs

``` text
HTTP Request
     ↓
Queue
     ↓
Worker
     ↓
Database
```

A bounded `BlockingQueue` can be useful for local in-process work
scheduling.

------------------------------------------------------------------------

## 124. CPU Scheduling

Tasks:

``` text
T1
T2
T3
T4
```

A scheduler may use different queue policies:

``` text
FIFO
Priority
Round Robin
Delay-based
```

The data structure depends on the scheduling policy.

------------------------------------------------------------------------

## 125. BFS

Breadth-First Search commonly uses a queue.

``` java
Queue<Node> queue = new ArrayDeque<>();

queue.offer(start);

while (!queue.isEmpty()) {
    Node current = queue.poll();

    // process current
}
```

BFS explores nodes level by level.

------------------------------------------------------------------------

# PART 64 --- QUEUE IN ALGORITHMS

## 126. BFS Pattern

``` text
Start
 ↓
Queue
 ↓
Neighbors
 ↓
Queue
 ↓
Next level
```

Complexity for graph BFS with adjacency-list representation:

``` text
O(V + E)
```

where:

``` text
V = vertices
E = edges
```

------------------------------------------------------------------------

## 127. Sliding Window

Deque-based algorithms can efficiently maintain candidates for a sliding
window.

Example problems:

``` text
Sliding Window Maximum
Monotonic Queue
```

These often use:

``` java
Deque<Integer>
```

rather than a plain FIFO queue.

------------------------------------------------------------------------

# PART 65 --- MONOTONIC QUEUE

## 128. What Is a Monotonic Queue?

A monotonic deque maintains elements in increasing or decreasing order
according to an algorithm's requirement.

For maximum sliding window:

``` text
largest candidate
      ↓
front
```

Elements that can no longer become the answer are removed.

This is an algorithmic use of `Deque`.

------------------------------------------------------------------------

# PART 66 --- PRIORITYQUEUE IN ALGORITHMS

## 129. Common Uses

`PriorityQueue` is commonly used for:

-   Dijkstra's algorithm
-   Prim's algorithm
-   K-way merge
-   Top K problems
-   Scheduling
-   Huffman coding
-   Best-first search
-   A\* search

------------------------------------------------------------------------

# PART 67 --- K-WAY MERGE

## 130. Concept

Suppose:

``` text
List 1 → 1 4 7
List 2 → 2 5 8
List 3 → 3 6 9
```

A priority queue can keep the smallest current element from each list.

``` text
PriorityQueue
 ├── 1
 ├── 2
 └── 3
```

Repeatedly remove the smallest and insert the next element from that
list.

------------------------------------------------------------------------

# PART 68 --- DSA QUEUE PATTERNS

## 131. Important Patterns

Learn these:

``` text
FIFO Queue
BFS
Multi-source BFS
Level-order traversal
Monotonic Queue
Priority Queue
Heap
Producer-Consumer
Sliding Window
Task Scheduling
Rate Limiting
```

------------------------------------------------------------------------

# PART 69 --- COMMON JAVA CODE PATTERNS

## 132. FIFO

``` java
Queue<Integer> q = new ArrayDeque<>();

q.offer(1);
q.offer(2);
q.offer(3);

while (!q.isEmpty()) {
    int x = q.poll();
    System.out.println(x);
}
```

------------------------------------------------------------------------

## 133. Priority

``` java
Queue<Integer> q = new PriorityQueue<>();

q.offer(30);
q.offer(10);
q.offer(20);

while (!q.isEmpty()) {
    System.out.println(q.poll());
}
```

Output:

``` text
10
20
30
```

------------------------------------------------------------------------

## 134. Deque

``` java
Deque<Integer> dq = new ArrayDeque<>();

dq.offerFirst(10);
dq.offerLast(20);

System.out.println(dq.pollFirst());
System.out.println(dq.pollLast());
```

------------------------------------------------------------------------

## 135. Blocking Queue

``` java
BlockingQueue<Integer> q =
    new ArrayBlockingQueue<>(10);

q.put(10);

int value = q.take();
```

------------------------------------------------------------------------

# PART 70 --- COMMON EXCEPTIONS

## 136. `NoSuchElementException`

Can occur with:

``` java
remove()
element()
```

when the queue is empty.

------------------------------------------------------------------------

## 137. `IllegalStateException`

Can occur when:

``` java
add()
```

is used on a bounded queue that cannot accept another element.

------------------------------------------------------------------------

## 138. `NullPointerException`

May occur when inserting null into implementations that reject null.

Example:

``` java
new ArrayDeque<>().offer(null);
```

------------------------------------------------------------------------

## 139. `InterruptedException`

Blocking methods such as:

``` java
put()
take()
offer(e, timeout, unit)
poll(timeout, unit)
```

can throw `InterruptedException`.

Correct handling commonly restores the interrupt status:

``` java
catch (InterruptedException e) {
    Thread.currentThread().interrupt();
}
```

------------------------------------------------------------------------

# PART 71 --- BEST PRACTICES

## 140. Program to the Interface

Prefer:

``` java
Queue<Integer> queue =
    new ArrayDeque<>();
```

instead of:

``` java
ArrayDeque<Integer> queue =
    new ArrayDeque<>();
```

when the code only needs Queue operations.

------------------------------------------------------------------------

## 141. Use Deque When Both Ends Are Needed

``` java
Deque<Integer> deque =
    new ArrayDeque<>();
```

Do not force a `Queue` abstraction when the algorithm requires both
ends.

------------------------------------------------------------------------

## 142. Use BlockingQueue for Thread Coordination

Avoid manually implementing:

``` text
wait()
notify()
```

for ordinary producer-consumer problems when a suitable `BlockingQueue`
directly models the requirement.

------------------------------------------------------------------------

## 143. Prefer Bounded Queues for Resource Protection

When workload can grow without limit, consider a capacity limit.

This helps prevent unbounded in-memory backlog.

------------------------------------------------------------------------

# PART 72 --- PERFORMANCE CHECKLIST

## 144. Performance Questions

Before choosing a queue, ask:

1.  Is it FIFO?
2.  Do I need priority?
3.  Do I need both ends?
4.  Is it single-threaded?
5.  Is it multi-threaded?
6.  Should operations block?
7.  Should capacity be bounded?
8.  Do I need timeouts?
9.  Is null required?
10. Is memory usage important?
11. Is cache locality important?
12. Is arbitrary lookup required?
13. Is ordering stable for equal priorities required?
14. Is the queue local to one JVM or distributed?

------------------------------------------------------------------------

# PART 73 --- JAVA QUEUE MENTAL MODEL

## 145. Simple Mental Model

Remember:

``` text
Queue
│
├── FIFO
│
├── ArrayDeque
│
├── LinkedList
│
├── PriorityQueue
│
├── ConcurrentLinkedQueue
│
└── BlockingQueue
     │
     ├── ArrayBlockingQueue
     ├── LinkedBlockingQueue
     ├── PriorityBlockingQueue
     ├── DelayQueue
     └── SynchronousQueue
```

And:

``` text
Deque
│
├── FIFO Queue
└── LIFO Stack
```

------------------------------------------------------------------------

# PART 74 --- 100% MASTER CHECKLIST

## 146. Beginner

-   [ ] What is Queue?
-   [ ] FIFO
-   [ ] Queue interface
-   [ ] `add()`
-   [ ] `offer()`
-   [ ] `remove()`
-   [ ] `poll()`
-   [ ] `element()`
-   [ ] `peek()`
-   [ ] Queue iteration
-   [ ] Queue size
-   [ ] Queue empty check

------------------------------------------------------------------------

## 147. Intermediate

-   [ ] LinkedList as Queue
-   [ ] ArrayDeque
-   [ ] PriorityQueue
-   [ ] Deque
-   [ ] FIFO vs LIFO
-   [ ] Queue vs List
-   [ ] Queue vs Deque
-   [ ] Queue vs PriorityQueue
-   [ ] Null handling
-   [ ] Time complexity
-   [ ] Memory behavior

------------------------------------------------------------------------

## 148. Advanced

-   [ ] BlockingQueue
-   [ ] ArrayBlockingQueue
-   [ ] LinkedBlockingQueue
-   [ ] PriorityBlockingQueue
-   [ ] DelayQueue
-   [ ] SynchronousQueue
-   [ ] TransferQueue
-   [ ] LinkedTransferQueue
-   [ ] ConcurrentLinkedQueue
-   [ ] Producer-consumer
-   [ ] Backpressure
-   [ ] Thread interruption
-   [ ] Timed operations
-   [ ] `drainTo()`

------------------------------------------------------------------------

## 149. Expert

-   [ ] Heap internals
-   [ ] Circular-buffer concepts
-   [ ] Concurrent queues
-   [ ] Lock-based vs non-blocking designs
-   [ ] CAS concepts
-   [ ] Memory visibility
-   [ ] Cache locality
-   [ ] Garbage-collection implications
-   [ ] Queue capacity design
-   [ ] Scheduling systems
-   [ ] BFS
-   [ ] Monotonic queue
-   [ ] Priority-based algorithms
-   [ ] Distributed message queues
-   [ ] Backpressure architecture

------------------------------------------------------------------------

# PART 75 --- FINAL SUMMARY

Java Queue is not a single data structure. It is an abstraction with
multiple implementations designed for different requirements.

### Normal FIFO

``` java
Queue<T> queue = new ArrayDeque<>();
```

### Double-ended

``` java
Deque<T> deque = new ArrayDeque<>();
```

### Priority

``` java
Queue<T> queue = new PriorityQueue<>();
```

### Concurrent FIFO

``` java
Queue<T> queue =
    new ConcurrentLinkedQueue<>();
```

### Blocking producer-consumer

``` java
BlockingQueue<T> queue =
    new ArrayBlockingQueue<>(100);
```

### Delayed processing

``` java
BlockingQueue<T> queue =
    new DelayQueue<>();
```

### Direct thread handoff

``` java
BlockingQueue<T> queue =
    new SynchronousQueue<>();
```

The most important concepts to remember are:

``` text
Queue
  ↓
FIFO

Deque
  ↓
Both ends

PriorityQueue
  ↓
Priority

BlockingQueue
  ↓
Producer / Consumer

ConcurrentLinkedQueue
  ↓
Non-blocking concurrent FIFO

ArrayDeque
  ↓
General-purpose in-memory FIFO/Deque

ArrayBlockingQueue
  ↓
Bounded concurrent queue
```

------------------------------------------------------------------------

# QUICK INTERVIEW REVISION

``` text
Queue → FIFO

add()    → insert / exception possible
offer()  → insert / false on failure

remove() → remove / exception if empty
poll()   → remove / null if empty

element() → inspect / exception if empty
peek()    → inspect / null if empty

ArrayDeque → fast general FIFO/Deque, not thread-safe
LinkedList → Queue + Deque + List
PriorityQueue → heap-based priority queue
Deque → both ends
BlockingQueue → blocking producer-consumer
ConcurrentLinkedQueue → non-blocking concurrent FIFO

PriorityQueue:
offer → O(log n)
poll  → O(log n)
peek  → O(1)

ArrayDeque:
offer/poll/peek → generally O(1), insertion growth amortized

Queue is an interface.
Choose implementation based on ordering,
concurrency, capacity, and performance requirements.
```

------------------------------------------------------------------------

# END --- JAVA QUEUE 100% COMPLETE NOTES
