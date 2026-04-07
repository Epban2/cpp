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

/*
// Your basic int type as an object.
class Item {
private:
  int val;
public:
  Item(int input=0) { val = input; }
  // The following is for those times when we actually
  //   need to get a value, rather than compare objects.
  int key() const { return val; }
};


// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i)
  { return s << i.key(); }
  */

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

// find function for Items.
// Return true if "K" is in list "L", false otherwise
inline int find(List<Item>& L, int K) {
  Item it;
  for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
    it = L.getValue();
    if (K == it.key() ) return L.currPos();  // Found K
  }
  return -1;                // K not found
}

// find function for Items.
// Return true if "item" is in list "L", false otherwise
inline int find(List<Item>& L, const Item& item_to_search) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (item_to_search.key() == it.key()) return L.currPos();  // Found K
	}
	return -1;                // K not found
}

// Insert "it" at current position
inline void insert_ordered(List<Item>& L, const Item& it) {
	if (L.length() == 0)
	{
		L.insert(it);
		return;
	}
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		if (it.key() <= L.getValue().key())
		{
			L.insert(it);
			return;
		}
	}
	L.append(it);
}

inline void selectionsort(List<Item>& L) {
   int min_pos;
   int min_value;
   Item it_curr;
   Item it_temp;
   // se lunghezza <2 non fai nulla
   for (int i=0; i<(L.length()-1); i++) {
	   L.moveToPos(i);
	   it_curr = L.getValue();
	   min_pos=i;
	   min_value = it_curr.key();
	   for (int j=i+1; j<L.length(); j++) {
		  L.moveToPos(j);
          it_temp = L.getValue();
          if (it_temp.key() < min_value ) 
			  {
				min_pos=L.currPos(); 
				min_value = it_temp.key();
              }
        }
	   L.moveToPos(min_pos);
	   it_temp=L.remove();
	   L.moveToPos(i);
	   L.insert(it_temp);
   }
  
 }

inline void bubblesort(List<Item>& L) {
	for (int i = 0; i< (L.length() - 1); i++) {
		for (int j = (L.length()-1); j> i; j--) {
			L.moveToPos(j);
			Item it_j = L.getValue();
			L.moveToPos(j-1);
			Item it_jj = L.getValue();
			if (it_jj.key()>it_j.key()) 
			{
				L.moveToPos(j);
				Item removed = L.remove();
				L.moveToPos(j-1);
				L.insert(removed);
			}
		}
	}
}



#endif

