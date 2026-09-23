# Where Only Move Method Exists.

## Moving unique_ptr

```cpp
unique_ptr<int> p1(new int(10));

unique_ptr<int> p2 = move(p1);
```
- Required because `unique_ptr` cannot be copied.
