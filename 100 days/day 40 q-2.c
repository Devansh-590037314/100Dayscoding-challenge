#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE] = {0};
    int rowsA, colsA, rowsB, colsB;

    printf("Enter the number of rows and columns of matrix A (1-100): ");
    if (scanf("%d %d", &rowsA, &colsA) != 2 || rowsA < 1 || rowsA > MAX_SIZE || colsA < 1 || colsA > MAX_SIZE) {
        fprintf(stderr, "Invalid dimensions for matrix A. Please enter values from 1 to 100.\n");
        return 1;
    }

    printf("Enter the number of rows and columns of matrix B (1-100): ");
    if (scanf("%d %d", &rowsB, &colsB) != 2 || rowsB < 1 || rowsB > MAX_SIZE || colsB < 1 || colsB > MAX_SIZE) {
        fprintf(stderr, "Invalid dimensions for matrix B. Please enter values from 1 to 100.\n");
        return 1;
    }

    if (colsA != rowsB) {
        fprintf(stderr, "Matrix multiplication is not possible because columns of A must equal rows of B.\n");
        return 1;
    }

    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            if (scanf("%d", &matrixA[i][j]) != 1) {
                fprintf(stderr, "Invalid input. Please enter integers only.\n");
                return 1;
            }
        }
    }

    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("B[%d][%d]: ", i + 1, j + 1);
            if (scanf("%d", &matrixB[i][j]) != 1) {
                fprintf(stderr, "Invalid input. Please enter integers only.\n");
                return 1;
            }
        }
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    printf("Product of the two matrices:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
