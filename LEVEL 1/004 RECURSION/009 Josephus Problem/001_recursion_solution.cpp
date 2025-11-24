#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, int k, vector<bool>& arr, int start, int count, int x) {
        if (start > n) start %= n;

        // Base case: if only 1 person left, return the survivor
        if (count == 1) {
            for (int i = 0; i < n; i++)
                if (arr[i] == false) return i + 1;
        }

        // Circular elimination
        for (int i = start; i <= n; i++) {
            if (arr[i - 1] == false) x++;

            if (x == k) {
                arr[i - 1] = true;
                // Move to next position after i
                return solve(n, k, arr, (i + 1), count - 1, 0);
            }
        }

        // If we reached end, wrap to start
        return solve(n, k, arr, 1, count, x);
    }

    int josephus(int n, int k) {
        vector<bool> arr(n, false);
        return solve(n, k, arr, 1, n, 0);
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    Solution obj;
    cout << obj.josephus(n, k) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
5 2

Sample Output:
3

Explanation:
People: 1 2 3 4 5
Eliminate every 2nd → survivor = 3

-----------------------------------------
Time Complexity:
O(n^2)
Reason:
Each elimination may scan up to n elements, and there are n eliminations.

Space Complexity:
O(n)
Reason:
Using a boolean vector of size n.

-----------------------------------------
*/