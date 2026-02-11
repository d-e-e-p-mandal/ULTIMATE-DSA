## What is vector?
vector is a dynamic array provided by the C++ STL.
It can grow and shrink at runtime, unlike normal arrays.

`Header :`
```cpp
#include <vector>
```

#### Constructors (ALL)
```cpp
vector<T> v;     // default
vector<int> v;   // empty vector
```
```cpp
vector<T> v(n);      // size n, default values
vector<int>v(5)     // (0,0,0,0,0)
```

```cpp
vector<T> v(n, value); // size n, fill value
vector<int> v(5,1);    //(1,1,1,1,1)
```

```cpp
vector<T> v(other_vector);   // copy constructor
vector<int> v1(1,2,3);
vector<int> v2(v1);  // deep copy

```

```cpp
vector<T> v(move(other_vector));              // move constructor
vector<int> v1(1,2,3);
vector<int> v2(move(v1));  // shallow copy
```

```cpp
vector<T> v(begin, end); // range constructor
vector<int> v1(1,2,3);
vector<int> v2(v1.begin(), v1.end());
```

```cpp
vector<T> v{a, b, c};   // initializer list constructor

vector<int> v{10, 20, 30, 40};    // vector contains 4 elements
    for (int x : v)
        cout << x << " ";
```
⸻

2️⃣ Destructor
```cpp
~vector();
```
(Automatically called, frees memory)

1. Declaring a Vector
```cpp
vector<int> v1(5);          // size 5, all values = 0
vector<int> v2(5, 10);      // size 5, all values = 10
vector<int> v3 = {1, 2, 3}; // initializer list
```

3️⃣ Assignment Operators
```cpp
v = other;           // copy assignment
v = move(other);     // move assignment
v = {1,2,3};         // initializer list assignment
```

4️⃣ Assign Functions
```cpp
v.assign(n, value);
v.assign(begin, end);
v.assign({1,2,3});
```


## Adding Elements

### v.push_back(value)
Adds element at the end.
```cpp
vecot<int> v;
v.push_back(10);
```
Time Complexity:
•	Average: O(1)
•	Worst case: O(n) (when reallocation happens)


### v.emplace_back(args...);
emplace_back avoids extra copy.
Constructs element directly at the end.

```cpp
v.emplace_back(20);
```
Time Complexity:
•	Average: O(1)
•	Worst case: O(n)

👉 Faster than push_back() for complex objects (avoids extra copy).

### v.emplace(args...);
```cpp
vector<int> v = {10, 20, 40};
v.emplace(v.begin() + 2, 30);
```
Time Complexity: O(n)
👉 All elements shift right.

### v.insert(position, value);

```cpp
v.insert(v.begin() + index, value);
```
Time Complexity: O(n)
👉 All elements shift right.


### v.insert(position, count, value);
```cpp
v.insert(v.begin(), 3, 5);  // insert 5 three(3) times
```
Time Complexity: O(n)
👉 All elements shift right.

•	Back insertion → O(1) amortized
•	Front insertion → O(n)
•	Middle insertion → O(n)
•	Vector is fast only at the back

⸻

3. Accessing Elements
```cpp
cout << v[0];       // no bounds checking
cout << v.at(1);    // safe (throws exception)
cout << v.front();  // first element
cout << v.back();   // last element
v.data();           // pointer to underlying array
```
⸻

4. Size & Capacity
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

Example:
```cpp
if(v.empty()) {
    cout << "Vector is empty";
}
```

⸻

5. Removing Elements
```cpp
pop_back()
```
Removes last element.
```cpp
v.pop_back();
```

```cpp
erase()
```
Removes element at position.
```cpp
v.erase(v.begin());          // remove first
v.erase(v.begin() + 2);      // remove 3rd element
```

Remove range
```cpp
v.erase(v.begin(), v.begin() + 3);
```
⸻

6. Clearing a Vector
```cpp
v.clear();    // removes all elements
```
Capacity remains unchanged.

⸻


6️⃣ Iterators (COMPLETE SET)

Normal Iterators
```cpp
v.begin();
v.end();
```
Const Iterators
```cpp
v.cbegin();
v.cend();
```
Reverse Iterators
```cpp
v.rbegin();
v.rend();
```
Const Reverse Iterators
```cpp
v.crbegin();
v.crend();
```

8. Iterating Over Vector

Normal loop
```cpp
for(int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}
```

Range-based loop
```cpp
for(int x : v) {
    cout << x << " ";
}
```

Using iterator
```cpp
for(auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}
```

⸻

9. Reverse Iteration
```cpp
for(auto it = v.rbegin(); it != v.rend(); it++) {
    cout << *it << " ";
}
```

⸻

10. Sorting a Vector
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


Binary Search (sorted vector only)
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

a.swap(b);
swap(a, b);
```

⸻

16. 2D Vector (Matrix)
```cpp
vector<vector<int>> mat(3, vector<int>(4, 0));
```
Traversal:
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

⸻

18. Time Complexity

Operation	Complexity
Access	O(1)
push_back	O(1) avg
insert / erase	O(n)
search	O(n)
sort	O(n log n)


⸻

19. Common Interview Questions

Q1. Vector vs Array?
→ Vector is dynamic, array is static.

Q2. push_back vs emplace_back?
→ emplace_back avoids extra copy.

Q3. Does clear() free memory?
→ No, capacity remains.

⸻

20. Complete Example Program

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
