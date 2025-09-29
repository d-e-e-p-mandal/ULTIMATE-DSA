# Max Consecutive Bit

[GFG](https://www.geeksforgeeks.org/problems/max-consecutive-one/1)

## 📌 Problem Statement
You are given an array `arr[]` consisting only of `0’s` and `1’s`.  
Your task is to **find the maximum number of consecutive 1’s or 0’s** present in the array.

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [0, 1, 0, 1, 1, 1, 1]`  

**Output:**  
`4`  

**Explanation:**  
The maximum consecutive 1’s are **4** (from index 3–6).  

---

### Example 2
**Input:**  
`arr = [0, 0, 1, 0, 1, 0]`  

**Output:**  
`2`  

**Explanation:**  
The maximum consecutive 0’s are **2** (from index 0–1).  

---

### Example 3
**Input:**  
`arr = [0, 0, 0, 0]`  

**Output:**  
`4`  

**Explanation:**  
The maximum consecutive 0’s are **4**.  

---

## 🎯 Constraints
- `1 ≤ arr.size() ≤ 10^5`  
- `0 ≤ arr[i] ≤ 1`  

---

## ⏱️ Expected Complexity
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)`  

---

## 💡 Approach
1. Traverse the array.  
2. Maintain a counter for consecutive elements.  
3. If the current element is same as the previous one → increment counter.  
4. Else reset counter = 1.  
5. Track the maximum value across traversal.  

---

🏢 Company Tags
	•	Accenture
	•	TCS
	•	Oracle

⸻

🏷️ Topic Tags
	•	Arrays
	•	Data Structures

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveBit(vector<int>& arr) {
    int n = arr.size();
    int maxCount = 1, count = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1]) {
            count++;
        } else {
            count = 1;
        }
        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int main() {
    vector<int> arr = {0, 1, 0, 1, 1, 1, 1};
    cout << maxConsecutiveBit(arr) << endl; // Output: 4
    return 0;
}