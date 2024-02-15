#include "prelab11.h"

EmpDatabase createSearchableEmployeeDB()
{
    EmpDatabase Database;
    Database.left = malloc(sizeof(EmpDatabase));
    Database.right = malloc(sizeof(EmpDatabase));

    Database.errorCode = 0;

    if (Database.left == NULL || Database.right == NULL)
        Database.errorCode = 1;

    return Database;
}
EmpDatabase insertEmp(Employee *new, EmpDatabase Database)
{
    if (Database.emp == NULL)
        Database.emp = new;
}
int countEmpsInSalaryRange(int min, int max, EmpDatabase Database)
{
    int count = 0;

    if (Database.emp->salary > min && Database.emp->salary < max)
    {
        count++;
        countEmpsInSalaryRange(min, max, *Database.emp->left);
        countEmpsInSalaryRange(min, max, *Database.emp->right);
    }

    if (Database.emp->salary < min)
    {
        countEmpsInSalaryRange(min, max, *Database.right);
    }

    if (Database.emp->salary < max)
    {
        countEmpsInSalaryRange(min, max, *Database.left);
    }
    return count;
}

void freeEmpDatabase(EmpDatabase *Database)
{
    if (Database != NULL)
    {
        freeEmpDatabase(Database->right);
        freeEmpDatabase(Database->left);
        free(Database);
    }
}

int getErrorCode(EmpDatabase Database)
{
    return Database.errorCode;
}
