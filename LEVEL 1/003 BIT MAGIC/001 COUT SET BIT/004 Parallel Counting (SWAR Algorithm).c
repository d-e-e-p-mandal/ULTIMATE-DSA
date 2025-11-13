// count_set_bits_swar.c
// Program: Count number of set bits (1s) in an integer
// Method: Parallel Counting (SWAR Algorithm)

#include <stdio.h>

// Function to count set bits using SWAR (SIMD Within A Register)
int countSetBits(unsigned int n) {
    // Step 1: Subtract pairs of bits (n >> 1) & mask
    n = n - ((n >> 1) & 0x55555555);

    // Step 2: Count bits in nibbles (groups of 2 bits)
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);

    // Step 3: Add 4-bit groups (nibbles)
    n = (n + (n >> 4)) & 0x0F0F0F0F;

    // Step 4: Accumulate results from bytes
    n = n + (n >> 8);

    // Step 5: Accumulate from 16-bit chunks
    n = n + (n >> 16);

    // Mask to get final 6-bit result (0–32)
    return n & 0x3F;
}

int main() {
    unsigned int n = 13; // Example number: binary 00000000 00000000 00000000 00001101

    printf("Number: %u\n", n);
    printf("Set Bits: %d\n", countSetBits(n));

    return 0;
}

/*
------------------------------------------
Explanation of Algorithm:
------------------------------------------
Idea:
Count bits in parallel using masks and shifts.
No loops — all operations are done via bit manipulation.

Masks used:
0x55555555 = 01010101...
0x33333333 = 00110011...
0x0F0F0F0F = 00001111...

Steps:
1. Subtract adjacent bit pairs → n - ((n >> 1) & 0x55555555)
2. Add results in groups of 2 bits.
3. Add 4-bit (nibble) results using mask 0x0F0F0F0F.
4. Combine results across bytes and half-words.

------------------------------------------
Example (n = 13, Binary: 00000000 00000000 00000000 00001101)
------------------------------------------
13 = binary 1101 → total 3 set bits
All operations eventually sum those bits in parallel.

Output:
Number: 13
Set Bits: 3

------------------------------------------
Time Complexity:  O(1)
Space Complexity: O(1)

------------------------------------------
Good for:
High-speed bit counting with no loops — efficient in modern CPUs.
------------------------------------------
*/