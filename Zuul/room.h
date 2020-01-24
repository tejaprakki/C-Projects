//room h file

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string.h>
#include <map>
#include "item.h"

using namespace std;

class room {
 public:
  room();
  map<char*, room*>* getExits();
  void setExits(map<char*, room*>* user);
  vector<item*>* getItems();
  void setItems(item* newItems);
  char* getDescription();
  char* getName();
  char* setName(char* user);
  char* setDescription(char* user);
 private:
  map<char*, room*>* exit;
  vector<item*>* roomItems;
  char* description;
  char* name;
};
#endif
