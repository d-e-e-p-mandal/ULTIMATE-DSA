#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp; // stores sequence length at boundaries
        int maxLen = 0;

        for(int num : nums){
            if(!mp[num]) { // process each number once
                mp[num] = mp[num-1] + mp[num+1] + 1; // total sequence length including num
                mp[num - mp[num-1]] = mp[num]; // update left boundary
                mp[num + mp[num+1]] = mp[num]; // update right boundary
                maxLen = max(maxLen, mp[num]);
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence Length: " 
         << sol.longestConsecutive(arr) << endl;
    return 0;
}

/*
Output:
Longest Consecutive Sequence Length: 4
Explanation: Sequence is [1,2,3,4].

Time Complexity: O(n) — each element is processed once.
Space Complexity: O(n) — for the unordered_map storing sequence lengths.
*/