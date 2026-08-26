

# Vector vs Deque

| Feature | Vector | Deque |
|----------|--------|--------|
| Continuous Memory | Yes | No |
| Random Access | O(1) | O(1) |
| Push Back | O(1) | O(1) |
| Push Front | O(n) | O(1) |
| Pop Back | O(1) | O(1) |
| Pop Front | O(n) | O(1) |
| Insert Middle | O(n) | O(n) |
| Erase Middle | O(n) | O(n) |

---

# Advantages

- Fast insertion at front.
- Fast insertion at back.
- Random access in O(1).
- Dynamic size.
- Efficient for queue-like operations.
- No large memory reallocation like vector.

---

# Disadvantages

- Not stored contiguously.
- Slightly slower random access than vector.
- Higher memory overhead.
- Cache performance is usually worse than vector.

---

# When to Use `deque`

Use `deque` when:

- Frequent insertion at the front.
- Frequent deletion at the front.
- Frequent insertion at the back.
- Frequent deletion at the back.
- Random access is required.
- Implementing queues, sliding window algorithms, or double-ended data structures.

---

# Common Interview Questions

### Q1. What does `deque` stand for?

```text
Double Ended Queue
```

---

### Q2. Is `deque` contiguous?

```text
No
```

It stores data in multiple memory blocks.

---

### Q3. Which is faster for front insertion?

```text
deque
```

---

### Q4. Which is faster for random access?

```text
Both provide O(1), but vector is usually slightly faster because its memory is contiguous.
```

---

### Q5. Which STL container is used to implement `queue` by default?

```cpp
deque
```

---

# Complete Example

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;

    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(10);

    cout << "Front : " << dq.front() << endl;
    cout << "Back  : " << dq.back() << endl;

    cout << "Elements : ";

    for(int x:dq)
        cout<<x<<" ";

    cout<<endl;

    dq.pop_front();
    dq.pop_back();

    cout<<"After deletion : ";

    for(int x:dq)
        cout<<x<<" ";

    return 0;
}
```

Output

```text
Front : 10
Back  : 30
Elements : 10 20 30
After deletion : 20
```

---

# Summary

```text
Header        : <deque>

Memory        : Multiple fixed-size blocks

Random Access : O(1)

Push Front    : O(1)

Push Back     : O(1)

Pop Front     : O(1)

Pop Back      : O(1)

Insert Middle : O(n)

Erase Middle  : O(n)

Best Use      : Fast insertion/deletion at both ends
```