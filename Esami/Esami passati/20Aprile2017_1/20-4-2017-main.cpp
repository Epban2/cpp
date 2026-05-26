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

void bubblesort(List<Item>& L) {
	for (int i = 0; i < (L.length() - 1); i++) {
		for (int j = (L.length() - 1); j > i; j--) {
			L.moveToPos(j);
			Item it_j = L.getValue();
			L.moveToPos(j - 1);
			Item it_jj = L.getValue();
			if (it_jj.key() < it_j.key())
			{
				L.moveToPos(j);
				Item removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
}

int find(List<Item>& L, Item awarded) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if ((awarded.getname() == it.getname()) && (awarded.getsurname() == it.getsurname())) return L.currPos();
	}
	return -1;
}

// Main routine for linked list driver class
int main(int argc, char** argv) {
  srand(time(NULL));
  LList<Item> Lbiglietti;
  LStack<Award> Saward;

  ifstream myfile("biglietti.txt");
  int nbiglietto;
  string nome;
  string cognome;
  if (myfile.is_open()) {
	  while (myfile >> nbiglietto >> nome >> cognome) {
		  Item temp(nbiglietto,nome,cognome);
		  Lbiglietti.append(temp);
	  }
  }
  else
  {
	  cout << "Errore di apertura del file" << endl;
	  return -1;
  }
  myfile.close();

  bubblesort(Lbiglietti);
  lprint(Lbiglietti);

  int K;
  cout << endl << "inserire il numero di premi" << endl;
  cin >> K;
  if (K>7) 
	 {
	  cout << "Il numero di premi deve essere minore di 7" << endl;
	  return -1;
	 }

  Award* item_array = new Award[K];

  ifstream myfile2("premi.txt");
  float valore;
  string descr;
  int i = 0;
  if (myfile2.is_open()) {
	  while (i<K) {
		  myfile2 >> descr >> valore;
		  Award pr(descr, valore/100);
		  item_array[i] = pr; 
		  i++;
	  }
  }
  else
  {
	  cout << "Errore di apertura del file" << endl;
	  return -1;
  }
  myfile2.close();

  Award temp_aw = item_array[0];
  item_array[0] = item_array[K-1];
  item_array[K-1] = temp_aw;

  float tot_value=0;
  for (int c=K-1; c>=0; c--)
  {
	  tot_value += item_array[c].getvalue();
	  Saward.push(item_array[c]);
  }
  cout << endl;
  Lstackprint(Saward);
  cout << endl << "Montepremi= " << tot_value << endl;

  LList<Item> Lpremiati;
  int found;
  while(Saward.length()>0)
  {
	  Award popped_aw = Saward.pop();
	  do 
	  {
		  int random_number = rand() % Lbiglietti.length();
		  Lbiglietti.moveToPos(random_number);
		  Item awarded = Lbiglietti.getValue();
		  found = find(Lpremiati, awarded);
		  if (found==-1)
		  {
			  cout << "Il premio " << popped_aw.getdescription() << " viene attribuito a " << awarded.getname() << " " << awarded.getsurname() << endl;
			  Lpremiati.append(awarded);
		  }
	  } while (found!=-1);
  }

  cout << "That is all.\n";

  return 0;
}