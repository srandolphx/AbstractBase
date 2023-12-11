
#include "Student.h"



Student::Student(char* inName, char* inDeg, float inGpa, int inRating)
{
    this->name =inName;
    this->degree = inDeg;
    this->gpa = inGpa;
    this->subscriber = inRating;
    
}
Student::~Student()
{

}
void Student::DisplayRecord()
{
    cout << "\nName: " << name << "\nDegree: " << degree << "\nGpa: " << gpa << "\nRating: " << subscriber << "\n";
}

Student::Student(const Student& input)
{


    name = input.name;
    degree = input.degree;
    gpa = input.gpa;
    subscriber = input.subscriber;
    
}

