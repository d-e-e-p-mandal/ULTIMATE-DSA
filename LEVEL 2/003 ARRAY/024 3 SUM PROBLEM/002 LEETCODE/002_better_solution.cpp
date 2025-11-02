#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;  // To store unique triplets

        // ✅ Iterate through each element as the first number of the triplet
        for (int i = 0; i < n - 2; i++) {
            set<int> hashSet;  // To store numbers we’ve seen for current i

            for (int j = i + 1; j < n; j++) {
                int sum = -(nums[i] + nums[j]);  // We want nums[k] = - (nums[i] + nums[j])

                // ✅ If the third number exists, form the triplet
                if (hashSet.find(sum) != hashSet.end()) {
                    vector<int> temp = {nums[i], nums[j], sum};
                    sort(temp.begin(), temp.end());  // Sort to handle duplicates
                    s.insert(temp);
                }

                hashSet.insert(nums[j]);  // Store number for later lookup
            }
        }

        // ✅ Convert set to vector for output
        vector<vector<int>> ans(s.begin(), s.end());
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

    for (auto &triplet : result) {
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
   - Outer loop runs O(n)
   - Inner loop with hashSet lookup runs O(n)
   - Sorting triplets adds O(log k), but negligible since k ≤ n².

✅ Space Complexity: O(n²)
   - O(n) for hashSet (per iteration)
   - O(k) for storing unique triplets in set.

✅ Explanation:
   - For each element nums[i], use a hashSet to find two other elements (nums[j], nums[k])
     such that nums[i] + nums[j] + nums[k] == 0.
   - Sort each found triplet to ensure uniqueness before inserting into set.
----------------------------------------
*/