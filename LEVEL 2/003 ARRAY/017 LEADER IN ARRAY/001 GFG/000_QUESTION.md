# Array Leaders

[GeeksForGeeks Problem Link](https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1)

---

## 📌 Problem Statement
You are given an array `arr` of positive integers.  

Your task is to **find all the leaders** in the array.  

### Definition:
An element is considered a **leader** if it is **greater than or equal to all elements to its right**.  
The **rightmost element** is always a leader.

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [16, 17, 4, 3, 5, 2]`  

**Output:**  
`[17, 5, 2]`  

**Explanation:**  
17, 5, and 2 have no greater elements to their right.

---

### Example 2
**Input:**  
`arr = [10, 4, 2, 4, 1]`  

**Output:**  
`[10, 4, 4, 1]`  

**Explanation:**  
Equal elements are allowed to be leaders.

---

### Example 3
**Input:**  
`arr = [5, 10, 20, 40]`  

**Output:**  
`[40]`  

**Explanation:**  
Only the rightmost element is the leader in a strictly increasing array.

---

### Example 4
**Input:**  
`arr = [30, 10, 10, 5]`  

**Output:**  
`[30, 10, 10, 5]`  

**Explanation:**  
All elements are leaders in a non-increasing array.

---

## 🎯 Constraints
- `1 <= arr.size() <= 10^6`  
- `0 <= arr[i] <= 10^6`  

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n)` — Traverse array from right to left once |
| **Space Complexity** | `O(n)` — For storing leader elements |

---

## 🏢 Company Tags
Payu, Adobe  

---

## 🏷️ Topic Tags
- Arrays  
- Data Structures  

---

## 💡 Approach – Right-to-Left Traversal
1. Start from the **rightmost element** (always a leader).  
2. Keep track of the **maximum element** seen so far.  
3. Traverse the array **from right to left**:
   - If the current element is greater than or equal to the maximum so far, it is a leader.  
   - Update the maximum if necessary.  
4. Collect all leaders in order of appearance from left to right (reverse the result at the end if needed).

---

## 🧠 Algorithm
1. Initialize `max_from_right = arr[n-1]` and `leaders = [arr[n-1]]`.  
2. Traverse `arr` from `n-2` down to `0`:  
   - If `arr[i] >= max_from_right`:
     - Append `arr[i]` to `leaders`.  
     - Update `max_from_right = arr[i]`.  
3. Reverse `leaders` array if you want left-to-right order.  
4. Return `leaders`.

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;
    int max_from_right = arr[n-1];
    leaders.push_back(max_from_right);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= max_from_right) {
            leaders.push_back(arr[i]);
            max_from_right = arr[i];
        }
    }

    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> res = findLeaders(arr);

    for (int x : res) cout << x << " ";
    return 0;
}