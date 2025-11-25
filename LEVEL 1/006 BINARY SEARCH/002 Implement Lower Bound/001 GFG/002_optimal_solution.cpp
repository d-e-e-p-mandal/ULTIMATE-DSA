#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;

        // Binary search for the first index where arr[mid] >= target
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < target)
                low = mid + 1;      // move right
            else
                high = mid - 1;     // possible answer lies left
        }

        return low;   // insertion index or first >= target
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cin >> target;

    Solution obj;
    cout << obj.lowerBound(arr, target) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
10
1 2 3 4 4 5 6 7 7 7
4

Sample Output:
3

Explanation:
First index where arr[i] >= 4 is index 3.

-----------------------------------------
Time Complexity:
O(log n)
Reason:
Binary search halves the search space each step.

Space Complexity:
O(1)
Reason:
Only constant extra variables used.

-----------------------------------------
*/