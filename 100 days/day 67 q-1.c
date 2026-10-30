#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int m;
    int n;

    if (scanf("%d %d", &m, &n) != 2 || m < 0 || n < 0 || m > INT_MAX - n) {
        fprintf(stderr, "Invalid array sizes.\n");
        return 1;
    }

    int *first = m > 0 ? malloc((size_t)m * sizeof(*first)) : NULL;
    int *second = n > 0 ? malloc((size_t)n * sizeof(*second)) : NULL;
    int *merged = m + n > 0 ? malloc((size_t)(m + n) * sizeof(*merged)) : NULL;

    if ((m > 0 && first == NULL) ||
        (n > 0 && second == NULL) ||
        (m + n > 0 && merged == NULL)) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(first);
        free(second);
        free(merged);
        return 1;
    }

    for (int i = 0; i < m; i++) {
        if (scanf("%d", &first[i]) != 1) {
            fprintf(stderr, "Invalid array element.\n");
            free(first);
            free(second);
            free(merged);
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &second[i]) != 1) {
            fprintf(stderr, "Invalid array element.\n");
            free(first);
            free(second);
            free(merged);
            return 1;
        }
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < m && j < n) {
        if (first[i] <= second[j]) {
            merged[k++] = first[i++];
        } else {
            merged[k++] = second[j++];
        }
    }

    while (i < m) {
        merged[k++] = first[i++];
    }

    while (j < n) {
        merged[k++] = second[j++];
    }

    for (int index = 0; index < m + n; index++) {
        if (index > 0) {
            printf(" ");
        }
        printf("%d", merged[index]);
    }
    printf("\n");

    free(first);
    free(second);
    free(merged);
    return 0;
}