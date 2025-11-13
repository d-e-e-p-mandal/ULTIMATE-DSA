import java.util.*;

class Optimal_solution_003 {
    // Merge two sorted halves and count inversions
    public int merge(int[] arr, int low, int mid, int high) {
        ArrayList<Integer> temp = new ArrayList<>();
        int i = low, j = mid + 1;
        int cnt = 0;

        // Merge while counting inversions
        while (i <= mid && j <= high) {
            if (arr[i] > arr[j]) {
                temp.add(arr[j]);
                j++;
                // All remaining elements from i to mid are greater than arr[j]
                cnt += (mid - i + 1);
            } else {
                temp.add(arr[i]);
                i++;
            }
        }

        // Copy remaining left half elements
        while (i <= mid) {
            temp.add(arr[i]);
            i++;
        }
        // Copy remaining right half elements
        while (j <= high) {
            temp.add(arr[j]);
            j++;
        }

        // Copy back to original array
        for (int k = low; k <= high; k++) {
            arr[k] = temp.get(k - low);
        }

        return cnt;
    }

    // Recursive function to divide and conquer inversion count
    public int solve(int[] arr, int low, int high) {
        if (low >= high) return 0;

        int mid = (low + high) / 2;

        int leftCount = solve(arr, low, mid);
        int rightCount = solve(arr, mid + 1, high);
        int mergeCount = merge(arr, low, mid, high);

        return leftCount + rightCount + mergeCount;
    }

    // Static method to be called externally
    public static int inversionCount(int[] arr) {
        Optimal_solution_003 obj = new Optimal_solution_003();
        return obj.solve(arr, 0, arr.length - 1);
    }

    // Main method for testing
    public static void main(String[] args) {
        int[] arr = {2, 4, 1, 3, 5};
        System.out.println("Inversion Count: " + inversionCount(arr)); // Output: 3
    }
}