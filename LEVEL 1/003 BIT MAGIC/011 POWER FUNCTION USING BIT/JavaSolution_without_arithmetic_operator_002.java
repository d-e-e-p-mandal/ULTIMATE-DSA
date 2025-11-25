import java.util.*;

public class JavaSolution_without_arithmetic_operator_002 {

    // Function to compute n^2 without using * operator
    static int square(int n) {
        int result = 0;
        int x = n;

        while (x > 0) {

            // If lowest bit of x is 1 → add current value of n
            if ((x & 1) == 1) {
                result = add(result, n);
            }

            // Multiply n by 2 (left shift)
            n <<= 1;

            // Divide x by 2 (right shift)
            x >>= 1;
        }

        return result;
    }

    // Add two numbers without using + operator
    static int add(int a, int b) {
        while (b != 0) {
            int carry = a & b;   // carry is stored where both bits are 1
            a = a ^ b;           // sum bits without carry
            b = carry << 1;      // shift carry left
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        // Output the square of n
        System.out.println(square(n));
    }
}

/*
--------------------------------------------------
Sample Input:
5

Sample Output:
25

Explanation:
Square(5) = 25
Computed using bitwise addition and shifting.

--------------------------------------------------
Time Complexity:
O(log n)
Reason:
Loop runs for number of bits in n (≈ log2 n). 
add() also runs in O(log n).

Space Complexity:
O(1)
Reason:
Only a few integer variables used.

--------------------------------------------------
*/