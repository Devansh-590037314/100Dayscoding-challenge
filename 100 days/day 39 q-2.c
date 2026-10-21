#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int matrix[MAX_SIZE][MAX_SIZE];
    long long rowSums[MAX_SIZE];
    int rows;
    int columns;

    printf("Enter the number of rows and columns (1-100): ");
    if (scanf("%d %d", &rows, &columns) != 2 ||
        rows < 1 || rows > MAX_SIZE ||
        columns < 1 || columns > MAX_SIZE) {
        fprintf(stderr, "Invalid dimensions. Enter row and column counts from 1 to 100.\n");
        return 1;
    }

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        rowSums[i] = 0;
        for (int j = 0; j < columns; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            if (scanf("%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Invalid input. Please enter integers only.\n");
                return 1;
            }
            rowSums[i] += matrix[i][j];
        }
    }

    printf("Sum of each row:\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d: %lld\n", i + 1, rowSums[i]);
    }

    return 0;
}