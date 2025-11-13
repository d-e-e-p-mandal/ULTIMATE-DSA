// count_set_bits_kernighan.c
// Program: Count number of set bits (1s) in an integer
// Method: Brian Kernighan’s Algorithm

#include <stdio.h>

// Function to count set bits using Brian Kernighan’s Algorithm
int countSetBits(int n) {
    int count = 0;

    // Loop until n becomes 0
    while (n) {
        // Remove the rightmost set bit
        n = n & (n - 1);
        count++;
    }

    return count;
}

int main() {
    int n = 13; // Example number: binary 1101

    printf("Number: %d\n", n);
    printf("Set Bits: %d\n", countSetBits(n));

    return 0;
}

/*
------------------------------------------
Explanation of Algorithm:
------------------------------------------
Each iteration removes one set bit (1) from n.
Operation: n = n & (n - 1)
This turns off the rightmost set bit of n.

------------------------------------------
Example Dry Run (n = 13, Binary: 1101)
------------------------------------------
Step | n (Binary) | n-1 (Binary) | n & (n-1) | Count
------------------------------------------
1    | 1101 (13)  | 1100 (12)    | 1100 (12) | 1
2    | 1100 (12)  | 1011 (11)    | 1000 (8)  | 2
3    | 1000 (8)   | 0111 (7)     | 0000 (0)  | 3
------------------------------------------
Final Count = 3

Output:
Number: 13
Set Bits: 3

------------------------------------------
Time Complexity:  O(k)
Where k = number of set bits (1s) in n

Space Complexity: O(1)
------------------------------------------
Good for:
Faster counting when the number has few set bits.
------------------------------------------
*/