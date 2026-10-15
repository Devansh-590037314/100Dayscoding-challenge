#include <stdio.h>

int main(void)
{
    int n;
    double sum = 0.0;

    printf("Enter the number of terms: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            sum += 1.0;
        } else {
            sum += (double)(2 * i - 1) / (2 * i);
        }
    }

    printf("Sum of the series = %.6f\n", sum);
    return 0;
}