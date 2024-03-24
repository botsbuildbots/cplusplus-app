#include "student.h"
#include "roster.h"
#include <iostream>
using namespace std;

Roster::Roster() {
  // constructor should call Parse() on studentData to populate array during creation
  // then Parse() will call Add() to add instances to array
  // this leaves Add() open for independent calls after Roster is populated initially
  for (int i = 0; i < NUM_STUDENTS; ++i) {
        Parse(studentData[i]);
  }
 }

Roster::~Roster() {
  // remember to clean up classRosterArray memory before program completes 
  delete[] classRosterArray;
}

void Roster::Parse(string studentData) {
  // Parse() should work through a single index of studentData[] and call Add() for that line to populate classRosterArray
  // Set ints for left bound and right bound, use find() to target the commas, then use substr() to extract the difference
  // Store substr() results into temp local variables, then push those to Add()
    int left = 0;
    int right = 0;
    right = studentData.find(",");
    string studentID = studentData.substr(0, right);
    left = right + 1;
    right = studentData.find(",", left);
    string firstName = studentData.substr(left, right - left);
    left = right + 1;
    right = studentData.find(",", left);
    string lastName = studentData.substr(left, right - left);
    left = right + 1;
    right = studentData.find(",", left);
    string emailAddress = studentData.substr(left, right - left);
    left = right + 1;
    right = studentData.find(",", left);

    // age and daysInCourse1,2,3 need to be sent to Add() as ints, so use stoi() on substr() results
    int age = stoi(studentData.substr(left, right - left));
    left = right + 1;
    right = studentData.find(",", left);
    int daysInCourse1 = stoi(studentData.substr(left, right - left));
    left = right + 1;
    right = studentData.find(",", left);
    int daysInCourse2 = stoi(studentData.substr(left, right - left));
    left = right + 1;
    right = studentData.find(",", left);
    int daysInCourse3 = stoi(studentData.substr(left, right - left));

    // switch statement for degreeProgram, case: "NETWORK" degreeProgram = NETWORK
    left = right + 1;
    right = studentData.find(",", left);
    string programHolder = studentData.substr(left, right - left);
    DegreeProgram degreeProgram;
    switch (programHolder) {
        case "SECURITY":
            degreeProgram = SECURITY;
            break;
        case "NETWORK":
            degreeProgram = NETWORK;
            break;
        case "SOFTWARE":
            degreeProgram = SOFTWARE;
            break;
    }

    Add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
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
    classRosterArray[targetIndex] = new Student(studentID, firstName, lastName, emailAddress, age, numDaysInCourse, degreeProgram);
    // classRosterArray[targetIndex] determination needs to be set in main() for each consecutive call of Add()
    // since numDaysInCourse is dynamically allocated it needs to be deleted later
    delete[] numDaysInCourse;
}

void Roster::Remove(string studentID) { 
  // this should for-loop Student objects for matching member value, then remove object
  // check and return an error if the specified object is not found
  // leave slot empty to create new instance later
}

void Roster::PrintAll() { 
  // for-loop through Student instances and print all available
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        classRosterArray[i]->Print();
    }
}

void Roster::PrintAverageDaysInCourse(string studentID) {
    int *targetArray;
    int average = 0;
    // loop through classRosterArray to find Student instance with matching studentID value
    // if matching value is found, grab pointer to daysInCourse array for that student instance
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            targetArray = classRosterArray[i]->GetDaysInCourse();
        }
    }
    average = (targetArray[0] + targetArray[1] + targetArray[2]) / 3;
    cout << average << endl;
}

void Roster::PrintInvalidEmails() {
    // loop through classRosterArray, store the emailAddress to temp local variable
    // run tests on that temp local string, if email address is invalid print message to console
    string testString;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        testString = classRosterArray[i]->GetEmail();
        if ( /*some string test mechanism*/ ) {
            /*some printed text to console*/
        }
    }
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
    // loops through classRosterArray, if degreeProgram value matches parameter call Print() on Student instance
    DegreeProgram compareProgram;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        compareProgram = classRosterArray[i]->GetDegreeProgram();
        if (compareProgram == degreeProgram) {
            classRosterArray[i]->Print();
        }
    }
}