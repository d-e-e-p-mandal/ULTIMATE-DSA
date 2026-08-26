# C++ `std::move()`:

### What is `std::move()`?
- `std::move()` is a function introduced in **C++11**.
- It converts an object into an **rvalue reference** so that its resources can be **moved** instead of **copied**.




### Why Do We Need `move()`?
**Suppose we have:**
```cpp
vector<int> a = {1,2,3};
```

**When we copy:**
```cpp
vector<int> b = a;
```
- A new memory block is created and all elements are copied.

```text
a --> [1 2 3]
b --> [1 2 3]
```
- This can be expensive for large objects.

**Instead of copying, we can move:**
```cpp
vector<int> b = move(a);
```

**After:**
```
a --> empty
b --> [1 2 3]
```
- Now ownership of memory is transferred.
- No element-by-element copy.


### Important Point

- `std::move()` itself does NOT move anything.

- Nothing happens.
- It only converts the object into an rvalue reference.

- The actual move happens when a:
  - Move Constructor
  - Move Assignment Operator

- receives it.


------


## Move Constructor
- Used when a **new object is being created**.

## Syntax
```cpp
ClassName obj2(move(obj1));
```

**or:**

```cpp
ClassName obj2 = move(obj1);
```

**Example 1:**
```cpp
vector<int> a = {1,2,3};
vector<int> b(move(a));
```

**Example 2:**
```cpp
vector<int> a = {1,2,3};
vector<int> b = move(a);
```

### Constructor Signature
```cpp
ClassName(ClassName&& other);
```

**Example:**
```cpp
vector(vector&& other);
```


## Move Assignment Operator
- Used when the object already exists.

## Syntax
```cpp
obj2 = move(obj1);
```

**Example:**
```cpp
vector<int> a = {1,2,3};
vector<int> b;

b = move(a);
```


### Assignment Signature
```cpp
ClassName& operator=(ClassName&& other);
```

**Example:**
```cpp
vector& operator=(vector&& other);
```

### Move Constructor vs Move Assignment

**Move Constructor:**

- Creates a new object.
```cpp
vector<int> b(move(a));

vector<int> b = move(a);
```


**Move Assignment:**
- Assigns to an existing object.
```cpp
vector<int> b;

b = move(a);
```

### After Moving

```cpp
vector<int> a = {1,2,3};
vector<int> b = move(a);
```

- The object `a` still exists but empty.

```cpp
a.push_back(10);
a.clear();
```
- Allowed.
- But do not depend on its old values.

```cpp
cout << a[0];
```

The state is unspecified.


#### Real-Life Example
- Suppose you own a house key.

**Copy:**
```text
Person A ----> Key Copy ----> Person B
```
- Now both have keys.

**Move:**
```text
Person A ----> Gives Original Key ----> Person B
```

- Person A no longer owns the key.
- This is exactly how move semantics works.


--------------------------------
================================

# Common Uses

### Pair Example
```cpp
pair<int,int> p1(1,2);
pair<int,int> p2(move(p1));
```

### Moving Vector
```cpp
vector<int> v1 = {1,2,3};
vector<int> v2 = move(v1);
```

### Moving String

```cpp
string s1 = "Hello";
string s2 = move(s1);
```


------------------


# Summary Table

| Statement | Uses |
|------------|--------|
| `vector<int> b(move(a));` | Move Constructor |
| `vector<int> b = move(a);` | Move Constructor |
| `b = move(a);` | Move Assignment |
| `pair<int,int> p2(move(p1));` | Move Constructor |
| `p2 = move(p1);` | Move Assignment |
| `move(obj)` | Converts to rvalue reference |
| `move(obj)` alone | Does nothing |
| Main Benefit | Avoid expensive copies |

# Interview One-Liner

> `std::move()` converts an object into an rvalue reference, allowing ownership of resources to be transferred instead of copied, improving performance.