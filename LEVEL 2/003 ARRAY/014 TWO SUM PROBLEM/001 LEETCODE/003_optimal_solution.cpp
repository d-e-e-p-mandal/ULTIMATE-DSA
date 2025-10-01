#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2);

        unordered_map<int, int> mp; // value -> index

        for (int i = 0; i < n; i++) {
            int sum = nums[i];
            int rem = target - sum;

            // if remainder exists in map, we found the pair
            if (mp.find(rem) != mp.end()) {
                ans[0] = i;
                ans[1] = mp[rem];
                return ans;
            }

            // store current element with its index
            mp[sum] = i;
        }

        return ans; // guaranteed one solution
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}

/*
-------------------------------
Expected Output:
Indices: [1, 0]   // nums[1] = 7 and nums[0] = 2 => 7 + 2 = 9

-------------------------------
Time Complexity: O(n)
- Single pass with O(1) average map operations.

Space Complexity: O(n)
- Hashmap stores up to n elements.
*/