// Optimal ans : Kadane's Algorithm
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;              // current subarray sum
        int maxSum = INT_MIN;     // maximum sum found so far

        for (int i = 0; i < n; i++) {
            sum += nums[i];               // include current element
            maxSum = max(maxSum, sum);    // update maxSum

            if (sum < 0) sum = 0;         // reset sum if negative
        }

        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = sol.maxSubArray(nums);
    cout << "Maximum Subarray Sum = " << result << endl;

    return 0;
}

/*
Example Output:
Maximum Subarray Sum = 6
Explanation: The subarray [4,-1,2,1] has the largest sum.

---------------------------------
Time Complexity:  O(n)
  → Single pass through the array
Space Complexity: O(1)
  → Only constant extra variables used
*/