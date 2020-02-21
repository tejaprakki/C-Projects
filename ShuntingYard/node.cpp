#include <iostream>
#include "node.h"

using namespace std;

Node::Node(char* tempData){
  data = tempData; //Pass in and set data 
}

char* Node::getData(){
  return data;//Return data
}

void Node::setLeft(Node * newLeft){
  left = newLeft;//Set input to left node
}

void Node::setRight(Node * newRight){
  right = newRight;//Set input to right node
}

void Node::setNext(Node* newNext){
  next = newNext;//Set the next to the input
}

Node * Node::getRight(){ //Return the node on the right
  return right;
}

Node * Node::getLeft(){ //Return the node on the left
  return left; 
}

Node* Node::getNext(){
  return next;
}

bool Node::checkLeft(){ //Check if there's a node on the left
  if (left != NULL){
    return true;
  }
  return false;
}

bool Node::checkRight(){ //Check if there's a node on the right
  if (right != NULL){
    return true;
  }
  return false;
}
