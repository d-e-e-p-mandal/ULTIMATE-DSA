#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        // Base condition: prefix sum 0 occurs once initially
        mp[0] = 1;
        
        int sum = 0;
        int count = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            sum += arr[i]; // prefix sum
            
            int remaining = sum - k; // target prefix
            count += mp[remaining];  // add number of matching prefixes
            
            mp[sum]++; // store current prefix sum
        }
        
        return count;
    }
};

int main() {
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;

    Solution obj;
    int result = obj.cntSubarrays(arr, k);

    cout << "Number of subarrays with sum " << k << " = " << result << endl;

    return 0;
}

/*
-----------------------------------
🧩 Example Output:
-----------------------------------
Number of subarrays with sum -10 = 3

-----------------------------------
✅ Time Complexity: O(n)
   - Each element is visited once, and hashmap lookups are O(1) average.

✅ Space Complexity: O(n)
   - In worst case, every prefix sum is unique and stored in the map.

✅ Explanation:
   Prefix Sum Technique:
   - Keep track of sum of all elements till index i.
   - If (sum - k) has been seen before, it means a subarray with sum k exists.
-----------------------------------
*/