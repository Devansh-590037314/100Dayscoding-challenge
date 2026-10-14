#include <stdio.h>

int main(void)
{
    int first, second;

    printf("Enter two positive integers: ");
    if (scanf("%d %d", &first, &second) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    if (first <= 0 || second <= 0) {
        printf("Please enter positive integers.\n");
        return 1;
    }

    int a = first;
    int b = second;
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }

    printf("HCF of %d and %d is %d.\n", first, second, a);
    return 0;
}