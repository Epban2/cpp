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

#include "llist.h"

#include "esercitazione5-es4-LStackTest.h"

// Driver class for list implementations

// Main routine for array-based list driver class
int main(int argc, char** argv) {
  // Declare some sample lists
  LStack<Item> S1,S2;
 
  Item temp1,temp2,temp3;
  int N = 12;

  S1.push(Item(1));
  S1.push(Item(1));
  cout << "S1: ";
  Lstackprint<Item>(S1);
  cout << endl;

  for (int i = 1; i <= N-2; i++)
  {
	  temp1 = S1.pop();
	  temp2 = S1.pop();
	  Item temp3(temp1.key() + temp2.key());
	  S1.push(temp2);
	  S1.push(temp1);
	  S1.push(temp3);
  }
 
  cout << "S1: ";
  Lstackprint<Item>(S1);
  cout << endl;

  LList<Item> L1;
  while (S1.length() > 0)
  {
	  Item popped = S1.pop();
	  L1.insert(popped);
  }
  cout << "L1: ";
  lprint(L1);

  cout << endl << "That is all.\n\n";
  return 0;
}