#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;

        // Last element is always a leader
        ans.push_back(arr[n-1]);

        // Traverse from second last element to first
        for(int i = n-2; i >= 0; i--) {
            if(arr[i] >= ans.back()) {
                ans.push_back(arr[i]);
            }
        }

        // Reverse to maintain original order of leaders
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    
    vector<int> result = sol.leaders(arr);
    
    cout << "Leaders in array: ";
    for(int x : result) cout << x << " ";
    cout << endl;

    return 0;
}

/*
Example Output:
Leaders in array: 17 5 2

Time Complexity:
- O(n), we traverse the array once and reverse the result once.

Space Complexity:
- O(n), for storing the leaders in a separate array.
*/