#include <iostream>
#include <string>


using namespace std;

class Employee {
public:
	string firstName;
	string lastName;
	double hoursWorked;
	int id;
	int type;
	void getEmpData();
private:
	double hoursScheduled;

public: Employee(string FirstName, string LastName, int ID) {
	firstName = FirstName;
	lastName = LastName;
	id = ID;
}
	  int setEmployeeType(int x) {
		  type = x;

		  return type;
	  }
};

class printSchedule { //This needs to be developed
private:
	string dayName;
	int day;
	string shift;
	double shifthours;
};

class Salary : public Employee {
public: 
	double salaryRate;

	double calcSalary(double x) {
		Employee::hoursWorked = x;

		double netPay = salaryRate * x;
		double taxes = netPay * 0.10; //tax rate for salaried employees is 0.10

	}
};

class Hourly : public Employee{
public:
	double hourlyRate; //tax rate for hourly employees is 0.04

	double calcWage = hourlyRate * hoursWorked;
};

void Employee::getEmpData() {
	int n{ 0 };
	cout << "Enter Employee's first name: ";
	cin >> firstName;
	cout << "\nEnter Employee's last name: ";
	cin >> lastName;
	cout << "\nEnter Employee's ID: ";
	cin >> id;
	cout << "/nEnter Employee type 0 for hourly and 1 for salary: ";
	cin >> n;
	setEmployeeType(n);
}

int main() {

	return 0;
}
