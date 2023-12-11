#pragma once
#include "Base.h"
class Employee :
	public Base
{
	char* name = nullptr;
	int salary;
	char* dept = nullptr;
public:
	Employee() { name = nullptr; dept = nullptr; salary = 0; }
	Employee(char* inName, char* inDept, int inSal);
	
	void DisplayRecord();

	Employee(Employee& input); 
	Employee& operator=(Employee& input); 
	~Employee() { delete[] name; delete[] dept; } 

};