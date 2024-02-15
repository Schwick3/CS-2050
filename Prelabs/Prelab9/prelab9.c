#include "prelab9.h"

EmpDatabase createSearchableEmployeeDB(Employee **unsortedDatabase, int size)
{
    EmpDatabase sortedDatabase;
    int i, j;
    Employee *sortByID = malloc(sizeof(Employee) * size);
    Employee *sortBySSN = malloc(sizeof(Employee) * size);

    if (sortByID == NULL || sortBySSN == NULL)
    {
        sortedDatabase.errorCode = 1;
        return sortedDatabase;
    }

    sortedDatabase.empIdData = sortedDatabase.empSSNData = malloc(sizeof(Employee) * size);

    for (i = 0; i < size; i++)
    {
        sortByID[i] = *unsortedDatabase[i];
        sortBySSN[i] = *unsortedDatabase[i];
    }

    Employee temp;
    sortedDatabase.size = size;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {

            if (sortByID[j].ID > sortByID[j + 1].ID)
            {
                temp = sortByID[j];
                sortByID[j] = sortByID[j + 1];
                sortByID[j + 1] = temp;
            }

            if (sortBySSN[j].SSN > sortBySSN[j + 1].SSN)
            {
                temp = sortBySSN[j];
                sortBySSN[j] = sortBySSN[j + 1];
                sortBySSN[j + 1] = temp;
            }
        }
    }

    sortedDatabase.empIdData = sortByID;
    sortedDatabase.empSSNData = sortBySSN;
    return sortedDatabase;
}

Employee *findEmpBySSN(int SSN, EmpDatabase Database)
{
    int mid;
    int first = 0;
    int last = Database.size;

    while (first <= last)
    {
        mid = (first + last) / 2;

        if (Database.empSSNData[mid].SSN == SSN)
        {
            Database.errorCode = 0;
            return &Database.empSSNData[mid];
        }

        if (SSN > Database.empSSNData[mid].SSN)
        {
            first = mid + 1;
        }

        else if (SSN < Database.empSSNData[mid].SSN)
        {
            last = mid - 1;
        }
    }

    Database.errorCode = 2;
    return NULL;
}

Employee *findEmpByID(int ID, EmpDatabase Database)
{
    int mid;
    int first = 0;
    int last = Database.size;

    while (first <= last)
    {
        mid = (first + last) / 2;

        if (Database.empIdData[mid].ID == ID)
        {
            Database.errorCode = 0;
            return &Database.empIdData[mid];
        }

        if (ID > Database.empIdData[mid].ID)
        {
            first = mid + 1;
        }

        else if (ID < Database.empIdData[mid].ID)
        {
            last = mid - 1;
        }
    }

    printf("\nNot found");

    Database.errorCode = 2;
    return NULL;
}

int getErrorCode(EmpDatabase Database)
{
    return Database.errorCode;
}

void freeEmpDatabase(EmpDatabase Database)
{
    free(Database.empIdData);
    free(Database.empSSNData);
    Database.empIdData = NULL;
    Database.empSSNData = NULL;
}
