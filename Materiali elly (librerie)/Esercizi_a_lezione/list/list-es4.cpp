//Creare una lista di  numeri  interi  ordinati  in  ordine  crescente. 
//Dopo aver memorizzato la sequenza in una lista, inserire nella posizione corretta all’interno della lista, tutti i numeri mancanti. 
//Stampare  in output la lista. Non devono essere usate altre liste o array di appoggio.  
//Esempio: Supponiamo che sia  fornita in input la sequenza 4, 7, 8, 9,15,17,21. 
//Dopo aver memorizzato gli elementi nella lista 4 > 7 > 8 > . . . > 21, 
//vengono inseriti i numeri mancanti, ottenendo la lista composta dagli elementi 
//4 > 5 > 6 > 7 > 8 >. . . > 19 > 20 > 21. 

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Include the link template class
#include "link.h"

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "listTest.h"

// Main routine 
int main(int argc, char** argv) {

  LList<Item> L1;  

  Item temp, elem, next_elem;

  L1.append(Item(3));
  L1.append(Item(7));
  L1.append(Item(10));
  L1.append(Item(16));
  L1.append(Item(21));
  L1.append(Item(35));
  L1.moveToStart();
  cout << "L1: "; lprint(L1);

  while (L1.currPos()<L1.length()-1) {
	  elem = L1.getValue();
	  L1.next();
	  next_elem = L1.getValue();

	  cout << "elem=" << elem.key() << endl;
	  cout << "next_elem=" << next_elem.key() << endl;

	  for (int i=elem.key(); i<next_elem.key()-1; i++)
	  {
		  Item it(i + 1);
		  L1.insert(it);
		  cout << i + 1 << " ";
		  L1.next();
	  }
	  cout << endl;
  }
  cout << "L1: "; lprint(L1);

  return 0;
}