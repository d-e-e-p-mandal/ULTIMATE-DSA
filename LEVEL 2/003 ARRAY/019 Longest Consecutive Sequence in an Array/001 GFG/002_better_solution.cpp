#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;  // empty array case

        // Step 1️⃣: Use set to remove duplicates and sort the elements
        set<int> s(arr.begin(), arr.end());

        // Step 2️⃣: Initialize variables
        int first = *(s.begin());  // first element in sorted set
        int number = first;
        int consecutive = 1, max_consecutive = 1;

        // Step 3️⃣: Traverse the set to find consecutive sequences
        for (int num : s) {
            if (number + 1 == num) {  // consecutive number
                consecutive++;
            } else {                  // reset counter
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
    vector<int> arr = {100, 4, 200, 1, 3, 2};

    cout << "Longest Consecutive Sequence Length: " 
         << sol.longestConsecutive(arr) << endl;

    return 0;
}

/*
Example Output:
Longest Consecutive Sequence Length: 4
Explanation: The consecutive sequence is [1, 2, 3, 4].

🕒 Time Complexity: O(n log n) 
    - Set insertion sorts the array and removes duplicates.

💾 Space Complexity: O(n) 
    - Extra set used to store unique elements.
*/