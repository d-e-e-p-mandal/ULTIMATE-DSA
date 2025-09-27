// Optimal Solution : Using Two Pointer : Time Complexity : O(N)

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int left = 0; // last unique element index
    for (int right = 1; right < numsSize; right++) {
        if (nums[left] != nums[right]) {
            left++;
            nums[left] = nums[right]; // update next unique position
        }
    }

    return left + 1; // new length
}

int main() {
    int nums[] = {1,1,2,2,3,4,4,5};
    int numsSize = sizeof(nums)/sizeof(nums[0]);

    int newLength = removeDuplicates(nums, numsSize);

    printf("New length after removing duplicates: %d\n", newLength);
    printf("Modified array: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

/*
Example Output:
New length after removing duplicates: 5
Modified array: 1 2 3 4 5

-----------------------
Time Complexity:
- O(n), single pass through array

Space Complexity:
- O(1), in-place modification, no extra array used
*/