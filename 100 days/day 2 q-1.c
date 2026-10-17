#include <stdio.h>

int main(void)
{
    double length, breadth;

    printf("Enter the length and breadth of the rectangle: ");
    if (scanf("%lf %lf", &length, &breadth) != 2 ||
        length < 0.0 || breadth < 0.0) {
        fprintf(stderr, "Invalid input. Enter non-negative numbers.\n");
        return 1;
    }

    printf("Area: %.2f\n", length * breadth);
    printf("Perimeter: %.2f\n", 2.0 * (length + breadth));

    return 0;
}