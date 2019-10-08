 //This is a program that allows 2 player to play the game of Tic Tac Toe. Also checks for wins.
//Date: 9/26/2019
//Author: Teja Prakki

#include <iostream>

using namespace std;

void printBoard(int** board) { //Print the 3x3 board
cout << " " << "1" << "2" << "3" << endl;
cout << "a" << (char)board[0][0] << (char)board[0][1] << (char)board[0][2] << endl;
cout << "b" << (char)board[1][0] << (char)board[1][1] << (char)board[1][2] << endl;
cout << "c" << (char)board[2][0] << (char)board[2][1] << (char)board[2][2] << endl;
}
bool win(int** board, char player);
int main () {
  int** board = new int *[3];
  for (int a = 0; a < 3; a++){
    board [a] = new int[3];
    for (int b = 0; b < 3; b++){
      board[a][b] = 0;
    }
  }
  char moveInput [1];
  int playing = 1;
  int X_WINS = 0;
  int O_WINS = 0;
  int TIES = 0;
  int BLANK = 0;
  int X_MOVE = 1;
  int O_MOVE = 2;
  int X_TURN = 0;
  int O_TURN = 1;
  int turn = X_TURN;
  char playAgain = 'y';
  //char player = 'x';
  while (playing == 1){
  cout << "Please enter a gridspace!" << endl;
  printBoard(board);
  cin.get(moveInput, 3);
  cin.ignore();
  if ((moveInput[0] != 'a') && (moveInput[0] != 'b') && (moveInput[0] != 'c')) {
    cout << "Please enter a, b, or c for your first character" << endl;
    }
  else if ((moveInput[1] != '1') && (moveInput[1] != '2') && (moveInput[1] != '3')) {
    cout << "Please enter 1, 2, or 3 for your second character" << endl;
    }
  else {
    int row = moveInput[0] - 97;
    int column = moveInput[1] - 49;
    if (board[row][column] == BLANK){
      if (turn == X_TURN) {
	board[row][column] = 'X';
	turn = O_TURN;
        }
      else if (turn == O_TURN) {
	board[row][column] = 'O';
	turn = X_TURN;
        }
      }
    }
  }
}
bool win(int** board, char player, int & turn){
  for(int i = 0; i < 3; i++){
    if(board[0][i] == turn && board[1][i] == turn && board[2][i] == turn) {
      return true;
    }
  }
}
