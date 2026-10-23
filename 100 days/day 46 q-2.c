#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char text[MAX_LENGTH];
    int seen[26] = {0};
    int length = 0;
    char firstRepeating = '\0';

    printf("Enter a string: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        fprintf(stderr, "Could not read the string.\n");
        return 1;
    }

    while (text[length] != '\0' && text[length] != '\n') {
        char ch = text[length];
        if (ch >= 'a' && ch <= 'z') {
            int index = ch - 'a';
            if (seen[index] && firstRepeating == '\0') {
                firstRepeating = ch;
            }
            seen[index] = 1;
        }
        length++;
    }

    if (text[length] == '\0' && length == MAX_LENGTH - 1) {
        int nextCharacter = getchar();
        if (nextCharacter != '\n' && nextCharacter != EOF) {
            fprintf(stderr, "Input is too long. Enter at most %d characters.\n", MAX_LENGTH - 1);
            return 1;
        }
    }

    if (firstRepeating != '\0') {
        printf("First repeating lowercase letter: %c\n", firstRepeating);
    } else {
        printf("No repeating lowercase letters found.\n");
    }

    return 0;
}