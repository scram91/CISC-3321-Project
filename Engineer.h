#pragma once
#include <iostream>
using namespace std;
#include "Employee.h"

class Engineer : public Employee {
public:
	Engineer(int id, string name, int dId);

	// show employee information
	virtual void showInfo();

	// get department number
	virtual string getDeptName();
};
