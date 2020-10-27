#pragma once
#include <iostream>
using namespace std;
#include <string>

// Employee abstract class
class Employee {
public:
	// show employee information
	virtual void showInfo() = 0;

	// get department number
	virtual string getDeptName() = 0;

	// employee number
	int m_Id;

	// employee name
	string m_Name;

	// department number
	int m_DeptId;
};
