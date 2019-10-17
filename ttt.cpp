 //This is a program that allows 2 player to play the game of Tic Tac Toe. Also checks for wins.
//Date: 10/17/2019
//Author: Teja Prakki

#include <iostream>

using namespace std;

//Initialize contant variables
const int BLANK = 0;
const int X_TURN = 1;
const int O_TURN = 2;
void printBoard(int** board) { //Print the 3x3 board
cout << " " << "1" << "2" << "3" << endl;
cout << "a" << (char)board[0][0] << (char)board[0][1] << (char)board[0][2] << endl;
cout << "b" << (char)board[1][0] << (char)board[1][1] << (char)board[1][2] << endl;
cout << "c" << (char)board[2][0] << (char)board[2][1] << (char)board[2][2] << endl;
}
//Call the Tie and Win and Clear processes
bool checkWin(int** board, int & turn);
bool checkTie(int** board);
void clear(int** board);
int main () {
  //Set up the new board using a pointer
  int** board = new int *[3];
  for (int a = 0; a < 3; a++){
    board [a] = new int[3];
    for (int b = 0; b < 3; b++){
      board[a][b] = 0;
    }
  }
  //Initialize the variables
  char moveInput [1];
  int playing = 1;
  int X_WINS = 0;
  int O_WINS = 0;
  int TIES = 0;
  int X_MOVE = 1;
  int O_MOVE = 2;
  int turn = X_TURN;
  char choice;
  //While playing is true...
  while (playing == 1){
    //Tell the user to enter a gridspace
  cout << "Please enter a gridspace!" << endl;
  printBoard(board);
  cin.get(moveInput, 3);
  cin.ignore();
  //If the input doesn't start with an a, b, or c...
  if ((moveInput[0] != 'a') && (moveInput[0] != 'b') && (moveInput[0] != 'c')) {
    //Tell them to try again
    cout << "Please enter a, b, or c for your first character" << endl;
    }
  //If the input doesn't end with a 1, 2, or 3...
  else if ((moveInput[1] != '1') && (moveInput[1] != '2') && (moveInput[1] != '3')) {
    //Tell them to try again
    cout << "Please enter 1, 2, or 3 for your second character" << endl;
    }
  else {
    //Convert the X and O values into ASCII numbers
    int row = moveInput[0] - 97;
    int column = moveInput[1] - 49;
    //If a space on the grid is open...
    if (board[row][column] == BLANK){
      //And if it's X's turn...
      if (turn == X_TURN) {
	//When the gridpace is entered, put in an "X" for the inputted space
	board[row][column] = 'X';
	//Check for a tie after the piece has been placed
	if (checkTie(board) == true){
	  //If there is a tie, tell them it ended in a tie and ask if they want to play again.
	  cout << "This game has ended in a tie! Would you like to play again?" << endl;
	  
	  cin >> choice;
	  //If yes, clear the board and restart the game
	  if (choice == 'y'){
	    cin.clear();
	    clear(board);
	    cin.ignore(1000000, '\n');
	    playing = 1;
	  }
	  //If not, end the game
	  else{
	    playing = 0;
	  }
	}
	//Check for a win after every play as well
	if (checkWin(board, turn = X_TURN) == true){
	  X_WINS++;
	  printBoard(board);
	  //If X wins, tell the them X won and ask if they want to play again.
	  cout << "X Won!" << endl << "X wins: " << X_WINS << endl << "O wins: " << O_WINS << endl << "Would you like to play again?" << endl;
	  cin >> choice;
	  //If yes, clear the board and restart the game
	  if (choice == 'y'){
	    cin.clear();
	    clear(board);
	    cin.ignore(1000000, '\n');
	    playing = 1;
	  }
	  //If not, end the game.
	  else{
	    playing = 0;
	  }
	}
	//If it's not X's turn, it's O's turn
	else{
	  turn = O_TURN;
	  }
        }
      //Run the same program as X Turn
        else if (turn == O_TURN) {
	  board[row][column] = 'O';
	  if (checkTie(board) == true){
	    cout << "This game has ended in a tie! Would you like to play again?" << endl;
	    cin >> choice;
	    if (choice == 'y'){
	      cin.clear();
	      clear(board);
	      cin.ignore(1000000, '\n');
	      playing = 1;
	    }
	    else if (choice == 'n'){
	      playing = 0;
	    }
	    else {
	      cout << "Please choose y or n" << endl;
	    }
	  }
	  if (checkWin(board, turn = O_TURN) == true){
	    O_WINS++;
	    printBoard(board);
	    cout << "X wins: " << X_WINS << endl << "O wins: " << O_WINS << endl;
	    cout << "O Won! Would you like to play again?" << endl;
	    cin >> choice;
	    if (choice == 'y'){
	      cin.clear();
	      clear(board);
	      cin.ignore(1000000, '\n');
	      playing = 1;
	  }
	    else if (choice == 'n'){
	    playing = 0;
	  }
	  else {
	    cout << "Please choose y or n" << endl;
	  }
        }
	else{
	  turn = X_TURN;
	  }
	}
      }
    else{
      cout << "There is already a piece there. Please try again." << endl;
    }
    }
  }
}
//Set up a code for clearing the board using pointers
void clear(int** board){
  for(int row = 0; row < 3; row++){
    for(int column = 0; column < 3; column++){
     board[row][column] = BLANK;
    }
  }
}
//Set up a code for checking ties
bool checkTie(int**board){
  for(int row = 0; row < 3; row++){
    for(int column = 0; column < 3; column++){
      if(board[row][column] == BLANK){
	return false;
      }
    }
  }
    return true;
}
//Set up a code for checking wins
  bool checkWin(int** board, int & turn){
    //Convert the turn from a char to an int
    int convertedTurn;
    if (turn == X_TURN){
      convertedTurn = (int)'X';
    }
    else if (turn == O_TURN){
      convertedTurn = (int)'O';
    }
  for(int i = 0; i < 3; i++){
    //Write a code showing all the ways that a player can win
    if(board[i][0] == convertedTurn && board[i][1] == convertedTurn && board[i][2] == convertedTurn) {
      return true;
    }
    if(board[0][i] == convertedTurn && board[1][i] == convertedTurn && board[2][i] == convertedTurn) {
      return true;
    }
    if(board[0][0] == convertedTurn && board[1][1] == convertedTurn && board[2][2] == convertedTurn) {
      return true;
    }
    if(board[0][2] == convertedTurn && board[1][1] == convertedTurn && board[2][0] == convertedTurn) {
      return true;
    }
  }
  return false;
}
