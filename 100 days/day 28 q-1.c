#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        return 1;
    }

    printf("Prime numbers from 1 to %d are:\n", n);
    for (int number = 2; number <= n; number++) {
        int is_prime = 1;

        for (int divisor = 2; divisor <= number / divisor; divisor++) {
            if (number % divisor == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime) {
            printf("%d ", number);
        }
    }
    printf("\n");

    return 0;
}