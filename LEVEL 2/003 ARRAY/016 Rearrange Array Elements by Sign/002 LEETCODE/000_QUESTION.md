# Rearrange Array Elements by Sign

[LeetCode Problem Link](https://leetcode.com/problems/rearrange-array-elements-by-sign/)

---

## 📌 Problem Statement
You are given a 0-indexed integer array `nums` of **even length**, consisting of an **equal number of positive and negative integers**.

Your task is to rearrange the array such that:
1. Every **consecutive pair of integers** have **opposite signs**.
2. The **relative order** of positive and negative numbers is preserved.
3. The rearranged array **starts with a positive integer**.

Return the modified array.

---

## ✨ Examples

### Example 1
**Input:**  
`nums = [3,1,-2,-5,2,-4]`

**Output:**  
`[3,-2,1,-5,2,-4]`

**Explanation:**  
- Positive numbers → `[3,1,2]`  
- Negative numbers → `[-2,-5,-4]`  
We alternately place them → `[3,-2,1,-5,2,-4]`.

---

### Example 2
**Input:**  
`nums = [-1,1]`

**Output:**  
`[1,-1]`

**Explanation:**  
The only positive integer is `1` and the only negative integer is `-1`, so output is `[1,-1]`.

---

## 🎯 Constraints
- `2 <= nums.length <= 2 * 10^5`  
- `nums.length` is **even**  
- `1 <= |nums[i]| <= 10^5`  
- `nums` contains an **equal number** of positive and negative integers  
- It is **not required** to modify the array in-place  

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n)` — Single traversal to split and rearrange |
| **Space Complexity** | `O(n)` — Additional space for storing rearranged array |

---

## 🏢 Company Tags
Amazon, Google, Microsoft, Adobe, Flipkart, Apple, TCS, Cognizant, Accenture, Infosys

---

## 🏷️ Topic Tags
- Arrays  
- Two Pointers  
- Simulation  
- Data Structures  
- Algorithms

---

## 💡 Approach – Two List + Merge
The problem can be efficiently solved using **two separate arrays** for positive and negative numbers, then merging them alternately.

### 🔍 Steps:
1. Traverse `nums` and store:
   - Positive numbers in `pos`.
   - Negative numbers in `neg`.
2. Create a new array `result` of same length.
3. Place elements alternately:  
   - Even indices → positive numbers  
   - Odd indices → negative numbers

---

## 🧠 Algorithm
```text
1. Initialize two lists: pos[], neg[].
2. Traverse nums:
      if nums[i] > 0 → pos.push_back(nums[i])
      else → neg.push_back(nums[i])
3. Create result[] of size n.
4. For i in range(0, n/2):
      result[2*i] = pos[i]
      result[2*i + 1] = neg[i]
5. Return result.