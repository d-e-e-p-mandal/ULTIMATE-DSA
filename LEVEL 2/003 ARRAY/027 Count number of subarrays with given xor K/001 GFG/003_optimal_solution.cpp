#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🔹 Function to count subarrays having XOR equal to k
    long subarrayXor(vector<int>& arr, int k) {
        int n = arr.size();

        unordered_map<int, int> mp; // stores frequency of prefix XOR values
        mp[0]++; // base case: XOR before starting is 0

        int xr = 0;  // current prefix XOR
        long cnt = 0; // total count of subarrays

        for (int i = 0; i < n; i++) {
            xr ^= arr[i]; // compute prefix XOR till index i

            int x = xr ^ k; 
            // If (xr ^ k) exists in map, it means there’s a subarray ending at i with XOR = k
            cnt += mp[x];

            // store current prefix XOR in map
            mp[xr]++;
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
1. [4, 2]
2. [6]
3. [2, 2, 6]
4. [4, 2, 2, 6, 4] (some overlapping parts included)

⚙️ Time Complexity: O(n)
   → Single traversal with hashmap lookups.

💾 Space Complexity: O(n)
   → Hashmap stores prefix XOR frequencies.

📘 Key Idea:
XOR from index 0 to i = xr
For a subarray (j+1...i) to have XOR = k:
   → (XOR[0...i]) ^ (XOR[0...j]) = k
   → XOR[0...j] = (XOR[0...i]) ^ k
So, we count how many previous prefix XORs match this value.
----------------------------------------
*/