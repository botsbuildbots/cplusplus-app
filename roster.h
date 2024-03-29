#ifndef ROSTER_H
#define ROSTER_H
#include "degree.h"
#include "student.h"
#include <string>
using namespace std;

class Roster {
  private:
    // "static const int" is used to avoid magic number declaration
    static const int NUM_STUDENTS = 5;
    // store studentData[] here, then have constructor call Parse() to populate initial array
    // typos are intentional so PrintInvalidEmails() has actual work to do
    const string studentData[NUM_STUDENTS] = {
		  "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
		  "A2,Suzan,Erickson,Erickson_1990@ gmail.com,19,50,30,40,NETWORK",
		  "A3,Jack,Napoli,The_Lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		  "A5,Michael,Fowler,mfow119@wgu.edu,32,14,14,14,SOFTWARE"
	  };
    // declares a pointer that will store location of array of student objects
  public:
    int printCount = NUM_STUDENTS;
    Student* classRosterArray[NUM_STUDENTS];
    int targetIndex = 0;
    Roster();
    ~Roster();
    void Parse(string studentData);
    void Add(string studentID, string firstName, string lastName, string emailAddress, int age, 
      int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void Remove(string studentID);
    void PrintAll();
    void PrintAverageDaysInCourse(string studentID);
    void PrintInvalidEmails();
    void PrintByDegreeProgram(DegreeProgram degreeProgram);
};

#endif