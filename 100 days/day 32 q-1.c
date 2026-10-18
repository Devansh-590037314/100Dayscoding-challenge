#include <stdio.h>

int main(void)
{
    int n1, n2;

    printf("Enter the size of the first array: ");
    if (scanf("%d", &n1) != 1 || n1 < 0) {
        printf("Invalid size for the first array.\n");
        return 1;
    }

    printf("Enter the size of the second array: ");
    if (scanf("%d", &n2) != 1 || n2 < 0) {
        printf("Invalid size for the second array.\n");
        return 1;
    }

    int first[n1];
    int second[n2];

    printf("Enter %d elements for the first array (sorted order):\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &first[i]);
    }

    printf("Enter %d elements for the second array (sorted order):\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &second[i]);
    }

    int mergedSize = n1 + n2;
    int merged[mergedSize];

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (first[i] <= second[j]) {
            merged[k++] = first[i++];
        } else {
            merged[k++] = second[j++];
        }
    }

    while (i < n1) {
        merged[k++] = first[i++];
    }

    while (j < n2) {
        merged[k++] = second[j++];
    }

    printf("Merged array: ");
    for (int x = 0; x < mergedSize; x++) {
        printf("%d ", merged[x]);
    }
    printf("\n");

    return 0;
}
