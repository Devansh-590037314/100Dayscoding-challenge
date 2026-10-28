#include <stdio.h>

#define MAX_SIZE 1000

int main(void)
{
    int arr[MAX_SIZE];
    int size;

    printf("Enter the number of elements (1-%d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE) {
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

    long long currentSum = arr[0];
    long long maximumSum = arr[0];

    for (int i = 1; i < size; i++) {
        if (currentSum < 0) {
            currentSum = arr[i];
        } else {
            currentSum += arr[i];
        }

        if (currentSum > maximumSum) {
            maximumSum = currentSum;
        }
    }

    printf("Maximum subarray sum: %lld\n", maximumSum);
    return 0;
}