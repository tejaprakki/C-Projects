#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

class Node{
public:
  Node(Student*);
  ~Node();
  void setStudent(Student*);
  Student* getStudent();
  void setNext(Node*);
  Node* getNext();
private:
  Student* student;
  Node* next;
};

#endif
