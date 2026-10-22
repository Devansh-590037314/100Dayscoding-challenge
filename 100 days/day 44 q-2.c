#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char text[MAX_LENGTH];
    int length = 0;

    printf("Enter a string: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        fprintf(stderr, "Could not read the string.\n");
        return 1;
    }

    while (text[length] != '\0' && text[length] != '\n') {
        if (text[length] == ' ') {
            text[length] = '-';
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

    text[length] = '\0';
    printf("String with spaces replaced: %s\n", text);
    return 0;
}