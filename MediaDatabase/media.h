#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>

using namespace std;

class Media {
 public:
  Media();
  int year;
  char* title;
  int getYear();
  char* getTitle();
  virtual int getType();
 private:
};

#endif
