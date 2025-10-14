#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        // Count the occurrences of 0, 1, and 2
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) cnt0++;
            else if (arr[i] == 1) cnt1++;
            else cnt2++;
        }

        // Overwrite the array in sorted order
        for (int i = 0; i < cnt0; i++) arr[i] = 0;
        for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1;
        for (int i = cnt0 + cnt1; i < n; i++) arr[i] = 2;
    }
};

// Helper function to print vector
void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> arr = {2, 0, 2, 1, 1, 0};

    cout << "Original Array: ";
    printArray(arr);

    sol.sort012(arr);

    cout << "Sorted Array:   ";
    printArray(arr);

    return 0;
}

/*
-----------------------------------------
🧩 Example Output:
Original Array: 2 0 2 1 1 0 
Sorted Array:   0 0 1 1 2 2 
-----------------------------------------

⏱️ Time Complexity:  O(N)
   → One pass for counting + one pass for rewriting.

💾 Space Complexity: O(1)
   → Only counters used, no extra data structure.
*/