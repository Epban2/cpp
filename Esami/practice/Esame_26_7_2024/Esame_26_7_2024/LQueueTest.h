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
const int DEFAULT_CODE = -1;
#include "lqueue.h"

// Your basic int type as an object.
class Item {
private:
	string nome;
	string nazione;
	int codice;
	float altezza;

public:
	Item(int c = DEFAULT_CODE, string n = "", string na = "", float alt = 0) { codice = c; nome = n; nazione = na; altezza = alt; }
	int key() const { return codice; }
	string getNome() const { return nome; }
	string getNazione() const { return nazione; }
	float getAltezza() const { return altezza; }
};


// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << "(" << i.key() << "," << i.getNome() << "," << i.getNazione() << "," << i.getAltezza() << ") ";
}
inline bool operator  < (const Item& i1, const Item& i2) {
	if (i1.key() < i2.key())
		return true;
	return false;
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
	for (int i = 0; i < Q.length(); i++)
	{
		E dequeued = Q.dequeue();
		cout << dequeued << " ";
		Q.enqueue(dequeued);
	}
}

#endif

