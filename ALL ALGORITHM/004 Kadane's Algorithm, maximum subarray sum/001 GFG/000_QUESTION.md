# Kadane's Algorithm

[GFG Problem Link](https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/)

---

## 📌 Problem Statement
Given an integer array `arr[]`, find the **maximum sum of a subarray** (containing at least one element).  

🧠 **Note:** A subarray is a **continuous part of an array**.

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [2, 3, -8, 7, -1, 2, 3]`  

**Output:**  
`11`  

**Explanation:**  
The subarray `[7, -1, 2, 3]` has the largest sum 11.

---

### Example 2
**Input:**  
`arr = [-2, -4]`  

**Output:**  
`-2`  

**Explanation:**  
The subarray `[-2]` has the largest sum -2.

---

### Example 3
**Input:**  
`arr = [5, 4, 1, 7, 8]`  

**Output:**  
`25`  

**Explanation:**  
The subarray `[5, 4, 1, 7, 8]` has the largest sum 25.

---

## 🎯 Constraints
- `1 ≤ arr.size() ≤ 10^5`  
- `-10^4 ≤ arr[i] ≤ 10^4`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|------------------|-------------|
| **Time Complexity** | `O(n)` — Traverse the array once |
| **Space Complexity** | `O(1)` — Only constant extra variables used |

---

## 🏢 Company Tags
Zoho, Flipkart, Morgan Stanley, Accolite, Amazon, Microsoft, Samsung, Snapdeal, 24*7 Innovation Labs, Citrix, D-E-Shaw, FactSet, Hike, Housing.com, MetLife, Ola Cabs, Oracle, Payu, Teradata, Visa, Walmart, Adobe, Google, Arcesium

---

## 🏷️ Topic Tags
- Arrays  
- Dynamic Programming  
- Data Structures  
- Algorithms

---

## 💡 Approach – Kadane's Algorithm (Optimal)
Kadane’s Algorithm finds the **maximum sum subarray** in **linear time** using a **greedy approach**.

### 🔍 Intuition
- Maintain a `current_sum` representing the **maximum subarray sum ending at current index**.  
- If `current_sum` becomes negative, reset it to 0 (since adding a negative sum decreases potential future sums).  
- Keep track of a `max_sum` which stores the **maximum encountered sum** so far.

---

## 🧠 Algorithm
1. Initialize `max_sum = arr[0]` and `current_sum = 0`.  
2. Traverse each element `num` in `arr`:  
   - `current_sum += num`  
   - If `current_sum > max_sum`, update `max_sum = current_sum`  
   - If `current_sum < 0`, reset `current_sum = 0`  
3. Return `max_sum`.

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int>& arr) {
    int max_sum = arr[0];
    int current_sum = 0;

    for (int num : arr) {
        current_sum += num;
        max_sum = max(max_sum, current_sum);
        if (current_sum < 0) current_sum = 0;
    }

    return max_sum;
}

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << kadane(arr); // Output: 11
    return 0;
}
```