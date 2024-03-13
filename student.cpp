#include "student.h"
#include <iostream>
using namespace std;

//default constructor
Student::Student() { }

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