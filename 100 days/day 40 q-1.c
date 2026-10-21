#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int matrix[MAX_SIZE][MAX_SIZE];
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
        for (int j = 0; j < columns; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            if (scanf("%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Invalid input. Please enter integers only.\n");
                return 1;
            }
        }
    }

    printf("Diagonal traversal:\n");
    for (int diagonal = 0; diagonal < rows + columns - 1; diagonal++) {
        int firstRow = diagonal - (columns - 1);
        int lastRow = diagonal;

        if (firstRow < 0) {
            firstRow = 0;
        }
        if (lastRow >= rows) {
            lastRow = rows - 1;
        }

        if (diagonal % 2 == 0) {
            for (int row = lastRow; row >= firstRow; row--) {
                int column = diagonal - row;
                printf("%d ", matrix[row][column]);
            }
        } else {
            for (int row = firstRow; row <= lastRow; row++) {
                int column = diagonal - row;
                printf("%d ", matrix[row][column]);
            }
        }
    }
    printf("\n");

    return 0;
}