#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        // Base case: if only 1 disk -> 1 move
        if (n == 1) return 1;

        int moves = 0;

        // Move (n-1) disks from 'from' to 'aux'
        moves += towerOfHanoi(n - 1, from, aux, to);

        // Move the largest disk from 'from' to 'to'
        moves++;

        // Move (n-1) disks from 'aux' to 'to'
        moves += towerOfHanoi(n - 1, aux, to, from);

        return moves;
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;

    // calling function with rods: from = 1, to = 3, aux = 2
    cout << obj.towerOfHanoi(n, 1, 3, 2) << endl;

    return 0;
}

/*
-----------------------------------------
Sample Input:
2

Sample Output:
3

Explanation:
Minimum moves for Tower of Hanoi with 2 disks = 2^2 - 1 = 3

-----------------------------------------
Time Complexity:
O(2^n)
Reason: Each recursive call splits into two calls: T(n) = 2T(n-1) + 1

Space Complexity:
O(n)
Reason: Due to recursion stack (max depth = n)

-----------------------------------------
*/
