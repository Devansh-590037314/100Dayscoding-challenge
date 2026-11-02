#include <stdio.h>
#include <string.h>

static int read_line(const char *prompt, char *buffer, size_t size)
{
    printf("%s", prompt);

    if (fgets(buffer, size, stdin) == NULL) {
        fprintf(stderr, "Failed to read input.\n");
        return 0;
    }

    size_t length = strcspn(buffer, "\r\n");
    if (buffer[length] == '\0' && !feof(stdin)) {
        int character;
        while ((character = getchar()) != '\n' && character != EOF) {
        }
        fprintf(stderr, "Input is too long.\n");
        return 0;
    }

    buffer[length] = '\0';
    return 1;
}

int main(void)
{
    char filename[256];
    char text[1024];

    if (!read_line("Enter the filename: ", filename, sizeof(filename)) ||
        !read_line("Enter the text to append: ", text, sizeof(text))) {
        return 1;
    }

    if (filename[0] == '\0') {
        fprintf(stderr, "Filename cannot be empty.\n");
        return 1;
    }

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Could not open file");
        return 1;
    }

    int write_failed = fputs(text, file) == EOF || fputc('\n', file) == EOF;
    if (fclose(file) == EOF) {
        perror("Could not close file");
        write_failed = 1;
    }

    if (write_failed) {
        fprintf(stderr, "Failed to append text to the file.\n");
        return 1;
    }

    printf("Text appended successfully.\n");
    return 0;
}