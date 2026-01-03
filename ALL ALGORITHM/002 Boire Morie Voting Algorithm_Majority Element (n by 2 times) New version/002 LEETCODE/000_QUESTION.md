# 961. N-Repeated Element in Size 2N Array

## 📌 Problem Statement
You are given an integer array nums with the following properties:

nums.length == 2 * n  
nums contains n + 1 unique elements  
Exactly one element of nums is repeated n times  

Return the element that is repeated n times.

---

## 🔗 Problem Link
https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [1,2,3,3]`

**Output:**  
`3`

---

### Example 2
**Input:**  
`nums = [2,1,2,5,3,2]`

**Output:**  
`2`

---

### Example 3
**Input:**  
`nums = [5,1,5,2,5,3,5,4]`

**Output:**  
`5`

---

## 🎯 Constraints
- 2 <= n <= 5000  
- nums.length == 2 * n  
- 0 <= nums[i] <= 10^4  
- nums contains n + 1 unique elements and one element is repeated exactly n times  

---

## ⏱️ Expected Complexities
- Time Complexity: O(n)  
- Auxiliary Space: O(n)

---

## 💡 Approach – Hash Table
1. Traverse the array and store frequency of each element using a hash table.  
2. The element whose frequency becomes greater than 1 and finally reaches n is the answer.  
3. Return that element.

---

🏷️ Topic Tags
	•	Array  
	•	Hash Table  

⸻

🏷️ Company Tags
	•	(LeetCode Weekly Contest 116)

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int x : nums){
            mp[x]++;
            if(mp[x] > 1)
                return x;
        }
        return -1;
    }
};

int main(){
    Solution sol;

    vector<int> nums1 = {1,2,3,3};
    cout << sol.repeatedNTimes(nums1) << endl; // Output: 3

    vector<int> nums2 = {2,1,2,5,3,2};
    cout << sol.repeatedNTimes(nums2) << endl; // Output: 2

    vector<int> nums3 = {5,1,5,2,5,3,5,4};
    cout << sol.repeatedNTimes(nums3) << endl; // Output: 5

    return 0;
}