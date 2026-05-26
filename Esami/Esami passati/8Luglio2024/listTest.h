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

#include "lqueue.h"

string maxKey = "";

// Your basic int type as an object.
class Item {
private:
  float tiratura;
  string nome;
  string sede;
  int anno;
public:
	Item(string n = maxKey, float t = 0.0, string s = "", int a = 0) { nome = n; tiratura = t; sede = s; anno = a; }
  // The following is for those times when we actually
  //   need to get a value, rather than compare objects.

  int null()
	{
		return sede == maxKey;
	}
  string key() const { return sede; }

  float gettiratura() const { return tiratura; }
  string getnome() const { return nome; }
  int getanno() const { return anno; }
  void setnome(string s) { nome=s; }

  void show(ostream& os = cout)
  {
	  os << "(" << nome << "," << tiratura << "," << sede << "," << anno << ") ";
  }
};


// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Item& i)
  { return s << "(" << i.getnome() << "," << i.gettiratura() << "," << i.key() << "," << i.getanno() << ")"; }
 
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

