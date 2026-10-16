#include <stdio.h>

int main(void)
{
    int stars[] = {1, 3, 5, 3, 1};

    for (int row = 0; row < 5; row++) {
        for (int star = 0; star < stars[row]; star++) {
            printf("*\n");
        }
        if (row < 4) {
            printf("\n");
        }
    }

    return 0;
}