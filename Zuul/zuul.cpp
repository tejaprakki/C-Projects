//Zuul main file

#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>
#include "room.h"
#include "item.h"


using namespace std;

void setup(vector<room*> *r, vector<item*> *items){
  
  char* name = new char[30];
  char* description = new char[1000];

  name = new char[30];
  description = new char[1000];
  room* room0 = new room();
  strcpy(name, "Main Entrance");
  strcpy(description, "Start here");
  room0->setName(name);
  room0->setDescription(description);
  r->push_back(room0);

  name = new char[30];
  description = new char[1000];
  room* room1 = new room();
  strcpy(name, "Cafeteria");
  strcpy(description, "You are in the cafeteria");
  room1->setName(name);
  room1->setDescription(description);
  r->push_back(room1);

  name = new char[30];
  description = new char[1000];
  room* room2 = new room();
  strcpy(name, "Computer Lab");
  strcpy(description, "You are in the computer lab");
  room2->setName(name);
  room2->setDescription(description);
  r->push_back(room2);

  name = new char[30];
  description = new char[1000];
  room* room3 = new room();
  strcpy(name, "Physics");
  strcpy(description, "You are in the physics classroom");
  room3->setName(name);
  room3->setDescription(description);
  r->push_back(room3);

  name = new char[30];
  description = new char[1000];
  room* room4 = new room();
  strcpy(name, "Chemistry");
  strcpy(description, "You are in the chemistry classroom");
  room4->setName(name);
  room4->setDescription(description);
  r->push_back(room4);

  name = new char[30];
  description = new char[1000];
  room* room5 = new room();
  strcpy(name, "Main Hall");
  strcpy(description, "You are in the main hall");
  room5->setName(name);
  room5->setDescription(description);
  r->push_back(room5);

  name = new char[30];
  description = new char[1000];
  room* room6 = new room();
  strcpy(name, "Math");
  strcpy(description, "You are in the math classroom");
  room6->setName(name);
  room6->setDescription(description);
  r->push_back(room6);

  name = new char[30];
  description = new char[1000];
  room* room7 = new room();
  strcpy(name, "Gym");
  strcpy(description, "You are in the gym");
  room7->setName(name);
  room7->setDescription(description);
  r->push_back(room7);

  name = new char[30];
  description = new char[1000];
  room* room8 = new room();
  strcpy(name, "Lit and Comp");
  strcpy(description, "You are in the lit and comp classroom");
  room8->setName(name);
  room8->setDescription(description);
  r->push_back(room8);

  name = new char[30];
  description = new char[1000];
  room* room9 = new room();
  strcpy(name, "History");
  strcpy(description, "You are in the history classroom");
  room9->setName(name);
  room9->setDescription(description);
  r->push_back(room9);

  name = new char[30];
  description = new char[1000];
  room* room10 = new room();
  strcpy(name, "Biology");
  strcpy(description, "You are in the biology classroom");
  room10->setName(name);
  room10->setDescription(description);
  r->push_back(room10);

  name = new char[30];
  description = new char[1000];
  room* room11 = new room();
  strcpy(name, "Storage");
  strcpy(description, "You are in the storage closet");
  room11->setName(name);
  room11->setDescription(description);
  r->push_back(room11);

  name = new char[30];
  description = new char[1000];
  room* room12 = new room();
  strcpy(name, "Courtyard");
  strcpy(description, "You are in the courtyard");
  room12->setName(name);
  room12->setDescription(description);
  r->push_back(room12);

  name = new char[30];
  description = new char[1000];
  room* room13 = new room();
  strcpy(name, "Office");
  strcpy(description, "You are in the office");
  room13->setName(name);
  room13->setDescription(description);
  r->push_back(room13);

  name = new char[30];
  description = new char[1000];
  room* room14 = new room();
  strcpy(name, "Athletic Office");
  strcpy(description, "You are in the athletic office");
  room14->setName(name);
  room14->setDescription(description);
  r->push_back(room14);

  map <char*, room*>*move = new map<char*, room*>();

  char* mynorth = new char[5];
  strcpy(mynorth, "north");
  char* mysouth = new char[5];
  strcpy(mysouth, "south");
  char* myeast = new char[5];
  strcpy(myeast, "east");
  char* mywest = new char[5];
  strcpy(mywest, "west");
  
  move->insert(pair<char*, room*>(mynorth, room1));
  room0->setExits(move);

  move = new map<char*, room*>();
  move->insert(pair<char*, room*>(mysouth, room0));
  move->insert(pair<char*, room*>(myeast, room3));
  move->insert(pair<char*, room*>(mywest, room2));
  room1->setExits(move);

  move = new map<char*, room*>();
  move->insert(pair<char*, room*>(mynorth, room14));
  move->insert(pair<char*, room*>(myeast, room1));
  room2->setExits(move);

  move = new map<char*, room*>();
  move->insert(pair<char*, room*>(mynorth, room5));
  move->insert(pair<char*, room*>(myeast, room4));
  move->insert(pair<char*, room*>(mywest, room1));
  room3->setExits(move);

  move = new map<char*, room*>();
  move->insert(pair<char*, room*>(mywest, room3));
  room4->setExits(move);

  move = new map<char*, room*>();
  move->insert(pair<char*, room*>(mynorth, room7));
  move->insert(pair<char*, room*>(myeast, room8));
  move->insert(pair<char*, room*>(mywest, room6));
  move->insert(pair<char*, room*>(mysouth, room3));
  room5->setExits(move);

  move = new map<char*, room*>();
  move->insert(pair<char*, room*>(mynorth, room10));
  move->insert(pair<char*, room*>(myeast, room5));
  room6->setExits(move);

  move = new map<char*, room*>();
  move->insert(pair<char*, room*>(mysouth, room5));
  room7->setExits(move);

  move = new map<char*, room*>();
  move->insert(pair<char*, room*>(mynorth, room9));
  move->insert(pair<char*, room*>(mywest, room5));
  room8->setExits(move);

  move = new map<char*, room*>();
  move->insert(pair<char*, room*>(mysouth, room8));
  room9->setExits(move);

  move = new map<char*, room*>();
  move->insert(pair<char*, room*>(mynorth, room11));
  move->insert(pair<char*, room*>(mysouth, room6));
  room10->setExits(move);

  move = new map<char*, room*>();
  move->insert(pair<char*, room*>(myeast, room12));
  move->insert(pair<char*, room*>(mysouth, room10));
  room11->setExits(move);

  move = new map<char*, room*>();
  move->insert(pair<char*, room*>(myeast, room13));
  move->insert(pair<char*, room*>(mywest, room11));
  room12->setExits(move);

  move = new map<char*, room*>();
  move->insert(pair<char*, room*>(mywest, room12));
  room13->setExits(move);

  move = new map<char*, room*>();
  move->insert(pair<char*, room*>(mysouth, room2));
  room14->setExits(move);

  name = new char[30];
  description = new char[1000];
  item* wires = new item();
  strcpy(name, "wires");
  strcpy(description, "These are wires that connect to you computer to turn it on!");
  wires->setName(name);
  wires->setDescription(description);
  room3->setItems(wires);
  
  name = new char[30];
  description = new char[1000];
  item* printer = new item();
  strcpy(name, "printer");
  strcpy(description, "This is a printer to print your essay!");
  printer->setName(name);
  printer->setDescription(description);
  room4->setItems(printer);
  
  name = new char[30];
  description = new char[1000];
  item* computer = new item();
  strcpy(name, "computer");
  strcpy(description, "This is the computer you are going to use to print your essay!");
  computer->setName(name);
  computer->setDescription(description);
  room8->setItems(computer);
  
  name = new char[30];
  description = new char[1000];
  item* monitor = new item();
  strcpy(name, "monitor");
  strcpy(description, "This connects to your computer so you see what you are printing!");
  monitor->setName(name);
  monitor->setDescription(description);
  room6->setItems(monitor);
  
  name = new char[30];
  description = new char[1000];
  item* cable = new item();
  strcpy(name, "cable");
  strcpy(description, "This will connect your computer to the printer!");
  cable->setName(name);
  cable->setDescription(description);
  room13->setItems(cable);
}

