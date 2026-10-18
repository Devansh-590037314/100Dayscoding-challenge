#include <stdio.h>

int main(void)
{
    int array[100];
    int n;
    int searchValue;
    int foundIndex = -1;

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

    printf("Enter the element to search for: ");
    if (scanf("%d", &searchValue) != 1) {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (array[i] == searchValue) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("%d found at position %d.\n", searchValue, foundIndex + 1);
    } else {
        printf("%d was not found in the array.\n", searchValue);
    }

    return 0;
}