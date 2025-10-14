// Better Approach: Using Hash Map to count frequencies

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;

        // Count frequency of each element
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }

        // Check which element occurs more than n/2 times
        for (auto m : mp) {
            if (m.second > n / 2) return m.first;
        }

        // If no majority element exists
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
💾 Space Complexity: O(N)

✅ Explanation:
- Use a hash map to store frequency of each element.
- Iterate over the map to find the element with frequency > n/2.
- Efficient compared to brute force (O(N^2)).
---------------------------------------
*/