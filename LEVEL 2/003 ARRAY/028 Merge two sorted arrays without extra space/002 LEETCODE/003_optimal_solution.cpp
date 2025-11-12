#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🧩 Merge Overlapping Intervals (Optimized)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};

        // Step 1️⃣: Sort intervals based on start times
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> arr;
        int low = intervals[0][0];
        int high = intervals[0][1];

        // Step 2️⃣: Traverse and merge overlapping intervals
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= high) {
                // Overlap → extend the merged range
                high = max(high, intervals[i][1]);
            } else {
                // No overlap → store the previous merged interval
                arr.push_back({low, high});
                low = intervals[i][0];
                high = intervals[i][1];
            }
        }

        // Step 3️⃣: Push the final interval
        arr.push_back({low, high});

        return arr;
    }
};

// 🧩 Main function for demonstration
int main() {
    Solution obj;

    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    cout << "Original Intervals: ";
    for (auto v : intervals) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> result = obj.merge(intervals);

    cout << "Merged Intervals: ";
    for (auto v : result) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;

    return 0;
}

/*
-------------------------------------------
🧩 Example Output:
-------------------------------------------
Original Intervals: [1,3] [2,6] [8,10] [15,18] 
Merged Intervals: [1,6] [8,10] [15,18]
-------------------------------------------

✅ Explanation:
- [1,3] and [2,6] overlap → merged into [1,6].
- [8,10] and [15,18] remain unchanged.

⚙️ Time Complexity: O(n log n)
   → Sorting takes O(n log n)
   → Single traversal to merge takes O(n)

💾 Space Complexity: O(n)
   → For storing merged intervals in result vector.

✅ Notes:
- Efficient and clean LeetCode-standard approach.
- Handles all overlapping and non-overlapping cases correctly.
-------------------------------------------
*/