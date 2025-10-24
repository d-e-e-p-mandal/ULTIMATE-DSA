#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** arr, int matrixSize, int* matrixColSize, int* returnSize) {
    int i, x = 0;
    int top = 0, left = 0, bottom = matrixSize - 1, right = *matrixColSize - 1;
    
    int *res = (int *)malloc(matrixSize * (*matrixColSize) * sizeof(int));
    *returnSize = matrixSize * (*matrixColSize);

    while(top <= bottom && left <= right){
        // Traverse top row
        for(i = left; i <= right; i++)
            res[x++] = arr[top][i];
        top++;

        // Traverse right column
        for(i = top; i <= bottom; i++)
            res[x++] = arr[i][right];
        right--;

        // Traverse bottom row
        for(i = right; i >= left; i--)
            if(top <= bottom)
                res[x++] = arr[bottom][i];
        bottom--;

        // Traverse left column
        for(i = bottom; i >= top; i--)
            if(left <= right)
                res[x++] = arr[i][left];
        left++;
    }

    return res;
}

int main() {
    int m = 3, n = 3;
    int* matrix[3];
    int mat0[] = {1, 2, 3};
    int mat1[] = {4, 5, 6};
    int mat2[] = {7, 8, 9};
    matrix[0] = mat0;
    matrix[1] = mat1;
    matrix[2] = mat2;

    int returnSize;
    int* result = spiralOrder(matrix, m, &n, &returnSize);

    printf("Spiral order: ");
    for(int i = 0; i < returnSize; i++)
        printf("%d ", result[i]);
    printf("\n");

    free(result);
    return 0;
}

/*
-----------------------------------
Example Output:
-----------------------------------
Spiral order: 1 2 3 6 9 8 7 4 5

-----------------------------------
Time Complexity: O(m × n)
   → Every element is visited exactly once.

Space Complexity: O(m × n)
   → Result array stores all m × n elements.
-----------------------------------
*/