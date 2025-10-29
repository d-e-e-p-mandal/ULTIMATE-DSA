#include <bits/stdc++.h>
using namespace std;

// Brute-force solution using O(n^2) approach
int maxSubarraySum(vector<int>& arr) {
    int n = arr.size();
    int maxi = INT_MIN; // store maximum sum

    // Iterate over all possible starting points of subarrays
    for (int i = 0; i < n; i++) {
        int sum = 0;

        // Iterate over all possible ending points of subarrays starting at i
        for (int j = i; j < n; j++) {
            sum += arr[j];            // sum elements from i to j
            maxi = max(maxi, sum);     // update maximum sum
        }
    }

    return maxi;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = maxSubarraySum(arr);
    cout << "Maximum Subarray Sum = " << result << endl; // Output: 6

    return 0;
}

/*
Example Output:
Maximum Subarray Sum = 6

-----------------------
Time Complexity:
- O(n^2): Two nested loops, sum calculated incrementally.

Space Complexity:
- O(1): Constant extra space.
*/