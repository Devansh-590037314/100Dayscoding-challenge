#include <stdio.h>

int main(void) {
    int n;
    long long sum;

    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    sum = (long long)n * (n + 1) / 2;
    printf("Sum of the first %d natural numbers = %lld\n", n, sum);

    return 0;
}