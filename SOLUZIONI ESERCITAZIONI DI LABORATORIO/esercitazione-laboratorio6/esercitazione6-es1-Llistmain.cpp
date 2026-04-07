// Linked list class test program

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the link template class
#include "link.h"

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "listTest.h"

const int MINVAL = 20;
const int MAXVAL = 80;
const int N = 6;

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
  srand(time(NULL));
  // Declare some sample lists
  LList<Item> L1,L2;
  int randNum;

  for (int i = 0; i<N; i++) {
	  randNum = rand() % (MAXVAL - MINVAL + 1) + MINVAL;
	  L1.insert(Item(randNum));
	  randNum = rand() % (MAXVAL - MINVAL + 1) + MINVAL;
	  L2.insert(Item(randNum));
  }
  
  cout << "L1: "; lprint(L1);
  cout << "L2: "; lprint(L2);

  Item it_temp;
  L1.moveToStart();
  for (int i = 0; i<L2.length(); i++) {
	  L2.moveToPos(i);
	  it_temp = L2.getValue();
	  L1.insert(it_temp);
  }

  selectionsort(L1);

  cout << "L1: "; lprint(L1);
  cout << "That is all.\n";

  return 0;
}