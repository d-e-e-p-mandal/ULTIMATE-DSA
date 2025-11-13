// count_set_bits_lookup.c
// Program: Count number of set bits (1s) in an integer
// Method: Lookup Table Method

#include <stdio.h>

// Global lookup table to store count of set bits for 0–255
int table[256];

// Function to initialize the lookup table
void initialize() {
    table[0] = 0;
    for (int i = 1; i < 256; i++)
        table[i] = (i & 1) + table[i / 2];
}

// Function to count set bits using the lookup table
int countSetBits(int n) {
    return table[n & 0xff] +               // byte 1
           table[(n >> 8) & 0xff] +        // byte 2
           table[(n >> 16) & 0xff] +       // byte 3
           table[(n >> 24) & 0xff];        // byte 4
}

int main() {
    initialize(); // Must call once before using countSetBits()

    int n = 13; // Example number: binary 00000000 00000000 00000000 00001101

    printf("Number: %d\n", n);
    printf("Set Bits: %d\n", countSetBits(n));

    return 0;
}

/*
------------------------------------------
Explanation of Algorithm:
------------------------------------------
Idea:
- Precompute the count of set bits for all 8-bit numbers (0–255).
- Any 32-bit number can be split into 4 bytes.
- Lookup the set bit count of each byte and sum them up.

------------------------------------------
Example Dry Run (n = 13, Binary: 00000000 00000000 00000000 00001101)
------------------------------------------
Byte 1 = 00001101 (13)  → table[13] = 3
Byte 2 = 00000000 (0)   → table[0] = 0
Byte 3 = 00000000 (0)   → table[0] = 0
Byte 4 = 00000000 (0)   → table[0] = 0
------------------------------------------
Total Set Bits = 3

Output:
Number: 13
Set Bits: 3

------------------------------------------
Time Complexity:
- Initialization: O(256)
- Counting: O(1) (after table setup)

Space Complexity: O(256) = O(1) (constant table size)

------------------------------------------
Good for:
Very fast bit counting after a one-time setup.
------------------------------------------
*/