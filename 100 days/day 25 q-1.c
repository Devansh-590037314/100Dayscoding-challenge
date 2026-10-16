#include <stdio.h>

int main(void)
{
    for (int row = 1; row <= 5; row++) {
        for (int number = 6 - row; number <= 5; number++) {
            printf("%d", number);
        }
        printf("\n");
    }

    return 0;
}