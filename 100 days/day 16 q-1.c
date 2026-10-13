#include <limits.h>
#include <stdio.h>

int main(void)
{
    long long number;
    unsigned long long value;
    char binary[sizeof(unsigned long long) * CHAR_BIT];
    int bit_count = 0;

    printf("Enter an integer: ");
    if (scanf("%lld", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Binary representation: ");
    if (number < 0) {
        printf("-");
        value = (unsigned long long)(-(number + 1)) + 1;
    } else {
        value = (unsigned long long)number;
    }

    if (value == 0) {
        printf("0\n");
        return 0;
    }

    while (value > 0) {
        binary[bit_count++] = (char)('0' + value % 2);
        value /= 2;
    }

    while (bit_count > 0) {
        printf("%c", binary[--bit_count]);
    }
    printf("\n");

    return 0;
}