#include <iostream>
#include "Header.h"
#include "Engineer.h"
#include "Manager.h"
#include "Sales.h"
#include "HR.h"
#include "Employee.h"

// We Just need to make some changes to make a tad bit simpler, but it does what we need it to do.
// Also if we add salary information and an employee schedule I think we'll be good. I already edited some of it but we can take out parts if we need to


using namespace std;

EmployeeManagement::EmployeeManagement() {
	// the file doesn't exist
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()) {
		//cout << "The file doesn't exist!" << endl;

		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_IsFileEmpty = true;

		ifs.close();
		return;
	}

	// the file exist, no data
	char ch;
	ifs >> ch;

	if (ifs.eof()) {
		//cout << "The file is empty!" << endl;

		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_IsFileEmpty = true;

		ifs.close();
		return;
	}

	// the file exists and have employee information
	int num = this->getEmpNum();
	//cout << "The number of employee is: " << num << endl;
	this->m_EmpNum = num;

	// allocate memory
	this->m_EmpArray = new Employee * [this->m_EmpNum];

	// Save the data in the file to an array
	this->initEmp();

}

// display the main menu
void EmployeeManagement::displayMenu() {
	cout << "*******************************************************************" << endl;
	cout << "**********   Welcome to employee management system!   *************" << endl;
	cout << "***************   0. Exit management system!       ****************" << endl;
	cout << "***************   1. Add employee information      ****************" << endl;
	cout << "***************   2. Display employee information  ****************" << endl;
	cout << "***************   3. Delete employee information   ****************" << endl;
	cout << "***************   4. Modify employee information   ****************" << endl;
	cout << "***************   5. Search employee information   ****************" << endl;
	cout << "***************   6. Sort by employee ID           ****************" << endl;
	cout << "***************   7. Clear all employees           ****************" << endl;
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
		// Calculate the size for the new space
		int newSize = this->m_EmpNum + addNum;

		// allocate memory
		Employee** newSpace = new Employee * [newSize];

		// Copy the data to the new space
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++)
				newSpace[i] = this->m_EmpArray[i];
		}

		// add new data
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int department;

			cout << "Please enter the working ID for employee " << i + 1 << " : " << endl;
			cin >> id;

			cout << "Please enter the name for employee " << i + 1 << " : " << endl;
			cin >> name;

			cout << "Please select the position for the employee: " << endl;
			cout << "1. HR" << endl;
			cout << "2. Sales" << endl;
			cout << "3. Engineer" << endl;
			cout << "4. Mangement" << endl;
			cin >> department;

			Employee* employee = NULL;

			switch (department) {
			case 1:
				employee = new HR(id, name, department);
				break;
			case 2:
				employee = new Sales(id, name, department);
				break;
			case 3:
				employee = new Engineer(id, name, department);
				break;
			case 4:
				employee = new Manager(id, name, department);
				break;
			default:
				break;
			}

			newSpace[this->m_EmpNum + i] = employee;
		}

		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;

		this->m_EmpNum = newSize;

		// Save data to file 
		this->save();
		this->m_IsFileEmpty = false;

		cout << "Successfully add" << addNum << "new employee!" << endl;
	}
	else
		cout << "Incorrect input data!" << endl;

	system("pause");
	system("cls");
}

// save file
void EmployeeManagement::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->getDeptName() << endl;
	}

	ofs.close();
}

// get the number of employee in the file
int EmployeeManagement::getEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	string deptName;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> deptName) {
		num++;
	}

	return num;
}

// Initialize employee
void EmployeeManagement::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	string deptName;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> deptName) {
		Employee* employee = NULL;

		if (deptName == "HR")
			employee = new HR(id, name, 1);
		else if (deptName == "Sales")
			employee = new Sales(id, name, 2);
		else if (deptName == "Engineer")
			employee = new Engineer(id, name, 3);
		else if (deptName == "Managment")
			employee = new Manager(id, name, 4);

		this->m_EmpArray[index++] = employee;
	}

	ifs.close();
}

// display employee
void EmployeeManagement::displayEmp() {
	if (this->m_IsFileEmpty)
		cout << "The file doesn't exist or the record is empty!" << endl;
	else
		for (int i = 0; i < this->m_EmpNum; i++)
			this->m_EmpArray[i]->showInfo();

	// press any key to clear the screen 
	system("pause");
	system("cls");
}

// delete employee
void EmployeeManagement::delEmp() {
	if (this->m_IsFileEmpty)
		cout << "The file doesn't exist or the record is empty!" << endl;
	else {
		cout << "Please enter the employee number you want to delete: " << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);
		if (index != -1) {
			for (int i = index; i < this->m_EmpNum - 1; i++)
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			this->m_EmpNum--;
			this->save();
			cout << "Delete employee successfully!" << endl;

		}
		else
			cout << "Delete failed, can't find this employee!" << endl;
	}

	system("pause");
	system("cls");
}

