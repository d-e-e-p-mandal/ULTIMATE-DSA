#include <stdio.h>

// 🔁 Swap two integers using bitwise XOR
void swap(int *x, int *y) {
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

// 🔄 Transpose the matrix
void transpose(int **matrix, int matrixSize, int *matrixColSize) {
    int i, j;
    for (i = 0; i < matrixSize; i++) {
        for (j = i + 1; j < *matrixColSize; j++) {
            if (i != j)
                swap(*(matrix + i) + j, *(matrix + j) + i);
        }
    }
}

// ↔️ Reverse columns of the matrix (to get 90° rotation)
void reverseCol(int **matrix, int matrixSize, int *matrixColSize) {
    int i = 0, j = *matrixColSize - 1, row;
    while (i < j) {
        for (row = 0; row < matrixSize; row++)
            swap(*(matrix + row) + i, *(matrix + row) + j);
        i++;
        j--;
    }
}

// 🔁 Rotate matrix 90° clockwise
void rotate(int **matrix, int matrixSize, int *matrixColSize) {
    transpose(matrix, matrixSize, matrixColSize);
    reverseCol(matrix, matrixSize, matrixColSize);
}

// 🧩 Main function for demonstration
int main() {
    int n = 3; // square matrix (3x3)
    int m = 3;
    int colSize = m;

    // Create 3x3 matrix
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Convert to pointer array (as LeetCode C expects)
    int *matrix[3];
    for (int i = 0; i < n; i++)
        matrix[i] = a[i];

    printf("Original Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    rotate(matrix, n, &colSize);

    printf("\nMatrix After 90° Rotation (Clockwise):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}

/*
-----------------------------------
🧩 Example Output:
-----------------------------------
Original Matrix:
1 2 3
4 5 6
7 8 9

Matrix After 90° Rotation (Clockwise):
7 4 1
8 5 2
9 6 3
-----------------------------------

✅ Time Complexity: O(n²)
   - Both transpose and column-reversal steps iterate through the entire matrix.

✅ Space Complexity: O(1)
   - In-place rotation; no extra memory used beyond a few variables.

✅ Additional Notes:
   - The `swap()` function uses XOR, so no temporary variable is required.
   - Works correctly for square matrices (n x n).
-----------------------------------
*/