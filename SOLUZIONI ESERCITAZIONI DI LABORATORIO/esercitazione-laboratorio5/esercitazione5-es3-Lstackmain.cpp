// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for the linked stack class

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "lstack.h"

#include "LStackTest.h"

// Driver class for list implementations

// Main routine for array-based list driver class
int main(int argc, char** argv) {
  // Declare some sample lists
  LStack<Item> S1,S2;
 
  Item temp;
  int N = 10;

  for (int i=1; i<=N; i++)
  {
   Item temp(i);
   S1.push(temp);
  }

  cout << "S1: ";
  Lstackprint<Item>(S1);
  cout << endl;

  int fact=1;
  for (int i = 1; i <= N; i++)
  {
	  temp = S1.pop();
	  fact *= temp.key();
  }
 
  cout << "fact(" << N << "): " << fact;
  Lstackprint<Item>(S1);
  cout << endl;

  cout << endl << "That is all.\n\n";
  return 0;
}