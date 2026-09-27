#include <stdio.h>

// Structure employee
struct Employee
{
    int id;
    char name[50];
    float salary;
};

int main()
{
    int n, i;
    float totalSalary = 0.0, averageSalary;
    int imax = 0;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name); // Reads a single word name
        printf("Salary: ");
        scanf("%f", &emp[i].salary);

        totalSalary += emp[i].salary;

        if (emp[i].salary > emp[imax].salary)
        {
            imax = i;
        }
    }

    averageSalary = totalSalary / n;

    printf("\n--- Employee with the Highest Salary ---\n");
    printf("ID: %d\n", emp[imax].id);
    printf("Name: %s\n", emp[imax].name);
    printf("Salary: %.2f\n", emp[imax].salary);

    printf("\n----------------------------------------\n");
    printf("Average Salary of all employees: %.2f\n", averageSalary);

    return 0;
}
