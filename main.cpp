#include "student.h"
#include "roster.h"
#include <iostream>
using namespace std;

int main() {

	// printed requirements for assignment: course title, programming language/IDE, studentID, name
	cout << "Scripting and Programming Applications C867" << endl;
	cout << "Written in C++ using Visual Studio Code" << endl;
	cout << "WGU Student ID: 011687882" << endl;
	cout << "WGU Student Name: Michael Fowler" << endl << endl << endl;

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

}