#include <stdio.h>

int main(void)
{
    for (int row = 1; row <= 5; row++) {
        for (int space = 0; space < 5 - row; space++) {
            printf(" ");
        }
        for (int number = row; number <= 5; number++) {
            printf("%d", number);
        }
        printf("\n");
    }

    return 0;
}