# Longest Subarray with Sum K

## 📌 Problem Statement
Given an array `arr[]` containing integers and an integer `k`, find the **length of the longest subarray** whose sum is equal to `k`.  
If no such subarray exists, return `0`.

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [10, 5, 2, 7, 1, -10], k = 15`  

**Output:**  
`6`  

**Explanation:**  
Subarrays with sum = 15 are:  
- `[5, 2, 7, 1]` → length = 4  
- `[10, 5]` → length = 2  
- `[10, 5, 2, 7, 1, -10]` → length = 6 ✅ (longest)  

---

### Example 2
**Input:**  
`arr = [-5, 8, -14, 2, 4, 12], k = -5`  

**Output:**  
`5`  

**Explanation:**  
Only subarray with sum = -5 is `[-5, 8, -14, 2, 4]` of length `5`.

---

### Example 3
**Input:**  
`arr = [10, -10, 20, 30], k = 5`  

**Output:**  
`0`  

**Explanation:**  
No subarray has sum `5`.

---

## 🎯 Constraints
- `1 ≤ arr.size() ≤ 10^5`  
- `-10^4 ≤ arr[i] ≤ 10^4`  
- `-10^9 ≤ k ≤ 10^9`  

---

## ⏱️ Expected Complexity
- **Time Complexity:** `O(n)`  
- **Space Complexity:** `O(n)`  

---

## 💡 Approach – Prefix Sum + HashMap
1. Maintain a running prefix sum.  
2. At each index `i`, check if `(prefixSum - k)` exists in the map.  
   - If yes, we found a subarray with sum `k`.  
   - Update the maximum length.  
3. Store the **first occurrence** of each prefix sum in the hashmap (to maximize length).  

---

🏷️ Company Tags
	•	Amazon

⸻

🏷️ Topic Tags
	•	Arrays
	•	HashMap
	•	Prefix Sum
	•	Data Structures
	•	Algorithms

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int>& arr, int k) {
    unordered_map<long long, int> mp;
    long long prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        if (prefixSum == k) {
            maxLen = i + 1;
        }

        if (mp.find(prefixSum - k) != mp.end()) {
            maxLen = max(maxLen, i - mp[prefixSum - k]);
        }

        // store first occurrence only
        if (mp.find(prefixSum) == mp.end()) {
            mp[prefixSum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;
    cout << longestSubarrayWithSumK(arr, k) << endl; // Output: 6
    return 0;
}