#include <stdio.h>

int main(void)
{
    long long number;
    long long product = 1;
    int found_odd_digit = 0;

    printf("Enter an integer: ");
    if (scanf("%lld", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    while (number != 0) {
        int digit = (int)(number % 10);
        if (digit < 0) {
            digit = -digit;
        }

        if (digit % 2 != 0) {
            product *= digit;
            found_odd_digit = 1;
        }

        number /= 10;
    }

    if (!found_odd_digit) {
        product = 0;
    }

    printf("Product of odd digits: %lld\n", product);
    return 0;
}