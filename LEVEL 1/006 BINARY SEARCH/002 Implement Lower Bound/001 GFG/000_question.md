# Implement Lower Bound

## 📌 Problem Statement
Given a sorted array arr[] and a number target, the task is to find the lower bound of the target in this given array. The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the given number.

Note: If all the elements in the given array are smaller than the target, the lower bound will be the length of the array. 

---

[GFG](https://practice.geeksforgeeks.org/problems/lower-bound-in-log-n/1)

---

## ✨ Examples

### Example 1
**Input:**  
`arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9`

**Output:**  
`3`

**Explanation:**  
3 is the smallest index in arr[] where element (arr[3] = 10) is greater than or equal to 9.

---

### Example 2
**Input:**  
`arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11`

**Output:**  
`4`

**Explanation:**  
4 is the smallest index in arr[] where element (arr[4] = 11) is greater than or equal to 11.

---

### Example 3
**Input:**  
`arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100`

**Output:**  
`7`

**Explanation:**  
As no element in arr[] is greater than 100, return the length of array.

---

## 🎯 Constraints
- 1 ≤ arr.size() ≤ 10^6  
- 1 ≤ arr[i] ≤ 10^6  
- 1 ≤ target ≤ 10^6

---

## ⏱️ Expected Complexity
- Time Complexity: O(log n)  
- Auxiliary Space: O(1)

---

## 💡 Approach – Binary Search
1. Use binary search to find the first index where arr[mid] >= target.  
2. If no such index exists, return array size.  
3. Standard lower-bound implementation.

---

🏷️ Topic Tags
	•	Binary Search
	•	Arrays
	•	Algorithms

---

## 🖥️ C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int lowerBound(vector<int>& arr, int target){
        int low = 0, high = arr.size();
        
        while(low < high){
            int mid = low + (high - low) / 2;
            
            if(arr[mid] >= target)
                high = mid;
            else
                low = mid + 1;
        }
        
        return low;
    }
};

int main(){
    Solution sol;
    
    vector<int> arr = {2, 3, 7, 10, 11, 11, 25};
    cout << sol.lowerBound(arr, 9) << endl;   // Output: 3
    cout << sol.lowerBound(arr, 11) << endl;  // Output: 4
    cout << sol.lowerBound(arr, 100) << endl; // Output: 7

    return 0;
}
```