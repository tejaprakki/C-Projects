//item cpp file

#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "item.h"

using namespace std;

char* item::getName(){
  return name;
}
char* item::getDescription(){
  return description;
}
char* item::setName(char* user){
  name = user;
}
char* item::setDescription(char* user){
  description = user;
}
