#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

//Credit: Tejash Panda and Michael Yan

//Code by: Teja Prakki. Heap is a program that collects numbers manually or through a file and creates a numerical tree from it.

void heap(int heapArray[], int &heapSize, int current){
  int parent = current;
  int left = 2 * current + 1;
  int right = 2 * current + 2;
  
  if(heapArray[left] > heapArray[parent] && left < heapSize){ //If left is larger than the parent...
    parent = left; //Set left to be the parent
  }
  if(heapArray[right] > heapArray[parent] && right < heapSize){ //If right is larger than the parent...
    parent = right;  //Set right to be the parent
  }
  if(parent != current){ //If the parent is not the current node...
    swap(heapArray[current], heapArray[parent]); //Swap the current and the parent values
    //Recursively run Heap algorithm
    heap(heapArray, heapSize, parent);
  }
}
void buildHeap(int heapArray[], int &heapSize){ //Build the heap from array
  int startIndex = (heapSize/2)-1;
  for(int current = startIndex; current >= 0; current--){ //Iteration from startIndex
    heap(heapArray, heapSize, current); //Heap algorithm is run
  }
}
void printHeap(int heapArray[], int &heapSize, int x, int current){ //Printing the heap...
  int left = 2*current;
  int right = 2*current+1;
  if(right <= heapSize){
    printHeap(heapArray, heapSize, x+1, right); //Call recursively to print
  }
  int actualIndex = x; //This is the actual index
  while (x > 0){
    cout << "   ";
    x--;
  }
  cout << heapArray[current-1] << endl; //Printing it
  if (left <= heapSize){
    printHeap(heapArray, heapSize, actualIndex+1, left);
  }
  
}
void deleteSort(int heapArray[], int orderArray[], int &heapSize, int y){ //Deleting and Sorting algorithm
  int z = 0;
  
  while(y > 0){ //While loop as long as Heap has something in it
    int move;
    move = heapArray[0];
    heapArray[0] = heapArray[heapSize-1]; //Find the smallest
    cout << heapArray[0];
    heapSize--; //Make the Heap Size smaller as they are being essentially deleted
    orderArray[z] = move;
    z++;
    buildHeap(heapArray, heapSize);
    cout << endl;
    for(int t = 0; t < heapSize-1; t++){ //Print the array each time to show deletion
      cout << heapArray[t] << " ";
    }
    y--;
  }
  
}
int main(){
  
  cout << "Would you like to enter numbers in the console or enter via txt file? Type 'manual' or 'file': "; //Ask the user if they want to manually enter numbers or use a file.
  char methodinput[50];
  cin.getline(methodinput, 50);
  
  int v; //Initialize variables
  
  int inputarr[1000]; //initialize inputarray
  
  if(strcmp(methodinput, "manual") == 0){ //If the user wants to input them manually...
    cout << "\nNOTE: Any non-numerical characters will be treated as a zero int value. Any floats will be rounded down." << endl;
    cout << "Type 'stop' when you are finished." << endl;
    int i = 0;
    bool inputting = true;
    while(inputting == true){ //As long as numbers are being inputted
      char token[10];
      cin.getline(token, 10);
      if(strcmp(token, "stop") == 0){ //When the user types stop, break the loop
	inputting = false;
      }
      //Credit Tejash for atoi command
      inputarr[i] = atoi(token); //Convert the input into an int
      i++; //Array grows everytime a number is added
    }
    v = i-1; //Remove the "stop" from memory
  }
  //credit: Michael Yan
  else if(strcmp(methodinput, "file") == 0){ //If the user wants to use a file...
    cout << "Type the file name (include the .txt extension): ";
    char* filename = new char[100];
    cin.getline(filename, 100);
    ifstream inFile;
    inFile.open(filename);
    int inputToken;
    int count = 0;
    int i;
    while(inFile >> inputToken){ //Input from file
      inputarr[count] = inputToken;
      count++;
      i++;
    }
    v = i-1;
  }
  int heapArray[v]; //Initialize the array
  for(int r = 0; r < v; r++){
    heapArray[r] = inputarr[r];
  }
  int heapSize = sizeof(heapArray) / sizeof(heapArray[0]);
  int newHeapSize;
  buildHeap(heapArray, heapSize); //Construct it using Heap algorithm
  int orderArray[v]; //Initialize the output array
  cout << "Heap array: ";
  for(int t = 0; t < heapSize; t++){ //Print the array
    cout << heapArray[t] << " ";
  }
  cout << " Size: " << heapSize;
  cout << " Tree: " << endl;
  printHeap(heapArray, heapSize, 0, 1); //Print heap as a tree
  cout << "Heap array: " << endl;
  for(int t = 0; t < heapSize-1; t++){ //Print heap before deletion and sorting
    cout << heapArray[t] << " ";
  }
  deleteSort(heapArray, orderArray, heapSize, heapSize); //Run srot algorithm
  cout << endl;
  cout << "Sequenced list: " << endl;
  for(int t = 0; t < v; t++){
    cout << orderArray[t] << " ";
  }
  return 0;
} 
