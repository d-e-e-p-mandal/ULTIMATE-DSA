 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Naive lower bound: linearly search for first index where arr[i] >= target
    int lowerBound(vector<int>& arr, int target) {
        int n = arr.size();
        int index = 0;

        // Scan from left until condition satisfies
        while (index < n) {
            if (arr[index] >= target) break;
            index++;
        }

        return index;   // if not found, returns n
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cin >> target;

    Solution obj;
    cout << obj.lowerBound(arr, target) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
10
1 2 3 4 4 5 6 7 7 7
4

Sample Output:
3

Explanation:
First index where arr[i] >= 4 is index 3.

-----------------------------------------
Time Complexity:
O(n)
Reason:
Naive approach checks each element once.

Space Complexity:
O(1)
Reason:
No extra space used other than a few variables.

-----------------------------------------
*/