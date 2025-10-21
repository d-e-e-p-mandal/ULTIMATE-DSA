#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos, neg, ans;
        
        // Separate positive and negative numbers
        for(int i = 0; i < n; i++) {
            if(nums[i] >= 0) {
                pos.push_back(nums[i]);
            }
            else {
                neg.push_back(nums[i]);
            }
        }

        // Merge positive and negative numbers alternately
        for(int i = 0; i < pos.size(); i++) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    
    vector<int> result = sol.rearrangeArray(nums);
    
    cout << "Rearranged Array: ";
    for(int x : result) cout << x << " ";
    cout << endl;

    return 0;
}

/*
Example Output:
Rearranged Array: 3 -2 1 -5 2 -4

Time Complexity:
- O(n), we traverse the array twice (once for separating, once for merging).

Space Complexity:
- O(n), for storing positive and negative numbers separately plus result array.
*/