//This is a program that takes a word or phrase and checks to see if it's a palindrome or not.
//Date: 9/24/2019
//Author: Teja Prakki

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <ctype.h>
#include <stdio.h>


using namespace std;

int main ()
{
  //Initiate the Char Arrays
  char str[81];
  char str2[81];
  char temp;
  //Tell the user to type in a word
  cout << "Type a Word or Phrase to check if it's a Palindrome!" << endl;
  //Get the input and...
  cin.get(str, 81);
  for(int i = 0; i < 81; i++){
    //make the phrase lowercase
    str[i] = tolower(str[i]);
    //remove all punctuation
    if (str[i] == ' ' || ispunct(str[i])){
      for(int a = i; a < 80; a++){
	//and remove all spacing
	str[a] = str[a+1];
      }
      i--;
    }
    
  }
  //Reverse the phrase to seit it up to compare with the original string
  for(int i = 0; i < 81; i++){
    temp = str[i];
    //Credit: Mark Daniloff
    str2[i] = str[strlen(str) -1 -i];
    temp = str[strlen(str) -1 -i];
  }
  //Compare the two strings to see if it is a palindrome
  int count = strcmp (str, str2);
  //If the count is 0...
  if (count == 0){
    //It's a palindrome
    cout << "This is a Palindrome" << endl;
    cout << str2 << endl;
  }
  //Otherwise...
  else {
    //It's not a palindrome
    cout << "This is not a Palindrome" << endl;
    cout << str2 << endl;
  }
}
