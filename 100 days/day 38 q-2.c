#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;
    int isSymmetric = 1;

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

    for (int i = 0; i < size && isSymmetric; i++) {
        for (int j = i + 1; j < size; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
    }

    if (isSymmetric) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }

    return 0;
}