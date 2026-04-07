// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Linked list class test program

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "ListTest.h"

void selectionsort(List<Item>& L) {
	int min_pos;
	Item min_element;
	// se lunghezza <2 non fai nulla
	for (int i = 0; i<L.length() - 1; i++) {
		L.moveToPos(i);
		min_element = L.getValue();
		min_pos = i;
		for (int j = i + 1; j<L.length(); j++) {
			L.moveToPos(j);
			Item it_temp = L.getValue();
			if (it_temp.key() < min_element.key())
			{
				min_pos = L.currPos();
				min_element = it_temp;
			}
		}
		L.moveToPos(min_pos);
		Item it_temp = L.remove();
		L.moveToPos(i);
		L.insert(it_temp);
	}
}

void bubblesort(List<Item>& L) {
	for (int i = 0; i< (L.length() - 1); i++) {
		for (int j = (L.length() - 1); j> i; j--) {
			L.moveToPos(j);
			Item it_j = L.getValue();
			L.moveToPos(j - 1);
			Item it_jj = L.getValue();
			if (it_jj.key()>it_j.key())
			{
				L.moveToPos(j);
				Item removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
}

void merge(LList<Item>& Lm, LList<Item>& La, LList<Item>& Lb) {
	La.moveToStart();
	Lb.moveToStart();
	Item removed;
	int N = La.length();
	int M = Lb.length();
	for (int k = 0; k < N + M; k++)
	{
		if (La.length() == 0)
		{
			removed = Lb.remove();
			Lm.append(removed);
			continue;
		}
		if (Lb.length() == 0)
		{
			removed = La.remove();
			Lm.append(removed);
			continue;
		}
		if (La.getValue().key()<Lb.getValue().key())
			removed = La.remove();
		else
			removed = Lb.remove();
		Lm.append(removed);
	}
}

void mergesort(LList<Item>& Lm)
{
	Lm.moveToStart();
	if (Lm.length() < 2) return;
	LList<Item> La, Lb;
	Item removed;
	int N = Lm.length();
	for (int k = 0; k<N; k++) {
		removed = Lm.remove();
		if (k % 2) La.append(removed);
		else Lb.append(removed);
	}
	mergesort(La);
	mergesort(Lb);
	merge(Lm, La, Lb);
}

// Main routine for linked list driver class
int main(int argc, char** argv) {

  // Declare some sample lists
  LList<Item> L1;  
  Item temp;
  L1.moveToStart();

  L1.insert(Item(39));
  L1.insert(Item(9));
  L1.insert(Item(5));
  L1.insert(Item(4));
  L1.insert(Item(3));
  L1.insert(Item(2));
  L1.insert(Item(1));
  L1.insert(Item(100));
  L1.insert(Item(91));
  L1.insert(Item(8));
  L1.insert(Item(43));
  L1.insert(Item(22));
  L1.insert(Item(2));
  L1.insert(Item(0));
  L1.insert(Item(60));
  L1.insert(Item(0));
  L1.insert(Item(1));
  L1.insert(Item(56));
  cout << "L1: "; lprint(L1);
  selectionsort(L1);
  cout << "SELECTION SORT L1: "; lprint(L1);
  
  L1.clear();

  L1.insert(Item(39));
  L1.insert(Item(9));
  L1.insert(Item(5));
  L1.insert(Item(4));
  L1.insert(Item(3));
  L1.insert(Item(2));
  L1.insert(Item(1));
  L1.insert(Item(100));
  L1.insert(Item(91));
  L1.insert(Item(8));
  L1.insert(Item(43));
  L1.insert(Item(22));
  L1.insert(Item(2));
  L1.insert(Item(0));
  L1.insert(Item(60));
  L1.insert(Item(0));
  L1.insert(Item(1));
  L1.insert(Item(56));
  bubblesort(L1);
  cout << "BUBBLE SORT L1: "; lprint(L1);

  //Test Mergesort
  LList<Item> La;
  LList<Item> Lb;
  LList<Item> Lm;
  La.append(Item(3));
  La.append(Item(10));
  La.append(Item(17));
  Lb.append(Item(1));
  Lb.append(Item(12));
  cout << "La: "; lprint(La);
  cout << "Lb: "; lprint(Lb);
  cout << "Lm: "; lprint(Lm);
  merge(Lm, La, Lb);
  cout << "After Merge La: "; lprint(La);
  cout << "After Merge Lb: "; lprint(Lb);
  cout << "After Merge Lm: "; lprint(Lm);
  Lm.clear();
  Lm.append(Item(3));
  Lm.append(Item(10));
  Lm.append(Item(17));
  Lm.append(Item(1));
  Lm.append(Item(12));
  Lm.append(Item(17));
  Lm.append(Item(109));
  Lm.append(Item(2));
  Lm.append(Item(174));
  cout << "Lm before Merge SORT : "; lprint(Lm);
  mergesort(Lm);
  cout << "Lm after Merge SORT: "; lprint(Lm);

  cout << "That is all.\n";

  return 0;
}