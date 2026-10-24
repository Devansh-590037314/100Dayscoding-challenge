#include <stdio.h>
#include <string.h>

#define DATE_LENGTH 10
#define INPUT_SIZE 100

int main(void)
{
    char date[INPUT_SIZE];

    printf("Enter a date in dd/04/yyyy format: ");
    if (fgets(date, sizeof(date), stdin) == NULL) {
        fprintf(stderr, "Could not read the date.\n");
        return 1;
    }

    size_t length = strcspn(date, "\n");
    if (date[length] == '\n') {
        date[length] = '\0';
    } else if (!feof(stdin)) {
        int extraCharacter = getchar();
        while (extraCharacter != '\n' && extraCharacter != EOF) {
            extraCharacter = getchar();
        }
        fprintf(stderr, "Input is too long.\n");
        return 1;
    }

    if (length != DATE_LENGTH ||
        date[2] != '/' || date[3] != '0' || date[4] != '4' || date[5] != '/') {
        fprintf(stderr, "Please enter the date in dd/04/yyyy format.\n");
        return 1;
    }

    for (size_t i = 0; i < DATE_LENGTH; i++) {
        if (i != 2 && i != 5 && (date[i] < '0' || date[i] > '9')) {
            fprintf(stderr, "The day and year must contain only digits.\n");
            return 1;
        }
    }

    int day = (date[0] - '0') * 10 + (date[1] - '0');
    if (day < 1 || day > 30) {
        fprintf(stderr, "April dates must have a day from 01 to 30.\n");
        return 1;
    }

    printf("Formatted date: %.2s-Apr-%.4s\n", date, date + 6);
    return 0;
}