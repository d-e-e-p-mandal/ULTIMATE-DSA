// Optimal Approach: Moore's Voting Algorithm

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;  // Counter for candidate
        int el;       // Candidate element

        // Step 1: Find a candidate for majority
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                el = arr[i];
                cnt = 1;
            }
            else if (arr[i] == el) cnt++;
            else cnt--;
        }

        // Step 2: Verify if candidate is actually majority
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == el) cnt1++;
        }

        if (cnt1 > n / 2) return el;
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 2, 1, 1, 2, 2, 2};

    cout << "Majority Element: " << sol.majorityElement(arr) << endl;

    return 0;
}

/*
---------------------------------------
🧩 Example Output:
Majority Element: 2
---------------------------------------

⏱️ Time Complexity:  O(N)
💾 Space Complexity: O(1)

✅ Explanation:
- Step 1: Find a candidate by canceling out different elements.
- Step 2: Verify the candidate occurs more than n/2 times.
- Optimal because it uses only constant extra space.
---------------------------------------
*/