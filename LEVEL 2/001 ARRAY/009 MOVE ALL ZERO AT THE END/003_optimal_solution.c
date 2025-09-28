#include <stdio.h>

// Swap two integers using XOR
void swap(int *x, int *y) {
    if (x == y) return; // avoid self-swap
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

// Function to move all zeroes to the end of the array
void moveZeroes(int* nums, int numsSize) {
    int j = 0; // position to place the next non-zero element

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) { // non-zero element found
            if (i != j) {   // only swap if i and j are different
                swap(&nums[i], &nums[j]);
            }
            j++; // move next position
        }
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, numsSize);

    printf("Array after moving zeroes: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

/*
Example Output:
Array after moving zeroes: 1 3 12 0 0

-----------------------
Time Complexity:
- O(n), single pass through the array

Space Complexity:
- O(1), in-place swapping with no extra array
*/