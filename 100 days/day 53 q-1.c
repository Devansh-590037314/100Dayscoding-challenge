#include <stdio.h>

#define MAX_SIZE 1000

int pivotIndex(const int nums[], int size)
{
    long long totalSum = 0;
    long long leftSum = 0;

    for (int i = 0; i < size; i++) {
        totalSum += nums[i];
    }

    for (int i = 0; i < size; i++) {
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}

int main(void)
{
    int nums[MAX_SIZE];
    int size;

    printf("Enter the number of elements (0-%d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 0 || size > MAX_SIZE) {
        fprintf(stderr, "Please enter a valid number of elements.\n");
        return 1;
    }

    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            fprintf(stderr, "Could not read all array elements.\n");
            return 1;
        }
    }

    printf("%d\n", pivotIndex(nums, size));
    return 0;
}