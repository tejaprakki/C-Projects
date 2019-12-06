#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Game:public Media{
 public:
  Game();
  float rating;
  char* publisher;
  virtual int getType();
  char* getPublisher();
  float getRating();
 private:
  //float rating;
};

#endif
