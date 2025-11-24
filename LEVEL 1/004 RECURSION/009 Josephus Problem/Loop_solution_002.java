import java.util.*;

class Solution {
    public int josephus(int n, int k) {
        // boolean array to mark eliminated persons (default false)
        boolean[] arr = new boolean[n];

        int x = 0;       // count steps until k
        int count = n;   // number of people left

        // loop continues until only one person remains
        for (int i = 1; count > 1; i++) {
            if (!arr[i - 1]) x++;   // count only alive persons

            if (x == k) {           // eliminate the k-th person
                x = 0;
                count--;
                arr[i - 1] = true;
            }

            // circular movement
            if (i == n) i %= n;
        }

        // find the last surviving person
        for (int i = 1; i <= n; i++) {
            if (!arr[i - 1]) return i;
        }

        return 0;
    }
}

class Loop_solution_002 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

        Solution obj = new Solution();
        System.out.println(obj.josephus(n, k));
    }
}

/*
-----------------------------------------
Sample Input:
5 2

Sample Output:
3

Explanation:
Eliminate every 2nd person → survivor = 3

-----------------------------------------
Time Complexity:
O(n^2)
Reason:
Each elimination may scan the array again in a circular manner.

Space Complexity:
O(n)
Reason:
Using a boolean array of size n.

-----------------------------------------
*/