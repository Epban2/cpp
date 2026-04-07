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

#include "esercitazione5-es6-LQueueTest.h"

// Driver class for queue implementations

// Main routine for array-based queue driver class
int main(int argc, char** argv) {
  LQueue<Item> Q1;
  Item temp1,temp2,temp3;
  int N;
  float number;

  cout << "Inserire il numero N di numeri: ";
  cin >> N;
 
  for (int i=1; i<=N; i++)
  {
	  cin >> number;
	  Item temp1(number);
	  Q1.enqueue(temp1);
  }

  int iterazione = 0;
  while (Q1.length()>1)
  {
  int  Q1length = Q1.length();
   for (int i = 1; i <= Q1length/2; i++)
   {
	  temp1 = Q1.dequeue();
	  temp2 = Q1.dequeue();
	  float valore;
	       
	  switch (iterazione%4)
	  {
	   case (0): valore = temp1.key() + temp2.key();
		         break;
	   case (1): valore = temp1.key() - temp2.key();
				 break;
	   case (2): valore = temp1.key() * temp2.key();
				 break;
	   case (3): valore = temp1.key() / temp2.key(); //sarebbe meglio eseguire anche un test per evitare divisione per zero
		         break;
	  }
	  Item temp3(valore);
	  Q1.enqueue(temp3);
   }

   if (Q1length %2==1)
   {
	  temp1 = Q1.dequeue();
	  Q1.enqueue(temp1);
   }

   cout << "Q1 is: ";
   Lqueueprint(Q1);
   cout << endl;

   iterazione++;
  }

  cout << "That is all.\n\n";
}