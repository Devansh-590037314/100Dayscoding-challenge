#include <stdio.h>

int factorial(int digit)
{
    int result = 1;
    int factor;

    for (factor = 2; factor <= digit; factor++)
    {
        result *= factor;
    }

    return result;
}

int main(void)
{
    long long number;
    long long original;
    long long sum = 0;
    int digit;

    printf("Enter a non-negative integer: ");
    if (scanf("%lld", &number) != 1 || number < 0)
    {
        printf("Invalid input. Enter a non-negative integer.\n");
        return 1;
    }

    original = number;
    do
    {
        digit = (int)(number % 10);
        sum += factorial(digit);
        number /= 10;
    } while (number > 0);

    if (sum == original)
    {
        printf("%lld is a strong number.\n", original);
    }
    else
    {
        printf("%lld is not a strong number.\n", original);
    }

    return 0;
}