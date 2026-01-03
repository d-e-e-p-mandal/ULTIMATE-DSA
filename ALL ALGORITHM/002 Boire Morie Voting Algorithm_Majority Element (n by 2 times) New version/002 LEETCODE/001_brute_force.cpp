#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        // Count frequency using hash map
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;

            // As soon as any element appears n/2 times, return it
            if (mp[nums[i]] == n / 2)
                return nums[i];
        }

        // Fallback (problem guarantees an answer)
        return nums[n - 1];
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
Single pass through the array with O(1) average hash operations.

Space Complexity:
O(n)
Reason:
Hash map stores frequency of elements.

-----------------------------------------
*/