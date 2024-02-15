#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int empID, jobType;
    float salary;
} Employee;

Employee *readEmployeeArray(FILE *fp);
Employee *getEmployeeByID(Employee *, int empID);

void setEmpSalary(Employee *, int empID, float salary, int *ec);
float getEmpSalary(Employee *, int empID, int *ec);
void setEmpJobType(Employee *, int empID, int job, int *ec);
int getEmpJobType(Employee *, int empID, int *ec);