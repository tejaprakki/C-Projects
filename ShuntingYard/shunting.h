#ifndef SHUNTING_H
#define SHUNTING_H

#include <iostream>
#include <cstring>
#include "list.h"
#include "node.h"

using namespace std;

class Shunting{
 public:
  Shunting();
  List* getQueue();
  void setQueue(List*);
  void doPostfix();
  void makeTree(List*);
  void infix(Node*);
  void postfix(Node*);
  void prefix(Node*);
 private:
  bool isOperator(char); //Operator check
  int precedence(char); //Precedence check
  List* stack; //Output stack linked list
  List* operatorStack; //Operator stack linked list
  List* inputQueue; //Input queue linked list
};

#endif
