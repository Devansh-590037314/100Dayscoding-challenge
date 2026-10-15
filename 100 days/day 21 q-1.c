#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char number[1024];
    size_t length;
    size_t first_digit;
    size_t last_digit;
    char temp;
    int is_negative;
    int next_char;

    printf("Enter an integer: ");
    if (scanf("%1023s", number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    length = strlen(number);
    next_char = getchar();
    if (length == sizeof(number) - 1 &&
        next_char != EOF &&
        !isspace((unsigned char)next_char)) {
        printf("Invalid input. The number is too long.\n");
        return 1;
    }

    is_negative = number[0] == '-';
    first_digit = (number[0] == '-' || number[0] == '+') ? 1 : 0;
    if (first_digit == length) {
        printf("Invalid input.\n");
        return 1;
    }

    for (size_t i = first_digit; i < length; i++) {
        if (!isdigit((unsigned char)number[i])) {
            printf("Invalid input. Enter an integer.\n");
            return 1;
        }
    }

    while (first_digit < length - 1 && number[first_digit] == '0') {
        first_digit++;
    }

    if (number[first_digit] == '0') {
        printf("Result: 0\n");
        return 0;
    }

    last_digit = length - 1;
    temp = number[first_digit];
    number[first_digit] = number[last_digit];
    number[last_digit] = temp;

    printf("Result: ");
    if (is_negative) {
        putchar('-');
    }
    printf("%s\n", number + first_digit);
    return 0;
}