 # C++ STL pair :

**What is pair?**
- pair is a container in C++ STL that stores two values together, possibly of different data types.

**Header :**
```cpp
#include <utility>
```

## Constructors: (ALL)

#### Default Constructor:
```cpp
pair<int,int> p;  // {0, 0}
```

#### Value Initialization:
```cpp
pair<int,int> p(1, 2);
```
 
#### Copy Constructor:
```cpp
pair<int,int> p2(p);
```

#### Converting Constructor
```cpp
pair<long, long> p2(p);
```

#### Piecewise Constructor
```cpp
pair<string, vector<int>> p(
    piecewise_construct,
    forward_as_tuple("abc"),
    forward_as_tuple(3, 10)
);
```


## Assignment Operators (ALL)
```cpp
pair<int,int> p(1, 2);
pair<int,int> p1 = p2;           // copy assignment
```

#### Helper Function: make_pair()
```cpp
auto p = make_pair(10, "hello");
```
- Type deduction
- Avoids writing types


## Initialization Methods

#### Using `{}` (Most common)
```cpp
pair<int, int> p = {3, 4};
```

#### Using make_pair()
```cpp
pair<int, int> p = make_pair(3, 4);
```


## Accessing

#### Acessing Pair Elements

```cpp
pair<int, int> p = {10, 20};

cout << p.first;   // 10
cout << p.second;  // 20
```

#### std::tie() with pair:
```cpp
int a, b;
tie(a, b) = p;
```
- **Used heavily in competitive programming.**

#### Structured Binding (C++17)
```cpp
pair<int, int> p = {10, 20};

auto [a, b] = p;
cout << a << " " << b;
```

#### Pair Inside vector
```cpp
vector<pair<int, int>> v;

v.push_back({1, 2});
v.push_back(make_pair(3, 4));

for (auto x : v) {
    cout << x.first << " " << x.second << "\n";
}
```

#### Pair Inside map
```cpp
map<int, string> mp;
mp[1] = "One";
mp[2] = "Two";
for (auto x : mp) {
    cout << x.first << " " << x.second << "\n";
}
```

**Internally, map stores data as:**
```cpp
pair<const Key, Value>
```


#### Pair Inside set
```cpp
set<pair<int, int>> st;

st.insert({1, 2});
st.insert({2, 3});
st.insert({1, 2}); // duplicate ignored
```


#### Nested Pair (Pair inside Pair)
```cpp
pair<int, pair<int, int>> p = {1, {2, 3}};

cout << p.first << "\n";           // 1
cout << p.second.first << "\n";    // 2
cout << p.second.second << "\n";   // 3
```


#### Vector of Nested Pairs (Very Important 💡)
```cpp
vector<pair<int, pair<int, int>>> v;

v.push_back({1, {2, 3}});
v.push_back({4, {5, 6}});

for (auto x : v) {
    cout << x.first << " "
         << x.second.first << " "
         << x.second.second << "\n";
}
```


--------------------------
===========================

### Relational Operators (ALL)

Pairs are compared lexicographically
(first → then second)
```cpp
p1 == p2
p1 != p2
p1 <  p2
p1 <= p2
p1 >  p2
p1 >= p2
```
Example
```cpp
pair<int,int> a = {1, 5};
pair<int,int> b = {2, 1};

cout << (a < b);   // true
```

### Sorting Pair (Lexicographical Order)

Default Sort
```cpp
vector<pair<int, int>> v = {{2, 1}, {1, 5}, {2, 0}};

sort(v.begin(), v.end());
```
- Sorting rules:
	1.	First element
	2.	If first same → second element


### Custom Sorting Using Pair

Sort by second element
```cpp
bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

sort(v.begin(), v.end(), cmp);
```


### Pair Comparison Operators

```cpp
pair<int, int> p1 = {1, 2};
pair<int, int> p2 = {1, 3};

if (p1 < p2) cout << "Yes";  // true
```
Comparison order:

`first → then second`



### Pair with Array
```cpp
pair<int, int> arr[3];

arr[0] = {1, 2};
arr[1] = {3, 4};
arr[2] = {5, 6};
```


### Swapping Pairs
```cpp
pair<int, int> p1 = {1, 2};
pair<int, int> p2 = {3, 4};

swap(p1, p2);
```



### Pair with Priority Queue

Max Heap (default)
```cpp
priority_queue<pair<int,int>> pq;

pq.push({10, 1});
pq.push({20, 2});
```
Min Heap
```cpp
priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;
```


1️⃣7️⃣ Pair Use Cases (Exam + CP 💯)

✔ Store coordinates (x, y)
✔ Graph edges (node, weight)
✔ Frequency (value, count)
✔ Sorting with original index
✔ Map / Set keys
✔ Priority Queue nodes

⸻