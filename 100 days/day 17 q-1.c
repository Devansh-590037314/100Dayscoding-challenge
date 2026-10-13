#include <stdio.h>

long long integerPower(int base, int exponent)
{
    long long result = 1;

    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

int main(void)
{
    int number;

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (number < 0) {
        printf("%d is not an Armstrong number.\n", number);
        return 0;
    }

    int originalNumber = number;
    int temporaryNumber = number;
    int digitCount = 0;
    long long sum = 0;

    do {
        digitCount++;
        temporaryNumber /= 10;
    } while (temporaryNumber != 0);

    temporaryNumber = number;
    do {
        int digit = temporaryNumber % 10;
        sum += integerPower(digit, digitCount);
        temporaryNumber /= 10;
    } while (temporaryNumber != 0);

    if (sum == originalNumber) {
        printf("%d is an Armstrong number.\n", originalNumber);
    } else {
        printf("%d is not an Armstrong number.\n", originalNumber);
    }

    return 0;
}