#include <stdio.h>

int main(void)
{
    int array[100];
    int n;
    int largest = 0;
    int secondLargest = 0;
    int hasLargest = 0;
    int hasSecondLargest = 0;

    printf("Enter the number of elements (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        fprintf(stderr, "Invalid size. Enter an integer from 1 to 100.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        if (scanf("%d", &array[i]) != 1) {
            fprintf(stderr, "Invalid input. Please enter integers.\n");
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!hasLargest || array[i] > largest) {
            if (hasLargest) {
                secondLargest = largest;
                hasSecondLargest = 1;
            }
            largest = array[i];
            hasLargest = 1;
        } else if (array[i] < largest &&
                   (!hasSecondLargest || array[i] > secondLargest)) {
            secondLargest = array[i];
            hasSecondLargest = 1;
        }
    }

    if (hasSecondLargest) {
        printf("The second largest distinct element is %d.\n", secondLargest);
    } else {
        printf("There is no second largest distinct element.\n");
    }

    return 0;
}