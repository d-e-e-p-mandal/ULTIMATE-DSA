// Brute Force Solution : Use Merge Sort

#include <bits/stdc++.h>
using namespace std;

// Standard merge function
void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    // Copy remaining elements
    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    // Copy sorted subarray back to original array
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

// Recursive merge sort function
void mergeSort(vector<int>& nums, int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}

void sortColors(vector<int>& nums) {
    mergeSort(nums, 0, nums.size() - 1);
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

⏱️ Time Complexity:  O(N log N)
💾 Space Complexity: O(N)
   → Due to temporary arrays used in merging.
-----------------------------------------
*/