//This program allows a user to create different digital media lists.
//Author: Teja Prakki
//Date: 11/5/2019

#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>
#include "media.h"
#include "movie.h"
#include "music.h"
#include "game.h"

using namespace std;

void ADD(vector<Media*> *media){
  char input[15];
  cout << "Which type of media would you like to add? (Movie, Song, or Game)" << endl;
  cin.get(input, 15);
  cin.clear();
  cin.ignore();
  if ((strcmp(input, "Movie") == 0) || (strcmp(input, "movie") == 0)){
    Movie* movie = new Movie();
    cout << "What is the name of the movie?" << endl;
    cin.getline(movie->title, 100, '\n');
    cin.clear();
    //cin.ignore();
    cout << "What year was the movie made?" << endl;
    cin >> movie->year;
    cin.clear();
    cin.ignore();
    cout << "Who is the director of this movie?" << endl;
    cin.getline(movie->director, 100, '\n');
    cin.clear();
    //cin.ignore();
    cout << "What is the duration of this movie? (In minutes as a whole number)" << endl;
    cin >> movie->duration;
    cin.clear();
    cin.ignore();
    cout << "What is the rating of this movie?" << endl;
    cin >> movie->rating;
    cin.clear();
    cin.ignore();
    
    media->push_back(movie);
  }
  else if((strcmp(input, "Song") == 0) || (strcmp(input, "song") == 0)){
    Music* music = new Music();
    cout << "What is the name of the song?" << endl;
    cin.getline(music->title, 100, '\n');
    cin.clear();
    //cin.ignore();
    cout << "What year was the song made?" << endl;
    cin >> music->year;
    cin.clear();
    cin.ignore();
    cout << "Who is the artist of this song?" << endl;
    cin.getline(music->artist, 100, '\n');
    cin.clear();
    //cin.ignore();
    cout << "What is the duration of this song? (In seconds as a whole number)" << endl;
    cin >> music->duration;
    cin.clear();
    cin.ignore();
    cout << "Who published this song?" << endl;
    cin.getline(music->publisher, 100, '\n');
    cin.clear();
    //cin.ignore();
    
    media->push_back(music);
  }
  else if ((strcmp(input, "Game") == 0) || (strcmp(input, "game") == 0)){
    Game* game = new Game();
    cout << "What is the name of the game?" << endl;
    cin.getline(game->title, 100, '\n');
    cin.clear();
    //cin.ignore();
    cout << "What year was the game made?" << endl;
    cin >> game->year;
    cin.clear();
    cin.ignore();
    cout << "Who is the publisher of this game?" << endl;
    cin.getline(game->publisher, 100, '\n');
    cin.clear();
    //cin.ignore();
    cout << "What is the rating of this game?" << endl;
    cin >> game->rating;
    cin.clear();
    cin.ignore();
    
    media->push_back(game);
  }
  else{
    cout << "That is not a valid choice to add to the list. Please try again." << endl;
  }
}

void LOOK(char* title, vector<Media*> *media){
  vector <Media*>::iterator a;
  for (a = media->begin(); a != media->end(); a++){
    if (strcmp(title, (*a)->getTitle()) == 0){
      cout << "The title: " << (*a)->getTitle() << endl;
      cout << "The year: " << (*a)->getYear() << endl;
      if ((*a)->getType() == 0){
	cout << "Director: " << static_cast<Movie*>(*a)->getDirector() << endl;
	cout << "Duration: " << static_cast<Movie*>(*a)->getDuration() << endl;
	cout << "Rating: " << static_cast<Movie*>(*a)->getRating() << endl;
      }
      else if ((*a)->getType() == 1){
	cout << "Pubisher: " << static_cast<Game*>(*a)->getPublisher() << endl;
	cout << "Rating: " << static_cast<Game*>(*a)->getRating() << endl;
      }
      else if ((*a)->getType() == 2){
	cout << "Artist: " << static_cast<Music*>(*a)->getArtist() << endl;
	cout << "Duration: " << static_cast<Music*>(*a)->getDuration() << endl;
	cout << "Publisher: " << static_cast<Music*>(*a)->getPublisher() << endl;
      }
    }
  }
}

void DELETE(char* title, vector<Media*> *media){
  char input [10];
  vector <Media*>::iterator b;
  for (b = media->begin(); b != media->end(); b++){
    if (strcmp(title, (*b)->getTitle()) == 0){
      cout << "The title: " << (*b)->getTitle() << endl;
      cout << "The year: " << (*b)->getYear() << endl;
      if ((*b)->getType() == 0){
	cout << "Director: " << static_cast<Movie*>(*b)->getDirector() << endl;
	cout << "Duration: " << static_cast<Movie*>(*b)->getDuration() << endl;
	cout << "Rating: " << static_cast<Movie*>(*b)->getRating() << endl;
      }
      else if ((*b)->getType() == 1){
	cout << "Pubisher: " << static_cast<Game*>(*b)->getPublisher() << endl;
	cout << "Rating: " << static_cast<Game*>(*b)->getRating() << endl;
      }
      else if ((*b)->getType() == 2){
	cout << "Artist: " << static_cast<Music*>(*b)->getArtist() << endl;
	cout << "Duration: " << static_cast<Music*>(*b)->getDuration() << endl;
	cout << "Publisher: " << static_cast<Music*>(*b)->getPublisher() << endl;
      }
      cout << "Are you sure you want to delete this? (Type 'y' for yes and 'n' for no)" << endl;
      cin.get(input, 10);
      cin.clear();
      cin.ignore();
      if(strcmp(input, "y") == 0){
	delete *b;
	b = media->erase(b);
	return;
      }
    }
  }
}

