#include <stdio.h>

int main(void)
{
    long long firstNumber;
    long long secondNumber;
    char operator;

    printf("Enter an expression (e.g., 10 + 5): ");
    if (scanf("%lld %c %lld", &firstNumber, &operator, &secondNumber) != 3) {
        printf("Invalid input.\n");
        return 1;
    }

    switch (operator) {
        case '+':
            printf("Result: %lld\n", firstNumber + secondNumber);
            break;
        case '-':
            printf("Result: %lld\n", firstNumber - secondNumber);
            break;
        case '*':
            printf("Result: %lld\n", firstNumber * secondNumber);
            break;
        case '/':
            if (secondNumber == 0) {
                printf("Error: division by zero.\n");
                return 1;
            }
            printf("Result: %lld\n", firstNumber / secondNumber);
            break;
        case '%':
            if (secondNumber == 0) {
                printf("Error: modulo by zero.\n");
                return 1;
            }
            printf("Result: %lld\n", firstNumber % secondNumber);
            break;
        default:
            printf("Invalid operator. Use +, -, *, /, or %%.\n");
            return 1;
    }

    return 0;
}