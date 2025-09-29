#include <stdio.h>

// Function to find the missing number in an array of size n
int missingNumber(int* nums, int numsSize) {
    int ans = numsSize; // XOR with last index
    for(int i = 0; i < numsSize; i++) {
        ans ^= nums[i] ^ i; // XOR array element with its index
    }
    return ans;  
}

int main() {
    int nums[] = {3, 0, 1}; // Example array
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = missingNumber(nums, n);
    printf("Missing Number: %d\n", result);

    return 0;
}

/*
Time Complexity:
- O(n), single traversal of the array.

Space Complexity:
- O(1), constant extra space.

Example Output:
Missing Number: 2
*/