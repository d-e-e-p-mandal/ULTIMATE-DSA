class Solution {

    // ---------------------------------------------------
    // Function to find Maximum Product Subarray
    // Using tracking of maxProd and minProd
    // ---------------------------------------------------
    public int maxProduct(int[] nums) {
        int n = nums.length;

        // Initial values
        int product = nums[0];
        int maxProd = nums[0];    // maximum product ending here
        int minProd = nums[0];    // minimum product ending here (needed due to negative numbers)

        // Traverse from second element
        for (int i = 1; i < n; i++) {

            int curr = nums[i];

            // If current number is negative → swap max and min
            // Because multiplying negative flips signs
            if (curr < 0) {
                int temp = maxProd;
                maxProd = minProd;
                minProd = temp;
            }

            // Update max/min products including current element
            maxProd = Math.max(curr, maxProd * curr);
            minProd = Math.min(curr, minProd * curr);

            // Update global answer
            product = Math.max(product, maxProd);
        }

        return product;
    }
}


// ------------------------------------------------------
// Main class to test the solution
// ------------------------------------------------------
public class Optimal_approach_2_003 {
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

The maximum product subarray is:
[2, 3] → 6

---------------------------------------------------------
Example Output:
Maximum Product Subarray: 6

---------------------------------------------------------
TIME COMPLEXITY: O(n)
 - Single traversal of array

SPACE COMPLEXITY: O(1)
 - Only constant extra variables

---------------------------------------------------------
*/