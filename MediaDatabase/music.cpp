//Music file

#include <iostream>
#include <cstring>
#include "media.h"
#include "music.h"

using namespace std;

Music::Music() {
  artist = new char[100];
  publisher = new char[100];
  duration = 0;
}
int Music::getType() {
  return 2;
}
char* Music::getArtist() {
  return artist;
}
int Music::getDuration() {
  return duration;
}
char* Music::getPublisher() {
  return publisher;
}
