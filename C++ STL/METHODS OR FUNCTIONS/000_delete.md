

🔥 C++ STL — ALL FUNCTIONS & METHODS (MASTER LIST)

⸻

1️⃣ SEQUENCE CONTAINERS

⸻

🔹 vector

v.begin() v.end() v.rbegin() v.rend()
v.size() v.empty() v.max_size()
v.capacity() v.reserve(n) v.shrink_to_fit()
v.clear()
v.push_back(x) v.pop_back()
v.insert(pos, x) v.insert(pos, n, x)
v.erase(pos) v.erase(first, last)
v.emplace(pos, x)
v.emplace_back(x)
v.front() v.back()
v.at(i) v[i]
v.assign(n, x)
v.swap(v2)
v.data()


⸻

🔹 deque

dq.begin() dq.end()
dq.size() dq.empty()
dq.push_back(x) dq.push_front(x)
dq.pop_back() dq.pop_front()
dq.front() dq.back()
dq.insert(pos, x)
dq.erase(pos)
dq.clear()
dq.assign(n, x)
dq.swap(dq2)


⸻

🔹 list

l.begin() l.end()
l.size() l.empty()
l.push_back(x) l.push_front(x)
l.pop_back() l.pop_front()
l.insert(pos, x)
l.erase(pos)
l.remove(x)
l.remove_if(cond)
l.sort()
l.reverse()
l.unique()
l.merge(l2)
l.splice(pos, l2)
l.clear()


⸻

🔹 forward_list

fl.before_begin()
fl.begin() fl.end()
fl.push_front(x)
fl.pop_front()
fl.insert_after(pos, x)
fl.erase_after(pos)
fl.remove(x)
fl.sort()
fl.reverse()


⸻

🔹 array

arr.size()
arr.empty()
arr.at(i)
arr[i]
arr.front()
arr.back()
arr.fill(x)
arr.swap(arr2)
arr.data()


⸻

🔹 string

s.size() s.length()
s.empty()
s.clear()
s.push_back(c) s.pop_back()
s.append(str)
s.insert(pos, str)
s.erase(pos, len)
s.replace(pos, len, str)
s.substr(pos, len)
s.find(str)
s.rfind(str)
s.compare(str)
s.c_str()
stoi(s) stol(s) stoll(s)
to_string(x)


⸻

2️⃣ ASSOCIATIVE CONTAINERS (ORDERED)

⸻

🔹 set

s.begin() s.end()
s.size() s.empty()
s.insert(x)
s.erase(x)
s.erase(it)
s.find(x)
s.count(x)
s.lower_bound(x)
s.upper_bound(x)
s.equal_range(x)
s.clear()
s.swap(s2)


⸻

🔹 multiset

ms.insert(x)
ms.erase(x)          // all x
ms.erase(ms.find(x)) // one x
ms.count(x)
ms.equal_range(x)


⸻

🔹 map

mp.begin() mp.end()
mp.size() mp.empty()
mp[key]
mp.at(key)
mp.insert({k,v})
mp.emplace(k,v)
mp.erase(key)
mp.find(key)
mp.count(key)
mp.lower_bound(key)
mp.upper_bound(key)
mp.equal_range(key)
mp.clear()
mp.swap(mp2)


⸻

🔹 multimap

mm.insert({k,v})
mm.count(key)
mm.equal_range(key)


⸻

3️⃣ UNORDERED CONTAINERS (HASHED)

⸻

🔹 unordered_set

us.insert(x)
us.erase(x)
us.find(x)
us.count(x)
us.bucket_count()
us.bucket_size(i)
us.load_factor()
us.rehash(n)


⸻

🔹 unordered_map

um[key]
um.at(key)
um.insert({k,v})
um.erase(key)
um.find(key)
um.count(key)
um.bucket_count()
um.load_factor()


⸻

4️⃣ CONTAINER ADAPTERS

⸻

🔹 stack

st.push(x)
st.pop()
st.top()
st.size()
st.empty()


⸻

🔹 queue

q.push(x)
q.pop()
q.front()
q.back()
q.size()
q.empty()


⸻

🔹 priority_queue

pq.push(x)
pq.pop()
pq.top()
pq.size()
pq.empty()


⸻

5️⃣ ALGORITHMS (<algorithm>)

⸻

🔹 Sorting & Rearranging

sort(first, last)
stable_sort(first, last)
partial_sort(first, mid, last)
nth_element(first, nth, last)
reverse(first, last)
rotate(first, mid, last)
shuffle(first, last, rng)


⸻

🔹 Searching

find(first, last, x)
find_if(first, last, cond)
binary_search(first, last, x)
lower_bound(first, last, x)
upper_bound(first, last, x)
equal_range(first, last, x)


⸻

🔹 Min / Max

min(a,b)
max(a,b)
min_element(first, last)
max_element(first, last)
minmax(a,b)
minmax_element(first,last)


⸻

🔹 Count & Check

count(first,last,x)
count_if(first,last,cond)
all_of(first,last,cond)
any_of(first,last,cond)
none_of(first,last,cond)


⸻

🔹 Modify

copy(first,last,dest)
move(first,last,dest)
swap(a,b)
swap_ranges(f1,l1,f2)
replace(first,last,old,new)
replace_if(first,last,cond,new)
remove(first,last,x)
remove_if(first,last,cond)
unique(first,last)


⸻

🔹 Permutations

next_permutation(first,last)
prev_permutation(first,last)


⸻

6️⃣ NUMERIC (<numeric>)

accumulate(first,last,init)
partial_sum(first,last,result)
adjacent_difference(first,last,result)
iota(first,last,val)
gcd(a,b)
lcm(a,b)


⸻

7️⃣ ITERATORS

begin() end()
rbegin() rend()
cbegin() cend()
advance(it,n)
distance(it1,it2)
next(it)
prev(it)


⸻

8️⃣ UTILITIES (<utility>)

⸻

🔹 pair

p.first
p.second
make_pair(a,b)
swap(p1,p2)


⸻

🔹 tuple

get<i>(t)
make_tuple(a,b,c)
tie(a,b,c)


⸻

9️⃣ FUNCTION OBJECTS (<functional>)

greater<T>()
less<T>()
plus<T>()
minus<T>()
multiplies<T>()
divides<T>()
modulus<T>()


⸻

🔟 BITSET (<bitset>)

b.set()
b.reset()
b.flip()
b.count()
b.any()
b.none()
b.all()
b.test(i)


⸻

🧠 FINAL REALITY CHECK (IMPORTANT)

✔ This covers almost everything ever used in CP, interviews, exams
✔ Official STL has more, but they’re rarely / never tested
✔ If you master this → STL fear = 0

⸻
