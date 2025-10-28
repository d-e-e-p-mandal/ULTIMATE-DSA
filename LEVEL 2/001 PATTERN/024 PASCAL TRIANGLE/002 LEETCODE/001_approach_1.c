
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **pascale, i, j;

    // Allocate memory for 'numRows' pointers (each pointing to a row)
    pascale = (int **)malloc(numRows * sizeof(int *));
    
    // Set number of rows
    *returnSize = numRows;

    // Allocate memory to store column size for each row
    *returnColumnSizes = (int *)malloc(numRows * sizeof(int));

    // Build Pascal’s Triangle
    for (i = 0; i < numRows; i++) {
        // Allocate memory for (i+1) elements in the i-th row
        pascale[i] = (int *)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;

        // Fill each row
        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                pascale[i][j] = 1;  // First and last element = 1
            else
                pascale[i][j] = pascale[i - 1][j - 1] + pascale[i - 1][j]; // Sum of two above
        }
    }

    return pascale;
}

// 🧩 Main function for demonstration
int main() {
    int numRows = 5;
    int returnSize;
    int *returnColumnSizes;

    int **triangle = generate(numRows, &returnSize, &returnColumnSizes);

    printf("Pascal’s Triangle (%d rows):\n", numRows);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < numRows; i++)
        free(triangle[i]);
    free(triangle);
    free(returnColumnSizes);

    return 0;
}

/*
-----------------------------------
🧩 Example Output:
-----------------------------------
Pascal’s Triangle (5 rows):
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
-----------------------------------

✅ Time Complexity: O(n²)
   - Each row i has i elements, and every element (except 1s) is computed from 2 previous values.

✅ Space Complexity: O(n²)
   - Triangle of total n(n+1)/2 elements stored using dynamic allocation.

✅ Notes:
   - Uses `malloc()` for each row as LeetCode requires returning a 2D array.
   - Each row can have a different number of columns.
   - Caller must `free()` all allocated memory.
-----------------------------------
*/