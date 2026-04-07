//Scrivere un programma che crei un array di liste di dimensione N. 
//Le liste contengono Item con valori interi positivi. 
//Il programma deve calcolare l’indice dell’array contenente la lista in cui compare l’elemento di valore massimo tra gli elementi di tutte le liste. 

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Include the link template class
#include "link.h"

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "ListTest.h"

const int N = 3;

// Main routine for linked list driver class
int main(int argc, char** argv) {

  LList<Item> array_of_lists[N];
  LList<Item> L1;  
  Item it;

  array_of_lists[0].append(Item(15));
  array_of_lists[0].append(Item(3));
  array_of_lists[0].append(Item(21));
  cout << "array_of_lists[0]: "; lprint(array_of_lists[0]);

  array_of_lists[1].append(Item(211));
  array_of_lists[1].append(Item(1));
  array_of_lists[1].append(Item(1000));
  array_of_lists[1].append(Item(14));
  cout << "array_of_lists[1]: "; lprint(array_of_lists[1]);

  array_of_lists[2].append(Item(7));
  array_of_lists[2].append(Item(98));
  array_of_lists[2].append(Item(73));
  array_of_lists[2].append(Item(31));
  array_of_lists[2].append(Item(24));
  cout << "array_of_lists[2]: "; lprint(array_of_lists[2]);

  int max = 0;
  int max_index = 0;
  for (int i=0; i<N; i++)
  {
	  for (array_of_lists[i].moveToStart(); array_of_lists[i].currPos()<array_of_lists[i].length(); array_of_lists[i].next()) {
		  it = array_of_lists[i].getValue();
		  if (it.key() > max) 
		  {
			  max = it.key();
			  max_index = i;
		  }
	  }
  }

  cout << "max index= " << max_index << " max= " << max << endl;
  return 0;
}