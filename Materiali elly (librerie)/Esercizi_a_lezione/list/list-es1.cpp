//Scrivete un programma in grado di svuotare due liste singolarmente concatenate di interi (L1, L2), ordinate in modo decrescente, e di fonderle in una singola lista ordinata di interi L3 ordinata in modo descrescente. 
//La funzione mergelists deve ricevere come parametri i riferimenti alle liste L1, L2, L3. 

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "link.h"
#include "llist.h"
#include "listTest.h"

// mergelists
void mergelists(List<Item>& L1, List<Item>& L2, List<Item>& L3)
{
	L3.moveToStart();

	while ((L1.length() > 0) || (L2.length() > 0))
	{
		if (L1.length()>0 && L2.length()>0)
		{
			if (L1.getValue().key() >= L2.getValue().key())
			{
				L3.append(L1.getValue());
				L1.remove();
			}
			else
			{
				L3.append(L2.getValue());
				L2.remove();
			}
		}
		else
		{
			if (L1.length()>0)
			{
				L3.append(L1.getValue());
				L1.remove();
			}
			else
			{
				L3.append(L2.getValue());
				L2.remove();
			}
		}
	} 
}

// Main routine for linked list driver class
int main(int argc, char** argv) {

  LList<Item> L1;  
  LList<Item> L2; 
  LList<Item> L3; 

  Item temp(35);

  L1.append(Item(35));
  L1.append(Item(17));
  L1.append(Item(13));
  L1.append(Item(8));
  L1.append(Item(2));
  cout << "L1: "; lprint(L1);

  L2.append(Item(12));
  L2.append(Item(11));
  L2.append(Item(7));
  L2.append(Item(1));
  cout << "L2: "; lprint(L2);

  mergelists(L1, L2, L3);
  cout << "L1: "; lprint(L1);
  cout << "L2: "; lprint(L2);
  cout << "L3: "; lprint(L3);

  return 0;
}