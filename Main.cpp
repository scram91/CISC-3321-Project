#include <iostream>
#include <fstream>
#include <iomanip>
#include "Header.h"
#include "Engineer.h"
#include "Manager.h"
#include "Sales.h"
#include "HR.h"
#include "Employee.h"
#include "Schedule.h"



using namespace std;

// display the main menu
void EmployeeManagement::displayMenu() {
	cout << "*******************************************************************" << endl;
	cout << "**********   Welcome to employee management system!   *************" << endl;
	cout << "***************   0. Exit management system!       ****************" << endl;
	cout << "***************   1. Add employee information      ****************" << endl;
	cout << "***************   2. Display employee information  ****************" << endl;
	cout << "***************   3. Set/show employee schedule    ****************" << endl;
	cout << "***************   4. Clear the Employee File       ****************" << endl;
	cout << "*******************************************************************" << endl;
	cout << endl;
}

// exit management system
void EmployeeManagement::exitSystem() {
	cout << "See you next time!" << endl;
	system("pause");
	exit(0);
}

// add employee
void EmployeeManagement::addEmployee() {
	cout << "Please enter the number of employees you want to add: " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {
		fstream outfile;

		outfile.open(FILENAME, ios::out);
		outfile << "Employee ID\t" << "Employee Name\t" << "Department\t" << "\n" << endl;

		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int department;

			cout << "Please enter the ID for employee " << i + 1 << " : " << endl;
			cin >> id;
			outfile << id << "\t\t";

			cout << "Please enter the name for employee " << i + 1 << " : " << endl;
			cin >> name;
			outfile << name << "\t\t";

			cout << "Please select the position for the employee " << endl;
			cout << "1. HR" << endl;
			cout << "2. Sales" << endl;
			cout << "3. Engineering" << endl;
			cout << "4. Management" << endl;
			cin >> department;
				


			Employee* employee = NULL;

			switch (department) {
			case 1:
				outfile << "HR" << endl;
				employee = new HR(id, name, department);
				break;
			case 2:
				outfile << "Sales" << endl;
				employee = new Sales(id, name, department);
				break;
			case 3:
				outfile << "Engineering" << endl;
				employee = new Engineer(id, name, department);
				break;
			case 4:
				outfile << "Management" << endl;
				employee = new Manager(id, name, department);
				break;
			default:
				break;
			}
		}
		outfile.close();
	}
		
}

//Add and display Employee Schedule
void EmployeeManagement::addSchedule() {
	int id;
	double mhours;
	double thours;
	double whours;
	double thhours;
	double fhours;
	
	cout << "Please enter the ID of the employee: ";
	cin >> id;
	cout << "Please enter hours scheduled for Monday: ";
	cin >> mhours;
	cout << "Please enter hours scheduled for Tuesday: ";
	cin >> thours;
	cout << "Please enter hours scheduled for Wednesday: ";
	cin >> whours;
	cout << "Please enter hours scheduled for Thursday: ";
	cin >> thhours;
	cout << "Please enter hours scheduled for Friday: ";
	cin >> fhours;

	Schedule schedule(id, mhours, thours, whours, thhours, fhours);
	schedule.setID(id);

	cout << setw(15) << "Employee Schedule" << endl << endl;
	cout << "Emplyee ID\t" << "Monday Hours\t" << "Tuesday Hours\t" << "Wednesday Hours\t" << "Thursday Hours\t" << "Friday Hours" << endl;
	cout << schedule.getID() << "\t\t" << mhours << "\t\t" << thours << "\t\t" << whours << "\t\t" << thhours << "\t\t" << fhours << endl << endl;
}

// display employee
void EmployeeManagement::displayEmp() {
	string myOutput;
	ifstream myFile(FILENAME);

	while (getline(myFile, myOutput)) {
		cout << myOutput << endl;
	}
	myFile.close();
}

void EmployeeManagement::clearFile() {
	ofstream ofs;
	ofs.open(FILENAME, ofstream::out | ofstream::trunc);
	ofs.close();
}

HR::HR(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void HR::showInfo() {
	cout << "Employee number: " << this->m_Id
		<< "\tEmployee name: " << this->m_Name
		<< "\tDepartment: " << this->getDeptName()
		<< "\tJob Responsibilities: Complete the task assigned by the manager" << endl;
}

string HR::getDeptName() {
	return string("HR");
}

Sales::Sales(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Sales::showInfo() {
	cout << "Employee number: " << this->m_Id
		<< "\tEmployee name: " << this->m_Name
		<< "\tDepartment: " << this->getDeptName()
		<< "\tJob Responsibilities: Complete the task assigned by the manager" << endl;
}

string Sales::getDeptName() {
	return string("Sales");
}

Engineer::Engineer(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Engineer::showInfo() {
	cout << "Employee number: " << this->m_Id
		<< "\tEmployee name: " << this->m_Name
		<< "\tDepartment: " << this->getDeptName()
		<< "\tJob Responsibilities: Complete the task assigned by the manager" << endl;
}

string Engineer::getDeptName() {
	return string("Engineer");
}

Manager::Manager(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Manager::showInfo() {
	cout << "Employee number: " << this->m_Id
		<< "\tEmployee name: " << this->m_Name
		<< "\tDepartment: " << this->getDeptName()
		<< "\tJob Responsibilities: Assign Tasks to Employees" << endl;
}

string Manager::getDeptName() {
	return string("Management");
}

int main() {

	EmployeeManagement em;

	int choice = 0;

	while (true) {

		// display the main menu
		em.displayMenu();

		cout << "Please enter your choice: " << endl;
		cin >> choice;

		switch (choice) {
		case 0:
			// Exit management system
			em.exitSystem();
			break;
		case 1:
			// Add employee information 
			em.addEmployee();
			break;
		case 2:
			// Display employee information
			em.displayEmp();
			break;
		case 3:
			em.addSchedule();
			break;
		case 4:
			em.clearFile();
		default:
			system("cls");
			break;
		}


	}

	return 0;
}
