#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student(const char* setName, int studentID, float studentGPA){ //Constructor
  strcpy(name, setName); //Set the name to the given input
  id = studentID; //Set the ID to the given input
  gpa = studentGPA; //Set the GPA to the given input
}

Student::~Student(){ //Destructor
  delete name;
}

char* Student::getName(){ //Return the name of the student
  return name; //Return the name
}

int Student::getID(){ //Return the ID of the student
  return id; //Return the ID
}

float Student::getGPA(){ //Return the GPA of the Student
  return gpa; //Return the GPA
}
