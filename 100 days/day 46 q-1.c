#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char text[MAX_LENGTH];
    int readIndex = 0;
    int writeIndex = 0;

    printf("Enter a string: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        fprintf(stderr, "Could not read the string.\n");
        return 1;
    }

    while (text[readIndex] != '\0' && text[readIndex] != '\n') {
        char ch = text[readIndex];
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' &&
            ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U') {
            text[writeIndex] = ch;
            writeIndex++;
        }
        readIndex++;
    }

    if (text[readIndex] == '\0' && readIndex == MAX_LENGTH - 1) {
        int nextCharacter = getchar();
        if (nextCharacter != '\n' && nextCharacter != EOF) {
            fprintf(stderr, "Input is too long. Enter at most %d characters.\n", MAX_LENGTH - 1);
            return 1;
        }
    }

    text[writeIndex] = '\0';
    printf("String without vowels: %s\n", text);
    return 0;
}