#include <stdio.h>

#define MAX_SIZE 1000

void printPreviousGreaterElements(const int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        int previousGreater = -1;

        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[i]) {
                previousGreater = arr[j];
                break;
            }
        }

        if (i > 0) {
            printf(", ");
        }
        printf("%d", previousGreater);
    }
    printf("\n");
}

int main(void)
{
    int arr[MAX_SIZE];
    int size;

    printf("Enter the number of elements (0-%d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 0 || size > MAX_SIZE) {
        fprintf(stderr, "Please enter a valid number of elements.\n");
        return 1;
    }

    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Could not read all array elements.\n");
            return 1;
        }
    }

    printPreviousGreaterElements(arr, size);
    return 0;
}