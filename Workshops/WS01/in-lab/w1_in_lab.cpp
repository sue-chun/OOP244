/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// File	w1_in_lab.cpp
// Version 1.0
// Date	2016/01/10
// Author	Fardad Soleimanloo
// Description
// This provides some source code in a single file to break 
// into modules and compile together
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad
/////////////////////////////////////////////////////////////////
***********************************************************************/


#include <iostream>
using namespace std;

// Maximum number of samples in an graph
#define MAX_NO_OF_SAMPLES 20
// Performs a fool-proof integer entry
int getInt(int min, int max);
// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples);
// Displays the user interface menu
int menu();
// Finds the largest sample in the samples array, if it is larger than 70,
// therwise it will return 70. 
int findMax(int samples[], int noOfSamples);
// Prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);
// Prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples);



// SeneGraph program
int main(){
  int noOfSamples = 0;
  int samples[MAX_NO_OF_SAMPLES] = { 0 };
  bool done = false;
  cout << "Welcome to SeneGraph" << endl;
  while (!done){
    cout << "No Of Samples: " << noOfSamples << endl;
    switch (menu()){
    case 1:
      cout << "Enter number of samples on hand: ";
      noOfSamples = getInt(1, MAX_NO_OF_SAMPLES);
      break;
    case 2:
      if (noOfSamples == 0){
        cout << "First enter the number of Samples." << endl;
      }
      else{
        cout << "Please enter the sample values: " << endl;
        getSamples(samples, noOfSamples);
      }
      break;
    case 3:
      if (noOfSamples == 0){
        cout << "First enter the number of Samples." << endl;
      }
      else if (samples[0] == 0){
        cout << "Firt enter the samples." << endl;
      }
      else{
        printGraph(samples, noOfSamples);
      }
      break;
    case 0:
      cout << "Thanks for using SeneGraph" << endl;
      done = true;
    }
  }
  return 0;
}

// displays the user interface menu
int menu(){
  cout << "1- Number of Samples" << endl;
  cout << "2- Sample Entry" << endl;
  cout << "3- Draw Graph" << endl;
  cout << "0- Exit" << endl;
  cout << "> ";
  return getInt(0, 3);
}

// Performs a fool-proof integer entry
int getInt(int min, int max){
  int val;
  bool done = false;
  while (!done){
    cin >> val;
    if (cin.fail()){
      cin.clear();
      cout << "Invalid Integer, try again: ";
    }
    else{
      if (val < min || val > max){
        cout << "Invalid value!" << endl << "Enter a value between " << min << " and " << max << ": ";
      }
      else{
        done = true;
      }
    }
    cin.ignore(1000, '\n');
  }
  return val;
}
// prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples){
  int max = findMax(samples, noOfSamples);
  cout << "Graph:" << endl;
  for (int i = 0; i < noOfSamples; i++){
    printBar(samples[i], max);
  }
}
// prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max){
  int i;
  for (i = 0; i < 70 * val / max; i++){
    cout << "*";
  }
  cout << " " << val << endl;
}

// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples){
  int i;
  for (i = 0; i < noOfSamples; i++){
    cout << (i + 1) << "/" << noOfSamples << ": ";
    samples[i] = getInt(1, 1000000);
  }
}

// finds the largest sample in the samples array, if it is larger than 70,
// otherwise it will return 70. 
int findMax(int samples[], int noOfSamples){
  int max = samples[0];
  int i;
  for (i = 1; i < noOfSamples; i++){
    if (max < samples[i]) max = samples[i];
  }
  return max < 70 ? 70 : max;
}

