#pragma once
#include "Base.h"

class Student :
	public Base
{
	char* name = nullptr;
	char* degree = nullptr;
	float gpa;
	int subscriber;

protected:


public:

	Student(char* inName, char* inDeg, float inGpa, int inRating);
	~Student();
	Student(const Student& input);

	virtual void DisplayRecord();
};