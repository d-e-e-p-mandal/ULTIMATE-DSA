# Search in Rotated Sorted Array

## 📌 Problem Statement
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is  
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]  

For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

---

## 🔗 Problem Link
https://leetcode.com/problems/search-in-rotated-sorted-array/

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [4,5,6,7,0,1,2], target = 0`  
**Output:**  
`4`

---

### Example 2
**Input:**  
`nums = [4,5,6,7,0,1,2], target = 3`  
**Output:**  
`-1`

---

### Example 3
**Input:**  
`nums = [1], target = 0`  
**Output:**  
`-1`

---

## 🎯 Constraints
- 1 <= nums.length <= 5000  
- -10^4 <= nums[i] <= 10^4  
- All values of nums are unique  
- nums is an ascending array that is possibly rotated  
- -10^4 <= target <= 10^4  

---

## ⏱️ Expected Complexity
- Time Complexity: O(log n)  
- Auxiliary Space: O(1)

---

## 💡 Approach – Binary Search in Rotated Array
1. Identify which half of the array (left or right) is sorted.  
2. If target lies in the sorted half, search there.  
3. Otherwise search in the unsorted half.  
4. Continue until low > high.

---

🏷️ Topic Tags
	•	Array
	•	Binary Search

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else {
                // Right half is sorted
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4,5,6,7,0,1,2};
    cout << sol.search(nums1, 0) << endl; // Output: 4

    vector<int> nums2 = {4,5,6,7,0,1,2};
    cout << sol.search(nums2, 3) << endl; // Output: -1

    vector<int> nums3 = {1};
    cout << sol.search(nums3, 0) << endl; // Output: -1

    return 0;
}
```