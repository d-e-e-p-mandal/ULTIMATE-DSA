#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🧩 Mathematical Approach
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();

        long long diff = 0;          // (repeating - missing)
        long long diff_square = 0;   // (r^2 - m^2)

        // Step 1️⃣: Calculate differences between actual and expected
        for (int i = 0; i < n; i++) {
            diff += (long long)arr[i] - (i + 1);
            diff_square += 1LL * arr[i] * arr[i] - 1LL * (i + 1) * (i + 1);
        }

        // Step 2️⃣: (r^2 - m^2) = (r - m)(r + m)
        // diff_square / diff = r + m
        diff_square /= diff;

        // Step 3️⃣: Solve two equations:
        // r - m = diff
        // r + m = diff_square / diff
        int repeating = (diff + diff_square) / 2;
        int missing = repeating - diff;

        return {repeating, missing};
    }
};

int main() {
    Solution obj;

    vector<int> arr = {1, 3, 3};  // Example input
    vector<int> res = obj.findTwoElement(arr);

    cout << "Repeating number: " << res[0] << endl;
    cout << "Missing number: " << res[1] << endl;

    return 0;
}

/*
-------------------------------------------
🧩 Example Output:
-------------------------------------------
Repeating number: 3
Missing number: 2
-------------------------------------------

⚙️ Time Complexity: O(n)
   → Single traversal of the array.

💾 Space Complexity: O(1)
   → Constant extra space (no hash/map used).

🧮 Formula Recap:
   Let r = repeating, m = missing

   diff = r - m
   diff_square = r² - m² = (r - m)(r + m)

   => (r + m) = diff_square / diff
   => r = (diff + diff_square/diff)/2
   => m = r - diff
-------------------------------------------
*/