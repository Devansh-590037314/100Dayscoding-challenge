#include <stdio.h>
#include <limits.h>

int main(void)
{
    long long number;
    unsigned long long factorial = 1;

    printf("Enter a non-negative integer: ");
    if (scanf("%lld", &number) != 1 || number < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    for (long long i = 2; i <= number; ++i) {
        if (factorial > ULLONG_MAX / (unsigned long long)i) {
            printf("The factorial is too large to represent.\n");
            return 1;
        }
        factorial *= (unsigned long long)i;
    }

    printf("%lld! = %llu\n", number, factorial);
    return 0;
}