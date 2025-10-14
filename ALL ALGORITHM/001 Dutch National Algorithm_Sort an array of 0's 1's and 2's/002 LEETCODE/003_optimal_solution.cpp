#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    // Dutch National Flag algorithm
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Original Array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    sortColors(nums);

    cout << "Sorted Array:   ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}

/*
-----------------------------------------
🧩 Example Output:
Original Array: 2 0 2 1 1 0 
Sorted Array:   0 0 1 1 2 2 
-----------------------------------------

⏱️ Time Complexity:  O(N)
   → Single traversal with constant swaps.

💾 Space Complexity: O(1)
   → In-place sorting, no extra data structures.
*/