# Stack:

## Declaration:
```cpp
stack<int> st;
```

## Constructors:

## Default Constructor
```cpp
stack<int> st;
```
- Creates an empty stack.


## Copy Constructor
```cpp
stack<int> st1;

st1.push(10);
st1.push(20);

stack<int> st2(st1);
```

- Both stacks contain

```
Top

20
10
```


## Move Constructor
```cpp
stack<int> st1;

st1.push(10);
st1.push(20);

stack<int> st2(move(st1));
```
- Ownership transferred.

---


## Basic Operations

## push():
- Inserts an element at the top.

**Syntax:**
```cpp
st.push(value);
```

**Example:**
```cpp
stack<int> st;

st.push(10);
st.push(20);
st.push(30);
```

**Stack:**
```
Top

30
20
10
```

**Time Complexity:** `O(1)`

---


## emplace()
- Constructs an element directly at the top.

**Syntax:**

```cpp
st.emplace(value);
```

**Example:**
```cpp
stack<pair<int,int>> st;

st.emplace(10,20);
```

**Instead of:**
```cpp
st.push({10,20});
```

**Time Complexity:** `O(1)`

---


## pop()
- Removes the top element.

**Syntax:**
```cpp
st.pop();
```

**Example:**
```cpp
stack<int> st;

st.push(10);
st.push(20);
st.push(30);

st.pop();
```

Stack becomes
```
Top

20
10
```

**Time Complexity:** `O(1)`


### Important:
- `pop()` does **NOT** return the removed element.

**Wrong:**
```cpp
int x = st.pop();
```

**Correct:**
```cpp
int x = st.top();
st.pop();
```

---

## top()
- Returns the top element.

**Syntax:**
```cpp
st.top();
```

**Example:**
```cpp
stack<int> st;

st.push(5);
st.push(7);

cout << st.top();
```

**Output:**
```
7
```

**Complexity:** `O(1)`

---


## empty()
- Checks whether the stack is empty.

**Syntax:**
```cpp
st.empty();
```

**Example:**
```cpp
if(st.empty())
    cout<<"Empty";
else
    cout<<"Not Empty";
```

**Return Type:** `bool`

**Time Complexity:** `O(1)`

---


## size()
- Returns the number of elements.

**Example:**
```cpp
stack<int> st;

st.push(1);
st.push(2);
st.push(3);

cout<<st.size();
```

**Output:** 3

**Time Complexity:** `O(1)`

---


## swap()
- Swaps two stacks.

**Example:**
```cpp
stack<int> st1, st2;

st1.push(1);
st1.push(2);

st2.push(10);

st1.swap(st2);
```

**Now:**
```
st1

10

st2

2
1
```

**Time Complexity:** `O(1)`

---

### Complete Member Functions

| Function | Description | Complexity |
|----------|-------------|------------|
| push() | Insert at top | O(1) |
| emplace() | Construct at top | O(1) |
| pop() | Remove top | O(1) |
| top() | Access top element | O(1) |
| empty() | Check empty | O(1) |
| size() | Number of elements | O(1) |
| swap() | Swap two stacks | O(1) |

---



## Traversing Stack
- Stack has **NO iterators**.

**Wrong:**
```cpp
for(auto it = st.begin(); it != st.end(); it++)
```

**Stack does not support:**
- begin()
- end()
- rbegin()
- rend()

**Correct method:**
```cpp
while(!st.empty())
{
    cout<<st.top()<<" ";
    st.pop();
}
```

**Output**
```
30 20 10
```

### Copy for Traversal

```cpp
stack<int> temp = st; // copying another stack

while(!temp.empty())
{
    cout<<temp.top()<<" ";
    temp.pop();
}
```
- Original stack remains unchanged.


### Example: Traversal

```cpp
stack<int> st;

for(int i=1;i<=5;i++)
    st.push(i);

while(!st.empty())
{
    cout<<st.top()<<" ";
    st.pop();
}
```

**Output:**
```
5 4 3 2 1
```


### Time Complexity

| Operation | Complexity |
|------------|------------|
| push() | O(1) |
| emplace() | O(1) |
| pop() | O(1) |
| top() | O(1) |
| size() | O(1) |
| empty() | O(1) |
| swap() | O(1) |


### Space Complexity :  `O(N)`

- For **N** elements: O(N)