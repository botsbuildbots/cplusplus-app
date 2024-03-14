#ifndef ROSTER_H
#define ROSTER_H
#include "degree.h"
#include "student.h"
#include <string>
using namespace std;

class Roster {
  private:
    // declares an array of pointers with an undefined size, this will be populated with pointers to Student class instances
    Student** classRosterArray = { nullptr };
  public:
    // constructor takes in the number of students to be added to the array
    Roster(int studentCount);
    ~Roster();
};

#endif