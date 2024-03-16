#include "student.h"
#include "roster.h"
#include <iostream>
using namespace std;

Roster::Roster(string studentData) {
  // constructor should parse studentData to populate array on creation
 }
// default destructor
Roster::~Roster() { 
  delete[] classRosterArray;
}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, 
  int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    // Student constructor needs the memory address of an int array, so create one here for daysInCourse parameters
    // numDaysInCourse should be passed to new Student(parameters)
    int *numDaysInCourse = new int[3];
    numDaysInCourse[0] = daysInCourse1;
    numDaysInCourse[1] = daysInCourse2;
    numDaysInCourse[2] = daysInCourse3;
    // Add() should only create a single instance at a specific classRosterArray[targetIndex] location
    // classRosterArray[targetIndex] determination needs to happen elsewhere
    // could Add() could check to see if classRosterArray[targetIndex] is occupied first?
  }
void Roster::Remove(string studentID) { 
  // this should for-loop Student objects for matching member value, then remove object
  // check and return an error if the specified object is not found
  // leave slot empty to create new instance later
}
void Roster::PrintAll() { 
  // for-loop through Student instances and print all available (create message to print for empty indexes)
}
void Roster::PrintAverageDaysInCourse(string studentID) {
  // same as Remove(), check for matching Student object and average out 
 }
void Roster::PrintInvalidEmails() {
  // check Student instances for invalid emails, print results
 }
void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) { 
  // check Student instances for matching DegreeProgram, print results
}