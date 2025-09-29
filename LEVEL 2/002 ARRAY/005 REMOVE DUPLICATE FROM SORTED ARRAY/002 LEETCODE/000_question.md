# Remove Duplicates from Sorted Array (In-Place)

[LeetCode](https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/)

## 📌 Problem Statement
Given a **sorted integer array** `nums` in non-decreasing order, remove the **duplicates in-place** so that each unique element appears **only once**.  

- The **relative order** of the elements should be kept the same.  
- Return the **number of unique elements** `k`.  
- Modify the array so that the **first `k` elements contain the unique elements**.  
- The elements beyond the first `k` are **not important**.

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [1,1,2]`  

**Output:**  
`2, nums = [1,2,_]`  

**Explanation:**  
Return `k = 2`, with the first two elements being `1` and `2`. The remaining element is ignored.

---

### Example 2
**Input:**  
`nums = [0,0,1,1,1,2,2,3,3,4]`  

**Output:**  
`5, nums = [0,1,2,3,4,_,_,_,_,_]`  

**Explanation:**  
Return `k = 5`, with the first five elements being `0,1,2,3,4`. Remaining elements are ignored.

---

## 🎯 Constraints
- `1 <= nums.length <= 3 * 10^4`  
- `-100 <= nums[i] <= 100`  
- `nums` is sorted in non-decreasing order

---

## ⏱️ Expected Complexity
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)`  

---

## 💡 Approach (Two-Pointer)
1. Use **slow pointer `i`** to track the last unique element index.  
2. Traverse the array with **fast pointer `j`**.  
3. Whenever `nums[j] != nums[i]`:  
   - Increment `i` and set `nums[i] = nums[j]`.  
4. Return `i + 1` as the number of unique elements (`k`).  

---

🏷️ Topic Tags
	•	Array
	•	Two Pointers

---
## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int i = 0; // slow pointer
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1; // number of unique elements
}

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k = removeDuplicates(nums);
    cout << "k = " << k << "\nnums = ";
    for (int n : nums) cout << n << " ";
    cout << endl;
    return 0;
}