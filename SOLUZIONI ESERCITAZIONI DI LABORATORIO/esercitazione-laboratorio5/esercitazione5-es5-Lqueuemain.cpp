// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for the linked queue class

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "lqueue.h"

#include "esercitazione5-es5-LQueueTest.h"

// Driver class for queue implementations

// Main routine for array-based queue driver class
int main(int argc, char** argv) {
  LQueue<Item> Q1,Q2;
  Item temp;

  Q1.enqueue(Item(1));
  Q1.enqueue(Item(2));
  Q1.enqueue(Item(3));
  Q1.enqueue(Item(4));

  Q2.enqueue(Item(1));
  Q2.enqueue(Item(2));
  Q2.enqueue(Item(3));
  Q2.enqueue(Item(4));
  cout << "Q1 equal to Q2 = " << equal_queues(Q1,Q2) << endl;
  cout << "That is all.\n\n";
}