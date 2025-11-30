#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find upper bound: first index where arr[i] > target
    int upperBound(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;

        // Standard binary search for upper bound
        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] <= target)
                low = mid + 1;      // move right
            else
                high = mid - 1;     // move left
        }

        return low; // position of 1st element > target
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
    cout << obj.upperBound(arr, target) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
10
1 2 3 4 4 5 6 7 7 7
4

Sample Output:
5

Explanation:
First index where arr[i] > 4 is index 5 (arr[5] = 5)

-----------------------------------------
Time Complexity:
O(log n)
Reason:
Binary search halves the search interval each iteration.

Space Complexity:
O(1)
Reason:
Only constant amount of extra memory used.

-----------------------------------------
*/