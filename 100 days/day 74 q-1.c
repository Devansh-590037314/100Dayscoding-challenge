#include <stdio.h>
#include <string.h>

static int read_filename(const char *prompt, char *filename, size_t size)
{
    printf("%s", prompt);

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
    char source_name[256];
    char destination_name[256];

    if (!read_filename("Enter the source filename: ", source_name, sizeof(source_name)) ||
        !read_filename("Enter the destination filename: ", destination_name, sizeof(destination_name))) {
        return 1;
    }

    if (strcmp(source_name, destination_name) == 0) {
        fprintf(stderr, "Source and destination filenames must be different.\n");
        return 1;
    }

    FILE *source = fopen(source_name, "rb");
    if (source == NULL) {
        perror("Could not open source file");
        return 1;
    }

    FILE *destination = fopen(destination_name, "wb");
    if (destination == NULL) {
        perror("Could not open destination file");
        fclose(source);
        return 1;
    }

    int character;
    int copy_failed = 0;
    while ((character = fgetc(source)) != EOF) {
        if (fputc(character, destination) == EOF) {
            fprintf(stderr, "Failed to write to destination file.\n");
            copy_failed = 1;
            break;
        }
    }

    if (ferror(source)) {
        fprintf(stderr, "Failed to read from source file.\n");
        copy_failed = 1;
    }

    if (fclose(source) == EOF) {
        perror("Could not close source file");
        copy_failed = 1;
    }

    if (fclose(destination) == EOF) {
        perror("Could not close destination file");
        copy_failed = 1;
    }

    if (copy_failed) {
        return 1;
    }

    printf("File copied successfully.\n");
    return 0;
}