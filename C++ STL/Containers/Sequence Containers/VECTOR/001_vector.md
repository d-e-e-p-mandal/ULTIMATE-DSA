
# Vector:

### What is vector?
- vector is a dynamic array provided by the C++ STL.
- It can grow and shrink at runtime, unlike normal arrays.

**Header:**
```cpp
#include <vector>
```

## Constructors: (ALL)

#### Default:
```cpp
vector<T> v;     // default
vector<int> v;   // empty vector
```

#### Size:
```cpp
vector<T> v(n);      // size n, default values
vector<int>v(5);     // (0,0,0,0,0)
```

#### Fill Vaue:

```cpp
vector<T> v(n, value); // size n, fill value
vector<int> v(5,1);    //(1,1,1,1,1)
```


#### Copy Constructor:
```cpp
vector<T> v(other_vector);   // copy constructor
vector<int> v1(1,2,3);
vector<int> v2(v1);  // deep copy

```


#### Range Constructor
```cpp
vector<T> v(begin, end); // range constructor
vector<int> v1(1,2,3);
vector<int> v2(v1.begin(), v1.end());
```

#### Intilizer List:

```cpp
vector<T> v{a, b, c};   // initializer list constructor
```
Or:
```cpp
vector<T> v = {a, b, c};   // initializer list constructor
```

**Example :**
```cpp
vector<int> v{10, 20, 30, 40};    // vector contains 4 elements
    for (int x : v)
        cout << x << " ";
```

## Destructor
```cpp
~vector();
```
(Automatically called, frees memory)

--------------------------

## Declare and assign value:
- Back insertion → O(1) amortized
- Front insertion → O(n)
- Middle insertion → O(n)

### Imp*: `Vector is fast only at the back`
- Rember. 
- Recomended. 
- Mostly Used this.


### Declaring a Vector
- Use any constructor.
- Use Based on need.
```cpp
vector<int> v1(5);          // size 5, all values = 0
vector<int> v2(5, 10);      // size 5, all values = 10
vector<int> v3 = {1, 2, 3}; // initializer list
```

### Assignment Operators
```cpp
vector<int>v;    // declare vector then assign
v = other;       // copy assignment
v = {1,2,3};     // initializer list assignment
```

### Assign Functions Use:
```cpp
v.assign(n, value);
v.assign(begin, end);
v.assign({1,2,3});
```


## Adding Elements
- Back insertion → O(1) amortized
- Front insertion → O(n)
- Middle insertion → O(n)

**Imp*:**` Vector is fast only at the back`.
  - Use

### v.push_back(value)
- Adds element at the end.

```cpp
vector<int> v;
v.push_back(10);
```
**Time Complexity:**
- Average: `O(1)`
- Worst case: `O(n)` (when reallocation happens)


### v.emplace_back(args...):
- emplace_back avoids extra copy.
- Constructs element directly at the end.

```cpp
v.emplace_back(20);
```
**Time Complexity:**
- Average: `O(1)`
- Worst case: `O(n)`

- *Faster than push_back() for complex objects (avoids extra copy).*


### v.emplace(position, args...):
```cpp
vector<int> v = {10, 20, 40}; // declare

v.emplace(v.begin() + 2, 30);
```
**Time Complexity:**
- `O(n)`
- All elements shift right.


### v.insert(position, value):

```cpp
v.insert(v.begin() + index, value);
```
**Time Complexity:** 
- `O(n)`
- All elements shift right.


### v.insert(position, count, value): Repeted value:
```cpp
v.insert(v.begin(), 3, 5);  // insert 5 three(3) times
```

Time Complexity:` O(n)`
- All elements shift right.



-----------------------------------------------


## Accessing Elements
```cpp
cout << v[0];       // no bounds checking
cout << v.at(1);    // safe (throws exception)

cout << v.front();  // first element
cout << v.back();   // last element

v.data();           // pointer to underlying array
```


## Size & Capacity
```cpp
v.size();              // number of elements
v.max_size();          // max possible elements

v.capacity();          // allocated capacity
v.empty();             // true if empty

v.reserve(n);          // reserve capacity
v.resize(n);           // resize (default values)
v.resize(n, value);    // resize with value

v.shrink_to_fit();     // reduce capacity
```

**x**
```cpp
if(v.empty()) {
    cout << "Vector is empty";
}
```

