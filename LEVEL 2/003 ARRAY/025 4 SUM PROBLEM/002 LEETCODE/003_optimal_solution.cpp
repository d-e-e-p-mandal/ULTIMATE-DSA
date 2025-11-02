#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort to handle duplicates easily

        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate i

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // skip duplicate j

                int k = j + 1, l = n - 1;
                while (k < l) {
                    //long sum = (long)nums[i] + nums[j] + nums[k] + nums[l];
                    long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++; l--;

                        // Skip duplicates for k and l
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
                    else if (sum < target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};

// 🧩 Main function for demonstration
int main() {
    Solution obj;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = obj.fourSum(nums, target);

    cout << "Input: [1, 0, -1, 0, -2, 2], Target = 0\n";
    cout << "Quadruplets that sum to target:\n";
    for (auto &quad : result) {
        cout << "[ ";
        for (int num : quad)
            cout << num << " ";
        cout << "]\n";
    }

    return 0;
}

/*
----------------------------------------
🧩 Example Output:
----------------------------------------
Input: [1, 0, -1, 0, -2, 2], Target = 0
Quadruplets that sum to target:
[ -2 -1 1 2 ]
[ -2 0 0 2 ]
[ -1 0 0 1 ]
----------------------------------------

✅ Time Complexity: O(n³)
   - Outer loops (i, j) and two-pointer scan (k, l).

✅ Space Complexity: O(1)
   - Apart from output vector, no extra space used.

✅ Explanation:
   - Sort the array.
   - Fix two numbers (i, j).
   - Use two-pointer method (k, l) to find remaining two that make the sum = target.
   - Skip duplicates to avoid repeated quadruplets.
----------------------------------------
*/