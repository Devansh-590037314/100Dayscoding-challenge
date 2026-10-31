#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define INPUT_SIZE 4096

int main(void)
{
    char text[INPUT_SIZE];

    printf("Enter a string: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        fprintf(stderr, "Failed to read input.\n");
        return 1;
    }

    size_t length = strlen(text);
    if (length > 0 && text[length - 1] == '\n') {
        text[--length] = '\0';
    }

    int sentence_start = 1;
    for (size_t i = 0; i < length; i++) {
        unsigned char character = (unsigned char)text[i];

        if (isalpha(character)) {
            text[i] = sentence_start ? (char)toupper(character)
                                     : (char)tolower(character);
            sentence_start = 0;
        } else if (character == '.' || character == '!' || character == '?') {
            sentence_start = 1;
        }
    }

    printf("Sentence case: %s\n", text);
    return 0;
}