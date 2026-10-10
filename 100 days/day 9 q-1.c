#include <math.h>
#include <stdio.h>

int main(void) {
    double a, b, c;
    double discriminant;

    printf("Enter the coefficients a, b, and c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Invalid input. Please enter three numbers.\n");
        return 1;
    }

    if (a == 0.0) {
        printf("The coefficient a must not be zero for a quadratic equation.\n");
        return 1;
    }

    discriminant = b * b - 4.0 * a * c;

    if (discriminant > 0.0) {
        double root1 = (-b + sqrt(discriminant)) / (2.0 * a);
        double root2 = (-b - sqrt(discriminant)) / (2.0 * a);

        printf("The equation has two distinct real roots: %.6g and %.6g\n",
               root1, root2);
    } else if (discriminant == 0.0) {
        double root = -b / (2.0 * a);

        printf("The equation has one repeated real root: %.6g\n", root);
    } else {
        double realPart = -b / (2.0 * a);
        double imaginaryPart = sqrt(-discriminant) / fabs(2.0 * a);

        printf("The equation has two complex conjugate roots: "
               "%.6g + %.6gi and %.6g - %.6gi\n",
               realPart, imaginaryPart, realPart, imaginaryPart);
    }

    return 0;
}