# 189. Rotate Array

[LEETCODE](https://leetcode.com/problems/rotate-array/description/)

## 📌 Problem Statement
Given an integer array `nums`, rotate the array to the **right** by `k` steps, where `k` is non-negative.

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [1,2,3,4,5,6,7], k = 3`  

**Output:**  
`[5,6,7,1,2,3,4]`  

**Explanation:**  
- Rotate 1 step → `[7,1,2,3,4,5,6]`  
- Rotate 2 steps → `[6,7,1,2,3,4,5]`  
- Rotate 3 steps → `[5,6,7,1,2,3,4]`  

---

### Example 2
**Input:**  
`nums = [-1,-100,3,99], k = 2`  

**Output:**  
`[3,99,-1,-100]`  

**Explanation:**  
- Rotate 1 step → `[99,-1,-100,3]`  
- Rotate 2 steps → `[3,99,-1,-100]`  

---

## 🎯 Constraints
- `1 <= nums.length <= 10^5`  
- `-2^31 <= nums[i] <= 2^31 - 1`  
- `0 <= k <= 10^5`

---

## 🏗️ Follow Up
- Try solving with **O(1) extra space**.  
- There are at least **3 different approaches**.

---

## ⏱️ Expected Complexity
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)` (for optimal solution)

---

## 💡 Approaches

### ✅ Approach 1: Naive (Rotate One Step at a Time) — O(n*k)
- Rotate the array one step, `k` times.  
- Too slow for large `k`.

---

### ✅ Approach 2: Extra Array — O(n) Time, O(n) Space
1. Create a new array.  
2. Place each element at its rotated position:  
   `newArr[(i + k) % n] = nums[i]`.  
3. Copy back to original.  

---

### ✅ Approach 3: Reversal Algorithm (Optimal, O(1) Space)
1. Reduce `k = k % n`.  
2. **Reverse the entire array.**  
3. **Reverse first k elements.**  
4. **Reverse remaining n-k elements.**

---

🏷️ Topic Tags
	•	Array
	•	Math
	•	Two Pointers


---

## 🖥️ C++ Implementation (Optimal: Reversal Method)

```cpp
#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>& nums, int l, int r) {
    while (l < r) swap(nums[l++], nums[r--]);
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    // Step 1: Reverse entire array
    reverseArray(nums, 0, n - 1);

    // Step 2: Reverse first k elements
    reverseArray(nums, 0, k - 1);

    // Step 3: Reverse remaining n-k elements
    reverseArray(nums, k, n - 1);
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    rotate(nums, k);

    cout << "Rotated Array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}