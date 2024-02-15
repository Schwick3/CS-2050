#include <stdlib.h>
#include <stdio.h>

//structs
typedef struct Employee{
    int salary;
    struct Employee *left;
    struct Employee *right;
}Employee;

typedef struct{
    Employee *empSalary;
    int errorCode;
}EmpDatabase;

//function prototypes
EmpDatabase createSearchableEmployeeDB(); // Just inits your struct 
Employee* insertHelper (Employee *emp, Employee *node);
EmpDatabase insertEmp(Employee *emp, EmpDatabase empDB);
int binaryRange (Employee *emp, int min, int max, int count);
int countEmpsInSalaryRange(int min, int max, EmpDatabase empDB); 
void freeEmpDatabase(EmpDatabase empDB); //done but check
int getErrorCode(EmpDatabase empDB); //done & simple

int main()
{
    EmpDatabase empDB = createSearchableEmployeeDB();

    Employee *emp1 = NULL;
    emp1 = malloc(sizeof(Employee));
    emp1->salary = 1000;
    Employee *emp2 = NULL;
    emp2 = malloc(sizeof(Employee));
    emp2->salary = 2000;
    Employee *emp3 = NULL;
    emp3 = malloc(sizeof(Employee));
    emp3->salary = 500;

    insertEmp(emp1,empDB);
    insertEmp(emp3,empDB);
    insertEmp(emp2,empDB);
    int x = countEmpsInSalaryRange(900, 1000, empDB);
    printf("\n# of ints found in range : %d", x);
}

EmpDatabase createSearchableEmployeeDB()
{
    EmpDatabase empDB;
    empDB.empSalary = malloc(sizeof(Employee));
    empDB.empSalary -> salary = 0;
    empDB.empSalary -> left = NULL;
    empDB.empSalary -> right = NULL;
    
    if(empDB.empSalary == NULL) //malloc check
    {
        empDB.errorCode = 1; //failure
        printf("\nError in creating database");
        return empDB;
    }

    empDB.errorCode = 0; //success
    return empDB;
}

Employee* insertHelper (Employee *emp, Employee *node)
{
    if (node == NULL)
        {
            node = malloc(sizeof(Employee));
            node -> left = NULL;
            node -> right = NULL;
            node -> salary = emp -> salary;
            return node;
        }

    int x = emp -> salary;
    int large = node -> salary;

    if (large == 0)
        {
            node -> salary = emp -> salary;
        }
    else if (x == large)
        {
            node -> salary = emp -> salary;
        }
    
    else if (x > large) //bigger case
        {
            node -> right = insertHelper(emp, node->right);
        }

    else if (x < large) //smaller case
        {
            node -> left = insertHelper(emp, node->left);
        }
    return node;
}

EmpDatabase insertEmp(Employee *emp, EmpDatabase empDB)
{
    int x = emp->salary;
    int large = empDB.empSalary->salary;

    if (x == 0) //nothing in emp data case
        {
            printf("\nData to be inserted not found");
            empDB.errorCode = 1; //fail ec
            return empDB;
        }

    if  (large == 0) //nothing in database case
        {
            empDB.empSalary->salary = emp->salary;
        }

    else if (x > large) //bigger case
        {
            empDB.empSalary -> right = insertHelper(emp, empDB.empSalary->right);
            return empDB;
        }
    else if (x < large) //smaller case
        {
            empDB.empSalary -> left = insertHelper(emp, empDB.empSalary->left);
            return empDB;
        }
    return empDB;
}

int binaryRange (Employee *emp, int min, int max, int count)
{
    if (emp == NULL)
    {
        return count;
    }
    int x = emp->salary;

    if (x < min)
    {
        binaryRange(emp->left,min,max,count);
    }

    else if (x >= min && x <= max)
    {
        count++;
        binaryRange(emp->right,min,max,count);
        binaryRange(emp->left,min,max,count);
    }

    else if (x > max)
    {
        return count;
    }
    return count;
}

int countEmpsInSalaryRange(int min, int max, EmpDatabase empDB)
{
    int x = empDB.empSalary->salary;
    int count = 0;

    if (x < min)
    {
        binaryRange(empDB.empSalary->left, min, max, count);
    }
    else if (x >= min && x <= max)
    {
        count++;
        binaryRange(empDB.empSalary->right, min, max, count);
        binaryRange(empDB.empSalary->left, min, max, count);
    }

    if (count == 0)
    {
        printf("\nNo salaries found in that range");
    }   

    return count;
}

void freeEmpDatabase(EmpDatabase empDB)
{
    free(empDB.empSalary);

    if (empDB.empSalary != NULL) //error check
    {
        printf("\nError in freeing database");
        empDB.errorCode = 1;
    }
}

int getErrorCode(EmpDatabase empDB)
{
    return empDB.errorCode;
}