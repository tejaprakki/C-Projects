#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

class Student{
 public:
  Student(const char*, int, float);
  ~Student();
  char* getName();
  int getID();
  float getGPA();
 private:
  char* name = new char[50];
  int id;
  float gpa;
};

#endif
