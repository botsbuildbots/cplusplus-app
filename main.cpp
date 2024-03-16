#include "student.h"
#include "roster.h"
#include <iostream>
using namespace std;

int main() {
  // traditionally main() returns an int = 0 for a successful run, is it good practice to return that value here?
  // set a default int = 1 and only change it on successful completion?
  const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_Lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Michael,Fowler,mfow119@wgu.edu,32,14,14,14,SOFTWARE"
	};
}