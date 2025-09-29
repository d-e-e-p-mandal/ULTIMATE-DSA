#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> prefixSum; // prefixSum -> frequency
        prefixSum[0] = 1; // handle case when subarray starts from index 0
        
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // remaining sum that would make subarray = k
            int remming = sum - k;

            // if remming exists, it contributes to subarray count
            if (prefixSum.find(remming) != prefixSum.end()) {
                cnt += prefixSum[remming];
            }

            // record this prefix sum
            prefixSum[sum]++;
        }
        
        return cnt;
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {1, 1, 1};
    int k1 = 2;
    cout << "Count = " << sol.subarraySum(arr1, k1) << endl; 
    // Output: 2 → subarrays [1,1] at (0,1) and (1,2)

    vector<int> arr2 = {10, 2, -2, -20, 10};
    int k2 = -10;
    cout << "Count = " << sol.subarraySum(arr2, k2) << endl;
    // Output: 3 → subarrays [10,2,-2,-20], [2,-2,-20,10], [-20,10]

    return 0;
}

/*
Example Output:
Count = 2
Count = 3

-----------------------
Time Complexity:
- O(n), because we iterate through nums once and hashmap lookups are O(1) average.

Space Complexity:
- O(n), for storing prefix sums and their frequencies.
*/