#include <iostream>
#include <string>

using namespace std;

class Employee{
public:
	string firstName;
	string lastName;
	double hoursWorked;
	
private:
	int id;
	
public: Employee(string FirstName, string LastName, int ID){
		firstName = FirstName;
		lastName = LastName;
		id = ID;
	
	void setID(int x){
		id = x;
	}
	int getID(){
		return id;
	}
}
	
};

class Salary : Employee{
	
};

class Hourly : Employee{
	
};

class EmployeeSchedule : Employee{
	
};

int main() {

	return 0;
}
