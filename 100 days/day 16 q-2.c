#include <stdio.h>

int main(void)
{
    long long input;
    unsigned long long number;
    unsigned long long original;
    unsigned long long reversed = 0;

    printf("Enter an integer: ");
    if (scanf("%lld", &input) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (input < 0) {
        printf("%lld is not a palindrome.\n", input);
        return 0;
    }

    number = (unsigned long long)input;
    original = number;

    while (number > 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }

    if (original == reversed) {
        printf("%lld is a palindrome.\n", input);
    } else {
        printf("%lld is not a palindrome.\n", input);
    }

    return 0;
}