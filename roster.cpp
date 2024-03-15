#include "roster.h"
#include "student.h"
#include <iostream>
using namespace std;

// default constructor
Roster::Roster() { }
// default destructor
Roster::~Roster() { }

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, 
  int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) { 
    // Add() needs to have a line like classRosterArray[index] = new Student(parameters), then ++index
  }
void Roster::Remove(string studentID) { 
  // this should check Student objects for matching member value, then remove object
}
void Roster::PrintAll() { }
void Roster::PrintAverageDaysInCourse(string studentID) { }
void Roster::PrintInvalidEmails() { }
void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) { }