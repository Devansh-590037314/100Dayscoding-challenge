#include <stdio.h>

#define MAX_SIZE 1000

void productExceptSelf(const int nums[], int answer[], int size)
{
    int prefixProduct = 1;

    for (int i = 0; i < size; i++) {
        answer[i] = prefixProduct;
        prefixProduct *= nums[i];
    }

    int suffixProduct = 1;
    for (int i = size - 1; i >= 0; i--) {
        answer[i] *= suffixProduct;
        suffixProduct *= nums[i];
    }
}

int main(void)
{
    int nums[MAX_SIZE];
    int answer[MAX_SIZE];
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

    productExceptSelf(nums, answer, size);

    printf("[");
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", answer[i]);
    }
    printf("]\n");

    return 0;
}