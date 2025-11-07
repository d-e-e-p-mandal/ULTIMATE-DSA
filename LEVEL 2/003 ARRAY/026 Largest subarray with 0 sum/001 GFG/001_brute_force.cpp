#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🔹 Brute Force Approach
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        int maxLen = 0;
        
        // Try every subarray (i...j)
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                
                // ✅ If subarray (i...j) sum is 0
                if (sum == 0)
                    maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};

// 🧩 Main Function
int main() {
    Solution obj;
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};

    cout << "Input Array: [15, -2, 2, -8, 1, 7, 10, 23]\n";
    int result = obj.maxLength(arr);

    cout << "Length of longest subarray with sum = 0: " << result << endl;

    return 0;
}

/*
----------------------------------------
🧩 Example Output:
----------------------------------------
Input Array: [15, -2, 2, -8, 1, 7, 10, 23]
Length of longest subarray with sum = 0: 5
----------------------------------------

✅ Explanation:
- The subarray [-2, 2, -8, 1, 7] has sum = 0 and length = 5.

⚙️ Time Complexity: O(n²)
   → Two nested loops to check all subarrays.

💾 Space Complexity: O(1)
   → No extra data structures used.

📘 Note:
This brute-force version is correct but inefficient for large n.
Use prefix-sum + hashmap (O(n)) for optimal solution.
----------------------------------------
*/