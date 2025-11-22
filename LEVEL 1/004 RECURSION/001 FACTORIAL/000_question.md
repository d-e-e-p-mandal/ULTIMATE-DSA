# Factorial

## 📌 Problem Statement
Given a positive integer `n`, find the **factorial of n**.  
If n = 0, return 1.

---

[GFG](https://practice.geeksforgeeks.org/problems/factorial/0)

---

## ✨ Examples

### Example 1
**Input:**  
`n = 5`  

**Output:**  
`120`  

**Explanation:**  
1 x 2 x 3 x 4 x 5 = 120

---

### Example 2
**Input:**  
`n = 4`  

**Output:**  
`24`  

**Explanation:**  
1 x 2 x 3 x 4 = 24

---

## 🎯 Constraints
- 0 ≤ n ≤ 12

---

## ⏱️ Expected Complexity
- **Time Complexity:** O(n)  
- **Auxiliary Space:** O(1)

---

## 💡 Approach – Iterative Multiplication
1. Initialize result as 1.  
2. Multiply result by every number from 1 to n.  
3. Return the final result.

---

🏷️ Company Tags
	•	Morgan Stanley
	•	Samsung
	•	FactSet
	•	MAQ Software
	•	Wipro

⸻

🏷️ Topic Tags
	•	Mathematical
	•	Algorithms

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int factorial(int n) {
        long long ans = 1;

        for (int i = 1; i <= n; i++) {
            ans *= i;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    cout << sol.factorial(5) << endl; // Output: 120
    cout << sol.factorial(4) << endl; // Output: 24
    cout << sol.factorial(0) << endl; // Output: 1

    return 0;
}