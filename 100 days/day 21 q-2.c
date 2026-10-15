#include <stdio.h>

int main(void)
{
    int number;
    int divisor;
    long long sum = 1;

    printf("Enter a positive integer: ");
    if (scanf("%d", &number) != 1 || number <= 0)
    {
        printf("Invalid input. Enter a positive integer.\n");
        return 1;
    }

    if (number == 1)
    {
        sum = 0;
    }
    else
    {
        for (divisor = 2; divisor <= number / divisor; divisor++)
        {
            if (number % divisor == 0)
            {
                sum += divisor;
                if (divisor != number / divisor)
                {
                    sum += number / divisor;
                }
            }
        }
    }

    if (sum == number)
    {
        printf("%d is a perfect number.\n", number);
    }
    else
    {
        printf("%d is not a perfect number.\n", number);
    }

    return 0;
}