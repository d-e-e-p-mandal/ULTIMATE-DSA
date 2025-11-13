#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ⚙️ XOR Bit Manipulation Approach
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();

        int missing = 0, repeating = 0, xr = 0;

        // Step 1️⃣: XOR of all elements and numbers from 1 to n
        for (int i = 0; i < n; i++) {
            xr ^= arr[i];     // XOR of array elements
            xr ^= (i + 1);    // XOR of natural numbers
        }

        // Now xr = repeating ^ missing

        // Step 2️⃣: Find the rightmost set bit (differs between missing & repeating)
        int diff_bit = xr & (-xr);

        // Step 3️⃣: Divide elements into two buckets based on diff_bit
        for (int i = 0; i < n; i++) {
            if (diff_bit & arr[i])
                repeating ^= arr[i];
            else
                missing ^= arr[i];

            if (diff_bit & (i + 1))
                repeating ^= (i + 1);
            else
                missing ^= (i + 1);
        }

        // Step 4️⃣: Determine which one is repeating by checking occurrence
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == repeating)
                cnt++;
        }

        if (cnt == 2)
            return {repeating, missing};
        else
            return {missing, repeating};
    }
};

int main() {
    Solution obj;

    vector<int> arr = {4, 3, 6, 2, 1, 1};  // Example array (n = 6)
    vector<int> res = obj.findTwoElement(arr);

    cout << "Repeating number: " << res[0] << endl;
    cout << "Missing number: " << res[1] << endl;

    return 0;
}

/*
-------------------------------------------
🧩 Example Output:
-------------------------------------------
Repeating number: 1
Missing number: 5
-------------------------------------------

🧠 Step-by-step Logic:
1️⃣ XOR all elements & [1...n] → gives xor = r ^ m
2️⃣ Find rightmost set bit (bit position where r and m differ)
3️⃣ Split into two groups:
      → Group 1: numbers with that bit set
      → Group 2: numbers with that bit unset
4️⃣ XOR within groups → gives r and m (but not sure which is which)
5️⃣ Check frequency to identify repeating

⚙️ Time Complexity: O(n)
   → Single pass for XOR and one more for checking.

💾 Space Complexity: O(1)
   → Constant space (no extra arrays or maps).
-------------------------------------------
*/