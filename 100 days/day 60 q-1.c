#include <stdio.h>

#define MAX_SIZE 1000

void printWindowMaximums(const int arr[], int size, int k)
{
    int deque[MAX_SIZE];
    int front = 0;
    int back = 0;

    for (int i = 0; i < size; i++) {
        while (front < back && deque[front] <= i - k) {
            front++;
        }

        while (front < back && arr[deque[back - 1]] <= arr[i]) {
            back--;
        }

        deque[back++] = i;

        if (i >= k - 1) {
            if (i > k - 1) {
                printf(" ");
            }
            printf("%d", arr[deque[front]]);
        }
    }

    printf("\n");
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

    printWindowMaximums(arr, size, k);
    return 0;
}