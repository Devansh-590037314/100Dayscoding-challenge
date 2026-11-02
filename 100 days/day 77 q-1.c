#include <ctype.h>
#include <stdio.h>

int main(void)
{
    FILE *input = fopen("input.txt", "r");
    if (input == NULL) {
        perror("Could not open input.txt");
        return 1;
    }

    FILE *output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("Could not open output.txt");
        fclose(input);
        return 1;
    }

    int failed = 0;
    int character;
    while ((character = fgetc(input)) != EOF) {
        if (fputc(toupper((unsigned char)character), output) == EOF) {
            perror("Could not write to output.txt");
            failed = 1;
            break;
        }
    }

    if (ferror(input)) {
        perror("Could not read input.txt");
        failed = 1;
    }

    if (fclose(input) == EOF) {
        perror("Could not close input.txt");
        failed = 1;
    }

    if (fclose(output) == EOF) {
        perror("Could not close output.txt");
        failed = 1;
    }

    return failed ? 1 : 0;
}