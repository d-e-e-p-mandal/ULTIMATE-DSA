// count_set_bits_naive.c
// Program: Count number of set bits (1s) in an integer
// Method: Naive / Simple Iterative Method

#include <stdio.h>

// Function to count set bits
int countSetBits(int n) {
    int count = 0;

    // Loop until all bits are checked
    while (n > 0) {
        // Check if last bit is 1
        if (n & 1)
            count++;

        // Shift bits right by one
        n >>= 1;
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
Example Dry Run (n = 13, Binary: 1101)
------------------------------------------
Step | Binary | n & 1 | Count | Shifted n
------------------------------------------
1    | 1101   | 1     | 1     | 110
2    | 110    | 0     | 1     | 11
3    | 11     | 1     | 2     | 1
4    | 1      | 1     | 3     | 0
------------------------------------------
Final Count = 3

Output:
Number: 13
Set Bits: 3

------------------------------------------
Time Complexity:  O(log n)
Space Complexity: O(1)
------------------------------------------
*/