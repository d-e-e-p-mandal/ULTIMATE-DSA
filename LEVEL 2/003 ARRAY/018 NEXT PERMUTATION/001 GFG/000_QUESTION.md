# Next Permutation

[GeeksForGeeks Problem Link](https://practice.geeksforgeeks.org/problems/next-permutation5226/1)

---

## 📌 Problem Statement
You are given an array of integers `arr[]` representing a **permutation**.  

Your task is to **rearrange** the elements into the **lexicographically next greater permutation** of numbers.  

If no such permutation exists, rearrange the array into the **lowest possible order** (i.e., sorted in ascending order).  

> A permutation of an array refers to a specific arrangement of its elements in a sequence or linear order.

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [2, 4, 1, 7, 5, 0]`  

**Output:**  
`[2, 4, 5, 0, 1, 7]`  

**Explanation:**  
The next permutation of the given array is `[2, 4, 5, 0, 1, 7]`.

---

### Example 2
**Input:**  
`arr = [3, 2, 1]`  

**Output:**  
`[1, 2, 3]`  

**Explanation:**  
As the given array is the last permutation, the next permutation is the lowest possible one.

---

### Example 3
**Input:**  
`arr = [3, 4, 2, 5, 1]`  

**Output:**  
`[3, 4, 5, 1, 2]`  

**Explanation:**  
The next permutation of `[3, 4, 2, 5, 1]` is `[3, 4, 5, 1, 2]`.

---

## 🎯 Constraints
- `1 ≤ arr.size() ≤ 10^5`  
- `0 ≤ arr[i] ≤ 10^5`

---

## ⏱️ Expected Complexities
| Complexity Type | Description |
|-----------------|-------------|
| **Time Complexity** | `O(n)` — Single traversal from right and constant swaps |
| **Space Complexity** | `O(1)` — In-place rearrangement without extra space |

---

## 🏢 Company Tags
Infosys, Flipkart, Amazon, Microsoft, FactSet, Hike, MakeMyTrip, Google, Qualcomm, Salesforce

---

## 🏷️ Topic Tags
- Arrays  
- Permutation  
- Constructive Algorithms  
- Data Structures  

---

## 💡 Approach – Lexicographic Next Permutation
To generate the next permutation in lexicographic order:

1. **Find the break point:**  
   Traverse from the end to find the first index `i` such that `arr[i] < arr[i+1]`.  
   This index marks where the next permutation can increase.

2. **If no such index exists:**  
   The array is in descending order, meaning it's the last permutation — so reverse it to get the smallest permutation.

3. **Find the smallest element greater than `arr[i]`:**  
   Traverse from the right to find index `j` such that `arr[j] > arr[i]`.

4. **Swap `arr[i]` and `arr[j]`.**

5. **Reverse the subarray from `i+1` to end** to get the smallest lexicographic order for that suffix.

---

## 🧠 Algorithm
1. Set `i = n - 2`.  
2. Move `i` leftward while `arr[i] >= arr[i+1]`.  
3. If `i < 0`, reverse entire array and return (last permutation case).  
4. Otherwise:
   - Find `j = n - 1` such that `arr[j] > arr[i]`.  
   - Swap `arr[i]` and `arr[j]`.  
   - Reverse subarray from `i + 1` to `n - 1`.  
5. Return the modified array.

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& arr) {
    int n = arr.size();
    int i = n - 2;

    // Step 1: Find first decreasing element from the right
    while (i >= 0 && arr[i] >= arr[i + 1]) i--;

    // Step 2: If not last permutation
    if (i >= 0) {
        int j = n - 1;
        // Find element just greater than arr[i]
        while (arr[j] <= arr[i]) j--;
        swap(arr[i], arr[j]);
    }

    // Step 3: Reverse the suffix
    reverse(arr.begin() + i + 1, arr.end());
}

int main() {
    vector<int> arr = {2, 4, 1, 7, 5, 0};
    nextPermutation(arr);

    for (int num : arr) cout << num << " ";
    return 0;
}
```