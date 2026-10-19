#include <stdio.h>

int main(void)
{
    int array[100];
    int n;
    int position;

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

    printf("Enter the position to delete (1-%d): ", n);
    if (scanf("%d", &position) != 1 || position < 1 || position > n) {
        fprintf(stderr, "Invalid position. Enter a position from 1 to %d.\n", n);
        return 1;
    }

    int index = position - 1;
    for (int i = index; i < n - 1; i++) {
        array[i] = array[i + 1];
    }
    n--;

    printf("Updated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d%s", array[i], i == n - 1 ? "\n" : " ");
    }
    if (n == 0) {
        printf("(empty)\n");
    }

    return 0;
}