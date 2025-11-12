# Merge Intervals

[LeetCode Problem Link](https://leetcode.com/problems/merge-intervals/)

---

## 📌 Problem Statement
Given an array of intervals where `intervals[i] = [starti, endi]`,  
merge all overlapping intervals and return an array of the **non-overlapping intervals** that cover all the intervals in the input.

---

## ✨ Examples

### Example 1
**Input:**  
`intervals = [[1,3],[2,6],[8,10],[15,18]]`  
**Output:**  
`[[1,6],[8,10],[15,18]]`  
**Explanation:**  
Since intervals `[1,3]` and `[2,6]` overlap, merge them into `[1,6]`.

---

### Example 2
**Input:**  
`intervals = [[1,4],[4,5]]`  
**Output:**  
`[[1,5]]`  
**Explanation:**  
Intervals `[1,4]` and `[4,5]` are considered overlapping.

---

### Example 3
**Input:**  
`intervals = [[4,7],[1,4]]`  
**Output:**  
`[[1,7]]`  
**Explanation:**  
After sorting, `[1,4]` and `[4,7]` overlap, hence merged into `[1,7]`.

---

## 🎯 Constraints
- `1 <= intervals.length <= 10⁴`  
- `intervals[i].length == 2`  
- `0 <= starti <= endi <= 10⁴`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n log n)` (due to sorting) |
| **Space Complexity** | `O(n)` (for result array) |

---

## 🏢 Company Tags
Amazon, Microsoft, Google, Adobe, Facebook, Apple

---

## 🏷️ Topic Tags
- Array  
- Sorting  
- Greedy  
- Intervals  

---

## 💡 Approach – Sorting + Merging

### 🔍 Idea:
We first **sort** the intervals based on their start time.  
Then, iterate through them —  
if the current interval overlaps with the previous one, **merge** them;  
otherwise, push the current interval to the result.

---

### 🔹 Steps:
1. Sort the intervals by start time.  
2. Initialize `result` with the first interval.  
3. For each next interval:
   - Compare it with the **last interval** in `result`.  
   - If overlapping, merge by updating the end time.  
   - Else, push it to the result.  
4. Return the result.

---

## 🧠 Algorithm
1. Sort `intervals` by their start value.  
2. Initialize `merged` with first interval.  
3. Traverse from `i = 1` to `n-1`:
   - If `current.start <= merged.back().end` → merge.  
   - Else → push as new interval.  
4. Return `merged`.

---

## 🖥️ C++ Implementation

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};

        // Step 1: Sort by start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Initialize result with the first interval
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        // Step 3: Iterate and merge
        for (int i = 1; i < n; i++) {
            int lastEnd = merged.back()[1];
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            // Overlapping intervals → merge
            if (currStart <= lastEnd) {
                merged.back()[1] = max(lastEnd, currEnd);
            } else {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
```