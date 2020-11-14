#pragma once
#include <iostream>
#include "Employee.h"
#include "HR.h"
#include "Manager.h"
#include "Sales.h"
#include "Engineer.h"
#include "Schedule.h"
#include <fstream>
#define FILENAME "empFile.txt"

using namespace std;

class EmployeeManagement {
public:
	// display the main menu
	void displayMenu();

	// exit system
	void exitSystem();

	// add employee
	void addEmployee();

	// diaplay employee
	void displayEmp();

	//Add employee schedule
	void addSchedule();

	void clearFile();
};