void pick(vector<item*>*i, room* currentRoom){
  cout << "What item would you like to pick up?" << endl;
  char theItem[15];
  cin >> theItem;
  cin.get();
  vector <item*>::iterator v;
  for(v = currentRoom->getItems()->begin(); v != currentRoom->getItems()->end(); v++){
    if (strcmp((*v)->getName(), theItem) == 0){
      i->push_back(*v);
      currentRoom->getItems()->erase(v);
      cout << "You picked up " << theItem << endl;
      break;
    }
    else {
      cout << "That item is not available in this room!" << endl;
    }
  }
}

void drop(vector<item*>*i, room* currentRoom){
  cout << "Which item would you like to drop?" << endl;
  char item2[15];
  cin >> item2;
  cin.get();
  vector<item*>::iterator v;
  for (v = i->begin(); v != i->end(); v++){
    if (strcmp((*v)->getName(), item2) == 0){
      currentRoom->getItems()->push_back(*v);
      i->erase(v);
      cout << "You dropped: " << item2 << endl;
      break;
    }
    else {
      cout << "That item is not in your inventory!" << endl;
    }
  }
}

void walk(vector<room*>*r, room* &currentRoom){
  char player[5];
  cout << "Which way would you like to go?" << endl;
  cin >> player;
  cin.get();
  map<char*, room*>::iterator e;
  for (e = currentRoom->getExits()->begin(); e != currentRoom->getExits()->end(); e++){
    if (strcmp(e->first, player) == 0){
      //cout << "This works!" << endl;
      currentRoom = e->second;
      break;
    }
    else{
      cout << "There is no exit there! Try again." << endl;
    }
  }
}

