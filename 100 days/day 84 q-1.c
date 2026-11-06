#include <stdio.h>

enum Status {
    SUCCESS,
    FAILURE,
    TIMEOUT
};

void print_status(enum Status status)
{
    switch (status) {
    case SUCCESS:
        printf("Operation completed successfully.\n");
        break;
    case FAILURE:
        printf("Operation failed.\n");
        break;
    case TIMEOUT:
        printf("Operation timed out.\n");
        break;
    default:
        printf("Unknown status.\n");
        break;
    }
}

int main(void)
{
    print_status(SUCCESS);
    print_status(FAILURE);
    print_status(TIMEOUT);

    return 0;
}