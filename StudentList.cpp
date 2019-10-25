//This program creates a list if students, student ID's and GPA. You can print this list too.
//Author: Teja Prakki
//Date: 10/23/2019

#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>

using namespace std;

//Start the struct with the variables
struct Students{
  char firstName[20];
  char lastName[20];
  int studentID;
  float gpa;
};

//Call the below methods
Students* ADD();
void PRINT(vector<Students*> student);
void DELETE(vector<Students*> &student, int studentID);

int main(){
  //Start with quit being false
  bool quit = false;
  char input[10];
  //Create a vector
  vector<Students*> student;
  //Initialize an IDinput variable for deletion
  int IDinput;
  //While "quit" is false
  while(!quit){
    //Ask the user which command they would like to use
    cout << "Welcome to Student List! Would you like to ADD, PRINT, DELETE, or QUIT?" << endl;
    //Get the input and run the command
    cin.get(input, 10);
    cin.clear();
    cin.ignore();
    //If add is the command...
    if ((strcmp(input, "ADD") == 0) || (strcmp(input, "add") == 0)){
      //rum the add method
      student.push_back(ADD());
    }
    //If print is the command...
    else if ((strcmp(input, "PRINT") == 0) || (strcmp(input, "print") == 0)){
      //run the print method
      PRINT(student);
    }
    //If delete is the command
    else if ((strcmp(input, "DELETE") == 0) || (strcmp(input, "delete") == 0)){
      //Ask the user which ID number they want to delete
      cout << "Please enter the ID number you would like to delete." << endl;
      //Get the input
      cin >> IDinput;
      cin.clear();
      cin.ignore();
      //And run the delete method
      DELETE(student, IDinput);
    }
    //If quit is the command...
    else if ((strcmp(input, "QUIT") == 0) || (strcmp(input, "quit") == 0)){
      //Turn quit into true
      quit = true;
    }
  }
}
//Add method
Students* ADD(){
  //define new student
  Students* newStdnt = new Students();
  //Ask for the first name
  cout << "What is the student's first name?" << endl;
  cin >> newStdnt->firstName;
  cin.clear();
  cin.ignore();
  //Ask for the last name
  cout << "What is the student's last name?" << endl;
  cin >> newStdnt->lastName;
  cin.clear();
  cin.ignore();
  //Ask for the Student ID
  cout << "What is the student's ID number?" << endl;
  cin >> newStdnt->studentID;
  cin.clear();
  cin.ignore();
  //Ask for the Student ID
  cout << "What is the student's GPA?" << endl;
  cin >> newStdnt->gpa;
  cin.clear();
  cin.ignore();
  return newStdnt;
}
//Print method
void PRINT(vector<Students*> student){
  //Create an iterator
  vector <Students*>::iterator a;
  //Go through a for loop for printing
  for (a = student.begin(); a != student.end(); a++){
    //Print the Student's first name, last name, ID, and GPA
    cout << endl << "Name: " << (*a)->firstName << " " << (*a)->lastName << endl;
    cout << "Student ID: " << (*a)->studentID << endl;
    cout << fixed << std::setprecision(2) << "GPA: " << (*a)->gpa << endl;
  }
}
//Delete method
void DELETE(vector<Students*> &student, int studentID){
  //Create another iterator
  vector <Students*>::iterator b;
  //Go through a for loop for deletion
  for (b = student.begin(); b != student.end(); b++){
    //Delete the given Student from the database
    if((*b)->studentID == studentID){
      delete *b;
      student.erase(b);
      return;
    }
  }
  //If that ID doesn't exist, tell the user it's not registered
  cout << "That Student ID may be invalid or not yet registered." << endl;
}
