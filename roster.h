#ifndef ROSTER_H
#define ROSTER_H
#include "degree.h"
#include "student.h"
#include <string>
using namespace std;

class Roster {
  private:
    // declares a pointer that will be used to build array of student objects
    // "static const int" is used to avoid magic number declaration, could use count parameter for variable size later
    static const int NUM_STUDENTS = 5;
    Student *classRosterArray[NUM_STUDENTS];
  public:
    // use classRosterArray[targetIndex] in main.cpp to specify where to add the student
    int targetIndex = 0;
    // store studentData[] in main.cpp, then have Roster() parse studentData when creating instance
    Roster(string studentData);
    ~Roster();
    void Add(string studentID, string firstName, string lastName, string emailAddress, int age, 
      int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void Remove(string studentID);
    void PrintAll();
    void PrintAverageDaysInCourse(string studentID);
    void PrintInvalidEmails();
    void PrintByDegreeProgram(DegreeProgram degreeProgram);
};

#endif