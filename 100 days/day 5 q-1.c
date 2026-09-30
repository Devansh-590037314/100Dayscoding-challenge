#include <stdio.h>
#include <math.h>

int main(void)
{
    double principal, rate, time;
    double simpleInterest, compoundInterest;

    printf("Enter principal, annual rate (%%), and time (years): ");
    if (scanf("%lf %lf %lf", &principal, &rate, &time) != 3) {
        printf("Invalid input.\n");
        return 1;
    }

    simpleInterest = principal * rate * time / 100.0;
    compoundInterest = principal * pow(1.0 + rate / 100.0, time) - principal;

    printf("Simple interest: %.2f\n", simpleInterest);
    printf("Compound interest (compounded annually): %.2f\n", compoundInterest);

    return 0;
}