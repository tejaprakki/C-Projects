#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

Node::Node(Student*){
  student = NULL;
  next = NULL;
}

Node::~Node(){
  delete &student;
  next = NULL;
}

void Node::setStudent(Student* newStudent){
  student = newStudent;
}

Student* Node::getStudent(){
  return student;
}

void Node::setNext(Node* newNext){
  next = newNext;
}

Node* Node::getNext(){
  return next;
}
