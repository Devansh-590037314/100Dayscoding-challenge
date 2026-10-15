#include <stdio.h>

int main(void)
{
    for (int row = 0; row < 5; row++) {
        for (int column = 0; column < 5; column++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}