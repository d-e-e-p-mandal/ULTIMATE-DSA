#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if (arr.empty()) return 0; // handle empty array
        
        unordered_set<int> s(arr.begin(), arr.end()); // store unique numbers
        int longest = 0;

        for (int num : s) {
            if (!s.count(num - 1)) { // start of a sequence
                int current = num;
                int streak = 1;
                while (s.count(current + 1)) { // count consecutive
                    current++;
                    streak++;
                }
                longest = max(longest, streak);
            }
        }
        
        return longest;
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

Time Complexity: O(n) — each number is visited at most twice.
Space Complexity: O(n) — for the unordered_set storing unique numbers.
*/