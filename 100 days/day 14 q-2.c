#include <limits.h>
#include <stdio.h>

int main(void)
{
    long long n;
    long long evenNumber;
    unsigned long long product = 1;

    printf("Enter a non-negative integer: ");
    if (scanf("%lld", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    for (evenNumber = 2; evenNumber <= n; ) {
        if (product > ULLONG_MAX / (unsigned long long)evenNumber) {
            printf("The product is too large to fit in the result type.\n");
            return 1;
        }
        product *= (unsigned long long)evenNumber;

        if (n - evenNumber < 2) {
            break;
        }
        evenNumber += 2;
    }

    printf("Product of even numbers from 1 to %lld: %llu\n", n, product);
    return 0;
}