# Longest Consecutive Subsequence

[GeeksForGeeks Problem Link](https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1)

---

## 📌 Problem Statement
You are given an array `arr[]` of non-negative integers.  
Your task is to **find the length of the longest subsequence** such that the elements in the subsequence are **consecutive integers**, irrespective of their order in the array.

> The consecutive elements can appear in any order in the given array.

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [2, 6, 1, 9, 4, 5, 3]`  

**Output:**  
`6`  

**Explanation:**  
The consecutive numbers are `[1, 2, 3, 4, 5, 6]`, forming the longest consecutive subsequence of length `6`.

---

### Example 2
**Input:**  
`arr = [1, 9, 3, 10, 4, 20, 2]`  

**Output:**  
`4`  

**Explanation:**  
The longest consecutive subsequence is `[1, 2, 3, 4]`.

---

### Example 3
**Input:**  
`arr = [15, 13, 12, 14, 11, 10, 9]`  

**Output:**  
`7`  

**Explanation:**  
The numbers `[9, 10, 11, 12, 13, 14, 15]` form the longest consecutive subsequence.

---

## 🎯 Constraints
- `1 ≤ arr.size() ≤ 10^5`  
- `0 ≤ arr[i] ≤ 10^5`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n)` using HashSet |
| **Space Complexity** | `O(n)` for storing unique elements |

---

## 🏢 Company Tags
Amazon, Microsoft, Walmart

---

## 🏷️ Topic Tags
- Hashing  
- Arrays  
- Data Structures  

---

## 💡 Approach – Using HashSet
We use a **HashSet** to efficiently check the presence of consecutive numbers.

### 🔍 Steps:
1. Insert all array elements into a **HashSet** for `O(1)` lookup.
2. Iterate through the array:
   - For each element `x`, check if `x-1` exists in the set.
   - If not, `x` is the start of a potential consecutive sequence.
   - Count the sequence length by checking for `x+1, x+2, ...` until not found.
3. Keep track of the **maximum length** found.
4. Return the maximum length after the loop.

---

## 🧠 Algorithm
1. Insert all numbers into a set.  
2. Initialize `longest = 0`.  
3. For each element `num` in `arr`:
   - If `(num - 1)` not in set → start counting sequence from `num`.
   - Initialize `current_num = num` and `streak = 1`.
   - While `(current_num + 1)` exists → increment `streak` and `current_num`.
   - Update `longest = max(longest, streak)`.
4. Return `longest`.

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(vector<int>& arr) {
    unordered_set<int> s(arr.begin(), arr.end());
    int longest = 0;

    for (int num : s) {
        // Check for sequence start
        if (s.find(num - 1) == s.end()) {
            int current_num = num;
            int streak = 1;

            // Count consecutive numbers
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
    vector<int> arr = {2, 6, 1, 9, 4, 5, 3};
    cout << findLongestConseqSubseq(arr); // Output: 6
    return 0;
}