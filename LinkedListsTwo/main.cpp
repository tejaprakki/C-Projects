#include <iostream>
#include <iomanip>
#include "node.h"
#include "student.h"

/*
Code by Teja Prakki

This is student list using a linked lists basis. It will allow users to add, print, and delete students from a database.

Node.o and Node.h files from Tejash Panda.
*/

using namespace std;

Node* head = NULL; //Start the head as null because there is nothing in the head

void add(Node* previous, char* name, int id, float gpa){ //Start the add function to add any students into the list
  Student* newStudent = new Student(name, id, gpa);
  if(head == NULL){ //If the head is empty...
    head = new Node();
    head->setStudent(newStudent); //Add a new student
  }
  else if(newStudent->getID() < head->getStudent()->getID()){ //If you are adding a new student to the beginning of the list...
    Node* temp = new Node(); //Create a temp node to hold the old information
    temp->setStudent(head->getStudent()); //Assign the old head to a temp node and assign the new head to a new node
    temp->setNext(head->getNext());
    head->setStudent(newStudent);
    head->setNext(temp);
  }
  else if(previous->getNext() == NULL){ //if it's at the end of the list...
    Node* newNode = new Node();
    newNode->setStudent(newStudent); //Assign the new information to a node
    previous->setNext(newNode); //set the previous node to a new node
  }
  else if(newStudent->getID() < previous->getNext()->getStudent()->getID()){ //This does the same as the head replacement but it replaces the previous node
    Node* newNode = new Node();
    newNode->setStudent(newStudent);
    newNode->setNext(previous->getNext());
    previous->setNext(newNode);
  }
  else {
    add(previous->getNext(), name, id, gpa); //Call the function recursively so that it can continue as long as the code is running
  }
}

void remove(Node* next, Node* prev, int inputID){ //Delete function that will allow the user to delete a student from the database
  char input[50];
  if(next == head && next->getStudent()->getID() == inputID){ //If the student being deleted is the head...
    cout << "You have selected this student to delete: " << endl;
    cout << "Name: " << next->getStudent()->getName() << ", ID: " << next->getStudent()->getID() << ", GPA: " << fixed << setprecision(2) << next->getStudent()->getGPA() << endl;
    cout << "Are you sure you would like to delete this student from the database? ('yes' or 'no')" << endl; //Ask if they want to delete the given student
    cin >> input;
    cin.clear();
    cin.ignore(1000000, '\n');
    if(strcmp(input, "yes") == 0){ //If ther want to delete that student...
      cout << "The student has been deleted from the database!" << endl; //Tell the user that the student has been deleted
      if(next->getNext() == NULL){ //If there's only one student in the database
	next->~Node(); //delete the node using the destructor
	head = NULL; //There are no students left causing the head to be empty (NULL)
      }
      else{ //If there's more than one student...
	head = next->getNext(); //Set the next node to be the head now
	next->~Node(); //Delete the node using the destructor
	remove(head, NULL, inputID); //Set the function to be recursive in case there are any other students with the same student ID
      }
    }
    else if(strcmp(input, "no") == 0){ //If the user decides not to delete the student...
      cout << "Ok. This student will not be deleted from the database!" << endl;
      if(next->getNext() != NULL){ //If there are more with the same ID, continue looking through the list
	remove(next->getNext(), next, inputID); //Continue on to the next node
      }
    }
    else{ //If the user doesn't respond wiht either yes or no...
      cout << "Please respond with 'yes' or 'no'" << endl; //Tell them to try again
    }
  }
  else if(next->getStudent()->getID() == inputID){ //If the user wants to delete a node that isn't the head node...
    cout << "You have selected the following student: " << endl;
    cout << "Name: " << next->getStudent()->getName() << ", ID: " << next->getStudent()->getID() << ", GPA: "  << fixed << setprecision(2) << next->getStudent()->getGPA() << endl;
    cout << "Are you sure you would like to delete this student from the database? ('yes' or 'no')" << endl; //Make sure the user wants to delete this student
    cin >> input;
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(input, "yes") == 0){ //If yes...
      cout << "The student has been deleted from the database!" << endl;
      prev->setNext(next->getNext()); //Set the previous node next is next node next
      next->~Node(); //Delete the node using the destructor
    }
    else if(strcmp(input, "no") == 0){ //If the user decides not to delete the student...
      cout << "Ok. This student will not be deleted from the database!" << endl;
      if(next->getNext() != NULL){ //If there are more with the same ID, continue looking through the list
	remove(next->getNext(), next, inputID); //Continue on to next node
      }
    }
    else{ //If the user doesn't respond with either yes or no...
      cout << "Please respond with 'yes' or 'no'"; //Tell them to try again
    }
  }
  if(next->getNext() != NULL){ //If the head is not to be deleted, go to the next node
    remove(next->getNext(), next, inputID); //Continue goibng through the list
  }
}

