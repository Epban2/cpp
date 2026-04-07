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

#include "LQueueTest.h"

//Si vuole simulare un sistema in cui sono presenti M code a cui devono essere assegnati N clienti 
//che attendono di essere serviti. Ad ogni iterazione viene selezionata una coda in modo casuale 
//in cui inserire il nuovo cliente e una seconda coda, sempre in modo casuale, da cui prelevare 
//il cliente in testa (se esiste) da servire.
void QueueServiceSimulation()
{
	srand(time(NULL));
	const int M = 5;
	const int N = 100;
	LQueue<Item> queues[M];

	for (int i = 0; i <= N; i++)
	{
		int in = rand() % M;
		int out = rand() % M;
		Item item(rand() % 100);

		cout << "enqueue " << item << " in queue " << in << endl;
		queues[in].enqueue(item);
		if (queues[out].length() > 0)
		{
			cout << "dequeue from " << out << endl;
			queues[out].dequeue();
		}

		for (int j = 0; j < M; j++)
		{
			cout << "queue[" << j << "] : ";
			if (queues[j].length()>0)
			 Lqueueprint(queues[j]);
			cout << endl;
		}
		cout << endl;
	}
}

// Test di uguaglianza tra due code (il test distrugge le due code)
int equal_queues(LQueue<Item>& Q1, LQueue<Item>& Q2)
{
	if (Q1.length() != Q2.length())
		return 0;
	while (Q1.length()>0)
	{
		Item q1 = Q1.dequeue();
		Item q2 = Q2.dequeue();
		if (q1.key() != q2.key())
			return 0;
	}
	return 1;
}

// Driver class for queue implementations

// Main routine for array-based queue driver class
int main(int argc, char** argv) {
  LQueue<Item> Q1,Q2;
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

  Q1.enqueue(Item(4400));
  Q1.enqueue(Item(31));
  Q1.enqueue(Item(11));
  cout << "Queue is: ";  
  Lqueueprint(Q1);
  cout << endl;

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

  cout << "QueueServiceSimulation()" << endl;
  QueueServiceSimulation();


  Q1.clear(); Q2.clear();
  Q1.enqueue(Item(1));
  Q1.enqueue(Item(2));
  Q1.enqueue(Item(3));
  Q1.enqueue(Item(4));

  Q2.enqueue(Item(1));
  Q2.enqueue(Item(20));
  Q2.enqueue(Item(3));
  Q2.enqueue(Item(4));
  cout << "Q1 equal to Q2 = " << equal_queues(Q1,Q2) << endl;
  cout << "That is all.\n\n";
}