class Solution {

    // -----------------------------------------------------
    // Find maximum product subarray using prefix + suffix
    // -----------------------------------------------------
    public int maxProduct(int[] nums) {
        int n = nums.length;

        int pre = 1, suff = 1;
        int product = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {

            // If product becomes zero, reset it because
            // product after zero must start new subarray.
            if (pre == 0) pre = 1;
            if (suff == 0) suff = 1;

            // Prefix product (left to right)
            pre *= nums[i];

            // Suffix product (right to left)
            suff *= nums[n - i - 1];

            // Max product could be from left or right scan
            product = Math.max(product, Math.max(pre, suff));
        }

        return product;
    }
}


// ------------------------------------------------------
// Main class for testing the solution
// ------------------------------------------------------
public class Optimal_approach_1_003 {
    public static void main(String[] args) {

        int[] arr = {2, 3, -2, 4};

        Solution obj = new Solution();
        int result = obj.maxProduct(arr);

        System.out.println("Maximum Product Subarray: " + result);
    }
}


/*
---------------------------------------------------------
Example Input:
[2, 3, -2, 4]

Possible subarrays:
2 → product = 2
2 * 3 = 6
3 * (-2) = -6
(-2) * 4 = -8
4 = 4

Maximum Product = 6

---------------------------------------------------------
Example Output:
Maximum Product Subarray: 6

---------------------------------------------------------
TIME COMPLEXITY: O(n)
 - One single scan from both ends (prefix + suffix)

SPACE COMPLEXITY: O(1)
 - Only constant extra variables used

---------------------------------------------------------
*/