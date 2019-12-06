//Game File

#include <iostream>
#include <cstring>
#include "media.h"
#include "game.h"

using namespace std;

Game::Game() {
  publisher = new char[100];
  rating = 0.0;
}
int Game::getType() {
  return 1;
}
char* Game::getPublisher() {
  return publisher;
}
float Game::getRating() {
  return rating;
}
