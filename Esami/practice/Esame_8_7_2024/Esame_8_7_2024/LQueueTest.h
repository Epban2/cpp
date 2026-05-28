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

	float tiratura;
	int anno;
	string nome;
	string keyval;

public:
	Item(string n = "", float t = 0, string s = "", int a = 0) { nome = n; tiratura = t; keyval = s; anno = a; }

	float getTiratura() const { return tiratura; }
	int getAnno() const { return anno; }
	string getNome() const { return nome; }
	string key() const { return keyval; }
	void setNome(string n) { nome = n; }
	void show(ostream& os = cout) { cout << "(" << nome << "," << tiratura << "," << keyval << "," << anno << ")  "; }
};

inline ostream& operator << (ostream& os, const Item& i) {
	return os << "(" << i.getNome() << "," << i.getTiratura() << "," << i.key() << "," << i.getAnno() << ") ";
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

