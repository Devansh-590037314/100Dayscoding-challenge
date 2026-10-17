#include <stdio.h>

int main(void)
{
    double first, second;

    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &first, &second) != 2) {
        fprintf(stderr, "Invalid input. Please enter two numbers.\n");
        return 1;
    }

    printf("Sum: %.2f\n", first + second);
    printf("Difference: %.2f\n", first - second);
    printf("Product: %.2f\n", first * second);

    if (second == 0.0) {
        printf("Quotient: undefined (division by zero)\n");
    } else {
        printf("Quotient: %.2f\n", first / second);
    }

    return 0;
}