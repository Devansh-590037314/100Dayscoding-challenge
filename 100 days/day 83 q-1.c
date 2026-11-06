#include <stdio.h>

enum Month {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

int main(void)
{
    const char *month_names[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    const int days_in_month[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    for (enum Month month = JANUARY; month <= DECEMBER; month++) {
        printf("%s: %d days", month_names[month], days_in_month[month]);
        if (month == FEBRUARY) {
            printf(" (29 in a leap year)");
        }
        printf("\n");
    }

    return 0;
}