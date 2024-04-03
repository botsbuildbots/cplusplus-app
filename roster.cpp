#include "student.h"
#include "roster.h"
#include <iostream>
using namespace std;

Roster::Roster() {
  for (int i = 0; i < NUM_STUDENTS; ++i) {
        Parse(studentData[i]);
  }
 }

// student instances are created with "new" so they need to be deleted after program completion
Roster::~Roster() {
    for (int i = 0; i < printCount; ++i) {
        delete classRosterArray[i];
    }
}

void Roster::Parse(string studentData) {
  // Set ints for left bound and right bound, use find() to target the commas, then use substr() to extract the difference
  // Store substr() results into temp local variables, then send those over to Add()
    size_t left = 0;
    size_t right = 0;
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

    left = right + 1;
    right = studentData.find(",", left);
    string programHolder = studentData.substr(left, right - left);
    DegreeProgram degreeProgram;
    if (programHolder == "SECURITY") {
        degreeProgram = SECURITY;
    }
    else if (programHolder == "NETWORK") {
        degreeProgram = NETWORK;
    }
    else {
        degreeProgram = SOFTWARE;
    }

    Add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age,
    int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    // Student constructor needs the memory address of an int array, so create one here for daysInCourse parameters
    int *numDaysInCourse = new int[3];
    numDaysInCourse[0] = daysInCourse1;
    numDaysInCourse[1] = daysInCourse2;
    numDaysInCourse[2] = daysInCourse3;
    // Add() creates a single student object at targetIndex, then targetIndex increases by one for the next iteration
    classRosterArray[targetIndex] = new Student(studentID, firstName, lastName, emailAddress, age, numDaysInCourse, degreeProgram);
    ++targetIndex;
    delete[] numDaysInCourse;
}

void Roster::Remove(string studentID) { 
    int indexToRemove = 0;
    // use boolean to filter between an if/else statement for student removal or error message
    bool foundStudent = false;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            indexToRemove = i;
            foundStudent = true;
        }
    }
    if (foundStudent == true) {
        delete classRosterArray[indexToRemove];
        for (int j = indexToRemove; j < NUM_STUDENTS - 1; ++j) {
            classRosterArray[j] = classRosterArray[j + 1];
        }
        --printCount;
    }
    else {
        cout << "An entry for Student \"" << studentID << "\" was not found." << endl;
    }
}

void Roster::PrintAll() { 
  for (int i = 0; i < printCount; ++i) {
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
    cout << "The average of the days left in each course for Student " << studentID << " is: " << average << endl;
}

void Roster::PrintInvalidEmails() {
    // valid email addresses must have '@' and '.' characters, must not have ' '
    // find() returns -1 (or npos) if specific character is not found
    cout << "Checking for valid student email addresses:" << endl;
    string testString;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        testString = classRosterArray[i]->GetEmail();
        if (testString.find("@") == -1 || testString.find(".") == -1 || testString.find(" ") != -1) {
            cout << "Student " << classRosterArray[i]->GetStudentID() << " does not have a valid email address on file." << endl;
            cout << "\"" << testString << "\" is not a valid email address." << endl << endl;
        }
    }
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
    DegreeProgram compareProgram;
    cout << "The following students are currently registered in the specified degree program:" << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        compareProgram = classRosterArray[i]->GetDegreeProgram();
        if (compareProgram == degreeProgram) {
            classRosterArray[i]->Print();
        }
    }
}