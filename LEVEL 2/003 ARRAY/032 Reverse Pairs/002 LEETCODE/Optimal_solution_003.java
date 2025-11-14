import java.util.*;

class Solution {

    // ---------------------------------------
    // Merge two sorted halves of the array
    // ---------------------------------------
    public static void merge(int[] nums, int low, int mid, int high) {

        int i = low, j = mid + 1;
        int[] temp = new int[high - low + 1];
        int k = 0;

        // Standard merge of two sorted halves
        while (i <= mid && j <= high) {

            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        // Copy remaining left half
        while (i <= mid) temp[k++] = nums[i++];

        // Copy remaining right half
        while (j <= high) temp[k++] = nums[j++];

        // Copy back to original array
        for (int p = low; p <= high; p++) {
            nums[p] = temp[p - low];
        }
    }

    // --------------------------------------------------------
    // Count reverse pairs: nums[i] > 2 * nums[j]
    // Using two-pointer scanning (sorted halves)
    // --------------------------------------------------------
    public static int countPairs(int[] nums, int low, int mid, int high) {

        int right = mid + 1;
        int cnt = 0;

        // Count pairs for each i in left half
        for (int i = low; i <= mid; i++) {

            while (right <= high && (long) nums[i] > 2L * nums[right]) {
                right++;
            }

            cnt += (right - (mid + 1)); // valid j count
        }

        return cnt;
    }

    // --------------------------------------------------------
    // MergeSort + Count reverse pairs
    // --------------------------------------------------------
    public static int solve(int[] nums, int low, int high) {

        if (low >= high) return 0; // single element → no pairs

        int mid = (low + high) / 2;

        int left = solve(nums, low, mid);
        int right = solve(nums, mid + 1, high);

        int cross = countPairs(nums, low, mid, high);

        merge(nums, low, mid, high);

        return left + right + cross;
    }

    // External function
    public int reversePairs(int[] nums) {
        return solve(nums, 0, nums.length - 1);
    }
}


// --------------------------------------------------------
// Main class for testing
// --------------------------------------------------------
public class Optimal_solution_003 {
    public static void main(String[] args) {

        int[] arr = {1, 3, 2, 3, 1};

        Solution obj = new Solution();
        int ans = obj.reversePairs(arr);

        System.out.println("Reverse Pairs Count: " + ans);
    }
}


/*
----------------------------------------------------------
Example Input:
[1, 3, 2, 3, 1]

Reverse Pairs (i < j and nums[i] > 2 * nums[j]):
(3, 1)
(3, 1)

----------------------------------------------------------
Example Output:
Reverse Pairs Count: 2

----------------------------------------------------------
TIME COMPLEXITY:
O(n log n)
- Merge Sort recursion: log n levels
- Counting + merging each level: O(n)

----------------------------------------------------------
SPACE COMPLEXITY:
O(n)
- Temporary arrays used in merging
----------------------------------------------------------
*/
