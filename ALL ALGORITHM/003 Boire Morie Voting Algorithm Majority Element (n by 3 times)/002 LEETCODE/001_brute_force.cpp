#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int appear = n / 3;  // threshold: element must appear more than n/3 times
        vector<int> ans;

        // 🔁 Check each element
        for (int i = 0; i < n; i++) {
            int count = 0;

            // Count how many times nums[i] appears
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j])
                    count++;
            }

            // ✅ If it appears more than n/3 times and not already in answer
            if (count > appear && find(ans.begin(), ans.end(), nums[i]) == ans.end()) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};

// 🧩 Main function for demonstration
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

✅ Time Complexity: O(n²)
   - Outer loop O(n)
   - Inner loop counts frequency O(n)
   - Total = O(n × n)

✅ Space Complexity: O(1)
   - Only constant extra variables (output vector excluded)
-----------------------------------
*/