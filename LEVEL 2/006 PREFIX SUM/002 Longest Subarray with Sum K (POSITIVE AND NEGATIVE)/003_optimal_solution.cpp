#include <bits/stdc++.h>
using namespace std;

// Function to find the length of longest subarray with sum = k
int longestSubarrayWithSumK(vector<int>& arr, int k) {
    unordered_map<long long, int> mp;  // stores prefixSum -> first index
    long long prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];  // compute running prefix sum

        // Case 1: if entire prefix equals k
        if (prefixSum == k) {
            maxLen = i + 1;
        }

        // Case 2: if prefixSum - k was seen before, subarray exists
        if (mp.find(prefixSum - k) != mp.end()) {
            maxLen = max(maxLen, i - mp[prefixSum - k]);
        }

        // Store prefixSum index only for first occurrence
        if (mp.find(prefixSum) == mp.end()) {
            mp[prefixSum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;

    cout << "Longest Subarray Length = " 
         << longestSubarrayWithSumK(arr, k) << endl;

    return 0;
}

/*
Example Output:
Longest Subarray Length = 6

Explanation:
The entire array [10, 5, 2, 7, 1, -10] sums to 15.

-----------------------
Time Complexity:
- O(n), since we traverse array once and hashmap lookups are O(1) average.

Space Complexity:
- O(n), for storing prefix sums in hashmap.
*/