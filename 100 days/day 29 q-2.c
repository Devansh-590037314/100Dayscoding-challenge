#include <stdio.h>

int main(void)
{
    int array[100];
    int n;

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
    }

    int minimum = array[0];
    int maximum = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] < minimum) {
            minimum = array[i];
        }
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }

    printf("Minimum element: %d\n", minimum);
    printf("Maximum element: %d\n", maximum);

    return 0;
}