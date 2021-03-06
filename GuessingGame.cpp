//This program creates a guessing game where the user has to guess a random number generated by the computer.
//Author: Teja Prakki
//9/16/2019

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
  //Set a Random Seed to start
  srand(time(NULL));
  //Initialize Variables
  int input = 0;
  char choice;
  int guess = 1;
  //Set playing to "true"
  int playing = 1;
  //Start the game with a random number between 0 and 100
  int number = rand() % 101;
  //As long as the player is playing...
  while(playing == 1){
    cout << "Please Guess a number" << endl;
    //Get an input from the player
    cin >> input;
    //Based on the input, if the input is the random number...
      if (input == number){
	//Tell them the number of guesses it took them
	cout << "Congratulations! It took you " << guess << " guesses!" << endl;
	//Ask if they want to play again
	cout << "Would you like to play again? (y/n)" << endl;
	  cin >> choice;
	//Based on the input, if the choice is y...
	if (choice == 'y'){
	  //Reset the guesses
	  guess = 1;
	  //Set a new random number
	  number = rand() % 101;
	  //Restart at the beginning of the while loop
	  playing = 1;
	}
	//If the choice is n...
	else if (choice == 'n'){
	  cout << "Thank You for playing!";
	  //End the game
	  playing = 0;
	}
      }
      //If the input is smaller than the random number...
      else if(input < number){
	//Guess again
	cout << "Your number is too low. Guess again!" << endl;
        guess++;
      }
      //If the input is larger than the random number...
      else{
	//Guess Again
	cout << "Your Number is too high. Guess again!" << endl;
	guess++;
      }
   }
}
