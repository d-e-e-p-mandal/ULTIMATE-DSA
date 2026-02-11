# 📘 ARRAYLIST 
ArrayList is a class in Java which implements the List interface.

It is:
	•	Dynamic array (size increases automatically)
	•	Allows duplicate values
	•	Maintains insertion order
	•	Allows null values
	•	Not thread safe

Package:
```java
import java.util.ArrayList;
```

🔹 2️⃣ How to Declare

Normal way
```java
ArrayList<String> list = new ArrayList<String>();
```
Recommended way
```java
List<String> list = new ArrayList<>();
```

⸻

🔹 3️⃣ Constructors
1.	Default constructor
```java
ArrayList<E> list = new ArrayList<>();
```
2.	With initial capacity
```java
ArrayList<E> list = new ArrayList<>(20);
```
3.	From another collection
```java
ArrayList<E> list = new ArrayList<>(collection);

```

🔹 1️⃣ Using Arrays.asList() 
```java
ArrayList<Integer> list = new ArrayList<>(Arrays.asList(1, 2, 3));

```

2️⃣ Using List.of() (Java 9+)
```java
ArrayList<Integer> list = new ArrayList<>(List.of(1, 2, 3));
```

4️⃣ Double Brace Initialization (Not Recommended)
```java
ArrayList<Integer> list = new ArrayList<Integer>() {{
    add(1);
    add(2);
    add(3);
}};
```

🔹 4️⃣ Internal Working
	•	Default capacity = 10
	•	When full → increases size by 50%
	•	Internally uses array

Example:

[10, 20, 30]


⸻

🔹 5️⃣ All Methods of ArrayList

⸻

✅ Adding Methods

### boolean add(E e)
```java
ArrayList<String> list = new ArrayList<>();
list.add("Apple");
```

### void add(int index, E element)
```java
ArrayList<String> list = new ArrayList<>();

        list.add("Apple");
        list.add("Mango");

        list.add(1, "Banana");   // insert at index 1
```
### boolean addAll(Collection c)
```java
ArrayList<String> list1 = new ArrayList<>();
        list1.add("A");
        list1.add("B");

        ArrayList<String> list2 = new ArrayList<>();
        list2.add("C");
        list2.add("D");

        list1.addAll(list2);
```
### boolean addAll(int index, Collection c)
```java
rrayList<String> list1 = new ArrayList<>();
        list1.add("A");
        list1.add("D");

        ArrayList<String> list2 = new ArrayList<>();
        list2.add("B");
        list2.add("C");

        list1.addAll(1, list2);   // insert at index 1
```

✅ Example 1 (Copy from another ArrayList)
```java
import java.util.*;

public class Main {
    public static void main(String[] args) {

        ArrayList<String> list1 = new ArrayList<>();
        list1.add("Apple");
        list1.add("Banana");
        list1.add("Mango");

        // Create new list from existing list
        ArrayList<String> list2 = new ArrayList<>(list1);

        System.out.println("Original List: " + list1);
        System.out.println("Copied List: " + list2);
    }
}
```
Output:
Original List: [Apple, Banana, Mango]
Copied List: [Apple, Banana, Mango]

👉 list2 is a copy of list1.

⸻

✅ Example 2 (Copy from HashSet)

You can copy from any Collection (Set, List, etc.)
```java
import java.util.*;

public class Main {
    public static void main(String[] args) {

        HashSet<String> set = new HashSet<>();
        set.add("A");
        set.add("B");
        set.add("C");

        ArrayList<String> list = new ArrayList<>(set);

        System.out.println(list);
    }
}
```
👉 Converts Set into ArrayList.
⸻

✅ Example 3 (Copy from LinkedList)
```java
import java.util.*;

public class Main {
    public static void main(String[] args) {

        LinkedList<Integer> linkedList = new LinkedList<>();
        linkedList.add(10);
        linkedList.add(20);
        linkedList.add(30);

        ArrayList<Integer> arrayList = new ArrayList<>(linkedList);

        System.out.println(arrayList);
    }
}
```

⸻

🎯 Important Point
	•	It copies elements
	•	It does NOT link both lists
	•	If you change original list → copied list will NOT change

