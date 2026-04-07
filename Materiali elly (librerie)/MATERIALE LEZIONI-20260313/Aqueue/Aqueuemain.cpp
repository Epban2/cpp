// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for the array-based queue class

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "aqueue.h"

#include "AQueueTest.h"

// Driver class for queue implementations

// Main routine for array-based queue driver class
int main(int argc, char** argv) {
  AQueue<Item> Q1;
  Item temp;

  // Test a bunch of queue operations
  Item temp1(10);
  cout << "Enqueue " << temp1 << endl;
  Q1.enqueue(temp1);
  Item temp2(20);
  cout << "Enqueue " << temp2 << endl;
  Q1.enqueue(temp2);
  Item temp3(15);
  cout << "Enqueue " << temp3 << endl;
  Q1.enqueue(temp3);
  cout << "Length is " << Q1.length() << endl;
  if (Q1.length() > 0) {
    temp = Q1.frontValue();
    cout << "Front is " << temp << endl;
  }
  else cout << "Nothing in queue\n";
  cout << "Dequeueing elements" << endl;
  while(Q1.length() > 0) {
    temp = Q1.dequeue();
    cout << temp << " ";
  }
  cout << endl;
  cout << "Length is " << Q1.length() << endl;
  if (Q1.length() > 0) {
    temp = Q1.frontValue();
    cout << "Front is " << temp << endl;
  }
  else cout << "Nothing in queue\n";
  Q1.clear();
  cout << "Length is " << Q1.length() << endl;
  cout << "That is all.\n\n";
}