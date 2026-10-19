#include <stdio.h>

int main(void)
{
    int arr[100], rotated[100];
    int n, k;

    printf("Enter the number of elements (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
        fprintf(stderr, "Invalid size. Enter an integer from 1 to 100.\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    printf("Enter the rotation count k: ");
    if (scanf("%d", &k) != 1) {
        fprintf(stderr, "Invalid rotation count.\n");
        return 1;
    }

    k %= n;

    for (int i = 0; i < n; i++) {
        rotated[(i + k) % n] = arr[i];
    }

    printf("Rotated array to the right by %d positions: ", k);
    for (int i = 0; i < n; i++) {
        printf("%d ", rotated[i]);
    }
    printf("\n");

    return 0;
}
