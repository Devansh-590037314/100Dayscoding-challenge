#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid array size.\n");
        return 1;
    }

    int *nums = malloc((size_t)n * sizeof(*nums));
    if (nums == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            fprintf(stderr, "Invalid array element.\n");
            free(nums);
            return 1;
        }
    }

    int target;
    if (scanf("%d", &target) != 1) {
        fprintf(stderr, "Invalid target.\n");
        free(nums);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((long long)nums[i] + nums[j] == target) {
                printf("%d %d\n", i, j);
                free(nums);
                return 0;
            }
        }
    }

    printf("-1 -1\n");
    free(nums);
    return 0;
}