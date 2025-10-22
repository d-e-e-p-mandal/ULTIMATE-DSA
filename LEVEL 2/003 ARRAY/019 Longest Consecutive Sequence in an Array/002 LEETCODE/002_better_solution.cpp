#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0; // empty array case

        // Store unique sorted elements
        set<int> s(nums.begin(), nums.end());

        // Explicit iterator for set
        set<int>::iterator it = s.begin();
        int number = *it;         // previous number
        int consecutive = 1;      // current consecutive length
        int max_consecutive = 1;  // max consecutive length

        ++it; // skip first element
        for(; it != s.end(); ++it) {
            int num = *it;
            if(number + 1 == num) { // consecutive
                consecutive++;
            } else {                 // reset
                consecutive = 1;
            }
            number = num;
            max_consecutive = max(max_consecutive, consecutive);
        }

        return max_consecutive;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence Length: " 
         << sol.longestConsecutive(nums) << endl;
    return 0;
}

/*
Output:
Longest Consecutive Sequence Length: 4
Explanation: Sequence is [1, 2, 3, 4].

Time Complexity: O(n log n) 
    - due to set insertion (sorting + uniqueness)
Space Complexity: O(n)
    - extra set to store unique elements
*/