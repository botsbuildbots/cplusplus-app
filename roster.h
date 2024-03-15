#ifndef ROSTER_H
#define ROSTER_H
#include "degree.h"
#include "student.h"
#include <string>
using namespace std;

class Roster {
  private:
    // declares a pointer that will be used to build array of student objects
    Student *classRosterArray;
  public:
    // constructor takes in the number of students to be added to the array, should create array for classRosterArray with that count
    // classRosterArray = new Student[studentCount];
    // alternatively just delcare classRosterArray with five students and then have add() create new Student and place at each index then ++index
    Roster(int studentCount);
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