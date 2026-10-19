#include <stdio.h>

int main(void)
{
    int array[100];
    int n;
    int value;

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
        if (i > 0 && array[i] < array[i - 1]) {
            fprintf(stderr, "Invalid input. Enter the elements in sorted order.\n");
            return 1;
        }
    }

    printf("Enter the element to insert: ");
    if (scanf("%d", &value) != 1) {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        return 1;
    }

    int index = n;
    while (index > 0 && array[index - 1] > value) {
        array[index] = array[index - 1];
        index--;
    }
    array[index] = value;
    n++;

    printf("Element inserted at position %d.\n", index + 1);
    printf("Updated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d%s", array[i], i == n - 1 ? "\n" : " ");
    }

    return 0;
}