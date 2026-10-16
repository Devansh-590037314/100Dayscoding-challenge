#include <stdio.h>

int main(void)
{
    for (int row = 0; row < 5; row++) {
        for (int space = 0; space < row; space++) {
            printf(" ");
        }
        for (int star = 0; star < 5 - row; star++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}