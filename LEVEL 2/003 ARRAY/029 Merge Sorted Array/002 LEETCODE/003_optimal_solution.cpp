#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🧩 Function to merge two sorted arrays in-place
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;               // Pointer for last element in nums1's valid part
        int j = n - 1;               // Pointer for last element in nums2
        int index = nums1.size() - 1; // Pointer for final position in nums1 (total size = m + n)

        // Step 1️⃣: Compare from the end and fill from the back
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j])
                nums1[index--] = nums1[i--];  // Place larger element at the end
            else
                nums1[index--] = nums2[j--];
        }

        // Step 2️⃣: If nums2 still has elements, copy them
        while (j >= 0)
            nums1[index--] = nums2[j--];

        // Step 3️⃣: (Optional) If nums1 has remaining, they’re already in place
    }
};

int main() {
    Solution obj;

    // Example Input
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // nums1 has extra space for nums2
    int m = 3; // number of valid elements in nums1
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    cout << "Before merge:\nnums1 = ";
    for (int x : nums1) cout << x << " ";
    cout << "\nnums2 = ";
    for (int x : nums2) cout << x << " ";
    cout << "\n\n";

    obj.merge(nums1, m, nums2, n);

    cout << "After merge (in-place):\nnums1 = ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    return 0;
}

/*
-------------------------------------------
🧩 Example Output:
-------------------------------------------
Before merge:
nums1 = 1 2 3 0 0 0 
nums2 = 2 5 6 

After merge (in-place):
nums1 = 1 2 2 3 5 6 
-------------------------------------------

⚙️ Time Complexity: O(m + n)
   → Each element from nums1 and nums2 is processed once.

💾 Space Complexity: O(1)
   → In-place merging (no extra arrays used).

✅ Notes:
- Works from the back to avoid overwriting nums1’s elements.
- Efficient and clean — the best approach for this problem.
-------------------------------------------
*/