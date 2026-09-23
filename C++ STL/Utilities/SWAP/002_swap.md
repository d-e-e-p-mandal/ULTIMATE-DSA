# C++ `swap()`:
- `swap()` is a utility function in C++ used to **exchange the values of two objects**.
- Instead of manually using a temporary variable, `swap()` exchanges values efficiently.

It is available in the Standard Library and is widely used with:
- Variables
- Arrays
- STL Containers
- Strings
- Pairs
- Tuples
- Smart Pointers
- Custom Classes

---

### Header File
```cpp
#include <utility>
```

or:
```cpp
#include <algorithm>
```


---
## Syntax
```cpp
swap(a, b);
```

---

# Parameters

| Parameter | Description |
|-----------|-------------|
| a | First object |
| b | Second object |

Both objects must have the same type (or be swappable).

---

# Return Type

```cpp
void
```

It simply exchanges values.

---

# How swap Works

Before

```text
a = 10
b = 20
```

After

```cpp
swap(a, b);
```

Result

```text
a = 20
b = 10
```

---

# Internal Working

Conceptually, swap works like this

```cpp
template<typename T>
void swap(T& a, T& b)
{
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}
```

Modern C++ uses **move semantics**, making swap very efficient.

---

# Basic Example

```cpp
#include <iostream>
#include <utility>
using namespace std;

int main()
{
    int a = 5;
    int b = 10;

    swap(a, b);

    cout << a << endl;
    cout << b << endl;
}
```

Output

```
10
5
```

---

# Without swap()

```cpp
int temp = a;
a = b;
b = temp;
```

Equivalent to

```cpp
swap(a, b);
```

---

# Swapping Different Data Types

## Integer

```cpp
int a = 10;
int b = 20;

swap(a, b);
```

---

## Double

```cpp
double x = 4.5;
double y = 8.9;

swap(x, y);
```

---

## Character

```cpp
char a = 'A';
char b = 'B';

swap(a, b);
```

---

## Boolean

```cpp
bool a = true;
bool b = false;

swap(a, b);
```

---

# Swapping Strings

```cpp
string s1 = "Hello";
string s2 = "World";

swap(s1, s2);

cout << s1 << endl;
cout << s2;
```

Output

```
World
Hello
```

---

# Swapping Vectors

```cpp
vector<int> a = {1,2,3};
vector<int> b = {4,5,6};

swap(a, b);
```

After swap

```
a = {4,5,6}

b = {1,2,3}
```

Complexity

```
O(1)
```

Only internal pointers are exchanged.

---

# Swapping Arrays

```cpp
int a[] = {1,2,3};
int b[] = {4,5,6};

// Not allowed
swap(a, b);
```

Raw arrays cannot be swapped directly.

Instead

```cpp
std::swap_ranges(a, a+3, b);
```

or

```cpp
std::array<int,3> a = {1,2,3};
std::array<int,3> b = {4,5,6};

swap(a,b);
```

---

# Swapping std::array

```cpp
array<int,4> a = {1,2,3,4};
array<int,4> b = {5,6,7,8};

swap(a,b);
```

Works directly.

Complexity

```
O(n)
```

because every element is swapped.

---

# Swapping Pair

```cpp
pair<int,string> p1 = {1,"One"};
pair<int,string> p2 = {2,"Two"};

swap(p1,p2);
```

Output

```
2 Two

1 One
```

---

# Swapping Tuple

```cpp
tuple<int,int,int> t1 = {1,2,3};
tuple<int,int,int> t2 = {4,5,6};

swap(t1,t2);
```

---

# Swapping Set

```cpp
set<int> s1 = {1,2,3};
set<int> s2 = {4,5,6};

swap(s1,s2);
```

Complexity

```
O(1)
```

---

# Swapping Map

```cpp
map<int,string> m1;
map<int,string> m2;

swap(m1,m2);
```

Complexity

```
O(1)
```

---

# Swapping Unordered Map

```cpp
unordered_map<int,int> m1;
unordered_map<int,int> m2;

swap(m1,m2);
```

Complexity

```
O(1)
```

---

# Swapping Queue

```cpp
queue<int> q1;
queue<int> q2;

swap(q1,q2);
```

or

```cpp
q1.swap(q2);
```

---

# Swapping Stack

```cpp
stack<int> s1;
stack<int> s2;

swap(s1,s2);
```

---

# Swapping Priority Queue

```cpp
priority_queue<int> p1;
priority_queue<int> p2;

swap(p1,p2);
```

---

# Swapping Deque

```cpp
deque<int> d1 = {1,2,3};
deque<int> d2 = {4,5};

swap(d1,d2);
```

---

# Swapping List

```cpp
list<int> l1 = {1,2};
list<int> l2 = {5,6};

swap(l1,l2);
```

---

# Swapping Forward List

```cpp
forward_list<int> a = {1,2};
forward_list<int> b = {3,4};

swap(a,b);
```

---

# Swapping Iterators

