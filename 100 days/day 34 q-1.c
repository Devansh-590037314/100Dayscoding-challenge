#include <stdio.h>

int main(void)
{
    int array[100];
    int n;
    int value;
    int position;

    printf("Enter the number of elements (0-99): ");
    if (scanf("%d", &n) != 1 || n < 0 || n >= 100) {
        fprintf(stderr, "Invalid size. Enter an integer from 0 to 99.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        if (scanf("%d", &array[i]) != 1) {
            fprintf(stderr, "Invalid input. Please enter integers.\n");
            return 1;
        }
    }

    printf("Enter the element to insert: ");
    if (scanf("%d", &value) != 1) {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        return 1;
    }

    printf("Enter the position to insert at (1-%d): ", n + 1);
    if (scanf("%d", &position) != 1 || position < 1 || position > n + 1) {
        fprintf(stderr, "Invalid position. Enter a position from 1 to %d.\n", n + 1);
        return 1;
    }

    int index = position - 1;
    for (int i = n; i > index; i--) {
        array[i] = array[i - 1];
    }
    array[index] = value;
    n++;

    printf("Updated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d%s", array[i], i == n - 1 ? "\n" : " ");
    }

    return 0;
}