void print(Node* next){ //Print function if the user wants to see what students are in the list
  if(next != NULL){ //Print the list using a name, ID, and GPA format
    cout << "Name: " << next->getStudent()->getName() << ", ID: " << next->getStudent()->getID() << " , GPA: " << fixed << setprecision(2) << next->getStudent()->getGPA() <<endl;
    print(next->getNext()); //Print it recursively
  }
}

//Credit: Tejash Panda
void average(Node* current){ //Average function if the user wants to average multiple student GPA's
  int amountStudent = 0; //Create variables to keep track of the GPA's and number of students
  float gpaSum = 0;
  if(current == head){ //If the current node is the head...
    gpaSum += (current->getStudent())->getGPA(); //Get the sum of the GPAs
    amountStudent++; //And increase the number of student so that it can show in the final calculation
  }
  while(current->getNext() != NULL){ //As long as there are more nodes in the list and the user isn't at the end of the list...
    gpaSum += head->getNext()->getStudent()->getGPA(); //Add the gpa to the sum
    amountStudent++; //Increase the number of students so that it can reflect in the final calculation
    current = current->getNext();
  }
  cout << "The average GPA is: " << gpaSum / amountStudent << endl << endl; //Show the user the average gpa of the students in the list
}

int main(){
  int stillPlaying = 0; //Create a variable so that a while loop can run as long as it's true

  while(stillPlaying == 0){ //As long as the user is still using the database...
    char input[100]; //Create variables that will be used throughout the code
    char* name = new char[50];
    int id = 0;
    float gpa = 0;
    cout << "Would you like to ADD, PRINT, DELETE, AVERAGE, or EXIT? (type 'add', 'print', 'delete', 'average' or 'exit')" << endl; //Ask the user what they would like to do
    cin.getline(input, 100); //Get the input and react accordingly

    if(strcmp(input, "add") == 0){ //If the user wants to add to the list...
      cout << "Type name of student:" << endl; //Ask them to type the name of the student
      cin.getline(name, 25, '\n');
      
      cout << "Type ID of student:" << endl; //Then the Student ID
      cin >> id;
      cin.clear();
      cin.ignore(1000000, '\n');
      
      cout << "Type GPA of student: " << endl; //The input the GPA of the student
      cin >> gpa;
      cin.clear();
      cin.ignore(1000000, '\n');

      add(head, name, id, gpa); //Call an add method so the the user's inputs can be added to the list
      //print(head);
    }
    else if(strcmp(input, "print") == 0){ //If the user wants to print the list...
      cout << "List: " << endl;
      print(head); //Print the list on the screen so the user can see it
    }
    else if(strcmp(input, "delete") == 0){ //If the user want to delete a student
      int inputID;
      if(head == NULL){ //If there is nothing in the head
	cout << "There are no student in the database!" << endl; //Tell the user
      }
      else{ //If there are items in the list...
	cout << "Please enter the student ID of the student you would like to delete" << endl; //Ask the user which student they would like to delete using student ID
	cin >> inputID;
	cin.clear();
	cin.ignore(1000000, '\n');
	remove(head, NULL, inputID); //Set the previous to Null and move everything back
      }
    }
    else if(strcmp(input, "average") == 0){ //If the user wants to average the GPAs...
      if(head == NULL){ //If there is nothing in the head...
	cout << "There are no students in the database!" << endl; //Tell the user
      }
      else{ //Otherwise...
	average(head); //Average the list
      }
    }
    else if(strcmp(input, "exit") == 0){ //If the user asks to exit...
      stillPlaying = 1; //Set the variable to 1 so that the loop ends
    }
    else { //If none of the given options are typed by the user...
      cout << "Please enter 'add', 'print', 'delete', 'average', or 'exit'" << endl; //Tell the user to try again.
    }
  }
}
