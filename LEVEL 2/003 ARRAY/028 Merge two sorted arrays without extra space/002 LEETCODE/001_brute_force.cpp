#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🧩 Brute Force Approach to Merge Overlapping Intervals
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;

        // Step 1️⃣: Sort intervals by their start time (required for merging)
        sort(intervals.begin(), intervals.end());

        int i = 0;
        while (i < n) {
            // Start of current merged interval
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Step 2️⃣: Merge with all overlapping intervals
            int j = i + 1;
            while (j < n && intervals[j][0] <= end) {
                // Update end to include the overlapping interval
                end = max(end, intervals[j][1]);
                j++;
            }

            // Step 3️⃣: Store merged interval
            ans.push_back({start, end});

            // Step 4️⃣: Move to next non-overlapping interval
            i = j;
        }

        return ans;
    }
};

// 🧩 Main Function for Demonstration
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

    cout << "Merged Intervals (Brute Force): ";
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
Merged Intervals (Brute Force): [1,6] [8,10] [15,18]
-------------------------------------------

✅ Explanation:
- [1,3] overlaps with [2,6] → merged to [1,6]
- [8,10] and [15,18] remain as they are

⚙️ Time Complexity: O(n log n + n)
   → Sorting: O(n log n)
   → Merging loop: O(n)
   → Overall ≈ O(n log n)

💾 Space Complexity: O(n)
   → Output list of merged intervals.

✅ Notes:
- Straightforward brute-force merging.
- Relies on sorting for interval alignment.
- No advanced data structures used.
-------------------------------------------
*/