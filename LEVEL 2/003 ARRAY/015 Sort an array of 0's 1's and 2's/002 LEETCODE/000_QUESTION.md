# Sort Colors

[LeetCode Problem Link](https://leetcode.com/problems/sort-colors/)

---

## 📌 Problem Statement
You are given an integer array `nums` with `n` objects colored **red**, **white**, or **blue**,  
represented by the integers `0`, `1`, and `2` respectively.  

Your task is to **sort them in-place** so that objects of the same color are adjacent,  
and the colors appear in the order **red → white → blue**.

📋 **Note:** You must solve this problem **without using the library’s sort function**.

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [2, 0, 2, 1, 1, 0]`  

**Output:**  
`[0, 0, 1, 1, 2, 2]`  

**Explanation:**  
After sorting, all red(0), white(1), and blue(2) objects are grouped in order.

---

### Example 2
**Input:**  
`nums = [2, 0, 1]`  

**Output:**  
`[0, 1, 2]`  

---

## 🎯 Constraints
- `n == nums.length`  
- `1 ≤ n ≤ 300`  
- `nums[i]` is either `0`, `1`, or `2`.

---

## ⏱️ Expected Complexities
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)`  

---

## 💡 Approach – Dutch National Flag Algorithm (Optimal One-Pass)
This is the **optimal approach** created by **Edsger Dijkstra**.

### Intuition
We maintain three regions:
- **0s region:** `[0 … low-1]`
- **1s region:** `[low … mid-1]`
- **Unprocessed region:** `[mid … high]`
- **2s region:** `[high+1 … n-1]`

We move through the array once and swap elements into their correct regions.

---

## 🧠 Algorithm
1. Initialize `low = 0`, `mid = 0`, and `high = n - 1`.  
2. While `mid <= high`:  
   - If `nums[mid] == 0`: swap with `nums[low]`, increment both.  
   - If `nums[mid] == 1`: just increment `mid`.  
   - If `nums[mid] == 2`: swap with `nums[high]`, decrement `high`.  

---

## ⏱️ Time & Space Complexity

| Complexity Type | Description |
|------------------|-------------|
| **Time Complexity** | **O(n)** — Each element is visited at most once in a single traversal. |
| **Space Complexity** | **O(1)** — Sorting is done in-place using constant extra space. |

---

## 🏢 Company Tags
Amazon, Microsoft, Facebook, Google, Apple, Adobe, Bloomberg, Flipkart, Walmart Labs, Paytm

---

## 🏷️ Topic Tags
- Arrays  
- Two Pointers  
- Sorting  
- In-place Algorithms  

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++; mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    for (int x : nums) cout << x << " ";
    return 0;
}

```
