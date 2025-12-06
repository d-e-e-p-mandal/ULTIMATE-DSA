#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int key) {
        
        int low = 0;
        int high = arr.size() - 1;

        // Binary search on rotated sorted array
        while (low <= high) {
            int mid = (low + high) / 2;

            // Case 1: element found
            if (arr[mid] == key) return mid;

            // Case 2: left half is sorted
            if (arr[low] <= arr[mid]) {
                if (arr[low] <= key && key < arr[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // Case 3: right half is sorted
            else {
                if (key > arr[mid] && key <= arr[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;   // not found
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cin >> key;

    Solution obj;
    cout << obj.search(arr, key) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
7
4 5 6 7 0 1 2
0

Sample Output:
4

Explanation:
The element 0 is found at index 4.

-----------------------------------------
Time Complexity:
O(log n)
Reason:
Binary search on a rotated sorted array.

Space Complexity:
O(1)
Reason:
Only using constant extra variables.

-----------------------------------------
*/