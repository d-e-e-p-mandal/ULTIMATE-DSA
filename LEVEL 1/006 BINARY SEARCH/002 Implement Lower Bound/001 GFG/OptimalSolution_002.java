import java.util.*;

class Solution {

    // Function to compute lower bound (first index where arr[i] >= target)
    int lowerBound(int[] arr, int target) {
        int n = arr.length;
        int low = 0, high = n - 1;

        // Standard lower bound binary search
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < target)
                low = mid + 1;   // go right
            else
                high = mid;      // possible answer is mid
        }

        // If target is greater than all elements
        if (low == n - 1 && arr[low] < target) 
            return low + 1;

        return low;
    }
}

class OptimalSolution_002 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        int target = sc.nextInt();

        Solution obj = new Solution();
        System.out.println(obj.lowerBound(arr, target));
    }
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
lower_bound of 4 = first index where arr[i] >= 4 → index 3

-----------------------------------------
Time Complexity:
O(log n)
Reason:
Binary search divides the range in half each time.

Space Complexity:
O(1)
Reason:
Only constant extra variables used.

-----------------------------------------
*/