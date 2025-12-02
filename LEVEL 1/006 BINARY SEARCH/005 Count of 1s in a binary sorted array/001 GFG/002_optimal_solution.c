#include <stdio.h>

int countOnes(int *arr, int n) {
    int low = 0;
    int high = n - 1;
    int target = 1;

    // Binary search to find index after the last 1
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            low = mid + 1;      // move right
        else
            high = mid - 1;     // move left
    }

    return low;   // number of 1s
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", countOnes(arr, n));

    return 0;
}

/*
-----------------------------------------
Sample Input:
7
0 0 0 1 1 1 1

Sample Output:
4

Explanation:
There are four 1s in the sorted binary array.
Binary search finds index after the last 1.

-----------------------------------------
Time Complexity:
O(log n)
Reason:
Binary search halves the range each step.

Space Complexity:
O(1)
Reason:
No extra arrays used.

-----------------------------------------
*/