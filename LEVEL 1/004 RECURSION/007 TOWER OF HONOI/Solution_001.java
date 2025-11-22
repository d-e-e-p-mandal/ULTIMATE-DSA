package delet.ans;
// Main class (Driver Code)
import java.util.*;

public class Solution_001 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Taking input n (number of disks)
        int n = sc.nextInt();
        
        // Creating object of Solution class
        Solution obj = new Solution();
        
        // Calling the function with rods: from = 1, to = 3, aux = 2
        System.out.println(obj.towerOfHanoi(n, 1, 3, 2));
    }
}

// Solution class (Your original code - unchanged)
class Solution {
    public int towerOfHanoi(int n, int from, int to, int aux) {
        // Base case: for 1 disk → only 1 move needed
        if (n == 1) return 1;

        int moves = 0;

        // 1. Move (n-1) disks from 'from' to 'aux'
        moves += towerOfHanoi(n - 1, from, aux, to);

        // 2. Move the largest disk from 'from' to 'to'
        moves++;

        // 3. Move (n-1) disks from 'aux' to 'to'
        moves += towerOfHanoi(n - 1, aux, to, from);

        return moves;
    }
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
Reason: Each call generates two more recursive calls → T(n) = 2T(n-1) + 1

Space Complexity:
O(n)
Reason: Recursion uses stack space proportional to height 'n'

-----------------------------------------
*/