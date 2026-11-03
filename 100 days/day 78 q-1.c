#include <ctype.h>
#include <stdio.h>
#include <string.h>

static int read_filename(char *filename, size_t size)
{
    printf("Enter the filename: ");

    if (fgets(filename, size, stdin) == NULL) {
        fprintf(stderr, "Failed to read the filename.\n");
        return 0;
    }

    size_t length = strcspn(filename, "\r\n");
    if (filename[length] == '\0' && !feof(stdin)) {
        int character;
        while ((character = getchar()) != '\n' && character != EOF) {
        }
        fprintf(stderr, "Filename is too long.\n");
        return 0;
    }

    filename[length] = '\0';
    if (filename[0] == '\0') {
        fprintf(stderr, "Filename cannot be empty.\n");
        return 0;
    }

    return 1;
}

int main(void)
{
    char filename[256];
    if (!read_filename(filename, sizeof(filename))) {
        return 1;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        return 1;
    }

    size_t vowels = 0;
    size_t consonants = 0;
    int character;

    while ((character = fgetc(file)) != EOF) {
        if (isalpha((unsigned char)character)) {
            int lowercase = tolower((unsigned char)character);
            if (lowercase == 'a' || lowercase == 'e' || lowercase == 'i' ||
                lowercase == 'o' || lowercase == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    if (ferror(file)) {
        fprintf(stderr, "Failed to read file.\n");
        fclose(file);
        return 1;
    }

    if (fclose(file) == EOF) {
        perror("Could not close file");
        return 1;
    }

    printf("Vowels: %zu\n", vowels);
    printf("Consonants: %zu\n", consonants);
    return 0;
}
