#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

class List{
 public:
  List();
  void push(Node*);
  void pop();
  Node* peek();
  void dissociate();  
  void enqueue(Node*); //Add the node to the end of list
  void dequeue(); //Remove the node from front of list
  bool isEmpty();
  //bool isFull();
  Node* getHead();//Return head
  Node* getTail();//Return tail
 private:
  Node* head = NULL;
  Node* tail = NULL;
};

#endif
