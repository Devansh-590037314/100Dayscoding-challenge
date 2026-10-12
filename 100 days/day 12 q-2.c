#include <stdio.h>

int main(void)
{
    long long units;
    long long bill;

    printf("Enter total units consumed: ");
    if (scanf("%lld", &units) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (units < 0) {
        printf("Units cannot be negative.\n");
        return 1;
    }

    if (units <= 100) {
        bill = units * 5;
    } else if (units <= 200) {
        bill = 100 * 5 + (units - 100) * 7;
    } else if (units <= 300) {
        bill = 100 * 5 + 100 * 7 + (units - 200) * 10;
    } else {
        bill = 100 * 5 + 100 * 7 + 100 * 10 + (units - 300) * 12;
    }

    printf("Electricity bill: Rs. %lld\n", bill);
    return 0;
}