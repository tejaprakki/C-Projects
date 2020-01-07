#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student(const char* setName, int studentID, float studentGPA){
  strcpy(name, setName);
  id = studentID;
  gpa = studentGPA;
}

Student::~Student(){
  delete name;
}

char* Student::getName(){
  return name;
}

int Student::getID(){
  return id;
}

float Student::getGPA(){
  return gpa;
}
