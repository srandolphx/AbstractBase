

#include "Employee.h"




Employee::Employee(char* inName, char* inDept, int inSal)
{
    this->name = inName;
    this->dept = inDept;
    this->salary = inSal;
    
}
void Employee::DisplayRecord()
{
    cout << "\nName: " << name << "\nSalary: " << salary << "\nDepartment: " << dept << "\n";
}

Employee::Employee(Employee& input)
{


    name = input.name;
    dept = input.dept;   
    salary = input.salary;

   
}

Employee& Employee::operator=(Employee& input)
{
    if (this != &input)
    {
        cout << " hello ";
    }
    return *this;

}