#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n < 1) {
        printf("Please enter a number greater than 0.\n");
        return 1;
    }

    for (int number = 1; number <= n; number++) {
        printf("%d", number);
        if (number < n) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}