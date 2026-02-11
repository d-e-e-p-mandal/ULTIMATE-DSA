# 📌 1️⃣ Java Collections Framework (JCF)
Java Collections Framework is a set of interfaces + classes to store and manipulate groups of objects.

Package:
```java
import java.util.*;
```

📊 2️⃣ COLLECTION HIERARCHY
```
Iterable
   |
Collection
   ├── List
   ├── Set
   └── Queue
        └── Deque
Map (Separate hierarchy, not child of Collection)
```

⸻

🔹 3️⃣ COLLECTION INTERFACE (Root Interface)

Common methods available in List, Set, Queue:

Method	                    Description
add(E e)	                Add element
addAll(Collection c)	    Add all elements
remove(Object o)	        Remove element
removeAll(Collection c)	    Remove all matching
clear()	Remove all
size()	                        Number of elements
isEmpty()	Check empty
contains(Object o)	Check presence
containsAll(Collection c)	Check all exist
iterator()	Returns iterator
toArray()	Convert to array


⸻

🔹 4️⃣ LIST INTERFACE

📌 Ordered
📌 Allows duplicates
📌 Allows null

Implementations:
	•	ArrayList
	•	LinkedList
	•	Vector
	•	Stack

⸻

🟢 A) ArrayList

📌 Dynamic array
📌 Fast random access
📌 Slow insertion in middle

Important Methods

Method	Description
add(E e)	
add(int index, E e)	
get(int index)	
set(int index, E e)	
remove(int index)	
indexOf(Object o)	
lastIndexOf(Object o)	
subList(int from, int to)	

Time Complexity

Operation	Time
get()	O(1)
add()	O(1) amortized
remove()	O(n)


⸻

🟢 B) LinkedList

📌 Doubly Linked List
📌 Fast insertion/deletion
📌 Slow random access

Extra methods (Deque support):

Method	Description
addFirst()	
addLast()	
removeFirst()	
removeLast()	
getFirst()	
getLast()	

Time:

Operation	Time
get()	O(n)
add/remove	O(1)


⸻

🟢 C) Vector

📌 Same as ArrayList
📌 Synchronized (Thread safe)

Extra methods:

Method
capacity()
ensureCapacity()


⸻

🟢 D) Stack (extends Vector)

LIFO structure

Method
push(E e)
pop()
peek()
empty()
search(Object o)


⸻

🔹 5️⃣ SET INTERFACE

📌 No duplicates
📌 Unordered (except LinkedHashSet & TreeSet)

Implementations:
	•	HashSet
	•	LinkedHashSet
	•	TreeSet

⸻

🟢 A) HashSet

📌 Uses HashMap internally
📌 No order guarantee

Methods same as Collection.

Time:
	•	add() → O(1)
	•	remove() → O(1)

⸻

🟢 B) LinkedHashSet

📌 Maintains insertion order
📌 Slightly slower than HashSet

⸻

🟢 C) TreeSet

📌 Sorted
📌 Uses Red-Black Tree

Extra methods (SortedSet / NavigableSet):

Method
first()
last()
headSet()
tailSet()
subSet()
ceiling()
floor()
higher()
lower()
pollFirst()
pollLast()

Time:
	•	add() → O(log n)

⸻

🔹 6️⃣ QUEUE INTERFACE

📌 FIFO

Implementations:
	•	PriorityQueue
	•	LinkedList
	•	ArrayDeque

⸻

🟢 A) PriorityQueue

📌 Min Heap by default

Method
offer(E e)
poll()
peek()

Time:
	•	offer() → O(log n)
	•	poll() → O(log n)

⸻

🟢 B) ArrayDeque

📌 Faster than Stack
📌 No null allowed

Method
addFirst()
addLast()
removeFirst()
removeLast()
peekFirst()
peekLast()


⸻

🔹 7️⃣ MAP INTERFACE (Separate Hierarchy)

📌 Key-Value pair
📌 Keys unique

Implementations:
	•	HashMap
	•	LinkedHashMap
	•	TreeMap
	•	Hashtable
	•	ConcurrentHashMap

⸻

🟢 A) HashMap

📌 Unordered
📌 Allows one null key

Important Methods

Method
put(K,V)
putIfAbsent()
get(Object key)
getOrDefault()
remove(Object key)
replace()
containsKey()
containsValue()
keySet()
values()
entrySet()
forEach()

Time:
	•	put() → O(1)
	•	get() → O(1)

⸻

🟢 B) LinkedHashMap

📌 Maintains insertion order

⸻

🟢 C) TreeMap

📌 Sorted by key
📌 Red-Black Tree

Extra methods:

Method
firstKey()
lastKey()
headMap()
tailMap()
subMap()
ceilingKey()
floorKey()
higherKey()
lowerKey()

Time:
	•	put() → O(log n)

⸻

🟢 D) Hashtable

📌 Thread safe
📌 No null allowed

⸻

🟢 E) ConcurrentHashMap

📌 Thread safe
📌 Better performance than Hashtable

Extra:
	•	compute()
	•	computeIfAbsent()
	•	merge()

⸻

🔹 8️⃣ ITERATOR & LISTITERATOR

Iterator

Method
hasNext()
next()
remove()

ListIterator

Method
hasPrevious()
previous()
add()
set()


⸻

🔹 9️⃣ COLLECTIONS UTILITY CLASS

Static methods:

Method
sort(List)
reverse(List)
shuffle(List)
binarySearch(List)
max()
min()
frequency()
copy()
fill()
synchronizedList()


⸻

🔹 🔟 COMPARATOR vs COMPARABLE

Comparable

class Student implements Comparable<Student> {
    public int compareTo(Student s) {
        return this.age - s.age;
    }
}

Comparator

Comparator<Student> c = (a,b) -> a.age - b.age;


⸻

🎯 MOST IMPORTANT INTERVIEW POINTS
	1.	Difference between ArrayList & LinkedList
	2.	HashMap vs Hashtable
	3.	HashSet internally uses? → HashMap
	4.	TreeMap uses? → Red Black Tree
	5.	Fail-fast vs Fail-safe iterator
	6.	ConcurrentHashMap segmentation
	7.	Load factor in HashMap (default 0.75)
	8.	Initial capacity of HashMap (16)

⸻

🚀 If You Want

I can next give you:
	•	🔥 Internal working of HashMap (very important for MCA & interviews)
	•	🔥 Complete time complexity comparison table
	•	🔥 Java Collection MCQ interview sheet
	•	🔥 Java 8 Stream methods notes
	•	🔥 Diagram-based revision sheet (1-page printable)

Tell me which one you want next.