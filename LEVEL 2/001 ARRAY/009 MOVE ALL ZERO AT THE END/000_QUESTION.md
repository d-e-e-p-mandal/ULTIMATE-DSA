# Move Zeroes

[LEETCODE](https://leetcode.com/problems/move-zeroes/description/)

## 📌 Problem Statement
Given an integer array `nums`, move all `0`s to the **end** of it while maintaining the **relative order** of the non-zero elements.  

You must do this **in-place** without making a copy of the array.  

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [0,1,0,3,12]`  

**Output:**  
`[1,3,12,0,0]`  

---

### Example 2
**Input:**  
`nums = [0]`  

**Output:**  
`[0]`  

---

## 🎯 Constraints
- `1 <= nums.length <= 10^4`  
- `-2^31 <= nums[i] <= 2^31 - 1`  

---

## 🏗️ Follow Up
- Could you **minimize the total number of operations** done?  

---

## ⏱️ Expected Complexity
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)`  

---

## 💡 Approach (Two Pointers)
1. Maintain a pointer `j` for the position of the **next non-zero element**.  
2. Traverse the array:  
   - If `nums[i] != 0`, swap `nums[i]` with `nums[j]` and increment `j`.  
3. This ensures all non-zeros are shifted left and zeros moved to the end.  

---

🏷️ Topic Tags
	•	Array
	•	Two Pointers

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int j = 0; // position for next non-zero element

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main() {
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);

    cout << "After moving zeroes: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}