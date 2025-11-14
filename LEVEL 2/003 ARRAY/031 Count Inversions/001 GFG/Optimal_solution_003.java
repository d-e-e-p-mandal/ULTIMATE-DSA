import java.util.*;

class Solution {
    // Merge two sorted halves and count inversions caused during merge
    public int merge(int[] arr, int low, int mid, int high) {
        ArrayList<Integer> temp = new ArrayList<>();
        int i = low, j = mid + 1;
        int cnt = 0;

        // Merge two sorted subarrays and count inversions
        while (i <= mid && j <= high) {
            if (arr[i] > arr[j]) {
                temp.add(arr[j]);
                j++;
                // All elements from i to mid are greater than arr[j]
                cnt += (mid - i + 1);
            } else {
                temp.add(arr[i]);
                i++;
            }
        }

        // Copy remaining elements from left half (if any)
        while (i <= mid) {
            temp.add(arr[i]);
            i++;
        }
        // Copy remaining elements from right half (if any)
        while (j <= high) {
            temp.add(arr[j]);
            j++;
        }

        // Copy sorted temp back to original array
        for (int k = low; k <= high; k++) {
            arr[k] = temp.get(k - low);
        }

        return cnt;
    }

    // Recursive function to divide array and count inversions
    public int solve(int[] arr, int low, int high) {
        if (low >= high) return 0;

        int mid = (low + high) / 2;

        int leftCount = solve(arr, low, mid);
        int rightCount = solve(arr, mid + 1, high);

        int mergeCount = merge(arr, low, mid, high);

        return leftCount + rightCount + mergeCount;
    }

    // Function to return total inversion count
    static int inversionCount(int[] arr) {
        Solution obj = new Solution();
        return obj.solve(arr, 0, arr.length - 1);
    }
}

// Example usage:
public class Optimal_solution_003 {
    public static void main(String[] args) {
        int[] arr = {2, 4, 1, 3, 5};
        int result = Solution.inversionCount(arr);
        System.out.println("Inversion Count: " + result);
    }
}

/*
-------------------------------------------
Example Output:
-------------------------------------------
Inversion Count: 3

-------------------------------------------
Time Complexity: O(n log n)
    - The array is recursively divided and merged.
    - Each merge step takes O(n) time.
    - Total merges ≈ log n levels, resulting in O(n log n).

Space Complexity: O(n)
    - Temporary list used during merges takes O(n) space.
-------------------------------------------
*/