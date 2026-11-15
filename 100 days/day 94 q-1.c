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
    struct Student student = {"Aarav", 101, 87.5f, MALE};

    printStudent(student);
    return 0;
}