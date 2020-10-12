#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
	string firstName;
	string lastName;
	double hoursScheduled;
	double hoursWorked;
	int type;
private:
	int id;

public: Employee(string FirstName, string LastName, int ID) {
	firstName = FirstName;
	lastName = LastName;
	id = ID;
}
	  void setID(int x) {
		  id = x;
	  }
	  int getID() {
		  return id;
	  }	  
	  int setEmployeeType(int x) {
		  type = x;

		  return type;
	  }
};

class printSchedule {
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
	double hourlyRate;	
	//tax rate for hourly employees is 0.04
	double calcWage
};

int main() {

	return 0;
}
