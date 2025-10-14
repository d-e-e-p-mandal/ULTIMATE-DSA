#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sort012(vector<int>& arr) {
        int low = 0, mid = 0, high = arr.size() - 1;

        // Dutch National Flag algorithm
        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1) {
                mid++;
            }
            else { // arr[mid] == 2
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {0, 2, 1, 2, 0, 1, 2};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    sol.sort012(arr);

    cout << "Sorted array:   ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

/*
-----------------------------------------
🧩 Example Output:
Original array: 0 2 1 2 0 1 2 
Sorted array:   0 0 1 1 2 2 
-----------------------------------------

⏱️ Time Complexity:  O(N)
💾 Space Complexity: O(1)
-----------------------------------------
*/