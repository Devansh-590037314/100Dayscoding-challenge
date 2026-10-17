#include <stdio.h>

int main(void)
{
    for (int row = 1; row <= 7; row++) {
        int stars = row <= 4 ? 2 * row - 1 : 2 * (8 - row) - 1;
        int spaces = (7 - stars) / 2;

        for (int space = 0; space < spaces; space++) {
            printf(" ");
        }
        for (int star = 0; star < stars; star++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}