#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    size_t capacity = 128;
    size_t length = 0;
    char *s = malloc(capacity);
    int ch;

    if (s == NULL) {
        fprintf(stderr, "Unable to allocate memory.\n");
        return 1;
    }

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (length + 1 >= capacity) {
            if (capacity > SIZE_MAX / 2) {
                fprintf(stderr, "Input is too large.\n");
                free(s);
                return 1;
            }

            capacity *= 2;
            char *new_s = realloc(s, capacity);
            if (new_s == NULL) {
                fprintf(stderr, "Unable to allocate memory.\n");
                free(s);
                return 1;
            }
            s = new_s;
        }

        s[length++] = (char)ch;
    }

    if (ferror(stdin)) {
        fprintf(stderr, "Unable to read input.\n");
        free(s);
        return 1;
    }

    if (length > 0 && s[length - 1] == '\r') {
        length--;
    }

    size_t last_seen[UCHAR_MAX + 1];
    for (size_t i = 0; i <= UCHAR_MAX; i++) {
        last_seen[i] = SIZE_MAX;
    }

    size_t start = 0;
    size_t longest = 0;

    for (size_t i = 0; i < length; i++) {
        unsigned char current = (unsigned char)s[i];

        if (last_seen[current] != SIZE_MAX && last_seen[current] >= start) {
            start = last_seen[current] + 1;
        }

        last_seen[current] = i;
        if (i - start + 1 > longest) {
            longest = i - start + 1;
        }
    }

    printf("%zu\n", longest);
    free(s);
    return 0;
}