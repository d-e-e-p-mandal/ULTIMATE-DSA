#include <stdio.h>

int countOnes(int *arr, int n) {
    for(int i = 0; i<n; i++) {
        if(arr[i] == 0) return i; // return index of 1st 0
    }

    return n;
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
O(n)
Reason:
Search halves the range each step.

Space Complexity:
O(1)
Reason:
No extra arrays used.

-----------------------------------------
*/