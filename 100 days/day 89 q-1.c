#include <stdio.h>

enum Color {
    RED = 1,
    GREEN,
    BLUE
};

int main(void)
{
    printf("RED = %d\n", RED);
    printf("GREEN = %d\n", GREEN);
    printf("BLUE = %d\n", BLUE);

    return 0;
}