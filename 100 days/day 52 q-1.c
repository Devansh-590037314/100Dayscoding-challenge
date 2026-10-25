#include <stdio.h>

#define MAX_SIZE 1000

int ceilIndex(const int nums[], int size, int target)
{
    int low = 0;
    int high = size;

    while (low < high) {
        int middle = low + (high - low) / 2;

        if (nums[middle] >= target) {
            high = middle;
        } else {
            low = middle + 1;
        }
    }

    return low < size ? low : -1;
}

int main(void)
{
    int nums[MAX_SIZE];
    int size;
    int target;

    printf("Enter the number of elements (0-%d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 0 || size > MAX_SIZE) {
        fprintf(stderr, "Please enter a valid number of elements.\n");
        return 1;
    }

    printf("Enter the sorted elements: ");
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            fprintf(stderr, "Could not read all array elements.\n");
            return 1;
        }
    }

    printf("Enter the value of x: ");
    if (scanf("%d", &target) != 1) {
        fprintf(stderr, "Could not read x.\n");
        return 1;
    }

    printf("%d\n", ceilIndex(nums, size, target));
    return 0;
}