#include <stdio.h>

int main(void)
{
    int days;
    int fine = 0;

    printf("Enter number of days late: ");
    if (scanf("%d", &days) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (days < 0) {
        printf("Days cannot be negative.\n");
        return 1;
    }

    if (days <= 5) {
        fine = days * 2;
        printf("Library fine: Rs. %d\n", fine);
    } else if (days <= 10) {
        fine = 5 * 2 + (days - 5) * 4;
        printf("Library fine: Rs. %d\n", fine);
    } else if (days <= 30) {
        fine = 5 * 2 + 5 * 4 + (days - 10) * 6;
        printf("Library fine: Rs. %d\n", fine);
    } else {
        printf("Membership Cancelled.\n");
    }

    return 0;
}
