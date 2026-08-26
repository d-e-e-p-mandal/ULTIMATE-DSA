
# 1. Introduction
- An **Iterator** is an object that is used to traverse (visit) elements stored inside a container.
- Think of an iterator as a **generalized pointer**.
- Instead of using array indexes, STL containers use iterators to access elements.

**Example:**

```cpp
vector<int> v = {10,20,30};

vector<int>::iterator it = v.begin();
cout << *it;
```

**Output:** 10


---

# 2. What is an Iterator?

- An iterator is an object that points to an element inside a container.

It allows us to:
- Read elements
- Modify elements
- Traverse containers
- Work with STL algorithms

**Visual Representation**

```
vector

+----+----+----+----+
|10  |20  |30  |40  |
+----+----+----+----+
  ^
  |
 iterator
```

---

# 3. Why Iterators are Needed

- Different containers store data differently.
- Example:
    - **Array:** Continuous Memory
    - **List:** Nodes connected using pointers
    - **Map:** Balanced Binary Search Tree
    - **Unordered Map:** Hash Table
- Since every container has a different internal implementation, STL provides **iterators** so algorithms work with every container in the same way.

#### Example:
**Instead of**
```cpp
for(int i=0;i<n;i++)
```

**we write**
```cpp
for(auto it=v.begin(); it!=v.end(); it++)
```

---

# 4. Pointer vs Iterator

| Pointer | Iterator |
|----------|----------|
| Points to memory | Points to container element |
| Works mainly with arrays | Works with STL containers |
| Arithmetic available | Depends on iterator type |
| Built into language | Implemented by containers |
| Limited | Generic |

#### Example

**Pointer:**
```cpp
int arr[]={1,2,3};
int *p=arr;
cout<<*p;
```

**Iterator:**
```cpp
vector<int> v={1,2,3};
auto it=v.begin();
cout<<*it;
```

---

# 5. How Iterators Work

Container

```
10 20 30 40 50
 ^
 |
begin()
```

Move iterator

```
10 20 30 40 50
    ^
    |
   ++it
```

Move again

```
10 20 30 40 50
       ^
       |
      ++it
```

Last position

```
10 20 30 40 50
               ^
             end()
```

Notice:

`end()` does NOT point to the last element.

It points **one position after the last element**.

---