#include <iostream>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <ctype.h>

#include "node.h"
#include "list.h"
#include "shunting.h"

using namespace std;

/*
  Code by Teja Prakki
  This code runs a Shunting Yard algorithm that converts equations with spaces into infix, prefix, and postfix.
*/

void Shunting::doPostfix(){ //Postfix code
  List* stack = new List();
  List* opStack = new List();
  
  while (!inputQueue->isEmpty()){
    
    char* headData = inputQueue->getHead()->getData(); //Store the head's data
    
    if (!isOperator(*headData)){ //Push head to stack if the first char isn't an operator
      Node* newNode = new Node(headData);
      stack->push(newNode);
      inputQueue->dequeue();
    }
    else{ //If it is an operator
      if (*headData == '('){ //If they are paranthesis
	Node* newNode = new Node(headData); //Push it to the opStack
	opStack->push(newNode);
	inputQueue->dequeue();
      }
      else if(*headData != ')'){ //If it's not a closed paranthesis
	int pres = precedence(*headData); 
	if (opStack->peek() != NULL){ //If the opStack isn't empty
	  if (pres != 1){ //And if the precedence is 2, 3, or 4
	    while(opStack->peek() != NULL && precedence(*opStack->peek()->getData()) > pres){ //And while there is nothing in opstack and the precedence is higher, push to the top
	      Node* newNode = new Node(opStack->peek()->getData()); //Push the top of the opStack to the stack
	      stack->push(newNode);
	      opStack->pop();
	    }
	    Node* newNode = new Node(headData); //Push the new operator to the stack
	    opStack->push(newNode);
	    inputQueue->dequeue();
	  }
	}
	else{ //If the opStack is empty
	  Node* newNode = new Node(headData);
	  opStack->push(newNode);
	  inputQueue->dequeue();
	}
      }
      else{ //If it's a close parenthesis
	while (*opStack->peek()->getData() != '('){ //As long as the top of operator stack is not open parenthesis
	  //Push it to the top of the opStack to main stack
	  Node* newNode = new Node(opStack->peek()->getData());
	  stack->push(newNode);
	  opStack->pop();
	}
	inputQueue->dequeue(); //Remove the paranthesis from the algorithm
	opStack->pop();
      }			
    }
  }
  while (!opStack->isEmpty()){ //As long as opStack isn't empty, push the top of opStack to main stack
    Node* newNode = new Node(opStack->peek()->getData());
    stack->push(newNode);
    opStack->pop();
  }
  Node* current = stack->getHead();//Set the current node to the the head of the stack
  
  List* inputQueue = new List();//Redo the list
  
  while(0 != current){ //As long as the current isn't null, push the current node to the input queue
    Node* newNode = new Node(current->getData());
    inputQueue->push(newNode);
    current = current->getNext();
  }
  makeTree(inputQueue);
}

//Credit: Michael
void Shunting::makeTree(List* input){ //Build the tree
  List* tree = new List(); //Initialize the tree as a list class member
  while (!input->isEmpty()){ //As long as the input isn't empty
    if(isdigit(*input->peek()->getData())){ //If first char of input is a number
      //Push the input head to the tree list
      Node* filler = new Node(input->peek()->getData());
      tree->push(filler);
      input->dequeue();
    }
    else{
      Node* currentNode = new Node(input->peek()->getData());//Create a node for the operator
      currentNode->setRight(tree->peek()); //Set right node to the head of tree
      tree->dissociate(); //Take head out of tree
      currentNode->setLeft(tree->peek()); //Set left node to the head of tree
      tree->dissociate(); //Take out the head of tree
      tree->push(currentNode); //Add the operator to the tree
      input->dequeue(); //Take head out of the input queue
    }
  }
  cout << "Which output would you like? ('infix', 'postfix', 'prefix', or 'quit') "; //Ask the user which kind of output they want
  
  char typeInput[100];
  cin.get(typeInput, 100);
  cin.get();
  
  if(strcmp(typeInput, "infix") == 0){ //Run the infix with the head
    infix(tree->peek());
    cout << endl;
  }
  else if(strcmp(typeInput, "postfix") == 0){ //Run the postfix with the head
    postfix(tree->peek());
    cout << endl;
  }
  else if(strcmp(typeInput, "prefix") == 0){ //Run the prefix with the head
    prefix(tree->peek());
    cout << endl;
  }
}

int main(){
  Shunting* shunt = new Shunting();//Create a new object
  
  cout << "Type an equation: ";
  char input[100];//Create an input char
  cin.get(input, 100);//Get the input from the user
  cin.get();
  
  char* token; 
  token = strtok(input, " "); //Automatically separate the char into tokens for easier separation
  
  List* newList = new List();//Create a new linked list
  
  while (token != NULL){
    Node* newNode = new Node(token);//Create a new node with the values from token
    newList->enqueue(newNode); //Add it to the Linked List
    token = strtok(NULL, " ");
  }
  
  shunt->setQueue(newList);
  
  shunt->doPostfix();
}
