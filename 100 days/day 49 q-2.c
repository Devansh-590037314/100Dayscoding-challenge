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

    char *pendingWord = NULL;
    char *current = name;
    while (*current != '\0') {
        while (*current != '\0' && isspace((unsigned char)*current)) {
            current++;
        }
        if (*current == '\0') {
            break;
        }

        char *word = current;
        while (*current != '\0' && !isspace((unsigned char)*current)) {
            current++;
        }
        if (*current != '\0') {
            *current++ = '\0';
        }

        if (pendingWord != NULL) {
            printf("%c. ", toupper((unsigned char)pendingWord[0]));
        }
        pendingWord = word;
    }

    if (pendingWord == NULL) {
        fprintf(stderr, "Please enter a name.\n");
        return 1;
    }

    printf("%s\n", pendingWord);
    return 0;
}