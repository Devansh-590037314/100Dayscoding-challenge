#include <stdio.h>

int main(void)
{
    long long n;
    long long sum;

    printf("Enter the number of odd numbers: ");
    if (scanf("%lld", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    sum = n * n;
    printf("Sum of the first %lld odd numbers: %lld\n", n, sum);

    return 0;
}