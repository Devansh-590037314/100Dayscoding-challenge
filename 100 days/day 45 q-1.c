#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
    char text[MAX_LENGTH];
    int length = 0;
    int frequency = 0;

    printf("Enter a string: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        fprintf(stderr, "Could not read the string.\n");
        return 1;
    }

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

    printf("Enter the character to count: ");
    int target = getchar();
    if (target == EOF || target == '\n') {
        fprintf(stderr, "Could not read a character.\n");
        return 1;
    }

    for (int i = 0; i < length; i++) {
        if (text[i] == target) {
            frequency++;
        }
    }

    printf("The character '%c' appears %d time(s).\n", target, frequency);
    return 0;
}