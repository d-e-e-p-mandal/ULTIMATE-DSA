# Subarray Sum Equals K

[LeetCode Problem Link](https://leetcode.com/problems/subarray-sum-equals-k/)

---

## 📌 Problem Statement
Given an array of integers `nums` and an integer `k`,  
return the **total number of subarrays** whose **sum equals to `k`**.

A **subarray** is a contiguous, non-empty sequence of elements within an array.

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [1, 1, 1], k = 2`  
**Output:**  
`2`  
**Explanation:**  
The subarrays with sum = 2 are `[1,1]` at indices (0,1) and (1,2).

---

### Example 2
**Input:**  
`nums = [1, 2, 3], k = 3`  
**Output:**  
`2`  
**Explanation:**  
The subarrays with sum = 3 are `[1,2]` and `[3]`.

---

## 🎯 Constraints
- `1 <= nums.length <= 2 × 10⁴`  
- `-1000 <= nums[i] <= 1000`  
- `-10⁷ <= k <= 10⁷`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n)` — Single pass using prefix sums and hashing |
| **Space Complexity** | `O(n)` — Hash map stores prefix sums |

---

## 🏢 Company Tags
Amazon, Google, Microsoft, Facebook, Adobe, Bloomberg

---

## 🏷️ Topic Tags
- Array  
- Hash Table  
- Prefix Sum  

---

## 💡 Approach – Prefix Sum + Hash Map

The idea is to track the cumulative sum (`prefix_sum`) and use a hash map to store how many times each prefix sum has occurred.  

For each element:
- Compute current `prefix_sum`.
- Check if `(prefix_sum - k)` exists in map → means there’s a previous prefix that forms a subarray summing to `k`.
- Increment count by the frequency of `(prefix_sum - k)`.
- Finally, increment frequency of current `prefix_sum` in map.

---

## 🧠 Algorithm
1. Initialize `count = 0`, `prefix_sum = 0`, and `unordered_map<int, int> freq = {{0, 1}}`.  
2. For each element `num` in `nums`:
   - Add `num` to `prefix_sum`.
   - If `(prefix_sum - k)` exists in map, add `freq[prefix_sum - k]` to `count`.
   - Increment `freq[prefix_sum]`.
3. Return `count`.

---

## 🧩 Dry Run Example

For `nums = [1, 2, 3], k = 3`

| i | num | prefix_sum | prefix_sum - k | Count Added | freq (prefix → count) |
|---|-----|-------------|----------------|--------------|------------------------|
| 0 | 1   | 1           | -2             | 0            | {0:1, 1:1}             |
| 1 | 2   | 3           | 0              | +1           | {0:1, 1:1, 3:1}        |
| 2 | 3   | 6           | 3              | +1           | {0:1, 1:1, 3:1, 6:1}   |

✅ **Final count = 2**

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixFreq;
        prefixFreq[0] = 1; // Handle subarrays starting from index 0
        
        int count = 0, prefixSum = 0;
        
        for (int num : nums) {
            prefixSum += num;
            
            // If prefixSum - k exists, add its frequency to count
            if (prefixFreq.find(prefixSum - k) != prefixFreq.end()) {
                count += prefixFreq[prefixSum - k];
            }
            
            // Increment current prefixSum frequency
            prefixFreq[prefixSum]++;
        }
        
        return count;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;
    Solution obj;
    cout << obj.subarraySum(nums, k); // Output: 2
    return 0;
}
```