#include <stdio.h>

int main(void)
{
    const double pi = 3.14159265358979323846;
    double radius;

    printf("Enter the radius of the circle: ");
    if (scanf("%lf", &radius) != 1 || radius < 0.0) {
        printf("Invalid radius. Enter a non-negative number.\n");
        return 1;
    }

    printf("Area: %.2f\n", pi * radius * radius);
    printf("Circumference: %.2f\n", 2.0 * pi * radius);

    return 0;
}