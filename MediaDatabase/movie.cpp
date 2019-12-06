//Movie File

#include <iostream>
#include <cstring>
#include "media.h"
#include "movie.h"

using namespace std;

Movie::Movie() {
  director = new char[100];
  duration = 0;
  rating = 0.0;
}
int Movie::getType() {
  return 0;
}
char* Movie::getDirector() {
  return director;
}
int Movie::getDuration() {
  return duration;
}
float Movie::getRating() {
  return rating;
}
