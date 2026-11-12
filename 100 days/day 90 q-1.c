#include <stdio.h>

enum Gender {
    MALE,
    FEMALE
};

struct Person {
    char name[50];
    enum Gender gender;
};

int main(void)
{
    struct Person person = {"Alex", FEMALE};

    printf("%s's gender: ", person.name);
    switch (person.gender) {
    case MALE:
        printf("Male\n");
        break;
    case FEMALE:
        printf("Female\n");
        break;
    default:
        printf("Unknown\n");
        break;
    }

    return 0;
}