✅ std::pair — ALL Functions, Methods & Operators (COMPLETE)

⸻

7️⃣ swap() (Member + Non-Member)

Member swap

p1.swap(p2);

Non-member swap

swap(p1, p2);



⸻

9️⃣ Tuple Interface (pair behaves like tuple)

get<>

cout << get<0>(p);   // first
cout << get<1>(p);   // second

tuple_size

cout << tuple_size<pair<int,int>>::value;  // 2

tuple_element

tuple_element<0, pair<int,int>>::type x;


⸻

🔟 std::tie() with pair

int a, b;
tie(a, b) = p;

Used heavily in competitive programming.

⸻

1️⃣1️⃣ Hash Support (C++14+)

unordered_map<pair<int,int>, int> mp; // ❌ NOT directly

// Requires custom hash

(Standard library does NOT provide default hash)

⸻

1️⃣2️⃣ Complete Example Using EVERYTHING

#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, string> p1(1, "one");
    pair<int, string> p2 = make_pair(2, "two");

    cout << p1.first << " " << p1.second << endl;

    p1.swap(p2);

    auto [x, y] = p1;
    cout << x << " " << y << endl;

    cout << (p1 < p2) << endl;

    cout << get<0>(p1) << " " << get<1>(p1) << endl;
}


⸻

1️⃣3️⃣ What std::pair DOES NOT HAVE ❌

❌ No size()
❌ No iterators
❌ No push / pop
❌ No member algorithms

Because it’s just:

template<class T1, class T2>
struct pair {
    T1 first;
    T2 second;
};


⸻

✅ FINAL CHECKLIST (NOTHING MISSED)

✔ Data members
✔ All constructors
✔ Assignment operators
✔ make_pair
✔ swap (member + non-member)
✔ Relational operators
✔ Structured binding
✔ Tuple interface
✔ tie
✔ Move semantics

⸻