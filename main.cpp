#include "student.h"
#include "roster.h"
#include <iostream>
using namespace std;

int main() {
  // traditionally main() returns an int = 0 for a successful run, is it good practice to return that value here?
  // set a default int = 1 and only change it on successful completion?

	// printed requirements for assignment: course title, programming language/IDE, studentID, name
	cout << "Scripting and Programming Applications C867" << endl;
	cout << "Written in C++ using Visual Studio Code" << endl;
	cout << "WGU Student ID: 011687882" << endl;
	cout << "WGU Student Name: Michael Fowler" << endl << endl << endl;

	// declares instance of Roster class to generate Student objects
	Roster classRoster;
	classRoster.PrintAll();
	cout << endl;
	classRoster.PrintInvalidEmails();

	for (int i = 0; i < 5; ++i) {
		classRoster.PrintAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
	}
	cout << endl;

	classRoster.PrintByDegreeProgram(SOFTWARE);
	cout << endl;

	classRoster.Remove("A3");
	classRoster.PrintAll();
	cout << endl;
	classRoster.Remove("A3");

	// waits for user input before continuing, use this to halt program for debug
	system("pause");
}