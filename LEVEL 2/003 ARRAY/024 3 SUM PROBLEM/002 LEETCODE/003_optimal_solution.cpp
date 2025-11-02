#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());  // ✅ Step 1: Sort array to apply two-pointer logic

        for (int i = 0; i < n; i++) {
            // Skip duplicate values for i to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            // ✅ Step 2: Use two-pointer technique to find pairs that sum to -nums[i]
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0)
                    j++; // Need a larger sum
                else if (sum > 0)
                    k--; // Need a smaller sum
                else {
                    // ✅ Found a valid triplet
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicate values for j and k
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }

        return ans;
    }
};

// 🧩 Demonstration Main Function
int main() {
    Solution obj;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = obj.threeSum(nums);

    cout << "Input: [-1, 0, 1, 2, -1, -4]\n";
    cout << "Triplets that sum to 0:\n";

    for (auto& triplet : result) {
        cout << "[ ";
        for (int num : triplet)
            cout << num << " ";
        cout << "]\n";
    }

    return 0;
}

/*
----------------------------------------
🧩 Example Output:
----------------------------------------
Input: [-1, 0, 1, 2, -1, -4]
Triplets that sum to 0:
[ -1 -1 2 ]
[ -1 0 1 ]
----------------------------------------

✅ Time Complexity: O(n²)
   - Sorting takes O(n log n)
   - Outer loop (i) → O(n)
   - Inner two-pointer traversal → O(n)
   - Combined → O(n²)

✅ Space Complexity: O(1)
   - Ignoring output storage, done in-place.

✅ Explanation:
   - Sort array.
   - For each element nums[i], use two pointers (j, k)
     to find all pairs such that nums[i] + nums[j] + nums[k] == 0.
   - Skip duplicates to avoid repeating triplets.
----------------------------------------
*/