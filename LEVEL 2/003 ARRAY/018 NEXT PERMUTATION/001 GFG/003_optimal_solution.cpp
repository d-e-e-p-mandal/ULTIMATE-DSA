#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int next_greater_index;

        // Step 1️⃣: Find the first element from the end which is smaller than its next element
        int i = n - 2;
        while (i >= 0) {
            if (arr[i] < arr[i + 1]) {
                break;
            }
            i--;
        }

        // Step 2️⃣: If such element is found
        if (i != -1) {
            next_greater_index = i + 1;

            // Step 3️⃣: Find the smallest element greater than arr[i] to the right of i
            for (int j = i + 2; j < n; j++)
                if (arr[j] <= arr[next_greater_index] && arr[j] > arr[i])
                    next_greater_index = j;

            // Step 4️⃣: Swap them
            swap(arr[i], arr[next_greater_index]);
        }

        // Step 5️⃣: Reverse the remaining part to get the next permutation
        int j = n - 1;
        i++;
        while (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3};

    sol.nextPermutation(arr);

    cout << "Next Permutation: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

/*
Example Output:
Next Permutation: 1 3 2

🕒 Time Complexity: O(n)
    - Single pass from end + reversal of the tail portion.

💾 Space Complexity: O(1)
    - In-place modification using constant extra space.
*/