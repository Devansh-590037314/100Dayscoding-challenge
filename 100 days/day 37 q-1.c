#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main(void)
{
    int matrix[MAX_ROWS][MAX_COLS];
    long long row_sums[MAX_ROWS] = {0};
    int rows, cols;

    printf("Enter the number of rows (1-100): ");
    if (scanf("%d", &rows) != 1 || rows < 1 || rows > MAX_ROWS) {
        fprintf(stderr, "Invalid row count. Enter an integer from 1 to 100.\n");
        return 1;
    }

    printf("Enter the number of columns (1-100): ");
    if (scanf("%d", &cols) != 1 || cols < 1 || cols > MAX_COLS) {
        fprintf(stderr, "Invalid column count. Enter an integer from 1 to 100.\n");
        return 1;
    }

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            if (scanf("%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Invalid input. Please enter integers only.\n");
                return 1;
            }
            row_sums[i] += matrix[i][j];
        }
    }

    printf("Sum of each row:\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d: %lld\n", i + 1, row_sums[i]);
    }

    return 0;
}