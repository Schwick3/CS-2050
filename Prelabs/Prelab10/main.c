#include "prelab10.h"

int main(int argc, char *argv[])
{
    Employee *emp[10];
    int size = 10;
    int i = 0;
    int j = 10;

    EmpDatabase Database;

    for (i = 0; i < size; i++)
    {
        emp[i] = malloc(sizeof(Employee) * size);
        emp[i]->ID = j;
        emp[i]->SSN = j;
        emp[i]->salary = j;
        j--;
    }

    for (i = 0; i < size; i++)
        printf("\nSSN[%d] Before Sort:%d", i, emp[i]->salary);

    printf("\n**********");

    Database = createSearchableEmployeeDB(emp, size);

    for (i = 0; i < size; i++)
        printf("\nSSN[%d] After Sort:%d", i, Database.salaryData[i].salary);

    printf("\n%p", findEmpByID(10, Database));
    printf("\n%p", findEmpBySSN(10, Database));

    printf("\nSalary in range (%d,%d): %d", 1, 10, countEmpsInSalaryRange(1, 10, Database));
    return 0;
}
