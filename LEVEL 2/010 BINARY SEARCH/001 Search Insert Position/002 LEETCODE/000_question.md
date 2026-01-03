# Search Insert Position

## 📌 Problem Statement
Given a sorted array of distinct integers and a target value, return the index if the target is found.  
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

---

## 🔗 Problem Link
https://leetcode.com/problems/search-insert-position/

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [1,3,5,6], target = 5`

**Output:**  
`2`

---

### Example 2
**Input:**  
`nums = [1,3,5,6], target = 2`

**Output:**  
`1`

---

### Example 3
**Input:**  
`nums = [1,3,5,6], target = 7`

**Output:**  
`4`

---

## 🎯 Constraints
- 1 <= nums.length <= 10^4  
- -10^4 <= nums[i] <= 10^4  
- nums contains distinct values sorted in ascending order  
- -10^4 <= target <= 10^4  

---

## ⏱️ Expected Complexities
- Time Complexity: O(log n)  
- Auxiliary Space: O(1)

---

## 💡 Approach – Binary Search
1. Use binary search to find the position of target.  
2. If found, return the index.  
3. If not found, return the left pointer (the insertion point).  

---

🏷️ Topic Tags
	•	Array
	•	Binary Search

⸻

🏷️ Company Tags
	•	(Interview experience not specified)

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};

int main(){
    Solution sol;

    vector<int> nums1 = {1,3,5,6};
    cout << sol.searchInsert(nums1, 5) << endl; // Output: 2

    vector<int> nums2 = {1,3,5,6};
    cout << sol.searchInsert(nums2, 2) << endl; // Output: 1

    vector<int> nums3 = {1,3,5,6};
    cout << sol.searchInsert(nums3, 7) << endl; // Output: 4

    return 0;
}
```
