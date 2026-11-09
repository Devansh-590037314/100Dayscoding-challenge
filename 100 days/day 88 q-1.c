#include <stdio.h>

enum Color {
    RED = 1,
    GREEN,
    BLUE
};

int main(void)
{
    const char *names[] = {"RED", "GREEN", "BLUE"};
    enum Color values[] = {RED, GREEN, BLUE};
    size_t count = sizeof(values) / sizeof(values[0]);

    for (size_t i = 0; i < count; i++) {
        printf("%s = %d\n", names[i], values[i]);
    }

    return 0;
}