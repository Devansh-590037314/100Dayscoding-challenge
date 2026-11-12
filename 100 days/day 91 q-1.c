#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

int main(void)
{
    struct Student student;

    printf("Enter student's name: ");
    if (scanf(" %49[^\n]", student.name) != 1) {
        fprintf(stderr, "Invalid name.\n");
        return 1;
    }

    printf("Enter roll number: ");
    if (scanf("%d", &student.roll_no) != 1) {
        fprintf(stderr, "Invalid roll number.\n");
        return 1;
    }

    printf("Enter marks: ");
    if (scanf("%f", &student.marks) != 1) {
        fprintf(stderr, "Invalid marks.\n");
        return 1;
    }

    printf("\nStudent details\n");
    printf("Name: %s\n", student.name);
    printf("Roll number: %d\n", student.roll_no);
    printf("Marks: %.2f\n", student.marks);

    return 0;
}