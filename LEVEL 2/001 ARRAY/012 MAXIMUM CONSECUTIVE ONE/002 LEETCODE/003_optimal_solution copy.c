#include <stdio.h>

// Function to find maximum consecutive 1s in array
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int i, count1 = 0, maxCount1 = 0;

    for(i = 0; i < numsSize; i++) {
        if(nums[i] == 1) {
            count1++;
            maxCount1 = (count1 > maxCount1) ? count1 : maxCount1; 
        } else {
            count1 = 0; // reset count when 0 found
        }
    }

    return maxCount1;
}

int main() {
    int nums[] = {1, 1, 0, 1, 1, 1, 0, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = findMaxConsecutiveOnes(nums, n);
    printf("Maximum consecutive ones: %d\n", result);

    return 0;
}

/*
Time Complexity: O(n)  
Space Complexity: O(1)  

Example Output:
Maximum consecutive ones: 3
*/