import java.util.*;

class Solution {
    public static int factorial(int n) {
        if(n == 0 || n == 1) return 1;

        return n * factorial(n-1);
    }
}

class RecursionSolution_001 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(Solution.factorial(n));
    }
}