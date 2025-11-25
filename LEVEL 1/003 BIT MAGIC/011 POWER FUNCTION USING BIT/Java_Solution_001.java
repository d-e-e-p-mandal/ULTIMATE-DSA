import java.util.*;

public class Java_Solution_001 {

    // Function to calculate square(n) using bit manipulation (no multiplication)
    static int square(int n) {
        int result = 0;

        // Check all 32 bits of n
        for (int i = 0; i < 32; i++) {

            // If the i-th bit of n is 1
            if ((n & (1 << i)) != 0) {

                // Add n * (2^i) → achieved using left shift
                result += (n << i);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        // Print square
        System.out.println(square(n));
    }
}

/*
--------------------------------------------------
Sample Input:
6

Sample Output:
36

Explanation:
Binary of 6 = 110
Square = 6*(2^1) + 6*(2^2) = 12 + 24 = 36

--------------------------------------------------
Time Complexity:
O(32) → O(1)
Reason:
Loop always runs 32 times regardless of input size.

Space Complexity:
O(1)
Reason:
Only fixed variables used.

--------------------------------------------------
*/