// check if an employee exists, if exists return the index in the array, or return -1
int EmployeeManagement::isExist(int id) {
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			index = i;
			break;
		}
	}

	return index;
}

// modify employee
void EmployeeManagement::modifyEmp() {
	if (this->m_IsFileEmpty)
		cout << "The file doesn't exist or the record is empty!" << endl;
	else {
		cout << "Please enter the ID of employee you want to modify: " << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1) {
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int deptSelect = 0;

			cout << "Find the employee with ID " << id << ", please enter the new employee ID: " << endl;
			cin >> newId;

			cout << "Please enter the new name: " << endl;
			cin >> newName;

			cout << "Please select the position for the employee: " << endl;
			cout << "1. HR" << endl;
			cout << "2. Sales" << endl;
			cout << "3. Engineer" << endl;
			cout << "5. Management" << endl;
			cin >> deptSelect;

			Employee* employee = NULL;

			switch (deptSelect) {
			case 1:
				employee = new HR(newId, newName, deptSelect);
				break;
			case 2:
				employee = new Sales(newId, newName, deptSelect);
				break;
			case 3:
				employee = new Engineer(newId, newName, deptSelect);
				break;
			case 4:
				employee = new Manager(newId, newName, deptSelect);
				break;
			default:
				break;
			}

			this->m_EmpArray[ret] = employee;
			cout << "Modify successfully!" << endl;
			this->save();

		}
		else
			cout << "Can't find this employee!" << endl;
	}

	system("pause");
	system("cls");
}

// find employee
void EmployeeManagement::findEmp() {
	if (this->m_IsFileEmpty)
		cout << "The file doesn't exist or the record is empty!" << endl;
	else {
		cout << "Please enter the search methods: " << endl;
		cout << "1. Search by employee ID" << endl;
		cout << "2. Search by employee name" << endl;

		int select = 0;
		cin >> select;

		if (select == 1) {
			// find employee by ID
			cout << "Please enter the employee ID you want to find: " << endl;
			int id;
			cin >> id;

			int ret = isExist(id);
			if (ret != -1) {
				cout << "Find the employee with ID " << id << ": " << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
				cout << "Can't find this employee!" << endl;
		}
		else if (select == 2) {
			// find employee by name
			cout << "Please enter the employee name you want to find: " << endl;
			string name;
			cin >> name;
			bool flag = false;

			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					cout << "Find the employee with ID "
						<< this->m_EmpArray[i]->m_Id
						<< ", the employee information: " << endl;

					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}

			if (flag == false)
				cout << "Can't find this employee!" << endl;
		}
		else
			cout << "Please enter the correct search methods!" << endl;
	}

	system("pause");
	system("cls");
}

// sort employee by ID
void EmployeeManagement::sortEmp() {
	if (this->m_IsFileEmpty) {
		cout << "The file doesn't exist or the record is empty!" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "Please select the sorting method: " << endl;
		cout << "1. Sort by employee ID in ascending order" << endl;
		cout << "2. Sort by employee ID in descending order" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum - 1; i++) {
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++) {
				// ascending order
				if (select == 1) {
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
						minOrMax = j;
				}
				else {
					// descending order
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
						minOrMax = j;
				}
			}

			if (i != minOrMax) {
				Employee* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}

		this->save();
		cout << "Sort successfully, the employee information after sorting is: " << endl;
		this->displayEmp();

	}

}

// clear file
void EmployeeManagement::clearFile() {
	cout << "Are you sure you want to clear all the employee information?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;

	int select;
	cin >> select;

	if (select == 1) {
		// Recreate file after deleting the file
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}

			}

			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_IsFileEmpty = true;
		}

		cout << "Clear all the employee information sucessfully!" << endl;
	}

	system("pause");
	system("cls");
}

EmployeeManagement::~EmployeeManagement() {
	if (this->m_EmpArray != NULL) {
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i] != NULL)
				delete this->m_EmpArray[i];
		}

		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
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
		<< "\tJob Responsibilities: Complete the task assigned by the manager" << endl;
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
			// Delete employee information
			em.delEmp();
			break;
		case 4:
			// Modify employee information
			em.modifyEmp();
			break;
		case 5:
			// Search employee information
			em.findEmp();
			break;
		case 6:
			// Sort by number
			em.sortEmp();
			break;
		case 7:
			// clear file
			em.clearFile();
			break;
		default:
			system("cls");
			break;
		}


	}

	return 0;
}
