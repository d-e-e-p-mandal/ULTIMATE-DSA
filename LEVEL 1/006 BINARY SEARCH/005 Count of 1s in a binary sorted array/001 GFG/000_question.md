# Count 1's in binary array

## 📌 Problem Statement
You are given a binary array that is sorted in non-increasing order, meaning all the 1's appear before the 0's. Find the total number of 1's present in the array.

---

## 🔗 Problem Link
[GFG](https://geeksforgeeks.org/problems/count-ones-in-binary-array-1587115620/1)

---

## ✨ Examples

### Example 1
**Input:**  
`arr[] = [1, 1, 1, 1, 1, 0, 0, 0]`

**Output:**  
`5`

**Explaination:**  
Count of 1's in the array is 5.

---

### Example 2
**Input:**  
`arr[] = [1, 1, 1, 1, 1, 1, 1]`

**Output:**  
`7`

**Explaination:**  
Count of 1's in the array is 7.

---

## 🎯 Constraints
- 1 ≤ arr.size() ≤ 10^5  
- 0 ≤ arr[i] ≤ 1

---

## ⏱️ Expected Complexity
- Time Complexity: O(log n)  
- Auxiliary Space: O(1)

---

## 💡 Approach – Binary Search
1. Since array is non-increasing, all 1's come first.  
2. Use binary search to find the first index where 0 appears.  
3. That index is the count of 1's.  
4. If no 0 exists, answer is array size.

---

🏷️ Topic Tags
	•	Searching
	•	Algorithms

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countOnes(vector<int>& arr){
        int low = 0, high = arr.size();
        
        while(low < high){
            int mid = low + (high - low) / 2;
            
            if(arr[mid] == 1)
                low = mid + 1;
            else
                high = mid;
        }
        
        return low; // number of 1's
    }
};

int main(){
    Solution sol;

    vector<int> arr1 = {1, 1, 1, 1, 1, 0, 0, 0};
    cout << sol.countOnes(arr1) << endl;  // Output: 5

    vector<int> arr2 = {1, 1, 1, 1, 1, 1, 1};
    cout << sol.countOnes(arr2) << endl;  // Output: 7

    return 0;
}
```