# Sort 0s, 1s and 2s

[GFG](https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1)

## 📌 Problem Statement
You are given an array `arr[]` containing only **0s**, **1s**, and **2s**.  
Your task is to sort the array in ascending order — all 0s first, then 1s, followed by 2s.

📋 **Note:** You must solve this problem **without using the built-in sort function.**

---

## ✨ Examples

### Example 1
**Input:**  
`arr = [0, 1, 2, 0, 1, 2]`  

**Output:**  
`[0, 0, 1, 1, 2, 2]`  

**Explanation:**  
All 0s, 1s, and 2s are segregated into ascending order.

---

### Example 2
**Input:**  
`arr = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]`  

**Output:**  
`[0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]`  

**Explanation:**  
All 0s, 1s, and 2s are grouped and sorted correctly.

---

## 🎯 Constraints
- `1 ≤ arr.size() ≤ 10^6`  
- `0 ≤ arr[i] ≤ 2`  

---

## ⏱️ Expected Complexities
- **Time Complexity:** `O(n)`  
- **Auxiliary Space:** `O(1)`  

---

## 💡 Approach 1 – Counting Method (Two Pass)
1. Count the number of 0s, 1s, and 2s.  
2. Rewrite the array based on the counts.

### ✅ Example
For `arr = [0, 1, 2, 0, 1, 2]`  
Count(0) = 2, Count(1) = 2, Count(2) = 2 → final `[0, 0, 1, 1, 2, 2]`.

---

## 💡 Approach 2 – Dutch National Flag Algorithm (One Pass, O(1) Space)
This is the **optimal approach** developed by Edsger Dijkstra.

### Steps:
- Maintain three pointers:
  - `low` → boundary for 0s
  - `mid` → current index
  - `high` → boundary for 2s
- Traverse the array once and swap accordingly.

---

## 🧠 Algorithm
1. Initialize `low = 0`, `mid = 0`, `high = n - 1`.  
2. While `mid <= high`:  
   - If `arr[mid] == 0`: swap with `arr[low]`, increment both.  
   - If `arr[mid] == 1`: just increment `mid`.  
   - If `arr[mid] == 2`: swap with `arr[high]`, decrement `high`.  

---

🏷️ Company Tags

Paytm, Flipkart, Morgan Stanley, Amazon, Microsoft, OYO Rooms, Samsung, Snapdeal, Hike, MakeMyTrip, Ola Cabs, Walmart, MAQ Software, Adobe, Yatra.com, SAP Labs, Qualcomm

⸻

🏷️ Topic Tags
	•	Arrays
	•	Sorting
	•	Data Structures
	•	Algorithms

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++; mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 2, 0, 1, 2};
    sort012(arr);
    for (int x : arr) cout << x << " ";
    return 0;
}