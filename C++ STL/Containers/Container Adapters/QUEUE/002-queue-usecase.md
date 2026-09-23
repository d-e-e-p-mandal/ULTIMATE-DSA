# Queue:

## Declaration
```cpp
queue<int> q;
```

## Constructors

## Default Constructor
```cpp
queue<int> q;
```
- Empty queue is created.


## Copy Constructor
```cpp
queue<int> q1;

q1.push(10);
q1.push(20);

queue<int> q2(q1);
```
- Both queues contain

```
10 20
```

---

## Move Constructor
```cpp
queue<int> q1;

q1.push(1);
q1.push(2);

queue<int> q2(move(q1));
```
- Ownership transferred.

---

## Basic Operations


## push()
- Insert at rear.

**Syntax:**
```cpp
q.push(value);
```

**Example:**
```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);
```

**Queue:**
```
10 20 30
```

**Time Complexity:** O(1)


## emplace()
- Constructs element directly.

**Syntax:**
```cpp
q.emplace(value);
```

**Example:**
```cpp
queue<pair<int,int>> q;
q.emplace(10,20);
```

**Instead of**
```cpp
q.push({10,20});
```
**Time Complexity:** `O(1)`


## pop()
- Removes front element.

**Syntax:**
```cpp
q.pop();
```

**Example:**
```cpp
queue<int> q;

q.push(10);
q.push(20);
q.push(30);

q.pop();
```

**Queue becomes:**
```
20 30
```
**Time Complexity:** O(1)

### Important
- `pop()` does **NOT** return the removed element.

**Wrong**
```cpp
int x = q.pop();
```

**Correct**
```cpp
int x = q.front();
q.pop();
```

## front()
- Returns first element.

**Syntax**
```cpp
q.front();
```

**Example:**
```cpp
queue<int> q;

q.push(5);
q.push(7);

cout<<q.front();
```
**Output:** 5

**Time Complexity:** `O(1)`


## back()
- Returns last element.
**Example:**
```cpp
queue<int> q;

q.push(10);
q.push(20);

cout<<q.back();
```
**Output:** 20
**Time Complexity:** `O(1)`


## empty()
- Checks whether queue is empty.

**Syntax:**
```cpp
q.empty();
```

**Example:**
```cpp
if(q.empty())
    cout<<"Empty";
else
    cout<<"Not Empty";
```
**Return Type:** bool

**Time Complexity:** `O(1)`



## size()
- Returns number of elements.

**Example:**
```cpp
queue<int> q;

q.push(1);
q.push(2);
q.push(3);

cout<<q.size();
```

**Output:**
```
3
```
**Complexity:** `O(1)`


---

## swap()
- Swaps two queues.

**Example:**
```cpp
queue<int> q1,q2;

q1.push(1);
q1.push(2);

q2.push(10);
q1.swap(q2);
```

**Now:**
```
q1

10

q2

1 2
```

**Time Complexity:** O(1)

---

## Complete Member Functions

| Function | Description | Complexity |
|----------|-------------|------------|
| push() | Insert at rear | O(1) |
| emplace() | Construct at rear | O(1) |
| pop() | Remove front | O(1) |
| front() | First element | O(1) |
| back() | Last element | O(1) |
| empty() | Check empty | O(1) |
| size() | Number of elements | O(1) |
| swap() | Swap queues | O(1) |

---


## Traversing Queue
- Queue has **NO iterators**.

**Wrong**
```cpp
for(auto it=q.begin();it!=q.end();it++)
```

**Queue does not support:**
- begin()
- end()
- rbegin()
- rend()

**Correct method**
```cpp
while(!q.empty())
{
    cout<<q.front()<<" ";
    q.pop();
}
```

**Output**
```
10 20 30
```

## Copy for Traversal
- If original queue should remain unchanged

```cpp
queue<int> temp=q;

while(!temp.empty())
{
    cout<<temp.front()<<" ";
    temp.pop();
}
```
- Original queue remains unchanged.


---

# Example:

```cpp
queue<int> q;

for(int i=1;i<=5;i++)
    q.push(i);

while(!q.empty())
{
    cout<<q.front()<<" ";
    q.pop();
}
```

Output

```
1 2 3 4 5
```

----

## Time Complexity

| Operation | Complexity |
|------------|------------|
| push() | O(1) |
| emplace() | O(1) |
| pop() | O(1) |
| front() | O(1) |
| back() | O(1) |
| size() | O(1) |
| empty() | O(1) |
| swap() | O(1) |


## Space Complexity
- **For **N** elements**: O(N)
