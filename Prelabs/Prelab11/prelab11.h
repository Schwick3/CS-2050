#include <stdio.h>
#include <stdlib.h>

typedef struct EmployeeStruct
{
    int salary;
    struct EmployeeStruct *left;
    struct EmployeeStruct *right;
} Employee;

typedef struct EmployeeDatabase
{
    Employee *emp;
    int errorCode;
    int size;
} EmpDatabase;

EmpDatabase createSearchableEmployeeDB(); // Just inits your struct
EmpDatabase insertEmp(Employee *new, EmpDatabase Database);
int countEmpsInSalaryRange(int min, int max, EmpDatabase Database);
void freeEmpDatabase(EmpDatabase *Database);
int getErrorCode(EmpDatabase Database);