import java.util.*;

class Solution_better_002 {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        int appear = n / 3; // threshold value

        List<Integer> ans = new ArrayList<>();
        HashMap<Integer, Integer> mp = new HashMap<>();

        // Count frequency of each element
        for (int i = 0; i < n; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);

            // Check if element appears more than n/3 times and not already added
            if (mp.get(nums[i]) > appear && !ans.contains(nums[i])) {
                ans.add(nums[i]);
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution obj = new Solution();

        int[] nums1 = {3, 2, 3};
        int[] nums2 = {1, 1, 1, 3, 3, 2, 2, 2};

        System.out.println("Input: [3, 2, 3]");
        System.out.println("Output: " + obj.majorityElement(nums1));
        System.out.println();

        System.out.println("Input: [1, 1, 1, 3, 3, 2, 2, 2]");
        System.out.println("Output: " + obj.majorityElement(nums2));
    }
}

/*
----------------------------------------
🧩 Example Output:
----------------------------------------
Input: [3, 2, 3]
Output: [3]

Input: [1, 1, 1, 3, 3, 2, 2, 2]
Output: [1, 2]
----------------------------------------

✅ Time Complexity: O(n)
   - Each element processed once.
   - ans.contains() check is O(1) effectively (since at most 2 elements possible).

✅ Space Complexity: O(n)
   - For HashMap to store element frequencies.
----------------------------------------
*/