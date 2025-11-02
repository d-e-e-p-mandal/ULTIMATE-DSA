#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> s;

        // 🔁 Fix two elements nums[i] and nums[j]
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                set<long> hashSet;

                // 🔍 Check for pairs (nums[k], sum) that complete the quadruplet
                for (int k = j + 1; k < n; k++) {
                    long sum = (long)target - ((long)nums[i] + (long)nums[j] + (long)nums[k]);
                    if (hashSet.find(sum) != hashSet.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)sum};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }

        // ✅ Convert set to vector for final result
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};

// 🧩 Demonstration main function
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
   - Three nested loops (i, j, k) and O(1) average lookup in hashSet.

✅ Space Complexity: O(n²)
   - O(n) hashSet per iteration + O(k) for storing unique quadruplets.

✅ Explanation:
   - Fix two numbers (nums[i], nums[j]).
   - Use hashSet to find remaining two numbers that sum to (target - (nums[i]+nums[j])).
   - Sort each quadruplet to ensure uniqueness and insert into set.
----------------------------------------
*/