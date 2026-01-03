#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();

        int x1, x2 = 0, y1, y2 = 0;

        // Modified Boyer–Moore Voting Algorithm
        for (int i = 0; i < n; i++) {
            if (x2 == 0) {
                x1 = nums[i];
                x2++;
            }
            else if (y2 == 0) {
                y1 = nums[i];
                y2++;
            }
            else if (x1 == nums[i]) {
                x2++;
            }
            else if (y1 == nums[i]) {
                y2++;
            }
            else {
                x2--;
                y2--;
            }
        }

        int count1 = 0, count2 = 0;

        // Verify which candidate appears n/2 times
        for (int i = 0; i < n; i++) {
            if (x1 == nums[i]) count1++;
            if (y1 == nums[i]) count2++;

            if (count1 >= n / 2) return x1;
            if (count2 >= n / 2) return y1;
        }

        return 0;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution obj;
    cout << obj.repeatedNTimes(nums) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
8
5 1 5 2 5 3 5 4

Sample Output:
5

Explanation:
The number 5 appears n/2 times (4 times).

-----------------------------------------
Time Complexity:
O(n)
Reason:
Two linear passes over the array.

Space Complexity:
O(1)
Reason:
Only constant extra variables used.

-----------------------------------------
*/