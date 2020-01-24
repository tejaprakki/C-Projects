#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string.h>

using namespace std;

class item{
 public:
  char* getName();
  char* getDescription();
  char* setName(char* user);
  char* setDescription(char* user);
 private:
  char* name;
  char* description;
};
#endif
