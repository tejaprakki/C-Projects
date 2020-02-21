#include <iostream>
#include <cstring>
#include "list.h"
#include "node.h"
#include "shunting.h"

using namespace std;

Shunting::Shunting(){ //Constructor
  List* inputQueue = new List();
}
void Shunting::infix(Node* subtree){
  if (isOperator(*subtree->getData())){ //If the data is an operator
    cout << "("; //Add an open parenthesis
  }
  if (subtree->getLeft() != NULL){ //If there's a node on the left...
    infix(subtree->getLeft()); //Use recursion
  }
  
  cout << subtree->getData() << ""; //Print the node using infix
  
  if (subtree->getRight() != NULL){ //If there's a node on the right...
    infix(subtree->getRight()); //Use recursion again
  }
  if (isOperator(*subtree->getData())){ //If it's an operator...
    cout << ")";//Add a closed parenthesis
  }
}
void Shunting::postfix(Node* subtree){ //Do same as above with infix when it comes to using recursion etc.
  if (subtree->checkLeft()){ 
    postfix(subtree->getLeft());
  }
  if(subtree->checkRight()){
    postfix(subtree->getRight());
  }
  cout << subtree->getData() << " "; //Print node using postfix
}
void Shunting::prefix(Node* subtree){ //Do the same as above with infix and postfix when it comes to using recursion etc.0
  cout << subtree->getData() << " "; //Print node
  if (subtree->getLeft() != NULL){
    prefix(subtree->getLeft());
  }
  if(subtree->getRight() != NULL){
    prefix(subtree->getRight());
  }
}
List* Shunting::getQueue(){
  return inputQueue; //Return the input queue
}
void Shunting::setQueue(List * newQueue){
  inputQueue = newQueue; //Sets the input into the list queue
}
bool Shunting::isOperator(char data){ //Check for an operator in node
  if (data == '+' || data == '-' || data == '/' || data == '*' || data == '^' || data == ')' || data == '(') {
      return true;
    }
  return false; //if not those characters, it's not an operator
}
int Shunting::precedence(char data){ //Assign precedence
  if (data == '^'){
    return 4; //Highest precedence
  }
  else if (data == '*' || data == '/'){
    return 3; //Middle precedence
  }
  else if (data == '+' || data == '-'){
    return 2; //Lowest precedence
  }
  else{
    return 1; //This means it's not an operator
  }
}
