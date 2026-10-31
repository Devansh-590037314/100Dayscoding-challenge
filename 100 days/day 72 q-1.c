#include <stdio.h>

int main(void)
{
    char line[256];
    FILE *file = fopen("info.txt", "r");

    if (file == NULL) {
        perror("Could not open info.txt");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        if (fputs(line, stdout) == EOF) {
            fprintf(stderr, "Failed to write file contents to the console.\n");
            fclose(file);
            return 1;
        }
    }

    if (ferror(file)) {
        fprintf(stderr, "Failed to read info.txt.\n");
        fclose(file);
        return 1;
    }

    if (fclose(file) == EOF) {
        perror("Could not close info.txt");
        return 1;
    }

    return 0;
}