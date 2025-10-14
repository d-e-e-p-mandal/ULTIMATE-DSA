#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        // Count the occurrences of 0, 1, and 2
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) cnt0++;
            else if (nums[i] == 1) cnt1++;
            else cnt2++;
        }

        // Overwrite the array in sorted order
        for (int i = 0; i < cnt0; i++) nums[i] = 0;
        for (int i = cnt0; i < cnt0 + cnt1; i++) nums[i] = 1;
        for (int i = cnt0 + cnt1; i < n; i++) nums[i] = 2;
    }
};

// Helper function to print vector
void printArray(const vector<int>& nums) {
    for (int num : nums) cout << num << " ";
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Original Array: ";
    printArray(nums);

    sol.sortColors(nums);

    cout << "Sorted Array:   ";
    printArray(nums);

    return 0;
}

/*
-----------------------------------------
🧩 Example Output:
Original Array: 2 0 2 1 1 0 
Sorted Array:   0 0 1 1 2 2 
-----------------------------------------

⏱️ Time Complexity:  O(N)
   → One pass for counting + one pass for rewriting.

💾 Space Complexity: O(1)
   → Only counters used, no extra data structure.
*/