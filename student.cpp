#include "student.h"
#include <iostream>
using namespace std;

// no need for default constructor definition here
// constructor with parameters, assigns instance member variables with the values passed in arguments
Student::Student(string ID, string first, string last, string email, int age, int* days, DegreeProgram program) {
  this->studentID = ID;
  this->firstName = first;
  this->lastName = last;
  this->emailAddress = email;
  this->studentAge = age;
  // constructor is passed the pointer, assigns each index value of instance with matching index of argument
  this->daysInCourse[0] = days[0];
  this->daysInCourse[1] = days[1];
  this->daysInCourse[2] = days[2];
  this->degreeProgram = program;
}

//default destructor
Student::~Student() { }

// accessors
string Student::GetStudentID() const {
  return this->studentID;
}
string Student::GetFirstName() const {
  return this->firstName;
}
string Student::GetLastName() const {
  return this->lastName;
}
string Student::GetEmail() const {
  return this->emailAddress;
}
int Student::GetAge() const {
  return this->studentAge;
}
int* Student::GetDaysInCourse() {
  return this->daysInCourse;
}
DegreeProgram Student::GetDegreeProgram() const {
  return this->degreeProgram;
}

// mutators
void Student::SetStudentID(string ID) {
  this->studentID = ID;
}
void Student::SetFirstName(string first) {
  this->firstName = first;
}
void Student::SetLastName(string last) {
  this->lastName = last;
}
void Student::SetEmail(string email) {
  this->emailAddress = email;
}
void Student::SetAge(int age) {
  this->studentAge = age;
}
void Student::SetDaysInCourse(int* days) {
  this->daysInCourse[0] = days[0];
  this->daysInCourse[1] = days[1];
  this->daysInCourse[2] = days[2];
}
void Student::SetDegreeProgram(DegreeProgram program) {
  this->degreeProgram = program;
}

// print() does not need arguments, it will just use class accessors    
void Student::Print() {
  // this->GetDegreeProgram() should resolve to a value (0,1,2) that can be used to match one of these strings
  const char* EnumDeterminate[] = { "SECURITY", "NETWORK", "SOFTWARE" };

  // A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security
  // this->GetDaysInCourse()[index] should be the same as this.daysInCourse[index], hopefully
  cout << this->GetStudentID() << "\t First Name: " << this->GetFirstName() << "\t Last Name: "                  << 
          this->GetLastName() << "\t Age: " << this->GetAge() << "\t daysInCourse: { "                            << 
          this->GetDaysInCourse()[0] << ", " << this->GetDaysInCourse()[1] << ", " << this->GetDaysInCourse()[2] <<
          " } Degree Program: " << EnumDeterminate[this->GetDegreeProgram()]                                      << endl;
}