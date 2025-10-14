#include <bits/stdc++.h>
using namespace std;

// Brute-force solution: check all subarrays
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN; // store maximum sum

    // Iterate over all possible subarrays
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;

            // Sum elements from i to j
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }

            // Update maximum sum
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = maxSubArray(nums);
    cout << "Maximum Subarray Sum = " << result << endl; // Output: 6

    return 0;
}

/*
Example Output:
Maximum Subarray Sum = 6

-----------------------
Time Complexity:
- O(n^3): Three nested loops for all subarrays and sum calculation.

Space Complexity:
- O(1): Constant extra space.
*/