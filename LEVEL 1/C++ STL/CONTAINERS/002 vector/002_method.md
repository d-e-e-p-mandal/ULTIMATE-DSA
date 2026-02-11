
## swap() :
```cpp
vector<int> a = {1,2,3};
vector<int> b = {4,5,6};
//1
a.swap(b);
//2
swap(a,b);
```


## move()
```cpp
vector<int> a = {1,2,3};
//1
vector<int> b(move(a));
//2
vector<int> b = move(a);
//3
vector<int> b;
b = move(a);
```