#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[100];
    int age;

    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        fprintf(stderr, "Failed to read the name.\n");
        return 1;
    }

    size_t length = strlen(name);
    if (length > 0 && name[length - 1] == '\n') {
        name[length - 1] = '\0';
    }

    printf("Enter your age: ");
    if (scanf("%d", &age) != 1) {
        fprintf(stderr, "Invalid age.\n");
        return 1;
    }

    FILE *file = fopen("info.txt", "w");
    if (file == NULL) {
        perror("Could not open info.txt");
        return 1;
    }

    if (fprintf(file, "Name: %s\nAge: %d\n", name, age) < 0) {
        fprintf(stderr, "Failed to write data to info.txt.\n");
        fclose(file);
        return 1;
    }

    if (fclose(file) == EOF) {
        perror("Could not close info.txt");
        return 1;
    }

    printf("Your data was successfully saved to info.txt.\n");
    return 0;
}