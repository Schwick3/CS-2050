#include "prelab9.h"

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
        j--;
    }

    for (i = 0; i < size; i++)
        printf("\nSSN[%d] Before Sort:%d", i, emp[i]->SSN);

    printf("\n**********");

    Database = createSearchableEmployeeDB(emp, size);

    for (i = 0; i < size; i++)
        printf("\nSSN[%d] After Sort:%d", i, Database.empSSNData[i].SSN);

    printf("\n%p", findEmpByID(10, Database));
    printf("\n%p", findEmpBySSN(10, Database));

    return 0;
}
