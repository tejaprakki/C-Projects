#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

class Student{
 public:
  Student(const char*, int, float); //Constructor
  ~Student(); //Destructor
  char* getName(); //Return the name of the student
  int getID(); //Return the ID
  float getGPA(); //Return the GPA
 private:
  char* name = new char[50]; //Name of the student
  int id; //ID of the student
  float gpa; //GPA of student
};

#endif
