#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        // Binary search on a rotated sorted array
        while (low <= high) {
            int mid = (low + high) / 2;

            // Case 1: found the element
            if (nums[mid] == target)
                return mid;

            // Case 2: left half is sorted
            if (nums[low] <= nums[mid]) {

                // Check if target lies in the sorted left half
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // Case 3: right half is sorted
            else {

                // Check if target lies in the sorted right half
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1; // element not found
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
    cout << obj.search(nums, target) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
7
4 5 6 7 0 1 2
0

Sample Output:
4

Explanation:
Element 0 is located at index 4.

-----------------------------------------
Time Complexity:
O(log n)
Reason:
Binary search halves the search interval each step.

Space Complexity:
O(1)
Reason:
Only constant extra variables used.

-----------------------------------------
*/