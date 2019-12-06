#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movie:public Media{
 public:
  Movie();
  char* director;
  int duration;
  float rating;
  virtual int getType();
  char* getDirector();
  int getDuration();
  float getRating();
 private:
  //int duration;
  //float rating;
};

#endif
