#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n); // Result array

        int pos_index = 0, neg_index = 1; // Even indices for positives, odd for negatives
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                ans[pos_index] = nums[i];
                pos_index += 2;
            } else {
                ans[neg_index] = nums[i];
                neg_index += 2;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    vector<int> result = sol.rearrangeArray(nums);

    for(int x : result) cout << x << " ";
    cout << endl;

    return 0;
}

/*
Output:
3 -2 1 -5 2 -4
Explanation:
- Positive and negative numbers are rearranged alternately
- Relative order among positives/negatives preserved in their respective positions

Time Complexity: O(n)
  → Single traversal to fill the result array

Space Complexity: O(n)
  → Extra array used for rearranged output
*/