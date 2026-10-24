#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(void)
{
    char name[MAX_LENGTH];

    printf("Enter a name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        fprintf(stderr, "Could not read the name.\n");
        return 1;
    }

    size_t length = strlen(name);
    if (length > 0 && name[length - 1] == '\n') {
        name[length - 1] = '\0';
    } else if (length == sizeof(name) - 1 && !feof(stdin)) {
        int extraCharacter = getchar();
        if (extraCharacter != '\n' && extraCharacter != EOF) {
            while (extraCharacter != '\n' && extraCharacter != EOF) {
                extraCharacter = getchar();
            }
            fprintf(stderr, "Name is too long. Enter at most %d characters.\n", MAX_LENGTH - 1);
            return 1;
        }
    }

    int atStartOfWord = 1;
    int foundInitial = 0;
    for (size_t i = 0; name[i] != '\0'; i++) {
        unsigned char character = (unsigned char)name[i];
        if (isspace(character)) {
            atStartOfWord = 1;
        } else if (atStartOfWord) {
            printf("%c.", toupper(character));
            atStartOfWord = 0;
            foundInitial = 1;
        }
    }

    if (!foundInitial) {
        fprintf(stderr, "Please enter a name.\n");
        return 1;
    }

    putchar('\n');
    return 0;
}