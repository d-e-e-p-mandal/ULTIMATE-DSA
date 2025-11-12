#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ⚡ Better Approach (O(n²)): Count subarrays with XOR == k
    long subarrayXor(vector<int>& arr, int k) {
        int n = arr.size();
        long cnt = 0;

        // Fix starting index
        for (int i = 0; i < n; i++) {
            int xr = 0; // XOR of current subarray starting from i

            // Extend subarray till j
            for (int j = i; j < n; j++) {
                xr ^= arr[j]; // accumulate XOR

                // If current XOR equals k, increment count
                if (xr == k)
                    cnt++;
            }
        }

        return cnt;
    }
};

// 🧩 Main Function
int main() {
    Solution obj;
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;

    cout << "Input Array: [4, 2, 2, 6, 4]\n";
    cout << "Target XOR (k): " << k << endl;

    long result = obj.subarrayXor(arr, k);

    cout << "Count of subarrays with XOR = " << k << " is: " << result << endl;

    return 0;
}

/*
----------------------------------------
🧩 Example Output:
----------------------------------------
Input Array: [4, 2, 2, 6, 4]
Target XOR (k): 6
Count of subarrays with XOR = 6 is: 4
----------------------------------------

✅ Explanation:
Subarrays with XOR = 6 are:
[4, 2], [6], [2, 2, 6], [4, 2, 2, 6, 4]

⚙️ Time Complexity: O(n²)
   → Outer loop fixes start, inner loop extends subarray.
   → XOR computed cumulatively instead of restarting.

💾 Space Complexity: O(1)
   → No extra storage.

📘 Note:
This avoids the third loop by maintaining the running XOR.
It’s a “better” version of the brute force while keeping the same core logic.
----------------------------------------
*/