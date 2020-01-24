//room cpp file

#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "room.h"

using namespace std;

room::room() {
  roomItems = new vector<item*>();
}
void room::setExits(map<char*, room*>* user){
  exit = user;
}
map<char*, room*>* room::getExits(){
  return exit;
}
vector<item*>* room::getItems(){
  return roomItems;
}
void room::setItems(item* newItems){
  roomItems->push_back(newItems);
}
char* room::getDescription(){
  return description;
}
char* room::getName(){
  return name;
}
char* room::setName(char* user){
  name = user;
}
char* room::setDescription(char* user){
  description = user;
}
