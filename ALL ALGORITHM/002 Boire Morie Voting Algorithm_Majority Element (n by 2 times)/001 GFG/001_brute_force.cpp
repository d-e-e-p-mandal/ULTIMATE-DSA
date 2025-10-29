// Brute Force Approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        
        // For each element, count how many times it appears
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) cnt++;
            }
            // If count > n/2 → majority element found
            if (cnt > n / 2) 
                return arr[i];
        }

        // No majority element
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 2, 1, 1, 2, 2, 2};

    cout << "Majority Element: " << sol.majorityElement(arr) << endl;

    return 0;
}

/*
---------------------------------------
🧩 Example Output:
Majority Element: 2
---------------------------------------

⏱️ Time Complexity:  O(N²)
💾 Space Complexity: O(1)

✅ Brute Force Explanation:
- For each element, count its frequency by scanning the entire array.
- If any element’s count > n/2, it’s the majority element.
- Otherwise, return -1.
---------------------------------------
*/