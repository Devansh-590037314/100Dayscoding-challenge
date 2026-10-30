#include <stdio.h>

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Invalid array size.\n");
        return 1;
    }

    long long expected_sum = (long long)n * (n + 1) / 2;
    long long actual_sum = 0;

    for (int i = 0; i < n; i++) {
        int value;

        if (scanf("%d", &value) != 1 || value < 0 || value > n) {
            fprintf(stderr, "Invalid array element.\n");
            return 1;
        }

        actual_sum += value;
    }

    printf("Missing number: %lld\n", expected_sum - actual_sum);
    return 0;
}