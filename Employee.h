#pragma once
#include <iostream>
#include <string>
using namespace std;


// Employee abstract class
class Employee {

public:
	// show employee information
	virtual void showInfo() = 0;

	// get department number
	virtual string getDeptName() = 0;

	// employee number
	int m_Id;

	// department number
	int m_DeptId;

	string m_Name;

};
