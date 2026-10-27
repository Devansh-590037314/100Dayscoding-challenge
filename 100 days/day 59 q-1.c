#include <stdio.h>

#define MAX_SIZE 1000

long long maxSubarraySumOfSizeK(const int arr[], int size, int k)
{
    long long windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    long long maxSum = windowSum;
    for (int i = k; i < size; i++) {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }

    return maxSum;
}

int main(void)
{
    int arr[MAX_SIZE];
    int size;
    int k;

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

    printf("Enter the subarray size k (1-%d): ", size);
    if (scanf("%d", &k) != 1 || k < 1 || k > size) {
        fprintf(stderr, "Please enter a valid subarray size.\n");
        return 1;
    }

    printf("Maximum sum of a subarray of size %d: %lld\n",
           k, maxSubarraySumOfSizeK(arr, size, k));
    return 0;
}