#pragma once
#include <iostream>
#include <string>

using namespace std;

class Schedule {
public:Schedule(int ID, double MonHours, double TueHours, double WedHours, double ThuHours, double FriHours) {
	id = ID;
	monhours = MonHours;
	tuehours = TueHours;
	wedhours = WedHours;
	thuhours = ThuHours;
	frihours = FriHours;
}
	  int getID() {
		  return id;
	  }

	  void setID(int ID) {
		  id = ID;
	  }

public:
	double monhours;
	double tuehours;
	double wedhours;
	double thuhours;
	double frihours;

private:
	int id;

};
