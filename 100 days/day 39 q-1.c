#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;
    int areDiagonalElementsDistinct = 1;

    printf("Enter the order of the square matrix (1-100): ");
    if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE) {
        fprintf(stderr, "Invalid size. Enter an integer from 1 to 100.\n");
        return 1;
    }

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            if (scanf("%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Invalid input. Please enter integers only.\n");
                return 1;
            }
        }
    }

    for (int i = 0; i < size && areDiagonalElementsDistinct; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][i] == matrix[j][j]) {
                areDiagonalElementsDistinct = 0;
                break;
            }
        }
    }

    if (areDiagonalElementsDistinct) {
        printf("The main diagonal elements are distinct.\n");
    } else {
        printf("The main diagonal elements are not distinct.\n");
    }

    return 0;
}