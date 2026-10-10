#include <stdio.h>

int main(void) {
    int day;

    printf("Enter a number from 1 to 7 (1 = Monday): ");
    if (scanf("%d", &day) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid day number. Please enter a number from 1 to 7.\n");
            return 1;
    }

    return 0;
}