#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🔹 Brute Force: Count subarrays having XOR equal to k
    long subarrayXor(vector<int>& arr, int k) {
        int n = arr.size();
        long cnt = 0; // to store total count

        // Iterate over all possible subarrays
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int xr = 0; // to store XOR of current subarray

                // Compute XOR from index i to j
                for (int p = i; p <= j; p++) {
                    xr ^= arr[p];
                }

                // Check if XOR equals k
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

⚙️ Time Complexity: O(n³)
   → Three nested loops (i, j, p)
   → For each (i, j), compute XOR again.

💾 Space Complexity: O(1)
   → No extra data structures used.

📘 Note:
This is the naive approach used for small constraints.
For large inputs, use the optimized O(n) prefix XOR + hashmap method.
----------------------------------------
*/