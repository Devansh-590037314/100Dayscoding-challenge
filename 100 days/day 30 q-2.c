#include <stdio.h>

int main(void)
{
    int array[100];
    int n;
    int positiveCount = 0;
    int negativeCount = 0;
    int zeroCount = 0;

    printf("Enter the number of elements (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        fprintf(stderr, "Invalid size. Enter an integer from 1 to 100.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        if (scanf("%d", &array[i]) != 1) {
            fprintf(stderr, "Invalid input. Please enter integers.\n");
            return 1;
        }

        if (array[i] > 0) {
            positiveCount++;
        } else if (array[i] < 0) {
            negativeCount++;
        } else {
            zeroCount++;
        }
    }

    printf("Positive numbers: %d\n", positiveCount);
    printf("Negative numbers: %d\n", negativeCount);
    printf("Zero elements: %d\n", zeroCount);

    return 0;
}