Iterator objects themselves can be swapped.

```cpp
auto it1 = v.begin();
auto it2 = v.end();

swap(it1,it2);
```

---

# Member swap()

Most STL containers provide their own member function.

```cpp
container.swap(other);
```

Example

```cpp
vector<int> a,b;

a.swap(b);
```

---

# std::swap vs Member swap()

```cpp
swap(a,b);
```

Equivalent to

```cpp
a.swap(b);
```

for STL containers.

---

# Swapping Custom Objects

```cpp
class Student
{
public:
    int id;
    string name;
};

int main()
{
    Student s1{1,"A"};
    Student s2{2,"B"};

    swap(s1,s2);
}
```

Entire objects are exchanged.

---

# Custom swap Function

```cpp
class Student
{
public:

    int id;

    string name;

    friend void swap(Student &a, Student &b)
    {
        std::swap(a.id,b.id);
        std::swap(a.name,b.name);
    }
};
```

Useful when a class manages expensive resources.

---

# Swap Using Move Semantics

```cpp
template<typename T>
void mySwap(T &a, T &b)
{
    T temp = move(a);
    a = move(b);
    b = move(temp);
}
```

Avoids unnecessary copying.

---

# swap() with Pointers

```cpp
int a = 10;
int b = 20;

int *p = &a;
int *q = &b;

swap(p,q);
```

Pointers are exchanged.

Objects remain unchanged.

---

# swap() with References

```cpp
int a = 5;
int b = 10;

int &x = a;
int &y = b;

// Invalid
swap(x,y);
```

References cannot be reseated. `swap(x, y)` swaps the **values referred to** (so `a` and `b` exchange values), not the bindings of the references.

---

# swap() in Sorting

```cpp
for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
        if(arr[i]>arr[j])
            swap(arr[i],arr[j]);
    }
}
```

Very common in

- Bubble Sort
- Selection Sort
- Quick Sort
- Heap Sort

---

# swap() in Algorithms

Example

```cpp
reverse(v.begin(),v.end());
```

Internally uses swap.

---

```cpp
next_permutation(v.begin(),v.end());
```

Uses swap.

---

```cpp
sort(v.begin(),v.end());
```

Uses swap extensively.

---

# Time Complexity

| Data Type | Complexity |
|------------|-----------|
| int | O(1) |
| double | O(1) |
| char | O(1) |
| pointer | O(1) |
| string | O(1) (typically swaps internal pointers) |
| vector | O(1) |
| deque | O(1) |
| list | O(1) |
| forward_list | O(1) |
| set | O(1) |
| map | O(1) |
| unordered_map | O(1) |
| queue | O(1) |
| stack | O(1) |
| priority_queue | O(1) |
| array | O(n) |

---

# Space Complexity

```
O(1)
```

---

# Advantages

- Simple syntax
- Faster than manual swapping
- Uses move semantics
- Generic function
- Works with STL containers
- Reduces code
- Improves readability
- Exception-safe for many standard types

---

# Limitations

- Both objects should be swappable.
- Raw arrays cannot be swapped directly using `std::swap`.
- Types must be compatible.

---

# Common Mistakes

## 1. Different Types

```cpp
int a = 10;
double b = 5.5;

swap(a,b);
```

Error

Different types.

---

## 2. Swapping Arrays

```cpp
int a[3];
int b[3];

swap(a,b);
```

Not allowed for raw arrays.

---

## 3. Forgetting Header

```cpp
swap(a,b);
```

Include

```cpp
#include <utility>
```

or

```cpp
#include <algorithm>
```

---

# Interview Questions

## Q1. What is `swap()`?

A utility function that exchanges the values of two objects.

---

## Q2. Which header contains `swap()`?

```cpp
#include <utility>
```

or

```cpp
#include <algorithm>
```

---

## Q3. What is the return type?

```cpp
void
```

---

## Q4. What is the complexity?

Usually

```
O(1)
```

For `std::array`

```
O(n)
```

---

## Q5. Does swap use move semantics?

Yes.

Modern implementations use move operations whenever possible.

---

## Q6. Difference between `swap()` and `container.swap()`?

`std::swap(a, b)` is a generic free function, while `container.swap(other)` is a member function provided by many STL containers. For standard containers, both typically achieve the same effect with similar complexity.

---

# Complete Program

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;

    swap(a,b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    string s1 = "Hello";
    string s2 = "World";

    swap(s1,s2);

    cout << s1 << endl;
    cout << s2 << endl;

    vector<int> v1 = {1,2,3};
    vector<int> v2 = {4,5,6};

    swap(v1,v2);

    cout << "Vector 1 : ";

    for(int x:v1)
        cout<<x<<" ";

    cout<<endl;

    cout<<"Vector 2 : ";

    for(int x:v2)
        cout<<x<<" ";
}
```

Output

```
a = 20
b = 10

World
Hello

Vector 1 : 4 5 6
Vector 2 : 1 2 3
```

---