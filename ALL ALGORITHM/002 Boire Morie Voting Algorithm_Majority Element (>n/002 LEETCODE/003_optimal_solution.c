#include <stdio.h>

// Function to find majority element using Moore's Voting Algorithm
int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int pickElement;

    // Step 1: Find candidate for majority
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            pickElement = nums[i]; // pick new candidate
            count = 1;
        }
        else if (pickElement == nums[i]) {
            count++;              // same element, increase count
        }
        else {
            count--;              // different element, decrease count
        }
    }

    // Step 2: No verification needed if question guarantees a majority element
    return pickElement;  // in question must contain majority element
}

int main() {
    int nums[] = {2, 2, 1, 1, 2, 2, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Majority Element: %d\n", majorityElement(nums, n));

    return 0;
}

/*
---------------------------------------
Example Output:
Majority Element: 2

Time Complexity:  O(N)
Space Complexity: O(1)

Explanation:
- Step 1: Find a candidate by canceling out different elements.
- Step 2: Since majority element is guaranteed, candidate is returned.
- Uses constant extra space.
---------------------------------------
*/