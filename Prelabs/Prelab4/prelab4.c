#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int empID, jobType;
    float salary;
} Employee;

// it is assumed that the file being passed in has the size needed for the array at the start of the file
Employee *readEmployeeArray(FILE *fp)
{
    Employee *Employees;
    int length = 0, i;
    fscanf(fp, "%d", &length);

    Employees = malloc(length * sizeof(Employee) + sizeof(Employee));
    if (Employees == NULL)
        printf("Malloc failed\n");

    Employees[0].empID = length; // stores the length of the created array in the first empID
    Employees++;                 // increments the entire array so that the length is hidden behind it

    for (i = 0; i < length; i++) // scans through the passed in file storing all the contained information in the array
    {
        fscanf(fp, "%d", &Employees[i].empID);
        fscanf(fp, "%d", &Employees[i].jobType);
        fscanf(fp, "%f", &Employees[i].salary);
    }

    return Employees; // returns the created array to the user
}

Employee *getEmployeeByID(Employee *Emp, int empID)
{
    int i;

    for (i = 0; i < Emp[-1].empID; i++) // for loop that scans through the array, uses the previously stored length that is hidden
    {                                   // behind the array
        if (empID == Emp[i].empID)      // if the passed in ID matches one found in the array
            return (Emp + i);           // return that array index to the user
    }

    printf("No Employee with that ID, please try again\n");
    return NULL;
}

void setEmpSalary(Employee *Emp, int empID, float salary, int *ec)
{
    if (getEmployeeByID(Emp, empID) == NULL)
        ec = 1;
    getEmployeeByID(Emp, empID)->salary = salary; // uses the getEmployeeById function to change the passed in IDs salary
}

void setEmpJobType(Employee *Emp, int empID, int job, int *ec)
{
    if (getEmployeeByID(Emp, empID) == NULL)
        ec = 1;
    getEmployeeByID(Emp, empID)->jobType = job; // uses the getEmployeeById function to change the passed in IDs job type
}

float getEmpSalary(Employee *Emp, int empID, int *ec)
{
    if (getEmployeeByID(Emp, empID) == NULL)
        ec = 1;
    return getEmployeeByID(Emp, empID)->salary; // uses the getEmployeeById function to return the salary of the passed in employee id, if found
}

int getEmpJobType(Employee *Emp, int empID, int *ec)
{
    if (getEmployeeByID(Emp, empID) == NULL)
        ec = 1;
    return getEmployeeByID(Emp, empID)->jobType; // uses the getEmployeeById function to return the job type of the passed in employee id, if found
}
