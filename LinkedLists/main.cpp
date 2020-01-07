#include <iostream>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

Node* head = NULL;

void add(char* name, int id, float gpa){
  Student* newStudent = new Student(name, id, gpa);
  Node* current = head;
  if(current == NULL){
    head = new Node(newStudent);
    head->setStudent(newStudent);
  }
  else{
    while(current->getNext() != NULL){
      current = current->getNext();
    }
    current->setNext(new Node(newStudent));
    current->getNext()->setStudent(newStudent);
  }
}

void print(Node* next){
  if(next == head){
    cout << "list: " << endl;
  }
  if(next != NULL){
    cout << "(Name: " << next->getStudent()->getName() << ", ID: " << next->getStudent()->getID() << " , GPA: " << fixed << setprecision(2) << next->getStudent()->getGPA() << ")" <<endl;
    print(next->getNext());
  }
}

int main(){
  int stillPlaying = 0;

  while(stillPlaying == 0){
    char* input = new char[50];
    char* studentName = new char[50];
    int id = 0;
    float gpa = 0;

    cout << "Do you want to add or exit?" << endl;
    cin.getline(input, 25, '\n');
    

    if(strcmp(input, "add") == 0){
      cout << "Type name of student:" << endl;
      cin.getline(studentName, 25, '\n');
      
      cout << "Type ID of student:" << endl;
      cin >> id;
      cin.clear();
      cin.ignore(1000000, '\n');
      
      cout << "Type GPA of student: " << endl;
      cin >> gpa;
      cin.clear();
      cin.ignore(1000000, '\n');

      add(studentName, id, gpa);
      print(head);
    }
    else if(strcmp(input, "exit") == 0){
      stillPlaying = 1;
    }
    else {
      cout << "That is not a choice. Try again! (Type 'add' or 'exit')" << endl;
    }
  }
}
