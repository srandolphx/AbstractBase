
#include <iostream>
#include <vector>
#include "Base.h"
#include "Student.cpp"
#include "Employee.h"

using namespace std;

Base* AddEntry();
Student* AddStudent();
Employee* AddEmployee();

vector<Base*> ManageRecords(vector<Base*> inVec);
float userNum(int min, int max);


int main()
{
	vector<Base*> people;
	bool run = true;
	int answer;;

	while (run)
	{
		system("cls");

		cout << "Would you like to add a record, or view/modify existing records?";
		cout << "\n1. Add a record\n2. View/Modify\n3. Exit the program ";

		answer = userNum(1, 3);

		switch (answer)
		{
		case 1:
			people.push_back(AddEntry());
			
			break;
		case 2:
			people = ManageRecords(people);

			break;
		case 3:
			run = false;

			break;
		default:
			break;
		}

	}
	return run;
	system("pause");
}
Base* AddEntry()
{

	bool run = false;

	while (!run)
	{
		int answer = 0;

		system("cls");

		cout << "Would you like to add an Employee or a Student?";
		cout << "\n1. Student\n2. Employee";
		answer = userNum(1, 2);
		if (answer == 1)
		{

			return AddStudent();

		}
		else if (answer == 2)
		{
			return AddEmployee();
		}


	}
	
}
Student* AddStudent()
{
	system("cls");


	char* inName = new char[32];
	char* inDeg = new char[32];
	float inGpa;
	int inRate;

	cin.clear();
	cin.ignore();

	cout << "What is the student's name: ";
	cin.getline(inName, 32, '\n');


	cout << endl << "enter " << inName << "'s" << " degree program: ";
	cin.getline(inDeg, 32, '\n');


	cout << endl << " what is " << inName << "'s" << " gpa: ";
	inGpa = userNum(0, 4);

	cout << endl << " whats " << inName << "'s" << " rating: ";
	inRate = userNum(0, 9999999999);

	Student* temp = new Student(inName, inDeg, inGpa, inRate);
	return temp;
}
float userNum(int min, int max)
{
	int result = 0;
	cin >> result;
	while (cin.fail())
	{
		cout<< "enter the right number \n";
		system("pause");

		return userNum(min, max);
	}
	return result;
}
Employee* AddEmployee()
{
	system("cls");


	char* inName = new char[32];
	char* inDep = new char[32];
	float inSal;
	cin.clear();
	cin.ignore();


	cout << "What is the employee's name?: ";
	cin.getline(inName, 32, '\n');

	cout << "\nWhat is their Department?: ";
	cin.getline(inDep, 32, '\n');

	cout << endl << "how much money does " << inName << "'s" << "make a year in (salary)?";
	inSal = userNum(0, 9999999999);


	Employee* temp = new Employee(inName, inDep, inSal);
	return temp;
}
vector<Base*> ManageRecords(vector<Base*> info)
{
	int input;
	int index1;
	int index2;

	while (true)
	{
		system("cls");

		cout << "Displaying People: ";
		
		cout << "\nWhich item would you like to copy from? \n";
		for (int i = 1; i < info.size(); i++)
		{
			cout << i << ")" << endl;

			info[i]->DisplayRecord();

			cout << " __________ " << endl;
		}
		cout << "1: Copy a record" << endl << "2: Exit" << "\nEnter number 1 or 2 : ";
		cin >> input;

		input = userNum(1, 2);


			if (input == 1)
			{
				cout << "Please enter the number for a person you want to pick: ";
				index1 = userNum(0, info.size());

				cout << "Please enter the number for second person you want to pick: ";
				index2 = userNum(0, info.size());

				Base* exp1 = info[index1];
				Base* exp2 = info[index2];
				if ((dynamic_cast<Employee*>(exp1) && dynamic_cast<Employee*>(exp2)) || ((dynamic_cast<Student*>(exp1) && dynamic_cast<Student*>(exp2))))
				{
					info[index1] = static_cast<Base*>(info[index2]);
				}
				return info;
			}
			else return info;
	}
}