void winning (vector<room*>*r, vector<item*>*i, bool &running){ //credit: Nick
  int items1 = 0;
  int items2 = 0;
  int items3 = 0;
  int items4 = 0;
  int items5 = 0;
  
  vector<item*>::iterator p;
  for(p = r->at(14)->getItems()->begin(); p != r->at(14)->getItems()->end(); p++){ //searches room14 item vector
    
    if (strcmp((*p)->getName(), "wires" ) == 0){
      items1 = 1;
    }
    else if (strcmp((*p)->getName(), "printer" ) == 0){
      items2 = 1;
    }
    else if (strcmp((*p)->getName(), "computer" ) == 0){
      items3 = 1;
    }
    else if (strcmp((*p)->getName(), "monitor" ) == 0){
      items4 = 1;
    }
    else if (strcmp((*p)->getName(), "cable" ) == 0){
      items5 = 1;
    }
  }
  if (items1 == 1 && items2 == 1 && items3 == 1 && items4 == 1 && items5 == 1) {
    cout << "You found all of the parts to rpint your essay!" << endl;
    cout << "I hope you get a good grade." << endl;
    running = false;
  }
}

void inventory(vector<item*>*i){
  cout << "This is your inventory: " << endl;
  vector<item*>::iterator it;
    for (it = i->begin(); it != i->end(); ++it) {
    cout << (*it)->getName() << ": ";
    cout << (*it)->getDescription() << endl;
    cout << "" << endl;
  }
}

int main(){
  bool running = true;
  char input[50];
  vector<room*>*r = new vector<room*>;
  vector<item*>*i = new vector<item*>;
  
  setup(r, i);
  room* currentRoom = r->at(0);

  
  cout << "You need a computer because you need to finish and print your essay." << endl;
  cout << "The only way this is possible is at Zuul High School." << endl;
  cout << "There are rooms and in those rooms are parts to a computer and printer." << endl;
  cout << "Go through the rooms and collect all of the items. Drop all of these items in the Athletic Office and you will be able to leave." << endl;
  cout << "Good Luck!" << endl;

  while (running = true){
    cout << "What would you like to do? (Commands: Drop item = 'drop', Pick up item = 'pick', Go = 'go', Inventory = 'inventory', and Quit = 'quit'." << endl;
    cout << currentRoom->getName() << endl;
    cout << currentRoom->getDescription() << endl;

    cout << "The items in the room: ";
    vector<item*>::iterator it;
    for(it = currentRoom->getItems()->begin(); it != currentRoom->getItems()->end(); it++){ 
      cout << (*it)->getName() << " ";
    }
    cout << endl;
    
    map<char*, room*>::iterator rms;
    cout << "The exits are: "; 
    for (rms = currentRoom->getExits()->begin(); rms != currentRoom->getExits()->end(); rms++) {
      cout << rms->first << " ";
    }
    cout << endl;
    
    cin.getline(input, 50, '\n');
    
    if (strcmp(input, "inventory") == 0){
      inventory(i);
    }
    else if (strcmp(input, "pick") == 0){
      pick(i, currentRoom);
    }
    else if (strcmp(input, "drop") == 0){
      drop(i, currentRoom);
    }
    if (strcmp(input, "go") == 0){
      walk(r, currentRoom);
    }
    if (strcmp(input, "quit") == 0){
      cout << "Quitting" << endl;
      running = false;
    }
    winning(r, i, running);
  }
  return 0;
}

