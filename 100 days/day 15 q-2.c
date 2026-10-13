#include <stdio.h>

int main(void)
{
    int number;
    long long reversed = 0;

    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    while (number != 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }

    printf("Reversed number: %lld\n", reversed);
    return 0;
}