Example:

list1.add("Orange");
System.out.println(list2);

👉 list2 remains same.

⸻


✅ Access Method

E get(int index)

list.get(index);
```java
ArrayList<String> list = new ArrayList<>();
        list.add("Apple");
        list.add("Banana");
        list.add("Mango");

        System.out.println(list.get(1));  // Banana
```
⸻

✅ Update Method

E set(int index, E element)

list.set(index, element);

```java
list.add("Apple");
list.add("Banana");
list.add("Mango");

list.set(1, "Orange");   // replace Banana

System.out.println(list);
```


⸻

✅ Remove Methods

E remove(int index)
```java
ArrayList<String> list = new ArrayList<>();
list.add("A");
list.add("B");
list.add("C");

list.remove(1);   // removes "B"

System.out.println(list); //[A, C]
```

boolean remove(Object o)
```java
ArrayList<String> list = new ArrayList<>();
list.add("A");
list.add("B");
list.add("C");

list.remove("B");

System.out.println(list); //[A, C]
```

boolean removeAll(Collection c)
```java
ArrayList<String> list = new ArrayList<>(Arrays.asList("A","B","C","D"));
ArrayList<String> removeList = new ArrayList<>(Arrays.asList("B","C"));

list.removeAll(removeList);

System.out.println(list); // [A, D]
```

boolean retainAll(Collection c)
```java
ArrayList<String> list = new ArrayList<>(Arrays.asList("A","B","C","D"));
ArrayList<String> keepList = new ArrayList<>(Arrays.asList("B","C"));

list.retainAll(keepList);

System.out.println(list); // [B, C]
```

void clear()
```java
ArrayList<String> list = new ArrayList<>(Arrays.asList("A","B","C"));

list.clear();

System.out.println(list); //[]
```


boolean removeIf(Predicate filter)
```java
ArrayList<Integer> list = new ArrayList<>(Arrays.asList(1,2,3,4,5));

list.removeIf(n -> n % 2 == 0);   // remove even numbers

System.out.println(list); // [1, 3, 5]
```

⸻

✅ Searching Methods

boolean contains(Object o)
boolean containsAll(Collection c)
int indexOf(Object o)
int lastIndexOf(Object o)


⸻

✅ Size Methods

int size()
boolean isEmpty()


⸻

✅ Conversion Methods

Object[] toArray()
<T> T[] toArray(T[] a)


⸻

✅ Iterator Methods

Iterator<E> iterator()
ListIterator<E> listIterator()
ListIterator<E> listIterator(int index)


⸻

✅ SubList

List<E> subList(int fromIndex, int toIndex)


⸻

✅ Sorting & Replace (Java 8)

void sort(Comparator c)
void replaceAll(UnaryOperator operator)
void forEach(Consumer action)
Spliterator spliterator()


⸻

✅ Capacity Methods (Special)

void ensureCapacity(int minCapacity)
void trimToSize()


⸻

✅ Clone Method

Object clone()


⸻

✅ Methods from Object Class

boolean equals(Object o)
int hashCode()
String toString()


⸻

🔹 6️⃣ Simple Example Program

import java.util.*;

public class Main {
    public static void main(String[] args) {

        ArrayList<String> list = new ArrayList<>();

        list.add("Apple");
        list.add("Banana");
        list.add("Mango");

        System.out.println(list);

        list.remove("Banana");

        System.out.println(list.get(1));

        list.set(1, "Orange");

        System.out.println(list.size());

        list.clear();

        System.out.println(list.isEmpty());
    }
}


⸻

🔹 7️⃣ Time Complexity
	•	get() → O(1)
	•	add() → O(1)
	•	remove() → O(n)
	•	search → O(n)

⸻

🔹 8️⃣ Advantages
	•	Dynamic size
	•	Easy to use
	•	Fast random access

⸻

🔹 9️⃣ Disadvantages
	•	Slow insertion in middle
	•	Not thread safe

⸻

🔹 🔟 Important Points
	•	Default capacity = 10
	•	Grows automatically
	•	Allows duplicates
	•	Allows null
	•	Implements RandomAccess
