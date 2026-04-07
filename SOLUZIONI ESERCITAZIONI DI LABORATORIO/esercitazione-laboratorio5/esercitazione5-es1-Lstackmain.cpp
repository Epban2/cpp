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

#include "esercitazione5-es1-LStackTest.h"

// Driver class for list implementations

// Main routine for array-based list driver class
int main(int argc, char** argv) {
  // Declare some sample lists
  LStack<Item> S1,S2;
 
  S1.push(Item(1));
  S1.push(Item(2));
  S1.push(Item(3));
  S1.push(Item(4));
  S1.push(Item(5));
  cout << "S1: ";
  Lstackprint<Item>(S1);
  cout << endl;

  Reverse<Item>(S1);

  cout << "S1: ";
  Lstackprint<Item>(S1);
  cout << endl << "That is all.\n\n";
  return 0;
}