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
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;

    cout << "Longest Subarray Length = "
         << longestSubarrayWithSumK(arr, k) << endl;

    return 0;
}

/*
-------------------------------
Expected Output:
Longest Subarray Length = 4
(Subarray: [5, 2, 7, 1])

-------------------------------
Time Complexity: O(n)
- Single pass through array with O(1) average hashmap lookups.

Space Complexity: O(n)
- Hashmap stores at most n prefix sums.
*/