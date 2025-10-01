#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result, i, j;
    result = (int *)malloc(2 * sizeof(int));   // allocate memory for 2 indices
    
    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;  // return pointer to result
            }
        }
    }
    *returnSize = 0;  // no solution (though problem guarantees one)
    return NULL; 
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    
    int *ans = twoSum(nums, 4, target, &returnSize);

    if (ans != NULL) {
        printf("Indices: [%d, %d]\n", ans[0], ans[1]);
        free(ans); // free allocated memory
    } else {
        printf("No solution found.\n");
    }

    return 0;
}

/*
-------------------------------
Expected Output:
Indices: [0, 1]   // nums[0] = 2, nums[1] = 7 → 2+7 = 9

-------------------------------
Time Complexity: O(n^2)
- Double loop over array.

Space Complexity: O(1)
- Only constant extra space (apart from result array).
*/