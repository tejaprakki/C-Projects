#include <iostream>
#include "list.h"
#include "node.h"

List::List(){ //Constructor
  
}
void List::push(Node* newNode){ //Adding a node to the front of the list
  if(isEmpty()){ //Empty the list
    head = newNode; 
    tail = newNode;
  }
  else{
    newNode->setNext(head);
    head = newNode; //Set the newNode to the head
  }
}
void List::pop(){ //Delete the node from the list or "pop the node"
  if (!isEmpty()){ //If the list has content in it
    Node* temp = head; //Create a temporary pointer to hold information
    head = head->getNext();
    delete temp;
  }
  if (head == 0){ //If the head is null
    head = 0;
    tail = 0;
  }
}
void List::dissociate(){ //This does the same as the pop function, but it doesn't delete the Node like pop does
  if (!isEmpty()){
    head = head->getNext();
  }
  if (head == 0){
    head = 0;
    tail = 0;
  }
}
Node* List::peek(){ //Look at the head
  return head;
}
void List::enqueue(Node* newNode){ //Add the node to the tail of the list
  if(isEmpty()){
    head = newNode; //Set the head and tail to a new node
    tail = newNode;
  }
  else{ //Else, set the new node as the tail
    tail->setNext(newNode); 
    tail = newNode;
  }
}
void List::dequeue(){ //Does essentially the same thing as pop
  if (!isEmpty()){
    Node* temp = head;
    head = head->getNext();
    delete temp;
  }
  if (isEmpty()){
    head = 0;
    tail = 0;
  }
}
bool List::isEmpty(){ //Check in the list to see if it's empty
  if (head == 0){
    tail = 0;
    return true;
  }
  return false;
}
Node* List::getHead(){ //Return the head
  return head;
}
Node* List::getTail(){ //Return the tail
  return tail;
}
