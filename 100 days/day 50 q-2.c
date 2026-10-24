#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(void)
{
    char string[MAX_LENGTH];

    printf("Enter a string: ");
    if (fgets(string, sizeof(string), stdin) == NULL) {
        fprintf(stderr, "Could not read the string.\n");
        return 1;
    }

    size_t length = strlen(string);
    if (length > 0 && string[length - 1] == '\n') {
        string[length - 1] = '\0';
        length--;
    } else if (length == sizeof(string) - 1 && !feof(stdin)) {
        int extraCharacter = getchar();
        if (extraCharacter != '\n' && extraCharacter != EOF) {
            while (extraCharacter != '\n' && extraCharacter != EOF) {
                extraCharacter = getchar();
            }
            fprintf(stderr, "String is too long. Enter at most %d characters.\n", MAX_LENGTH - 1);
            return 1;
        }
    }

    if (length == 0) {
        fprintf(stderr, "Please enter a string.\n");
        return 1;
    }

    printf("Substrings:\n");
    for (size_t start = 0; start < length; start++) {
        for (size_t end = start; end < length; end++) {
            for (size_t i = start; i <= end; i++) {
                putchar(string[i]);
            }
            putchar('\n');
        }
    }

    return 0;
}