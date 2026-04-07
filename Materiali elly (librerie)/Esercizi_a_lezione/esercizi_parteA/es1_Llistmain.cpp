// Dispensa e ricette
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the link template class
#include "link.h"

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "es1_ListTest.h"

int find(List<prodotto>& L, string codice) {
	prodotto it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (codice == it.key()) return L.currPos();
	}
	return -1;
}

int findpiatto(List<Item>& L, int piatto) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (piatto == it.key().numero) return L.currPos();
	}
	return -1;
}

void bubblesort(List<Item>& L) {
	for (int i = 0; i< (L.length() - 1); i++) {
		for (int j = (L.length() - 1); j> i; j--) {
			L.moveToPos(j);
			Item it_j = L.getValue();
			L.moveToPos(j - 1);
			Item it_jj = L.getValue();
			if (it_jj.key().numero>it_j.key().numero)
			{
				L.moveToPos(j);
				Item removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
}


// Main routine 
int main(int argc, char** argv) {

  LList<prodotto> Ldispensa;  

  ifstream myfile("dispensa.txt");
  string codice;
  string nome;
  string sq;
  int quantita;
  
  if (myfile.is_open()) {
	  while (getline(myfile, codice, ';')) {
		  getline(myfile, nome, ';');
		  getline(myfile, sq);
		  istringstream token(sq);
		  token >> quantita;
		  prodotto temp(codice,nome,quantita);

		  int result=find(Ldispensa, temp.key());
		  if (result==-1)
			  Ldispensa.insert(temp);
		  else
		  {
			  prodotto toremove;
			  Ldispensa.moveToPos(result);
			  toremove= Ldispensa.getValue();
			  Ldispensa.remove();
			  toremove.setquantita(toremove.getquantita()+temp.getquantita());
			  Ldispensa.insert(toremove);
		  }
	  }
	  myfile.close();
  }

  cout << "Ldispensa: "; lprint(Ldispensa);

  LList<Item> Lricette;
  string str;
  myfile.open("ricette.txt");
  if (myfile.is_open()) {
	  while (getline(myfile, str, ';')) {
		  ricetta ric;
		  istringstream sstr(str);
		  sstr >> ric.numero;

		  getline(myfile, ric.descrizione, ';');

		  getline(myfile, ric.ingrediente1, ';');
		  getline(myfile, str, ';');
		  istringstream si1q(str);
		  si1q >> ric.quantita_ingr1;

		  getline(myfile, ric.ingrediente2, ';');
		  getline(myfile, str);
		  istringstream si2q(str);
		  si2q >> ric.quantita_ingr2;

          Item temp(ric);
		  Lricette.insert(temp);
	  }
	  myfile.close();
  }
  
  cout << "Lricette: "; lprint(Lricette);
  bubblesort(Lricette);
  cout << endl << "Lricette: "; lprint(Lricette);

  while(1)
  {
   cout << "Inserire il numero di un piatto:";
   int piatto;
   cin >> piatto;
   int piattotrovato=findpiatto(Lricette,piatto);
   if (piattotrovato == -1)
	  cout << "piatto non disponibile" << endl;
   else 
   {
	  Lricette.moveToPos(piattotrovato);
	  Item ricettatrovata=Lricette.getValue();
	  int result1 = find(Ldispensa, ricettatrovata.key().ingrediente1);
	  Ldispensa.moveToPos(result1);
	  prodotto p1=Ldispensa.getValue();
	  int result2 = find(Ldispensa, ricettatrovata.key().ingrediente2);
	  Ldispensa.moveToPos(result2);
	  prodotto p2 = Ldispensa.getValue();
	 
	  if (p1.getquantita()<ricettatrovata.key().quantita_ingr1)
		  cout << "quantita' ingrediente1 in dispensa non sufficiente" << endl;
	  else if (p2.getquantita()<ricettatrovata.key().quantita_ingr2)
		  cout << "quantita' ingrediente2 in dispensa non sufficiente" << endl;
	  else {
		    cout << "ordine accettato" << endl;
			Ldispensa.moveToPos(result1);
			Ldispensa.remove();
			p1.setquantita(p1.getquantita() - ricettatrovata.key().quantita_ingr1);
			Ldispensa.insert(p1);

			Ldispensa.moveToPos(result2);
			Ldispensa.remove();
			p2.setquantita(p2.getquantita() - ricettatrovata.key().quantita_ingr2);
			Ldispensa.insert(p2);
			cout << "Ldispensa: "; lprint(Ldispensa);
	  }
   }
  }

  cout << "That is all.\n";
  return 0;
}