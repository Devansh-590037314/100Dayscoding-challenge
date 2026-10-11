#include <stdio.h>

int main(void)
{
    double costPrice, sellingPrice, percentage;

    printf("Enter cost price: ");
    if (scanf("%lf", &costPrice) != 1 || costPrice <= 0) {
        printf("Cost price must be a positive number.\n");
        return 1;
    }

    printf("Enter selling price: ");
    if (scanf("%lf", &sellingPrice) != 1 || sellingPrice < 0) {
        printf("Selling price must be a non-negative number.\n");
        return 1;
    }

    if (sellingPrice > costPrice) {
        percentage = ((sellingPrice - costPrice) / costPrice) * 100.0;
        printf("Profit percentage: %.2f%%\n", percentage);
    } else if (sellingPrice < costPrice) {
        percentage = ((costPrice - sellingPrice) / costPrice) * 100.0;
        printf("Loss percentage: %.2f%%\n", percentage);
    } else {
        printf("There is no profit or loss.\n");
    }

    return 0;
}