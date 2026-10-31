#include <stdio.h>

int main(void)
{
    FILE *file = fopen("info.txt", "r");
    unsigned long long characters = 0;
    unsigned long long words = 0;
    unsigned long long lines = 0;
    int inWord = 0;
    int lineHasContent = 0;
    int character;

    if (file == NULL) {
        perror("Could not open info.txt");
        return 1;
    }

    while ((character = fgetc(file)) != EOF) {
        characters++;

        if (character == ' ' || character == '\n') {
            inWord = 0;
        } else if (!inWord) {
            words++;
            inWord = 1;
        }

        if (character == '\n') {
            lines++;
            lineHasContent = 0;
        } else {
            lineHasContent = 1;
        }
    }

    if (ferror(file)) {
        fprintf(stderr, "Failed to read info.txt.\n");
        fclose(file);
        return 1;
    }

    if (lineHasContent) {
        lines++;
    }

    if (fclose(file) == EOF) {
        perror("Could not close info.txt");
        return 1;
    }

    printf("Characters: %llu\n", characters);
    printf("Words: %llu\n", words);
    printf("Lines: %llu\n", lines);

    return 0;
}