# Subarray Sum Equals K

## 📌 Problem Statement
Given an integer array `nums` and an integer `k`, return the total number of **subarrays** whose sum equals `k`.

A subarray is a contiguous **non-empty sequence** of elements within an array.

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [1,1,1], k = 2`  

**Output:**  
`2`  

---

### Example 2
**Input:**  
`nums = [1,2,3], k = 3`  

**Output:**  
`2`  

---

## 🎯 Constraints
- `1 <= nums.length <= 2 * 10^4`  
- `-1000 <= nums[i] <= 1000`  
- `-10^7 <= k <= 10^7`  

---

## ⏱️ Expected Complexity
- **Time Complexity:** `O(n)`  
- **Space Complexity:** `O(n)`  

---

## 💡 Approach – Prefix Sum + HashMap
1. Maintain a running prefix sum.  
2. At each index `i`, check if `(prefixSum - k)` exists in a hashmap.  
   - This means there’s a subarray ending at `i` with sum `k`.  
3. Store frequency of each prefix sum in hashmap.  

---

🏷️ Topic Tags
	•	Array
	•	Hash Table
	•	Prefix Sum

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1; // base case: sum 0 occurs once
    int count = 0, prefixSum = 0;
    
    for (int num : nums) {
        prefixSum += num;
        if (mp.find(prefixSum - k) != mp.end()) {
            count += mp[prefixSum - k];
        }
        mp[prefixSum]++;
    }
    
    return count;
}

int main() {
    vector<int> nums = {1,1,1};
    int k = 2;
    cout << subarraySum(nums, k) << endl; // Output: 2
    return 0;
}