⸻

## Removing Elements

### pop_back()
- Removes last element.

```cpp
vector<int> x(1,2,3);
v.pop_back();
```

### erase()
- Removes element at position.

```cpp
v.erase(v.begin());          // remove first
v.erase(v.begin() + 2);      // remove 3rd element
```

### Remove range
```cpp
v.erase(v.begin(), v.begin() + 3);
```

### Clearing a Vector
- removes all elements.
- Capacity remains unchanged.

```cpp
v.clear();    // removes all elements
```


----------------------------


## Iterators (COMPLETE SET)

### Normal Iterators
```cpp
v.begin();  // position: 1st element
v.end();    // positon: after last element
```


### Const Iterators
```cpp
v.cbegin();
v.cend();
```


### Reverse Iterators
```cpp
v.rbegin(); // position: last element
v.rend();   // postion: befor 1st element
```


### Const Reverse Iterators
```cpp
v.crbegin();
v.crend();
```

### Iterating Over Vector: simple loop using

### Simple loop Traverse:
```cpp
for(int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}
```

### Range-based loop:
```cpp
for(int x : v) {
    cout << x << " ";
}
```


### Using iterator
```cpp
for(auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}
```


### Reverse Iteration
```cpp
for(auto it = v.rbegin(); it != v.rend(); it++) {
    cout << *it << " ";
}
```

-------------------------
Complate Later:

## Sorting a Vector
```cpp
#include <algorithm>

sort(v.begin(), v.end());              // ascending
sort(v.begin(), v.end(), greater<int>()); // descending
```

⸻

11. Searching
```cpp
find()

auto it = find(v.begin(), v.end(), 10);
if(it != v.end())
    cout << "Found";
```


### Binary Search (sorted vector only)
```cpp
binary_search(v.begin(), v.end(), 10);
```

⸻

12. Min / Max Element
```cpp
*min_element(v.begin(), v.end());
*max_element(v.begin(), v.end());
```

⸻

13. Count & Accumulate
```cpp
count(v.begin(), v.end(), 5);

#include <numeric>
accumulate(v.begin(), v.end(), 0);
```

⸻

14. Resize & Reserve
```cpp
v.resize(10);     // change size
v.reserve(100);   // pre-allocate memory
```

⸻

15. Swap Vectors
```cpp
vector<int> a = {1, 2};
vector<int> b = {3, 4};

// both are Swap function
a.swap(b);
swap(a, b); // internally a.swap(b)
```

⸻

## 2D Vector (Matrix) 
1. **2D Vector Declaration :**

```cpp
vector<vector<int>> vec; // empty vector
vector<vector<int>> vec(10); // 10 row size
vector<vector<int>> mat(3, vector<int>(4)); // 3 row, 4 col
vector<vector<int>> mat(3, vector<int>(4, 0)); // 3 row, 4 col, fill with 0
```

2. **Traversal:**
```cpp
for(int i = 0; i < mat.size(); i++) {
    for(int j = 0; j < mat[i].size(); j++) {
        cout << mat[i][j] << " ";
    }
    cout << endl;
}
```

⸻

17. Vector of Pairs
```cpp
vector<pair<int,int>> vp;
vp.push_back({1, 2});
vp.emplace_back(3, 4);
```


-------------------


**Example Program:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {5, 2, 9, 1};

    v.push_back(10);
    sort(v.begin(), v.end());

    for(int x : v)
        cout << x << " ";

    return 0;
}
```

--------
19. Common Interview Questions

Q1. Vector vs Array?
→ Vector is dynamic, array is static.

Q2. push_back vs emplace_back?
→ emplace_back avoids extra copy.

Q3. Does clear() free memory?
→ No, capacity remains.

---------------




⸻

🔟 Relational Operators (ALL)

v1 == v2
v1 != v2
v1 <  v2
v1 <= v2
v1 >  v2
v1 >= v2


⸻

1️⃣1️⃣ Allocator Functions

v.get_allocator();


⸻

1️⃣2️⃣ C++11+ Move Support

vector<T> v2 = move(v1);
v2 = move(v1);


⸻

1️⃣3️⃣ C++17 / C++20 Additions

data() is non-const & const

T* p = v.data();
const T* p = cv.data();

erase_if (C++20 – via algorithm)

erase_if(v, [](int x){ return x % 2 == 0; });


