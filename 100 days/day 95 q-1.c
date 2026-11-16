#include <stdio.h>

enum Gender {
    MALE,
    FEMALE,
    OTHER
};

struct Student {
    char name[50];
    int roll_no;
    float marks;
    enum Gender gender;
};

struct Student getTopStudent(const struct Student students[], int count)
{
    int highest_index = 0;
    int i;

    for (i = 1; i < count; i++) {
        if (students[i].marks > students[highest_index].marks) {
            highest_index = i;
        }
    }

    return students[highest_index];
}

void printStudent(struct Student student)
{
    printf("Name: %s\n", student.name);
    printf("Roll number: %d\n", student.roll_no);
    printf("Marks: %.2f\n", student.marks);
    printf("Gender: ");

    switch (student.gender) {
    case MALE:
        printf("Male\n");
        break;
    case FEMALE:
        printf("Female\n");
        break;
    case OTHER:
        printf("Other\n");
        break;
    default:
        printf("Unknown\n");
        break;
    }
}

int main(void)
{
    struct Student students[5];
    struct Student top_student;
    int i;
    int gender_choice;

    for (i = 0; i < 5; i++) {
        printf("\nEnter details for student %d\n", i + 1);

        printf("Name: ");
        if (scanf(" %49[^\n]", students[i].name) != 1) {
            fprintf(stderr, "Invalid name.\n");
            return 1;
        }

        printf("Roll number: ");
        if (scanf("%d", &students[i].roll_no) != 1) {
            fprintf(stderr, "Invalid roll number.\n");
            return 1;
        }

        printf("Marks: ");
        if (scanf("%f", &students[i].marks) != 1) {
            fprintf(stderr, "Invalid marks.\n");
            return 1;
        }

        printf("Gender (0 = Male, 1 = Female, 2 = Other): ");
        if (scanf("%d", &gender_choice) != 1 ||
            gender_choice < MALE || gender_choice > OTHER) {
            fprintf(stderr, "Invalid gender choice.\n");
            return 1;
        }
        students[i].gender = (enum Gender)gender_choice;
    }

    top_student = getTopStudent(students, 5);

    printf("\nTop student's details\n");
    printStudent(top_student);

    return 0;
}