#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        if (n == 0) return;

        d = d % n;  // handle if d > n

        // Step 1: Reverse first d elements
        reverse(arr.begin(), arr.begin() + d);

        // Step 2: Reverse remaining elements
        reverse(arr.begin() + d, arr.end());

        // Step 3: Reverse entire array
        reverse(arr.begin(), arr.end());
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;

    sol.rotateArr(arr, d);

    cout << "Array after rotating left by " << d << " steps: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

/*
Example Output:
Array after rotating left by 2 steps: 3 4 5 6 7 1 2 

-----------------------
Time Complexity:
- O(n), each element reversed at most twice.

Space Complexity:
- O(1), in-place reversal.
*/