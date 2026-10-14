#include <stdio.h>

int main(void)
{
    long long number;
    int sum = 0;

    printf("Enter an integer: ");
    if (scanf("%lld", &number) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    while (number != 0)
    {
        int digit = (int)(number % 10);
        if (digit < 0)
        {
            digit = -digit;
        }
        sum += digit;
        number /= 10;
    }

    printf("Sum of digits: %d\n", sum);
    return 0;
}