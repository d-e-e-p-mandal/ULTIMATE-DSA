⸻

✅ std::vector — ALL METHODS & FUNCTIONS (COMPLETE)

#include <vector>
using namespace std;


⸻

1️⃣ Constructors (ALL)

vector<T> v;                                   // default
vector<T> v(n);                               // size n, default values
vector<T> v(n, value);                        // size n, fill value
vector<T> v(other_vector);                    // copy constructor
vector<T> v(move(other_vector));              // move constructor
vector<T> v(begin, end);                      // range constructor
vector<T> v{a, b, c};                         // initializer list


⸻

2️⃣ Destructor

~vector();

(Automatically called, frees memory)

⸻

3️⃣ Assignment Operators

v = other;                     // copy assignment
v = move(other);               // move assignment
v = {1,2,3};                   // initializer list assignment


⸻

4️⃣ Assign Functions

v.assign(n, value);
v.assign(begin, end);
v.assign({1,2,3});


⸻

5️⃣ Element Access (ALL)

v[index];          // operator[]
v.at(index);       // bounds-checked
v.front();
v.back();
v.data();          // pointer to underlying array


⸻

6️⃣ Iterators (COMPLETE SET)

Normal Iterators

v.begin();
v.end();

Const Iterators

v.cbegin();
v.cend();

Reverse Iterators

v.rbegin();
v.rend();

Const Reverse Iterators

v.crbegin();
v.crend();


⸻

7️⃣ Capacity Functions (ALL)

v.size();              // number of elements
v.max_size();          // max possible elements
v.capacity();          // allocated capacity
v.empty();             // true if empty
v.reserve(n);          // reserve capacity
v.resize(n);           // resize (default values)
v.resize(n, value);    // resize with value
v.shrink_to_fit();     // reduce capacity


⸻

8️⃣ Modifiers (ALL — VERY IMPORTANT)

Add Elements

v.push_back(value);
v.emplace_back(args...);
v.insert(pos, value);
v.insert(pos, count, value);
v.insert(pos, begin, end);
v.insert(pos, {1,2,3});
v.emplace(pos, args...);

Remove Elements

v.pop_back();
v.erase(pos);
v.erase(begin, end);
v.clear();

Replace / Manage

v.swap(other);


⸻

9️⃣ Non-Member Functions (Vector-Specific)

swap(v1, v2);


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


⸻

1️⃣4️⃣ Iterator Invalidations (IMPORTANT)

Operation	Invalidates
push_back()	Yes (if reallocation)
insert()	Yes
erase()	Yes
resize()	Yes
clear()	Yes
reserve()	Yes (if realloc)
swap()	Yes


⸻

1️⃣5️⃣ Time Complexity Summary

Operation	Complexity
Access ([], at)	O(1)
push_back	O(1) amortized
insert / erase	O(n)
resize	O(n)
clear	O(n)
find / count	O(n)


⸻

1️⃣6️⃣ Complete Demo (Uses MOST methods)

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,2,3};

    v.push_back(4);
    v.emplace_back(5);

    v.insert(v.begin()+1, 10);
    v.erase(v.begin());

    v.assign(3, 7);

    v.resize(5, 100);
    v.reserve(20);

    cout << v.front() << " " << v.back() << endl;

    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
}


⸻

✅ FINAL CHECKLIST (NOTHING MISSED)

✔ Constructors
✔ Destructor
✔ Assignment operators
✔ Assign functions
✔ Element access
✔ Iterators (all 8 types)
✔ Capacity methods
✔ Modifiers
✔ Allocator
✔ Relational operators
✔ Non-member swap
✔ C++20 erase_if
✔ Complexity & invalidation

⸻