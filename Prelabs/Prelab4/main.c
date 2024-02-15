#include "prelab4.h"

int main(int argc, char *argv[])
{
    FILE *fptr = fopen("testfile.csv", "r");

    Employee *Employees;
    Employees = readEmployeeArray(fptr);

    int i, errorCode;
    // printf("Length = %d\n", Employees[-1].empID);
    for (i = 0; i < Employees[-1].empID; i++)
    {
        printf("Employee ID: %d Job Type: %d Salary: %f\n", Employees[i].empID, Employees[i].jobType, Employees[i].salary);
    }

    getEmployeeByID(Employees, 3);

    setEmpJobType(Employees, 1, 15, &errorCode);
    setEmpSalary(Employees, 1, 100.0, &errorCode);

    printf("New employee job type: %d\n", getEmpJobType(Employees, 1, &errorCode));
    printf("New employee salary: %f\n", getEmpSalary(Employees, 1, &errorCode));

    return 0;
}