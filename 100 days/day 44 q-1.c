#include <ctype.h>
#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char text[MAX_LENGTH];
    int spaces = 0;
    int digits = 0;
    int specialCharacters = 0;

    printf("Enter a string: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        fprintf(stderr, "Could not read the string.\n");
        return 1;
    }

    int length = 0;
    while (text[length] != '\0' && text[length] != '\n') {
        length++;
    }

    if (text[length] == '\0' && length == MAX_LENGTH - 1) {
        int nextCharacter = getchar();
        if (nextCharacter != '\n' && nextCharacter != EOF) {
            fprintf(stderr, "Input is too long. Enter at most %d characters.\n", MAX_LENGTH - 1);
            return 1;
        }
    }

    for (int i = 0; i < length; i++) {
        unsigned char ch = (unsigned char)text[i];

        if (isspace(ch)) {
            spaces++;
        } else if (isdigit(ch)) {
            digits++;
        } else if (!isalnum(ch)) {
            specialCharacters++;
        }
    }

    printf("Spaces: %d\n", spaces);
    printf("Digits: %d\n", digits);
    printf("Special characters: %d\n", specialCharacters);

    return 0;
}