// count_set_bits_builtin.c
// Program: Count number of set bits (1s) in an integer
// Method: Built-in Function (Using GCC/Clang intrinsics)

#include <stdio.h>

// Main program
int main() {
    int n = 13; // Example number: binary 00000000 00000000 00000000 00001101

    // For 32-bit integers
    int count32 = __builtin_popcount(n);

    // For 64-bit integers (long long)
    long long num64 = 13;
    int count64 = __builtin_popcountll(num64);

    printf("Number (32-bit): %d\n", n);
    printf("Set Bits (32-bit): %d\n", count32);

    printf("\nNumber (64-bit): %lld\n", num64);
    printf("Set Bits (64-bit): %d\n", count64);

    return 0;
}

/*
------------------------------------------
Explanation of Algorithm:
------------------------------------------
Idea:
Use the processor’s **POPCNT** instruction available in modern CPUs.
This instruction directly counts the number of set bits in binary.

How it works:
- GCC and Clang compilers provide built-in functions:
  ➤ __builtin_popcount(n)    → for 32-bit integers
  ➤ __builtin_popcountll(n)  → for 64-bit integers

These functions are **hardware-optimized** and very fast.

------------------------------------------
Example:
Number: 13 (Binary: 1101)
Set Bits: 3

Output:
Number (32-bit): 13
Set Bits (32-bit): 3

Number (64-bit): 13
Set Bits (64-bit): 3

------------------------------------------
Time Complexity:  O(1)
Space Complexity: O(1)

------------------------------------------
Good for:
Real-world applications where speed matters — 
compilers translate this directly into a CPU-level POPCNT instruction.
------------------------------------------
*/