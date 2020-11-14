#pragma once
#include <iostream>
#include "Employee.h"
using namespace std;


class HR : public Employee {
public:
		HR(int id, string name, int dId);

		// show employee information
		virtual void showInfo();

		// get department number
		virtual string getDeptName();
};
