#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "llist.h"
#include "lstack.h"

// Generic list test commands
#include "ListTest.h"

void selectionsort(List<Item>& L) {
	int max_pos;
	Item max_element;
	// se lunghezza <2 non fai nulla
	for (int i = 0; i<L.length() - 1; i++) {
		L.moveToPos(i);
		max_element = L.getValue();
		max_pos = i;
		for (int j = i + 1; j<L.length(); j++) {
			L.moveToPos(j);
			Item it_temp = L.getValue();
			if (it_temp.key() >= max_element.key())
			{
				max_pos = L.currPos();
				max_element = it_temp;
			}
		}
		L.moveToPos(max_pos);
		Item it_temp = L.remove();
		L.moveToPos(i);
		L.insert(it_temp);
	}

}

int main(int argc, char** argv) {
  LList<Item> Lbiglietti;
  LStack<Item> Sbiglietti;
  LStack<Item> Sbiglietti_temp;

  ifstream myfile("bigliettiVenduti.txt");
  int nbiglietto;
  string str;
  string nome;
  string cognome;
  if (myfile.is_open()) {
	  while (getline(myfile, str, ',')) {
		  istringstream token(str);
		  token >> nbiglietto;
		  getline(myfile, nome, ',');
		  getline(myfile, cognome);
		 
		  Item temp(nbiglietto,nome,cognome);
		  Lbiglietti.append(temp);
	  }
  }
  myfile.close();

  string prev_name = "";
  string prev_surname = "";
  for (Lbiglietti.moveToStart(); Lbiglietti.currPos()<Lbiglietti.length(); Lbiglietti.next())
  {
   Item cur_it = Lbiglietti.getValue();
   if ((cur_it.getname()!=prev_name) || (cur_it.getsurname()!=prev_surname))
   {
	   cout << "primo biglietto acquistato da " << cur_it.getname() << " " << cur_it.getsurname() << " :" << cur_it.key() << endl;
	   prev_name = cur_it.getname();
	   prev_surname = cur_it.getsurname();
   }
  }
  cout << endl;
  selectionsort(Lbiglietti);
  lprint(Lbiglietti);

  Lbiglietti.moveToStart();
  while (Lbiglietti.currPos()<Lbiglietti.length())
  {
	 Item it_cur = Lbiglietti.getValue();
	 if (it_cur.key()%2==0)
	 {
	   Sbiglietti.push(it_cur);
	   Lbiglietti.next();
	 }
	 else
	   Lbiglietti.remove();
  }
  cout << endl << "lista con solo biglietti pari:";
  lprint(Lbiglietti);
  cout << endl << "Stack prima di inversione elementi:";
  Lstackprint(Sbiglietti);

  Item first = Sbiglietti.pop();
  Item popped;
  while (Sbiglietti.length()>0)
  {
	  popped= Sbiglietti.pop();
	  if (Sbiglietti.length()>0)
		  Sbiglietti_temp.push(popped);
  }
  Sbiglietti.push(first);
  while (Sbiglietti_temp.length()>0)
  {
	  Item popped_temp = Sbiglietti_temp.pop();
	  Sbiglietti.push(popped_temp);
  }
  if (Sbiglietti.length()>0) 
	  Sbiglietti.push(popped);
  cout << endl << endl << "Stack dopo inversione elementi:";
  Lstackprint(Sbiglietti);

  cout << endl << "That is all.\n";

  return 0;
}