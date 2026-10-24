#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int readString(char *text, size_t size, const char *prompt)
{
    printf("%s", prompt);
    if (fgets(text, size, stdin) == NULL) {
        fprintf(stderr, "Could not read the string.\n");
        return 0;
    }

    char *newline = strchr(text, '\n');
    if (newline != NULL) {
        *newline = '\0';
    } else if (!feof(stdin)) {
        int nextCharacter = getchar();
        if (nextCharacter != '\n' && nextCharacter != EOF) {
            while (nextCharacter != '\n' && nextCharacter != EOF) {
                nextCharacter = getchar();
            }
            fprintf(stderr, "Input is too long. Enter at most %d characters.\n", MAX_LENGTH - 1);
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    char first[MAX_LENGTH];
    char second[MAX_LENGTH];
    char doubled[MAX_LENGTH * 2];

    if (!readString(first, sizeof(first), "Enter the first string: ") ||
        !readString(second, sizeof(second), "Enter the second string: ")) {
        return 1;
    }

    size_t length = strlen(first);
    if (length == strlen(second)) {
        memcpy(doubled, first, length);
        memcpy(doubled + length, first, length);
        doubled[length * 2] = '\0';

        if (strstr(doubled, second) != NULL) {
            printf("The strings are rotations of each other.\n");
            return 0;
        }
    }

    printf("The strings are not rotations of each other.\n");
    return 0;
}