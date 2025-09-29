#include <stdio.h>

// Utility function to swap two elements
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to reverse elements between indices left and right
void rev(int *nums, int left, int right) {
    while (left < right) {
        swap(nums + left, nums + right);
        left++;
        right--;
    }
}

// Function to rotate array by k steps to the right
void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 0) return;

    k %= numsSize;  // handle k > numsSize

    // Step 1: Reverse the whole array
    rev(nums, 0, numsSize - 1);

    // Step 2: Reverse first k elements
    rev(nums, 0, k - 1);

    // Step 3: Reverse remaining elements
    rev(nums, k, numsSize - 1);
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    rotate(nums, numsSize, k);

    printf("Array after rotation by %d steps: ", k);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

/*
Example Output:
Array after rotation by 3 steps: 5 6 7 1 2 3 4 

-----------------------
Time Complexity:
- O(n), every element reversed at most twice.

Space Complexity:
- O(1), in-place reversal with no extra array.
*/