#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <string>
using namespace std;

class Student {
  public:
    string GetStudentID() const;
    string GetFirstName() const;
    string GetLastName() const;
    string GetEmail() const;
    int GetAge() const;
    // how do you create a getter for an array member?
    // int GetDaysInCourse();
    void SetStudentID(string ID);
    void SetFirstName(string first);
    void SetLastName(string last);
    void SetEmail(string email);
    void SetAge(int years);
    // how do you create a setter for an array member?
    // void SetDaysInCourse();
    void SetDegreeProgram(DegreeProgram program);
  // member variables should not be adjusted outside of mutators/accessors
  private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;
};

#endif