void LOOK(int year, vector<Media*> *media){
  vector <Media*>::iterator a;
  for (a = media->begin(); a != media->end(); a++){
    if (year == (*a)->getYear()){
      cout << "The title: " << (*a)->getTitle() << endl;
      cout << "The year: " << (*a)->getYear() << endl;
      if ((*a)->getType() == 0){
	cout << "Director: " << static_cast<Movie*>(*a)->getDirector() << endl;
	cout << "Duration: " << static_cast<Movie*>(*a)->getDuration() << endl;
	cout << "Rating: " << static_cast<Movie*>(*a)->getRating() << endl;
      }
      else if ((*a)->getType() == 1){
	cout << "Pubisher: " << static_cast<Game*>(*a)->getPublisher() << endl;
	cout << "Rating: " << static_cast<Game*>(*a)->getRating() << endl;
      }
      else if ((*a)->getType() == 2){
	cout << "Artist: " << static_cast<Music*>(*a)->getArtist() << endl;
	cout << "Duration: " << static_cast<Music*>(*a)->getDuration() << endl;
	cout << "Publisher: " << static_cast<Music*>(*a)->getPublisher() << endl;
      }
    }
  }
}

void DELETE(int year, vector<Media*> *media){
  char input [10];
  vector <Media*>::iterator b;
  for (b = media->begin(); b != media->end(); b++){
    if (year == (*b)->getYear()){
      cout << "The title: " << (*b)->getTitle() << endl;
      cout << "The year: " << (*b)->getYear() << endl;
      if ((*b)->getType() == 0){
	cout << "Director: " << static_cast<Movie*>(*b)->getDirector() << endl;
	cout << "Duration: " << static_cast<Movie*>(*b)->getDuration() << endl;
	cout << "Rating: " << static_cast<Movie*>(*b)->getRating() << endl;
      }
      else if ((*b)->getType() == 1){
	cout << "Pubisher: " << static_cast<Game*>(*b)->getPublisher() << endl;
	cout << "Rating: " << static_cast<Game*>(*b)->getRating() << endl;
      }
      else if ((*b)->getType() == 2){
	cout << "Artist: " << static_cast<Music*>(*b)->getArtist() << endl;
	cout << "Duration: " << static_cast<Music*>(*b)->getDuration() << endl;
	cout << "Publisher: " << static_cast<Music*>(*b)->getPublisher() << endl;
      }
      cout << "Are you sure you want to delete this? (Type 'y' for yes and 'n' for no)" << endl;
      cin.get(input, 10);
      cin.clear();
      cin.ignore();
      if(strcmp(input, "y") == 0){
	delete *b;
	b = media->erase(b);
	return;
      }
    }
  }
}
    
int main() {
  bool quit = false;
  vector<Media*> *media = new vector<Media*>();
  char input[15];
  char input2[100];
  int input3;
  while (!quit){
    cout << "Would you like to ADD, LOOK, DELETE, or QUIT?" << endl;
    cin.get(input, 10);
    cin.clear();
    cin.ignore();
    if ((strcmp(input, "ADD") == 0) || (strcmp(input, "add") == 0)){
      ADD(media);
    }
    else if ((strcmp(input, "LOOK") == 0) || (strcmp(input, "look") == 0)){
      cout << "Would you like to search by title or year?" << endl;
      cin.get(input, 10);
      cin.clear();
      cin.ignore();
      if ((strcmp(input, "TITLE") == 0) || (strcmp(input, "title") == 0)){
	cout << "What is the title?" << endl;
	cin.get(input2, 100);
	cin.clear();
	cin.ignore();
	LOOK(input2, media);
      }
      else if ((strcmp(input, "YEAR") == 0) || (strcmp(input, "year") == 0)){
	cout << "Which year?" << endl;
	cin >> input3;
	cin.clear();
	cin.ignore();
	LOOK(input3, media);
      }
      else {
	cout << "Please type 'title' or 'year'?" << endl;
      }
    }
    else if ((strcmp(input, "DELETE") == 0) || (strcmp(input, "delete") == 0)){
      cout << "Would you like to delete by title or year?" << endl;
      cin.get(input, 10);
      cin.clear();
      cin.ignore();
      if ((strcmp(input, "TITLE") == 0) || (strcmp(input, "title") == 0)){
	cout << "What is the title?" << endl;
	cin.get(input2, 100);
	cin.clear();
	cin.ignore();
	DELETE(input2, media);
      }
      else if ((strcmp(input, "YEAR") == 0) || (strcmp(input, "year") == 0)){
	cout << "Which year?" << endl;
	cin >> input3;
	cin.clear();
	cin.ignore();
	DELETE(input3, media);
      }
      else {
	cout << "Please type 'title' or 'year'?" << endl;
      }
    }
    else if ((strcmp(input, "QUIT") == 0) || (strcmp(input, "quit") == 0)){
      cout << "Thank you!" << endl;
      quit = true;
    }
    else {
      cout << "That was an invalid input. Try again." << endl;
    }
  }
}
