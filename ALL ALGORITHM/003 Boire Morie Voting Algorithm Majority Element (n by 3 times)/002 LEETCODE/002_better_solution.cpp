#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int appear = n / 3;  // threshold value
        vector<int> ans;
        
        unordered_map<int, int> mp;  // store frequency of each number

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;  // count occurrences

            // If element crosses n/3 frequency and is not already added
            if (mp[nums[i]] > appear && find(ans.begin(), ans.end(), nums[i]) == ans.end()) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {3, 2, 3};
    vector<int> nums2 = {1, 1, 1, 3, 3, 2, 2, 2};

    vector<int> result1 = obj.majorityElement(nums1);
    vector<int> result2 = obj.majorityElement(nums2);

    cout << "Input: [3, 2, 3]\nOutput: ";
    for (int x : result1) cout << x << " ";
    cout << "\n\n";

    cout << "Input: [1, 1, 1, 3, 3, 2, 2, 2]\nOutput: ";
    for (int x : result2) cout << x << " ";
    cout << "\n";

    return 0;
}

/*
-----------------------------------
🧩 Example Output:
-----------------------------------
Input: [3, 2, 3]
Output: 3

Input: [1, 1, 1, 3, 3, 2, 2, 2]
Output: 1 2
-----------------------------------

✅ Time Complexity: O(n)
   - Single pass through nums
   - find() check on small ans vector (max 2 elements)

✅ Space Complexity: O(n)
   - For storing frequency counts in unordered_map
-----------------------------------
*/