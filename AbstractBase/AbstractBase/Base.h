#pragma once
#include <iostream>

using namespace std;

class Base
{
#pragma once
protected :

	Base();
	~Base();

public:
	
	virtual void DisplayRecord() = 0;
	
};
