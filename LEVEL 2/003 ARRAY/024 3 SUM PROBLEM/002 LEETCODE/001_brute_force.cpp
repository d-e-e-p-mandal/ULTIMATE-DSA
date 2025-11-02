#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>s; // to store unique value we using set

        // ✅ Iterate through each element as the first number of the triplet
        for(int i=0; i<n-2; i++) {
            for(int j=i+1; j<n-1; j++) {
                for(int k = j+1; k<n; k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        vector<int>temp(3);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[k];
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>>ans(s.begin(), s.end());
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

✅ Time Complexity: O(n³)
   - Outer loop runs O(n)
   - Inner loop with hashSet lookup runs O(n)
   - Sorting triplets adds O(log k), but negligible since k ≤ n².

✅ Space Complexity: O(1)

✅ Explanation:
   - For each element nums[i], use a hashSet to find two other elements (nums[j], nums[k])
     such that nums[i] + nums[j] + nums[k] == 0.
   - Sort each found triplet to ensure uniqueness before inserting into set.
----------------------------------------
*/