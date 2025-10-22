# Longest Consecutive Sequence

[LeetCode Problem Link](https://leetcode.com/problems/longest-consecutive-sequence/)

---

## 📌 Problem Statement
Given an unsorted array of integers `nums`, return the length of the **longest consecutive elements sequence**.  

You must write an algorithm that runs in **O(n) time**.

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [100,4,200,1,3,2]`  

**Output:**  
`4`  

**Explanation:**  
The longest consecutive elements sequence is `[1, 2, 3, 4]`.

---

### Example 2
**Input:**  
`nums = [0,3,7,2,5,8,4,6,0,1]`  

**Output:**  
`9`  

**Explanation:**  
The sequence `[0,1,2,3,4,5,6,7,8]` is the longest consecutive sequence.

---

### Example 3
**Input:**  
`nums = [1,0,1,2]`  

**Output:**  
`3`  

**Explanation:**  
The sequence `[0,1,2]` is the longest consecutive sequence.

---

## 🎯 Constraints
- `0 <= nums.length <= 10^5`  
- `-10^9 <= nums[i] <= 10^9`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n)` |
| **Space Complexity** | `O(n)` |

---

## 🏢 Company Tags
Amazon, Microsoft, Google

---

## 🏷️ Topic Tags
- Array  
- Hash Table  
- Union Find  
- Data Structures  

---

## 💡 Approach – Using HashSet
We use a **HashSet** to track all numbers and find consecutive sequences efficiently.

### 🔍 Steps:
1. Insert all elements into a **HashSet** for O(1) lookup.  
2. Iterate through each number:
   - If `num-1` is **not in the set**, `num` is the start of a sequence.  
   - Count the length of the consecutive sequence starting from `num`.  
3. Keep track of the **maximum sequence length** found.  
4. Return the maximum length.

---

## 🧠 Algorithm
1. Convert array to `unordered_set` → `s`.  
2. Initialize `longest = 0`.  
3. For each `num` in `s`:
   - If `(num - 1)` not in `s`:  
     - Start a sequence `current_num = num` and `streak = 1`.  
     - While `(current_num + 1)` exists in `s`:  
       - `current_num++`, `streak++`  
     - Update `longest = max(longest, streak)`  
4. Return `longest`.

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;

    for (int num : s) {
        if (s.find(num - 1) == s.end()) {
            int current_num = num;
            int streak = 1;

            while (s.find(current_num + 1) != s.end()) {
                current_num++;
                streak++;
            }

            longest = max(longest, streak);
        }
    }

    return longest;
}

int main() {
    vector<int> nums = {100,4,200,1,3,2};
    cout << longestConsecutive(nums); // Output: 4
    return 0;
}
```
