#include <stdio.h>

int main(void) {
    int first, second, third;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &first, &second, &third);

    if (first >= second && first >= third)
        printf("Largest number: %d\n", first);
    else if (second >= first && second >= third)
        printf("Largest number: %d\n", second);
    else
        printf("Largest number: %d\n", third);

    return 0;
}