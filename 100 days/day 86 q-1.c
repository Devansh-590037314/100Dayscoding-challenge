#include <stdio.h>

enum MenuChoice {
    ADD = 1,
    SUBTRACT,
    MULTIPLY
};

int main(void)
{
    enum MenuChoice choice;
    double firstNumber;
    double secondNumber;

    printf("Choose an operation:\n");
    printf("%d. Add\n", ADD);
    printf("%d. Subtract\n", SUBTRACT);
    printf("%d. Multiply\n", MULTIPLY);
    printf("Enter your choice: ");

    if (scanf("%d", (int *)&choice) != 1) {
        fprintf(stderr, "Invalid choice.\n");
        return 1;
    }

    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &firstNumber, &secondNumber) != 2) {
        fprintf(stderr, "Invalid numbers.\n");
        return 1;
    }

    switch (choice) {
        case ADD:
            printf("Result: %g\n", firstNumber + secondNumber);
            break;
        case SUBTRACT:
            printf("Result: %g\n", firstNumber - secondNumber);
            break;
        case MULTIPLY:
            printf("Result: %g\n", firstNumber * secondNumber);
            break;
        default:
            fprintf(stderr, "Invalid choice. Choose 1, 2, or 3.\n");
            return 1;
    }

    return 0;
}