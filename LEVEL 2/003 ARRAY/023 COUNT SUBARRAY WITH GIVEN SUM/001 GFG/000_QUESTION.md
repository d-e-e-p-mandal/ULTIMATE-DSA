# Subarrays with Sum K

[GeeksforGeeks Problem Link](https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1)

---

## 📌 Problem Statement
Given an **unsorted array** `arr[]` of integers,  
find the **number of subarrays** whose **sum exactly equals** a given number `k`.

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [10, 2, -2, -20, 10], k = -10`  
**Output:**  
`3`  
**Explanation:**  
The subarrays with sum `-10` are:  
- `arr[0...3] = [10, 2, -2, -20]`  
- `arr[1...4] = [2, -2, -20, 10]`  
- `arr[3...4] = [-20, 10]`

---

### Example 2
**Input:**  
`arr = [9, 4, 20, 3, 10, 5], k = 33`  
**Output:**  
`2`  
**Explanation:**  
Subarrays with sum `33` are:  
- `arr[0...2] = [9, 4, 20]`  
- `arr[2...4] = [20, 3, 10]`

---

### Example 3
**Input:**  
`arr = [1, 3, 5], k = 0`  
**Output:**  
`0`  
**Explanation:**  
No subarray has sum equal to 0.

---

## 🎯 Constraints
- `1 ≤ arr.size() ≤ 10⁵`  
- `-10³ ≤ arr[i] ≤ 10³`  
- `-10⁵ ≤ k ≤ 10⁵`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n)` — Single pass using prefix sum and hashing |
| **Space Complexity** | `O(n)` — Hash map for storing prefix sums |

---

## 🏢 Company Tags
Microsoft

---

## 🏷️ Topic Tags
Hash, Arrays, Data Structures

---

## 💡 Approach – Prefix Sum + Hash Map

This problem is an adaptation of the **prefix sum** technique with hashing.

### 🔍 Idea:
Let `prefix[i]` = sum of all elements from `arr[0]` to `arr[i]`.  
If at any index `i`, there exists a `prefix[j]` (where `j < i`) such that:
prefix[i] - prefix[j] = k

then the subarray `(j+1 ... i)` has a sum equal to `k`.

We store frequencies of prefix sums in a hash map and count valid pairs as we go.

---

### 🧠 Algorithm
1. Initialize:
   - `count = 0`
   - `prefix_sum = 0`
   - `unordered_map<int, int> freq` with `{0: 1}` (to handle case when subarray starts at index 0)
2. Traverse each element in `arr`:
   - Add `arr[i]` to `prefix_sum`.
   - Check if `(prefix_sum - k)` exists in the map → if yes, add its frequency to `count`.
   - Increment frequency of current `prefix_sum` in map.
3. Return `count`.

---

## 🧩 Dry Run

For `arr = [10, 2, -2, -20, 10], k = -10`

| i | arr[i] | prefix_sum | prefix_sum - k | Count Added | Map (prefix → freq) |
|---|--------:|------------:|---------------:|-------------:|--------------------:|
| 0 | 10      | 10          | 20             | 0            | {0:1, 10:1}         |
| 1 | 2       | 12          | 22             | 0            | {0:1,10:1,12:1}     |
| 2 | -2      | 10          | 20             | 0            | {0:1,10:2,12:1}     |
| 3 | -20     | -10         | 0              | +1           | {0:1,10:2,12:1,-10:1}|
| 4 | 10      | 0           | 10             | +2           | {0:2,10:2,12:1,-10:1}|

✅ Final `count = 3`

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subArraySum(vector<int>& arr, int k) {
        unordered_map<int, int> prefixFreq;
        prefixFreq[0] = 1; // Handle case where subarray starts at index 0
        
        int count = 0, prefixSum = 0;
        
        for (int num : arr) {
            prefixSum += num;
            
            // If (prefixSum - k) exists, add its frequency
            if (prefixFreq.find(prefixSum - k) != prefixFreq.end()) {
                count += prefixFreq[prefixSum - k];
            }
            
            // Increment frequency of current prefix sum
            prefixFreq[prefixSum]++;
        }
        
        return count;
    }
};

int main() {
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;
    Solution obj;
    cout << obj.subArraySum(arr, k); // Output: 3
    return 0;
}