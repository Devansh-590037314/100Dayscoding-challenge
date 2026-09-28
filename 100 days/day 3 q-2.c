#include <stdio.h>

int main(void) {
    int first, second, temp;

    printf("Enter two numbers: ");
    scanf("%d %d", &first, &second);

    temp = first;
    first = second;
    second = temp;

    printf("After swapping: first = %d, second = %d\n", first, second);
    return 0;
}