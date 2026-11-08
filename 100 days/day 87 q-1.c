#include <stdio.h>

enum UserRole {
    ADMIN = 1,
    USER,
    GUEST
};

int main(void)
{
    int roleInput;
    enum UserRole role;

    printf("Select a user role:\n");
    printf("%d. Admin\n", ADMIN);
    printf("%d. User\n", USER);
    printf("%d. Guest\n", GUEST);
    printf("Enter your choice: ");

    if (scanf("%d", &roleInput) != 1) {
        fprintf(stderr, "Invalid role.\n");
        return 1;
    }

    role = (enum UserRole)roleInput;

    switch (role) {
        case ADMIN:
            printf("Welcome, admin. You have full access.\n");
            break;
        case USER:
            printf("Welcome, user. You have standard access.\n");
            break;
        case GUEST:
            printf("Welcome, guest. You have limited access.\n");
            break;
        default:
            fprintf(stderr, "Invalid role. Choose 1, 2, or 3.\n");
            return 1;
    }

    return 0;
}