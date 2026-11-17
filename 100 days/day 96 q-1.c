#include <stdio.h>

enum Department {
    HR,
    ENGINEERING,
    SALES
};

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    int id;
    char name[50];
    enum Department department;
    struct Date joining_date;
};

void printEmployee(struct Employee employee)
{
    const char *department_name;

    switch (employee.department) {
    case HR:
        department_name = "HR";
        break;
    case ENGINEERING:
        department_name = "Engineering";
        break;
    case SALES:
        department_name = "Sales";
        break;
    default:
        department_name = "Unknown";
        break;
    }

    printf("Employee ID: %d\n", employee.id);
    printf("Name: %s\n", employee.name);
    printf("Department: %s\n", department_name);
    printf("Joining date: %02d/%02d/%04d\n",
           employee.joining_date.day,
           employee.joining_date.month,
           employee.joining_date.year);
}

int main(void)
{
    struct Employee employee = {
        101,
        "Aarav Sharma",
        ENGINEERING,
        {15, 6, 2022}
    };

    printEmployee(employee);
    return 0;
}