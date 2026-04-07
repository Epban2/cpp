// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for the array-based stack class

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "astack.h"

#include "AStackTest.h"

// Driver class for list implementations

// Main routine for array-based list driver class
int main(int argc, char** argv) {
  // Declare some sample lists
  AStack<Item> S1;

  Item temp;

  // Test a bunch of stack operations
  if (S1.length() > 0) {
    temp = S1.pop();
    cout << "Top is " << temp << endl;
  }
  else cout << "Nothing in stack\n";
  Item temp1(10);
  S1.push(temp1);
  cout << "Pushed " << temp1 << endl;
  Item temp2(20);
  S1.push(temp2);
  cout << "Pushed " << temp2 << endl;
  Item temp3(15);
  S1.push(temp3);
  cout << "Pushed " << temp3 << endl;
  cout << "Size is " << S1.length() << endl;
  if (S1.length() > 0) {
    temp = S1.pop();
    cout << "Popped " << temp << endl;
  }
  else cout << "Nothing in stack\n";
  cout << "Popping elements" << endl;
  while(S1.length() > 0) {
    temp = S1.pop();
    cout << temp << " ";
  }
  cout << endl;
  if (S1.length() > 0) {
    temp = S1.pop();
    cout << "Top is " << temp << endl;
  }
  else cout << "Nothing in stack\n";
  cout << "Size is " << S1.length() << endl;
  S1.clear();
  cout << "Size is " << S1.length() << endl;

  cout << "That is all.\n\n";
  return 0;
}