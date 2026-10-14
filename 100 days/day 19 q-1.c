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

    long long lcm = (long long)(first / a) * second;
    printf("LCM of %d and %d is %lld.\n", first, second, lcm);

    return 0;
}