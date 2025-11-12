#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🧩 Brute Force Merge Function
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;  // extra array to store merged elements

        // Step 1️⃣: Copy valid elements from nums1 (ignore trailing zeros)
        for (int i = 0; i < m; i++)
            temp.push_back(nums1[i]);

        // Step 2️⃣: Copy all elements from nums2
        for (int j = 0; j < n; j++)
            temp.push_back(nums2[j]);

        // Step 3️⃣: Sort the combined array
        sort(temp.begin(), temp.end());

        // Step 4️⃣: Copy back sorted values into nums1
        for (int k = 0; k < temp.size(); k++)
            nums1[k] = temp[k];
    }
};

int main() {
    Solution obj;

    // Example Input
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    cout << "Before merge:\nnums1 = ";
    for (int x : nums1) cout << x << " ";
    cout << "\nnums2 = ";
    for (int x : nums2) cout << x << " ";
    cout << "\n\n";

    obj.merge(nums1, m, nums2, n);

    cout << "After merge (Brute Force):\nnums1 = ";
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

After merge (Brute Force):
nums1 = 1 2 2 3 5 6 
-------------------------------------------

⚙️ Time Complexity: O((m + n) log(m + n))
   → Combining + sorting all elements.

💾 Space Complexity: O(m + n)
   → Uses extra space for the temp array.

⚠️ Drawback:
   - Not in-place (extra space used)
   - Sorting adds unnecessary overhead since both arrays were already sorted.

✅ Simplicity:
   - Easiest to implement; good for brute-force understanding.
-------------------------------------------
*/