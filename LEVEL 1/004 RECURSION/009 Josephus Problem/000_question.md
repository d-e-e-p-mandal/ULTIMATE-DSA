# Josephus Problem

## 📌 Problem Statement
You are playing a game with n people standing in a circle, numbered from 1 to n. Starting from person 1, every kth person is eliminated in a circular fashion. The process continues until only one person remains.
Given integers n and k, return the position (1-based index) of the person who will survive.

---

## 🔗 Problem Link
https://practice.geeksforgeeks.org/problems/josephus-problem/1

---

## ✨ Examples

### Example 1
**Input:**  
`n = 5, k = 2`

**Output:**  
`3`

**Explanation:**  
Firstly, the person at position 2 is killed, then the person at position 4 is killed, then the person at position 1 is killed.  
Finally, the person at position 5 is killed. So the person at position 3 survives.

---

### Example 2
**Input:**  
`n = 7, k = 3`

**Output:**  
`4`

**Explanation:**  
The elimination order is 3 → 6 → 2 → 7 → 5 → 1, and the person at position 4 survives.

---

## 🎯 Constraints
- 1 ≤ n, k ≤ 500

---

## ⏱️ Expected Complexity
- Time Complexity: O(n)  
- Auxiliary Space: O(n)

---

## 💡 Approach – Recursive Josephus Formula
1. Base case: J(1, k) = 1  
2. Recursive: J(n, k) = (J(n-1, k) + k - 1) % n + 1  
3. Final result is the safe position.

---

🏷️ Company Tags
	•	Amazon
	•	Microsoft
	•	Walmart

⸻

🏷️ Topic Tags
	•	Recursion
	•	Data Structures
	•	Algorithms

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int josephus(int n, int k) {
        if(n == 1) return 1;
        return (josephus(n-1, k) + k - 1) % n + 1;
    }
};

int main() {
    Solution sol;

    cout << sol.josephus(5, 2) << endl; // Output: 3
    cout << sol.josephus(7, 3) << endl; // Output: 4

    return 0;
}