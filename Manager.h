#pragma once
#include <iostream>
using namespace std;
#include "Employee.h"

class Manager : public Employee {
public:
	Manager(int id, string name, int dId);

	// show employee information
	virtual void showInfo();

	// get department number
	virtual string getDeptName();
};
