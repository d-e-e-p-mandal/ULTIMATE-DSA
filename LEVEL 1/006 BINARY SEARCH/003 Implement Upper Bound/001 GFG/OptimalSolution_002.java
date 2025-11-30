class Solution {

    // Function to find upper bound: first index where arr[i] > target
    int upperBound(int[] arr, int target) {
        int low = 0;
        int high = arr.length - 1;

        // Binary search for upper bound
        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] <= target)
                low = mid + 1;       // move right
            else
                high = mid - 1;      // move left
        }

        return low;   // index of first element > target
    }
}

class OptimalSolution_002 {
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        int target = sc.nextInt();

        Solution obj = new Solution();
        System.out.println(obj.upperBound(arr, target));
    }
}

/*
-----------------------------------------
Sample Input:
10
1 2 3 4 4 5 6 7 7 7
4

Sample Output:
5

Explanation:
First index where arr[i] > 4 is 5 (arr[5] = 5)

-----------------------------------------
Time Complexity:
O(log n)
Reason:
Binary search halves the search interval each step.

Space Complexity:
O(1)
Reason:
Only using a few variables.

-----------------------------------------
*/
