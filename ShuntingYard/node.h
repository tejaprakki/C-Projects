#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>

using namespace std;

class Node{
 public:
  Node(char*);
  char* getData();
  void setRight(Node*);
  void setLeft(Node*);
  void setNext(Node*);
  Node* getRight();
  Node* getLeft();
  Node* getNext();
  bool checkLeft();
  bool checkRight();
 private:
  Node* next = NULL;
  char* data;
  Node* left = NULL;
  Node* right = NULL;
};

#endif
