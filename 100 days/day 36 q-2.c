#include <stdio.h>

int main(void)
{
    int matrix[10][10];
    int rows, columns;
    long long sum = 0;

    printf("Enter the number of rows and columns (1-10): ");
    if (scanf("%d %d", &rows, &columns) != 2 ||
        rows < 1 || rows > 10 || columns < 1 || columns > 10)
    {
        printf("Invalid matrix dimensions.\n");
        return 1;
    }

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                printf("Invalid matrix element.\n");
                return 1;
            }
            sum += matrix[i][j];
        }
    }

    printf("Sum of all matrix elements: %lld\n", sum);
    return 0;
}