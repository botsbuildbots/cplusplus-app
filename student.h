#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <string>
using namespace std;

class Student {
  // per assignment requirements member variables should not be adjusted outside of mutators/accessors
   private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int studentAge;
    int daysInCourse[3];
    DegreeProgram degreeProgram;
  public:
    // constructor with parameters
    Student(string ID, string first, string last, string email, int age, int* days, DegreeProgram program);
    // destructor
    ~Student();
    // accessors
    string GetStudentID() const;
    string GetFirstName() const;
    string GetLastName() const;
    string GetEmail() const;
    int GetAge() const;
    int* GetDaysInCourse();  // overthought this, the accessor should just return the pointer to location
    DegreeProgram GetDegreeProgram() const;
    // mutators
    void SetStudentID(string ID);
    void SetFirstName(string first);
    void SetLastName(string last);
    void SetEmail(string email);
    void SetAge(int age);
    void SetDaysInCourse(int* days);  // overthought this, the parameter just tells the function where to make the changes
    void SetDegreeProgram(DegreeProgram program);
    void Print();
};

#endif