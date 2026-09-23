# Deque:

## Creating a Deque

#### Empty:
```cpp
deque<int> dq;
```

#### With size:
```cpp
deque<int> dq(5);
```

**Output:**
```text
0 0 0 0 0
```

#### With initial value:
```cpp
deque<int> dq(5,100);
```

**Output:**
```text
100 100 100 100 100
```

#### Initializer List:
```cpp
deque<int> dq = {1,2,3,4,5};
```

#### Copy Constructor
```cpp
deque<int> dq1 = {1,2,3};
deque<int> dq2(dq1);
```

#### Move Constructor
```cpp
deque<int> dq2(move(dq1));
```
- Resources are transferred.


## Accessing Elements

## operator[]
```cpp
deque<int> dq={10,20,30};
cout<<dq[1];
```

**Output:** 20


## at()
```cpp
cout<<dq.at(2);
```
**Output:** 30

- Checks bounds.
- Throws exception if index is invalid.


## front()
```cpp
cout<<dq.front();
```

**Output:** 10


## back()
```cpp
cout<<dq.back();
```

**Output** 30

---

## Capacity Functions

## size()
```cpp
dq.size();
```
- Returns number of elements.

---

## empty()
```cpp
dq.empty();
```
**Returns:** `true` or `false`


## max_size()
```cpp
dq.max_size();
```
- Returns maximum possible elements.

---

## resize()
**Increase:**
```cpp
dq.resize(7);
```
- Adds default values.

**Decrease:**
```cpp
dq.resize(2);
```
- Removes extra elements.


## shrink_to_fit()
```cpp
dq.shrink_to_fit();
```
- Requests removal of unused memory.
- (Not guaranteed.)

---

## Insertion Functions

## push_back()
```cpp
deque<int> dq;

dq.push_back(10);
dq.push_back(20);
```

**Output:**
```text
10 20
```
**Time Complexity:** `O(1)`


## push_front()
```cpp
dq.push_front(5);
```

**Output:**
```text
5 10 20
```

**Time Complexity:** `O(1)`


## emplace_back()
- Constructs object directly.

```cpp
deque<pair<int,int>> dq;
dq.emplace_back(1,2);
```

- Avoids temporary object.


## emplace_front()
```cpp
dq.emplace_front(5,6);
```


## emplace()
```cpp
auto it=dq.begin()+2;

dq.emplace(it,100);
```


## insert()
**Insert one element:**
```cpp
dq.insert(dq.begin()+1,50);
```

**Insert multiple copies:**
```cpp
dq.insert(dq.begin(),3,100);
```

**Insert range:**
```cpp
dq.insert(dq.end(),v.begin(),v.end());
```

---

## Removal Functions

## pop_back()
```cpp
dq.pop_back();
```
- Removes last element.


## pop_front()
```cpp
dq.pop_front();
```
- Removes first element.


## erase()

**Single:**
```cpp
dq.erase(dq.begin()+2);
```

**Range:**
```cpp
dq.erase(dq.begin(),dq.begin()+3);
```

## clear()
```cpp
dq.clear();
```
- Removes all elements.
- Size becomes: `0`


---

## Assign Functions

```cpp
deque<int> dq;
dq.assign(5,10);
```

**Output:**
```text
10 10 10 10 10
```

### Assign from another container
```cpp
vector<int> v={1,2,3};

dq.assign(v.begin(),v.end());
```

---

## Swap
```cpp
deque<int> a={1,2};
deque<int> b={10,20};
a.swap(b);
```

**or:**

```cpp
swap(a,b);
```

---

## Iterators
- `dq.begin()`
- `dq.end()`
- `dq.rbegin()`
- `dq.rend()`
- `dq.cbegin()`
- `dq.cend()`


**Example:**
```cpp
for(auto it=dq.begin();it!=dq.end();it++)
{
    cout<<*it<<" ";
}
```


**Example: Range-based loop:**
```cpp
for(int x:dq)
{
    cout<<x<<" ";
}
```

---

## Comparison Operators

```cpp
dq1==dq2

dq1!=dq2

dq1<dq2

dq1<=dq2

dq1>dq2

dq1>=dq2
```

Lexicographical comparison.

---

## Move Semantics

## Move Constructor

```cpp
deque<int> dq1={1,2,3};
deque<int> dq2(move(dq1));
```
- Resources transferred.

---

## Move Assignment

```cpp
deque<int> dq1={1,2,3};
deque<int> dq2;
dq2=move(dq1);
```

Calls

```cpp
operator=(deque&&)
```

---

## Copy Constructor

```cpp
deque<int> dq2(dq1);
```

Creates complete copy.

---

## Copy Assignment

```cpp
dq2=dq1;
```

Copies all elements.

---

## Time Complexity

| Operation | Complexity |
|-----------|------------|
| front() | O(1) |
| back() | O(1) |
| operator[] | O(1) |
| at() | O(1) |
| push_front() | O(1) |
| push_back() | O(1) |
| pop_front() | O(1) |
| pop_back() | O(1) |
| insert() middle | O(n) |
| erase() middle | O(n) |
| clear() | O(n) |
| size() | O(1) |
| empty() | O(1) |

---