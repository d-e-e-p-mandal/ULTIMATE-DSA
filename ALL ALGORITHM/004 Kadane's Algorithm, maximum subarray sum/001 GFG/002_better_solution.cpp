// Recursive function: divide array into halves

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper to find max sum crossing the middle point
    int sumOfLeftRight(vector<int>& arr, int left, int mid, int right) {
        int sum = 0;
        int left_sum = INT_MIN;

        // Compute maximum sum on left half (including mid)
        for (int i = mid; i >= left; i--) {
            sum += arr[i];
            left_sum = max(left_sum, sum);
        }

        sum = 0;
        int right_sum = INT_MIN;

        // Compute maximum sum on right half (excluding mid)
        for (int i = mid + 1; i <= right; i++) {
            sum += arr[i];
            right_sum = max(right_sum, sum);
        }

        return left_sum + right_sum; // best subarray crossing mid
    }

    // Recursive function: divide array into halves
    int solve(vector<int>& arr, int left, int right) {
        if (left == right)
            return arr[left];  // base case: single element

        int mid = left + (right - left) / 2;

        // Compute maximum sum for left, right, and crossing subarrays
        int leftSum = solve(arr, left, mid);
        int rightSum = solve(arr, mid + 1, right);
        int crossSum = sumOfLeftRight(arr, left, mid, right);

        return max({leftSum, rightSum, crossSum});
    }

    // Main function
    int maxSubarraySum(vector<int>& arr) {
        return solve(arr, 0, arr.size() - 1);
    }
};

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution sol;
    cout << "Maximum Subarray Sum = " << sol.maxSubarraySum(arr) << endl;

    return 0;
}

/*
---------------------------------------------
🧠 Approach:
---------------------------------------------
- Split the array into two halves recursively.
- Find:
   1️⃣ Maximum subarray sum in left half.
   2️⃣ Maximum subarray sum in right half.
   3️⃣ Maximum subarray sum crossing the midpoint.
- Return the maximum of these three values.

---------------------------------------------
🕒 Time Complexity:  O(n log n)
   → Each level does O(n) work for combining results.
   → log n levels of recursion.
💾 Space Complexity: O(log n)
   → Due to recursion stack depth.
---------------------------------------------

📘 Example:
Input:  [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum.
*/