#include <ctype.h>
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
        unsigned char ch = (unsigned char)text[length];
        if (islower(ch)) {
            text[length] = (char)toupper(ch);
        } else if (isupper(ch)) {
            text[length] = (char)tolower(ch);
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
    printf("String with case toggled: %s\n", text);
    return 0;
}