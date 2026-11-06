#include <stdio.h>

enum Priority {
    LOW = 10,
    MEDIUM = 11,
    HIGH = 12
};

int main(void)
{
    printf("LOW = %d\n", LOW);
    printf("MEDIUM = %d\n", MEDIUM);
    printf("HIGH = %d\n", HIGH);

    return 0;
}