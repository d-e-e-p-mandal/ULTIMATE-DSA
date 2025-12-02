import java.util.*;

class Solution {

    // Find the first index where arr[i] >= target
    int firstOccurence(int[] arr, int target, int n) {
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] < target)
                low = mid + 1;   // move right
            else
                high = mid - 1;  // potential first occurrence on left
        }

        return low;   // first index where arr[i] >= target
    }

    // Find the last index where arr[i] <= target
    int lastOccurence(int[] arr, int target, int n) {
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] <= target)
                low = mid + 1;   // move right
            else
                high = mid - 1;  // move left
        }

        return high;  // last index where arr[i] <= target
    }

    // Count how many times target appears
    int countFreq(int[] arr, int target) {
        int n = arr.length;

        int f = firstOccurence(arr, target, n);   // first >= target
        int l = lastOccurence(arr, target, n);    // last <= target

        return l - f + 1;
    }
}

class OptimalSolution_003 {
    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        int target = sc.nextInt();

        Solution obj = new Solution();
        System.out.println(obj.countFreq(arr, target));
    }
}

/*
-----------------------------------------
Sample Input:
10
1 2 2 2 3 4 4 5 6 7
2

Sample Output:
3

Explanation:
The value 2 appears at indices: 1, 2, 3 → total = 3

-----------------------------------------
Time Complexity:
O(log n)
Reason:
Binary search used for first and last occurrence.

Space Complexity:
O(1)
Reason:
Only a few variables used.

-----------------------------------------
*/