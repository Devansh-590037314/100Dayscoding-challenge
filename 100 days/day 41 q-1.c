#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char text[MAX_LENGTH];
    int count = 0;

    printf("Enter a string: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        fprintf(stderr, "Could not read the string.\n");
        return 1;
    }

    while (text[count] != '\0' && text[count] != '\n') {
        count++;
    }

    if (text[count] == '\0' && count == MAX_LENGTH - 1) {
        int nextCharacter = getchar();
        if (nextCharacter != '\n' && nextCharacter != EOF) {
            fprintf(stderr, "Input is too long. Enter at most %d characters.\n", MAX_LENGTH - 1);
            return 1;
        }
    }

    printf("Number of characters: %d\n", count);
    return 0;
}