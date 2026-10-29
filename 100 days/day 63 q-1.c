#include <stdio.h>
#include <stdlib.h>

static int compare_ints(const void *left, const void *right)
{
    int a = *(const int *)left;
    int b = *(const int *)right;

    return (a > b) - (a < b);
}

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid array size.\n");
        return 1;
    }

    int *arr = malloc((size_t)n * sizeof(*arr));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid array element.\n");
            free(arr);
            return 1;
        }
    }

    int k;
    if (scanf("%d", &k) != 1 || k < 1 || k > n) {
        fprintf(stderr, "k must be between 1 and the array size.\n");
        free(arr);
        return 1;
    }

    qsort(arr, (size_t)n, sizeof(*arr), compare_ints);
    printf("%d\n", arr[k - 1]);

    free(arr);
    return 0;
}