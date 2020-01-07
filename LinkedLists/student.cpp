#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student(const char* setName, int studentID, float studentGPA){
  strcpy(name, setName); //Set name to input
  id = studentID; //ID to imput
  gpa = studentGPA; //GPA to input
}

Student::~Student(){ //destructor
  delete name;
}

char* Student::getName(){ //returns name to student
  return name; //return name
}

int Student::getID(){ //returns id to student
  return id; //return id
}

float Student::getGPA(){ //return gpa to student
  return gpa; //return gpa
}
