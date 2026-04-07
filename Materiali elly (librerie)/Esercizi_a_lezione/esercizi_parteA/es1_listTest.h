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

class prodotto {
private:
  string codice;
  string nomeprodotto;
  int quantita;
public:
	prodotto() { }
	prodotto(string c, string n, int q) { codice = c; nomeprodotto = n; quantita = q; }
  // The following is for those times when we actually
  //   need to get a value, rather than compare objects.
  string key() const { return codice; }
  string getnome() const { return nomeprodotto; }
  int getquantita() const { return quantita; }
  void setquantita(int q) { quantita = q; }
};

struct ricetta{ 
	int numero;
	string descrizione;
	string ingrediente1;
	int quantita_ingr1;
	string ingrediente2;
	int quantita_ingr2;
};

class Item {
private:
	ricetta ric;
public:
	Item() { }
	Item(ricetta r) { ric = r; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	ricetta key() const { return ric; }
};

// Let us print out Items easily
inline ostream& operator<<(ostream& s, const prodotto& i)
{
	return s << "(" << i.key() << " " << i.getnome() << " " << i.getquantita() << ")";
}

// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << "(" << i.key().numero << " " << i.key().descrizione << " " << i.key().ingrediente1 << "-" << i.key().quantita_ingr1 << " " << i.key().ingrediente2 << "-" << i.key().quantita_ingr2 << ")";
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
  for (i=0; i<currpos; i++) {
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

