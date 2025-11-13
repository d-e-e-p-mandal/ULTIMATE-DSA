
import java.util.*;

class Optimal_xor_diff_approach_003 {
    ArrayList<Integer> findTwoElement(int arr[]) {
        int n = arr.length;  // ✅ array size

        int xr = 0;  // overall XOR of all numbers (arr + 1..n)
        int r = 0, m = 0; // repeating & missing numbers

        ArrayList<Integer> ans = new ArrayList<>(2);

        // Step 1️⃣: XOR all elements and numbers from 1 to n
        for (int i = 0; i < n; i++) {
            xr ^= arr[i];
            xr ^= (i + 1);
        }

        // Step 2️⃣: find the rightmost set bit in xr
        int pos = 0;
        while ((xr & 1) == 0) { // find LSB = 1 position
            xr >>= 1;
            pos++;
        }

        // Step 3️⃣: Divide elements into two groups based on that bit
        for (int i = 0; i < n; i++) {
            if ((arr[i] & (1 << pos)) != 0)
                r ^= arr[i];
            else
                m ^= arr[i];

            if (((i + 1) & (1 << pos)) != 0)
                r ^= (i + 1);
            else
                m ^= (i + 1);
        }

        // Step 4️⃣: Check which is repeating (appears twice)
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (r == arr[i]) {
                cnt++;
                if (cnt == 2) {
                    ans.add(r); // repeating
                    ans.add(m); // missing
                    return ans;
                }
            }
        }

        // If not found earlier, reverse (means m was repeating)
        ans.add(m);
        ans.add(r);
        return ans;
    }

    // 🧩 Example driver code
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {4, 3, 6, 2, 1, 1};

        ArrayList<Integer> res = sol.findTwoElement(arr);
        System.out.println("Repeating number: " + res.get(0));
        System.out.println("Missing number: " + res.get(1));
    }
}

/*
-------------------------------------------
🧩 Example Output:
-------------------------------------------
Repeating number: 1
Missing number: 5
-------------------------------------------

✅ Time Complexity: O(n)
✅ Space Complexity: O(1)

⚙️ Logic Summary:
- Use XOR to cancel out identical numbers.
- The remaining XOR result = (missing ⊕ repeating)
- Split numbers by a differing bit to isolate each one.
-------------------------------------------
*/