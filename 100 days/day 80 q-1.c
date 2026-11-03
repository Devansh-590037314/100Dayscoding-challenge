#include <stdio.h>

#define NAME_LENGTH 50

int main(void)
{
    FILE *file;
    int number_of_students;

    printf("Enter the number of students: ");
    if (scanf("%d", &number_of_students) != 1 || number_of_students <= 0) {
        fprintf(stderr, "Please enter a positive number of students.\n");
        return 1;
    }

    file = fopen("students.txt", "w");
    if (file == NULL) {
        perror("Could not open students.txt");
        return 1;
    }

    for (int i = 0; i < number_of_students; i++) {
        char name[NAME_LENGTH];
        int roll_number;
        float marks;

        printf("Enter name, roll number, and marks for student %d: ", i + 1);
        if (scanf("%49s %d %f", name, &roll_number, &marks) != 3) {
            fprintf(stderr, "Invalid student record.\n");
            fclose(file);
            return 1;
        }

        if (fprintf(file, "%s %d %.2f\n", name, roll_number, marks) < 0) {
            perror("Could not write to students.txt");
            fclose(file);
            return 1;
        }
    }

    if (fclose(file) == EOF) {
        perror("Could not close students.txt");
        return 1;
    }

    file = fopen("students.txt", "r");
    if (file == NULL) {
        perror("Could not reopen students.txt");
        return 1;
    }

    printf("\nStudent records:\n");
    printf("%-20s %-12s %s\n", "Name", "Roll number", "Marks");

    for (int i = 0; i < number_of_students; i++) {
        char name[NAME_LENGTH];
        int roll_number;
        float marks;

        if (fscanf(file, "%49s %d %f", name, &roll_number, &marks) != 3) {
            fprintf(stderr, "Could not read a complete student record.\n");
            fclose(file);
            return 1;
        }

        printf("%-20s %-12d %.2f\n", name, roll_number, marks);
    }

    if (fclose(file) == EOF) {
        perror("Could not close students.txt");
        return 1;
    }

    return 0;
}