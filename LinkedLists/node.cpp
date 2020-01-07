#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

Node::Node(Student*){
  student = NULL; //set Student to null
  next = NULL; //and next to null
}

Node::~Node(){
  delete &student; //delete the student value
  next = NULL; //sets next to null again
}

void Node::setStudent(Student* newStudent){ //set up the student
  student = newStudent; //sets student to the input
}

Student* Node::getStudent(){ //return the student
  return student; //returns student
}

void Node::setNext(Node* newNext){ //get the next node
  next = newNext; //set next to inputed node
}

Node* Node::getNext(){ //returns the next node
  return next; //return next
}
