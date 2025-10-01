# Two Sum

[LeetCode](https://leetcode.com/problems/two-sum/)

## 📌 Problem Statement
Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to `target`.  

- You may not use the same element twice.  
- You may return the answer in any order.  
- You can assume there is **exactly one solution**.  

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [2,7,11,15], target = 9`  

**Output:**  
`[0,1]`  

**Explanation:**  
`nums[0] + nums[1] = 2 + 7 = 9`.

---

### Example 2
**Input:**  
`nums = [3,2,4], target = 6`  

**Output:**  
`[1,2]`

---

### Example 3
**Input:**  
`nums = [3,3], target = 6`  

**Output:**  
`[0,1]`

---

## 🎯 Constraints
- `2 <= nums.length <= 10^4`  
- `-10^9 <= nums[i] <= 10^9`  
- `-10^9 <= target <= 10^9`  
- Only one valid answer exists.  

---

## ⏱️ Expected Complexity
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(n)`   

---

## 💡 Approach – HashMap
1. Use a hash map to store each number and its index.  
2. For each element `nums[i]`, check if `target - nums[i]` already exists in the map.  
3. If yes → return indices.  
4. Otherwise, store `nums[i]` in the map.  

---

🏷️ Company Tags
	•	Amazon
	•	Microsoft
	•	Google
	•	Facebook
	•	Apple

⸻

🏷️ Topic Tags
	•	Array
	•	Hash Table

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp; // value -> index
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }
        mp[nums[i]] = i;
    }
    return {}; // should not reach here as per constraints
}

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ans = twoSum(nums, target);
    cout << "[" << ans[0] << "," << ans[1] << "]" << endl; // Output: [0,1]
    return 0;
}