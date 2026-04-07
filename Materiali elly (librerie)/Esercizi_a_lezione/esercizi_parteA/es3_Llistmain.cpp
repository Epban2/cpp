// esercizio sequenza di numeri

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the link template class
#include "link.h"

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "ListTest.h"

const int N = 100;

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

// Main routine 
int main(int argc, char** argv) {

  LList<Item> Listarray[N];  

  for (int i=0; i<N; i++) {
	  Item temp(i+1);
	  Listarray[i].insert(temp);
  }

  for (int i = 0; i<N; i++) {
	  int cur_number = i + 1;
	  while (cur_number!=1)
	  {
		  if (cur_number % 2 != 0)
			  cur_number = cur_number * 3 + 1;
		  else
			  cur_number = cur_number / 2;
		  Item temp(cur_number);
		  Listarray[i].append(temp);
	  }
  }

  int maxl=0;
  int maxnumber;
  for (int i = 0; i<N; i++) {
	  cout << "L" << i+1 << " "; lprint(Listarray[i]);
	  if (Listarray[i].length() > maxl)
	  {
		  maxl = Listarray[i].length();
		  maxnumber = i+1;
	  }
  }

  cout << endl << "numero che genera la sequenza piu' lunga:" << maxnumber << " " << " lunghezza:" << maxl << endl << endl;
 
  ofstream myfile("es3_sequenza_numeri.txt");
  for (Listarray[maxnumber-1].moveToStart(); Listarray[maxnumber - 1].currPos()<Listarray[maxnumber - 1].length(); Listarray[maxnumber - 1].next()) {
	  Item it = Listarray[maxnumber - 1].getValue();
	  myfile << it.key() << " ";
  }
  myfile.close();

  for (int i = 0; i<N; i++) {
	  selectionsort(Listarray[i]);
	  cout << "L" << i + 1 << " "; lprint(Listarray[i]);
  }

  cout << "That is all.\n";

  return 0;
}