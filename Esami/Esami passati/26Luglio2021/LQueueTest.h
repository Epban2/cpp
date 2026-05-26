// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#ifndef LQUEUETEST_H
#define LQUEUETEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "lqueue.h"

// Your basic int type as an object.
class Item {
private:
	int codice;
	string nome;
	string nazione;
	float altezza;
public:
	Item(int c = -1, string n = "", string na = "", float a = -1) { codice = c; nome = n; nazione = na; altezza = a;}
	int getcodice() const { return codice; }
	string getnome() const { return nome; }
	float getaltezza() const { return altezza; }
	string getnazione() const { return nazione; }
	bool operator<(const Item& other) const {
		if (codice < other.getcodice()) return true;
		else return false;
	}
};

// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << "(" << i.getcodice() << "," << i.getnome() << "," << i.getnazione() << "," << i.getaltezza() << ")";
}


// Assert: If "val" is false, print a message and terminate
// the program
inline void Assert(bool val, string s) {
  if (!val) { // Assertion failed -- close the program
    cout << "Assertion Failed: " << s << endl;
    exit(-1);
  }
}

// Print the queue
template <typename E>
void Lqueueprint(LQueue<E>& Q) {
	for (int i=0; i<Q.length(); i++)
	{
		E dequeued = Q.dequeue();
		cout << dequeued << " ";
		Q.enqueue(dequeued);
	}
}

#endif

