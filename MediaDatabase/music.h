#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music:public Media{
 public:
  Music();
  char* artist;
  int duration;
  char* publisher;
  virtual int getType();
  char* getArtist();
  int getDuration();
  char* getPublisher();
 private:
  //char * publisher = new char[100];
};

#endif
