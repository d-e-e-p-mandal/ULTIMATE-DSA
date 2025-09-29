#include <stdio.h>

// Function to find the unique number in the array
int singleNumber(int* nums, int numsSize) {
    int i, singleNumber = 0;
    for(i = 0; i < numsSize; i++)
        singleNumber ^= nums[i];   // XOR cancels numbers appearing twice
    return singleNumber;           // returns the number which occurs once
}

int main() {
    int nums[] = {2, 30, 2, 15, 20, 30, 15};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = singleNumber(nums, n);
    printf("Unique Number: %d\n", result);

    return 0;
}

/*
Time Complexity:
- O(n), single traversal of the array.

Space Complexity:
- O(1), constant extra space.

Example Output:
Unique Number: 20
*/