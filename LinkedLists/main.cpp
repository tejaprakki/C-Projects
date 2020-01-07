#include <iostream>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

Node* head = NULL; //Node starts the function

void add(char* name, int id, float gpa){ //Funstion that adds students to the end of the list
  Student* newStudent = new Student(name, id, gpa);
  Node* current = head; //creating a new node to equal the value of the head
  if(current == NULL){ //if the head is equal to null...
    head = new Node(newStudent); //add a new node
    head->setStudent(newStudent); //Set the student into to the head  
  }
  else{
    while(current->getNext() != NULL){//While the pointer isn't the end of the array
      current = current->getNext(); //make the current node equal to the next node
    }
    current->setNext(new Node(newStudent)); //Make a new node to set the location of the next node
    current->getNext()->setStudent(newStudent); //Set the student node to the input function
  }
}

void print(Node* next){ //Add the print funtion
  if(next == head){ //If the next node is equal to the head
    cout << "list: " << endl; //Print the list
  }
  if(next != NULL){ //If the next node isn't equal to null
    cout << "(Name: " << next->getStudent()->getName() << ", ID: " << next->getStudent()->getID() << " , GPA: " << fixed << setprecision(2) << next->getStudent()->getGPA() << ")" <<endl; //print the name of the student in the list
    print(next->getNext());
  }
}

int main(){ //Main loop
  int running = 0;

  while(running == 0){ //start a while loop
    char* input = new char[50]; //Specify what each variable will be set to
    char* studentName = new char[50];
    int id = 0;
    float gpa = 0;

    cout << "Do you want to add or exit?" << endl; //Ask if the user wants to add or exit
    cin.getline(input, 25, '\n');
    

    if(strcmp(input, "add") == 0){ //If the user says add...
      cout << "Type name of student:" << endl; //Ask the user to type the name of the student
      cin.getline(studentName, 25, '\n');
      
      cout << "Type ID of student:" << endl; //Then the ID number of the student
      cin >> id;
      cin.clear();
      cin.ignore(1000000, '\n');
      
      cout << "Type GPA of student: " << endl; //Then the GPA of the student
      cin >> gpa;
      cin.clear();
      cin.ignore(1000000, '\n');

      add(studentName, id, gpa);
      print(head);
    }
    else if(strcmp(input, "exit") == 0){ //If the user says to exit
      running = 1; //Break the while loop
    }
    else { //If the user types neither, tell them to try again
      cout << "That is not a choice. Try again! (Type 'add' or 'exit')" << endl;
    }
  }
}
