#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rearrange(vector<int> &arr) {
        int n = arr.size();
        
        vector<int> pos, neg;

        // Separate positives and negatives
        for(int i = 0; i < n; i++) {
            if(arr[i] >= 0) pos.push_back(arr[i]);
            else neg.push_back(arr[i]);
        }

        int i = 0, arr_index = 0;
        // Alternate placement of positive and negative numbers
        while(i < pos.size() && i < neg.size()) {
            arr[arr_index++] = pos[i];
            arr[arr_index++] = neg[i];
            i++;
        }

        // Add remaining positives
        while(i < pos.size()) arr[arr_index++] = pos[i++];

        // Add remaining negatives
        while(i < neg.size()) arr[arr_index++] = neg[i++];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 1, -2, -5, 2, -4};

    sol.rearrange(arr);

    for(int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

/*
Output:
3 -2 1 -5 2 -4
Explanation:
- Positive and negative numbers alternate
- Relative order among positives and negatives is preserved

Time Complexity: O(n)
  → Single pass to separate, and another to merge

Space Complexity: O(n)
  → Extra vectors for positive and negative numbers
*/