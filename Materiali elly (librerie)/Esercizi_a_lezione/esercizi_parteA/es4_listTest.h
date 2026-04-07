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

class Item {
private:
	int mese_iniziale;
	int mese_finale;
	float importo;
public:
	Item(int mese_i = 0, int mese_f = 0, float i=0.0) { mese_iniziale = mese_i; mese_finale = mese_f; importo = i; }
	// The following is for those times when we actually
	//   need to get a value, rather than compare objects.
	int getmesei() const { return mese_iniziale; }
	int getmesef() const { return mese_finale; }
	float getimporto() const { return importo; }
};


class mese {
private:
  int nmese;
  float spesa_mensile;
public:
	mese(int n=0, float s_mensile=0.0) { nmese = n; spesa_mensile = s_mensile; }
  // The following is for those times when we actually
  //   need to get a value, rather than compare objects.
  int key() const { return nmese; }
  float getspesa_mensile() const { return spesa_mensile; }
  void setspesa_mensile(float q) { spesa_mensile = q; }
};


// Let us print out Items easily
inline ostream& operator<<(ostream& s, const mese& i)
{
	return s << "(" << i.key() << " " << i.getspesa_mensile() << ")";
}


// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << "(" << i.getmesei() << " " << i.getmesef() << " " << i.getimporto() << ")";
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

