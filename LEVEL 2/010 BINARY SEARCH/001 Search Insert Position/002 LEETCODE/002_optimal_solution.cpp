#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return index where target should be inserted
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        // Binary search to find first index where nums[mid] >= target
        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] < target)
                low = mid + 1;     // target is on the right
            else
                high = mid - 1;    // target should be before mid
        }

        return low;   // insertion index
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int target;
    cin >> target;

    Solution obj;
    cout << obj.searchInsert(nums, target) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
4
1 3 5 6
5

Sample Output:
2

Explanation:
Target 5 is found at index 2.

-----------------------------------------
Another Example:
Input:
4
1 3 5 6
2

Output:
1      // 2 should be inserted at index 1

-----------------------------------------
Time Complexity:
O(log n)
Reason:
Binary search halves the search space each step.

Space Complexity:
O(1)
Reason:
Only constant extra variables used.

-----------------------------------------
*/