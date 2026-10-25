#include <stdio.h>

#define MAX_SIZE 1000

int firstOccurrence(const int nums[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    int result = -1;

    while (low <= high) {
        int middle = low + (high - low) / 2;

        if (nums[middle] >= target) {
            if (nums[middle] == target) {
                result = middle;
            }
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }

    return result;
}

int lastOccurrence(const int nums[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    int result = -1;

    while (low <= high) {
        int middle = low + (high - low) / 2;

        if (nums[middle] <= target) {
            if (nums[middle] == target) {
                result = middle;
            }
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }

    return result;
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

    printf("Enter the target: ");
    if (scanf("%d", &target) != 1) {
        fprintf(stderr, "Could not read the target.\n");
        return 1;
    }

    int first = firstOccurrence(nums, size, target);
    int last = lastOccurrence(nums, size, target);

    if (first == -1) {
        printf("Target not found. First and last indices: -1, -1\n");
    } else {
        printf("First occurrence: %d at index %d\n", target, first);
        printf("Last occurrence: %d at index %d\n", target, last);
    }

    return 0;
}