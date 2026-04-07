// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions
using namespace std;

#include "list.h"
#include<string>


// Your basic int type as an object.
class Item {
private:
	string nome;
	string cognome;
	int giorno;
	int mese;
	int anno;
public:
	Item(string n = "", string c = "", int g = -1, int m = -1, int a = -1) { nome = n; cognome = c; giorno = g; mese = m; anno = a; }

	string getnome() const { return nome; }
	string getcognome() const { return cognome; }
	int getgiorno() const { return giorno; }
	int getmese() const { return mese; }
	int getanno() const { return anno; }
};

// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << "(" << i.getcognome() << " " << i.getnome() << " " << i.getgiorno() << "/" << i.getmese() << "/" << i.getanno() << ")";
}

// Assert: If "val" is false, print a message and terminate
// the program
inline void Assert(bool val, string s) {
	if (!val) { // Assertion failed -- close the program
		cout << "Assertion Failed: " << s << endl;
		exit(-1);
	}
}


// Print out the list (including showing position for the fence)
// Print list contents
template <typename E>
void lprint(List<E>& L) {
	int currpos = L.currPos();

	L.moveToStart();

	cout << "< ";
	int i;
	for (i = 0; i<currpos; i++) {
		cout << L.getValue() << " ";
		L.next();
	}
	cout << "| ";
	while (L.currPos()<L.length()) {
		cout << L.getValue() << " ";
		L.next();
	}
	cout << ">\n";
	L.moveToPos(currpos); // Reset the fence to its original position
}



#endif

