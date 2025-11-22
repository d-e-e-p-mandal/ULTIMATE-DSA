# Tower Of Hanoi

## 📌 Problem Statement
You are given n disks placed on a starting rod (from), with the smallest disk on top and the largest at the bottom. There are three rods: the starting rod(from), the target rod (to), and an auxiliary rod (aux).
You have to calculate the minimum number of moves required to transfer all n disks from the starting rod to the target rod, following these rules:
      1. Only one disk can be moved at a time.
      2. A disk can only be placed on top of a larger disk or on an empty rod.
Return the minimum number of moves needed to complete the task.

---

[GFG](https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1)

---

## ✨ Examples

### Example 1
**Input:**  
`n = 2`

**Output:**  
`3`

**Explanation:**  
For n = 2, total 3 steps will be taken. Steps are as follows -  
move disk 1 from rod 1 to rod 2  
move disk 2 from rod 1 to rod 3  
move disk 1 from rod 2 to rod 3

---

### Example 2
**Input:**  
`n = 3`

**Output:**  
`7`

**Explanation:**  
For n = 3, total 7 steps will be taken. Steps are as follows -  
move disk 1 from rod 1 to rod 3  
move disk 2 from rod 1 to rod 2  
move disk 1 from rod 3 to rod 2  
move disk 3 from rod 1 to rod 3  
move disk 1 from rod 2 to rod 1  
move disk 2 from rod 2 to rod 3  
move disk 1 from rod 1 to rod 3

---

### Example 3
**Input:**  
`n = 0`

**Output:**  
`0`

**Explanation:**  
Total 0 steps will be taken.

---

## 🎯 Constraints
- 0 ≤ n ≤ 20

---

## ⏱️ Expected Complexity
- Time Complexity: O(2^n)  
- Auxiliary Space: O(n)

---

## 💡 Approach – Recursion
1. Move n-1 disks from source to auxiliary.  
2. Move the largest disk from source to target.  
3. Move n-1 disks from auxiliary to target.  
4. Total moves = 2^n - 1

---

🏷️ Company Tags
	•	Flipkart
	•	Microsoft

⸻

🏷️ Topic Tags
	•	Recursion
	•	Algorithms

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long toh(int n, int from, int to, int aux) {
        if(n == 0) return 0;
        
        long long moves = 0;

        moves += toh(n-1, from, aux, to);
        moves += 1;
        moves += toh(n-1, aux, to, from);

        return moves;
    }
};

int main() {
    Solution sol;

    cout << sol.toh(2, 1, 3, 2) << endl; // Output: 3
    cout << sol.toh(3, 1, 3, 2) << endl; // Output: 7
    cout << sol.toh(0, 1, 3, 2) << endl; // Output: 0

    return 0;
}
```