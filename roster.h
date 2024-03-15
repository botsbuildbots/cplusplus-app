#ifndef ROSTER_H
#define ROSTER_H
#include "degree.h"
#include "student.h"
#include <string>
using namespace std;

class Roster {
  private:
    // declares a pointer that will be used to build array of student objects
    // "static const int" is just to avoid magic number declaration, could use count parameters later
    static const int NUM_STUDENTS = 5;
    Student *classRosterArray[NUM_STUDENTS];
  public:
    // Just declare classRosterArray with five students, have add() create new Student and place at each index, then ++index
    Roster();
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