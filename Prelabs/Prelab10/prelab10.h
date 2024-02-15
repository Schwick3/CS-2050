#include <stdio.h>
#include <stdlib.h>

typedef struct EmployeeStruct
{
    int SSN;
    int ID;
    int salary;
} Employee;

typedef struct EmployeeDatabase
{
    Employee *empIdData;
    Employee *empSSNData;
    Employee *salaryData;
    int errorCode;
    int size;
} EmpDatabase;

EmpDatabase createSearchableEmployeeDB(Employee **employeeArray, int size);
Employee *findEmpBySSN(int SSN, EmpDatabase Database);
Employee *findEmpByID(int ID, EmpDatabase Database);
void freeEmpDatabase(EmpDatabase Database);
int getErrorCode(EmpDatabase Database);
int countEmpsInSalaryRange(int min, int max, EmpDatabase Database);
