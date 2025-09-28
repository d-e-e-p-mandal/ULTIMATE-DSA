
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to rotate array by one position to the right
    void rotate(vector<int> &arr) {
        int n = arr.size();
        int temp = arr[n - 1];  // store last element

        // shift elements one step to the right
        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = temp; // place last element at first position
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};

    sol.rotate(arr);

    cout << "Array after rotation: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

/*
Example Output:
Array after rotation: 5 1 2 3 4 

-----------------------
Time Complexity:
- O(n), since we shift all elements once

Space Complexity:
- O(1), only one temp variable used
*/