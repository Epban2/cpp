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
#include "Lstack.h"

// Your basic int type as an object.
class Item {
private:
  int number;
  string name;
  string surname;
public:
  Item() { }
  Item(int n, string np, string sname) { number = n; name = np; surname = sname; }
  // The following is for those times when we actually
  //   need to get a value, rather than compare objects.
  int key() const { return number; }
  string getname() const { return name; }
  string getsurname() const { return surname; }
};

// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
{
	return s << "(" << i.key() << " " << i.getname() << " "<< i.getsurname() << ")";
}



// Assert: If "val" is false, print a message and terminate
// the program
void Assert(bool val, string s) {
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

// Print out the stack
template <typename E>
void Lstackprint(LStack<E>& S) {
	LStack<E> Stemp;
	while (S.length()>0)
	{
		E popped = S.pop();
		cout << popped << " ";
		Stemp.push(popped);
	}
	while (Stemp.length()>0)
	{
		E popped = Stemp.pop();
		S.push(popped);
	}
}

#endif

