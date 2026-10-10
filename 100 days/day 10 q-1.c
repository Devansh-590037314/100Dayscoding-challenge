#include <stdio.h>

int main(void) {
    double side1, side2, side3;

    printf("Enter the three side lengths: ");
    if (scanf("%lf %lf %lf", &side1, &side2, &side3) != 3) {
        printf("Invalid input. Please enter three numbers.\n");
        return 1;
    }

    if (side1 <= 0.0 || side2 <= 0.0 || side3 <= 0.0) {
        printf("Side lengths must be greater than zero.\n");
        return 1;
    }

    if (side1 + side2 <= side3 ||
        side1 + side3 <= side2 ||
        side2 + side3 <= side1) {
        printf("The side lengths do not form a valid triangle.\n");
        return 1;
    }

    if (side1 == side2 && side2 == side3)
        printf("Equilateral triangle\n");
    else if (side1 == side2 || side1 == side3 || side2 == side3)
        printf("Isosceles triangle\n");
    else
        printf("Scalene triangle\n");

    return 0;
}