#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int appear = n / 3;  // threshold value (element must appear > n/3 times)

        // Candidate elements and their counts
        int ind1 = -1, ind2 = -1;
        int cnt1 = 0, cnt2 = 0;

        // 🔹 Step 1: Find potential candidates using Boyer-Moore voting algorithm
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && nums[i] != ind2) {
                ind1 = nums[i];
                cnt1 = 1;
            } 
            else if (cnt2 == 0 && nums[i] != ind1) {
                ind2 = nums[i];
                cnt2 = 1;
            } 
            else if (nums[i] == ind1)
                cnt1++;
            else if (nums[i] == ind2)
                cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        // 🔹 Step 2: Verify actual counts of candidates
        vector<int> ans;
        cnt1 = cnt2 = 0;

        for (int num : nums) {
            if (num == ind1) cnt1++;
            else if (num == ind2) cnt2++;
        }

        if (cnt1 > appear) ans.push_back(ind1);
        if (cnt2 > appear) ans.push_back(ind2);

        return ans;
    }
};

// 🧩 Demonstration Main Function
int main() {
    Solution obj;

    vector<int> nums1 = {3, 2, 3};
    vector<int> nums2 = {1, 1, 1, 3, 3, 2, 2, 2};

    vector<int> res1 = obj.majorityElement(nums1);
    vector<int> res2 = obj.majorityElement(nums2);

    cout << "Input: [3, 2, 3]\nOutput: ";
    for (int x : res1) cout << x << " ";
    cout << "\n\n";

    cout << "Input: [1, 1, 1, 3, 3, 2, 2, 2]\nOutput: ";
    for (int x : res2) cout << x << " ";
    cout << "\n";

    return 0;
}

/*
----------------------------------------
🧩 Example Output:
----------------------------------------
Input: [3, 2, 3]
Output: 3 

Input: [1, 1, 1, 3, 3, 2, 2, 2]
Output: 1 2
----------------------------------------

✅ Time Complexity: O(n)
   - One pass to find candidates, one pass to verify.

✅ Space Complexity: O(1)
   - Only constant extra variables used.

✅ Explanation:
   - Boyer–Moore majority vote keeps at most two candidates
     (since at most ⌊n/3⌋ majority elements can exist).
----------------------------------------
*/